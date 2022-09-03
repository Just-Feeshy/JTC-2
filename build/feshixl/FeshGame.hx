package feshixl;

import flixel.FlxG;
import flixel.FlxGame;
import flixel.FlxState;

/**
* Debugger game. (pretty much)
*/
@:access(openfl.display.Stage)
class FeshGame extends FlxGame {
    public function new(GameWidth:Int = 0, GameHeight:Int = 0, ?InitialState:Class<FlxState>, Zoom:Float = 1, UpdateFramerate:Int = 60,
        DrawFramerate:Int = 60, SkipSplash:Bool = false, StartFullscreen:Bool = false)
    {
        super(GameWidth, GameHeight, InitialState, Zoom, UpdateFramerate, DrawFramerate, SkipSplash, StartFullscreen);
    }
}