package feshixl.math;

import flixel.math.FlxMath;

class FeshMath {

    /**
	 * "Clamps" a value to boundaries (min, max).
     */
    public inline static function clamp(value:Float, min:Float, max:Float):Float {
        if (value < min)
			return min;
		else if (value > max)
			return max;
		else
			return value;
    }

	/**
	 * Converts specified angle in degrees to radians.
	 * @return angle in radians
	 */
	public inline static function radians(deg:Float):Float {
		return deg * (Math.PI / 180);
	}

	/**
	 * Converts specified angle in radians to degrees.
	 * @return angle in degrees
	 */
	public inline static function degrees(rads:Float):Float {
		return rads * (180 / Math.PI);
	}

	/**
	 * Returns the trigonometric secant of the specified angle `v`, in radians.
	 * If `v` is `NaN` or infinite, the result is `NaN`.
	 */
	public inline static function sec(v:Float):Float {
		return 1 / Math.cos(v);
	}

	/**
	 * Returns the trigonometric cosecant of the specified angle `v`, in radians.
	 * If `v` is `NaN` or infinite, the result is `NaN`.
	 */
	public inline static function csc(v:Float):Float {
		return 1 / Math.sin(v);
	}

	/**
	 * @return the cube root of @param x.
	 */
	public inline static function cbrt(x:Float):Float {
		#if cpp
		return untyped __cpp__("std::cbrt({0})", x);
		#elseif js
		return untyped __js__("Math.cbrt({0})", x);
		#else
		return Math.pow(x, 1 / 3);
		#end
	}
}