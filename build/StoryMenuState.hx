package;

#if windows
import Discord.DiscordClient;
#end
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.display.FlxBackdrop;
import flixel.addons.transition.FlxTransitionableState;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.group.FlxGroup;
import flixel.math.FlxMath;
import flixel.text.FlxText;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.util.FlxColor;
import flixel.effects.FlxFlicker;
import lime.net.curl.CURLCode;

import Feeshmora;

using StringTools;

class StoryMenuState extends MusicBeatState
{
	var scoreText:FlxText;

	var curDifficulty:Int = 1;

	var chooseDifficulty:Bool;

	var txtWeekTitle:FlxText;

	var curWeek:Int = 0;

	var txtTracklist:FlxText;

	var grpWeekText:FlxTypedGroup<FlxSprite>;

	var grpLocks:FlxTypedGroup<FlxSprite>;

	var menuBG:MenuBackground;
	var extraStuff:FlxBackdrop;

	var difficultySelectors:FlxGroup;
	var sprDifficulty:FlxSprite;
	var leftArrow:FlxSprite;
	var rightArrow:FlxSprite;

	override function create()
	{
		transIn = FlxTransitionableState.defaultTransIn;
		transOut = FlxTransitionableState.defaultTransOut;

		if (FlxG.sound.music != null)
		{
			if (!FlxG.sound.music.playing)
				FlxG.sound.playMusic(Paths.music('freakyMenu'));
		}

		menuBG = new MenuBackground(0, 56);
		add(menuBG);

		extraStuff = new FlxBackdrop(Paths.image('check'), 0.2, 0.2, true, true);
		extraStuff.alpha = 0.1;
		add(extraStuff);

		var blackBarThingie:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, 56, FlxColor.BLACK);
		add(blackBarThingie);

		var bottomBarThingie:FlxSprite = new FlxSprite(0, FlxG.height * 0.7).makeGraphic(FlxG.width, 216, FlxColor.BLACK);
		add(bottomBarThingie);

		persistentUpdate = persistentDraw = true;

		scoreText = new FlxText(10, 10, 0, "SCORE: 49324858", 36);
		scoreText.setFormat("VCR OSD Mono", 32);

		txtWeekTitle = new FlxText(FlxG.width * 0.7, 10, 0, "", 32);
		txtWeekTitle.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, RIGHT);
		txtWeekTitle.alpha = 0.7;

		var rankText:FlxText = new FlxText(0, 10);
		rankText.text = 'RANK: GREAT';
		rankText.setFormat(Paths.font("vcr.ttf"), 32);
		rankText.size = scoreText.size;
		rankText.screenCenter(X);

		var ui_tex = Paths.getSparrowAtlas('campaign_menu_UI_assets');

		grpWeekText = new FlxTypedGroup<FlxSprite>();
		add(grpWeekText);

		grpLocks = new FlxTypedGroup<FlxSprite>();
		add(grpLocks);

		trace("Line 70");
		
		#if windows
		// Updating Discord Rich Presence
		DiscordClient.changePresence("In the Menus", null);
		#end

		var i:Int = 0;

		for (index in Paths.modJSON.weeks) {
			var weekThing:FlxSprite = new FlxSprite(0, 575).loadGraphic(Paths.image('storymenu/week' + i));

			weekThing.centerOffsets();

			if(i != curWeek)
				weekThing.alpha = 0;

			grpWeekText.add(weekThing);

			weekThing.screenCenter(X);
			weekThing.antialiasing = FlxG.save.data.showAntialiasing;
			// weekThing.updateHitbox();

			// Needs an offset thingie
			if (!Paths.modJSON.weeks.get("week_" + i).week_unlocked) {
				var lock:FlxSprite = new FlxSprite(0, 575);
				lock.frames = ui_tex;
				lock.animation.addByPrefix('lock', 'lock');
				lock.animation.play('lock');
				lock.ID = i;
				lock.antialiasing = true;
				lock.screenCenter(X);
				grpLocks.add(lock);
			}

			i++;
		}

		difficultySelectors = new FlxGroup();
		add(difficultySelectors);

		rightArrow = new FlxSprite(grpWeekText.members[0].x + grpWeekText.members[0].width + 10, 570);
		rightArrow.frames = Paths.getSparrowAtlas('pick_right');
		rightArrow.animation.addByPrefix('idle', 'arrow0');
		rightArrow.animation.addByPrefix('press', "arrow push right", 24, false);
		rightArrow.animation.play('idle');
		rightArrow.antialiasing = FlxG.save.data.showAntialiasing;
		difficultySelectors.add(rightArrow);

		leftArrow = new FlxSprite(grpWeekText.members[0].x - rightArrow.width - 10, 570);
		leftArrow.frames = Paths.getSparrowAtlas('pick_left');
		leftArrow.animation.addByPrefix('idle', "arrow0");
		leftArrow.animation.addByPrefix('press', "arrow push left", 24, false);
		leftArrow.animation.play('idle');
		leftArrow.antialiasing = FlxG.save.data.showAntialiasing;
		difficultySelectors.add(leftArrow);

		sprDifficulty = new FlxSprite(leftArrow.x + 130, leftArrow.y);
		sprDifficulty.frames = ui_tex;
		sprDifficulty.animation.addByPrefix('easy', 'EASY');
		sprDifficulty.animation.addByPrefix('normal', 'NORMAL');
		sprDifficulty.animation.addByPrefix('hard', 'HARD');
		sprDifficulty.animation.play('easy');
		changeDifficulty();

		sprDifficulty.screenCenter(X);
		sprDifficulty.visible = false;
		difficultySelectors.add(sprDifficulty);

		txtTracklist = new FlxText(FlxG.width * 0.05, 535, 0, "", 24);
		txtTracklist.alignment = CENTER;
		txtTracklist.color = FlxColor.WHITE;
		add(txtTracklist);
		// add(rankText);
		add(scoreText);
		add(txtWeekTitle);

		updateText();

		trace("Line 165");

		super.create();
	}

	var movedBack:Bool = false;
	var selectedWeek:Bool = false;
	var stopspamming:Bool = false;

	override function update(elapsed:Float)
	{
		// scoreText.setFormat('VCR OSD Mono', 32);
		lerpScore = Math.floor(FlxMath.lerp(lerpScore, intendedScore, 0.5));

		scoreText.text = "WEEK SCORE:" + lerpScore;

		txtWeekTitle.text = Paths.modJSON.weeks.get("week_" + curWeek).week_name.toUpperCase();
		txtWeekTitle.x = FlxG.width - (txtWeekTitle.width + 10);

		// FlxG.watch.addQuick('font', scoreText.font);

		difficultySelectors.visible = Paths.modJSON.weeks.get("week_" + curWeek).week_unlocked;

		grpLocks.forEach(function(lock:FlxSprite)
		{
			lock.y = grpWeekText.members[lock.ID].y;
		});

		extraStuff.x -= 0.45 / (Paths.modJSON.main_menu.bpm / 60);
		extraStuff.y += 0.45 / (Paths.modJSON.main_menu.bpm / 60);

		if (!movedBack)
		{
			if (!selectedWeek && !stopspamming)
			{
				if (controls.RIGHT_P) {
					rightArrow.animation.play('press');

					if(chooseDifficulty)
						changeDifficulty(1);
					else
						changeWeek(1);
				}else if(controls.RIGHT_R) {
					rightArrow.animation.play('idle');
				}

				if (controls.LEFT_P) {
					leftArrow.animation.play('press');
					
					if(chooseDifficulty)
						changeDifficulty(-1);
					else
						changeWeek(-1);
				} else if(controls.LEFT_R)
					leftArrow.animation.play('idle');
			}

			if (controls.ACCEPT)
			{
				selectWeek();
			}
		}

		if (controls.BACK && !movedBack && !selectedWeek) {
			if(chooseDifficulty) {
				chooseDifficulty = false;
				sprDifficulty.visible = false;
				add(grpWeekText);
				FlxG.sound.play(Paths.sound('cancelMenu'));
				changeWeek(0);
			}else {
				FlxG.sound.play(Paths.sound('cancelMenu'));
				movedBack = true;
				FlxG.switchState(new MainMenuState(true));
			}
		}

		menuBG.sway += 0.001;
        menuBG.y -= Math.sin(menuBG.sway * Paths.modJSON.main_menu.bpm * 0.1)/4;

		super.update(elapsed);
	}

	function selectWeek()
	{
		if(!chooseDifficulty) {
			remove(grpWeekText);
			sprDifficulty.visible = true;
			chooseDifficulty = true;
			return;
		}

		if (Paths.modJSON.weeks.get("week_" + curWeek).week_unlocked)
		{
			if (stopspamming == false)
			{
				FlxG.sound.play(Paths.sound('confirmMenu'));

				stopspamming = true;
			}

			var daSongs:Array<String> = [];

			for(i in 0...Paths.modJSON.weeks.get("week_" + curWeek).week_data.length)
				daSongs.push(Paths.modJSON.weeks.get("week_" + curWeek).week_data[i]);


			PlayState.storyPlaylist = daSongs;
			PlayState.isStoryMode = true;
			selectedWeek = true;

			var diffic = "";

			switch (curDifficulty)
			{
				case 0:
					diffic = '-easy';
				case 2:
					diffic = '-hard';
			}

			PlayState.storyDifficulty = curDifficulty;

			PlayState.SONG = Song.loadFromJson(PlayState.storyPlaylist[0].toLowerCase() + diffic, PlayState.storyPlaylist[0].toLowerCase());
			PlayState.storyWeek = curWeek;
			PlayState.campaignScore = 0;

			//FlxG.switchState(new InGameOptions("StoryMenuState", PlayState.SONG));

			FlxFlicker.flicker(sprDifficulty, 1, 0.06, false, false, function(flick:FlxFlicker) {
				#if cpp
				CacheState.loadAndSwitchState(new PlayState());
				#else
				LoadingState.loadAndSwitchState(new PlayState());
				#end
			});
		}
	}

	function changeDifficulty(change:Int = 0):Void
	{
		curDifficulty += change;

		if (curDifficulty < 0)
			curDifficulty = 2;
		if (curDifficulty > 2)
			curDifficulty = 0;

		sprDifficulty.offset.x = 0;

		if(change != 0)
			FlxG.sound.play(Paths.sound('scrollMenu'));

		switch (curDifficulty)
		{
			case 0:
				sprDifficulty.animation.play('easy');
				sprDifficulty.offset.x = 20;
			case 1:
				sprDifficulty.animation.play('normal');
				sprDifficulty.offset.x = 70;
			case 2:
				sprDifficulty.animation.play('hard');
				sprDifficulty.offset.x = 20;
		}

		sprDifficulty.alpha = 0;

		// USING THESE WEIRD VALUES SO THAT IT DOESNT FLOAT UP
		sprDifficulty.y = leftArrow.y - 15;
		intendedScore = Highscore.getWeekScore(curWeek, curDifficulty);

		#if !switch
		intendedScore = Highscore.getWeekScore(curWeek, curDifficulty);
		#end

		FlxTween.tween(sprDifficulty, {y: leftArrow.y + 15, alpha: 1}, 0.07);
	}

	var lerpScore:Int = 0;
	var intendedScore:Int = 0;

	var weekAlpha:Float = 1;

	function changeWeek(change:Int = 0):Void
	{
		curWeek += change;

		stopspamming = true;

		if (curWeek >= Lambda.count(Paths.modJSON.weeks))
			curWeek = 0;
		if (curWeek < 0)
			curWeek = Lambda.count(Paths.modJSON.weeks) - 1;

		for (i in 0...grpWeekText.length) {
			grpWeekText.members[i].alpha = 0;
		}

		menuBG.changeBackground(curWeek, change);

		if(Paths.modJSON.weeks.get("week_" + curWeek).week_unlocked)
			weekAlpha = 1;
		else
			weekAlpha = 0.6;

		if(!chooseDifficulty) {
			FlxTween.tween(grpWeekText.members[curWeek], {alpha: weekAlpha}, 0.3, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
				rightArrow.animation.play('idle');
				leftArrow.animation.play('idle');
				stopspamming = false;
			}});
		}	

		var bullShit:Int = 0;

		FlxG.sound.play(Paths.sound('scrollMenu'));

		updateText();
	}

	function updateText() {
		txtTracklist.text = "Tracks\n\n";

		var stringThing:Array<String> = Paths.modJSON.weeks.get("week_" + curWeek).week_data;

		for (i in 0...stringThing.length) {
			txtTracklist.text += stringThing[i] + "\n";
		}

		txtTracklist.text = txtTracklist.text.toUpperCase();

		txtTracklist.screenCenter(X);
		txtTracklist.x -= FlxG.width * 0.35;

		#if !switch
		intendedScore = Highscore.getWeekScore(curWeek, curDifficulty);
		#end
	}
}