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

#if sys
import sys.FileSystem;
#end

using StringTools;

/**
 * Handles caching of textures and sounds for the game.
 * Mirrors Funkin's FunkinMemory: every cache operation is synchronous,
 * no worker pool, no lime.app.Future machinery, no pending-decode joins.
 *
 * The JTC-specific extension methods (cacheCharacter, cacheStage,
 * cacheAsset, byte-array caching, song-sound cleanup, library barrier)
 * live alongside the Funkin-style primitives because external callers
 * (PlayState, Paths, CacheState, ChartingState, PlayLua, mod DialogueBuilders)
 * depend on them. The "parallel" / "async" entry points are kept as serial
 * loops so the call sites compile without churn.
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
	 * Caches textures and sounds that are always required.
	 */
	public static function initialCache():Void
	{
		var allImages:Array<String> = OpenFlAssets.list(AssetType.IMAGE);

		for (file in allImages)
		{
			if (!file.endsWith(".png") || file.contains("chart-editor") || !file.contains("ui/"))
				continue;

			var normalized:String = file.replace(" ", "");
			if (!normalized.contains("shared") && normalized.indexOf(":") < 0)
			{
				if (OpenFlAssets.exists('shared:$normalized', AssetType.IMAGE))
					normalized = 'shared:$normalized';
			}
			else if (normalized.indexOf(":") < 0)
			{
				normalized = 'shared:$normalized';
			}

			permanentCacheTexture(normalized);
		}

		for (key in [
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
			if (key != null && key != "") permanentCacheTexture(key);
		}

		var allSounds:Array<String> = OpenFlAssets.list(AssetType.SOUND);

		for (file in allSounds)
		{
			if (!file.endsWith(".ogg") || !file.contains("countdown/")) continue;

			var normalized:String = file.replace(" ", "");
			if (!normalized.contains("shared") && normalized.indexOf(":") < 0)
			{
				if (OpenFlAssets.exists('shared:$normalized', AssetType.SOUND))
					normalized = 'shared:$normalized';
			}
			else if (normalized.indexOf(":") < 0)
			{
				normalized = 'shared:$normalized';
			}

			permanentCacheSound(normalized);
		}

		for (key in [
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
			if (key != null) permanentCacheSound(key);
		}
	}

	/**
	 * Clears the current texture and sound caches.
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

	///// LIBRARIES /////

	/**
	 * Mirrors Funkin's LoadingState.checkLibrary pattern. Desktop libraries are
	 * preload="true" in the project manifest, so getLibrary returns non-null
	 * and the barrier fires onReady() synchronously. Web targets still go
	 * through lime's async loadLibrary.
	 */
	public static function ensureLibrariesLoaded(libraries:Array<String>, onReady:Void->Void):Void
	{
		if (onReady == null) return;
		if (libraries == null || libraries.length == 0)
		{
			onReady();
			return;
		}

		var unique:Array<String> = [];
		for (lib in libraries)
		{
			if (lib == null || lib == "") continue;
			if (unique.indexOf(lib) == -1) unique.push(lib);
		}

		if (unique.length == 0)
		{
			onReady();
			return;
		}

		var remaining:Int = unique.length;
		var fired:Bool = false;
		var step = function():Void
		{
			remaining--;
			if (remaining <= 0 && !fired)
			{
				fired = true;
				onReady();
			}
		};

		for (lib in unique)
		{
			if (lime.utils.Assets.getLibrary(lib) != null)
			{
				step();
				continue;
			}

			@:privateAccess
			var paths = lime.utils.Assets.libraryPaths;
			if (paths == null || !paths.exists(lib))
			{
				// No such library declared — treat as ready rather than hang the barrier.
				step();
				continue;
			}

			lime.utils.Assets.loadLibrary(lib).onComplete(function(_):Void
			{
				step();
			}).onError(function(_):Void
			{
				step();
			});
		}
	}

	///// TEXTURES /////

	/**
	 * Ensures a texture with the given key is cached.
	 */
	public static function cacheTexture(key:String):Void
	{
		if (key == null || key == "")
			return;

		if (currentCachedTextures.exists(key))
			return;

		if (previousCachedTextures.exists(key))
		{
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
	 * Serial cache of multiple textures. Funkin doesn't have a parallel
	 * primitive — the name is preserved for API compatibility with existing
	 * callers, but every key is now decoded + uploaded on the main thread.
	 */
	public static function parallelCacheTextures(keys:Array<String>):Void
	{
		if (keys == null) return;
		for (key in keys) cacheTexture(key);
	}

	/**
	 * Resolve every texture key the song needs — stage background plus
	 * each character JSON's `file` field — and cache them serially.
	 * Mirrors what PlayState.create's serial Cache.cacheStage / cacheCharacter
	 * calls cover, just batched into one entry point.
	 */
	public static function parallelPrewarmSong(stagePath:String, player1:String, player2:String, gfVersion:String):Void
	{
		var keys:Array<String> = [];

		appendStageTextureKeys(keys, stagePath);
		appendCharacterTextureKeys(keys, player1);
		appendCharacterTextureKeys(keys, player2);
		appendCharacterTextureKeys(keys, gfVersion);

		for (key in keys) cacheTexture(key);
	}

	static function appendStageTextureKeys(into:Array<String>, stagePath:String):Void
	{
		if (stagePath == null || stagePath == "") return;

		var key:String = Paths.getPath('images/stages/$stagePath.png', AssetType.IMAGE, null);
		if (key != null && key != "" && !into.contains(key)) into.push(key);
	}

	static function appendCharacterTextureKeys(into:Array<String>, characterPath:String):Void
	{
		if (characterPath == null || characterPath == "") return;

		var info:ConfigCharacters = null;
		try
		{
			info = Character.loadInfo('characters/$characterPath');
		}
		catch (e:Dynamic) {}

		if (info != null && info.file != null && info.file.trim() != "")
		{
			for (file in info.file.split(","))
			{
				var trimmed:String = file.trim();
				if (trimmed == "") continue;

				var extensionIndex:Int = trimmed.lastIndexOf(".");
				var basePath:String = extensionIndex >= 0 ? trimmed.substr(0, extensionIndex) : trimmed;
				var key:String = Paths.getPath('images/$basePath.png', AssetType.IMAGE, null);

				if (key != null && key != "" && !into.contains(key)) into.push(key);
			}

			return;
		}

		// No JSON: assume a single PNG at images/characters/<name>.png.
		var fallback:String = Paths.getPath('images/characters/$characterPath.png', AssetType.IMAGE, null);
		if (fallback != null && fallback != "" && !into.contains(fallback)) into.push(fallback);
	}

	/**
	 * Permanently caches a texture with the given key.
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
		currentCachedTextures.set(key, graphic);
		forceRender(graphic);
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

	public static inline function preparePurgeTextureCache():Void
	{
		previousCachedTextures = currentCachedTextures;
		currentCachedTextures = permanentCachedTextures.copy();

		for (graphicKey in previousCachedTextures.keys())
		{
			if (permanentCachedTextures.exists(graphicKey))
				previousCachedTextures.remove(graphicKey);
		}
	}

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

		var sprite = new FlxSprite();
		sprite.loadGraphic(graphic);
		sprite.draw();

		if (graphic.bitmap != null && FlxG.stage != null && FlxG.stage.context3D != null)
		{
			graphic.bitmap.getTexture(FlxG.stage.context3D);
		}

		sprite.destroy();
	}

	public static function isTextureCached(key:String):Bool
	{
		return FlxG.bitmap.get(key) != null
			&& (permanentCachedTextures.exists(key) || currentCachedTextures.exists(key) || previousCachedTextures.exists(key));
	}

	///// SOUND //////

	public static function cacheSound(key:String):Void
	{
		if (key == null || key == "")
			return;

		if (currentCachedSounds.exists(key))
			return;

		if (previousCachedSounds.exists(key))
		{
			var sound:Sound = previousCachedSounds.get(key);
			previousCachedSounds.remove(key);
			if (sound != null)
				currentCachedSounds.set(key, sound);
			return;
		}

		var sound:Sound = decodeSoundForKey(key);
		if (sound == null)
			return;

		currentCachedSounds.set(key, sound);
	}

	static function decodeSoundForKey(key:String):Sound
	{
		if (key == null || key == "") return null;

		try
		{
			if (OpenFlAssets.exists(key, AssetType.SOUND) || OpenFlAssets.exists(key, AssetType.MUSIC))
				return OpenFlAssets.getSound(key, true);
		}
		catch (e:Dynamic) {}

		#if sys
		try
		{
			if (FileSystem.exists(key))
				return Sound.fromFile(key);
		}
		catch (e:Dynamic) {}
		#end

		return null;
	}

	/**
	 * Serial cache of multiple sounds. Funkin doesn't have a parallel sound
	 * primitive — the name is preserved for API compatibility.
	 */
	public static function beginAsyncCacheSounds(keys:Array<String>):Void
	{
		if (keys == null) return;
		for (key in keys) cacheSound(key);
	}

	/**
	 * No-op. All sound caching is synchronous now, so by the time any caller
	 * reaches this point every prior cache request has already completed.
	 */
	public static function awaitPendingSounds(maxWaitMs:Int = 2000):Void {}

	/**
	 * Cache the instrumental + vocals for a song.
	 */
	public static function parallelPrewarmSongAudio(song:String):Void
	{
		if (song == null || song == "") return;

		var keys:Array<String> = [];
		appendSongSoundKey(keys, song, "Inst");

		if (Paths.songSoundExists(song, "1_Voices") && Paths.songSoundExists(song, "2_Voices"))
		{
			appendSongSoundKey(keys, song, "1_Voices");
			appendSongSoundKey(keys, song, "2_Voices");
		}
		else if (Paths.songSoundExists(song, "Voices"))
		{
			appendSongSoundKey(keys, song, "Voices");
		}

		for (key in keys) cacheSound(key);
	}

	static function appendSongSoundKey(into:Array<String>, song:String, soundFile:String):Void
	{
		var key:String = Paths.getSongSoundPath(song, soundFile);
		if (key != null && key != "" && !into.contains(key)) into.push(key);
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
	 */
	static function permanentCacheSound(key:String):Void
	{
		if (key == null || permanentCachedSounds.exists(key))
			return;

		if (!OpenFlAssets.exists(key, AssetType.SOUND) && !OpenFlAssets.exists(key, AssetType.MUSIC))
			return;

		var sound:Sound = OpenFlAssets.getSound(key, true);
		if (sound == null)
			return;

		permanentCachedSounds.set(key, sound);
		currentCachedSounds.set(key, sound);
	}

	public static function preparePurgeSoundCache():Void
	{
		previousCachedSounds = currentCachedSounds;
		currentCachedSounds = permanentCachedSounds.copy();

		for (key in previousCachedSounds.keys())
		{
			if (permanentCachedSounds.exists(key))
				previousCachedSounds.remove(key);
		}
	}

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

	public static function preparePurgeCache():Void
	{
		preparePurgeTextureCache();
		preparePurgeSoundCache();
	}

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

	public static inline function clearFreeplay():Void
	{
		clearByContains("freeplay");
		preparePurgeSoundCache();
		purgeSoundCache();
	}

	public static inline function clearCharacters():Void
	{
		clearByContains("characters");
	}

	public static inline function clearStages():Void
	{
		clearByContains("stages");
	}

	public static inline function clearStickers():Void
	{
		clearByContains("stickers");
	}

	static function clearByContains(substr:String):Void
	{
		var keysToRemove:Array<String> = [];

		@:privateAccess
		for (key in FlxG.bitmap._cache.keys())
		{
			if (!key.contains(substr))
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

	///// LEGACY API /////

	public static function cacheCharacter(characterPath:String):Void
	{
		if (characterPath == null || characterPath == "")
			return;

		var characterInfo:ConfigCharacters = null;
		try
		{
			characterInfo = Character.loadInfo('characters/$characterPath');
		}
		catch (e) {}

		if (characterInfo != null && characterInfo.file != null && characterInfo.file.trim() != "")
		{
			for (file in characterInfo.file.split(","))
			{
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
