package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import haxe.io.Bytes;
import haxe.io.Path;
import openfl.display.BitmapData;
import openfl.media.Sound;
import lime.net.HTTPRequest;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import lime.utils.Assets;
import haxe.Json;

import ModInitialize;
import json2object.JsonParser;

#if sys
import sys.FileSystem;
import sys.io.File;
#end

using StringTools;

class Paths
{
	inline public static var SOUND_EXT = #if web "mp3" #else "ogg" #end;
	inline static var REMOTE_FUNKIN_ASSETS_REPO:String = "https://github.com/FunkinCrew/funkin.assets.git";
	inline static var REMOTE_FUNKIN_ASSETS_MAIN:String = "https://raw.githubusercontent.com/FunkinCrew/funkin.assets/main/";
	inline static var REMOTE_FUNKIN_ASSETS_MASTER:String = "https://raw.githubusercontent.com/FunkinCrew/funkin.assets/master/";
	inline static var REMOTE_CACHE_ROOT:String = ".funkin_asset_cache";

	@:isVar public static var modJSON(get, never):ConfigDef;

	static var currentLevel:String;
	static var remoteAssetCache:Map<String, String> = [];
	static var remoteAssetMisses:Map<String, Bool> = [];

	static function get_modJSON():ConfigDef {
		if(!OpenFlAssets.exists("config/mod.json")) {
		    return null;
		}

		if(modJSON == null) {
			var parser = new JsonParser<ConfigDef>();
			var content = OpenFlAssets.getText("config/mod.json");

			return parser.fromJson(content, "mod.json");
		}else {
			return modJSON;
		}
	}

	static public function getCoreAssets():String {
		#if macos
		return "../Resources/";
		#else
		return "";
		#end
	}

	static public function setCurrentLevel(name:String)
	{
		currentLevel = name.toLowerCase();
	}

	static function normalizeLibrary(library:Null<String>):String
	{
		if (library == null || library == "" || library == "default")
			return "preload";

		return library;
	}

	static function getBuiltInAssetId(file:String, library:Null<String>):String
	{
		var normalizedLibrary = normalizeLibrary(library);

		if (normalizedLibrary == "preload")
			return 'assets/$file';

		return '$normalizedLibrary:assets/$normalizedLibrary/$file';
	}

	static function builtInAssetExists(path:String, type:AssetType):Bool
	{
		if (path == null || path == "")
			return false;

		return type != null ? OpenFlAssets.exists(path, type) : OpenFlAssets.exists(path);
	}

	static function getRuntimePathCandidates(file:String, library:Null<String>):Array<String>
	{
		var normalizedLibrary = normalizeLibrary(library);
		var candidates:Array<String> = ['mod_assets/$file'];
		var remoteRelativeCandidates = getRemoteRelativeCandidates(file, library);

		for (remoteRelativePath in remoteRelativeCandidates)
			candidates.push('$REMOTE_CACHE_ROOT/$remoteRelativePath');

		if (normalizedLibrary == "preload")
		{
			if (file.startsWith("characters/"))
				candidates.push('funkin_assets/preload/data/$file');

			if (file.startsWith("fonts/") || file.startsWith("videos/"))
				candidates.push('funkin_assets/$file');
			else
				candidates.push('funkin_assets/preload/$file');

			candidates.push('funkin_assets/$file');
		}
		else
		{
			candidates.push('funkin_assets/$normalizedLibrary/$file');
		}

		return candidates;
	}

	static function resolveLocalPath(file:String, library:Null<String>):String
	{
		#if sys
		for (path in getRuntimePathCandidates(file, library))
		{
			if (FileSystem.exists(path))
				return path;
		}
		#end

		return null;
	}

	static function getRemoteRelativeCandidates(file:String, library:Null<String>):Array<String>
	{
		var normalizedLibrary = normalizeLibrary(library);
		var candidates:Array<String> = [];

		if (normalizedLibrary == "preload")
		{
			if (file.startsWith("characters/"))
				candidates.push('preload/data/$file');

			if (file.startsWith("fonts/") || file.startsWith("videos/"))
				candidates.push(file);
			else
				candidates.push('preload/$file');

			candidates.push(file);
		}
		else
		{
			candidates.push('$normalizedLibrary/$file');
		}

		return candidates;
	}

	static function ensureDirectory(path:String):Void
	{
		#if sys
		if (path == null || path == "" || path == "." || FileSystem.exists(path))
			return;

		ensureDirectory(Path.directory(path));
		FileSystem.createDirectory(path);
		#end
	}

	static function downloadRemoteAsset(file:String, library:Null<String>):String
	{
		#if sys
		var relativeCandidates = getRemoteRelativeCandidates(file, library);

		for (remoteRelativePath in relativeCandidates)
		{
			var cacheKey = remoteRelativePath;

			if (remoteAssetCache.exists(cacheKey))
			{
				var cachedPath = remoteAssetCache.get(cacheKey);
				if (cachedPath != null && FileSystem.exists(cachedPath))
					return cachedPath;
			}

			if (remoteAssetMisses.exists(cacheKey))
				continue;

			var localPath = '$REMOTE_CACHE_ROOT/$remoteRelativePath';
			if (FileSystem.exists(localPath))
			{
				remoteAssetCache.set(cacheKey, localPath);
				return localPath;
			}

			ensureDirectory(Path.directory(localPath));

			for (baseUrl in [REMOTE_FUNKIN_ASSETS_MAIN, REMOTE_FUNKIN_ASSETS_MASTER])
			{
				try
				{
					var request = new HTTPRequest<Bytes>(baseUrl + remoteRelativePath);
					var bytes = request.load().result(request.timeout);

					if (bytes != null)
					{
						File.saveBytes(localPath, bytes);
						remoteAssetCache.set(cacheKey, localPath);
						trace('Fetched missing asset from ' + REMOTE_FUNKIN_ASSETS_REPO + ' -> ' + remoteRelativePath);
						return localPath;
					}
				}
				catch (e:Dynamic)
				{
					trace('Remote asset fetch failed for ' + remoteRelativePath + ' from ' + baseUrl + ' -> ' + Std.string(e));
				}
			}

			remoteAssetMisses.set(cacheKey, true);
		}
		#end

		return null;
	}

	static function downloadDirectRemoteAsset(relativePath:String):String
	{
		#if sys
		var cacheKey = relativePath;

		if (remoteAssetCache.exists(cacheKey))
		{
			var cachedPath = remoteAssetCache.get(cacheKey);
			if (cachedPath != null && FileSystem.exists(cachedPath))
				return cachedPath;
		}

		if (remoteAssetMisses.exists(cacheKey))
			return null;

		var localPath = '$REMOTE_CACHE_ROOT/$relativePath';
		if (FileSystem.exists(localPath))
		{
			remoteAssetCache.set(cacheKey, localPath);
			return localPath;
		}

		ensureDirectory(Path.directory(localPath));

		for (baseUrl in [REMOTE_FUNKIN_ASSETS_MAIN, REMOTE_FUNKIN_ASSETS_MASTER])
		{
			try
			{
				var request = new HTTPRequest<Bytes>(baseUrl + relativePath);
				var bytes = request.load().result(request.timeout);

				if (bytes != null)
				{
					File.saveBytes(localPath, bytes);
					remoteAssetCache.set(cacheKey, localPath);
					trace('Fetched missing asset from ' + REMOTE_FUNKIN_ASSETS_REPO + ' -> ' + relativePath);
					return localPath;
				}
			}
			catch (e:Dynamic)
			{
				trace('Remote asset fetch failed for ' + relativePath + ' from ' + baseUrl + ' -> ' + Std.string(e));
			}
		}

		remoteAssetMisses.set(cacheKey, true);
		#end

		return null;
	}

	static function resolveRuntimePath(file:String, type:AssetType, library:Null<String>):String
	{
		var localPath = resolveLocalPath(file, library);
		if (localPath != null)
			return localPath;

		var builtInAssetId = getBuiltInAssetId(file, library);
		if (builtInAssetExists(builtInAssetId, type))
			return builtInAssetId;

		var remotePath = downloadRemoteAsset(file, library);
		if (remotePath != null)
			return remotePath;

		return builtInAssetId;
	}

	static public function assetExists(path:String, ?type:AssetType):Bool
	{
		if (path == null || path == "")
			return false;

		if (OpenFlAssets.exists(path, type))
			return true;

		#if sys
		return FileSystem.exists(path);
		#else
		return false;
		#end
	}

	static public function readText(path:String):String
	{
		if (path == null || path == "")
			return "";

		if (OpenFlAssets.exists(path, TEXT))
			return OpenFlAssets.getText(path);

		#if sys
		if (FileSystem.exists(path))
			return File.getContent(path);
		#end

		return "";
	}

	static public function loadBitmap(path:String):BitmapData
	{
		if (path == null || path == "")
			return null;

		if (OpenFlAssets.exists(path, IMAGE))
			return OpenFlAssets.getBitmapData(path);

		#if sys
		if (FileSystem.exists(path))
			return BitmapData.fromFile(path);
		#end

		return null;
	}

	static public function loadSoundAsset(path:String):Sound
	{
		if (path == null || path == "")
			return null;

		if (OpenFlAssets.exists(path, SOUND) || OpenFlAssets.exists(path, MUSIC))
			return OpenFlAssets.getSound(path, true);

		#if sys
		if (FileSystem.exists(path))
			return Sound.fromFile(path);
		#end

		return null;
	}

	static public function getPath(file:String, type:AssetType, library:Null<String>)
	{
		if (library != null)
			return getLibraryPath(file, library);

		if (currentLevel != null)
		{
			var levelPath = getLibraryPathForce(file, currentLevel);
			if (assetExists(levelPath, type))
				return levelPath;

			levelPath = getLibraryPathForce(file, "shared");
			if (assetExists(levelPath, type))
				return levelPath;
		}

		return getPreloadPath(file);
	}

	static public function getLibraryPath(file:String, library = "preload")
	{
		var normalizedLibrary = normalizeLibrary(library);
		return if (normalizedLibrary == "preload") getPreloadPath(file); else getLibraryPathForce(file, normalizedLibrary);
	}

	inline static function getLibraryPathForce(file:String, library:String)
	{
		return resolveRuntimePath(file, null, library);
	}

	inline static public function getPreloadPath(file:String)
	{
		return resolveRuntimePath(file, null, "preload");
	}

	inline static public function file(file:String, type:AssetType = TEXT, ?library:String)
	{
		return getPath(file, type, library);
	}

	inline static public function xml(key:String, ?library:String)
	{
		return getPath('data/$key.xml', TEXT, library);
	}

	inline static public function soundRandom(key:String, min:Int, max:Int, ?library:String)
	{
		return sound(key + FlxG.random.int(min, max), library);
	}

	inline static public function font(key:String)
	{
		var path = getPreloadPath('fonts/$key');
		if(assetExists(path, FONT)) {
			return path;
		}else {
			return "";
		}
	}

	inline static public function mora(key:String, type:String, ?library:String)
	{
		var path = getPath('feeshdata/$key.$type', TEXT, library);
		if(assetExists(path, TEXT))
			return path;
		else {
			trace("Error: could not locate file - " + '$key.$type');
			return "";
		}
	}

	inline static public function txt(key:String, ?library:String)
	{
		var path = getPath('data/$key.txt', TEXT, library);
		if(assetExists(path, TEXT))
			return path;
		else {
			trace("Warning: could not locate text file - " + key);
			return "";
		}
	}

	inline static public function pak(key:String,?library:String)
	{
		var path = getPath('pakdata/$key.pak', TEXT, library);
		if(assetExists(path, TEXT))
			return path;
		else {
			trace("Error: could not locate pak file - " + key);
			return "";
		}
	}

	inline static public function json(key:String, ?library:String)
	{
		var path = getPath('data/$key.json', TEXT, library);
		if(assetExists(path, TEXT))
			return path;
		else {
			trace("Error: could not locate json file - " + path);
			return "";
		}
	}

	inline static public function shader(key:String, ?library:String) {
		var path = getPath('shaders/$key', TEXT, library);
		if(assetExists(path, TEXT))
			return path;
		else {
			trace("Error: could not locate glsl file - " + path);
			return "";
		}
	}

	inline static public function getPackerAtlas(key:String, ?library:String, ?cache:Bool)
	{
		var cacheFile:String = "";

		if(cache)
			cacheFile = "cache/";

		if(assetExists('mod_assets/images/$key.png', IMAGE)
		&& assetExists('mod_assets/images/$key.xml', TEXT)) {
			cacheFile = "";
			library = "";
		}

		var cachedImage:FlxGraphic = ifImageCached(cacheFile + key, library);
		var descriptionPath = file('images/' + cacheFile + key + '.txt', library);

		if(assetExists(descriptionPath, TEXT)) {
			return FlxAtlasFrames.fromSpriteSheetPacker(cachedImage != null ? cachedImage : image(cacheFile + key, library), readText(descriptionPath));
		}else {
			trace("Error: could not locate asset - " + descriptionPath);
			return null;
		}
	}

	inline static public function video(key:String) {
		return getPreloadPath("videos/" + key);
	}

	inline static function ifImageCached(key:String, ?library:String):FlxGraphic {
		var asset:FlxGraphic = Cache.getAsset(key, library);
		return asset;
	}

	inline static public function sound(key:String, ?library:String)
	{
		var path = getPath('sounds/$key.$SOUND_EXT', SOUND, library);
		var sound = loadSoundAsset(path);

		if(sound != null) {
			return sound;
		}else {
			trace("Error: could not locate sound - " + key);
			return null;
		}
	}

	inline static public function music(key:String, ?library:String)
	{
		var path = getPath('music/$key.$SOUND_EXT', MUSIC, library);
		var music = loadSoundAsset(path);

		if(music != null) {
			return music;
		}else {
			trace("Error: could not locate music - " + key);
			return null;
		}
	}

	static function getSongSoundPath(song:String, soundFile:String):String
	{
		var relativePath = 'songs/${song.toLowerCase()}/$soundFile.$SOUND_EXT';
		var builtInAssetId = 'songs:assets/$relativePath';

		#if sys
		for (path in ['mod_assets/$relativePath', '$REMOTE_CACHE_ROOT/$relativePath', 'funkin_assets/$relativePath'])
		{
			if (FileSystem.exists(path))
				return path;
		}
		#end

		if (OpenFlAssets.exists(builtInAssetId, SOUND) || OpenFlAssets.exists(builtInAssetId, MUSIC))
			return builtInAssetId;

		var remotePath = downloadDirectRemoteAsset(relativePath);
		if (remotePath != null)
			return remotePath;

		return builtInAssetId;
	}

	inline static public function songSoundExists(song:String, soundFile:String):Bool
	{
		return assetExists(getSongSoundPath(song, soundFile), SOUND);
	}

	inline static public function songSound(song:String, soundFile:String)
	{
		var path = getSongSoundPath(song, soundFile);
		var sound = loadSoundAsset(path);

		if(sound != null) {
			return sound;
		}else {
			trace("Error: could not locate song audio - " + song + "/" + soundFile + "." + SOUND_EXT);
			return null;
		}
	}

	inline static public function voices(song:String, ?suffix:String = "")
	{
		if(suffix == null)
			suffix = "";

		return songSound(song, 'Voices$suffix');
	}
	
	inline static public function inst(song:String)
	{
		return songSound(song, "Inst");
	}

	inline static public function getSparrowAtlas(key:String, ?library:String, ?cache:Bool)
	{
		var cacheFile:String = "";

		if(cache) {
			cacheFile = "cache/";
		}

		if(assetExists('mod_assets/images/$key.png', IMAGE)
		&& assetExists('mod_assets/images/$key.xml', TEXT)) {
			cacheFile = "";
			library = "";
		}

		var cachedImage:FlxGraphic = ifImageCached(cacheFile + key, library);
		var descriptionPath = file('images/' + cacheFile + key + '.xml', library);

		if(assetExists(descriptionPath, TEXT)) {
			return FlxAtlasFrames.fromSparrow(cachedImage != null ? cachedImage : image(cacheFile + key, library), readText(descriptionPath));
		}else {
			trace("Error: could not locate asset - " + descriptionPath);
			return null;
		}
	}

	inline static public function getNoteAtlas(key:String, library:String = "shared") {
		return getSparrowAtlas("notes/" + key, library);
	}

	static public function image(key:String, ?library:String):FlxGraphic {
		var cachedImage:FlxGraphic = ifImageCached(key, library);

		if(cachedImage != null) {
			return cachedImage;
		}

		var path = getPath('images/$key.png', IMAGE, library);
		var bitmap = loadBitmap(path);

		if(bitmap != null) {
			var graphics:FlxGraphic = FlxGraphic.fromBitmapData(bitmap, false, path);
			graphics.persist = false;
			return graphics;
		}else {
			//trace("Error: could not locate asset - " + file('images/$key.png', library));
			return null;
		}
	}

	static public function lua(key:String) {
		var path = getPath('scripts/$key.lua', TEXT, null);
		if(assetExists(path, TEXT)) {
			return path;
		}else {
			trace("Error: could not locate asset - " + path);
			return "";
		}
	}
}
