package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import haxe.ds.StringMap;
#if lime
import lime.system.ThreadPool;
#end
import lime.utils.Assets;
import openfl.display.BitmapData;
import openfl.display3D.Context3DTextureFormat;
import openfl.display3D.textures.RectangleTexture;
import openfl.media.Sound;
import openfl.system.System;
import openfl.utils.Assets as OpenFlAssets;
import openfl.utils.ByteArray;
#if sys
import sys.thread.Thread;
#end

import SaveData.SaveType;

//Basically a class like Path
class Cache {
    @:noCompletion private static var theseAssets:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
    @:noCompletion private static var gpuReady:StringMap<Bool> = new StringMap<Bool>();
    @:noCompletion private static var pendingGPU:Array<String> = [];
    @:noCompletion private static var pendingGPUSet:StringMap<Bool> = new StringMap<Bool>();
#if sys
    static var mainThread:Thread = null;
#end

    static public function cacheListedFormat(path:String):Void {
        switch(path.split('.')[1]) {
            case "png":
                cacheAssetDirectly(path);
            case Paths.SOUND_EXT:
                OpenFlAssets.getSound(path, true);
        }
    }

    static function cacheAssetDirectly(path:String):Void {
        if(getAssetDirectly(path) != null) {
            return;
        }

        if(!OpenFlAssets.exists(path, IMAGE)) {
            trace("Warning: could not locate asset - " + path);
            return;
        }

        var bitmap:BitmapData = OpenFlAssets.getBitmapData(path);

        if(bitmap == null) {
            return;
        }

        var graphics:FlxGraphic = FlxGraphic.fromBitmapData(bitmap, false, path);
        graphics.persist = true;
        graphics.destroyOnNoUse = false;
        theseAssets.set(path, graphics);

        if(SaveData.getData(SaveType.GPU_CACHE)) {
            if(shouldUseGPUCache()) {
                promoteGraphicToGPU(path, graphics);
            } else {
                queueGPUUpload(path);
            }
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
				theseAssets.remove(path);
				gpuReady.remove(path);
				removePendingEntry(path);

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
                processPendingGPUUploads();
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
                processPendingGPUUploads();
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
                gpuReady.remove(key);
                removePendingEntry(key);

				graphic.persist = false;
				graphic.destroyOnNoUse = true;
				graphic.destroy();
			}
		}

        pendingGPU = [];
        pendingGPUSet = new StringMap<Bool>();
        gpuReady = new StringMap<Bool>();

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

	static inline function shouldUseGPUCache():Bool {
	    return SaveData.getData(SaveType.GPU_CACHE) && isGPUContextReady() && isOnMainThread();
	}

    static function isGPUContextReady():Bool {
        if(FlxG.stage == null) {
            return false;
        }

        #if lime
        if(!ThreadPool.isMainThread()) {
            return false;
        }
        #end

        try {
            return FlxG.stage.context3D != null;
        } catch(_:Dynamic) {
            return false;
        }
    }

    static inline function isOnMainThread():Bool {
#if sys
        if(mainThread == null) {
            return false;
        }

        return Thread.current() == mainThread;
#else
        return true;
#end
    }

    public static function processPendingGPUUploads():Void {
#if sys
        if(mainThread == null) {
            mainThread = Thread.current();
        }
#end

        if(!SaveData.getData(SaveType.GPU_CACHE)) {
            pendingGPU = [];
            pendingGPUSet = new StringMap<Bool>();
            return;
        }

        if(!isGPUContextReady()) {
            return;
        }

        var index = 0;
        while(index < pendingGPU.length) {
            var path = pendingGPU[index];
            var graphic = theseAssets.get(path);

            if(graphic != null && promoteGraphicToGPU(path, graphic)) {
                continue;
            }

            index++;
        }
    }

	static function queueGPUUpload(path:String):Void {
		if(pendingGPUSet.exists(path)) {
			return;
		}

		pendingGPU.push(path);
		pendingGPUSet.set(path, true);
	}

	static function removePendingEntry(path:String):Void {
		if(!pendingGPUSet.exists(path)) {
			return;
		}

		for(i in 0...pendingGPU.length) {
			if(pendingGPU[i] == path) {
				pendingGPU.splice(i, 1);
				break;
			}
		}

		pendingGPUSet.remove(path);
	}

	static function promoteGraphicToGPU(path:String, graphic:FlxGraphic):Bool {
		if(graphic == null) {
			return false;
		}

		if(gpuReady.exists(path)) {
			removePendingEntry(path);
			return true;
		}

        var bitmap:BitmapData = graphic.bitmap;

        if(bitmap == null) {
            return false;
        }

        var gpuBitmap = uploadBitmapToGPU(bitmap);

        if(gpuBitmap == null) {
            return false;
        }

		graphic.bitmap = gpuBitmap;
		gpuReady.set(path, true);
		removePendingEntry(path);
		return true;
	}

    static function uploadBitmapToGPU(bitmap:BitmapData):BitmapData {
        var context = FlxG.stage != null ? FlxG.stage.context3D : null;

        if(context == null) {
            return null;
        }

        try {
            var texture:RectangleTexture = context.createRectangleTexture(bitmap.width, bitmap.height, Context3DTextureFormat.BGRA, true);
            texture.uploadFromBitmapData(bitmap);

            var gpuBitmap = BitmapData.fromTexture(texture);

            return gpuBitmap;
        } catch(error:Dynamic) {
            #if debug
            trace('GPU cache upload failed: ' + error);
            #end
        }

        return null;
    }
}
