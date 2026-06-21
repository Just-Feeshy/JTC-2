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

		var dataExtension:String = extension == "json" ? "json" : "xml";

		// Resolve against the shared library first (mod_assets + assets/shared, which keep sprites in a
		// `cache/` subfolder). If that misses, fall back to the preload library: base-game sprites are
		// embedded under assets/preload/images at the image root (no `cache/` subfolder), so they need
		// `cache = false`. Without this fallback the character creator can't render any character whose
		// only sprite lives in preload (e.g. the stock FNF characters).
		var library:String = "shared";
		var useCache:Bool = true;
		var imagePath:String = Paths.getPath('images/$basePath.png', IMAGE, library);
		var dataPath:String = Paths.getPath('images/$basePath.$dataExtension', TEXT, library);

		if(!Paths.assetExists(imagePath, IMAGE) || !Paths.assetExists(dataPath, TEXT)) {
			library = "preload";
			useCache = false;
			imagePath = Paths.getPath('images/$basePath.png', IMAGE, library);
			dataPath = Paths.getPath('images/$basePath.$dataExtension', TEXT, library);
		}

		if(!Paths.assetExists(imagePath, IMAGE) || !Paths.assetExists(dataPath, TEXT)) {
			return null;
		}

		return switch(extension) {
			case "json":
				Paths.getPackerAtlas(basePath, library, useCache);
			default:
				Paths.getSparrowAtlas(basePath, library, useCache);
		};
	}
}
