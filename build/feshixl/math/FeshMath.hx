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
}