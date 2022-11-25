package feshixl.ui;

import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.graphics.frames.FlxFrame;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFrame.FlxFrameAngle;
import flixel.util.FlxDestroyUtil;
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
        if(offsetInfo == null || offsetInfo == null) {
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

            var rect:FlxRect = if(offsetInfo.get(name).length > 2) {
                FlxRect.get( 
                    texture.frame.x + offsetInfo.get(name)[0],
                    texture.frame.y + offsetInfo.get(name)[1],
                    texture.frame.width + offsetInfo.get(name)[2],
                    texture.frame.height + offsetInfo.get(name)[3]
                );
            }else {
                FlxRect.get( 
                    texture.frame.x,
                    texture.frame.y,
                    texture.frame.width + offsetInfo.get(name)[0],
                    texture.frame.height + offsetInfo.get(name)[1]
                );
            }

            newFrames.addAtlasFrame(rect, sourceSize, offset, name, flipX, flipY);
        }

        frames = destroyStuff ? FlxDestroyUtil.destroy(frames) : frames;
        return newFrames;
    }
}