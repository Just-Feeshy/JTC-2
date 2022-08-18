package;

import flixel.FlxG;
import openfl.events.Event;

class DevStateTest extends HelperStates {
    public function new() {
        super();

        FlxG.stage.addEventListener(Event.ENTER_FRAME, enterFrame);
    }

    override function create():Void {
        super.create();
    }

    function enterFrame(_):Void {
        trace("do a silly");

        if(FlxG.keys.justPressed.P) {
            throw "haha you suck!";
        }
    }
}