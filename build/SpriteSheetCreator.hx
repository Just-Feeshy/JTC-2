package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxCamera;
import flixel.text.FlxText;
import flixel.graphics.FlxGraphic;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUITabMenu;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIInputText;
import flixel.input.keyboard.FlxKey;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.IOErrorEvent;
import openfl.net.FileReference;

using StringTools;

class SpriteSheetCreator extends MusicBeatState {
    var UI_thingy:FlxUITabMenu;

    var _file:FileReference;

    var escapeText:FlxText;
    var displaySprite:FlxSprite;

    var camHUD:FlxCamera;
    var camGame:FlxCamera;

    var animFrames:Map<String, Array<FlxGraphic>>;
    var animNames:Array<String>;

    var frameIndex(default, set):Int = 0;

    override function create() {
        FlxG.mouse.visible = true;

        animFrames = new Map<String, Array<FlxGraphic>>();
        animNames = [];

        camHUD = new FlxCamera();
        camGame = new FlxCamera();
        camHUD.bgColor.alpha = 0;
        camGame.bgColor.alpha = 0;

        FlxG.cameras.add(camGame);
        FlxG.cameras.add(camHUD);

        FlxCamera.defaultCameras = [camHUD];

        var tabs = [
            {name: "Spritesheet", label: "Spritesheet"}
		];

        UI_thingy = new FlxUITabMenu(null, tabs, true);

        UI_thingy.resize(250, 210);
		UI_thingy.x = Std.int(FlxG.width - UI_thingy.width - 25);
        UI_thingy.screenCenter(Y);
        UI_thingy.y -= Std.int(UI_thingy.height / 4);
        UI_thingy.scrollFactor.set();

        add(UI_thingy);

        createSpritesheetUI();

        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, attachKeysToEditor);

        escapeText = new FlxText(30, 30, "");
        updateText();
        add(escapeText);

        UI_thingy.cameras = [camHUD];
        escapeText.cameras = [camHUD];

        super.create();
    }

    function createSpritesheetUI():Void {
        var tab_group_spritesheet = new FlxUI(null, UI_thingy);
        tab_group_spritesheet.name = "Spritesheet";

        var animSelector:FlxUIDropDownMenu = new FlxUIDropDownMenu(10, 30, FlxUIDropDownMenu.makeStrIdLabelArray(fillIfEmpty(), true), function(choose:String) {
            if(choose.trim() != "") {
                frameIndex = 0;
            }
        });
        var animSelectorTxt:FlxText = new FlxText(10, 10, "Animation Selector:");

        var inputName:FlxUIInputText = new FlxUIInputText(animSelector.x + animSelector.width + 10, 30, 80, "", 8);
        var inputNameTxt:FlxText = new FlxText(inputName.x, 10, "Animation Name:");

        var removeAnimButton:FlxUIButton = new FlxUIButton(inputName.x, 0, "Remove Anim", function() {
            
        });
        removeAnimButton.y = UI_thingy.height + removeAnimButton.height - 5;

        var createAnimButton:FlxUIButton = new FlxUIButton(inputName.x, 0, "Create Anim", function() {
            if(inputName.text.trim() != "") {
                animNames.push(inputName.text);
                animFrames.set(inputName.text, []);
                animSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(fillIfEmpty(), true));
                inputName.text = "";
                frameIndex = 0;
            }
        });
        createAnimButton.y = removeAnimButton.y - createAnimButton.height - 5;

        tab_group_spritesheet.add(animSelector);
        tab_group_spritesheet.add(animSelectorTxt);
        tab_group_spritesheet.add(inputName);
        tab_group_spritesheet.add(inputNameTxt);
        tab_group_spritesheet.add(createAnimButton);
        tab_group_spritesheet.add(removeAnimButton);

        UI_thingy.addGroup(tab_group_spritesheet);
    }

    function fillIfEmpty():Array<String> {
        if(animNames.length > 0) {
            return animNames;
        }

        return [""];
    }

    function updateSprite():Void {

    }

    function updateText():Void {
        escapeText.text = 
            "Frame Index: "
            + frameIndex
            + "\n\nUP/DOWN - Increase/Decrease Frame Index"
            + "\nMouse Wheel | Q/E - Camera Zoom"
            + "\nESCAPE - To Exit"
            + "\n\nMade By: Feeshy"
        ;
    }

    function attachKeysToEditor(event:KeyboardEvent):Void {
        var key:FlxKey = event.keyCode;

        if(key == FlxKey.ESCAPE) {
            FlxG.switchState(new OptionsMenuState("editors"));
        }
    }

    function onSelect(event:Event):Void {
        _file = cast(event.target, FileReference);
        _file.addEventListener(Event.COMPLETE, onComplete);
        _file.load();
    }

    function onComplete(event:Event) {

    }

    function onCancel(_):Void {
		clearEvent();
	}

    function clearEvent():Void {
        _file.removeEventListener(Event.COMPLETE, onComplete);
        _file.removeEventListener(Event.CANCEL, onCancel);
        _file = null;
    }

    function set_frameIndex(index:Int):Int {
        frameIndex = index;
        updateSprite();
        updateText();
        return frameIndex;
    }

    override function destroy():Void {
        FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, attachKeysToEditor);

        super.destroy();
    }
}