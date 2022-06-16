package;

import flixel.FlxG;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUITabMenu;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.text.FlxTypeText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.input.keyboard.FlxKey;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.text.FlxText;
import flixel.system.FlxSound;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.IOErrorEvent;
import feshixl.interfaces.IDialogue;
import openfl.net.FileReference;
import openfl.utils.ByteArray;
import sys.FileSystem;
import haxe.Json;

#if json2object
import json2object.JsonParser;
#end

import SaveData.SaveType;
import ModInitialize.AnimationInfo;

using StringTools;

@:enum
abstract FileStatus(String) {
    var NONE = "none";
    var OVERRIDE = "override";
    var DOCUMENT = "document";
}

/**
* BONUS CHALLENGE: Don't override the `update` method.
*/
class DialogueCreatorState extends MusicBeatState {
    var UI_thingy:FlxUITabMenu;

    var _file:FileReference;

    var _info:DialogueInfo;

    var fileStatus:FileStatus;
    var fileType:Array<String> = [];

    var totalSprites:Array<DialogueFileData>;

    var leftPortrait:EditorSprite;
    var rightPortrait:EditorSprite;
    var speechBubble:EditorSprite;

    var curSprite:String;

    var dialogueScene:Int = 0;
    var selectedAsset:Int = 0;

    var changeSprite:Bool = false;

    var readOutDialogue:FlxTypeText;

    public function new() {
        super();
    }

    override function create():Void {
        totalSprites = [];

        _info = {info: [{
            speed: 1.0,

            protagonistTalking: false,
            soundTalking: null,

            text: [],
            font: "pixel",
            textSize: 32,

            leftPortrait: {animations: [], assetID: 2, size: 0.8, x: 0, y: 0},
            rightPortrait: {animations: [], assetID: 1, size: 0.8, x: 0, y: 0},
            speechBubble: {animations: [], assetID: 0, size: 0.8, x: 144, y: 360}
        }], totalSprites: this.totalSprites};

        var tabs = [
            {name: "Dialogue", label: "Dialogue"},
			{name: "E Sprites", label: 'Sprites'},
            {name: "F Animation", label: 'Animation'},
            {name: "Scene", label: 'Scene'},
            {name: "T Export", label: 'Export'}
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

        createDialogueUI();
        createDisplayUI();
        createAnimationUI();
        createSceneUI();

        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, attachKeysToEditor);

        super.create();
    }

    function refreshDisplay():Void {
        _info.totalSprites = totalSprites;

        remove(leftPortrait);
        remove(rightPortrait);
        remove(speechBubble);

        leftPortrait = FlxDestroyUtil.destroy(leftPortrait);
        rightPortrait = FlxDestroyUtil.destroy(rightPortrait);
        speechBubble = FlxDestroyUtil.destroy(speechBubble);

        leftPortrait = new EditorSprite();
        rightPortrait = new EditorSprite();
        speechBubble = new EditorSprite();

        leftPortrait.implementXML(safelyGetAssetInfo("xml", totalSprites[_info.info[dialogueScene].leftPortrait.assetID]));
        rightPortrait.implementXML(safelyGetAssetInfo("xml", totalSprites[_info.info[dialogueScene].rightPortrait.assetID]));
        speechBubble.implementXML(safelyGetAssetInfo("xml", totalSprites[_info.info[dialogueScene].speechBubble.assetID]));

        leftPortrait.implementBitmap(safelyGetAssetInfo("sprite", totalSprites[_info.info[dialogueScene].leftPortrait.assetID]));
        rightPortrait.implementBitmap(safelyGetAssetInfo("sprite", totalSprites[_info.info[dialogueScene].rightPortrait.assetID]));
        speechBubble.implementBitmap(safelyGetAssetInfo("sprite", totalSprites[_info.info[dialogueScene].speechBubble.assetID]));

        speechBubble.defaultCompiler = function() {
            speechBubble.frames = Paths.getSparrowAtlas("speech_bubble_talking", "shared");
            speechBubble.animation.addByPrefix("normal", "speech bubble normal", 24, true);
            speechBubble.playAnim("normal");
        }

        add(leftPortrait);
        add(rightPortrait);
        add(speechBubble);

        leftPortrait.compileSprite();
        rightPortrait.compileSprite();
        speechBubble.compileSprite();

        leftPortrait.setGraphicSize(Std.int(leftPortrait.width * _info.info[dialogueScene].leftPortrait.size));
        rightPortrait.setGraphicSize(Std.int(leftPortrait.width * _info.info[dialogueScene].rightPortrait.size));
        speechBubble.setGraphicSize(Std.int(speechBubble.width * _info.info[dialogueScene].speechBubble.size));

        leftPortrait.updateHitbox();
        rightPortrait.updateHitbox();
        speechBubble.updateHitbox();
        
        leftPortrait.x = _info.info[dialogueScene].leftPortrait.x;
        leftPortrait.y = _info.info[dialogueScene].leftPortrait.y;
        rightPortrait.x = _info.info[dialogueScene].rightPortrait.x;
        rightPortrait.y = _info.info[dialogueScene].rightPortrait.y;
        speechBubble.x = _info.info[dialogueScene].speechBubble.x;
        speechBubble.y = _info.info[dialogueScene].speechBubble.y;

        leftPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        rightPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        speechBubble.antialiasing = SaveData.getData(SaveType.GRAPHICS);

        if(thisSprite != null) {
            thisSprite.text = "Selected sprite: " + dialogueSpriteSelector.selectedLabel;
        }

        if(curSprite == null) {
            curSprite = "speech bubble";
        }

        if(spriteSelector != null) {
            var tempSelected:String = spriteSelector.selectedLabel;
            spriteSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(getSpriteNames(), true));
            spriteSelector.selectedLabel = tempSelected;
        }

        if(dialogueAssetSelector != null) {
            var tempSelected:String = dialogueAssetSelector.selectedLabel;
            dialogueAssetSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(getSpriteNames(), true));
            dialogueAssetSelector.selectedLabel = tempSelected;
        }

        if(animSourceSelector != null) {
            animSourceSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(getSpriteAnimations(dialogueSpriteSelector.selectedLabel), true));
        }

        if(animSelector != null) {
            animSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(getSprAnimDataName(dialogueSpriteSelector.selectedLabel), true));
        }

        refreshDisplayText();
    }

    var displayText:FlxText;

    function refreshDisplayText(text:String = ""):Void {
        if(displayText != null) {
            displayText.setPosition(displayText.x + speechBubble.x + 100, displayText.y + speechBubble.y + 100);

            if(text.trim() != "") {
                displayText.text = text;
                //displayText.resetText(text);
                //displayText.start(0.04 / _info.info[dialogueScene].speed, true);
            }
        }else {
            displayText = new FlxText(242, 460, Std.int(FlxG.width * 0.6), "Hello", _info.info[dialogueScene].textSize);
            displayText.font = Paths.font("PhantomMuff-Full-Letters-1.1.5.ttf");
            displayText.color = FlxColor.BLACK;
            add(displayText);
        }
    }

    var dialogueSpriteSelector:FlxUIDropDownMenu;
    var dialogueAssetSelector:FlxUIDropDownMenu;

    function createDialogueUI():Void {
        var tab_group_dialogue = new FlxUI(null, UI_thingy);
        tab_group_dialogue.name = "Dialogue";

        var instructionSprite:FlxText = new FlxText(10, 10, "Select sprite");

        dialogueSpriteSelector = new FlxUIDropDownMenu(10, 30, FlxUIDropDownMenu.makeStrIdLabelArray(["speech bubble", "left portrait", "right portrait"], true), function(choose:String) {
            changeSprite = true;
        });
        dialogueSpriteSelector.selectedLabel = "speech bubble";

        dialogueAssetSelector = new FlxUIDropDownMenu(10 + dialogueSpriteSelector.x + dialogueSpriteSelector.width, 30, FlxUIDropDownMenu.makeStrIdLabelArray(getSpriteNames(), true), function(choose:String) {
            //changeSprite = true;
        });
        dialogueAssetSelector.selectedLabel = getSpriteNames()[0];

        var attachAssets:FlxUIButton = new FlxUIButton(10, dialogueSpriteSelector.y + dialogueSpriteSelector.height + 10, "Attach Asset\nTo Sprite", function() {
            if(dialogueAssetSelector.selectedLabel.trim() == "") {
                return;
            }

            switch(dialogueSpriteSelector.selectedLabel) {
                case "speech bubble": _info.info[dialogueScene].speechBubble.assetID = getSpriteNames().indexOf(dialogueAssetSelector.selectedLabel);
                case "right portrait": _info.info[dialogueScene].rightPortrait.assetID = getSpriteNames().indexOf(dialogueAssetSelector.selectedLabel);
                case "left portrait": _info.info[dialogueScene].leftPortrait.assetID = getSpriteNames().indexOf(dialogueAssetSelector.selectedLabel);
                default: return;
            }

            changeSprite = true;
        });
        attachAssets.color = FlxColor.LIME;
        attachAssets.label.color = FlxColor.WHITE;
        attachAssets.resize(attachAssets.width, attachAssets.height * 1.5);

        var instructionAsset:FlxText = new FlxText(dialogueAssetSelector.x, 10, "Select asset");

        tab_group_dialogue.add(instructionSprite);
        tab_group_dialogue.add(instructionAsset);
        tab_group_dialogue.add(dialogueSpriteSelector);
        tab_group_dialogue.add(dialogueAssetSelector);
        tab_group_dialogue.add(attachAssets);

        UI_thingy.addGroup(tab_group_dialogue);
    }

    var spriteSelector:FlxUIDropDownMenu;
    var unableLabel:FlxText;

    function createDisplayUI():Void {
        var tab_group_display = new FlxUI(null, UI_thingy);
		tab_group_display.name = "E Sprites";

        var instructions:FlxText = new FlxText(10, 10, "Select asset from the drop down menu to modify");

        spriteSelector = new FlxUIDropDownMenu(10, 30, FlxUIDropDownMenu.makeStrIdLabelArray(getSpriteNames(), true), function(choose:String) {
            //changeSprite = true;
        });
        spriteSelector.selectedLabel = getSpriteNames()[0];

        var getXML:FlxUIButton = new FlxUIButton(spriteSelector.width + spriteSelector.x + 20, 30, "Import XML", function() {
            fileStatus = OVERRIDE;
            fileType = [".xml"];

            _file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        var getPNG:FlxUIButton = new FlxUIButton(getXML.x, 5 + getXML.y + getXML.height, "Import PNG", function() {
            fileStatus = OVERRIDE;
            fileType = [".png"];

            _file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        unableLabel = new FlxText(10, 50, "");
		unableLabel.color = FlxColor.RED;

        var inputName:FlxUIInputText = new FlxUIInputText(getXML.x, getPNG.y + getPNG.height + 20, 80, "", 8);

        var createAsset:FlxUIButton = new FlxUIButton(getXML.x, inputName.y + inputName.height + 5, "Create Asset", function() {
            if(inputName.text.trim() != "") {
                totalSprites.push({
                    name: inputName.text,
                    spriteData: null,
                    xmlData: null
                });
            }

            inputName.text = "";
            changeSprite = true;
        });
        createAsset.color = FlxColor.GREEN;
        createAsset.label.color = FlxColor.WHITE;

        var nameText:FlxText = new FlxText(0, inputName.y, "Asset Name: ");
        nameText.x = inputName.x - 70;

        tab_group_display.add(instructions);
        tab_group_display.add(spriteSelector);
        tab_group_display.add(getXML);
        tab_group_display.add(getPNG);
        tab_group_display.add(unableLabel);
        tab_group_display.add(inputName);
        tab_group_display.add(createAsset);
        tab_group_display.add(nameText);

        UI_thingy.addGroup(tab_group_display);
    }

    var thisSprite:FlxText;

    var animSourceSelector:FlxUIDropDownMenu;
    var animSelector:FlxUIDropDownMenu;

    var inputAnimName:FlxUIInputText;
    var framerateStepper:FlxUINumericStepper;
    var loopedCheckbox:FlxUICheckBox;

    function createAnimationUI():Void {
        var tab_group_animation = new FlxUI(null, UI_thingy);
        tab_group_animation.name = "F Animation";

        thisSprite = new FlxText(10, 10, "Selected sprite: " + dialogueSpriteSelector.selectedLabel);

        animSelector = new FlxUIDropDownMenu(10, 60, FlxUIDropDownMenu.makeStrIdLabelArray([""], true), function(choose:String) {
            //empty
        });

        animSourceSelector = new FlxUIDropDownMenu(142, 60, FlxUIDropDownMenu.makeStrIdLabelArray([""], true), function(choose:String) {
            //empty
        });

        var animSourceListTxt:FlxText = new FlxText(142, 40, "Select source animation");
        var animListTxt:FlxText = new FlxText(10, 40, "Select animation");

        var createAnimButton:FlxUIButton = new FlxUIButton(10, 200, "Create Animation", function() {
            if(inputAnimName == null) {
                return;
            }

            if(inputAnimName.text.trim() == "") {
                return;
            }

            if(framerateStepper == null) {
                return;
            }

            if(loopedCheckbox == null) {
                return;
            }

            switch(dialogueSpriteSelector.selectedLabel) {
                case "speech bubble": _info.info[dialogueScene].speechBubble.animations.push({name: inputAnimName.text, prefix: animSourceSelector.selectedLabel, framerate: Std.int(framerateStepper.value), looped: loopedCheckbox.checked, offset: []});
                case "right portrait": _info.info[dialogueScene].rightPortrait.animations.push({name: inputAnimName.text, prefix: animSourceSelector.selectedLabel, framerate: Std.int(framerateStepper.value), looped: loopedCheckbox.checked, offset: []});
                case "left portrait": _info.info[dialogueScene].leftPortrait.animations.push({name: inputAnimName.text, prefix: animSourceSelector.selectedLabel, framerate: Std.int(framerateStepper.value), looped: loopedCheckbox.checked, offset: []});
                default: return;
            }

            inputAnimName.text = "";
            framerateStepper.value = 24;
            loopedCheckbox.checked = false;

            changeSprite = true;
        });
        createAnimButton.color = FlxColor.GREEN;
        createAnimButton.label.color = FlxColor.WHITE;
        createAnimButton.resize(createAnimButton.width, createAnimButton.height * 1.5);

        var refreshAnimButton:FlxUIButton = new FlxUIButton(createAnimButton.x + createAnimButton.width + 5, 200, "Play/Refresh Animation", function() {
            implementAnimToSprite(leftPortrait, "left portrait");
            implementAnimToSprite(rightPortrait, "right portrait");
            implementAnimToSprite(speechBubble, "speech bubble");

            if(animSelector.selectedLabel.trim() == "") {
                return;
            }

            switch(dialogueSpriteSelector.selectedLabel) {
                case "speech bubble": speechBubble.playAnim(animSelector.selectedLabel);
                case "right portrait": rightPortrait.playAnim(animSelector.selectedLabel);
                case "left portrait": leftPortrait.playAnim(animSelector.selectedLabel);
                default: return;
            }
        });
        refreshAnimButton.color = FlxColor.LIME;
        refreshAnimButton.label.color = FlxColor.WHITE;
        refreshAnimButton.resize(refreshAnimButton.width, refreshAnimButton.height * 1.5);

        inputAnimName = new FlxUIInputText(10, createAnimButton.y + createAnimButton.height + 10, 80, "");
        var animNameText:FlxText = new FlxText(inputAnimName.x + inputAnimName.width + 5, inputAnimName.y, "Animation Name");

        framerateStepper = new FlxUINumericStepper(10, inputAnimName.y + inputAnimName.height + 10, 1, 24, 0, 60);
        framerateStepper.name = "info_framerate";

        var framerateText:FlxText = new FlxText(framerateStepper.x + framerateStepper.width + 10, framerateStepper.y, "Framerate");

        loopedCheckbox = new FlxUICheckBox(10, framerateStepper.y + framerateStepper.height + 10, null, null, "Looped", 50);
        loopedCheckbox.checked = false;

        tab_group_animation.add(thisSprite);
        tab_group_animation.add(animSourceSelector);
        tab_group_animation.add(animSelector);
        tab_group_animation.add(animSourceListTxt);
        tab_group_animation.add(animListTxt);
        tab_group_animation.add(createAnimButton);
        tab_group_animation.add(refreshAnimButton);
        tab_group_animation.add(inputAnimName);
        tab_group_animation.add(animNameText);
        tab_group_animation.add(framerateStepper);
        tab_group_animation.add(framerateText);
        tab_group_animation.add(loopedCheckbox);

        UI_thingy.addGroup(tab_group_animation);
    }

    var unableLabelText:FlxText;
    var narratorDropDown:FlxUIDropDownMenu;

    function createSceneUI():Void {
        var tab_group_scene = new FlxUI(null, UI_thingy);
        tab_group_scene.name = "Scene";

        var sceneStepper:FlxUINumericStepper = new FlxUINumericStepper(10, 30, 1, 1, 1, _info.info.length);
        sceneStepper.name = "info_scene";

        var selectSceneText:FlxText = new FlxText(sceneStepper.x + sceneStepper.width + 10, 30, "Dialogue Scene");

        var getTXT:FlxUIButton = new FlxUIButton(10, 60, "Import TXT", function() {
            fileStatus = DOCUMENT;
            fileType = [".txt"];

            _file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

            _file.browse();
        });

        var playDialogue:FlxUIButton = new FlxUIButton(10, getTXT.y + getTXT.height + 5, "Play Dialogue", function() {
            refreshDisplayText(_info.info[dialogueScene].text[1]);
        });
        playDialogue.color = FlxColor.LIME;
        playDialogue.label.color = FlxColor.WHITE;

        unableLabelText = new FlxText(getTXT.x, getTXT.y + getTXT.height + 25, "");
        unableLabelText.color = FlxColor.RED;

        narratorDropDown = new FlxUIDropDownMenu(getTXT.x + getTXT.width + 20, 60, FlxUIDropDownMenu.makeStrIdLabelArray(["left portrait", "right portrait"], true), function(choose:String) {

        });

        tab_group_scene.add(sceneStepper);
        tab_group_scene.add(selectSceneText);
        tab_group_scene.add(getTXT);
        tab_group_scene.add(playDialogue);
        tab_group_scene.add(narratorDropDown);
        tab_group_scene.add(unableLabelText);

        UI_thingy.addGroup(tab_group_scene);
    }

    function getSpriteAnimations(spriteName:String):Array<String> {
        var animation:Array<String>;

        switch(spriteName) {
            case "speech bubble": animation = speechBubble.getSourceAnimationName();
            case "right portrait": animation = rightPortrait.getSourceAnimationName();
            case "left portrait": animation = leftPortrait.getSourceAnimationName();
            default: animation = [];
        }

        if(animation.length == 0) {
            animation.push("");
        }

        return animation;
    }

    function getSprAnimDataName(spriteName:String):Array<String> {
        var animNames:Array<String> = [];
        var index = 0;

        var animHandler:Array<AnimationInfo>;
        
        switch(spriteName) {
            case "speech bubble": animHandler = _info.info[dialogueScene].speechBubble.animations;
            case "right portrait": animHandler = _info.info[dialogueScene].rightPortrait.animations;
            case "left portrait": animHandler = _info.info[dialogueScene].leftPortrait.animations;
            default: animHandler = [];
        }

        while(index < animHandler.length) {
            animNames.push(animHandler[index++].name);
        }

        if(animNames.length == 0) {
            animNames.push("");
        }

        return animNames;
    }

    function implementAnimToSprite(spr:EditorSprite, spriteName:String):Void {
        var index = 0;

        var animHandler:Array<AnimationInfo>;
        
        switch(spriteName) {
            case "speech bubble": animHandler = _info.info[dialogueScene].speechBubble.animations;
            case "right portrait": animHandler = _info.info[dialogueScene].rightPortrait.animations;
            case "left portrait": animHandler = _info.info[dialogueScene].leftPortrait.animations;
            default: animHandler = [];
        }

        spr.animation.destroyAnimations();

        while(index < animHandler.length) {
            spr.animation.addByPrefix(animHandler[index].name, animHandler[index].prefix, animHandler[index].framerate, animHandler[index].looped);

            index++;
        }
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

        if(id == FlxUINumericStepper.CHANGE_EVENT && (sender is FlxUINumericStepper)) {
            var nums:FlxUINumericStepper = cast sender;
			var wname = nums.name;

            if(wname == "info_scene") {
                if(dialogueScene != Std.int(nums.value) - 1) {
                    dialogueScene = Std.int(nums.value) - 1;
                    refreshDisplay();
                }
            }
        }
    }

    function safelyGetAssetInfo(value:String, file:DialogueFileData):ByteArray {
        if(file != null) {
            if(value == "sprite") {
                return file.spriteData;
            }else {
                return file.xmlData;
            }
        }

        return null;
    }

    function attachKeysToEditor(event:KeyboardEvent) {
        var key:FlxKey = event.keyCode;

        if(key == FlxKey.ESCAPE) {
            FlxG.switchState(new OptionsMenuState("editiors"));
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

        unableLabel.text = "";

        var foundFile:Bool = false;

        for(i in 0...fileType.length) {
            if(_file.type == fileType[i]) {
                foundFile = true;
            }
        }

        if(!foundFile) {
            unableLabel.text = "Unable to compile file:\n" + _file.name;
            unableLabelText.text = "Unable to compile file:\n" + _file.name;
            return;
        }

		switch(fileStatus) {
            case OVERRIDE:
                if(spriteSelector.selectedLabel.trim() == "") {
                    unableLabel.text = "Unable to compile file:\n" + _file.name + "\n\n" + "You must create an empty asset value.";
                    return;
                }

                if(fileType.contains(".xml")) {
                    for(i in 0...totalSprites.length) {
                        if(spriteSelector.selectedLabel == totalSprites[i].name) {
                            totalSprites[i].xmlData = _file.data;
                            break;
                        }
                    }
                }else if(fileType.contains(".png")) {
                    for(i in 0...totalSprites.length) {
                        if(spriteSelector.selectedLabel == totalSprites[i].name) {
                            totalSprites[i].spriteData = _file.data;
                            break;
                        }
                    }
                }

                refreshDisplay();

                fileType = [];
            case DOCUMENT:
                _info.info[dialogueScene].text[0] = narratorDropDown.selectedLabel;
                _info.info[dialogueScene].text[1] = _file.data.toString();

                fileType = [];
            default:
                return;
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

    override function destroy():Void {
        FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, attachKeysToEditor);

        super.destroy();
    }
}