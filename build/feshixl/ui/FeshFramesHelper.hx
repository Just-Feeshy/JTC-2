package feshixl.ui;

import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.graphics.frames.FlxFrame;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFrame.FlxFrameAngle;
import flixel.util.FlxDestroyUtil;
import feshixl.Feshixl;
import flash.geom.Rectangle;

class FeshFramesHelper {

    /**
     * `FlxRect` wouldn't work so I used `Array<Int>`.
     * 
     * @param frames The original frames required. 
     * @param offsetInfo The info needed to caculate the original size and position to the offset.
     * @param destroyStuff Destroy the original frames.
     */
    public static function addOffsetInfo(frames:FlxFramesCollection, offsetInfo:Map<String, Array<Int>>, destroyStuff:Bool = true):FlxFramesCollection {
        if(frames == null || offsetInfo == null || offsetInfo == null) {
            return frames;
        }

        var newFrames:FlxFramesCollection = new FlxFramesCollection(frames.parent, frames.type, frames.border);

        for(texture in frames.frames) {
            var name:String = texture.name;
            var sourceSize:FlxPoint = texture.sourceSize;
            var offset:FlxPoint = texture.offset;
            var flipX:Bool = texture.flipX;
            var flipY:Bool = texture.flipY;

            var cleanedAnimName:String = Feshixl.removeNumbersFromString(name);

            if(!offsetInfo.exists(cleanedAnimName)) {
                newFrames.addAtlasFrame(texture.frame, sourceSize, offset, name, flipX, flipY);
                continue;
            }

            var rect:FlxRect = if(offsetInfo.get(cleanedAnimName).length > 2) {
                FlxRect.get( 
                    texture.frame.x + offsetInfo.get(cleanedAnimName)[0],
                    texture.frame.y + offsetInfo.get(cleanedAnimName)[1],
                    texture.frame.width + offsetInfo.get(cleanedAnimName)[2],
                    texture.frame.height + offsetInfo.get(cleanedAnimName)[3]
                );
            }else {
                FlxRect.get( 
                    texture.frame.x,
                    texture.frame.y,
                    texture.frame.width + offsetInfo.get(cleanedAnimName)[0],
                    texture.frame.height + offsetInfo.get(cleanedAnimName)[1]
                );
            }

            newFrames.addAtlasFrame(rect, sourceSize, offset, name, flipX, flipY);
        }

        frames = destroyStuff ? FlxDestroyUtil.destroy(frames) : frames;
        return newFrames;
    }

    /*
    * Make a replica of @param frames
    * 
    * @param frames The original frames required. 
    */
    public static function copyFrames(frames:FlxFramesCollection):FlxFramesCollection {
        if(frames == null) {
            return frames;
        }

        var newFrames:FlxFramesCollection = new FlxFramesCollection(frames.parent, frames.type, frames.border);

        for(texture in frames.frames) {
            var name:String = texture.name;
            var sourceSize:FlxPoint = texture.sourceSize;
            var offset:FlxPoint = texture.offset;
            var flipX:Bool = texture.flipX;
            var flipY:Bool = texture.flipY;
            var frame:FlxRect = texture.frame;

            newFrames.addAtlasFrame(frame, sourceSize, offset, name, flipX, flipY);
        }

        return newFrames;
    }
}