package betterShit;

import flixel.FlxCamera;
import flixel.util.FlxDestroyUtil;
import flixel.math.FlxPoint;
import flixel.FlxG;
import openfl.filters.BitmapFilter;

class BetterCams extends FlxCamera {

    public var getFilters(get, never):Array<BitmapFilter>;

    private var lockedFilters:Array<BitmapFilter>;
    private var wastefulFilters:Array<BitmapFilter>;

    public var betterFiltersEnabled:Bool = true;

	public var engineX(default, set):Float = 0;
	public var engineY(default, set):Float = 0;

    public var engineAngle(default, set):Float = 0;

    public function new() {
        lockedFilters = new Array<BitmapFilter>();

        filtersEnabled = false;

        super();
    }

    public function setTrashFilters(trashFilters:Array<BitmapFilter>) {
        wastefulFilters = trashFilters;
    }
    
    public function lockFilter(filters:BitmapFilter):Void {
        lockedFilters.push(filters);
        setFilters(getFilters);
    }

    public function eraseFilters() {
        lockedFilters = [];
        wastefulFilters = [];
        setFilters([]);
    }

    function get_getFilters():Array<BitmapFilter> {
        var daFilters:Array<BitmapFilter> = _filters;

        for(i in 0...lockedFilters.length)
            if(!daFilters.contains(lockedFilters[i]))
                daFilters.push(lockedFilters[i]);

        for(i in 0...wastefulFilters.length)
            if(!daFilters.contains(wastefulFilters[i]))
                daFilters.push(wastefulFilters[i]);

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

    /**
	*Reuse and recycle! - Feeshy
	**/
	function set_engineAngle(Angle:Float):Float {
		this.engineAngle = Angle;
		set_angle(this.angle);
		return Angle;
	}

    override function set_angle(Angle:Float):Float {
        angle = Angle;
        flashSprite.rotation = engineAngle + Angle;
        return Angle;
    }

    override public function update(elapsed:Float):Void {
        filtersEnabled = false;

        super.update(elapsed);

        flashSprite.filters = betterFiltersEnabled ? getFilters : null;
    }

    override public function destroy():Void {
        super.destroy();

        lockedFilters.splice(0, lockedFilters.length);
        lockedFilters = null;
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