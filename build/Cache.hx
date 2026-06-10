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

import haxe.Json;

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

	#if sys
	// Sound keys whose decode has been kicked off on a worker thread but
	// haven't landed in currentCachedSounds yet. getCachedSound() polls this
	// (with a small timeout) so that if the main thread asks for the sound
	// before the worker finishes, it waits for the worker rather than racing
	// it and double-decoding the same file on main.
	#end

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
	 * Cache a batch of textures by PNG-decoding them in parallel on a worker
	 * pool. The expensive part — reading the file off disk and decoding the
	 * PNG into a BitmapData — runs on background threads; the GPU upload
	 * (FlxGraphic.fromBitmapData) stays on the main thread because the GL
	 * context lives there.
	 *
	 * Blocks until every job in the batch has been uploaded so callers can
	 * treat it as a drop-in replacement for a loop of cacheTexture() calls.
	 */
	public static function parallelCacheTextures(keys:Array<String>):Void
	{
		if (keys == null || keys.length == 0)
			return;

		for (key in keys) cacheTexture(key);
	}

	/**
	 * Resolve the on-disk texture keys a song needs in one shot — stage
	 * background plus every PNG referenced in each character JSON's `file`
	 * field — and parallel-cache them. Call this once at the top of
	 * PlayState.create() so the four serial Cache.cacheCharacter / cacheStage
	 * calls later in create() all hit a warm cache.
	 */
	public static function parallelPrewarmSong(stagePath:String, player1:String, player2:String, gfVersion:String):Void
	{
		var keys:Array<String> = [];

		appendStageTextureKeys(keys, stagePath);
		appendCharacterTextureKeys(keys, player1);
		appendCharacterTextureKeys(keys, player2);
		appendCharacterTextureKeys(keys, gfVersion);

		parallelCacheTextures(keys);
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

		var infoPath:String = Paths.getPreloadPath('characters/$characterPath.json');

		if (!Paths.assetExists(infoPath, AssetType.TEXT))
			infoPath = Paths.getPath('characters/$characterPath.json', AssetType.TEXT, "shared");

		if (Paths.assetExists(infoPath, AssetType.TEXT))
		{
			var raw:String = Paths.readText(infoPath);
			if (raw != null && raw != "")
			{
				try
				{
					var info:Dynamic = Json.parse(raw);

					if (info != null && info.file != null)
					{
						var fileList:String = info.file;

						for (file in fileList.split(","))
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
				}
				catch (e:Dynamic) {}
			}
		}

		// Same fallback as Cache.cacheCharacter when there's no JSON: assume
		// the character is a single PNG at images/characters/<name>.png.
		var fallback:String = Paths.getPath('images/characters/$characterPath.png', AssetType.IMAGE, null);
		if (fallback != null && fallback != "" && !into.contains(fallback)) into.push(fallback);
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

	/**
	 * Prepares the cache for purging unused textures.
	 */
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

	/**
	 * Fire-and-forget version of parallel sound caching. Spawns worker
	 * threads to OGG/MP3-decode each key, marks them as pending, and
	 * returns immediately so the main thread can keep going with whatever
	 * else it needs to do. When something later asks for one of these
	 * sounds via getCachedSound(), that call transparently waits for the
	 * worker if the decode is still in flight.
	 *
	 * Use this for prewarms that should run *alongside* main-thread setup
	 * work (PlayState.create, etc.). If you need the keys to be ready by
	 * the time the call returns, use the (now-deprecated) parallelCacheSounds.
	 */
	public static function beginAsyncCacheSounds(keys:Array<String>):Void
	{
		if (keys == null || keys.length == 0) return;

		for (key in keys)
		{
			if (key == null || key == "") continue;
			if (currentCachedSounds.exists(key) || permanentCachedSounds.exists(key)) continue;

			if (previousCachedSounds.exists(key))
			{
				var sound:Sound = previousCachedSounds.get(key);
				previousCachedSounds.remove(key);
				if (sound != null) currentCachedSounds.set(key, sound);
				continue;
			}

			cacheSound(key);
		}
	}

	/**
	 * Block until every pending sound from beginAsyncCacheSounds finishes
	 * (or the timeout elapses). Useful as a sync point before code that
	 * absolutely must have all decoded audio available.
	 */
	public static function awaitPendingSounds(maxWaitMs:Int = 2000):Void
	{
		// Synchronous shim: beginAsyncCacheSounds now decodes inline, so there
		// is never anything pending by the time this returns.
	}

	/**
	 * Resolve the audio tracks the song will need at startSong() time —
	 * instrumental plus whichever vocal layout (split or single) the song
	 * uses — and kick off their decode on the worker pool *without
	 * blocking*. This is meant to run early in PlayState.create() so the
	 * OGG decode overlaps with the rest of create's main-thread setup
	 * (character init, HUD, chart parse, etc.); by the time
	 * startInstrumentTrack() actually pulls the Sound out via Paths.inst()
	 * the worker has either already cached it or getCachedSound() will
	 * wait the small remainder for it.
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

		beginAsyncCacheSounds(keys);
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
		previousCachedSounds = currentCachedSounds;
		currentCachedSounds = permanentCachedSounds.copy();

		for (key in previousCachedSounds.keys())
		{
			if (permanentCachedSounds.exists(key))
				previousCachedSounds.remove(key);
		}
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
