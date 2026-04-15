package;

import flixel.FlxG;
import flixel.FlxState;
import lime.utils.Assets;
import haxe.Json;
import haxe.Timer;
import SaveData.SaveType;
import openfl.utils.AssetType;

import IDialogue.DialogueData;
import ModInitialize;

#if json2object
import json2object.JsonParser;
#end

using StringTools;

/**
 * Loading state that pre-caches song assets before switching to PlayState.
 * Based on Funkin's LoadingState approach.
 */
class CacheState extends HelperStates {
	public static var playStateAssetsPreloaded(default, null):Bool = false;

	var target:FlxState;
	var stopMusic = false;
	var assetsLoaded:Bool = false;
	var loadingScene:LoadingScene;
	var preloadQueue:Array<Void->Void> = [];
	var preloadQueueIndex:Int = 0;
	var pendingStateSwitch:Bool = false;

	public function new(target:FlxState, stopMusic:Bool):Void {
		super("void", "void");

		this.target = target;
		this.stopMusic = stopMusic;
	}

	override function create() {
		super.create();

		loadingScene = new LoadingScene();
		add(loadingScene);

		if(Std.isOfType(target, PlayState)) {
			buildPreloadQueue();
			if(preloadQueue.length <= 0) {
				finishPreloadAndSwitch();
			}
		}else {
			pendingStateSwitch = true;
		}
	}

	/**
	 * Pre-caches song assets (audio, characters, stage) before entering PlayState.
	 * Similar to Funkin's LoadingState.loadPlayState approach.
	 */
	function buildPreloadQueue():Void {
		if(PlayState.SONG == null)
			return;

		var song:String = PlayState.SONG.song.toLowerCase();

		preloadQueue = [];

		var instPath:String = Paths.getSongSoundPath(song, "Inst");
		if(instPath != null && instPath != "") {
			preloadQueue.push(function() {
				Cache.cacheSound(instPath);
			});
		}

		for(soundFile in getSongVoiceFiles(song)) {
			var voicePath:String = Paths.getSongSoundPath(song, soundFile);
			if(voicePath == null || voicePath == "") {
				continue;
			}

			preloadQueue.push(function() {
				Cache.cacheSound(voicePath);
			});
		}

		if(SaveData.getData(SaveType.MISS_SOUND_VOLUME) > 0) {
			for(missKey in ["missnote1", "missnote2", "missnote3"]) {
				var soundPath:String = Paths.getPath('sounds/$missKey.${Paths.SOUND_EXT}', AssetType.SOUND, "shared");
				preloadQueue.push(function() {
					Cache.cacheSound(soundPath);
				});
			}
		}

		preloadQueue.push(function() {
			Cache.cacheAsset("iconGrid");
		});

		for(characterName in [PlayState.SONG.player1, PlayState.SONG.player2, PlayState.SONG.girlfriend]) {
			if(characterName == null || characterName.trim() == "") {
				continue;
			}

			preloadQueue.push(function() {
				Cache.cacheCharacter(characterName);
			});
		}

		if(PlayState.SONG.stage != null && PlayState.SONG.stage.trim() != "") {
			var stageName:String = PlayState.SONG.stage;
			preloadQueue.push(function() {
				Cache.cacheStage(stageName);
			});
		}

		preloadQueueIndex = 0;
		loadingScene.setCacheValue(0, false);
	}

	function getSongVoiceFiles(song:String):Array<String> {
		var result:Array<String> = [];

		if(Paths.songSoundExists(song, "1_Voices") && Paths.songSoundExists(song, "2_Voices")) {
			result.push("1_Voices");
			result.push("2_Voices");
		}else if(Paths.songSoundExists(song, "Voices")) {
			result.push("Voices");
		}

		return result;
	}

	function processPreloadQueue():Void {
		if(preloadQueueIndex >= preloadQueue.length) {
			finishPreloadAndSwitch();
			return;
		}

		var startTime:Float = Timer.stamp();
		var timeBudget:Float = 1 / 240;

		while(preloadQueueIndex < preloadQueue.length && (Timer.stamp() - startTime) < timeBudget) {
			preloadQueue[preloadQueueIndex]();
			preloadQueueIndex++;
		}

		loadingScene.setCacheValue(preloadQueueIndex / preloadQueue.length, false);

		if(preloadQueueIndex >= preloadQueue.length) {
			finishPreloadAndSwitch();
		}
	}

	function finishPreloadAndSwitch():Void {
		if(assetsLoaded) {
			return;
		}

		assetsLoaded = true;
		playStateAssetsPreloaded = Std.isOfType(target, PlayState);
		loadingScene.setCacheValue(1, false);
		switchToTarget();
	}

	public static function consumePlayStatePreloadFlag():Bool {
		var result:Bool = playStateAssetsPreloaded;
		playStateAssetsPreloaded = false;
		return result;
	}

	function switchToTarget():Void {
		FlxG.switchState(target);
	}

	override function update(elapsed:Float):Void {
		super.update(elapsed);

		if(assetsLoaded) {
			return;
		}

		if(preloadQueue.length > 0) {
			processPreloadQueue();
			return;
		}

		if(pendingStateSwitch) {
			pendingStateSwitch = false;
			switchToTarget();
		}
	}

	static function queuePurgeOnStateSwitch():Void {
		FlxG.signals.preStateSwitch.addOnce(function() {
			Cache.purgeCache(true);
		});
	}

	static public function loadAndSwitchState(target:FlxState, ?stopMusic:Bool = true, ?exception:Bool = false):Void {
		Paths.setCurrentLevel("week" + PlayState.storyWeek);

		if(Std.isOfType(FlxG.state, FreeplayState)) {
			FlxG.signals.preStateSwitch.addOnce(function() {
				Cache.clearFreeplay();
			});
		}

		if(Std.isOfType(FlxG.state, StoryMenuState)) {
			FlxG.signals.preStateSwitch.addOnce(function() {
				Cache.clearCharacters();
			});
		}

		if(Std.isOfType(FlxG.state, PlayState)) {
			cast(FlxG.state, PlayState).prepareForStateSwitch();

			if(PlayState.isStoryMode && PlayState.storyPlaylist.length > 0) {
				FlxG.signals.preStateSwitch.addOnce(function() {
					Cache.clearCharacters();
				});
			}
		}

		if (stopMusic && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}

		// Handle video cutscenes
		if(PlayState.SONG.video != null && !exception && !SaveData.getData(SaveType.SKIP_CUTSCENES)) {
			queuePurgeOnStateSwitch();
			FlxG.switchState(new VideoState(new PlayState(), PlayState.SONG.video));
			return;
		}

		// Use CacheState as intermediate loading state for PlayState transitions
		// This pre-caches audio and textures before entering gameplay (like Funkin's LoadingState)
		if(Std.isOfType(target, PlayState)) {
			FlxG.switchState(new CacheState(target, stopMusic));
			return;
		}

		queuePurgeOnStateSwitch();
		FlxG.switchState(target);
	}

	static public function loadAndSwitchStateF(target:FlxState, ?stopMusic:Bool = true, ?exception:Bool = false):Void {
		Paths.setCurrentLevel("week" + PlayState.storyWeek);

		if(Std.isOfType(FlxG.state, FreeplayState)) {
			FlxG.signals.preStateSwitch.addOnce(function() {
				Cache.clearFreeplay();
			});
		}

		if(Std.isOfType(FlxG.state, PlayState)) {
			cast(FlxG.state, PlayState).prepareForStateSwitch();
		}

		if (stopMusic && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}

		// Use CacheState as intermediate loading state for PlayState transitions
		if(Std.isOfType(target, PlayState)) {
			FlxG.switchState(new CacheState(target, stopMusic));
			return;
		}

		queuePurgeOnStateSwitch();
		FlxG.switchState(target);
	}
}
