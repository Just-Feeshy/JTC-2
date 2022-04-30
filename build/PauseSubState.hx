package;

import Controls.KeyboardScheme;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxSubState;
import flixel.addons.transition.FlxTransitionableState;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.input.keyboard.FlxKey;
import flixel.system.FlxSound;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;

import SaveData.SaveType;

class PauseSubState extends MusicBeatSubstate
{
	private var doneHover:Bool;
	private var otherStuff:FlxText;

	var grpMenuShit:FlxTypedGroup<Alphabet>;

	var menuItems:Array<String> = ['Resume', 'Restart Song', 'Change Controls', 'Exit to menu'];
	var curSelected:Int = 0;

	var pauseMusic:FlxSound;

	public function new(x:Float, y:Float)
	{
		super();

		pauseMusic = new FlxSound().loadEmbedded(Paths.music('breakfast'), true, true);
		pauseMusic.volume = 0;
		pauseMusic.play(false, FlxG.random.int(0, Std.int(pauseMusic.length / 2)));

		FlxG.sound.list.add(pauseMusic);

		var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bg.alpha = 0;
		bg.scrollFactor.set();
		add(bg);

		var levelInfo:FlxText = new FlxText(20, 15, 0, "", 32);
		levelInfo.text += PlayState.SONG.song;
		levelInfo.scrollFactor.set();
		levelInfo.setFormat(Paths.font("vcr.ttf"), 32);
		levelInfo.updateHitbox();
		add(levelInfo);

		var levelDifficulty:FlxText = new FlxText(20, 15 + 32, 0, "", 32);
		levelDifficulty.text += CoolUtil.difficultyString();
		levelDifficulty.scrollFactor.set();
		levelDifficulty.setFormat(Paths.font('vcr.ttf'), 32);
		levelDifficulty.updateHitbox();
		add(levelDifficulty);


		otherStuff = new FlxText(20, 15 + 96, 0, "", 32);
		
		switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
			case 0:
				otherStuff.text = "SCHEME: "+"WASD";
			case 1:
				otherStuff.text = "SCHEME: "+"DFJK";
			case 2:
				otherStuff.text = "SCHEME: "+"ZX12";
			case 3:
				otherStuff.text = "SCHEME: "+"CUSTOM";
		}

		otherStuff.scrollFactor.set();
		otherStuff.setFormat(Paths.font('vcr.ttf'), 32);
		otherStuff.updateHitbox();
		add(otherStuff);

		levelDifficulty.alpha = 0;
		levelInfo.alpha = 0;
		otherStuff.alpha = 0;

		levelInfo.x = FlxG.width - (levelInfo.width + 20);
		levelDifficulty.x = FlxG.width - (levelDifficulty.width + 20);
		otherStuff.x = FlxG.width - (otherStuff.width + 20);

		FlxTween.tween(bg, {alpha: 0.6}, 0.4, {ease: FlxEase.quartInOut});
		FlxTween.tween(levelInfo, {alpha: 1, y: 20}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0.3});
		FlxTween.tween(levelDifficulty, {alpha: 1, y: levelDifficulty.y + 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0.5});

		grpMenuShit = new FlxTypedGroup<Alphabet>();
		add(grpMenuShit);

		for (i in 0...menuItems.length)
		{
			var songText:Alphabet = new Alphabet(0, (70 * i) + 30, menuItems[i], true, false);
			songText.isMenuItem = true;
			songText.targetY = i;
			grpMenuShit.add(songText);
		}

		changeSelection();

		cameras = [PlayState.camHUD];
	}

	override function update(elapsed:Float) {
		if (pauseMusic.volume < 0.5)
			pauseMusic.volume += 0.01 * elapsed;

		super.update(elapsed);

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

		if (accepted || FlxG.mouse.justPressed)
		{
			var daSelected:String = menuItems[curSelected];

			switch (daSelected)
			{
				case "Resume":
					close();
				case "Restart Song":
					FlxG.resetState();
				case "Exit to menu":
					Compile.kill();
					FlxG.switchState(new MainMenuState());
				case "Change Controls":
					FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);

					FlxG.save.data.dfjk += 1;

					if (FlxG.save.data.dfjk > 3)
						FlxG.save.data.dfjk = 0;

					switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
						case 0:
							controls.setKeyboardScheme(KeyboardScheme.Duo(true), true);
						case 1:
							controls.setKeyboardScheme(KeyboardScheme.Solo, true);
						case 2:
							controls.setKeyboardScheme(KeyboardScheme.Duo(false), true);
						case 3:
							controls.setKeyboardScheme(KeyboardScheme.Custom, true);
					}

					switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
						case 0:							
							otherStuff.text = "SCHEME: "+"WASD";
						case 1:
							otherStuff.text = "SCHEME: "+"DFJK";
						case 2:
							otherStuff.text = "SCHEME: "+"ZX12";
						case 3:
							otherStuff.text = "SCHEME: "+"CUSTOM";
					}

					otherStuff.x = FlxG.width - (otherStuff.width + 20);
			}
		}

		if(menuItems[curSelected] == "Change Controls") {
			if(!doneHover) {
				doneHover = true;
				FlxTween.tween(otherStuff, {alpha: 1, y: otherStuff.y - 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0});
			}
		}else{
			if(doneHover) {
				doneHover = false;
				FlxTween.tween(otherStuff, {alpha: 0, y: otherStuff.y + 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0});
			}
		}
	}

	override function destroy()
	{
		pauseMusic.destroy();

		super.destroy();
	}

	function changeSelection(change:Int = 0):Void
	{
		curSelected += change;

		FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);

		if (curSelected < 0)
			curSelected = menuItems.length - 1;
		if (curSelected >= menuItems.length)
			curSelected = 0;

		var bullShit:Int = 0;

		for (item in grpMenuShit.members)
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
	}
}