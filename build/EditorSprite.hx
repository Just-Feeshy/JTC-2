package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxCamera;
import flixel.util.FlxColor;
import flixel.graphics.FlxGraphic;
import flixel.system.FlxAssets.FlxGraphicAsset;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFrame.FlxFrameAngle;
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
* TODO: Get animations from json too.
*
* @author Feeshy
*/
class EditorSprite extends FlxSprite {
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

    var graphics:FlxGraphic;
    var xmlData:Xml;

    public function new(?X:Float = 0, ?Y:Float = 0, ?SimpleGraphic:FlxGraphicAsset) {
        super(X, Y, SimpleGraphic);

        antialiasing = SaveData.getData(SaveType.GRAPHICS);
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

    public function updateFrameSizeOffset(width:Float, height:Float, ?name:String = null):Void {
        var frameIndex:Int = 0;

        while(frameIndex < frames.frames.length) {
            if(name == frames.frames[frameIndex].name || name == null) {
                frames.frames[frameIndex].frame.width += width;
                frames.frames[frameIndex].frame.height += height;
            }

            frameIndex++;
        }
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
    override function drawComplex(camera:FlxCamera):Void {
		_frame.prepareMatrix(_matrix, FlxFrameAngle.ANGLE_0, checkFlipX(), checkFlipY());
		_matrix.translate(-origin.x, -origin.y);
		_matrix.scale(scale.x, scale.y);

		if (bakedRotationAngle <= 0) {
			updateTrig();

			if (angle != 0 || xAngle != 0 || yAngle != 0) {
                animation.update(0);
                angleMatrixTransform();
            }
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
        FeshMath3D.rotateWithTrig3D(_matrix, xAngle, yAngle, zAngle);
    }

    override function destroy() {
        FlxG.bitmap.remove(graphics);
        graphics = FlxDestroyUtil.destroy(graphics);

        defaultCompiler = null;
        completeCallback = null;

        super.destroy();
    }
}