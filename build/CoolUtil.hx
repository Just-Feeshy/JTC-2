package;

import lime.utils.Assets;
import flixel.util.FlxColor;
import openfl.display.BitmapData;
import sys.FileSystem;

using StringTools;

class CoolUtil
{
	public static var difficultyArray:Array<String> = ['EASY', "NORMAL", "HARD"];

	public static function difficultyString():String
	{
		return difficultyArray[PlayState.storyDifficulty];
	}

	public static function coolTextFile(path:String):Array<String>
	{
		var daList:Array<String> = Assets.getText(path).trim().split('\n');

		for (i in 0...daList.length)
		{
			daList[i] = daList[i].trim();
		}

		return daList;
	}

	public static function numberArray(max:Int, ?min = 0):Array<Int>
	{
		var dumbArray:Array<Int> = [];
		for (i in min...max)
		{
			dumbArray.push(i);
		}
		return dumbArray;
	}

	public static function calculateAverageColor(bitmap:BitmapData):FlxColor {
		var red:Float = 0;
		var green:Float = 0;
		var blue:Float = 0;
		var alpha:Float = 0;

		for (column in 0...bitmap.width) {
			for (row in 0...bitmap.height) {
				var color:FlxColor = bitmap.getPixel32(column, row);

				if((color.red > 25 || color.green > 25 || color.blue > 25) && color.alpha > 0) {
					red += color.redFloat * color.alpha;
					green += color.greenFloat * color.alpha;
					blue += color.blueFloat * color.alpha;
					alpha += color.alpha;
				}
			}
		}
		if (alpha == 0) {
			return 0xFF000000;
		} else {
			return FlxColor.fromRGBFloat(red / alpha, green / alpha, blue / alpha);
		}
    }

	//I hate this
	public static function getFileDirectory(folder:String, file:String):String {
		var files:Array<String> = FileSystem.readDirectory(folder);

		var index:Int = 0;

		while(index < files.length) {
			if(files[index].contains(file)) {
				return files[index];
			}

			index++;
		}

		return null;
	}
}