package;

import flixel.input.keyboard.FlxKey;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.util.FlxColor;

import SaveData.SaveType;

using StringTools;

class OptionsSubState extends MusicBeatSubstate {
	public function new() {
		super();
	}

	static public function newSubState(type:SaveType):OptionsSubState {
		switch(type) {
			case CUSTOM_KEYBINDS:
				return new CustomKeys();
			default:
				return new OptionsSubState();
		}
	}
}

class CustomKeys extends OptionsSubState {
	private var bgBlack:FlxSprite;

	private var keys:Alphabet;
	private var howManyKey:FlxText;

	private var section:Int = 0;

	private var colorSway:Float = 0;

	private var changingKeys:Bool = false;

	private var saveryMapArray:Bool = false;
	private var changedOnSteam:Int = 0;

	public function new() {
		super();

		if(FlxG.save.data.customKeys.split(" ").length < 4)
			FlxG.save.data.customKeys = "A S W D";

		bgBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bgBlack.alpha = 0;
		add(bgBlack);

		FlxTween.tween(bgBlack, {alpha: 0.5}, 1, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			keys = new Alphabet(0, 0, FlxG.save.data.customKeys, true, false);
			keys.screenCenter();
			add(keys);

			howManyKey = new FlxText(0, 0, FlxG.width, "Standard Four Keybinds", 32);
			howManyKey.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
			howManyKey.borderSize = 2;
			howManyKey.screenCenter(X);
			howManyKey.y = howManyKey.getScreenCenter(Y) + (keys.height * 1.5);
			add(howManyKey);
		}});
	}

	override public function update(elapsed:Float) {
		if(keys != null) {
			colorSway += elapsed;

			for(i in 0...keys.letters.length) {
				if(keys.letters[i].spaceLocation == section) {
					keys.letters[i].color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
					0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
				}
			}
		}


		if(FlxG.keys.justPressed.ANY && !changingKeys) {
			if(!saveryMapArray) {
				changingKeys = true;

				var containKeys:Array<String> = FlxG.save.data.customKeys.split(" ");
				FlxG.save.data.customKeys = "";

				for(i in 0...containKeys.length) {
					if(section == i) {
						FlxG.save.data.customKeys += FlxKey.toStringMap.get(FlxG.keys.firstJustPressed()) + " ";
					}else {
						FlxG.save.data.customKeys += containKeys[i] + " ";
					}
				}

				var trimmed:String = FlxG.save.data.customKeys;
				FlxG.save.data.customKeys = trimmed.rtrim();

				section += 1;
				reloadKeys(FlxG.save.data.customKeys);

				if(section >= containKeys.length) {
					section = 0;
					SaveData.saveClient();
					saveryMapArray = true;

					reloadKeys(FlxG.save.data.menuBinds[changedOnSteam]);

					if(changedOnSteam == 0)
						howManyKey.text = "Middle Keybind For Five Keys";
				}

				changingKeys = false;
			}else if(saveryMapArray) {
				changingKeys = true;

				var containKeys:Array<String> = FlxG.save.data.menuBinds[changedOnSteam].split(" ");

				FlxG.save.data.menuBinds[changedOnSteam] = "";

				for(i in 0...containKeys.length) {
					if(section == i) {
						FlxG.save.data.menuBinds[changedOnSteam] += FlxKey.toStringMap.get(FlxG.keys.firstJustPressed()) + " ";
					}else {
						FlxG.save.data.menuBinds[changedOnSteam] += containKeys[i] + " ";
					}
				}

				var trimmed:String = FlxG.save.data.menuBinds[changedOnSteam];
				FlxG.save.data.menuBinds[changedOnSteam] = trimmed.rtrim();

				section += 1;
				reloadKeys(FlxG.save.data.menuBinds[changedOnSteam]);

				if(section >= containKeys.length) {
					section = 0;
					SaveData.saveClient();
					saveryMapArray = true;

					close();
				}

				changingKeys = false;
			}
		}

		super.update(elapsed);
	}

	function reloadKeys(text:String) {
		remove(keys);
		keys.destroy();
		keys = new Alphabet(0, 0, text, true, false);
		keys.screenCenter();
		add(keys);
	}
}