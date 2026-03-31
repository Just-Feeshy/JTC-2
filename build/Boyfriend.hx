package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.util.FlxTimer;

using StringTools;

class Boyfriend extends Character {
	public function new(x:Float, y:Float, ?char:String = 'bf', frameOffsetApply:Bool = true) {
		super(x, y, char, true, frameOffsetApply);
	}

	override function update(elapsed:Float)
	{
		if (!debugMode && animation.curAnim != null)
		{
			if (animation.curAnim.name == 'firstDeath' && animation.curAnim.finished && !isDead)
			{
				playAnim('deathLoop');
			}
		}

		super.update(elapsed);
	}
}
