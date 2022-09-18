package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;

class Strum extends feshixl.FeshSprite {
	public var noteData(get, never):Int;
	public var direction(get, never):String;

	public var ifCustom:String = "regular";
	public var ifOpponent:Bool;
	public var onlyFans:Float;
	public var xAxis:Bool;

	public var directionAngle:Float = 0;

	public var prevVisible:Bool = true;
	public var onlyVisible:Bool = true;

	private var rendered:Bool = false;

	#if (debug || USING_MOD_DEBUG)
	private var testRotationArray:Array<Float> = [
		0.25,
		0.5
	];

	private var TCR:Int = 0;
	#end

	override public function new(x:Float, y:Float) {
		super(x, y);
		
		onlyFans = 1;

		if(Main.feeshmoraModifiers && DefaultHandler.modifiers.blindEffect.enabled) {
			visible = false;
		}
	}

	override function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		if(AnimName == 'confirm' && !rendered) {
			updateFrameSizeOffset(0, -1, 'confirm');
			rendered = true;
		}

		super.playAnim(AnimName, Force, Reversed, Frame);
		
		centerOffsets();
		centerOrigin();

		if(AnimName == "pressed")
			indevRenderer();
	}

	public function setupAnimations():Void {
		animation.addByPrefix('static', 'arrow' + direction.toUpperCase());
		animation.addByPrefix('pressed', direction + ' press', 24, false);
		animation.addByPrefix('confirm', direction + ' confirm0', 24, false);

		updateHitbox();
	}

	/**
	*Use this function instead of the visible value.
	*/
	public function setVisibility(visibility:Bool):Bool {
		prevVisible = visible;
		visible = visibility;
		return visible;
	}

	function indevRenderer():Void {
		/*
		if(rendered)return;
		rendered = true;

		@:privateAccess trace(_frame.matrix);
		*/
	}

	function get_noteData():Int {
		return ID;
	}

	function get_direction():String {
		if(PlayState.SONG.fifthKey) {
			switch(noteData) {
				case 0: return "left";
				case 1: return "down";
				case 2: return "space";
				case 3: return "up";
				case 4: return "right";
			}
		}else {
			switch(noteData) {
				case 0: return "left";
				case 1: return "down";
				case 2: return "up";
				case 3: return "right";
			}
		}

		return "";
	}

	override function update(elapsed:Float):Void {
		super.update(elapsed / (FlxG.save.data.showAntialiasing ? 1 : 1.5));

		if (animation.finished && ifOpponent && animation.curAnim.name != 'static') {
			playAnim('static');
			centerOffsets();
			centerOrigin();
		}

		if(Main.feeshmoraModifiers && DefaultHandler.modifiers != null) {
			if((animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && DefaultHandler.modifiers.blindEffect.enabled) {
				visible = false;
			}
			
			if(!(animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && DefaultHandler.modifiers.blindEffect.enabled && visible == false) {
				visible = true;
			}
		}

		#if (debug || USING_MOD_DEBUG)
		if (FlxG.keys.justPressed.TWO) {
			TCR = (TCR + 1) % testRotationArray.length;
			directionAngle = Math.PI * testRotationArray[TCR];
		}
		#end
	}
}