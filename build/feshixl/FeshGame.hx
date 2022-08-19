package feshixl;

import flixel.FlxGame;
import flixel.FlxState;

/**
* Debugger game. (pretty much)
*/
class FeshGame extends FlxGame {
    public function new(GameWidth:Int = 0, GameHeight:Int = 0, ?InitialState:Class<FlxState>, Zoom:Float = 1, UpdateFramerate:Int = 60,
        DrawFramerate:Int = 60, SkipSplash:Bool = false, StartFullscreen:Bool = false)
    {
        super(0, 0, InitialState, Zoom, UpdateFramerate, DrawFramerate, SkipSplash, StartFullscreen);
    }

    override function onEnterFrame(_):Void {
        //trace("accumulator: " + _accumulator);
        //trace("stepMS: " + _stepMS);

        super.onEnterFrame(_);
    }
}