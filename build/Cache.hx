package;

import flixel.FlxG;
import openfl.display.BitmapData;
import flixel.graphics.FlxGraphic;
import openfl.utils.Assets as OpenFlAssets;

//Basically a class like Path
class Cache {
    private static var theseAssets:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

    static public function cacheAsset(key:String, ?library:String = ""):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if (OpenFlAssets.exists(path, IMAGE)) {
            if(!theseAssets.exists(path)) {
                var graphics:FlxGraphic = FlxG.bitmap.add(path, false, path);
                graphics.persist = true;
                trace("Retrieved: " + path);
                theseAssets.set(path, graphics);
            }
        }else {
            trace("Warning: could not locate asset - " + path);
        }
    }

    static public function getAsset(key:String, ?library:String = ""):FlxGraphic {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if (OpenFlAssets.exists(path, IMAGE)) {
            if(theseAssets.exists(path)) {
                trace("Retrieved file: " + path);
                return theseAssets.get(path);
            }else {
                return null;
            }
        }

        return null;
    }

    static public function clear():Void {
        /**
        * Use `@:privateAccess` to get keys cached.
        */

        @:privateAccess
		for (key in FlxG.bitmap._cache.keys()) {
            var daBitmap:FlxGraphic = FlxG.bitmap.get(key);

            if (theseAssets.exists(key)) {
                trace("Remove cached file: " + key);

                FlxG.bitmap.removeKey(key);
                daBitmap.destroy();

                daBitmap = null;
            }
        }
    }

    static public function clearALLassets() {
        @:privateAccess
		for (key in FlxG.bitmap._cache.keys()) {
            var daBitmap:FlxGraphic = FlxG.bitmap.get(key);

            if(daBitmap != null && !theseAssets.exists(key)) {
                FlxG.bitmap.removeKey(key);
                daBitmap.destroy();

                daBitmap = null;
            }
        }

        openfl.Assets.cache.clear("songs");
    }
}