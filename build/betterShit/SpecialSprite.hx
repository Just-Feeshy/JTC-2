package betterShit;

import openfl.display.BitmapData;

/**
* Basically just FlxSprite, but with a lot more xustomizability.
*/
class SpecialSprite extends EditorSprite {
    var glowBitmap

    public function new(?X:Float = 0, ?Y:Float = 0, ?SimpleGraphic:FlxGraphicAsset) {
        super(X, Y, SimpleGraphic);
    }
}