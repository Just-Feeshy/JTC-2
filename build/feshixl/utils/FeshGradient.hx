package feshixl.utils;

import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.display.BitmapData;
import openfl.display.Shape;
import openfl.display.InterpolationMethod;
import openfl.display.GradientType;
import openfl.display.SpreadMethod;
import flixel.util.FlxColor;
import flixel.FlxSprite;

class FeshGradient {
    public static function createGradient(width:Int, height:Int, colors:Array<FlxColor>):GradientMatrix {
		var gradientMatrix = new Matrix();

		gradientMatrix.createGradientBox(width, height, 1.57079632679, 0, 0);

		var alpha:Array<Float> = [];
		for(i in 0...colors.length) {
			alpha.push(colors[i].alphaFloat);
		}

		var ratio:Array<Int> = [];

		if(colors.length == 2) {
		    ratio[0] = 0;
			ratio[1] = 255;
		} else {
		    var spread:Int = Std.int(255 / (colors.length - 1));
			ratio.push(0);

			for(i in 1...colors.length - 1) {
				ratio.push(spread * i);
			}

			ratio.push(255);
		}

		return {
			matrix:gradientMatrix,
			alpha:alpha,
			ratio:ratio
		};
	}

	public static function createGradientBitmapData(width:UInt, height:UInt, colors:Array<FlxColor>, interpolate:Bool = true):BitmapData {
		if(width < 1) {
			width = 1;
		}

		if(height < 1) {
			height = 1;
		}

		var gradient = createGradient(width, height, colors);
		var shape = new Shape();
		var interpolationMethod = interpolate ? InterpolationMethod.RGB : InterpolationMethod.LINEAR_RGB;

		#if flash
		var colors = colors.map(function(c):UInt return c);
		#end

		shape.graphics.beginGradientFill(GradientType.LINEAR, colors, gradient.alpha, gradient.ratio, gradient.matrix, SpreadMethod.PAD, interpolationMethod, 0);
		shape.graphics.drawRect(0, 0, width, height);

		var data = new BitmapData(width, height, true, FlxColor.TRANSPARENT);
		data.draw(shape);

		return data;
	}

	public static function createGradientFlxSprite(width:Int, height:Int, colors:Array<FlxColor>, interpolate:Bool = true):FlxSprite {
		var sprite = new FlxSprite();
		sprite.makeGraphic(width, height, FlxColor.TRANSPARENT);
		sprite.pixels = createGradientBitmapData(width, height, colors, interpolate);
		return sprite;
	}
}

typedef GradientMatrix =
{
	matrix:Matrix,
	alpha:Array<Float>,
	ratio:Array<Int>
}
