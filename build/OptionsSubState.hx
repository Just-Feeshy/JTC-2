package;

import flixel.input.keyboard.FlxKey;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.util.FlxColor;

import openfl.filters.ShaderFilter;

import BuiltInShaders.ShaderType;
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
			case CUSTOM_UI_KEYBINDS:
				return new CustomUIKeys();
			case ERASE_DATA:
				return new EraseSave();
			case GAMMA:
				return new GammaMenu();
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

	private var changedOnSteam:Int = 0;

	private var keyString:String;

	private var keyLength:Int = 4;
	private var keyIndex:Int = 0;

	public function new() {
		super();

		keyString = keysToString(SaveData.getData(SaveType.CUSTOM_KEYBINDS), 0, keyLength);

		if(keyString.split(" ").length < keyLength) {
			keyString = "A S W D";
		}

		bgBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bgBlack.alpha = 0;
		add(bgBlack);

		FlxTween.tween(bgBlack, {alpha: 0.5}, 1, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			keys = new Alphabet(0, 0, keyString, true, false);
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

	override function update(elapsed:Float) {
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
			changingKeys = true;

			var containKeys:Array<String> = keyString.split(" ");
			keyString = "";

			for(i in 0...keyLength) {
				if(section == i) {
					keyString += FlxKey.toStringMap.get(FlxG.keys.firstJustPressed()) + " ";
				}else {
					keyString += containKeys[i] + " ";
				}
			}

			var trimmed:String = keyString;
			keyString = trimmed.rtrim();

			section += 1;
			reloadKeys(keyString);

			if(section >= keyLength) {
				section = 0;

				keyString.rtrim();

				for(i in 0...keyLength) {
					FlxG.save.data.customKeys[i + keyIndex][0] = FlxKey.fromStringMap.get(keyString.split(" ")[i]);
				}

				SaveData.saveClient();

				if(changedOnSteam == 0)
					howManyKey.text = "Middle Keybind For Five Keys";

				if(keyLength > 1) {
					keyLength = 1;
					keyIndex = 4;
					keyString = keysToString(SaveData.getData(SaveType.CUSTOM_KEYBINDS), 4, keyLength);
					section = 0;

					if(keyString.split(" ").length < keyLength)
						keyString = "SPACE";

					reloadKeys(keyString);
				}else {
					controls.setKeyboardScheme(controls.keyboardScheme, true);

					SaveData.saveClient();
					close();
				}
			}

			changingKeys = false;
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

	function keysToString(key:Array<Array<FlxKey>>, index:Int, length:Int):String {
		var stringKeys:String = "";

		for(i in index...(index + length)) {
			stringKeys += FlxKey.toStringMap.get(key[i][0]) + " ";
		}

		stringKeys.rtrim();
		return stringKeys;
	}
}

class CustomUIKeys extends OptionsSubState {
	private var bgBlack:FlxSprite;

	private var keys:Alphabet;
	private var howManyKey:FlxText;

	private var section:Int = 0;

	private var colorSway:Float = 0;

	private var changingKeys:Bool = false;

	private var changedOnSteam:Int = 0;

	private var keyString:String;

	private var keyLength:Int = 4;
	private var keyIndex:Int = 0;

	private var turns:Int = 0;

	public function new() {
		super();

		keyString = keysToString(SaveData.getData(SaveType.CUSTOM_UI_KEYBINDS), 0, keyLength);

		if(keyString.split(" ").length < keyLength) {
			keyString = "A S W D";
		}

		bgBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bgBlack.alpha = 0;
		add(bgBlack);

		FlxTween.tween(bgBlack, {alpha: 0.5}, 1, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			keys = new Alphabet(0, 0, keyString, true, false);
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

	override function update(elapsed:Float) {
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
			changingKeys = true;

			var containKeys:Array<String> = keyString.split(" ");
			keyString = "";

			for(i in 0...keyLength) {
				if(section == i) {
					keyString += FlxKey.toStringMap.get(FlxG.keys.firstJustPressed()) + " ";
				}else {
					keyString += containKeys[i] + " ";
				}
			}

			var trimmed:String = keyString;
			keyString = trimmed.rtrim();

			section += 1;
			reloadKeys(keyString);

			try {
				if(section >= keyLength) {
					section = 0;

					keyString.rtrim();

					for(i in 0...keyLength) {
						FlxG.save.data.customUIKeys[i + keyIndex][0] = FlxKey.fromStringMap.get(keyString.split(" ")[i]);
					}

					if(turns < 2) {
						if(turns == 0) {
							keyLength = 2;
							keyIndex = 4;

							keyString = keysToString(SaveData.getData(SaveType.CUSTOM_UI_KEYBINDS), keyIndex, keyLength);
							howManyKey.text = "Start Keybinds";

							reloadKeys(keyString);
						}else if(turns == 1) {
							keyLength = 2;
							keyIndex = 6;

							keyString = keysToString(SaveData.getData(SaveType.CUSTOM_UI_KEYBINDS), keyIndex, keyLength);
							howManyKey.text = "Escape Keybinds";

							reloadKeys(keyString);
						}

						turns++;
					}else {
						controls.setKeyboardScheme(controls.keyboardScheme, true);

						SaveData.saveClient();
						close();
					}
				}
			}catch(e) {
				SaveData.createNewBinds(CUSTOM_UI_KEYBINDS);
			}

			changingKeys = false;
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

	function keysToString(key:Array<Array<FlxKey>>, index:Int, length:Int):String {
		var stringKeys:String = "";

		for(i in index...(index + length)) {
			stringKeys += FlxKey.toStringMap.get(key[i][0]) + " ";
		}

		stringKeys.rtrim();
		return stringKeys;
	}
}

class EraseSave extends OptionsSubState {
	private var bgBlack:FlxSprite;

	private var choices:Alphabet;
	private var yourSure:FlxText;

	private var section:Int = 0;

	private var colorSway:Float = 0;

	private var changingKeys:Bool = false;

	public function new() {
		super();

		bgBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bgBlack.alpha = 0;
		add(bgBlack);

		FlxTween.tween(bgBlack, {alpha: 0.5}, 1, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			choices = new Alphabet(0, 0, "yes no", true, false);
			choices.screenCenter();
			add(choices);

			yourSure = new FlxText(0, 0, FlxG.width, "Are you sure?", 32);
			yourSure.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
			yourSure.borderSize = 2;
			yourSure.screenCenter(X);
			yourSure.y = yourSure.getScreenCenter(Y) + (choices.height * 1.5);
			add(yourSure);
		}});
	}

	override function update(elapsed:Float) {
		if(choices != null) {
			colorSway += elapsed;

			for(i in 0...choices.letters.length) {
				if(choices.letters[i].spaceLocation == section) {
					choices.letters[i].color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
					0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
				}else {
					choices.letters[i].color = FlxColor.fromRGBFloat(1, 1, 1);
				}
			}
		}

		if(changingKeys == false) {
			changingKeys = true;

			if(controls.LEFT_P) {
				section -= 1;
			}

			if(controls.RIGHT_P) {
				section += 1;
			}

			section %= 2;

			if(controls.ACCEPT) {
				if(section == 0) {
					FlxG.save.erase();
					SaveData.saveClient();
				}

				controls.setKeyboardScheme(controls.keyboardScheme, true);

				close();
			}

			changingKeys = false;
		}

		super.update(elapsed);
	}
}

class GammaMenu extends OptionsSubState {
	private var bgBlack:FlxSprite;

	private var valueTxt:FlxText;
	private var tutorial:FlxText;

	private var changingKeys:Bool = false;

	public function new() {
		super();

		bgBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bgBlack.alpha = 0;
		add(bgBlack);

		FlxTween.tween(bgBlack, {alpha: 0.5}, 1, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			valueTxt = new FlxText(0, 0, FlxG.width, "< " + SaveData.getData(SaveType.GAMMA) + " >", 64);
			valueTxt.setFormat("VCR OSD Mono", 64, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
			valueTxt.borderSize = 4;
			valueTxt.screenCenter();
			add(valueTxt);

			tutorial = new FlxText(0, 0, FlxG.width, "Use left and right keys", 32);
			tutorial.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
			tutorial.borderSize = 2;
			tutorial.screenCenter(X);
			tutorial.y = tutorial.getScreenCenter(Y) + (tutorial.height * 2);
			add(tutorial);
		}});
	}

	function getShaders():BuiltInShaders {
		@:privateAccess
		for(i in 0...FlxG.game._filters.length) {
			var shaderFilter:ShaderFilter = cast(FlxG.game._filters[i], ShaderFilter);
			var shaders:BuiltInShaders = cast (shaderFilter.shader, BuiltInShaders);

			if(shaders.shader == ShaderType.GAMMA) {
				return shaders;
			}
		}

		throw "Error: Has GAMMA not been implemented";
		return null;
	}

	override function update(elapsed:Float) {
		if(!changingKeys) {
			if(controls.LEFT_P) {
				FlxG.save.data.gamma = FlxG.save.data.gamma - 0.1;
				FlxG.save.data.gamma = Math.round(FlxG.save.data.gamma * 10) / 10;
				valueTxt.text = "< " + SaveData.getData(SaveType.GAMMA) + " >";

				var shaders:BuiltInShaders = getShaders();
				shaders.position = SaveData.getData(SaveType.GAMMA);
			}else if(controls.RIGHT_P) {
				FlxG.save.data.gamma = FlxG.save.data.gamma + 0.1;
				FlxG.save.data.gamma = Math.round(FlxG.save.data.gamma * 10)  / 10;
				valueTxt.text = "< " + SaveData.getData(SaveType.GAMMA) + " >";

				var shaders:BuiltInShaders = getShaders();
				shaders.position = SaveData.getData(SaveType.GAMMA);
			}

			if(controls.BACK || controls.ACCEPT) {
				changingKeys = true;

				SaveData.saveClient();

				close();
			}
		}
	}
}