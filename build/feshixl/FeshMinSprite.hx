package feshixl;

import SaveData.SaveType;
import flixel.system.FlxAssets.FlxGraphicAsset;
import flixel.graphics.frames.FlxFramesCollection;

using StringTools;

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

	public static function loadFrameCollection(file:String):FlxFramesCollection {
		var trimmedFile:String = file != null ? file.trim() : "";
		var extension:String = "";
		var basePath:String = trimmedFile;
		var extensionIndex:Int = trimmedFile.lastIndexOf(".");

		if(extensionIndex >= 0) {
			basePath = trimmedFile.substr(0, extensionIndex);
			extension = trimmedFile.substr(extensionIndex + 1).toLowerCase();
		}

		var imagePath:String = Paths.getPath('images/$basePath.png', IMAGE, "shared");
		var dataPath:String = Paths.getPath('images/$basePath.${extension == "json" ? "json" : "xml"}', extension == "json" ? TEXT : TEXT, "shared");

		if(!Paths.assetExists(imagePath, IMAGE) || !Paths.assetExists(dataPath, TEXT)) {
			return null;
		}

		return switch(extension) {
			case "json":
				Paths.getPackerAtlas(basePath, "shared", true);
			default:
				Paths.getSparrowAtlas(basePath, "shared", true);
		};
	}
}
