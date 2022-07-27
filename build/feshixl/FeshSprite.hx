package feshixl;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxCamera;
import flixel.util.FlxColor;
import flixel.graphics.FlxGraphic;
import flixel.system.FlxAssets.FlxGraphicAsset;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFrame;
import flixel.util.FlxDestroyUtil;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.math.FlxMatrix;
import feshixl.math.FeshMath3D;
import openfl.geom.Rectangle;
import openfl.utils.ByteArray;
import openfl.display.BitmapData;
import openfl.geom.Point;
import haxe.xml.Access;

import SaveData.SaveType;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

/**
* This sprite class was made to make `FlxSprite` easier to configure
* which would also allow the user to easily cutomize said sprite for there mod.
*
* WARNING: This class is for experimental purposes only.
* TODO: Get animations from json too.
*
* @author Feeshy
*/
class FeshSprite extends FlxSprite {
    /**
    * Rotate angle's pitch axis.
    */
    public var xAngle(default, set):Float = 0;

    /**
    * Rotate angle's yaw axis.
    */
    public var yAngle(default, set):Float = 0;

    /**
    * Rotate angle's row axis.
    */
    public var zAngle(get, set):Float;

    public var defaultCompiler:Void->Void;
    public var completeCallback:Void->Void;

    public var engineWidth:Float = 0;
    public var engineHeight:Float = 0;

    /**
    * Should use either advance clipping or regular.
    */
    public var useAdvanceClipping:Bool = true;

    var graphics:FlxGraphic;
    var xmlData:Xml;

    @:noCompletion var clippingPointAtlas:Map<String, FlxPoint>;

    public function new(?X:Float = 0, ?Y:Float = 0, ?SimpleGraphic:FlxGraphicAsset) {
        super(X, Y, SimpleGraphic);

        antialiasing = SaveData.getData(SaveType.GRAPHICS);
        clippingPointAtlas = new Map<String, FlxPoint>();
    }

    public function implementBitmap(image:ByteArray):Void {
        if(image == null)
            return;

        graphics = FlxG.bitmap.add(BitmapData.fromBytes(image));
        graphics.persist = true;
        graphics.destroyOnNoUse = false;
    }

    public function implementXML(xml:ByteArray):Void {
        if(xml == null)
            return;

        this.xmlData = Xml.parse(xml.toString());
    }

    public function compileSprite() {
        if(graphics == null || xmlData == null) {
            if(defaultCompiler != null) {
                defaultCompiler();
            }

            return;
        }

        this.frames = null;

        /**
        * Directly copied from `FlxAtlasFrames`.
        */
        var tempFrames:FlxAtlasFrames = FlxAtlasFrames.findFrame(graphics);

		if (tempFrames != null) {
			this.frames = tempFrames;
        }

        tempFrames = new FlxAtlasFrames(graphics);

        var data:Access = new Access(xmlData.firstElement());

        for (texture in data.nodes.SubTexture) {
            var name = texture.att.name;
            var trimmed = texture.has.frameX;
            var rotated = (texture.has.rotated && texture.att.rotated == "true");
            var flipX = (texture.has.flipX && texture.att.flipX == "true");
            var flipY = (texture.has.flipY && texture.att.flipY == "true");

            var rect = FlxRect.get(Std.parseFloat(texture.att.x), Std.parseFloat(texture.att.y), Std.parseFloat(texture.att.width),
                Std.parseFloat(texture.att.height));

            var size = if (trimmed)
            {
                new Rectangle(Std.parseInt(texture.att.frameX), Std.parseInt(texture.att.frameY), Std.parseInt(texture.att.frameWidth),
                    Std.parseInt(texture.att.frameHeight));
            }
            else
            {
                new Rectangle(0, 0, rect.width, rect.height);
            }

            var angle = rotated ? FlxFrameAngle.ANGLE_NEG_90 : FlxFrameAngle.ANGLE_0;

            var offset = FlxPoint.get(-size.left, -size.top);
            var sourceSize = FlxPoint.get(size.width, size.height);

            if (rotated && !trimmed)
                sourceSize.set(size.height, size.width);

            tempFrames.addAtlasFrame(rect, sourceSize, offset, name, angle, flipX, flipY);
        }

        this.frames = tempFrames;

        if(completeCallback != null) {
            completeCallback();
        }
    }

    public function twoInOneFrames(firstF:FlxFramesCollection, secondF:FlxFramesCollection):Void {
        try {
            var bitmapCum:BitmapData = new BitmapData(firstF.parent.width, firstF.parent.height + secondF.parent.height, FlxColor.TRANSPARENT);

            bitmapCum.copyPixels(firstF.parent.bitmap, firstF.parent.bitmap.rect, new Point(0, 0));
            bitmapCum.copyPixels(secondF.parent.bitmap, secondF.parent.bitmap.rect, new Point(0, firstF.parent.height));

            var tempFrames:FlxAtlasFrames = new FlxAtlasFrames(FlxG.bitmap.add(bitmapCum));
            var frameIndex:Int = 0;

            while(frameIndex < firstF.frames.length + secondF.frames.length) {
                if(frameIndex >= firstF.frames.length) {
                    tempFrames.pushFrame(secondF.frames[frameIndex - firstF.frames.length]);
                }else {
                    tempFrames.pushFrame(firstF.frames[frameIndex]);
                }

                frameIndex++;
            }

            frames = tempFrames;
        }catch(e:haxe.Exception) { //Just in case.
            trace("Warning - Can no longer implement a second frame.");
        }
    }
    
    public function updateFrameSizeOffset(width:Float, height:Float, ?name:String = null):Void {
        clippingPointAtlas.set(name, new FlxPoint(width, height));
    }

    public function getSourceAnimationName():Array<String> {
        var frameName:Array<String> = [];

        var index:Int = 0;

        if(this.frames != null) {
            while(index < this.frames.frames.length) {
                if(!frameName.contains(this.frames.frames[index].name.split("0")[0])) {
                    frameName.push(this.frames.frames[index].name.split("0")[0]);
                }

                index++;
            }
        }

        return frameName;
    }

    public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
        /**
        * Just to be safe.
        * Basically, if it can't find the animation it's looking for to play, then it'll execute a random one.
        */
        @:privateAccess
        if(!animation._animations.exists(AnimName)) {
            var getRandom:Int = FlxG.random.int(0, Lambda.count(animation._animations) - 1);
            var index = 0;

            var tempAnimName:String = "";

            for(k in animation._animations.keys()) {
                if(index >= getRandom) {
                    tempAnimName = animation._animations.get(k).name;
                    break;
                }

                index++;
            }

            animation.play(tempAnimName, Force, Reversed, Frame);
            
            AnimName = tempAnimName;
        }else {
            animation.play(AnimName, Force, Reversed, Frame);
        }
    }

    public function animationsExist():Bool {
        var doesExist:Bool = false;

        @:privateAccess
        for(k in animation._animations.keys()) {
            doesExist = true;
            break;
        }

        return doesExist;
    }

    @:noCompletion
    function set_xAngle(Value:Float):Float {
        var newAngle = (xAngle != Value);
		var ret = Value;
		if (newAngle) {
			_angleChanged = true;
		}

        xAngle = ret;
		return ret;
    }

    @:noCompletion
    function set_yAngle(Value:Float):Float {
        var newAngle = (yAngle != Value);
		var ret = Value;
		if (newAngle) {
			_angleChanged = true;
		}

        yAngle = ret;
		return ret;
    }

    @:noCompletion
    override function set_angle(Value:Float):Float {
        var newAngle = (angle != Value);
		var ret = Value;
		if (newAngle) {
			_angleChanged = true;
		}

        angle = ret;
		return ret;
    }

    @:noCompletion
    function get_zAngle():Float {
        return angle;
    }

    @:noCompletion
    function set_zAngle(Value:Float):Float {
        angle = Value;
        return Value;
    }

    @:noCompletion
	override function set_frame(Value:FlxFrame):FlxFrame { //A lot better algorithm for clipping
		frame = Value;

		if (frame != null) {
			resetFrameSize();
			dirty = true;
		}else if (frames != null && frames.frames != null && numFrames > 0) {
			frame = frames.frames[0];
			dirty = true;
		}else {
			return null;
		}

		if (FlxG.renderTile) {
			_frameGraphic = FlxDestroyUtil.destroy(_frameGraphic);
		}

        var betterClipRect:FlxRect = null;

        if(animation.curAnim != null && useAdvanceClipping) {
            betterClipRect = getAClipRect(animation.curAnim.name);
        }else {
            betterClipRect = clipRect;
        }

		if (betterClipRect != null) {
			_frame = frame.clipTo(betterClipRect, _frame);
		}else {
			_frame = frame.copyTo(_frame);
		}

		return frame;
	}

    @:noCompletion
    override function drawComplex(camera:FlxCamera):Void {
		_frame.prepareMatrix(_matrix, FlxFrameAngle.ANGLE_0, checkFlipX(), checkFlipY());
		_matrix.translate(-origin.x, -origin.y);
		_matrix.scale(scale.x + engineWidth, scale.y + engineHeight);

		if (bakedRotationAngle <= 0) {
			updateTrig();
			angleMatrixTransform();
		}

		_point.add(origin.x, origin.y);
		_matrix.translate(_point.x, _point.y);

		if (isPixelPerfectRender(camera)) {
			_matrix.tx = Math.floor(_matrix.tx);
			_matrix.ty = Math.floor(_matrix.ty);
		}

		camera.drawPixels(_frame, framePixels, _matrix, colorTransform, blend, antialiasing, shader);
	}

    @:noCompletion
    function angleMatrixTransform():Void {
        if (angle != 0 || xAngle != 0 || yAngle != 0) {
            animation.update(0);
            FeshMath3D.rotateWithTrig3D(_matrix, xAngle, yAngle, zAngle, true);
        }
    }

    @:noCompletion
    function getAClipRect(frameName:String):FlxRect {
        var completeRect:FlxRect = null;

        var foundMapping:Bool = clippingPointAtlas.exists(frameName); //Cache to speed things up.

        if(foundMapping || clipRect != null) {
            var tempAtlasClipRect:FlxRect = null;
            var tempClipRect:FlxRect = null;

            if(foundMapping) {
                var tempAtlasPoint:FlxPoint = clippingPointAtlas.get(frameName);
                tempAtlasClipRect = new FlxRect(0, 0, frameWidth + tempAtlasPoint.x, frameHeight + tempAtlasPoint.y);
            }else {
                tempAtlasClipRect = new FlxRect(0, 0, 0, 0);
            }

            if(clipRect != null) {
                tempClipRect = clipRect;
            }else {
                tempClipRect = new FlxRect(0, 0, 0, 0);
            }

            completeRect = new FlxRect(
                tempAtlasClipRect.x + tempClipRect.x,
                tempAtlasClipRect.y + tempClipRect.y,
                tempAtlasClipRect.width + tempClipRect.width,
                tempAtlasClipRect.height + tempClipRect.height
            );
        }

        return completeRect;
    }

    override function destroy() {
        FlxG.bitmap.remove(graphics);
        graphics = FlxDestroyUtil.destroy(graphics);

        defaultCompiler = null;
        completeCallback = null;

        super.destroy();

        if(clippingPointAtlas != null) {
            for(k in clippingPointAtlas.keys()) {
                var rect:FlxPoint = clippingPointAtlas.get(k);

                if(rect != null) {
                    rect.destroy();
                    rect = null;
                    clippingPointAtlas.remove(k);
                }
            }

            clippingPointAtlas.clear();
        }

        clippingPointAtlas = null;
    }
}