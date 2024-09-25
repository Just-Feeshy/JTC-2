package;

import flixel.FlxG;
import flixel.input.keyboard.FlxKey;
import openfl.events.KeyboardEvent;
import haxe.ui.containers.menus.MenuBar;
import haxe.ui.containers.menus.MenuItem;
import haxe.ui.backend.flixel.UIState;
import haxe.ui.containers.dialogs.Dialog;
import funkin.input.Cursor;
import stage.*;

@:build(haxe.ui.ComponentBuilder.build("assets/exclude/stage/main-view.xml"))
class StageDesignState extends UIState {
    /*
    * Used to prevent background interactions while dialog is open.
    */
    var isHaxeUIDialogOpen:Bool = false;

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

        setupUIListeners();

        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, attachKeys);

        var __newDialog = openNewDialog(false);
    }

    function attachKeys(event:KeyboardEvent):Void {
        if(!isHaxeUIDialogOpen) {
            var key:FlxKey = event.keyCode;
            attachUIKeys(key);
        }
    }

    function attachUIKeys(key:FlxKey):Void {
        if (FlxG.keys.pressed.CONTROL && FlxG.keys.justPressed.N) {
            this.openNewDialog(true);
        }

        if(key == FlxKey.ESCAPE) {
            FlxG.switchState(new OptionsMenuState("editors"));
        }
    }

    function setupUIListeners():Void {
        menubarItemNew.onClick = _ -> this.openNewDialog(true);
    }

    override function destroy():Void {
        FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, attachKeys);

        super.destroy();
    }

    public function openNewDialog(closable:Bool = true):Null<Dialog> {
        var dialog = NewDialog.build(this, closable);
        this.isHaxeUIDialogOpen = true;

        return dialog;
    }
}
