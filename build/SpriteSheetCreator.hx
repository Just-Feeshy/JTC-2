package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxCamera;
import flixel.FlxObject;
import flixel.text.FlxText;
import flixel.graphics.FlxGraphic;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUITabMenu;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIInputText;
import flixel.input.keyboard.FlxKey;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import openfl.display.BitmapData;
import openfl.events.IOErrorEvent;
import openfl.events.Event;
import openfl.net.FileReference;

using StringTools;

class SpriteSheetCreator extends MusicBeatState {
    var UI_thingy:FlxUITabMenu;

    var _file:FileReference;

    var escapeText:FlxText;
    var displaySprite:FlxSprite;

    var camHUD:FlxCamera;
    var camGAME:FlxCamera;

    var camFollow:FlxObject;

    var fileType:Array<String> = [];

    var animFrames:Map<String, Array<FlxGraphic>>;
    var animNames:Array<String>;

    var frameIndex(default, set):Int = 0;

    override function create() {
        FlxG.mouse.visible = true;

        animFrames = new Map<String, Array<FlxGraphic>>();
        animNames = [];

        camHUD = new FlxCamera();
        camGAME = new FlxCamera();
        camHUD.bgColor.alpha = 0;
        camGAME.bgColor.alpha = 0;

        FlxG.cameras.add(camGAME);
        FlxG.cameras.add(camHUD);

        FlxCamera.defaultCameras = [camGAME];

        var tabs = [
            {name: "Spritesheet", label: "Spritesheet"}
		];

        camFollow = new FlxObject(0, 0, 1, 1);

        displaySprite = new FlxSprite();
        updateSprite();
        add(displaySprite);

        UI_thingy = new FlxUITabMenu(null, tabs, true);

        UI_thingy.resize(250, 210);
		UI_thingy.x = Std.int(FlxG.width - UI_thingy.width - 25);
        UI_thingy.screenCenter(Y);
        UI_thingy.y -= Std.int(UI_thingy.height / 4);
        UI_thingy.scrollFactor.set();

        add(UI_thingy);

        createSpritesheetUI();

        escapeText = new FlxText(30, 30, "");
        updateText();
        add(escapeText);

        UI_thingy.cameras = [camHUD];
        escapeText.cameras = [camHUD];

        super.create();
    }

    override function update(elapsed:Float):Void {
        if(FlxG.keys.pressed.ESCAPE) {
            FlxG.switchState(new OptionsMenuState("editors"));
        }

        if(camGAME.zoom <= 2 && camGAME.zoom >= 0.1 && Math.abs(FlxG.mouse.wheel) > 0.1) {
            camGAME.zoom += FlxG.mouse.wheel * elapsed * 1.2;
            updateText();
        }

        if(FlxG.keys.pressed.Q && camGAME.zoom <= 2) {
            camGAME.zoom += elapsed;
            updateText();
        }

        if(FlxG.keys.pressed.E && camGAME.zoom >= 0.1) {
            camGAME.zoom -= elapsed;
            updateText();
        }

        if(camGAME.zoom > 2) {
            camGAME.zoom = 2;
            updateText();
        }

        if(camGAME.zoom < 0.1) {
            camGAME.zoom = 0.1;
            updateText();
        }

        super.update(elapsed);
    }

    var animSelector:FlxUIDropDownMenu;
    var unableLabel:FlxText;

    function createSpritesheetUI():Void {
        var tab_group_spritesheet = new FlxUI(null, UI_thingy);
        tab_group_spritesheet.name = "Spritesheet";

        animSelector = new FlxUIDropDownMenu(10, 30, FlxUIDropDownMenu.makeStrIdLabelArray(fillIfEmpty(), true), function(choose:String) {
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

        var importImageButton:FlxUIButton = new FlxUIButton(createAnimButton.x - createAnimButton.width - 10, createAnimButton.y, "Import PNG", function() {
            fileType = [".png"];

            _file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        unableLabel = new FlxText(10, animSelector.y + animSelector.height + 5, "");
		unableLabel.color = FlxColor.RED;

        tab_group_spritesheet.add(animSelector);
        tab_group_spritesheet.add(animSelectorTxt);
        tab_group_spritesheet.add(inputName);
        tab_group_spritesheet.add(inputNameTxt);
        tab_group_spritesheet.add(createAnimButton);
        tab_group_spritesheet.add(removeAnimButton);
        tab_group_spritesheet.add(importImageButton);
        tab_group_spritesheet.add(unableLabel);

        UI_thingy.addGroup(tab_group_spritesheet);
    }

    function fillIfEmpty():Array<String> {
        if(animNames.length > 0) {
            return animNames;
        }

        return [""];
    }

    function updateSprite():Void {
        if(animSelector == null) {
            return;
        }

        if(!animFrames.exists(animSelector.selectedLabel)) {
            return;
        }

        var graphicArray:Array<FlxGraphic> = animFrames.get(animSelector.selectedLabel);

        if(graphicArray.length > 0) {
            displaySprite.antialiasing = SaveData.getData(SaveType.GRAPHICS);
            displaySprite.loadGraphic(graphicArray[frameIndex]);
            displaySprite.updateHitbox();
            displaySprite.screenCenter();

            camFollow.setPosition(displaySprite.getMidpoint().x, displaySprite.getMidpoint().y);
            add(camFollow);

            camGAME.follow(camFollow, LOCKON, 0.04);
            camGAME.focusOn(camFollow.getPosition());
        }
    }

    function updateText():Void {
        escapeText.text =
            "Zoom: "
            + Std.int(camGAME.zoom * 100) + "%"
            + "\nFrame Index: "
            + (frameIndex + 1)
            + "\n\nUP/DOWN - Increase/Decrease Frame Index"
            + "\nMouse Wheel | Q/E - Camera Zoom"
            + "\nESCAPE - To Exit"
            + "\n\nMade By: Feeshy"
        ;
    }

    function onSelect(event:Event):Void {
        _file = cast(event.target, FileReference);
        _file.addEventListener(Event.COMPLETE, onComplete);
        _file.load();
    }

    function onComplete(event:Event):Void {
        clearEvent();
        _file = cast(event.target, FileReference);

        var foundFile:Bool = false;

        unableLabel.text = "";

        for(i in 0...fileType.length) {
            if(_file.type == fileType[i]) {
                foundFile = true;
                break;
            }
        }

        if(!foundFile) {
            unableLabel.text = "Unable to compile file:\n" + _file.name;
            return;
        }

        if(animSelector == null) {
            unableLabel.text = "No animations selected";
            return;
        }

        if(!animFrames.exists(animSelector.selectedLabel)) {
            unableLabel.text = "No animations selected";
            return;
        }

        var graphicLoaded = FlxG.bitmap.add(BitmapData.fromBytes(_file.data));
        graphicLoaded.persist = true;
        graphicLoaded.destroyOnNoUse = false;

        animFrames.get(animSelector.selectedLabel).push(graphicLoaded);
        frameIndex = Std.int(Math.max(0, animFrames.get(animSelector.selectedLabel).length - 1));
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
        super.destroy();
    }
}