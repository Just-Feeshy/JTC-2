package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.addons.transition.FlxTransitionableState;

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

        if (OpenFlAssets.exists(path, IMAGE)) {
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

    static public function cacheSound(key:String, ?library:String = ""):Void {
        var soundPath:String = Paths.sound(key, library);

        if(soundPath != null) {
            if(!theseSounds.exists(soundPath)) {
                theseSounds.set(soundPath, Sound.fromFile(soundPath));
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

    static public function getSound(key:String, ?library:String = ""):Sound {
        var soundPath:String = Paths.sound(key, library);

        if(soundPath != null) {
            if(theseSounds.exists(soundPath)) {
                trace("Retrieved sound: " + soundPath);
                return theseSounds.get(soundPath);
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
                trace("Remove cached file: " + key);

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
                FlxG.bitmap.removeKey(key);
                daBitmap.destroy();

                daBitmap = null;
            }
        }

        theseAssets.clear();
        openfl.Assets.cache.clear();
        System.gc();
    }
}