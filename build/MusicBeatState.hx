package;

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
	{
		return Conductor.instance.trackedSongPosition;
	}

	override function onCreate():Dynamic {
		#if (USING_LUA && cpp)
		var stateLua = getModLua();
		if(stateLua != null) {
			stateLua.set("curStep", curStep);
			stateLua.set("curBeat", curBeat);
		}
		#end

		return super.onCreate();
	}

	override function update(elapsed:Float)
	{
		var oldStep:Int = curStep;

		updateCurStep();
		updateBeat();

		if (oldStep != curStep)
			stepHit();

		super.update(elapsed);
	}

	public function syncMusicBeatState(?songTime:Null<Float>):Void {
		var sourceSongTime:Float = songTime != null ? songTime : songPos;

		if(songTime != null && Math.abs(sourceSongTime - Conductor.instance.trackedSongPosition) > 0.001) {
			var stepTime:Float = Conductor.instance.getTimeInSteps(sourceSongTime);
			curStep = Math.floor(stepTime);
			curBeat = Math.floor(stepTime * 0.25);
		} else {
			curStep = Conductor.instance.currentStep;
			curBeat = Conductor.instance.currentBeat;
		}

		lastStep = curStep;
		lastBeat = curBeat;

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).set("curStep", curStep);
			HelperStates.getLua(Type.getClass(this)).set("curBeat", curBeat);
		}
		#end
	}

	public function clickedOnSprite(clickSprite:FlxSprite, spriteDiameter:Float):Bool {

		if(FlxG.mouse.justPressed) {
			if(Math.sqrt(Math.pow(clickSprite.getMidpoint().x - FlxG.mouse.x, 2) + Math.pow(clickSprite.getMidpoint().y - FlxG.mouse.y, 2)) < spriteDiameter)
				return true;
		}

		return false;
    }

	private function updateBeat():Void {
		curBeat = Conductor.instance.currentBeat;

		#if (USING_LUA && cpp)
		var stateLua = getModLua();
		if(stateLua != null)
			stateLua.call("updateBeat", []);
		#end
	}

	private function updateCurStep():Void {
		curStep = Conductor.instance.currentStep;

		#if (USING_LUA && cpp)
		var stateLua = getModLua();
		if(stateLua != null)
			stateLua.call("updateCurStep", []);
		#end
	}

	public function stepHit():Void {
		curStep = Conductor.instance.currentStep;
		curBeat = Conductor.instance.currentBeat;

		#if (USING_LUA && cpp)
		var stateLua = getModLua();
		if(stateLua != null) {
			stateLua.set("curStep", curStep);
			stateLua.set("curBeat", curBeat);

			if(Std.isOfType(this, PlayState)) {
				var playState:PlayState = cast this;
				playState.updateLuaVars();
				playState.updatePerSectionLuaVars();
			}

			stateLua.call("onStepHit", []);
		}
		#end

		if (curStep % 4 == 0)
			beatHit();
	}

	public function beatHit():Void {
		curStep = Conductor.instance.currentStep;
		curBeat = Conductor.instance.currentBeat;

		#if (USING_LUA && cpp)
		var stateLua = getModLua();
		if(stateLua != null) {
			stateLua.set("curStep", curStep);
			stateLua.set("curBeat", curBeat);

			if(Std.isOfType(this, PlayState)) {
				var playState:PlayState = cast this;
				playState.updateLuaVars();
				playState.updatePerSectionLuaVars();
			}

			stateLua.call("onBeatHit", []);
		}
		#end
	}
}
