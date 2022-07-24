package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxSpriteGroup;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import openfl.display.BitmapData;

class HealthBar extends FlxSpriteGroup {
    public var emptyBar(default, null):FlxSprite;
    public var filledBar(default, null):FlxSprite;

    public var emptyColor(default, set):FlxColor = 0;
    public var filledColor(default, set):FlxColor = 0;

    public var barWidth(default, null):Int;
	public var barHeight(default, null):Int;

    @:isVar public var value(get, set):Float;

    public var percent(get, never):Int;

    public var min(default, null):Float;
    public var max(default, null):Float;
    public var range(default, null):Float;

    public var parent:Dynamic;
    public var parentVariable:String;

    public function new(x:Float, y:Float, width:Int = 100, height:Int = 10, ?parentRef:Dynamic, variable:String = "",
        min:Float = 0, max:Float = 100) {
        super(x, y);

        barWidth = width;
        barHeight = height;

        if(parentRef != null) {
            parent = parentRef;
            parentVariable = variable;
        }

        setRange(min, max);
        createNewBar();
    }

    public function createFilledBar(emptyColor, filledColor):HealthBar {
        this.emptyColor = emptyColor;
        this.filledColor = filledColor;

        return this;
    }

    public function createNewBar():Void {
        if(emptyBar != null && filledBar != null) {
            remove(emptyBar);
            remove(filledBar);
        }

        emptyBar = FlxDestroyUtil.destroy(emptyBar);
        filledBar = FlxDestroyUtil.destroy(filledBar);
        emptyBar = new FlxSprite();
        filledBar = new FlxSprite();

        var regularBarGraphic:FlxGraphic = FlxG.bitmap.add(new BitmapData(barWidth, barHeight, false, FlxColor.WHITE));

        emptyBar.frames = new FlxFramesCollection(regularBarGraphic);
        filledBar.frames = new FlxFramesCollection(regularBarGraphic);
        emptyBar.frames.addAtlasFrame(FlxRect.get(0, 0, barWidth, barHeight), FlxPoint.get(barWidth, barHeight), FlxPoint.get(), "filled");
        filledBar.frames.addAtlasFrame(FlxRect.get(0, 0, barWidth, barHeight), FlxPoint.get(barWidth, barHeight), FlxPoint.get(), "filled");
        
        emptyBar.color = emptyColor;
        filledBar.color = filledColor;

        add(emptyBar);
        add(filledBar);
    }

    public function attachGraphics(graphic:FlxGraphic):Void {
        if(emptyBar != null && filledBar != null) {
            remove(emptyBar);
            remove(filledBar);
        }

        emptyBar = FlxDestroyUtil.destroy(emptyBar);
        filledBar = FlxDestroyUtil.destroy(filledBar);
        emptyBar = new FlxSprite();
        filledBar = new FlxSprite();

        barWidth = graphic.width;
        barHeight = graphic.height;

        emptyBar.frames = new FlxFramesCollection(graphic);
        filledBar.frames = new FlxFramesCollection(graphic);
        emptyBar.frames.addAtlasFrame(FlxRect.get(0, 0, barWidth, barHeight), FlxPoint.get(barWidth, barHeight), FlxPoint.get(), "filled");
        filledBar.frames.addAtlasFrame(FlxRect.get(0, 0, barWidth, barHeight), FlxPoint.get(barWidth, barHeight), FlxPoint.get(), "filled");

        emptyBar.color = emptyColor;
        filledBar.color = filledColor;

        add(emptyBar);
        add(filledBar);
    }

    public function setRange(min:Float, max:Float):Void {
        if (max <= min) {
            throw "HealthBar: max cannot be less than or equal to min";
            return;
        }

        this.min = min;
		this.max = max;
		this.range = max - min;
    }

    public function updateValueFromParent():Void {
        value = Reflect.field(parent, parentVariable);
    }

    function get_percent():Int {
        return Std.int((value / range) * 100);
    }

    function get_value():Float {
        #if neko
        if (value == null) {
            value = min;
        }
        #end
    
        return value;
    }

    function set_value(newValue:Float):Float {
        if(emptyBar != null && filledBar != null) {
            emptyBar.frames.frames[0].frame.width = barWidth - (barWidth * (value / range));
            filledBar.frames.frames[0].frame.width = barWidth * (value / range);

            if(barWidth - (barWidth * (value / range)) > 0) {
                emptyBar.visible = true;
            }else {
                emptyBar.visible = false;
            }

            if(barWidth * (value / range) > 0) {
                filledBar.visible = true;
            }else {
                filledBar.visible = false;
            }

            emptyBar.frame = emptyBar.frames.frames[0];
            filledBar.frame = filledBar.frames.frames[0];
            filledBar.frame.flipX = true;

            filledBar.x = x + (barWidth - (barWidth * (value / range)));
        }

        return value = Math.max(min, Math.min(newValue, max));
    }

    function set_emptyColor(color:FlxColor):FlxColor {
        if(emptyBar != null) {
            emptyBar.color = color;
        }

        return emptyColor = color;
    }

    function set_filledColor(color:FlxColor):FlxColor {
        if(filledBar != null) {
            filledBar.color = color;
        }
        
        return filledColor = color;
    }

    override function update(elapsed:Float) {
        if (parent != null) {
            if (Reflect.getProperty(parent, parentVariable) != value) {
                updateValueFromParent();
            }
        }

        super.update(elapsed);
    }
}