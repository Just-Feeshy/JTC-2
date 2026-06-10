package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import lime.app.Future;
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
 * Based on FunkinMemory from Friday Night Funkin'.
 *
 * The "parallel" APIs use lime.app.Future with useThreads=true so OGG / PNG
 * decode actually runs on the lime worker pool. The GL upload step for
 * textures (FlxGraphic.fromBitmapData + forceRender) always happens on the
 * main thread because the GL context lives there.
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

	// Sound keys whose decode has been kicked off on a worker thread but
	// haven't landed in currentCachedSounds yet. getCachedSound() / cacheSound()
	// wait on these so that if the main thread asks for the sound before the
	// worker finishes, it joins the in-flight decode instead of racing it.
	static var pendingSoundFutures:Map<String, Future<Sound>> = new Map<String, Future<Sound>>();

	static var threadPoolConfigured:Bool = false;

	static var purgeFilter:Array<String> = ["/week", "/characters", "/charSelect", "/results", "/stages"];

	static function ensureThreadPool():Void
	{
		if (threadPoolConfigured) return;
		threadPoolConfigured = true;
		// lime defaults to minThreads=0, maxThreads=1 which collapses parallel
		// Futures into a serial queue. Open it up so multiple OGG / PNG
		// decodes can actually run side-by-side.
		#if (lime_threads && !html5)
		lime.app.FutureWork.minThreads = 2;
		lime.app.FutureWork.maxThreads = 4;
		#end
	}

	/**
	 * Caches textures that are always required.
	 */
	public static function initialCache():Void
	{
		ensureThreadPool();

		var uiTextureKeys:Array<String> = [];
		var allImages:Array<String> = OpenFlAssets.list(AssetType.IMAGE);

		for (file in allImages)
		{
			if (!file.endsWith(".png") || file.contains("chart-editor") || !file.contains("ui/"))
				continue;

			var normalizedFile = file.replace(" ", "");
			// Fast path: a key whose library prefix already names "shared" needs no
			// fix-up; same for keys that are already library-qualified ("foo:...").
			// Only run the (expensive) Assets.exists probe when we genuinely don't
			// know whether the shared library claims this asset.
			if (!normalizedFile.contains("shared") && normalizedFile.indexOf(":") < 0)
			{
				if (OpenFlAssets.exists('shared:$normalizedFile', AssetType.IMAGE))
					normalizedFile = 'shared:$normalizedFile';
			}
			else if (normalizedFile.indexOf(":") < 0)
			{
				normalizedFile = 'shared:$normalizedFile';
			}

			uiTextureKeys.push(normalizedFile);
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
			if (texture != null && texture != "" && !uiTextureKeys.contains(texture))
				uiTextureKeys.push(texture);
		}

		permanentParallelCacheTextures(uiTextureKeys);

		var soundKeys:Array<String> = [];
		var allSounds:Array<String> = OpenFlAssets.list(AssetType.SOUND);

		for (file in allSounds)
		{
			if (!file.endsWith(".ogg") || !file.contains("countdown/"))
				continue;

			var normalizedFile = file.replace(" ", "");
			if (!normalizedFile.contains("shared") && normalizedFile.indexOf(":") < 0)
			{
				if (OpenFlAssets.exists('shared:$normalizedFile', AssetType.SOUND))
					normalizedFile = 'shared:$normalizedFile';
			}
			else if (normalizedFile.indexOf(":") < 0)
			{
				normalizedFile = 'shared:$normalizedFile';
			}

			soundKeys.push(normalizedFile);
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
			if (sound != null && !soundKeys.contains(sound))
				soundKeys.push(sound);
		}

		permanentParallelCacheSounds(soundKeys);
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

	///// LIBRARIES /////

	/**
	 * Ensure each of the given asset libraries is loaded, then fire onReady.
	 * Mirrors Funkin's LoadingState.checkLibrary pattern: libraries that
	 * are already resident fire instantly; ones that aren't go through
	 * lime's async Assets.loadLibrary and join the barrier.
	 *
	 * On desktop targets the project ships every library with preload="true",
	 * so this almost always fast-paths to an immediate onReady().
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
				// No such library declared in the manifest — treat as ready
				// rather than hang the barrier forever.
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
		parallelCacheTexturesInternal(keys, false);
	}

	static function permanentParallelCacheTextures(keys:Array<String>):Void
	{
		parallelCacheTexturesInternal(keys, true);
	}

	static function parallelCacheTexturesInternal(keys:Array<String>, permanent:Bool):Void
	{
		if (keys == null || keys.length == 0)
			return;

		ensureThreadPool();

		var workKeys:Array<String> = [];
		var workFutures:Array<Future<BitmapData>> = [];

		for (key in keys)
		{
			if (key == null || key == "") continue;

			// Already in a hot map: nothing to do (or just promote from previous).
			if (permanent ? permanentCachedTextures.exists(key) : currentCachedTextures.exists(key))
				continue;

			if (!permanent && previousCachedTextures.exists(key))
			{
				var graphic:FlxGraphic = previousCachedTextures.get(key);
				previousCachedTextures.remove(key);
				if (graphic != null) currentCachedTextures.set(key, graphic);
				continue;
			}

			workKeys.push(key);
			workFutures.push(new Future<BitmapData>(function() return decodeBitmapForKey(key), true));
		}

		if (workKeys.length == 0) return;

		for (i in 0...workKeys.length)
		{
			var key:String = workKeys[i];
			var bitmap:BitmapData = workFutures[i].result();
			uploadTextureBitmap(key, bitmap, permanent);
		}
	}

	static function decodeBitmapForKey(key:String):BitmapData
	{
		if (key == null || key == "") return null;

		// OpenFL's Assets.getBitmapData ultimately uses the lime image decoder.
		// It also touches its internal asset cache map, which can race with the
		// main thread; we accept the same risk Funkin's FunkinMemory async
		// prewarms accept. Sys file fallback is fully thread-safe.
		try
		{
			if (OpenFlAssets.exists(key, AssetType.IMAGE))
				return OpenFlAssets.getBitmapData(key, false);
		}
		catch (e:Dynamic) {}

		#if sys
		try
		{
			if (FileSystem.exists(key))
				return BitmapData.fromFile(key);
		}
		catch (e:Dynamic) {}
		#end

		return null;
	}

	static function uploadTextureBitmap(key:String, bitmap:BitmapData, permanent:Bool):Void
	{
		if (bitmap == null)
		{
			FlxG.log.warn('Failed to cache graphic: $key');
			return;
		}

		var graphic:FlxGraphic = FlxGraphic.fromBitmapData(bitmap, false, key);
		if (graphic == null)
		{
			FlxG.log.warn('Failed to cache graphic: $key');
			return;
		}

		graphic.persist = true;
		currentCachedTextures.set(key, graphic);
		if (permanent) permanentCachedTextures.set(key, graphic);
		forceRender(graphic);
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
			var sound:Sound = previousCachedSounds.get(key);
			previousCachedSounds.remove(key);
			if (sound != null)
				currentCachedSounds.set(key, sound);
			return;
		}

		// If a worker is already decoding this key, join its result rather than
		// kicking off a second decode of the same file on the main thread.
		if (pendingSoundFutures.exists(key))
		{
			var snd:Sound = pendingSoundFutures.get(key).result();
			pendingSoundFutures.remove(key);
			if (snd != null && !currentCachedSounds.exists(key))
				currentCachedSounds.set(key, snd);
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
	 * Fire-and-forget parallel sound caching. Spawns a worker-thread Future
	 * per key, returns immediately. getCachedSound() / cacheSound() join the
	 * pending Future if asked before the worker finishes.
	 */
	public static function beginAsyncCacheSounds(keys:Array<String>):Void
	{
		if (keys == null || keys.length == 0) return;

		ensureThreadPool();

		for (key in keys)
		{
			if (key == null || key == "") continue;
			if (currentCachedSounds.exists(key) || permanentCachedSounds.exists(key)) continue;
			if (pendingSoundFutures.exists(key)) continue;

			if (previousCachedSounds.exists(key))
			{
				var sound:Sound = previousCachedSounds.get(key);
				previousCachedSounds.remove(key);
				if (sound != null) currentCachedSounds.set(key, sound);
				continue;
			}

			var pending:Future<Sound> = new Future<Sound>(function() return decodeSoundForKey(key), true);
			pendingSoundFutures.set(key, pending);
			pending.onComplete(function(snd:Sound):Void
			{
				// onComplete fires on the main thread, so it's safe to touch
				// the cache maps from here.
				if (snd != null && !currentCachedSounds.exists(key))
					currentCachedSounds.set(key, snd);
				if (pendingSoundFutures.get(key) == pending)
					pendingSoundFutures.remove(key);
			});
		}
	}

	/**
	 * Block until every pending sound from beginAsyncCacheSounds finishes
	 * (or the per-key timeout elapses). Use as a sync point before code that
	 * needs all decoded audio available.
	 */
	public static function awaitPendingSounds(maxWaitMs:Int = 2000):Void
	{
		if (pendingSoundFutures.iterator().hasNext() == false) return;

		var snapshot:Array<String> = [for (k in pendingSoundFutures.keys()) k];

		for (key in snapshot)
		{
			var pending:Future<Sound> = pendingSoundFutures.get(key);
			if (pending == null) continue;

			var snd:Sound = pending.result(maxWaitMs);
			pendingSoundFutures.remove(key);
			if (snd != null && !currentCachedSounds.exists(key))
				currentCachedSounds.set(key, snd);
		}
	}

	static function permanentParallelCacheSounds(keys:Array<String>):Void
	{
		if (keys == null || keys.length == 0) return;

		ensureThreadPool();

		var workKeys:Array<String> = [];
		var workFutures:Array<Future<Sound>> = [];

		for (key in keys)
		{
			if (key == null || key == "") continue;
			if (permanentCachedSounds.exists(key)) continue;

			workKeys.push(key);
			workFutures.push(new Future<Sound>(function() return decodeSoundForKey(key), true));
		}

		for (i in 0...workKeys.length)
		{
			var key:String = workKeys[i];
			var snd:Sound = workFutures[i].result();
			if (snd == null) continue;

			permanentCachedSounds.set(key, snd);
			currentCachedSounds.set(key, snd);
		}
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

		// Worker-decoded but not yet landed in a cache map: block on it so the
		// caller gets a Sound instead of null. result() returns immediately if
		// the Future is already done.
		if (pendingSoundFutures.exists(path))
		{
			var pending:Future<Sound> = pendingSoundFutures.get(path);
			var snd:Sound = pending.result();
			pendingSoundFutures.remove(path);
			if (snd != null && !currentCachedSounds.exists(path))
				currentCachedSounds.set(path, snd);
			return snd;
		}

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
