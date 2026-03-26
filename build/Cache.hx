package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import openfl.display.BitmapData;
import openfl.media.Sound;
import openfl.utils.ByteArray;
import openfl.utils.Assets as OpenFlAssets;
import lime.utils.Assets;
import haxe.Json;

import SaveData.SaveType;

using StringTools;

//Basically a class like Path
class Cache {
    @:noCompletion private static var theseAssets:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
    @:noCompletion private static var permanentAssets:Map<String, Bool> = new Map<String, Bool>();

    static inline function isFreeplayAssetKey(key:String):Bool {
        if(key == null) {
            return false;
        }

        var normalized = key.toLowerCase();
        return normalized.indexOf("freeplay") >= 0 || normalized.indexOf("graffiti") >= 0;
    }

    static inline function shouldUseGPUCache(allowGPUCache:Bool):Bool {
        return allowGPUCache
            && SaveData.getData(SaveType.GPU_CACHE)
            && FlxG.stage != null
            && FlxG.stage.context3D != null;
    }

    static function warmGraphicTexture(graphic:FlxGraphic):Void {
        if(graphic == null || graphic.bitmap == null || FlxG.stage == null || FlxG.stage.context3D == null) {
            return;
        }

        // Match upstream Funkin's approach: keep the bitmap readable,
        // but force a GPU upload so gameplay doesn't stall on first draw.
        var sprite:FlxSprite = new FlxSprite();
        sprite.loadGraphic(graphic);
        sprite.draw();
        graphic.bitmap.getTexture(FlxG.stage.context3D);
        sprite.destroy();
    }

    static public function cacheListedFormat(path:String, allowGPUCache:Bool = true):Void {
        var extensionIndex:Int = path.lastIndexOf(".");

        if(extensionIndex < 0 || extensionIndex >= path.length - 1) {
            return;
        }

        switch(path.substr(extensionIndex + 1).toLowerCase()) {
            case "png":
                if(Paths.assetExists(path, IMAGE)) {
                    cacheAssetDirectly(path, allowGPUCache);
                }
            case Paths.SOUND_EXT:
                if(Paths.assetExists(path, SOUND) || Paths.assetExists(path, MUSIC)) {
                    Paths.loadSoundAsset(path);
                }
        }
    }

    static function cacheAssetDirectly(path:String, allowGPUCache:Bool = true):Void {
        if(getAssetDirectly(path) == null) {
				var useGPUCache = shouldUseGPUCache(allowGPUCache);
				var bitmap = Paths.loadBitmap(path, !useGPUCache);

                if(bitmap == null) {
                    trace("Warning: could not locate asset - " + path);
                    return;
                }

				if(useGPUCache) {
					// Avoid leaving a second CPU-side copy alive in the OpenFL asset cache,
					// but keep the bitmap itself readable for atlas/frame math and color sampling.
					OpenFlAssets.cache.removeBitmapData(path);
				}else {
					// Keep CPU caching on a private bitmap copy so later atlas/frame mutations
					// don't alias the original asset bitmap returned by OpenFL.
					bitmap = bitmap.clone();
				}

				var graphics:FlxGraphic = FlxGraphic.fromBitmapData(bitmap, false, path);
				graphics.persist = true;
				graphics.destroyOnNoUse = false;
				theseAssets.set(path, graphics);

				if(useGPUCache) {
					warmGraphicTexture(graphics);
				}
        }else if(!Paths.assetExists(path, IMAGE)) {
            trace("Warning: could not locate asset - " + path);
        }
    }

    static public function cacheAsset(key:String, ?library:String = "", allowGPUCache:Bool = true):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);
        cacheAssetDirectly(path, allowGPUCache);
    }

    static public function cacheRemove(key:String, ?library:String = ""):Void {
        var path:String = Paths.getPath('images/$key.png', IMAGE, library);

        if(Paths.assetExists(path, IMAGE)) {

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
        cacheByteArrayInternal(name, bytes, false);
    }

    static public function cachePermanentFromByteArray(name:String, bytes:ByteArray):FlxGraphic {
        return cacheByteArrayInternal(name, bytes, true);
    }

    static function cacheByteArrayInternal(name:String, bytes:ByteArray, permanent:Bool):FlxGraphic {
        if(bytes == null)
            return null;

        if(theseAssets.exists(name)) {
            if(permanent) {
                permanentAssets.set(name, true);
            }

            return theseAssets.get(name);
        }

        var bitmap:BitmapData = BitmapData.fromBytes(bytes);

        if(bitmap == null) {
            return null;
        }

        var graphics:FlxGraphic = FlxG.bitmap.add(bitmap, false, name);
        graphics.persist = true;
        graphics.destroyOnNoUse = false;

        theseAssets.set(name, graphics);
        if(permanent) {
            permanentAssets.set(name, true);
        }

        if(shouldUseGPUCache(true)) {
            warmGraphicTexture(graphics);
        }

        return graphics;
    }

    static public function getAssetDirectly(path:String):FlxGraphic {
        if (Paths.assetExists(path, IMAGE)) {
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
            if(permanentAssets.exists(key)) {
                continue;
            }

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

        clearSongSoundCache();
        collectNow();
    }

    static public function collectNow():Void {
        MemoryUtil.collect(true);
        MemoryUtil.compact();
    }

    static public function clearSongSoundCache():Void {
        for(prefix in ["songs", "assets/music/", "shared:assets/shared/music/", "preload:assets/preload/music/"]) {
            OpenFlAssets.cache.clear(prefix);
        }
    }

    static public function clearFreeplay():Void {
        var keysToRemove:Array<String> = [];

        @:privateAccess
        for(key in FlxG.bitmap._cache.keys()) {
            if(!isFreeplayAssetKey(key)) {
                continue;
            }

            if(permanentAssets.exists(key)) {
                continue;
            }

            keysToRemove.push(key);
        }

        @:privateAccess
        for(key in keysToRemove) {
            var graphic:FlxGraphic = FlxG.bitmap.get(key);

            if(graphic != null) {
                graphic.persist = false;
                graphic.destroyOnNoUse = true;
                graphic.destroy();
            }

            FlxG.bitmap.removeKey(key);
            OpenFlAssets.cache.clear(key);
            theseAssets.remove(key);
        }

        collectNow();
    }

    static function resolveImagePathFromCacheEntry(entry:Dynamic):String {
        if(entry == null) {
            return null;
        }

        var key:String = null;
        var library:String = "";

        if(Std.isOfType(entry, String)) {
            var text:String = cast entry;
            var separatorIndex:Int = text.indexOf(":");

            if(separatorIndex > 0) {
                library = text.substr(0, separatorIndex).trim();
                key = text.substr(separatorIndex + 1).trim();
            }else {
                key = text.trim();
            }
        }else {
            key = Std.string(Reflect.field(entry, "key")).trim();

            if(Reflect.hasField(entry, "library")) {
                library = Std.string(Reflect.field(entry, "library")).trim();
            }
        }

        if(key == null || key == "") {
            return null;
        }

        var path:String = Paths.getPath('images/$key.png', IMAGE, library);
        return Paths.assetExists(path, IMAGE) ? path : null;
    }

    static function releaseCachedImagePath(path:String):Void {
        if(!shouldUseGPUCache(true) || path == null) {
            return;
        }

        var graphic:FlxGraphic = theseAssets.get(path);
        if(graphic == null || graphic.bitmap == null || graphic.bitmap.image == null) {
            return;
        }

        graphic.bitmap.getTexture(FlxG.stage.context3D);
        graphic.bitmap.disposeImage();
        OpenFlAssets.cache.removeBitmapData(path);
    }

    static function getSongCacheDirectory(song:String):String {
        var candidates:Array<String> = [];

        inline function pushCandidate(name:String):Void {
            if(name == null) {
                return;
            }

            var value:String = name.toLowerCase().trim();
            if(value != "" && !candidates.contains(value)) {
                candidates.push(value);
            }
        }

        pushCandidate(song);
        pushCandidate(CoolUtil.readableSongDirectory(song));

        for(candidate in candidates) {
            if(Paths.assetExists(Paths.getPath('data/${candidate}/cache.json', TEXT, ""), TEXT)) {
                return candidate;
            }
        }

        return candidates.length > 0 ? candidates[0] : "";
    }

    static public function releaseSongCacheImages(song:String):Void {
        if(song == null || song.trim() == "" || !shouldUseGPUCache(true)) {
            return;
        }

        var songCacheDirectory:String = getSongCacheDirectory(song);
        if(songCacheDirectory == "") {
            return;
        }

        var cachePath:String = Paths.getPath('data/${songCacheDirectory}/cache.json', TEXT, "");
        if(!Paths.assetExists(cachePath, TEXT)) {
            return;
        }

        var cacheList:Array<Dynamic> = cast Json.parse(Paths.readText(cachePath));
        for(entry in cacheList) {
            releaseCachedImagePath(resolveImagePathFromCacheEntry(entry));
        }

        collectNow();
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
