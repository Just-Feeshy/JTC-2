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

	public var directionAngle:Float = 0; //This is in radians.
	public var holdTimer:Float = 0;

	public var prevVisible:Bool = true;
	public var onlyVisible:Bool = true;

	private var rendered:Bool = false;

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
	}

	public function setupAnimations():Void {
		animation.addByPrefix('static', 'arrow' + direction.toUpperCase());
		animation.addByPrefix('pressed', direction + ' press', 24, false);
		animation.addByPrefix('confirm', direction + ' confirm0', 24, false);

		updateHitbox();
	}

	public function getAnimName():String {
		if(animation.curAnim == null) {
			return "";
		}

		return animation.curAnim.name;
	}

	/**
	*Use this function instead of the visible value.
	*/
	public function setVisibility(visibility:Bool):Bool {
		prevVisible = visible;
		visible = visibility;
		return visible;
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
		if(holdTimer > 0) {
			holdTimer -= elapsed;

			if(holdTimer < 0) {

				if(ifOpponent || getAnimName() != 'confirm') {
					playAnim('static');
				}else {
					playAnim('pressed');
				}

				holdTimer = 0;
			}
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
		if (FlxG.keys.pressed.TWO) {
			directionAngle += elapsed;
		}
		#end

		super.update(elapsed);
	}
}
