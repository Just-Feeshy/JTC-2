package;

import flixel.FlxSprite;
import flixel.util.FlxColor;

class CreditSprites extends FlxSprite {
    public var redFloat(get, set):Float;
	public var blueFloat(get, set):Float;
	public var greenFloat(get, set):Float;
	public var alphaFloat(get, set):Float;

    public function new() {
        super();
    }

    function set_redFloat(Value:Float):Float {
        var newColor = color;
        newColor.redFloat = Value;
        color = newColor;
        return Value;
    }

    function set_blueFloat(Value:Float):Float {
        var newColor = color;
        newColor.blueFloat = Value;
        color = newColor;
        return Value;
    }

    function set_greenFloat(Value:Float):Float {
        var newColor = color;
        newColor.greenFloat = Value;
        color = newColor;
        return Value;
    }

    function set_alphaFloat(Value:Float):Float {
        var newColor = color;
        newColor.alphaFloat = Value;
        color = newColor;
        return Value;
    }

    function get_redFloat():Float {
        return color.redFloat;
    }

    function get_blueFloat():Float {
        return color.blueFloat;
    }

    function get_greenFloat():Float {
        return color.greenFloat;
    }

    function get_alphaFloat():Float {
        return color.alphaFloat;
    }
}