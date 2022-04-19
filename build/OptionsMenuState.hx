package;

import Controls.Control;
import Controls.KeyboardScheme;
import flixel.input.keyboard.FlxKey;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.group.FlxSpriteGroup.FlxTypedSpriteGroup;
import flixel.system.FlxAssets.FlxShader;
import flixel.util.FlxDestroyUtil;
import flixel.FlxSubState;
import flixel.FlxSprite;
import flixel.math.FlxMath;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxTimer;
import flixel.util.FlxColor;
import betterShit.BetterCams;
import openfl.Lib;

import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.ShaderFilter;

import feshixl.filters.GuassianBlur;

import SaveData.SaveType;

using StringTools;

/**
* Scratched Idea
**/
private typedef OptionSystem = {
    catagory:String,
    options:Array<Options>
}

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

class OptionsMenuState extends MusicBeatState {
	final imNotSure:Int = 10;

	private var camBackground:BetterCams;
	private var camNoBlur:BetterCams;
	private var camSubState:BetterCams;

	private var blurEffect:GuassianBlur;

	private var optionList:Array<OptionSystem>;
	private var curOptionSection:FlxTypedSpriteGroup<Options>;

	private var optionSetting:FlxTypedGroup<Alphabet>;

	private var curCatalog:Int = 0;
	private var curSelected:Int = 0;

	private var shouldPress:Bool = false;
	private var isChangingOption:Bool = false;

	private var changeBlur:Bool = false;

	private var settingTxt:String = "";

    override public function create():Void {
		FlxG.mouse.visible = true;

		SaveData.saveClient();

        camBackground = new BetterCams();
        camNoBlur = new BetterCams();
		camSubState = new BetterCams();
        camBackground.bgColor.alpha = 0;
        camNoBlur.bgColor.alpha = 0;
		camSubState.bgColor.alpha = 0;

        FlxG.cameras.reset(camBackground);
        FlxG.cameras.add(camNoBlur);
		FlxG.cameras.add(camSubState);

		camNoBlur.zoom = 0.9;

        FlxCamera.defaultCameras = [camBackground];

		curOptionSection = new FlxTypedSpriteGroup<Options>();

		optionList = [
			{
				catagory: "Everything",
				options: [
					new Options(0, 10, "Custom Keybinds", SaveType.CUSTOM_KEYBINDS, function(option:Options, pressed:Bool) {
						option.ID = 0;

						if(option.optionIcon.animation.curAnim.name != "other")
							option.optionIcon.animation.play("other");
						
						if(pressed) {
							option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
							option.optionSubState = OptionsSubState.newSubState(SaveType.CUSTOM_KEYBINDS);
							option.optionSubState.cameras = [camSubState];

							openSubStateBlur(option.optionSubState);
						}

						setting(option, "", option.ID);
					}),
					new Options(0, 20, "Preset Keybinds", SaveType.PRESET_KEYBINDS, function(option:Options, pressed:Bool) {
						option.ID = 1;

						if(option.optionIcon.animation.curAnim.name != "other")
							option.optionIcon.animation.play("other");

						if(pressed) {
							FlxG.save.data.dfjk += 1;
							setControls(option, option.ID);
						}else {
							setControls(option, option.ID);
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 30, "Minimal FPS Cap", SaveType.SET_FPS_DEFAULT, function(option:Options, pressed:Bool) {
						option.ID = 2;

						if(option.optionIcon.animation.curAnim.name != "other")
							option.optionIcon.animation.play("other");

						if(pressed) {
							FlxG.save.data.lowFps += 10;

							if(FlxG.save.data.lowFps > 100)
								FlxG.save.data.lowFps = 60;
							
							Lib.current.stage.frameRate = FlxG.save.data.lowFps * SaveData.getData(SaveType.FPS_MULTIPLIER);
							Main.framerate = FlxG.save.data.lowFps;
						}

						setting(option, Std.string(FlxG.save.data.lowFps), option.ID);

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 40, "Multiply FPS", SaveType.FPS_MULTIPLIER, function(option:Options, pressed:Bool) {
						option.ID = 3;

						if(option.optionIcon.animation.curAnim.name != "other")
							option.optionIcon.animation.play("other");

						if(pressed) {
							FlxG.save.data.fpsMulti += 1;

							if(FlxG.save.data.fpsMulti > 9)
								FlxG.save.data.fpsMulti = 1;

							Lib.current.stage.frameRate = FlxG.save.data.lowFps * SaveData.getData(SaveType.FPS_MULTIPLIER);
							Main.framerate = FlxG.save.data.lowFps;
						}

						setting(option, Std.string(FlxG.save.data.fpsMulti), option.ID);

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 50, "Complex Inputs", SaveType.PRESET_INPUTS, function(option:Options, pressed:Bool) {
						option.ID = 4;

						if(pressed)
							FlxG.save.data.simpInputs = !FlxG.save.data.simpInputs;

						if(!SaveData.getData(SaveType.PRESET_INPUTS)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play ("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 60, "Downscroll", SaveType.DOWNSCROLL, function(option:Options, pressed:Bool) {
						option.ID = 5;

						if(pressed)
							FlxG.save.data.helpme = !FlxG.save.data.helpme;

						if(!SaveData.getData(SaveType.DOWNSCROLL)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 70, "Note Splash", SaveType.SHOW_NOTE_SPLASH, function(option:Options, pressed:Bool) {
						option.ID = 6;

						if(pressed)
							FlxG.save.data.showEffect = !FlxG.save.data.showEffect;

						if(!SaveData.getData(SaveType.SHOW_NOTE_SPLASH)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 80, "Show Accuracy", SaveType.SHOW_BOTTOM_BAR, function(option:Options, pressed:Bool) {
						option.ID = 7;

						if(pressed)
							FlxG.save.data.showstuff = !FlxG.save.data.showstuff;

						if(!SaveData.getData(SaveType.SHOW_BOTTOM_BAR)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 90, "High Graphics", SaveType.GRAPHICS, function(option:Options, pressed:Bool) {
						option.ID = 8;

						if(pressed)
							FlxG.save.data.showAntialiasing = !FlxG.save.data.showAntialiasing;

						if(!SaveData.getData(SaveType.GRAPHICS)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, 100, "Cache Assets", SaveType.CACHE_ASSETS, function(option:Options, pressed:Bool) {
						option.ID = 9;

						if(pressed)
							FlxG.save.data.preload = !FlxG.save.data.preload;

						if(!SaveData.getData(SaveType.CACHE_ASSETS)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new GhostTapping(0, 110, "Ghost Tapping", SaveType.GHOST_TAPPING, function(option:Options, pressed:Bool) {
						option.ID = 10;

						if(pressed)
							FlxG.save.data.ghostTapping = !FlxG.save.data.ghostTapping;

						if(!SaveData.getData(SaveType.GHOST_TAPPING)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("on");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 1) * 10) + 60, "Modifiers", SaveType.NONE, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 1;

						option.optionIcon.kill();
						option.optionTitle = true;
						setting(option, "", option.ID);
					}),
					new Options(0, ((imNotSure + 1) * 10) + 120, "Opposite Chart", SaveType.FLIP_CHART_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 2;

						if(pressed)
							FlxG.save.data.flip = !FlxG.save.data.flip;

						if(!SaveData.getData(SaveType.FLIP_CHART_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 2) * 10) + 120, "Custom Hell", SaveType.CUSTOM_HELL_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 3;

						if(pressed)
							FlxG.save.data.customhell = !FlxG.save.data.customhell;

						if(!SaveData.getData(SaveType.CUSTOM_HELL_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 3) * 10) + 120, "Get Good Scrub", SaveType.PERFECT_MODE_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 4;

						if(pressed)
							FlxG.save.data.perfectMode = !FlxG.save.data.perfectMode;

						if(!SaveData.getData(SaveType.PERFECT_MODE_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 4) * 10) + 120, "Both Health Gain", SaveType.FAIR_BATTLE_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 5;

						if(pressed)
							FlxG.save.data.fair = !FlxG.save.data.fair;

						if(!SaveData.getData(SaveType.FAIR_BATTLE_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 5) * 10) + 120, "Fade In Notes", SaveType.FADE_BATTLE_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 6;

						if(pressed)
							FlxG.save.data.fade = !FlxG.save.data.fade;

						if(!SaveData.getData(SaveType.FADE_BATTLE_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 6) * 10) + 120, "No Blue Balls", SaveType.NO_BLUE_BALLS_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 7;

						if(pressed)
							FlxG.save.data.safeballs = !FlxG.save.data.safeballs;

						if(!SaveData.getData(SaveType.NO_BLUE_BALLS_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 7) * 10) + 120, "Simon Says", SaveType.BLIND_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 8;

						if(pressed)
							FlxG.save.data.blind = !FlxG.save.data.blind;

						if(!SaveData.getData(SaveType.BLIND_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					}),
					new Options(0, ((imNotSure + 8) * 10) + 120, "Wobbly Notes", SaveType.X_WOBBLE_MOD, function(option:Options, pressed:Bool) {
						option.ID = imNotSure + 9;

						if(pressed)
							FlxG.save.data.xWobble = !FlxG.save.data.xWobble;

						if(!SaveData.getData(SaveType.X_WOBBLE_MOD)) {
							setting(option, "Off", option.ID);
							option.optionIcon.animation.play("off");
						}else {
							setting(option, "On", option.ID);
							option.optionIcon.animation.play("modifier");
						}

						if(pressed)
							isChangingOption = false;
					})
				]
			}
		];

		setCat(curCatalog);

        camBackground.setFilters([new BlurFilter(15, 15, BitmapFilterQuality.LOW), new ShaderFilter(new StupidVibeShader(1.5))]);

		add(curOptionSection);

		blurEffect = new GuassianBlur(0);
		camNoBlur.setFilters([new ShaderFilter(blurEffect)]);

        if(Paths.modJSON.main_menu.background_image != '') {
			var bg:FlxSprite = new FlxSprite().loadGraphic(Paths.image(Paths.modJSON.main_menu.background_image));
			bg.setGraphicSize(1280, 720);
			bg.updateHitbox();
			bg.screenCenter();
			bg.scrollFactor.set(0.1);
			add(bg);
		}else {
			var bg:FlxSprite = new FlxSprite(-100, -15).loadGraphic(Paths.image('menu/sky2'));
			bg.scrollFactor.set();
			add(bg);

			var city:FlxSprite = new FlxSprite(-10, -15).loadGraphic(Paths.image('menu/city'));
			city.scrollFactor.set(0.1);
			city.updateHitbox();
			city.screenCenter();
			add(city);

			var light:FlxSprite = new FlxSprite(city.x, city.y).loadGraphic(Paths.image('menu/win2'));
			light.scrollFactor.set(0.1);
			light.updateHitbox();
			light.screenCenter();
			add(light);

			var streetBehind:FlxSprite = new FlxSprite(-40, -50).loadGraphic(Paths.image('menu/behindTrain'));
			streetBehind.scrollFactor.set();
			add(streetBehind);

			var street:FlxSprite = new FlxSprite(-40, streetBehind.y).loadGraphic(Paths.image('menu/street'));
			street.scrollFactor.set(0.1);
			add(street);
		}

		curOptionSection.cameras = [camNoBlur];

		shouldPress = true;

		super.create();
    }

	function setControls(option:Options, id:Int):Void {
		if (FlxG.save.data.dfjk > 3)
			FlxG.save.data.dfjk = 0;

		switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
			case 0:
				controls.setKeyboardScheme(KeyboardScheme.Duo(true), true);
				setting(option, "W A S D", id);
			case 1:
				controls.setKeyboardScheme(KeyboardScheme.Solo, true);
				setting(option, "D F J K", id);
			case 2:
				controls.setKeyboardScheme(KeyboardScheme.Duo(false), true);
				setting(option, "Z X 1 2", id);
			case 3:
				controls.setKeyboardScheme(KeyboardScheme.Custom, true);
				setting(option, "CUSTOM", id);
		}
	}

	function changeSelection(change:Int = 0):Void {
		FlxG.sound.play(Paths.sound('scrollMenu'), 0.4);

		curSelected += change;

		if (curSelected < 0)
			curSelected = optionList[curCatalog].options.length - 1;
		if (curSelected >= optionList[curCatalog].options.length)
			curSelected = 0;

		var bullShit:Int = 0;

		curOptionSection.forEach(function(option:Options) {
			if(option.optionTitle && option.ID == curSelected) {
				curSelected += change;

				if (curSelected < 0)
					curSelected = optionList[curCatalog].options.length - 1;
				if (curSelected >= optionList[curCatalog].options.length)
					curSelected = 0;

				return;
			}
		});

		for(i in 0...curOptionSection.length) {
			var item:Options = curOptionSection.members[i];

			item.targetY = bullShit - curSelected;
			bullShit++;

			item.alpha = 0.6;

			if (item.targetY == 0 || item.optionTitle)
				item.alpha = 1;
		}
	}

	function setting(option:Options, display:String, id:Int):Void {
		if(optionSetting == null) {
			optionSetting = new FlxTypedGroup<Alphabet>();
			add(optionSetting);
		}

		var optionS:Alphabet = new Alphabet(0, 0, display, false, false, 840);
		optionS.ID = id;
		optionS.cameras = [camNoBlur];
		optionSetting.add(optionS);
	}

	function setCat(catagory:Int):Void {
		curOptionSection.clear();

		for(i in 0...optionList[catagory].options.length) {
			if(i != 0)optionList[catagory].options[i].alpha = 0.6;
			optionList[catagory].options[i].targetY = i;
			curOptionSection.add(optionList[catagory].options[i]);
		}
	}

	public function openSubStateBlur(SubState:FlxSubState):Void {
		changeBlur = true;

		FlxTween.tween(blurEffect, {size: 20}, 0.75, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			openSubState(SubState);
			changeBlur = false;
		}});
	}

	override public function closeSubState() {
		isChangingOption = false;
		FlxTween.tween(blurEffect, {size: 0}, 0.75, {ease: FlxEase.quadOut});

		super.closeSubState();
	}

	override public function update(elapsed:Float):Void {
		super.update(elapsed);

		var upP = controls.UP_P;
		var downP = controls.DOWN_P;
		var accepted = controls.ACCEPT;
		var escaped = controls.BACK;

		if((upP || FlxG.mouse.wheel > 0.1) && !isChangingOption)
			changeSelection(-1);
		if((downP || FlxG.mouse.wheel < -0.1) && !isChangingOption)
			changeSelection(1);

		if(accepted && !isChangingOption) {
			isChangingOption = true;
			
			settingTxt = "";

			remove(optionSetting);
			optionSetting = FlxDestroyUtil.destroy(optionSetting);

			for(i in 0...optionList[curCatalog].options.length) {
				var item:Options = optionList[curCatalog].options[i];

				if (item.targetY == 0)
					item.callback(item, true);
				else
					item.callback(item, false);
			}
		}

		if(escaped && !isChangingOption) {
			FlxG.switchState(new MainMenuState());
		}

		if(optionSetting != null) {
			curOptionSection.forEach(function(option:Options) {
				optionSetting.members[option.ID].x = option.x;
				optionSetting.members[option.ID].y = option.optionIcon.y - (optionSetting.members[option.ID].height / 2) + 5;
			});	
		}
	}
}