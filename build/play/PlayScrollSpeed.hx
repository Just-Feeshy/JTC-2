package play;

import flixel.util.FlxDestroyUtil.IFlxDestroyable;

typedef ScrollSpeedSegment =
{
	var startTime:Float;
	var endTime:Float;
	var startMultiplier:Float;
	var endMultiplier:Float;
}

class PlayScrollSpeed implements IFlxDestroyable
{
	public static var active:PlayScrollSpeed;

	private var segments:Array<ScrollSpeedSegment> = [];
	private var defaultMultiplier:Float = 1;

	public function new(?defaultMultiplier:Float = 1)
	{
		reset(defaultMultiplier);
	}

	public function reset(?multiplier:Float = 1):Void
	{
		defaultMultiplier = multiplier;
		segments = [];
		Note.AFFECTED_SCROLLSPEED = multiplier;
	}

	public function snapTo(multiplier:Float, currentSongTime:Float):Void
	{
		tweenTo(multiplier, currentSongTime, 0);
	}

	public function tweenTo(multiplier:Float, currentSongTime:Float, durationSeconds:Float):Void
	{
		var safeSongTime:Float = currentSongTime;
		var startMultiplier:Float = getMultiplierAt(safeSongTime);
		var durationMs:Float = Math.max(0, durationSeconds * 1000);

		cancelFutureSegments(safeSongTime);

		if(durationMs <= 0)
		{
			segments.push({
				startTime: safeSongTime,
				endTime: safeSongTime,
				startMultiplier: startMultiplier,
				endMultiplier: multiplier
			});
		}
		else
		{
			segments.push({
				startTime: safeSongTime,
				endTime: safeSongTime + durationMs,
				startMultiplier: startMultiplier,
				endMultiplier: multiplier
			});
		}

		Note.AFFECTED_SCROLLSPEED = multiplier;
	}

	public function getMultiplierAt(songTime:Float):Float
	{
		if(songTime < 0)
		{
			return defaultMultiplier;
		}

		var currentMultiplier:Float = defaultMultiplier;

		for(segment in segments)
		{
			if(songTime < segment.startTime)
			{
				return currentMultiplier;
			}

			if(songTime <= segment.endTime)
			{
				return resolveSegmentMultiplier(segment, songTime);
			}

			currentMultiplier = segment.endMultiplier;
		}

		return currentMultiplier;
	}

	public function getIntegratedMultiplier(songTime:Float):Float
	{
		if(songTime <= 0)
		{
			return songTime * defaultMultiplier;
		}

		var total:Float = 0;
		var lastTime:Float = 0;
		var currentMultiplier:Float = defaultMultiplier;

		for(segment in segments)
		{
			if(songTime <= segment.startTime)
			{
				total += (songTime - lastTime) * currentMultiplier;
				return total;
			}

			total += (segment.startTime - lastTime) * currentMultiplier;

			if(songTime <= segment.endTime)
			{
				total += integrateSegment(segment, songTime);
				return total;
			}

			total += integrateSegment(segment, segment.endTime);
			currentMultiplier = segment.endMultiplier;
			lastTime = segment.endTime;
		}

		total += (songTime - lastTime) * currentMultiplier;
		return total;
	}

	public static function getVisualSongDelta(fromSongTime:Float, toSongTime:Float):Float
	{
		if(active == null)
		{
			return (toSongTime - fromSongTime) * Note.AFFECTED_SCROLLSPEED;
		}

		return active.getIntegratedMultiplier(toSongTime) - active.getIntegratedMultiplier(fromSongTime);
	}

	public function destroy():Void
	{
		segments = null;

		if(active == this)
		{
			active = null;
		}
	}

	private function cancelFutureSegments(currentSongTime:Float):Void
	{
		if(segments == null || segments.length == 0)
		{
			return;
		}

		var currentMultiplier:Float = getMultiplierAt(currentSongTime);
		var retained:Array<ScrollSpeedSegment> = [];

		for(segment in segments)
		{
			if(segment.endTime <= currentSongTime)
			{
				retained.push(segment);
			}
			else if(segment.startTime < currentSongTime)
			{
				retained.push({
					startTime: segment.startTime,
					endTime: currentSongTime,
					startMultiplier: segment.startMultiplier,
					endMultiplier: currentMultiplier
				});
			}
		}

		segments = retained;
	}

	private function resolveSegmentMultiplier(segment:ScrollSpeedSegment, songTime:Float):Float
	{
		var duration:Float = segment.endTime - segment.startTime;

		if(duration <= 0)
		{
			return segment.endMultiplier;
		}

		var elapsed:Float = songTime - segment.startTime;
		var progress:Float = elapsed / duration;
		return segment.startMultiplier + ((segment.endMultiplier - segment.startMultiplier) * progress);
	}

	private function integrateSegment(segment:ScrollSpeedSegment, songTime:Float):Float
	{
		var duration:Float = segment.endTime - segment.startTime;
		var elapsed:Float = songTime - segment.startTime;

		if(duration <= 0 || elapsed <= 0)
		{
			return 0;
		}

		var slope:Float = (segment.endMultiplier - segment.startMultiplier) / duration;
		return (segment.startMultiplier * elapsed) + (slope * elapsed * elapsed * 0.5);
	}
}
