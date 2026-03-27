package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import openfl.display.BitmapData;
import openfl.media.Sound;
import openfl.utils.ByteArray;
import openfl.utils.Assets as OpenFlAssets;

import SaveData.SaveType;

using StringTools;

// Basically a class like Path.
@:access(flixel.FlxG)
class Cache {
	@:noCompletion private static var permanentCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
	@:noCompletion private static var currentCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
	@:noCompletion private static var previousCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

	@:noCompletion private static var permanentCachedSounds:Map<String, Sound> = new Map<String, Sound>();
	@:noCompletion private static var currentCachedSounds:Map<String, Sound> = new Map<String, Sound>();
	@:noCompletion private static var previousCachedSounds:Map<String, Sound> = new Map<String, Sound>();

	@:noCompletion private static var purgeFilter:Array<String> = ["/week", "/characters", "/charSelect", "/results"];

static function isFreeplayAssetKey(key:String):Bool {
		if(key == null) {
			return false;
		}

		var normalized = key.toLowerCase();
		return normalized.indexOf("freeplay") >= 0 || normalized.indexOf("graffiti") >= 0;
	}

	static function isSongSoundKey(key:String):Bool {
		if(key == null) {
			return false;
		}

		for(prefix in ["songs", "assets/music/", "shared:assets/shared/music/", "preload:assets/preload/music/"]) {
			if(key.indexOf(prefix) >= 0) {
				return true;
			}
		}

		return false;
	}

	static inline function shouldUseGPUCache(allowGPUCache:Bool):Bool {
		return allowGPUCache
			&& SaveData.getData(SaveType.GPU_CACHE)
			&& FlxG.stage != null
			&& FlxG.stage.context3D != null;
	}

	static function copyTextureMap(source:Map<String, FlxGraphic>):Map<String, FlxGraphic> {
		var copy:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

		for(key in source.keys()) {
			copy.set(key, source.get(key));
		}

		return copy;
	}

	static function copySoundMap(source:Map<String, Sound>):Map<String, Sound> {
		var copy:Map<String, Sound> = new Map<String, Sound>();

		for(key in source.keys()) {
			copy.set(key, source.get(key));
		}

		return copy;
	}

	static function mergeTextureMaps(first:Map<String, FlxGraphic>, second:Map<String, FlxGraphic>):Map<String, FlxGraphic> {
		var merged:Map<String, FlxGraphic> = copyTextureMap(second);

		for(key in first.keys()) {
			merged.set(key, first.get(key));
		}

		return merged;
	}

	static function mergeSoundMaps(first:Map<String, Sound>, second:Map<String, Sound>):Map<String, Sound> {
		var merged:Map<String, Sound> = copySoundMap(second);

		for(key in first.keys()) {
			merged.set(key, first.get(key));
		}

		return merged;
	}

	static function warmGraphicTexture(graphic:FlxGraphic):Void {
		if(graphic == null || graphic.bitmap == null || FlxG.stage == null || FlxG.stage.context3D == null) {
			return;
		}

		var sprite:FlxSprite = new FlxSprite();
		sprite.loadGraphic(graphic);
		sprite.draw();
		graphic.bitmap.getTexture(FlxG.stage.context3D);
		sprite.destroy();
	}

	static function getCachedTexture(path:String, promoteFromPrevious:Bool):FlxGraphic {
		if(path == null || path == "") {
			return null;
		}

		var graphic:FlxGraphic = permanentCachedTextures.get(path);

		if(graphic != null) {
			return graphic;
		}

		graphic = currentCachedTextures.get(path);

		if(graphic != null) {
			return graphic;
		}

		graphic = previousCachedTextures.get(path);

		if(graphic != null && promoteFromPrevious) {
			previousCachedTextures.remove(path);
			currentCachedTextures.set(path, graphic);
		}

		return graphic;
	}

	static function getCachedSound(path:String, promoteFromPrevious:Bool):Sound {
		if(path == null || path == "") {
			return null;
		}

		var sound:Sound = permanentCachedSounds.get(path);

		if(sound != null) {
			return sound;
		}

		sound = currentCachedSounds.get(path);

		if(sound != null) {
			return sound;
		}

		sound = previousCachedSounds.get(path);

		if(sound != null && promoteFromPrevious) {
			previousCachedSounds.remove(path);
			currentCachedSounds.set(path, sound);
		}

		return sound;
	}

	static function destroyGraphic(path:String, graphic:FlxGraphic):Void {
		if(graphic != null) {
			graphic.persist = false;
			graphic.destroyOnNoUse = true;
		}

		if(graphic != null) {
			FlxG.bitmap.remove(graphic);
		}
		OpenFlAssets.cache.removeBitmapData(path);
	}

	static function cacheSoundDirectly(path:String):Void {
		if(getCachedSound(path, true) != null) {
			return;
		}

		if(!(Paths.assetExists(path, SOUND) || Paths.assetExists(path, MUSIC))) {
			trace("Warning: could not locate asset - " + path);
			return;
		}

		var sound:Sound = Paths.loadSoundAsset(path);

		if(sound == null) {
			trace("Warning: could not locate asset - " + path);
			return;
		}

		currentCachedSounds.set(path, sound);
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
					cacheSoundDirectly(path);
				}
		}
	}

	static function cacheAssetDirectly(path:String, allowGPUCache:Bool = true):Void {
		if(getCachedTexture(path, true) != null) {
			return;
		}

		if(!Paths.assetExists(path, IMAGE)) {
			trace("Warning: could not locate asset - " + path);
			return;
		}

		var useGPUCache:Bool = shouldUseGPUCache(allowGPUCache);
		var bitmap:BitmapData = Paths.loadBitmap(path, !useGPUCache);

		if(bitmap == null) {
			trace("Warning: could not locate asset - " + path);
			return;
		}

		if(!useGPUCache) {
			bitmap = bitmap.clone();
			OpenFlAssets.cache.removeBitmapData(path);
		}

		var graphic:FlxGraphic = FlxG.bitmap.add(bitmap, false, path);
		graphic.persist = true;
		graphic.destroyOnNoUse = false;
		currentCachedTextures.set(path, graphic);

		if(useGPUCache) {
			warmGraphicTexture(graphic);
		}
	}

	static public function cacheAsset(key:String, ?library:String = "", allowGPUCache:Bool = true):Void {
		var path:String = Paths.getPath('images/$key.png', IMAGE, library);
		cacheAssetDirectly(path, allowGPUCache);
	}

	static public function cacheRemove(key:String, ?library:String = ""):Void {
		var path:String = Paths.getPath('images/$key.png', IMAGE, library);
		var graphic:FlxGraphic = getCachedTexture(path, false);

		if(graphic == null) {
			return;
		}

		permanentCachedTextures.remove(path);
		currentCachedTextures.remove(path);
		previousCachedTextures.remove(path);
		destroyGraphic(path, graphic);
	}

	static public function cacheFromByteArray(name:String, bytes:ByteArray):Void {
		cacheByteArrayInternal(name, bytes, false);
	}

	static public function cachePermanentFromByteArray(name:String, bytes:ByteArray):FlxGraphic {
		return cacheByteArrayInternal(name, bytes, true);
	}

	static function cacheByteArrayInternal(name:String, bytes:ByteArray, permanent:Bool):FlxGraphic {
		if(bytes == null) {
			return null;
		}

		var cachedGraphic:FlxGraphic = getCachedTexture(name, true);

		if(cachedGraphic != null) {
			if(permanent) {
				permanentCachedTextures.set(name, cachedGraphic);
			}

			return cachedGraphic;
		}

		var bitmap:BitmapData = BitmapData.fromBytes(bytes);

		if(bitmap == null) {
			return null;
		}

		var graphic:FlxGraphic = FlxG.bitmap.add(bitmap, false, name);
		graphic.persist = true;
		graphic.destroyOnNoUse = false;
		currentCachedTextures.set(name, graphic);

		if(permanent) {
			permanentCachedTextures.set(name, graphic);
		}

		if(shouldUseGPUCache(true)) {
			warmGraphicTexture(graphic);
		}

		return graphic;
	}

	static public function getAssetDirectly(path:String):FlxGraphic {
		return getCachedTexture(path, true);
	}

	static public function getAsset(key:String, ?library:String = ""):FlxGraphic {
		var path:String = Paths.getPath('images/$key.png', IMAGE, library);
		return getAssetDirectly(path);
	}

	public static function preparePurgeTextureCache():Void {
		previousCachedTextures = currentCachedTextures;

		for(key in permanentCachedTextures.keys()) {
			previousCachedTextures.remove(key);
		}

		currentCachedTextures = copyTextureMap(permanentCachedTextures);
	}

	public static function purgeTextureCache():Void {
		for(key in previousCachedTextures.keys()) {
			if(permanentCachedTextures.exists(key)) {
				continue;
			}

			var graphic:FlxGraphic = previousCachedTextures.get(key);

			if(graphic != null) {
				destroyGraphic(key, graphic);
			}
		}

		previousCachedTextures = new Map<String, FlxGraphic>();

		@:privateAccess
		if(FlxG.bitmap._cache == null) {
			@:privateAccess
			FlxG.bitmap._cache = new Map();
		}

		@:privateAccess
		for(key in FlxG.bitmap._cache.keys()) {
			var graphic:FlxGraphic = FlxG.bitmap.get(key);

			if(graphic == null || graphic.persist || permanentCachedTextures.exists(key) || key.contains("fonts")) {
				continue;
			}

			if(graphic.useCount > 0) {
				for(purgeEntry in purgeFilter) {
					if(key.contains(purgeEntry)) {
						FlxG.bitmap.removeByKey(key);
						break;
					}
				}
			}
		}
	}

	public static function preparePurgeSoundCache():Void {
		previousCachedSounds = currentCachedSounds;

		for(key in permanentCachedSounds.keys()) {
			previousCachedSounds.remove(key);
		}

		currentCachedSounds = copySoundMap(permanentCachedSounds);
	}

	public static function purgeSoundCache():Void {
		for(key in previousCachedSounds.keys()) {
			if(permanentCachedSounds.exists(key)) {
				continue;
			}

			OpenFlAssets.cache.removeSound(key);
		}

		previousCachedSounds = new Map<String, Sound>();

		for(prefix in ["songs", "music"]) {
			OpenFlAssets.cache.clear(prefix);
		}
	}

	public static function preparePurgeCache():Void {
		preparePurgeTextureCache();
		preparePurgeSoundCache();
	}

	public static function purgeCache(callGarbageCollector:Bool = false):Void {
		purgeTextureCache();
		purgeSoundCache();

		if(callGarbageCollector) {
			collectNow();
		}
	}

	static public function clear():Void {
		previousCachedTextures = mergeTextureMaps(currentCachedTextures, previousCachedTextures);
		currentCachedTextures = copyTextureMap(permanentCachedTextures);
		purgeTextureCache();

		previousCachedSounds = mergeSoundMaps(currentCachedSounds, previousCachedSounds);
		currentCachedSounds = copySoundMap(permanentCachedSounds);
		purgeSoundCache();

		collectNow();
	}

	static public function collectNow():Void {
		MemoryUtil.collect(true);
		MemoryUtil.compact();
	}

	static public function clearSongSoundCache():Void {
		for(key in currentCachedSounds.keys()) {
			if(!permanentCachedSounds.exists(key) && isSongSoundKey(key)) {
				currentCachedSounds.remove(key);
				OpenFlAssets.cache.removeSound(key);
			}
		}

		for(key in previousCachedSounds.keys()) {
			if(!permanentCachedSounds.exists(key) && isSongSoundKey(key)) {
				previousCachedSounds.remove(key);
				OpenFlAssets.cache.removeSound(key);
			}
		}

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

			if(permanentCachedTextures.exists(key)) {
				continue;
			}

			keysToRemove.push(key);
		}

		for(key in keysToRemove) {
			var graphic:FlxGraphic = FlxG.bitmap.get(key);

			currentCachedTextures.remove(key);
			previousCachedTextures.remove(key);
			destroyGraphic(key, graphic);
		}

		preparePurgeSoundCache();
		purgeSoundCache();
		collectNow();
	}

	// Upstream Funkin does not dispose song cache bitmaps after state creation.
	// Keeping this as a no-op avoids breaking atlas-backed stage assets.
	static public function releaseSongCacheImages(song:String):Void {}

	static public function clearNoneCachedAssets() {
		@:privateAccess
		for(key in FlxG.bitmap._cache.keys()) {
			var graphic:FlxGraphic = FlxG.bitmap.get(key);

			if(graphic != null && getCachedTexture(key, false) == null) {
				OpenFlAssets.cache.removeBitmapData(key);
				FlxG.bitmap.removeByKey(key);
			}
		}
	}
}
