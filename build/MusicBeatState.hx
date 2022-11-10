package;

import Conductor.BPMChangeEvent;
import flixel.FlxG;
import flixel.addons.transition.FlxTransitionableState;
import flixel.addons.ui.FlxUIState;
import flixel.math.FlxRect;
import flixel.util.FlxTimer;
import flixel.FlxSprite;

class MusicBeatState extends HelperStates
{
	private var lastBeat:Float = 0;
	private var lastStep:Float = 0;

	private var curStep:Int = 0;
	private var curBeat:Int = 0;

	private var songPos(get, never):Float;

	function get_songPos():Float
		return Conductor.songPosition;

	override function create() {
		super.create();
	}

	override function onCreate():Dynamic {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).set("curStep", curStep);
		}

		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).set("curBeat", curBeat);
		}
		#end

		return super.onCreate();
	}

	override function update(elapsed:Float)
	{
		var oldStep:Int = curStep;

		updateCurStep();
		updateBeat();

		if (oldStep != curStep && curStep > 0)
			stepHit();

		super.update(elapsed);
	}

	public function clickedOnSprite(clickSprite:FlxSprite, spriteDiameter:Float):Bool {

		if(FlxG.mouse.justPressed) {
			if(Math.sqrt(Math.pow(clickSprite.getMidpoint().x - FlxG.mouse.x, 2) + Math.pow(clickSprite.getMidpoint().y - FlxG.mouse.y, 2)) < spriteDiameter)
				return true;
		}

		return false;
    }

	private function updateBeat():Void {
		curBeat = Math.floor(curStep * 0.25);

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this)))
			HelperStates.getLua(Type.getClass(this)).call("updateBeat", []);
		#end
	}

	private function updateCurStep():Void {
		var lastChange:BPMChangeEvent = {
			stepTime: 0,
			songTime: 0,
			bpm: 0
		}
		for (i in 0...Conductor.bpmChangeMap.length)
		{
			if (songPos >= Conductor.bpmChangeMap[i].songTime)
				lastChange = Conductor.bpmChangeMap[i];
		}

		curStep = lastChange.stepTime + Math.floor((songPos - lastChange.songTime) / Conductor.stepCrochet);

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this)))
			HelperStates.getLua(Type.getClass(this)).call("updateCurStep", []);
		#end
	}

	public function stepHit():Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).call("onStepHit", []);
			HelperStates.getLua(Type.getClass(this)).set("curStep", curStep);
		}
		#end

		if (curStep % 4 == 0)
			beatHit();
	}

	public function beatHit():Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).call("onBeatHit", []);
			HelperStates.getLua(Type.getClass(this)).set("curBeat", curBeat);
		}
		#end
	}
}