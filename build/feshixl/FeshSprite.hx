package feshixl;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxCamera;
import flixel.util.FlxColor;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.system.FlxAssets.FlxGraphicAsset;
import flixel.graphics.frames.FlxFrame;
import flixel.util.FlxDestroyUtil;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.math.FlxMath;
import openfl.geom.Rectangle;
import openfl.geom.Matrix;
import openfl.utils.ByteArray;
import openfl.display.BitmapData;
import openfl.geom.Point;
import haxe.xml.Access;
import haxe.io.Bytes;

import FlxAnimationUtil;
import SaveData.SaveType;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

/**
* This sprite class was made to make `FlxSprite` easier to configure
* which would also allow the user to easily cutomize said sprite for there mod.
* Only issue, it overrides stuff
*
* WARNING: This class is for experimental purposes only.
* @author Feeshy
*/
class FeshSprite extends FeshMinSprite {
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

    @:noCompletion private var __clippingPointAtlas:Map<String, FlxPoint>;
    @:noCompletion private var __animationRectangle:Map<String, FlxRect>;

    public function new(?X:Float = 0, ?Y:Float = 0, ?SimpleGraphic:FlxGraphicAsset) {
        super(X, Y, SimpleGraphic);

        antialiasing = SaveData.getData(SaveType.GRAPHICS);

        __clippingPointAtlas = new Map<String, FlxPoint>();
        __animationRectangle = new Map<String, FlxRect>();
    }

    public function implementBitmap(image:Bytes):Void {
        if(image == null)
            return;

        graphics = FlxG.bitmap.add(BitmapData.fromBytes(ByteArray.fromBytes(image)));
        graphics.persist = true;
        graphics.destroyOnNoUse = false;
    }

    public function implementXML(xml:Bytes):Void {
        if(xml == null)
            return;

        this.xmlData = Xml.parse(decodeXmlBytes(xml));
    }

    static function decodeXmlBytes(xml:Bytes):String {
        var len = xml.length;
        if (len >= 2 && xml.get(0) == 0xFF && xml.get(1) == 0xFE) {
            var sb = new StringBuf();
            var i = 2;
            while (i + 1 < len) {
                sb.addChar(xml.get(i) | (xml.get(i + 1) << 8));
                i += 2;
            }
            return stripXmlEncodingDecl(sb.toString());
        }
        if (len >= 2 && xml.get(0) == 0xFE && xml.get(1) == 0xFF) {
            var sb = new StringBuf();
            var i = 2;
            while (i + 1 < len) {
                sb.addChar((xml.get(i) << 8) | xml.get(i + 1));
                i += 2;
            }
            return stripXmlEncodingDecl(sb.toString());
        }
        var s = xml.toString();
        if (s.length > 0 && s.charCodeAt(0) == 0xFEFF) s = s.substr(1);
        return s;
    }

    static function stripXmlEncodingDecl(s:String):String {
        if (s.length > 0 && s.charCodeAt(0) == 0xFEFF) s = s.substr(1);
        var end = s.indexOf("?>");
        if (s.substr(0, 5) == "<?xml" && end > 0) {
            return s.substr(end + 2);
        }
        return s;
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

    public static function twoInOneFrames(firstF:FlxFramesCollection, secondF:FlxFramesCollection):FlxFramesCollection {
		return FlxAnimationUtil.combineFramesCollections(firstF, secondF);
	}

    public function updateFrameSizeOffset(width:Float, height:Float, ?name:String = null):Void {
        __clippingPointAtlas.set(name, FlxPoint.get(width, height));
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

    @:noCompletion
    override function set_angle(Value:Float):Float {
        var newAngle = (angle != Value);
		var ret = Value;
		if (newAngle) {
			_angleChanged = true;
		}

        angle = ret;
		return ret % Math.PI * 2;
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
        if(_frame == null || _frame.parent == null || _frame.parent.bitmap == null || camera == null || camera.canvas == null) {
            return;
        }

		_frame.prepareMatrix(_matrix, FlxFrameAngle.ANGLE_0, checkFlipX(), checkFlipY());
		_matrix.translate(-origin.x, -origin.y);
		_matrix.scale(scale.x + engineWidth, scale.y + engineHeight);

		if (bakedRotationAngle <= 0)
		{
			updateTrig();

			if (angle != 0)
				_matrix.rotateWithTrig(_cosAngle, _sinAngle);
		}

		getScreenPosition(_point, camera).subtract(offset);
		_point.add(origin.x, origin.y);
		_matrix.translate(_point.x, _point.y);

		if (isPixelPerfectRender(camera))
		{
			_matrix.tx = Math.floor(_matrix.tx);
			_matrix.ty = Math.floor(_matrix.ty);
		}

		camera.drawPixels(_frame, framePixels, _matrix, colorTransform, blend, antialiasing, shader);
	}

    @:noCompletion
    function getAClipRect(frameName:String):FlxRect {
        var completeRect:FlxRect = null;

        var foundMapping:Bool = __clippingPointAtlas.exists(frameName); //Cache to speed things up.

        if(foundMapping || clipRect != null) {
            var tempAtlasClipRect:FlxRect = null;
            var tempClipRect:FlxRect = null;

            if(foundMapping) {
                var tempAtlasPoint:FlxPoint = __clippingPointAtlas.get(frameName);

                tempAtlasClipRect = FlxRect.get(
                    Math.min(tempAtlasPoint.x, 0),
                    Math.min(tempAtlasPoint.y, 0),
                    frameWidth + Math.max(tempAtlasPoint.x, 0),
                    frameHeight + Math.max(tempAtlasPoint.y, 0)
                );
            }else {
                tempAtlasClipRect = FlxRect.get(0, 0, 0, 0);
            }

            if(clipRect != null) {
                tempClipRect = clipRect;
            }else {
                tempClipRect = FlxRect.get(0, 0, 0, 0);
            }

            completeRect = FlxRect.get(
                tempAtlasClipRect.x + tempClipRect.x,
                tempAtlasClipRect.y + tempClipRect.y,
                tempAtlasClipRect.width + tempClipRect.width,
                tempAtlasClipRect.height + tempClipRect.height
            );

            tempAtlasClipRect = FlxDestroyUtil.put(tempAtlasClipRect);
        }

        return completeRect;
    }

    override function destroy() {
        FlxG.bitmap.remove(graphics);
        graphics = FlxDestroyUtil.destroy(graphics);

        defaultCompiler = null;
        completeCallback = null;

        super.destroy();

        if(__clippingPointAtlas != null) {
            for(k in __clippingPointAtlas.keys()) {
                var rect:FlxPoint = __clippingPointAtlas.get(k);

                if(rect != null) {
                    rect.put();
                    rect = null;
                    __clippingPointAtlas.remove(k);
                }
            }

            __clippingPointAtlas.clear();
        }

        if(__animationRectangle != null) {
            for(k in __animationRectangle.keys()) {
                var rect:FlxRect = __animationRectangle.get(k);

                if(rect != null) {
                    rect.put();
                    rect = null;
                    __animationRectangle.remove(k);
                }
            }

            __animationRectangle.clear();
        }

        __clippingPointAtlas = null;
        __animationRectangle = null;
    }
}
