package;

import flixel.FlxG;

class Highscore {
	#if (haxe >= "4.0.0")
	public static var songScores:Map<String, Int> = new Map();
	#else
	public static var songScores:Map<String, Int> = new Map<String, Int>();
	#end


	public static function saveScore(song:String, score:Int = 0, ?diff:Int = 0):Void {
		var daSong:String = formatSong(song, diff);

		if (songScores.exists(daSong)) {
			if (songScores.get(daSong) < score) {
				setScore(daSong, score);
			}
		}
		else {
			setScore(daSong, score);
		}
	}

	public static function saveWeekScore(week:Int = 1, score:Int = 0, ?diff:Int = 0):Void {
		var daWeek:String = formatSong('week' + week, diff);

		if (songScores.exists(daWeek))
		{
			if (songScores.get(daWeek) < score)
				setScore(daWeek, score);
		}
		else
			setScore(daWeek, score);
	}

	/**
	 * YOU SHOULD FORMAT SONG WITH formatSong() BEFORE TOSSING IN SONG VARIABLE
	 */
	static function setScore(song:String, score:Int):Void {
		// Reminder that I don't need to format this song, it should come formatted!
		songScores.set(song, score);
		FlxG.save.data.songScores = songScores;
		FlxG.save.flush();
	}

	public static function formatSong(song:String, diff:Int):String {
		var daDif:String = "-" + CoolUtil.difficultyArray[diff].toLowerCase();

		if(CoolUtil.difficultyArray[diff].toLowerCase() == "normal") {
			daDif = "";
		}

		return song.toLowerCase() + daDif;
	}

	public static function getScore(song:String, diff:Int):Int {
		var getSong:String = formatSong(song, diff);

		trace(songScores.get(getSong) + " " + getSong);

		if (!songScores.exists(getSong))
			setScore(getSong, 0);

		return songScores.get(getSong);
	}

	public static function getWeekScore(week:Int, diff:Int):Int {
		if (!songScores.exists(formatSong('week' + week, diff)))
			setScore(formatSong('week' + week, diff), 0);

		return songScores.get(formatSong('week' + week, diff));
	}

	public static function load():Void {
		if (FlxG.save.data.songScores != null)
		{
			songScores = FlxG.save.data.songScores;
		}
	}
}
