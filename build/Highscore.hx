package;

import flixel.FlxG;

class Highscore {

	//No point?
	public static var songScores:Map<String, Int> = new Map<String, Int>();
	public static var weekScores:Map<String, Int> = new Map<String, Int>();

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

	public static function saveWeekScore(week:String, score:Int = 0, ?diff:Int = 0):Void {
		var daWeek:String = formatSong(week + "_" + Paths.modJSON.mod.name, diff);

		if (weekScores.exists(daWeek)) {
			if (weekScores.get(daWeek) < score)
				setWeekScore(daWeek, score);
		}
		else {
			setWeekScore(daWeek, score);
		}

		trace(daWeek);
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

	static function setWeekScore(week:String, score:Int):Void {
		// Reminder that I don't need to format this song, it should come formatted!
		weekScores.set(week, score);
		FlxG.save.data.weekScores = weekScores;
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

		if (!songScores.exists(getSong))
			setScore(getSong, 0);

		return songScores.get(getSong);
	}

	public static function getWeekScore(week:String, diff:Int):Int {
		var daWeek:String = formatSong(week + "_" + Paths.modJSON.mod.name, diff);

		if (!weekScores.exists(daWeek))
			setWeekScore(daWeek, 0);

		return weekScores.get(daWeek);
	}

	public static function load():Void {
		if (FlxG.save.data.weekScores != null) {
			weekScores = FlxG.save.data.weekScores;
		}

		if (FlxG.save.data.songScores != null) {
			songScores = FlxG.save.data.songScores;
		}
	}
}