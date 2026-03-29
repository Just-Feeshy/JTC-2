package;

#if windows
import Discord.DiscordClient;
#end
import Section.SwagSection;
import Song.SwagSong;
import Conductor.BPMChangeEvent;
import WiggleEffect.WiggleEffectType;
import Controls.Control;
import Controls.Device;
import CheeseSliceSprite;
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
import flixel.input.gamepad.FlxGamepadInputID;
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
import openfl.Lib;
import openfl.system.System;
import openfl.display.BlendMode;
import openfl.display.StageQuality;
import openfl.filters.ShaderFilter;
import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilterQuality;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import feshixl.group.FeshEventGroup;
import feshixl.math.FeshMath;
import feshixl.FeshCamera;
import lime.utils.Assets;
import lime.system.ThreadPool;

import example_code.DefaultEvents;
import example_code.DefaultStage;
import template.CustomNote;
import template.StageBuilder;

import SaveData.SaveType;

using StringTools;

typedef QueuedLaneInput =
{
	var lane:Int;
	var pressed:Bool;
	var songTime:Float;
}

typedef SongTrackInfo =
{
	var tag:String;
	var fileName:String;
	var sound:FlxSound;
	var side:String;
	var baseVolume:Float;
	var stateVolume:Float;
	var looped:Bool;
	var tagFilters:Array<String>;
}

class PlayState extends MusicBeatState
{
	private static inline var GAMEPLAY_CAMERA_FOLLOW_LERP_60FPS:Float = 0.08;

	//Cache Stuff
	var precacheList:Map<String, String> = new Map<String, String>();

	//Lua Stuff
	public var modifiableCharacters:Map<String, Character>;

	//More Stuff
	public var stage:StageBuilder;

	private var createdCharacters:Bool;
	private var testSprite:FlxSprite;
	private var warningSprState:WarningSubGroup;
	private var curChar:String = '';
	private var camMovementPos:FlxPoint;
	public var showCountdownSprites:Bool = true;
	public var playCountdownSounds:Bool = true;
	private var prevDadNoteData:Int = -1;
    private var disableInputs:Bool = false;
	private var videoSwitchState:String = "";

		public var camPos:FlxPoint;
		public var flipWiggle:Int = 1;
		public var timeFreeze:Float = 0;
		public var health:Float = 1;
		public var healthLerp:Float = 1;
		public var hudIconsStatic:Bool = false;

		public var healthTween:FlxTween;
		public var prevHealth:Float = 0;

	inline function getGameplayCameraFollowLerp():Float
	{
		return GAMEPLAY_CAMERA_FOLLOW_LERP_60FPS * 60 / FlxG.updateFramerate;
	}

	public var opponentAltAnim:String = "";
	public var playerAltAnim:String = "";

	private var isPixel:Bool = false;

	//Event Stuff
	public var eventInfo(default, null):Array<EventInfo>;

	public var eventCounter:Int = 0;
	public var prevEventStep:Int = 0;
	private static inline var SONG_TRACK_SIDE_PLAYER:String = "player";
	private static inline var SONG_TRACK_SIDE_OPPONENT:String = "opponent";
	private static inline var SONG_TRACK_SIDE_EXTRA:String = "extra";
	private static inline var SONG_TRACK_SIDE_SHARED:String = "shared";
	private static inline var PLAYER_VOCALS_TRACK_TAG:String = "__player_vocals";
	private static inline var OPPONENT_VOCALS_TRACK_TAG:String = "__opponent_vocals";
	private static inline var SHARED_VOCALS_TRACK_TAG:String = "__shared_vocals";
	private static inline var SONG_TRACK_DESYNC_TOLERANCE:Float = 20;

	//Modifier Values
	public var singDrainValue:Float = 1;
	public var fadeInValue:Int = 400;
	public var cameraMovementInsensity:Float = 1;
	inline static var CAMERA_MOVEMENT_OFFSET_SCALE:Float = 2.5;
	inline static var CAMERA_MOVEMENT_EASE:Float = 0.32;
	public var vSliceCameraFocusEnabled:Bool = false;
	public var vSliceCameraFocusX:Float = 0;
	public var vSliceCameraFocusY:Float = 0;
	public var vSliceCameraFocusLerp:Float = 0;
	public var vSliceDirectZoomEnabled:Bool = false;
	public var vSliceDirectZoomValue:Float = 1;

	@:isVar public var wobbleModPower(get, set):Float = 30;

	//Chart Shit
	public static var muteInst:Bool;
	public var eventStorage:Array<String> = [];

	//Camera Shit
	public static var camHUD:FeshCamera;
	public static var camNOTE:CameraNote;
	private var ownedCamHUD:FeshCamera;
	private var ownedCamNOTE:CameraNote;
	private var ownedCamNoteSustain:FeshCamera;
	private var playLua:PlayLua;
	public var playScrollSpeed:PlayScrollSpeed;

	//Note Stuff Funk U
	private var trippyWiggle:WiggleEffect = new WiggleEffect();
	private var triggerGroup:FlxTypedGroup<FlxSprite>;
	private var grpHoldCover:FlxTypedGroup<HoldCoverSprite>;
	private var grpSplash:FlxTypedGroup<SplashSprite>;
	private var trippyShader:ShaderFilter;
	private var currentHoldCoverSprites:Array<HoldCoverSprite> = [];
	private var currentHoldCoverTimers:Array<Float> = [];
	private var oppositeHoldCoverSprites:Array<HoldCoverSprite> = [];
	private var oppositeHoldCoverTimers:Array<Float> = [];

	//Controls
	private var keys2DArray:Array<Array<Int>> = [];
	private var inputQueue:Array<QueuedLaneInput> = [];
	private var heldLaneKeys:Array<Array<Int>> = [];
	private var previousHeldInputSongTime:Null<Float> = null;

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
	private static var skipDialogueSongOnNextLoad:String = null;

	var daRating:String = "sick";

	private var curSection:Int = 0;

	private var vocals:FlxSound;
	private var opponentVocals:FlxSound;
	private var syncedSongTracks:Array<SongTrackInfo> = [];
	private var syncedSongTrackMap:Map<String, SongTrackInfo> = new Map<String, SongTrackInfo>();

	public var dad:Character;
	public var gf:Character;
	public var boyfriend:Boyfriend;

	public var currentPlayer(get, never):Character;
	public var currentOpponent(get, never):Character;

	public var notes:FlxTypedGroup<Note>;
	public var unspawnNotes:Array<Note> = [];

	public var waitForFinishPlayer:Bool = false;
	public var waitForFinishOpponent:Bool = false;

	public var bumpPerBeat:Int = 4;
	public var bumpForce:Float = 1;
	public var bumpOffset:Int = 0;

	private var strumLine:FlxSprite;
	public var camFollow:FlxObject;

	private static var prevCamFollow:FlxObject;

	public var strumLineNotes:FlxTypedGroup<Strum>;

	public static var playerStrums:FlxTypedSpriteGroup<Strum>;
	public static var opponentStrums:FlxTypedSpriteGroup<Strum>;

	public var currentStrums(get, never):FlxTypedSpriteGroup<Strum>;
	public var oppositeStrums(get, never):FlxTypedSpriteGroup<Strum>;

	/*
	* When note is missed, player WON'T receive damage.
	*/
	public var avoidHealthIssues:Bool = false;

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

	public var defaultCamZoom:Float = 1.05;

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
		playLua = new PlayLua(this);
		playScrollSpeed = new PlayScrollSpeed();
		PlayScrollSpeed.active = playScrollSpeed;

		Note.AFFECTED_SCROLLSPEED = 1;
		Note.AFFECTED_STRUMTIME = 0;

		muteInst = muted;
		super("sticker", "sticker");
	}

	public static function skipDialogueOnNextLoad(?song:String):Void {
		if(song == null || song.trim() == "") {
			song = SONG != null ? SONG.song : null;
		}

		skipDialogueSongOnNextLoad = song != null ? song.toLowerCase() : null;
	}

	function consumeSkipDialogueOnLoad():Bool {
		if(skipDialogueSongOnNextLoad == null || SONG == null || SONG.song == null) {
			return false;
		}

		var shouldSkip = skipDialogueSongOnNextLoad == SONG.song.toLowerCase();

		if(shouldSkip) {
			skipDialogueSongOnNextLoad = null;
		}

		return shouldSkip;
	}

	override public function create() {

		modifiableCharacters = new Map<String, Character>();

		Cache.clearNoneCachedAssets();

		FlxG.mouse.visible = false;
		//testSprite.visible = false;
		eventStorage = [];

		if (FlxG.sound.music != null)
			FlxG.sound.music.stop();

		SaveData.saveClient();

		camGame = new FeshCamera();
		camNOTE = new CameraNote();
		camNOTE.createSustainCam();
		camHUD = new FeshCamera();
		ownedCamNOTE = camNOTE;
		ownedCamNoteSustain = camNOTE.camNoteSustain;
		ownedCamHUD = camHUD;
		camHUD.bgColor.alpha = 0;
		camNOTE.bgColor.alpha = 0;

		FlxG.cameras.reset(camGame);
		FlxG.cameras.add(camNOTE);
		FlxG.cameras.add(camNOTE.camNoteSustain);
		FlxG.cameras.add(camHUD);

		FlxCamera.defaultCameras = [camGame];

		persistentUpdate = true;
		persistentDraw = true;

		if (SONG == null)
			SONG = Song.loadFromJson('tutorial');

		readableSong = SONG.song.toLowerCase();

		if(Paths.assetExists(Paths.getPath('data/warning.txt', TEXT, ""), TEXT)) //WIP
			if(Paths.readText(Paths.txt('${readableSong}/warning')) != "" 
			&& Paths.readText(Paths.txt('${readableSong}/warning')) != null)
				hasWarning = true;
			else
				hasWarning = false;
		else
			hasWarning = false;

		if(SONG.modifiers == null)
			SONG.modifiers = [];

		// Making difficulty text for Discord Rich Presence.
		storyDifficultyText = CoolUtil.getDifficultyName(storyDifficulty);

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

		if(SaveData.getData(MISS_SOUND_VOLUME) > 0) {
			precacheList.set('missnote1', 'sound');
			precacheList.set('missnote2', 'sound');
			precacheList.set('missnote3', 'sound');
		}

		precacheList.set(PlayState.SONG.song, 'voices');
		precacheList.set(PlayState.SONG.song, 'inst');

		precacheList.set("iconGrid", 'images');
		
		updateCache();
		generateSong(SONG.song);

		camFollow = new FlxObject(0, 0, 1, 1);

		camFollow.setPosition(camPos.x + camMovementPos.x, camPos.y + camMovementPos.y);

		if (prevCamFollow != null)
		{
			camFollow = prevCamFollow;
			prevCamFollow = null;
		}

		add(camFollow);

		FlxG.camera.follow(camFollow, LOCKON, getGameplayCameraFollowLerp());
		// FlxG.camera.setScrollBounds(0, FlxG.width, 0, FlxG.height);
		FlxG.camera.zoom = defaultCamZoom;
		vSliceDirectZoomValue = defaultCamZoom;
		vSliceCameraFocusX = camPos.x;
		vSliceCameraFocusY = camPos.y;
		vSliceCameraFocusLerp = 0;
		FlxG.camera.focusOn(camFollow.getPosition());

		FlxG.worldBounds.set(0, 0, FlxG.width, FlxG.height);

		//FlxG.fixedTimestep = false;

		healthBarBG = new FlxSprite(0, FlxG.height * 0.9).loadGraphic(Paths.image('healthBar'));

		if (FlxG.save.data.helpme)
			healthBarBG.y = 50;

		healthBarBG.screenCenter(X);
		healthBarBG.scrollFactor.set();

		counterTxt = new FlxText(healthBarBG.x + healthBarBG.width - 190, healthBarBG.y + 32, 0, "", 20);
		counterTxt.setFormat(Paths.font("vcr.ttf"), 18, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		counterTxt.antialiasing = FlxG.save.data.showAntialiasing;
		counterTxt.scrollFactor.set();

		iconP1 = new HealthIcon(SONG.player1, true);
		iconP2 = new HealthIcon(SONG.player2, false);

		if(boyfriend.curCharacter != "none") iconP1.createAnim(boyfriend.curCharacter, boyfriend._info.icon, true);
		if(dad.curCharacter != "none") iconP2.createAnim(dad.curCharacter, dad._info.icon, false);

		stage.configIcons(iconP1, iconP2);

		if(SaveData.getData(PLAY_AS_OPPONENT)) {
			iconP2.bpm = SONG.bpm;
		}else {
			iconP1.bpm = SONG.bpm;
		}

			healthBar = new HealthBar(healthBarBG.x + 4, healthBarBG.y + 4, Std.int(healthBarBG.width - 8), Std.int(healthBarBG.height - 8), this,
				'healthLerp', 0, 2);
		healthBar.subtractIt = SaveData.getData(PLAY_AS_OPPONENT);
		healthBar.scrollFactor.set();

		playerIconColor = CoolUtil.calculateAverageColor(iconP1.updateFramePixels());
		opponentIconColor = CoolUtil.calculateAverageColor(iconP2.updateFramePixels());
		healthBar.createFilledBar(opponentIconColor, playerIconColor);

		createScene();

		getLuaScript();

		if(playLua.hasScript()) {
			generateStaticLua();
			updateLuaVars();
		}

		iconP1.y = healthBar.y - (iconP1.height / 2);
		iconP2.y = healthBar.y - (iconP2.height / 2);

		strumLineNotes.cameras = [camNOTE];
		notes.cameras = [camNOTE];
		grpHoldCover.cameras = [camNOTE.camNoteSustain];
		grpSplash.cameras = [camNOTE];
		healthBar.cameras = [camHUD];
		healthBarBG.cameras = [camHUD];
		iconP1.cameras = [camHUD];
		iconP2.cameras = [camHUD];
		counterTxt.cameras = [camHUD];

		if(SONG.modifiers != null)
			eventInfo = SONG.modifiers.copy();
		else
			eventInfo = [];

		eventInfo.sort(function(a:EventInfo, b:EventInfo):Int {
			var aTime:Null<Float> = Reflect.field(a, "modTime");
			var bTime:Null<Float> = Reflect.field(b, "modTime");

			if(aTime != null && bTime != null)
				return aTime < bTime ? -1 : (aTime > bTime ? 1 : 0);

			var aGrid:Int = Reflect.field(a, "modGridY");
			var bGrid:Int = Reflect.field(b, "modGridY");
			return aGrid < bGrid ? -1 : (aGrid > bGrid ? 1 : 0);
		});

		startingSong = true;

		if(!hasWarning)
			inDeBenigin();

		setupKeyStuff();

		if(FlxG.keys.enabled) {
			FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, getPressed);
			FlxG.stage.addEventListener(KeyboardEvent.KEY_UP, getReleased);
		}

		super.create();

		stage.finishedInitGame();
	}

	function updateCache():Void {
		for (key => type in precacheList) {
			switch(type) {
				case 'image':
					Paths.image(key);
				case 'sound':
					Paths.sound(key);
				case 'music':
					Paths.music(key);
				case "voices":
					if (Paths.songSoundExists(key, "1_Voices") && Paths.songSoundExists(key, "2_Voices")) {
						Paths.songSound(key, "1_Voices");
						Paths.songSound(key, "2_Voices");
					}else {
						Paths.voices(key);
					}
				case "inst":
					Paths.inst(key);
			}
		}
	}

	function setupKeyStuff():Void {
		if(SONG.fifthKey) {
			singAnims = ["singLEFT", "singDOWN", "singUP", "singUP", "singRIGHT"];
		}else {
			singAnims = ["singLEFT", "singDOWN", "singUP", "singRIGHT"];
		}

		SaveData.saveClient();

		keys2DArray = [];

		var laneControls = getLaneControls();
		var index:Int = 0;

		while(index < laneControls.length) {
			keys2DArray[index] = controls.getInputsFor(laneControls[index], Keys, []);
			index++;
		}

		resetHeldLaneKeys();
	}

	function resetHeldLaneKeys():Void {
		heldLaneKeys = [];

		var index:Int = 0;
		while(index < getLaneCount()) {
			heldLaneKeys.push([]);
			index++;
		}
	}

	function inDeBenigin() {
		var skipDialogueForReload:Bool = consumeSkipDialogueOnLoad() || SaveData.getData(SaveType.SKIP_CUTSCENES);

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
					if(skipDialogueForReload) {
						startCountdown();
						return;
					}

					if(curSong.toLowerCase() == 'roses') {
						FlxG.sound.play(Paths.sound('ANGRY'));
					}

					var dialogue:Array<String> = ['blah blah blah', 'coolswag'];
					var file:String = Paths.txt(readableSong + '/' + readableSong + 'Dialogue');

					if (Paths.assetExists(file, TEXT)) {
						dialogue = CoolUtil.coolTextFile(file);
					}

					doof = new DialogueBox(false, dialogue);
					doof.scrollFactor.set();
					doof.finishThing = startCountdown;
					doof.cameras = [camHUD];

					schoolIntro(doof);
				default:
					var dialogueBox = Type.createInstance(cast Register.dialogues.get(curSong.toLowerCase()), []);

					if(dialogueBox != null && !skipDialogueForReload) {
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
				healthTween = null;
			}

			prevHealth = hp;
			health = hp;
		}

		function updateHealthBar():Void {
			if(modifierCheckList('bot mode')) {
				healthLerp = 2;
			}else {
				healthLerp = FlxMath.lerp(healthLerp, health, 0.15);
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
		DefaultHandler.modifiers.cameraMovement.enabled = true;
		DefaultHandler.modifiers.botMode.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.BOT_MODE_MOD) #else false #end;

		if(modifierCheckList('bot mode')) {
			SONG.validScore = false;
		}
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
			case "camera move":
				return true;
			case "bot mode":
				return DefaultHandler.modifiers.botMode.enabled;
			default: return false;
		}
	}

	function startCountdown():Void {
		FlxG.sound.music.stop();
		inCutscene = false;
		showCountdownSprites = true;
		playCountdownSounds = true;

		add(healthBarBG);
		add(healthBar);
		add(counterTxt);
		add(iconP1);
		add(iconP2);

		generateStaticArrows(0);
		generateStaticArrows(1);
		setupHoldCoverSprites();

		talking = false;
		startedCountdown = true;
		previousHeldInputSongTime = null;
		Conductor.songPosition = 0;
		Conductor.songPosition -= Conductor.crochet * 5;
		Conductor.trackPosition = Conductor.songPosition + SaveData.getData(NOTE_OFFSET);

		makeNoteLua();

		playLua.set("startedCountdown", true);
		playLua.call("generatedStage", []);

		if (!showCountdownSprites && !playCountdownSounds)
		{
			iconP1.setGraphicSize(Std.int(iconP1.width + 30));

			if(gf != null) {
				gf.dance();
			}

			dad.dance();
			boyfriend.dance();

			Conductor.songPosition = 0;
			Conductor.trackPosition = Conductor.songPosition + SaveData.getData(NOTE_OFFSET);
			startSong();
			return;
		}

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
					if (playCountdownSounds)
						FlxG.sound.play(Paths.sound('intro3'), 0.6);
				case 1:
					if (showCountdownSprites)
					{
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
					}
					if (playCountdownSounds)
						FlxG.sound.play(Paths.sound('intro2'), 0.6);
				case 2:
					if (showCountdownSprites)
					{
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
					}
					if (playCountdownSounds)
						FlxG.sound.play(Paths.sound('intro1'), 0.6);
				case 3:
					if (showCountdownSprites)
					{
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
					}
					if (playCountdownSounds)
						FlxG.sound.play(Paths.sound('introGo'), 0.6);
			}

			swagCounter += 1;
			// generateSong('fresh');
		}, 5);
	}

	var previousFrameTime:Int = 0;
	var lastReportedPlayheadPosition:Int = 0;
	var songTime:Float = 0;

	private function parseSongTrackSide(side:String):String
	{
		if (side == null)
			return SONG_TRACK_SIDE_EXTRA;

		var normalizedSide = side.trim().toLowerCase();

		return switch (normalizedSide)
		{
			case SONG_TRACK_SIDE_PLAYER, SONG_TRACK_SIDE_OPPONENT, SONG_TRACK_SIDE_SHARED:
				normalizedSide;
			default:
				SONG_TRACK_SIDE_EXTRA;
		}
	}

	private function normalizeSongTrackFilters(filterString:String):Array<String>
	{
		var filters:Array<String> = [];

		if (filterString == null)
			return filters;

		for (entry in filterString.split(","))
		{
			var normalizedEntry = entry.trim().toLowerCase();

			if (normalizedEntry != "")
				filters.push(normalizedEntry);
		}

		return filters;
	}

	private function sanitizeSongTrackFilters(filters:Array<String>):Array<String>
	{
		var normalizedFilters:Array<String> = [];

		if (filters == null)
			return normalizedFilters;

		for (entry in filters)
		{
			if (entry == null)
				continue;

			var normalizedEntry = entry.trim().toLowerCase();

			if (normalizedEntry != "")
				normalizedFilters.push(normalizedEntry);
		}

		return normalizedFilters;
	}

	private inline function isSongTrackInSoundList(sound:FlxSound):Bool
	{
		return sound != null
			&& FlxG.sound.list != null
			&& FlxG.sound.list.members != null
			&& FlxG.sound.list.members.contains(sound);
	}

	private inline function applySongTrackVolume(track:SongTrackInfo):Void
	{
		if (track != null && track.sound != null)
			track.sound.volume = track.baseVolume * track.stateVolume;
	}

	private function songTrackMatchesTag(track:SongTrackInfo, noteTag:String):Bool
	{
		if (track == null || track.tagFilters == null || track.tagFilters.length == 0)
			return true;

		if (noteTag == null)
			return false;

		return track.tagFilters.contains(noteTag.trim().toLowerCase());
	}

	private function registerSongTrack(tag:String, fileName:String, sound:FlxSound, side:String, baseVolume:Float = 1,
		looped:Bool = false, ?tagFilters:Array<String>):SongTrackInfo
	{
		if (tag == null || tag.trim() == "" || sound == null)
			return null;

		var normalizedTag = tag.trim();

		if (syncedSongTrackMap.exists(normalizedTag))
			destroySongTrack(normalizedTag);

		var track:SongTrackInfo = {
			tag: normalizedTag,
			fileName: fileName,
			sound: sound,
			side: parseSongTrackSide(side),
			baseVolume: baseVolume,
			stateVolume: 1,
			looped: looped,
			tagFilters: sanitizeSongTrackFilters(tagFilters)
		};

		syncedSongTracks.push(track);
		syncedSongTrackMap.set(track.tag, track);

		if (!isSongTrackInSoundList(sound))
			FlxG.sound.list.add(sound);

		applySongTrackVolume(track);
		return track;
	}

	private function destroySongTrack(tag:String):Void
	{
		if (tag == null || !syncedSongTrackMap.exists(tag))
			return;

		var track = syncedSongTrackMap.get(tag);
		syncedSongTrackMap.remove(tag);
		syncedSongTracks.remove(track);

		if (track.sound != null)
		{
			track.sound.stop();

			if (isSongTrackInSoundList(track.sound))
				FlxG.sound.list.remove(track.sound, true);

			track.sound.destroy();
		}

		if (vocals == track.sound)
			vocals = new FlxSound();

		if (opponentVocals == track.sound)
			opponentVocals = null;
	}

	private function destroyAllSongTracks():Void
	{
		for (track in syncedSongTracks.copy())
			destroySongTrack(track.tag);

		syncedSongTracks = [];
		syncedSongTrackMap = new Map<String, SongTrackInfo>();
		vocals = new FlxSound();
		opponentVocals = null;
	}

	private function playSongTrack(track:SongTrackInfo, ?startTime:Null<Float>):Void
	{
		if (track == null || track.sound == null)
			return;

		if (startTime != null)
			track.sound.time = startTime;

		track.sound.play(false, startTime != null ? startTime : track.sound.time);

		applySongTrackVolume(track);
	}

	private function addSongTrack(tag:String, fileName:String, side:String = SONG_TRACK_SIDE_EXTRA, baseVolume:Float = 1,
		looped:Bool = false, ?tagFilters:Array<String>):Bool
	{
		if (tag == null || tag.trim() == "" || fileName == null || fileName.trim() == "")
			return false;

		if (!Paths.songSoundExists(PlayState.SONG.song, fileName))
			return false;

		var sound = new FlxSound().loadEmbedded(Paths.songSound(PlayState.SONG.song, fileName), looped);
		var track = registerSongTrack(tag, fileName, sound, side, baseVolume, looped, tagFilters);

		if (track == null)
			return false;

		if (FlxG.sound.music != null && FlxG.sound.music.playing && !paused)
		{
			track.sound.time = FlxG.sound.music.time;
			playSongTrack(track, FlxG.sound.music.time);
		}

		return true;
	}

	private function hasSongTrackDesync(baseTime:Float):Bool
	{
		for (track in syncedSongTracks)
		{
			if (track.sound != null && Math.abs(track.sound.time - baseTime) > SONG_TRACK_DESYNC_TOLERANCE)
				return true;
		}

		return false;
	}

	private function loadSongVocals(song:String):Void
	{
		destroyAllSongTracks();
		opponentVocals = null;

		if (SONG.needsVoices)
		{
			var hasSplitVocals:Bool = Paths.songSoundExists(song, "1_Voices") && Paths.songSoundExists(song, "2_Voices");
			var hasSingleVocals:Bool = Paths.songSoundExists(song, "Voices");

			if (hasSplitVocals)
			{
				vocals = new FlxSound().loadEmbedded(Paths.songSound(song, "1_Voices"));
				opponentVocals = new FlxSound().loadEmbedded(Paths.songSound(song, "2_Voices"));
				registerSongTrack(PLAYER_VOCALS_TRACK_TAG, "1_Voices", vocals, SONG_TRACK_SIDE_PLAYER);
				registerSongTrack(OPPONENT_VOCALS_TRACK_TAG, "2_Voices", opponentVocals, SONG_TRACK_SIDE_OPPONENT);
			}
			else if (hasSingleVocals)
			{
				vocals = new FlxSound().loadEmbedded(Paths.voices(song));
				registerSongTrack(SHARED_VOCALS_TRACK_TAG, "Voices", vocals, SONG_TRACK_SIDE_SHARED);
			}
			else
			{
				trace("Warning: no vocals found for " + song + ", continuing without vocals.");
				vocals = new FlxSound();
			}
		}
		else
		{
			vocals = new FlxSound();
		}
	}

	private inline function pauseVocals():Void
	{
		for (track in syncedSongTracks)
			track.sound.pause();
	}

	private inline function playVocals(?startTime:Null<Float>):Void
	{
		for (track in syncedSongTracks)
			playSongTrack(track, startTime);
	}

	private inline function stopVocals():Void
	{
		for (track in syncedSongTracks)
			track.sound.stop();
	}

	private inline function setVocalsTime(time:Float):Void
	{
		for (track in syncedSongTracks)
			track.sound.time = time;
	}

	private inline function setAllVocalsVolume(volume:Float):Void
	{
		for (track in syncedSongTracks)
		{
			track.stateVolume = volume;
			applySongTrackVolume(track);
		}
	}

	private inline function setPlayerVocalsVolume(volume:Float, ?noteTag:String):Void
	{
		for (track in syncedSongTracks)
		{
			if ((track.side == SONG_TRACK_SIDE_PLAYER || track.side == SONG_TRACK_SIDE_SHARED) && songTrackMatchesTag(track, noteTag))
			{
				track.stateVolume = volume;
				applySongTrackVolume(track);
			}
		}
	}

	private inline function setOpponentVocalsVolume(volume:Float, ?noteTag:String):Void
	{
		for (track in syncedSongTracks)
		{
			if ((track.side == SONG_TRACK_SIDE_OPPONENT || track.side == SONG_TRACK_SIDE_SHARED) && songTrackMatchesTag(track, noteTag))
			{
				track.stateVolume = volume;
				applySongTrackVolume(track);
			}
		}
	}

	private inline function hasCharacterAnimation(character:Character, animName:String):Bool
	{
		return character != null && character.animation != null && character.animation.getByName(animName) != null;
	}

	private inline function breakComboOnMiss():Void
	{
		if(gf != null && combo > 5 && gf.animOffsets.exists('sad'))
		{
			gf.playNoDanceAnim('sad');
		}

		combo = 0;
	}

	private function playPlayerMissAnimation(direction:Int):Void
	{
		var missAnim:String = singAnims[direction] + "miss";
		var fallbackAnim:String = singAnims[direction];

		if(hasCharacterAnimation(currentPlayer, missAnim))
		{
			currentPlayer.playNoDanceAnim(missAnim, true);
		}
		else if(hasCharacterAnimation(currentPlayer, fallbackAnim))
		{
			currentPlayer.playNoDanceAnim(fallbackAnim, true);
		}

		currentPlayer.holdTimer = 0;
	}

	private function applyPlayerMissFeedback(direction:Int, ?noteTag:String, playSound:Bool = true, playAnim:Bool = true):Void
	{
		setPlayerVocalsVolume(0, noteTag);

		if(playSound && SaveData.getData(MISS_SOUND_VOLUME) > 0)
		{
			FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), SaveData.getData(MISS_SOUND_VOLUME) * FlxG.random.float(0.1, 0.2));
		}

		if(playAnim)
		{
			playPlayerMissAnimation(direction);
		}
	}

	private function startInstrumentTrack(?startTime:Null<Float>):Void
	{
		if (FlxG.sound.music == null)
			FlxG.sound.music = new FlxSound();
		else
			FlxG.sound.music.stop();

		FlxG.sound.music.loadEmbedded(Paths.inst(PlayState.SONG.song), false);
		FlxG.sound.music.persist = true;
		FlxG.sound.music.group = FlxG.sound.defaultMusicGroup;
		FlxG.sound.music.volume = muteInst ? 0 : 1;
		FlxG.sound.music.play(false, startTime == null ? 0 : startTime);
		FlxG.sound.music.onComplete = whenSongFinished.bind();
	}

	function startSong():Void
	{
		startingSong = false;
		previousHeldInputSongTime = null;

		previousFrameTime = FlxG.game.ticks;
		lastReportedPlayheadPosition = 0;

		startInstrumentTrack(0);
		playVocals(FlxG.sound.music != null ? FlxG.sound.music.time : 0);

		if(paused) {
			FlxG.sound.music.pause();
			pauseVocals();
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

		loadSongVocals(PlayState.SONG.song);

		notes = new FlxTypedGroup<Note>();
		add(notes);

		grpHoldCover = new FlxTypedGroup<HoldCoverSprite>();
		add(grpHoldCover);

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

				if(songNotes[5] != null)
					swagNote.playAnyAnimation = songNotes[5];

				if(songNotes[4] != null) {
					swagNote.tag = songNotes[4];
				}

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

				swagNote.mustPress = gottaHitNote;

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

			playLua.call('onResume', []);

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
			pauseVocals();
		}

		if(startTimer != null) {
			if (!startTimer.finished)
				startTimer.active = false;
		}
	}

	public function resyncVocals():Void {
		if(timeFreeze > 0)
			return;

		pauseVocals();
		previousHeldInputSongTime = null;

		if(muteInst)
			FlxG.sound.music.volume = 0;

		FlxG.sound.music.play();
		setSongPosition(FlxG.sound.music.time);
		setVocalsTime(FlxG.sound.music.time);
		playVocals(FlxG.sound.music.time);
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

	function calculateNoteY(note:Note, downscroll:Bool):Float {
		var noteCacurations:Float = (-0.45 * (downscroll ? -1 : 1))
			* PlayScrollSpeed.getVisualSongDelta(DefaultHandler.getNoteTime(note.strumTime), Conductor.trackPosition)
			* FlxMath.roundDecimal(note.howSpeed, 2);
		var yAddon:Float = 0;
		
		if(note.height < 50 && note.isSustainNote) {
			yAddon -= (Note.swagWidth - note.height) * 0.5;

			if(note.downscrollNote) {
				yAddon -= ((Note.swagWidth - note.height) * 0.5) * Math.cos(note.angle);
			}else {
				yAddon += ((Note.swagWidth - note.height) * 0.5) * Math.cos(note.angle);
				yAddon *= -1;
			}
		}

		return noteCacurations - yAddon;
	}

	function cutOff(note:Note, downscroll:Bool):Float {
		var noteCacurations:Float = (-0.45 * (downscroll ? -1 : 1))
			* PlayScrollSpeed.getVisualSongDelta(DefaultHandler.getNoteTime(note.strumTime), Conductor.trackPosition)
			* FlxMath.roundDecimal(note.howSpeed, 2);
		var yAddon:Float = 0;
		
		if(note.height < 50 && note.isSustainNote) {
			yAddon += (Note.swagWidth - note.height) * 0.5;

			if(note.downscrollNote) {
				yAddon += ((Note.swagWidth - note.height));
				yAddon *= -1;
			}else {
				yAddon -= ((Note.swagWidth - note.height) * 0.5) * Math.cos(note.angle);
			}
		}

		return noteCacurations - yAddon;
	}

	function addToNoteX(alreadyX:Float, note:Note):Float {
		return alreadyX;
	}

	private var paused:Bool = false;
	var startedCountdown:Bool = false;
	var canPause:Bool = true;

	override public function update(elapsed:Float)
	{
		FlxG.camera.followLerp = getGameplayCameraFollowLerp();

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

		if (startingSong)
		{
			if (startedCountdown)
			{
				Conductor.songPosition += FlxG.elapsed * 1000;
				Conductor.trackPosition = Conductor.songPosition + SaveData.getData(NOTE_OFFSET);

				if (Conductor.trackPosition >= 0) {
					startSong();
				}
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

		super.update(elapsed);

		noteBeat = curBeat;

		if(playFPS != null && Lib.current.stage.frameRate < playFPS && SONG.modifyFPS) {
			Register.updateFramerate(playFPS * SaveData.getData(SaveType.FPS_MULTIPLIER));
			Main.framerate = playFPS;
		}

		if(FlxG.save.data.showstuff) {
			counterTxt.text = 'Accuracy: ' + accTotal + '%' + '       ' + 'Miss Clicks: ' + missClicks + '       ' + 'Misses: ' + misses + '       ' + 'Score: ' + songScore;
			counterTxt.screenCenter(X);
		}else
			counterTxt.text = "Score: " + songScore;

		events.whenGameIsRunning(eventStorage, this);

		if (controls.PAUSE && startedCountdown && canPause){
			pauseMenu();
		}

		if(hasWarning && !startedCountdown) { //All this just for a simple warning screen...
			persistentUpdate = false;
			persistentDraw = true;
			hasWarning = false;

			warningSprState = new WarningSubGroup([Paths.readText(Paths.txt('${SONG.song.toLowerCase()}/warning'))]);
			warningSprState.screenCenter();
			add(warningSprState);
		}else if(!hasWarning && warningSprState != null && !startedCountdown) {
			if(warningSprState.acceptedTermsOfService) {
				warningSprState.acceptedTermsOfService = false;
				remove(warningSprState);
				inDeBenigin();
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

			if(!hudIconsStatic) {
				iconP1.setGraphicSize(Std.int(FlxMath.lerp(iconP1.width, 150, 0.1/(Main.framerate/100))));
				iconP2.setGraphicSize(Std.int(FlxMath.lerp(iconP2.width, 150, 0.1/(Main.framerate/100))));

				iconP1.updateHitbox();
				iconP2.updateHitbox();
			}

			if (health > 2)
				health = 2;

			updateHealthBar();
			healthBar.updateValueFromParent();

			if(!hudIconsStatic) {
				var iconOffset:Int = 26;

				iconP1.x = healthBar.x + (healthBar.barWidth * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01) - iconOffset);
				iconP2.x = healthBar.x + (healthBar.barWidth * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01)) - (iconP2.width - iconOffset);
			}

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

		var liveEventStep:Int = getStepFromTime(Conductor.songPosition);

		if(startedCountdown && !startingSong && !inCutscene && prevEventStep != liveEventStep) {
			prevEventStep = liveEventStep;
			eventLoad();
		}

		var cameraPlaybackTime:Float = Conductor.songPosition;
		var cameraFollowStep:Int = Std.int(Math.max(getStepFromTime(cameraPlaybackTime) - 4, 0));
		var cameraSectionIndex:Int = Std.int(cameraFollowStep / 16);

		if (generatedMusic && startedCountdown && !inCutscene && SONG.notes[cameraSectionIndex] != null)
		{
			if (!SONG.notes[cameraSectionIndex].mustHitSection)
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
					setOpponentVocalsVolume(1);

				if (SONG.song.toLowerCase() == 'tutorial')
				{
					tweenCamIn();
				}
			}

			if(SONG.notes[cameraSectionIndex].mustHitSection)
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

				var followX:Float = camPos.x + camMovementPos.x;
				var followY:Float = camPos.y + camMovementPos.y;

				if(vSliceCameraFocusEnabled) {
					var focusLerp:Float = FlxMath.bound(vSliceCameraFocusLerp, 0, 1);
					followX = FlxMath.lerp(vSliceCameraFocusX, camPos.x, focusLerp) + camMovementPos.x;
					followY = FlxMath.lerp(vSliceCameraFocusY, camPos.y, focusLerp) + camMovementPos.y;
				}

			camFollow.setPosition(followX, followY);
		}

		if (camZooming)
		{
			FlxG.camera.zoom = FlxMath.lerp(defaultCamZoom, FlxG.camera.zoom, 0.95);
			camHUD.zoom = FlxMath.lerp(1, camHUD.zoom, 0.95);
			camNOTE.zoom = FlxMath.lerp(1, camNOTE.zoom, 0.95);
		}

		if(vSliceDirectZoomEnabled) {
			FlxG.camera.zoom = vSliceDirectZoomValue;
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
					setAllVocalsVolume(0);
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
				stage.modifyNotesDirectly(dunceNote);
				notes.add(dunceNote);

				if(dunceNote.hasCustomAddon != null)
					dunceNote.hasCustomAddon.whenIsSpawned(dunceNote);

				var index:Int = unspawnNotes.indexOf(dunceNote);
				unspawnNotes.splice(index, 1);
			}
		}

		if(FlxG.gamepads.lastActive != null) {
			controllerInput();
		}

		if (generatedMusic && !inCutscene)
		{
			defaultGameStuff();

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

				daNote.caculatePos = calculateNoteY(daNote, daNote.downscrollNote);
				daNote.setNoteAxis(strumPos, strumAngle);

				final properCutOff:Float = cutOff(daNote, daNote.downscrollNote) + strumPos;
				final centerNote:Float = strumPos + Note.swagWidth * 0.5;

				// fixed it kinda
				if (daNote.isSustainNote && (daNote.mustPress || !daNote.ignore)
				&& (!daNote.mustPress || (daNote.wasGoodHit || (daNote.prevNote.wasGoodHit && !daNote.canBeHit)))) {
					if(longConditionForNote(daNote, centerNote)) {
						if(daNote.downscrollNote) {
							var swagRect = new FlxRect(0, 0, daNote.frameWidth, daNote.frameHeight);
							swagRect.height = (centerNote - properCutOff) / daNote.scale.y;
							swagRect.y = daNote.frameHeight - swagRect.height;

							daNote.clipRect = swagRect;
						}else {
							var swagRect = new FlxRect(0, 0, daNote.width / daNote.scale.x, daNote.height / daNote.scale.y);
							swagRect.y = (centerNote - properCutOff) / daNote.scale.y;
							swagRect.height -= swagRect.y;

							daNote.clipRect = swagRect;
						}
					}
				}

				if (!daNote.mustPress && !daNote.shouldBeDead && daNote.wasGoodHit && !daNote.ignore) {
					opponentNoteHit(daNote);
				}

				if (daNote.mustPress) {
					final strumIndex = Math.floor(Math.abs(daNote.noteData));
					final currentStrum = currentStrums.members[strumIndex];
					final sustainDirectionAngle = currentStrum.directionAngle;
					final sustainNoteAngle = currentStrum.directionAngle * -FeshMath.sec(daNote.yAngle);

					daNote.setVisibility(currentStrum.onlyVisible);

					daNote.setXaxis(
						currentStrums.members,
						currentStrum.x,
						addToNoteX(currentStrum.x, daNote),
						currentStrum.directionAngle
					);

					daNote.setNoteAngle(currentStrum.angle, sustainNoteAngle);
					daNote.setNoteAlpha(currentStrum.onlyFans, fadeInValue);

					//Nothing planned for now.
					daNote.xAngle = currentStrum.xAngle;
					daNote.yAngle = currentStrum.yAngle;

					if (daNote.isSustainNote) {
						daNote.setXaxisSustain(currentStrums.members, currentStrum.x, currentStrum.x + (Note.swagWidth / 3), sustainDirectionAngle);
					}
				}
				else {
					final strumIndex = Math.floor(Math.abs(daNote.noteData));
					final oppositeStrum = oppositeStrums.members[strumIndex];
					final sustainDirectionAngle = oppositeStrum.directionAngle;
					final sustainNoteAngle = oppositeStrum.directionAngle * -FeshMath.sec(daNote.yAngle);

					daNote.setVisibility(oppositeStrum.onlyVisible);

					daNote.setXaxis(
						oppositeStrums.members,
						oppositeStrum.x,
						addToNoteX(oppositeStrum.x, daNote),
						oppositeStrum.directionAngle
					);

					daNote.setNoteAngle(oppositeStrum.angle, sustainNoteAngle);
					daNote.setNoteAlpha(oppositeStrum.onlyFans, fadeInValue);

					//Nothing planned for now.
					daNote.xAngle = oppositeStrum.xAngle;
					daNote.yAngle = oppositeStrum.yAngle;

					if (daNote.isSustainNote) {
						daNote.setXaxisSustain(oppositeStrums.members, oppositeStrum.x, oppositeStrum.x + (Note.swagWidth / 3), sustainDirectionAngle);
					}
				}

				if(daNote.isSustainNote) {
					if(!daNote.cameras.contains(camNOTE.camNoteSustain)) {
						daNote.cameras = [camNOTE.camNoteSustain];
					}
				}else if(daNote.cameras.contains(camNOTE.camNoteSustain) && daNote.noteAbstract != "side note") {
					daNote.cameras = [camNOTE];
				}

				var detector:Bool = Conductor.trackPosition > DefaultHandler.getNoteTime(daNote.strumTime) + 260;

				if (detector) {
					if (daNote.isSustainNote && daNote.wasGoodHit) {
						removeNote(daNote);
						}else if(daNote.mustPress && !modifierCheckList('bot mode')) {
							if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {

								if((daNote.tooLate || !daNote.wasGoodHit) && daNote.noteAbstract == "side note") {
									setHealth(health - 2);
								}else{
									setHealth(health - daNote.missDamage());
								}
							}

							if(daNote.tooLate || !daNote.wasGoodHit) {
								if(!CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
									breakComboOnMiss();

									if(daNote.isSustainNote)
										missesHold += 1;
									else
										misses += 1;

									// Match upstream hold-note behavior: dropping sustains should not spam miss anims/sounds.
									applyPlayerMissFeedback(
										Std.int(Math.abs(daNote.noteData)),
										daNote.tag,
										!daNote.isSustainNote,
										daNote.playAnyAnimation && !daNote.isSustainNote
									);
									playLua.call("noteMiss", [daNote.noteData, daNote.tag]);
								}
							}
						}

					daNote.active = false;
					daNote.visible = false;

					removeNote(daNote);
				}
			});

			if(playLua.hasScript()) {
				updateLuaVars();
			}
		}
	}

	function opponentNoteHit(note:Note):Void {
		if (SONG.song != 'Tutorial')
			camZooming = true;

		var altAnim:String = opponentAltAnim;

		if (SONG.notes[Math.floor(curStep / 16)] != null)
		{
			if (SONG.notes[Math.floor(curStep / 16)].altAnim)
				altAnim = '-alt';
		}

		if(note.playAnyAnimation) {
			if(!note.isSustainNote || (note.isSustainNote && currentOpponent.dancing)) {
				currentOpponent.playNoDanceAnim(singAnims[Std.int(Math.abs(note.noteData))] + altAnim);
			}

			currentOpponent.holdTimer = 0;
		}

		events.whenNoteIsPressed(note, this);
		stage.whenNoteIsPressed(note);
		cameraMovement(note.noteData, note.isSustainNote);

		if(modifierCheckList('sing drain') && health > 0.2) {
			setHealth(health - (0.04 * singDrainValue));
		}

		oppositeStrums.forEach(function(spr:Strum) {
			if(Math.abs(note.noteData) == spr.ID) {
				note.hit();
				if(note.isSustainNote) {
					refreshHoldCoverForLane(spr.ID, false);
				}
				playStrumConfirm(spr);
			}
		});

		if (SONG.needsVoices)
			setOpponentVocalsVolume(1, note.tag);

		playLua.call("opponentNoteHit", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);

		if(!note.isSustainNote) {
			removeNote(note);
		}else {
			note.shouldBeDead = true;
		}
	}

    function haveGamePaused():Void {
			paused = (!paused ? true : false);

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

	function pauseMenu():Void {
		persistentUpdate = false;
		persistentDraw = true;
		paused = true;

		pauseMusic();

        // 1 / 1000 chance for Gitaroo Man easter egg
        if (FlxG.random.bool(0.1)) {
            // gitaroo man easter egg
            FlxG.switchState(new GitarooPause());
        } else {
            final screenPos = currentPlayer.getScreenPosition();
            openSubState(new PauseSubState(screenPos.x, screenPos.y));
        }

		#if windows
		DiscordClient.changePresence(detailsPausedText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC);
		#end
	}

	function controllerInput():Void {
		if(modifierCheckList('bot mode')) {
			return;
		}

		var controlPressArray = getGamepadPressArray();
		var controlReleaseArray = getGamepadReleaseArray();
		var index:Int = 0;

		while(index < getLaneCount()) {
			if (controlPressArray[index]) {
				queueLaneInput(index, true, getCurrentInputSongTime());
				playLua.call('onKeyPress', [getPrimaryLaneKeyCode(index)]);
			}

			if (controlReleaseArray[index]) {
				queueLaneInput(index, false, getCurrentInputSongTime());
				playLua.call('onKeyRelease', [getPrimaryLaneKeyCode(index)]);
			}

			index++;
		}
	}

	function getReleased(event:Event):Void {
		if(paused || inCutscene || modifierCheckList('bot mode'))
			return;

		var getEvent:KeyboardEvent = cast event;
		var index:Int = getKeyOrButton(getEvent.keyCode);

		if(index < 0 || index >= getLaneCount()) {
			return;
		}

		var laneHeldKeys:Array<Int> = heldLaneKeys[index];

		if(laneHeldKeys != null) {
			laneHeldKeys.remove(getEvent.keyCode);

			if(laneHeldKeys.length <= 0) {
				queueLaneInput(index, false, getCurrentInputSongTime());
			}
		}

		playLua.call('onKeyRelease', [getEvent.keyCode]);
	}

	function gameOverScreen():Void {
		currentPlayer.stunned = true;

		if(modifierCheckList('blind effect'))
			FlxG.camera.alpha = 1;

		persistentUpdate = false;
		persistentDraw = false;
		paused = true;

		stopVocals();
		FlxG.sound.music.stop();

		FlxG.camera.zoom = defaultCamZoom;

		playLua.set("inGameOver", true);

		openSubState(new GameOverSubstate(currentPlayer.getScreenPosition().x, currentPlayer.getScreenPosition().y));

		#if windows
		// Game Over doesn't get his own variable because it's only used here
		DiscordClient.changePresence("Game Over - " + detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
		#end
	}

	function whenSongFinished():Void {
		canPause = false;
		FlxG.sound.music.volume = 0;
		setAllVocalsVolume(0);
		pauseVocals();

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

				if(videoSwitchState == "" || videoSwitchState == null || SaveData.getData(SaveType.SKIP_CUTSCENES)) {
				    FlxG.sound.playMusic(Paths.music('Main Menu'));
				    FlxG.switchState(new StoryMenuState());
				}else {
				    FlxG.sound.music.stop();
				    FlxG.switchState(new VideoState(new StoryMenuState(), videoSwitchState));
				}

				if (SONG.validScore && !modifierCheckList('blue balls')) { //Make sure to not override.
					#if !switch
					Highscore.saveWeekScore(Paths.modJSON.weeks.get("week_" + PlayState.storyWeek).week_name, campaignScore, storyDifficulty);
					#end
				}
			}
			else
			{
				var difficulty:String = CoolUtil.getDifficultyFileSuffix(storyDifficulty);

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

				PlayState.SONG = Song.loadFromJson(PlayState.storyPlaylist[0].toLowerCase() + difficulty, PlayState.storyPlaylist[0]);
				FlxG.sound.music.stop();

				if(videoSwitchState == "" || videoSwitchState == null || SaveData.getData(SaveType.SKIP_CUTSCENES)) {
				    CacheState.loadAndSwitchState(new PlayState());
				}else {
				    CacheState.loadAndSwitchState(new VideoState(new PlayState(), videoSwitchState));
				}
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

	private function popUpScore(strumtime:Float, id:Int, abby:String, ?judgeSongPosition:Float, ?noteTag:String):Void
	{
		var noteDiff:Float = Math.abs(strumtime - (judgeSongPosition == null ? Conductor.trackPosition : judgeSongPosition));
		setPlayerVocalsVolume(1, noteTag);

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

			setHealth(health - 0.05);
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

			setHealth(health - 0.03);
		}
		else if (noteDiff > Conductor.safeZoneOffset * 0.2)
		{
			daRating = 'good';
			score = 200;
			totalRatingAcc -= 0.10 * GhostTapping.consequence;
			setHealth(health - 0.015);
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

		var botMode:Bool = modifierCheckList('bot mode');
		var controlHoldArray = botMode ? getBotControlHoldArray() : getControlHoldArray();

		if(botMode) {
			processBotplayNotes();
		}

		processInputQueue(controlHoldArray);
		refreshHeldStrums(controlHoldArray);
		processHeldNotes(controlHoldArray, getCurrentInputSongTime());
		updateHoldCoverSprites(true, controlHoldArray);
		updateHoldCoverSprites(false);

		if(boyfriend.holdTimer > Conductor.stepCrochet * (0.0011 #if FLX_PITCH / FlxG.sound.music.pitch #end) * boyfriend.singMultiplier && boyfriend.animation.curAnim.name.startsWith('sing') && !boyfriend.animation.curAnim.name.endsWith('miss')) {
			boyfriend.dance();
		}
	}

	function getPressed(event:Event):Void
	{
		if(paused || inCutscene || disableInputs || modifierCheckList('bot mode')) {
			return;
		}

		var getEvent:KeyboardEvent = cast event;
		var index:Int = getKeyOrButton(getEvent.keyCode);

		if(index < 0 || index >= getLaneCount() || !generatedMusic) {
			return;
		}

		var laneHeldKeys:Array<Int> = heldLaneKeys[index];

		if(laneHeldKeys == null) {
			laneHeldKeys = [];
			heldLaneKeys[index] = laneHeldKeys;
		}

		if(laneHeldKeys.contains(getEvent.keyCode)) {
			return;
		}

		laneHeldKeys.push(getEvent.keyCode);
		queueLaneInput(index, true, getCurrentInputSongTime());
		playLua.call('onKeyPress', [getEvent.keyCode]);
	}

	function getLaneCount():Int {
		return SONG.fifthKey ? 5 : 4;
	}

	function getLaneControls():Array<Control> {
		if(SONG.fifthKey) {
			return [
				Control.GAME_LEFT,
				Control.GAME_DOWN,
				Control.GAME_SPACE,
				Control.GAME_UP,
				Control.GAME_RIGHT
			];
		}

		return [
			Control.GAME_LEFT,
			Control.GAME_DOWN,
			Control.GAME_UP,
			Control.GAME_RIGHT
		];
	}

	function getLaneGamepadBinds():Array<FlxGamepadInputID> {
		var savedBinds:Array<Dynamic> = cast SaveData.getData(CUSTOM_GAMEPAD_BINDS);
		var defaultBinds:Array<FlxGamepadInputID> = [
			FlxGamepadInputID.LEFT_TRIGGER,
			FlxGamepadInputID.LEFT_SHOULDER,
			FlxGamepadInputID.RIGHT_SHOULDER,
			FlxGamepadInputID.RIGHT_TRIGGER,
			FlxGamepadInputID.X
		];

		inline function resolveBind(index:Int):FlxGamepadInputID {
			if(savedBinds != null && index < savedBinds.length && savedBinds[index] != null) {
				return cast savedBinds[index];
			}

			return defaultBinds[index];
		}

		if(SONG.fifthKey) {
			return [resolveBind(0), resolveBind(1), resolveBind(4), resolveBind(2), resolveBind(3)];
		}

		return [resolveBind(0), resolveBind(1), resolveBind(2), resolveBind(3)];
	}

	function getControlHoldArray():Array<Bool> {
		if(SONG.fifthKey) {
			return [
				controls.GAME_LEFT,
				controls.GAME_DOWN,
				controls.GAME_SPACE,
				controls.GAME_UP,
				controls.GAME_RIGHT
			];
		}

		return [
			controls.GAME_LEFT,
			controls.GAME_DOWN,
			controls.GAME_UP,
			controls.GAME_RIGHT
		];
	}

	function getBotControlHoldArray():Array<Bool> {
		var values:Array<Bool> = [];
		var index:Int = 0;
		var songTime:Float = getCurrentInputSongTime();

		while(index < getLaneCount()) {
			values.push(false);
			index++;
		}

		notes.forEachAlive(function(daNote:Note) {
			if(daNote.mustPress
				&& daNote.isSustainNote
				&& !daNote.wasGoodHit
				&& daNote.noteData >= 0
				&& daNote.noteData < values.length
				&& daNote.canHoldHit(songTime)
				&& songTime >= daNote.getNoteTime()) {
				values[daNote.noteData] = true;
			}
		});

		return values;
	}

	function getGamepadPressArray():Array<Bool> {
		var gamepadBinds = getLaneGamepadBinds();
		var values:Array<Bool> = [];
		var index:Int = 0;

		while(index < getLaneCount()) {
			var bind = gamepadBinds[index];
			values.push(FlxG.gamepads.anyJustPressed(bind));
			index++;
		}

		return values;
	}

	function getGamepadReleaseArray():Array<Bool> {
		var gamepadBinds = getLaneGamepadBinds();
		var values:Array<Bool> = [];
		var index:Int = 0;

		while(index < getLaneCount()) {
			var bind = gamepadBinds[index];
			values.push(FlxG.gamepads.anyJustReleased(bind));
			index++;
		}

		return values;
	}

	function getPrimaryLaneKeyCode(lane:Int):Int {
		if(lane < 0 || lane >= keys2DArray.length || keys2DArray[lane] == null || keys2DArray[lane].length == 0) {
			return FlxKey.NONE;
		}

		return keys2DArray[lane][0];
	}

	function getCurrentInputSongTime():Float {
		if(FlxG.sound.music != null) {
			return FlxG.sound.music.time;
		}

		return Conductor.trackPosition;
	}

	function processBotplayNotes():Void {
		if(!generatedMusic || disableInputs) {
			return;
		}

		var songTime:Float = getCurrentInputSongTime();
		var lane:Int = 0;

		while(lane < getLaneCount()) {
			var targetNote:Note = findTapNote(lane, songTime);

			while(targetNote != null && targetNote.shouldAutoHit(songTime)) {
				playStrumPress(lane);
				goodNoteHit(targetNote, targetNote.getNoteTime());
				targetNote = findTapNote(lane, songTime);
			}

			lane++;
		}
	}

	function queueLaneInput(lane:Int, pressed:Bool, songTime:Float):Void {
		if(lane < 0 || lane >= getLaneCount()) {
			return;
		}

		inputQueue.push({lane: lane, pressed: pressed, songTime: songTime});

		if(pressed) {
			playStrumPress(lane);
		}else {
			var spr:Strum = currentStrums.members[lane];

			if(spr != null) {
				spr.keyHeld = false;
			}
		}
	}

	function processInputQueue(controlHoldArray:Array<Bool>):Void {
		if(inputQueue.length == 0) {
			return;
		}

		if(FlxG.sound.music != null) {
			setSongPosition(FlxG.sound.music.time);
		}

		while(inputQueue.length > 0) {
			var input = inputQueue.shift();

			if(input == null) {
				continue;
			}

			if(input.pressed) {
				handleLanePress(input.lane, input.songTime);
			}else {
				handleLaneRelease(input.lane, controlHoldArray);
			}
		}
	}

	function getActiveSustainHoldArray(controlHoldArray:Array<Bool>):Array<Bool> {
		var values:Array<Bool> = [];
		var index:Int = 0;
		var songTime:Float = getCurrentInputSongTime();

		while(index < getLaneCount()) {
			values.push(false);
			index++;
		}

		notes.forEachAlive(function(daNote:Note) {
			var lane:Int = daNote.noteData;
			var chainActive:Bool = false;

			if(daNote.mustPress
				&& daNote.isSustainNote
				&& lane >= 0
				&& lane < values.length
				&& controlHoldArray[lane]) {
				if(daNote.wasGoodHit || daNote.shouldBeDead) {
					chainActive = true;
				}else if(daNote.canHoldHit(songTime)) {
					chainActive = true;
				}else if(songTime < daNote.getNoteTime()
					&& daNote.prevNote != null
					&& (daNote.prevNote.wasGoodHit || daNote.prevNote.shouldBeDead)) {
					chainActive = true;
				}
			}

			if(chainActive) {
				values[lane] = true;
			}
		});

		return values;
	}

	function refreshHeldStrums(controlHoldArray:Array<Bool>):Void {
		var sustainHoldArray:Array<Bool> = getActiveSustainHoldArray(controlHoldArray);

		currentStrums.forEachAlive(function(spr:Strum) {
			if(!controlHoldArray[spr.ID]) {
				spr.keyHeld = false;
				spr.sustainHeld = false;

				if(spr.animation.curAnim != null
					&& (spr.animation.curAnim.name == "pressed" || spr.animation.curAnim.name == "confirm-hold")) {
					spr.playAnim('static');
					spr.holdTimer = 0;
				}
				}else {
					spr.keyHeld = true;
					spr.sustainHeld = sustainHoldArray[spr.ID];

					if(spr.animation.curAnim != null) {
						if(spr.sustainHeld) {
							if((spr.animation.curAnim.name == "static" || spr.animation.curAnim.name == "pressed")
								&& !CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)
								&& spr.hasDedicatedConfirmHold()) {
								spr.playAnim("confirm-hold");
							}else if(spr.animation.curAnim.name == "confirm"
								&& spr.animation.curAnim.finished
								&& spr.hasDedicatedConfirmHold()) {
								if(spr.hasDedicatedConfirmHold()) {
									spr.playAnim("confirm-hold");
								}
							}
						}else {
							if(spr.animation.curAnim.name == "static"
								&& !CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)) {
								spr.playAnim("pressed");
							}else if(spr.animation.curAnim.name == "confirm-hold"
								|| (spr.animation.curAnim.name == "confirm" && spr.holdTimer <= 0 && spr.animation.curAnim.finished)) {
								spr.playAnim("pressed");
							}
						}
					}
				}
			});
		}

	function shouldCatchHeldSustainNote(daNote:Note, currentSongTime:Float):Bool {
		if(previousHeldInputSongTime == null || currentSongTime <= previousHeldInputSongTime) {
			return false;
		}

		if(daNote.prevNote != null && !daNote.prevNote.wasGoodHit && !daNote.prevNote.shouldBeDead) {
			return false;
		}

		var noteTime:Float = daNote.getNoteTime();

		return noteTime > previousHeldInputSongTime && noteTime <= currentSongTime;
	}

	function processHeldNotes(controlHoldArray:Array<Bool>, songTime:Float):Void {
		notes.forEachAlive(function(daNote:Note) {
			if (daNote.mustPress && daNote.isSustainNote && !daNote.wasGoodHit
				&& controlHoldArray[daNote.noteData] && !disableInputs
				&& (daNote.canHoldHit(songTime) || shouldCatchHeldSustainNote(daNote, songTime))) {
				goodNoteHit(daNote, daNote.getNoteTime());
			}
		});

		previousHeldInputSongTime = songTime;
	}

	function handleLanePress(lane:Int, hitSongTime:Float):Void {
		if(!generatedMusic || disableInputs) {
			return;
		}

		var targetNote = findTapNote(lane, hitSongTime);

		if(targetNote != null) {
			goodNoteHit(targetNote, hitSongTime);
			return;
		}

			if(!GhostTapping.ghostTap) {
				breakComboOnMiss();
				takeDamage(lane, true);
				songScore -= 10;
				setHealth(health - 0.08);
				missClicks++;
			}
	}

	function handleLaneRelease(lane:Int, controlHoldArray:Array<Bool>):Void {
		var spr:Strum = currentStrums.members[lane];

		if(spr == null) {
			return;
		}

		spr.keyHeld = false;
		spr.sustainHeld = false;
		spr.holdTimer = 0;
		spr.playAnim('static');
		endHoldCoverForLane(lane, true);
	}

	function findTapNote(lane:Int, hitSongTime:Float):Note {
		var inputNotes = notes.members.filter(function(note:Note):Bool {
			return note != null
				&& note.mustPress
				&& note.noteData == lane
				&& !note.wasGoodHit
				&& !note.isSustainNote
				&& note.canPlayerHit(hitSongTime);
		});

		inputNotes.sort(function(a:Note, b:Note):Int {
			var timeDiff = a.getNoteTime() - b.getNoteTime();

			if(timeDiff < 0) return -1;
			if(timeDiff > 0) return 1;

			return 0;
		});

		if(inputNotes.length == 0) {
			return null;
		}

		var targetNote = inputNotes[0];
		var index:Int = 1;

		while(index < inputNotes.length) {
			var stackedNote = inputNotes[index];

			if(!targetNote.getNoteHittable(stackedNote)) {
				break;
			}

			removeNote(stackedNote);
			index++;
		}

		return targetNote;
	}

	function playStrumPress(lane:Int):Void {
		var spr:Strum = currentStrums.members[lane];

		if(spr == null || CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)) {
			return;
		}

		spr.keyHeld = true;

		if(spr.animation.curAnim == null || !spr.isConfirmAnimation()) {
			spr.playAnim('pressed');
			spr.holdTimer = 0;
		}
	}

	function getKeyOrButton(keyCode:Int):Int {
		var index:Int = 0;

		if (keyCode != FlxKey.NONE) {
			while(index < keys2DArray.length) {
				if(keys2DArray[index].contains(keyCode)) {
					return index;
				}

				index++;
			}
		}

		return -1;
	}

	/*
	function noteMiss(direction:Int = 1, ?note:Note, ?evenTho:Bool = false):Void
	{
		if(note != null) {
			if(CustomNoteHandler.dontHitNotes.contains(note.noteAbstract) && !evenTho) {
				return;
			}
		}

		if (!currentPlayer.stunned) {

			if(!avoidHealthIssues) {
				setHealth(health - 0.04);
			}

			if(gf != null) {
				if (combo > 5 && gf.animOffsets.exists('sad'))
				{
					gf.playNoDanceAnim('sad');
				}
			}

			combo = 0;

			if(note == null) {
				if(SaveData.getData(MISS_SOUND_VOLUME) > 0) {
					FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), SaveData.getData(MISS_SOUND_VOLUME) * FlxG.random.float(0.1, 0.2));
				}

				songScore -= 10;
			}else {
				if(CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)) {
					songScore -= 30;
				}else {
					playLua.call("noteMiss", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);
					songScore -= 10;
				}
			}

			takeDamage(direction, note.playAnyAnimation);
		}
	}
	*/

		function takeDamage(direction:Int, playAnim:Bool):Void {
				applyPlayerMissFeedback(direction, null, true, playAnim);
		}

	function goodNoteHit(note:Note, ?hitSongTime:Float):Void
	{
		if (!note.wasGoodHit)
		{
			if (!note.isSustainNote && !CustomNoteHandler.dontHitNotes.contains(note.noteAbstract))
			{
				popUpScore(note.getNoteTime(), note.noteData, note.noteAbstract, hitSongTime, note.tag);
				combo += 1;
			}

			setHealth(health + note.giveHealth());

			note.pressedByPlayer(currentPlayer, currentOpponent, gf);
			currentPlayer.customAnimation = true;

				var currentAnim = currentPlayer.animation != null ? currentPlayer.animation.curAnim : null;

				if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract) &&
				(currentPlayer.customAnimation && ((currentAnim != null && currentAnim.name.startsWith("sing")) || currentPlayer.dancing))) {
				var animPlay:String = singAnims[Std.int(Math.abs(note.noteData))] + playerAltAnim + currentPlayer.hasBePlayer;

				events.whenNoteIsPressed(note, this);
				stage.whenNoteIsPressed(note);
				cameraMovement(note.noteData, note.isSustainNote);

				currentPlayer.customAnimation = false;

				if(note.playAnyAnimation) {
					if((!note.isSustainNote || currentPlayer.isAnimationFinished()) || (note.isSustainNote && currentPlayer.dancing)) {
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

			note.hit();

			if(spr != null && spr.sustainHeld && note.isSustainNote) {
				refreshHoldCoverForLane(note.noteData, true);
			}

			if(!isPixel) {
				note.splash(grpSplash.members[spr.ID], spr, daRating);
			}

			if(note.hasCustomAddon != null) {
				var noteSprite:FlxSprite = note.hasCustomAddon.createSpriteWhenHit();

				if(noteSprite != null) {
					if(Std.isOfType(noteSprite, CheeseSliceSprite) && camNOTE != null && camNOTE.camNoteSustain != null) {
						noteSprite.cameras = [camNOTE.camNoteSustain];
					}

					customNoteSprites.add(noteSprite);
				}
			    if(note.hasCustomAddon.whenNoteIsHit(spr)) {
					if(note.isSustainNote && spr.sustainHeld) {
						if(spr.hasDedicatedConfirmHold()) {
							playStrumConfirmHold(spr);
						}else {
							playStrumConfirm(spr);
						}
					}else {
						playStrumConfirm(spr);
					}
			    }
			}else {
				if(note.isSustainNote && spr.sustainHeld) {
					if(spr.hasDedicatedConfirmHold()) {
						playStrumConfirmHold(spr);
					}else {
						playStrumConfirm(spr);
					}
				}else {
					playStrumConfirm(spr);
				}
			}

			if(!CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)) {
				note.wasGoodHit = true;

				if(SONG.needsVoices && !currentPlayer.stunned) {
					setPlayerVocalsVolume(1, note.tag);
				}

				hits++;
			}

			playLua.call("goodNoteHit", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);

			if (!note.isSustainNote) {
				removeNote(note);
			}else {
				note.shouldBeDead = true;
			}
		}
	}

	private function playStrumConfirm(strumNote:Strum):Void {
		strumNote.playAnim("confirm", true);
		strumNote.holdTimer = Conductor.stepCrochet * 1.25 / 1000;
	}

	private function playStrumConfirmHold(strumNote:Strum):Void {
		if(strumNote.hasDedicatedConfirmHold()) {
			if(strumNote.getAnimName() == "confirm-hold") {
				return;
			}

			if(strumNote.getAnimName() == "confirm") {
				if(strumNote.animation.curAnim != null && strumNote.animation.curAnim.finished) {
					strumNote.playAnim("confirm-hold", true);
				}
			}else {
				strumNote.playAnim("confirm", true);
				strumNote.holdTimer = 0;
			}
		}else {
			playStrumConfirm(strumNote);
		}
	}

	function setupHoldCoverSprites():Void {
		if(grpHoldCover == null) {
			return;
		}

		for(cover in currentHoldCoverSprites) {
			if(cover != null) {
				grpHoldCover.remove(cover, true);
				cover.destroy();
			}
		}

		for(cover in oppositeHoldCoverSprites) {
			if(cover != null) {
				grpHoldCover.remove(cover, true);
				cover.destroy();
			}
		}

		currentHoldCoverSprites = [];
		currentHoldCoverTimers = [];
		oppositeHoldCoverSprites = [];
		oppositeHoldCoverTimers = [];

		setupHoldCoverSpriteList(currentStrums, currentHoldCoverSprites, currentHoldCoverTimers, true);
		setupHoldCoverSpriteList(oppositeStrums, oppositeHoldCoverSprites, oppositeHoldCoverTimers, false);
	}

	function setupHoldCoverSpriteList(strums:FlxTypedSpriteGroup<Strum>, sprites:Array<HoldCoverSprite>, timers:Array<Float>, currentSide:Bool):Void {
		for(index in 0...getLaneCount()) {
			var strum:Strum = strums.members[index];
			var cover:HoldCoverSprite = null;

			if(strum != null) {
				cover = new HoldCoverSprite(strum.direction);
			}

			sprites.push(cover);
			timers.push(0);

			if(cover != null) {
				cover.cameras = [camNOTE.camNoteSustain];
				grpHoldCover.add(cover);
				updateHoldCoverPosition(index, currentSide);
			}
		}
	}

	function refreshHoldCoverForLane(lane:Int, currentSide:Bool):Void {
		var holdCoverSprites = currentSide ? currentHoldCoverSprites : oppositeHoldCoverSprites;
		var holdCoverTimers = currentSide ? currentHoldCoverTimers : oppositeHoldCoverTimers;

		if(lane < 0 || lane >= holdCoverSprites.length) {
			return;
		}

		var cover:HoldCoverSprite = holdCoverSprites[lane];

		if(cover == null) {
			return;
		}

		holdCoverTimers[lane] = (Conductor.stepCrochet * 1.1) / 1000;

		if(cover.activeHold && !cover.ending) {
			cover.refreshHold();
		}else {
			cover.beginHold();
		}

		updateHoldCoverPosition(lane, currentSide);
	}

	function endHoldCoverForLane(lane:Int, currentSide:Bool):Void {
		var holdCoverSprites = currentSide ? currentHoldCoverSprites : oppositeHoldCoverSprites;
		var holdCoverTimers = currentSide ? currentHoldCoverTimers : oppositeHoldCoverTimers;

		if(lane < 0 || lane >= holdCoverSprites.length) {
			return;
		}

		holdCoverTimers[lane] = 0;

		var cover:HoldCoverSprite = holdCoverSprites[lane];

		if(cover != null) {
			cover.endHold();
		}
	}

	function updateHoldCoverSprites(currentSide:Bool, ?controlHoldArray:Array<Bool>):Void {
		var holdCoverSprites = currentSide ? currentHoldCoverSprites : oppositeHoldCoverSprites;
		var holdCoverTimers = currentSide ? currentHoldCoverTimers : oppositeHoldCoverTimers;
		var lane:Int = 0;

		while(lane < holdCoverSprites.length) {
			if(holdCoverTimers[lane] > 0) {
				holdCoverTimers[lane] -= FlxG.elapsed;
			}

			updateHoldCoverPosition(lane, currentSide);

			if(currentSide) {
				if(controlHoldArray == null || lane >= controlHoldArray.length || !controlHoldArray[lane] || holdCoverTimers[lane] <= 0) {
					endHoldCoverForLane(lane, true);
				}
			}else if(holdCoverTimers[lane] <= 0) {
				endHoldCoverForLane(lane, false);
			}

			lane++;
		}
	}

	function updateHoldCoverPosition(lane:Int, currentSide:Bool):Void {
		var holdCoverSprites = currentSide ? currentHoldCoverSprites : oppositeHoldCoverSprites;
		var strums = currentSide ? currentStrums : oppositeStrums;

		if(lane < 0 || lane >= holdCoverSprites.length) {
			return;
		}

		var cover:HoldCoverSprite = holdCoverSprites[lane];
		var strum:Strum = strums.members[lane];

		if(cover == null || strum == null) {
			return;
		}

		cover.visible = (cover.activeHold || cover.ending) && strum.visible;

		if(!cover.visible) {
			return;
		}

		cover.alpha = strum.alpha;
		cover.angle = strum.angle;
		cover.x = strum.x + (strum.width * 0.5) - (cover.width * 0.5) - 8;
		cover.y = strum.y - 96;
	}

	private function cameraMovement(noteCData:Int, isSus:Bool):Void {
		if(Main.feeshmoraModifiers && !isSus) {
			if(noteCData == 0) {
				camMovementPos.x = (-SONG.bpm / 45) * CAMERA_MOVEMENT_OFFSET_SCALE * cameraMovementInsensity;
				camMovementPos.y = 0;
			}

			if(noteCData == (strumLineNotes.members.length / 2) - 1) {
				camMovementPos.x = (SONG.bpm / 45) * CAMERA_MOVEMENT_OFFSET_SCALE * cameraMovementInsensity;
				camMovementPos.y = 0;
			}

			if(noteCData == 1) {
				camMovementPos.y = (SONG.bpm / 45) * CAMERA_MOVEMENT_OFFSET_SCALE * cameraMovementInsensity;
				camMovementPos.x = 0;
			}

			if(noteCData == (strumLineNotes.members.length / 2) - 2) {
				camMovementPos.y = (-SONG.bpm / 45) * CAMERA_MOVEMENT_OFFSET_SCALE * cameraMovementInsensity;
				camMovementPos.x = 0;
			}
		}
	}

	public function setScriptedCameraFocus(x:Float, y:Float, snap:Bool = true):Void {
		vSliceCameraFocusEnabled = true;
		vSliceCameraFocusX = x;
		vSliceCameraFocusY = y;

		if(snap) {
			camFollow.setPosition(x + camMovementPos.x, y + camMovementPos.y);
			FlxG.camera.focusOn(camFollow.getPosition());
		}
	}

	public function clearScriptedCameraFocus(snap:Bool = true):Void {
		vSliceCameraFocusEnabled = false;
		vSliceCameraFocusLerp = 0;

		if(snap) {
			camFollow.setPosition(camPos.x + camMovementPos.x, camPos.y + camMovementPos.y);
			FlxG.camera.focusOn(camFollow.getPosition());
		}
	}

	public function setScriptedCameraFocusLerp(lerp:Float):Void {
		vSliceCameraFocusLerp = FlxMath.bound(lerp, 0, 1);
	}

	public function resetScriptedCameraState(snap:Bool = true):Void {
		vSliceCameraFocusEnabled = false;
		vSliceCameraFocusLerp = 0;
		vSliceDirectZoomEnabled = false;

		if(camMovementPos != null) {
			camMovementPos.set(0, 0);
		}

		if(snap && camFollow != null) {
			camFollow.setPosition(camPos.x, camPos.y);
			FlxG.camera.focusOn(camFollow.getPosition());
			FlxG.camera.zoom = defaultCamZoom;
		}
	}

	public function setScriptedCameraZoom(zoom:Float, direct:Bool = true, snap:Bool = true):Void {
		if(direct) {
			vSliceDirectZoomEnabled = true;
			vSliceDirectZoomValue = zoom;
		}else {
			vSliceDirectZoomEnabled = false;
			defaultCamZoom = zoom;
		}

		if(snap) {
			FlxG.camera.zoom = zoom;
		}
	}

	public function clearScriptedCameraZoom(snap:Bool = true):Void {
		vSliceDirectZoomEnabled = false;

		if(snap) {
			FlxG.camera.zoom = defaultCamZoom;
		}
	}

	public function focusGameplayCameraOnSprite(name:String, zoom:Float = 1, anchorX:Float = 0.5, anchorY:Float = 0.5,
		offsetX:Float = 0, offsetY:Float = 0, direct:Bool = true, snap:Bool = true):Bool {
		var spr:FlxSprite = playLua != null ? playLua.getSprite(name) : null;

		if(spr == null) {
			return false;
		}

		var focusX:Float = spr.x + (spr.width * anchorX) + offsetX;
		var focusY:Float = spr.y + (spr.height * anchorY) + offsetY;
		setScriptedCameraFocus(focusX, focusY, snap);
		setScriptedCameraZoom(zoom, direct, snap);
		return true;
	}

	private function getStepFromTime(songTime:Float):Int
	{
		var lastChange:BPMChangeEvent = {
			stepTime: 0,
			songTime: 0,
			bpm: 0
		};

		for (i in 0...Conductor.bpmChangeMap.length)
		{
			if (songTime >= Conductor.bpmChangeMap[i].songTime)
				lastChange = Conductor.bpmChangeMap[i];
		}

		var lastBpm:Int = lastChange.bpm > 0 ? lastChange.bpm : Conductor.bpm;
		var stepCrochet:Float = ((60 / lastBpm) * 1000) / 4;
		return lastChange.stepTime + Math.floor((songTime - lastChange.songTime) / stepCrochet);
	}

	function removeNote(note:Note) {
		note.active = false;

		note.kill();

		if(note.trail != null)
			remove(note.trail);

		notes.remove(note, true);
		note.destroy();
	}

	function addLuaToAngle(daAngle:Float, note:Note):Float {
		return playLua != null ? playLua.addToNoteAngle(daAngle, note) : daAngle;
	}

	/**
	* Reason why the variables are named the same as Psych Engine is so transferring lua scripts can be easier.
	*/
	function getLuaScript():Void {
		if(playLua != null)
			playLua.loadScript();
	}

	function generateStaticLua():Void {
		if(playLua != null)
			playLua.generateStaticBindings();
	}

	function makeNoteLua():Void {
		if(playLua != null)
			playLua.generateNoteBindings();
	}

	function updateLuaVars():Void {
		if(playLua != null)
			playLua.updateDynamicVars();
	}

	function updatePerSectionLuaVars():Void {
		if(playLua != null)
			playLua.updatePerSectionVars();
	}

	function eventLoad():Void {
		if(eventInfo.length == 0)
			return;

		var liveSongTime:Float = Conductor.songPosition;
		var liveStep:Int = getStepFromTime(liveSongTime);
		var liveGridY:Int = liveStep * 40;

		while(eventInfo.length > 0) {
			var nextEvent:EventInfo = eventInfo[0];
			var eventTime:Null<Float> = Reflect.field(nextEvent, "modTime");

			if(eventTime != null) {
				if(liveSongTime < eventTime)
					return;
			} else {
				var gridY:Int = Reflect.field(nextEvent, "modGridY");

				if(liveGridY < gridY)
					return;
			}

			eventLoad_DefaultHandler();
		}
	}

	function eventLoad_DefaultHandler():Void {
		var value:String = Reflect.field(eventInfo[0], "modValue");
		var value2:String = Reflect.field(eventInfo[0], "modValueTwo");
		var skill:String = Reflect.field(eventInfo[0], "modSkill");

		eventInfo.shift();

		if(skill == null) {
			skill = "";
		}

		skill = skill.toLowerCase().trim();

		if(!eventStorage.contains(skill))
			eventStorage.push(skill);

		var useRawValues:Bool = VSliceEvent.usesRawValues(skill);

		if(value != null) {
			value = useRawValues ? value.trim() : value.toLowerCase().trim();
		}

		if(value2 != null) {
			value2 = useRawValues ? value2.trim() : value2.toLowerCase().trim();
		}

		events.whenTriggered(skill, value, value2, this);
		event_Extra(skill, value, value2);
	}

	function event_Extra(skill:String, value:String, value2:String):Void {
		stage.onEvent(skill, value, value2);

		playLua.call("whenEventTriggered", [skill, value, value2]);
	}

	function set_wobbleModPower(value:Float):Float {
		wobbleModPower = value;
		return wobbleModPower;
	}

	//Getter Functions
	override function get_songPos():Float {
		return Conductor.trackPosition;
	}

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
		return wobbleModPower;
	}

	override function stepHit()
	{
		super.stepHit();

		if (((FlxG.sound.music.time > Conductor.songPosition + SONG_TRACK_DESYNC_TOLERANCE
			|| FlxG.sound.music.time < Conductor.songPosition - SONG_TRACK_DESYNC_TOLERANCE)
			|| hasSongTrackDesync(FlxG.sound.music.time)) && !paused)
		{
			resyncVocals();
		}

		if(CustomNoteHandler.yourNoteData["side note"] != null) {
			if(FlxFlicker.isFlickering(CustomNoteHandler.yourNoteData["side note"])) {
				FlxG.sound.play(Paths.sound('Warning'), 0.25);
			}
		}

		stage.stepHit();
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

		/*
		if(dad.holdTimer < Conductor.stepCrochet * 0.0011 * boyfriend.singMultiplier) {
			var dadAnim:String = dad.animation.curAnim.name;

			if(dadAnim.startsWith("sing")) {
				dad.playNoDanceAnim(dadAnim, true);
			}
		}

		if(boyfriend.holdTimer < Conductor.stepCrochet * 0.0011 * boyfriend.singMultiplier) {
			//var boyfriendAnim:String = boyfriend.animation.curAnim.name.replace("miss", "");
			var boyfriendAnim:String = boyfriend.animation.curAnim.name;

			if(boyfriendAnim.startsWith("sing")) {
				boyfriend.playNoDanceAnim(boyfriendAnim, true);
			}
		}
		*/

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

		if(bumpPerBeat > 0 && curBeat >= bumpOffset && (curBeat - bumpOffset) % bumpPerBeat == 0) {
			if (camZooming && FlxG.camera.zoom < 1.35) {
				FlxG.camera.zoom += 0.015 * bumpForce;
				camHUD.zoom += 0.03 * bumpForce;
				camNOTE.zoom += 0.03 * bumpForce;
			}

			if(playLua.hasScript()) {
				updatePerSectionLuaVars();
			}
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

		stage.beatHit();
	}

	@:access(flixel.FlxGame)
	function clearCache():Void {
		if(!((cast FlxG.game._requestedState is PlayState) || (cast FlxG.game._requestedState is CacheState))) {
		    #if debug
		    trace("Clearing Cache");
		    #end

			Cache.clear();
		}
	}

	public function prepareForStateSwitch():Void {
		var stateCamNOTE:CameraNote = ownedCamNOTE;
		var stateCamNoteSustain:FeshCamera = ownedCamNoteSustain;
		var stateCamHUD:FeshCamera = ownedCamHUD;

		resetScriptedCameraState(false);

		if(stateCamNOTE != null) {
			if(notes != null) {
				notes.cameras = [stateCamNOTE];

				notes.forEachAlive(function(note:Note) {
					if(note != null) {
						note.cameras = [stateCamNOTE];
					}
				});
			}

			if(grpHoldCover != null) {
				grpHoldCover.cameras = [stateCamNOTE];

				grpHoldCover.forEachAlive(function(cover:HoldCoverSprite) {
					if(cover != null) {
						cover.cameras = [stateCamNOTE];
					}
				});
			}

				stateCamNOTE.setFilters([]);
				stateCamNOTE.clearRenderState();
				stateCamNOTE.visible = false;
				FlxG.cameras.remove(stateCamNOTE, false);

				if(stateCamNoteSustain != null) {
					stateCamNoteSustain.setFilters([]);
					stateCamNoteSustain.clearRenderState();
					stateCamNoteSustain.visible = false;
					FlxG.cameras.remove(stateCamNoteSustain, false);
					stateCamNoteSustain.destroy();
					ownedCamNoteSustain = null;
					stateCamNOTE.camNoteSustain = null;
				}
			}

			if(stateCamHUD != null) {
				stateCamHUD.setFilters([]);
				stateCamHUD.clearRenderState();
				stateCamHUD.visible = false;
				FlxG.cameras.remove(stateCamHUD, false);
			}

		if(playLua != null) {
			playLua.prepareForStateSwitch();
		}
	}

	override public function destroy() {
		var statePlayLua:PlayLua = playLua;
		var stateCamNOTE:CameraNote = ownedCamNOTE;
		var stateCamNoteSustain:FeshCamera = ownedCamNoteSustain;
		var stateCamHUD:FeshCamera = ownedCamHUD;

		FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, getPressed);
		FlxG.stage.removeEventListener(KeyboardEvent.KEY_UP, getReleased);

		prepareForStateSwitch();
		destroyAllSongTracks();

		super.destroy();

		if(stateCamNOTE != null) {
			FlxG.cameras.remove(stateCamNOTE, false);
			stateCamNOTE.destroy();
		}

		if(stateCamHUD != null) {
			FlxG.cameras.remove(stateCamHUD, false);
			stateCamHUD.destroy();
		}

		if(camNOTE == stateCamNOTE) {
			camNOTE = null;
		}

		if(camHUD == stateCamHUD) {
			camHUD = null;
		}

		FlxG.sound.destroy();

		stage = FlxDestroyUtil.destroy(stage);
		events = FlxDestroyUtil.destroy(events);

		keys2DArray = null;
		eventInfo = null;

		if(statePlayLua != null) {
			statePlayLua.destroy();
			playLua = null;
		}

		DefaultHandler.kill();

		if(playScrollSpeed != null) {
			playScrollSpeed.destroy();
			playScrollSpeed = null;
		}

		clearCache();

		if(modifiableCharacters != null) {
            for(k in modifiableCharacters.keys()) {
                var spr:Character = modifiableCharacters.get(k);

                if(spr != null) {
                    spr.destroy();
                }
            }

			precacheList.clear();
			precacheList = null;

            modifiableCharacters.clear();
            modifiableCharacters = null;
        }
	}
}
