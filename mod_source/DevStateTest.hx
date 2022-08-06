package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.graphics.frames.FlxFramesCollection;
import openfl.display.BitmapData;
import openfl.geom.Point;
import haxe.io.Bytes;

#if json2object
import json2object.JsonParser;
#end

class DevStateTest extends HelperStates {
    public function new() {
        super();
    }

    override function create():Void {
        testJSON();

        super.create();
    }

    #if json2object
    function testJSON():Void {
        var parser:JsonParser<Bytes> = new JsonParser<Bytes>();
    }
    #end
}