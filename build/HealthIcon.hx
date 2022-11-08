package;

import flixel.FlxG;
import flixel.FlxSprite;

#if sys
import sys.FileSystem;
import sys.io.File;
#end

#if json2object
import json2object.JsonParser;
#end

import ModInitialize;

class HealthIcon extends FlxSprite
{
	/**
	 * Used for FreeplayState! If you use it elsewhere, prob gonna annoying
	 */
	public var sprTracker:FlxSprite;

	private var iconSway:Float = 0;

	public var iconCharacters:Array<String>;

	private var updatePref:Float = 1;

	public var iconAnimInfo:Array<Int> = [];

	public var character:String = "";
	public var bpm:Int;

	public function new(char:String = 'bf', isPlayer:Bool = false, ?storybpm:Int = 0, ?loadAnims:Bool = true)
	{
		super();

		character = char;

		updatePref = (FlxG.save.data.showAntialiasing ? 1 : 0.75);

		loadGraphic(Paths.image('iconGrid'), true, 150, 150);

		if(FlxG.save.data.showAntialiasing)
			antialiasing = true;

		iconCharacters = new Array<String>();

		if(loadAnims)
			loadAllAnims(isPlayer);

		scrollFactor.set();

		if(storybpm <= 0)
			updatePref += 1;

		bpm = storybpm;
	}

	public function loadAllAnims(isPlayer:Bool):Void {
		for(i in 0...FileSystem.readDirectory("assets/characters").length) {
			var funnyJson:ConfigCharacters = cast loadJSON("assets", "characters/" + FileSystem.readDirectory("assets/characters")[i].split(".")[0]);
			createAnim(FileSystem.readDirectory("assets/characters")[i].split(".")[0], funnyJson.icon, isPlayer);
		}

		for(i in 0...FileSystem.readDirectory("mod_assets/characters").length) {
			var funnyJson:ConfigCharacters = cast loadJSON("mod_assets", "characters/" + FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0]);
			createAnim(FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0], funnyJson.icon, isPlayer);
		}
	}

	public function createAnim(character:String, iconAnimInfo:Array<Int>, isPlayer:Bool = false):Void {
		if(!iconCharacters.contains(character)) {
			iconCharacters.push(character);
		}else {
			animation.remove(character);
		}

		if(this.character == character) {
			this.iconAnimInfo = iconAnimInfo;
			animation.add(character, iconAnimInfo, 0, false, isPlayer);
			animation.play(this.character);
		}
	}

	private function loadJSON(file:String, character:String):ConfigCharacters {
		var parser:JsonParser<ConfigCharacters> = new JsonParser<ConfigCharacters>();

		return parser.fromJson(File.getContent(file + '/$character.json'), '${character.split('/')[1]}.json');
	}

	override function update(elapsed:Float):Void
		{
			super.update(elapsed * updatePref);
	
			if (sprTracker != null)
				setPosition(sprTracker.x + sprTracker.width + 10, sprTracker.y - 30);
	
			if(bpm >= 1) {
				var currentSway:Float = iconSway*(bpm/120);
				iconSway += 0.004;
	
				angle = 15*Math.sin(currentSway * Math.PI);
			}
		}
}