package;

import flixel.FlxG;
import flixel.FlxSubState;
import play.PlayScriptEvent;
import play.PlayScriptEventDispatcher;

class MusicBeatSubstate extends FlxSubState
{
	public function new()
	{
		super();
	}

	private var lastBeat:Float = 0;
	private var lastStep:Float = 0;

	private var curStep:Int = 0;
	private var curBeat:Int = 0;
	private var controls(get, never):Controls;

	private var songPos(get, never):Float;

	function get_songPos():Float
		return Conductor.instance.trackedSongPosition;

	inline function get_controls():Controls
		return PlayerSettings.player1.controls;

	override function update(elapsed:Float)
	{
		//everyStep();
		var oldStep:Int = curStep;

		updateCurStep();
		curBeat = Math.floor(curStep / 4);

		if (oldStep != curStep && curStep > 0)
			stepHit();

		super.update(elapsed);
	}

	private function updateCurStep():Void
	{
		curStep = Math.floor(Conductor.instance.getTimeInSteps(songPos));
	}

	public function stepHit():Void
	{
		if (curStep % 4 == 0)
			beatHit();
	}

	public function beatHit():Void
	{
		//do literally nothing dumbass
	}

	public function dispatchEvent(event:PlayScriptEvent):Void
	{
		PlayScriptEventDispatcher.callEvent(this, event);
	}
}
