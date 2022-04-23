package;

import flixel.FlxG;
import haxe.Json;
import openfl.display.BitmapData;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import lime.utils.Assets;

import ModInitialize;
import json2object.JsonParser;
import sys.FileSystem;
import sys.io.File;

using StringTools;

class Paths
{
	inline public static var SOUND_EXT = #if web "mp3" #else "ogg" #end;

	@:isVar public static var modJSON(get, never):ConfigDef;

	public static var bitLiteralMap:Map<String, FlxGraphic> = new Map<String, FlxGraphic>();

	static var currentLevel:String;

	static public function cacheEitherWay():Void {
		
		#if desktop
		if(bitLiteralMap.get("regular/splash") == null) {
			var splashGraphic:FlxGraphic = FlxGraphic.fromBitmapData(BitmapData.fromFile('assets/shared/images/notes/regular/splash.png'));
			splashGraphic.persist = true;
			bitLiteralMap.set("regular/splash", splashGraphic);
		}	
		#end
	}

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
		if(FileSystem.exists('mod_assets/$file'))
			return 'mod_assets/$file';
		else
			return '$library:assets/$library/$file';
	}

	inline static function getPreloadPath(file:String)
	{
		if(FileSystem.exists('mod_assets/$file'))
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
		return 'assets/fonts/$key';
	}

	//Finally! Theres a console crash log
	inline static public function mora(key:String, type:String,?library:String)
	{
		if(Assets.exists(getPath('feeshdata/$key.$type', TEXT, library)))
			return getPath('feeshdata/$key.$type', TEXT, library);
		else {
			throw ("Error: could not locate file - " + '$key.$type');
			return null;
		}
	}

	inline static public function txt(key:String, ?library:String)
	{
		if(Assets.exists(getPath('data/$key.txt', TEXT, library)))
			return getPath('data/$key.txt', TEXT, library);
		else {
			throw ("Warning: could not locate text file - " + key);
			return null;
		}
	}

	inline static public function pak(key:String,?library:String)
	{
		if(Assets.exists(getPath('pakdata/$key.pak', TEXT, library)))
			return getPath('pakdata/$key.pak', TEXT, library);
		else {
			throw ("Error: could not locate pak file - " + key);
			return null;
		}
	}

	inline static public function json(key:String, ?library:String)
	{
		if(Assets.exists(getPath('data/$key.json', TEXT, library)))
			return getPath('data/$key.json', TEXT, library);
		else {
			throw ("Error: could not locate json file - " + key);
			return null;
		}
	}

	inline static public function getPackerAtlas(key:String, ?library:String, ?cache:Bool)
	{
		var cacheFile:String = "";

		if(cache)
			cacheFile = "cache/";

		if(FileSystem.exists('mod_assets/images/$key.png')
		&& FileSystem.exists('mod_assets/images/$key.xml'))
			cacheFile = "";

		if(Assets.exists(file('images/' + cacheFile + key + '.txt', library))) {
			if(ifImageCached(cacheFile + key) != null)
				return FlxAtlasFrames.fromSpriteSheetPacker(ifImageCached(cacheFile + key), file('images/' + cacheFile + key + '.txt', library));
			else
				return FlxAtlasFrames.fromSpriteSheetPacker(image(cacheFile + key, library), file('images/' + cacheFile + key + '.txt', library));
		}else {
			throw ("Error: could not locate asset - " + file('images/' + cacheFile + key + '.txt', library));
			return null;
		}
	}

	inline static public function sound(key:String, ?library:String)
	{
		if(Assets.exists(getPath('sounds/$key.$SOUND_EXT', SOUND, library)))
			return getPath('sounds/$key.$SOUND_EXT', SOUND, library);
		else {
			throw ("Error: could not locate sound - " + key);
			return null;
		}
	}

	inline static public function music(key:String, ?library:String)
	{
		if(Assets.exists(getPath('music/$key.$SOUND_EXT', MUSIC, library)))
			return getPath('music/$key.$SOUND_EXT', MUSIC, library);
		else {
			throw ("Error: could not locate music - " + key);
			return null;
		}
	}

	inline static public function voices(song:String)
	{
		if(Assets.exists('songs:' + getPreloadPath('songs/${song.toLowerCase()}/Voices.$SOUND_EXT')))
			return 'songs:' + getPreloadPath('songs/${song.toLowerCase()}/Voices.$SOUND_EXT');
		else {
			throw ("Error: could not locate voices - " + song + "." + SOUND_EXT);
			return null;
		}
	}
	
	inline static public function inst(song:String)
	{
		if(Assets.exists('songs:' + getPreloadPath('songs/${song.toLowerCase()}/Inst.$SOUND_EXT')))
			return 'songs:' + getPreloadPath('songs/${song.toLowerCase()}/Inst.$SOUND_EXT');
		else {
			throw ("Error: could not locate instrumental - " + song + "." + SOUND_EXT);
			return null;
		}
	}

	static function ifImageCached(key:String):FlxGraphic {
		return bitLiteralMap.get(key);
	}

	inline static public function getSparrowAtlas(key:String, ?library:String, ?cache:Bool)
	{
		var cacheFile:String = "";

		if(cache) {
			cacheFile = "cache/";
		}

		if(FileSystem.exists('mod_assets/images/$key.png') 
		&& FileSystem.exists('mod_assets/images/$key.xml')) {
			cacheFile = "";
			library = "";
		}

		if(Assets.exists(file('images/' + cacheFile + key + '.xml', library))) {

			if(ifImageCached(cacheFile + key) != null)
				return FlxAtlasFrames.fromSparrow(ifImageCached(cacheFile + key), file('images/' + cacheFile + key + '.xml', library)); //fImageCached(key)
			else {
				return FlxAtlasFrames.fromSparrow(image(cacheFile + key, library), file('images/' + cacheFile + key + '.xml', library));
			}	
		}else {
			throw ("Error: could not locate asset - " + file('images/' + cacheFile + key + '.xml', library));
			return null;
		}
	}

	inline static public function getNoteAtlas(key:String) {
		if(Assets.exists(image("notes/" + key))) {
			if(ifImageCached(key) != null)
				return FlxAtlasFrames.fromSparrow(image("notes/" + key), file('images/notes/$key.xml'));
			else
				return FlxAtlasFrames.fromSparrow(image("notes/" + key), file('images/notes/$key.xml'));
		}else {
			throw ("Error: could not locate asset - " + file('images/$key.xml'));
			return null;
		}
	}

	static public function image(key:String, ?library:String)
	{
		if(Assets.exists(getPath('images/$key.png', IMAGE, library)))
			return getPath('images/$key.png', IMAGE, library);
		else {
			//throw ("Error: could not locate asset - " + file('images/$key.png', library));
			return null;
		}
	}

	static public function lua(key:String) {
		if(Assets.exists(getPath('scripts/$key.lua', TEXT, ""))) {
			return getPath('scripts/$key.lua', TEXT, "");
		}else {
			throw ("Error: could not locate asset - " + getPath('scripts/$key.lua', TEXT, ""));
			return null;
		}
	}
}