package;

import lime.utils.Assets;
import flixel.util.FlxColor;
import openfl.display.BitmapData;

#if sys
import sys.FileSystem;
#end

using StringTools;

class CoolUtil
{
	public static var difficultyArray(get, never):Array<String>;

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

	public static function readableSongDirectory(path:String):String {
		return path.replace(' ', '-');
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

	inline static function get_difficultyArray():Array<String>
	{
		if(Paths.modJSON == null) {
			return ["Easy", "Normal", "Hard"];
		}else {
			return Paths.modJSON.song_util.difficulties;
		}
	}

	#if sys
	/**
	* Based off of the `Locator` class in
	* https://github.com/Just-Feeshy/Study-Guide/blob/Recursion/Locator.java
	*
	* Recursion is pretty useful.
	*/
	public static function getFilesInDirectories(directory:String, ignoreFormats:Array<String> = null):Array<String> {
		var allFiles:Array<String> = [];

		if(directory.substring(directory.length - 1, directory.length) == "/") {
			directory = directory.substring(0, directory.length - 1);
		}

		if (FileSystem.exists(directory)) {
			if(ignoreFormats == null) {
				ignoreFormats = [];
			}

			var directories:Array<String> = FileSystem.readDirectory(directory);
			var index:Int = 0;

			if(directories == null) {
				return allFiles;
			}

			while(index < directories.length) {
				var pureDirectory:String = directory + "/" + directories[index];

				if(FileSystem.isDirectory(pureDirectory)) {
					allFiles = allFiles.concat(getFilesInDirectories(pureDirectory, ignoreFormats));
				}else if(!ignoreFormats.contains(pureDirectory.split(".")[1])) {
					allFiles.push(pureDirectory);
				}

				index++;
			}
		}

		return allFiles;
	}
	#end
}
