package;

import flixel.FlxG;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUITabMenu;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIButton;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.text.FlxText;
import flixel.system.FlxSound;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import feshixl.interfaces.IDialogue;
import openfl.net.FileReference;
import sys.FileSystem;
import haxe.Json;

#if json2object
import json2object.JsonParser;
#end

import SaveData.SaveType;

using StringTools;

@:enum
abstract FileStatus(String) {
    var NONE = "none";
    var OVERRIDE = "override";
}

class DialogueCreatorState extends MusicBeatState {
    var UI_thingy:FlxUITabMenu;

    var _file:FileReference;

    var _info:Array<DialogueData>;

    var fileStatus:FileStatus;
    var fileType:Array<String> = [];

    var totalSprites:Array<DialogueFileData>;

    var leftPortrait:EditorSprite;
    var rightPortrait:EditorSprite;
    var speechBubble:EditorSprite;

    var curSprite:String;

    var dialogueScene:Int = 0;

    var changeSprite:Bool = false;

    public function new() {
        super();
    }

    override function create():Void {
        totalSprites = [];

        _info = [{
            speed: 1.0,

            protagonistTalking: false,
            soundTalking: null,

            text: null,

            totalSprites: this.totalSprites,

            leftPortrait: {assetID: 0, size: 0.8},
            rightPortrait: {assetID: 0, size: 0.8},
            speechBubble: {assetID: 0, size: 0.8}
        }];

        var tabs = [
            {name: "Dialgoue", label: "Dialgoue"},
			{name: "D Sprites", label: 'Sprites'},
            {name: "Export", label: 'Export'}
		];

        fileStatus = NONE;

        refreshDisplay();

        UI_thingy = new FlxUITabMenu(null, tabs, true);

		UI_thingy.resize(300, 400);
		UI_thingy.x = Std.int(FlxG.width - UI_thingy.width - 50);
        UI_thingy.screenCenter(Y);
        UI_thingy.y -= Std.int(UI_thingy.height / 4);
        UI_thingy.scrollFactor.set();

        add(UI_thingy);

        createDisplayUI();

        super.create();
    }

    function refreshDisplay():Void {
        remove(leftPortrait);
        remove(rightPortrait);
        remove(speechBubble);

        leftPortrait = FlxDestroyUtil.destroy(leftPortrait);
        rightPortrait = FlxDestroyUtil.destroy(rightPortrait);
        speechBubble = FlxDestroyUtil.destroy(speechBubble);

        leftPortrait = new EditorSprite();
        rightPortrait = new EditorSprite();
        speechBubble = new EditorSprite();

        add(leftPortrait);
        add(rightPortrait);
        add(speechBubble);

        leftPortrait.compileSprite();
        rightPortrait.compileSprite();
        speechBubble.compileSprite();

        speechBubble.setGraphicSize(Std.int(speechBubble.width * _info[dialogueScene].speechBubble.size));
        speechBubble.updateHitbox();
        speechBubble.screenCenter(X);
        speechBubble.y = 60;

        leftPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        rightPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        speechBubble.antialiasing = SaveData.getData(SaveType.GRAPHICS);

        speechBubble.defaultCompiler = function() {
            speechBubble.frames = Paths.getSparrowAtlas("speech_bubble_talking", "shared");
            speechBubble.animation.addByPrefix("normal", "speech bubble normal", 24, true);
            speechBubble.playAnim("normal");
        }

        if(curSprite == null) {
            curSprite = "speech bubble";
        }
    }

    var spriteSelector:FlxUIDropDownMenu;
    var unableLabel:FlxText;

    function createDisplayUI():Void {
        var tab_group_display = new FlxUI(null, UI_thingy);
		tab_group_display.name = 'D Sprites';

        var instructions:FlxText = new FlxText(10, 10, "Select sprite from the drop down menu to modify");

        spriteSelector = new FlxUIDropDownMenu(10, 30, FlxUIDropDownMenu.makeStrIdLabelArray(getSpriteNames(), true), function(choose:String) {
            changeSprite = true;
        });
        spriteSelector.selectedLabel = "";

        var getXML:FlxUIButton = new FlxUIButton(spriteSelector.width + spriteSelector.x + 20, 30, "Get XML", function() {
            fileStatus = OVERRIDE;
            fileType = [".xml"];

            _file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        var getPNG:FlxUIButton = new FlxUIButton(getXML.x, 10 + getXML.y + getXML.height, "Get PNG", function() {
            fileStatus = OVERRIDE;
            fileType = [".png"];

            _file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        unableLabel = new FlxText(10, 50, "");
		unableLabel.color = FlxColor.RED;

        tab_group_display.add(instructions);
        tab_group_display.add(spriteSelector);
        tab_group_display.add(getXML);
        tab_group_display.add(getPNG);
        tab_group_display.add(unableLabel);

        UI_thingy.addGroup(tab_group_display);
    }

    function getSpriteNames():Array<String> {
        var spriteArray:Array<String> = [];

        for(i in 0...totalSprites.length) {
            spriteArray.push(totalSprites[i].name);
        }

        if(spriteArray[0] == null) {
            spriteArray.push("");
        }

        return spriteArray;
    }

    override function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void {
        if((id == FlxUIDropDownMenu.CLICK_EVENT || id == "click_button") && changeSprite) {
            changeSprite = false;
            refreshDisplay();
        }
    }

    function saveLevel() {
        var data:String = Json.stringify(_info, "\t");

        if ((data != null) && (data.length > 0))
        {
            _file = new FileReference();
            _file.addEventListener(Event.COMPLETE, onSaveComplete);
            _file.addEventListener(Event.CANCEL, onCancel);
            _file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
            _file.save(data.trim(), "dialogue.json");
        }
    }

    function onSelect(event:Event):Void {
        _file = cast(event.target, FileReference);
        _file.addEventListener(Event.COMPLETE, onComplete);
        _file.load();
    }

	function onSaveComplete(_):Void {
		clearEvent();
		FlxG.log.notice("Successfully saved DIALOGUE.");
	}

	function onComplete(event:Event):Void {
		_file = cast(event.target, FileReference);
        _file.removeEventListener(Event.COMPLETE, onComplete);

		switch(fileStatus) {
            case OVERRIDE: {
                unableLabel.text = "";

                var foundFile:Bool = false;

                for(i in 0...fileType.length) {
                    if(_file.type == fileType[i]) {
                        foundFile = true;
                    }
                }

                if(!foundFile || spriteSelector.selectedLabel == "") {
                    unableLabel.text = "Unable to compile file:\n" + _file.name;
                    return;
                }

                if(fileType.contains(".xml")) {
                    for(i in 0...totalSprites.length) {
                        if(spriteSelector.selectedLabel == totalSprites[i].name) {

                        }
                    }
                }else if(fileType.contains(".png")) {
                    for(i in 0...totalSprites.length) {
                        if(spriteSelector.selectedLabel == totalSprites[i].name) {

                        }
                    }
                }

                refreshDisplay();

                fileType = [];
            }default: {
                return;
            }
        }
	}

	/**
	 * Called when the save file dialog is cancelled.
	 */
	function onCancel(_):Void {
		clearEvent();
	}

	function onSaveError(_):Void {
		clearEvent();
		FlxG.log.error("Problem saving dialogue data");
	}

	function clearEvent():Void {
        _file.removeEventListener(Event.COMPLETE, onSaveComplete);
        _file.removeEventListener(Event.CANCEL, onCancel);
        _file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        _file.removeEventListener(Event.SELECT, onSelect);
        _file = null;
    }
}