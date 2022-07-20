package feshixl.math;

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
}