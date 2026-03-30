package;

import flixel.graphics.frames.FlxFramesCollection;

class FlxAnimationUtil
{
	public static function combineFramesCollections(a:FlxFramesCollection, b:FlxFramesCollection):FlxFramesCollection
	{
		return combineAtlas([a, b]);
	}

	public static function combineAtlas(collections:Array<FlxFramesCollection>):FlxFramesCollection
	{
		return new CombinedAtlasFrames(collections);
	}
}
