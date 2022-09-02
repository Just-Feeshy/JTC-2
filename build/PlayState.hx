package;

#if windows
import Discord.DiscordClient;
#end
import Section.SwagSection;
import Song.SwagSong;
import WiggleEffect.WiggleEffectType;
import flixel.FlxBasic;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxGame;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.FlxSubState;
import flixel.effects.FlxFlicker;
import flixel.addons.display.FlxGridOverlay;
import flixel.input.keyboard.FlxKey;
import flixel.addons.effects.FlxTrail;
import flixel.addons.effects.FlxTrailArea;
import flixel.addons.effects.chainable.FlxEffectSprite;
import flixel.addons.effects.chainable.FlxWaveEffect;
import flixel.addons.transition.FlxTransitionableState;
import flixel.graphics.atlas.FlxAtlas;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.group.FlxSpriteGroup.FlxTypedSpriteGroup;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxMath;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.system.FlxSound;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxCollision;
import flixel.util.FlxColor;
import flixel.util.FlxSort;
import flixel.util.FlxStringUtil;
import flixel.util.FlxTimer;
import haxe.Json;
import lime.utils.Assets;
import openfl.system.System;
import openfl.display.BlendMode;
import openfl.display.StageQuality;
import openfl.filters.ShaderFilter;
import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilterQuality;
import feshixl.group.FeshEventGroup;
import openfl.Lib;
import feshixl.FeshCamera;

import example_code.DefaultEvents;
import example_code.DefaultStage;
import template.CustomNote;
import template.StageBuilder;

import SaveData.SaveType;

using StringTools;

class PlayState extends MusicBeatState
{
	//More Stuff
	private var stage:StageBuilder;

	private var createdCharacters:Bool;
	private var trippyFog:FlxSprite;
	private var waterFog:FlxSprite;
	private var testSprite:FlxSprite;
	private var warningSprState:WarningSubGroup;
	private var debugText:FlxText;
	private var curChar:String = '';
	private var camMovementPos:FlxPoint;
	private var prevDadNoteData:Int = -1;

	private var healthTween:FlxTween;

	public var camPos:FlxPoint;
	public var flipWiggle:Int = 1;
	public var timeFreeze:Float = 0;
	public var health:Float = 1;

	private var prevHealth:Float = 0;

	public var opponentAltAnim:String = "";
	public var playerAltAnim:String = "";

	private var isPixel:Bool = false;

	//Event Stuff
	public var eventInfo(default, null):Array<EventInfo>;

	public var eventCounter:Int = 0;
	public var prevEventStep:Int = 0;

	//Modifier Values
	public var singDrainValue:Float = 1;
	public var fadeInValue:Int = 400;
	public var cameraMovementInsensity:Float = 1;

	@:isVar public var wobbleModPower(get, set):Float = 30;

	//Chart Shit
	public static var muteInst:Bool;
	public var eventStorage:Array<String> = [];

	//Camera Shit
	public static var camHUD:FeshCamera;
	public static var camNOTE:CameraNote;

	//Note Stuff Funk U
	private var waterBlur:Array<BlurFilter> = [];
	private var trippyWiggle:WiggleEffect = new WiggleEffect();
	private var triggerGroup:FlxTypedGroup<FlxSprite>;
	private var grpSplash:FlxTypedGroup<SplashSprite>;
	private var trippyShader:ShaderFilter;

	//Controls
	private var keysMatrix:Array<Array<Int>> = [];

	//Da Variables
	private var hits:Int = 0;
	private var misses:Int = 0;
	private var missesHold:Int = 0;
	private var missClicks:Int = 0;
	private var totalNotesLoaded:Int = 0;
	private var defaultBlur:Float = 0;
	private var playFPS:Null<Int> = Main.framerate;
	private var counterTxt:FlxText;

	private var accTotal(get, never):Float;
	private var totalRatingAcc:Float = 0;

	public static var hasWarning:Bool = true;
	public static var curStage:String = '';
	public static var rawJSON:String = '';
	public static var SONG:SwagSong;
	public static var isStoryMode:Bool = false;
	public static var storyWeek:Int = 0;
	public static var storyPlaylist:Array<String> = [];
	public static var storyDifficulty:Int = 2;
	public static var noteBeat:Float;

	var daRating:String = "sick";

	private var curSection:Int = 0;

	private var vocals:FlxSound;

	public var dad:Character;
	public var gf:Character;
	public var boyfriend:Boyfriend;

	public var currentPlayer(get, never):Character;
	public var currentOpponent(get, never):Character;

	public var notes:FlxTypedGroup<Note>;
	public var unspawnNotes:Array<Note> = [];

	public var waitForFinishPlayer:Bool = false;
	public var waitForFinishOpponent:Bool = false;

	private var strumLine:FlxSprite;

	public var camFollow:FlxObject;

	private static var prevCamFollow:FlxObject;

	public var strumLineNotes:FlxTypedGroup<Strum>;

	public static var playerStrums:FlxTypedSpriteGroup<Strum>;
	public static var opponentStrums:FlxTypedSpriteGroup<Strum>;

	public var currentStrums(get, never):FlxTypedSpriteGroup<Strum>;
	public var oppositeStrums(get, never):FlxTypedSpriteGroup<Strum>;

	private var camZooming:Bool = false;
	private var curSong:String = "";
	private var readableSong:String = "";
	private var combo:Int = 0;

	public var healthBarBG:FlxSprite;
	public var healthBar:HealthBar;

	public var iconP1:HealthIcon;
	public var iconP2:HealthIcon;

	private var generatedMusic:Bool = false;
	private var startingSong:Bool = false;

	public var camGame:FeshCamera;

	var customNoteSprites:FlxTypedGroup<FlxSprite>;

	var playerIconColor:FlxColor;
	var opponentIconColor:FlxColor;

	var halloweenBG:FlxSprite;
	var isHalloween:Bool = false;

	var upperBoppers:FlxSprite;
	var bottomBoppers:FlxSprite;
	var santa:FlxSprite;

	var bgGirls:BackgroundGirls;
	var wiggleShit:WiggleEffect = new WiggleEffect();

	var talking:Bool = true;
	var songScore:Int = 0;

	public static var campaignScore:Int = 0;

	var defaultCamZoom:Float = 1.05;

	var doof:DialogueBox;
	var events:FeshEventGroup;

	// how big to stretch the pixel art assets
	public static var daPixelZoom:Float = 6;

	public var inCutscene:Bool = false;

	var singAnims:Array<String> = [];

	#if desktop
	// Discord RPC variables
	var storyDifficultyText:String = "";
	var iconRPC:String = "";
	var songLength:Float = 0;
	var detailsText:String = "";
	var detailsPausedText:String = "";
	#end

	override public function new(?muted:Bool) {
		CustomNoteHandler.spawn();

		Note.AFFECTED_SCROLLSPEED = 1;
		Note.AFFECTED_STRUMTIME = 0;

		muteInst = muted;
		super();
	}

	override public function create() {
		Cache.clearNoneCachedAssets();

		FlxG.mouse.visible = false;
		//testSprite.visible = false;
		eventStorage = [];

		if (FlxG.sound.music != null)
			FlxG.sound.music.stop();

		SaveData.saveClient();
		
		camGame = new FeshCamera();
		camNOTE = new CameraNote();
		camHUD = new FeshCamera();
		camHUD.bgColor.alpha = 0;
		camNOTE.bgColor.alpha = 0;

		FlxG.cameras.reset(camGame);
		FlxG.cameras.add(camNOTE);
		FlxG.cameras.add(camHUD);

		FlxCamera.defaultCameras = [camGame];

		persistentUpdate = true;
		persistentDraw = true;

		if (SONG == null)
			SONG = Song.loadFromJson('tutorial');

		readableSong = SONG.song.toLowerCase();

		if(Assets.exists(Paths.getPath('data/warning.txt', TEXT, ""))) //WIP
			if(Assets.getText(Paths.txt('${readableSong}/warning')) != "" 
			&& Assets.getText(Paths.txt('${readableSong}/warning')) != null)
				hasWarning = true;
			else
				hasWarning = false;
		else
			hasWarning = false;

		if(SONG.modifiers == null)
			SONG.modifiers = [];

		// Making difficulty text for Discord Rich Presence.
		switch (storyDifficulty)
		{
			case 0:
				storyDifficultyText = "Easy";
			case 1:
				storyDifficultyText = "Normal";
			case 2:
				storyDifficultyText = "Hard";
		}

		playFPS = SONG.fps;

		iconRPC = SONG.player2;

		// To avoid having duplicate images in Discord assets
		switch (iconRPC)
		{
			case 'senpai-angry':
				iconRPC = 'senpai';
			case 'monster-christmas':
				iconRPC = 'monster';
			case 'mom-car':
				iconRPC = 'mom';
		}

		// String that contains the mode defined here so it isn't necessary to call changePresence for each mode
		if (isStoryMode)
		{
			detailsText = "Story Mode: Week " + storyWeek;
		}
		else
		{
			detailsText = "Freeplay";
		}

		// String for when the game is paused
		detailsPausedText = "Paused - " + detailsText;
		
		// Updating Discord Rich Presence.
		#if windows
		DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
		#end

		if(SONG.stage == null)
			SONG.stage = DefaultStage.setMainGameStage(SONG.song.toLowerCase());

		curStage = SONG.stage;

		stage = cast Type.createInstance(Register.stage, [curStage]);
		add(stage);

		events = new FeshEventGroup();

		for(i in 0...Register.events.length) {
			events.add(cast Type.createInstance(Register.events[i], []));
		}

		if(waterBlur[0] == null)
			waterBlur.push(new BlurFilter(defaultBlur, defaultBlur, BitmapFilterQuality.HIGH));

		waterBlur.push(new BlurFilter(1, 1, BitmapFilterQuality.HIGH));

		var gfVersion:String = 'gf';

		if(SONG.girlfriend == null) {
			switch (curStage) {
				case 'limo':
					gfVersion = 'gf-car';
				case 'mall' | 'mallEvil':
					gfVersion = 'gf-christmas';
				case 'school':
					gfVersion = 'gf-pixel';
				case 'schoolEvil':
					gfVersion = 'gf-pixel';
			}

			if (curStage == 'limo')
				gfVersion = 'gf-car';
		}else {
			gfVersion = SONG.girlfriend;
		}

		gf = new Character(400, 130, gfVersion);
		gf.scrollFactor.set(0.95, 0.95);
		
		if(!stage.hasGirlfriend()) {
			gf.destroy();
			gf = null;
		}

		dad = new Character(100, 100, SONG.player2);

		camPos = new FlxPoint(dad.getGraphicMidpoint().x, dad.getGraphicMidpoint().y);
		camMovementPos = new FlxPoint(0, 0);

		switch (SONG.player2) {
			case 'gf':
				dad.setPosition(gf.x, gf.y);
				gf.visible = false;
				if (isStoryMode) {
					camPos.x += 600;
					tweenCamIn();
				}
		}

		boyfriend = new Boyfriend(770, 100, SONG.player1);

		boyfriend.refresh(SONG.player1, camPos);
		camPos.set(dad.getGraphicMidpoint().x, dad.getGraphicMidpoint().y);
		dad.refresh(SONG.player2, camPos);

		stage.configStage();

		boyfriend.setPosition(boyfriend.x - SONG.player1X, boyfriend.y - SONG.player1Y);
		dad.setPosition(dad.x - SONG.player2X, dad.y - SONG.player2Y);

		Conductor.trackPosition = -5000;

		strumLine = new FlxSprite(0, 50).makeGraphic(FlxG.width, 10);
		strumLine.scrollFactor.set();

		if (FlxG.save.data.helpme)
			strumLine.y = FlxG.height - 175;

		strumLineNotes = new FlxTypedGroup<Strum>();
		add(strumLineNotes);

		if(playerStrums != null) {
			for(i in 0...playerStrums.length) {
				for(v in playerStrums.members) {
					v.kill();
					playerStrums.remove(v, true);
					v.destroy();
				}

				for(v in opponentStrums.members) {
					v.kill();
					opponentStrums.remove(v, true);
					v.destroy();
				}
			}
		}	

		playerStrums = new FlxTypedSpriteGroup<Strum>();
		opponentStrums = new FlxTypedSpriteGroup<Strum>();

		grpSplash = new FlxTypedGroup<SplashSprite>();
		add(grpSplash);

		DefaultHandler.spawn();
		setupModifiers();

		if(modifierCheckList('blind effect')) {
			camGame.engineAlpha = 0;
		}

		// startCountdown();
		generateSong(SONG.song);

		// add(strumLine);

		camFollow = new FlxObject(0, 0, 1, 1);

		camFollow.setPosition(camPos.x + camMovementPos.x, camPos.y + camMovementPos.y);

		if (prevCamFollow != null)
		{
			camFollow = prevCamFollow;
			prevCamFollow = null;
		}

		add(camFollow);

		FlxG.camera.follow(camFollow, LOCKON, 0.04);
		// FlxG.camera.setScrollBounds(0, FlxG.width, 0, FlxG.height);
		FlxG.camera.zoom = defaultCamZoom;
		FlxG.camera.focusOn(camFollow.getPosition());

		FlxG.worldBounds.set(0, 0, FlxG.width, FlxG.height);

		FlxG.fixedTimestep = false;

		healthBarBG = new FlxSprite(0, FlxG.height * 0.9).loadGraphic(Paths.image('healthBar'));

		if (FlxG.save.data.helpme)
			healthBarBG.y = 50;

		healthBarBG.screenCenter(X);
		healthBarBG.scrollFactor.set();

		//Feesh Miss
		debugText = new FlxText(0, 0, FlxG.width, "Debug Pause State", 32);
		debugText.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		debugText.borderSize = 3;
		debugText.visible = false;
		add(debugText);

		counterTxt = new FlxText(healthBarBG.x + healthBarBG.width - 190, healthBarBG.y + 32, 0, "", 20);
		counterTxt.setFormat(Paths.font("vcr.ttf"), 18, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		counterTxt.antialiasing = FlxG.save.data.showAntialiasing;
		counterTxt.scrollFactor.set();

		iconP1 = new HealthIcon(SONG.player1, true);

		iconP2 = new HealthIcon(SONG.player2, false);

		if(SaveData.getData(PLAY_AS_OPPONENT)) {
			iconP2.bpm = SONG.bpm;
		}else {
			iconP1.bpm = SONG.bpm;
		}

		healthBar = new HealthBar(healthBarBG.x + 4, healthBarBG.y + 4, Std.int(healthBarBG.width - 8), Std.int(healthBarBG.height - 8), this,
			'health', 0, 2);
			
		healthBar.subtractIt = SaveData.getData(PLAY_AS_OPPONENT);
		healthBar.scrollFactor.set();

		playerIconColor = CoolUtil.calculateAverageColor(iconP1.updateFramePixels());
		opponentIconColor = CoolUtil.calculateAverageColor(iconP2.updateFramePixels());
		healthBar.createFilledBar(opponentIconColor, playerIconColor);

		createScene();
		createFogs();

		getLuaScript();

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			generateStaticLua();
			updateLuaVars();
		}
		#end

		iconP1.y = healthBar.y - (iconP1.height / 2);
		iconP2.y = healthBar.y - (iconP2.height / 2);

		strumLineNotes.cameras = [camNOTE];
		notes.cameras = [camNOTE];
		grpSplash.cameras = [camNOTE];
		healthBar.cameras = [camHUD];
		healthBarBG.cameras = [camHUD];
		iconP1.cameras = [camHUD];
		iconP2.cameras = [camHUD];
		debugText.cameras = [camHUD];
		counterTxt.cameras = [camHUD];

		if(SONG.modifiers != null)
			eventInfo = SONG.modifiers.copy();
		else
			eventInfo = [];

		eventInfo.sort((a, b) -> Std.int(Reflect.field(a, "modGridY") - Reflect.field(b, "modGridY")));

		startingSong = true;

		if(!hasWarning)
			inDeBenigin();

		setupKeyStuff();
		eventLoad();

		super.create();
	}

	function setupKeyStuff():Void {
		if(SONG.fifthKey) {
			singAnims = ["singLEFT", "singDOWN", "singUP", "singUP", "singRIGHT"];
		}else {
			singAnims = ["singLEFT", "singDOWN", "singUP", "singRIGHT"];
		}
	}

	function inDeBenigin() {
		#if !(debug || USING_MOD_DEBUG)
		if (isStoryMode) {
		#end
			switch (curSong.toLowerCase())
			{
				case "winter-horrorland":
					var blackScreen:FlxSprite = new FlxSprite(0, 0).makeGraphic(Std.int(FlxG.width * 2), Std.int(FlxG.height * 2), FlxColor.BLACK);
					add(blackScreen);
					blackScreen.scrollFactor.set();
					camHUD.visible = false;
					camNOTE.visible = false;

					new FlxTimer().start(0.1, function(tmr:FlxTimer)
					{
						remove(blackScreen);
						FlxG.sound.play(Paths.sound('Lights_Turn_On'));
						camFollow.y = -2050;
						camFollow.x += 200;
						FlxG.camera.focusOn(camFollow.getPosition());
						FlxG.camera.zoom = 1.5;

						new FlxTimer().start(0.8, function(tmr:FlxTimer)
						{
							camHUD.visible = true;
							camNOTE.visible = true;
							remove(blackScreen);
							FlxTween.tween(FlxG.camera, {zoom: defaultCamZoom}, 2.5, {
								ease: FlxEase.quadInOut,
								onComplete: function(twn:FlxTween)
								{
									startCountdown();
								}
							});
						});
					});
				case 'senpai' | 'roses' | 'thorns':
					if(curSong.toLowerCase() == 'roses') {
						FlxG.sound.play(Paths.sound('ANGRY'));
					}

					var dialogue:Array<String> = ['blah blah blah', 'coolswag'];
					var file:String = Paths.txt(readableSong + '/' + readableSong + 'Dialogue');

					if (Assets.exists(file)) {
						dialogue = CoolUtil.coolTextFile(file);
					}

					doof = new DialogueBox(false, dialogue);
					doof.scrollFactor.set();
					doof.finishThing = startCountdown;
					doof.cameras = [camHUD];

					schoolIntro(doof);
				default:
					var dialogueBox = Type.createInstance(cast Register.dialogues.get(curSong.toLowerCase()), []);

					if(dialogueBox != null) {
						inCutscene = true;
						dialogueBox.finishCallback = clearDialogue;

						dialogueBox.createDialogue(this);
						dialogueBox.attachToCamera(camHUD);
					}else {
						startCountdown();
					}
			}
		#if !(debug || USING_MOD_DEBUG)
		}
		else
		{
			switch (curSong.toLowerCase())
			{
				default:
					startCountdown();
			}
		}
		#end
	}

	function schoolIntro(?dialogueBox:DialogueBox):Void
	{
		inCutscene = true;

		var black:FlxSprite = new FlxSprite(-100, -100).makeGraphic(FlxG.width * 2, FlxG.height * 2, FlxColor.BLACK);
		black.scrollFactor.set();
		add(black);

		var red:FlxSprite = new FlxSprite(-100, -100).makeGraphic(FlxG.width * 2, FlxG.height * 2, 0xFFff1b31);
		red.scrollFactor.set();

		var senpaiEvil:FlxSprite = new FlxSprite();
		senpaiEvil.frames = Paths.getSparrowAtlas('weeb/senpaiCrazy');
		senpaiEvil.animation.addByPrefix('idle', 'Senpai Pre Explosion', 24, false);
		senpaiEvil.setGraphicSize(Std.int(senpaiEvil.width * 6));
		senpaiEvil.scrollFactor.set();
		senpaiEvil.updateHitbox();
		senpaiEvil.screenCenter();
		senpaiEvil.x += 300;

		if (readableSong == 'roses' || readableSong == 'thorns')
		{
			remove(black);

			if (readableSong == 'thorns')
			{
				add(red);
			}
		}

		new FlxTimer().start(0.3, function(tmr:FlxTimer)
		{
			black.alpha -= 0.15;

			if (black.alpha > 0)
			{
				tmr.reset(0.3);
			}
			else
			{
				if (dialogueBox != null)
				{
					if (readableSong == 'thorns')
					{
						add(senpaiEvil);
						senpaiEvil.alpha = 0;
						new FlxTimer().start(0.3, function(swagTimer:FlxTimer)
						{
							senpaiEvil.alpha += 0.15;
							if (senpaiEvil.alpha < 1)
							{
								swagTimer.reset();
							}
							else
							{
								senpaiEvil.animation.play('idle');
								FlxG.sound.play(Paths.sound('Senpai_Dies'), 1, false, null, true, function()
								{
									remove(senpaiEvil);
									remove(red);
									FlxG.camera.fade(FlxColor.WHITE, 0.01, true, function()
									{
										add(dialogueBox);
									}, true);
								});
								new FlxTimer().start(3.2, function(deadTime:FlxTimer)
								{
									FlxG.camera.fade(FlxColor.WHITE, 1.6, false);
								});
							}
						});
					}
					else
					{
						add(dialogueBox);
					}
				}
				else
					startCountdown();

				remove(black);
			}
		});
	}

	function clearDialogue(dialogue:IDialogue) {
		dialogue.destroyDialogue();

		camGame.setTrashFilters([]);
		camHUD.setTrashFilters([]);

		startCountdown();
	}

	function setHealth(hp:Float, shouldTween:Bool = true) {
		if(healthTween != null) {
			healthTween.cancel();
			healthTween.destroy();

			health = prevHealth;
		}

		final tempHealth:Float = health;
		prevHealth = hp;

		if(Math.abs(hp - tempHealth) > 0.02) {
			healthTween = FlxTween.tween(this, {health: hp}, Math.abs(hp - tempHealth) * 2, {ease: FlxEase.quadOut});
		}else {
			health = hp;
		}
	}

	function createScene(?setup:Bool = true) {
		if(setup) {
			Conductor.mapBPMChanges(SONG);
			Conductor.changeBPM(SONG.bpm);
		}

		if(!createdCharacters) {
			stage.add(gf);

			stage.add(dad);
			stage.add(boyfriend);

			stage.whenCreatingScene();
		} else {
			return;
		}
	}

	function createFogs() {
		waterFog = new FlxSprite(0, 0).makeGraphic(1280, 720, FlxColor.BLUE);
		waterFog.screenCenter();
		waterFog.alpha = 0;
		add(waterFog);

		waterFog.cameras = [camNOTE];

		trippyFog = new FlxSprite(0, 0).makeGraphic(1480, 920, FlxColor.PURPLE);
		trippyFog.screenCenter();
		trippyFog.alpha = 0;
		trippyFog.scrollFactor.set();
		add(trippyFog);

		trippyFog.cameras = [camNOTE];
	}

	var startTimer:FlxTimer;
	var perfectMode:Bool = false;

	function setupModifiers():Void {
		DefaultHandler.modifiers.customHell.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.CUSTOM_HELL_MOD) #else false #end;
		DefaultHandler.modifiers.getGoodScrub.enabled = #if TOGGLEABLE_MODIFIERS (SaveData.getData(SaveType.PERFECT_MODE_MOD) > 0 ? true : false) #else false #end;
		DefaultHandler.modifiers.mirrorChart.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FLIP_CHART_MOD) #else false #end;
		DefaultHandler.modifiers.singDrain.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FAIR_BATTLE_MOD) #else false #end;
		DefaultHandler.modifiers.fadeInNotes.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FADE_BATTLE_MOD) #else false #end;
		DefaultHandler.modifiers.safeBalls.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.NO_BLUE_BALLS_MOD) #else false #end;
		DefaultHandler.modifiers.blindEffect.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.BLIND_MOD) #else false #end;
		DefaultHandler.modifiers.wobbleNotes.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.X_WOBBLE_MOD) #else false #end;
		DefaultHandler.modifiers.cameraMovement.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.CAMERA_MOVEMENT_MOD) #else false #end;
	}

	function modifierCheckList(mod:String):Bool {
		if(!Main.feeshmoraModifiers || DefaultHandler.modifiers == null) {
			return false;
		}

		switch(mod) {
			case "custom hell":
				return DefaultHandler.modifiers.customHell.enabled;
			case "get good":
				return DefaultHandler.modifiers.getGoodScrub.enabled;
			case "mirror chart":
				return DefaultHandler.modifiers.mirrorChart.enabled;
			case "sing drain":
				return DefaultHandler.modifiers.singDrain.enabled;
			case "fadein notes":
				return DefaultHandler.modifiers.fadeInNotes.enabled;
			case "blue balls":
				return DefaultHandler.modifiers.safeBalls.enabled;
			case "blind effect":
				return DefaultHandler.modifiers.blindEffect.enabled;
			case "note woggle":
				return DefaultHandler.modifiers.wobbleNotes.enabled;
			case "camera move":
				return DefaultHandler.modifiers.cameraMovement.enabled;
			default: return false;
		}
	}

	function startCountdown():Void {
		FlxG.sound.music.stop();
		inCutscene = false;

		add(healthBarBG);
		add(healthBar);
		add(counterTxt);
		add(iconP1);
		add(iconP2);

		generateStaticArrows(0);
		generateStaticArrows(1);

		talking = false;
		startedCountdown = true;
		Conductor.songPosition = 0;
		Conductor.songPosition -= Conductor.crochet * 5;
		Conductor.trackPosition = Conductor.songPosition + SaveData.getData(NOTE_OFFSET);

		makeNoteLua();

		setLua("startedCountdown", true);
		callLua("generatedStage", []);

		var swagCounter:Int = 0;

		startTimer = new FlxTimer().start(Conductor.crochet / 1000, function(tmr:FlxTimer)
		{
			iconP1.setGraphicSize(Std.int(iconP1.width + 30));

			if(gf != null) {
				gf.dance();
			}

			dad.dance();
			boyfriend.dance();

			var introAssets:Map<String, Array<String>> = new Map<String, Array<String>>();
			introAssets.set('default', ['ready', "set", "go"]);
			introAssets.set('school', ['weeb/pixelUI/ready-pixel', 'weeb/pixelUI/set-pixel', 'weeb/pixelUI/date-pixel']);
			introAssets.set('schoolEvil', ['weeb/pixelUI/ready-pixel', 'weeb/pixelUI/set-pixel', 'weeb/pixelUI/date-pixel']);

			var introAlts:Array<String> = introAssets.get('default');
			var altSuffix:String = "";

			for (value in introAssets.keys())
			{
				if (value == curStage)
				{
					introAlts = introAssets.get(value);
					altSuffix = '-pixel';
				}
			}

			switch (swagCounter)

			{
				case 0:
					FlxG.sound.play(Paths.sound('intro3'), 0.6);
				case 1:
					var ready:FlxSprite = new FlxSprite().loadGraphic(Paths.image(introAlts[0]));
					ready.scrollFactor.set();
					ready.updateHitbox();

					ready.cameras = [camNOTE];

					if (isPixel)
						ready.setGraphicSize(Std.int(ready.width * daPixelZoom));

					ready.screenCenter();
					add(ready);
					FlxTween.tween(ready, {y: ready.y += 100, alpha: 0}, Conductor.crochet / 1000, {
						ease: FlxEase.cubeInOut,
						onComplete: function(twn:FlxTween)
						{
							ready.destroy();
						}
					});
					FlxG.sound.play(Paths.sound('intro2'), 0.6);
				case 2:
					var set:FlxSprite = new FlxSprite().loadGraphic(Paths.image(introAlts[1]));
					set.scrollFactor.set();

					set.cameras = [camNOTE];

					if (isPixel)
						set.setGraphicSize(Std.int(set.width * daPixelZoom));

					set.screenCenter();
					add(set);
					FlxTween.tween(set, {y: set.y += 100, alpha: 0}, Conductor.crochet / 1000, {
						ease: FlxEase.cubeInOut,
						onComplete: function(twn:FlxTween)
						{
							set.destroy();
						}
					});
					FlxG.sound.play(Paths.sound('intro1'), 0.6);
				case 3:
					var go:FlxSprite = new FlxSprite().loadGraphic(Paths.image(introAlts[2]));
					go.scrollFactor.set();

					go.cameras = [camNOTE];

					if (isPixel)
						go.setGraphicSize(Std.int(go.width * daPixelZoom));

					go.updateHitbox();

					go.screenCenter();
					add(go);
					FlxTween.tween(go, {y: go.y += 100, alpha: 0}, Conductor.crochet / 1000, {
						ease: FlxEase.cubeInOut,
						onComplete: function(twn:FlxTween)
						{
							go.destroy();
						}
					});
					FlxG.sound.play(Paths.sound('introGo'), 0.6);
			}

			swagCounter += 1;
			// generateSong('fresh');
		}, 5);
	}

	var previousFrameTime:Int = 0;
	var lastReportedPlayheadPosition:Int = 0;
	var songTime:Float = 0;

	function startSong():Void
	{
		startingSong = false;

		previousFrameTime = FlxG.game.ticks;
		lastReportedPlayheadPosition = 0;

		if (!muteInst)
			FlxG.sound.playMusic(Paths.inst(PlayState.SONG.song), 1, false);

		FlxG.sound.music.onComplete = whenSongFinished.bind();
		vocals.play();

		if(paused) {
			FlxG.sound.music.pause();
			vocals.pause();
		}

		songLength = FlxG.sound.music.length;

		#if windows
		// Song duration in a float, useful for the time left feature
		// Updating Discord Rich Presence (with Time Left)
		DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC, true, songLength);
		#end
	}

	var debugNum:Int = 0;

	private function generateSong(dataPath:String):Void
	{
		var loadedSplashAnimations:Array<String> = [];

		// FlxG.log.add(ChartParser.parse());
		var keys:Int = 4;

		var songData = SONG;
		Conductor.changeBPM(songData.bpm);

		curSong = songData.song;

		if (SONG.needsVoices)
			vocals = new FlxSound().loadEmbedded(Paths.voices(PlayState.SONG.song));
		else
			vocals = new FlxSound();

		FlxG.sound.list.add(vocals);

		notes = new FlxTypedGroup<Note>();
		add(notes);

		var noteData:Array<SwagSection>;

		// NEW SHIT
		noteData = songData.notes;

		var playerCounter:Int = 0;

		var daBeats:Int = 0; // Not exactly representative of 'daBeats' lol, just how much it has looped

		if(SONG.fifthKey)
			keys = 5;

		for (i in 0...keys) {
			var splashSprite:SplashSprite = new SplashSprite();

			if(SaveData.getData(SaveType.SHOW_NOTE_SPLASH) ) {
				splashSprite.texture = "regular/splash";
				splashSprite.animation.play('sploosh0');
				splashSprite.animation.curAnim.curFrame = splashSprite.animation.curAnim.numFrames;
				grpSplash.add(splashSprite);

				loadedSplashAnimations.push(splashSprite.texture);
			}
		}

		customNoteSprites = new FlxTypedGroup<FlxSprite>();
		customNoteSprites.cameras = [camNOTE];
		add(customNoteSprites);

		for (section in noteData)
		{
			var coolSection:Int = Std.int(section.lengthInSteps / keys);

			for (songNotes in section.sectionNotes)
			{
				var daStrumTime:Float = songNotes[0];

				var daNoteData:Int = Std.int(songNotes[1] % keys);

				var daNoteAbstract:String = songNotes[3];

				var gottaHitNote:Bool = section.mustHitSection;

				if (songNotes[1] > keys-1)
				{
					gottaHitNote = !section.mustHitSection;
				}

				if(modifierCheckList('mirror chart') && gottaHitNote && Main.feeshmoraModifiers)
					daNoteData = Std.int(Math.abs(daNoteData-(keys-1)));

				if(modifierCheckList('custom hell') && Main.feeshmoraModifiers)
					daNoteAbstract = CoolUtil.coolTextFile(Paths.pak('mapHandler'))[FlxG.random.int(1, CoolUtil.coolTextFile(Paths.pak('mapHandler')).length-1)];

				var oldNote:Note;
				
				if (unspawnNotes.length > 0)
					oldNote = unspawnNotes[Std.int(unspawnNotes.length - 1)];
				else
					oldNote = null;

				var swagNote:Note = new Note(daStrumTime, daNoteData, oldNote, false, daNoteAbstract, false, true);
				swagNote.mustPress = gottaHitNote;
				swagNote.sustainLength = songNotes[2];
				swagNote.scrollFactor.set(0, 0);
				swagNote.refresh(SONG.fifthKey);
				swagNote.refresh(SONG.fifthKey, true);

				for (i in 0...keys) {
					var splashSprite:SplashSprite = new SplashSprite();
		
					if(swagNote.hasCustomAddon != null && !loadedSplashAnimations.contains(swagNote.hasCustomAddon.getSplashTexture())) {
						splashSprite.texture = swagNote.hasCustomAddon.getSplashTexture();
						swagNote.hasCustomAddon.createSplashSprite(splashSprite, FlxRect.get(), "sick");
						loadedSplashAnimations.push(splashSprite.texture);

						Cache.cacheAsset("notes/" + swagNote.hasCustomAddon.getSplashTexture(), "");
					}
				}

				if(daNoteAbstract != null && !DefaultHandler.tempNoteAbstracts.contains(daNoteAbstract))
					DefaultHandler.tempNoteAbstracts.push(daNoteAbstract);
				
				if(songNotes[4] > 0)
					swagNote.howSpeed = songNotes[4];

				if(songNotes[5] != null)
					swagNote.tag = songNotes[5];

				if(songNotes[6] != null)
					swagNote.playAnyAnimation = songNotes[6];

				swagNote.setupPosition = DefaultHandler.compilePosition(daStrumTime);

				var susLength:Float = swagNote.sustainLength;

				susLength = susLength / Conductor.stepCrochet;

				if(swagNote.trail != null)
					add(swagNote.trail);

				unspawnNotes.push(swagNote);

				if(swagNote.hasCustomAddon != null)
					swagNote.hasCustomAddon.whenIsFirstRendered(swagNote, keys);

				for (susNote in 0...Math.floor(susLength)) {
					oldNote = unspawnNotes[Std.int(unspawnNotes.length - 1)];

					if(!oldNote.isSustainNote && oldNote.trail != null)
						oldNote.trail.members[0].visible = true;

					var sustainNote:Note = new Note(daStrumTime + (Conductor.stepCrochet * susNote) + Conductor.stepCrochet, daNoteData, oldNote, true, daNoteAbstract);
					sustainNote.scrollFactor.set();

					sustainNote.howSpeed = oldNote.howSpeed;
					sustainNote.tag = oldNote.tag;

					sustainNote.playAnyAnimation = oldNote.playAnyAnimation;

					sustainNote.setupPosition = DefaultHandler.compilePosition((daStrumTime + (Conductor.stepCrochet * susNote) + Conductor.stepCrochet) * swagNote.howSpeed);

					if(!sustainNote.wasSustainNote)
						unspawnNotes.push(sustainNote);
					else
						sustainNote.destroy();

					sustainNote.mustPress = gottaHitNote;

					if (sustainNote.mustPress)
					{
						sustainNote.x += FlxG.width / 2; // general offset
					}

					if(SaveData.getData(PLAY_AS_OPPONENT)) {
						sustainNote.mustPress = !sustainNote.mustPress;
					}
				}

				if (swagNote.mustPress)
				{
					swagNote.x += FlxG.width / 2; // general offset	
				}

				if(SaveData.getData(PLAY_AS_OPPONENT)) {
					swagNote.mustPress = !swagNote.mustPress;
				}
			}
			daBeats += 1;
		}

		// trace(unspawnNotes.length);
		// playerCounter += 1;

		unspawnNotes.sort(sortByShit);
		totalNotesLoaded = unspawnNotes.length;
		loadedSplashAnimations = [];
		generatedMusic = true;
	}

	function sortByShit(Obj1:Note, Obj2:Note):Int
	{
		return FlxSort.byValues(FlxSort.ASCENDING, Obj1.strumTime, Obj2.strumTime);
	}

	private function generateStaticArrows(player:Int):Void
	{
		var keys:Int = 4;
		var notSplash:Int = 0;

		if(SONG.fifthKey)
			keys = 5;

		for (i in 0...keys)
		{
			var babyArrow:Strum;

			if(SONG.fifthKey)
				babyArrow = new Strum(0, strumLine.y);
			else
				babyArrow = new Strum(42, strumLine.y);

			babyArrow.ID = i;

			if(SONG.fifthKey) {
				switch (curStage)
				{
					case 'school' | 'schoolEvil':
						babyArrow.loadGraphic(Paths.image('weeb/pixelUI/arrows-pixels'), true, 17, 17);
						babyArrow.animation.add('green', [6]);
						babyArrow.animation.add('red', [7]);
						babyArrow.animation.add('blue', [5]);
						babyArrow.animation.add('purplel', [4]);

						babyArrow.setGraphicSize(Std.int(babyArrow.width * daPixelZoom));
						babyArrow.updateHitbox();
						babyArrow.antialiasing = false;

						switch (Math.abs(i))
						{
							case 0:
								babyArrow.x += Note.swagWidth * 0;
								babyArrow.animation.add('static', [0]);
								babyArrow.animation.add('pressed', [4, 8], 12, false);
								babyArrow.animation.add('confirm', [12, 16], 24, false);
							case 1:
								babyArrow.x += Note.swagWidth * 1;
								babyArrow.animation.add('static', [1]);
								babyArrow.animation.add('pressed', [5, 9], 12, false);
								babyArrow.animation.add('confirm', [13, 17], 24, false);
							case 2:
								babyArrow.x += Note.swagWidth * 2;
								babyArrow.animation.add('static', [20]);
								babyArrow.animation.add('pressed', [21, 22], 12, false);
								babyArrow.animation.add('confirm', [24, 23], 24, false);
							case 3:
								babyArrow.x += Note.swagWidth * 3;
								babyArrow.animation.add('static', [2]);
								babyArrow.animation.add('pressed', [6, 10], 12, false);
								babyArrow.animation.add('confirm', [14, 18], 12, false);
							case 4:
								babyArrow.x += Note.swagWidth * 4;
								babyArrow.animation.add('static', [3]);
								babyArrow.animation.add('pressed', [7, 11], 12, false);
								babyArrow.animation.add('confirm', [15, 19], 24, false);
						}
					default:
						babyArrow.frames = Paths.getSparrowAtlas('NOTE_assets', null, true);

						babyArrow.antialiasing = true;
						babyArrow.setGraphicSize(Std.int(babyArrow.width * 0.7));
						babyArrow.x += Note.swagWidth * i;
						babyArrow.setupAnimations();
				}
			}else {
				switch (curStage)
				{
					case 'school' | 'schoolEvil':
						babyArrow.loadGraphic(Paths.image('weeb/pixelUI/arrows-pixels'), true, 17, 17);
						babyArrow.animation.add('green', [6]);
						babyArrow.animation.add('red', [7]);
						babyArrow.animation.add('blue', [5]);
						babyArrow.animation.add('purplel', [4]);

						babyArrow.setGraphicSize(Std.int(babyArrow.width * daPixelZoom));
						babyArrow.updateHitbox();
						babyArrow.antialiasing = false;

						switch (Math.abs(i))
						{
							case 0:
								babyArrow.x += Note.swagWidth * 0;
								babyArrow.animation.add('static', [0]);
								babyArrow.animation.add('pressed', [4, 8], 12, false);
								babyArrow.animation.add('confirm', [12, 16], 24, false);
							case 1:
								babyArrow.x += Note.swagWidth * 1;
								babyArrow.animation.add('static', [1]);
								babyArrow.animation.add('pressed', [5, 9], 12, false);
								babyArrow.animation.add('confirm', [13, 17], 24, false);
							case 2:
								babyArrow.x += Note.swagWidth * 2;
								babyArrow.animation.add('static', [2]);
								babyArrow.animation.add('pressed', [6, 10], 12, false);
								babyArrow.animation.add('confirm', [14, 18], 12, false);
							case 3:
								babyArrow.x += Note.swagWidth * 3;
								babyArrow.animation.add('static', [3]);
								babyArrow.animation.add('pressed', [7, 11], 12, false);
								babyArrow.animation.add('confirm', [15, 19], 24, false);
						}
					default:
						babyArrow.frames = Paths.getSparrowAtlas('NOTE_assets', null, true);

						babyArrow.antialiasing = FlxG.save.data.showAntialiasing;
						babyArrow.setGraphicSize(Std.int(babyArrow.width * 0.7));
						babyArrow.x += Note.swagWidth * i;
						babyArrow.setupAnimations();
				}
			}

			babyArrow.updateHitbox();
			babyArrow.scrollFactor.set();

			if (!isStoryMode)
			{
				babyArrow.y -= 10;
				babyArrow.alpha = 0;
				FlxTween.tween(babyArrow, {y: babyArrow.y + 10, alpha: 1}, 1, {ease: FlxEase.circOut, startDelay: 0.5 + (0.2 * i)});
			}

			if (player == 1) {
				playerStrums.add(babyArrow);
			}else {
				babyArrow.ifOpponent = true;
				opponentStrums.add(babyArrow);
			}

			if(SaveData.getData(PLAY_AS_OPPONENT)) {
				babyArrow.ifOpponent = !babyArrow.ifOpponent;
			}

			babyArrow.playAnim('static');
			babyArrow.x += 50;
			babyArrow.x += ((FlxG.width / 2) * player);

			strumLineNotes.add(babyArrow);

			DefaultHandler.strumSize.push([babyArrow.scale.x, babyArrow.scale.y]);
		}
	}

	function tweenCamIn():Void {
		FlxTween.tween(FlxG.camera, {zoom: 1.3}, (Conductor.stepCrochet * 4 / 1000), {ease: FlxEase.elasticInOut});
	}

	override function closeSubState()
	{
		if (paused)
		{
			if (FlxG.sound.music != null && !startingSong)
			{
				resyncVocals();
			}

			if(startTimer != null) {
				if (!startTimer.finished)
					startTimer.active = true;
			}

			paused = false;

			callLua('onResume', []);

			#if windows
			if (startTimer.finished)
			{
				songLength = FlxG.sound.music.length;

				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC, true, - songLength);
			}
			else
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
			}
			#end
		}

		setupKeyStuff();

		super.closeSubState();
	}

	override public function onFocus():Void
	{
		#if windows
		if (health > 0 && !paused)
		{
			if (Conductor.trackPosition > 0.0)
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC, true, songLength - Conductor.trackPosition);
			}
			else
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
			}
		}
		#end

		super.onFocus();
	}
	
	override public function onFocusLost():Void
	{
		#if windows
		if (health > 0 && !paused)
		{
			DiscordClient.changePresence(detailsPausedText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
		}
		#end

		super.onFocusLost();
	}

	public function pauseMusic():Void {
		if (FlxG.sound.music != null) {
			FlxG.sound.music.pause();
			vocals.pause();
		}

		if(startTimer != null) {
			if (!startTimer.finished)
				startTimer.active = false;
		}
	}

	public function resyncVocals():Void {
		if(timeFreeze > 0)
			return;

		vocals.pause();

		if(muteInst)
			FlxG.sound.music.volume = 0;

		FlxG.sound.music.play();
		setSongPosition(FlxG.sound.music.time);
		vocals.time = FlxG.sound.music.time;
		vocals.play();
	}

	function setSongPosition(time:Float):Void {
		var prevTrackPos:Float = Conductor.trackPosition;

		Conductor.songPosition = time;
		Conductor.trackPosition += (Conductor.songPosition - prevTrackPos) * (1 - timeFreeze);
	}

	function longConditionForNote(daNote:Note, center:Float):Bool {
		if(daNote.downscrollNote) {
			if(daNote.getNoteAxis() - daNote.offset.y * daNote.scale.y + daNote.height >= center) {
				return true;
			}
		}else {
			if (daNote.getNoteAxis() + daNote.offset.y * daNote.scale.y <= center) {
				return true;
			}
		}

		return false;
	}

	function caculateNoteY(note:Note, downscroll:Bool):Float {
		var noteCacurations:Float = ((-0.45 * (downscroll ? -1 : 1)) * (Conductor.trackPosition - DefaultHandler.getNoteTime(note.strumTime)) * Note.AFFECTED_SCROLLSPEED * FlxMath.roundDecimal(note.howSpeed, 2));

		if(downscroll && note.isSustainNote) {
			if(note.height < 50) {
				noteCacurations += 10 * (Conductor.crochet / 400) * 3.1 * FlxMath.roundDecimal(note.howSpeed, 2);

				if(isPixel)
					noteCacurations += 8;
			}

			noteCacurations += (Note.swagWidth / 2) - (60.5 * (FlxMath.roundDecimal(note.howSpeed, 2) - 1));
			noteCacurations += 27.5 * ((SONG.bpm / 100) - 1) * (FlxMath.roundDecimal(note.howSpeed, 2) - 1);
		}

		return noteCacurations;
	}

	function addToNoteX(alreadyX:Float, note:Note):Float {
		final noteCacurations:Float = Math.min(0, note.getNoteY());

		var wobbleStrength:Int = 0;
		var modWobble:Float = 0;

		if(note.hasCustomAddon != null)
			wobbleStrength = note.hasCustomAddon.getWobblePower();
		
		if(modifierCheckList('note woggle') && Main.feeshmoraModifiers && wobbleStrength == 0 && !note.isSustainNote) {
			modWobble = flipWiggle * (wobbleModPower * Math.sin(noteCacurations * Math.PI * 0.005));
		}

		if(wobbleStrength > 0 && !note.isSustainNote)
			modWobble = flipWiggle * (wobbleStrength * Math.sin(noteCacurations * Math.PI * 0.005));

		return alreadyX + modWobble;
	}

	private var paused:Bool = false;
	var startedCountdown:Bool = false;
	var canPause:Bool = true;

	override public function update(elapsed:Float)
	{
		#if !debug
		perfectMode = false;
		#end

		if (FlxG.keys.justPressed.NINE)
		{
			if (iconP1.animation.curAnim.name == 'bf-old') {
				iconP1.animation.play(SONG.player1);

				if(iconP1.animation.curAnim.curFrame == 2)
					iconP1.animation.curAnim.curFrame = 1;
			} else
				iconP1.animation.play('bf-old');
		}

		super.update(elapsed);

		noteBeat = curBeat;

		if(playFPS != null && Lib.current.stage.frameRate < playFPS && SONG.modifyFPS) {
			Lib.current.stage.frameRate = playFPS * SaveData.getData(SaveType.FPS_MULTIPLIER);
			Main.framerate = playFPS;
		}

		if(FlxG.save.data.showstuff) {
			counterTxt.text = 'Accuracy: ' + accTotal + '%' + '       ' + 'Miss Clicks: ' + missClicks + '       ' + 'Misses: ' + misses + '       ' + 'Score: ' + songScore;
			counterTxt.screenCenter(X);
		}else
			counterTxt.text = "Score: " + songScore;

		if(prevEventStep != curStep) {
			prevEventStep = curStep;
			eventLoad();
		}

		#if windows
		DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC, true, songLength - FlxG.sound.music.time);
		#end

		events.whenGameIsRunning(eventStorage, this);

		if (controls.PAUSE && startedCountdown && canPause){
			pauseMenu();
		}

		if(hasWarning && !startedCountdown) { //All this just for a simple warning screen...
			persistentUpdate = false;
			persistentDraw = true;
			hasWarning = false;

			warningSprState = new WarningSubGroup([Assets.getText(Paths.txt('${SONG.song.toLowerCase()}/warning'))]);
			warningSprState.screenCenter();
			add(warningSprState);
		}else if(!hasWarning && warningSprState != null && !startedCountdown) {
			if(warningSprState.acceptedTermsOfService) {
				warningSprState.acceptedTermsOfService = false;
				remove(warningSprState);
				inDeBenigin();
			}
		}

		if(FlxG.keys.justPressed.TAB && startedCountdown && canPause) {
			paused = (!paused ? true : false);
			debugText.visible = paused;

			if (paused) {
				pauseMusic();
			}else {
				if (FlxG.sound.music != null && !startingSong) {
					resyncVocals();
				}
	
				if(startTimer != null) {
					if (!startTimer.finished)
						startTimer.active = true;
				}
			}
		}

		if(FlxG.keys.justPressed.SEVEN) {
			DefaultHandler.kill();

			FlxG.switchState(new ChartingState());

			#if windows
			DiscordClient.changePresence("Chart Editor", null, null, true);
			#end
		}

		#if (debug || USING_MOD_DEBUG)
		if(FlxG.keys.justPressed.SIX) {
			songScore += 1000;
			whenSongFinished();
		}
		#end

		// FlxG.watch.addQuick('VOL', vocals.amplitudeLeft);
		// FlxG.watch.addQuick('VOLRight', vocals.amplitudeRight);

		iconP1.setGraphicSize(Std.int(FlxMath.lerp(iconP1.width, 150, 0.1/(Main.framerate/100))));
		iconP2.setGraphicSize(Std.int(FlxMath.lerp(iconP2.width, 150, 0.1/(Main.framerate/100))));

		iconP1.updateHitbox();
		iconP2.updateHitbox();

		var iconOffset:Int = 26;

		iconP1.x = healthBar.x + (healthBar.barWidth * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01) - iconOffset);
		iconP2.x = healthBar.x + (healthBar.barWidth * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01)) - (iconP2.width - iconOffset);

		healthBar.updateValueFromParent();

		if (health > 2)
			health = 2;

		if (healthBar.percent < 20) {
			iconP1.animation.curAnim.curFrame = 1;
		} else {
			if((iconP1.animation.curAnim.name != 'bf-old' || iconP1.animation.curAnim.name != 'bf-pixel') && iconP1.animation.curAnim.name.split('-')[0] == 'bf' && combo >= 100)
				iconP1.animation.curAnim.curFrame = 2;
			else
				iconP1.animation.curAnim.curFrame = 0;
		}

		if (healthBar.percent > 80)
			iconP2.animation.curAnim.curFrame = 1;
		else if (healthBar.percent < 20)
			iconP2.animation.curAnim.curFrame = 2;
		else
			iconP2.animation.curAnim.curFrame = 0;

		if (startingSong)
		{
			if (startedCountdown)
			{
				Conductor.songPosition += FlxG.elapsed * 1000;
				Conductor.trackPosition = Conductor.songPosition + SaveData.getData(NOTE_OFFSET);
				if (Conductor.trackPosition >= 0)
					startSong();
			}
		}
		else
		{
			if(!paused) {
				var prevTrackPos:Float = Conductor.trackPosition;

				Conductor.songPosition += FlxG.elapsed * 1000;
				Conductor.trackPosition += (Conductor.songPosition - prevTrackPos) * (1 - timeFreeze);
			}

			if (!paused)
			{
				songTime += FlxG.game.ticks - previousFrameTime;
				previousFrameTime = FlxG.game.ticks;

				// Interpolation type beat
				if (Conductor.lastSongPos != Conductor.trackPosition)
				{
					songTime = (songTime + Conductor.trackPosition) / 2;
					Conductor.lastSongPos = Conductor.trackPosition;
					// Conductor.trackPosition += FlxG.elapsed * 1000;
					// trace('MISSED FRAME');
				}
			}

			// Conductor.lastSongPos = FlxG.sound.music.time;
		}

		if (generatedMusic && SONG.notes[Std.int(curStep / 16)] != null)
		{
			if (!SONG.notes[Std.int(curStep / 16)].mustHitSection)
			{
				var camFollowX:Float = dad.getMidpoint().x + 150;
				var camFollowY:Float = dad.getMidpoint().y - 100;

				if(curChar != "dad") {
					camMovementPos.x = 0;
					camMovementPos.y = 0;
				}

				curChar = "dad";

				switch (dad.curCharacter)
				{
					case 'mom':
						camFollowY = dad.getMidpoint().y;
					case 'senpai':
						camFollowY = dad.getMidpoint().y - 430;
						camFollowX = dad.getMidpoint().x - 100;
					case 'senpai-angry':
						camFollowY = dad.getMidpoint().y - 430;
						camFollowX = dad.getMidpoint().x - 100;
				}

				camPos.x = camFollowX;
				camPos.y = camFollowY;

				if (dad.curCharacter == 'mom')
					vocals.volume = 1;

				if (SONG.song.toLowerCase() == 'tutorial')
				{
					tweenCamIn();
				}
			}
			
			if(SONG.notes[Std.int(curStep / 16)].mustHitSection)
			{
				var camFollowX:Float = boyfriend.getMidpoint().x - 100;
				var camFollowY:Float = boyfriend.getMidpoint().y - 100;

				if(curChar != "bf") {
					camMovementPos.x = 0;
					camMovementPos.y = 0;
				}

				curChar = "bf";

				switch (curStage)
				{
					case 'limo':
						camFollowX = boyfriend.getMidpoint().x - 300;
					case 'mall':
						camFollowY = boyfriend.getMidpoint().y - 200;
					case 'school':
						camFollowX = boyfriend.getMidpoint().x - 200;
						camFollowY = boyfriend.getMidpoint().y - 200;
					case 'schoolEvil':
						camFollowX = boyfriend.getMidpoint().x - 200;
						camFollowY = boyfriend.getMidpoint().y - 200;
				}

				camPos.x = camFollowX;
				camPos.y = camFollowY;

				if (SONG.song.toLowerCase() == 'tutorial')
				{
					FlxTween.tween(FlxG.camera, {zoom: 1}, (Conductor.stepCrochet * 4 / 1000), {ease: FlxEase.elasticInOut});
				}
			}

			var newCamPos:FlxPoint = stage.setCamPos(camPos);

			if(newCamPos != null) {
				camPos = newCamPos;
			}

			camFollow.setPosition(camPos.x + camMovementPos.x, camPos.y + camMovementPos.y);
		}

		if (camZooming)
		{
			FlxG.camera.zoom = FlxMath.lerp(defaultCamZoom, FlxG.camera.zoom, 0.95);
			camHUD.zoom = FlxMath.lerp(1, camHUD.zoom, 0.95);
			camNOTE.zoom = FlxMath.lerp(1, camNOTE.zoom, 0.95);
		}

		FlxG.watch.addQuick("beatShit", curBeat);
		FlxG.watch.addQuick("stepShit", curStep);

		if (curSong == 'Fresh')
		{
			switch (curBeat)
			{
				case 16:
					camZooming = true;
					gf.danceBeatTimer = 2;
				case 48:
					gf.danceBeatTimer = 1;
				case 80:
					gf.danceBeatTimer = 2;
				case 112:
					gf.danceBeatTimer = 1;
			}
		}

		if (curSong == 'Bopeebo')
		{
			switch (curBeat)
			{
				case 128, 129, 130:
					vocals.volume = 0;
			}
		}
		// better streaming of shit

		// RESET = Quick Game Over Screen
		if (controls.RESET)
		{
			health = 0;
			trace("RESET = True");
		}

		if (health <= 0 && (!modifierCheckList('blue balls') && Main.feeshmoraModifiers || !Main.feeshmoraModifiers)) {
			gameOverScreen();
		}else if(health <= 0 && (modifierCheckList('blue balls') && Main.feeshmoraModifiers)) {
			health = 0;
		}

		if (unspawnNotes[0] != null)
		{
			var spawnTime:Float = 3000;

			spawnTime /= Math.min(1, unspawnNotes[0].howSpeed);

			while(unspawnNotes.length > 0 && unspawnNotes[0].strumTime - Conductor.trackPosition < spawnTime)
			{
				spawnTime /= Math.min(1, unspawnNotes[0].howSpeed);

				var dunceNote:Note = unspawnNotes[0];
				notes.add(dunceNote);

				if(dunceNote.hasCustomAddon != null)
					dunceNote.hasCustomAddon.whenIsSpawned(dunceNote);

				var index:Int = unspawnNotes.indexOf(dunceNote);
				unspawnNotes.splice(index, 1);
			}
		}

		if (generatedMusic && !inCutscene)
		{
			keyShit();
			defaultGameStuff();

			if(trippyFog.alpha == 0.5) {
				var curBet:Float = CustomNoteHandler.yourNoteData.get("trippy")*(Conductor.bpm/120);
				CustomNoteHandler.yourNoteData.set("trippy", CustomNoteHandler.yourNoteData.get("trippy")+0.004);

				trippyWiggle.waveAmplitude = Math.sin(curBet * Math.PI * 6)/30;
			}

			//Nothing here!
			notes.forEachAlive(function(daNote:Note)
			{	
				var strumAngle:Float = 0;
				var strumPos:Float = 0;

				if(daNote.mustPress) {
					strumAngle = currentStrums.members[daNote.noteData].directionAngle;
					strumPos = currentStrums.members[daNote.noteData].y;
				}else {
					strumAngle = oppositeStrums.members[daNote.noteData].directionAngle;
					strumPos = oppositeStrums.members[daNote.noteData].y;
				}

				final centerNote:Float = strumPos + Note.swagWidth / 2;

				daNote.caculatePos = caculateNoteY(daNote, daNote.downscrollNote);
				daNote.setNoteAxis(strumPos, strumAngle);

				// fixed it kinda
				if (daNote.isSustainNote && (daNote.mustPress || !daNote.ignore)
				&& (!daNote.mustPress || (daNote.wasGoodHit || (daNote.prevNote.wasGoodHit && !daNote.canBeHit)))) {
					if(longConditionForNote(daNote, centerNote)) {
						if(daNote.downscrollNote) {
							var swagRect = new FlxRect(0, 0, daNote.frameWidth, daNote.frameHeight);
							swagRect.height = (centerNote - daNote.y) / daNote.scale.y;
							swagRect.y = daNote.frameHeight - swagRect.height;

							daNote.clipRect = swagRect;
						}else {
							var swagRect = new FlxRect(0, 0, daNote.width / daNote.scale.x, daNote.height / daNote.scale.y);
							swagRect.y = (centerNote - daNote.y) / daNote.scale.y;
							swagRect.height -= swagRect.y;

							daNote.clipRect = swagRect;
						}
					}
				}

				if (!daNote.mustPress && daNote.wasGoodHit && !daNote.ignore)
				{
					if (SONG.song != 'Tutorial')
						camZooming = true;

					var altAnim:String = opponentAltAnim;

					if (SONG.notes[Math.floor(curStep / 16)] != null)
					{
						if (SONG.notes[Math.floor(curStep / 16)].altAnim)
							altAnim = '-alt';
					}

					if(daNote.playAnyAnimation) {
						if(!daNote.isSustainNote || (daNote.isSustainNote && currentOpponent.dancing)) {
							currentOpponent.playNoDanceAnim(singAnims[Std.int(Math.abs(daNote.noteData))] + altAnim);
						}

						currentOpponent.holdTimer = 0;
					}

					events.whenNoteIsPressed(daNote, this);
					cameraMovement(daNote.noteData, daNote.isSustainNote);

					if(modifierCheckList('sing drain') && health > 0.2) {
						setHealth(health - (0.02 * singDrainValue));
					}

					oppositeStrums.forEach(function(spr:Strum) {
						if (Math.abs(daNote.noteData) == spr.ID) {
							daNote.hit(spr);
						}
					});

					if (SONG.needsVoices)
						vocals.volume = 1;

					callLua("opponentNoteHit", [daNote.caculatePos, daNote.strumTime, daNote.noteData, daNote.tag, daNote.noteAbstract, daNote.isSustainNote]);
					removeNote(daNote);
				}

				if (daNote.mustPress) {
					daNote.setVisibility(currentStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyVisible);

					daNote.setXaxis(
						currentStrums.members,
						currentStrums.members[Math.floor(Math.abs(daNote.noteData))].x,
						addToNoteX(addLuaToX(currentStrums.members[Math.floor(Math.abs(daNote.noteData))].x, daNote), daNote),
						currentStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle
					);
					
					daNote.setNoteAngle(addLuaToAngle(currentStrums.members[Math.floor(Math.abs(daNote.noteData))].angle, daNote), currentStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle);
					daNote.setNoteAlpha(currentStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyFans, fadeInValue);

					//Nothing planned for now.
					daNote.xAngle = currentStrums.members[Math.floor(Math.abs(daNote.noteData))].xAngle;
					daNote.yAngle = currentStrums.members[Math.floor(Math.abs(daNote.noteData))].yAngle;

					if (daNote.isSustainNote) {
						if(daNote.prevNote.isSustainNote)
							daNote.setXaxisSustain(currentStrums.members, currentStrums.members[Math.floor(Math.abs(daNote.noteData))].x, daNote.prevNote.getInverseAxis(), currentStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle);
						else
							daNote.setXaxisSustain(currentStrums.members, currentStrums.members[Math.floor(Math.abs(daNote.noteData))].x, daNote.getInverseAxis() + (daNote.prevNote.width / 3), currentStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle);
					}
				}
				else {
					daNote.setVisibility(oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyVisible);

					daNote.setXaxis(
						oppositeStrums.members,
						oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].x,
						addToNoteX(addLuaToX(oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].x, daNote), daNote),
						oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle
					);

					daNote.setNoteAngle(addLuaToAngle(oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].angle, daNote), oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle);
					daNote.setNoteAlpha(oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyFans, fadeInValue);

					//Nothing planned for now.
					daNote.xAngle = oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].xAngle;
					daNote.yAngle = oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].yAngle;

					if (daNote.isSustainNote) {
						if(daNote.prevNote.isSustainNote)
							daNote.setXaxisSustain(oppositeStrums.members, oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].x, daNote.prevNote.getInverseAxis(), oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle);
						else
							daNote.setXaxisSustain(oppositeStrums.members, oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].x, daNote.getInverseAxis() + (daNote.prevNote.width / 3), oppositeStrums.members[Math.floor(Math.abs(daNote.noteData))].directionAngle);
					}
				}

				var noteShouldWobble:Bool = false;

				if(modifierCheckList('note woggle') && Main.feeshmoraModifiers) {
					noteShouldWobble = true;
				}

				if(daNote.hasCustomAddon != null) {
					if(daNote.hasCustomAddon.getWobblePower() > 0) {
						noteShouldWobble = true;
					}
				}

				if(noteShouldWobble) {
					if(daNote.isSustainNote) {
						if(camNOTE.camNoteWOBBLE == null) {
							camNOTE.createNoteCam(daNote.noteAbstract);
			
							FlxG.cameras.remove(camNOTE, false);
							FlxG.cameras.add(camNOTE);
							FlxG.cameras.add(camNOTE.camNoteWOBBLE);
							FlxG.cameras.remove(camHUD, false);
							FlxG.cameras.add(camHUD);
						}
			
						if(!daNote.cameras.contains(camNOTE.camNoteWOBBLE)) {
							daNote.cameras = [camNOTE.camNoteWOBBLE];
						}
					}
				}else if(!noteShouldWobble) {
					if(daNote.cameras.contains(camNOTE.camNoteWOBBLE) && daNote.noteAbstract != "side note")
						daNote.cameras = [camNOTE];
				}

				var detector:Bool = Conductor.trackPosition > DefaultHandler.getNoteTime(daNote.strumTime) + 260;

				if (detector && daNote.mustPress)
					{
						if (daNote.isSustainNote && daNote.wasGoodHit)
							{
								removeNote(daNote);
							}
							else 
							{
								if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
	
									if((daNote.tooLate || !daNote.wasGoodHit) && daNote.noteAbstract == "side note") {
										setHealth(health - 2);
									}else{
										setHealth(health - daNote.missDamage());
									}

									vocals.volume = 0;
								}
			
								if(SONG.notes[Math.floor(curStep / 16)].bpm <= 130) {
									if(daNote.tooLate || !daNote.wasGoodHit) {
										if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
											combo = 0;

											if(daNote.isSustainNote)
												missesHold += 1;
											else
												misses += 1;

											if(daNote.playAnyAnimation) {
												FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
												currentPlayer.playNoDanceAnim(singAnims[Std.int(Math.abs(daNote.noteData))] + "miss", true);
											}
										}
									}
								}else{
									if(daNote.tooLate || !daNote.wasGoodHit) {
										if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
											combo = 0;
											
											if(daNote.isSustainNote)
												missesHold += 1;
											else
												misses += 1;

											if(daNote.playAnyAnimation) {
												FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
												currentPlayer.playNoDanceAnim(singAnims[Std.int(Math.abs(daNote.noteData))] + "miss", true);
											}
										}
									}
								}
							}
		
						daNote.active = false;
						daNote.visible = false;
		
						removeNote(daNote);
					}
			});

			#if (USING_LUA && cpp)
			if(HelperStates.luaExist(Type.getClass(this))) {
				updateLuaVars();
			}
			#end
		}
	}

	function pauseMenu():Void {
		persistentUpdate = false;
		persistentDraw = true;
		paused = true;

		pauseMusic();

		var pauseLua:Dynamic = callLua('onPause', []);

		if(pauseLua != 1 && pauseLua != true) {
			// 1 / 1000 chance for Gitaroo Man easter egg
			if (FlxG.random.bool(0.1)) {
				// gitaroo man easter egg
				FlxG.switchState(new GitarooPause());
			} else {
				openSubState(new PauseSubState(currentPlayer.getScreenPosition().x, currentPlayer.getScreenPosition().y));
			}
		}	
	
		#if windows
		DiscordClient.changePresence(detailsPausedText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
		#end
	}

	function keyReleased():Void {
		if(paused || inCutscene)
			return;

		var controlArray = [
			controls.GAME_LEFT_R,
			controls.GAME_DOWN_R,
			controls.GAME_UP_R,
			controls.GAME_RIGHT_R
		];

		if(SONG.fifthKey) {
			controlArray = [
				controls.GAME_LEFT_R,
				controls.GAME_DOWN_R,
				controls.GAME_SPACE_R,
				controls.GAME_UP_R,
				controls.GAME_RIGHT_R
			];
		}

		for(i in 0...controlArray.length) {
			if(controlArray[i]) {
				var spr:Strum = currentStrums.members[i];

				if(spr != null) {
					spr.setColorTransform(1,1,1,1,0,0,0,0);
					spr.playAnim('static');
				}
			}
		}
	}

	function gameOverScreen():Void {
		currentPlayer.stunned = true;

		if(modifierCheckList('blind effect'))
			FlxG.camera.alpha = 1;

		persistentUpdate = false;
		persistentDraw = false;
		paused = true;

		vocals.stop();
		FlxG.sound.music.stop();

		FlxG.camera.zoom = defaultCamZoom;

		setLua("inGameOver", true);

		openSubState(new GameOverSubstate(currentPlayer.getScreenPosition().x, currentPlayer.getScreenPosition().y));
		
		#if windows
		// Game Over doesn't get his own variable because it's only used here
		DiscordClient.changePresence("Game Over - " + detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
		#end
	}

	function whenSongFinished():Void {
		canPause = false;
		FlxG.sound.music.volume = 0;
		vocals.volume = 0;
		vocals.pause();

		if(SaveData.getData(NOTE_OFFSET) > 0) {
			new FlxTimer().start(SaveData.getData(NOTE_OFFSET) / 1000, function(tmr:FlxTimer) {
				endSong();
			});
		}else {
			endSong();
		}
	}

	function endSong():Void
	{
		DefaultHandler.kill();

		if (SONG.validScore && !modifierCheckList('blue balls')) {
			#if !switch
			Highscore.saveScore(SONG.song, songScore, storyDifficulty);
			#end
		}

		if (isStoryMode) {
			campaignScore += songScore;
			storyPlaylist.remove(storyPlaylist[0]);

			if (storyPlaylist.length <= 0) {
				FlxG.sound.playMusic(Paths.music('Main Menu'));
				FlxG.switchState(new StoryMenuState());

				if (SONG.validScore && !modifierCheckList('blue balls')) { //Make sure to not override.
					#if !switch
					Highscore.saveWeekScore(Paths.modJSON.weeks.get("week_" + PlayState.storyWeek).week_name, campaignScore, storyDifficulty);
					#end
				}
			}
			else
			{
				var difficulty:String = "";
				difficulty = '-hard';

				trace('LOADING NEXT SONG');
				trace(PlayState.storyPlaylist[0].toLowerCase() + difficulty);

				if (SONG.song.toLowerCase() == 'eggnog') {
					var blackShit:FlxSprite = new FlxSprite(-FlxG.width * FlxG.camera.zoom,
						-FlxG.height * FlxG.camera.zoom).makeGraphic(FlxG.width * 3, FlxG.height * 3, FlxColor.BLACK);
					blackShit.scrollFactor.set();
					add(blackShit);
					camHUD.visible = false;
					camNOTE.visible = false;

					FlxG.sound.play(Paths.sound('Lights_Shut_off'));
				}

				prevCamFollow = camFollow;

				PlayState.SONG = Song.loadFromJson(PlayState.storyPlaylist[0].toLowerCase() + "-hard", PlayState.storyPlaylist[0]);
				FlxG.sound.music.stop();

				CacheState.loadAndSwitchState(new PlayState());
			}
		}
		else
		{
			trace('WENT BACK TO FREEPLAY??');
			FlxG.switchState(new FreeplayState());
		}

		hasWarning = true;
	}

	var endingSong:Bool = false;

	private function popUpScore(strumtime:Float, id:Int, abby:String):Void
	{
		var noteDiff:Float = Math.abs(strumtime - Conductor.trackPosition);
		vocals.volume = 1;

		var placement:String = Std.string(combo);

		var coolText:FlxText = new FlxText(0, 0, 0, placement, 32);
		coolText.screenCenter();
		coolText.x = FlxG.width * 0.55;
		//

		var rating:FlxSprite = new FlxSprite();
		var score:Int = 350;

		if (noteDiff > Conductor.safeZoneOffset * 0.9)
		{
			if(modifierCheckList('get good')) {
				setHealth(health - 2);
			}

			daRating = 'shit';
			score = 50;
			totalRatingAcc -= 0.75 * GhostTapping.consequence;
			combo = 0;

			setHealth(health - 0.005);
		}
		else if (noteDiff > Conductor.safeZoneOffset * 0.75)
		{
			if(modifierCheckList('get good')) {
				setHealth(health - 2);
			}

			daRating = 'bad';
			score = 100;
			totalRatingAcc -= 0.50 * GhostTapping.consequence;
			combo = 0;

			setHealth(health - 0.002);
		}
		else if (noteDiff > Conductor.safeZoneOffset * 0.2)
		{
			daRating = 'good';
			score = 200;
			totalRatingAcc -= 0.10 * GhostTapping.consequence;
		}else {
			daRating = 'sick';
		}

		songScore += Std.int(score / GhostTapping.consequence);

		var pixelShitPart1:String = "";
		var pixelShitPart2:String = '';
		
		var comboUCM:String = '';

		if(combo > 50)
			comboUCM = '2';

		if (isPixel)
		{
			pixelShitPart1 = 'weeb/pixelUI/';
			pixelShitPart2 = '-pixel';
		}

		rating.loadGraphic(Paths.image(pixelShitPart1 + daRating + pixelShitPart2 + comboUCM));
		rating.screenCenter();
		rating.x = coolText.x - 40;
		rating.y -= 60;
		rating.acceleration.y = 550;
		rating.velocity.y -= FlxG.random.int(140, 175);
		rating.velocity.x -= FlxG.random.int(0, 10);

		var timer:Float = Math.round(noteDiff*1000)/1000;

		var comboSpr:FlxSprite = new FlxSprite().loadGraphic(Paths.image(pixelShitPart1 + 'combo' + pixelShitPart2));
		comboSpr.screenCenter();
		comboSpr.x = coolText.x;
		comboSpr.acceleration.y = 600;
		comboSpr.velocity.y -= 150;

		comboSpr.velocity.x += FlxG.random.int(1, 10);
		add(rating);

		if (!isPixel)
		{
			rating.setGraphicSize(Std.int(rating.width * 0.7));
			rating.antialiasing = FlxG.save.data.showAntialiasing;
			comboSpr.setGraphicSize(Std.int(comboSpr.width * 0.7));
			comboSpr.antialiasing = FlxG.save.data.showAntialiasing;
		}
		else
		{
			rating.setGraphicSize(Std.int(rating.width * daPixelZoom * 0.7));
			comboSpr.setGraphicSize(Std.int(comboSpr.width * daPixelZoom * 0.7));
		}

		comboSpr.updateHitbox();
		rating.updateHitbox();

		var seperatedScore:Array<Int> = [];

		seperatedScore.push(Math.floor(combo / 100));
		seperatedScore.push(Math.floor((combo - (seperatedScore[0] * 100)) / 10));
		seperatedScore.push(combo % 10);

		var daLoop:Int = 0;
		for (i in seperatedScore)
		{
			var numScore:FlxSprite = new FlxSprite().loadGraphic(Paths.image(pixelShitPart1 + 'num' + Std.int(i) + pixelShitPart2));
			numScore.screenCenter();
			numScore.x = coolText.x + (43 * daLoop) - 90;
			numScore.y += 80;

			if (!isPixel)
			{
				numScore.antialiasing = FlxG.save.data.showAntialiasing;
				numScore.setGraphicSize(Std.int(numScore.width * 0.5));
			}
			else
			{
				numScore.setGraphicSize(Std.int(numScore.width * daPixelZoom));
			}
			numScore.updateHitbox();

			numScore.acceleration.y = FlxG.random.int(200, 300);
			numScore.velocity.y -= FlxG.random.int(140, 160);
			numScore.velocity.x = FlxG.random.float(-5, 5);

			if (combo >= 10 || combo == 0)
				add(numScore);

			FlxTween.tween(numScore, {alpha: 0}, 0.2, {
				onComplete: function(tween:FlxTween)
				{
					numScore.destroy();
				},
				startDelay: Conductor.crochet * 0.002
			});

			daLoop++;
		}
		/* 
			trace(combo);
			trace(seperatedScore);
		 */

		coolText.text = Std.string(seperatedScore);
		// add(coolText);

		FlxTween.tween(rating, {alpha: 0}, 0.2, {
			startDelay: Conductor.crochet * 0.001
		});

		FlxTween.tween(comboSpr, {alpha: 0}, 0.2, {
			onComplete: function(tween:FlxTween)
			{
				coolText.destroy();
				comboSpr.destroy();

				rating.destroy();
			},
			startDelay: Conductor.crochet * 0.001
		});

		curSection += 1;
	}

	function defaultGameStuff():Void {
		if(paused || inCutscene)
			return;

		var controlHoldArray = [
			controls.GAME_LEFT,
			controls.GAME_DOWN,
			controls.GAME_UP,
			controls.GAME_RIGHT
		];

		if(SONG.fifthKey) {
			controlHoldArray = [
				controls.GAME_LEFT,
				controls.GAME_DOWN,
				controls.GAME_SPACE,
				controls.GAME_UP,
				controls.GAME_RIGHT
			];
		}

		notes.forEachAlive(function(daNote:Note) {
			if (daNote.canBeHit && daNote.mustPress && !daNote.tooLate
			&& !daNote.wasGoodHit && controlHoldArray[daNote.noteData] && daNote.isSustainNote) {
				goodNoteHit(daNote);
			}
		});

		if(boyfriend.holdTimer > Conductor.stepCrochet * 0.0011 * boyfriend.singMultiplier && boyfriend.animation.curAnim.name.startsWith('sing') && !boyfriend.animation.curAnim.name.endsWith('miss')) {
			boyfriend.dance();
		}
	}

	function keyShit():Void
	{
		if(paused || inCutscene)
			return;

		var checkControlStatus:Bool = false;

		var controlArray = [
			controls.GAME_LEFT_P,
			controls.GAME_DOWN_P,
			controls.GAME_UP_P,
			controls.GAME_RIGHT_P
		];

		if(SONG.fifthKey) {
			controlArray = [
				controls.GAME_LEFT_P,
				controls.GAME_DOWN_P,
				controls.GAME_SPACE_P,
				controls.GAME_UP_P,
				controls.GAME_RIGHT_P
			];
		}

		if (generatedMusic && controlArray.contains(true)) {
			var noteCaculation:Bool = false;

			var noteList:Array<Array<Note>> = [];
			var pressedNotes:Array<Note> = [];

			setSongPosition(FlxG.sound.music.time);

			notes.forEachAlive(function(daNote:Note) {
				if(daNote.canBeHit && daNote.mustPress && !daNote.tooLate
				&& !daNote.wasGoodHit && !daNote.isSustainNote) {
					for(i in 0...controlArray.length) {
						if(controlArray[i] && daNote.noteData == i) {
							if(noteList[i] == null) {
								noteList[i] = [];
							}

							noteList[i].push(daNote);
						}
					}
				}
			});

			var counter:Int = 0;

			/**
			* Better Jack detection.
			*/
			for(noteSections in noteList) {
				if(noteSections != null) {
					noteSections.sort((a, b) -> Std.int(DefaultHandler.getNoteTime(a.strumTime) - DefaultHandler.getNoteTime(b.strumTime)));

					for(n in 0...noteSections.length) {
						var note:Note = noteSections[n].getNoteHittable(pressedNotes);
			
						if(note != null) {
							removeNote(note);
						}else {
							goodNoteHit(noteSections[n]);
							pressedNotes.push(noteSections[n]);
							break;
						}
					}
				}else {
					counter++;
				}
			}

			if(counter == noteList.length) {
				if(!GhostTapping.ghostTap) {
					for(i in 0...controlArray.length) {
						if(controlArray[i]) {
							noteMiss(i);
							break;
						}
					}
				}

				missClicks++;

				currentStrums.forEach(function(spr:Strum) {
					if(!CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)) {
						if(controlArray[spr.noteData]) {
							spr.playAnim('pressed');
						}
					}
				});

				counter = 0;
			}
		}

		keyReleased();
	}

	function noteMiss(direction:Int = 1, ?note:Note, ?evenTho:Bool = false):Void
	{
		if(note != null) {
			if(CustomNoteHandler.dontHitNotes.contains(note.noteAbstract) && !evenTho) {
				return;
			}
		}

		if (!currentPlayer.stunned)
		{
			setHealth(health - 0.04);

			if(gf != null) {
				if (combo > 5 && gf.animOffsets.exists('sad'))
				{
					gf.playNoDanceAnim('sad');
				}
			}

			combo = 0;

			if(note == null) {
				FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
				songScore -= 10;
			}else {
				if(CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)) {
					songScore -= 30;
				}else {
					callLua("noteMiss", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);
					songScore -= 10;
				}
			}

			currentPlayer.stunned = true;

			// get stunned for 5 seconds
			new FlxTimer().start(5 / 60, function(tmr:FlxTimer)
			{
				currentPlayer.stunned = false;
			});

			if(note == null) {
				FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
				currentPlayer.playNoDanceAnim(singAnims[direction] + "miss", true);
			}else {
				if(note.playAnyAnimation) {
					FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
					currentPlayer.playNoDanceAnim(singAnims[direction] + "miss", true);
				}
			}
		}
	}

	function goodNoteHit(note:Note):Void
	{
		if (!note.wasGoodHit)
		{
			if(CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)){

				if(note.noteAbstract == "trippy")	{
					setHealth(health - 0.3);
				}else if(note.noteAbstract == "planet notes") {
					setHealth(health - 0.4);
				}
			}

			if (!note.isSustainNote && !CustomNoteHandler.dontHitNotes.contains(note.noteAbstract))
			{
				popUpScore(DefaultHandler.getNoteTime(note.strumTime), note.noteData, note.noteAbstract);
				combo += 1;
			}

			setHealth(health + note.giveHealth());

			if(note.noteAbstract == "spiritual star")
				setHealth(health - 0.054);
			
			if(note.noteAbstract == "cherry") {

				if(SONG.fifthKey && note.noteData == 2) {
					setHealth(health + 1);
					FlxG.sound.play(Paths.sound("confirmMenu"));
				} else {
					setHealth(health + 0.069);
				}	
			}

			if(note.noteAbstract == "trippy") {

				if(waterBlur[1] != null) {
						
					if(waterBlur[1].blurX <= 0) {
						waterBlur[1].blurX -= 1;
						waterBlur[1].blurY -= 1;
						camNOTE.setTrashFilters([waterBlur[1]]);
					}else {
						waterBlur[1] = new BlurFilter(1, 1, BitmapFilterQuality.LOW);
						camNOTE.setTrashFilters([]);

						if(waterFog.alpha == 0.25)
							waterFog.alpha = 0;
					}

					camGame.setTrashFilters([]);
				}

				if(trippyFog.alpha == 0) {
					trippyFog.alpha = 0.5;
					FlxG.sound.play(Paths.sound("drugsl"));
					camGame.setTrashFilters([waterBlur[0], trippyShader]);
					camNOTE.setTrashFilters([trippyShader]);

					if(waterBlur[0].blurX <= defaultBlur+2) {
						waterBlur[0].blurX = defaultBlur+3;
						waterBlur[0].blurY = defaultBlur+3;
					}
				}
			}else {
				if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract)) {
					
					if(waterBlur[1] != null) {
						
						if(waterBlur[1].blurX <= 0) {
							waterBlur[1].blurX -= 1;
							waterBlur[1].blurY -= 1;
							camNOTE.setTrashFilters([waterBlur[1]]);
						}else {
							waterBlur[1] = new BlurFilter(1, 1, BitmapFilterQuality.LOW);
							camNOTE.setTrashFilters([]);

							if(waterFog.alpha == 0.25) {
								waterFog.alpha = 0;
								FlxG.sound.play(Paths.sound("splashlol"));
		
								if(waterBlur[0].blurX >= defaultBlur+3) {
									waterBlur[0].blurX = defaultBlur;
									waterBlur[0].blurY = defaultBlur;
									camGame.setTrashFilters([waterBlur[0]]);
								}
							}
						}
					}
				}

				if(trippyFog.alpha == 0.5) {
					trippyFog.alpha = 0;
					FlxG.sound.play(Paths.sound("drugsl"));

					if(waterBlur[0].blurX >= defaultBlur+3) {
						waterBlur[0].blurX = defaultBlur;
						waterBlur[0].blurY = defaultBlur;
						camGame.setFilters([waterBlur[0]]);
					}
				}
			}

			note.pressedByPlayer(currentPlayer, currentOpponent, gf);
			currentPlayer.customAnimation = true;

			if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract) &&
			(currentPlayer.customAnimation && (currentPlayer.animation.curAnim.name.startsWith("sing") || currentPlayer.dancing))) {
				var animPlay:String = singAnims[Std.int(Math.abs(note.noteData))] + playerAltAnim + currentPlayer.hasBePlayer;

				events.whenNoteIsPressed(note, this);
				cameraMovement(note.noteData, note.isSustainNote);

				currentPlayer.customAnimation = false;

				if(note.playAnyAnimation) {
					if(!note.isSustainNote || (note.isSustainNote && currentPlayer.dancing)) {
						currentPlayer.playNoDanceAnim(animPlay, true);
					}

					currentPlayer.holdTimer = 0;
				}
			}

			var spr:Strum = currentStrums.members[note.noteData];

			if(note.noteAbstract != null)
				spr.ifCustom = note.noteAbstract;
			else
				spr.ifCustom = "regular";

			note.hit(spr);

			if(!isPixel) {
				note.splash(grpSplash.members[spr.ID], spr, daRating);
			}

			if(note.hasCustomAddon != null) {
				var noteSprite:FlxSprite = note.hasCustomAddon.createSpriteWhenHit();

				if(noteSprite != null) {
					customNoteSprites.add(noteSprite);
				}
			}

			if(!CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)) {
				note.wasGoodHit = true;
				vocals.volume = 1;

				hits++;
			}

			callLua("goodNoteHit", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);

			if (!note.isSustainNote) {
				removeNote(note);
			}
		}
	}

	private function cameraMovement(noteCData:Int, isSus:Bool) {
		if(modifierCheckList('camera move') && Main.feeshmoraModifiers && !isSus) {
			if(noteCData == 0) {
				camMovementPos.x = (-SONG.bpm / 45) * 5 * cameraMovementInsensity;
				camMovementPos.y = 0;
			}

			if(noteCData == (strumLineNotes.members.length / 2) - 1) {
				camMovementPos.x = (SONG.bpm / 45) * 5 * cameraMovementInsensity;
				camMovementPos.y = 0;
			}

			if(noteCData == 1) {
				camMovementPos.y = (SONG.bpm / 45) * 5 * cameraMovementInsensity;
				camMovementPos.x = 0;
			}

			if(noteCData == (strumLineNotes.members.length / 2) - 2) {
				camMovementPos.y = (-SONG.bpm / 45) * 5 * cameraMovementInsensity;
				camMovementPos.x = 0;
			}
		}
	}

	function removeNote(note:Note) {
		note.active = false;

		note.kill();

		if(note.trail != null)						
			remove(note.trail);

		notes.remove(note, true);
		note.destroy();
	}

	function addLuaToX(daX:Float, note:Note):Float {
		var xLua:Null<Float> = callLua("addToNoteX", [daX, note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);
		var finalLuaVar:Float = daX;

		if(xLua != null)
			finalLuaVar = xLua + daX;

		return finalLuaVar;
	}

	function addLuaToAngle(daAngle:Float, note:Note):Float {
		var xLua:Null<Float> = callLua("addToNoteAngle", [daAngle, note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);
		var finalLuaVar:Float = daAngle;

		if(xLua != null)
			finalLuaVar = xLua + daAngle;

		return finalLuaVar;
	}

	/**
	* Reason why the variables are named the same as Psych Engine is so transferring lua scripts can be easier.
	*/
	
	function getLuaScript():Void {
		#if (USING_LUA && cpp)
		if(Assets.exists(Paths.getPath('scripts/${"stage/" + curStage.toLowerCase()}.lua', TEXT, null))) {
			Register.detachLuaFromState(PlayState);
			Register.attachLuaToState(PlayState, Paths.lua("stage/" + curStage.toLowerCase()));
			getModLua().execute();
		}
		#end
	}

	function generateStaticLua():Void {
		modifiableSprites.set("iconP1", iconP1);
		modifiableSprites.set("iconP2", iconP2);
		modifiableSprites.set("healthBarBG", healthBarBG);
		modifiableSprites.set("healthBar", healthBar);
		modifiableSprites.set("boyfriend", boyfriend);
		modifiableSprites.set("gf", gf);
		modifiableSprites.set("dad", dad);

		modifiableCameras.set("camHUD", camHUD);
		modifiableCameras.set("camGAME", FlxG.camera);
		modifiableCameras.set("camNOTE", camNOTE);

		setLua("songName", PlayState.SONG.song);
		setLua("isStoryMode", PlayState.isStoryMode);
		setLua("startedCountdown", false);
		setLua("difficulty", PlayState.storyDifficulty);
		setLua("difficultyName", CoolUtil.difficultyArray[PlayState.storyDifficulty]);
		setLua("week", Paths.modJSON.weeks.get("week_" + PlayState.storyWeek).week_name.toUpperCase());
		setLua("weekRaw", PlayState.storyWeek);
		setLua("totalKeysForStrum", PlayState.SONG.fifthKey ? 5 : 4);
		setLua("hasCutscene", PlayState.SONG.video != null ? true : false);
		setLua("inGameOver", false);

		setLua("defaultBoyfriendX", boyfriend.x);
		setLua("defaultBoyfriendY", boyfriend.y);
		setLua("defaultOpponentX", dad.x);
		setLua("defaultOpponentY", dad.y);

		if(gf != null) {
			setLua("defaultGirlfriendX", gf.x);
			setLua("defaultGirlfriendY", gf.y);
		}else {
			setLua("defaultGirlfriendX", 0);
			setLua("defaultGirlfriendY", 0);
		}

		addCallback("callEvent", function(skill:String, value:String, value2:String) {
			events.whenTriggered(skill, value, value2, this);
		});

		addCallback("instaKillPlayer", function() {
			gameOverScreen();
		});

		addCallback("createCharacterSprite", function(name:String, characterName:String, x:Float, y:Float) {
			if(getModLua().luaSprites.exists(name)) {
                return;
            }

			var characterSprite:Character = new Character(x, y, characterName);
			characterSprite.refresh(characterName, camPos);
			characterSprite.active = true;

            getModLua().luaSprites.set(name, characterSprite);
		});

		addCallback("addSpriteToStage", function(name:String) {
			var spr:FlxSprite = getModLua().getSprite(name);

            if(spr == null) {
                return;
            }

			stage.add(spr);
		});

		addCallback("removeSpriteToStage", function(name:String) {
			var spr:FlxSprite = getModLua().getSprite(name);

            if(spr == null) {
                return;
            }

			stage.remove(spr);
		});

		addCallback("setHealthBarColors", function(opponentHex:String, playerHex:String) {
			var opponentColor:FlxColor = 0;
			var playerColor:FlxColor = 0;

			if(!opponentHex.startsWith("0x")) {
				opponentColor = Std.parseInt('0xff' + opponentHex);
			}else {
				opponentColor = Std.parseInt(opponentHex);
			}

			if(!playerHex.startsWith("0x")) {
				playerColor = Std.parseInt('0x' + playerHex);
			}else {
				playerColor = Std.parseInt(playerHex);
			}

			healthBar.createFilledBar(opponentColor, playerColor);
		});

		addCallback("doTweenHealthBarColor", function(name:String, side:String, hex:String, duration:Float, ease:String) {
			var barColor:FlxColor = 0;

			if(!hex.startsWith("0x")) {
				barColor = Std.parseInt('0xff' + hex);
			}else {
				barColor = Std.parseInt(hex);
			}

			if(side == "left" || side == "opponent") {
				getModLua().luaTweens.set(name, FlxTween.color(healthBar.emptyBar, duration, healthBar.emptyColor, barColor, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        getModLua().luaTweens.remove(name);
						callLua('onTweenCompleted', [name]);
                    }
				}));
			}

			if(side == "right" || side == "player") {
				getModLua().luaTweens.set(name, FlxTween.color(healthBar.filledBar, duration, healthBar.filledColor, barColor, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        getModLua().luaTweens.remove(name);
						callLua('onTweenCompleted', [name]);
                    }
				}));
			}
		});

		addCallback("setHealthBarColor", function(hex:String, side:String) {
			var hexColor:FlxColor = 0;

			if(!hex.startsWith("0x")) {
				hexColor = Std.parseInt('0xff' + hex);
			}else {
				hexColor = Std.parseInt(hex);
			}

			if(side == "left" || side == "opponent") {
				healthBar.emptyColor = hexColor;
			}

			if(side == "right" || side == "player") {
				healthBar.filledColor = hexColor;
			}
		});
	}

	function makeNoteLua():Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			for(i in 0...playerStrums.members.length) {
				setLua('defaultPlayerStrumX' + i, playerStrums.members[i].x);
				setLua('defaultPlayerStrumY' + i, playerStrums.members[i].y);
			}
	
			for (i in 0...opponentStrums.members.length) {
				setLua('defaultOpponentStrumX' + i, opponentStrums.members[i].x);
				setLua('defaultOpponentStrumY' + i, opponentStrums.members[i].y);
			}

			addCallback("setNoteStrumPos", function(id:Int, x:Float, y:Float) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];
	
				strumOBJ.x = x;
				strumOBJ.y = y;
			});
	
			addCallback("setNoteStrumAngle", function(id:Int, angle:Float) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];
				strumOBJ.angle = angle;
			});
	
			addCallback("setPlayerStrumDirection", function(id:Int, angle:Float) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];
				strumOBJ.directionAngle = angle;
			});

			addCallback("noteTweenX", function(name:String, id:Int, value:Dynamic, duration:Float, ease:String) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];

				if(strumOBJ != null) {
					getModLua().luaTweens.set(name, FlxTween.tween(strumOBJ, {x: value}, duration, {ease: Register.getFlxEaseByString(ease),
						onComplete: function(twn:FlxTween) {
							getModLua().luaTweens.remove(name);
							callLua('onTweenCompleted', [name]);
						}
					}));
				}
			});

			addCallback("noteTweenY", function(name:String, id:Int, value:Dynamic, duration:Float, ease:String) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];

				if(strumOBJ != null) {
					getModLua().luaTweens.set(name, FlxTween.tween(strumOBJ, {y: value}, duration, {ease: Register.getFlxEaseByString(ease),
						onComplete: function(twn:FlxTween) {
							getModLua().luaTweens.remove(name);
							callLua('onTweenCompleted', [name]);
						}
					}));
				}
			});

			addCallback("noteTweenAngle", function(name:String, id:Int, value:Dynamic, duration:Float, ease:String) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];

				if(strumOBJ != null) {
					getModLua().luaTweens.set(name, FlxTween.tween(strumOBJ, {angle: value}, duration, {ease: Register.getFlxEaseByString(ease),
						onComplete: function(twn:FlxTween) {
							getModLua().luaTweens.remove(name);
							callLua('onTweenCompleted', [name]);
						}
					}));
				}
			});

			addCallback("noteTweenDirection", function(name:String, id:Int, value:Dynamic, duration:Float, ease:String) {
				var strumOBJ:Strum = strumLineNotes.members[Std.int(Math.abs(id)) % strumLineNotes.length];

				if(strumOBJ != null) {
					getModLua().luaTweens.set(name, FlxTween.tween(strumOBJ, {directionAngle: value}, duration, {ease: Register.getFlxEaseByString(ease),
						onComplete: function(twn:FlxTween) {
							getModLua().luaTweens.remove(name);
							callLua('onTweenCompleted', [name]);
						}
					}));
				}
			});
		}
		#end
	}

	function updateLuaVars():Void {
		setLua('cameraX', camFollow.x);
		setLua('cameraY', camFollow.y);

		setLua("score", songScore);
		setLua("misses", misses);
		setLua("hits", hits);

		setLua("boyfriendName", boyfriend.curCharacter);
		setLua("dadName", dad.curCharacter);

		if(gf != null) {
			setLua("gfName", gf.curCharacter);
		}else {
			setLua("gfName", "");
		}

		setLua('downscroll', SaveData.getData(DOWNSCROLL));
		setLua('framerate', Lib.current.stage.frameRate);
		setLua('ghostTapping', GhostTapping.ghostTap);
		setLua("songLength", FlxG.sound.music.length);
		setLua("trackPos", Conductor.trackPosition);

		setLua("iconP1_ID_Regular", iconP1.iconAnimInfo[0]);
		setLua("iconP2_ID_Regular", iconP2.iconAnimInfo[0]);
		setLua("iconP1_ID_Dead", iconP1.iconAnimInfo[1]);
		setLua("iconP2_ID_Dead", iconP2.iconAnimInfo[1]);
		setLua("iconP1_ID_Winning", iconP1.iconAnimInfo[2]);
		setLua("iconP2_ID_Winning", iconP2.iconAnimInfo[2]);
	}

	function updatePerSectionLuaVars():Void {
		setLua("bpm", PlayState.SONG.bpm);
		setLua("scrollspeed", PlayState.SONG.speed);
		setLua("mustHitSection", SONG.notes[Std.int(curStep / 16)].mustHitSection);
		setLua("altAnim", SONG.notes[Math.floor(curStep / 16)].altAnim);
	}

	function eventLoad():Void {
		if(eventInfo.length == 0)
			return;

		var gridY = Reflect.field(eventInfo[0], "modGridY");

		if((curStep*40) == gridY)
			return eventLoad_DefaultHandler();
		else
			return;
	}

	function eventLoad_DefaultHandler():Void {
		var value:String = Reflect.field(eventInfo[0], "modValue");
		var value2:String = Reflect.field(eventInfo[0], "modValueTwo");
		var skill:String = Reflect.field(eventInfo[0], "modSkill");

		eventInfo.shift();

		if(!eventStorage.contains(skill))
			eventStorage.push(skill);

		value = value.toLowerCase();
		value2 = value2.toLowerCase();

		events.whenTriggered(skill, value, value2, this);

		callLua("whenEventTriggered", [skill, value, value2]);
	}

	function set_wobbleModPower(value:Float):Float {
		wobbleModPower = value;
		camNOTE.wobblePower = wobbleModPower * flipWiggle;
		return wobbleModPower;
	}

	//Getter Functions
	override function get_songPos():Float
		return Conductor.trackPosition;

	function get_currentStrums():FlxTypedSpriteGroup<Strum> {
		if(SaveData.getData(PLAY_AS_OPPONENT))
			return opponentStrums;
		else
			return playerStrums;
	}

	function get_oppositeStrums():FlxTypedSpriteGroup<Strum> {
		if(SaveData.getData(PLAY_AS_OPPONENT))
			return playerStrums;
		else
			return opponentStrums;
	}

	function get_currentPlayer():Character {
		if(SaveData.getData(PLAY_AS_OPPONENT))
			return dad;
		else
			return boyfriend;
	}

	function get_currentOpponent():Character {
		if(SaveData.getData(PLAY_AS_OPPONENT))
			return boyfriend;
		else
			return dad;
	}

	function get_accTotal():Float {
		return Math.floor(((totalNotesLoaded - misses - missesHold + totalRatingAcc)/totalNotesLoaded)*10000)/100;
	}

	function get_wobbleModPower():Float {
		if(Main.feeshmoraModifiers && DefaultHandler.modifiers.wobbleNotes.enabled) {
			return wobbleModPower;
		}

		return 30;
	}

	override function stepHit()
	{
		super.stepHit();

		if ((FlxG.sound.music.time > Conductor.songPosition + 20 || FlxG.sound.music.time < Conductor.songPosition - 20) && !paused)
		{
			resyncVocals();
		}

		if(CustomNoteHandler.yourNoteData["side note"] != null) {
			if(FlxFlicker.isFlickering(CustomNoteHandler.yourNoteData["side note"])) {
				FlxG.sound.play(Paths.sound('Warning'), 0.25);
			}
		}

		stage.curStep();
	}

	var lightningStrikeBeat:Int = 0;
	var lightningOffset:Int = 8;

	override function beatHit()
	{
		super.beatHit();

		if (generatedMusic)
		{
			notes.sort(FlxSort.byY, FlxSort.DESCENDING);
		}

		if (gf != null) {
			if(gf.animation.curAnim != null) {
				if (curBeat % gf.danceBeatTimer == 0 && !gf.animation.curAnim.name.startsWith("sing") && !gf.stunned && gf.shouldPlayDance) {
					gf.dance();
				}
			}
		}

		if(dad.animation.curAnim != null) {
			if (curBeat % dad.danceBeatTimer == 0 && !dad.animation.curAnim.name.startsWith("sing") && !dad.stunned && dad.shouldPlayDance) {
				dad.dance();
			}
		}

		if(boyfriend.animation.curAnim != null) {
			if (curBeat % boyfriend.danceBeatTimer == 0 && !boyfriend.animation.curAnim.name.startsWith("sing") && !boyfriend.stunned && boyfriend.shouldPlayDance) {
				boyfriend.dance();
			}
		}

		if(dad.holdTimer < Conductor.stepCrochet * 0.0011 * boyfriend.singMultiplier) {
			var dadAnim:String = dad.animation.curAnim.name;
			
			if(dadAnim.startsWith("sing")) {
				dad.playNoDanceAnim(dadAnim, true);
			}
		}

		if(boyfriend.holdTimer < Conductor.stepCrochet * 0.0011 * boyfriend.singMultiplier) {
			var boyfriendAnim:String = boyfriend.animation.curAnim.name;
			
			if(boyfriendAnim.startsWith("sing")) {
				boyfriend.playNoDanceAnim(boyfriendAnim, true);
			}
		}

		if (SONG.notes[Math.floor(curStep / 16)] != null)
		{
			if (SONG.notes[Math.floor(curStep / 16)].changeBPM)
			{
				Conductor.changeBPM(SONG.notes[Math.floor(curStep / 16)].bpm);
				FlxG.log.add('CHANGED BPM!');
			}
			// else
			// Conductor.changeBPM(SONG.bpm);
		}
		// FlxG.log.add('change bpm' + SONG.notes[Std.int(curStep / 16)].changeBPM);
		wiggleShit.update(Conductor.crochet);

		// HARDCODING FOR MILF ZOOMS!
		if (curSong.toLowerCase() == 'milf' && curBeat >= 168 && curBeat < 200 && camZooming && FlxG.camera.zoom < 1.35)
		{
			FlxG.camera.zoom += 15 * FlxG.elapsed;
			camHUD.zoom += 6 * FlxG.elapsed;
			camNOTE.zoom += 6 * FlxG.elapsed;
		}

		if(curBeat % 4 == 0) {
			if (camZooming && FlxG.camera.zoom < 1.35) {
				FlxG.camera.zoom += 15 * FlxG.elapsed;
				camHUD.zoom += 6 * FlxG.elapsed;
				camNOTE.zoom += 6 * FlxG.elapsed;
			}
	
			#if (USING_LUA && cpp)
			if(HelperStates.luaExist(Type.getClass(this))) {
				updatePerSectionLuaVars();
			}
			#end
		}

		iconP1.setGraphicSize(Std.int(iconP1.width + 30));
		iconP2.setGraphicSize(Std.int(iconP2.width + 30));
		iconP1.updateHitbox();
		iconP2.updateHitbox();

		if (curBeat % 8 == 7 && curSong == 'Bopeebo')
		{
			boyfriend.playNoDanceAnim('hey', true);
		}

		if (curBeat % 16 == 15 && SONG.song == 'Tutorial' && dad.curCharacter == 'gf' && curBeat > 16 && curBeat < 48)
		{
			boyfriend.playNoDanceAnim('hey', true);
			dad.playNoDanceAnim('cheer', true);
		}

		stage.curBeat();
	}

	@:access(flixel.FlxGame)
	function clearCache():Void {
		if(!(cast FlxG.game._requestedState is PlayState)) {
			Cache.clear();
		}
	}

	override public function destroy() {
		super.destroy();

		FlxG.sound.destroy();

		stage = FlxDestroyUtil.destroy(stage);
		events = FlxDestroyUtil.destroy(events);

		eventInfo = null;

		if(getModLua() != null) {
			getModLua().close();
			Register.detachLuaFromState(PlayState);
		}

		DefaultHandler.kill();

		clearCache();
	}
}