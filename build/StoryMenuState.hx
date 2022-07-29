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
import flixel.group.FlxSpriteGroup;
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

	var grpWeekText:FlxSpriteGroup;

	var grpLocks:FlxTypedGroup<FlxSprite>;

	var menuBG:MenuBackground;
	var extraStuff:FlxBackdrop;

	var difficultySelectors:FlxGroup;
	var sprDifficulty:FlxSprite;
	var leftArrow:FlxSprite;
	var rightArrow:FlxSprite;

	var disableControls:Bool = false;

	override function create()
	{
		if (FlxG.sound.music != null)
		{
			if (!FlxG.sound.music.playing)
				FlxG.sound.playMusic(Paths.music('mainMenu'));
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

		grpWeekText = new FlxSpriteGroup();
		add(grpWeekText);

		grpLocks = new FlxTypedGroup<FlxSprite>();
		add(grpLocks);
		
		#if windows
		// Updating Discord Rich Presence
		DiscordClient.changePresence("In the Menus", null);
		#end

		var i:Int = 0;

		while(Paths.modJSON.weeks.get("week_" + i) != null) {
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

		sprDifficulty.screenCenter(X);
		sprDifficulty.visible = false;
		difficultySelectors.add(sprDifficulty);

		txtTracklist = new FlxText(FlxG.width * 0.05, 535, 0, "", 24);
		txtTracklist.alignment = CENTER;
		txtTracklist.color = FlxColor.WHITE;
		add(txtTracklist);
		add(scoreText);
		add(txtWeekTitle);

		updateText();

		#if USING_LUA
		if(HelperStates.luaExist(Type.getClass(this))) {
			modifiableSprites.set("menuBG", menuBG);
			modifiableSprites.set("backdrop", extraStuff);
			modifiableSprites.set("blackBarTop", blackBarThingie);
			modifiableSprites.set("blackBarBottom", bottomBarThingie);
			modifiableSprites.set("rightArrow", rightArrow);
			modifiableSprites.set("leftArrow", leftArrow);
			modifiableSprites.set("sprDifficulty", sprDifficulty);
			modifiableSprites.set("txtTracklist", txtTracklist);
			modifiableSprites.set("txtWeekTitle", txtWeekTitle);
			modifiableSprites.set("grpWeekText", grpWeekText);
		}
		#end

		super.create();
	}

	override function onCreate():Dynamic {
		addCallback("disableRegularInput", function(value:Bool) {
			disableControls = value;
		});

		addCallback("selectWeek", function() {
			basedWeekChange();
		});

		addCallback("changeDifficulty", function(value:Int) {
			changeDifficulty(value);
		});

		setLua("curDifficulty", curDifficulty);
		changeDifficulty();
		return super.onCreate();
	}

	var movedBack:Bool = false;
	var selectedWeek:Bool = false;
	var stopspamming:Bool = false;

	override function update(elapsed:Float) {
		var leftP:Bool = (disableControls ? false : controls.LEFT_P);
		var downP:Bool = (disableControls ? false : controls.DOWN_P);
		var upP:Bool = (disableControls ? false : controls.UP_P);
		var rightP:Bool = (disableControls ? false : controls.RIGHT_P);

		var leftR:Bool = (disableControls ? false : controls.LEFT_R);
		var downR:Bool = (disableControls ? false : controls.DOWN_R);
		var upR:Bool = (disableControls ? false : controls.UP_R);
		var rightR:Bool = (disableControls ? false : controls.RIGHT_R);

		var accept:Bool = (disableControls ? false : controls.ACCEPT);
		var back:Bool = (disableControls ? false : controls.BACK);

		lerpScore = Math.floor(FlxMath.lerp(lerpScore, intendedScore, 0.5));
		scoreText.text = "WEEK SCORE:" + lerpScore;

		if(txtWeekTitle.exists) {
			txtWeekTitle.text = Paths.modJSON.weeks.get("week_" + curWeek).week_name.toUpperCase();
			txtWeekTitle.x = FlxG.width - (txtWeekTitle.width + 10);
		}

		difficultySelectors.visible = Paths.modJSON.weeks.get("week_" + curWeek).week_unlocked;

		grpLocks.forEach(function(lock:FlxSprite)
		{
			if(grpWeekText.exists) {
				lock.y = grpWeekText.members[lock.ID].y;
			}
		});

		if(extraStuff.exists) {
			extraStuff.x -= 0.45 / (Paths.modJSON.main_menu.bpm / 60);
			extraStuff.y += 0.45 / (Paths.modJSON.main_menu.bpm / 60);
		}

		if (!movedBack)
		{
			if (!selectedWeek && !stopspamming)
			{
				if (rightP) {
					if(rightArrow.exists)rightArrow.animation.play('press');

					if(chooseDifficulty)
						changeDifficulty(1);
					else
						changeWeek(1);
				}else if(rightR) {
					if(rightArrow.exists)rightArrow.animation.play('idle');
				}

				if (leftP) {
					if(leftArrow.exists)leftArrow.animation.play('press');
					
					if(chooseDifficulty)
						changeDifficulty(-1);
					else
						changeWeek(-1);
				} else if(leftR) {
					if(leftArrow.exists)leftArrow.animation.play('idle');
				}
			}

			if (accept) {
				if(rightArrow.exists && leftArrow.exists) {
					leftArrow.animation.play('idle');
					rightArrow.animation.play('idle');
				}

				selectWeek();
			}
		}

		if (back && !movedBack && !selectedWeek) {
			if(chooseDifficulty) {
				chooseDifficulty = false;

				if(sprDifficulty.exists) {
					sprDifficulty.visible = false;
				}

				if(grpWeekText.exists) {
					add(grpWeekText);
				}

				FlxG.sound.play(Paths.sound('cancelMenu'));
				changeWeek(0);
			}else {
				FlxG.sound.play(Paths.sound('cancelMenu'));
				movedBack = true;
				FlxG.switchState(new MainMenuState(true));
			}
		}

		if(menuBG.exists) {
			menuBG.sway += 0.001;
			menuBG.y -= Math.sin(menuBG.sway * Paths.modJSON.main_menu.bpm * 0.1)/4;
		}

		super.update(elapsed);
	}

	function selectWeek()
	{
		if(!chooseDifficulty) {
			if(grpWeekText.exists) {
				remove(grpWeekText);
			}

			if(sprDifficulty.exists) {
				sprDifficulty.visible = true;
			}

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

			basedWeekChange();
		}
	}

	function basedWeekChange():Void {
		var daSongs:Array<String> = [];

		for(i in 0...Paths.modJSON.weeks.get("week_" + curWeek).week_data.length) {
			daSongs.push(Paths.modJSON.weeks.get("week_" + curWeek).week_data[i]);
		}

		var diffic = "";

		switch (curDifficulty)
		{
			case 0:
				diffic = '-easy';
			case 2:
				diffic = '-hard';
		}

		PlayState.storyPlaylist = daSongs;
		PlayState.isStoryMode = true;
		selectedWeek = true;

		PlayState.storyDifficulty = curDifficulty;

		PlayState.SONG = Song.loadFromJson(PlayState.storyPlaylist[0].toLowerCase() + diffic, PlayState.storyPlaylist[0].toLowerCase());
		PlayState.storyWeek = curWeek;
		PlayState.campaignScore = 0;

		//FlxG.switchState(new InGameOptions("StoryMenuState", PlayState.SONG));

		if(sprDifficulty.exists) {
			FlxFlicker.flicker(sprDifficulty, 1, 0.06, false, false, function(flick:FlxFlicker) {
				#if cpp
				CacheState.loadAndSwitchState(new PlayState());
				#else
				LoadingState.loadAndSwitchState(new PlayState());
				#end
			});
		}else {
			#if cpp
			CacheState.loadAndSwitchState(new PlayState());
			#else
			LoadingState.loadAndSwitchState(new PlayState());
			#end
		}
	}

	function changeDifficulty(change:Int = 0):Void
	{
		curDifficulty += change;

		if (curDifficulty < 0)
			curDifficulty = CoolUtil.difficultyArray.length;
		if (curDifficulty > CoolUtil.difficultyArray.length)
			curDifficulty = 0;

		setLua("curDifficulty", curDifficulty);

		if(change != 0)
			FlxG.sound.play(Paths.sound('scrollMenu'));

		if(sprDifficulty.exists) {
			sprDifficulty.offset.x = 0;

			switch (curDifficulty)
			{
				case 0:
					sprDifficulty.animation.play('easy');
				case 1:
					sprDifficulty.animation.play('normal');
				case 2:
					sprDifficulty.animation.play('hard');
			}

			sprDifficulty.centerOffsets();
			sprDifficulty.alpha = 0;

			// USING THESE WEIRD VALUES SO THAT IT DOESNT FLOAT UP
			sprDifficulty.y = leftArrow.y - 15;

			FlxTween.tween(sprDifficulty, {y: leftArrow.y + 15, alpha: 1}, 0.07);
		}

		intendedScore = Highscore.getWeekScore(curWeek, curDifficulty);

		#if !switch
		intendedScore = Highscore.getWeekScore(curWeek, curDifficulty);
		#end
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

		if(grpWeekText.exists) {
			for (i in 0...grpWeekText.length) {
				grpWeekText.members[i].alpha = 0;
			}
		}

		if(menuBG.exists) {
			menuBG.changeBackground(curWeek, change);
		}

		if(Paths.modJSON.weeks.get("week_" + curWeek).week_unlocked)
			weekAlpha = 1;
		else
			weekAlpha = 0.6;

		if(!chooseDifficulty) {
			if(grpWeekText.exists) {
				FlxTween.tween(grpWeekText.members[curWeek], {alpha: weekAlpha}, 0.3, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
					if(rightArrow.exists && leftArrow.exists) {
						rightArrow.animation.play('idle');
						leftArrow.animation.play('idle');
					}

					stopspamming = false;
				}});
			}else {
				if(rightArrow.exists && leftArrow.exists) {
					rightArrow.animation.play('idle');
					leftArrow.animation.play('idle');
				}

				stopspamming = false;
			}
		}	

		var bullShit:Int = 0;

		FlxG.sound.play(Paths.sound('scrollMenu'));

		updateText();
	}

	function updateText() {
		if(txtTracklist.exists) {
			txtTracklist.text = "Tracks\n\n";

			var stringThing:Array<String> = Paths.modJSON.weeks.get("week_" + curWeek).week_data;

			for (i in 0...stringThing.length) {
				txtTracklist.text += stringThing[i] + "\n";
			}

			txtTracklist.text = txtTracklist.text.toUpperCase();

			txtTracklist.screenCenter(X);
			txtTracklist.x -= FlxG.width * 0.35;
		}

		#if !switch
		intendedScore = Highscore.getWeekScore(curWeek, curDifficulty);
		#end
	}
}