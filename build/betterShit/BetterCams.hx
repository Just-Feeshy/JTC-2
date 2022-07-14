package betterShit;

import flixel.FlxCamera;
import flixel.util.FlxDestroyUtil;
import flixel.math.FlxPoint;
import flixel.FlxG;
import openfl.filters.BitmapFilter;

class BetterCams extends FlxCamera {

    private var lockedFilters:Array<BitmapFilter>;
    private var wastefulFilters:Array<BitmapFilter>;

    public var betterFiltersEnabled:Bool = true;

	public var engineX(default, set):Float = 0;
	public var engineY(default, set):Float = 0;

    public var engineAngle(default, set):Float = 0;

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