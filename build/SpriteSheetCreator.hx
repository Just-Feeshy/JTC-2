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
import feshixl.utils.FeshFileHandler;
import openfl.utils.ByteArray;
import openfl.display.PNGEncoderOptions;
import openfl.display.BitmapData;
import openfl.events.IOErrorEvent;
import openfl.events.Event;
import openfl.geom.Point;
import lime.ui.FileDialog;
import haxe.io.Bytes;

import SaveData.SaveType;

using StringTools;

/**
* Heavily under WIP.
* Btw if your going to "borrow" this code or any other, please credit me.
*
* I can't do `FlxG.bitmap.add` cause it'll cause rendering issues.
* @author Feeshy
*/
@:access(flixel.graphics.FlxGraphic)
class SpriteSheetCreator extends MusicBeatState {
    var UI_thingy:FlxUITabMenu;

    var _file:FeshFileHandler;

    var escapeText:FlxText;
    var displaySprite:FlxSprite;
    var camCursor:FlxSprite;

    var camHUD:FlxCamera;
    var camGAME:FlxCamera;

    var camFollow:FlxObject;

    var existing:Bool = false;

    var fileType:Array<String> = [];

    var animFrames:Map<String, Array<FlxGraphic>>;
    var animNames:Array<String>;

    var column:Int = 7; //hehe 7 lucky number.
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
        if(!existing) {
            if(FlxG.keys.pressed.ESCAPE) {
                FlxG.switchState(new OptionsMenuState("editors"));
                existing = true;
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

            if(FlxG.keys.justPressed.UP) {
                if(frameIndex < animFrames.get(animSelector.selectedLabel).length - 1) {
                    frameIndex++;
                }else {
                    frameIndex = 0;
                }
            }

            if(FlxG.keys.justPressed.DOWN) {
                if(frameIndex > 0) {
                    frameIndex--;
                }else {
                    frameIndex = animFrames.get(animSelector.selectedLabel).length - 1;
                }
            }

            if(FlxG.keys.justPressed.RIGHT) {
                column++;
                updateText();
            }

            if(FlxG.keys.justPressed.LEFT && column > 1) {
                column--;
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
            animNames.remove(animSelector.selectedLabel);
            animFrames.remove(animSelector.selectedLabel);
            animSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(fillIfEmpty(), true));
            frameIndex = 0;
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

            _file = new FeshFileHandler();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        var uniqueExportButton:FlxUIButton = new FlxUIButton(createAnimButton.x - createAnimButton.width - 10, removeAnimButton.y, "Export", function() {
            if(animNames.length > 0) {
                for(k in animFrames.keys()) {
                    saveSpriteheet();
                    break;
                }
            }
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
        tab_group_spritesheet.add(uniqueExportButton);
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
            + frameIndex
            + "\nColumns Per Row: "
            + column
            + "\n\nLEFT/RIGHT - Change how many columns per row"
            + "\nUP/DOWN - Increase/Decrease Frame Index"
            + "\nMouse Wheel | Q/E - Camera Zoom"
            + "\nESCAPE - To Exit"
            + "\n\nMade By: Feeshy"
        ;
    }

    /**
    * This takes long to register and compile... Too bad!
    */
    function saveSpriteheet():Void {
        var xMatrix:Array<Array<Int>> = [];
        var yMatrix:Array<Array<Int>> = [];

        var maxWidth:Int = 0;
        var maxHeight:Int = 0;

        var allGraphics:Array<FlxGraphic> = totalGraphics();

        for(i in 0...Math.ceil(allGraphics.length / column)) {
            xMatrix.push([]);
            yMatrix.push([]);

            var tempWidth:Int = 0;
            var tempHeight:Int = 0;

            for(k in 0...column) {
                if(k + (i * column) >= allGraphics.length) {
                    break;
                }

                xMatrix[i].push(tempWidth);
                yMatrix[i].push(maxHeight);

                tempWidth += allGraphics[k].width;

                if(tempHeight < allGraphics[(i * column)].height) {
                    tempHeight = allGraphics[(i * column)].height;
                }
            }

            if(maxWidth < tempWidth) {
                maxWidth = tempWidth;
            }

            if(i < Math.ceil(allGraphics.length / column) - 1) {
                maxHeight += tempHeight;
            }else {
                maxHeight += tempHeight;
            }
        }

        var ohNo:BitmapData = new BitmapData(maxWidth, maxHeight, true, 0x00000000);

        var happyMapX:Map<String, Array<Int>> = new Map<String, Array<Int>>();
        var happyMapY:Map<String, Array<Int>> = new Map<String, Array<Int>>();

        for(i in 0...Math.ceil(allGraphics.length / column)) { //vertical
            for(k in 0...column) { //horizontal
                if(k + (i * column) >= allGraphics.length) {
                    break;
                }

                if(!happyMapX.exists(allGraphics[k + (i * column)].key)) {
                    happyMapX.set(allGraphics[k + (i * column)].key, []);
                }

                if(!happyMapY.exists(allGraphics[k + (i * column)].key)) {
                    happyMapY.set(allGraphics[k + (i * column)].key, []);
                }

                happyMapX.get(allGraphics[k + (i * column)].key).push(xMatrix[i][k]);
                happyMapY.get(allGraphics[k + (i * column)].key).push(yMatrix[i][k]);

                ohNo.copyPixels(allGraphics[k + (i * column)].bitmap, allGraphics[k + (i * column)].bitmap.rect, new Point(xMatrix[i][k], yMatrix[i][k]));
            }
        }

        var toBytes:ByteArray = new ByteArray();
        toBytes = ohNo.encode(ohNo.rect, new PNGEncoderOptions(true), toBytes);

        _file = new FeshFileHandler();
        _file.addEventListener(Event.COMPLETE, onSaveComplete);
        _file.addEventListener(Event.CANCEL, onCancel);
        _file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);

        _file.savedFileCallback = function(name:String, path:String) {
            saveSpritesheetXml(name, path, happyMapX, happyMapY);

            happyMapX.clear();
            happyMapY.clear();
        }

        _file.save(toBytes, "spritesheet.png");
    }

    function saveSpritesheetXml(fileName:String, path:String, xm:Map<String, Array<Int>>, ym:Map<String, Array<Int>>):Void {
        var xmlVersion:String = 
        '<?xml version="1.0" encoding="utf-8"?>\n'
        + '<TextureAtlas imagePath="${fileName}">\n'
        + '\t<!-- Created with Feeshmora FNF -->\n';

        var mapIndex:Int = 0;

        for(k in animFrames.keys()) {
            var frameArray:Array<FlxGraphic> = animFrames.get(k);

            for(i in 0...frameArray.length) {
                xmlVersion += '\t<SubTexture name="${k + nodeIDString(i)}" x="${xm.get(k)[i]}" y="${ym.get(k)[i]}" width="${frameArray[i].width}" height="${frameArray[i].height}">\n';
            }

            mapIndex++;
        }

        xmlVersion += "</ TextureAtlas>";

        if(_file != null) {
            _file = new FeshFileHandler();
        }

        _file.addEventListener(Event.COMPLETE, onSaveComplete);
        _file.addEventListener(Event.CANCEL, onCancel);
        _file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        _file.save(xmlVersion, fileName.split(".")[0] + ".xml");
    }

    function nodeIDString(id:Int):String {
        var newNumString:String = "";
        var tempNum:String = Std.string(id);

        for(i in 0...Std.int(Math.max(0, 4 - tempNum.length))) {
            newNumString += "0";
        }

        newNumString += tempNum;
        return newNumString;
    }

    function onSaveComplete(_):Void {
		clearEvent();
	}

    function onSaveError(_):Void {
		clearEvent();
		FlxG.log.error("Problem saving ERROR");
	}

    function totalGraphics():Array<FlxGraphic> {
        var totalGraphicArray:Array<FlxGraphic> = [];

        for(k in animFrames.keys()) {
            totalGraphicArray = totalGraphicArray.concat(animFrames.get(k));
        }

        return totalGraphicArray;
    }

    function onSelect(event:Event):Void {
        _file = cast(event.target, FeshFileHandler);
        _file.addEventListener(Event.COMPLETE, onComplete);
        _file.load();
    }

    function onComplete(event:Event):Void {
        clearEvent();
        _file = cast(event.target, FeshFileHandler);

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

        var graphicLoaded = new FlxGraphic(animSelector.selectedLabel, BitmapData.fromBytes(_file.data));
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
        _file.removeEventListener(Event.COMPLETE, onSaveComplete);
        _file.removeEventListener(Event.CANCEL, onCancel);
        _file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        _file.removeEventListener(Event.SELECT, onSelect);
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

        for(k in animFrames.keys()) {
            var frameArray:Array<FlxGraphic> = animFrames.get(k);

            for(i in 0...frameArray.length) {
                frameArray[i] = FlxDestroyUtil.destroy(frameArray[i]);
                frameArray.shift();
            }

            animFrames.remove(k);
        }

        animFrames.clear();
        openfl.Assets.cache.clear();
    }
}