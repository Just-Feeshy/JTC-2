package;

#if windows
import Discord.DiscordClient;
#end

import Song.SwagSong;
import Controls.Control;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxObject;
import flixel.FlxCamera;
import flixel.tweens.FlxTween;
import flixel.util.FlxAxes;
import flixel.input.gamepad.FlxGamepad;
import flixel.graphics.FlxGraphic;
import flixel.util.FlxGradient;
import flixel.ui.FlxBar;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUITabMenu;
import flixel.system.debug.interaction.tools.Pointer.GraphicCursorCross;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIInputText;
import flixel.util.FlxDestroyUtil;
import flixel.math.FlxMath;
import flixel.tweens.FlxEase;
import flixel.util.FlxTimer;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.IOErrorEvent;
import openfl.net.FileFilter;
import openfl.net.FileReference;
import openfl.utils.ByteArray;
import sys.FileSystem;
import sys.io.File;
import haxe.Json;

import Character;
import ModInitialize;
import Alphabet;
import Options;

#if json2object
import json2object.JsonParser;
#end

using StringTools;

enum FileType {
    CHARACTER;
    COLOR_MAPPING;
}

typedef PreloadJSON = Map<String, Array<Array<Float>>>;

class CharacterCreatorState extends MusicBeatState {
    private var isIn:Bool = true;
    private var UI_thingy:FlxUITabMenu;
    private var startTimer:FlxTimer;
    private var keyPress:Bool;
    private var shadowEntity:Character;
    private var character:Character;
    private var characterStorage:FlxTypedGroup<Character>;
    private var characterAutosave:Map<String, ConfigCharacters>;
    private var mapEditor:Map<String, Dynamic>;
    private var characterJSONs:Array<String> = new Array<String>();
    private var parser = new JsonParser<PreloadJSON>();
    private var healthBar:FlxBar;
    private var instrucTxt:FlxText;
    private var iconP1:HealthIcon;
    private var iconP2:HealthIcon;
    private var camCursor:FlxSprite;
    private var health:Float = 1;

    private final chooseSkin:Int = 0;

    private var colorSway:Float = 0;

    private var _character:ConfigCharacters;

    private var camHUD:FlxCamera;
    private var camGame:FlxCamera;

    private var camFollow:FlxObject;
    private var camPos:FlxPoint;

    private var changeCharacter:Bool;

    private var _file:FileReference;

    override function create() {
        FlxG.mouse.visible = true;

        camHUD = new FlxCamera();
        camGame = new FlxCamera();
        camHUD.bgColor.alpha = 0;
        camGame.bgColor.alpha = 0;

        FlxG.cameras.add(camGame);
        FlxG.cameras.add(camHUD);

        FlxCamera.defaultCameras = [camHUD];

        mapEditor = [
            "character" => [[0,0,0,0,0,0,0,0]],
            "health" => 0
        ];

        characterAutosave = new Map<String, ConfigCharacters>();

        var tabs = [
			{name: "Display", label: 'Display'},
            {name: "E Animations", label: 'Animations'},
            {name: "Export", label: 'Export'}
		];

        #if windows
		DiscordClient.changePresence("Making Character", null);
		#end

        createDisplay();

        UI_thingy = new FlxUITabMenu(null, tabs, true);

		UI_thingy.resize(400, 400);
		UI_thingy.x = Std.int(FlxG.width / 1.5);
        UI_thingy.screenCenter(Y);
        UI_thingy.y -= Std.int(UI_thingy.height / 4);
        UI_thingy.scrollFactor.set();

        UI_thingy.cameras = [camHUD];

		add(UI_thingy);

        if(File.getContent(Paths.mora("skins", "json")).length > 48)
            mapEditor = cast parser.fromJson(File.getContent(Paths.mora("skins", "json")), "skins.json");

        for(i in 0...FileSystem.readDirectory("assets/characters").length) {
            characterJSONs.push(FileSystem.readDirectory("assets/characters")[i].split(".")[0]);
            characterAutosave.set(FileSystem.readDirectory("assets/characters")[i].split(".")[0],
            Character.loadInfo("characters/"+FileSystem.readDirectory("assets/characters")[i].split(".")[0]));
            DefaultHandler.setupUpdateInfo(characterAutosave.get(FileSystem.readDirectory("assets/characters")[i].split(".")[0]));
        }

        for(i in 0...FileSystem.readDirectory("mod_assets/characters").length) {
            characterJSONs.push(FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0]);
            characterAutosave.set(FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0],
            Character.loadInfo("characters/"+FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0]));
            DefaultHandler.setupUpdateInfo(characterAutosave.get(FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0]));
        }

        addDisplayUI();
        addAnimationsUI();
        addExportUI();

        instrucTxt = new FlxText(8, 16, FlxG.width,
            "Mouse Wheel | Q/E - Camera Zoom\n" +
            "Keybinds - Sing Direction\n" +
            "ESCAPE - To Exit",
        16);

        instrucTxt.cameras = [camHUD];

        add(instrucTxt);
        super.create();
    }

    function createDisplay() {
		var bg:FlxSprite = new FlxSprite(-600, -200).loadGraphic(Paths.image('stageback'));
		bg.antialiasing = true;
	    bg.active = false;
		add(bg);

		var stageFront:FlxSprite = new FlxSprite(-650, 600).loadGraphic(Paths.image('stagefront'));
		stageFront.setGraphicSize(Std.int(stageFront.width * 1.1));
		stageFront.updateHitbox();
		stageFront.antialiasing = true;
		stageFront.active = false;
		add(stageFront);

		var stageCurtains:FlxSprite = new FlxSprite(-500, -300).loadGraphic(Paths.image('stagecurtains'));
		stageCurtains.setGraphicSize(Std.int(stageCurtains.width * 0.9));
		stageCurtains.updateHitbox();
		stageCurtains.antialiasing = true;
		stageCurtains.active = false;

        characterStorage = new FlxTypedGroup<Character>();
        add(characterStorage);

        character = new Character(440, 100, "bf", true);
        character.updateFinalized(character.getScreenCenter(X), 100);
        characterStorage.add(character);
        
		add(stageCurtains);
        camGame.zoom = 0.9;

        camPos = new FlxPoint(character.getGraphicMidpoint().x, character.getGraphicMidpoint().y);
        camFollow = new FlxObject(0, 0, 1, 1);

        character.refresh(character.curCharacter, camPos);

        if(character.flipX)
            character.flipX = false;

        camFollow.setPosition(camPos.x, camPos.y);
        add(camFollow);

        camGame.follow(camFollow, LOCKON, 0.04);
        camGame.focusOn(camFollow.getPosition());

        var healthBarBG:FlxSprite = new FlxSprite(0, FlxG.height * 0.9).loadGraphic(Paths.image('healthBar'));
        healthBarBG.screenCenter(X);
        healthBarBG.scrollFactor.set();
        add(healthBarBG);

        healthBar = new FlxBar(healthBarBG.x + 4, healthBarBG.y + 4, RIGHT_TO_LEFT, Std.int(healthBarBG.width - 8), Std.int(healthBarBG.height - 8), this,
			'health', 0, 2);
        healthBar.percent = 50;
        healthBar.scrollFactor.set();
        add(healthBar);

        iconP1 = new HealthIcon("bf", true);
        iconP1.y = healthBar.y - (iconP1.height * 0.5);
        iconP1.setGraphicSize(Std.int(FlxMath.lerp(150, iconP1.width, 0.50)));
        iconP1.updateHitbox();
		add(iconP1);

        iconP2 = new HealthIcon("dad", false);
        iconP2.y = healthBar.y - (iconP2.height * 0.5);
        iconP2.setGraphicSize(Std.int(FlxMath.lerp(150, iconP1.width, 0.50)));
        iconP2.updateHitbox();
		add(iconP2);

        var camCursorGraphic:FlxGraphic = FlxGraphic.fromClass(GraphicCursorCross);
        camCursor = new FlxSprite().loadGraphic(camCursorGraphic);
        camCursor.setGraphicSize(40, 40);
        camCursor.updateHitbox();
        camCursor.color = FlxColor.WHITE;
        add(camCursor);

        updateCursorPos();

        iconP1.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01) - 26);
		iconP2.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01)) - (iconP2.width - 26);

        bg.cameras = [camGame];
        stageFront.cameras = [camGame];
        stageCurtains.cameras = [camGame];
        character.cameras = [camGame];
        camCursor.cameras = [camGame];

        healthBarBG.cameras = [camHUD];
        healthBar.cameras = [camHUD];
        iconP1.cameras = [camHUD];
        iconP2.cameras = [camHUD];
    }

    var tab_group_display:FlxUI;

    var redMulti:FlxUINumericStepper;
    var greenMulti:FlxUINumericStepper;
    var blueMulti:FlxUINumericStepper;
    var alphaMulti:FlxUINumericStepper;

    var redOffset:FlxUINumericStepper;
    var greenOffset:FlxUINumericStepper;
    var blueOffset:FlxUINumericStepper;
    var alphaOffset:FlxUINumericStepper;

    var redColor:FlxUINumericStepper;
    var blueColor:FlxUINumericStepper;
    var greenColor:FlxUINumericStepper;

    var plrHealth:FlxUINumericStepper;

    var xInput:FlxUINumericStepper;
    var yInput:FlxUINumericStepper;
    var xCamInput:FlxUINumericStepper;
    var yCamInput:FlxUINumericStepper;

    var normalIxon:FlxUINumericStepper;
    var dedIxon:FlxUINumericStepper;
    var hapeyIxon:FlxUINumericStepper;

    var characterSelector:FlxUIDropDownMenu;

    var fileName:FinderUIInputText;
    var iconFileName:FinderUIInputText;

    function addDisplayUI():Void {
        var tab_group_display = new FlxUI(null, UI_thingy);
		tab_group_display.name = 'Display';

        fileName = new FinderUIInputText(10, 50, 80, "", 8);
        fileName.text = characterAutosave.get(character.curCharacter).file;

        fileName.textUpdateCallback = function(text:String) {
            if(FileSystem.exists(Paths.getPreloadPath("images/" + text))) {
                return true;
            }

            return false;
        }

        var updateFileButton:FlxUIButton = new FlxUIButton(10, 50 + fileName.height + 5, "Update\nCharacter", function() {
            characterAutosave.get(character.curCharacter).file = fileName.text;
            changeCharacter = true;
        });
        updateFileButton.resize(updateFileButton.width, updateFileButton.height * 1.5);

        iconFileName = new FinderUIInputText(10, updateFileButton.y + updateFileButton.height + 40, 80, "", 8);
        iconFileName.text = characterAutosave.get(character.curCharacter).iconFile;

        iconFileName.textUpdateCallback = function(text:String) {
            if(Paths.image(text) != null) {
                return true;
            }

            return false;
        }

        var updateIconFileButton:FlxUIButton = new FlxUIButton(10, 50 + iconFileName.height + 5, "Update Icon", function() {
            characterAutosave.get(character.curCharacter).iconFile = iconFileName.text;

            if(normalIxon != null) {
                normalIxon.value = 0;
            }

            if(dedIxon != null) {
                dedIxon.value = 0;
            }

            if(hapeyIxon != null) {
                hapeyIxon.value = 0;
            }


        });

        var fileText:FlxText = new FlxText(fileName.width + 15, 50, 0, "XML File");
        var iconFileText:FlxText = new FlxText(fileName.width + 15, iconFileName.y - 5, 0, "PNG File");

        var iconTextColor:FlxText = new FlxUIText(10, updateFileButton.y + updateFileButton.height + 20, 0, "Icon Stuff");

        var bfTextColor:FlxText = new FlxUIText(10, 30, 0, "Character Stuff");
        redMulti = new FlxUINumericStepper(10, 60, 0.1, 1, 0, 255, 1);
        greenMulti = new FlxUINumericStepper(10, 80, 0.1, 1, 0, 255, 1);
        blueMulti = new FlxUINumericStepper(10, 100, 0.1, 1, 0, 255, 1);
        alphaMulti = new FlxUINumericStepper(10, 120, 0.1, 1, 0, 255, 1);
        redOffset = new FlxUINumericStepper(10, 150, 1, 0, 0, 255, 0);
        greenOffset = new FlxUINumericStepper(10, 170, 1, 0, 0, 255, 0);
        blueOffset = new FlxUINumericStepper(10, 190, 1, 0, 0, 255, 0);
        alphaOffset = new FlxUINumericStepper(10, 150, 1, 0, 0, 255, 0);

        redColor = new FlxUINumericStepper(210, 60, 1, 0, 0, 255, 0);
        blueColor = new FlxUINumericStepper(210, 75, 1, 0, 0, 255, 0);
        greenColor = new FlxUINumericStepper(210, 90, 1, 0, 0, 255, 0);

        plrHealth = new FlxUINumericStepper(210, 50, 10, 50, 10, 100, 0);
        plrHealth.value = health * 50;
        plrHealth.name = "health";

        characterSelector = new FlxUIDropDownMenu(210, 225, FlxUIDropDownMenu.makeStrIdLabelArray(characterJSONs, true), function(choose:String) {
            changeCharacter = true;
        });
        characterSelector.selectedLabel = character.curCharacter;

        var centerCamButton:FlxUIButton = new FlxUIButton(characterSelector.x - 90, characterSelector.y, "Center Camera", function() {
            camPos.set(character.getGraphicMidpoint().x, character.getGraphicMidpoint().y);
            camFollow.setPosition(camPos.x, camPos.y);
        });

        var characterName:FlxUIInputText = new FlxUIInputText(10, characterSelector.y, 80, "", 8);

        var createCharacterButton:FlxUIButton = new FlxUIButton(10, characterSelector.y + 20, "New Character", function() {
            if(!characterJSONs.contains(characterName.text) && characterName.text.length > 0) {
                changeCharacter = true;

                characterJSONs.push(characterName.text);
                characterSelector.setData(FlxUIDropDownMenu.makeStrIdLabelArray(characterJSONs, true));

                if(characterAutosave.get(characterName.text) == null) {
                    characterAutosave.set(characterName.text, {
                        file: "",
                        animations: [],
                        position: [
                            "x" => 0,
                            "y" => 0,
                            "camPosX" => 0,
                            "camPosY" => 0
                        ],
                        icon: [10, 11],
                        playAnim: "",
                        isPlayer: false,
                        pixel: false,

                        iconFile: "iconGrid",
				        clippingAdjustment: []
                    });
                }

                characterSelector.selectedLabel = characterName.text;
                getEvent("click_button", this, Std.string(characterJSONs.indexOf(characterName.text)));
                characterName.text = "";
            }    
        });

        var flipSpriteButton:FlxUIButton = new FlxUIButton(centerCamButton.x, createCharacterButton.y, "Flip Sprite", function() {
            if(character != null) {
                character.flipX = !character.flipX;
            }
        });

        var characterSelectorText:FlxText = new FlxText(characterSelector.x, characterSelector.y - 15, 0, 'Character Selector:');
        var characterNameText:FlxText = new FlxText(characterName.x - 2, characterName.y - 15, 0, 'Character Name:');

        xInput = new FlxUINumericStepper(10, 280, 1, 0, -999, 999, 0);
        xInput.value = characterAutosave.get(character.curCharacter).position.get('x');
        xInput.name = 'x_pos';

        yInput = new FlxUINumericStepper(10, 295, 1, 0, -999, 999, 0);
        yInput.value = characterAutosave.get(character.curCharacter).position.get('y');
        yInput.name = 'y_pos';

        xCamInput = new FlxUINumericStepper(10, 310, 1, 0, -999, 999, 0);
        xCamInput.value = characterAutosave.get(character.curCharacter).position.get('camPosX');
        xCamInput.name = 'x_cam_pos';

        yCamInput = new FlxUINumericStepper(10, 325, 1, 0, -999, 999, 0);
        yCamInput.value = characterAutosave.get(character.curCharacter).position.get('camPosY');
        yCamInput.name = 'y_cam_pos';

        normalIxon = new FlxUINumericStepper(characterSelector.x - 90, 280, 1, 0, 0, 100, 0);
        normalIxon.value = characterAutosave.get(character.curCharacter).icon[0];
        normalIxon.name = "normal_icon";

        dedIxon = new FlxUINumericStepper(characterSelector.x - 90, 295, 1, 0, 0, 100, 0);
        dedIxon.value = characterAutosave.get(character.curCharacter).icon[1];
        dedIxon.name = "ded_icon";

        hapeyIxon = new FlxUINumericStepper(characterSelector.x - 90, 310, 1, 0, 0, 100, 0);
        hapeyIxon.value = characterAutosave.get(character.curCharacter).icon[2];
        hapeyIxon.name = "hapey_icon";

        var xInputTxt:FlxText = new FlxText(xInput.x + 65, xInput.y, "X");
        var yInputTxt:FlxText = new FlxText(yInput.x + 65, yInput.y, "Y");
        var xCamInputTxt:FlxText = new FlxText(xCamInput.x + 65, xCamInput.y, "Cam X");
        var yCamInputTxt:FlxText = new FlxText(yCamInput.x + 65, yCamInput.y, "Cam Y");

        var normalIxonTxt:FlxText = new FlxText(normalIxon.x + 65, normalIxon.y, "Normal Icon");
        var dedIxonTxt:FlxText = new FlxText(dedIxon.x + 65, dedIxon.y, "Dead Icon");
        var hapeyIxonTxt:FlxText = new FlxText(hapeyIxon.x + 65, hapeyIxon.y, "Hapey Icon");

        mapEditor.set("health", CoolUtil.calculateAverageColor(iconP1.updateFramePixels()));

        setColorOptions(mapEditor.get("health"));

        healthBar.percent = 50;

        var hpTextChange:FlxText = new FlxUIText(208, 30, 0, "Health Bar Settings");

        redMulti.name = "redMulti";
        greenMulti.name = "greenMulti";
        blueMulti.name = "blueMulti";
        alphaMulti.name = "alphaMulti";
        redOffset.name = "redOffset";
        greenOffset.name = "greenOffset";
        blueOffset.name = "blueOffset";
        alphaOffset.name = "alphaOffset";
        redColor.name = "redColor";
        blueColor.name = "blueColor";
        greenColor.name = "greenColor";

        tab_group_display.add(bfTextColor);
        tab_group_display.add(centerCamButton);
        tab_group_display.add(characterName);
        tab_group_display.add(createCharacterButton);
        tab_group_display.add(flipSpriteButton);
        tab_group_display.add(characterSelectorText);
        tab_group_display.add(characterNameText);
        tab_group_display.add(hpTextChange);
        tab_group_display.add(plrHealth);

        tab_group_display.add(xInput);
        tab_group_display.add(xInputTxt);
        tab_group_display.add(yInput);
        tab_group_display.add(yInputTxt);
        tab_group_display.add(xCamInput);
        tab_group_display.add(xCamInputTxt);
        tab_group_display.add(yCamInput);
        tab_group_display.add(yCamInputTxt);
        tab_group_display.add(normalIxon);
        tab_group_display.add(normalIxonTxt);
        tab_group_display.add(dedIxon);
        tab_group_display.add(dedIxonTxt);
        tab_group_display.add(hapeyIxon);
        tab_group_display.add(hapeyIxonTxt);
        tab_group_display.add(characterSelector);
        tab_group_display.add(fileName);
        tab_group_display.add(fileText);
        tab_group_display.add(iconFileName);
        tab_group_display.add(iconFileText);
        tab_group_display.add(iconTextColor);
        tab_group_display.add(updateFileButton);

        UI_thingy.addGroup(tab_group_display);
    }

    var animationDrop:FlxUIDropDownMenu;
    var lockAnimCheck:FlxUICheckBox;
    var prefixInput:FlxUIInputText;
    var framerateChange:FlxUINumericStepper;
    var loopAnim:FlxUICheckBox;

    var offsetXInput:FlxUINumericStepper;
    var offsetYInput:FlxUINumericStepper;

    var checkPlayable:FlxUICheckBox;
    var canBePixel:FlxUICheckBox;

    var playCustomAnim:Bool = false;
    
    function addAnimationsUI():Void {
        var tab_group_animations = new FlxUI(null, UI_thingy);
        tab_group_animations.name = 'E Animations';

        var changeButton:FlxUIButton = new FlxUIButton(40, 40, "Refresh", function() {
            changeCharacter = true;

            if(character._info.animations.get(animationDrop.selectedLabel) != null) {
                character._info.animations.get(animationDrop.selectedLabel).prefix = prefixInput.text;
                character._info.animations.get(animationDrop.selectedLabel).framerate = Std.int(framerateChange.value);
                character._info.animations.get(animationDrop.selectedLabel).looped = loopAnim.checked;
                character._info.animations.get(animationDrop.selectedLabel).offset[0] = Std.int(offsetXInput.value);
                character._info.animations.get(animationDrop.selectedLabel).offset[1] = Std.int(offsetYInput.value);
            }

            character._info.isPlayer = checkPlayable.checked;
            character._info.pixel = canBePixel.checked;

            characterAutosave.set(character.curCharacter, character._info);
            getEvent("click_button", this, Std.string(characterJSONs.indexOf(characterSelector.selectedLabel)));
        });

        animationDrop = new FlxUIDropDownMenu(240, 20, FlxUIDropDownMenu.makeStrIdLabelArray(character.animations, true), function(choose:String) {
            updateStuff();
        });

        if(character.animations.length > 0) {
            animationDrop.selectedLabel = character.animation.curAnim.name;
        }
        
        var animationDropTxt:FlxText = new FlxText(240, animationDrop.y - 15, "Custom Animation:");

        var playAnimButton:FlxUIButton = new FlxUIButton(40, 70, "Play Animation", function() {
            playCustomAnim = true;

            character.playAnim(animationDrop.selectedLabel);
        });

        var stopAnimButton:FlxUIButton = new FlxUIButton(40, playAnimButton.y + 20, "Stop Animation", function() {
            playCustomAnim = false;
        });

        var deleteAnimButton:FlxUIButton = new FlxUIButton(40, stopAnimButton.y + 25, "Delete Animation", function() {
            if(character.animations.length > 0) {
                changeCharacter = true;

                characterAutosave.get(character.curCharacter).animations.remove(animationDrop.selectedLabel);
                character.animations.remove(animationDrop.selectedLabel);

                animationDrop.selectedLabel = character.animations[character.animations.length - 1];

                prefixInput.text = character._info.animations.get(character.animations[character.animations.length - 1]).prefix;
                framerateChange.value = character._info.animations.get(character.animations[character.animations.length - 1]).framerate;
                loopAnim.checked = character._info.animations.get(character.animations[character.animations.length - 1]).looped;
                offsetXInput.value = character._info.animations.get(character.animations[character.animations.length - 1]).offset[0];
                offsetYInput.value = character._info.animations.get(character.animations[character.animations.length - 1]).offset[1];

                getEvent("click_button", this, Std.string(characterJSONs.indexOf(character.curCharacter)));
            }
        });

        deleteAnimButton.color = 0xFFFF4444;
        deleteAnimButton.label.color = FlxColor.WHITE;
        deleteAnimButton.resize(deleteAnimButton.width, deleteAnimButton.height * 1.5);

        var animNameInput:FlxUIInputText = new FlxUIInputText(140, 20, 80, "", 8);
        var animNameTxt:FlxText = new FlxText(animNameInput.x, animNameInput.y - 15, "Anim Name:");

        var newAnimButton:FlxUIButton = new FlxUIButton(140, 40, "Create New", function() {
            if(!character.animations.contains(animNameInput.text)) {
                changeCharacter = true;

                characterAutosave.get(character.curCharacter).animations.set(animNameInput.text, {
                    name: "",
                    prefix: prefixInput.text.trim(),
                    framerate: Std.int(framerateChange.value),
                    looped: loopAnim.checked,
                    offset: [Std.int(offsetXInput.value), Std.int(offsetYInput.value)]
                });

                getEvent("click_button", this, Std.string(characterJSONs.indexOf(character.curCharacter)));
                animationDrop.selectedLabel = animNameInput.text;

                prefixInput.text = character._info.animations.get(animNameInput.text).prefix;
                framerateChange.value = character._info.animations.get(animNameInput.text).framerate;
                loopAnim.checked = character._info.animations.get(animNameInput.text).looped;
                offsetXInput.value = character._info.animations.get(animNameInput.text).offset[0];
                offsetYInput.value = character._info.animations.get(animNameInput.text).offset[1];
            }    
        });

        var shadowMan:FlxUIButton = new FlxUIButton(140, newAnimButton.y + 30, "Create Shadow", function() {
            changeCharacter = true;

            if(shadowEntity != null) {
                characterStorage.remove(shadowEntity, true);
                shadowEntity.destroy();
                shadowEntity = null;
            }

            shadowEntity = new Character(character.x, character.y, character.curCharacter, true, character._info);
            shadowEntity.flipX = character.flipX;
            shadowEntity.isPlayer = true;
            shadowEntity.alpha = 0.5;
            characterStorage.add(shadowEntity);

            shadowEntity.animation.play(character.animation.curAnim.name);
            shadowEntity.animation.stop();
            shadowEntity.animation.curAnim.curFrame = shadowEntity.animation.curAnim.numFrames;

            shadowEntity.cameras = [camGame];

            getEvent("click_button", this, Std.string(characterJSONs.indexOf(character.curCharacter)));
        });

        lockAnimCheck = new FlxUICheckBox(40, shadowMan.y + 80, null, null, "Lock Animation", 80);

        var animationSettings:FlxText = new FlxUIText(10, 180, 0, "Animation Config", 11);

        prefixInput = new FlxUIInputText(10, 210, 80, character._info.animations.get(animationDrop.selectedLabel).prefix, 8);
        var prefixInputTxt:FlxText = new FlxText(95, prefixInput.y, "prefix");

        framerateChange = new FlxUINumericStepper(10, 230, 1, 0, -600, 600, 0);
        framerateChange.value = character._info.animations.get(animationDrop.selectedLabel).framerate;
        framerateChange.name = "framerate";

        var framerateChangeTxt:FlxText = new FlxText(70, framerateChange.y, "framerate");

        loopAnim = new FlxUICheckBox(10, 250, null, null, "Looped", 50);

        offsetXInput = new FlxUINumericStepper(10, 280, 1, 0, -999, 999, 0);
        offsetXInput.value = character._info.animations.get(animationDrop.selectedLabel).offset[0];
        offsetXInput.name = "x_offset";

        var offsetXInputTxt:FlxText = new FlxText(70, offsetXInput.y, "offset X");

        offsetYInput = new FlxUINumericStepper(10, 295, 1, 0, -999, 999, 0);
        offsetYInput.value = character._info.animations.get(animationDrop.selectedLabel).offset[1];
        offsetYInput.name = "y_offset";        

        var offsetYInputTxt:FlxText = new FlxText(70, offsetYInput.y, "offset Y");

        checkPlayable = new FlxUICheckBox(140, shadowMan.y + 50, null, null, "Is Flipped");
        checkPlayable.checked = characterAutosave.get(character.curCharacter).isPlayer;

        canBePixel = new FlxUICheckBox(140, shadowMan.y + 80, null, null, "Is Pixel");
        canBePixel.checked = characterAutosave.get(character.curCharacter).pixel;

        tab_group_animations.add(changeButton);
        tab_group_animations.add(animationDropTxt);
        tab_group_animations.add(playAnimButton);
        tab_group_animations.add(stopAnimButton);
        tab_group_animations.add(lockAnimCheck);
        tab_group_animations.add(animationSettings);
        tab_group_animations.add(prefixInput);
        tab_group_animations.add(prefixInputTxt);
        tab_group_animations.add(animNameInput);
        tab_group_animations.add(newAnimButton);
        tab_group_animations.add(animNameTxt);
        tab_group_animations.add(framerateChange);
        tab_group_animations.add(framerateChangeTxt);
        tab_group_animations.add(loopAnim);
        tab_group_animations.add(offsetXInput);
        tab_group_animations.add(offsetXInputTxt);
        tab_group_animations.add(offsetYInput);
        tab_group_animations.add(offsetYInputTxt);
        tab_group_animations.add(checkPlayable);
        tab_group_animations.add(canBePixel);
        tab_group_animations.add(shadowMan);
        tab_group_animations.add(animationDrop);
        tab_group_animations.add(deleteAnimButton);

        UI_thingy.addGroup(tab_group_animations);
    }

    function addExportUI():Void {
        var tab_group_export = new FlxUI(null, UI_thingy);
		tab_group_export.name = 'Export';

        var bfTextColor:FlxText = new FlxUIText(10, 30, 0, "Export", 11);

        var saveCharacter:FlxUIButton = new FlxUIButton(10, 60, "Character", function() {
            saveFile(CHARACTER);
        });

        var saveColors:FlxUIButton = new FlxUIButton(10, 80, "Color Map", function() {
            saveFile(COLOR_MAPPING);
        });

        tab_group_export.add(bfTextColor);
        tab_group_export.add(saveCharacter);
        //tab_group_export.add(saveColors);

        UI_thingy.addGroup(tab_group_export);
    }

    function updateStuff():Void {
        if(character._info.animations.get(animationDrop.selectedLabel) != null) {
            prefixInput.text = character._info.animations.get(animationDrop.selectedLabel).prefix;
            framerateChange.value = character._info.animations.get(animationDrop.selectedLabel).framerate;
            loopAnim.checked = character._info.animations.get(animationDrop.selectedLabel).looped;
            offsetXInput.value = character._info.animations.get(animationDrop.selectedLabel).offset[0];
            offsetYInput.value = character._info.animations.get(animationDrop.selectedLabel).offset[1];
        }else {
            prefixInput.text = "";
            framerateChange.value = 24;
            loopAnim.checked = false;
            offsetXInput.value = 0;
            offsetYInput.value = 0;
        }

        xInput.value = characterAutosave.get(character.curCharacter).position.get('x');
        yInput.value = characterAutosave.get(character.curCharacter).position.get('y');
        xCamInput.value = characterAutosave.get(character.curCharacter).position.get('camPosX');
        yCamInput.value = characterAutosave.get(character.curCharacter).position.get('camPosY');

        checkPlayable.checked = characterAutosave.get(character.curCharacter).isPlayer;
    }

    override function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void {
        if((id == FlxUIDropDownMenu.CLICK_EVENT || id == "click_button") && changeCharacter) {
            changeCharacter = false;

            characterStorage.remove(character, true);
            character.destroy();
            character = null;
            character = new Character(440, 100, characterJSONs[Std.parseInt(data)], true, characterAutosave.get(characterJSONs[Std.parseInt(data)]));

            character.flipX = false;

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            if(iconP1.iconCharacters.contains(characterJSONs[Std.parseInt(data)]))
                iconP1.animation.play(characterJSONs[Std.parseInt(data)]);
            else
                iconP1.animation.play('face');

            normalIxon.value = characterAutosave.get(character.curCharacter).icon[0];

            if(characterAutosave.get(character.curCharacter).icon.length > 1)
                dedIxon.value = characterAutosave.get(character.curCharacter).icon[1];
            else
                dedIxon.value = characterAutosave.get(character.curCharacter).icon[0];

            if(characterAutosave.get(character.curCharacter).icon.length > 2)
                hapeyIxon.value = characterAutosave.get(character.curCharacter).icon[2];
            else
                hapeyIxon.value = characterAutosave.get(character.curCharacter).icon[0];

            if(character.animations.length > 0)
                animationDrop.setData(FlxUIDropDownMenu.makeStrIdLabelArray(character.animations, true));
            else
                animationDrop.setData(FlxUIDropDownMenu.makeStrIdLabelArray([""], true));

            if(character.animations.length > 0)
                animationDrop.selectedLabel = character.animation.curAnim.name;

            fileName.text = characterAutosave.get(character.curCharacter).file;

            updateStuff();

            character.updateFinalized(character.getScreenCenter(X), character.y);
            character.refresh(character.curCharacter, camPos);
            camFollow.setPosition(camPos.x, camPos.y);
            character.isPlayer = true;
            character.cameras = [camGame];
            characterStorage.add(character);

            mapEditor.set("health", CoolUtil.calculateAverageColor(iconP1.updateFramePixels()));
            setColorOptions(mapEditor.get("health"));
        }

        if(id == FlxUINumericStepper.CHANGE_EVENT && (sender is FlxUINumericStepper)) {
            var nums:FlxUINumericStepper = cast sender;
			var wname = nums.name;

            if(wname == 'x_pos') {
                character._info.position.set('x', Std.int(nums.value));
                characterAutosave.set(character.curCharacter, character._info);
                character.refresh(character.curCharacter, camPos);
            }else if(wname == 'y_pos') {
                character._info.position.set('y', Std.int(nums.value));
                characterAutosave.set(character.curCharacter, character._info);
                character.refresh(character.curCharacter, camPos);
            }else if(wname == 'x_cam_pos') {
                character._info.position.set('camPosX', Std.int(nums.value));
                characterAutosave.set(character.curCharacter, character._info);
                character.refresh(character.curCharacter, camPos);
                camFollow.setPosition(camPos.x, camPos.y);
            }else if(wname == 'y_cam_pos') {
                character._info.position.set('camPosY', Std.int(nums.value));
                characterAutosave.set(character.curCharacter, character._info);
                character.refresh(character.curCharacter, camPos);
                camFollow.setPosition(camPos.x, camPos.y);
            }else if(wname == 'x_offset') {
                character._info.animations.get(animationDrop.selectedLabel).offset[0] = Std.int(nums.value);
                characterAutosave.set(character.curCharacter, character._info);
                character.animOffsets[animationDrop.selectedLabel][0] = Std.int(nums.value);
                character.changeOffsets(animationDrop.selectedLabel, Std.int(nums.value), X);

                if(animationDrop.selectedLabel == character.animation.curAnim.name)
                    character.offset.set(character.animOffsets[animationDrop.selectedLabel][0], character.animOffsets[animationDrop.selectedLabel][1]);
            }else if(wname == 'y_offset') {
                character._info.animations.get(animationDrop.selectedLabel).offset[1] = Std.int(nums.value);
                characterAutosave.set(character.curCharacter, character._info);
                character.animOffsets[animationDrop.selectedLabel][1] = Std.int(nums.value);
                character.changeOffsets(animationDrop.selectedLabel, Std.int(nums.value), Y);

                if(animationDrop.selectedLabel == character.animation.curAnim.name)
                    character.offset.set(character.animOffsets[animationDrop.selectedLabel][0], character.animOffsets[animationDrop.selectedLabel][1]);
            }else if(wname == 'framerate') {
                character._info.animations.get(animationDrop.selectedLabel).framerate = Std.int(nums.value);
                characterAutosave.set(character.curCharacter, character._info);
            }else if(wname == 'normal_icon') {
                character._info.icon[0] = Std.int(nums.value);
                characterAutosave.set(character.curCharacter, character._info);
            }else if(wname == 'ded_icon'){
                character._info.icon[1] = Std.int(nums.value);
                characterAutosave.set(character.curCharacter, character._info);
            }else if(wname == 'hapey_icon') {
                character._info.icon[2] = Std.int(nums.value);
                characterAutosave.set(character.curCharacter, character._info);
            }else if(wname == 'health') {
                health = plrHealth.value / 50;
            }
            
            if(wname == 'redColor' || wname == 'blueColor' || wname == 'greenColor') {
                var color:Int = FlxColor.fromRGB(
                    Std.int(redColor.value),
                    Std.int(greenColor.value),
                    Std.int(blueColor.value)
                );

                setColorOptions(color);
            }

            if(wname.endsWith('icon')) {
                remove(iconP1);
                iconP1.destroy();
                iconP1 = null;
                iconP1 = new HealthIcon(character.curCharacter, true);
                iconP1.createAnim(character.curCharacter, characterAutosave.get(character.curCharacter).icon, true);

                iconP1.animation.play(character.curCharacter);

                iconP1.y = healthBar.y - (iconP1.height / 2);
                iconP1.setGraphicSize(Std.int(FlxMath.lerp(150, iconP1.width, 0.50)));
                iconP1.updateHitbox();
                add(iconP1);

                iconP1.cameras = [camHUD];
            }
        }
    }

    override function update(elapsed:Float) {
		super.update(elapsed);

        updateCursorPos();

        if(camGame.zoom <= 2 && camGame.zoom >= 0.1)
            camGame.zoom += FlxG.mouse.wheel * elapsed * 1.2;
        if(FlxG.keys.pressed.Q && camGame.zoom <= 2)
            camGame.zoom += elapsed;
        if(FlxG.keys.pressed.E && camGame.zoom >= 0.1)
            camGame.zoom -= elapsed;          

        if(camGame.zoom > 2)
            camGame.zoom = 2;
        if(camGame.zoom < 0.1)
            camGame.zoom = 0.1;
     
		iconP1.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01) - 26);
        iconP2.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01)) - (iconP2.width - 26);

        if (healthBar.percent >= 80)
			iconP1.animation.curAnim.curFrame = 2;
		else if(healthBar.percent <= 20)
            iconP1.animation.curAnim.curFrame = 1;
        else
			iconP1.animation.curAnim.curFrame = 0;

        if (FlxG.keys.justPressed.ESCAPE && isIn) {
			#if !mobile
			FlxG.mouse.visible = false;
			#end

            characterAutosave.clear();

            _character = null;

            characterAutosave = null;
            characterJSONs = null;

            FlxG.switchState(new OptionsMenuState("editors"));
		}

        var controlArray:Array<Bool> = [
			controls.LEFT_P,
			controls.DOWN_P,
			controls.UP_P,
			controls.RIGHT_P
		];

        var controlHoldArray:Array<Bool> = [
			controls.LEFT,
			controls.DOWN,
			controls.UP,
			controls.RIGHT
		];

        if(playCustomAnim && character.animation.finished && !lockAnimCheck.checked)
            playCustomAnim = false;

        if(!playCustomAnim) {
            if (controlArray[0] && character.animations.contains('singLEFT'))
                character.playAnim('singLEFT');
            if (controlArray[1] && character.animations.contains('singDOWN'))
                character.playAnim('singDOWN');
            if (controlArray[2] && character.animations.contains('singUP'))
                character.playAnim('singUP');
            if (controlArray[3] && character.animations.contains('singRIGHT'))
                character.playAnim('singRIGHT');

            if(character.animations.contains('idle')
            || character.animations.contains('danceRight')
            || character.animations.contains('danceLeft')) {
                if((!controlHoldArray.contains(true) && character.animation.curAnim.name.startsWith("sing"))
                || (!character.animation.curAnim.name.startsWith("sing") && character.animation.finished))
                    character.dance();
            }
        }

        if(shadowEntity != null) {
            colorSway += elapsed;
            shadowEntity.color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
            0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
        }else if(colorSway > 0) {
            colorSway = 0;
        }

        if(mapEditor.get("character")[chooseSkin][0] != redMulti.value) {
            mapEditor.get("character")[chooseSkin][0] = redMulti.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
        if(mapEditor.get("character")[chooseSkin][1] != greenMulti.value) {
            mapEditor.get("character")[chooseSkin][1] = greenMulti.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
        if(mapEditor.get("character")[chooseSkin][2] != blueMulti.value) {
            mapEditor.get("character")[chooseSkin][2] = blueMulti.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
        if(mapEditor.get("character")[chooseSkin][3] != alphaMulti.value) {
            mapEditor.get("character")[chooseSkin][3] = alphaMulti.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }

        if(mapEditor.get("character")[chooseSkin][4] != redOffset.value) {
            mapEditor.get("character")[chooseSkin][4] = redOffset.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
        if(mapEditor.get("character")[chooseSkin][5] != greenOffset.value) {
            mapEditor.get("character")[chooseSkin][5] = greenOffset.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
        if(mapEditor.get("character")[chooseSkin][6] != blueOffset.value) {
            mapEditor.get("character")[chooseSkin][6] = blueOffset.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
        if(mapEditor.get("character")[chooseSkin][7] != alphaOffset.value) {
            mapEditor.get("character")[chooseSkin][7] = alphaOffset.value;
            
            iconP1.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );

            character.setColorTransform(
                mapEditor.get("character")[chooseSkin][0],
                mapEditor.get("character")[chooseSkin][1],
                mapEditor.get("character")[chooseSkin][2],
                mapEditor.get("character")[chooseSkin][3],
                Std.int(mapEditor.get("character")[chooseSkin][4]),
                Std.int(mapEditor.get("character")[chooseSkin][5]),
                Std.int(mapEditor.get("character")[chooseSkin][6]),
                Std.int(mapEditor.get("character")[chooseSkin][7])
            );
        }
    }

    function setColorOptions(getColor:Int) {
        var color:FlxColor = new FlxColor(getColor);

        mapEditor.set("health", getColor);

        healthBar.createFilledBar(FlxColor.RED, color);
        healthBar.percent = plrHealth.value;

        redColor.value = color.red;
        greenColor.value = color.green;
        blueColor.value = color.blue;
    }

    function updateCursorPos():Void {
        var x:Float = camFollow.x;
        var y:Float = camFollow.y;

        x -= camCursor.width / 2;
		y -= camCursor.height / 2;
		camCursor.setPosition(x, y);
    }

    function saveFile(fileType:FileType):Void {
        var data:String;

        switch(fileType) {
            case CHARACTER:
                data = Json.stringify(characterAutosave.get(character.curCharacter), "\t");

                if (data != null && data.length > 0) {
                    _file = new FileReference();
                    _file.addEventListener(Event.COMPLETE, onSaveComplete);
                    _file.addEventListener(Event.CANCEL, onCancel);
                    _file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
                    _file.save(data.trim(), character.curCharacter + ".json");
                }
            case COLOR_MAPPING:
                data = Json.stringify(mapEditor);

                if (data != null && data.length > 0) {
                    _file = new FileReference();
                    _file.addEventListener(Event.COMPLETE, onSaveComplete);
                    _file.addEventListener(Event.CANCEL, onCancel);
                    _file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
                    _file.save(data.trim(),  "colors.json");
                }
        }
    }

    function onSelect(event:Event):Void {
        _file = cast(event.target, FileReference);
        _file.addEventListener(Event.COMPLETE, onComplete);
        _file.load();
    }

    function onComplete(event:Event):Void {
        _file = cast(event.target, FileReference);
        _file.removeEventListener(Event.COMPLETE, onComplete);

        try {
            changeCharacter = true;

            getEvent("click_button", null, Std.string(characterJSONs.indexOf(character.curCharacter)));

            trace(_file.name);
        }catch(e:haxe.Exception) {
            clearEvent();
            throw e;
        }
    }

    function clearEvent():Void {
        _file.removeEventListener(Event.COMPLETE, onSaveComplete);
        _file.removeEventListener(Event.CANCEL, onCancel);
        _file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        _file.removeEventListener(Event.SELECT, onSelect);
        _file = null;
    }

    function onSaveComplete(_):Void {
        clearEvent();
        FlxG.log.notice("Successfully saved CHARACTER DATA.");
    }

    function onCancel(_):Void {
        clearEvent();
    }

    function onSaveError(_):Void {
        clearEvent();
        FlxG.log.error("Problem saving Character data");
    }
}

private class FinderUIInputText extends FlxUIInputText {
    public var textUpdateCallback:(text:String)->Bool;

    override function onKeyDown(e:KeyboardEvent):Void {
        super.onKeyDown(e);

        if(textUpdateCallback != null) {
            if(textUpdateCallback(text)) {
                color = FlxColor.BLACK;
            }else {
                color = FlxColor.RED;
            }
        }
    }
}