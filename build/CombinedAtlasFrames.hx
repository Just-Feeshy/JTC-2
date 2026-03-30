package;

import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFramesCollection.FlxFrameCollectionType;

class CombinedAtlasFrames extends FlxFramesCollection
{
	var usedGraphics:Array<FlxGraphic> = [];

	public function new(collections:Array<FlxFramesCollection>)
	{
		super(resolveParent(collections), FlxFrameCollectionType.ATLAS, null);

		if(collections == null) {
			return;
		}

		for(collection in collections) {
			if(collection == null) {
				continue;
			}

			for(frame in collection.frames) {
				pushFrame(frame);
			}

			var graphic:FlxGraphic = collection.parent;
			if(graphic == null || graphic == parent || usedGraphics.indexOf(graphic) >= 0) {
				continue;
			}

			graphic.destroyOnNoUse = false;
			graphic.useCount++;
			usedGraphics.push(graphic);
		}
	}

	static function resolveParent(collections:Array<FlxFramesCollection>):FlxGraphic
	{
		if(collections == null) {
			return null;
		}

		for(collection in collections) {
			if(collection != null && collection.parent != null) {
				collection.parent.destroyOnNoUse = false;
				return collection.parent;
			}
		}

		return null;
	}

	override public function destroy():Void
	{
		while(usedGraphics.length > 0) {
			var graphic:FlxGraphic = usedGraphics.pop();

			if(graphic != null) {
				graphic.useCount--;
			}
		}

		super.destroy();
	}
}
