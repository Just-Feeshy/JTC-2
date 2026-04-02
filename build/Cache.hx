package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import openfl.display.BitmapData;
import openfl.media.Sound;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import openfl.utils.ByteArray;

using StringTools;

/**
 * Simplified cache system - relies on Flixel's built-in caching.
 * Only permanently caches essential UI assets.
 */
@:access(flixel.FlxG)
class Cache
{
	// Only essential UI assets that should never be unloaded
	static var essentialAssets:Array<String> = [];
	static var initialized:Bool = false;

	/**
	 * Cache essential UI assets on startup (minimal set).
	 */
	public static function initialCache():Void
	{
		if (initialized) return;
		initialized = true;

		// Only cache truly essential assets that are used everywhere
		for (texture in [
			Paths.getPath("images/healthBar.png", AssetType.IMAGE, null),
			Paths.getPath("images/notes.png", AssetType.IMAGE, "shared"),
			Paths.getPath("images/noteStrumline.png", AssetType.IMAGE, "shared")
		])
		{
			if (texture != null && texture != "")
			{
				essentialAssets.push(texture);
				// Just load into Flixel's cache, no special handling
				FlxGraphic.fromAssetKey(texture, false, null, true);
			}
		}
	}

	/**
	 * Clears non-essential assets from memory.
	 */
	public static function purgeCache(callGarbageCollector:Bool = false):Void
	{
		clearNonEssentialTextures();
		clearNonEssentialSounds();

		#if (cpp || neko || hl)
		if (callGarbageCollector)
			MemoryUtil.collect(true);
		#end
	}

	static function clearNonEssentialTextures():Void
	{
		@:privateAccess
		if (FlxG.bitmap._cache == null) return;

		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			// Keep essential assets and fonts
			if (essentialAssets.contains(key) || key.contains("fonts"))
				continue;

			keysToRemove.push(key);
		}

		for (key in keysToRemove)
		{
			var obj:FlxGraphic = FlxG.bitmap.get(key);
			if (obj != null)
			{
				obj.persist = false;
				obj.destroy();
			}
			FlxG.bitmap.remove(obj);
			OpenFlAssets.cache.clear(key);
		}
	}

	static function clearNonEssentialSounds():Void
	{
		// Clear song audio caches
		for (prefix in ["songs", "assets/music/", "shared:assets/shared/music/", "preload:assets/preload/music/"])
			OpenFlAssets.cache.clear(prefix);
	}

	/**
	 * Get a cached graphic if it exists.
	 */
	public static function getCachedGraphic(path:String):FlxGraphic
	{
		return FlxG.bitmap.get(path);
	}

	/**
	 * Check if a texture is cached.
	 */
	public static function isTextureCached(key:String):Bool
	{
		return FlxG.bitmap.get(key) != null;
	}

	/**
	 * Clear all caches and trigger GC.
	 */
	public static function clear():Void
	{
		purgeCache(true);
	}

	public static function collectNow():Void
	{
		MemoryUtil.collect(true);
		MemoryUtil.compact();
	}

	/**
	 * Clear freeplay-related assets.
	 */
	public static function clearFreeplay():Void
	{
		clearAssetsContaining("freeplay");
	}

	/**
	 * Clear character-related assets.
	 */
	public static function clearCharacters():Void
	{
		clearAssetsContaining("characters");
	}

	/**
	 * Clear stage-related assets.
	 */
	public static function clearStages():Void
	{
		clearAssetsContaining("stages");
	}

	static function clearAssetsContaining(pattern:String):Void
	{
		@:privateAccess
		if (FlxG.bitmap._cache == null) return;

		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!key.contains(pattern)) continue;
			if (essentialAssets.contains(key) || key.contains("fonts")) continue;

			keysToRemove.push(key);
		}

		for (key in keysToRemove)
		{
			var obj:FlxGraphic = FlxG.bitmap.get(key);
			if (obj != null)
			{
				obj.persist = false;
				obj.destroy();
			}
			FlxG.bitmap.remove(obj);
			OpenFlAssets.cache.clear(key);
		}
	}

	public static function clearSongSoundCache():Void
	{
		clearNonEssentialSounds();
	}

	public static function clearNoneCachedAssets():Void
	{
		// No-op - let Flixel handle its own cache
	}

	public static function releaseSongCacheImages(song:String):Void
	{
		// No-op
	}

	// Legacy API - these now do nothing since we use lazy loading
	public static function cacheTexture(key:String):Void {}
	public static function cacheSound(key:String):Void {}
	public static function preparePurgeTextureCache():Void {}
	public static function purgeTextureCache():Void {}
	public static function preparePurgeSoundCache():Void {}
	public static function purgeSoundCache():Void {}
	public static function preparePurgeCache():Void {}

	public static function cacheCharacter(characterPath:String):Void {}
	public static function cacheStage(stagePath:String):Void {}
	public static function cacheAsset(key:String, ?library:String = ""):Void {}

	public static function getAsset(key:String, ?library:String = ""):FlxGraphic
	{
		var path = Paths.getPath('images/$key.png', AssetType.IMAGE, library);
		return getCachedGraphic(path);
	}

	public static function getAssetDirectly(path:String):FlxGraphic
	{
		return getCachedGraphic(path);
	}

	public static function cacheFromByteArray(name:String, bytes:ByteArray):Void
	{
		cacheByteArrayInternal(name, bytes);
	}

	public static function cachePermanentFromByteArray(name:String, bytes:ByteArray):FlxGraphic
	{
		return cacheByteArrayInternal(name, bytes);
	}

	static function cacheByteArrayInternal(name:String, bytes:ByteArray):FlxGraphic
	{
		if (bytes == null) return null;

		var cachedGraphic = getCachedGraphic(name);
		if (cachedGraphic != null) return cachedGraphic;

		var bitmap = BitmapData.fromBytes(bytes);
		if (bitmap == null) return null;

		var graphic = FlxG.bitmap.add(bitmap, false, name);
		return graphic;
	}
}
