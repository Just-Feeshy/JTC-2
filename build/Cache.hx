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

@:access(flixel.FlxG)
class Cache
{
	@:noCompletion private static var permanentCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
	@:noCompletion private static var currentCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();
	@:noCompletion private static var previousCachedTextures:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

	@:noCompletion private static var permanentCachedSounds:Map<String, Sound> = new Map<String, Sound>();
	@:noCompletion private static var currentCachedSounds:Map<String, Sound> = new Map<String, Sound>();
	@:noCompletion private static var previousCachedSounds:Map<String, Sound> = new Map<String, Sound>();

	@:noCompletion private static var purgeFilter:Array<String> = ["/week", "/characters", "/charSelect", "/results"];

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

	static function copyTextureMap(source:Map<String, FlxGraphic>):Map<String, FlxGraphic>
	{
		var copy:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

		for (key in source.keys())
			copy.set(key, source.get(key));

		return copy;
	}

	static function copySoundMap(source:Map<String, Sound>):Map<String, Sound>
	{
		var copy:Map<String, Sound> = new Map<String, Sound>();

		for (key in source.keys())
			copy.set(key, source.get(key));

		return copy;
	}

	static function mergeTextureMaps(first:Map<String, FlxGraphic>, second:Map<String, FlxGraphic>):Map<String, FlxGraphic>
	{
		var merged = copyTextureMap(second);

		for (key in first.keys())
			merged.set(key, first.get(key));

		return merged;
	}

	static function mergeSoundMaps(first:Map<String, Sound>, second:Map<String, Sound>):Map<String, Sound>
	{
		var merged = copySoundMap(second);

		for (key in first.keys())
			merged.set(key, first.get(key));

		return merged;
	}

	static function isFreeplayAssetKey(key:String):Bool
	{
		if (key == null)
			return false;

		var normalized = key.toLowerCase();
		return normalized.indexOf("freeplay") >= 0 || normalized.indexOf("graffiti") >= 0;
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

	static function removeGraphicByKey(key:String):Void
	{
		if (key != null && key != "")
			FlxG.bitmap.removeByKey(key);
	}

	static function destroyGraphic(key:String, graphic:FlxGraphic):Void
	{
		if (graphic != null)
		{
			graphic.persist = false;
			graphic.destroyOnNoUse = true;
			FlxG.bitmap.remove(graphic);
			graphic.destroy();
		}

		removeGraphicByKey(key);
		OpenFlAssets.cache.removeBitmapData(key);
	}

	static function removeStaleGraphic(key:String, graphic:FlxGraphic):Void
	{
		if (graphic == null || graphic.bitmap != null)
			return;

		permanentCachedTextures.remove(key);
		currentCachedTextures.remove(key);
		previousCachedTextures.remove(key);
		removeGraphicByKey(key);
		OpenFlAssets.cache.removeBitmapData(key);
	}

	static function buildGraphic(key:String):FlxGraphic
	{
		if (key == null || key == "")
			return null;

		var bitmapGraphic:FlxGraphic = FlxG.bitmap.get(key);

		if (bitmapGraphic != null)
		{
			if (bitmapGraphic.bitmap != null)
				return bitmapGraphic;

			removeGraphicByKey(key);
		}

		var graphic:FlxGraphic = null;

		if (OpenFlAssets.exists(key, AssetType.IMAGE))
		{
			graphic = FlxGraphic.fromAssetKey(key, false, null, true);
		}
		else
		{
			var bitmap:BitmapData = Paths.loadBitmap(key, true);

			if (bitmap == null)
				return null;

			graphic = FlxGraphic.fromBitmapData(bitmap, false, key);
		}

		// Ensure the graphic is properly registered with FlxG.bitmap
		// This is critical for Windows GPU memory management
		if (graphic != null)
		{
			graphic = FlxG.bitmap.add(graphic, false, key);
		}

		return graphic;
	}

	static function buildSound(key:String):Sound
	{
		return Paths.loadSoundAsset(key);
	}

	static function forceRender(graphic:FlxGraphic):Void
	{
		if (graphic == null)
			return;

		// Ensure the graphic is registered with FlxG.bitmap
		var bmp:FlxGraphic = FlxG.bitmap.get(graphic.key);
		if (bmp != null && bmp.bitmap != null)
		{
			// Trigger bitmap property access to ensure it's loaded into memory
			var _ = bmp.bitmap.width;
		}

		// Create a temporary sprite and draw it to force GPU upload
		// This is critical for Windows GPU context to properly cache the texture
		if (graphic.bitmap != null)
		{
			var sprite = new FlxSprite();
			sprite.loadGraphic(graphic);
			sprite.draw(); // This forces the sprite to be rendered and uploaded to GPU

			// Explicitly get the texture on the GPU context
			// This ensures the bitmap data is properly transferred to VRAM on Windows
			if (FlxG.stage != null && FlxG.stage.context3D != null)
			{
				try
				{
					graphic.bitmap.getTexture(FlxG.stage.context3D);

					// Flush the GPU context to ensure immediate upload on Windows
					// This prevents texture loss due to context switches or GC
					flushGPUContext();
				}
				catch (e:Dynamic)
				{
					FlxG.log.error('Failed to upload texture to GPU for ${graphic.key}: $e');
				}
			}

			sprite.destroy();
		}
	}

	/**
	 * Flushes the GPU context to ensure textures are properly committed to VRAM.
	 * This is critical on Windows where GPU context can be lost during context switches.
	 */
	static function flushGPUContext():Void
	{
		if (FlxG.stage == null || FlxG.stage.context3D == null)
			return;

		try
		{
			// Ensure all pending GPU commands are executed
			FlxG.stage.context3D.present();
		}
		catch (e:Dynamic)
		{
			// GPU context may not support present() in all scenarios
			// This is non-fatal and we can continue
		}
	}

	/**
	 * Verifies and reloads graphics that may have been lost from GPU memory.
	 * Useful for Windows where GPU context loss can occur.
	 * Call this if sprites are mysteriously disappearing.
	 */
	static public function verifyGPUMemory():Void
	{
		// Verify permanent cache
		for (key in permanentCachedTextures.keys())
		{
			var graphic = permanentCachedTextures.get(key);
			if (graphic != null && graphic.bitmap != null)
			{
				// Re-render to ensure it's in GPU memory
				forceRender(graphic);
			}
		}

		// Verify current cache
		for (key in currentCachedTextures.keys())
		{
			var graphic = currentCachedTextures.get(key);
			if (graphic != null && graphic.bitmap != null)
			{
				// Re-render to ensure it's in GPU memory
				forceRender(graphic);
			}
		}

		trace('[CACHE] GPU memory verification complete');
	}

	static function getCachedTexture(key:String, promoteFromPrevious:Bool):FlxGraphic
	{
		if (key == null || key == "")
			return null;

		var graphic = permanentCachedTextures.get(key);
		removeStaleGraphic(key, graphic);

		if (graphic != null && graphic.bitmap != null)
			return graphic;

		graphic = currentCachedTextures.get(key);
		removeStaleGraphic(key, graphic);

		if (graphic != null && graphic.bitmap != null)
			return graphic;

		graphic = previousCachedTextures.get(key);
		removeStaleGraphic(key, graphic);

		if (graphic != null && graphic.bitmap != null && promoteFromPrevious)
		{
			previousCachedTextures.remove(key);
			currentCachedTextures.set(key, graphic);
		}

		return (graphic != null && graphic.bitmap != null) ? graphic : null;
	}

	static function getCachedSound(key:String, promoteFromPrevious:Bool):Sound
	{
		if (key == null || key == "")
			return null;

		var sound = permanentCachedSounds.get(key);

		if (sound != null)
			return sound;

		sound = currentCachedSounds.get(key);

		if (sound != null)
			return sound;

		sound = previousCachedSounds.get(key);

		if (sound != null && promoteFromPrevious)
		{
			previousCachedSounds.remove(key);
			currentCachedSounds.set(key, sound);
		}

		return sound;
	}

	public static function cacheTexture(key:String):Void
	{
		if (currentCachedTextures.exists(key))
			return;

		var previousGraphic = previousCachedTextures.get(key);
		removeStaleGraphic(key, previousGraphic);

		if (previousGraphic != null && previousGraphic.bitmap != null)
		{
			// Ensure the recovered graphic has proper GPU settings
			previousGraphic.persist = true;
			previousGraphic.destroyOnNoUse = false;
			previousCachedTextures.remove(key);
			currentCachedTextures.set(key, previousGraphic);
			return;
		}

		var graphic = buildGraphic(key);

		if (graphic == null)
		{
			FlxG.log.warn('Failed to cache graphic: $key');
			return;
		}

		// Ensure persistent graphics cannot be garbage collected on Windows
		graphic.persist = true;
		graphic.destroyOnNoUse = false;

		currentCachedTextures.set(key, graphic);

		// Force GPU upload - this is critical for Windows where GPU context
		// can be lost or textures can be garbage collected prematurely
		forceRender(graphic);
	}

	static function permanentCacheTexture(key:String):Void
	{
		if (permanentCachedTextures.exists(key))
			return;

		var graphic = buildGraphic(key);

		if (graphic == null)
		{
			FlxG.log.warn('Failed to cache graphic: $key');
			return;
		}

		// Ensure permanent graphics cannot be garbage collected
		// These persist flags are critical for Windows GPU memory management
		graphic.persist = true;
		graphic.destroyOnNoUse = false;

		permanentCachedTextures.set(key, graphic);
		currentCachedTextures = copyTextureMap(permanentCachedTextures);

		// Force GPU upload for permanent cache
		forceRender(graphic);
	}

	public static function getCachedGraphic(path:String):FlxGraphic
	{
		return getCachedTexture(path, false);
	}

	public static function isTextureCached(path:String):Bool
	{
		return FlxG.bitmap.get(path) != null
			&& (permanentCachedTextures.exists(path) || currentCachedTextures.exists(path) || previousCachedTextures.exists(path));
	}

	public static function cacheSound(key:String):Void
	{
		if (currentCachedSounds.exists(key))
			return;

		var previousSound = previousCachedSounds.get(key);

		if (previousSound != null)
		{
			previousCachedSounds.remove(key);
			currentCachedSounds.set(key, previousSound);
			return;
		}

		var sound = buildSound(key);

		if (sound == null)
			return;

		currentCachedSounds.set(key, sound);
	}

	static function permanentCacheSound(key:String):Void
	{
		if (permanentCachedSounds.exists(key))
			return;

		var sound = buildSound(key);

		if (sound == null)
			return;

		permanentCachedSounds.set(key, sound);
		currentCachedSounds.set(key, sound);
	}

	static function cacheSoundDirectly(path:String):Void
	{
		cacheSound(path);
	}

	static public function cacheListedFormat(path:String, _allowGPUCache:Bool = true):Void
	{
		var extensionIndex = path.lastIndexOf(".");

		if (extensionIndex < 0 || extensionIndex >= path.length - 1)
			return;

		switch (path.substr(extensionIndex + 1).toLowerCase())
		{
			case "png":
				if (Paths.assetExists(path, AssetType.IMAGE))
					cacheTexture(path);
			case Paths.SOUND_EXT:
				if (Paths.assetExists(path, AssetType.SOUND) || Paths.assetExists(path, AssetType.MUSIC))
					cacheSoundDirectly(path);
		}
	}

	static function cacheAssetDirectly(path:String, _allowGPUCache:Bool = true):Void
	{
		cacheTexture(path);
	}

	static public function cacheAsset(key:String, ?library:String = "", _allowGPUCache:Bool = true):Void
	{
		var path = Paths.getPath('images/$key.png', AssetType.IMAGE, library);
		cacheAssetDirectly(path);
	}

	static public function cacheRemove(key:String, ?library:String = ""):Void
	{
		var path = Paths.getPath('images/$key.png', AssetType.IMAGE, library);
		var graphic = getCachedTexture(path, false);

		permanentCachedTextures.remove(path);
		currentCachedTextures.remove(path);
		previousCachedTextures.remove(path);
		destroyGraphic(path, graphic);
	}

	static public function cacheFromByteArray(name:String, bytes:ByteArray):Void
	{
		cacheByteArrayInternal(name, bytes, false);
	}

	static public function cachePermanentFromByteArray(name:String, bytes:ByteArray):FlxGraphic
	{
		return cacheByteArrayInternal(name, bytes, true);
	}

	static function cacheByteArrayInternal(name:String, bytes:ByteArray, permanent:Bool):FlxGraphic
	{
		if (bytes == null)
			return null;

		var cachedGraphic = getCachedTexture(name, true);

		if (cachedGraphic != null)
		{
			if (permanent)
				permanentCachedTextures.set(name, cachedGraphic);

			return cachedGraphic;
		}

		var bitmap = BitmapData.fromBytes(bytes);

		if (bitmap == null)
			return null;

		// Use FlxG.bitmap.add() to ensure proper GPU memory registration
		var graphic = FlxG.bitmap.add(bitmap, false, name);

		if (graphic == null)
			return null;

		// Ensure GPU-cached graphics cannot be garbage collected on Windows
		graphic.persist = true;
		graphic.destroyOnNoUse = false;

		currentCachedTextures.set(name, graphic);

		if (permanent)
			permanentCachedTextures.set(name, graphic);

		// Force GPU upload - critical for Windows GPU context stability
		forceRender(graphic);

		return graphic;
	}

	static public function getAssetDirectly(path:String):FlxGraphic
	{
		return getCachedTexture(path, true);
	}

	static public function getAsset(key:String, ?library:String = ""):FlxGraphic
	{
		var path = Paths.getPath('images/$key.png', AssetType.IMAGE, library);
		return getAssetDirectly(path);
	}

	public static function preparePurgeTextureCache():Void
	{
		previousCachedTextures = copyTextureMap(currentCachedTextures);

		for (key in previousCachedTextures.keys())
		{
			if (permanentCachedTextures.exists(key))
				previousCachedTextures.remove(key);
		}

		currentCachedTextures = copyTextureMap(permanentCachedTextures);
	}

	public static function purgeTextureCache():Void
	{
		for (key in previousCachedTextures.keys())
		{
			if (permanentCachedTextures.exists(key))
			{
				previousCachedTextures.remove(key);
				continue;
			}

			if (key.contains("fonts"))
				continue;

			var graphic = previousCachedTextures.get(key);

			if (graphic != null)
				destroyGraphic(key, graphic);

			previousCachedTextures.remove(key);
		}

		@:privateAccess
		if (FlxG.bitmap._cache == null)
			@:privateAccess
			FlxG.bitmap._cache = new Map();

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			var graphic:FlxGraphic = FlxG.bitmap.get(key);

			if (graphic == null || (graphic.persist && permanentCachedTextures.exists(key)) || key.contains("fonts"))
				continue;

			if (getCachedTexture(key, false) != null)
				continue;

			if (graphic.useCount > 0)
			{
				for (purgeEntry in purgeFilter)
				{
					if (key.contains(purgeEntry))
					{
						removeGraphicByKey(key);
						graphic.persist = false;
						graphic.destroy();
						break;
					}
				}
			}
		}
	}

	public static function preparePurgeSoundCache():Void
	{
		previousCachedSounds = copySoundMap(currentCachedSounds);

		for (key in previousCachedSounds.keys())
		{
			if (permanentCachedSounds.exists(key))
				previousCachedSounds.remove(key);
		}

		currentCachedSounds = copySoundMap(permanentCachedSounds);
	}

	public static function purgeSoundCache():Void
	{
		for (key in previousCachedSounds.keys())
		{
			if (permanentCachedSounds.exists(key))
			{
				previousCachedSounds.remove(key);
				continue;
			}

			if (previousCachedSounds.get(key) != null)
				OpenFlAssets.cache.removeSound(key);

			previousCachedSounds.remove(key);
		}

		OpenFlAssets.cache.clear("songs");
		OpenFlAssets.cache.clear("music");
	}

	public static function preparePurgeCache():Void
	{
		preparePurgeTextureCache();
		preparePurgeSoundCache();
	}

	public static function purgeCache(callGarbageCollector:Bool = false):Void
	{
		purgeTextureCache();
		purgeSoundCache();

		if (callGarbageCollector)
			collectNow();
	}

	static public function clear():Void
	{
		previousCachedTextures = mergeTextureMaps(currentCachedTextures, previousCachedTextures);
		currentCachedTextures = copyTextureMap(permanentCachedTextures);
		purgeTextureCache();

		previousCachedSounds = mergeSoundMaps(currentCachedSounds, previousCachedSounds);
		currentCachedSounds = copySoundMap(permanentCachedSounds);
		purgeSoundCache();

		collectNow();
	}

	static public function collectNow():Void
	{
		MemoryUtil.collect(true);
		MemoryUtil.compact();
	}

	static public function clearSongSoundCache():Void
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

	static public function clearFreeplay():Void
	{
		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!isFreeplayAssetKey(key))
				continue;

			if (permanentCachedTextures.exists(key) || key.contains("fonts"))
				continue;

			keysToRemove.push(key);
		}

		for (key in keysToRemove)
		{
			var graphic = FlxG.bitmap.get(key);

			currentCachedTextures.remove(key);
			previousCachedTextures.remove(key);
			destroyGraphic(key, graphic);
		}

		preparePurgeSoundCache();
		purgeSoundCache();
		collectNow();
	}

	static public function releaseSongCacheImages(song:String):Void {}

	static public function clearNoneCachedAssets():Void
	{
		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			var graphic = FlxG.bitmap.get(key);

			if (graphic != null && getCachedTexture(key, false) == null)
			{
				OpenFlAssets.cache.removeBitmapData(key);
				removeGraphicByKey(key);
			}
		}
	}

	/**
	 * Caches character graphics to prevent them from disappearing on different machines.
	 * This ensures the graphics are properly uploaded to GPU memory and protected from GC.
	 * @param characterPath The path to the character's sprite sheet
	 */
	static public function cacheCharacter(characterPath:String):Void
	{
		if (characterPath == null || characterPath == "")
			return;

		var graphicKey = Paths.getPath('images/characters/$characterPath.png', AssetType.IMAGE, null);

		if (graphicKey == null || graphicKey == "")
			return;

		// Check if already cached
		if (currentCachedTextures.exists(graphicKey))
			return;

		// Build and cache the graphic with proper GPU protection
		var graphic = buildGraphic(graphicKey);

		if (graphic != null)
		{
			// Ensure character graphics persist in GPU memory and cannot be GC'd on Windows
			graphic.persist = true;
			graphic.destroyOnNoUse = false;

			currentCachedTextures.set(graphicKey, graphic);

			// Critical: Force GPU upload and ensure texture is in VRAM
			// This prevents sprites from disappearing on Windows
			forceRender(graphic);

			trace('[CACHE] Cached character: $characterPath');
		}
		else
		{
			FlxG.log.warn('Failed to cache character: $characterPath');
		}
	}

	/**
	 * Caches a stage's graphics with proper GPU memory protection.
	 * Ensures stage sprites don't disappear on Windows due to GPU context loss.
	 * @param stagePath The path to the stage
	 */
	static public function cacheStage(stagePath:String):Void
	{
		if (stagePath == null || stagePath == "")
			return;

		var graphicKey = Paths.getPath('images/stages/$stagePath.png', AssetType.IMAGE, null);

		if (graphicKey == null || graphicKey == "")
			return;

		// Use standard cacheTexture which ensures proper GPU memory management
		cacheTexture(graphicKey);
		trace('[CACHE] Cached stage: $stagePath');
	}

	/**
	 * Clears all character-related assets from cache.
	 */
	static public function clearCharacters():Void
	{
		// Remove character graphics from cache maps only, don't destroy them.
		// This allows old sprites to keep their references while new sprites get fresh instances.
		// The graphics will be garbage collected naturally when old sprites are destroyed.
		var keysToRemove:Array<String> = [];

		for (key in currentCachedTextures.keys())
		{
			if (key.contains("characters"))
			{
				keysToRemove.push(key);
			}
		}

		for (key in keysToRemove)
		{
			currentCachedTextures.remove(key);
		}

		keysToRemove = [];
		for (key in previousCachedTextures.keys())
		{
			if (key.contains("characters"))
			{
				keysToRemove.push(key);
			}
		}

		for (key in keysToRemove)
		{
			previousCachedTextures.remove(key);
		}

		trace('[CACHE] Cleared character cache references');
	}

	/**
	 * Clears all stage-related assets from cache.
	 */
	static public function clearStages():Void
	{
		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!key.contains("stages"))
				continue;

			if (permanentCachedTextures.exists(key))
				continue;

			keysToRemove.push(key);
		}

		for (key in keysToRemove)
		{
			var graphic = FlxG.bitmap.get(key);
			currentCachedTextures.remove(key);
			previousCachedTextures.remove(key);
			destroyGraphic(key, graphic);
		}

		trace('[CACHE] Cleared stage assets');
	}
}
