package;

import flixel.FlxG;
import openfl.display.BitmapData;
import flixel.graphics.FlxGraphic;
import openfl.utils.Assets as OpenFlAssets;

//Basically a class like Path
class Cache {
    private static var theseAssets:Map<String, FlxGraphics> = new Map<String, FlxGraphics>();

    static public function cacheAsset(key:String, ?library:String = ""):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if (OpenFlAssets.exists(path, IMAGE)) {
            if(!theseAssets.exists(path)) {
                var graphics:FlxGraphic = FlxG.bitmap.add(path, false, path);
                theseAssets.set(path, graphics);
            }
        }else {
            trace("Warning: could not locate asset - " + path);
        }
    }

    static public function getAsset(key:String):FlxGraphics {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if (OpenFlAssets.exists(path, IMAGE)) {
            if(theseAssets.exists(path)) {
                return currentTrackedAssets.get(modKey);
            }else {
                trace("Warning: Could not locate asset in the cache files - " + path);
                return path;
            }
        }

        throw "Error: could not locate asset - " + path;
        return null;
    }

    static public function clear():Void {
        /**
        * Use `@:privateAccess` to get keys cached.
        */

        @:privateAccess
		for (key in FlxG.bitmap._cache.keys()) {
            var daBitmap:FlxGraphic = FlxG.bitmap.get(key);

            if (daBitmap != null && !theseAssets.exists(path)) {
                FlxG.bitmap.removeKey();
                daBitmap.destroy();

                daBitmap = null;
            }
        }
    }
}