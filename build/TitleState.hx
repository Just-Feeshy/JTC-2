package;

#if windows
import Discord.DiscordClient;
import sys.thread.Thread;
#end
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.addons.display.FlxGridOverlay;
import flixel.graphics.FlxGraphic;
import flixel.group.FlxSpriteGroup;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.group.FlxGroup;
import flixel.input.gamepad.FlxGamepad;
import flixel.math.FlxPoint;
import flixel.system.FlxSound;
import flixel.system.ui.FlxSoundTray;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;
import flixel.util.FlxSort;
import lime.app.Application;
import openfl.Assets;

using StringTools;

class TitleState extends MusicBeatState {
	static var initialized:Bool = false;

	var logoBl:FlxSprite;
	var gfDance:FlxSprite;
	var danceLeft:Bool = false;
	var titleText:FlxSprite;

	var blackScreen:FlxSprite;
	var credGroup:FlxGroup;
	var credTextShit:Alphabet;
	var textGroup:FlxGroup;
	var ngSpr:FlxSprite;

	var credits:Array<String> = Paths.modJSON.title_menu.mod_creators;

	override public function create():Void
	{
		Conductor.songPosition = 0;
		Conductor.songPosition -= Conductor.crochet * 5;
		credits.sort(sortByShit);

		PlayerSettings.init();

		#if windows
		DiscordClient.initialize();
		
		Application.current.onExit.add (function (exitCode) {
			DiscordClient.shutdown();
		});
		#end

		super.create();

		if(!callLua("cancelDefaultIntro", [])) {
			startIntro();
		}
	}

	function startIntro()
	{
		FlxG.sound.playMusic(Paths.music(Paths.modJSON.title_menu.music.song), 0);
		FlxG.sound.music.fadeIn(4, 0, 0.7);

		Conductor.changeBPM(Paths.modJSON.title_menu.music.bpm);
		persistentUpdate = true;

		var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		add(bg);

		logoBl = new FlxSprite(-150, -100);
		logoBl.frames = Paths.getSparrowAtlas('logoBumpin');
		logoBl.antialiasing = true;
		logoBl.animation.addByPrefix('bump', 'logo bumpin', 24);
		logoBl.animation.play('bump');
		logoBl.updateHitbox();

		gfDance = new FlxSprite(FlxG.width * 0.4, FlxG.height * 0.07);
		gfDance.frames = Paths.getSparrowAtlas('gfDanceTitle');
		gfDance.animation.addByIndices('danceLeft', 'gfDance', [30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14], "", 24, false);
		gfDance.animation.addByIndices('danceRight', 'gfDance', [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29], "", 24, false);
		gfDance.antialiasing = true;
		add(gfDance);
		add(logoBl);

		titleText = new FlxSprite(100, FlxG.height * 0.8);
		titleText.frames = Paths.getSparrowAtlas('titleEnter');
		titleText.animation.addByPrefix('idle', "Press Enter to Begin", 24);
		titleText.animation.addByPrefix('press', "ENTER PRESSED", 24);
		titleText.antialiasing = true;
		titleText.animation.play('idle');
		titleText.updateHitbox();
		// titleText.screenCenter(X);
		add(titleText);

		var logo:FlxSprite = new FlxSprite().loadGraphic(Paths.image('logo'));
		logo.screenCenter();
		logo.antialiasing = true;
		// add(logo);

		credGroup = new FlxGroup();
		add(credGroup);
		textGroup = new FlxGroup();

		blackScreen = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		credGroup.add(blackScreen);

		credTextShit = new Alphabet(0, 0, "ninjamuffin99\nPhantomArcade\nkawaisprite\nevilsk8er", true);
		credTextShit.screenCenter();

		credTextShit.visible = false;

		ngSpr = new FlxSprite(0, FlxG.height * 0.52).loadGraphic(Paths.image('newgrounds_logo'));
		add(ngSpr);
		ngSpr.visible = false;
		ngSpr.setGraphicSize(Std.int(ngSpr.width * 0.8));
		ngSpr.updateHitbox();
		ngSpr.screenCenter(X);
		ngSpr.antialiasing = true;

		FlxTween.tween(credTextShit, {y: credTextShit.y + 20}, 2.9, {ease: FlxEase.quadInOut, type: PINGPONG});

		FlxG.mouse.visible = false;

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			modifiableSprites.set("logoBl", logoBl);
			modifiableSprites.set("gfDance", gfDance);
			modifiableSprites.set("titleText", titleText);
			modifiableCameras.set("mainCam", FlxG.camera);
		}
		#end

		callLua("onStartIntro", [initialized]);

		if (initialized)
			skipIntro();
		else
			initialized = true;
	}

	function getIntroTextShit():Array<Array<String>>
	{
		var fullText:String = Assets.getText(Paths.txt('introText'));

		var firstArray:Array<String> = fullText.split('\n');
		var swagGoodArray:Array<Array<String>> = [];

		for (i in firstArray)
		{
			swagGoodArray.push(i.split('--'));
		}

		return swagGoodArray;
	}

	var pressedEnter:Bool;

	var transitioning:Bool = false;

	override function update(elapsed:Float) {
		if (FlxG.sound.music != null) {
			Conductor.songPosition += FlxG.elapsed * 1000;
		}

		if (FlxG.keys.justPressed.F)
		{
			FlxG.fullscreen = !FlxG.fullscreen;
		}

		if(curBeat >= 2)
			pressedEnter = FlxG.keys.justPressed.ENTER;

		#if mobile
		for (touch in FlxG.touches.list)
		{
			if (touch.justPressed)
			{
				pressedEnter = true;
			}
		}
		#end

		var gamepad:FlxGamepad = FlxG.gamepads.lastActive;

		if (gamepad != null)
		{
			if (gamepad.justPressed.START)
				pressedEnter = true;

			if (gamepad.justPressed.B)
				pressedEnter = true;
		}

		if (pressedEnter && !transitioning && skippedIntro)
		{
			if(titleText.exists) {
				titleText.animation.play('press');
			}

			FlxG.camera.flash(FlxColor.WHITE, 1);
			FlxG.sound.play(Paths.sound('confirmMenu'), 0.7);

			transitioning = true;
			// FlxG.sound.music.stop();

			new FlxTimer().start(2, function(tmr:FlxTimer)
			{
				FlxG.switchState(new MainMenuState(true));
			});
		}

		if (pressedEnter && !skippedIntro && initialized)
		{
			skipIntro();
		}

		super.update(elapsed);
	}

	override function stepHit() {
		super.stepHit();

		if ((FlxG.sound.music.time > Conductor.songPosition + 20 || FlxG.sound.music.time < Conductor.songPosition - 20)) {
			Conductor.songPosition = FlxG.sound.music.time;
		}
	}

	function createCoolText(textArray:Array<String>):Void {
		for (i in 0...textArray.length) {
			var money:Alphabet = new Alphabet(0, 0, textArray[i], true, false);
			money.screenCenter(X);
			money.y += (i * 60) + 200;
			credGroup.add(money);
			textGroup.add(money);
		}
	}

	function addMoreText(text:String):Void {
		var coolText:Alphabet = new Alphabet(0, 0, text, true, false);
		coolText.screenCenter(X);
		coolText.y += (textGroup.length * 60) + 200;
		credGroup.add(coolText);
		textGroup.add(coolText);
	}

	function addMultipleText(textArray:Array<String>):Void {
		var index:Int = 0;

		while(index < textArray.length) {
			addMoreText(textArray[index++]);
		}
	}

	function deleteCoolText()
	{
		while (textGroup.members.length > 0)
		{
			credGroup.remove(textGroup.members[0], true);
			textGroup.remove(textGroup.members[0], true);
		}
	}

	override function beatHit()
	{
		super.beatHit();

		danceLeft = !danceLeft;

		if(gfDance.exists) {
			if (danceLeft)
				gfDance.animation.play('danceRight');
			else
				gfDance.animation.play('danceLeft');
		}

		if(logoBl.exists) {
			logoBl.animation.play('bump');
		}

		FlxG.log.add(curBeat);

		if(credGroup.exists || textGroup.exists) {
			if(curBeat < Paths.modJSON.title_menu.waky.length) {
				if(Paths.modJSON.title_menu.waky[curBeat].addon) {
					addMultipleText(Paths.modJSON.title_menu.waky[curBeat].texts);
				}else {
					if(Paths.modJSON.title_menu.waky[curBeat].texts.length > 0) {
						deleteCoolText();
					}

					createCoolText(Paths.modJSON.title_menu.waky[curBeat].texts);
				}
			}else if(curBeat - (Paths.modJSON.title_menu.waky.length - 1) < Paths.modJSON.title_menu.random_waky.length) {
				var thisBeat:Int = curBeat - (Paths.modJSON.title_menu.waky.length - 1);

				deleteCoolText();
				createCoolText(Paths.modJSON.title_menu.random_waky[FlxG.random.int(0, Paths.modJSON.title_menu.random_waky.length-1)]);
			}else {
				skipIntro();
			}
		}
	}

	var skippedIntro:Bool = false;

	function skipIntro():Void
	{
		if (!skippedIntro)
		{
			remove(ngSpr);

			FlxG.camera.flash(FlxColor.WHITE, 4);
			remove(credGroup);
			skippedIntro = true;

			callLua("onSkipIntro", []);
		}
	}

	inline function sortByShit(str1:String, str2:String):Int {
		return FlxSort.byValues(FlxSort.ASCENDING, str1.length, str2.length);
	}	
}