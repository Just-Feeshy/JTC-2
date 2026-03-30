package;

import Song.SwagSong;

class SongDataUtils
{
	public static function sortTimeChanges(songTimeChanges:Array<SongTimeChange>):Void
	{
		if (songTimeChanges == null) return;

		songTimeChanges.sort(function(a:SongTimeChange, b:SongTimeChange):Int
		{
			if (a.timeStamp < b.timeStamp) return -1;
			if (a.timeStamp > b.timeStamp) return 1;
			return 0;
		});
	}

	public static function buildTimeChangesFromSong(song:SwagSong):Array<SongTimeChange>
	{
		var result:Array<SongTimeChange> = [];

		if (song == null)
		{
			result.push(new SongTimeChange(0, Constants.DEFAULT_BPM));
			return result;
		}

		var curBPM:Int = song.bpm;
		var totalPos:Float = 0.0;

		result.push(new SongTimeChange(0, curBPM));

		for (section in song.notes)
		{
			if (section.changeBPM && section.bpm != curBPM)
			{
				curBPM = section.bpm;
				result.push(new SongTimeChange(totalPos, curBPM));
			}

			totalPos += (((Constants.SECS_PER_MIN / curBPM) * Constants.MS_PER_SEC) / Constants.STEPS_PER_BEAT) * section.lengthInSteps;
		}

		return result;
	}
}
