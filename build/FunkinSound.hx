package;

import flixel.FlxG;
import flixel.system.FlxSound;
import openfl.media.Sound;

class FunkinSound extends FlxSound
{
	public var isPlaying(get, never):Bool;

	public function new()
	{
		super();
	}

	static function getMusicGroup():Dynamic
	{
		return FlxG.sound != null ? FlxG.sound.defaultMusicGroup : null;
	}

	public static function load(path:String):FunkinSound
	{
		var sound = new FunkinSound();
		// Use Paths.loadSoundAsset to properly handle library paths and filesystem paths
		var soundAsset:Sound = Paths.loadSoundAsset(path);
		if (soundAsset != null)
		{
			sound.loadEmbedded(soundAsset, false, true);
		}
		else
		{
			// Fallback to direct path loading
			sound.loadEmbedded(path, false, true);
		}
		sound.persist = true;
		sound.group = getMusicGroup();
		return sound;
	}

	public static function playOnce(path:String, ?onComplete:Void->Void):FunkinSound
	{
		var sound = load(path);
		sound.onComplete = onComplete;
		FlxG.sound.list.add(sound);
		sound.play();
		return sound;
	}

	function get_isPlaying():Bool
	{
		return playing;
	}
}
