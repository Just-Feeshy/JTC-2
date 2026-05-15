package util;

import flixel.FlxG;
import flixel.util.FlxSignal.FlxTypedSignal;
import openfl.events.KeyboardEvent;
import openfl.ui.Keyboard;

class WindowUtil
{
	public static final windowExit:FlxTypedSignal<Int->Void> = new FlxTypedSignal<Int->Void>();
	private static var initialized:Bool = false;

	public static function initWindowEvents():Void
	{
		if(initialized || openfl.Lib.current == null || openfl.Lib.current.stage == null) {
			return;
		}

		initialized = true;

		openfl.Lib.current.stage.application.onExit.add(function(exitCode:Int) {
			windowExit.dispatch(exitCode);
		});

		#if (desktop || html5)
		openfl.Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		#end
	}

	private static function onKeyDown(event:KeyboardEvent):Void
	{
		#if FEATURE_HAXEUI
		if(haxe.ui.focus.FocusManager.instance.focus != null) {
			return;
		}
		#end

		#if FLX_DEBUG
		@:privateAccess
		if(FlxG.game != null && FlxG.game.debugger != null && FlxG.game.debugger.visible) {
			return;
		}
		#end

		if(event.keyCode == Keyboard.F11) {
			openfl.Lib.application.window.fullscreen = !openfl.Lib.application.window.fullscreen;
		}
	}

	public static function setWindowTitle(value:String):Void
	{
		if(lime.app.Application.current != null && lime.app.Application.current.window != null) {
			lime.app.Application.current.window.title = value;
		}
	}
}
