package;

import flixel.FlxState;
import flixel.FlxG;
import flixel.FlxGame;
import haxe.ui.Toolkit;
import openfl.Assets;
import openfl.Lib;
import openfl.display.Sprite;
import openfl.events.Event;
import ui.FullScreenScaleMode;
import util.WindowUtil;

@:allow(BootState)
class Main extends Sprite
{
	var feeshmora:FlxGame; // The actual game!

	var gameWidth:Int = 1280; // Width of the game in pixels (might be less / more in actual pixels depending on your zoom).
	var gameHeight:Int = 720; // Height of the game in pixels (might be less / more in actual pixels depending on your zoom).
	var initialState:Class<FlxState> = BootState; // The FlxState the game starts with.
	var zoom:Float = -1; // If -1, zoom is automatically calculated to fit the window dimensions.
	var skipSplash:Bool = true; // Whether to skip the flixel splash screen that appears in release mode.
	var startFullscreen:Bool = false; // Whether to start the game in fullscreen on desktop targets.

	public static var feeshmoraModifiers:Bool = true; //Add Feeshmora modifiers to your mod. Side Note: This also affects other menu stuff.
	public static var framerate:Int = 60; // How many frames per second the game should run at.

	public static var trueFramerate = framerate;

	// You can pretty much ignore everything from here on - your code should go in your states.

	public static function main():Void {
		Lib.current.addChild(new Main());
	}

	public function new()
	{
		super();

		if (stage != null)
		{
			init();
		}
		else
		{
			addEventListener(Event.ADDED_TO_STAGE, init);
		}
	}

	private function init(?E:Event):Void
	{
		if (hasEventListener(Event.ADDED_TO_STAGE))
		{
			removeEventListener(Event.ADDED_TO_STAGE, init);
		}

		setupGame();
	}

	private function setupGame():Void
	{
		initHaxeUI();
		WindowUtil.initWindowEvents();

		var stageWidth:Int = Lib.current.stage.stageWidth;
		var stageHeight:Int = Lib.current.stage.stageHeight;

		if (zoom == -1)
		{
			var ratioX:Float = stageWidth / gameWidth;
			var ratioY:Float = stageHeight / gameHeight;
			zoom = Math.min(ratioX, ratioY);
			gameWidth = Math.ceil(stageWidth / zoom);
			gameHeight = Math.ceil(stageHeight / zoom);
		}

		#if !debug
		initialState = BootState;
		#end

		feeshmora = new FlxGame(gameWidth, gameHeight, initialState, #if (flixel < "5.0.0") zoom, #end framerate, framerate, skipSplash, startFullscreen);

		@:privateAccess
		feeshmora._customSoundTray = FunkinSoundTray;

		// Register Funkin cursors with HaxeUI's CursorHelper BEFORE the game
		// starts spinning up UI - otherwise the first hover races our setup
		// and HaxeUI sticks to its default pointer hand.
		FunkinCursor.registerHaxeUICursors();

		SaveData.bindProjectSave();

		addChild(feeshmora);

		FlxG.signals.postGameStart.addOnce(FunkinCursor.load);

		#if !html5
		FlxG.scaleMode = new FullScreenScaleMode();
		FlxG.signals.preUpdate.add(updateFullScreenScaleMode);
		#end
	}

	private function updateFullScreenScaleMode():Void
	{
		#if !html5
		if(FullScreenScaleMode.instance != null) {
			FullScreenScaleMode.instance.onMeasurePostAwait();
		}
		#end
	}

	private function initHaxeUI():Void
	{
		Toolkit.init();
		Toolkit.theme = "dark";
		Toolkit.autoScale = false;
		haxe.ui.focus.FocusManager.instance.autoFocus = false;
		haxe.ui.tooltips.ToolTipManager.defaultDelay = 200;
	}
}
