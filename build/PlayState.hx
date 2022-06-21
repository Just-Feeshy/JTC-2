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
import flixel.ui.FlxBar;
import flixel.util.FlxCollision;
import flixel.util.FlxColor;
import flixel.util.FlxSort;
import flixel.util.FlxStringUtil;
import flixel.util.FlxTimer;
import betterShit.BetterCams;
import haxe.Json;
import lime.utils.Assets;
import openfl.system.System;
import openfl.display.BlendMode;
import openfl.display.StageQuality;
import openfl.filters.ShaderFilter;
import feshixl.group.FeshEventGroup;
import feshixl.interfaces.IDialogue;
import openfl.Lib;

import example_code.DefaultStage;
import template.CustomNote;
import template.StageBuilder;

import flash.filters.BlurFilter;
import flash.filters.BitmapFilterQuality;

import SaveData.SaveType;
import Feeshmora;

using StringTools;

class PlayState extends MusicBeatState
{
	//More Stuff
	private var stageGroup:FlxTypedGroup<StageBuilder>;

	private var createdCharacters:Bool;
	private var trippyFog:FlxSprite;
	private var waterFog:FlxSprite;
	private var testSprite:FlxSprite;
	private var warningSprState:WarningSubGroup;
	private var debugText:FlxText;
	private var curChar:String = '';
	private var camMovementPos:FlxPoint;
	private var prevTrackPos:Float = 0;

	private var healthTween:FlxTween;

	public var camPos:FlxPoint;
	public var flipWiggle:Int = 1;
	public var health:Float = 1;

	public var opponentAltAnim:String = "";
	public var playerAltAnim:String = "";

	private var isPixel:Bool = false;

	//Modifier/Event Stuff
	public var eventCounter:Int = 0;
	public var prevEventStep:Int = 0;

	//Chart Shit
	public static var muteInst:Bool;
	public static var modStorage:Array<String> = [];

	//Camera Shit
	public static var camHUD:BetterCams;
	public static var camNOTE:CameraNote;
	public static var camSCENERY:BetterCams;

	//Note Stuff Funk U
	private var waterBlur:Array<BlurFilter> = [];
	private var trippyWiggle:WiggleEffect = new WiggleEffect();
	private var triggerGroup:FlxTypedGroup<FlxSprite>;
	private var grpSplash:FlxTypedGroup<SplashSprite>;
	private var trippyShader:ShaderFilter;

	//Controls
	private var keysMatrix:Array<Array<FlxKey>> = [];

	//Da Variables
	private var misses:Int = 0;
	private var missClicks:Int = 0;
	private var accuracy:Float = 100;
	private var maxAcc:Float = 100;
	private var accTotal:Float = 100;
	private var defaultBlur:Float = 0;
	private var playFPS:Null<Int> = Main.framerate;
	private var counterTxt:FlxText;

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

	//public var testers(default, set):Int;

	private var vocals:FlxSound;

	public var dad:Character;
	public var gf:Character;
	public var boyfriend:Boyfriend;

	public var notes:FlxTypedGroup<Note>;
	public var unspawnNotes:Array<Note> = [];

	private var strumLine:FlxSprite;
	private var curSection:Int = 0;

	private var camFollow:FlxObject;

	private static var prevCamFollow:FlxObject;

	public var strumLineNotes:FlxTypedGroup<Strum>;

	public static var playerStrums:FlxTypedSpriteGroup<Strum>;
	public static var opponentStrums:FlxTypedSpriteGroup<Strum>;

	private var camZooming:Bool = false;
	private var curSong:String = "";

	private var gfSpeed:Int = 1;
	private var combo:Int = 0;

	private var healthBarBG:FlxSprite;
	private var healthBar:FlxBar;

	private var generatedMusic:Bool = false;
	private var startingSong:Bool = false;

	private var iconP1:HealthIcon;
	private var iconP2:HealthIcon;

	public var camGame:BetterCams;

	var halloweenBG:FlxSprite;
	var isHalloween:Bool = false;

	var phillyCityLights:FlxTypedGroup<FlxSprite>;
	var phillyTrain:FlxSprite;
	var trainSound:FlxSound;

	var limo:FlxSprite;
	var grpLimoDancers:FlxTypedGroup<BackgroundDancer>;
	var fastCar:FlxSprite;

	var upperBoppers:FlxSprite;
	var bottomBoppers:FlxSprite;
	var santa:FlxSprite;

	var bgGirls:BackgroundGirls;
	var wiggleShit:WiggleEffect = new WiggleEffect();

	var talking:Bool = true;
	var songScore:Int = 0;

	public static var campaignScore:Int = 0;

	var defaultCamZoom:Float = 1.05;

	// how big to stretch the pixel art assets
	public static var daPixelZoom:Float = 6;

	public var inCutscene:Bool = false;

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
		modStorage = [];

		if (FlxG.sound.music != null)
			FlxG.sound.music.stop();

		SaveData.saveClient();
		
		camGame = new BetterCams();
		camNOTE = new CameraNote();
		camSCENERY = new BetterCams();
		camHUD = new BetterCams();
		camHUD.bgColor.alpha = 0;
		camNOTE.bgColor.alpha = 0;
		camSCENERY.bgColor.alpha = 0;

		FlxG.cameras.reset(camGame);
		FlxG.cameras.add(camNOTE);
		FlxG.cameras.add(camSCENERY);
		FlxG.cameras.add(camHUD);

		FlxCamera.defaultCameras = [camGame];

		persistentUpdate = true;
		persistentDraw = true;

		if (SONG == null)
			SONG = Song.loadFromJson('tutorial');

		if(Assets.exists(Paths.getPath('data/warning.txt', TEXT, ""))) //WIP
			if(Assets.getText(Paths.txt('${SONG.song.toLowerCase()}/warning')) != "" 
			&& Assets.getText(Paths.txt('${SONG.song.toLowerCase()}/warning')) != null)
				hasWarning = true;
			else
				hasWarning = false;
		else
			hasWarning = false;

		if(SONG.modifiers == null)
			SONG.modifiers = [];

		if(modifierCheckList('blind effect'))
			FlxG.camera.alpha = 0;

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

		stageGroup = new FlxTypedGroup<StageBuilder>();
		add(stageGroup);

		if(SONG.stage == null)
			SONG.stage = DefaultStage.setMainGameStage(SONG.song.toLowerCase());

		curStage = SONG.stage;

		for(i in 0...Register.stages.length) {
			stageGroup.add(cast Type.createInstance(Register.stages[i], [curStage]));
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

		boyfriend.animation.finishCallback = function(name:String) {
			if(name != 'idle' && !name.startsWith('dance')) {
				boyfriend.dance();
			}
		}

		if(ChooseFeeshmora.chooseSkin.get("boyfriend").length >= 1) {
			
			boyfriend.setColorTransform(
				ChooseFeeshmora.chooseSkin.get("boyfriend")[0],
				ChooseFeeshmora.chooseSkin.get("boyfriend")[1],
				ChooseFeeshmora.chooseSkin.get("boyfriend")[2],
				ChooseFeeshmora.chooseSkin.get("boyfriend")[3],
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[4]),
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[5]),
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[6]),
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[7])
			);
		}

		stageGroup.forEach(function(stage:StageBuilder) {
			stage.configStage();
		});

		boyfriend.setPosition(boyfriend.x - SONG.player1X, boyfriend.y - SONG.player1Y);
		dad.setPosition(dad.x - SONG.player2X, dad.y - SONG.player2Y);

		createScene();
		createFogs();

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

		Compile.spawn();

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
		add(healthBarBG);

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
		add(counterTxt);

		iconP1 = new HealthIcon(SONG.player1, true, SONG.bpm);
		

		if(ChooseFeeshmora.chooseSkin.get("boyfriend").length >= 1) {

			iconP1.setColorTransform(
				ChooseFeeshmora.chooseSkin.get("boyfriend")[0],
				ChooseFeeshmora.chooseSkin.get("boyfriend")[1],
				ChooseFeeshmora.chooseSkin.get("boyfriend")[2],
				ChooseFeeshmora.chooseSkin.get("boyfriend")[3],
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[4]),
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[5]),
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[6]),
				Std.int(ChooseFeeshmora.chooseSkin.get("boyfriend")[7])
			);
		}

		iconP2 = new HealthIcon(SONG.player2, false);

		healthBar = new FlxBar(healthBarBG.x + 4, healthBarBG.y + 4, RIGHT_TO_LEFT, Std.int(healthBarBG.width - 8), Std.int(healthBarBG.height - 8), this,
			'health', 0, 2);
		healthBar.scrollFactor.set();

		healthBar.createFilledBar(CoolUtil.calculateAverageColor(iconP2.updateFramePixels()), CoolUtil.calculateAverageColor(iconP1.updateFramePixels()));

		// healthBar
		add(healthBar);

		iconP1.y = healthBar.y - (iconP1.height / 2);
		iconP2.y = healthBar.y - (iconP2.height / 2);

		add(iconP1);
		add(iconP2);

		strumLineNotes.cameras = [camNOTE];
		notes.cameras = [camNOTE];
		grpSplash.cameras = [camNOTE];
		healthBar.cameras = [camHUD];
		healthBarBG.cameras = [camHUD];
		iconP1.cameras = [camHUD];
		iconP2.cameras = [camHUD];
		debugText.cameras = [camHUD];
		counterTxt.cameras = [camHUD];

		// if (SONG.song == 'South')
		// FlxG.camera.alpha = 0.7;
		// UI_camera.zoom = 1;

		// cameras = [FlxG.cameras.list[1]];

		startingSong = true;

		if(!hasWarning)
			inDeBenigin();

		setupExtraKeys();
		eventLoad();

		super.create();
	}

	function setupExtraKeys() {
		if(SONG.fifthKey) {
			keysMatrix[0] = SaveData.getData(CUSTOM_KEYBINDS)[0];
			keysMatrix[1] = SaveData.getData(CUSTOM_KEYBINDS)[1];
			keysMatrix[4] = SaveData.getData(CUSTOM_KEYBINDS)[4];
			keysMatrix[2] = SaveData.getData(CUSTOM_KEYBINDS)[2];
			keysMatrix[3] = SaveData.getData(CUSTOM_KEYBINDS)[3];
		}else {
			keysMatrix[0] = SaveData.getData(CUSTOM_KEYBINDS)[0];
			keysMatrix[1] = SaveData.getData(CUSTOM_KEYBINDS)[1];
			keysMatrix[2] = SaveData.getData(CUSTOM_KEYBINDS)[2];
			keysMatrix[3] = SaveData.getData(CUSTOM_KEYBINDS)[3];
		}
	}

	function inDeBenigin() {
		if (isStoryMode) {
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
				default:
					var dialogueBox = Type.createInstance(cast Register.dialogues.get(curSong.toLowerCase()), []);

					if(dialogueBox != null) {
						dialogueBox.finishCallback = clearDialogue;

						dialogueBox.createDialogue(this);
						dialogueBox.attachToCamera(camHUD);
					}else {
						startCountdown();
					}
			}
		}
		else
		{
			switch (curSong.toLowerCase())
			{
				default:
					startCountdown();
			}
		}
	}

	function clearDialogue(dialogue:IDialogue) {
		dialogue.destroyDialogue();
		dialogue = null;

		startCountdown();
	}

	function setHealth(hp:Float) {
		final tempHealth:Float = health;

		if(Math.abs(health - tempHealth) > 0.01) {
			healthTween = FlxTween.tween(this, {health: hp}, Math.abs(health - tempHealth), {ease: FlxEase.quadOut});
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
			add(gf);

			stageGroup.forEach(function(stage:StageBuilder) {
				stage.whenCreatingScene();
			});

			add(dad);
			add(boyfriend);
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

	public function triggerScene(note:Note) {
		if(CustomNoteHandler.triggerWarning[note.noteAbstract] == null || (curStage == "school" || curStage == "schoolEvil"))
			return;

		if(triggerGroup == null) {
			triggerGroup = new FlxTypedGroup<FlxSprite>();
			triggerGroup.cameras = [camSCENERY];
			add(triggerGroup);
		}

		if(triggerGroup.members[0] == null) {
			switch(note.noteAbstract) {
				case "reverse":
					var noteBITCH:FlxSprite = new FlxSprite().loadGraphic(Paths.image('reverseScene'));
					noteBITCH.setGraphicSize(Std.int(noteBITCH.width/1.75));
					noteBITCH.updateHitbox();
					noteBITCH.cameras = [camSCENERY];
					noteBITCH.antialiasing = true;
					noteBITCH.alpha = 0;
					noteBITCH.screenCenter();
					triggerGroup.add(noteBITCH);

					var noteRings:FeeshSprite = new FeeshSprite(0, 0, "rings");
					noteRings.cameras = [camSCENERY];
					noteRings.antialiasing = true;
					noteRings.alpha = 0;
					noteRings.screenCenter();
					triggerGroup.add(noteRings);

					FlxTween.tween(camSCENERY, {zoom: 1.5}, 0.85, {ease: FlxEase.quadOut});
					FlxTween.tween(noteBITCH, {alpha: 0.5}, 0.75, {ease: FlxEase.quadOut});
					FlxTween.tween(noteRings, {alpha: 0.5}, 0.75, {ease: FlxEase.quadOut});

					CustomNoteHandler.triggerWarning[note.noteAbstract] = true;
					
					new FlxTimer().start(0.75, function(tick:FlxTimer) {
						FlxTween.tween(noteBITCH, {alpha: 0}, 0.1, {ease: FlxEase.quadOut});
						FlxTween.tween(noteRings, {alpha: 0}, 0.1, {ease: FlxEase.quadOut});

						new FlxTimer().start(0.1, function(tick:FlxTimer) {
							camSCENERY.zoom = 1;
							triggerGroup.clear();

							noteBITCH.kill();
							noteBITCH.destroy();

							noteRings.kill();
							noteRings.destroy();
						});
					});
				case "reverse poison":
					var noteBITCH:FlxSprite = new FlxSprite().loadGraphic(Paths.image('skullpog'));
					noteBITCH.setGraphicSize(Std.int(noteBITCH.width/3));
					noteBITCH.updateHitbox();
					noteBITCH.cameras = [camSCENERY];
					noteBITCH.antialiasing = true;
					noteBITCH.alpha = 0.75;
					noteBITCH.screenCenter();
					triggerGroup.add(noteBITCH);

					var noteRings:FeeshSprite = new FeeshSprite(0, 0, "rings", true);
					noteRings.cameras = [camSCENERY];
					noteRings.antialiasing = true;
					noteRings.alpha = 0.75;
					noteRings.screenCenter();
					triggerGroup.add(noteRings);

					FlxTween.tween(camSCENERY, {zoom: 2}, 1.1, {ease: FlxEase.quadOut});
					FlxTween.tween(noteBITCH, {alpha: 0}, 1, {ease: FlxEase.quadOut});
					FlxTween.tween(noteRings, {alpha: 0}, 1, {ease: FlxEase.quadOut});

					FlxG.sound.play(Paths.sound('poison'));
					CustomNoteHandler.triggerWarning[note.noteAbstract] = true;

					new FlxTimer().start(1.1, function(tick:FlxTimer) {
						camSCENERY.zoom = 1;
						triggerGroup.clear();

						noteBITCH.kill();
						noteBITCH.destroy();

						noteRings.kill();
						noteRings.destroy();
					});				
				case "poison":
					var noteBITCH:FlxSprite = new FlxSprite().loadGraphic(Paths.image('skull'));
					noteBITCH.setGraphicSize(Std.int(noteBITCH.width/1.75));
					noteBITCH.updateHitbox();
					noteBITCH.cameras = [camSCENERY];
					noteBITCH.antialiasing = true;
					noteBITCH.alpha = 0;
					noteBITCH.screenCenter();
					triggerGroup.add(noteBITCH);

					FlxTween.tween(camSCENERY, {zoom: 1.5}, 0.85, {ease: FlxEase.quadOut});
					FlxTween.tween(noteBITCH, {alpha: 0.5}, 0.75, {ease: FlxEase.quadOut});

					FlxG.sound.play(Paths.sound('poison'));
					CustomNoteHandler.triggerWarning[note.noteAbstract] = true;
					
					new FlxTimer().start(0.75, function(tick:FlxTimer) {
						FlxTween.tween(noteBITCH, {alpha: 0}, 0.1, {ease: FlxEase.quadOut});

						new FlxTimer().start(0.1, function(tick:FlxTimer) {
							camSCENERY.zoom = 1;
							triggerGroup.clear();

							noteBITCH.kill();
							noteBITCH.destroy();
						});
					});
				case "spiritual star":
					CustomNoteHandler.triggerWarning[note.noteAbstract] = true;

					var dedBF:Character = new Character(0, 0, 'bf');
					dedBF.cameras = [camSCENERY];
					dedBF.antialiasing = true;
					dedBF.alpha = 0;
					dedBF.flipX = true;
					dedBF.screenCenter();
					triggerGroup.add(dedBF);

					FlxTween.tween(camSCENERY, {zoom: 1.5}, 0.85, {ease: FlxEase.quadOut});
					FlxTween.tween(dedBF, {alpha: 0.25}, 0.75, {ease: FlxEase.quadOut});

					dedBF.playAnim('firstDeath');

					new FlxTimer().start(0.75, function(tick:FlxTimer) {
						FlxTween.tween(dedBF, {alpha: 0}, 0.1, {ease: FlxEase.quadOut});

						new FlxTimer().start(0.1, function(tick:FlxTimer) {
							camSCENERY.zoom = 1;
							triggerGroup.clear();

							dedBF.kill();
							dedBF.destroy();
						});
					});
				case "side note":
					var blackBox:FlxSprite = new FlxSprite().makeGraphic(FlxG.width * 3, FlxG.height * 3, FlxColor.BLACK);
					blackBox.screenCenter();
					blackBox.scrollFactor.set();
					blackBox.alpha = 0;
					triggerGroup.add(blackBox);

					CustomNoteHandler.yourNoteData[note.noteAbstract] = new FlxSprite().loadGraphic(Paths.image('warningScene'));
					CustomNoteHandler.yourNoteData[note.noteAbstract].scrollFactor.set();
					CustomNoteHandler.yourNoteData[note.noteAbstract].alpha = 0.25;
					CustomNoteHandler.yourNoteData[note.noteAbstract].screenCenter();
					triggerGroup.add(CustomNoteHandler.yourNoteData[note.noteAbstract]);
					
					FlxTween.tween(blackBox, {alpha: 1}, 0.1, {ease: FlxEase.quadOut});
					CustomNoteHandler.triggerWarning[note.noteAbstract] = true;

					FlxFlicker.flicker(CustomNoteHandler.yourNoteData[note.noteAbstract], 0.75, Conductor.stepCrochet/1000, false, false, function(flick:FlxFlicker) {
						FlxTween.tween(blackBox, {alpha: 0}, 0.1, {ease: FlxEase.quadIn});

						new FlxTimer().start(0.1, function(tick:FlxTimer) {
							triggerGroup.clear();

							blackBox.kill();
							blackBox.destroy();

							CustomNoteHandler.yourNoteData[note.noteAbstract].kill();
							CustomNoteHandler.yourNoteData[note.noteAbstract].destroy();
							CustomNoteHandler.yourNoteData[note.noteAbstract] = null;
						});
					});
				//default:
					
			}
		}
	}

	var startTimer:FlxTimer;
	var perfectMode:Bool = false;

	static public function modifierCheckList(mod:String):Bool {
		if(!Main.feeshmoraModifiers)
			return false;

		if(modStorage.length > 0 && modStorage.contains(mod))
			return true;

		if(mod == "flip chart" && FlxG.save.data.flip && SONG.modifiers[0] == null)
			return true;
		else if(mod == "custom hell" && FlxG.save.data.customhell)
			return true;
		else if(mod == "safe balls" && FlxG.save.data.safeballs)
			return true;
		else if(mod == "get good" && FlxG.save.data.perfectMode >= 1)
			return true;
		else if(mod == "fair battle" && FlxG.save.data.fair && SONG.modifiers[0] == null)
			return true;
		else if(mod == "fade battle" && FlxG.save.data.fade && SONG.modifiers[0] == null)
			return true;
		else if(mod == "blind effect" && FlxG.save.data.blind && SONG.modifiers[0] == null)
			return true;
		else if(mod == "note woggle" && FlxG.save.data.xWobble && SONG.modifiers[0] == null)
			return true;
		else if(mod == "camera move" && FlxG.save.data.camMove && SONG.modifiers[0] == null)
			return true;
		else
			return false;
	}

	function startCountdown():Void {
		FlxG.sound.music.stop();
		inCutscene = false;

		generateStaticArrows(0);
		generateStaticArrows(1);

		talking = false;
		startedCountdown = true;
		Conductor.songPosition = 0;
		Conductor.songPosition -= Conductor.crochet * 5;

		Conductor.trackPosition = Conductor.songPosition;

		var swagCounter:Int = 0;

		startTimer = new FlxTimer().start(Conductor.crochet / 1000, function(tmr:FlxTimer)
		{
			iconP1.setGraphicSize(Std.int(iconP1.width + 30));

			gf.dance();
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

		FlxG.sound.music.onComplete = endSong;
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

				if(modifierCheckList('flip chart') && gottaHitNote && Main.feeshmoraModifiers)
					daNoteData = Std.int(Math.abs(daNoteData-(keys-1)));

				if(modifierCheckList('custom hell') && Main.feeshmoraModifiers)
					daNoteAbstract = CoolUtil.coolTextFile(Paths.pak('mapHandler'))[FlxG.random.int(1, CoolUtil.coolTextFile(Paths.pak('mapHandler')).length-1)];

				var oldNote:Note;
				if (unspawnNotes.length > 0)
					oldNote = unspawnNotes[Std.int(unspawnNotes.length - 1)];
				else
					oldNote = null;

				var swagNote:Note = new Note(daStrumTime, daNoteData, oldNote, false, daNoteAbstract, false, true);
				swagNote.sustainLength = songNotes[2];
				swagNote.scrollFactor.set(0, 0);
				swagNote.refresh(SONG.fifthKey);
				swagNote.refresh(SONG.fifthKey, true);

				if(daNoteAbstract != null && !Compile.tempNoteAbstracts.contains(daNoteAbstract))
					Compile.tempNoteAbstracts.push(daNoteAbstract);
				
				if(songNotes[4] >= 0.1)
					swagNote.howSpeed = songNotes[4];

				swagNote.setupPosition = Compile.compilePosition(daStrumTime);

				if((swagNote.noteAbstract == "reverse" || swagNote.noteAbstract == "reverse poison") && gottaHitNote)
					swagNote.noteData = Std.int(Math.abs(swagNote.noteData-(keys-1)));

				var susLength:Float = swagNote.sustainLength;

				susLength = susLength / Conductor.stepCrochet;

				if(swagNote.trail != null)
					add(swagNote.trail);

				unspawnNotes.push(swagNote);

				for (susNote in 0...Math.floor(susLength)) {
					oldNote = unspawnNotes[Std.int(unspawnNotes.length - 1)];

					if(!oldNote.isSustainNote && oldNote.trail != null)
						oldNote.trail.members[0].visible = true;

					var sustainNote:Note = new Note(daStrumTime + (Conductor.stepCrochet * susNote) + Conductor.stepCrochet, daNoteData, oldNote, true, daNoteAbstract);
					sustainNote.scrollFactor.set();

					sustainNote.howSpeed = oldNote.howSpeed;

					sustainNote.setupPosition = Compile.compilePosition((daStrumTime + (Conductor.stepCrochet * susNote) + Conductor.stepCrochet) * swagNote.howSpeed);

					if(!sustainNote.wasSustainNote)
						unspawnNotes.push(sustainNote);
					else
						sustainNote.destroy();

					if(sustainNote.noteAbstract == "reverse poison" && gottaHitNote)
						sustainNote.noteData = Std.int(Math.abs(sustainNote.noteData-(keys-1)));

					sustainNote.mustPress = gottaHitNote;

					if (sustainNote.mustPress)
					{
						sustainNote.x += FlxG.width / 2; // general offset
					}
				}

				swagNote.mustPress = gottaHitNote;

				if (swagNote.mustPress)
				{
					swagNote.x += FlxG.width / 2; // general offset	
				}
			}
			daBeats += 1;
		}

		// trace(unspawnNotes.length);
		// playerCounter += 1;

		unspawnNotes.sort(sortByShit);
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
			var splashSprite:SplashSprite = new SplashSprite();
			var babyArrow:Strum;

			if(SONG.fifthKey)
				babyArrow = new Strum(0, strumLine.y);
			else
				babyArrow = new Strum(42, strumLine.y);

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
						babyArrow.animation.addByPrefix('green', 'arrowUP');
						babyArrow.animation.addByPrefix('blue', 'arrowDOWN');
						babyArrow.animation.addByPrefix('purple', 'arrowLEFT');
						babyArrow.animation.addByPrefix('red', 'arrowRIGHT');
						babyArrow.animation.addByPrefix('diamond', 'arrowSPACE');

						babyArrow.antialiasing = true;
						babyArrow.setGraphicSize(Std.int(babyArrow.width * 0.7));

						switch (Math.abs(i))
						{
							case 0:
								babyArrow.x += Note.swagWidth * 0;
								babyArrow.animation.addByPrefix('static', 'arrowLEFT');
								babyArrow.animation.addByPrefix('pressed', 'left press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'left confirm', 24, false);
							case 1:
								babyArrow.x += Note.swagWidth * 1;
								babyArrow.animation.addByPrefix('static', 'arrowDOWN');
								babyArrow.animation.addByPrefix('pressed', 'down press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'down confirm', 24, false);
							case 2:
								babyArrow.x += Note.swagWidth * 2;
								babyArrow.animation.addByPrefix('static', 'arrowSPACE');
								babyArrow.animation.addByPrefix('pressed', 'space press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'space confirm', 24, false);
							case 3:
								babyArrow.x += Note.swagWidth * 3;
								babyArrow.animation.addByPrefix('static', 'arrowUP');
								babyArrow.animation.addByPrefix('pressed', 'up press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'up confirm', 24, false);
							case 4:
								babyArrow.x += Note.swagWidth * 4;
								babyArrow.animation.addByPrefix('static', 'arrowRIGHT');
								babyArrow.animation.addByPrefix('pressed', 'right press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'right confirm', 24, false);
						}
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
						babyArrow.animation.addByPrefix('green', 'arrowUP');
						babyArrow.animation.addByPrefix('blue', 'arrowDOWN');
						babyArrow.animation.addByPrefix('purple', 'arrowLEFT');
						babyArrow.animation.addByPrefix('red', 'arrowRIGHT');

						babyArrow.antialiasing = FlxG.save.data.showAntialiasing;
						babyArrow.setGraphicSize(Std.int(babyArrow.width * 0.7));

						switch (Math.abs(i))
						{
							case 0:
								babyArrow.x += Note.swagWidth * 0;
								babyArrow.animation.addByPrefix('static', 'arrowLEFT');
								babyArrow.animation.addByPrefix('pressed', 'left press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'left confirm', 24, false);
							case 1:
								babyArrow.x += Note.swagWidth * 1;
								babyArrow.animation.addByPrefix('static', 'arrowDOWN');
								babyArrow.animation.addByPrefix('pressed', 'down press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'down confirm', 24, false);
							case 2:
								babyArrow.x += Note.swagWidth * 2;
								babyArrow.animation.addByPrefix('static', 'arrowUP');
								babyArrow.animation.addByPrefix('pressed', 'up press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'up confirm', 24, false);
							case 3:
								babyArrow.x += Note.swagWidth * 3;
								babyArrow.animation.addByPrefix('static', 'arrowRIGHT');
								babyArrow.animation.addByPrefix('pressed', 'right press', 24, false);
								babyArrow.animation.addByPrefix('confirm', 'right confirm', 24, false);
						}
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

			babyArrow.ID = i;

			if (player == 1) {
				playerStrums.add(babyArrow);
			}else {
				babyArrow.ifOpponent = true;
				opponentStrums.add(babyArrow);
			}

			babyArrow.animation.play('static');
			babyArrow.x += 50;
			babyArrow.x += ((FlxG.width / 2) * player);

			if(FlxG.save.data.showEffect && player == 1) {
				splashSprite.texture = "regular/splash";
				splashSprite.animation.play('sploosh0');
				splashSprite.animation.curAnim.curFrame = splashSprite.animation.curAnim.numFrames;
				grpSplash.add(splashSprite);
			}

			strumLineNotes.add(babyArrow);

			Compile.strumSize.push([babyArrow.scale.x, babyArrow.scale.y]);
		}
	}

	function tweenCamIn():Void
	{
		FlxTween.tween(FlxG.camera, {zoom: 1.3}, (Conductor.stepCrochet * 4 / 1000), {ease: FlxEase.elasticInOut});
	}

	override function openSubState(SubState:FlxSubState) {
		if (paused) {
			pauseMusic();
		}

		super.openSubState(SubState);
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
		if(Compile.timeFreeze > 0)
			return;

		vocals.pause();

		if(muteInst)
			FlxG.sound.music.volume = 0;

		FlxG.sound.music.play();
		Conductor.songPosition = FlxG.sound.music.time;
		vocals.time = FlxG.sound.music.time;
		vocals.play();
	}

	function longConditionForNote(daNote:Note, center:Float):Bool {
		if(daNote.downscrollNote) {
			if(daNote.y - daNote.offset.y * daNote.scale.y + daNote.height >= center
			&& (!daNote.mustPress || (daNote.wasGoodHit || (daNote.prevNote.wasGoodHit && !daNote.canBeHit)))) {
				return true;
			}
		}else {
			if (daNote.isSustainNote
			&& daNote.y + daNote.offset.y * daNote.scale.y <= center
			&& (!daNote.mustPress || (daNote.wasGoodHit || (daNote.prevNote.wasGoodHit && !daNote.canBeHit)))) {
				return true;
			}
		}

		return false;
	}

	function caculateNoteY(targetY:Float, note:Note, downscroll:Bool):Float {
		var noteCacurations:Float = (targetY - (Conductor.trackPosition - Compile.getNoteTime(note.strumTime)) * Note.AFFECTED_SCROLLSPEED * (0.45 *  (downscroll ? -1 : 1) * FlxMath.roundDecimal(note.howSpeed, 2)));

		if(downscroll && note.isSustainNote) {
			if(note.height < 50 && note.distanceAxis != X) {
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
			modWobble = flipWiggle * (30*Math.sin(noteCacurations * Math.PI * 0.005));
		}

		if(wobbleStrength > 0 && !note.isSustainNote)
			modWobble = wobbleStrength * Math.sin(noteCacurations * Math.PI * 0.005);

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

		Register.events.whenGameIsRunning(modStorage, this);

		super.update(elapsed);

		noteBeat = curBeat;

		if(playFPS != null && Lib.current.stage.frameRate < playFPS) {
			Lib.current.stage.frameRate = playFPS * SaveData.getData(SaveType.FPS_MULTIPLIER);
			Main.framerate = playFPS;
		}

		accTotal = Math.floor(Math.min(maxAcc, Math.max(0, Math.floor(accuracy*100)/100))*100)/100;

		if(GhostTapping.ghostTap && FlxG.save.data.showstuff) {
			counterTxt.text = 'Accuracy: ' + accTotal + '%' + '       ' + 'Ghost Taps: ' + missClicks + '       ' + 'Misses: ' + misses + '       ' + 'Score: ' + songScore;
			counterTxt.screenCenter(X);
		}else if(FlxG.save.data.showstuff) {
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

		if (FlxG.keys.justPressed.ENTER && startedCountdown && canPause)
		{
			persistentUpdate = false;
			persistentDraw = true;
			paused = true;

			// 1 / 1000 chance for Gitaroo Man easter egg
			if (FlxG.random.bool(0.1)) {
				// gitaroo man easter egg
				FlxG.switchState(new GitarooPause());
			} else {
				openSubState(new PauseSubState(boyfriend.getScreenPosition().x, boyfriend.getScreenPosition().y));
			}	
		
			#if windows
			DiscordClient.changePresence(detailsPausedText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
			#end
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

		if (FlxG.keys.justPressed.SEVEN)
		{
			Compile.kill();

			FlxG.switchState(new ChartingState());

			#if windows
			DiscordClient.changePresence("Chart Editor", null, null, true);
			#end
		}

		// FlxG.watch.addQuick('VOL', vocals.amplitudeLeft);
		// FlxG.watch.addQuick('VOLRight', vocals.amplitudeRight);

		iconP1.setGraphicSize(Std.int(FlxMath.lerp(iconP1.width, 150, 0.1/(Main.framerate/100))));
		iconP2.setGraphicSize(Std.int(FlxMath.lerp(iconP2.width, 150, 0.1/(Main.framerate/100))));

		iconP1.updateHitbox();
		iconP2.updateHitbox();

		var iconOffset:Int = 26;

		iconP1.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01) - iconOffset);
		iconP2.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01)) - (iconP2.width - iconOffset);

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
		else
			iconP2.animation.curAnim.curFrame = 0;

		/* if (FlxG.keys.justPressed.NINE)
			FlxG.switchState(new Charting()); */

		#if debug
		if (FlxG.keys.justPressed.EIGHT)
			FlxG.switchState(new AnimationDebug(SONG.player2));
		#end

		if (startingSong)
		{
			if (startedCountdown)
			{
				Conductor.songPosition += FlxG.elapsed * 1000;
				Conductor.trackPosition = Conductor.songPosition;
				if (Conductor.trackPosition >= 0)
					startSong();
			}
		}
		else
		{
			// Conductor.songPosition = FlxG.sound.music.time;
			Conductor.songPosition += FlxG.elapsed * 1000;

			Conductor.trackPosition = FlxMath.lerp(Conductor.songPosition, prevTrackPos, Compile.timeFreeze);

			if(Compile.timeFreeze <= 0 && !paused)
				prevTrackPos = Conductor.songPosition + (Conductor.stepCrochet * 6);

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

				camFollow.setPosition(camFollowX + camMovementPos.x, camFollowY + camMovementPos.y);

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

				camFollow.setPosition(camFollowX + camMovementPos.x, camFollowY + camMovementPos.y);

				if (SONG.song.toLowerCase() == 'tutorial')
				{
					FlxTween.tween(FlxG.camera, {zoom: 1}, (Conductor.stepCrochet * 4 / 1000), {ease: FlxEase.elasticInOut});
				}
			}
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
					gfSpeed = 2;
				case 48:
					gfSpeed = 1;
				case 80:
					gfSpeed = 2;
				case 112:
					gfSpeed = 1;
				case 163:
					// FlxG.sound.music.stop();
					// FlxG.switchState(new TitleState());
			}
		}

		if (curSong == 'Bopeebo')
		{
			switch (curBeat)
			{
				case 128, 129, 130:
					vocals.volume = 0;
					// FlxG.sound.music.stop();
					// FlxG.switchState(new PlayState());
			}
		}
		// better streaming of shit

		// RESET = Quick Game Over Screen
		if (controls.RESET)
		{
			health = 0;
			trace("RESET = True");
		}

		if (health <= 0 && (!modifierCheckList('safe balls') && Main.feeshmoraModifiers || !Main.feeshmoraModifiers))
		{
			boyfriend.stunned = true;

			if(modifierCheckList('blind effect'))
				FlxG.camera.alpha = 1;

			persistentUpdate = false;
			persistentDraw = false;
			paused = true;

			vocals.stop();
			FlxG.sound.music.stop();

			FlxG.camera.zoom = defaultCamZoom;

			openSubState(new GameOverSubstate(boyfriend.getScreenPosition().x, boyfriend.getScreenPosition().y));

			// FlxG.switchState(new GameOverState(boyfriend.getScreenPosition().x, boyfriend.getScreenPosition().y));
			
			#if windows
			// Game Over doesn't get his own variable because it's only used here
			DiscordClient.changePresence("Game Over - " + detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
			#end
		}else if(health <= 0 && (modifierCheckList('safe balls') && Main.feeshmoraModifiers)) {
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

				var index:Int = unspawnNotes.indexOf(dunceNote);
				unspawnNotes.splice(index, 1);
			}
		}

		if (generatedMusic)
		{
			keyShit();
			keyReleased();

			if(trippyFog.alpha == 0.5) {
				var curBet:Float = CustomNoteHandler.yourNoteData.get("trippy")*(Conductor.bpm/120);
				CustomNoteHandler.yourNoteData.set("trippy", CustomNoteHandler.yourNoteData.get("trippy")+0.004);

				trippyWiggle.waveAmplitude = Math.sin(curBet * Math.PI * 6)/30;
			}

			//Nothing here!
			notes.forEachAlive(function(daNote:Note)
			{
				if (daNote.y > FlxG.height)
					{
						daNote.active = false;
						daNote.visible = false;
					}
					else
					{
						if(!CustomNoteHandler.triggerWarning[daNote.noteAbstract] && CustomNoteHandler.triggerWarning[daNote.noteAbstract] != null)
							triggerScene(daNote);
	
						if(daNote.noteAbstract == "trippy" && trippyShader == null) {
							trippyWiggle.effectType = WiggleEffectType.DREAMY;
		                    trippyWiggle.waveSpeed = 1;
							trippyWiggle.waveFrequency = Math.PI * 15;

							trippyShader = new ShaderFilter(trippyWiggle.shader);
						}

						switch(daNote.noteAbstract) {
							case "side note":
								if(daNote.isSustainNote) {
									if(camNOTE.camNoteWOBBLE == null) {
										camNOTE.createNoteCam(daNote.noteAbstract);

										FlxG.cameras.remove(camNOTE, false);
										FlxG.cameras.add(camNOTE);
										FlxG.cameras.remove(camHUD, false);
										FlxG.cameras.add(camHUD);
									}	

									daNote.cameras = [camNOTE.camNoteWOBBLE];

									if(!daNote.prevNote.isSustainNote)
										daNote.prevNote.trail.cameras = [camNOTE.camNoteWOBBLE];
								}

						}	

						daNote.visible = true;
						daNote.active = true;

						if(daNote.hasCustomAddon != null)
							daNote.hasCustomAddon.whenIsSpawned(daNote);
					}
				var strumPos:Float = 0;

				if(daNote.mustPress)
					strumPos = playerStrums.members[daNote.noteData].getRegularAxis(daNote.distanceAxis);
				else
					strumPos = opponentStrums.members[daNote.noteData].getRegularAxis(daNote.distanceAxis);

				final centerNote:Float = strumPos + Note.swagWidth / 2;

				daNote.caculatePos = caculateNoteY(strumPos, daNote, daNote.downscrollNote);
				daNote.setNoteAxis(daNote.distanceAxis);

				// fixed it kinda
				if (daNote.isSustainNote && (daNote.mustPress || !daNote.ignore)) {
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

					if(SONG.fifthKey) {
						switch (Math.abs(daNote.noteData))
						{
							case 0:
								dad.playAnim('singLEFT' + altAnim, true);
							case 1:
								dad.playAnim('singDOWN' + altAnim, true);
							case 2:
								dad.playAnim('singUP' + altAnim, true);
							case 3:
								dad.playAnim('singUP' + altAnim, true);
							case 4:
								dad.playAnim('singRIGHT' + altAnim, true);
						}
					}else {
						switch (Math.abs(daNote.noteData))
						{
							case 0:
								dad.playAnim('singLEFT' + altAnim, true);
							case 1:
								dad.playAnim('singDOWN' + altAnim, true);
							case 2:
								dad.playAnim('singUP' + altAnim, true);
							case 3:
								dad.playAnim('singRIGHT' + altAnim, true);
						}
					}

					Register.events.whenNoteIsPressed(daNote, this);
					cameraMovement(daNote.noteData, daNote.isSustainNote);

					if(modifierCheckList('fair battle') && health < 0.1)
						setHealth(health - 0.01);

					opponentStrums.forEach(function(spr:FlxSprite) {
						if (Math.abs(daNote.noteData) == spr.ID) {
							spr.animation.play('confirm', true);
						}

						if (spr.animation.curAnim.name == 'confirm' && !CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract) && !isPixel) {
							spr.centerOffsets();
							spr.offset.x -= 13;
							spr.offset.y -= 13;
						}else {
							spr.centerOffsets();
						}
					});

					dad.holdTimer = 0;

					if (SONG.needsVoices)
						vocals.volume = 1;

					removeNote(daNote);
				}

				if(daNote.noteAbstract == "side note") {
				
					if(daNote.mustPress) {
						daNote.setInverseAxis(daNote.distanceAxis, addToNoteX(playerStrums.members[Math.floor(Math.abs(daNote.noteData))].getInverseAxis(daNote.distanceAxis) + (Conductor.trackPosition - Compile.getNoteTime(daNote.strumTime)) * (0.45 * FlxMath.roundDecimal(daNote.howSpeed * Note.AFFECTED_SCROLLSPEED, 2)), daNote));
					}else {
						daNote.setInverseAxis(daNote.distanceAxis, addToNoteX(opponentStrums.members[Math.floor(Math.abs(daNote.noteData))].getInverseAxis(daNote.distanceAxis) + (Conductor.trackPosition - Compile.getNoteTime(daNote.strumTime)) * (-0.45 * FlxMath.roundDecimal(daNote.howSpeed * Note.AFFECTED_SCROLLSPEED, 2)), daNote));
					}
				}

				if (daNote.mustPress) {
					daNote.setVisibility(playerStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyVisible);
					daNote.setXaxis(addToNoteX(playerStrums.members[Math.floor(Math.abs(daNote.noteData))].getInverseAxis(daNote.distanceAxis), daNote));
					daNote.setNoteAngle(playerStrums.members[Math.floor(Math.abs(daNote.noteData))].angle);
					daNote.setNoteAlpha(playerStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyFans);
				}
				else {
					daNote.setVisibility(opponentStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyVisible);
					daNote.setXaxis(addToNoteX(opponentStrums.members[Math.floor(Math.abs(daNote.noteData))].getInverseAxis(daNote.distanceAxis), daNote));
					daNote.setNoteAngle(opponentStrums.members[Math.floor(Math.abs(daNote.noteData))].angle);
					daNote.setNoteAlpha(opponentStrums.members[Math.floor(Math.abs(daNote.noteData))].onlyFans);
				}

				if (daNote.isSustainNote) {
					if(daNote.prevNote.isSustainNote)
						daNote.setInverseAxis(daNote.distanceAxis, daNote.prevNote.getInverseAxis(daNote.prevNote.distanceAxis));
					else
						daNote.setInverseAxis(daNote.distanceAxis, daNote.getInverseAxis(daNote.distanceAxis) + (daNote.prevNote.width / 3));
				}

				if(modifierCheckList('note woggle') && Main.feeshmoraModifiers) {
					if(daNote.isSustainNote && modifierCheckList('note woggle')) {
						if(camNOTE.camNoteWOBBLE == null) {
							camNOTE.createNoteCam(daNote.noteAbstract);
			
							FlxG.cameras.remove(camNOTE, false);
							FlxG.cameras.add(camNOTE);
							FlxG.cameras.remove(camHUD, false);
							FlxG.cameras.add(camHUD);
						}
			
						if(!daNote.cameras.contains(camNOTE.camNoteWOBBLE))
							daNote.cameras = [camNOTE.camNoteWOBBLE];
					}
				}else if(!modifierCheckList('note woggle') && Main.feeshmoraModifiers) {
					if(daNote.cameras.contains(camNOTE.camNoteWOBBLE) && daNote.noteAbstract != "side note")
						daNote.cameras = [camNOTE];
				}

				var detector:Bool = Conductor.trackPosition > Compile.getNoteTime(daNote.strumTime) + 260;

				if (detector && daNote.mustPress)
					{
						if (daNote.isSustainNote && daNote.wasGoodHit)
							{
								if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract))
									setHealth(health + 0.010);		
								
								if(maxAcc < 99) {
									accuracy += 0.05;
									maxAcc += 0.05;
								}
	
								if(maxAcc > 100)
									maxAcc = 100;

								removeNote(daNote);
							}
							else 
							{
								if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
	
									if((daNote.tooLate || !daNote.wasGoodHit) && daNote.noteAbstract == "side note")
										setHealth(health - 2);
									else
										setHealth(health - 0.069);

									vocals.volume = 0;
	
									if(SONG.fifthKey)
										accuracy -= 0.5 * GhostTapping.consequence;
									else
										accuracy -= 1;
								}	
			
								if(!daNote.isSustainNote) {
									if(SONG.notes[Math.floor(curStep / 16)].bpm <= 130) {
										if(daNote.tooLate || !daNote.wasGoodHit) {
											if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
												
												if(SONG.fifthKey)
													maxAcc -= 0.25;
												else
													maxAcc -= 0.5;
	
												combo = 0;
												misses += 1;

												bfMissSing(daNote.noteData);
											}
										}
									}else{
										if(daNote.tooLate || !daNote.wasGoodHit) {
											if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
											
												if(SONG.fifthKey)
													maxAcc -= 0.25;
												else
													maxAcc -= 0.5;
	
												combo = 0;
												misses += 1;

												bfMissSing(daNote.noteData);
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
		}

		#if debug
		if (FlxG.keys.justPressed.ONE)
			endSong();
		#end
	}

	function keyReleased() {
		if(paused && inCutscene)
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

		for(i in 0...controlHoldArray.length) {
			if(!controlHoldArray[i]) {
				var spr:Strum = playerStrums.members[i];

				spr.setColorTransform(1,1,1,1,0,0,0,0);
				spr.animation.play('static');

				spr.centerOffsets();
				spr.centerOrigin();
			}
		}
	}

	function endSong():Void
	{
		canPause = false;
		FlxG.sound.music.volume = 0;
		vocals.volume = 0;

		Compile.kill();

		if (SONG.validScore && !modifierCheckList('safe balls'))
		{
			#if !switch
			Highscore.saveScore(SONG.song, songScore, storyDifficulty);
			#end
		}

		if (isStoryMode)
		{
			campaignScore += songScore;

			storyPlaylist.remove(storyPlaylist[0]);

			if (storyPlaylist.length <= 0)
			{
				FlxG.sound.playMusic(Paths.music('freakyMenu'));

				FlxG.switchState(new StoryMenuState());

				// if ()

				//Make your own!

				/**
				StoryMenuState.weekUnlocked[Std.int(Math.min(storyWeek + 1, StoryMenuState.weekUnlocked.length - 1))] = true;

				if (SONG.validScore)
				{
					NGio.unlockMedal(60961);
					Highscore.saveWeekScore(storyWeek, campaignScore, storyDifficulty);
				}

				FlxG.save.data.weekUnlocked = StoryMenuState.weekUnlocked;
				FlxG.save.flush();
				**/
			}
			else
			{
				var difficulty:String = "";
				difficulty = '-hard';

				trace('LOADING NEXT SONG');
				trace(PlayState.storyPlaylist[0].toLowerCase() + difficulty);

				if (SONG.song.toLowerCase() == 'eggnog')
				{
					var blackShit:FlxSprite = new FlxSprite(-FlxG.width * FlxG.camera.zoom,
						-FlxG.height * FlxG.camera.zoom).makeGraphic(FlxG.width * 3, FlxG.height * 3, FlxColor.BLACK);
					blackShit.scrollFactor.set();
					add(blackShit);
					camHUD.visible = false;
					camNOTE.visible = false;

					FlxG.sound.play(Paths.sound('Lights_Shut_off'));
				}

				FlxTransitionableState.skipNextTransIn = true;
				FlxTransitionableState.skipNextTransOut = true;
				prevCamFollow = camFollow;

				PlayState.SONG = Song.loadFromJson(PlayState.storyPlaylist[0].toLowerCase() + "-hard", PlayState.storyPlaylist[0]);
				FlxG.sound.music.stop();

				#if cpp
				CacheState.loadAndSwitchState(new PlayState());
				#else
				LoadingState.loadAndSwitchState(new PlayState());
				#end
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
		// boyfriend.playAnim('hey');
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
			maxAcc -= 0.06 * GhostTapping.consequence;
			accuracy -= 0.75 * GhostTapping.consequence;
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
			maxAcc -= 0.0 * GhostTapping.consequence;
			accuracy -= 0.50 * GhostTapping.consequence;
			combo = 0;

			setHealth(health - 0.002);
		}
		else if (noteDiff > Conductor.safeZoneOffset * 0.2)
		{
			if(!isPixel && FlxG.save.data.showEffect) {
				grpSplash.members[id].setPosition(playerStrums.members[id].x-(grpSplash.members[id].width/3), playerStrums.members[id].y-(grpSplash.members[id].height/3));
				grpSplash.members[id].animation.play('sploosh' + id);
			}

			daRating = 'good';
			score = 200;
			maxAcc -= 0.02 * GhostTapping.consequence;
			accuracy -= 0.25 * GhostTapping.consequence;
		}else {
			daRating = 'sick';
		}

		if(daRating == 'sick') {
			accuracy += 0.11 / GhostTapping.consequence;
		}

		songScore += Std.int(score / GhostTapping.consequence);

		/* if (combo > 60)
				daRating = 'sick';
			else if (combo > 12)
				daRating = 'good'
			else if (combo > 4)
				daRating = 'bad';
		 */

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

	function getKey(key:FlxKey) {
		if(key != FlxKey.NONE) {
			for(i in 0...keysMatrix.length) {
				if(keysMatrix[i].contains(key)) {
					trace(i);
					return i;
				}
			}
		}

		return -1;
	}

	private function keyShit():Void
	{
		if(paused && inCutscene)
			return;

		var controlReleaseArray:Array<Bool> = [
			controls.GAME_LEFT_R,
			controls.GAME_DOWN_R,
			controls.GAME_UP_R,
			controls.GAME_RIGHT_R
		];

		var controlArray:Array<Bool> = [
			controls.GAME_LEFT_P,
			controls.GAME_DOWN_P,
			controls.GAME_UP_P,
			controls.GAME_RIGHT_P
		];

		var controlHoldArray:Array<Bool> = [
			controls.GAME_LEFT,
			controls.GAME_DOWN,
			controls.GAME_UP,
			controls.GAME_RIGHT
		];

		// I could care less about fixing input tbh

		if(SONG.fifthKey) {
			controlReleaseArray = [
				controls.GAME_LEFT_R,
				controls.GAME_DOWN_R,
				controls.GAME_SPACE_R,
				controls.GAME_UP_R,
				controls.GAME_RIGHT_R
			];

			controlArray = [
				controls.GAME_LEFT_P,
				controls.GAME_DOWN_P,
				controls.GAME_SPACE_P,
				controls.GAME_UP_P,
				controls.GAME_RIGHT_P
			];
			
			controlHoldArray = [
				controls.GAME_LEFT,
				controls.GAME_DOWN,
				controls.GAME_SPACE,
				controls.GAME_UP,
				controls.GAME_RIGHT
			];
		}

		if (generatedMusic) {
			var noteCaculation:Bool = false;

			var noteList:Array<Array<Note>> = [];
			var pressedNotes:Array<Note> = [];

			notes.forEachAlive(function(daNote:Note) {
				if (daNote.canBeHit && daNote.mustPress && !daNote.tooLate
				&& !daNote.wasGoodHit && controlHoldArray[daNote.noteData] && daNote.isSustainNote) {
					goodNoteHit(daNote);
				}

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

			/**
			* Better Jack detection.
			*/
			for(noteSections in noteList) {
				if(noteSections != null) {
					noteSections.sort((a, b) -> Std.int(Compile.getNoteTime(a.strumTime) - Compile.getNoteTime(b.strumTime)));

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
				}
			}
		}

		if (!inCutscene && !paused) {
			if (boyfriend.holdTimer > Conductor.stepCrochet * 4 * 0.001 && !controlHoldArray.contains(true)) {
				if (boyfriend.animation.curAnim.name.startsWith('sing') && !boyfriend.animation.curAnim.name.endsWith('miss')) {
					boyfriend.dance();
				}
			}
		}

		playerStrums.forEach(function(spr:Strum) {
			if(!CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)) {
				if(controlArray[spr.ID] && spr.animation.curAnim.name != 'confirm') {
					spr.animation.play('pressed');
					missClicks++;
				}
			}
		});
	}

	function noteMiss(direction:Int = 1, ?note:Note, ?evenTho:Bool = false):Void
	{
		if(note != null) {
			if(CustomNoteHandler.dontHitNotes.contains(note.noteAbstract) && !evenTho) {
				return;
			}
		}

		if (!boyfriend.stunned)
		{
			setHealth(health - 0.04);

			if (combo > 5 && gf.animOffsets.exists('sad'))
			{
				gf.playAnim('sad');
			}
			combo = 0;

			//if(note != null) {
			//	if(note.noteAbstract != "poison" && note.noteAbstract != "spiritual star")
					//FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
				// FlxG.sound.play(Paths.sound('missnote1'), 1, false);
				// FlxG.log.add('played imss note');
			//} else {
			//	FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
			//}

			if(note == null) {
				FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), FlxG.random.float(0.1, 0.2));
				songScore -= 10;
			}else {
				if(CustomNoteHandler.ouchyNotes.contains(note.noteAbstract))
					songScore -= 30;
				else
					songScore -= 10;
			}

			boyfriend.stunned = true;

			// get stunned for 5 seconds
			new FlxTimer().start(5 / 60, function(tmr:FlxTimer)
			{
				boyfriend.stunned = false;
			});

			bfMissSing(direction);
		}
	}

	function bfMissSing(direction:Int):Void {
		if(SONG.fifthKey) {
			switch (direction)
			{
				case 0:
					boyfriend.playAnim('singLEFTmiss' + playerAltAnim, true);
				case 1:
					boyfriend.playAnim('singDOWNmiss' + playerAltAnim, true);
				case 2:
					boyfriend.playAnim('singUPmiss' + playerAltAnim, true);
				case 3:
					boyfriend.playAnim('singUPmiss' + playerAltAnim, true);
				case 4:
					boyfriend.playAnim('singRIGHTmiss' + playerAltAnim, true);
			}
		}else {
			switch (direction)
			{
				case 0:
					boyfriend.playAnim('singLEFTmiss' + playerAltAnim, true);
				case 1:
					boyfriend.playAnim('singDOWNmiss' + playerAltAnim, true);
				case 2:
					boyfriend.playAnim('singUPmiss' + playerAltAnim, true);
				case 3:
					boyfriend.playAnim('singRIGHTmiss' + playerAltAnim, true);
			}
		}
	}

	function goodNoteHit(note:Note):Void
	{
		if (!note.wasGoodHit)
		{
			if(CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)){

				if(note.noteAbstract == "poison" || note.noteAbstract == "reverse poison") {
					for(i in 0...150) {
						new FlxTimer().start(0.25, function(tmr:FlxTimer) {
							setHealth(health - (0.001));
						});
					}
				}else if(note.noteAbstract == "trippy")	{
					setHealth(health - 0.3);
				}else if(note.noteAbstract == "planet notes") {
					setHealth(health - 0.4);
				}

				noteMiss(note.noteData, note, true);
			}

			if (!note.isSustainNote && !CustomNoteHandler.dontHitNotes.contains(note.noteAbstract))
			{
				popUpScore(Compile.getNoteTime(note.strumTime), note.noteData, note.noteAbstract);
				combo += 1;
			}

			if(note.noteAbstract == "regular" || note.noteAbstract == "ghost") {

				if (note.noteData >= 0)
					setHealth(health + 0.023);
				else
					setHealth(health + 0.004);
			}else if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract)) {

				if (note.noteData >= 0)
					setHealth(health + 0.004);
			}

			if(note.hasCustomAddon != null)
				setHealth(health + note.hasCustomAddon.giveHealth());

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

			note.pressedByPlayer(boyfriend, dad, gf);
			boyfriend.customAnimation = true;

			if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract) &&
			(boyfriend.customAnimation && (boyfriend.animation.curAnim.name.startsWith("sing") ||
			(boyfriend.animation.curAnim.name == "idle" || boyfriend.animation.curAnim.name.contains("dance"))))) {
				var animPlay:String = "";

				if(SONG.fifthKey) {
					switch (note.noteData)
					{
						case 0:
							animPlay = 'singLEFT' + playerAltAnim + boyfriend.hasBePlayer;
						case 1:
							animPlay = 'singDOWN' + playerAltAnim + boyfriend.hasBePlayer;
						case 2:
							if(note.noteAbstract == "cherry")
								animPlay = 'hey';
							else
								animPlay = 'singUP' + playerAltAnim + boyfriend.hasBePlayer;
						case 3:
							animPlay = 'singUP' + playerAltAnim + boyfriend.hasBePlayer;
						case 4:
							animPlay = 'singRIGHT' + playerAltAnim + boyfriend.hasBePlayer;
					}
				}else {
					switch (note.noteData)
					{
						case 0:
							animPlay = 'singLEFT' + playerAltAnim + boyfriend.hasBePlayer;
						case 1:
							animPlay = 'singDOWN' + playerAltAnim + boyfriend.hasBePlayer;
						case 2:
							animPlay = 'singUP' + playerAltAnim + boyfriend.hasBePlayer;
						case 3:
							animPlay = 'singRIGHT' + playerAltAnim + boyfriend.hasBePlayer;
					}
				}

				Register.events.whenNoteIsPressed(note, this);
				cameraMovement(note.noteData, note.isSustainNote);

				boyfriend.customAnimation = false;
				boyfriend.playAnim(animPlay, true);
			}

			playerStrums.forEach(function(spr:Strum)
			{
				if (Math.abs(note.noteData) == spr.ID)
				{
					if(note.noteAbstract != null)
						spr.ifCustom = note.noteAbstract;
					else
						spr.ifCustom = "regular";

					var key:Int = (SONG.fifthKey ? 5 : 4);

					note.splash(grpSplash.members[spr.ID], spr, daRating);
	
					/**
					* Old shit made in 2020 while trying to learn how Haxe and HaxeFlixel.
					*/
					try{ switch(spr.ifCustom) {
						case "reverse":
							spr.animation.play('static');
							spr.setColorTransform(3,3,0,0.75,0,0,0,0);

							var reverse:FlxSprite = new FlxSprite(spr.x-(spr.width/2), spr.y-(spr.width/2)).loadGraphic(Paths.image('reverse'));
							reverse.setGraphicSize(Std.int(spr.width*2));
							reverse.updateHitbox();
							reverse.cameras = [camNOTE];
							reverse.antialiasing = FlxG.save.data.showAntialiasing;

							if(FlxG.save.data.showEffect)
								add(reverse);

							if(FlxG.save.data.showEffect) {
								FlxTween.tween(reverse, {angle: 270}, 0.3, {ease: FlxEase.quadIn});
								FlxTween.tween(reverse, {alpha: 0}, 0.25, {ease: FlxEase.sineOut});
							}	

							new FlxTimer().start(0.25, function(tmr:FlxTimer) {
								spr.setColorTransform(1,1,1,1,0,0,0,0);

								if(FlxG.save.data.showEffect)
									remove(reverse);

								reverse = null;
							});
						case "poison":
							spr.animation.play('static');
							spr.setColorTransform(0.5,0,1.5,0.75,0,0,0,0);

							if(FlxG.save.data.showEffect) {
								grpSplash.members[spr.ID].setPosition(spr.x-(grpSplash.members[spr.ID].width/3), spr.y-(grpSplash.members[spr.ID].height/3));
								grpSplash.members[spr.ID].animation.play('sploosh' + spr.ID);
							}	

							new FlxTimer().start(0.25, function(tmr:FlxTimer) {
								FlxG.sound.play(Paths.sound("poison"));

								new FlxTimer().start(0.25, function(tmr:FlxTimer) {
									spr.setColorTransform(1,1,1,1,0,0,0,0);
								});
							});
						case "reverse poison":
							spr.animation.play('static');
							spr.setColorTransform(0.5,0,1.5,1.5,0,0,0,0);

							var reverse:FlxSprite = new FlxSprite(spr.x-(spr.width/2), spr.y-(spr.width/2)).loadGraphic(Paths.image('reversePoison'));
							reverse.setGraphicSize(Std.int(spr.width*2));
							reverse.updateHitbox();
							reverse.cameras = [camNOTE];
							reverse.antialiasing = FlxG.save.data.showAntialiasing;
							reverse.alpha = 1;

							if(FlxG.save.data.showEffect)
								add(reverse);

							if(FlxG.save.data.showEffect) {
								FlxTween.tween(reverse, {angle: 270}, 0.6, {ease: FlxEase.quadIn});
								FlxTween.tween(reverse, {alpha: 0}, 0.5, {ease: FlxEase.sineOut});

								grpSplash.members[spr.ID].setPosition(spr.x-(grpSplash.members[spr.ID].width/3), spr.y-(grpSplash.members[spr.ID].height/3));
								grpSplash.members[spr.ID].animation.play('sploosh' + spr.ID);
							}	

							new FlxTimer().start(0.25, function(tmr:FlxTimer) {
								FlxG.sound.play(Paths.sound("poison"));

								new FlxTimer().start(0.25, function(tmr:FlxTimer) {

									if(FlxG.save.data.showEffect)
										remove(reverse);

									reverse = null;
								});
							});
						case "spiritual star":
							spr.animation.play('static');
							FlxG.sound.play(Paths.sound("spoopyChild"));
							FlxTween.tween(spr, {onlyFans: 0}, 0.5, {ease: FlxEase.quadIn});

							new FlxTimer().start(5, function(tmr:FlxTimer) {
								FlxTween.tween(spr, {onlyFans: 1}, 0.5, {ease: FlxEase.quadOut});
							});
						case "trippy":
							spr.animation.play('static');

							var swirl:FlxSprite = new FlxSprite(spr.x-(spr.width/4), spr.y-(spr.width/4));
							swirl.frames = Paths.getSparrowAtlas('notes/trippy/NOTE_assets');
							swirl.animation.addByPrefix('spiral', 'swirl');
							swirl.updateHitbox();
							swirl.cameras = [camNOTE];
							swirl.antialiasing = FlxG.save.data.showAntialiasing;
							swirl.alpha = 0.5;
							add(swirl);

							swirl.animation.play('spiral');

							FlxTween.tween(swirl, {angle: 270}, 0.3*(Conductor.bpm/120), {ease: FlxEase.quadIn});
							FlxTween.tween(swirl, {alpha: 0}, 0.25*(Conductor.bpm/120), {ease: FlxEase.sineOut});

							new FlxTimer().start(0.25, function(tmr:FlxTimer) {
								swirl.kill();
								remove(swirl);
								swirl = null;
							});
						case "side note":
							spr.animation.play('static');
							spr.setColorTransform(1,1,1,1,0,0,0,0);
					}
				}}
			});

			if(CustomNoteHandler.ouchyNotes.contains(note.noteAbstract))
				return;

			note.wasGoodHit = true;
			vocals.volume = 1;

			if (!note.isSustainNote)
			{
				removeNote(note);
			}
		}
	}

	private function cameraMovement(noteCData:Int, isSus:Bool) {
		if(modifierCheckList('camera move') && Main.feeshmoraModifiers && !isSus) {
			if(noteCData == 0) {
				camMovementPos.x = (-SONG.bpm / 45) * 5;
				camMovementPos.y = 0;
			}

			if(noteCData == (strumLineNotes.members.length / 2) - 1) {
				camMovementPos.x = (SONG.bpm / 45) * 5;
				camMovementPos.y = 0;
			}

			if(noteCData == 1) {
				camMovementPos.y = (SONG.bpm / 45) * 5;
				camMovementPos.x = 0;
			}

			if(noteCData == (strumLineNotes.members.length / 2) - 2) {
				camMovementPos.y = (-SONG.bpm / 45) * 5;
				camMovementPos.x = 0;
			}
		}
	}

	function removeNote(note:Note) {
		note.kill();

		if(note.trail != null)						
			remove(note.trail);

		notes.remove(note, true);
		note.destroy();
	}

	function eventLoad():Void {
		var stepCounter = 0;

		if(SONG.modifiers == null)
			SONG.modifiers = [];

		while(stepCounter < SONG.modifiers.length) {
			var gridY = Reflect.field(SONG.modifiers[stepCounter], "modGridY");

			if((curStep*40) == gridY) //Just wanna make sure...
				break;

			stepCounter++;
		}

		if(stepCounter > SONG.modifiers.length)
			return;

		eventCounter = stepCounter;
		return eventLoad_Compile();
	}

	function eventLoad_Compile():Void {
		var value:String = Reflect.field(SONG.modifiers[eventCounter], "modValue");
		var value2:String = Reflect.field(SONG.modifiers[eventCounter], "modValueTwo");
		var skill:String = Reflect.field(SONG.modifiers[eventCounter], "modSkill");

		if(!modStorage.contains(skill))
			modStorage.push(skill);

		value = value.toLowerCase();
		value2 = value2.toLowerCase();

		Register.events.whenTriggered(skill, value, value2, this);
	}

	//Getter Function

	override function get_songPos():Float
		return Conductor.trackPosition;

	function get_playerStrums():FlxTypedSpriteGroup<Strum> {
		return playerStrums;
	}

	override function stepHit()
	{
		super.stepHit();

		if ((FlxG.sound.music.time > Conductor.trackPosition + 20 || FlxG.sound.music.time < Conductor.trackPosition - 20) && !paused)
		{
			resyncVocals();
		}

		if (dad.curCharacter == 'spooky' && curStep % 4 == 2)
		{
			// dad.dance();
		}

		if(CustomNoteHandler.yourNoteData["side note"] != null) {
			if(FlxFlicker.isFlickering(CustomNoteHandler.yourNoteData["side note"])) {
				FlxG.sound.play(Paths.sound('Warning'), 0.25);
			}
		}

		stageGroup.forEach(function(stage:StageBuilder) {
			stage.curStep();
		});
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

		if (SONG.notes[Math.floor(curStep / 16)] != null)
		{
			if (SONG.notes[Math.floor(curStep / 16)].changeBPM)
			{
				Conductor.changeBPM(SONG.notes[Math.floor(curStep / 16)].bpm);
				FlxG.log.add('CHANGED BPM!');
			}
			// else
			// Conductor.changeBPM(SONG.bpm);

			// Dad doesnt interupt his own notes
			if (SONG.notes[Math.floor(curStep / 16)].mustHitSection)
				dad.dance();
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

		if (camZooming && FlxG.camera.zoom < 1.35 && curBeat % 4 == 0)
		{
			FlxG.camera.zoom += 15 * FlxG.elapsed;
			camHUD.zoom += 6 * FlxG.elapsed;
			camNOTE.zoom += 6 * FlxG.elapsed;
		}

		iconP1.setGraphicSize(Std.int(iconP1.width + 30));
		iconP2.setGraphicSize(Std.int(iconP2.width + 30));
		iconP1.updateHitbox();
		iconP2.updateHitbox();

		if (curBeat % gfSpeed == 0)
		{
			gf.dance();
		}

		if (!boyfriend.animation.curAnim.name.startsWith("sing"))
		{
			if(boyfriend.animation.curAnim.name.startsWith("dodge") && boyfriend.animation.finished)
				boyfriend.dance();
			else if(!boyfriend.animation.curAnim.name.startsWith("dodge"))
				boyfriend.dance();
		}

		if (curBeat % 8 == 7 && curSong == 'Bopeebo')
		{
			boyfriend.playAnim('hey', true);
		}

		if (curBeat % 16 == 15 && SONG.song == 'Tutorial' && dad.curCharacter == 'gf' && curBeat > 16 && curBeat < 48)
		{
			boyfriend.playAnim('hey', true);
			dad.playAnim('cheer', true);
		}

		stageGroup.forEach(function(stage:StageBuilder) {
			stage.curBeat();
		});
	}

	override public function destroy() {
		Compile.kill();
		
		super.destroy();
	}
}