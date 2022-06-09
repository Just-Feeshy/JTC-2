package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;

import openfl.Lib;
import openfl.display.BitmapData;
import openfl.display3D.textures.RectangleTexture;
import openfl.utils.ByteArray;

import lime.math.BGRA;

/**
* This was made to test features that could/aren't implemented to the mod yet.
* @author Feeshy
*/
class TestDevState extends HelperStates {
    var texture:RectangleTexture;
    var bytes:ByteArray;

    public function new(bytes:ByteArray) {
        this.bytes = bytes;

        super();
    }

    override function create() {
        super.create();

        var sprite = new FlxSprite();

        texture = Lib.current.stage.stage3Ds[0].context3D.createRectangleTexture(FlxG.width, FlxG.height, BGRA, true);
        texture.uploadFromByteArray(bytes, 0);
        sprite.loadGraphic(FlxGraphic.fromBitmapData(BitmapData.fromTexture(texture)));
        add(sprite);
    }

    override function destroy() {
        texture.dispose();
        texture = null;

        bytes.clear();
        bytes = null;

        super.destroy();
    }
}