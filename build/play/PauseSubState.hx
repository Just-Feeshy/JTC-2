package play;

import Controls.KeyboardScheme;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.sound.FlxSound;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;

import SaveData.SaveType;

class PauseSubState extends MusicBeatSubstate
{
	private static inline var PAUSE_LUA_SCRIPT:String = "jtc_pause";

	private var doneHover:Bool;
	private var otherStuff:FlxText;
	private var levelInfo:FlxText;
	private var levelDifficulty:FlxText;
	private var bg:FlxSprite;
	private var pauseLua:ModLua;
	private var usePauseLua:Bool;

	var grpMenuShit:FlxTypedGroup<Alphabet>;

	var menuItems:Array<String> = ['Resume', 'Restart Song', 'Change Controls', 'Exit to menu'];
	var curSelected:Int = 0;

	var pauseMusic:FlxSound;

	private function cleanupPauseMusic():Void
	{
		if (pauseMusic == null)
			return;

		pauseMusic.stop();

		if (FlxG.sound.list != null)
			FlxG.sound.list.remove(pauseMusic);

		pauseMusic.destroy();
		pauseMusic = null;
	}

	public function new(x:Float, y:Float)
	{
		super();
		usePauseLua = shouldUsePauseLua();

		pauseMusic = new FlxSound().loadEmbedded(Paths.music('breakfast'), true, true);
		pauseMusic.volume = 0;
		pauseMusic.play(false, FlxG.random.int(0, Std.int(pauseMusic.length / 2)));

		FlxG.sound.list.add(pauseMusic);

		bg = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bg.alpha = 0;
		bg.scrollFactor.set();
		add(bg);

		levelInfo = new FlxText(20, usePauseLua ? 0 : 15, 0, "", 32);
		levelInfo.text += PlayState.SONG.song;
		levelInfo.scrollFactor.set();
		levelInfo.setFormat(Paths.font(usePauseLua ? "PhantomMuff.ttf" : "vcr.ttf"), 32);
		levelInfo.updateHitbox();
		if(usePauseLua) {
			levelInfo.y = FlxG.height - levelInfo.height - (15 + 96);
		}
		add(levelInfo);

		levelDifficulty = new FlxText(20, usePauseLua ? FlxG.height - (15 + 32) : 15 + 32, 0, "", 32);
		levelDifficulty.text += usePauseLua ? CoolUtil.difficultyString() : CoolUtil.difficultyString().toUpperCase();
		levelDifficulty.scrollFactor.set();
		levelDifficulty.setFormat(Paths.font(usePauseLua ? "PhantomMuff.ttf" : "vcr.ttf"), 32);
		levelDifficulty.updateHitbox();
		if(usePauseLua) {
			levelDifficulty.y = FlxG.height - levelDifficulty.height - levelInfo.height - 10;
		}
		add(levelDifficulty);

		otherStuff = new FlxText(20, usePauseLua ? 15 : 15 + 96, 0, "", 32);
		otherStuff.scrollFactor.set();
		otherStuff.setFormat(Paths.font(usePauseLua ? "PhantomMuff.ttf" : "vcr.ttf"), 32);
		otherStuff.updateHitbox();
		if(usePauseLua) {
			otherStuff.y = FlxG.height - otherStuff.height - 15;
		}
		add(otherStuff);

		levelDifficulty.alpha = 0;
		levelInfo.alpha = 0;
		otherStuff.alpha = 0;

		if(!usePauseLua) {
			levelInfo.x = FlxG.width - (levelInfo.width + 20);
			levelDifficulty.x = FlxG.width - (levelDifficulty.width + 20);
			otherStuff.x = FlxG.width - (otherStuff.width + 20);

			FlxTween.tween(bg, {alpha: 0.6}, 0.4 * (Conductor.instance.activeBpm / 120), {ease: FlxEase.quadOut});
			FlxTween.tween(levelInfo, {alpha: 1, y: 20}, 0.4 * (Conductor.instance.activeBpm / 120), {ease: FlxEase.quadOut, startDelay: 0.3});
			FlxTween.tween(levelDifficulty, {alpha: 1, y: levelDifficulty.y + 5}, 0.4 * (Conductor.instance.activeBpm / 120), {ease: FlxEase.quadOut, startDelay: 0.5});
		}

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

	override function create():Void
	{
		super.create();
		loadPauseLua();
	}

	override function update(elapsed:Float) {
		if (pauseMusic.volume < 0.5)
			pauseMusic.volume += 0.01 * elapsed;

		super.update(elapsed);

		if(pauseLua != null) {
			pauseLua.set("curElapsed", elapsed);
			pauseLua.call("onUpdate", [elapsed]);
		}

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

			if(pauseLua != null) {
				pauseLua.call("onOptionConfirmed", [daSelected, curSelected]);
			}

			switch (daSelected)
			{
				case "Resume":
					cleanupPauseMusic();

					close();
				case "Restart Song":
					cleanupPauseMusic();

					var playState:PlayState = Std.isOfType(_parentState, PlayState) ? cast _parentState : null;

					if(playState != null) {
						playState.requestSongRestart();
					}

					close();
				case "Exit to menu":
					cleanupPauseMusic();

					var playState:PlayState = Std.isOfType(_parentState, PlayState) ? cast _parentState : null;

					if(playState != null) {
						playState.requestPauseExitToMenu();
					}

					close();
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

					if(!usePauseLua) {
						otherStuff.x = FlxG.width - (otherStuff.width + 20);
					}
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
		if(pauseLua != null) {
			pauseLua.call("onDestroy", []);
			Register.detachLuaFromState(PauseSubState);
			pauseLua = null;
		}

		cleanupPauseMusic();

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

		if(menuItems[curSelected] == "Change Controls") {
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
		}

		if(!usePauseLua) {
			otherStuff.x = FlxG.width - (otherStuff.width + 20);
		}

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

		if(pauseLua != null) {
			pauseLua.set("curSelected", curSelected);
			pauseLua.call("onSelectionChange", [curSelected]);
		}
	}

	function loadPauseLua():Void
	{
		#if (USING_LUA && cpp)
		if(pauseLua != null) {
			return;
		}

		var scriptPath = Paths.getPath('scripts/$PAUSE_LUA_SCRIPT.lua', TEXT, null);
		if(!Paths.assetExists(scriptPath, TEXT)) {
			return;
		}

		if(!HelperStates.luaExist(PauseSubState)) {
			Register.attachLuaToState(PauseSubState, Paths.lua(PAUSE_LUA_SCRIPT));
		}

		pauseLua = HelperStates.getLua(PauseSubState);

		if(pauseLua == null) {
			return;
		}

		pauseLua.luaSprites.set("pauseBackground", bg);
		pauseLua.luaTexts.set("pauseLevelInfo", levelInfo);
		pauseLua.luaTexts.set("pauseLevelDifficulty", levelDifficulty);
		pauseLua.luaTexts.set("pauseOtherStuff", otherStuff);
		pauseLua.execute();

		pauseLua.addCallback("addPauseSprite", function(name:String) {
			var spr = pauseLua.getSprite(name);
			if(spr != null && members.indexOf(spr) < 0) {
				add(spr);
			}
		});

		pauseLua.addCallback("insertPauseSprite", function(position:Int, name:String) {
			var spr = pauseLua.getSprite(name);
			if(spr != null && members.indexOf(spr) < 0) {
				insert(position, spr);
			}
		});

		pauseLua.addCallback("addPauseText", function(name:String) {
			var txt = pauseLua.getText(name);
			if(txt != null && members.indexOf(txt) < 0) {
				add(txt);
			}
		});

		pauseLua.addCallback("setDefaultPauseMenuVisible", function(visible:Bool) {
			if(grpMenuShit != null) {
				grpMenuShit.visible = visible;
			}
		});

		pauseLua.addCallback("getPauseSelection", function() {
			return curSelected;
		});

		pauseLua.addCallback("getPauseMenuLength", function() {
			return menuItems.length;
		});

		pauseLua.addCallback("getPauseOptionName", function(index:Int) {
			if(index < 0 || index >= menuItems.length) {
				return null;
			}

			return menuItems[index];
		});

		pauseLua.addCallback("getPauseMusicVolume", function() {
			return pauseMusic != null ? pauseMusic.volume : 0;
		});
		pauseLua.set("curSelected", curSelected);
		pauseLua.set("pauseSongName", PlayState.SONG.song);
		pauseLua.set("pauseDifficultyName", CoolUtil.difficultyString().toUpperCase());
		pauseLua.call("onCreate", []);
		#end
	}

	private function shouldUsePauseLua():Bool
	{
		#if (USING_LUA && cpp)
		var scriptPath = Paths.getPath('scripts/$PAUSE_LUA_SCRIPT.lua', TEXT, null);
		return Paths.assetExists(scriptPath, TEXT);
		#else
		return false;
		#end
	}
}
