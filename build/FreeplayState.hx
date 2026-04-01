package;

#if windows
import Discord.DiscordClient;
#end

import Song.SwagSong;
import flash.text.TextField;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.system.FlxAssets.FlxShader;
import flixel.addons.display.FlxGridOverlay;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxMath;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilter;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.ShaderFilter;
import feshixl.math.FeshMath;
import lime.utils.Assets;
import haxe.Json;

import ModInitialize;

using StringTools;

private class StupidVibeShader extends FlxShader {

    @:glFragmentSource('
        #pragma header

        uniform float vibe;

		void main() {
			vec4 color = flixel_texture2D(bitmap, openfl_TextureCoordv);

			gl_FragColor = vec4((vec3(color.r+color.g+color.b)/3.0) * (1.0 - vibe) + color.rgb * vibe, color.a);
		}
    ')
    public function new(vibeMeter:Float) {
		super();

		vibe.value = [vibeMeter];
    }
}

class FreeplayState extends MusicBeatState
{
	private static var songCharacterCache:Map<String, String> = [];
	private var songs:Array<SongMetadata> = [];

	var selector:FlxText;

	private static var curSelected:Int = 0;
	private static var curDifficulty:Int = 1;

	var scoreText:FlxText;
	var diffText:FlxText;
	var lerpScore:Int = 0;
	var intendedScore:Int = 0;
	var grpSongs:FlxTypedGroup<Alphabet>;
	var curPlaying:Bool = false;

	var giveTick:Float = 0;
	private var iconArray:Array<HealthIcon> = [];

	private var menuBG:MenuBackground;
	private var backgroundBlur:Float = 0;

	var camFreeplay:FlxCamera;
	var camBackground:FlxCamera;

	#if (USING_LUA && cpp)
	private var hasGraffiti:Array<Bool> = [];
	private var luaReady:Bool = false;
	#end

	override function create()
	{
		#if windows
		// Updating Discord Rich Presence
		DiscordClient.changePresence("In the Menus", null);
		#end

		var isDebug:Bool = false;

		#if debug
		isDebug = true;
		#end

		var index:Int = 0;

		#if (USING_LUA && cpp)
		hasGraffiti = [];
		#end

		while(Paths.modJSON.weeks.get("week_" + index) != null) {
			for(v in 0...Paths.modJSON.weeks.get("week_" + index).week_data.length) {
				var songId:String = Paths.modJSON.weeks.get("week_" + index).week_data[v].toLowerCase();

				if(Paths.modJSON.weeks.get("week_" + index).week_unlocked)
					addSong(songId, index, resolveSongCharacter(songId));
			}

			index++;
		}

		Conductor.instance.trackedSongPosition = 0;
		Conductor.instance.trackedSongPosition -= Conductor.instance.beatLengthMs * 5;

		camFreeplay = new FlxCamera();
		camBackground = new FlxCamera();
		camFreeplay.bgColor.alpha = 0;
		camBackground.bgColor.alpha = 0;

        FlxG.cameras.reset(camBackground);
		FlxG.cameras.add(camFreeplay);

		backgroundBlur = Paths.modJSON.main_menu.background_blur != null ? Paths.modJSON.main_menu.background_blur : 0;

		FlxCamera.defaultCameras = [camFreeplay];

		var backgroundFilters:Array<BitmapFilter> = [new ShaderFilter(new StupidVibeShader(1.5))];
		if(backgroundBlur > 0) {
			backgroundFilters.unshift(new BlurFilter(backgroundBlur, backgroundBlur, BitmapFilterQuality.LOW));
		}
		camBackground.setFilters(backgroundFilters);

		// LOAD MUSIC

		// LOAD CHARACTERS

		menuBG = new MenuBackground(0, 0);
		menuBG.cameras = [camBackground];
		add(menuBG);

		var blackOverlay:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		blackOverlay.alpha = 0.2;
		blackOverlay.cameras = [camBackground];
		add(blackOverlay);

		grpSongs = new FlxTypedGroup<Alphabet>();
		grpSongs.cameras = [camFreeplay];
		add(grpSongs);

		for (i in 0...songs.length)
		{
			var songText:Alphabet = new Alphabet(0, (70 * i) + 30, songs[i].songName, true, false);
			songText.isMenuItem = true;
			songText.targetY = i;

			if(i != 0)
				songText.alpha = 0.6;

			grpSongs.add(songText);

			var iconCharacter:String = songs[i].songCharacter;

			var icon:HealthIcon = new HealthIcon(iconCharacter);
			icon.createAnim(iconCharacter, icon.getIconJSON(iconCharacter));
			icon.cameras = [camFreeplay];
			icon.sprTracker = songText;

			// using a FlxGroup is too much fuss!
			iconArray.push(icon);
			add(icon);

			#if (USING_LUA && cpp)
			if(HelperStates.luaExist(Type.getClass(this))) {
				modifiableSprites.set('freeplayIcon_' + i, icon);
				hasGraffiti.push(Paths.image('Graffiti/' + songs[i].songName.toLowerCase()) != null);
			}
			#end
		}

		scoreText = new FlxText(FlxG.width * 0.7, 5, 0, "", 32);
		// scoreText.autoSize = false;
		scoreText.setFormat(Paths.font("vcr.ttf"), 32, FlxColor.WHITE, RIGHT);
		scoreText.cameras = [camFreeplay];
		// scoreText.alignment = RIGHT;

		var scoreBG:FlxSprite = new FlxSprite(scoreText.x - 6, 0).makeGraphic(Std.int(FlxG.width * 0.35), 66, 0xFF000000);
		scoreBG.cameras = [camFreeplay];
		scoreBG.alpha = 0.6;
		add(scoreBG);

		diffText = new FlxText(scoreText.x, scoreText.y + 36, 0, "", 24);
		diffText.cameras = [camFreeplay];
		diffText.font = scoreText.font;
		add(diffText);

		add(scoreText);

		normalizeDifficulty();
		changeSelection();
		changeDiff();
		clearStuff();

		selector = new FlxText();

		selector.size = 40;
		selector.text = ">";
		// add(selector);

		var swag:Alphabet = new Alphabet(1, 0, "swag");

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			modifiableSprites.set("menuBG", menuBG);
			modifiableCameras.set("cameraBackground", camBackground);
			modifiableCameras.set("cameraFreeplay", camFreeplay);
			setLua("menuBackgroundBlur", backgroundBlur);
		}
		#end

		super.create();
	}

	inline function getDifficultyCount():Int
	{
		return CoolUtil.difficultyArray != null ? CoolUtil.difficultyArray.length : 0;
	}

	function normalizeDifficulty():Int
	{
		var difficultyCount:Int = getDifficultyCount();

		if (difficultyCount <= 0)
		{
			curDifficulty = 0;
			return 0;
		}

		if (curDifficulty < 0 || curDifficulty >= difficultyCount)
			curDifficulty = 0;

		return difficultyCount;
	}

	public function addSong(songName:String, weekNum:Int, songCharacter:String)
	{
		songs.push(new SongMetadata(songName, weekNum, songCharacter));
	}

	function resolveSongCharacter(songName:String):String
	{
		var normalizedSong:String = songName != null ? songName.toLowerCase().trim() : "";

		if(normalizedSong == "")
			return "dad";

		if(songCharacterCache.exists(normalizedSong))
			return songCharacterCache.get(normalizedSong);

		var resolvedCharacter:String = readSongCharacterFromMetadata(normalizedSong);

		if(resolvedCharacter == null || resolvedCharacter.trim() == "") {
			var chart:SwagSong = Song.loadFromJson(normalizedSong, normalizedSong, false);
			resolvedCharacter = chart != null && chart.player2 != null && chart.player2.trim() != "" ? chart.player2 : "dad";
		}

		songCharacterCache.set(normalizedSong, resolvedCharacter);
		return resolvedCharacter;
	}

	function readSongCharacterFromMetadata(songName:String):Null<String>
	{
		var metadataPath:String = Paths.getPath('data/' + songName + '/' + songName + '-metadata.json', TEXT, null);
		if(!Paths.assetExists(metadataPath, TEXT))
			return null;

		try {
			var metadata:Dynamic = Json.parse(Paths.readText(metadataPath));

			if(metadata != null) {
				var playData:Dynamic = Reflect.field(metadata, "playData");
				var characters:Dynamic = playData != null ? Reflect.field(playData, "characters") : null;
				var opponent:Dynamic = characters != null ? Reflect.field(characters, "opponent") : null;

				if(opponent != null) {
					var value:String = Std.string(opponent).trim();
					if(value != "")
						return value;
				}

				var legacyOpponent:Dynamic = Reflect.field(metadata, "player2");
				if(legacyOpponent != null) {
					var legacyValue:String = Std.string(legacyOpponent).trim();
					if(legacyValue != "")
						return legacyValue;
				}
			}
		}catch(e) {
			trace('Warning: could not parse metadata for Freeplay song "' + songName + '" -> ' + Std.string(e));
		}

		return null;
	}

	override function update(elapsed:Float) {
		super.update(elapsed);

		if (FlxG.sound.music != null)
			Conductor.instance.trackedSongPosition = FlxG.sound.music.length;

		if (FlxG.sound.music.volume < 0.7) {
			FlxG.sound.music.volume += 0.5 * FlxG.elapsed;
		}

		lerpScore = Math.floor(FlxMath.lerp(lerpScore, intendedScore, FeshMath.clamp(elapsed * 25, 0, 1)));
		scoreText.text = "PERSONAL BEST:" + lerpScore;

		var upP = controls.UP_P;
		var downP = controls.DOWN_P;
		var accepted = controls.ACCEPT;

		if (upP || FlxG.mouse.wheel > 0.1)
		{
			changeSelection(-1);
		}
		if (downP || FlxG.mouse.wheel < -0.1)
		{
			changeSelection(1);
		}

		var difficultyCount:Int = normalizeDifficulty();

		if (difficultyCount > 1)
		{
			if (controls.LEFT_P)
				changeDiff(-1);
			if (controls.RIGHT_P)
				changeDiff(1);
		}

		if (controls.BACK)
		{
			FlxG.switchState(new MainMenuState(true));
		}

		#if PRELOAD_ALL
		if(giveTick > 1 && !curPlaying) {
			FlxG.sound.playMusic(Paths.inst(songs[curSelected].songName), 0.7);
			curPlaying = true;
		}else if(giveTick <= 1)
			giveTick += elapsed;
		#end

		if (accepted || FlxG.mouse.justPressed)
		{
			var poop:String = Highscore.formatSong(songs[curSelected].songName.toLowerCase(), curDifficulty);

			//trace(poop);

			PlayState.SONG = Song.loadFromJson(poop, songs[curSelected].songName.toLowerCase());
			PlayState.isStoryMode = false;
			PlayState.storyDifficulty = curDifficulty;

			PlayState.storyWeek = songs[curSelected].week;
		    #if debug
			CacheState.loadAndSwitchState(new PlayState());
		    #else
			CacheState.loadAndSwitchStateF(new PlayState());
		    #end
		}
	}

	override function stepHit() {
		super.stepHit();

		if ((FlxG.sound.music.time > Conductor.instance.trackedSongPosition + 20 || FlxG.sound.music.time < Conductor.instance.trackedSongPosition - 20)) {
			Conductor.instance.trackedSongPosition = FlxG.sound.music.time;
		}
	}

	function changeDiff(change:Int = 0)
	{
		var difficultyCount:Int = getDifficultyCount();

		if (difficultyCount <= 0)
		{
			curDifficulty = 0;
			diffText.text = "";
			return;
		}

		if (difficultyCount > 1)
		{
			curDifficulty += change;

			if (curDifficulty < 0)
				curDifficulty = difficultyCount - 1;
			if (curDifficulty > difficultyCount - 1)
				curDifficulty = 0;
		}
		else
		{
			curDifficulty = 0;
			change = 0;
		}

		#if !switch
		intendedScore = Highscore.getScore(songs[curSelected].songName, curDifficulty);
		#end

		diffText.text = CoolUtil.difficultyArray[curDifficulty].toUpperCase();

		#if (USING_LUA && cpp)
		if(luaReady) {
			setLua("curDifficulty", curDifficulty);
			callLua("onFreeplayDifficultyChange", [curDifficulty, change]);
		}
		#end
	}

	function changeSelection(change:Int = 0)
	{
		// NGio.logEvent('Fresh');
		FlxG.sound.play(Paths.sound('scrollMenu'), 0.4);

		curPlaying = false;
		giveTick = 0;

		curSelected += change;

		if (curSelected < 0)
			curSelected = songs.length - 1;
		if (curSelected >= songs.length)
			curSelected = 0;

		if(menuBG.exists) {
			menuBG.changeBackground(songs[curSelected].week, change);
		}

		// selector.y = (70 * curSelected) + 30;
		normalizeDifficulty();

		#if !switch
		intendedScore = Highscore.getScore(songs[curSelected].songName, curDifficulty);
		// lerpScore = 0;
		#end

		var bullShit:Int = 0;

		for (i in 0...iconArray.length)
		{
			iconArray[i].alpha = 0.6;
		}

		iconArray[curSelected].alpha = 1;

		for (item in grpSongs.members)
		{
			item.targetY = bullShit - curSelected;
			bullShit++;

			item.alpha = 0.6;
			// item.setGraphicSize(Std.int(item.width * 0.8));

			if (item.targetY == 0)
			{
				item.alpha = 1;
				// item.setGraphicSize(Std.int(item.width));
			}
		}

		#if (USING_LUA && cpp)
		if(luaReady) {
			setLua("curSelected", curSelected);
			callLua("onFreeplaySelectionChange", [curSelected, change]);
		}
		#end
	}

	#if (USING_LUA && cpp)
	override function onCreate():Dynamic {
		if(HelperStates.luaExist(Type.getClass(this))) {
			setupLuaBindings();
		}

		var result = super.onCreate();

		if(HelperStates.luaExist(Type.getClass(this))) {
			luaReady = true;
			setLua("curSelected", curSelected);
			setLua("curDifficulty", curDifficulty);
			callLua("onFreeplaySelectionChange", [curSelected, 0]);
			callLua("onFreeplayDifficultyChange", [curDifficulty, 0]);
		}

		return result;
	}

	function setupLuaBindings():Void {
		if(!HelperStates.luaExist(Type.getClass(this))) {
			return;
		}

		setLua("freeplaySongCount", songs.length);
		setLua("curSelected", curSelected);
		setLua("curDifficulty", curDifficulty);
		setLua("menuBackgroundBlur", backgroundBlur);

		addCallback("getFreeplaySongCount", function():Int {
			return songs.length;
		});

		addCallback("getFreeplaySongName", function(index:Int):String {
			var data = getSongAt(index);
			return data != null ? data.songName : "";
		});

		addCallback("getFreeplaySongWeek", function(index:Int):Int {
			var data = getSongAt(index);
			return data != null ? data.week : -1;
		});

		addCallback("getFreeplaySongCharacter", function(index:Int):String {
			var data = getSongAt(index);
			return data != null ? data.songCharacter : "";
		});

		addCallback("getFreeplayAlphabetInfo", function(index:Int):Dynamic {
			var entry = getAlphabetAt(index);
			if(entry == null) {
				return null;
			}

			return {
				x: entry.x,
				y: entry.y,
				width: entry.width,
				height: entry.height,
				alpha: entry.alpha,
				targetY: entry.targetY,
				visible: entry.visible
			};
		});

		addCallback("setFreeplayAlphabetVisible", function(index:Int, value:Bool) {
			var entry = getAlphabetAt(index);
			if(entry != null) {
				entry.visible = value;
			}
		});

		addCallback("setFreeplayAlphabetAlpha", function(index:Int, value:Float) {
			var entry = getAlphabetAt(index);
			if(entry != null) {
				entry.alpha = value;
			}
		});

		addCallback("setFreeplayAlphabetYMultiplier", function(index:Int, value:Int) {
			var entry = getAlphabetAt(index);
			if(entry != null) {
				entry.yMultiplier = value;
			}
		});

		addCallback("hasFreeplayGraffiti", function(index:Int):Bool {
			return (index >= 0 && index < hasGraffiti.length) ? hasGraffiti[index] : false;
		});

		addCallback("getFreeplaySelection", function():Int {
			return curSelected;
		});

		addCallback("getFreeplayDifficulty", function():Int {
			return curDifficulty;
		});
	}

	inline function getSongAt(index:Int):SongMetadata {
		return (index >= 0 && index < songs.length) ? songs[index] : null;
	}

	inline function getAlphabetAt(index:Int):Alphabet {
		if(grpSongs == null || grpSongs.members == null) {
			return null;
		}

		return (index >= 0 && index < grpSongs.members.length) ? grpSongs.members[index] : null;
	}
	#end
}

class SongMetadata {
	public var songName:String = "";
	public var week:Int = 0;
	public var songCharacter:String = "";

	public function new(song:String, week:Int, songCharacter:String)
	{
		this.songName = song;
		this.week = week;
		this.songCharacter = songCharacter;
	}
}
