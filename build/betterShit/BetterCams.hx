package betterShit;

import flixel.FlxG;
import flixel.FlxCamera;
import flixel.system.FlxAssets.FlxShader;
import flixel.graphics.frames.FlxFrame;
import flixel.util.FlxDestroyUtil;
import flixel.math.FlxPoint;
import flixel.math.FlxMatrix;
import flixel.math.FlxMath;
import openfl.filters.BitmapFilter;
import openfl.display.BlendMode;
import openfl.display.BitmapData;
import openfl.geom.ColorTransform;
import openfl.geom.Rectangle;
import openfl.geom.Point;

using flixel.util.FlxColorTransformUtil;

class BetterCams extends FlxCamera {

    private var lockedFilters:Array<BitmapFilter>;
    private var wastefulFilters:Array<BitmapFilter>;

    public var betterFiltersEnabled:Bool = true;

	public var engineX(default, set):Float = 0;
	public var engineY(default, set):Float = 0;

    public var engineAngle(default, set):Float = 0;
    public var engineAlpha(default, set):Float = 1;

    public function new() {
        _filters = [];

        lockedFilters = [];
        wastefulFilters = [];

        filtersEnabled = false;

        super();
    }

    public function setTrashFilters(trashFilters:Array<BitmapFilter>) {
        wastefulFilters = trashFilters;
    }
    
    public function lockFilter(filters:BitmapFilter):Void {
        lockedFilters.push(filters);
    }

    public function eraseFilters() {
        lockedFilters = [];
        wastefulFilters = [];
        setFilters([]);
    }

    function getFilters():Array<BitmapFilter> {
        var daFilters:Array<BitmapFilter> = [];

        daFilters = _filters.concat(lockedFilters);
        daFilters = daFilters.concat(wastefulFilters);

        return daFilters;
    }

    function set_engineX(x:Float):Float {
		this.engineX = x;
        updateFlashSpritePosition();
        return engineX;
	}

	function set_engineY(y:Float):Float {
		this.engineY = y;
        updateFlashSpritePosition();
        return engineY;
	}

    override function drawPixels(?frame:FlxFrame, ?pixels:BitmapData, matrix:FlxMatrix, ?transform:ColorTransform, ?blend:BlendMode, ?smoothing:Bool = false,
        ?shader:FlxShader):Void {
        if (FlxG.renderBlit)
        {
            _helperMatrix.copyFrom(matrix);

            if (_useBlitMatrix)
            {
                _helperMatrix.concat(_blitMatrix);
                buffer.draw(pixels, _helperMatrix, null, null, null, (smoothing || antialiasing));
            }
            else
            {
                _helperMatrix.translate(-viewOffsetX, -viewOffsetY);
                buffer.draw(pixels, _helperMatrix, null, blend, null, (smoothing || antialiasing));
            }
        }
        else
        {
            var isColored = (transform != null && transform.hasRGBMultipliers());
            var hasColorOffsets:Bool = (transform != null && transform.hasRGBAOffsets());

            #if FLX_RENDER_TRIANGLE
            var drawItem:FlxDrawTrianglesItem = startTrianglesBatch(frame.parent, smoothing, isColored, blend);
            #else
            var drawItem = startQuadBatch(frame.parent, isColored, hasColorOffsets, blend, smoothing, shader);
            #end
            drawItem.addQuad(frame, matrix, transform);
        }

        return;
    }

    override function copyPixels(?frame:FlxFrame, ?pixels:BitmapData, ?sourceRect:Rectangle, destPoint:Point, ?transform:ColorTransform, ?blend:BlendMode,
        ?smoothing:Bool = false, ?shader:FlxShader):Void {
        if (FlxG.renderBlit)
        {
            if (pixels != null)
            {
                if (_useBlitMatrix)
                {
                    _helperMatrix.identity();
                    _helperMatrix.translate(destPoint.x, destPoint.y);
                    _helperMatrix.concat(_blitMatrix);
                    buffer.draw(pixels, _helperMatrix, null, null, null, (smoothing || antialiasing));
                }
                else
                {
                    _helperPoint.x = destPoint.x - Std.int(viewOffsetX);
                    _helperPoint.y = destPoint.y - Std.int(viewOffsetY);
                    buffer.copyPixels(pixels, sourceRect, _helperPoint, null, null, true);
                }
            }
            else if (frame != null)
            {
                // TODO: fix this case for zoom less than initial zoom...
                frame.paint(buffer, destPoint, true);
            }
        }
        else
        {
            _helperMatrix.identity();
            _helperMatrix.translate(destPoint.x + frame.offset.x, destPoint.y + frame.offset.y);

            var isColored = (transform != null && transform.hasRGBMultipliers());
            var hasColorOffsets:Bool = (transform != null && transform.hasRGBAOffsets());

            #if !FLX_RENDER_TRIANGLE
            var drawItem = startQuadBatch(frame.parent, isColored, hasColorOffsets, blend, smoothing, shader);
            #else
            var drawItem:FlxDrawTrianglesItem = startTrianglesBatch(frame.parent, smoothing, isColored, blend);
            #end
            drawItem.addQuad(frame, _helperMatrix, transform);
        }

        return;
    }

    /**
	*Reuse and recycle! - Feeshy
	*/

	function set_engineAngle(Angle:Float):Float {
		this.engineAngle = Angle;
		set_angle(this.angle);
		return Angle;
	}

    function set_engineAlpha(Alpha:Float):Float {
        this.engineAlpha = Alpha;
        set_alpha(this.alpha);
        return Alpha;
    }

    override function set_angle(Angle:Float):Float {
        angle = Angle;
        flashSprite.rotation = engineAngle + Angle;
        return Angle;
    }

    override function set_alpha(Alpha:Float):Float {
        alpha = FlxMath.bound(Alpha * engineAngle, 0, 1);

        if (FlxG.renderBlit) {
            _flashBitmap.alpha = alpha;
        }else {
            canvas.alpha = alpha;
        }

        return alpha;
    }

    override public function update(elapsed:Float):Void {
        filtersEnabled = false;

        super.update(elapsed);

        flashSprite.filters = betterFiltersEnabled ? getFilters() : null;
    }

    override public function destroy():Void {
        super.destroy();

        if(lockedFilters != null)
            lockedFilters.splice(0, lockedFilters.length);

        lockedFilters = null;

        if(wastefulFilters != null)
            wastefulFilters.splice(0, wastefulFilters.length);

        wastefulFilters = null;
    }

    override function updateFlashSpritePosition():Void {
        if (flashSprite != null) {
            flashSprite.x = (x + engineX) * FlxG.scaleMode.scale.x + _flashOffset.x;
            flashSprite.y = (y + engineY) * FlxG.scaleMode.scale.y + _flashOffset.y;
        }

        return;

        super.updateFlashSpritePosition();
    }
}