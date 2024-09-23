package;

import flixel.FlxG;
import flixel.input.keyboard.FlxKey;
import openfl.events.KeyboardEvent;
import haxe.ui.containers.menus.MenuBar;
import haxe.ui.containers.menus.MenuItem;
import haxe.ui.backend.flixel.UIState;
import funkin.input.Cursor;

@:build(haxe.ui.ComponentBuilder.build("assets/exclude/stage/main-view.xml"))
class StageDesignState extends UIState {
    /*
     *  The menubar at the top of the screen
     */
    var menubar:MenuBar;

    /*
     * The `File -> New Chart` menu item
     */
    var menubarItemNew:MenuItem;

    public function new() {
        super();
    }

    override function create():Void {
        super.create();

        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, attachKeys);
    }

    function attachKeys(event:KeyboardEvent):Void {
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
