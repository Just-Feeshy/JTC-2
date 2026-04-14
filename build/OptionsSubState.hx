package;

import flixel.input.keyboard.FlxKey;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxMath;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;

import openfl.filters.ShaderFilter;

import BuiltInShaders.ShaderType;
import SaveData.SaveType;

using StringTools;

typedef LatencyArrowData = {
	var sprite:FlxSprite;
	var beat:Float;
}

class OptionsSubState extends MusicBeatSubstate {
	private var bgBlack:FlxSprite;


	public function new() {
		super();

		bgBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bgBlack.alpha = 0;
		add(bgBlack);

		FlxTween.tween(bgBlack, {alpha: 0.5}, 1, {ease: FlxEase.quadOut, onComplete: finishTransition});
	}

	function finishTransition(twn:FlxTween) {
		//empty
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
			case NOTE_OFFSET:
				return new OffsetMenu();
			case MISS_SOUND_VOLUME:
				return new MissVolumeMenu();
			default:
				return new OptionsSubState();
		}
	}
}

class CustomKeys extends OptionsSubState {
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
	}

	override function finishTransition(twn:FlxTween) {
		keys = new Alphabet(0, 0, keyString, true, false);
		keys.screenCenter();
		add(keys);

		howManyKey = new FlxText(0, 0, FlxG.width, "Standard Four Keybinds", 32);
		howManyKey.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		howManyKey.borderSize = 2;
		howManyKey.screenCenter(X);
		howManyKey.y = FlixelCompat.getScreenCenter(howManyKey, Y) + (keys.height * 1.5);
		add(howManyKey);
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
	}

	override function finishTransition(twn:FlxTween) {
		keys = new Alphabet(0, 0, keyString, true, false);
		keys.screenCenter();
		add(keys);

		howManyKey = new FlxText(0, 0, FlxG.width, "Standard Four Keybinds", 32);
		howManyKey.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		howManyKey.borderSize = 2;
		howManyKey.screenCenter(X);
		howManyKey.y = FlixelCompat.getScreenCenter(howManyKey, Y) + (keys.height * 1.5);
		add(howManyKey);
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
	private var choices:Alphabet;
	private var yourSure:FlxText;

	private var section:Int = 0;

	private var colorSway:Float = 0;

	private var changingKeys:Bool = false;

	public function new() {
		super();
	}

	override function finishTransition(twn:FlxTween) {
		choices = new Alphabet(0, 0, "yes no", true, false);
		choices.screenCenter();
		add(choices);

		yourSure = new FlxText(0, 0, FlxG.width, "Are you sure?", 32);
		yourSure.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		yourSure.borderSize = 2;
		yourSure.screenCenter(X);
		yourSure.y = FlixelCompat.getScreenCenter(yourSure, Y) + (choices.height * 1.5);
		add(yourSure);
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
				colorSway = 0;
				section -= 1;
			}

			if(controls.RIGHT_P) {
				colorSway = 0;
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
	private var valueTxt:FlxText;
	private var tutorial:FlxText;

	private var changingKeys:Bool = false;

	public function new() {
		super();
	}

	override function finishTransition(twn:FlxTween) {
		valueTxt = new FlxText(0, 0, FlxG.width, "< " + SaveData.getData(SaveType.GAMMA) + " >", 64);
		valueTxt.setFormat("VCR OSD Mono", 64, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		valueTxt.borderSize = 4;
		valueTxt.screenCenter();
		add(valueTxt);

		tutorial = new FlxText(0, 0, FlxG.width, "Use left and right keys", 32);
		tutorial.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		tutorial.borderSize = 2;
		tutorial.screenCenter(X);
		tutorial.y = FlixelCompat.getScreenCenter(tutorial, Y) + (tutorial.height * 2);
		add(tutorial);
	}

	function getShaders():BuiltInShaders {
		var gameFilters:Array<Dynamic> = FlixelCompat.getGameFilters();

		for(i in 0...gameFilters.length) {
			var shaderFilter:ShaderFilter = cast(gameFilters[i], ShaderFilter);
			var shaders:BuiltInShaders = cast (shaderFilter.shader, BuiltInShaders);

			if(shaders.shader == ShaderType.GAMMA) {
				return shaders;
			}
		}

		throw "Error: Has GAMMA not been implemented";
		return null;
	}

	override function update(elapsed:Float) {
		if(!changingKeys && valueTxt != null) {
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

class OffsetMenu extends OptionsSubState {
	private var valueTxt:FlxText;
	private var tutorial:FlxText;
	private var statusTxt:FlxText;
	private var countTxt:FlxText;
	private var receptor:FlxSprite;
	private var receptorGraphic:FlxGraphic;
	private var arrowGraphic:FlxGraphic;
	private var arrows:FlxTypedGroup<FlxSprite>;
	private var arrowData:Array<LatencyArrowData> = [];

	private var changingKeys:Bool = false;
	private var calibrationActive:Bool = false;
	private var calibrationReady:Bool = false;
	private var differences:Array<Float> = [];

	private var calibrationBpm:Float = 100;
	private var msPerBeat:Float = 60000 / 100;
	private var nextArrowBeat:Float = 4;
	private var appliedOffset:Float = 0;
	private var savedOffset:Float = 0;
	private var targetOffset:Float = 0;
	private var previousOffset:Float = 0;
	private var offsetLerpTime:Float = 1;
	private var lastMusicTime:Float = 0;

	public function new() {
		super();
	}

	override function finishTransition(twn:FlxTween) {
		valueTxt = new FlxText(0, 0, FlxG.width, formatOffsetText(), 64);
		valueTxt.setFormat("VCR OSD Mono", 64, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		valueTxt.borderSize = 4;
		valueTxt.screenCenter();
		valueTxt.y -= 120;
		add(valueTxt);

		tutorial = new FlxText(0, 0, FlxG.width, "LEFT/RIGHT adjust   ENTER calibrate   BACK close", 24);
		tutorial.setFormat("VCR OSD Mono", 24, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		tutorial.borderSize = 2;
		tutorial.screenCenter(X);
		tutorial.y = valueTxt.y + valueTxt.height + 12;
		add(tutorial);

		statusTxt = new FlxText(0, 0, FlxG.width, "Press ENTER to start latency calibration.", 28);
		statusTxt.setFormat("VCR OSD Mono", 28, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		statusTxt.borderSize = 2;
		statusTxt.screenCenter(X);
		statusTxt.y = tutorial.y + tutorial.height + 24;
		add(statusTxt);

		countTxt = new FlxText(0, 0, FlxG.width, "", 24);
		countTxt.setFormat("VCR OSD Mono", 24, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		countTxt.borderSize = 2;
		countTxt.screenCenter(X);
		countTxt.y = statusTxt.y + statusTxt.height + 16;
		add(countTxt);

		arrows = new FlxTypedGroup<FlxSprite>();
		add(arrows);

		receptor = new FlxSprite();
		receptor.visible = false;
		add(receptor);

		loadCalibrationAssets();
	}

	function loadCalibrationAssets():Void {
		Paths.loadRemoteSharedGraphic("latencyReceptor", function(graphic:FlxGraphic) {
			receptorGraphic = graphic;

			if(receptor != null) {
				if(graphic != null) {
					receptor.loadGraphic(graphic);
				}else {
					receptor.makeGraphic(96, 96, 0xFFB0B0B0);
				}

				receptor.antialiasing = SaveData.getData(SaveType.GRAPHICS);
				receptor.visible = true;
				recenterReceptor();
			}
		});

		Paths.loadRemoteSharedGraphic("latencyArrow", function(graphic:FlxGraphic) {
			arrowGraphic = graphic;
			calibrationReady = true;
		});
	}

	function recenterReceptor():Void {
		if(receptor == null || receptor.graphic == null) {
			return;
		}

		receptor.updateHitbox();
		receptor.centerOffsets();
		receptor.centerOrigin();
		receptor.x = (FlxG.width - receptor.width) / 2;
		receptor.y = (FlxG.height * 0.72) - (receptor.height / 2);
	}

	inline function formatOffsetText():String {
		return "< " + Std.int(SaveData.getData(SaveType.NOTE_OFFSET)) + "ms >";
	}

	inline function currentBeat():Float {
		if(FlxG.sound.music == null) {
			return 0;
		}

		return FlxG.sound.music.time / msPerBeat;
	}

	function createArrow(beat:Float):Void {
		var arrow = new FlxSprite();

		if(arrowGraphic != null) {
			arrow.loadGraphic(arrowGraphic);
		}else {
			arrow.makeGraphic(48, 48, FlxColor.WHITE);
		}

		arrow.antialiasing = SaveData.getData(SaveType.GRAPHICS);
		arrow.alpha = 1;
		arrow.updateHitbox();
		arrow.x = receptor.x + (receptor.width - arrow.width) / 2;
		arrow.y = FlxG.height + arrow.height;
		arrows.add(arrow);

		arrowData.push({
			sprite: arrow,
			beat: beat
		});
	}

	function clearArrows():Void {
		if(arrowData != null) {
			arrowData.resize(0);
		}

		if(arrows != null) {
			arrows.clear();
		}
	}

	function getAverage():Float {
		if(differences.length == 0) {
			return 0;
		}

		var avg:Float = 0;
		for(value in differences) {
			avg += value;
		}

		return avg / differences.length;
	}

	function getConsistency():Float {
		if(differences.length == 0) {
			return 0;
		}

		var avg = getAverage();
		var variance:Float = 0;

		for(value in differences) {
			variance += Math.pow(value - avg, 2);
		}

		return Math.sqrt(variance / differences.length);
	}

	function addDifference(ms:Float):Void {
		differences.push(ms);

		if(differences.length > 2 && differences.length % 2 != 0) {
			previousOffset = appliedOffset;
			targetOffset = Math.round(getAverage());
			offsetLerpTime = 0;
		}
	}

	function startCalibration():Void {
		if(changingKeys || !calibrationReady) {
			if(!calibrationReady) {
				statusTxt.text = "Loading latency assets...";
			}

			return;
		}

		calibrationActive = true;
		differences = [];
		savedOffset = SaveData.getData(SaveType.NOTE_OFFSET);
		appliedOffset = 0;
		targetOffset = 0;
		previousOffset = 0;
		offsetLerpTime = 1;

		valueTxt.text = "< 0ms >";
		statusTxt.text = "Press any key to the beat.\nThe arrows should line up with the receptor.";
		countTxt.text = "Current Offset: 0ms\n0/16";

		clearArrows();

		FlxG.sound.playMusic(Paths.sound("soundTest"));
		if(FlxG.sound.music != null) {
			FlxG.sound.music.time = 0;
			lastMusicTime = 0;
		}

		nextArrowBeat = 4;
	}

	function finishCalibration(saveResult:Bool):Void {
		calibrationActive = false;
		clearArrows();

		if(FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}

		if(saveResult) {
			FlxG.save.data.noteOffset = Math.round(targetOffset);
			SaveData.saveClient();
			statusTxt.text = "Calibration complete.";
		}else {
			FlxG.save.data.noteOffset = savedOffset;
			SaveData.saveClient();
			statusTxt.text = "Calibration cancelled.";
		}

		valueTxt.text = formatOffsetText();
		countTxt.text = "";
	}

	function processCalibrationInput():Void {
		if(!FlxG.keys.justPressed.ANY || FlxG.sound.music == null) {
			return;
		}

		var beatValue = currentBeat();
		var closestBeat = Math.round(beatValue);
		var diffMs = (closestBeat - beatValue) * msPerBeat;

		var closestArrow:LatencyArrowData = null;
		var closestArrowDiff:Float = 99999;
		for(data in arrowData) {
			var dataDiff = Math.abs(data.beat - beatValue);
			if(dataDiff < closestArrowDiff) {
				closestArrowDiff = dataDiff;
				closestArrow = data;
			}
		}

		if(closestArrow != null && closestArrowDiff < 0.35) {
			closestArrow.sprite.kill();
			arrows.remove(closestArrow.sprite, true);
			arrowData.remove(closestArrow);
		}

		if(getConsistency() > 80 && differences.length > 4) {
			differences = [];
			appliedOffset = 0;
			targetOffset = 0;
			previousOffset = 0;
			offsetLerpTime = 1;
			statusTxt.text = "Try to be a little more consistent with your timing!";
			countTxt.text = "Current Offset: 0ms\n0/16";
			return;
		}

		addDifference(diffMs);

		if(diffMs == 0) {
			statusTxt.text = "Perfect!";
		}else if(diffMs > 0) {
			statusTxt.text = "Early!\n" + Std.int(diffMs) + "ms";
		}else {
			statusTxt.text = "Late!\n" + Std.int(diffMs) + "ms";
		}

		countTxt.text = "Current Offset: " + Std.int(appliedOffset) + "ms\n" + differences.length + "/16";

		if(differences.length >= 16) {
			targetOffset = Math.round(getAverage());
			appliedOffset = targetOffset;
			finishCalibration(true);
		}
	}

	function updateCalibration(elapsed:Float):Void {
		if(FlxG.sound.music == null) {
			return;
		}

		if(offsetLerpTime < 1) {
			offsetLerpTime += elapsed * 2;
			if(offsetLerpTime > 1) {
				offsetLerpTime = 1;
			}

			appliedOffset = FlxMath.lerp(previousOffset, targetOffset, FlxEase.cubeInOut(offsetLerpTime));
		}else {
			appliedOffset = targetOffset;
		}

		if(FlxG.sound.music.time < lastMusicTime) {
			clearArrows();
			nextArrowBeat = 4;
		}
		lastMusicTime = FlxG.sound.music.time;

		var beatValue = currentBeat();

		while(beatValue >= nextArrowBeat - 1) {
			createArrow(nextArrowBeat);
			nextArrowBeat = (nextArrowBeat - (nextArrowBeat % 2)) + 2;
		}

		var toRemove:Array<LatencyArrowData> = [];
		for(data in arrowData) {
			if(data.sprite == null) {
				toRemove.push(data);
				continue;
			}

			var beatOffset = appliedOffset / msPerBeat;
			var songMs = data.beat * msPerBeat;
			data.sprite.x = receptor.x + (receptor.width - data.sprite.width) / 2;
			data.sprite.y = receptor.y + ((songMs + appliedOffset) - FlxG.sound.music.time) * 0.45 - (data.sprite.height / 2);

			if((data.beat + beatOffset) < beatValue - 0.25) {
				data.sprite.alpha -= elapsed * 5;
			}

			if(data.sprite.alpha <= 0) {
				data.sprite.kill();
				arrows.remove(data.sprite, true);
				toRemove.push(data);
			}
		}

		for(data in toRemove) {
			arrowData.remove(data);
		}

		var beatPhase = beatValue - Math.floor(beatValue);
		var pulse = 1 - Math.min(Math.abs(beatPhase - 0.1) / 0.2, 1);
		var pulseScale = 1 + (pulse * 0.08);
		receptor.scale.set(pulseScale, pulseScale);
		receptor.updateHitbox();
		recenterReceptor();

		countTxt.text = "Current Offset: " + Std.int(appliedOffset) + "ms\n" + differences.length + "/16";
	}

	override function update(elapsed:Float) {
		if(valueTxt == null || changingKeys) {
			super.update(elapsed);
			return;
		}

		if(calibrationActive) {
			if(controls.BACK) {
				finishCalibration(false);
			}else {
				processCalibrationInput();
				updateCalibration(elapsed);
			}
		}else {
			var multiply = FlxG.keys.pressed.SHIFT ? 10 : 1;

			if(controls.LEFT_P) {
				FlxG.save.data.noteOffset = Math.round((FlxG.save.data.noteOffset - multiply));
				valueTxt.text = formatOffsetText();
			}else if(controls.RIGHT_P) {
				FlxG.save.data.noteOffset = Math.round((FlxG.save.data.noteOffset + multiply));
				valueTxt.text = formatOffsetText();
			}

			if(controls.ACCEPT) {
				startCalibration();
			}else if(controls.BACK) {
				changingKeys = true;
				SaveData.saveClient();
				close();
			}
		}

		super.update(elapsed);
	}

	override function destroy() {
		if(calibrationActive && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}

		receptor = FlxDestroyUtil.destroy(receptor);
		arrows = FlxDestroyUtil.destroy(arrows);
		super.destroy();
	}
}

class MissVolumeMenu extends OptionsSubState {
	private var valueTxt:FlxText;
	private var tutorial:FlxText;

	private var changingKeys:Bool = false;

	public function new() {
		super();
	}

	override function finishTransition(twn:FlxTween) {
		valueTxt = new FlxText(0, 0, FlxG.width, "< " + SaveData.getData(SaveType.MISS_SOUND_VOLUME) + " >", 64);
		valueTxt.setFormat("VCR OSD Mono", 64, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		valueTxt.borderSize = 4;
		valueTxt.screenCenter();
		add(valueTxt);

		tutorial = new FlxText(0, 0, FlxG.width, "Use left and right keys", 32);
		tutorial.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		tutorial.borderSize = 2;
		tutorial.screenCenter(X);
		tutorial.y = FlixelCompat.getScreenCenter(tutorial, Y) + (tutorial.height * 2);
		add(tutorial);
	}

	override function update(elapsed:Float) {
		if(!changingKeys && valueTxt != null) {
			if(controls.LEFT_P) {
				FlxG.save.data.missVolume = FlxG.save.data.missVolume - 0.1;
				FlxG.save.data.missVolume = Math.round(FlxG.save.data.missVolume * 10) / 10;
			}else if(controls.RIGHT_P) {
				FlxG.save.data.missVolume = FlxG.save.data.missVolume + 0.1;
				FlxG.save.data.missVolume = Math.round(FlxG.save.data.missVolume * 10)  / 10;
			}

			if(SaveData.getData(SaveType.MISS_SOUND_VOLUME) > 1) {
				FlxG.save.data.missVolume = 1;
			}else if(SaveData.getData(SaveType.MISS_SOUND_VOLUME) < 0) {
				FlxG.save.data.missVolume = 0;
			}

			valueTxt.text = "< " + SaveData.getData(SaveType.MISS_SOUND_VOLUME) + " >";

			if(controls.BACK || controls.ACCEPT) {
				changingKeys = true;

				SaveData.saveClient();

				close();
			}
		}
	}
}
