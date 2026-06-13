package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.system.ui.FlxSoundTray;
import openfl.Lib;
import openfl.display.Bitmap;
import openfl.media.Sound;

class FunkinSoundTray extends FlxSoundTray
{
	static inline var GRAPHIC_SCALE:Float = 0.30;

	var lerpYPos:Float = 0;
	var alphaTarget:Float = 0;

	var bgBitmap:Bitmap;
	var backingBar:Bitmap;
	var assetsReady:Bool = false;
	var pendingShowUp:Null<Bool> = null;

	var volumeMaxSnd:Sound;
	var volumeUpSnd:Sound;
	var volumeDownSnd:Sound;

	public function new()
	{
		super();

		removeChildren();
		_bars = [];

		y = -height;
		visible = false;

		loadRemoteAssets();
	}

	override public function screenCenter():Void
	{
		var w:Float = (bgBitmap != null) ? bgBitmap.width * bgBitmap.scaleX * scaleX : 80 * scaleX;
		x = 0.5 * (Lib.current.stage.stageWidth - w) - FlxG.game.x;
	}

	function loadRemoteAssets():Void
	{
		Paths.loadRemoteGraphic("preload/images/soundtray/volumebox.png", function(g:FlxGraphic) {
			if (g == null)
			{
				trace("FunkinSoundTray: failed to load volumebox");
				return;
			}

			bgBitmap = new Bitmap(g.bitmap);
			bgBitmap.scaleX = GRAPHIC_SCALE;
			bgBitmap.scaleY = GRAPHIC_SCALE;
			bgBitmap.smoothing = true;
			addChild(bgBitmap);

			Paths.loadRemoteGraphic("preload/images/soundtray/bars_10.png", function(bg:FlxGraphic) {
				if (bg != null)
				{
					backingBar = new Bitmap(bg.bitmap);
					backingBar.x = 9;
					backingBar.y = 5;
					backingBar.scaleX = GRAPHIC_SCALE;
					backingBar.scaleY = GRAPHIC_SCALE;
					backingBar.smoothing = true;
					backingBar.alpha = 0.4;
					addChild(backingBar);
				}
				loadBar(1);
			});
		});

		Paths.loadRemoteSound("preload/sounds/soundtray/Volup.ogg", function(s:Sound) { volumeUpSnd = s; });
		Paths.loadRemoteSound("preload/sounds/soundtray/Voldown.ogg", function(s:Sound) { volumeDownSnd = s; });
		Paths.loadRemoteSound("preload/sounds/soundtray/VolMAX.ogg", function(s:Sound) { volumeMaxSnd = s; });
	}

	function loadBar(index:Int):Void
	{
		if (index > 10)
		{
			assetsReady = true;
			screenCenter();
			y = -height - 10;

			if (pendingShowUp != null)
			{
				var up = pendingShowUp;
				pendingShowUp = null;
				moveTrayMakeVisible(up);
			}
			return;
		}

		Paths.loadRemoteGraphic("preload/images/soundtray/bars_" + index + ".png", function(g:FlxGraphic) {
			if (g != null)
			{
				var bar = new Bitmap(g.bitmap);
				bar.x = 9;
				bar.y = 5;
				bar.scaleX = GRAPHIC_SCALE;
				bar.scaleY = GRAPHIC_SCALE;
				bar.smoothing = true;
				addChild(bar);
				_bars.push(bar);
			}
			loadBar(index + 1);
		});
	}

	override public function update(ms:Float):Void
	{
		if (!assetsReady) return;

		var elapsed = ms / 1000.0;

		if (_timer > 0)
		{
			_timer -= elapsed;
			if (_timer <= 0)
			{
				lerpYPos = -height - 10;
				alphaTarget = 0;
			}
		}
		else if (y <= -height)
		{
			visible = false;
			active = false;
		}

		y = smoothLerp(y, lerpYPos, elapsed, 0.768);
		alpha = smoothLerp(alpha, alphaTarget, elapsed, 0.307);
		screenCenter();
	}

	static inline function smoothLerp(base:Float, target:Float, deltaTime:Float, duration:Float):Float
	{
		if (deltaTime == 0 || base == target) return target;
		var factor:Float = Math.pow(1 / 100, deltaTime / duration);
		return target + (base - target) * factor;
	}

	override function show(up:Bool = false):Void
	{
		moveTrayMakeVisible(up);
		saveVolumePreferences();
	}

	function moveTrayMakeVisible(up:Bool):Void
	{
		if (!assetsReady)
		{
			pendingShowUp = up;
			return;
		}

		showTray();

		if (!silent)
		{
			var s:Sound = FlxG.sound.volume == 1 ? volumeMaxSnd : (up ? volumeUpSnd : volumeDownSnd);
			if (s != null) FlxG.sound.play(s);
		}
	}

	function showTray():Void
	{
		_timer = 1;
		lerpYPos = 10;
		visible = true;
		active = true;
		alphaTarget = 1;
		updateBars();
	}

	function updateBars():Void
	{
		var globalVolume:Int = (FlxG.sound.muted || FlxG.sound.volume == 0)
			? 0
			: Math.round(FlxG.sound.volume * 10);

		for (i in 0..._bars.length) _bars[i].visible = i < globalVolume;
	}

	function saveVolumePreferences():Void
	{
		#if FLX_SAVE
		if (FlxG.save.isBound)
		{
			FlxG.save.data.mute = FlxG.sound.muted;
			FlxG.save.data.volume = FlxG.sound.volume;
			FlxG.save.flush();
		}
		#end
	}
}
