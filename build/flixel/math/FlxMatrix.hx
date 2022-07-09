package flixel.math;

import flash.geom.Matrix;

/**
 * Helper class for making fast matrix calculations for rendering.
 * It mostly copies Matrix class, but with some additions for
 * faster rotation by 90 degrees.
 */
class FlxMatrix extends Matrix
{
	/**
	 * Rotates this matrix, but takes the values of sine and cosine,
	 * so it might be useful when you rotate multiple matrices by the same angle
	 * @param	cos	The cosine value for rotation angle
	 * @param	sin	The sine value for rotation angle
	 * @return	this transformed matrix
	 */
	public inline function rotateWithTrig(cos:Float, sin:Float):FlxMatrix
	{
		var a1:Float = a * cos - b * sin;
		b = a * sin + b * cos;
		a = a1;

		var c1:Float = c * cos - d * sin;
		d = c * sin + d * cos;
		c = c1;

		var tx1:Float = tx * cos - ty * sin;
		ty = tx * sin + ty * cos;
		tx = tx1;

		return this;
	}

    /**
    * @param Z regular 2d angle from `FlxSprite`.
    */
    public inline function rotateWithTrig3D(thetaX:Float, thetaY:Float, thetaZ:Float):Matrix {
        final xc:Float = Math.cos(thetaX);
        final xs:Float = Math.sin(thetaX);
        final yc:Float = Math.cos(thetaY);
        final ys:Float = Math.sin(thetaY);
        final zc:Float = Math.cos(thetaZ);
        final zs:Float = Math.sin(thetaZ);

		/**
        var a1:Float = a * zc - b * zs;
        a1 = a1 * yc - 0 * ys;
        a = a1;

        var b1:Float = a * zs + b * zc;
        b1 = b1 * xc - (0 * yc + a1 * ys) * xs;
        b = b1;

        var c1:Float = c * zc - d * zs;
        c1 = c1 * yc - 0 * ys;
        c = c1;

        var d1:Float = c * zs + d * zc;
        d1 = d1 * xc - (0 * yc + c1 * ys) * xs;
        d = d1;

        var tx1:Float = tx * zc - ty * zs;
        tx1 = tx1 * yc - 0 * ys;
        tx = tx1;

        var ty1:Float = tx * zs + ty * zc;
        ty1 = ty1 * xc - (0 * yc + tx1 * ys) * xs;
        ty = ty1;
		*/

		var a1:Float = (a * zc - b * zs) * yc - 0 * ys;
		b = (a * zs + b * zc) * xc - (0 * yc + a1 * ys) * xs;
		a = a1;

		var c1:Float = (c * zc - d * zs) * yc - 0 * ys;
		d = (c * zs + d * zc) * xc - (0 * yc + c1 * ys) * xs;
		c = c1;

		var tx1:Float = (tx * zc - ty * zs) * yc - 0 * ys;
		ty = (tx * zs + ty * zc) * xc - (0 * yc + tx1 * ys) * xs;
		tx = tx1;

        return this;
    }

	/**
	 * Adds 180 degrees to rotation of this matrix
	 * @return	rotated matrix
	 */
	public inline function rotateBy180():FlxMatrix
	{
		this.setTo(-a, -b, -c, -d, -tx, -ty);
		return this;
	}

	/**
	 * Adds 90 degrees to rotation of this matrix
	 * @return	rotated matrix
	 */
	public inline function rotateByPositive90():FlxMatrix
	{
		this.setTo(-b, a, -d, c, -ty, tx);
		return this;
	}

	/**
	 * Subtract 90 degrees from rotation of this matrix
	 * @return	rotated matrix
	 */
	public inline function rotateByNegative90():FlxMatrix
	{
		this.setTo(b, -a, d, -c, ty, -tx);
		return this;
	}

	/**
	 * Transforms x coordinate of the point.
	 * Took original code from openfl.geom.Matrix (which isn't available on flash target).
	 *
	 * @param	px	x coordinate of the point
	 * @param	py	y coordinate of the point
	 * @return	transformed x coordinate of the point
	 *
	 * @since 4.3.0
	 */
	public inline function transformX(px:Float, py:Float):Float
	{
		return px * a + py * c + tx;
	}

	/**
	 * Transforms y coordinate of the point.
	 * Took original code from openfl.geom.Matrix (which isn't available on flash target).
	 *
	 * @param	px	x coordinate of the point
	 * @param	py	y coordinate of the point
	 * @return	transformed y coordinate of the point
	 *
	 * @since 4.3.0
	 */
	public inline function transformY(px:Float, py:Float):Float
	{
		return px * b + py * d + ty;
	}

	#if (nme && !flash)
	public function copyFrom(sourceMatrix:Matrix):Void
	{
		a = sourceMatrix.a;
		b = sourceMatrix.b;
		c = sourceMatrix.c;
		d = sourceMatrix.d;
		tx = sourceMatrix.tx;
		ty = sourceMatrix.ty;
	}
	#end
}