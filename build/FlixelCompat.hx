package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.util.FlxAxes;
import openfl.filters.BitmapFilter;

class FlixelCompat
{
	public static function getScreenCenter(object:FlxObject, axes:FlxAxes):Float
	{
		if (object == null)
			return 0;

		if (axes != FlxAxes.Y)
		{
			return (FlxG.width / 2) - (object.width / 2);
		}
		else if (axes != FlxAxes.X)
		{
			return (FlxG.height / 2) - (object.height / 2);
		}

		return 0;
	}

	public static function setDefaultCameras(cameras:Array<FlxCamera>):Void
	{
		@:privateAccess FlxCamera._defaultCameras = cameras;
	}

	public static function getCameraFilters(camera:FlxCamera):Array<BitmapFilter>
	{
		if (camera == null || camera.filters == null)
			return [];

		return camera.filters.concat([]);
	}

	public static function setCameraFilters(camera:FlxCamera, filters:Array<BitmapFilter>):Void
	{
		if (camera == null)
			return;

		var normalizedFilters:Array<BitmapFilter> = filters != null ? filters.concat([]) : [];
		camera.filters = normalizedFilters.length > 0 ? normalizedFilters : null;

		if (camera.flashSprite != null)
		{
			camera.flashSprite.filters = camera.filtersEnabled ? camera.filters : null;
			@:privateAccess camera.flashSprite.__setRenderDirty();
		}
	}

	public static function clearCameraFilters(camera:FlxCamera):Void
	{
		setCameraFilters(camera, []);
	}

	public static function getGameFilters():Array<BitmapFilter>
	{
		@:privateAccess
		var filters:Array<BitmapFilter> = FlxG.game._filters;

		return filters != null ? filters.concat([]) : [];
	}
}
