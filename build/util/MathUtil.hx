package util;

import flixel.math.FlxMath;

class MathUtil
{
	public static function gcd(m:Int, n:Int):Int
	{
		m = Math.floor(Math.abs(m));
		n = Math.floor(Math.abs(n));

		while(true) {
			if(n == 0) {
				return m;
			}

			var t:Int = m;
			m = n;
			n = t % m;
		}
	}

	public static function smoothLerpPrecision(current:Float, target:Float, elapsed:Float, duration:Float):Float
	{
		if(duration <= 0) {
			return target;
		}

		return FlxMath.lerp(target, current, Math.exp(-elapsed / duration));
	}
}
