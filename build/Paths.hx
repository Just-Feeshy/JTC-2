package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import haxe.io.Bytes;
import openfl.display.BitmapData;
import openfl.events.Event;
import openfl.events.HTTPStatusEvent;
import openfl.events.IOErrorEvent;
import openfl.events.SecurityErrorEvent;
import openfl.media.Sound;
import openfl.net.URLLoader;
import openfl.net.URLLoaderDataFormat;
import openfl.net.URLRequest;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import openfl.utils.ByteArray;
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
	inline static var REMOTE_FUNKIN_ASSETS_DEVELOP:String = "https://raw.githubusercontent.com/FunkinCrew/funkin.assets/develop/";
	inline static var REMOTE_FUNKIN_ASSETS_MASTER:String = "https://raw.githubusercontent.com/FunkinCrew/funkin.assets/master/";

	@:isVar public static var modJSON(get, never):ConfigDef;

	static var currentLevel:String;
	static var remoteAssetMisses:Map<String, Bool> = [];
	static var remoteBytesCache:Map<String, Bytes> = [];
	static var remoteBytesPending:Map<String, Array<Bytes->Void>> = [];
	static var remoteSharedGraphicCache:Map<String, FlxGraphic> = [];
	static var remoteSharedGraphicPending:Map<String, Array<FlxGraphic->Void>> = [];
	static var remoteSharedAtlasCache:Map<String, FlxAtlasFrames> = [];
	static var remoteSharedAtlasPending:Map<String, Array<FlxAtlasFrames->Void>> = [];
	static var remoteSharedSoundCache:Map<String, Sound> = [];
	static var remoteSharedSoundPending:Map<String, Array<Sound->Void>> = [];

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

		if (type != null)
			return OpenFlAssets.exists(path, type);

		for (candidateType in [IMAGE, TEXT, SOUND, MUSIC, FONT, BINARY])
		{
			if (OpenFlAssets.exists(path, candidateType))
				return true;
		}

		return false;
	}

	static function getRuntimePathCandidates(file:String, library:Null<String>):Array<String>
	{
		var normalizedLibrary = normalizeLibrary(library);
		var candidates:Array<String> = ['mod_assets/$file'];

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

	static function resolveLocalOrBuiltInPath(file:String, type:AssetType, library:Null<String>):String
	{
		var localPath = resolveLocalPath(file, library);
		if (localPath != null)
			return localPath;

		var builtInAssetId = getBuiltInAssetId(file, library);
		if (builtInAssetExists(builtInAssetId, type))
			return builtInAssetId;

		return null;
	}

	static function resolveRuntimePath(file:String, type:AssetType, library:Null<String>):String
	{
		var resolvedPath = resolveLocalOrBuiltInPath(file, type, library);
		return resolvedPath != null ? resolvedPath : getBuiltInAssetId(file, library);
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
		{
			var embeddedBytes:ByteArray = OpenFlAssets.getBytes(path);
			var embeddedText:String = decodeTextBytes(embeddedBytes != null ? Bytes.ofData(embeddedBytes) : null);

			if (embeddedText != "")
				return embeddedText;

			return sanitizeTextContent(OpenFlAssets.getText(path));
		}

		#if sys
		if (FileSystem.exists(path))
		{
			var bytes:Bytes = File.getBytes(path);
			var decoded:String = decodeTextBytes(bytes);
			return decoded != "" ? decoded : sanitizeTextContent(bytes != null ? bytes.toString() : "");
		}
		#end

		return "";
	}

	static function decodeTextBytes(bytes:Bytes):String
	{
		if (bytes == null || bytes.length == 0)
			return "";

		if (bytes.length >= 2)
		{
			var first:Int = bytes.get(0);
			var second:Int = bytes.get(1);

			if ((first == 0xFF && second == 0xFE) || (first == 0xFE && second == 0xFF))
				return sanitizeTextContent(decodeUtf16Text(bytes));
		}

		return "";
	}

	static function decodeUtf16Text(bytes:Bytes):String
	{
		if (bytes == null || bytes.length == 0)
			return "";

		var littleEndian:Bool = true;
		var start:Int = 0;

		if (bytes.length >= 2)
		{
			var first:Int = bytes.get(0);
			var second:Int = bytes.get(1);

			if (first == 0xFF && second == 0xFE)
			{
				littleEndian = true;
				start = 2;
			}
			else if (first == 0xFE && second == 0xFF)
			{
				littleEndian = false;
				start = 2;
			}
		}

		var buffer = new StringBuf();
		var index:Int = start;

		while (index + 1 < bytes.length)
		{
			var codeUnit:Int = littleEndian
				? bytes.get(index) | (bytes.get(index + 1) << 8)
				: (bytes.get(index) << 8) | bytes.get(index + 1);

			if (codeUnit != 0 && codeUnit != 0xFEFF)
				buffer.addChar(codeUnit);

			index += 2;
		}

		return buffer.toString();
	}

	static function sanitizeTextContent(text:String):String
	{
		if (text == null || text == "")
			return "";

		if (text.charCodeAt(0) == 0xFEFF)
			text = text.substr(1);

		return text.replace("\x00", "");
	}

	static public function loadBitmap(path:String, useCache:Bool = true):BitmapData
	{
		if (path == null || path == "")
			return null;

		if (OpenFlAssets.exists(path, IMAGE))
			return OpenFlAssets.getBitmapData(path, useCache);

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

		var cachedSound:Sound = Cache.getCachedSound(path);
		if (cachedSound != null)
			return cachedSound;

		if (OpenFlAssets.exists(path, SOUND) || OpenFlAssets.exists(path, MUSIC))
			return OpenFlAssets.getSound(path, true);

		#if sys
		if (FileSystem.exists(path))
			return Sound.fromFile(path);
		#end

		return null;
	}

	static function loadRemoteBytes(relativePath:String, onComplete:Bytes->Void):Void
	{
		#if sys
		if (remoteBytesCache.exists(relativePath))
		{
			onComplete(remoteBytesCache.get(relativePath));
			return;
		}

		if (remoteAssetMisses.exists(relativePath))
		{
			onComplete(null);
			return;
		}

		if (remoteBytesPending.exists(relativePath))
		{
			remoteBytesPending.get(relativePath).push(onComplete);
			return;
		}

		remoteBytesPending.set(relativePath, [onComplete]);

		var baseUrls = [REMOTE_FUNKIN_ASSETS_MAIN, REMOTE_FUNKIN_ASSETS_DEVELOP, REMOTE_FUNKIN_ASSETS_MASTER];

		function finish(bytes:Bytes):Void
		{
			var callbacks = remoteBytesPending.get(relativePath);
			remoteBytesPending.remove(relativePath);

			if (bytes != null)
				remoteBytesCache.set(relativePath, bytes);
			else
				remoteAssetMisses.set(relativePath, true);

			if (callbacks != null)
			{
				for (callback in callbacks)
				{
					callback(bytes);
				}
			}
		}

		function tryBase(index:Int):Void
		{
			if (index >= baseUrls.length)
			{
				trace('Remote asset fetch failed for ' + relativePath);
				finish(null);
				return;
			}

			var baseUrl = baseUrls[index];
			var request = new URLRequest(baseUrl + relativePath);
			var loader = new URLLoader();
			var status:Int = 0;
			var handleStatus:HTTPStatusEvent->Void = null;
			var handleComplete:Event->Void = null;
			var handleIOError:IOErrorEvent->Void = null;
			var handleSecurityError:SecurityErrorEvent->Void = null;

			function cleanup():Void
			{
				loader.removeEventListener(Event.COMPLETE, handleComplete);
				loader.removeEventListener(IOErrorEvent.IO_ERROR, handleIOError);
				loader.removeEventListener(SecurityErrorEvent.SECURITY_ERROR, handleSecurityError);
				loader.removeEventListener(HTTPStatusEvent.HTTP_STATUS, handleStatus);
			}

			handleStatus = function(event:HTTPStatusEvent):Void
			{
				status = event.status;
			}

			handleComplete = function(_):Void
			{
				cleanup();

				var data:ByteArray = cast loader.data;
				var bytes:Bytes = data;

				if (bytes != null && bytes.length > 0)
				{
					finish(bytes);
				}
				else
				{
					trace('Remote asset fetch returned no data for ' + relativePath + ' from ' + baseUrl + ' (status ' + status + ')');
					tryBase(index + 1);
				}
			}

			handleIOError = function(event:IOErrorEvent):Void
			{
				cleanup();
				trace('Remote asset fetch failed for ' + relativePath + ' from ' + baseUrl + ' -> ' + event.text);
				tryBase(index + 1);
			}

			handleSecurityError = function(event:SecurityErrorEvent):Void
			{
				cleanup();
				trace('Remote asset fetch failed for ' + relativePath + ' from ' + baseUrl + ' -> ' + event.text);
				tryBase(index + 1);
			}

			loader.dataFormat = URLLoaderDataFormat.BINARY;
			loader.addEventListener(Event.COMPLETE, handleComplete);
			loader.addEventListener(IOErrorEvent.IO_ERROR, handleIOError);
			loader.addEventListener(SecurityErrorEvent.SECURITY_ERROR, handleSecurityError);
			loader.addEventListener(HTTPStatusEvent.HTTP_STATUS, handleStatus);
			loader.load(request);
		}

		tryBase(0);
		#else
		onComplete(null);
		#end
	}

	static public function loadRemoteSharedSparrowAtlas(key:String, onComplete:FlxAtlasFrames->Void):Void
	{
		#if sys
		if (remoteSharedAtlasCache.exists(key))
		{
			onComplete(remoteSharedAtlasCache.get(key));
			return;
		}

		if (remoteSharedAtlasPending.exists(key))
		{
			remoteSharedAtlasPending.get(key).push(onComplete);
			return;
		}

		remoteSharedAtlasPending.set(key, [onComplete]);

		function finish(frames:FlxAtlasFrames):Void
		{
			var callbacks = remoteSharedAtlasPending.get(key);
			remoteSharedAtlasPending.remove(key);

			if (frames != null)
				remoteSharedAtlasCache.set(key, frames);

			if (callbacks != null)
			{
				for (callback in callbacks)
				{
					callback(frames);
				}
			}
		}

		loadRemoteBytes('shared/images/$key.png', function(imageBytes) {
			if (imageBytes == null)
			{
				finish(null);
				return;
			}

			loadRemoteBytes('shared/images/$key.xml', function(xmlBytes) {
				if (xmlBytes == null)
				{
					finish(null);
					return;
				}

				try
				{
					var graphicKey = '__remote_shared__/$key.png';
					var graphic = Cache.getAssetDirectly(graphicKey);

					if (graphic == null)
					{
						graphic = Cache.cachePermanentFromByteArray(graphicKey, ByteArray.fromBytes(imageBytes));
					}

					if (graphic == null)
					{
						finish(null);
						return;
					}

					var frames = FlxAtlasFrames.fromSparrow(graphic, xmlBytes.getString(0, xmlBytes.length));
					finish(frames);
				}
				catch (e:Dynamic)
				{
					trace('Error: could not build remote shared atlas - ' + key + ' -> ' + Std.string(e));
					finish(null);
				}
			});
		});
		#else
		onComplete(null);
		#end
	}

	static public function loadRemoteSharedGraphic(key:String, onComplete:FlxGraphic->Void):Void
	{
		#if sys
		if (remoteSharedGraphicCache.exists(key))
		{
			onComplete(remoteSharedGraphicCache.get(key));
			return;
		}

		if (remoteSharedGraphicPending.exists(key))
		{
			remoteSharedGraphicPending.get(key).push(onComplete);
			return;
		}

		remoteSharedGraphicPending.set(key, [onComplete]);

		function finish(graphic:FlxGraphic):Void
		{
			var callbacks = remoteSharedGraphicPending.get(key);
			remoteSharedGraphicPending.remove(key);

			if (graphic != null)
			{
				remoteSharedGraphicCache.set(key, graphic);
			}

			if (callbacks != null)
			{
				for (callback in callbacks)
				{
					callback(graphic);
				}
			}
		}

		loadRemoteBytes('shared/images/$key.png', function(imageBytes) {
			if (imageBytes == null)
			{
				finish(null);
				return;
			}

			try
			{
				var graphicKey = '__remote_shared__/$key.png';
				var graphic = Cache.cachePermanentFromByteArray(graphicKey, ByteArray.fromBytes(imageBytes));
				finish(graphic);
			}
			catch (e:Dynamic)
			{
				trace('Error: could not build remote shared graphic - ' + key + ' -> ' + Std.string(e));
				finish(null);
			}
		});
		#else
		onComplete(null);
		#end
	}

	static public function loadRemoteText(relativePath:String, onComplete:String->Void):Void
	{
		loadRemoteBytes(relativePath, function(bytes) {
			if (bytes == null)
			{
				onComplete(null);
				return;
			}

			onComplete(bytes.getString(0, bytes.length));
		});
	}

	static public function loadRemoteSharedSound(key:String, onComplete:Sound->Void):Void
	{
		#if sys
		if (remoteSharedSoundCache.exists(key))
		{
			onComplete(remoteSharedSoundCache.get(key));
			return;
		}

		if (remoteSharedSoundPending.exists(key))
		{
			remoteSharedSoundPending.get(key).push(onComplete);
			return;
		}

		remoteSharedSoundPending.set(key, [onComplete]);

		function finish(sound:Sound):Void
		{
			var callbacks = remoteSharedSoundPending.get(key);
			remoteSharedSoundPending.remove(key);

			if (sound != null)
			{
				remoteSharedSoundCache.set(key, sound);
			}

			if (callbacks != null)
			{
				for (callback in callbacks)
				{
					callback(sound);
				}
			}
		}

		loadRemoteBytes('shared/sounds/$key.$SOUND_EXT', function(soundBytes) {
			if (soundBytes == null)
			{
				finish(null);
				return;
			}

			try
			{
				var sound = new Sound();
				var byteArray = ByteArray.fromBytes(soundBytes);
				sound.loadCompressedDataFromByteArray(byteArray, byteArray.length);
				finish(sound);
			}
			catch (e:Dynamic)
			{
				trace('Error: could not build remote shared sound - ' + key + ' -> ' + Std.string(e));
				finish(null);
			}
		});
		#else
		onComplete(null);
		#end
	}

	static public function getPath(file:String, type:AssetType, library:Null<String>)
	{
		if (library != null)
			return getLibraryPath(file, library);

		if (currentLevel != null)
		{
			var levelPath = resolveLocalOrBuiltInPath(file, type, currentLevel);
			if (levelPath != null)
				return levelPath;

			levelPath = resolveLocalOrBuiltInPath(file, type, "shared");
			if (levelPath != null)
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

	public static function getSongSoundPath(song:String, soundFile:String):String
	{
		var relativePath = 'songs/${song.toLowerCase()}/$soundFile.$SOUND_EXT';
		var builtInAssetId = 'songs:assets/$relativePath';

		#if sys
		for (path in ['mod_assets/$relativePath', 'funkin_assets/$relativePath'])
		{
			if (FileSystem.exists(path))
				return path;
		}
		#end

		if (OpenFlAssets.exists(builtInAssetId, SOUND) || OpenFlAssets.exists(builtInAssetId, MUSIC))
			return builtInAssetId;

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

		if(cachedImage != null && cachedImage.bitmap != null) {
			return cachedImage;
		} else if(cachedImage != null) {
			FlxG.bitmap.removeByKey(cachedImage.key);
		}

		var path = getPath('images/$key.png', IMAGE, library);
		var bitmapGraphic:FlxGraphic = FlxG.bitmap.get(path);

		if(bitmapGraphic != null && bitmapGraphic.bitmap != null) {
			return bitmapGraphic;
		} else if(bitmapGraphic != null) {
			FlxG.bitmap.removeByKey(path);
		}

		if(OpenFlAssets.exists(path, IMAGE)) {
			return FlxGraphic.fromAssetKey(path, false, null, true);
		}

		var bitmap = loadBitmap(path, true);

		if(bitmap != null) {
			var graphics:FlxGraphic = FlxGraphic.fromBitmapData(bitmap, false, path);
			graphics.persist = false;
			return graphics;
		}

		return null;
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
