package feshixl.math;

import flixel.math.FlxMatrix;

class FeshMath3D {

    /**
    * @param Z regular 2d angle from `FlxSprite`.
    */
    public inline static function rotateWithTrig3D(matrix:FlxMatrix, thetaX:Float, thetaY:Float, thetaZ:Float, hasPerspective:Bool = true):Void {

        final xc:Float = Math.cos(thetaX);
        final xs:Float = Math.sin(thetaX);
        final yc:Float = Math.cos(thetaY);
        final ys:Float = Math.sin(thetaY);
        final zc:Float = Math.cos(thetaZ);
        final zs:Float = Math.sin(thetaZ);

        var p1:Float = 1;
        var p2:Float = 1;
        var p3:Float = 1;

        matrix.rotateWithTrig(zc, zs);

        var a1:Float = p1 * ((0 * ys) + (matrix.a * yc));
        matrix.b = p1 * ((matrix.b * xc) - ((0 * yc - matrix.a * ys) * xs));
        matrix.a = a1;

        var c1:Float = p2 * ((0 * ys) + (matrix.c * yc));
        matrix.d = p2 * ((matrix.d * xc) - ((0 * yc - matrix.c * ys) * xs));
        matrix.c = c1;

        var tx1:Float = p3 * ((0 * ys) + (matrix.tx * yc));
        matrix.ty = p3 * ((matrix.ty * xc) - ((0 * yc - matrix.tx * ys) * xs));
        matrix.tx = tx1;
    }
}