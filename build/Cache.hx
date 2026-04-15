package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import openfl.display.BitmapData;
import openfl.media.Sound;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import openfl.utils.ByteArray;
import ModInitialize;

using StringTools;

// I was at this for hours, let's see how Claude pulls this off.

/**
 * Handles caching of textures and sounds for the game.
 * Based on FunkinMemory from Friday Night Funkin'.
 */
@:access(flixel.FlxG)
class Cache
{
	static var permanentCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
	static var currentCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
	static var previousCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

	static var permanentCachedSounds:Map<String, Sound> = new Map<String, Sound>();
	static var currentCachedSounds:Map<String, Sound> = new Map<String, Sound>();
	static var previousCachedSounds:Map<String, Sound> = new Map<String, Sound>();

	static var purgeFilter:Array<String> = ["/week", "/characters", "/charSelect", "/results", "/stages"];

	/**
	 * Caches textures that are always required.
	 */
	public static function initialCache():Void
	{
		var allImages:Array<String> = OpenFlAssets.list(AssetType.IMAGE);

		for (file in allImages)
		{
			if (!file.endsWith(".png") || file.contains("chart-editor") || !file.contains("ui/"))
				continue;

			var normalizedFile = file.replace(" ", "");

			if (normalizedFile.contains("shared") || OpenFlAssets.exists('shared:$normalizedFile', AssetType.IMAGE))
				normalizedFile = 'shared:$normalizedFile';

			permanentCacheTexture(normalizedFile);
		}

		for (texture in [
			Paths.getPath("images/healthBar.png", AssetType.IMAGE, null),
			Paths.getPath("images/menuDesat.png", AssetType.IMAGE, null),
			Paths.getPath("images/notes.png", AssetType.IMAGE, "shared"),
			Paths.getPath("images/noteSplashes.png", AssetType.IMAGE, "shared"),
			Paths.getPath("images/noteStrumline.png", AssetType.IMAGE, "shared"),
			Paths.getPath("images/NOTE_hold_assets.png", AssetType.IMAGE, null),
			Paths.getPath("images/fonts/bold.png", AssetType.IMAGE, null),
			Paths.getPath("images/fonts/default.png", AssetType.IMAGE, null),
			Paths.getPath("images/fonts/freeplay-clear.png", AssetType.IMAGE, null)
		])
		{
			if (texture != null && texture != "")
				permanentCacheTexture(texture);
		}

		var allSounds:Array<String> = OpenFlAssets.list(AssetType.SOUND);

		for (file in allSounds)
		{
			if (!file.endsWith(".ogg") || !file.contains("countdown/"))
				continue;

			var normalizedFile = file.replace(" ", "");

			if (normalizedFile.contains("shared") || OpenFlAssets.exists('shared:$normalizedFile', AssetType.SOUND))
				normalizedFile = 'shared:$normalizedFile';

			permanentCacheSound(normalizedFile);
		}

		for (sound in [
			Paths.getPath('sounds/cancelMenu.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('sounds/confirmMenu.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('sounds/screenshot.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('sounds/scrollMenu.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('sounds/soundtray/Voldown.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('sounds/soundtray/VolMAX.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('sounds/soundtray/Volup.${Paths.SOUND_EXT}', AssetType.SOUND, null),
			Paths.getPath('music/freakyMenu/freakyMenu.${Paths.SOUND_EXT}', AssetType.MUSIC, null),
			Paths.getPath('sounds/missnote1.${Paths.SOUND_EXT}', AssetType.SOUND, "shared"),
			Paths.getPath('sounds/missnote2.${Paths.SOUND_EXT}', AssetType.SOUND, "shared"),
			Paths.getPath('sounds/missnote3.${Paths.SOUND_EXT}', AssetType.SOUND, "shared")
		])
		{
			if (sound != null)
				permanentCacheSound(sound);
		}
	}

	/**
	 * Clears the current texture and sound caches.
	 * @param callGarbageCollector Whether to call the system's garbage collector after purging.
	 */
	public static inline function purgeCache(callGarbageCollector:Bool = false):Void
	{
		preparePurgeTextureCache();
		purgeTextureCache();
		preparePurgeSoundCache();
		purgeSoundCache();

		#if (cpp || neko || hl)
		if (callGarbageCollector)
			MemoryUtil.collect(true);
		#end
	}

	///// TEXTURES /////

	/**
	 * Ensures a texture with the given key is cached.
	 * @param key The key of the texture to cache.
	 */
	public static function cacheTexture(key:String):Void
	{
		if (key == null || key == "")
			return;

		if (currentCachedTextures.exists(key))
			return;

		if (previousCachedTextures.exists(key))
		{
			// Move the texture from the previous cache to the current cache.
			var graphic:FlxGraphic = previousCachedTextures.get(key);
			previousCachedTextures.remove(key);
			if (graphic != null)
				currentCachedTextures.set(key, graphic);
			return;
		}

		var graphic:FlxGraphic = FlxGraphic.fromAssetKey(key, false, null, true);
		if (graphic == null)
		{
			var bitmap = Paths.loadBitmap(key, true);
			if (bitmap != null)
				graphic = FlxGraphic.fromBitmapData(bitmap, false, key);
		}

		if (graphic == null)
		{
			FlxG.log.warn('Failed to cache graphic: $key');
			return;
		}

		trace('[CACHE] Cached asset $key');
		graphic.persist = true;
		currentCachedTextures.set(key, graphic);
		forceRender(graphic);
	}

	/**
	 * Permanently caches a texture with the given key.
	 * @param key The key of the texture to cache.
	 */
	static function permanentCacheTexture(key:String):Void
	{
		if (key == null || key == "")
			return;

		if (permanentCachedTextures.exists(key))
			return;

		var graphic:FlxGraphic = FlxGraphic.fromAssetKey(key, false, null, true);
		if (graphic == null)
		{
			var bitmap = Paths.loadBitmap(key, true);
			if (bitmap != null)
				graphic = FlxGraphic.fromBitmapData(bitmap, false, key);
		}

		if (graphic == null)
		{
			FlxG.log.warn('Failed to cache graphic: $key');
			return;
		}

		trace('[CACHE] Cached graphic $key');
		graphic.persist = true;
		permanentCachedTextures.set(key, graphic);
		forceRender(graphic);
		currentCachedTextures = permanentCachedTextures.copy();
	}

	public static function getCachedGraphic(path:String):FlxGraphic
	{
		if (permanentCachedTextures.exists(path))
			return permanentCachedTextures.get(path);
		if (currentCachedTextures.exists(path))
			return currentCachedTextures.get(path);
		if (previousCachedTextures.exists(path))
			return previousCachedTextures.get(path);

		return null;
	}

	/**
	 * Prepares the cache for purging unused textures.
	 */
	public static inline function preparePurgeTextureCache():Void
	{
		previousCachedTextures = currentCachedTextures.copy();

		for (graphicKey in previousCachedTextures.keys())
		{
			if (permanentCachedTextures.exists(graphicKey))
			{
				previousCachedTextures.remove(graphicKey);
			}
		}

		currentCachedTextures = permanentCachedTextures.copy();
	}

	/**
	 * Purges unused textures from the cache.
	 */
	public static function purgeTextureCache():Void
	{
		for (graphicKey in previousCachedTextures.keys())
		{
			if (permanentCachedTextures.exists(graphicKey))
			{
				previousCachedTextures.remove(graphicKey);
				continue;
			}

			if (graphicKey.contains("fonts"))
				continue;

			var graphic:FlxGraphic = previousCachedTextures.get(graphicKey);
			if (graphic != null)
			{
				FlxG.bitmap.remove(graphic);
				graphic.persist = false;
				graphic.destroy();
				previousCachedTextures.remove(graphicKey);
				OpenFlAssets.cache.clear(graphicKey);
			}
		}

		@:privateAccess
		if (FlxG.bitmap._cache == null)
		{
			@:privateAccess
			FlxG.bitmap._cache = new Map();
		}

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			var obj:FlxGraphic = FlxG.bitmap.get(key);

			if (obj == null || (obj.persist && permanentCachedTextures.exists(key)) || key.contains("fonts"))
			{
				continue;
			}

			if (obj.useCount > 0)
			{
				for (purgeEntry in purgeFilter)
				{
					if (key.contains(purgeEntry))
					{
						FlxG.bitmap.removeKey(key);
						obj.persist = false;
						obj.destroy();
						break;
					}
				}
			}
		}
	}

	/**
	 * Forces the GPU to load and upload a FlxGraphic.
	 * @param graphic The graphic to force render.
	 */
	private static function forceRender(graphic:FlxGraphic):Void
	{
		if (graphic == null)
			return;

		var bmp:FlxGraphic = FlxG.bitmap.get(graphic.key);
		if (bmp != null && bmp.bitmap != null)
		{
			var _:Int = bmp.bitmap.width; // Trigger
		}

		// Draws sprite and actually caches it.
		var sprite = new FlxSprite();
		sprite.loadGraphic(graphic);
		sprite.draw(); // Draw sprite and load it into game's memory.

		if (graphic.bitmap != null && FlxG.stage != null && FlxG.stage.context3D != null)
		{
			graphic.bitmap.getTexture(FlxG.stage.context3D); // Just in case that didn't work...
		}

		sprite.destroy();
	}

	/**
	 * Determine whether the texture with the given key is cached.
	 * @param key The key of the texture to check.
	 * @return Whether the texture is cached.
	 */
	public static function isTextureCached(key:String):Bool
	{
		return FlxG.bitmap.get(key) != null
			&& (permanentCachedTextures.exists(key) || currentCachedTextures.exists(key) || previousCachedTextures.exists(key));
	}

	///// SOUND //////

	/**
	 * Caches a sound with the given key.
	 * @param key The key of the sound to cache.
	 */
	public static function cacheSound(key:String):Void
	{
		if (key == null || key == "")
			return;

		if (currentCachedSounds.exists(key))
			return;

		if (previousCachedSounds.exists(key))
		{
			// Move the sound from the previous cache to the current cache.
			var sound:Sound = previousCachedSounds.get(key);
			previousCachedSounds.remove(key);
			if (sound != null)
				currentCachedSounds.set(key, sound);
			return;
		}

		var sound:Sound = null;
		if (OpenFlAssets.exists(key, AssetType.SOUND) || OpenFlAssets.exists(key, AssetType.MUSIC))
		{
			sound = OpenFlAssets.getSound(key, true);
		}
		#if sys
		else if (sys.FileSystem.exists(key))
		{
			sound = Sound.fromFile(key);
		}
		#end

		if (sound == null)
			return;

		currentCachedSounds.set(key, sound);
	}

	public static function getCachedSound(path:String):Sound
	{
		if (path == null || path == "")
			return null;

		if (permanentCachedSounds.exists(path))
			return permanentCachedSounds.get(path);
		if (currentCachedSounds.exists(path))
			return currentCachedSounds.get(path);
		if (previousCachedSounds.exists(path))
			return previousCachedSounds.get(path);

		return null;
	}

	/**
	 * Permanently caches a sound with the given key.
	 * @param key The key of the sound to cache.
	 */
	static function permanentCacheSound(key:String):Void
	{
		if (permanentCachedSounds.exists(key))
			return;

		if (!OpenFlAssets.exists(key, AssetType.SOUND) && !OpenFlAssets.exists(key, AssetType.MUSIC))
			return;

		var sound:Sound = OpenFlAssets.getSound(key, true);
		if (sound == null)
			return;

		permanentCachedSounds.set(key, sound);
		currentCachedSounds.set(key, sound);
	}

	/**
	 * Prepares the cache for purging unused sounds.
	 */
	public static function preparePurgeSoundCache():Void
	{
		previousCachedSounds = currentCachedSounds.copy();

		for (key in previousCachedSounds.keys())
		{
			if (permanentCachedSounds.exists(key))
			{
				previousCachedSounds.remove(key);
			}
		}

		currentCachedSounds = permanentCachedSounds.copy();
	}

	/**
	 * Purges unused sounds from the cache.
	 */
	public static inline function purgeSoundCache():Void
	{
		for (key in previousCachedSounds.keys())
		{
			if (permanentCachedSounds.exists(key))
			{
				previousCachedSounds.remove(key);
				continue;
			}

			var sound:Sound = previousCachedSounds.get(key);
			if (sound != null)
			{
				OpenFlAssets.cache.removeSound(key);
				previousCachedSounds.remove(key);
			}
		}

		OpenFlAssets.cache.clear("songs");
		OpenFlAssets.cache.clear("music");
	}

	///// MISC /////

	/**
	 * Prepares both caches for purging.
	 */
	public static function preparePurgeCache():Void
	{
		preparePurgeTextureCache();
		preparePurgeSoundCache();
	}

	/**
	 * Clears all non-permanent assets from memory.
	 */
	public static function clear():Void
	{
		preparePurgeCache();
		purgeCache(true);
	}

	public static function collectNow():Void
	{
		MemoryUtil.collect(true);
		MemoryUtil.compact();
	}

	/**
	 * Clears all Freeplay assets from memory.
	 */
	public static inline function clearFreeplay():Void
	{
		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!key.contains("freeplay"))
				continue;
			if (permanentCachedTextures.exists(key) || key.contains("fonts"))
				continue;

			keysToRemove.push(key);
		}

		@:privateAccess
		for (key in keysToRemove)
		{
			trace('[CACHE] Cleaning asset $key');
			var obj:FlxGraphic = FlxG.bitmap.get(key);
			if (obj != null)
			{
				obj.persist = false;
				obj.destroy();
			}
			FlxG.bitmap.removeKey(key);
			if (currentCachedTextures.exists(key))
				currentCachedTextures.remove(key);
			if (previousCachedTextures.exists(key))
				previousCachedTextures.remove(key);
			OpenFlAssets.cache.clear(key);
		}

		preparePurgeSoundCache();
		purgeSoundCache();
	}

	/**
	 * Clears all character-related assets from memory.
	 */
	public static inline function clearCharacters():Void
	{
		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!key.contains("characters"))
				continue;
			if (permanentCachedTextures.exists(key) || key.contains("fonts"))
				continue;

			keysToRemove.push(key);
		}

		@:privateAccess
		for (key in keysToRemove)
		{
			trace('[CACHE] Cleaning character asset $key');
			var obj:FlxGraphic = FlxG.bitmap.get(key);
			if (obj != null)
			{
				obj.persist = false;
				obj.destroy();
			}
			FlxG.bitmap.removeKey(key);
			if (currentCachedTextures.exists(key))
				currentCachedTextures.remove(key);
			if (previousCachedTextures.exists(key))
				previousCachedTextures.remove(key);
			OpenFlAssets.cache.clear(key);
		}
	}

	/**
	 * Clears all stage-related assets from memory.
	 */
	public static inline function clearStages():Void
	{
		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!key.contains("stages"))
				continue;
			if (permanentCachedTextures.exists(key) || key.contains("fonts"))
				continue;

			keysToRemove.push(key);
		}

		@:privateAccess
		for (key in keysToRemove)
		{
			trace('[CACHE] Cleaning stage asset $key');
			var obj:FlxGraphic = FlxG.bitmap.get(key);
			if (obj != null)
			{
				obj.persist = false;
				obj.destroy();
			}
			FlxG.bitmap.removeKey(key);
			if (currentCachedTextures.exists(key))
				currentCachedTextures.remove(key);
			if (previousCachedTextures.exists(key))
				previousCachedTextures.remove(key);
			OpenFlAssets.cache.clear(key);
		}
	}

	public static function clearSongSoundCache():Void
	{
		for (key in currentCachedSounds.keys())
		{
			if (!permanentCachedSounds.exists(key) && isSongSoundKey(key))
			{
				currentCachedSounds.remove(key);
				OpenFlAssets.cache.removeSound(key);
			}
		}

		for (key in previousCachedSounds.keys())
		{
			if (!permanentCachedSounds.exists(key) && isSongSoundKey(key))
			{
				previousCachedSounds.remove(key);
				OpenFlAssets.cache.removeSound(key);
			}
		}

		for (prefix in ["songs", "assets/music/", "shared:assets/shared/music/", "preload:assets/preload/music/"])
			OpenFlAssets.cache.clear(prefix);
	}

	static function isSongSoundKey(key:String):Bool
	{
		if (key == null)
			return false;

		for (prefix in ["songs", "assets/music/", "shared:assets/shared/music/", "preload:assets/preload/music/"])
		{
			if (key.indexOf(prefix) >= 0)
				return true;
		}

		return false;
	}

	public static function clearNoneCachedAssets():Void
	{
		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			var graphic = FlxG.bitmap.get(key);

			if (graphic != null && getCachedGraphic(key) == null)
			{
				OpenFlAssets.cache.removeBitmapData(key);
				FlxG.bitmap.removeByKey(key);
			}
		}
	}

	public static function releaseSongCacheImages(song:String):Void {}

	// Legacy API support
	public static function cacheCharacter(characterPath:String):Void
	{
		if (characterPath == null || characterPath == "")
			return;

		var characterInfo:ConfigCharacters = null;

		try {
			characterInfo = Character.loadInfo('characters/$characterPath');
		} catch (e) {}

		if(characterInfo != null && characterInfo.file != null && characterInfo.file.trim() != "") {
			var fileList:String = characterInfo.file;

			for(file in fileList.split(",")) {
				var trimmedFile:String = file.trim();
				var extensionIndex:Int = trimmedFile.lastIndexOf(".");
				var basePath:String = extensionIndex >= 0 ? trimmedFile.substr(0, extensionIndex) : trimmedFile;
				var graphicKey = Paths.getPath('images/$basePath.png', AssetType.IMAGE, null);

				if (graphicKey != null && graphicKey != "")
					cacheTexture(graphicKey);
			}

			return;
		}

		var graphicKey = Paths.getPath('images/characters/$characterPath.png', AssetType.IMAGE, null);
		if (graphicKey != null && graphicKey != "")
			cacheTexture(graphicKey);
	}

	public static function cacheStage(stagePath:String):Void
	{
		if (stagePath == null || stagePath == "")
			return;

		var graphicKey = Paths.getPath('images/stages/$stagePath.png', AssetType.IMAGE, null);
		if (graphicKey != null && graphicKey != "")
			cacheTexture(graphicKey);
	}

	public static function cacheAsset(key:String, ?library:String = ""):Void
	{
		var path = Paths.getPath('images/$key.png', AssetType.IMAGE, library);
		cacheTexture(path);
	}

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
		cacheByteArrayInternal(name, bytes, false);
	}

	public static function cachePermanentFromByteArray(name:String, bytes:ByteArray):FlxGraphic
	{
		return cacheByteArrayInternal(name, bytes, true);
	}

	static function cacheByteArrayInternal(name:String, bytes:ByteArray, permanent:Bool):FlxGraphic
	{
		if (bytes == null)
			return null;

		var cachedGraphic = getCachedGraphic(name);
		if (cachedGraphic != null)
		{
			if (permanent)
				permanentCachedTextures.set(name, cachedGraphic);
			return cachedGraphic;
		}

		var bitmap = BitmapData.fromBytes(bytes);
		if (bitmap == null)
			return null;

		var graphic = FlxG.bitmap.add(bitmap, false, name);
		if (graphic == null)
			return null;

		graphic.persist = true;
		currentCachedTextures.set(name, graphic);

		if (permanent)
			permanentCachedTextures.set(name, graphic);

		forceRender(graphic);

		return graphic;
	}
}
