package play;

import flixel.math.FlxPoint;

class CameraFocusPositioner
{
	public static function getOpponentFocus(playState:PlayState, ?out:FlxPoint):FlxPoint
	{
		return getCharacterFocus(playState != null ? playState.dad : null, "dad", PlayState.curStage, out);
	}

	public static function getPlayerFocus(playState:PlayState, ?out:FlxPoint):FlxPoint
	{
		return getCharacterFocus(playState != null ? playState.boyfriend : null, "boyfriend", PlayState.curStage, out);
	}

	public static function getFocusForSection(playState:PlayState, mustHitSection:Bool, ?out:FlxPoint):FlxPoint
	{
		return mustHitSection ? getPlayerFocus(playState, out) : getOpponentFocus(playState, out);
	}

	public static function getCharacterFocus(character:Character, role:String, stage:String, ?out:FlxPoint):FlxPoint
	{
		var point:FlxPoint = out != null ? out : FlxPoint.get();

		if(character == null) {
			point.set(0, 0);
			return point;
		}

		var basePoint:FlxPoint = character.cameraFocusPoint;
		point.set(basePoint.x, basePoint.y);

		switch(role) {
			case "dad" | "opponent":
				applyOpponentOffset(character, point);
			case "boyfriend" | "bf" | "player":
				applyPlayerOffset(stage, point);
			case "gf" | "girlfriend":
		}

		return point;
	}

	private static function applyOpponentOffset(character:Character, point:FlxPoint):Void
	{
		switch(character.curCharacter) {
			case "mom":
			case "senpai" | "senpai-angry":
				point.x -= 100;
				point.y -= 430;
			default:
				point.x += 150;
				point.y -= 100;
		}
	}

	private static function applyPlayerOffset(stage:String, point:FlxPoint):Void
	{
		switch(stage) {
			case "limo":
				point.x -= 300;
				point.y -= 100;
			case "mall":
				point.x -= 100;
				point.y -= 200;
			case "school" | "schoolEvil":
				point.x -= 200;
				point.y -= 200;
			default:
				point.x -= 100;
				point.y -= 100;
		}
	}
}
