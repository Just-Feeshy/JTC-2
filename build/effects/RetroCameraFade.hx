package effects;

import flixel.FlxCamera;
import flixel.util.FlxColor;

class RetroCameraFade
{
	public static function fadeBlack(camera:FlxCamera, _:Float, duration:Float):Void
	{
		if(camera != null) {
			camera.fade(FlxColor.BLACK, duration, false);
		}
	}

	public static function fadeToBlack(camera:FlxCamera, _:Float, duration:Float):Void
	{
		if(camera != null) {
			camera.fade(FlxColor.BLACK, duration, false);
		}
	}
}
