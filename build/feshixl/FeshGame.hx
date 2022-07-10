package feshixl;

import flixel.FlxG;
import flixel.FlxGame;
import flixel.FlxState;
import flixel.input.gamepad.FlxGamepad;

using StringTools;

class FeshGame extends FlxGame {
    public function new(GameWidth:Int = 0, GameHeight:Int = 0, ?InitialState:Class<FlxState>, Zoom:Float = 1, UpdateFramerate:Int = 60,
        DrawFramerate:Int = 60, SkipSplash:Bool = false, StartFullscreen:Bool = false) 
    { //First time for everything.
        super(GameWidth, GameHeight, InitialState, Zoom, UpdateFramerate, DrawFramerate, SkipSplash, StartFullscreen);
    }

    override function update():Void {

        /**
        * Incredibly cheap way to make this.
        */
        var gamepad:FlxGamepad = FlxG.gamepads.lastActive;

        if(gamepad != null) {
            if(FlxG.stage.hasEventListener(GamepadEvent.BUTTON_DOWN) && gamepad.justPressed.ANY) {
                var index:Int = 0;

                @:access(openfl.events.EventDispatcher)
                while(index < FlxG.stage.__eventMap.get(GamepadEvent.BUTTON_DOWN).length) {
                    FlxG.stage.__eventMap.get(GamepadEvent.BUTTON_DOWN)[index].callback(new GamepadEvent(GamepadEvent.BUTTON_DOWN, false, false, gamepad.firstJustPressedRawID()));

                    index++;
                }
            }

            if(FlxG.stage.hasEventListener(GamepadEvent.BUTTON_UP) && gamepad.justReleased.ANY) {
                var index:Int = 0;

                @:access(openfl.events.EventDispatcher)
                while(index < FlxG.stage.__eventMap.get(GamepadEvent.BUTTON_UP).length) {
                    FlxG.stage.__eventMap.get(GamepadEvent.BUTTON_UP)[index].callback(new GamepadEvent(GamepadEvent.BUTTON_UP, false, false, gamepad.firstJustReleasedRawID()));

                    index++;
                }
            }
        }

        super.update();
    }
}