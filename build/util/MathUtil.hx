package util;

import flixel.math.FlxMath;

class MathUtil
{
	public static function smoothLerpPrecision(current:Float, target:Float, elapsed:Float, duration:Float):Float
	{
		if(duration <= 0) {
			return target;
		}

		return FlxMath.lerp(target, current, Math.exp(-elapsed / duration));
	}
}
