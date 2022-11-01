package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.group.FlxSpriteGroup;
import flixel.math.FlxMath;
import flixel.util.FlxTimer;

import flixel.util.FlxAxes;

import SaveData.SaveType;

using StringTools;

/**
 * Loosley based on FlxTypeText lolol
 */
class Alphabet extends FlxSpriteGroup
{
	public var yMultiplier:Int = 120;

	public var delay:Float = 0.05;
	public var paused:Bool = false;

	// for menu shit
	public var targetY:Int = 0;
	public var isMenuItem:Bool = false;

	//for Feeshmora Options
	public var isOptionItem:Bool = false;
	public var prevX:Float = 0;

	public var text:String = "";

	var _finalText:String = "";
	var _curText:String = "";

	public var widthOfWords:Float = FlxG.width;

	var yMulti:Float = 1;

	public var totalSpaces:Int = 0;

	public var letters:Array<AlphaCharacter> = [];

	// custom shit
	// amp, backslash, question mark, apostrophy, comma, angry faic, period
	var lastSprite:AlphaCharacter;
	var xPosResetted:Bool = false;
	var lastWasSpace:Bool = false;

	var splitWords:Array<String> = [];

	var isBold:Bool = false;

	public function new(x:Float, y:Float, text:String = "", ?bold:Bool = false, typed:Bool = false, ?startX:Float = 0)
	{
		super(x, y);

		_finalText = text;
		this.text = text;
		isBold = bold;

		if (text != "")
		{
			if (typed)
			{
				startTypedText(startX);
			}
			else
			{
				addText(startX);
			}
		}
	}

	public function addText(startX:Float)
	{
		doSplitWords();

		var xPos:Float = startX;
		for (character in splitWords) {
			if (character == " " || character == "-" || character == "_")
			{
				lastWasSpace = true;
				totalSpaces++;
			}

			var isNumber:Bool = AlphaCharacter.numbers.indexOf(character) != -1;
			var isSymbol:Bool = AlphaCharacter.symbols.indexOf(character) != -1;
			var isLetter:Bool = AlphaCharacter.alphabet.indexOf(character.toLowerCase()) != -1;

			if (isNumber || isLetter || (isSymbol && !isBold)) {
				if (lastSprite != null) {
					xPos = lastSprite.x + lastSprite.width;
				}

				if (lastWasSpace) {
					xPos += 40;
					lastWasSpace = false;
				}

				// var letter:AlphaCharacter = new AlphaCharacter(30 * loopNum, 0);
				var letter:AlphaCharacter = new AlphaCharacter(xPos, 0);

				if (isBold) {
					if(isNumber) {
						letter.isBoldNumbers();
					}

					letter.createBold(character);
				}else {
					if(isNumber) {
						letter.createNumber(character);
					}else if(isSymbol) {
						letter.createSymbol(character);
					}else {
						letter.createLetter(character);
					}
				}

				letter.spaceLocation = totalSpaces;

				add(letter);
				letters.push(letter);

				lastSprite = letter;
			}

			// loopNum += 1;
		}
	}

	function doSplitWords():Void
	{
		splitWords = _finalText.split("");
	}

	public var personTalking:String = 'gf';

	public function startTypedText(startX:Float):Void
	{
		_finalText = text;
		doSplitWords();

		// trace(arrayShit);

		var loopNum:Int = 0;

		var xPos:Float = startX;
		var curRow:Int = 0;

		new FlxTimer().start(0.05, function(tmr:FlxTimer)
		{
			// trace(_finalText.fastCodeAt(loopNum) + " " + _finalText.charAt(loopNum));
			if (_finalText.fastCodeAt(loopNum) == "\n".code)
			{
				yMulti += 1;
				xPosResetted = true;
				xPos = startX;
				curRow += 1;
			}

			if (splitWords[loopNum] == " ")
			{
				lastWasSpace = true;
			}

			#if (haxe >= "4.0.0")
			var isNumber:Bool = AlphaCharacter.numbers.contains(splitWords[loopNum]);
			var isSymbol:Bool = AlphaCharacter.symbols.contains(splitWords[loopNum]);
			#else
			var isNumber:Bool = AlphaCharacter.numbers.indexOf(splitWords[loopNum]) != -1;
			var isSymbol:Bool = AlphaCharacter.symbols.indexOf(splitWords[loopNum]) != -1;
			#end

			if (AlphaCharacter.alphabet.indexOf(splitWords[loopNum].toLowerCase()) != -1 || isNumber || isSymbol)
				// if (AlphaCharacter.alphabet.contains(splitWords[loopNum].toLowerCase()) || isNumber || isSymbol)

			{
				if (lastSprite != null && !xPosResetted)
				{
					lastSprite.updateHitbox();
					xPos += lastSprite.width + 3;
					// if (isBold)
					// xPos -= 80;
				}
				else
				{
					xPosResetted = false;
				}

				if (lastWasSpace)
				{
					xPos += 20;
					lastWasSpace = false;
				}
				// trace(_finalText.fastCodeAt(loopNum) + " " + _finalText.charAt(loopNum));

				// var letter:AlphaCharacter = new AlphaCharacter(30 * loopNum, 0);
				var letter:AlphaCharacter = new AlphaCharacter(xPos, 55 * yMulti);
				letter.row = curRow;
				if (isBold)
				{
					if(isNumber) {
						letter.isBoldNumbers();
					}
					
					letter.createBold(splitWords[loopNum]);
				}
				else
				{
					if (isNumber)
					{
						letter.createNumber(splitWords[loopNum]);
					}
					else if (isSymbol)
					{
						letter.createSymbol(splitWords[loopNum]);
					}
					else
					{
						letter.createLetter(splitWords[loopNum]);
					}

					letter.x += 90;
				}

				if (FlxG.random.bool(40))
				{
					var daSound:String = "GF_";
					FlxG.sound.play(Paths.soundRandom(daSound, 1, 4));
				}

				add(letter);

				lastSprite = letter;
			}

			loopNum += 1;

			tmr.time = FlxG.random.float(0.04, 0.09);
		}, splitWords.length);
	}

	override function update(elapsed:Float)
	{
		prevX = x;

		if (isMenuItem)
		{
			var scaledY = FlxMath.remapToRange(targetY, 0, 1, 0, 1.3);
	
			y = FlxMath.lerp(y, (scaledY * yMultiplier) + (FlxG.height * 0.48), 0.16);
	
			if(targetY == 0)
				x = FlxMath.lerp(prevX, (targetY * 20) + 140, 0.16);
			else
				x = FlxMath.lerp(prevX, (targetY * 20) + 90, 0.16);
		}

		super.update(elapsed);
	}
}

class AlphaCharacter extends FlxSprite
{
	@:final public static var alphabet:String = "abcdefghijklmnopqrstuvwxyz";

	@:final public static var numbers:String = "1234567890";

	@:final public static var symbols:String = "|~#$%()*+-:;<=>@[]^_.,'!?";

	public var spaceLocation:Int = 0;

	public var row:Int = 0;

	public function new(x:Float, y:Float)
	{
		super(x, y);
		var tex = Paths.getSparrowAtlas('alphabet');
		frames = tex;

		antialiasing = SaveData.getData(SaveType.GRAPHICS);
	}

	public function isBoldNumbers() {
		animation.destroyAnimations();

		var tex = Paths.getSparrowAtlas('numbers-bold');
		frames = tex;
	}

	public function createBold(letter:String)
	{
		if(symbols.indexOf(letter) != -1) {
			return;
		}

		animation.addByPrefix(letter, letter.toUpperCase() + " bold", 24);
		animation.play(letter);
		updateHitbox();
	}

	public function createLetter(letter:String):Void
	{
		var letterCase:String = "lowercase";
		if (letter.toLowerCase() != letter)
		{
			letterCase = 'capital';
		}

		animation.addByPrefix(letter, letter + " " + letterCase, 24);
		animation.play(letter);
		updateHitbox();

		y = (110 - height);
		y += row * 60;
	}

	public function createNumber(letter:String):Void
	{
		animation.addByPrefix(letter, letter, 24);
		animation.play(letter);

		updateHitbox();

		y = (110 - height);
		y += row * 60;
	}

	public function createSymbol(letter:String)
	{
		switch (letter)
		{
			case '.':
				animation.addByPrefix(letter, 'period', 24);
				animation.play(letter);
				y += 95;
			case "'":
				animation.addByPrefix(letter, 'apostraphie', 24);
				animation.play(letter);
				y -= 0;
			case "?":
				animation.addByPrefix(letter, 'question mark', 24);
				animation.play(letter);
			case "!":
				animation.addByPrefix(letter, 'exclamation point', 24);
				animation.play(letter);
			case ">":
				animation.addByPrefix(letter, 'right arrow', 24);
				animation.play(letter);
			case "<":
				animation.addByPrefix(letter, 'left arrow', 24);
				animation.play(letter);
			case "^":
				animation.addByPrefix(letter, 'up arrow', 24);
				animation.play(letter);
		}

		updateHitbox();
	}
}