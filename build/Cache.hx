package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import openfl.display.BitmapData;
import openfl.display3D.textures.Texture;
import openfl.media.Sound;
import openfl.utils.ByteArray;
import openfl.system.System;
import openfl.display3D.textures.RectangleTexture;
import openfl.utils.Assets as OpenFlAssets;
import lime.utils.Assets;

import SaveData.SaveType;

//Basically a class like Path
class Cache {
    @:noCompletion private static var theseAssets:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

    static public function cacheListedFormat(path:String):Void {
        switch(path.split('.')[1]) {
            case "png":
                cacheAssetDirectly(path);
            case Paths.SOUND_EXT:
                OpenFlAssets.getSound(path, true);
        }
    }

    static function cacheAssetDirectly(path:String):Void {
        if(getAssetDirectly(path) == null) {
				var bitmap = OpenFlAssets.getBitmapData(path);

				if(SaveData.getData(SaveType.GPU_CACHE)) {
				    var texture:RectangleTexture = FlxG.stage.context3D.createRectangleTexture(bitmap.width, bitmap.height, BGRA, true);
					texture.uploadFromBitmapData(bitmap);
					bitmap.image.data = null;
					bitmap.dispose();
					bitmap.disposeImage();
					bitmap = BitmapData.fromTexture(texture);
				}

				var graphics:FlxGraphic = FlxGraphic.fromBitmapData(bitmap, false, path);
				graphics.persist = true;
				graphics.destroyOnNoUse = false;
				theseAssets.set(path, graphics);
        }else if(!OpenFlAssets.exists(path, IMAGE)) {
            trace("Warning: could not locate asset - " + path);
        }
    }

    static public function cacheAsset(key:String, ?library:String = "", directly:Bool = false):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);
        cacheAssetDirectly(path);
    }

    static public function cacheRemove(key:String, ?library:String = ""):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if(OpenFlAssets.exists(path, IMAGE)) {

            /**
            * Use `@:privateAccess` to get keys cached.
            */

            @:privateAccess
            if(theseAssets.exists(path) && openfl.Assets.cache.hasBitmapData(key)) {
                var daBitmap:FlxGraphic = FlxG.bitmap.get(key);
                theseAssets.remove(key);

                openfl.Assets.cache.removeBitmapData(key);
                FlxG.bitmap.removeKey(key);
                daBitmap.destroy();

                daBitmap = null;
            }
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

    static public function getAssetDirectly(path:String):FlxGraphic {
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

    static public function clear():Void {
        /**
        * Use `@:privateAccess` to get keys cached.
        */

		for(key in theseAssets.keys()) {
		    var graphic = theseAssets.get(key);

			@:privateAccess if(graphic != null) {
				FlxG.bitmap._cache.remove(key);
				openfl.Assets.cache.removeBitmapData(key);
				theseAssets.remove(key);

				graphic.persist = false;
				graphic.destroyOnNoUse = true;
				graphic.destroy();
			}
		}

        System.gc();
    }

    static public function clearNoneCachedAssets() {
        /**
        * Use `@:privateAccess` to get keys cached.
        */

        @:privateAccess
		for(key in FlxG.bitmap._cache.keys()) {
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
