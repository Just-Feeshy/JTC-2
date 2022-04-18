package;

import flixel.FlxG;
import flixel.FlxSprite;
import sys.FileSystem;

#if json2object
import json2object.JsonParser;
import sys.io.File;
import ModInitialize;
#end

class HealthIcon extends FlxSprite
{
	/**
	 * Used for FreeplayState! If you use it elsewhere, prob gonna annoying
	 */
	public var sprTracker:FlxSprite;

	private var iconSway:Float = 0;
	private var BPM:Int;

	public var iconCharacters:Array<String>;

	private var updatePref:Float = 1;

	public function new(char:String = 'bf', isPlayer:Bool = false, ?storyBPM:Int = 0, ?loadAnims:Bool = true)
	{
		super();

		updatePref = (FlxG.save.data.showAntialiasing ? 1 : 1.5);

		loadGraphic(Paths.image('iconGrid'), true, 150, 150);

		if(FlxG.save.data.showAntialiasing)
			antialiasing = true;

		iconCharacters = new Array<String>();

		if(loadAnims)
			loadAllAnims(isPlayer);

		animation.play(char);
		scrollFactor.set();

		if(storyBPM <= 0)
			updatePref += 1;

		BPM = storyBPM;
	}

	public function loadAllAnims(isPlayer:Bool):Void {
		for(i in 0...FileSystem.readDirectory("config/characters").length) {
			var funnyJson:ConfigCharacters = cast loadJSON("characters/" + FileSystem.readDirectory("config/characters")[i].split(".")[0]);
			createAnim(FileSystem.readDirectory("config/characters")[i].split(".")[0], funnyJson.icon, isPlayer);
		}
	}

	public function createAnim(character:String, iconAnimInfo:Array<Int>, isPlayer:Bool = false):Void {
		if(!iconCharacters.contains(character)) {
			iconCharacters.push(character);
			animation.add(character, iconAnimInfo, 0, false, isPlayer);
		}
	}

	private function loadJSON(character:String):ConfigCharacters {
		var parser:JsonParser<ConfigCharacters> = new JsonParser<ConfigCharacters>();

		return parser.fromJson(File.getContent('config/$character.json'), '${character.split('/')[1]}.json');
	}

	override function update(elapsed:Float):Void
		{
			super.update(elapsed / updatePref);
	
			if (sprTracker != null)
				setPosition(sprTracker.x + sprTracker.width + 10, sprTracker.y - 30);
	
			if(BPM >= 1) {
				var currentSway:Float = iconSway*(BPM/120);
				iconSway += 0.004;
	
				angle = 15*Math.sin(currentSway * Math.PI);
			}
		}
}