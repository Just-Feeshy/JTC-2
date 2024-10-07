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

	var camFollow:FlxObject;
	var secondCam:FlxObject;

	var blurSize:Int = 0;
	var saturationBackground:Float = 1;
	var saturationMenu:Float = 1;

	var fromFreeplay:Bool = false;

	public function new(fromFreeplay:Bool = false) {
		this.fromFreeplay = fromFreeplay;

		super();
	}

	#if !(switch || debug)
	var optionShit:Array<String> = ['story mode', 'freeplay', 'settings'];
	#else
	var optionShit:Array<String> = ['story mode', 'freeplay'];
	#end

	override function create() {
        FlxG.mouse.visible = false;

		Conductor.songPosition = 0;
		Conductor.songPosition -= Conductor.crochet * 5;

		camX = new FeshCamera();
		camMenu = new FeshCamera();
		camNoBump = new FeshCamera();
		camX.bgColor.alpha = 0;
		camNoBump.bgColor.alpha = 0;

		FlxG.cameras.reset(camMenu);
		FlxG.cameras.add(camX);
		FlxG.cameras.add(camNoBump);

		FlxCamera.defaultCameras = [camMenu];
		FlxG.camera.setFilters([new BlurFilter(blurSize, blurSize, BitmapFilterQuality.LOW), new ShaderFilter(new StupidVibeShader(saturationBackground))]);
		camNoBump.setFilters([new ShaderFilter(new StupidVibeShader(saturationMenu))]);

		PlayState.hasWarning = true;

		Conductor.changeBPM(Paths.modJSON.main_menu.bpm);

		Main.trueFramerate = FlxG.save.data.lowFps;
        Register.updateFramerate(Main.trueFramerate * SaveData.getData(SaveType.FPS_MULTIPLIER));

		#if windows
		// Updating Discord Rich Presence
		DiscordClient.changePresence("In the Menus", null);
		#end

		if(FlxG.sound.music.playing && fromFreeplay) {
			FlxG.sound.music.stop();
			FlxG.sound.playMusic(Paths.music('Main Menu'));
		}else {
			FlxG.sound.playMusic(Paths.music('Main Menu'));
		}

		persistentUpdate = persistentDraw = true;

		if(Paths.modJSON.main_menu.has_background_image) {
			if(Paths.modJSON.main_menu.background_image != '') {
				var bg:FlxSprite = new FlxSprite().loadGraphic(Paths.image(Paths.modJSON.main_menu.background_image));
				bg.setGraphicSize(1280, 720);
				bg.updateHitbox();
				bg.screenCenter();
				bg.scrollFactor.set();
				add(bg);
			}else {
				var bg:FlxSprite = new FlxSprite(-100, -15).loadGraphic(Paths.image('menu/sky2'));
				bg.scrollFactor.set();
				add(bg);

				var city:FlxSprite = new FlxSprite(-10, -15).loadGraphic(Paths.image('menu/city'));
				city.scrollFactor.set();
				city.updateHitbox();
				city.screenCenter();
				add(city);

				var light:FlxSprite = new FlxSprite(city.x, city.y).loadGraphic(Paths.image('menu/win2'));
				light.scrollFactor.set();
				light.updateHitbox();
				light.screenCenter();
				add(light);

				var streetBehind:FlxSprite = new FlxSprite(-40, -50).loadGraphic(Paths.image('menu/behindTrain'));
				streetBehind.scrollFactor.set();
				add(streetBehind);

				var street:FlxSprite = new FlxSprite(-40, streetBehind.y).loadGraphic(Paths.image('menu/street'));
				street.scrollFactor.set();
				add(street);
			}
		}

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
			modifiableCameras.set("cameraBackground", camMenu);
			modifiableCameras.set("cameraMenu", camNoBump);

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

			addCallback("setBackgroundBlur", function(blurSize:Int) {
				this.blurSize = blurSize;

				FlxG.camera.setFilters([new BlurFilter(blurSize, blurSize, BitmapFilterQuality.LOW), new ShaderFilter(new StupidVibeShader(saturationBackground))]);
			});

			addCallback("setBackgroundSaturation", function(saturation:Float) {
				this.saturationBackground = saturation;

				FlxG.camera.setFilters([new BlurFilter(blurSize, blurSize, BitmapFilterQuality.LOW), new ShaderFilter(new StupidVibeShader(saturationBackground))]);
			});

			addCallback("setMenuSaturation", function(saturation:Float) {
				this.saturationMenu = saturation;

				camNoBump.setFilters([new ShaderFilter(new StupidVibeShader(saturationMenu))]);
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
	}

	//To call from different segment in code.
	override public function onCreate():Dynamic {
		return null;
	}

	var selectedSomethin:Bool = false;

	override function update(elapsed:Float)
	{
		if (FlxG.sound.music != null)
			Conductor.songPosition = FlxG.sound.music.time;

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

				menuItems.forEach(function(spr:FlxSprite)
				{
					if (curSelected != spr.ID)
					{
						FlxTween.tween(spr, {alpha: 0}, 0.4, {
							ease: FlxEase.quadOut,
							onComplete: function(twn:FlxTween)
							{
								spr.kill();
							}
						});
					}
					else
					{
						selectedSomethin = true;
						FlxG.sound.play(Paths.sound('confirmMenu'));

						menuItems.forEach(function(spr:FlxSprite)
						{
							if (curSelected != spr.ID)
							{
								FlxTween.tween(spr, {alpha: 0}, 1.3, {
									ease: FlxEase.quadOut,
									onComplete: function(twn:FlxTween)
									{
										spr.kill();
									}
								});
							}
							else
							{
								spr.updateHitbox();

								#if (USING_LUA && cpp)
								if(HelperStates.luaExist(Type.getClass(this))) {
									HelperStates.getLua(Type.getClass(this)).call("callOptionChoice", []);
								}
								#end

								FlxFlicker.flicker(spr, 1, 0.06, false, false, function(flick:FlxFlicker)
								{
									#if (USING_LUA && cpp)
									if(HelperStates.luaExist(Type.getClass(this))) {
										HelperStates.getLua(Type.getClass(this)).call("pressedAnOption", [optionShit[curSelected]]);
									}
									#end

									switch(optionShit[curSelected]) {
										case 'story mode':
											FlxG.switchState(new StoryMenuState());
										case 'freeplay':
											FlxG.switchState(new FreeplayState());
										case 'settings':
											FlxG.switchState(new OptionsMenuState());
									}
								});
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

		FlxG.camera.zoom = 1.1 + 0.02 * (Math.sin(0.0005 * Conductor.songPosition * Math.PI * (Paths.modJSON.main_menu.bpm/120)));

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
				camFollow.x = spr.getGraphicMidpoint().x - spr.width / 4;
			}
	
			spr.updateHitbox();
		});
	}
}
