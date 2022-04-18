package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxAxes;

class Strum extends FlxSprite {
	public var ifCustom:String = "regular";
	public var ifOpponent:Bool;
	public var onlyFans:Float;
	public var xAxis:Bool;

	public var prevVisible:Bool = true;
	public var onlyVisible:Bool = true;

	override public function new(x:Float, y:Float) {
		super(x, y);
		
		onlyFans = 1;

		if(PlayState.modifierCheckList('blind effect'))
			visible = false;
	}

	/**
	*Use this function instead of the visible value.
	**/
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

	override function update(elapsed:Float) {
		super.update(elapsed / (FlxG.save.data.showAntialiasing ? 1 : 1.5));

		if (animation.finished && ifOpponent && animation.curAnim.name == 'confirm') {
			animation.play('static');
			centerOffsets();
		}

		if((animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && PlayState.modifierCheckList('blind effect'))
			visible = false;
		
		if(animation.curAnim.name == 'confirm' && PlayState.modifierCheckList('blind effect') && visible == false) {
			visible = true;
		}
	}
}