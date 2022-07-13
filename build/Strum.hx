package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxAxes;
import flixel.util.FlxColor;

class Strum extends EditorSprite {
	public var noteData(get, never):Int;
	public var direction(get, never):String;

	public var ifCustom:String = "regular";
	public var ifOpponent:Bool;
	public var onlyFans:Float;
	public var xAxis:Bool;

	public var prevVisible:Bool = true;
	public var onlyVisible:Bool = true;

	private var rendered:Bool = false;

	override public function new(x:Float, y:Float) {
		super(x, y);
		
		onlyFans = 1;

		if(PlayState.modifierCheckList('blind effect'))
			visible = false;
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

	public function getInverseAxis(ax:FlxAxes):Float {
		if(ax == FlxAxes.Y)
			return x;
		else
			return y;
	}

	public function getRegularAxis(ax:FlxAxes):Float {
		if(ax == FlxAxes.Y)
			return y;
		else
			return x;
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
			animation.play('static');
			centerOffsets();
			centerOrigin();
		}

		if((animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && PlayState.modifierCheckList('blind effect'))
			visible = false;
		
		if(!(animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && PlayState.modifierCheckList('blind effect') && visible == false) {
			visible = true;
		}
	}
}