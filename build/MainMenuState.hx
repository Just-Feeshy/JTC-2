package;

#if windows
import Discord.DiscordClient;
#end

import Song.SwagSong;
import Controls.KeyboardScheme;
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.effects.FlxFlicker;
import flixel.group.FlxSpriteGroup;
import flixel.system.FlxAssets.FlxShader;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.addons.transition.FlxTransitionSprite.GraphicTransTileDiamond;
import flixel.addons.transition.FlxTransitionableState;
import flixel.addons.transition.TransitionData;
import flixel.graphics.FlxGraphic;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxRect;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.math.FlxPoint;
import flixel.math.FlxMath;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;
import lime.app.Application;
import feshixl.FeshCamera;

import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilter;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.ShaderFilter;

import openfl.Lib;

import SaveData.SaveType;

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

class MainMenuState extends MusicBeatState
{
	//Cameras
	var camX:FeshCamera;
	var camMenu:FeshCamera;
	var camNoBump:FeshCamera;

	var curSelected:Int = 0;

	var menuItems:FlxTypedGroup<FlxSprite>;
	var displayChain:FlxSpriteGroup;
	var menuBG:MenuBackground;
	var menuBGOverlay:FlxSprite;

	var camFollow:FlxObject;
	var secondCam:FlxObject;

	var blurSize:Float = 0;
	var saturationBackground:Float = 1;
	var saturationMenu:Float = 1;
	var zoomSineWave:Bool = true;
	final baseMenuZoom:Float = 1.1;

	var fromFreeplay:Bool = false;

	public function new(fromFreeplay:Bool = false) {
		this.fromFreeplay = fromFreeplay;

		super("void", "void");
	}

	function applyBackgroundFilters():Void {
		var filters:Array<BitmapFilter> = [new ShaderFilter(new StupidVibeShader(saturationBackground))];

		if(blurSize > 0) {
			filters.unshift(new BlurFilter(blurSize, blurSize, BitmapFilterQuality.LOW));
		}

		camX.setFilters(filters);
	}

	function applyMenuZoom():Void {
		if(zoomSineWave) {
			camMenu.zoom = baseMenuZoom + 0.02 * (Math.sin(0.0005 * Conductor.instance.trackedSongPosition * Math.PI * (Paths.modJSON.main_menu.bpm / 120)));
		}else {
			camMenu.zoom = baseMenuZoom;
		}
	}

	#if !(switch || debug)
	var optionShit:Array<String> = ['story mode', 'freeplay', 'settings'];
	#else
	var optionShit:Array<String> = ['story mode', 'freeplay'];
	#end

	override function create() {
        FlxG.mouse.visible = false;

		Conductor.instance.trackedSongPosition = 0;
		Conductor.instance.trackedSongPosition -= Conductor.instance.beatLengthMs * 5;

		camX = new FeshCamera();
		camMenu = new FeshCamera();
		camNoBump = new FeshCamera();
		camX.bgColor.alpha = 0;
		camMenu.bgColor.alpha = 0;
		camNoBump.bgColor.alpha = 0;
		camX.zoom = 1;

		FlxG.cameras.reset(camX);
		FlxG.cameras.add(camMenu);
		FlxG.cameras.add(camNoBump);

		blurSize = Paths.modJSON.main_menu.background_blur != null ? Paths.modJSON.main_menu.background_blur : 0;
		zoomSineWave = Paths.modJSON.main_menu.zoom_sine_wave != null ? Paths.modJSON.main_menu.zoom_sine_wave : true;

		FlxCamera.defaultCameras = [camMenu];
		applyBackgroundFilters();
		applyMenuZoom();
		camNoBump.setFilters([new ShaderFilter(new StupidVibeShader(saturationMenu))]);

		PlayState.hasWarning = true;

		Conductor.instance.forceBPM(Paths.modJSON.main_menu.bpm);

		Main.trueFramerate = FlxG.save.data.lowFps;
        Register.updateFramerate(Main.trueFramerate * SaveData.getData(SaveType.FPS_MULTIPLIER));

		#if windows
		// Updating Discord Rich Presence
		DiscordClient.changePresence("In the Menus", null);
		#end

        #if !(USING_LUA && cpp)
        if(FlxG.sound.music != null) {
            if(FlxG.sound.music.playing && fromFreeplay) {
                FlxG.sound.music.stop();
                FlxG.sound.playMusic(Paths.music('Main Menu'));
            }else {
                FlxG.sound.playMusic(Paths.music('Main Menu'));
            }
        }else {
            FlxG.sound.playMusic(Paths.music('Main Menu'));
        }
        #end

		persistentUpdate = persistentDraw = true;

		menuBG = new MenuBackground(0, 0);
		menuBG.cameras = [camX];
		add(menuBG);

		menuBGOverlay = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		menuBGOverlay.alpha = 0.2;
		menuBGOverlay.scrollFactor.set();
		menuBGOverlay.cameras = [camX];
		add(menuBGOverlay);

		camFollow = new FlxObject(0, 0, 1, 1);
		add(camFollow);

		secondCam = new FlxObject(0, 0, 1, 1);
		add(secondCam);

		menuItems = new FlxTypedGroup<FlxSprite>();

		displayChain = new FlxSpriteGroup();
		displayChain.cameras = [camNoBump];
		displayChain.scrollFactor.set(0, 1);
		add(displayChain);

		modifiableSprites.set("chainGroup", displayChain);

		var tex = Paths.getSparrowAtlas('FNF_main_menu_assets');

		camNoBump.follow(secondCam, null, 1);
		camMenu.follow(secondCam, null, 1);

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

		super.create();

		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			modifiableCameras.set("cameraBackground", camX);
			modifiableCameras.set("cameraMenu", camNoBump);
			if(menuBG != null) {
				modifiableSprites.set("menuBG", menuBG);
			}
			if(menuBGOverlay != null) {
				modifiableSprites.set("menuBGOverlay", menuBGOverlay);
			}
			setLua("menuBackgroundBlur", blurSize);
			setLua("menuZoomSineWave", zoomSineWave);

			getLuaOptions();

			addCallback("setSpriteAsMenuItem", function(name:String) {
				var spr:FlxSprite = getModLua().getSprite(name);

				if(spr == null) {
					return;
				}

				spr.ID = menuItems.length - 1;
				menuItems.add(spr);
				displayChain.add(spr);
			});

			addCallback("setSpriteAsDisplayChain", function(name:String) {
				var spr:FlxSprite = getModLua().getSprite(name);

				if(spr == null) {
					return;
				}

				displayChain.add(spr);
			});

			addCallback("setBackgroundBlur", function(blurSize:Float) {
				this.blurSize = blurSize;

				applyBackgroundFilters();
			});

			addCallback("setBackgroundSaturation", function(saturation:Float) {
				this.saturationBackground = saturation;

				applyBackgroundFilters();
			});

			addCallback("setMenuSaturation", function(saturation:Float) {
				this.saturationMenu = saturation;

				camNoBump.setFilters([new ShaderFilter(new StupidVibeShader(saturationMenu))]);
			});

			addCallback("setMenuZoomSineWave", function(enabled:Bool) {
				this.zoomSineWave = enabled;
				setLua("menuZoomSineWave", enabled);
				applyMenuZoom();
			});

			addCallback("finishMenuOptionChoice", function(option:String) {
				switchToOption(option);
			});
		}

		for (i in 0...optionShit.length) {
			var menuItem:FlxSprite = new FlxSprite(90, (i * 200));
			menuItem.frames = tex;
			menuItem.setGraphicSize(Std.int(menuItem.width));
			menuItem.updateHitbox();
			menuItem.animation.addByPrefix('idle', optionShit[i] + " basic", 24);
			menuItem.animation.addByPrefix('selected', optionShit[i] + " whte", 24);
			menuItem.animation.play('idle');
			menuItem.scrollFactor.set(0, 1);
			menuItem.ID = i;
			menuItem.alpha = 0;
			menuItems.add(menuItem);
			displayChain.add(menuItem);
			menuItem.antialiasing = true;

			modifiableSprites.set(optionShit[i], menuItem);
		}

		super.onCreate();
		
		#else
		for (i in 0...optionShit.length) {
			var menuItem:FlxSprite = new FlxSprite(90, (i * 200));
			menuItem.frames = tex;
			menuItem.setGraphicSize(Std.int(menuItem.width));
			menuItem.updateHitbox();
			menuItem.animation.addByPrefix('idle', optionShit[i] + " basic", 24);
			menuItem.animation.addByPrefix('selected', optionShit[i] + " whte", 24);
			menuItem.animation.play('idle');
			menuItem.scrollFactor.set(0, 1);
			menuItem.ID = i;
			menuItem.alpha = 0;
			menuItems.add(menuItem);
			displayChain.add(menuItem);
			menuItem.antialiasing = true;
		}
		#end

		FlxTween.tween(menuItems.members[0], {alpha: 1}, 1, {ease: FlxEase.quadOut});

		changeItem();
		secondCam.setPosition(camFollow.x, camFollow.y);
	}

	//To call from different segment in code.
	override public function onCreate():Dynamic {
		return null;
	}

	var selectedSomethin:Bool = false;

	function switchToOption(option:String):Void {
		HelperStates.nextTransitionInType = "void";
		HelperStates.skipNextTransitionIn = false;

		switch(option) {
			case 'story mode':
				FlxG.switchState(new StoryMenuState());
			case 'freeplay':
				FlxG.switchState(new FreeplayState());
			case 'settings':
				FlxG.switchState(new OptionsMenuState());
			case 'crew':
				FlxG.switchState(new CrewState());
		}
	}

	override function update(elapsed:Float)
	{
		if (FlxG.sound.music != null)
			Conductor.instance.trackedSongPosition = FlxG.sound.music.time;

		if (FlxG.sound.music.volume < 0.8)
		{
			FlxG.sound.music.volume += 0.5 * FlxG.elapsed;
		}

		if (!selectedSomethin) {
			var lerpTick:Float = Math.min(1, Math.max(0, elapsed * 5.6));

			secondCam.setPosition(FlxMath.lerp(secondCam.x, camFollow.x, lerpTick), FlxMath.lerp(secondCam.y, camFollow.y, lerpTick));

			if (controls.UP_P) {
				FlxG.sound.play(Paths.sound('scrollMenu'));
				changeItem(-1);
			}

			if (controls.DOWN_P) {
				FlxG.sound.play(Paths.sound('scrollMenu'));
				changeItem(1);
			}

			if (controls.ACCEPT)
			{
				selectedSomethin = true;
				FlxG.sound.play(Paths.sound('confirmMenu'));
				var selectedOption:String = optionShit[curSelected];
				var hasLuaScript:Bool = false;

				#if (USING_LUA && cpp)
				hasLuaScript = HelperStates.luaExist(Type.getClass(this));
				#end

				menuItems.forEach(function(spr:FlxSprite)
				{
					if (curSelected == spr.ID)
					{
						spr.updateHitbox();

						#if (USING_LUA && cpp)
						if(hasLuaScript) {
							HelperStates.getLua(Type.getClass(this)).call("callOptionChoice", [selectedOption]);
						}
						#end

						FlxFlicker.flicker(spr, 1, 0.06, true, false, function(flick:FlxFlicker)
						{
							if(!hasLuaScript) {
								switchToOption(selectedOption);
							}
						});
					}
				});
			}

			menuItems.forEach(function(spr:FlxSprite) {
				if(spr.ID == curSelected) {
					spr.alpha = FlxMath.lerp(1, 0.4, lerpTick);
				}else if(spr.ID != curSelected) {
					spr.alpha = FlxMath.lerp(0.4, 1, lerpTick);
				}
			});
		}

		applyMenuZoom();

		super.update(elapsed);
	}

	function getLuaOptions() {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			var luaOptionShit:Array<String> = HelperStates.getLua(Type.getClass(this)).call("setupCustomOptions", [curSelected]);

			if(luaOptionShit != null)
				optionShit = luaOptionShit;
		}
		#end
	}

	function getSelectVal(sel:Int = 0):Int {

		if (sel >= menuItems.length)
			sel = 0;
		if (sel < 0)
			sel = menuItems.length - 1;

		return sel;
	}

	function changeItem(huh:Int = 0)
	{
		curSelected += huh;	
		curSelected = getSelectVal(curSelected);
	
		menuItems.forEach(function(spr:FlxSprite) {
			spr.animation.play('idle');
			
			if(spr.ID == curSelected) {
				camFollow.y = spr.getGraphicMidpoint().y - spr.height / 4;
				// Keep the menu camera locked to the resting menu layout while the chain group slides in and out.
				camFollow.x = spr.getGraphicMidpoint().x - spr.width / 4 - displayChain.x;
			}
	
			spr.updateHitbox();
		});
	}
}
