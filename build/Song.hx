package;

import Section.SwagSection;
import haxe.Json;
import haxe.format.JsonParser;
import lime.utils.Assets;

import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;

import example_code.DefaultEvents.Modifiers;

using StringTools;

typedef SwagSong =
{
	var song:String;
	var notes:Array<SwagSection>;
	var modifiers:Array<Modifiers>;
	var bpm:Int;
	var needsVoices:Bool;
	var speed:Float;

	var player1:String;
	var player2:String;
	var girlfriend:String;

	var stage:String;
	var video:String;

	var validScore:Bool;
	var fifthKey:Bool;
	var colorMapping:Int;
	var fps:Int;

	//Player1
	var player1X:Float;
	var player1Y:Float;

	//Player2
	var player2X:Float;
	var player2Y:Float;
}

class Song
{
	public var song:String;
	public var notes:Array<SwagSection>;
	public var modifiers:Array<Modifiers>;	
	public var bpm:Int;
	public var needsVoices:Bool = true;
	public var speed:Float = 1;
	public var colorMapping:Int;
	public var fps:Int;

	public var player1X:Float;
	public var player1Y:Float;

	public var player2X:Float;
	public var player2Y:Float;

	public var fifthKey:Bool;

	public function new(song, notes, bpm, fps)
	{
		this.song = song;
		this.notes = notes;
		this.bpm = bpm;
		this.fps = fps;
	}

	public static function loadFromJson(jsonInput:String, ?folder:String, ?ifPlayState:Bool = true):SwagSong
	{
		var rawJson;

		if(ifPlayState)
			rawJson = Assets.getText(Paths.json(folder.toLowerCase() + '/' + jsonInput.toLowerCase())).trim();
		else
			rawJson = Assets.getText(Paths.getPath(folder.toLowerCase() + '/' + jsonInput + '.json', TEXT, null)).trim();

		while (!rawJson.endsWith("}"))
		{
			rawJson = rawJson.substr(0, rawJson.length - 1);
			// LOL GOING THROUGH THE BULLSHIT TO CLEAN IDK WHATS STRANGE
		}

		// FIX THE CASTING ON WINDOWS/NATIVE
		// Windows???
		// trace(songData);

		// trace('LOADED FROM JSON: ' + songData.notes);
		/* 
			for (i in 0...songData.notes.length)
			{
				trace('LOADED FROM JSON: ' + songData.notes[i].sectionNotes);
				// songData.notes[i].sectionNotes = songData.notes[i].sectionNotes
			}

				daNotes = songData.notes;
				daSong = songData.song;
				daBpm = songData.bpm; */

		return parseJSONshit(rawJson);
	}

	public static function getRawJSON(jsonInput:String, ?folder:String):String {
		return Assets.getText(Paths.json(folder.toLowerCase() + '/' + jsonInput.toLowerCase())).trim();
	}

	public static function parseJSONshit(rawJson:String):SwagSong
	{
		var swagShit:SwagSong = cast Json.parse(rawJson).song;
		swagShit.validScore = true;
		return swagShit;
	}
}