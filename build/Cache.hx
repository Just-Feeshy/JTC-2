package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import openfl.display.BitmapData;
import openfl.media.Sound;
import openfl.utils.ByteArray;
import openfl.system.System;
import openfl.utils.Assets as OpenFlAssets;
import lime.utils.Assets;

//Basically a class like Path
class Cache {
    public static var permanentCache:Array<String> = new Array<String>();

    private static var theseAssets:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
    private static var theseSounds:Map<String, Sound> = new Map<String, Sound>();

    static public function cacheAsset(key:String, ?library:String = ""):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if(OpenFlAssets.exists(path, IMAGE)) {
            if(!theseAssets.exists(path)) {
                var graphics:FlxGraphic = FlxG.bitmap.add(path, false, path);
                graphics.persist = true;
                graphics.destroyOnNoUse = false;
                theseAssets.set(path, graphics);
            }
        }else {
            trace("Warning: could not locate asset - " + path);
        }
    }

    static public function cacheFromByteArray(name:String, bytes:ByteArray):Void {
        if(bytes == null)
            return;

        var graphics:FlxGraphic = FlxG.bitmap.add(BitmapData.fromBytes(bytes), false, name);
        graphics.persist = true;
        graphics.destroyOnNoUse = false;

        theseAssets.set(name, graphics);
    }

    static public function cacheSound(directory:String = "sounds", key:String, ?library:String = ""):Void {
        var path:String = Paths.getPath('$directory/$key.${Paths.SOUND_EXT}', SOUND, library);

        if(OpenFlAssets.exists(path, SOUND)) {
            if(!theseSounds.exists(path)) {
                theseSounds.set(path, Sound.fromFile(path));
            }else {
                trace("Warning: could not locate sound - " + path);
            }
        }
    }

    static public function getAsset(key:String, ?library:String = ""):FlxGraphic {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if (OpenFlAssets.exists(path, IMAGE)) {
            if(theseAssets.exists(path)) {
                //trace("Retrieved file: " + path);
                return theseAssets.get(path);
            }else {
                return null;
            }
        }

        return null;
    }

    static public function getSound(directory:String = "sounds", key:String, ?library:String = ""):Sound {
        var path:String = Paths.getPath('$directory/$key.${Paths.SOUND_EXT}', SOUND, library);

        if(OpenFlAssets.exists(path, SOUND)) {
            if(!theseSounds.exists(path)) {
                trace("Retrieved sound: " + path);
                return theseSounds.get(path);
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

            if (theseAssets.exists(key) && !permanentCache.contains(key)) {
                openfl.Assets.cache.removeBitmapData(key);
                FlxG.bitmap.removeKey(key);
                daBitmap.destroy();

                daBitmap = null;
            }
        }

        theseAssets.clear();
        openfl.Assets.cache.clear();
        System.gc();
    }

    static public function clearNoneCachedAssets() {
        /**
        * Use `@:privateAccess` to get keys cached.
        */

        @:privateAccess
		for (key in FlxG.bitmap._cache.keys()) {
            var daBitmap:FlxGraphic = FlxG.bitmap.get(key);
            
            if(daBitmap != null && !theseAssets.exists(key)) {
                openfl.Assets.cache.removeBitmapData(key);
                FlxG.bitmap.removeKey(key);
                daBitmap.destroy();

                daBitmap = null;
            }
        }
    }
}