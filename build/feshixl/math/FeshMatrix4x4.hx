package feshixl.math;

import flixel.math.FlxMath;
import flixel.math.FlxMatrix;
import openfl.geom.Matrix;
import openfl.Vector;

/**
* Most of it copied from heaps.io
* https://github.com/HeapsIO/heaps/blob/master/h3d/Matrix.hx
*/
class FeshMatrix4x4 extends FlxMatrix {
    /**
	* All variables of 16 numbers, where every four elements is a column of a 4x4 matrix.
	*/
    public var _11(get, set):Float;
	public var _12(get, set):Float;
	public var _13:Float;
	public var _14:Float;
	public var _21(get, set):Float;
	public var _22(get, set):Float;
	public var _23:Float;
	public var _24:Float;
	public var _31:Float;
	public var _32:Float;
	public var _33:Float;
	public var _34:Float;
	public var _41(get, set):Float;
	public var _42(get, set):Float;
	public var _43:Float;
	public var _44:Float;

    public function new() {
        initIdentity();
        super();
    }

    public function initScale(scaleX:Float = 0, scaleY:Float = 0, scaleZ:Float = 1) {
		_11 = scaleX; _12 = 0.0; _13 = 0.0; _14 = 0.0;
		_21 = 0.0; _22 = scaleY; _23 = 0.0; _24 = 0.0;
		_31 = 0.0; _32 = 0.0; _33 = scaleZ; _34 = 0.0;
		_41 = 0.0; _42 = 0.0; _43 = 0.0; _44 = 1.0;
	}

    public function initIdentity() {
		_11 = 1.0; _12 = 0.0; _13 = 0.0; _14 = 0.0;
		_21 = 0.0; _22 = 1.0; _23 = 0.0; _24 = 0.0;
		_31 = 0.0; _32 = 0.0; _33 = 1.0; _34 = 0.0;
		_41 = 0.0; _42 = 0.0; _43 = 0.0; _44 = 1.0;
	}

    public function scale4x3(scaleX:Float, scaleY:Float, scaleZ:Float = 1) {
        var temp:FeshMatrix4x4 = new FeshMatrix4x4();
        temp.initScale(scaleX, scaleY, scaleZ);
        multiplyBy(temp);
    }

    public function translate4x3(x:Float, y:Float, z:Float = 0) {
		_11 += x * _14;
		_12 += y * _14;
		_13 += z * _14;

		_21 += x * _24;
		_22 += y * _24;
		_23 += z * _24;

		_31 += x * _34;
		_32 += y * _34;
		_33 += z * _34;

		_41 += x * _44;
		_42 += y * _44;
		_43 += z * _44;
	}


    public function multiplyBy(b:FeshMatrix4x4):Void {
        var a11 = this._11; var a12 = this._12; var a13 = this._13; var a14 = this._14;
		var a21 = this._21; var a22 = this._22; var a23 = this._23; var a24 = this._24;
		var a31 = this._31; var a32 = this._32; var a33 = this._33; var a34 = this._34;
		var a41 = this._41; var a42 = this._42; var a43 = this._43; var a44 = this._44;
		var b11 = b._11; var b12 = b._12; var b13 = b._13; var b14 = b._14;
		var b21 = b._21; var b22 = b._22; var b23 = b._23; var b24 = b._24;
		var b31 = b._31; var b32 = b._32; var b33 = b._33; var b34 = b._34;
		var b41 = b._41; var b42 = b._42; var b43 = b._43; var b44 = b._44;

		_11 = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
		_12 = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
		_13 = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
		_14 = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

		_21 = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
		_22 = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
		_23 = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
		_24 = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

		_31 = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
		_32 = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
		_33 = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
		_34 = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

		_41 = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
		_42 = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
		_43 = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
		_44 = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;
    }

    public function multiplyValues(v:Float):Void {
		_11 *= v;
		_12 *= v;
		_13 *= v;
		_14 *= v;

		_21 *= v;
		_22 *= v;
		_23 *= v;
		_24 *= v;

		_31 *= v;
		_32 *= v;
		_33 *= v;
		_34 *= v;

		_41 *= v;
		_42 *= v;
		_43 *= v;
		_44 *= v;
	}

    public function invert4x4(m:FeshMatrix4x4):FeshMatrix4x4 {
		var m11 = m._11; var m12 = m._12; var m13 = m._13; var m14 = m._14;
		var m21 = m._21; var m22 = m._22; var m23 = m._23; var m24 = m._24;
		var m31 = m._31; var m32 = m._32; var m33 = m._33; var m34 = m._34;
		var m41 = m._41; var m42 = m._42; var m43 = m._43; var m44 = m._44;

		_11 = m22 * m33 * m44 - m22 * m34 * m43 - m32 * m23 * m44 + m32 * m24 * m43 + m42 * m23 * m34 - m42 * m24 * m33;
		_12 = -m12 * m33 * m44 + m12 * m34 * m43 + m32 * m13 * m44 - m32 * m14 * m43 - m42 * m13 * m34 + m42 * m14 * m33;
		_13 = m12 * m23 * m44 - m12 * m24 * m43 - m22 * m13 * m44 + m22 * m14 * m43 + m42 * m13 * m24 - m42 * m14 * m23;
		_14 = -m12 * m23 * m34 + m12 * m24 * m33 + m22 * m13 * m34 - m22 * m14 * m33 - m32 * m13 * m24 + m32 * m14 * m23;

		_21 = -m21 * m33 * m44 + m21 * m34 * m43 + m31 * m23 * m44 - m31 * m24 * m43 - m41 * m23 * m34 + m41 * m24 * m33;
		_22 = m11 * m33 * m44 - m11 * m34 * m43 - m31 * m13 * m44 + m31 * m14 * m43 + m41 * m13 * m34 - m41 * m14 * m33;
		_23 = -m11 * m23 * m44 + m11 * m24 * m43 + m21 * m13 * m44 - m21 * m14 * m43 - m41 * m13 * m24 + m41 * m14 * m23;
		_24 =  m11 * m23 * m34 - m11 * m24 * m33 - m21 * m13 * m34 + m21 * m14 * m33 + m31 * m13 * m24 - m31 * m14 * m23;

		_31 = m21 * m32 * m44 - m21 * m34 * m42 - m31 * m22 * m44 + m31 * m24 * m42 + m41 * m22 * m34 - m41 * m24 * m32;
		_32 = -m11 * m32 * m44 + m11 * m34 * m42 + m31 * m12 * m44 - m31 * m14 * m42 - m41 * m12 * m34 + m41 * m14 * m32;
		_33 = m11 * m22 * m44 - m11 * m24 * m42 - m21 * m12 * m44 + m21 * m14 * m42 + m41 * m12 * m24 - m41 * m14 * m22;
		_34 =  -m11 * m22 * m34 + m11 * m24 * m32 + m21 * m12 * m34 - m21 * m14 * m32 - m31 * m12 * m24 + m31 * m14 * m22;

		_41 = -m21 * m32 * m43 + m21 * m33 * m42 + m31 * m22 * m43 - m31 * m23 * m42 - m41 * m22 * m33 + m41 * m23 * m32;
		_42 = m11 * m32 * m43 - m11 * m33 * m42 - m31 * m12 * m43 + m31 * m13 * m42 + m41 * m12 * m33 - m41 * m13 * m32;
		_43 = -m11 * m22 * m43 + m11 * m23 * m42 + m21 * m12 * m43 - m21 * m13 * m42 - m41 * m12 * m23 + m41 * m13 * m22;
		_44 = m11 * m22 * m33 - m11 * m23 * m32 - m21 * m12 * m33 + m21 * m13 * m32 + m31 * m12 * m23 - m31 * m13 * m22;

        var det = m11 * _11 + m12 * _21 + m13 * _31 + m14 * _41;

        if(Math.abs(det) > FlxMath.EPSILON) {
            det = 1.0 / det;
        }else {
            det = 0;
        }

        multiplyValues(det);
        return this;
	}

    function get__11():Float {
        return a;
    }

    function set__11(v:Float):Float {
        return a = v;
    }

    function get__21():Float {
        return b;
    }

    function set__21(v:Float):Float {
        return b = v;
    }

    function get__12():Float {
        return c;
    }

    function set__12(v:Float):Float {
        return c = v;
    }

    function get__22():Float {
        return d;
    }

    function set__22(v:Float):Float {
        return d = v;
    }

    function get__41():Float {
        return tx;
    }

    function set__41(v:Float):Float {
        return tx = v;
    }

    function get__42():Float {
        return ty;
    }

    function set__42(v:Float):Float {
        return ty = v;
    }
}