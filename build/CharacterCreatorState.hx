package;

#if desktop
import Discord.DiscordClient;
#end

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxMath;
import flixel.math.FlxPoint;
import flixel.system.debug.Icon;
import flixel.ui.FlxBar;
import flixel.util.FlxAxes;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import haxe.Json;
import haxe.ui.backend.flixel.UIState;
import haxe.ui.components.Button;
import haxe.ui.components.CheckBox;
import haxe.ui.components.DropDown;
import haxe.ui.components.Label;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextField;
import haxe.ui.core.Screen;
import haxe.ui.focus.FocusManager;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.net.FileReference;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFLAssets;
import ModInitialize.ConfigCharacters;

#if json2object
import json2object.JsonParser;
#end

using StringTools;

enum FileType {
    CHARACTER;
    COLOR_MAPPING;
}

typedef PreloadJSON = Map<String, Array<Array<Float>>>;

@:build(haxe.ui.ComponentBuilder.build("assets/preload/data/character-creator.xml"))
class CharacterCreatorState extends UIState {
    private static inline var DEFAULT_HEALTH_COLOR:Int = 0xFFFF0000;

    private var shadowEntity:CreatorCharacter;
    private var character:CreatorCharacter;
    private var characterStorage:FlxTypedGroup<CreatorCharacter>;
    private var characterAutosave:Map<String, ConfigCharacters>;
    private var mapEditor:Map<String, Dynamic>;
    private var characterJSONs:Array<String> = [];
    #if json2object
    private var parser = new JsonParser<PreloadJSON>();
    #end
    private var healthBar:FlxBar;
    private var iconP1:HealthIcon;
    private var iconP2:HealthIcon;
    private var camCursor:FlxSprite;
    private var health:Float = 1;
    private var colorSway:Float = 0;
    private var camHUD:FlxCamera;
    private var camGame:FlxCamera;
    private var camFollow:FlxObject;
    private var camPos:FlxPoint;
    private var currentCharacterName:String = "bf";
    private var playCustomAnim:Bool = false;
    private var syncingUi:Bool = false;
    private var fileRef:FileReference;

    private final chooseSkin:Int = 0;

    var instructionsLabel:Label;
    var statusLabel:Label;

    var fileNameInput:TextField;
    var fileValidationLabel:Label;
    var updateFileButton:Button;
    var iconFileNameInput:TextField;
    var iconValidationLabel:Label;
    var updateIconFileButton:Button;

    var characterSelectorDropDown:DropDown;
    var characterNameInput:TextField;
    var centerCameraButton:Button;
    var createCharacterButton:Button;
    var flipSpriteButton:Button;

    var xInput:NumberStepper;
    var yInput:NumberStepper;
    var xCamInput:NumberStepper;
    var yCamInput:NumberStepper;
    var normalIconStepper:NumberStepper;
    var deadIconStepper:NumberStepper;
    var happyIconStepper:NumberStepper;
    var plrHealthStepper:NumberStepper;

    var redMultiStepper:NumberStepper;
    var greenMultiStepper:NumberStepper;
    var blueMultiStepper:NumberStepper;
    var alphaMultiStepper:NumberStepper;
    var redOffsetStepper:NumberStepper;
    var greenOffsetStepper:NumberStepper;
    var blueOffsetStepper:NumberStepper;
    var alphaOffsetStepper:NumberStepper;
    var redColorStepper:NumberStepper;
    var greenColorStepper:NumberStepper;
    var blueColorStepper:NumberStepper;

    var animationDropDown:DropDown;
    var refreshAnimationButton:Button;
    var playAnimButton:Button;
    var stopAnimButton:Button;
    var deleteAnimButton:Button;
    var newAnimNameInput:TextField;
    var newAnimButton:Button;
    var createShadowButton:Button;
    var lockAnimCheck:CheckBox;

    var prefixInput:TextField;
    var framerateChange:NumberStepper;
    var loopAnim:CheckBox;
    var offsetXInput:NumberStepper;
    var offsetYInput:NumberStepper;
    var clippingXInput:NumberStepper;
    var clippingYInput:NumberStepper;
    var clippingWidthInput:NumberStepper;
    var clippingHeightInput:NumberStepper;
    var applyClippingButton:Button;
    var checkPlayable:CheckBox;
    var canBePixel:CheckBox;

    var saveCharacterButton:Button;
    var saveColorsButton:Button;

    var allowInput(get, never):Bool;

    function get_allowInput():Bool {
        return FocusManager.instance.focus == null;
    }

    override function create():Void {
        camGame = new FlxCamera();
        camHUD = new FlxCamera();
        camGame.bgColor.alpha = 0;
        camHUD.bgColor.alpha = 0;

        FlxG.cameras.reset(camGame);
        FlxG.cameras.add(camHUD, false);
        FlxG.cameras.setDefaultDrawTarget(camGame, true);
        FlixelCompat.setDefaultCameras([camHUD]);

        mapEditor = [
            "character" => [[1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]],
            "health" => DEFAULT_HEALTH_COLOR
        ];
        characterAutosave = [];

        loadSkinColorData();
        loadCharacterConfigs();
        createDisplay();

        super.create();

        root.scrollFactor.set();
        root.cameras = [camHUD];
        root.width = FlxG.width;
        root.height = FlxG.height;
        Screen.instance.addComponent(root);

        setupUiState();
        reloadCharacter(currentCharacterName);

        #if desktop
        DiscordClient.changePresence("Making Character", null);
        #end
    }

    private function loadSkinColorData():Void {
        var rawSkins:String = Paths.readText(Paths.mora("skins", "json"));
        if(rawSkins == null || rawSkins.length <= 48) {
            return;
        }

        #if json2object
        var parsed:PreloadJSON = cast parser.fromJson(rawSkins, "skins.json");
        if(parsed != null && parsed.exists("character") && parsed.get("character") != null && parsed.get("character").length > 0) {
            mapEditor.set("character", parsed.get("character"));
        }
        if(parsed != null && parsed.exists("health") && parsed.get("health") != null) {
            mapEditor.set("health", parsed.get("health"));
        }
        #end
    }

    private function loadCharacterConfigs():Void {
        var characterListRaw:Array<String> = OpenFLAssets.list(TEXT);

        for(characterPath in characterListRaw) {
            if(characterPath == null) {
                continue;
            }

            if(characterPath.startsWith("mod_assets/characters/")
                || characterPath.startsWith("assets/characters/")
                || characterPath.startsWith("funkin_assets/preload/data/characters/")) {
                var fileName:String = characterPath.split("/").pop();
                if(fileName == null || !fileName.endsWith(".json")) {
                    continue;
                }

                var characterName:String = fileName.substr(0, fileName.length - 5);
                if(characterJSONs.contains(characterName)) {
                    continue;
                }

                var info:ConfigCharacters = Character.loadInfo("characters/" + characterName);
                normalizeCharacterInfo(info);
                characterAutosave.set(characterName, info);
                characterJSONs.push(characterName);
            }
        }

        if(characterJSONs.length <= 0) {
            var fallbackConfig:ConfigCharacters = buildDefaultCharacterConfig();
            normalizeCharacterInfo(fallbackConfig);
            characterAutosave.set("bf", fallbackConfig);
            characterJSONs.push("bf");
        }

        currentCharacterName = characterJSONs.contains("bf") ? "bf" : characterJSONs[0];
    }

    private function createDisplay():Void {
        var bg:FlxSprite = new FlxSprite(-600, -200).loadGraphic(Paths.image("stageback"));
        bg.antialiasing = true;
        bg.active = false;
        bg.cameras = [camGame];
        add(bg);

        var stageFront:FlxSprite = new FlxSprite(-650, 600).loadGraphic(Paths.image("stagefront"));
        stageFront.setGraphicSize(Std.int(stageFront.width * 1.1));
        stageFront.updateHitbox();
        stageFront.antialiasing = true;
        stageFront.active = false;
        stageFront.cameras = [camGame];
        add(stageFront);

        var stageCurtains:FlxSprite = new FlxSprite(-500, -300).loadGraphic(Paths.image("stagecurtains"));
        stageCurtains.setGraphicSize(Std.int(stageCurtains.width * 0.9));
        stageCurtains.updateHitbox();
        stageCurtains.antialiasing = true;
        stageCurtains.active = false;
        stageCurtains.cameras = [camGame];
        add(stageCurtains);

        characterStorage = new FlxTypedGroup<CreatorCharacter>();
        add(characterStorage);

        character = new CreatorCharacter(440, 100, currentCharacterName, true);
        character.updateFinalized(FlixelCompat.getScreenCenter(character, X), 100);
        character.cameras = [camGame];
        characterStorage.add(character);

        camGame.zoom = 0.9;
        camPos = new FlxPoint(character.getGraphicMidpoint().x, character.getGraphicMidpoint().y);
        camFollow = new FlxObject(0, 0, 1, 1);

        character.refresh(character.curCharacter, camPos);
        if(character.flipX) {
            character.flipX = false;
        }

        camFollow.setPosition(camPos.x, camPos.y);
        add(camFollow);

        camGame.follow(camFollow, LOCKON, 0.04);
        camGame.focusOn(camFollow.getPosition());

        var healthBarBG:FlxSprite = new FlxSprite(0, FlxG.height * 0.9).loadGraphic(Paths.image("healthBar"));
        healthBarBG.screenCenter(X);
        healthBarBG.scrollFactor.set();
        healthBarBG.cameras = [camHUD];
        add(healthBarBG);

        healthBar = new FlxBar(
            healthBarBG.x + 4,
            healthBarBG.y + 4,
            RIGHT_TO_LEFT,
            Std.int(healthBarBG.width - 8),
            Std.int(healthBarBG.height - 8),
            this,
            "health",
            0,
            2
        );
        healthBar.percent = 50;
        healthBar.scrollFactor.set();
        healthBar.cameras = [camHUD];
        add(healthBar);

        iconP1 = new HealthIcon("bf", true);
        iconP1.y = healthBar.y - (iconP1.height * 0.5);
        iconP1.setGraphicSize(Std.int(FlxMath.lerp(150, iconP1.width, 0.50)));
        iconP1.updateHitbox();
        iconP1.cameras = [camHUD];
        add(iconP1);

        iconP2 = new HealthIcon("dad", false);
        iconP2.y = healthBar.y - (iconP2.height * 0.5);
        iconP2.setGraphicSize(Std.int(FlxMath.lerp(150, iconP1.width, 0.50)));
        iconP2.updateHitbox();
        iconP2.cameras = [camHUD];
        add(iconP2);

        cacheIconAnimation(iconP1, true);
        cacheIconAnimation(iconP2, false);

        var camCursorGraphic:FlxGraphic = FlxGraphic.fromBitmapData(Icon.cross);
        camCursor = new FlxSprite().loadGraphic(camCursorGraphic);
        camCursor.setGraphicSize(40, 40);
        camCursor.updateHitbox();
        camCursor.color = FlxColor.WHITE;
        camCursor.cameras = [camGame];
        add(camCursor);

        updateCursorPos();
        updateHealthIconPositions();
    }

    private function setupUiState():Void {
        instructionsLabel.text = "Mouse Wheel | Q/E - Camera Zoom\nArrow Keybinds - Sing Direction\nESCAPE - To Exit";
        statusLabel.text = "";

        populateDropDown(characterSelectorDropDown, characterJSONs);

        bindDisplayHandlers();
        bindAnimationHandlers();
        bindExportHandlers();
    }

    private function bindDisplayHandlers():Void {
        fileNameInput.onChange = function(_) updateFileValidation();
        iconFileNameInput.onChange = function(_) updateIconValidation();

        updateFileButton.onClick = function(_) {
            currentConfig().file = fileNameInput.text.trim();
            reloadCharacter(currentCharacterName);
        };

        updateIconFileButton.onClick = function(_) {
            currentConfig().iconFile = iconFileNameInput.text.trim();
            ensureIconSlots(currentConfig());
            currentConfig().icon[0] = 0;
            currentConfig().icon[1] = 0;
            currentConfig().icon[2] = 0;
            reloadCharacter(currentCharacterName);
        };

        characterSelectorDropDown.onChange = function(_) {
            if(syncingUi) {
                return;
            }

            currentCharacterName = getDropDownValue(characterSelectorDropDown, currentCharacterName);
            reloadCharacter(currentCharacterName);
        };

        centerCameraButton.onClick = function(_) {
            camPos.set(character.getGraphicMidpoint().x, character.getGraphicMidpoint().y);
            camFollow.setPosition(camPos.x, camPos.y);
        };

        createCharacterButton.onClick = function(_) createNewCharacter();
        flipSpriteButton.onClick = function(_) if(character != null) character.flipX = !character.flipX;

        xInput.onChange = function(_) updateCharacterPosition("x", xInput);
        yInput.onChange = function(_) updateCharacterPosition("y", yInput);
        xCamInput.onChange = function(_) updateCharacterPosition("camPosX", xCamInput);
        yCamInput.onChange = function(_) updateCharacterPosition("camPosY", yCamInput);

        normalIconStepper.onChange = function(_) updateCharacterIconSlot(0, normalIconStepper);
        deadIconStepper.onChange = function(_) updateCharacterIconSlot(1, deadIconStepper);
        happyIconStepper.onChange = function(_) updateCharacterIconSlot(2, happyIconStepper);

        plrHealthStepper.onChange = function(_) health = plrHealthStepper.pos / 50;

        redMultiStepper.onChange = function(_) onColorTransformChanged();
        greenMultiStepper.onChange = function(_) onColorTransformChanged();
        blueMultiStepper.onChange = function(_) onColorTransformChanged();
        alphaMultiStepper.onChange = function(_) onColorTransformChanged();
        redOffsetStepper.onChange = function(_) onColorTransformChanged();
        greenOffsetStepper.onChange = function(_) onColorTransformChanged();
        blueOffsetStepper.onChange = function(_) onColorTransformChanged();
        alphaOffsetStepper.onChange = function(_) onColorTransformChanged();

        redColorStepper.onChange = function(_) onHealthColorChanged();
        greenColorStepper.onChange = function(_) onHealthColorChanged();
        blueColorStepper.onChange = function(_) onHealthColorChanged();
    }

    private function bindAnimationHandlers():Void {
        animationDropDown.onChange = function(_) {
            if(syncingUi) {
                return;
            }

            refreshAnimationFields();
            previewSelectedAnimation(true);
        };

        refreshAnimationButton.onClick = function(_) {
            commitSelectedAnimationFields();
            reloadCharacter(currentCharacterName);
        };

        playAnimButton.onClick = function(_) {
            playCustomAnim = true;
            previewSelectedAnimation(true);
        };

        stopAnimButton.onClick = function(_) playCustomAnim = false;
        deleteAnimButton.onClick = function(_) deleteSelectedAnimation();
        newAnimButton.onClick = function(_) createNewAnimation();
        createShadowButton.onClick = function(_) createShadowCharacter();

        prefixInput.onChange = function(_) commitSelectedAnimationFields();
        framerateChange.onChange = function(_) commitSelectedAnimationFields();
        loopAnim.onChange = function(_) commitSelectedAnimationFields();
        offsetXInput.onChange = function(_) syncSelectedAnimationOffsetFromInputs();
        offsetYInput.onChange = function(_) syncSelectedAnimationOffsetFromInputs();

        applyClippingButton.onClick = function(_) applyClippingOffsets();

        checkPlayable.onChange = function(_) currentConfig().isPlayer = checkPlayable.selected;
        canBePixel.onChange = function(_) currentConfig().pixel = canBePixel.selected;
    }

    private function bindExportHandlers():Void {
        saveCharacterButton.onClick = function(_) saveFile(CHARACTER);
        saveColorsButton.onClick = function(_) saveFile(COLOR_MAPPING);
    }

    private function createNewCharacter():Void {
        var characterName:String = characterNameInput.text.trim();
        if(characterName.length <= 0 || characterJSONs.contains(characterName)) {
            return;
        }

        var info:ConfigCharacters = buildDefaultCharacterConfig();
        normalizeCharacterInfo(info);
        characterAutosave.set(characterName, info);
        characterJSONs.push(characterName);

        populateDropDown(characterSelectorDropDown, characterJSONs);
        selectDropDownItem(characterSelectorDropDown, characterName);
        characterNameInput.text = "";

        currentCharacterName = characterName;
        reloadCharacter(characterName);
    }

    private function createNewAnimation():Void {
        var animName:String = newAnimNameInput.text.trim();
        if(animName.length <= 0 || currentConfig().animations.exists(animName)) {
            return;
        }

        currentConfig().animations.set(animName, {
            name: animName,
            prefix: prefixInput.text.trim(),
            framerate: Std.int(framerateChange.pos),
            looped: loopAnim.selected,
            offset: [Std.int(offsetXInput.pos), Std.int(offsetYInput.pos)]
        });

        reloadCharacter(currentCharacterName);
        selectDropDownItem(animationDropDown, animName);
        refreshAnimationFields(animName);
    }

    private function deleteSelectedAnimation():Void {
        var animName:Null<String> = safeSelectedAnimation();
        if(animName == null) {
            return;
        }

        currentConfig().animations.remove(animName);
        if(character.animations != null) {
            character.animations.remove(animName);
        }

        reloadCharacter(currentCharacterName);
    }

    private function createShadowCharacter():Void {
        clearShadowCharacter();

        shadowEntity = new CreatorCharacter(character.x, character.y, character.curCharacter, true, character._info);
        shadowEntity.flipX = character.flipX;
        shadowEntity.isPlayer = true;
        shadowEntity.alpha = 0.5;
        shadowEntity.cameras = [camGame];
        characterStorage.add(shadowEntity);

        if(character.animation.curAnim != null) {
            shadowEntity.playAnim(character.animation.curAnim.name);
            shadowEntity.animation.stop();
            if(shadowEntity.animation.curAnim != null) {
                shadowEntity.animation.curAnim.curFrame = shadowEntity.animation.curAnim.numFrames;
            }
        }
    }

    private function clearShadowCharacter():Void {
        if(shadowEntity == null) {
            return;
        }

        characterStorage.remove(shadowEntity, true);
        shadowEntity.destroy();
        shadowEntity = null;
    }

    private function updateCharacterPosition(field:String, stepper:NumberStepper):Void {
        if(syncingUi || character == null) {
            return;
        }

        currentConfig().position.set(field, Std.int(stepper.pos));
        character.refresh(character.curCharacter, camPos);
        if(field == "camPosX" || field == "camPosY") {
            camFollow.setPosition(camPos.x, camPos.y);
        }
    }

    private function updateCharacterIconSlot(index:Int, stepper:NumberStepper):Void {
        if(syncingUi) {
            return;
        }

        ensureIconSlots(currentConfig());
        currentConfig().icon[index] = Std.int(stepper.pos);
        updateIconPreview();
    }

    private function onColorTransformChanged():Void {
        if(syncingUi) {
            return;
        }

        var values:Array<Dynamic> = getColorTransformValues();
        values[0] = redMultiStepper.pos;
        values[1] = greenMultiStepper.pos;
        values[2] = blueMultiStepper.pos;
        values[3] = alphaMultiStepper.pos;
        values[4] = redOffsetStepper.pos;
        values[5] = greenOffsetStepper.pos;
        values[6] = blueOffsetStepper.pos;
        values[7] = alphaOffsetStepper.pos;

        applyCharacterColorTransforms();
    }

    private function onHealthColorChanged():Void {
        if(syncingUi) {
            return;
        }

        var color:Int = FlxColor.fromRGB(
            Std.int(redColorStepper.pos),
            Std.int(greenColorStepper.pos),
            Std.int(blueColorStepper.pos)
        );
        setColorOptions(color);
    }

    private function commitSelectedAnimationFields():Void {
        if(syncingUi) {
            return;
        }

        var animName:Null<String> = safeSelectedAnimation();
        if(animName == null) {
            return;
        }

        var animData = currentConfig().animations.get(animName);
        if(animData == null) {
            return;
        }

        var previousPrefix:String = animData.prefix;
        var nextPrefix:String = prefixInput.text.trim();
        animData.prefix = nextPrefix;
        animData.framerate = Std.int(framerateChange.pos);
        animData.looped = loopAnim.selected;
        animData.offset[0] = Std.int(offsetXInput.pos);
        animData.offset[1] = Std.int(offsetYInput.pos);

        if(previousPrefix != nextPrefix
            && previousPrefix != null
            && previousPrefix != ""
            && currentConfig().clippingAdjustment.exists(previousPrefix)
            && !currentConfig().clippingAdjustment.exists(nextPrefix)) {
            currentConfig().clippingAdjustment.set(nextPrefix, currentConfig().clippingAdjustment.get(previousPrefix));
            currentConfig().clippingAdjustment.remove(previousPrefix);
        }
    }

    private function syncSelectedAnimationOffsetFromInputs():Void {
        if(syncingUi || character == null) {
            return;
        }

        var animName:Null<String> = safeSelectedAnimation();
        if(animName == null) {
            return;
        }

        var animData = currentConfig().animations.get(animName);
        if(animData == null || !character.animOffsets.exists(animName)) {
            return;
        }

        var nextOffsetX:Int = Std.int(offsetXInput.pos);
        var nextOffsetY:Int = Std.int(offsetYInput.pos);
        var changed:Bool = false;

        if(animData.offset[0] != nextOffsetX) {
            animData.offset[0] = nextOffsetX;
            character.animOffsets[animName][0] = nextOffsetX;
            character.changeOffsets(animName, nextOffsetX, X);
            changed = true;
        }

        if(animData.offset[1] != nextOffsetY) {
            animData.offset[1] = nextOffsetY;
            character.animOffsets[animName][1] = nextOffsetY;
            character.changeOffsets(animName, nextOffsetY, Y);
            changed = true;
        }

        if(changed) {
            previewSelectedAnimation(false);
        }
    }

    private function applyClippingOffsets():Void {
        var animName:Null<String> = safeSelectedAnimation();
        if(animName == null) {
            return;
        }

        var animData = currentConfig().animations.get(animName);
        if(animData == null) {
            return;
        }

        var clippingKey:String = animData.prefix != null && animData.prefix != "" ? animData.prefix : animName;
        var values:Array<Int> = [
            Std.int(clippingXInput.pos),
            Std.int(clippingYInput.pos),
            Std.int(clippingWidthInput.pos),
            Std.int(clippingHeightInput.pos)
        ];

        if(values[0] == 0 && values[1] == 0 && values[2] == 0 && values[3] == 0) {
            currentConfig().clippingAdjustment.remove(clippingKey);
        } else {
            currentConfig().clippingAdjustment.set(clippingKey, values);
        }

        reloadCharacter(currentCharacterName);
        selectDropDownItem(animationDropDown, animName);
        refreshAnimationFields(animName);
    }

    private function reloadCharacter(characterName:String):Void {
        currentCharacterName = characterName;
        normalizeCharacterInfo(currentConfig());
        clearShadowCharacter();

        if(character != null) {
            characterStorage.remove(character, true);
            character.destroy();
            character = null;
        }

        character = new CreatorCharacter(440, 100, characterName, true, currentConfig());
        character.flipX = false;
        character.updateFinalized(FlixelCompat.getScreenCenter(character, X), character.y);
        character.refresh(character.curCharacter, camPos);
        character.isPlayer = true;
        character.cameras = [camGame];
        characterStorage.add(character);

        camFollow.setPosition(camPos.x, camPos.y);
        camGame.focusOn(camFollow.getPosition());

        iconP1.loadNewIcons(currentConfig().iconFile);
        updateIconPreview();
        applyCharacterColorTransforms();

        mapEditor.set("health", CoolUtil.calculateAverageColor(iconP1.updateFramePixels()));
        setColorOptions(mapEditor.get("health"));
        refreshColorTransformFields();
        refreshDisplayFields();
        rebuildAnimationDropDown(character.animation.curAnim != null ? character.animation.curAnim.name : null);
        refreshAnimationFields();
    }

    private function refreshDisplayFields():Void {
        syncingUi = true;

        selectDropDownItem(characterSelectorDropDown, currentCharacterName);
        fileNameInput.text = currentConfig().file;
        iconFileNameInput.text = currentConfig().iconFile;

        xInput.pos = currentConfig().position.get("x");
        yInput.pos = currentConfig().position.get("y");
        xCamInput.pos = currentConfig().position.get("camPosX");
        yCamInput.pos = currentConfig().position.get("camPosY");

        ensureIconSlots(currentConfig());
        normalIconStepper.pos = currentConfig().icon[0];
        deadIconStepper.pos = currentConfig().icon[1];
        happyIconStepper.pos = currentConfig().icon[2];
        checkPlayable.selected = currentConfig().isPlayer;
        canBePixel.selected = currentConfig().pixel;

        syncingUi = false;

        updateFileValidation();
        updateIconValidation();
    }

    private function refreshAnimationFields(?preferredAnimation:String):Void {
        var selectedAnimation:String = preferredAnimation != null ? preferredAnimation : getDropDownValue(animationDropDown, "");
        var animData = selectedAnimation != "" ? currentConfig().animations.get(selectedAnimation) : null;

        syncingUi = true;

        if(selectedAnimation != "") {
            selectDropDownItem(animationDropDown, selectedAnimation);
        }

        if(animData != null) {
            prefixInput.text = animData.prefix;
            framerateChange.pos = animData.framerate;
            loopAnim.selected = animData.looped;
            offsetXInput.pos = animData.offset[0];
            offsetYInput.pos = animData.offset[1];

            var clippingKey:String = animData.prefix != null && animData.prefix != "" ? animData.prefix : selectedAnimation;
            var clipping:Array<Int> = currentConfig().clippingAdjustment.get(clippingKey);
            clippingXInput.pos = clipping != null ? clipping[0] : 0;
            clippingYInput.pos = clipping != null ? clipping[1] : 0;
            clippingWidthInput.pos = clipping != null ? clipping[2] : 0;
            clippingHeightInput.pos = clipping != null ? clipping[3] : 0;
        } else {
            prefixInput.text = "";
            framerateChange.pos = 24;
            loopAnim.selected = false;
            offsetXInput.pos = 0;
            offsetYInput.pos = 0;
            clippingXInput.pos = 0;
            clippingYInput.pos = 0;
            clippingWidthInput.pos = 0;
            clippingHeightInput.pos = 0;
        }

        syncingUi = false;
    }

    private function rebuildAnimationDropDown(?preferredAnimation:String):Void {
        var animations:Array<String> = character != null && character.animations != null ? character.animations.copy() : [];
        if(animations.length <= 0) {
            animations = [""];
        }

        populateDropDown(animationDropDown, animations);

        var targetAnimation:String = preferredAnimation;
        if(targetAnimation == null || targetAnimation == "") {
            targetAnimation = character != null && character.animation.curAnim != null ? character.animation.curAnim.name : animations[0];
        }

        selectDropDownItem(animationDropDown, targetAnimation);
    }

    private function previewSelectedAnimation(forcePlay:Bool = false):Void {
        if(character == null) {
            return;
        }

        var animName:Null<String> = safeSelectedAnimation();
        if(animName == null) {
            return;
        }

        if(forcePlay || character.animation.curAnim == null || character.animation.curAnim.name != animName) {
            character.playAnim(animName, true);
        } else if(character.animOffsets.exists(animName)) {
            character.offset.set(character.animOffsets[animName][0], character.animOffsets[animName][1]);
        }
    }

    private function updateIconPreview():Void {
        ensureIconSlots(currentConfig());
        iconP1.createAnim(currentCharacterName, [
            currentConfig().icon[0],
            currentConfig().icon[1],
            currentConfig().icon[2]
        ], true);

        if(iconP1.iconCharacters.contains(currentCharacterName)) {
            iconP1.animation.play(currentCharacterName);
        } else {
            iconP1.animation.play("face");
        }
    }

    private function applyCharacterColorTransforms():Void {
        var values:Array<Dynamic> = getColorTransformValues();
        if(iconP1 != null) {
            iconP1.setColorTransform(
                values[0],
                values[1],
                values[2],
                values[3],
                Std.int(values[4]),
                Std.int(values[5]),
                Std.int(values[6]),
                Std.int(values[7])
            );
        }

        if(character != null) {
            character.setColorTransform(
                values[0],
                values[1],
                values[2],
                values[3],
                Std.int(values[4]),
                Std.int(values[5]),
                Std.int(values[6]),
                Std.int(values[7])
            );
        }
    }

    private function refreshColorTransformFields():Void {
        var values:Array<Dynamic> = getColorTransformValues();

        syncingUi = true;
        redMultiStepper.pos = values[0];
        greenMultiStepper.pos = values[1];
        blueMultiStepper.pos = values[2];
        alphaMultiStepper.pos = values[3];
        redOffsetStepper.pos = values[4];
        greenOffsetStepper.pos = values[5];
        blueOffsetStepper.pos = values[6];
        alphaOffsetStepper.pos = values[7];
        syncingUi = false;
    }

    private function getColorTransformValues():Array<Dynamic> {
        var characterValues:Dynamic = mapEditor.get("character");
        if(characterValues == null || characterValues[chooseSkin] == null) {
            mapEditor.set("character", [[1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]]);
            characterValues = mapEditor.get("character");
        }

        return characterValues[chooseSkin];
    }

    private function currentConfig():ConfigCharacters {
        return characterAutosave.get(currentCharacterName);
    }

    private function safeSelectedAnimation():Null<String> {
        var animName:String = getDropDownValue(animationDropDown, "");
        if(animName == "" || character == null || !character.animations.contains(animName)) {
            return null;
        }

        return animName;
    }

    private function normalizeCharacterInfo(info:ConfigCharacters):Void {
        if(info.animations == null) {
            info.animations = [];
        }
        if(info.position == null) {
            info.position = [
                "x" => 0,
                "y" => 0,
                "camPosX" => 0,
                "camPosY" => 0
            ];
        }
        if(info.icon == null) {
            info.icon = [0, 0, 0];
        }
        ensureIconSlots(info);
        if(info.file == null) {
            info.file = "";
        }
        if(info.playAnim == null) {
            info.playAnim = "";
        }
        if(info.iconFile == null || info.iconFile == "") {
            info.iconFile = "iconGrid";
        }
        if(info.clippingAdjustment == null) {
            info.clippingAdjustment = [];
        }

        DefaultHandler.setupUpdateInfo(info);
    }

    private function ensureIconSlots(info:ConfigCharacters):Void {
        while(info.icon.length < 3) {
            var fallback:Int = info.icon.length > 0 ? info.icon[info.icon.length - 1] : 0;
            info.icon.push(fallback);
        }
    }

    private function buildDefaultCharacterConfig():ConfigCharacters {
        return {
            file: "",
            animations: [],
            position: [
                "x" => 0,
                "y" => 0,
                "camPosX" => 0,
                "camPosY" => 0
            ],
            icon: [10, 11, 10],
            playAnim: "",
            isPlayer: false,
            pixel: false,
            iconFile: "iconGrid",
            clippingAdjustment: []
        };
    }

    private function populateDropDown(dropDown:DropDown, items:Array<String>):Void {
        dropDown.dataSource.clear();

        for(item in items) {
            dropDown.dataSource.add({id: item, text: item});
        }
    }

    private function selectDropDownItem(dropDown:DropDown, value:String):Void {
        for(index in 0...dropDown.dataSource.size) {
            var item:Dynamic = dropDown.dataSource.get(index);
            var itemId:Dynamic = item != null ? Reflect.field(item, "id") : null;
            var itemText:Dynamic = item != null ? Reflect.field(item, "text") : null;

            if(Std.string(itemId) == value || Std.string(itemText) == value) {
                dropDown.selectedIndex = index;
                return;
            }
        }

        if(dropDown.dataSource.size > 0) {
            dropDown.selectedIndex = 0;
        }
    }

    private function getDropDownValue(dropDown:DropDown, fallback:String):String {
        var selected:Dynamic = dropDown.selectedItem;

        if(selected != null) {
            var idValue:Dynamic = Reflect.field(selected, "id");
            if(idValue != null && Std.string(idValue) != "") {
                return Std.string(idValue);
            }

            var textValue:Dynamic = Reflect.field(selected, "text");
            if(textValue != null && Std.string(textValue) != "") {
                return Std.string(textValue);
            }
        }

        return fallback;
    }

    private function updateFileValidation():Void {
        var value:String = fileNameInput.text.trim();
        var exists:Bool = value.length > 0 && Paths.assetExists(Paths.getPreloadPath("images/" + value), IMAGE);
        fileValidationLabel.text = exists ? "Asset found" : "Asset missing";
    }

    private function updateIconValidation():Void {
        var value:String = iconFileNameInput.text.trim();
        var exists:Bool = value.length > 0 && Paths.image(value) != null;
        iconValidationLabel.text = exists ? "Icon sheet found" : "Icon sheet missing";
    }

    function cacheIconAnimation(icon:HealthIcon, player:Bool = false):Void {
        var characterList:Array<String> = DefaultHandler.getcharacterJSON();

        for(characterName in characterList) {
            icon.createAnim(characterName, icon.getIconJSON(characterName), player);
        }
    }

    private function updateCursorPos():Void {
        var x:Float = camFollow.x - camCursor.width / 2;
        var y:Float = camFollow.y - camCursor.height / 2;
        camCursor.setPosition(x, y);
    }

    private function updateHealthIconPositions():Void {
        iconP1.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01) - 26);
        iconP2.x = healthBar.x + (healthBar.width * (FlxMath.remapToRange(healthBar.percent, 0, 100, 100, 0) * 0.01)) - (iconP2.width - 26);
    }

    override function update(elapsed:Float):Void {
        super.update(elapsed);

        updateCursorPos();

        if(allowInput) {
            if(camGame.zoom <= 2 && camGame.zoom >= 0.1) {
                camGame.zoom += FlxG.mouse.wheel * elapsed * 1.2;
            }
            if(FlxG.keys.pressed.Q && camGame.zoom <= 2) {
                camGame.zoom += elapsed;
            }
            if(FlxG.keys.pressed.E && camGame.zoom >= 0.1) {
                camGame.zoom -= elapsed;
            }
        }

        if(camGame.zoom > 2) {
            camGame.zoom = 2;
        }
        if(camGame.zoom < 0.1) {
            camGame.zoom = 0.1;
        }

        updateHealthIconPositions();

        if(healthBar.percent >= 80) {
            iconP1.animation.curAnim.curFrame = 2;
        } else if(healthBar.percent <= 20) {
            iconP1.animation.curAnim.curFrame = 1;
        } else {
            iconP1.animation.curAnim.curFrame = 0;
        }

        if(FlxG.keys.justPressed.ESCAPE) {
            #if !mobile
            FlxG.mouse.visible = false;
            #end

            characterAutosave.clear();
            FlxG.switchState(new OptionsMenuState("editors"));
        }

        var controlArray:Array<Bool> = [
            FlxG.keys.justPressed.LEFT,
            FlxG.keys.justPressed.DOWN,
            FlxG.keys.justPressed.UP,
            FlxG.keys.justPressed.RIGHT
        ];

        var controlHoldArray:Array<Bool> = [
            FlxG.keys.pressed.LEFT,
            FlxG.keys.pressed.DOWN,
            FlxG.keys.pressed.UP,
            FlxG.keys.pressed.RIGHT
        ];

        var selectedAnimation:Null<String> = safeSelectedAnimation();
        var lockSelectedAnimation:Bool = allowInput
            && lockAnimCheck.selected
            && selectedAnimation != null;

        if(lockSelectedAnimation) {
            if(character.animation.curAnim == null
                || character.animation.curAnim.name != selectedAnimation
                || character.animation.finished) {
                previewSelectedAnimation(true);
            } else {
                previewSelectedAnimation(false);
            }
        } else if(allowInput) {
            if(playCustomAnim && character.animation.finished) {
                playCustomAnim = false;
            }

            if(!playCustomAnim && character.animation.curAnim != null) {
                if(controlArray[0] && character.animations.contains("singLEFT")) character.playAnim("singLEFT");
                if(controlArray[1] && character.animations.contains("singDOWN")) character.playAnim("singDOWN");
                if(controlArray[2] && character.animations.contains("singUP")) character.playAnim("singUP");
                if(controlArray[3] && character.animations.contains("singRIGHT")) character.playAnim("singRIGHT");

                if(character.animations.contains("idle")
                    || character.animations.contains("danceRight")
                    || character.animations.contains("danceLeft")) {
                    if((!controlHoldArray.contains(true) && character.animation.curAnim.name.startsWith("sing"))
                        || (!character.animation.curAnim.name.startsWith("sing") && character.animation.finished)) {
                        character.dance();
                    }
                }
            }
        }

        if(shadowEntity != null) {
            colorSway += elapsed;
            shadowEntity.color = FlxColor.fromRGBFloat(
                0.6 + Math.sin(colorSway * Math.PI) * 0.4,
                0.6 + Math.sin(colorSway * Math.PI) * 0.4,
                0.6 + Math.sin(colorSway * Math.PI) * 0.4
            );
        } else if(colorSway > 0) {
            colorSway = 0;
        }
    }

    override function destroy():Void {
        clearShadowCharacter();
        iconP1 = FlxDestroyUtil.destroy(iconP1);
        iconP2 = FlxDestroyUtil.destroy(iconP2);
        super.destroy();
    }

    function setColorOptions(getColor:Int):Void {
        var color:FlxColor = new FlxColor(getColor);
        mapEditor.set("health", getColor);

        healthBar.createFilledBar(FlxColor.RED, color);
        healthBar.percent = plrHealthStepper != null ? plrHealthStepper.pos : 50;

        syncingUi = true;
        redColorStepper.pos = color.red;
        greenColorStepper.pos = color.green;
        blueColorStepper.pos = color.blue;
        syncingUi = false;
    }

    function saveFile(fileType:FileType):Void {
        var data:String = null;
        var name:String = null;

        switch(fileType) {
            case CHARACTER:
                data = Json.stringify(currentConfig(), "\t");
                name = currentCharacterName + ".json";
            case COLOR_MAPPING:
                data = Json.stringify(mapEditor, "\t");
                name = "colors.json";
        }

        if(data == null || data.length <= 0) {
            return;
        }

        fileRef = new FileReference();
        fileRef.addEventListener(Event.COMPLETE, onSaveComplete);
        fileRef.addEventListener(Event.CANCEL, onCancel);
        fileRef.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        fileRef.save(data.trim(), name);
    }

    function clearSaveEvents():Void {
        if(fileRef == null) {
            return;
        }

        fileRef.removeEventListener(Event.COMPLETE, onSaveComplete);
        fileRef.removeEventListener(Event.CANCEL, onCancel);
        fileRef.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        fileRef = null;
    }

    function onSaveComplete(_):Void {
        clearSaveEvents();
        statusLabel.text = "Saved successfully.";
        FlxG.log.notice("Successfully saved character data.");
    }

    function onCancel(_):Void {
        clearSaveEvents();
        statusLabel.text = "Save cancelled.";
    }

    function onSaveError(_):Void {
        clearSaveEvents();
        statusLabel.text = "Problem saving character data.";
        FlxG.log.error("Problem saving character data");
    }
}
