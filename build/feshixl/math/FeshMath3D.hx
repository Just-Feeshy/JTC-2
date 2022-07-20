package feshixl.math;

import flixel.math.FlxMatrix;

class FeshMath3D {
    /**
    * @param Z regular 2d angle from `FlxSprite`.
    */
    public inline static function rotateWithTrig3D(matrix:FlxMatrix, thetaX:Float, thetaY:Float, thetaZ:Float):Void {
        final xc:Float = Math.cos(thetaX);
        final xs:Float = Math.sin(thetaX);
        final yc:Float = Math.cos(thetaY);
        final ys:Float = Math.sin(thetaY);
        final zc:Float = Math.cos(thetaZ);
        final zs:Float = Math.sin(thetaZ);

        var a1:Float = (matrix.a * zc - matrix.b * zs) * yc - 0 * ys;
		matrix.b = (matrix.a * zs + matrix.b * zc) * xc - (0 * yc + a1 * ys) * xs;
		matrix.a = a1;

		var c1:Float = (matrix.c * zc - matrix.d * zs) * yc - 0 * ys;
		matrix.d = (matrix.c * zs + matrix.d * zc) * xc - (0 * yc + c1 * ys) * xs;
		matrix.c = c1;

		var tx1:Float = (matrix.tx * zc - matrix.ty * zs) * yc - 0 * ys;
		matrix.ty = (matrix.tx * zs + matrix.ty * zc) * xc - (0 * yc + tx1 * ys) * xs;
		matrix.tx = tx1;
    }
}