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
import lime.utils.Assets;
import lime.system.ThreadPool;

import example_code.DefaultEvents;
import example_code.DefaultStage;
import play.PlayAudio;
import play.PlayCamera;
import play.Countdown;
import play.DefaultHandler;
import play.PlayEvents;
import play.GameOverSubstate;
import play.GitarooPause;
import play.PlayFlow;
import play.PauseSubState;
import play.PlayInput;
import play.PlayLua;
import play.PlayScoreFeedback;
import play.PlayScrollSpeed;
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

typedef StrumResetState =
{
	var x:Float;
	var y:Float;
	var alpha:Float;
	var angle:Float;
	var xAngle:Float;
	var yAngle:Float;
	var directionAngle:Float;
	var scaleX:Float;
	var scaleY:Float;
}

class PlayState extends MusicBeatState
{
	public static var instance:PlayState;
	private static inline var GAMEPLAY_CAMERA_FOLLOW_LERP_60FPS:Float = 0.08;
	private static inline var CONDUCTOR_DRIFT_THRESHOLD:Float = 65;
	private static inline var MUSIC_EASE_RATIO:Float = 42;

	//Cache Stuff
	var precacheList:Map<String, String> = new Map<String, String>();

	//Lua Stuff
	public var modifiableCharacters:Map<String, Character>;

	//More Stuff
	public var stage:StageBuilder;
	public var deathCounter:Int = 0;

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
		public var isInCountdown:Bool = false;
		public var startTimestamp:Float = 0;
		public var needsReset:Bool = false;

		public var healthTween:FlxTween;
		public var prevHealth:Float = 0;

	public var currentStage(get, never):StageBuilder;
	public var cameraFollowPoint(get, never):FlxObject;
	public var isMinimalMode(get, never):Bool;

	inline function getGameplayCameraFollowLerp():Float
	{
		return GAMEPLAY_CAMERA_FOLLOW_LERP_60FPS * 60 / FlxG.updateFramerate;
	}

	function get_currentStage():StageBuilder
	{
		return stage;
	}

	function get_cameraFollowPoint():FlxObject
	{
		return camFollow;
	}

	function get_isMinimalMode():Bool
	{
		return false;
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
	private var restartScriptedCameraCaptured:Bool = false;
	private var restartCameraFocusEnabled:Bool = false;
	private var restartCameraFocusX:Float = 0;
	private var restartCameraFocusY:Float = 0;
	private var restartCameraFocusLerp:Float = 0;
	private var restartDirectZoomEnabled:Bool = false;
	private var restartDirectZoomValue:Float = 1;
	private var restartDefaultCamZoom:Float = 1;

	@:isVar public var wobbleModPower(get, set):Float = 30;

	//Chart Shit
	public static var muteInst:Bool;
	public var eventStorage:Array<String> = [];

	//Camera Shit
	public static var camHUD:PlayCamera;
	public static var camNOTE:CameraNote;
	private var ownedCamHUD:PlayCamera;
	private var ownedCamNOTE:CameraNote;
	private var ownedCamNoteSustain:PlayCamera;
	private var playAudio:PlayAudio;
	private var playEvents:PlayEvents;
	private var playFlow:PlayFlow;
	private var playInput:PlayInput;
	private var playLua:PlayLua;
	private var playScoreFeedback:PlayScoreFeedback;
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
	private var botplayText:BotplayText;

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

	public var camGame:PlayCamera;

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
		playAudio = new PlayAudio(this);
		playEvents = new PlayEvents(this);
		playFlow = new PlayFlow(this);
		playInput = new PlayInput(this);
		playLua = new PlayLua(this);
		playScoreFeedback = new PlayScoreFeedback(this);
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
		instance = this;

		modifiableCharacters = new Map<String, Character>();

		Cache.clearNoneCachedAssets();

		FlxG.mouse.visible = false;
		//testSprite.visible = false;
		eventStorage = [];

		if (FlxG.sound.music != null)
			FlxG.sound.music.stop();

		SaveData.saveClient();

		camGame = new PlayCamera();
		camNOTE = new CameraNote();
		camNOTE.createSustainCam();
		camHUD = new PlayCamera();
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

		Conductor.instance.trackedSongPosition = -5000;

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

		updateBotplayOverlay();

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

					blockSongStartForDialogue();
					doof = new DialogueBox(false, dialogue);
					doof.scrollFactor.set();
					doof.finishThing = startCountdown;
					doof.cameras = [camHUD];

					schoolIntro(doof);
				default:
					blockSongStartForDialogue();
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

		inCutscene = false;
		talking = false;

		startCountdown();
	}

	function blockSongStartForDialogue():Void {
		if(!startingSong) {
			return;
		}

		Countdown.stopCountdown();
		isInCountdown = false;
		stopVocals();

		if(FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}
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
			Conductor.instance.forceBPM(null);
			Conductor.instance.mapTimeChangesFromSong(SONG);
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
	var restartIntroTimer:FlxTimer;
	var restartVwooshNotes:FlxTypedGroup<Note>;
	var perfectMode:Bool = false;
	private static inline var RESTART_NOTE_INTRO_TIME:Float = 0.5;
	private static inline var RESTART_NOTE_INTRO_OFFSET:Float = 200;
	var defaultPlayerStrumState:Array<StrumResetState> = [];
	var defaultOpponentStrumState:Array<StrumResetState> = [];
	var restartVwooshActive:Bool = false;

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
		startTimestamp = 0;
		Countdown.reset();
		defaultPlayerStrumState = [];
		defaultOpponentStrumState = [];

		add(healthBarBG);
		add(healthBar);
		add(counterTxt);
		add(iconP1);
		add(iconP2);

		generateStaticArrows(0);
		generateStaticArrows(1);
		setupHoldCoverSprites();

		beginCountdownSequence(true);
	}

	function beginCountdownSequence(callGeneratedStage:Bool = true):Void {
		talking = false;
		startedCountdown = true;
		isInCountdown = false;
		previousHeldInputSongTime = null;

		makeNoteLua();
		updateLuaVars();
		updatePerSectionLuaVars();

		if(playLua != null) {
			playLua.set("startedCountdown", true);

			if(callGeneratedStage) {
				playLua.call("generatedStage", []);
				captureRestartScriptedCameraState();
			}
		}

		if(!Countdown.performCountdown()) {
			startedCountdown = false;
			isInCountdown = false;

			if(playLua != null) {
				playLua.set("startedCountdown", false);
				playLua.set("isInCountdown", false);
			}
		}
	}

	function rebuildEventInfo():Void {
		if(SONG.modifiers != null) {
			eventInfo = SONG.modifiers.copy();
		}else {
			eventInfo = [];
		}

		eventInfo.sort(function(a:EventInfo, b:EventInfo):Int {
			var aTime:Null<Float> = Reflect.field(a, "modTime");
			var bTime:Null<Float> = Reflect.field(b, "modTime");

			if(aTime != null && bTime != null)
				return aTime < bTime ? -1 : (aTime > bTime ? 1 : 0);

			var aGrid:Int = Reflect.field(a, "modGridY");
			var bGrid:Int = Reflect.field(b, "modGridY");
			return aGrid < bGrid ? -1 : (aGrid > bGrid ? 1 : 0);
		});
	}

	function rebuildEvents():Void {
		if(events != null) {
			events.destroy();
		}

		events = new FeshEventGroup();

		for(i in 0...Register.events.length) {
			events.add(cast Type.createInstance(Register.events[i], []));
		}
	}

	function clearGeneratedSongState():Void {
		Countdown.stopCountdown();
		Countdown.reset();
		restartVwooshActive = false;

		if(restartIntroTimer != null) {
			restartIntroTimer.cancel();
			restartIntroTimer.destroy();
			restartIntroTimer = null;
		}

		if(notes != null) {
			for(note in notes.members) {
				if(note != null && note.trail != null) {
					remove(note.trail);
					note.trail.destroy();
				}
			}

			remove(notes, true);
			notes.destroy();
			notes = null;
		}

		if(unspawnNotes != null) {
			for(note in unspawnNotes) {
				if(note != null && note.trail != null) {
					remove(note.trail);
					note.trail.destroy();
				}

				if(note != null) {
					note.destroy();
				}
			}
		}

		unspawnNotes = [];

		if(customNoteSprites != null) {
			remove(customNoteSprites, true);
			customNoteSprites.destroy();
			customNoteSprites = null;
		}

		if(grpHoldCover != null) {
			remove(grpHoldCover, true);
			grpHoldCover.destroy();
			grpHoldCover = null;
		}

		currentHoldCoverSprites = [];
		currentHoldCoverTimers = [];
		oppositeHoldCoverSprites = [];
		oppositeHoldCoverTimers = [];

		if(grpSplash != null) {
			for(splash in grpSplash.members.copy()) {
				if(splash != null) {
					grpSplash.remove(splash, true);
					splash.destroy();
				}
			}
		}

		generatedMusic = false;
		totalNotesLoaded = 0;
	}

	function resetStrumVisualState():Void {
		if(playerStrums != null) {
			playerStrums.forEachAlive(function(strum:Strum) {
				if(strum != null) {
					strum.playAnim('static');
				}
			});
		}

		if(opponentStrums != null) {
			opponentStrums.forEachAlive(function(strum:Strum) {
				if(strum != null) {
					strum.playAnim('static');
				}
			});
		}
	}

	function storeDefaultStrumState(player:Int, lane:Int, strum:Strum, finalY:Float, finalAlpha:Float):Void {
		var targetState:Array<StrumResetState> = player == 1 ? defaultPlayerStrumState : defaultOpponentStrumState;
		targetState[lane] = {
			x: strum.x,
			y: finalY,
			alpha: finalAlpha,
			angle: strum.angle,
			xAngle: strum.xAngle,
			yAngle: strum.yAngle,
			directionAngle: strum.directionAngle,
			scaleX: strum.scale.x,
			scaleY: strum.scale.y
		};
	}

	function applyStrumResetState(strum:Strum, state:StrumResetState):Void {
		if(strum == null || state == null) {
			return;
		}

		strum.engineWidth = 0;
		strum.engineHeight = 0;
		strum.scale.set(state.scaleX, state.scaleY);
		strum.updateHitbox();
		strum.x = state.x;
		strum.y = state.y;
		strum.alpha = state.alpha;
		strum.angle = state.angle;
		strum.xAngle = state.xAngle;
		strum.yAngle = state.yAngle;
		strum.directionAngle = state.directionAngle;
		strum.onlyFans = 1;
		strum.holdTimer = 0;
		strum.keyHeld = false;
		strum.sustainHeld = false;
		strum.visible = true;
		strum.prevVisible = true;
		strum.onlyVisible = true;
		strum.color = FlxColor.WHITE;
		strum.playAnim('static');
	}

	function resetStrumLayout():Void {
		if(opponentStrums == null || playerStrums == null) {
			return;
		}

		opponentStrums.x = 0;
		opponentStrums.y = 0;
		playerStrums.x = 0;
		playerStrums.y = 0;

		DefaultHandler.strumSize = [];

		for(i in 0...opponentStrums.length) {
			var strum:Strum = opponentStrums.members[i];
			var state:StrumResetState = i < defaultOpponentStrumState.length ? defaultOpponentStrumState[i] : null;
			applyStrumResetState(strum, state);

			if(state != null) {
				DefaultHandler.strumSize.push([state.scaleX, state.scaleY]);
			}
		}

		for(i in 0...playerStrums.length) {
			var strum:Strum = playerStrums.members[i];
			var state:StrumResetState = i < defaultPlayerStrumState.length ? defaultPlayerStrumState[i] : null;
			applyStrumResetState(strum, state);

			if(state != null) {
				DefaultHandler.strumSize.push([state.scaleX, state.scaleY]);
			}
		}
	}

	function resetHealthUi():Void {
		if(boyfriend.curCharacter != "none") {
			iconP1.createAnim(boyfriend.curCharacter, boyfriend._info.icon, true);
		}

		if(dad.curCharacter != "none") {
			iconP2.createAnim(dad.curCharacter, dad._info.icon, false);
		}

		stage.configIcons(iconP1, iconP2);

		playerIconColor = CoolUtil.calculateAverageColor(iconP1.updateFramePixels());
		opponentIconColor = CoolUtil.calculateAverageColor(iconP2.updateFramePixels());
		healthBar.createFilledBar(opponentIconColor, playerIconColor);
		healthBar.updateValueFromParent();

		iconP1.setGraphicSize(150, 150);
		iconP2.setGraphicSize(150, 150);
		iconP1.updateHitbox();
		iconP2.updateHitbox();
		iconP1.y = healthBar.y - (iconP1.height / 2);
		iconP2.y = healthBar.y - (iconP2.height / 2);
	}

	function captureRestartScriptedCameraState():Void {
		restartScriptedCameraCaptured = true;
		restartCameraFocusEnabled = vSliceCameraFocusEnabled;
		restartCameraFocusX = vSliceCameraFocusX;
		restartCameraFocusY = vSliceCameraFocusY;
		restartCameraFocusLerp = vSliceCameraFocusLerp;
		restartDirectZoomEnabled = vSliceDirectZoomEnabled;
		restartDirectZoomValue = vSliceDirectZoomValue;
		restartDefaultCamZoom = defaultCamZoom;
	}

	function restoreRestartScriptedCameraState(snap:Bool = true):Void {
		if(!restartScriptedCameraCaptured) {
			return;
		}

		vSliceCameraFocusEnabled = restartCameraFocusEnabled;
		vSliceCameraFocusX = restartCameraFocusX;
		vSliceCameraFocusY = restartCameraFocusY;
		vSliceCameraFocusLerp = restartCameraFocusLerp;
		vSliceDirectZoomEnabled = restartDirectZoomEnabled;
		vSliceDirectZoomValue = restartDirectZoomValue;
		defaultCamZoom = restartDefaultCamZoom;

		if(snap && camFollow != null) {
			var followX:Float = restartCameraFocusEnabled ? restartCameraFocusX : camPos.x;
			var followY:Float = restartCameraFocusEnabled ? restartCameraFocusY : camPos.y;

			camFollow.setPosition(followX + camMovementPos.x, followY + camMovementPos.y);
			FlxG.camera.focusOn(camFollow.getPosition());
			FlxG.camera.zoom = restartDirectZoomEnabled ? restartDirectZoomValue : defaultCamZoom;
		}
	}

	function refreshGeneratedSongCameras():Void {
		if(notes != null) {
			notes.cameras = [camNOTE];
		}

		if(customNoteSprites != null) {
			customNoteSprites.cameras = [camNOTE];
		}

		if(grpHoldCover != null) {
			grpHoldCover.cameras = [camNOTE.camNoteSustain];
		}

		if(grpSplash != null) {
			grpSplash.cameras = [camNOTE];
		}
	}

	function regenNoteData(?reloadVocals:Bool = true):Void {
		clearGeneratedSongState();
		generateSong(SONG.song, reloadVocals);
		resetStrumVisualState();
		setupHoldCoverSprites();
		refreshGeneratedSongCameras();
	}

	function spawnVisibleNotes():Void {
		if(unspawnNotes == null || notes == null) {
			return;
		}

		while(unspawnNotes.length > 0) {
			var nextNote:Note = unspawnNotes[0];

			if(nextNote == null) {
				unspawnNotes.splice(0, 1);
				continue;
			}

			var spawnTime:Float = 3000 / Math.min(1, nextNote.howSpeed);

			if(nextNote.strumTime - Conductor.instance.trackedSongPosition >= spawnTime) {
				break;
			}

			stage.modifyNotesDirectly(nextNote);
			notes.add(nextNote);

			if(nextNote.hasCustomAddon != null) {
				nextNote.hasCustomAddon.whenIsSpawned(nextNote);
			}

			unspawnNotes.splice(0, 1);
		}
	}

	function clearRestartVwooshNotes():Void {
		if(restartVwooshNotes == null) {
			return;
		}

		for(note in restartVwooshNotes.members.copy()) {
			if(note == null) {
				continue;
			}

			restartVwooshNotes.remove(note, true);
			note.destroy();
		}

		remove(restartVwooshNotes, true);
		restartVwooshNotes.destroy();
		restartVwooshNotes = null;
	}

	function vwooshNotesOut():Void {
		clearRestartVwooshNotes();

		if(notes == null) {
			return;
		}

		restartVwooshNotes = new FlxTypedGroup<Note>();
		restartVwooshNotes.cameras = [camNOTE];
		add(restartVwooshNotes);

		for(note in notes.members.copy()) {
			if(note == null || !note.alive) {
				continue;
			}

			if(note.trail != null) {
				remove(note.trail);
				note.trail.destroy();
				note.trail = null;
			}

			notes.remove(note, true);
			restartVwooshNotes.add(note);
			note.restartVisualOffsetY = 0;

			var targetY:Float = note.y + FlxG.height;
			if(note.downscrollNote) {
				targetY = note.y - FlxG.height;
			}

			FlxTween.tween(note, {y: targetY}, RESTART_NOTE_INTRO_TIME, {
				ease: FlxEase.expoIn,
				onComplete: function(_) {
					if(restartVwooshNotes != null) {
						restartVwooshNotes.remove(note, true);
					}

					note.kill();
					note.destroy();
				}
			});
		}
	}

	function vwooshNotesIn():Void {
		if(notes == null) {
			return;
		}

		notes.forEachAlive(function(note:Note) {
			if(note == null) {
				return;
			}

			note.restartVisualOffsetY = note.downscrollNote ? -RESTART_NOTE_INTRO_OFFSET : RESTART_NOTE_INTRO_OFFSET;
			FlxTween.tween(note, {restartVisualOffsetY: 0}, RESTART_NOTE_INTRO_TIME, {
				ease: FlxEase.expoOut,
				onComplete: function(_) {
					note.restartVisualOffsetY = 0;
				}
			});
		});
	}

	function updateCountdownConductor(elapsed:Float):Void {
		if(inCutscene || talking) {
			return;
		}

		Conductor.instance.update(Conductor.instance.trackedSongPosition + elapsed * 1000, false);

		if(Conductor.instance.trackedSongPosition >= (startTimestamp + Conductor.instance.combinedOffset)) {
			startSong();
		}
	}

	function updateGameplayConductor(elapsed:Float):Void {
		if(paused || FlxG.sound.music == null || !FlxG.sound.music.playing) {
			return;
		}

		if(timeFreeze > 0) {
			var frozenDelta:Float = elapsed * 1000 * (1 - timeFreeze);
			Conductor.instance.update(Conductor.instance.trackedSongPosition + frozenDelta, false);
			return;
		}

		var audioDiff:Float = Math.round(Math.abs(FlxG.sound.music.time - (Conductor.instance.trackedSongPosition - Conductor.instance.combinedOffset)));
		if(audioDiff <= CONDUCTOR_DRIFT_THRESHOLD) {
			var easedRatio:Float = 1.0 - Math.exp(-MUSIC_EASE_RATIO * elapsed);
			var targetSongPos:Float = FlxMath.lerp(Conductor.instance.trackedSongPosition, FlxG.sound.music.time + Conductor.instance.combinedOffset, easedRatio);
			Conductor.instance.update(targetSongPos, false);
		} else {
			Conductor.instance.update();
		}
	}

	function restartSongInPlace():Void {
		needsReset = false;

		persistentUpdate = true;
		persistentDraw = true;
		paused = false;
		canPause = true;
		inCutscene = false;
		talking = false;
		startingSong = true;
		startedCountdown = false;
		startTimestamp = 0;
		waitForFinishPlayer = false;
		waitForFinishOpponent = false;
		hasWarning = false;
		previousHeldInputSongTime = null;
		previousFrameTime = FlxG.game.ticks;
		lastReportedPlayheadPosition = 0;
		songTime = 0;
		curSection = 0;
		eventCounter = 0;
		prevEventStep = 0;
		eventStorage = [];
		hits = 0;
		misses = 0;
		missesHold = 0;
		missClicks = 0;
		combo = 0;
		songScore = 0;
		totalRatingAcc = 0;
		daRating = "sick";
		health = 1;
		healthLerp = health;
		prevHealth = health;
		bumpPerBeat = 4;
		bumpForce = 1;
		bumpOffset = 0;
		singDrainValue = 1;
		fadeInValue = 400;
		cameraMovementInsensity = 1;
		opponentAltAnim = "";
		playerAltAnim = "";
		flipWiggle = 1;
		timeFreeze = 0;
		wobbleModPower = 30;

		CustomNoteHandler.spawn();
		Note.AFFECTED_STRUMTIME = 0;

		if(playScrollSpeed != null) {
			playScrollSpeed.reset(1);
		}else {
			Note.AFFECTED_SCROLLSPEED = 1;
		}

		stage.resetStage();
		resetHeldLaneKeys();
		setupModifiers();
		DefaultHandler.sizeTimer = 0;
		DefaultHandler.shakeCamTimer = 0;
		DefaultHandler.shakeCamTimerHUD = 0;
		DefaultHandler.strumOffsetEvent = [0, 0];
		DefaultHandler.tempNoteAbstracts = [];
		DefaultHandler.preloadAddon = false;

		if(healthTween != null) {
			healthTween.cancel();
			healthTween.destroy();
			healthTween = null;
		}

		if(boyfriend != null) {
			boyfriend.stunned = false;
			boyfriend.holdTimer = 0;
			boyfriend.customAnimation = false;
		}

		if(dad != null) {
			dad.stunned = false;
			dad.holdTimer = 0;
			dad.customAnimation = false;
		}

		if(gf != null) {
			gf.stunned = false;
			gf.holdTimer = 0;
			gf.customAnimation = false;
		}

		rebuildEvents();
		rebuildEventInfo();

		Countdown.stopCountdown();
		Countdown.reset();

		if(restartIntroTimer != null) {
			restartIntroTimer.cancel();
			restartIntroTimer.destroy();
			restartIntroTimer = null;
		}

		vwooshNotesOut();

		Conductor.instance.forceBPM(null);
		Conductor.instance.mapTimeChangesFromSong(SONG);

		if(FlxG.sound.music != null) {
			FlxG.sound.music.pause();
			FlxG.sound.music.time = 0;
			FlxG.sound.music.volume = muteInst ? 0 : 1;
		}

		stopVocals();
		setVocalsTime(0);
		setAllVocalsVolume(1);
		regenNoteData(false);

		resetStrumLayout();
		resetHealthUi();

		camPos.set(dad.getGraphicMidpoint().x, dad.getGraphicMidpoint().y);
		resetScriptedCameraState(false);
		restartScriptedCameraCaptured = false;

		if(camFollow != null) {
			camFollow.setPosition(camPos.x, camPos.y);
			FlxG.camera.follow(camFollow, LOCKON, getGameplayCameraFollowLerp());
			FlxG.camera.focusOn(camFollow.getPosition());
		}

		FlxG.camera.stopFX();
		camHUD.stopFX();
		camNOTE.stopFX();
		if(camNOTE.camNoteSustain != null) {
			camNOTE.camNoteSustain.stopFX();
			camNOTE.camNoteSustain.visible = true;
		}

		FlxG.camera.visible = true;
		camHUD.visible = true;
		camNOTE.visible = true;
		FlxG.camera.alpha = 1;
		camHUD.alpha = 1;
		camNOTE.alpha = 1;
		FlxG.camera.zoom = defaultCamZoom;
		camHUD.zoom = 1;
		camNOTE.zoom = 1;
		camGame.engineAlpha = modifierCheckList('blind effect') ? 0 : 1;

		Conductor.instance.update(startTimestamp - (RESTART_NOTE_INTRO_TIME * 1000) + (Conductor.instance.beatLengthMs * -5));
		lastTrackedSongPos = Conductor.instance.trackedSongPosition;
		syncMusicBeatState(Conductor.instance.trackedSongPosition);

		if(playLua != null) {
			playLua.reloadScriptForSongRestart();
			updateLuaVars();
			updatePerSectionLuaVars();
			playLua.set("inGameOver", false);
			playLua.set("startedCountdown", false);
			playLua.call("generatedStage", []);
			captureRestartScriptedCameraState();
			restoreRestartScriptedCameraState(true);
		}

		restartVwooshActive = true;
		disableInputs = true;
		restartIntroTimer = new FlxTimer().start(RESTART_NOTE_INTRO_TIME, function(_) {
			restartIntroTimer = null;
			restartVwooshActive = false;
			spawnVisibleNotes();
			vwooshNotesIn();
			disableInputs = false;
			beginCountdownSequence(false);
		});
	}

	var previousFrameTime:Int = 0;
	var lastReportedPlayheadPosition:Int = 0;
	var lastTrackedSongPos:Float = 0;
	var songTime:Float = 0;

	private function parseSongTrackSide(side:String):String {
		return playAudio.parseSongTrackSide(side);
	}

	private function normalizeSongTrackFilters(filterString:String):Array<String> {
		return playAudio.normalizeSongTrackFilters(filterString);
	}

	private function sanitizeSongTrackFilters(filters:Array<String>):Array<String> {
		return playAudio.sanitizeSongTrackFilters(filters);
	}

	private inline function isSongTrackInSoundList(sound:FlxSound):Bool {
		return playAudio.isSongTrackInSoundList(sound);
	}

	private inline function applySongTrackVolume(track:SongTrackInfo):Void {
		playAudio.applySongTrackVolume(track);
	}

	private function songTrackMatchesTag(track:SongTrackInfo, noteTag:String):Bool {
		return playAudio.songTrackMatchesTag(track, noteTag);
	}

	private function registerSongTrack(tag:String, fileName:String, sound:FlxSound, side:String, baseVolume:Float = 1,
		looped:Bool = false, ?tagFilters:Array<String>):SongTrackInfo {
		return playAudio.registerSongTrack(tag, fileName, sound, side, baseVolume, looped, tagFilters);
	}

	private function destroySongTrack(tag:String):Void {
		playAudio.destroySongTrack(tag);
	}

	private function destroyAllSongTracks():Void {
		playAudio.destroyAllSongTracks();
	}

	private function playSongTrack(track:SongTrackInfo, ?startTime:Null<Float>):Void {
		playAudio.playSongTrack(track, startTime);
	}

	private function addSongTrack(tag:String, fileName:String, side:String = SONG_TRACK_SIDE_EXTRA, baseVolume:Float = 1,
		looped:Bool = false, ?tagFilters:Array<String>):Bool {
		return playAudio.addSongTrack(tag, fileName, side, baseVolume, looped, tagFilters);
	}

	private function hasSongTrackDesync(baseTime:Float):Bool {
		return playAudio.hasSongTrackDesync(baseTime);
	}

	private function loadSongVocals(song:String):Void {
		playAudio.loadSongVocals(song);
	}

	private inline function pauseVocals():Void {
		playAudio.pauseVocals();
	}

	private inline function playVocals(?startTime:Null<Float>):Void {
		playAudio.playVocals(startTime);
	}

	private inline function stopVocals():Void {
		playAudio.stopVocals();
	}

	private inline function setVocalsTime(time:Float):Void {
		playAudio.setVocalsTime(time);
	}

	private inline function setAllVocalsVolume(volume:Float):Void {
		playAudio.setAllVocalsVolume(volume);
	}

	private inline function setPlayerVocalsVolume(volume:Float, ?noteTag:String):Void {
		playAudio.setPlayerVocalsVolume(volume, noteTag);
	}

	private inline function setOpponentVocalsVolume(volume:Float, ?noteTag:String):Void {
		playAudio.setOpponentVocalsVolume(volume, noteTag);
	}

	private inline function breakComboOnMiss():Void
	{
		if(gf != null && combo > 5 && gf.animOffsets.exists('sad'))
		{
			gf.playNoDanceAnim('sad');
		}

		combo = 0;
	}

	private function applyPlayerMissFeedback(direction:Int, ?noteTag:String, playSound:Bool = true, playAnim:Bool = true, holdDrop:Bool = false, ghostMiss:Bool = false):Void
	{
		setPlayerVocalsVolume(0, noteTag);

		if(playSound && SaveData.getData(MISS_SOUND_VOLUME) > 0)
		{
			FlxG.sound.play(Paths.soundRandom('missnote', 1, 3), SaveData.getData(MISS_SOUND_VOLUME) * FlxG.random.float(0.1, 0.2));
		}

		if(playAnim)
		{
			if(ghostMiss) {
				currentPlayer.onNoteGhostMiss(direction);
			}else if(holdDrop) {
				currentPlayer.onNoteHoldDrop(direction);
			}else {
				currentPlayer.onNoteMiss(direction);
			}
		}
	}

	private function startInstrumentTrack(?startTime:Null<Float>):Void {
		playAudio.startInstrumentTrack(startTime);
	}

	function startSong():Void
	{
		if(inCutscene || talking) {
			return;
		}

		prepareCharactersForSongStart();
		playAudio.startSong();
	}

	function prepareCharactersForSongStart():Void
	{
		resetCharacterForSongStart(gf);
		resetCharacterForSongStart(dad);
		resetCharacterForSongStart(boyfriend);
	}

	function resetCharacterForSongStart(character:Character):Void
	{
		if(character == null) {
			return;
		}

		character.stunned = false;
		character.holdTimer = 0;
		character.customAnimation = false;
		character.dance(true);
	}

	var debugNum:Int = 0;

	private function generateSong(dataPath:String, ?reloadVocals:Bool = true):Void
	{
		var loadedSplashAnimations:Array<String> = [];

		// FlxG.log.add(ChartParser.parse());
		var keys:Int = 4;

		var songData = SONG;
		Conductor.instance.forceBPM(null);
		Conductor.instance.mapTimeChangesFromSong(songData);

		curSong = songData.song;

		if(reloadVocals) {
			loadSongVocals(PlayState.SONG.song);
		}

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

				susLength = susLength / Conductor.instance.stepLengthMs;

				if(swagNote.trail != null)
					add(swagNote.trail);

				unspawnNotes.push(swagNote);

				if(swagNote.hasCustomAddon != null)
					swagNote.hasCustomAddon.whenIsFirstRendered(swagNote, keys);

				for (susNote in 0...Math.floor(susLength)) {
					oldNote = unspawnNotes[Std.int(unspawnNotes.length - 1)];

					if(!oldNote.isSustainNote && oldNote.trail != null)
						oldNote.trail.members[0].visible = true;

					var sustainNote:Note = new Note(daStrumTime + (Conductor.instance.stepLengthMs * susNote) + Conductor.instance.stepLengthMs, daNoteData, oldNote, true, daNoteAbstract);
					sustainNote.scrollFactor.set();
					sustainNote.tag = oldNote.tag;

					sustainNote.playAnyAnimation = oldNote.playAnyAnimation;

					sustainNote.setupPosition = DefaultHandler.compilePosition((daStrumTime + (Conductor.instance.stepLengthMs * susNote) + Conductor.instance.stepLengthMs) * swagNote.howSpeed);

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
			storeDefaultStrumState(player, i, babyArrow, !isStoryMode ? babyArrow.y + 10 : babyArrow.y, 1);

			strumLineNotes.add(babyArrow);

			DefaultHandler.strumSize.push([babyArrow.scale.x, babyArrow.scale.y]);
		}
	}

	function tweenCamIn():Void {
		FlxTween.tween(FlxG.camera, {zoom: 1.3}, (Conductor.instance.stepLengthMs * 4 / 1000), {ease: FlxEase.elasticInOut});
	}

	override public function openSubState(SubState:FlxSubState):Void
	{
		var isGameOverSubstate:Bool = Std.isOfType(SubState, GameOverSubstate);

		if(paused && !isGameOverSubstate)
		{
			var substateName:String = Type.getClassName(Type.getClass(SubState));

			pauseMusic();
			FlxG.camera.followLerp = 0;

			if(playLua != null)
			{
				playLua.set("substateOpenName", substateName);
				playLua.call("onPause", [substateName]);
			}
		}

		super.openSubState(SubState);
	}

	override function closeSubState()
	{
		var wasGameOverSubstate:Bool = Std.isOfType(subState, GameOverSubstate);
		var shouldResume:Bool = paused && !wasGameOverSubstate;

		if (shouldResume)
		{
			paused = false;
		}

		setupKeyStuff();

		super.closeSubState();

		if(shouldResume && !needsReset) {
			persistentUpdate = true;
			persistentDraw = true;
			FlxG.camera.followLerp = getGameplayCameraFollowLerp();

			if (FlxG.sound.music != null && !startingSong && !inCutscene && !talking)
			{
				resyncVocals();
			}

			Countdown.resumeCountdown();

			if(playLua != null) {
				playLua.set("substateOpenName", "");
			}

			updateLuaVars();
			updatePerSectionLuaVars();

			if(playLua != null) {
				playLua.call('onResume', []);
			}

			#if windows
			if (startTimer != null && startTimer.finished)
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
	}

	override public function onFocus():Void
	{
		#if windows
		if (health > 0 && !paused)
		{
			if (Conductor.instance.trackedSongPosition > 0.0)
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")\n Acc: " + accTotal + "%", iconRPC, true, songLength - Conductor.instance.trackedSongPosition);
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
		playAudio.pauseMusic();
	}

	public function resyncVocals():Void {
		playAudio.resyncVocals();
	}

	function setSongPosition(time:Float):Void {
		playAudio.setSongPosition(time);
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
			* PlayScrollSpeed.getVisualSongDelta(DefaultHandler.getNoteTime(note.strumTime), Conductor.instance.trackedSongPosition)
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
			* PlayScrollSpeed.getVisualSongDelta(DefaultHandler.getNoteTime(note.strumTime), Conductor.instance.trackedSongPosition)
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
			if (isInCountdown)
			{
				updateCountdownConductor(elapsed);
			}
		}

		else
		{
			updateGameplayConductor(elapsed);
			lastTrackedSongPos = Conductor.instance.trackedSongPosition;
		}

		super.update(elapsed);

		if(needsReset) {
			restartSongInPlace();
			return;
		}

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

		var liveEventStep:Int = getStepFromTime(Conductor.instance.trackedSongPosition);

		if(startedCountdown && !startingSong && !inCutscene && prevEventStep != liveEventStep) {
			prevEventStep = liveEventStep;
			eventLoad();
		}

		var cameraPlaybackTime:Float = Conductor.instance.trackedSongPosition;
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
					FlxTween.tween(FlxG.camera, {zoom: 1}, (Conductor.instance.stepLengthMs * 4 / 1000), {ease: FlxEase.elasticInOut});
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

		if (!restartVwooshActive && unspawnNotes[0] != null)
		{
			var spawnTime:Float = 3000;

			spawnTime /= Math.min(1, unspawnNotes[0].howSpeed);

			while(unspawnNotes.length > 0 && unspawnNotes[0].strumTime - Conductor.instance.trackedSongPosition < spawnTime)
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
			playInput.controllerInput();
		}

		if (generatedMusic && !inCutscene)
		{
			playInput.defaultGameStuff();
			var botMode:Bool = modifierCheckList('bot mode');

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

				if(botMode && shouldBotplayHitPlayerNote(daNote)) {
					goodNoteHit(daNote, daNote.getNoteTime());
				}

				if(!daNote.exists || !daNote.alive) {
					return;
				}

				if (daNote.mustPress) {
					final strumIndex = Math.floor(Math.abs(daNote.noteData));
					final currentStrum = currentStrums.members[strumIndex];
					final sustainDirectionAngle = currentStrum.directionAngle;
					final sustainNoteAngle = currentStrum.directionAngle;

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
					daNote.xAngle = 0;
					daNote.yAngle = 0;

					if (daNote.isSustainNote) {
						daNote.setXaxisSustain(currentStrums.members, currentStrum.x, currentStrum.x + (Note.swagWidth / 3), sustainDirectionAngle);
					}
				}
				else {
					final strumIndex = Math.floor(Math.abs(daNote.noteData));
					final oppositeStrum = oppositeStrums.members[strumIndex];
					final sustainDirectionAngle = oppositeStrum.directionAngle;
					final sustainNoteAngle = oppositeStrum.directionAngle;

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
					daNote.xAngle = 0;
					daNote.yAngle = 0;

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

				var detector:Bool = Conductor.instance.trackedSongPosition > DefaultHandler.getNoteTime(daNote.strumTime) + 260;

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
										daNote.playAnyAnimation,
										daNote.isSustainNote
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
			currentOpponent.onNoteHit(Std.int(Math.abs(note.noteData)), altAnim);
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

	function shouldBotplayHitPlayerNote(note:Note):Bool {
		if(note == null || !note.mustPress || note.wasGoodHit || note.shouldBeDead) {
			return false;
		}

		if(note.getNoteTime() > Conductor.instance.trackedSongPosition) {
			return false;
		}

		if(note.isSustainNote && note.prevNote != null && !note.prevNote.wasGoodHit && !note.prevNote.shouldBeDead) {
			return false;
		}

		return true;
	}

    function haveGamePaused():Void {
		playFlow.haveGamePaused();
    }

	function pauseMenu():Void {
		playFlow.pauseMenu();
	}

	function controllerInput():Void {
		playInput.controllerInput();
	}

	function getReleased(event:Event):Void {
		playInput.getReleased(event);
	}

	function gameOverScreen():Void {
		playFlow.gameOverScreen();
	}

	function whenSongFinished():Void {
		playFlow.whenSongFinished();
	}

	function endSong():Void
	{
		playFlow.endSong();
	}

	var endingSong:Bool = false;

	private function popUpScore(strumtime:Float, id:Int, abby:String, ?judgeSongPosition:Float, ?noteTag:String):Void
	{
		playScoreFeedback.popUpScore(strumtime, id, abby, judgeSongPosition, noteTag);
	}

	function defaultGameStuff():Void {
		playInput.defaultGameStuff();
	}

	function getPressed(event:Event):Void
	{
		playInput.getPressed(event);
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
				applyPlayerMissFeedback(direction, null, true, playAnim, false, true);
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

			if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract)) {
				events.whenNoteIsPressed(note, this);
				stage.whenNoteIsPressed(note);
				cameraMovement(note.noteData, note.isSustainNote);

				currentPlayer.customAnimation = false;

				if(note.playAnyAnimation) {
					currentPlayer.onNoteHit(Std.int(Math.abs(note.noteData)), playerAltAnim + currentPlayer.hasBePlayer);
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
		strumNote.holdTimer = Conductor.instance.stepLengthMs * 1.25 / 1000;
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

		holdCoverTimers[lane] = (Conductor.instance.stepLengthMs * 1.1) / 1000;

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

		return Math.floor(Conductor.instance.getTimeInSteps(songTime));
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
		playEvents.generateStaticLua();
	}

	function makeNoteLua():Void {
		playEvents.makeNoteLua();
	}

	public function updateLuaVars():Void {
		playEvents.updateLuaVars();
	}

	public function updatePerSectionLuaVars():Void {
		playEvents.updatePerSectionLuaVars();
	}

	function eventLoad():Void {
		playEvents.eventLoad();
	}

	function eventLoad_DefaultHandler():Void {
		playEvents.eventLoadDefaultHandler();
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
		return Conductor.instance.trackedSongPosition;
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

	public function extractGameOverCharacter():Character
	{
		var deathCharacter:Character = currentPlayer;

		if(deathCharacter == null)
		{
			return null;
		}

		if(stage != null)
		{
			stage.remove(deathCharacter, true);
		}

		return deathCharacter;
	}

	public function restoreGameOverCharacter(character:Character):Void
	{
		if(character == null || stage == null)
		{
			return;
		}

		if(character == boyfriend)
		{
			stage.addCharacter(character, CharacterRole.BOYFRIEND);
		}
		else if(character == dad)
		{
			stage.addCharacter(character, CharacterRole.OPPONENT);
		}
		else if(character == gf)
		{
			stage.addCharacter(character, CharacterRole.GIRLFRIEND);
		}
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

		if (!startingSong && !inCutscene && !talking && ((FlxG.sound.music.time > Conductor.instance.trackedSongPosition + SONG_TRACK_DESYNC_TOLERANCE
			|| FlxG.sound.music.time < Conductor.instance.trackedSongPosition - SONG_TRACK_DESYNC_TOLERANCE)
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
				if (!isInCountdown && curBeat % gf.danceBeatTimer == 0 && !gf.isSinging() && !gf.stunned && gf.shouldPlayDance) {
					gf.dance();
				}
			}
		}

		if(dad.animation.curAnim != null) {
			if (curBeat % dad.danceBeatTimer == 0 && !dad.isSinging() && !dad.stunned && dad.shouldPlayDance) {
				dad.dance();
			}
		}

		if(boyfriend.animation.curAnim != null) {
			if (curBeat % boyfriend.danceBeatTimer == 0 && !boyfriend.isSinging() && !boyfriend.stunned && boyfriend.shouldPlayDance) {
				boyfriend.dance();
			}
		}

		/*
		if(dad.holdTimer < Conductor.instance.stepLengthMs * 0.0011 * boyfriend.singMultiplier) {
			var dadAnim:String = dad.animation.curAnim.name;

			if(dadAnim.startsWith("sing")) {
				dad.playNoDanceAnim(dadAnim, true);
			}
		}

		if(boyfriend.holdTimer < Conductor.instance.stepLengthMs * 0.0011 * boyfriend.singMultiplier) {
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
				FlxG.log.add('SECTION BPM CHANGE ACTIVE');
			}
			// else
			// Conductor.instance.forceBPM(SONG.bpm);
		}
		// FlxG.log.add('change bpm' + SONG.notes[Std.int(curStep / 16)].changeBPM);
		wiggleShit.update(Conductor.instance.beatLengthMs);

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

		if(!hudIconsStatic) {
			iconP1.setGraphicSize(Std.int(iconP1.width + 30));
			iconP2.setGraphicSize(Std.int(iconP2.width + 30));
			iconP1.updateHitbox();
			iconP2.updateHitbox();
		}

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
		var stateCamNoteSustain:PlayCamera = ownedCamNoteSustain;
		var stateCamHUD:PlayCamera = ownedCamHUD;

		removeBotplayOverlay();
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

	public function requestSongRestart():Void {
		needsReset = true;
		persistentUpdate = true;
		persistentDraw = true;
	}

	function updateBotplayOverlay():Void {
		if(!modifierCheckList('bot mode')) {
			removeBotplayOverlay();
			return;
		}

		if(botplayText == null) {
			botplayText = new BotplayText();
		}

		if(botplayText.parent == null) {
			Lib.current.addChild(botplayText);
		}
	}

	function removeBotplayOverlay():Void {
		if(botplayText == null) {
			return;
		}

		if(botplayText.parent != null) {
			botplayText.parent.removeChild(botplayText);
		}

		botplayText.dispose();
		botplayText = null;
	}

	public function requestGameOverRestart():Void {
		needsReset = true;
		persistentUpdate = true;
		persistentDraw = false;
		paused = false;

		FlxG.camera.stopFX();
		FlxG.camera.alpha = 1;

		if(playLua != null) {
			playLua.set("inGameOver", false);
		}
	}

	override public function destroy() {
		var statePlayLua:PlayLua = playLua;
		var stateCamNOTE:CameraNote = ownedCamNOTE;
		var stateCamNoteSustain:PlayCamera = ownedCamNoteSustain;
		var stateCamHUD:PlayCamera = ownedCamHUD;

		FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, getPressed);
		FlxG.stage.removeEventListener(KeyboardEvent.KEY_UP, getReleased);

		Countdown.stopCountdown();
		clearRestartVwooshNotes();
		if(instance == this) {
			instance = null;
		}

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
