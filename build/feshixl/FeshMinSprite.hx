package feshixl;

import SaveData.SaveType;
import flixel.system.FlxAssets.FlxGraphicAsset;

/*
 * I a simpler version of `FeshSprite`
 * @author Feeshy
*/
class FeshMinSprite extends flixel.FlxSprite {

    public function new(?X:Float = 0, ?Y:Float = 0, ?SimpleGraphic:FlxGraphicAsset) {
        super(X, Y, SimpleGraphic);

        antialiasing = SaveData.getData(SaveType.GRAPHICS);
    }

    public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		animation.play(AnimName, Force, Reversed, Frame);
	}
}
