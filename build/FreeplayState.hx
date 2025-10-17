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
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.ShaderFilter;
import feshixl.math.FeshMath;
import feshixl.FeshCamera;
import lime.utils.Assets;
import flixel.graphics.FlxGraphic;
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

    // Optional graffiti images that replace song text if present
    private var graffitiSprites:Array<FlxSprite> = [];
	private var grpGraffiti:FlxTypedGroup<FlxSprite>;

	static inline var GRAFFITI_HEIGHT:Int = 444; // target height for each graffiti label
	static inline var GRAFFITI_Y_OFFSET:Int = 0; // small vertical tweak to center on the row
	static inline var MENU_SPACING:Int = 320; // spacing between menu rows (lower = tighter)

	// Spray-can reveal animation state
	private var graffitiRevealed:Array<Bool> = [];
	private var graffitiCanSprites:Array<FlxSprite> = [];
	private var graffitiAnimT:Array<Float> = [];
	private var graffitiAnimActive:Array<Bool> = [];
	private var graffitiFading:Array<Bool> = [];
	static inline var CAN_ANIM_DURATION:Float = 1.0;

	private var menuBG:MenuBackground;

	var camFreeplay:FeshCamera;
	var camBackground:FeshCamera;

	override function create()
	{
		super.create();

		#if windows
		// Updating Discord Rich Presence
		DiscordClient.changePresence("In the Menus", null);
		#end

		var isDebug:Bool = false;

		#if debug
		isDebug = true;
		#end

		var index:Int = 0;

		while(Paths.modJSON.weeks.get("week_" + index) != null) {
			for(v in 0...Paths.modJSON.weeks.get("week_" + index).week_data.length) {
				var peepeepoopoo:SwagSong = Song.loadFromJson(
					Paths.modJSON.weeks.get("week_" + index).week_data[v].toLowerCase(),
					Paths.modJSON.weeks.get("week_" + index).week_data[v].toLowerCase()
				);

				if(Paths.modJSON.weeks.get("week_" + index).week_unlocked)
					addSong(Paths.modJSON.weeks.get("week_" + index).week_data[v].toLowerCase(), index, peepeepoopoo.player2);
			}

			index++;
		}

		Conductor.songPosition = 0;
		Conductor.songPosition -= Conductor.crochet * 5;

		camFreeplay = new FeshCamera();
		camBackground = new FeshCamera();
		camFreeplay.bgColor.alpha = 0;
		camBackground.bgColor.alpha = 0;

        FlxG.cameras.add(camBackground);
		FlxG.cameras.add(camFreeplay);

		FlxCamera.defaultCameras = [camFreeplay];

		camBackground.setFilters([new BlurFilter(10, 10, BitmapFilterQuality.LOW), new ShaderFilter(new StupidVibeShader(1.5))]);

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

		// group to render graffiti labels; placed right after text so icons appear above
		grpGraffiti = new FlxTypedGroup<FlxSprite>();
		grpGraffiti.cameras = [camFreeplay];
		add(grpGraffiti);

		for (i in 0...songs.length)
		{
			var songText:Alphabet = new Alphabet(0, (70 * i) + 30, songs[i].songName, true, false);
			songText.isMenuItem = true;
			songText.targetY = i;
			songText.yMultiplier = MENU_SPACING;

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
			// Hide icons (yellow faces) in Freeplay when using graffiti labels
			icon.visible = false;

            // Try to load a graffiti image for this song: mod_assets/images/Graffiti/<song>.png
            var graffitiKey:String = 'Graffiti/' + songs[i].songName.toLowerCase();
            var graffitiGraphic:FlxGraphic = Paths.image(graffitiKey);
            if (graffitiGraphic != null) {
                var g:FlxSprite = new FlxSprite(songText.x, songText.y);
                g.loadGraphic(graffitiGraphic);
                g.setGraphicSize(0, GRAFFITI_HEIGHT);
                g.updateHitbox();
                g.cameras = [camFreeplay];
                g.alpha = songText.alpha;
                grpGraffiti.add(g);
                graffitiSprites.push(g);
                // Hide the original text; we still keep it for layout/selection logic
                songText.visible = false;
                // init reveal flags
                graffitiRevealed.push(false);
                graffitiCanSprites.push(null);
                graffitiAnimT.push(0);
                graffitiAnimActive.push(false);
                graffitiFading.push(false);
            } else {
                // Keep array aligned with songs for simpler syncing
                graffitiSprites.push(null);
                graffitiRevealed.push(true);
                graffitiCanSprites.push(null);
                graffitiAnimT.push(0);
                graffitiAnimActive.push(false);
                graffitiFading.push(false);
            }
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
		}
		#end
	}

	public function addSong(songName:String, weekNum:Int, songCharacter:String)
	{
		songs.push(new SongMetadata(songName, weekNum, songCharacter));
	}

	override function update(elapsed:Float) {
		super.update(elapsed);

		if (FlxG.sound.music != null)
			Conductor.songPosition = FlxG.sound.music.length;

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

		if (controls.LEFT_P)
			changeDiff(-1);
		if (controls.RIGHT_P)
			changeDiff(1);

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
			//FlxG.switchState(new InGameOptions("StoryMenuState", PlayState.SONG));

			var peepeepoopoo:SwagSong = Song.loadFromJson(poop, songs[curSelected].songName.toLowerCase());
		    #if debug
			CacheState.loadAndSwitchState(new PlayState());
		    #else
			CacheState.loadAndSwitchStateF(new PlayState());
		    #end
		}

        // Keep any graffiti images aligned with the invisible text items as they smoothly animate
        for (i in 0...songs.length) {
            var songText = grpSongs.members[i];
            var g = graffitiSprites[i];
            if (g != null && songText != null) {
                g.x = (FlxG.width - g.width) / 2;
                g.y = songText.y + ((songText.height - g.height) / 2) + GRAFFITI_Y_OFFSET;
                // Only force-hide before reveal; during fading let tween control alpha
                if (!graffitiRevealed[i] && !graffitiFading[i]) g.alpha = 0;
                if (graffitiRevealed[i]) g.alpha = songText.alpha;
            }
        }

        // Update active spray-can animations
        for (i in 0...songs.length) {
            if (graffitiAnimActive[i]) {
                updateCanAnim(i, elapsed);
            }
        }
	}

	override function stepHit() {
		super.stepHit();

		if ((FlxG.sound.music.time > Conductor.songPosition + 20 || FlxG.sound.music.time < Conductor.songPosition - 20)) {
			Conductor.songPosition = FlxG.sound.music.time;
		}
	}

	function changeDiff(change:Int = 0)
	{
		curDifficulty += change;

		if (curDifficulty < 0)
			curDifficulty = CoolUtil.difficultyArray.length - 1;
		if (curDifficulty > CoolUtil.difficultyArray.length - 1)
			curDifficulty = 0;

		#if !switch
		intendedScore = Highscore.getScore(songs[curSelected].songName, curDifficulty);
		#end

		diffText.text = CoolUtil.difficultyArray[curDifficulty].toUpperCase();
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

        // Also update the alpha of any graffiti sprites to match selection highlighting
        for (i in 0...songs.length) {
            var songText = grpSongs.members[i];
            var g = graffitiSprites[i];
            if (g != null && songText != null) {
                if (graffitiRevealed[i]) g.alpha = songText.alpha;
                g.x = (FlxG.width - g.width) / 2;
                g.y = songText.y + ((songText.height - g.height) / 2) + GRAFFITI_Y_OFFSET;
            }
        }

        // Trigger reveal animation once per song when first selected
        if (graffitiSprites[curSelected] != null && !graffitiRevealed[curSelected] && !graffitiAnimActive[curSelected]) {
            startGraffitiReveal(curSelected);
        }
	}

    inline function logChirp(x:Float, a:Float, b:Float, n:Float, A:Float):Float {
        var shift:Float = Math.exp(-4.0 * Math.PI / a);
        var u:Float = x / b + shift;
        var phase:Float = a * Math.log(u);
        var env:Float = Math.exp(0.5 - (x / (b * n)));
        return A * 4.0 * env * Math.sin(phase);
    }

    inline function gFunc(t:Float):Float {
        return t * Math.exp(t / 4);
    }

    function startGraffitiReveal(index:Int):Void {
        var g = graffitiSprites[index];
        if (g == null) return;

        // Prepare for fade-in
        g.alpha = 0;
        graffitiAnimT[index] = 0;
        graffitiAnimActive[index] = true;

        var canGfx:FlxGraphic = Paths.image('Graffiti/can');
        if (canGfx == null) {
            graffitiRevealed[index] = true;
            graffitiAnimActive[index] = false;
            g.alpha = 1;
            return;
        }

        var can = new FlxSprite();
        can.loadGraphic(canGfx);
        can.cameras = [camFreeplay];
        can.setGraphicSize(Std.int(g.height * 2.0));
        can.updateHitbox();
        graffitiCanSprites[index] = can;
        add(can);
    }

    function updateCanAnim(index:Int, elapsed:Float):Void {
        var g = graffitiSprites[index];
        var can = graffitiCanSprites[index];
        if (g == null || can == null) return;

        graffitiAnimT[index] += elapsed;
        var t:Float = graffitiAnimT[index] / CAN_ANIM_DURATION;
        if (t > 1) t = 1;

        var left:Float = (FlxG.width - g.width) / 2 - can.width * 0.5;
        var midY:Float = g.y + g.height * 0.5;
        var xOffset:Float = g.width * t;
        var yOffset:Float = logChirp(t * 48.0, 48.0, 24.0, 1.0, Math.max(6.0, g.height * 0.06));

        can.x = left + xOffset;
        can.y = midY + yOffset - can.height * 0.5;

        if (graffitiAnimT[index] >= CAN_ANIM_DURATION) {
            // Begin fade in; tween controls alpha until completion
            g.alpha = 0;
            g.visible = true;
            graffitiFading[index] = true;
            FlxTween.tween(g, {alpha: 1}, 0.4, {
                ease: FlxEase.quadOut,
                onComplete: function(_) {
                    graffitiFading[index] = false;
                    graffitiRevealed[index] = true;
                }
            });

            remove(can, true);
            graffitiCanSprites[index] = null;
            graffitiAnimActive[index] = false;
        }
    }
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
