package feshixl.ui;

import flixel.ui.FlxBar;
import flixel.util.FlxColor;

/**
* Whole point is to store the color of both sides of the bar.
*/
class FeshBar extends FlxBar {
    public var currentEmptyColor(default, null):FlxColor = 0;
    public var currentFilledColor(default, null):FlxColor = 0;

    public var showBorder(default, null):Bool = false;
    public var border(default, null):FlxColor = FlxColor.WHITE;

    public function new(x:Float = 0, y:Float = 0, ?direction:FlxBarFillDirection, width:Int = 100, height:Int = 10, ?parentRef:Dynamic, variable:String = "",
        min:Float = 0, max:Float = 100, showBorder:Bool = false) 
    {
        this.showBorder = showBorder;

        super(x, y, direction, width, height, parentRef, variable, min, max, showBorder);
    }

    override function createFilledBar(empty:FlxColor, fill:FlxColor, showBorder:Bool = false, border:FlxColor = FlxColor.WHITE):FlxBar {
        currentEmptyColor = empty;
        currentFilledColor = fill;

        this.showBorder = showBorder;
        this.border = border;

        return super.createFilledBar(empty, fill, showBorder, border);
    }
}