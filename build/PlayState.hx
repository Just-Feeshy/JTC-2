package;

#if desktop
import Discord.DiscordClient;
#end
import Section.SwagSection;
import Song.SwagSong;
import Conductor.BPMChangeEvent;
import WiggleEffect.WiggleEffectType;
import Controls.Control;
import Controls.Device;
import CheeseSliceSprite;
import Cache;
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
import flixel.graphics.frames.FlxFramesCollection;
import feshixl.FeshMinSprite;
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
import play.PlayScriptEvent;
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
	public var customDeathCharacter:play.DeathCharacter;
	public var boyfriendMap:Map<String, Boyfriend> = new Map<String, Boyfriend>();
	public var dadMap:Map<String, Character> = new Map<String, Character>();
	public var gfMap:Map<String, Character> = new Map<String, Character>();

	// Track character changes for proper reset
	public var originalPlayer1:String = "";
	public var originalPlayer2:String = "";
	public var originalGirlfriend:String = "";
	public var characterChangeDirty:Bool = false;

	public var currentPlayer(get, never):Character;
	public var currentOpponent(get, never):Character;

	public var notes:FlxTypedGroup<Note>;
	public var unspawnNotes:Array<Note> = [];

	public var waitForFinishPlayer:Bool = false;
	public var waitForFinishOpponent:Bool = false;

	public var bumpPerBeat:Int = 4;
	public var bumpForce:Float = 1;
	public var bumpOffset:Int = 0;

	private static inline var CAMERA_BUMP_GAME_ZOOM:Float = 0.02;
	private static inline var CAMERA_BUMP_HUD_ZOOM:Float = 0.04;
	private static inline var ICON_BUMP_SIZE:Int = 45;
	private static inline var ICON_BUMP_LERP:Float = 0.08;

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
	public var stageDefaultCamZoom:Float = 1.05;

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

	#if desktop
	public function buildDiscordRPCState():String
	{
		var songName:String = SONG != null && SONG.song != null ? SONG.song : "???";
		var difficultyName:String = storyDifficultyText != null && storyDifficultyText.trim() != "" ? storyDifficultyText : "???";
		return songName + " [" + difficultyName + "]";
	}

	public function buildDiscordRPCDetails(?prefix:String):String
	{
		var baseDetails:String = detailsText;

		if(baseDetails == null || baseDetails.trim() == "") {
			baseDetails = isStoryMode ? "Story Mode: Week " + storyWeek : "Freeplay";
		}

		if(prefix != null && prefix.trim() != "") {
			return prefix + " - " + baseDetails;
		}

		return baseDetails;
	}

	public function updateDiscordPresence(?detailsPrefix:String):Void
	{
		DiscordClient.setPresence({
			state: buildDiscordRPCState(),
			details: buildDiscordRPCDetails(detailsPrefix),
			smallImageKey: iconRPC
		});
	}
	#end

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
		#if false
		DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
		#end

		if(SONG.stage == null)
			SONG.stage = DefaultStage.setMainGameStage(SONG.song.toLowerCase());

		curStage = SONG.stage;

		Cache.cacheStage(curStage);
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

		Cache.cacheCharacter(gfVersion);
		gf = new Character(400, 130, gfVersion);
		gf.scrollFactor.set(0.95, 0.95);
		
		if(!stage.hasGirlfriend()) {
			gf.destroy();
			gf = null;
		}

		Cache.cacheCharacter(SONG.player2);
		dad = new Character(100, 100, SONG.player2);
		originalPlayer1 = SONG.player1;
		originalPlayer2 = SONG.player2;
		originalGirlfriend = gf != null ? gf.curCharacter : "";
		characterChangeDirty = false;

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

		Cache.cacheCharacter(SONG.player1);
		boyfriend = new Boyfriend(770, 100, SONG.player1);

		boyfriend.refresh(SONG.player1, camPos);
		camPos.set(dad.getGraphicMidpoint().x, dad.getGraphicMidpoint().y);
		dad.refresh(SONG.player2, camPos);
		boyfriendMap.set(boyfriend.curCharacter, boyfriend);
		dadMap.set(dad.curCharacter, dad);
		if(gf != null) {
			gfMap.set(gf.curCharacter, gf);
		}

		stage.configStage();
		stageDefaultCamZoom = defaultCamZoom;

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
		GameOverSubstate.reset();

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
			singAnims = ["singLEFT", "singDOWN", "", "singUP", "singRIGHT"];
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
		inputQueue = [];
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
	var restartRequestedFromGameOver:Bool = false;

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
		isInCountdown = false;
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
			directionAngle: strum.directionAngle,
			scaleX: strum.scale.x,
			scaleY: strum.scale.y
		};
	}

	function applyStrumResetState(strum:Strum, state:StrumResetState):Void {
		if(strum == null || state == null) {
			return;
		}

		strum.scale.set(state.scaleX, state.scaleY);
		strum.updateHitbox();
		strum.x = state.x;
		strum.y = state.y;
		strum.alpha = state.alpha;
		strum.angle = state.angle;
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
		if(paused || FlxG.sound.music == null) {
			return;
		}

		var allowFreezeDrivenUpdate:Bool = timeFreeze > 0 && playAudio != null && playAudio.isTimeFreezeAudioPaused();

		if(!FlxG.sound.music.playing && !allowFreezeDrivenUpdate) {
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
		var fromGameOver:Bool = restartRequestedFromGameOver;
		restartRequestedFromGameOver = false;
		needsReset = false;

		persistentUpdate = true;
		persistentDraw = true;
		paused = false;
		canPause = true;
		inCutscene = false;
		talking = false;
		startingSong = true;
		startedCountdown = false;
		isInCountdown = false;
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
		setTimeFreezeValue(0);
		wobbleModPower = 30;

		// Revert character changes on restart
		if(characterChangeDirty && originalPlayer2 != "") {
			revertCharacterChanges();
		}

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
		isInCountdown = false;

		if(restartIntroTimer != null) {
			restartIntroTimer.cancel();
			restartIntroTimer.destroy();
			restartIntroTimer = null;
		}

		if(!fromGameOver) {
			vwooshNotesOut();
		} else {
			clearRestartVwooshNotes();
		}

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
		clearGameplayCameraFilters();
		defaultCamZoom = stageDefaultCamZoom;
		vSliceDirectZoomValue = defaultCamZoom;

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

		var restartCountdownLeadIn:Float = Conductor.instance.beatLengthMs * -5;
		if(!fromGameOver) {
			restartCountdownLeadIn -= RESTART_NOTE_INTRO_TIME * 1000;
		}
		Conductor.instance.update(startTimestamp + restartCountdownLeadIn);
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

		if(fromGameOver) {
			restartVwooshActive = false;
			disableInputs = false;
			spawnVisibleNotes();
			beginCountdownSequence(false);
		}else {
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
	}

	var previousFrameTime:Int = 0;
	var lastReportedPlayheadPosition:Int = 0;
	var lastTrackedSongPos:Float = 0;
	var pausedTrackedSongPos:Null<Float> = null;
	var pendingPauseExitToMenu:Bool = false;
	var songTime:Float = 0;
	var preparedForStateSwitch:Bool = false;

	private function cachePausedRuntimeState():Void {
		pausedTrackedSongPos = Conductor.instance != null ? Conductor.instance.trackedSongPosition : null;
	}

	private function pauseGlobalRuntimeManagers():Void {
		FlxTimer.globalManager.forEach(function(timer:FlxTimer) {
			if(timer != null && !timer.finished) {
				timer.active = false;
			}
		});

		FlxTween.globalManager.forEach(function(tween:FlxTween) {
			if(tween != null && !tween.finished) {
				tween.active = false;
			}
		});
	}

	private function resumeGlobalRuntimeManagers():Void {
		FlxTimer.globalManager.forEach(function(timer:FlxTimer) {
			if(timer != null && !timer.finished) {
				timer.active = true;
			}
		});

		FlxTween.globalManager.forEach(function(tween:FlxTween) {
			if(tween != null && !tween.finished) {
				tween.active = true;
			}
		});
	}

	private function restorePausedRuntimeState():Void {
		if(pausedTrackedSongPos == null || Conductor.instance == null) {
			return;
		}

		Conductor.instance.update(pausedTrackedSongPos, false);
		syncMusicBeatState(pausedTrackedSongPos);
		lastTrackedSongPos = pausedTrackedSongPos;
		previousFrameTime = FlxG.game.ticks;
		pausedTrackedSongPos = null;
	}

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

	private inline function getSustainSegmentDurationMs(note:Note):Float
	{
		if(note == null || note.prevNote == null) {
			return Conductor.instance.stepLengthMs;
		}

		var segmentDurationMs:Float = Math.abs(note.getNoteTime() - note.prevNote.getNoteTime());
		return segmentDurationMs > 0 ? segmentDurationMs : Conductor.instance.stepLengthMs;
	}

	private inline function getSustainSegmentDurationSec(note:Note):Float
	{
		return getSustainSegmentDurationMs(note) / Constants.MS_PER_SEC;
	}

	private function isSustainChainStarted(note:Note):Bool
	{
		if(note == null || !note.isSustainNote) {
			return false;
		}

		var current:Note = note.prevNote;

		while(current != null) {
			if(current.wasGoodHit || current.shouldBeDead) {
				return true;
			}

			if(!current.isSustainNote || current.prevNote == null || current.prevNote == current) {
				break;
			}

			current = current.prevNote;
		}

		return false;
	}

	private function laneHasActiveSustainChain(lane:Int, mustPress:Bool):Bool
	{
		inline function matches(note:Note):Bool {
			return note != null
				&& note.isSustainNote
				&& note.noteData == lane
				&& note.mustPress == mustPress
				&& !note.sustainChainMissed
				&& !note.shouldBeDead
				&& isSustainChainStarted(note);
		}

		for(note in notes.members) {
			if(matches(note)) {
				return true;
			}
		}

		for(note in unspawnNotes) {
			if(matches(note)) {
				return true;
			}
		}

		return false;
	}

	public inline function hasActiveSustainChain(lane:Int, mustPress:Bool):Bool
	{
		return laneHasActiveSustainChain(lane, mustPress);
	}

	private function processActiveSustainStates(elapsed:Float, botMode:Bool):Void
	{
		if(startingSong) {
			return;
		}

		for(lane in 0...getLaneCount()) {
			var playerStrum:Strum = currentStrums.members[lane];
			var opponentStrum:Strum = oppositeStrums.members[lane];
			var playerChainActive:Bool = laneHasActiveSustainChain(lane, true);
			var opponentChainActive:Bool = laneHasActiveSustainChain(lane, false);

			if(playerChainActive && playerStrum != null && (botMode || playerStrum.sustainHeld)) {
				if(!botMode) {
					setHealth(health + (Constants.HEALTH_HOLD_BONUS_PER_SECOND * elapsed));
					songScore += Std.int(Constants.SCORE_HOLD_BONUS_PER_SECOND * elapsed);
				}

				if(currentPlayer != null && currentPlayer.isSinging()) {
					currentPlayer.holdTimer = 0;
				}

				refreshHoldCoverForLane(lane, true);
			}

			if(opponentChainActive) {
				if(currentOpponent != null && currentOpponent.isSinging()) {
					currentOpponent.holdTimer = 0;

					if(currentOpponent.isAnimationFinished()
						&& !currentOpponent.specialAnim
						&& !currentOpponent.customAnimation) {
						currentOpponent.onNoteHit(lane, getCurrentOpponentAnimSuffix());
					}
				}

				if(opponentStrum != null) {
					refreshHoldCoverForLane(lane, false);

					if(opponentStrum.hasDedicatedConfirmHold()) {
						playStrumConfirmHold(opponentStrum);
					}else {
						playStrumConfirm(opponentStrum);
					}
				}
			}
		}
	}

	private function getCurrentOpponentAnimSuffix():String
	{
		var altAnim:String = opponentAltAnim;

		if(SONG.notes[Math.floor(curStep / 16)] != null && SONG.notes[Math.floor(curStep / 16)].altAnim) {
			altAnim = '-alt';
		}

		return altAnim;
	}

	private function isSustainChainDescendantOf(candidate:Note, chainNote:Note):Bool
	{
		if(candidate == null || chainNote == null || !candidate.isSustainNote) {
			return false;
		}

		var current:Note = candidate;
		while(current != null) {
			if(current == chainNote) {
				return true;
			}

			if(current.prevNote == null || current.prevNote == current) {
				break;
			}

			// Stop at head notes - don't cross into different sustain chains
			// Head notes link to the previous song note which may be from a different chain
			if(!current.prevNote.isSustainNote) {
				break;
			}

			current = current.prevNote;
		}

		return false;
	}

	private function markRemainingSustainChainMissed(chainNote:Note):Void
	{
		if(chainNote == null || !chainNote.isSustainNote) {
			return;
		}

		chainNote.sustainChainMissed = true;

		for(candidate in notes.members) {
			if(candidate != null && isSustainChainDescendantOf(candidate, chainNote)) {
				candidate.sustainChainMissed = true;
			}
		}

		for(candidate in unspawnNotes) {
			if(candidate != null && isSustainChainDescendantOf(candidate, chainNote)) {
				candidate.sustainChainMissed = true;
			}
		}
	}

	private function handlePlayerSustainDrop(note:Note):Void
	{
		if(note == null || !note.isSustainNote || note.sustainChainMissed) {
			return;
		}

		markRemainingSustainChainMissed(note);

		// Calculate actual remaining length like Funkin does:
		// The end time of this segment is strumTime + sustainLength
		// The actual remaining is (endTime - currentSongPosition)
		var sustainEndTime:Float = note.getNoteTime() + note.sustainLength;
		var actualRemainingMs:Float = Math.max(0, sustainEndTime - Conductor.instance.trackedSongPosition);

		if(actualRemainingMs <= Constants.HOLD_DROP_PENALTY_THRESHOLD_MS) {
			return;
		}

		var remainingLengthSec:Float = actualRemainingMs / Constants.MS_PER_SEC;
		var healthChangeUncapped:Float = remainingLengthSec * Constants.HEALTH_HOLD_DROP_PENALTY_PER_SECOND;
		var healthChangeMax:Float = Constants.HEALTH_HOLD_DROP_PENALTY_MAX - (note.prevNote != null && note.prevNote.wasGoodHit ? -Constants.HEALTH_MISS_PENALTY : 0);
		var healthChange:Float = FlxMath.bound(healthChangeUncapped, healthChangeMax, 0);
		var scoreChange:Int = Std.int(Constants.SCORE_HOLD_DROP_PENALTY_PER_SECOND * remainingLengthSec);

		breakComboOnMiss();
		missesHold += 1;
		setHealth(health + healthChange);
		songScore += scoreChange;
		applyPlayerMissFeedback(Std.int(Math.abs(note.noteData)), note.tag, true, note.playAnyAnimation, true);
		updateLuaVars();
		updatePerSectionLuaVars();
		playLua.call("noteMiss", [note.noteData, note.tag]);
	}

	/**
	 * Funkin-style immediate sustain drop handling.
	 * Called when the player releases a key while holding a sustain.
	 */
	public function onSustainKeyReleased(lane:Int):Void
	{
		if(startingSong || modifierCheckList('bot mode')) {
			return;
		}

		var currentSongTime:Float = Conductor.instance.trackedSongPosition;
		var droppedNote:Note = null;

		// Find the first active sustain segment on this lane that was being held
		notes.forEachAlive(function(daNote:Note) {
			if(droppedNote != null) {
				return; // Already found one
			}

			if(daNote.mustPress
				&& daNote.isSustainNote
				&& daNote.noteData == lane
				&& !daNote.sustainChainMissed
				&& !daNote.wasGoodHit
				&& daNote.prevNote != null
				&& (daNote.prevNote.wasGoodHit || daNote.prevNote.shouldBeDead)) {
				droppedNote = daNote;
			}
		});

		if(droppedNote == null) {
			return;
		}

		// Find the head note of this sustain chain
		var headNote:Note = findSustainHeadNote(droppedNote);

		// Handle the drop penalty (this also marks the chain as missed)
		handlePlayerSustainDrop(droppedNote);

		// Immediately remove ALL sustain segments connected to this head note (Funkin-style)
		var notesToRemove:Array<Note> = [];

		notes.forEachAlive(function(daNote:Note) {
			if(daNote.isSustainNote && daNote.noteData == lane && belongsToSustainChain(daNote, headNote)) {
				daNote.visible = false;
				daNote.alpha = 0;
				notesToRemove.push(daNote);
			}
		});

		for(note in notesToRemove) {
			removeNote(note);
		}

		// Also remove from unspawned notes
		var unspawnedToRemove:Array<Note> = [];
		for(daNote in unspawnNotes) {
			if(daNote != null && daNote.isSustainNote && daNote.noteData == lane && belongsToSustainChain(daNote, headNote)) {
				unspawnedToRemove.push(daNote);
			}
		}

		for(note in unspawnedToRemove) {
			unspawnNotes.remove(note);
			note.destroy();
		}
	}

	/**
	 * Finds the head note (non-sustain) of a sustain chain by walking up prevNote.
	 */
	private function findSustainHeadNote(sustainNote:Note):Note
	{
		if(sustainNote == null) {
			return null;
		}

		var current:Note = sustainNote;
		while(current != null) {
			if(!current.isSustainNote) {
				return current; // Found the head note
			}

			if(current.prevNote == null || current.prevNote == current) {
				break;
			}

			current = current.prevNote;
		}

		return null;
	}

	/**
	 * Checks if a sustain note belongs to a chain with the given head note.
	 */
	private function belongsToSustainChain(sustainNote:Note, headNote:Note):Bool
	{
		if(sustainNote == null || headNote == null || !sustainNote.isSustainNote) {
			return false;
		}

		var foundHead:Note = findSustainHeadNote(sustainNote);
		return foundHead == headNote;
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

	public function hitPlayerSustainSegment(note:Note):Void
	{
		if(note == null || !note.isSustainNote || note.wasGoodHit || note.sustainChainMissed) {
			return;
		}

		note.wasGoodHit = true;
		note.shouldBeDead = true;

		if(SONG.needsVoices && !currentPlayer.stunned && canNoteUnmuteVoiceAudio(note)) {
			setPlayerVocalsVolume(1, note.tag);
		}

		refreshHoldCoverForLane(note.noteData, true);
	}

	private inline function canNoteUnmuteVoiceAudio(note:Note):Bool
	{
		if(note == null) {
			return true;
		}

		if(note.hasCustomAddon != null) {
			return note.hasCustomAddon.canUnmuteVoiceAudio();
		}

		return CustomNoteHandler.getCustomNoteUnmuteVoiceAudio(note.noteAbstract);
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
					sustainNote.sustainLength = Math.max(0, swagNote.sustainLength - (Conductor.instance.stepLengthMs * susNote));

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
		playLua.set("totalNotesLoaded", totalNotesLoaded);
		loadedSplashAnimations = [];
		generatedMusic = true;
	}

	function sortByShit(Obj1:Note, Obj2:Note):Int
	{
		return FlxSort.byValues(FlxSort.ASCENDING, Obj1.strumTime, Obj2.strumTime);
	}

	inline function getLaneXOffset(lane:Int, keys:Int):Float {
		var position:Float = Note.swagWidth * lane;

		if(keys == 5) {
			var middleLane:Int = Std.int((keys - 1) * 0.5);
			var middleGapOffset:Float = 20;

			if(lane < middleLane) {
				position -= middleGapOffset;
			}else if(lane > middleLane) {
				position += middleGapOffset;
			}
		}

		return position;
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
								babyArrow.x += getLaneXOffset(0, keys);
								babyArrow.animation.add('static', [0]);
								babyArrow.animation.add('pressed', [4, 8], 12, false);
								babyArrow.animation.add('confirm', [12, 16], 24, false);
							case 1:
								babyArrow.x += getLaneXOffset(1, keys);
								babyArrow.animation.add('static', [1]);
								babyArrow.animation.add('pressed', [5, 9], 12, false);
								babyArrow.animation.add('confirm', [13, 17], 24, false);
							case 2:
								babyArrow.x += getLaneXOffset(2, keys);
								babyArrow.animation.add('static', [20]);
								babyArrow.animation.add('pressed', [21, 22], 12, false);
								babyArrow.animation.add('confirm', [24, 23], 24, false);
							case 3:
								babyArrow.x += getLaneXOffset(3, keys);
								babyArrow.animation.add('static', [2]);
								babyArrow.animation.add('pressed', [6, 10], 12, false);
								babyArrow.animation.add('confirm', [14, 18], 12, false);
							case 4:
								babyArrow.x += getLaneXOffset(4, keys);
								babyArrow.animation.add('static', [3]);
								babyArrow.animation.add('pressed', [7, 11], 12, false);
								babyArrow.animation.add('confirm', [15, 19], 24, false);
						}
					default:
						babyArrow.reloadFrames('NOTE_assets');

						babyArrow.antialiasing = true;
						babyArrow.setGraphicSize(Std.int(babyArrow.width * 0.7));
						babyArrow.x += getLaneXOffset(i, keys);
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
						babyArrow.reloadFrames('NOTE_assets');

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
			cachePausedRuntimeState();
			pauseMusic();
			FlxG.camera.followLerp = 0;
			pauseGlobalRuntimeManagers();

			if(playLua != null)
			{
				playLua.set("substateOpenName", Type.getClassName(Type.getClass(SubState)));
			}

			dispatchEvent(new PlayScriptEvent(PlayScriptEvent.PAUSE));
		}

		super.openSubState(SubState);
	}

	override function closeSubState()
	{
		var wasGameOverSubstate:Bool = Std.isOfType(subState, GameOverSubstate);
		var shouldResume:Bool = paused && !wasGameOverSubstate;
		var shouldExitToMenu:Bool = pendingPauseExitToMenu && !wasGameOverSubstate;

		if(shouldExitToMenu) {
			pendingPauseExitToMenu = false;
		}

		setupKeyStuff();

		super.closeSubState();

		if(shouldExitToMenu) {
			paused = false;
			persistentUpdate = true;
			persistentDraw = true;
			FlxG.camera.followLerp = getGameplayCameraFollowLerp();
			resumeGlobalRuntimeManagers();

			if(playLua != null) {
				playLua.set("substateOpenName", null);
			}

			FlxG.signals.preStateSwitch.addOnce(function() {
				prepareForStateSwitch();
			});
			FlxG.switchState(new MainMenuState());
			return;
		}

		if(shouldResume && !needsReset) {
			paused = false;
			persistentUpdate = true;
			persistentDraw = true;
			FlxG.camera.followLerp = getGameplayCameraFollowLerp();
			restorePausedRuntimeState();

			if (FlxG.sound.music != null && !startingSong && !inCutscene && !talking)
			{
				resyncVocals();
			}

			Countdown.resumeCountdown();
			resumeGlobalRuntimeManagers();

			if(playLua != null) {
				playLua.syncResumeState();
			}

			dispatchEvent(new PlayScriptEvent(PlayScriptEvent.RESUME));

			#if desktop
			updateDiscordPresence();
			#end

			#if false
			if (startTimer != null && startTimer.finished)
			{
				songLength = FlxG.sound.music.length;

				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC, true, - songLength);
			}
			else
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
			}
			#end
		}
	}

	override public function onFocus():Void
	{
		if(!paused && isInCountdown)
		{
			Countdown.resumeCountdown();
		}

		#if false
		if (health > 0 && !paused)
		{
			if (Conductor.instance.trackedSongPosition > 0.0)
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC, true, songLength - Conductor.instance.trackedSongPosition);
			}
			else
			{
				DiscordClient.changePresence(detailsText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
			}
		}
		#end

		super.onFocus();
	}
	
	override public function onFocusLost():Void
	{
		if(!paused && isInCountdown)
		{
			Countdown.pauseCountdown();
		}

		#if false
		if (health > 0 && !paused)
		{
			DiscordClient.changePresence(detailsPausedText, SONG.song + " (" + storyDifficultyText + ")", iconRPC);
		}
		#end

		super.onFocusLost();
	}

	public function pauseMusic():Void {
		playAudio.pauseMusic();
	}

	public function resyncVocals(force:Bool = false):Void {
		playAudio.resyncVocals(force);
	}

	function setSongPosition(time:Float):Void {
		playAudio.setSongPosition(time);
	}

	public function getTimeFreezePlaybackRate(?freezeAmount:Null<Float>):Float {
		var amount:Float = freezeAmount == null ? timeFreeze : freezeAmount;
		return Math.min(1, Math.max(0.0001, 1 - FlxMath.bound(amount, 0, 1)));
	}

	public function setTimeFreezeValue(value:Float):Void {
		var previousFreeze:Float = timeFreeze;
		timeFreeze = FlxMath.bound(value, 0, 1);
		playAudio.applyTimeFreezeValue(previousFreeze, timeFreeze);
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
				yAddon -= ((Note.swagWidth - note.height) * 0.5);
			}else {
				yAddon += ((Note.swagWidth - note.height) * 0.5);
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
				yAddon -= ((Note.swagWidth - note.height) * 0.5);
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
			counterTxt.text = 'Misses: ' + misses + '       ' + 'Score: ' + songScore;
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

			#if false
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
				iconP1.setGraphicSize(Std.int(FlxMath.lerp(iconP1.width, 150, ICON_BUMP_LERP/(Main.framerate/100))));
				iconP2.setGraphicSize(Std.int(FlxMath.lerp(iconP2.width, 150, ICON_BUMP_LERP/(Main.framerate/100))));

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
				var centerNote:Float = strumPos + Note.swagWidth * 0.5;

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

				if(!startingSong && botMode && shouldBotplayHitPlayerNote(daNote)) {
					if(daNote.isSustainNote) {
						hitPlayerSustainSegment(daNote);
					}else {
						goodNoteHit(daNote, daNote.getNoteTime());
					}
				}

				if(!daNote.exists || !daNote.alive) {
					return;
				}

				if (daNote.mustPress) {
					final strumIndex = Math.floor(Math.abs(daNote.noteData));
					final currentStrum = currentStrums.members[strumIndex];
					final sustainDirectionAngle = currentStrum.directionAngle;
							final sustainNoteAngle = -FeshMath.degrees(currentStrum.directionAngle);

					daNote.setVisibility(currentStrum.onlyVisible);

					daNote.setXaxis(
						currentStrums.members,
						currentStrum.x,
						addToNoteX(currentStrum.x, daNote),
						currentStrum.directionAngle
					);

					daNote.setNoteAngle(currentStrum.angle, sustainNoteAngle);
					daNote.setNoteAlpha(currentStrum.onlyFans, fadeInValue);

					if (daNote.isSustainNote) {
						daNote.setXaxisSustain(currentStrums.members, currentStrum.x, currentStrum.x + (Note.swagWidth / 3), sustainDirectionAngle);
					}
				}
				else {
					final strumIndex = Math.floor(Math.abs(daNote.noteData));
					final oppositeStrum = oppositeStrums.members[strumIndex];
					final sustainDirectionAngle = oppositeStrum.directionAngle;
							final sustainNoteAngle = FeshMath.degrees(oppositeStrum.directionAngle);

					daNote.setVisibility(oppositeStrum.onlyVisible);

					daNote.setXaxis(
						oppositeStrums.members,
						oppositeStrum.x,
						addToNoteX(oppositeStrum.x, daNote),
						oppositeStrum.directionAngle
					);

					daNote.setNoteAngle(oppositeStrum.angle, sustainNoteAngle);
					daNote.setNoteAlpha(oppositeStrum.onlyFans, fadeInValue);

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

				var detector:Bool = !startingSong && Conductor.instance.trackedSongPosition > DefaultHandler.getNoteTime(daNote.strumTime) + 260;

				if (detector) {
					if (daNote.isSustainNote && (daNote.wasGoodHit || daNote.sustainChainMissed)) {
						removeNote(daNote);
						return;
					}else if(daNote.isSustainNote) {
						if(daNote.mustPress && !modifierCheckList('bot mode') && !CustomNoteHandler.dontHitNotes.contains(daNote.noteAbstract)) {
							if(daNote.prevNote != null && daNote.prevNote.wasGoodHit) {
								handlePlayerSustainDrop(daNote);
							}else {
								markRemainingSustainChainMissed(daNote);
							}
						}

						removeNote(daNote);
						return;
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
									updateLuaVars();
									updatePerSectionLuaVars();
									playLua.call("noteMiss", [daNote.noteData, daNote.tag]);
								}
							}
						}

					daNote.active = false;
					daNote.visible = false;

					removeNote(daNote);
				}
			});

			processActiveSustainStates(elapsed, botMode);

			if(playLua.hasScript()) {
				updateLuaVars();
			}
		}
	}

	function opponentNoteHit(note:Note):Void {
		if(note.isSustainNote) {
			note.shouldBeDead = true;
			return;
		}

		if (SONG.song != 'Tutorial')
			camZooming = true;

		var altAnim:String = getCurrentOpponentAnimSuffix();

		if(note.playAnyAnimation && !currentOpponent.specialAnim && !currentOpponent.customAnimation) {
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
				playStrumConfirm(spr);
			}
		});

		if (SONG.needsVoices && canNoteUnmuteVoiceAudio(note))
			setOpponentVocalsVolume(1, note.tag);

		updateLuaVars();
		updatePerSectionLuaVars();
		playLua.call("opponentNoteHit", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);

		removeNote(note);
	}

	public function playOpponentIdle():Void
	{
		if(dad == null) {
			return;
		}

		if(dad.specialAnim || dad.customAnimation) {
			return;
		}

		dad.playPreferredIdle(true);
	}

	function shouldBotplayHitPlayerNote(note:Note):Bool {
		if(note == null || !note.mustPress || note.wasGoodHit || note.shouldBeDead || note.ignore || note.sustainChainMissed) {
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
					updateLuaVars();
					updatePerSectionLuaVars();
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

	function singNotePlayer(note:Note):Void {
		if(!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract)) {
			events.whenNoteIsPressed(note, this);
			stage.whenNoteIsPressed(note);
			cameraMovement(note.noteData, false);

			currentPlayer.customAnimation = false;

			if(note.playAnyAnimation) {
				currentPlayer.onNoteHit(Std.int(Math.abs(note.noteData)), playerAltAnim + currentPlayer.hasBePlayer);
			}
		}
	}

	function goodNoteHit(note:Note, ?hitSongTime:Float):Void {
		if(note.isSustainNote) {
			hitPlayerSustainSegment(note);
			return;
		}

		if (!note.wasGoodHit)
		{
			if (!CustomNoteHandler.dontHitNotes.contains(note.noteAbstract))
			{
				popUpScore(note.getNoteTime(), note.noteData, note.noteAbstract, hitSongTime, note.tag);
				combo += 1;
			}

			setHealth(health + note.giveHealth());

			note.pressedByPlayer(currentPlayer, currentOpponent, gf);
			currentPlayer.customAnimation = true;
			singNotePlayer(note);

			var spr:Strum = currentStrums.members[note.noteData];

			if(note.noteAbstract != null)
				spr.ifCustom = note.noteAbstract;
			else
				spr.ifCustom = "regular";

			note.hit();

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
					playStrumConfirm(spr);
				}
			}else {
				playStrumConfirm(spr);
			}

			if(!CustomNoteHandler.ouchyNotes.contains(note.noteAbstract)) {
				note.wasGoodHit = true;

				if(SONG.needsVoices && !currentPlayer.stunned && canNoteUnmuteVoiceAudio(note)) {
					setPlayerVocalsVolume(1, note.tag);
				}

				hits++;
			}

			updateLuaVars();
			updatePerSectionLuaVars();
			playLua.call("goodNoteHit", [note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, false]);
			removeNote(note);
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

	override public function onCreate():Dynamic {
		if(playLua != null && playLua.hasScript()) {
			playLua.resetElapsed();
			return callLua("onCreate", []);
		}

		return super.onCreate();
	}

	function makeNoteLua():Void {
		playEvents.makeNoteLua();
	}

	override public function getModLua():ModLua {
		return playLua != null ? playLua.getOwnedLua() : null;
	}

	override public function addCallback(name:String, method:Dynamic):Void {
		var lua:ModLua = getModLua();
		if(lua != null) {
			lua.addCallback(name, method);
		}
	}

	override public function callLua(name:String, args:Array<Dynamic>):Dynamic {
		var lua:ModLua = getModLua();
		return lua != null ? lua.call(name, args) : null;
	}

	override public function setLua(variable:String, data:Dynamic):Void {
		if(playLua != null) {
			playLua.set(variable, data);
		}
	}

	override public function attachSprite(name:String, spr:FlxSprite):Void {
		var lua:ModLua = getModLua();

		if(lua != null && lua.luaSprites != null && !lua.luaSprites.exists(name)) {
			lua.luaSprites.set(name, spr);
		}
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

		// Track character changes for restart revert
		if(skill == "character change") {
			characterChangeDirty = true;
		}

		playLua.call("whenEventTriggered", [skill, value, value2]);
	}

	public function revertCharacterChanges():Void {
		if(!characterChangeDirty)
			return;

		if(originalPlayer1 != "" && boyfriend != null && boyfriend.curCharacter != originalPlayer1) {
			events.whenTriggered("character change", originalPlayer1, "boyfriend", this);
			event_Extra("character change", originalPlayer1, "boyfriend");
		}

		if(originalPlayer2 != "" && dad != null && dad.curCharacter != originalPlayer2) {
			events.whenTriggered("character change", originalPlayer2, "dad", this);
			event_Extra("character change", originalPlayer2, "dad");
		}

		if(originalGirlfriend != "" && gf != null && gf.curCharacter != originalGirlfriend) {
			events.whenTriggered("character change", originalGirlfriend, "gf", this);
			event_Extra("character change", originalGirlfriend, "gf");
		}

		characterChangeDirty = false;
	}

	public function addCharacterToList(newCharacter:String, type:Int):Void {
		if(newCharacter == null || newCharacter.trim() == "") {
			return;
		}

		var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(newCharacter);

		if(resolvedCharacter == null) {
			return;
		}

		newCharacter = resolvedCharacter;

		switch(type) {
			case 0:
				if(!boyfriendMap.exists(newCharacter)) {
					var sourceBoyfriend:Boyfriend = boyfriend;
					var baseX:Float = sourceBoyfriend != null ? sourceBoyfriend.x - sourceBoyfriend._info.position.get("x") : 770;
					var baseY:Float = sourceBoyfriend != null ? sourceBoyfriend.y - sourceBoyfriend._info.position.get("y") : 100;
					var newBoyfriend:Boyfriend = new Boyfriend(baseX, baseY, newCharacter);
					var newCamPos:FlxPoint = FlxPoint.get();
					newBoyfriend.refresh(newCharacter, newCamPos);
					newCamPos.put();
					newBoyfriend.alpha = 0.00001;
					boyfriendMap.set(newCharacter, newBoyfriend);

					if(stage != null) {
						var insertIndex:Int = sourceBoyfriend != null ? stage.members.indexOf(sourceBoyfriend) : -1;

						if(insertIndex >= 0)
							stage.insert(insertIndex, newBoyfriend);
						else
							stage.add(newBoyfriend);
					}
				}

			case 1:
				if(!dadMap.exists(newCharacter)) {
					var sourceDad:Character = dad;
					var baseX:Float = sourceDad != null ? sourceDad.x - sourceDad._info.position.get("x") : 100;
					var baseY:Float = sourceDad != null ? sourceDad.y - sourceDad._info.position.get("y") : 100;
					var newDad:Character = new Character(baseX, baseY, newCharacter);
					var newCamPos:FlxPoint = FlxPoint.get();
					newDad.refresh(newCharacter, newCamPos);
					newCamPos.put();
					newDad.alpha = 0.00001;
					dadMap.set(newCharacter, newDad);

					if(stage != null) {
						var insertIndex:Int = sourceDad != null ? stage.members.indexOf(sourceDad) : -1;

						if(insertIndex >= 0)
							stage.insert(insertIndex, newDad);
						else
							stage.add(newDad);
					}
				}

			case 2:
				if(gf != null && !gfMap.exists(newCharacter)) {
					var sourceGf:Character = gf;
					var baseX:Float = sourceGf != null ? sourceGf.x - sourceGf._info.position.get("x") : 400;
					var baseY:Float = sourceGf != null ? sourceGf.y - sourceGf._info.position.get("y") : 130;
					var newGf:Character = new Character(baseX, baseY, newCharacter);
					var newCamPos:FlxPoint = FlxPoint.get();
					newGf.refresh(newCharacter, newCamPos);
					newCamPos.put();
					newGf.alpha = 0.00001;
					gfMap.set(newCharacter, newGf);

					if(stage != null) {
						var insertIndex:Int = sourceGf != null ? stage.members.indexOf(sourceGf) : -1;

						if(insertIndex >= 0)
							stage.insert(insertIndex, newGf);
						else
							stage.add(newGf);
					}
				}
		}
	}

	private function destroyLoadedCharacterInstance(character:Character):Void {
		if(character == null) {
			return;
		}

		if(stage != null && stage.members.indexOf(character) >= 0) {
			stage.remove(character, true);
		}

		if(modifiableCharacters != null) {
			var removeKeys:Array<String> = [];

			for(key in modifiableCharacters.keys()) {
				if(modifiableCharacters.get(key) == character) {
					removeKeys.push(key);
				}
			}

			for(key in removeKeys) {
				modifiableCharacters.remove(key);
			}
		}

		character.exists = false;
		character.visible = false;
		character.active = false;
		character.destroy();
	}

	public function removeLoadedCharacter(characterName:String, type:Int):Bool {
		if(characterName == null || characterName.trim() == "") {
			return false;
		}

		var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(characterName);

		if(resolvedCharacter == null) {
			return false;
		}

		switch(type) {
			case 0:
				var loadedBoyfriend:Boyfriend = boyfriendMap != null ? boyfriendMap.get(resolvedCharacter) : null;

				if(loadedBoyfriend == null || loadedBoyfriend == boyfriend) {
					return false;
				}

				boyfriendMap.remove(resolvedCharacter);
				destroyLoadedCharacterInstance(loadedBoyfriend);
				return true;

			case 1:
				var loadedDad:Character = dadMap != null ? dadMap.get(resolvedCharacter) : null;

				if(loadedDad == null || loadedDad == dad) {
					return false;
				}

				dadMap.remove(resolvedCharacter);
				destroyLoadedCharacterInstance(loadedDad);
				return true;

			case 2:
				var loadedGf:Character = gfMap != null ? gfMap.get(resolvedCharacter) : null;

				if(loadedGf == null || loadedGf == gf) {
					return false;
				}

				gfMap.remove(resolvedCharacter);
				destroyLoadedCharacterInstance(loadedGf);
				return true;
		}

		return false;
	}

	private function syncLoadedCharacterTransform(currentChar:Character, nextChar:Character):Void {
		if(currentChar == null || nextChar == null) {
			return;
		}

		nextChar.setPosition(currentChar.x, currentChar.y);
		nextChar.updateFinalized(currentChar.x - nextChar._info.position.get("x"), currentChar.y - nextChar._info.position.get("y"));
		nextChar.alpha = currentChar.alpha;
		nextChar.angle = currentChar.angle;
		nextChar.visible = currentChar.visible;
		nextChar.flipX = currentChar.flipX;
	}

	public function swapCharacterToLoaded(newCharacter:String, type:Int):Bool {
		if(newCharacter == null || newCharacter.trim() == "") {
			return false;
		}

		var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(newCharacter);

		if(resolvedCharacter == null) {
			return false;
		}

		newCharacter = resolvedCharacter;

		addCharacterToList(newCharacter, type);

		switch(type) {
			case 0:
				var nextBoyfriend:Boyfriend = boyfriendMap.get(newCharacter);

				if(nextBoyfriend == null || boyfriend == nextBoyfriend) {
					return false;
				}

				var previousBoyfriend:Boyfriend = boyfriend;
				syncLoadedCharacterTransform(previousBoyfriend, nextBoyfriend);
				boyfriend.alpha = 0.00001;
				boyfriend.active = false;
				boyfriend = nextBoyfriend;
				boyfriend.active = true;
				modifiableCharacters.set("boyfriend", boyfriend);
				if(playLua != null) {
					playLua.syncDefaultCharacterPositions();
				}
				iconP1.character = boyfriend.curCharacter;
				iconP1.createAnim(boyfriend.curCharacter, boyfriend._info.icon, true);
				return true;

			case 1:
				var nextDad:Character = dadMap.get(newCharacter);

				if(nextDad == null || dad == nextDad) {
					return false;
				}

				var previousDad:Character = dad;
				syncLoadedCharacterTransform(previousDad, nextDad);
				dad.alpha = 0.00001;
				dad.active = false;
				dad = nextDad;
				dad.active = true;
				modifiableCharacters.set("dad", dad);
				if(playLua != null) {
					playLua.syncDefaultCharacterPositions();
				}
				iconP2.character = dad.curCharacter;
				iconP2.createAnim(dad.curCharacter, dad._info.icon, false);
				return true;

			case 2:
				var nextGf:Character = gfMap.get(newCharacter);

				if(nextGf == null || gf == nextGf) {
					return false;
				}

				var previousGf:Character = gf;
				syncLoadedCharacterTransform(previousGf, nextGf);
				gf.alpha = 0.00001;
				gf.active = false;
				gf = nextGf;
				gf.active = true;
				modifiableCharacters.set("gf", gf);
				if(playLua != null) {
					playLua.syncDefaultCharacterPositions();
				}
				return true;
		}

		return false;
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
				playOpponentIdle();
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
				FlxG.camera.zoom += CAMERA_BUMP_GAME_ZOOM * bumpForce;
				camHUD.zoom += CAMERA_BUMP_HUD_ZOOM * bumpForce;
				camNOTE.zoom += CAMERA_BUMP_HUD_ZOOM * bumpForce;
			}

			if(playLua.hasScript()) {
				updatePerSectionLuaVars();
			}
		}

		if(!hudIconsStatic) {
			iconP1.setGraphicSize(150 + ICON_BUMP_SIZE, 150 + ICON_BUMP_SIZE);
			iconP2.setGraphicSize(150 + ICON_BUMP_SIZE, 150 + ICON_BUMP_SIZE);
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
		if(preparedForStateSwitch) {
			return;
		}

		preparedForStateSwitch = true;

		var stateCamNOTE:CameraNote = ownedCamNOTE;
		var stateCamNoteSustain:PlayCamera = ownedCamNoteSustain;
		var stateCamHUD:PlayCamera = ownedCamHUD;

		// Leaving gameplay while paused skips closeSubState(), so resume global managers here.
		if(paused) {
			paused = false;
			persistentUpdate = true;
			persistentDraw = true;
			resumeGlobalRuntimeManagers();
		}

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
		restartRequestedFromGameOver = false;
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
		restartRequestedFromGameOver = true;
		needsReset = true;
		persistentUpdate = true;
		persistentDraw = false;
		paused = false;

		clearGameplayCameraFilters();
		FlxG.camera.stopFX();
		FlxG.camera.alpha = 1;

		if(playLua != null) {
			playLua.set("inGameOver", false);
		}
	}

	public function requestPauseExitToMenu():Void {
		pendingPauseExitToMenu = true;
	}

	public function clearGameplayCameraFilters():Void {
		clearGameplayCameraFilterStack(FlxG.camera);
		clearGameplayCameraFilterStack(ownedCamHUD);
		clearGameplayCameraFilterStack(ownedCamNOTE);
		clearGameplayCameraFilterStack(ownedCamNoteSustain);
	}

	private function clearGameplayCameraFilterStack(camera:FlxCamera):Void {
		if(camera == null) {
			return;
		}

		if(Std.isOfType(camera, PlayCamera)) {
			(cast camera:PlayCamera).eraseFilters();
		} else {
			camera.setFilters([]);
		}

		if(camera.flashSprite != null) {
			camera.flashSprite.filters = null;
			@:privateAccess camera.flashSprite.__setRenderDirty();
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
		isInCountdown = false;
		clearRestartVwooshNotes();
		if(instance == this) {
			instance = null;
		}

		prepareForStateSwitch();
		destroyAllSongTracks();

		if(FlxG.sound.music != null) {
			FlxG.sound.music.onComplete = null;
			FlxG.sound.music.stop();
		}

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

                if(spr != null && spr != boyfriend && spr != dad && spr != gf) {
                    spr.destroy();
                }
            }

			precacheList.clear();
			precacheList = null;

            modifiableCharacters.clear();
            modifiableCharacters = null;
        }

		if(boyfriendMap != null) {
			boyfriendMap.clear();
			boyfriendMap = null;
		}

		if(dadMap != null) {
			dadMap.clear();
			dadMap = null;
		}

		if(gfMap != null) {
			gfMap.clear();
			gfMap = null;
		}
	}
}
