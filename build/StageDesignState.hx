package;

import flixel.FlxG;
import flixel.input.keyboard.FlxKey;
import openfl.events.KeyboardEvent;
import haxe.ui.backend.flixel.UIState;

class StageDesignState extends UIState {
    public function new() {
        super();
    }

    override function create():Void {
        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, attachKeys);

        super.create();
    }

    private function attachKeys(event:KeyboardEvent):Void {
        var key:FlxKey = event.keyCode;

        if(key == FlxKey.ESCAPE) {
            FlxG.switchState(new OptionsMenuState("editors"));
        }
    }

    override function destroy():Void {
        FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, attachKeys);

        super.destroy();
    }
}
