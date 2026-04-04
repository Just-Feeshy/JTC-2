package;

import flixel.FlxG;
import flixel.FlxState;
import lime.utils.Assets;
import haxe.Json;
import SaveData.SaveType;

import IDialogue.DialogueData;
import ModInitialize;

#if json2object
import json2object.JsonParser;
#end

using StringTools;

/**
 * Simplified state transition - no more pre-caching from cache.json.
 * Assets are loaded on-demand (lazy loading) like base Funkin.
 */
class CacheState extends HelperStates {
	var target:FlxState;
	var stopMusic = false;

	public function new(target:FlxState, stopMusic:Bool):Void {
		super("void", "void");

		this.target = target;
		this.stopMusic = stopMusic;
	}

	override function create() {
		super.create();
		// Immediately transition - no pre-caching needed
		switchToTarget();
	}

	function switchToTarget():Void {
		queuePurgeOnStateSwitch();
		FlxG.switchState(target);
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

		queuePurgeOnStateSwitch();
		FlxG.switchState(target);
	}
}
