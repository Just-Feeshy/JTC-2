package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.display.BitmapData;
import openfl.media.Sound;
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

	@:isVar public static var modJSON(get, never):ConfigDef;

	static var currentLevel:String;

	static function get_modJSON():ConfigDef {
		if(modJSON == null) { 
			var parser:JsonParser<ConfigDef> = new JsonParser<ConfigDef>();

			return parser.fromJson(File.getContent("config/mod.json"), "mod.json");
		}else {
			return modJSON;
		}
	}

	static public function setCurrentLevel(name:String)
	{
		currentLevel = name.toLowerCase();
	}

	static public function getPath(file:String, type:AssetType, library:Null<String>)
	{
		if (library != null)
			return getLibraryPath(file, library);

		if (currentLevel != null)
		{
			var levelPath = getLibraryPathForce(file, currentLevel);
			if (OpenFlAssets.exists(levelPath, type))
				return levelPath;

			levelPath = getLibraryPathForce(file, "shared");
			if (OpenFlAssets.exists(levelPath, type))
				return levelPath;
		}

		return getPreloadPath(file);
	}

	static public function getLibraryPath(file:String, library = "preload")
	{
		return if (library == "preload" || library == "default") getPreloadPath(file); else getLibraryPathForce(file, library);
	}

	inline static function getLibraryPathForce(file:String, library:String)
	{
		if(OpenFlAssets.exists('mod_assets/$file'))
			return 'mod_assets/$file';
		else
			return '$library:assets/$library/$file';
	}

	inline static public function getPreloadPath(file:String)
	{
		if(OpenFlAssets.exists('mod_assets/$file'))
			return 'mod_assets/$file';
		else
			return 'assets/$file';
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
		if(OpenFlAssets.exists(getPreloadPath('fonts/$key'))) {
			return getPreloadPath('fonts/$key');
		}else {
			return "";
		}
	}

	inline static public function mora(key:String, type:String,?library:String)
	{
		if(OpenFlAssets.exists(getPath('feeshdata/$key.$type', TEXT, library)))
			return getPath('feeshdata/$key.$type', TEXT, library);
		else {
			trace("Error: could not locate file - " + '$key.$type');
			return "";
		}
	}

	inline static public function txt(key:String, ?library:String)
	{
		if(OpenFlAssets.exists(getPath('data/$key.txt', TEXT, library)))
			return getPath('data/$key.txt', TEXT, library);
		else {
			trace("Warning: could not locate text file - " + key);
			return "";
		}
	}

	inline static public function pak(key:String,?library:String)
	{
		if(OpenFlAssets.exists(getPath('pakdata/$key.pak', TEXT, library)))
			return getPath('pakdata/$key.pak', TEXT, library);
		else {
			trace("Error: could not locate pak file - " + key);
			return "";
		}
	}

	inline static public function json(key:String, ?library:String)
	{
		if(OpenFlAssets.exists(getPath('data/$key.json', TEXT, library)))
			return getPath('data/$key.json', TEXT, library);
		else {
			trace("Error: could not locate json file - " + getPath('data/$key.json', TEXT, library));
			return "";
		}
	}

	inline static public function shader(key:String, ?library:String) {
		if(OpenFlAssets.exists(getPath('shaders/$key', TEXT, library)))
			return getPath('shaders/$key', TEXT, library);
		else {
			trace("Error: could not locate glsl file - " + getPath('shaders/$key', TEXT, library));
			return "";
		}
	}

	inline static public function getPackerAtlas(key:String, ?library:String, ?cache:Bool)
	{
		var cacheFile:String = "";

		if(cache)
			cacheFile = "cache/";

		if(OpenFlAssets.exists('mod_assets/images/$key.png')
		&& OpenFlAssets.exists('mod_assets/images/$key.xml')) {
			cacheFile = "";
			library = "";
		}

		var cachedImage:FlxGraphic = ifImageCached(cacheFile + key);

		if(OpenFlAssets.exists(file('images/' + cacheFile + key + '.txt', library))) {
			return FlxAtlasFrames.fromSpriteSheetPacker(cachedImage != null ? cachedImage : image(cacheFile + key, library), file('images/' + cacheFile + key + '.txt', library));
		}else {
			trace("Error: could not locate asset - " + file('images/' + cacheFile + key + '.txt', library));
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
		var getPath:String = getPath('sounds/$key.$SOUND_EXT', SOUND, library);

		if(OpenFlAssets.exists(getPath)) {
			return OpenFlAssets.getSound(getPath, true);
		}else {
			trace("Error: could not locate sound - " + key);
			return null;
		}
	}

	inline static public function music(key:String, ?library:String)
	{
		var getPath:String = getPath('music/$key.$SOUND_EXT', MUSIC, library);

		if(OpenFlAssets.exists(getPath)) {
			return OpenFlAssets.getSound(getPath, true);
		}else {
			trace("Error: could not locate music - " + key);
			return null;
		}
	}

	inline static public function voices(song:String)
	{
		var getPath:String = "songs:" + getPreloadPath('songs/${song.toLowerCase()}/Voices.$SOUND_EXT');

		if(OpenFlAssets.exists(getPath)) {
			return OpenFlAssets.getSound(getPath, true);
		}else {
			trace("Error: could not locate voices - " + song + "." + SOUND_EXT);
			return null;
		}
	}
	
	inline static public function inst(song:String)
	{
		var getPath:String = "songs:" + getPreloadPath('songs/${song.toLowerCase()}/Inst.$SOUND_EXT');

		if(OpenFlAssets.exists(getPath)) {
			return OpenFlAssets.getSound(getPath, true);
		}else {
			trace("Error: could not locate instrumental - " + song + "." + SOUND_EXT);
			return null;
		}
	}

	inline static public function getSparrowAtlas(key:String, ?library:String, ?cache:Bool)
	{
		var cacheFile:String = "";

		if(cache) {
			cacheFile = "cache/";
		}

		if(OpenFlAssets.exists('mod_assets/images/$key.png') 
		&& OpenFlAssets.exists('mod_assets/images/$key.xml')) {
			cacheFile = "";
			library = "";
		}

		var cachedImage:FlxGraphic = ifImageCached(key, "");

		if(OpenFlAssets.exists(file('images/' + cacheFile + key + '.xml', library))) {
			return FlxAtlasFrames.fromSparrow(cachedImage != null ? cachedImage : image(cacheFile + key, library), file('images/' + cacheFile + key + '.xml', library));
		}else {
			trace("Error: could not locate asset - " + file('images/' + cacheFile + key + '.xml', library));
			return null;
		}
	}

	inline static public function getNoteAtlas(key:String, library:String = "shared") {
		return getSparrowAtlas("notes/" + key, library);
	}

	static public function image(key:String, ?library:String):FlxGraphic {
		var cachedImage:FlxGraphic = ifImageCached(key);

		if(cachedImage != null) {
			return cachedImage;
		}

		if(OpenFlAssets.exists(getPath('images/$key.png', IMAGE, library))) {
			var path:String = getPath('images/$key.png', IMAGE, library);

			var graphics:FlxGraphic = FlxG.bitmap.add(path, false, path);
			graphics.persist = false;
			return graphics;
		}else {
			//trace("Error: could not locate asset - " + file('images/$key.png', library));
			return null;
		}
	}

	static public function lua(key:String) {
		if(OpenFlAssets.exists(getPath('scripts/$key.lua', TEXT, null))) {
			return getPath('scripts/$key.lua', TEXT, null);
		}else {
			trace("Error: could not locate asset - " + getPath('scripts/$key.lua', TEXT, null));
			return "";
		}
	}
}