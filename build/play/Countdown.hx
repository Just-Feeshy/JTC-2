package play;

import Conductor;
import LuaUtils;
import Paths;
import PlayState;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.system.FlxSound;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxTimer;

@:access(PlayState)
class Countdown
{
	public static var countdownStep(default, null):CountdownStep = BEFORE;
	public static var soundSuffix:String = "";
	public static var graphicSuffix:String = "";

	static var countdownTimer:FlxTimer = null;
	static var countdownGraphicSprite:FlxSprite = null;
	static var countdownGraphicTween:FlxTween = null;

	public static function performCountdown():Bool
	{
		countdownStep = BEFORE;

		var cancelled:Bool = propagateCountdownEvent(countdownStep);
		if(cancelled)
		{
			return false;
		}

		stopCountdown();

		var playState:PlayState = PlayState.instance;
		if(playState == null)
		{
			return false;
		}

		playState.isInCountdown = true;
		Conductor.instance.update(playState.startTimestamp + Conductor.instance.beatLengthMs * -5);
		playState.syncMusicBeatState(Conductor.instance.trackedSongPosition);
		playState.updateLuaVars();
		playState.updatePerSectionLuaVars();
		if(playState.playLua != null && playState.playLua.hasScript())
		{
			playState.playLua.set("isInCountdown", true);
		}

		countdownTimer = new FlxTimer();
		playState.startTimer = countdownTimer;

		countdownTimer.start(Conductor.instance.beatLengthMs / 1000, function(tmr:FlxTimer)
		{
			var activePlayState:PlayState = PlayState.instance;
			if(activePlayState == null)
			{
				stopCountdown();
				return;
			}

			countdownStep = decrement(countdownStep);
			activePlayState.updateLuaVars();
			activePlayState.updatePerSectionLuaVars();

			showCountdownGraphic(countdownStep);
			playCountdownSound(countdownStep);

			var stepCancelled:Bool = propagateCountdownEvent(countdownStep);
			if(stepCancelled)
			{
				pauseCountdown();
			}

			if(countdownStep == AFTER)
			{
				stopCountdown();
			}
		}, 5);

		return true;
	}

	static function propagateCountdownEvent(index:CountdownStep):Bool
	{
		var playState:PlayState = PlayState.instance;
		if(playState == null || playState.playLua == null || !playState.playLua.hasScript())
		{
			return false;
		}

		syncCountdownLuaVars(index);

		var callbackName:String = switch(index)
		{
			case BEFORE: "onCountdownStart";
			case THREE | TWO | ONE | GO: "onCountdownStep";
			case AFTER: "onCountdownEnd";
		};

		var result:Dynamic = playState.playLua.call(callbackName, [stepToString(index), stepToInt(index)]);
		return isCallbackCancelled(result);
	}

	public static function pauseCountdown():Void
	{
		if(countdownTimer != null && !countdownTimer.finished)
		{
			countdownTimer.active = false;
		}

		if(countdownGraphicTween != null)
		{
			countdownGraphicTween.active = false;
		}
	}

	public static function resumeCountdown():Void
	{
		if(countdownTimer != null && !countdownTimer.finished)
		{
			countdownTimer.active = true;
		}

		if(countdownGraphicTween != null)
		{
			countdownGraphicTween.active = true;
		}
	}

	public static function stopCountdown():Void
	{
		if(countdownTimer != null)
		{
			countdownTimer.cancel();
			countdownTimer.destroy();
			countdownTimer = null;
		}

		var playState:PlayState = PlayState.instance;
		if(playState != null)
		{
			if(playState.startTimer != null)
			{
				playState.startTimer = null;
			}
		}
	}

	public static function skipCountdown():Void
	{
		stopCountdown();

		var playState:PlayState = PlayState.instance;
		if(playState == null)
		{
			return;
		}

		Conductor.instance.update(playState.startTimestamp);
		playState.syncMusicBeatState(Conductor.instance.trackedSongPosition);
		playState.updateLuaVars();
		playState.updatePerSectionLuaVars();
	}

	public static function resetCountdown():Void
	{
		if(countdownTimer != null)
		{
			countdownTimer.reset();
		}
	}

	public static function reset():Void
	{
		countdownStep = BEFORE;
		soundSuffix = "";
		graphicSuffix = "";
		countdownGraphicSprite = null;
		countdownGraphicTween = null;
	}

	public static function stepToString(step:CountdownStep):String
	{
		return switch(step)
		{
			case BEFORE: "BEFORE";
			case THREE: "THREE";
			case TWO: "TWO";
			case ONE: "ONE";
			case GO: "GO";
			case AFTER: "AFTER";
		};
	}

	public static function stepToInt(step:CountdownStep):Int
	{
		return switch(step)
		{
			case BEFORE: 0;
			case THREE: 1;
			case TWO: 2;
			case ONE: 3;
			case GO: 4;
			case AFTER: 5;
		};
	}

	static function syncCountdownLuaVars(step:CountdownStep):Void
	{
		var playState:PlayState = PlayState.instance;
		if(playState == null || playState.playLua == null || !playState.playLua.hasScript())
		{
			return;
		}

		playState.playLua.set("countdownStep", stepToString(step));
		playState.playLua.set("countdownStepInt", stepToInt(step));
		playState.playLua.set("isInCountdown", playState.isInCountdown);
	}

	static function isCallbackCancelled(result:Dynamic):Bool
	{
		if(result == null)
		{
			return false;
		}

		if(result == true)
		{
			return true;
		}

		return result == LuaUtils.Function_Stop || result == LuaUtils.Function_StopLua || result == LuaUtils.Function_StopAll;
	}

	public static function showCountdownGraphic(index:CountdownStep):Void
	{
		var playState:PlayState = PlayState.instance;
		if(playState == null || !playState.showCountdownSprites)
		{
			return;
		}

		var graphicPath:String = getGraphicPath(index);
		if(graphicPath == null)
		{
			return;
		}

		var countdownSprite:FlxSprite = new FlxSprite().loadGraphic(Paths.image(graphicPath));
		countdownSprite.scrollFactor.set();
		countdownSprite.cameras = [PlayState.camHUD];

		if(playState.isPixel)
		{
			countdownSprite.setGraphicSize(Std.int(countdownSprite.width * PlayState.daPixelZoom));
		}

		countdownSprite.updateHitbox();
		countdownSprite.screenCenter();
		playState.add(countdownSprite);
		countdownGraphicSprite = countdownSprite;

		var activeTween:FlxTween = null;
		activeTween = FlxTween.tween(countdownSprite, {y: countdownSprite.y + 100, alpha: 0}, Conductor.instance.beatLengthMs / 1000, {
			ease: FlxEase.cubeInOut,
			onComplete: function(_)
			{
				if(countdownGraphicSprite == countdownSprite)
				{
					countdownGraphicSprite = null;
				}

				if(countdownGraphicTween == activeTween)
				{
					countdownGraphicTween = null;
				}

				countdownSprite.destroy();
			}
		});
		countdownGraphicTween = activeTween;
	}

	public static function playCountdownSound(step:CountdownStep):FlxSound
	{
		var playState:PlayState = PlayState.instance;
		if(playState == null || !playState.playCountdownSounds)
		{
			return null;
		}

		var soundId:String = switch(step)
		{
			case BEFORE: "intro3";
			case THREE: "intro2";
			case TWO: "intro1";
			case ONE: "introGo";
			default: null;
		};

		if(soundId == null)
		{
			return null;
		}

		return FlxG.sound.play(Paths.sound(soundId + soundSuffix), 0.6);
	}

	static function getGraphicPath(step:CountdownStep):String
	{
		var playState:PlayState = PlayState.instance;
		if(playState == null)
		{
			return null;
		}

		var defaultGraphics:Array<String> = [
			"ready" + graphicSuffix,
			"set" + graphicSuffix,
			"go" + graphicSuffix
		];
		var pixelGraphics:Array<String> = [
			"weeb/pixelUI/ready-pixel",
			"weeb/pixelUI/set-pixel",
			"weeb/pixelUI/date-pixel"
		];
		var graphics:Array<String> = switch(PlayState.curStage)
		{
			case "school", "schoolEvil": pixelGraphics;
			default: defaultGraphics;
		};

		return switch(step)
		{
			case THREE: graphics[0];
			case TWO: graphics[1];
			case ONE: graphics[2];
			default: null;
		};
	}

	public static function decrement(step:CountdownStep):CountdownStep
	{
		switch(step)
		{
			case BEFORE:
				return THREE;
			case THREE:
				return TWO;
			case TWO:
				return ONE;
			case ONE:
				return GO;
			case GO:
				return AFTER;
			default:
				return AFTER;
		}
	}
}

enum CountdownStep
{
	BEFORE;
	THREE;
	TWO;
	ONE;
	GO;
	AFTER;
}
