package play;

import FlixelCompat;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.math.FlxMath;
import openfl.filters.BitmapFilter;
import openfl.filters.ShaderFilter;

@:access(flixel.FlxCamera)
class PlayCamera extends FlxCamera
{
    private var baseFilters:Array<BitmapFilter> = [];
    private var trashFilters:Array<BitmapFilter> = [];

    public var engineX(default, set):Float = 0;
    public var engineY(default, set):Float = 0;
    public var engineAngle(default, set):Float = 0;
    public var engineAlpha(default, set):Float = 1;

    public function new()
    {
        super();
        filtersEnabled = true;
        rebuildFilters();
    }

    public function setTrashFilters(filters:Array<BitmapFilter>):Void
    {
        trashFilters = filters != null ? filters.concat([]) : [];
        rebuildFilters();
    }

    public function lockFilter(filter:BitmapFilter):Void
    {
        if (filter != null)
        {
            trashFilters.push(filter);
            rebuildFilters();
        }
    }

    public function eraseFilters():Void
    {
        baseFilters = [];
        trashFilters = [];
        rebuildFilters();
    }

    public function collectBaseFilters():Array<BitmapFilter>
    {
        return baseFilters != null ? baseFilters.concat([]) : [];
    }

    public function collectFilters():Array<BitmapFilter>
    {
        return filters != null ? filters.concat([]) : [];
    }

    public function setFilters(filters:Array<BitmapFilter>):Void
    {
        baseFilters = filters != null ? filters.concat([]) : [];
        rebuildFilters();
    }

    private function rebuildFilters():Void
    {
        var filters:Array<BitmapFilter> = [];

        if (baseFilters != null)
        {
            filters = filters.concat(baseFilters);
        }

        if (trashFilters != null)
        {
            filters = filters.concat(trashFilters);
        }

        FlixelCompat.setCameraFilters(this, filters);
    }

    private function set_engineX(value:Float):Float
    {
        engineX = value;
        updateFlashSpritePosition();
        return value;
    }

    private function set_engineY(value:Float):Float
    {
        engineY = value;
        updateFlashSpritePosition();
        return value;
    }

    private function set_engineAngle(value:Float):Float
    {
        engineAngle = value;
        set_angle(angle);
        return value;
    }

    private function set_engineAlpha(value:Float):Float
    {
        engineAlpha = value;
        set_alpha(alpha);
        return value;
    }

    override function set_angle(value:Float):Float
    {
        angle = value;

        if (flashSprite != null)
        {
            flashSprite.rotation = engineAngle + value;
        }

        return value;
    }

    override function set_alpha(value:Float):Float
    {
        alpha = FlxMath.bound(value * engineAlpha, 0, 1);

        if (FlxG.renderBlit)
        {
            _flashBitmap.alpha = alpha;
        }
        else
        {
            canvas.alpha = alpha;
        }

        return alpha;
    }

    public function clearRenderState():Void
    {
        clearDrawStack();

        if (canvas != null)
        {
            canvas.graphics.clear();
        }
    }

    public function invalidateFilters():Void
    {
        var activeFilters:Array<BitmapFilter> = filters != null ? filters : [];

        for (filter in activeFilters)
        {
            if (filter != null && Std.isOfType(filter, ShaderFilter))
            {
                (cast filter:ShaderFilter).invalidate();
            }
        }

        if (flashSprite != null)
        {
            @:privateAccess flashSprite.__setRenderDirty();
        }
    }

    override public function destroy():Void
    {
        clearRenderState();
        super.destroy();

        if (trashFilters != null)
        {
            trashFilters.splice(0, trashFilters.length);
        }
        trashFilters = null;

        if (baseFilters != null)
        {
            baseFilters.splice(0, baseFilters.length);
        }
        baseFilters = null;
    }

    override function updateFlashSpritePosition():Void
    {
        if (flashSprite != null)
        {
            flashSprite.x = (x + engineX) * FlxG.scaleMode.scale.x + _flashOffset.x;
            flashSprite.y = (y + engineY) * FlxG.scaleMode.scale.y + _flashOffset.y;
        }
    }
}
