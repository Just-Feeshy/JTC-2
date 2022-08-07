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
	final imNotSure:Int = 0;

	private var bar:FlxSprite;
	private var displayDescription:FlxText;

	private var camBackground:BetterCams;
	private var camNoBlur:BetterCams;
	private var camSubState:BetterCams;

	private var blurEffect:GuassianBlur;

	private var optionList:Array<OptionSystem>;
	private var allTweens:Array<FlxTween>;
	private var curOptionSection:FlxTypedSpriteGroup<Options>;

	private var optionSetting:FlxTypedGroup<Alphabet>;

	private var curCatalog:Int = 0;
	private var curSelected:Int = 0;

	private var extra:Int = 0;

	private var shouldPress:Bool = false;
	private var isChangingOption:Bool = false;

	private var changeBlur:Bool = false;

	private var settingTxt:String = "";

	private var catalog:String;

	public function new(?catalog:String = "none") {
		this.catalog = catalog;

		super();
	}

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

		#if !mobile
		extra += 20;
		#end

		persistentUpdate = persistentDraw = true;

		switch(this.catalog) {
			case "game": {
				optionList = [
					{
						catagory: this.catalog,
						options: [
							new Options(0, 0, "Custom Key Binds", SaveType.CUSTOM_KEYBINDS, function(option:Options, pressed:Bool) {
								option.ID = 0;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");
								
								if(pressed) {
									option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
									option.optionSubState = OptionsSubState.newSubState(SaveType.CUSTOM_KEYBINDS);
									option.optionSubState.cameras = [camSubState];

									openSubStateCustom(option.optionSubState);
								}

								option.description = "Change the key bindings to the main game.";
								setting(option, "", option.ID);
							}),
							new Options(0, 10, "Custom UI Key Binds", SaveType.CUSTOM_KEYBINDS, function(option:Options, pressed:Bool) {
								option.ID = 1;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");
								
								if(pressed) {
									option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
									option.optionSubState = OptionsSubState.newSubState(SaveType.CUSTOM_UI_KEYBINDS);
									option.optionSubState.cameras = [camSubState];

									openSubStateCustom(option.optionSubState);
								}

								option.description = "Change the key bindings to UI navigation. (Don't recommend)";
								setting(option, "", option.ID);
							}),
							new Options(0, 20, "Preset Key Binds", SaveType.PRESET_KEYBINDS, function(option:Options, pressed:Bool) {
								option.ID = 2;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								option.description = "Switch through preset key bindings to use for the main game.";

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
								option.ID = 3;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed) {
									FlxG.save.data.lowFps += 10;

									if(FlxG.save.data.lowFps > 100)
										FlxG.save.data.lowFps = 60;
									
									Lib.current.stage.frameRate = FlxG.save.data.lowFps * SaveData.getData(SaveType.FPS_MULTIPLIER);
									Main.framerate = FlxG.save.data.lowFps;
								}

								option.description = "I don't know why I have the cap at 100.";
								setting(option, Std.string(FlxG.save.data.lowFps), option.ID);

								if(pressed)
									isChangingOption = false;
							}),
							new Options(0, 40, "Multiply FPS", SaveType.FPS_MULTIPLIER, function(option:Options, pressed:Bool) {
								option.ID = 4;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed) {
									FlxG.save.data.fpsMulti += 1;

									if(FlxG.save.data.fpsMulti > 9)
										FlxG.save.data.fpsMulti = 1;

									Lib.current.stage.frameRate = FlxG.save.data.lowFps * SaveData.getData(SaveType.FPS_MULTIPLIER);
									Main.framerate = FlxG.save.data.lowFps;
								}

								option.description = "Multiply the minimal FPS.";
								setting(option, Std.string(FlxG.save.data.fpsMulti), option.ID);

								if(pressed)
									isChangingOption = false;
							}),
							new Options(0, 50, "Note Offset", SaveType.NOTE_OFFSET, function(option:Options, pressed:Bool) {
								option.ID = 5;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed) {
									option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
									option.optionSubState = OptionsSubState.newSubState(SaveType.NOTE_OFFSET);
									option.optionSubState.cameras = [camSubState];

									openSubStateCustom(option.optionSubState);
								}

								option.description = "Set note offset.";
								setting(option, "", option.ID);
							}),
							#if !mobile
							new Options(0, 60, "FPS Counter", SaveType.SHOW_FPS, function(option:Options, pressed:Bool) {
								option.ID = 6;

								if(pressed)
									FlxG.save.data.showFPS = !FlxG.save.data.showFPS;

								option.description = "Toggle the FPS counter.";

								if(!SaveData.getData(SaveType.SHOW_FPS)) {
									setting(option, "Off", option.ID);
									option.optionIcon.animation.play("off");

									openfl.Lib.current.removeChild(SaveData.globalFPS);
								}else {
									setting(option, "On", option.ID);
									option.optionIcon.animation.play ("on");

									openfl.Lib.current.addChild(SaveData.globalFPS);
								}

								if(pressed)
									isChangingOption = false;
							}),
							new Options(0, 70, "Memory Counter", SaveType.SHOW_MEMORY, function(option:Options, pressed:Bool) {
								option.ID = 7;

								if(pressed)
									FlxG.save.data.showMEM = !FlxG.save.data.showMEM;

								option.description = "Toggle the memory counter.";

								if(!SaveData.getData(SaveType.SHOW_MEMORY)) {
									setting(option, "Off", option.ID);
									option.optionIcon.animation.play("off");

									openfl.Lib.current.removeChild(SaveData.globalMEM);
								}else {
									setting(option, "On", option.ID);
									option.optionIcon.animation.play ("on");

									openfl.Lib.current.addChild(SaveData.globalMEM);
								}

								if(pressed)
									isChangingOption = false;
							}),
							#end
							new Options(0, 60 + extra, "Complex Inputs", SaveType.PRESET_INPUTS, function(option:Options, pressed:Bool) {
								option.ID = 6 + Math.ceil(extra / 10);

								if(pressed)
									FlxG.save.data.simpInputs = !FlxG.save.data.simpInputs;

								option.description = "Toggle to either the regular inputs or indev inputs.";

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
							new Options(0, 70 + extra, "Downscroll", SaveType.DOWNSCROLL, function(option:Options, pressed:Bool) {
								option.ID = 7 + Math.ceil(extra / 10);

								if(pressed)
									FlxG.save.data.helpme = !FlxG.save.data.helpme;

								option.description = "Change the strumline layout.";

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
							new Options(0, 80 + extra, "Note Splash", SaveType.SHOW_NOTE_SPLASH, function(option:Options, pressed:Bool) {
								option.ID = 8 + Math.ceil(extra / 10);

								if(pressed)
									FlxG.save.data.showEffect = !FlxG.save.data.showEffect;

								option.description = "Toggle whether to display the splash effect.";

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
							new Options(0, 90 + extra, "Show Accuracy", SaveType.SHOW_BOTTOM_BAR, function(option:Options, pressed:Bool) {
								option.ID = 9 + Math.ceil(extra / 10);

								if(pressed)
									FlxG.save.data.showstuff = !FlxG.save.data.showstuff;

								option.description = "Toggle whether to display the splash effect.";

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
							new GhostTapping(0, 100 + extra, "Ghost Tapping", SaveType.GHOST_TAPPING, function(option:Options, pressed:Bool) {
								option.ID = 10 + Math.ceil(extra / 10);

								if(pressed)
									FlxG.save.data.ghostTapping = !FlxG.save.data.ghostTapping;

								option.description = "Toggle whether miss tapping should have consequences.";

								if(!SaveData.getData(SaveType.GHOST_TAPPING)) {
									setting(option, "Off", option.ID);
									option.optionIcon.animation.play("off");
								}else {
									setting(option, "On", option.ID);
									option.optionIcon.animation.play("on");
								}

								if(pressed)
									isChangingOption = false;
							})
						]
					}
				];
			}case "graphics": {
				optionList = [
					{
						catagory: this.catalog,
						options: [
							new Options(0, 0, "High Quality", SaveType.GRAPHICS, function(option:Options, pressed:Bool) {
								option.ID = 0;

								if(pressed)
									FlxG.save.data.showAntialiasing = !FlxG.save.data.showAntialiasing;

								option.description = "Enable high-quality mode for a visually pleasing experience.";

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
							new Options(0, 10, "Gamma Correction", SaveType.GAMMA, function(option:Options, pressed:Bool) {
								option.ID = 1;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed) {
									option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
									option.optionSubState = OptionsSubState.newSubState(SaveType.GAMMA);
									option.optionSubState.cameras = [camSubState];

									openSubStateCustom(option.optionSubState);
								}

								option.description = "Change the gamme value for the game/app.";
								setting(option, "", option.ID);
							})
						]
					}
				];
			}
			#if TOGGLEABLE_MODIFIERS
			case "modifiers": {
				optionList = [
					{
						catagory: this.catalog,
						options: [
							new Options(0, ((imNotSure + 0) * 10) + 120, "Custom Hell", SaveType.CUSTOM_HELL_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure;

								if(pressed)
									FlxG.save.data.customhell = !FlxG.save.data.customhell;

								option.description = "Convert every regular note into a random custom note.";

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
							new Options(0, ((imNotSure + 1) * 10) + 120, "Get Good Scrub", SaveType.PERFECT_MODE_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 1;

								if(pressed)
									FlxG.save.data.perfectMode = !FlxG.save.data.perfectMode;

								option.description = "Anything less than a good rating would be instant death.";

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
							new Options(0, ((imNotSure + 2) * 10) + 120, "Mirror Chart", SaveType.FLIP_CHART_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 2;

								if(pressed)
									FlxG.save.data.flip = !FlxG.save.data.flip;

								option.description = "Toggle mirror mode.";

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
							new Options(0, ((imNotSure + 3) * 10) + 120, "Sing Health Drain", SaveType.FAIR_BATTLE_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 3;

								if(pressed)
									FlxG.save.data.fair = !FlxG.save.data.fair;

								option.description = "Drains health when opponent sings.";

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
							new Options(0, ((imNotSure + 4) * 10) + 120, "Fade In Notes", SaveType.FADE_BATTLE_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 4;

								if(pressed)
									FlxG.save.data.fade = !FlxG.save.data.fade;

								if(!SaveData.getData(SaveType.FADE_BATTLE_MOD)) {
									setting(option, "Off", option.ID);
									option.optionIcon.animation.play("off");
								}else {
									setting(option, "On", option.ID);
									option.optionIcon.animation.play("modifier");
								}

								option.description = "Toggle whether notes should have a fade-in effect.";

								if(pressed)
									isChangingOption = false;
							}),
							new Options(0, ((imNotSure + 5) * 10) + 120, "No Blue Balls", SaveType.NO_BLUE_BALLS_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 5;

								if(pressed)
									FlxG.save.data.safeballs = !FlxG.save.data.safeballs;

								option.description = "Toggle immortality";

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
							new Options(0, ((imNotSure + 6) * 10) + 120, "Simon Says", SaveType.BLIND_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 6;

								if(pressed)
									FlxG.save.data.blind = !FlxG.save.data.blind;

								option.description = "Follow your opponent's pattern. Well...";

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
							new Options(0, ((imNotSure + 7) * 10) + 120, "Wobbly Notes", SaveType.X_WOBBLE_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 7;

								if(pressed)
									FlxG.save.data.xWobble = !FlxG.save.data.xWobble;

								option.description = "Notes sway back and forth.";

								if(!SaveData.getData(SaveType.X_WOBBLE_MOD)) {
									setting(option, "Off", option.ID);
									option.optionIcon.animation.play("off");
								}else {
									setting(option, "On", option.ID);
									option.optionIcon.animation.play("modifier");
								}

								if(pressed)
									isChangingOption = false;
							}),
							new Options(0, ((imNotSure + 8) * 10) + 120, "Camera Movement", SaveType.CAMERA_MOVEMENT_MOD, function(option:Options, pressed:Bool) {
								option.ID = imNotSure + 8;

								if(pressed)
									FlxG.save.data.camMove = !FlxG.save.data.camMove;

								option.description = "The camera follows the direction of each singing pose.";

								if(!SaveData.getData(SaveType.CAMERA_MOVEMENT_MOD)) {
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
			}
			#end
			#if (debug || USING_MOD_DEBUG)
			case "editors": {
				optionList = [
					{
						catagory: this.catalog,
						options: [
							new Options(0, 0, "Dialogue Creator", SaveType.NONE, function(option:Options, pressed:Bool) {
								option.ID = 0;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed)
									FlxG.switchState(new DialogueCreatorState());

								option.description = "Dialogue Creator.";
								setting(option, "", option.ID);
							}),
							new Options(0, 10, "Character Creator", SaveType.NONE, function(option:Options, pressed:Bool) {
								option.ID = 1;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed)
									FlxG.switchState(new CharacterCreatorState());

								option.description = "Character Creator.";
								setting(option, "", option.ID);
							})
						]
					}
				];
			}
			#end
			case "none": {
				optionList = [
					{
						catagory: this.catalog,
						options: [
							new Options(0, 0, "Gameplay And Performance", SaveType.NONE, function(option:Options, pressed:Bool) {
								option.ID = 0;

								if(option.optionIcon.animation.curAnim.name != "section")
									option.optionIcon.animation.play("section");

								if(pressed)
									FlxG.switchState(new OptionsMenuState("game"));

								setting(option, "", option.ID);
							}),
							new Options(0, 10, "Graphics And Window", SaveType.NONE, function(option:Options, pressed:Bool) {
								option.ID = 1;

								if(option.optionIcon.animation.curAnim.name != "section")
									option.optionIcon.animation.play("section");

								if(pressed)
									FlxG.switchState(new OptionsMenuState("graphics"));

								setting(option, "", option.ID);
							}),
							new Options(0, 20, "Modifiers", SaveType.NONE, function(option:Options, pressed:Bool) {
								option.ID = 2;

								if(option.optionIcon.animation.curAnim.name != "section")
									option.optionIcon.animation.play("section");

								if(pressed)
									FlxG.switchState(new OptionsMenuState("modifiers"));

								setting(option, "", option.ID);
							}),
							new Options(0, 30, "Erase Save Data", SaveType.CACHE_ASSETS, function(option:Options, pressed:Bool) {
								option.ID = 3;

								if(option.optionIcon.animation.curAnim.name != "other")
									option.optionIcon.animation.play("other");

								if(pressed) {
									option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
									option.optionSubState = OptionsSubState.newSubState(SaveType.ERASE_DATA);
									option.optionSubState.cameras = [camSubState];

									openSubStateCustom(option.optionSubState);
								}

								setting(option, "", option.ID);
							})
							#if (debug || USING_MOD_DEBUG),
							new Options(0, 40, "Dev Tools Stuff", SaveType.NONE, function(option:Options, pressed:Bool) {
								option.ID = 4;

								if(option.optionIcon.animation.curAnim.name != "section")
									option.optionIcon.animation.play("section");

								if(pressed)
									FlxG.switchState(new OptionsMenuState("editors"));

								setting(option, "", option.ID);
							})
							#end
						]
					}
				];
			}default: {
				optionList = [
					{
						catagory: this.catalog,
						options: []
					}
				];
			}
		}
		
		super.create();

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).set("catalog", catalog);
			HelperStates.getLua(Type.getClass(this)).set("listSize", optionList[0].options.length);

			HelperStates.getLua(Type.getClass(this)).addCallback("insertOption", function(name:String, anim:String, index:Int) {
				optionList[0].options.insert(index, new Options(0, index * 10, name, SaveType.NONE, function(option:Options, pressed:Bool) {
					option.ID = index;

					if(option.optionIcon.animation.curAnim.name != anim)
						option.optionIcon.animation.play(anim);

					if(pressed) {
						option.optionSubState = FlxDestroyUtil.destroy(option.optionSubState);
						option.optionSubState = Register.forNameClass(HelperStates.getLua(Type.getClass(this)).call("createOptionSubState", [option.text]), []);

						if(option.optionSubState != null) {
							option.optionSubState.cameras = [camSubState];
							openSubStateCustom(option.optionSubState);
						}
					}

					setting(option, "", option.ID);
				}));

				for(i in index...optionList[0].options.length) {
					optionList[0].options[i].ID = index;
					optionList[0].options[i].y = i * 10;
				}
			});

			HelperStates.getLua(Type.getClass(this)).addCallback("enterOptionState", function(catalog:String) {
				FlxG.switchState(new OptionsMenuState(catalog));
			});
		}
		#end

		super.onCreate();

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

		allTweens = new Array<FlxTween>();
		
		if(this.catalog != "none") {
			bar = new FlxSprite().makeGraphic(Std.int(FlxG.width * 1.25), 45, FlxColor.BLACK);
			bar.y = FlxG.height + bar.height + 10;
			bar.screenCenter(X);
			bar.scrollFactor.set();
			bar.alpha = 0.6;
			add(bar);

			trace(optionList[0].options[0]);

			var description:String = "Description - " + optionList[0].options[0].description;
			displayDescription = new FlxText(0, bar.y, description.toUpperCase(), 32);
			displayDescription.setFormat(Paths.font("OpenSans-Bold.ttf"), 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
			displayDescription.antialiasing = SaveData.getData(SaveType.GRAPHICS);
			displayDescription.x = -displayDescription.width - 5;
			displayDescription.borderSize = 2;
			add(displayDescription);

			bar.cameras = [camNoBlur];
			displayDescription.cameras = [camNoBlur];

			FlxTween.tween(bar, {y: 576}, 0.5, {ease: FlxEase.quadOut});
			FlxTween.tween(displayDescription, {x: 5}, 0.5, {ease: FlxEase.quadOut});
		}

		curOptionSection.cameras = [camNoBlur];

		shouldPress = true;
    }

	override public function onCreate():Dynamic {
		return null;
	}

	function cleanTween() {
        if (allTweens != null) {
            var index:Int = 0;
            var tween:FlxTween = null;

            while (index < allTweens.length) {
                tween = allTweens[index++];

                if (tween != null) {
                    tween.cancel();
                    tween.destroy();
                }

                allTweens.remove(tween);
            }
        }
    }

	function optionLuaCallback(name:String):Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).call("whenOptionPressed", [name]);
		}
		#end
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

			if (item.targetY == 0 || item.optionTitle) {
				if(displayDescription != null)
					displayDescription.text = "Description - " + item.description.toUpperCase();

				item.alpha = 1;
			}
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

	override function openSubStateCustom(SubState:FlxSubState):Void {
		changeBlur = true;

		FlxTween.tween(blurEffect, {size: 20}, 0.75, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
			openSubState(SubState);
			changeBlur = false;
		}});
	}

	override function closeSubState() {
		isChangingOption = false;
		FlxTween.tween(blurEffect, {size: 0}, 0.75, {ease: FlxEase.quadOut});

		super.closeSubState();
	}

	override function update(elapsed:Float):Void {
		super.update(elapsed);

		var upP = controls.UP_P;
		var downP = controls.DOWN_P;
		var accepted = controls.ACCEPT;
		var escaped = controls.BACK;

		if(displayDescription != null)
			displayDescription.y = bar.y;

		if((upP || FlxG.mouse.wheel > 0.1) && !isChangingOption)
			changeSelection(-1);
		if((downP || FlxG.mouse.wheel < -0.1) && !isChangingOption)
			changeSelection(1);

		if((accepted || FlxG.mouse.justPressed) && !isChangingOption) {
			isChangingOption = true;
			
			settingTxt = "";

			remove(optionSetting);
			optionSetting = FlxDestroyUtil.destroy(optionSetting);

			for(i in 0...optionList[curCatalog].options.length) {
				var item:Options = optionList[curCatalog].options[i];

				if (item.targetY == 0) {
					item.callback(item, true);
					optionLuaCallback(item.text);
				}else {
					item.callback(item, false);
				}
			}
		}

		if(escaped && !isChangingOption) {
			switch(catalog) {
				case "none":
					FlxG.switchState(new MainMenuState());
				default:
					FlxG.switchState(new OptionsMenuState());
			}
		}

		if(optionSetting != null) {
			curOptionSection.forEach(function(option:Options) {
				optionSetting.members[option.ID].x = option.x;
				optionSetting.members[option.ID].y = option.optionIcon.y - (optionSetting.members[option.ID].height / 2) + 5;
			});	
		}
	}
}