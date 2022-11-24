package feshixl.ui;

import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.graphics.frames.FlxFrame;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFrame.FlxFrameAngle;
import flixel.util.FlxDestroyUtil;
import flash.geom.Rectangle;

class FeshFramesHelper {
    public static function addOffsetRect(frames:FlxFramesCollection, offsetRect:FlxRect, destroyStuff:Bool = true):FlxFramesCollection {
        if(offsetRect == null) {
            return frames;
        }

        var newFrames:FlxFramesCollection = new FlxFramesCollection(frames.parent, frames.type, frames.border);

        for(texture in frames.frames) {
            var name:String = texture.name;
            var sourceSize:FlxPoint = texture.sourceSize;
            var offset:FlxPoint = texture.offset;
            var angle:FlxFrameAngle = texture.angle;
            var flipX:Bool = texture.flipX;
            var flipY:Bool = texture.flipY;

            var rect:FlxRect = FlxRect.get( 
                texture.frame.x + offsetRect.x,
                texture.frame.y + offsetRect.y,
                texture.frame.width + offsetRect.width,
                texture.frame.height + offsetRect.height
            );

            newFrames.addAtlasFrame(rect, sourceSize, offset, name, flipX, flipY);
        }

        frames = destroyStuff ? FlxDestroyUtil.destroy(frames) : frames;
        offsetRect = FlxDestroyUtil.put(offsetRect);

        return newFrames;
    }
}