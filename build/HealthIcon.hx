package;

import flixel.FlxG;
import flixel.FlxSprite;

#if sys
import sys.FileSystem;
import sys.io.File;
#end

import openfl.utils.Assets;
import json2object.JsonParser;

import SaveData.SaveType;
import ModInitialize;

class HealthIcon extends FlxSprite
{
	/**
	 * Used for FreeplayState! If you use it elsewhere, prob gonna annoying
	 */
	public var sprTracker:FlxSprite;

	public var iconCharacters:Array<String>;
	public var iconAnimInfo:Array<UInt>;

	public var character:String = "";
	public var bpm(default, set):UInt = 0;

	public var isPlayer(default, null):Bool = false;
	public var iconFile(default, null):String = "iconGrid";

	private var iconSway:Float = 0;
	private var updatePref:Float = 1;

	public function new(character:String = 'bf', isPlayer:Bool = false)
	{
		super();

		this.iconCharacters = [];
		this.iconAnimInfo = [];

		this.isPlayer = isPlayer;
		this.character = character;

		updatePref = (FlxG.save.data.showAntialiasing ? 1 : 0.5);

		loadGraphic(Paths.image(iconFile), true, 150, 150);

		antialiasing = SaveData.getData(SaveType.GRAPHICS);
		scrollFactor.set();
	}

	public function loadNewIcons(file:String) {
		if(iconFile == file) {
			return;
		}

		iconFile = file;
		loadGraphic(Paths.image(file), true, 150, 150);
	}

	public function createAnim(character:String, iconAnimInfo:Array<UInt>, isPlayer:Bool = false):Void {
		if(!iconCharacters.contains(character)) {
			iconCharacters.push(character);
		}else {
			animation.remove(character);
		}

		this.iconAnimInfo = iconAnimInfo;
		animation.add(character, iconAnimInfo, 0, false, isPlayer);
		animation.play(this.character);
	}

	public function getIconJSON(character:String):Array<Int> {
		var parser:JsonParser<ConfigCharacters> = new JsonParser<ConfigCharacters>();
		var jsonPath:String = Paths.getPreloadPath('characters/$character.json');

		return parser.fromJson(Assets.getText(jsonPath), '$character.json').icon;
	}

	public function getIconFileJSON(character:String):String {
		var parser:JsonParser<ConfigCharacters> = new JsonParser<ConfigCharacters>();
		var jsonPath:String = Paths.getPreloadPath('characters/$character.json');

		return parser.fromJson(Assets.getText(jsonPath), '$character.json').iconFile;
	}

	function set_bpm(value:UInt):UInt {
		if(value == 0 || SaveData.getData(SaveType.GRAPHICS)) {
			updatePref = 0.5;
		}else {
			updatePref = 1;
		}

		return bpm = value;
	}

	override function update(elapsed:Float):Void {
		super.update(elapsed * updatePref);

		if (sprTracker != null) {
			setPosition(sprTracker.x + sprTracker.width + 10, sprTracker.y - 30);
		}

		if(bpm >= 1) {
			var currentSway:Float = iconSway*(bpm/120);
			iconSway += 0.004;

			angle = 15 * Math.sin(currentSway * Math.PI);
		}
	}
}