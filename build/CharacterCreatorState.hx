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
import haxe.ui.containers.TabView;
import haxe.ui.core.Screen;
import haxe.ui.focus.FocusManager;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.geom.Rectangle;
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

typedef AtlasFrame = {
    name:String,
    x:Int,
    y:Int,
    width:Int,
    height:Int
}

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
    var atlasModeDropDown:DropDown;

    private static inline var MODE_SPARROW:String = "sparrow";
    private static inline var MODE_PACKER:String = "packer";
    private static inline var MODE_ANIMATE:String = "animate";

    private static var ATLAS_MODE_LABELS:Array<{id:String, text:String}> = [
        {id: MODE_SPARROW, text: "SPRITESHEET"},
        {id: MODE_ANIMATE, text: "ANIMATIONS"}
    ];

    var combineTargetAnimDropDown:DropDown;
    var combineBaseOffsetX:NumberStepper;
    var combineBaseOffsetY:NumberStepper;
    var combineOverlayXmlDropDown:DropDown;
    var combineOverlayPrefixDropDown:DropDown;
    var combineOverlayOffsetX:NumberStepper;
    var combineOverlayOffsetY:NumberStepper;
    var combineAnimationsButton:Button;
    var updateCombineButton:Button;
    var clearCombineButton:Button;
    var flipCombineZButton:Button;
    var combineZOrderLabel:Label;
    var combineStatusLabel:Label;

    private var xmlPrefixCache:Map<String, Array<String>> = new Map();

    var saveCharacterButton:Button;
    var saveColorsButton:Button;

    var mainTabView:TabView;
    var atlasFileDropDown:DropDown;
    var atlasPrefixDropDown:DropDown;
    var atlasInfoLabel:Label;

    private var atlasGroup:FlxTypedGroup<FlxSprite>;
    private var atlasViewSprite:FlxSprite;
    private var atlasViewOverlay:FlxSprite;
    private var isAtlasTabActive:Bool = false;
    private static inline var ATLAS_TAB_INDEX:Int = 3;

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

        atlasGroup = new FlxTypedGroup<FlxSprite>();
        add(atlasGroup);

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
        ensureAtlasModeDropDown();

        bindDisplayHandlers();
        bindAnimationHandlers();
        bindCombineHandlers();
        bindExportHandlers();
        bindAtlasHandlers();
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

        atlasModeDropDown.onChange = function(_) {
            if(syncingUi) return;
            var newMode:String = getDropDownValue(atlasModeDropDown, MODE_SPARROW);
            if(newMode == "") newMode = MODE_SPARROW;
            var oldMode:String = currentAtlasMode();
            if(newMode == oldMode) return;

            currentConfig().atlasMode = newMode;
            currentConfig().isAnimateAtlas = (newMode == MODE_ANIMATE);
            currentConfig().file = renameFileFieldForMode(currentConfig().file, newMode);
            xmlPrefixCache = new Map();

            syncingUi = true;
            fileNameInput.text = currentConfig().file;
            syncingUi = false;

            reloadCharacter(currentCharacterName);
            if(isAtlasTabActive) rebuildAtlasView();
            updateFileValidation();
        };
    }

    private function bindCombineHandlers():Void {
        combineTargetAnimDropDown.onChange = function(_) {
            if(syncingUi) return;
            refreshCombineFieldsFromTarget();
        };
        combineOverlayXmlDropDown.onChange = function(_) {
            if(syncingUi) return;
            rebuildOverlayPrefixDropDown();
        };
        combineAnimationsButton.onClick = function(_) applyCombineToTarget(false);
        updateCombineButton.onClick = function(_) applyCombineToTarget(true);
        clearCombineButton.onClick = function(_) removeOverlayFromTarget();
        flipCombineZButton.onClick = function(_) flipCombineZOrder();
    }

    private function bindExportHandlers():Void {
        saveCharacterButton.onClick = function(_) saveFile(CHARACTER);
        saveColorsButton.onClick = function(_) saveFile(COLOR_MAPPING);
    }

    private function rebuildCombineDropDowns():Void {
        syncingUi = true;

        var files:Array<String> = parseXmlFileList(currentConfig().file);
        if(files.length == 0) files = [""];
        populateDropDown(combineOverlayXmlDropDown, files);

        var animNames:Array<String> = [];
        for(key in currentConfig().animations.keys()) animNames.push(key);
        if(animNames.length == 0) animNames = [""];
        populateDropDown(combineTargetAnimDropDown, animNames);

        syncingUi = false;

        rebuildOverlayPrefixDropDown();
        refreshCombineFieldsFromTarget();
    }

    private function rebuildOverlayPrefixDropDown():Void {
        var selectedXml:String = getDropDownValue(combineOverlayXmlDropDown, "");
        var prefixes:Array<String> = selectedXml != "" ? loadXmlPrefixes(selectedXml) : [];
        if(prefixes.length == 0) prefixes = [""];

        syncingUi = true;
        populateDropDown(combineOverlayPrefixDropDown, prefixes);
        syncingUi = false;
    }

    private function refreshCombineFieldsFromTarget():Void {
        var animName:String = getDropDownValue(combineTargetAnimDropDown, "");
        var info = animName != "" ? currentConfig().animations.get(animName) : null;

        syncingUi = true;
        if(info != null) {
            combineBaseOffsetX.pos = info.offset[0];
            combineBaseOffsetY.pos = info.offset[1];
            if(info.secondaryPrefix != null && info.secondaryPrefix != "") {
                selectDropDownItem(combineOverlayPrefixDropDown, info.secondaryPrefix);
                if(info.secondaryOffset != null && info.secondaryOffset.length >= 2) {
                    combineOverlayOffsetX.pos = info.secondaryOffset[0];
                    combineOverlayOffsetY.pos = info.secondaryOffset[1];
                } else {
                    combineOverlayOffsetX.pos = 0;
                    combineOverlayOffsetY.pos = 0;
                }
                combineZOrderLabel.text = info.secondaryBehind == true
                    ? "Overlay drawn behind base"
                    : "Overlay drawn on top";
            } else {
                combineOverlayOffsetX.pos = 0;
                combineOverlayOffsetY.pos = 0;
                combineZOrderLabel.text = "No overlay attached";
            }
        } else {
            combineBaseOffsetX.pos = 0;
            combineBaseOffsetY.pos = 0;
            combineOverlayOffsetX.pos = 0;
            combineOverlayOffsetY.pos = 0;
            combineZOrderLabel.text = "";
        }
        syncingUi = false;
    }

    private function parseXmlFileList(raw:String):Array<String> {
        var out:Array<String> = [];
        if(raw == null) return out;
        for(piece in raw.split(",")) {
            var trimmed:String = piece.trim();
            if(trimmed.length > 0) out.push(trimmed);
        }
        return out;
    }

    private function currentAtlasFiles():Array<String> {
        var raw:Array<String> = parseXmlFileList(currentConfig().file);
        if(currentAtlasMode() != MODE_ANIMATE) return raw;

        var out:Array<String> = [];
        for(folder in raw) {
            var clean:String = folder;
            var dot:Int = clean.lastIndexOf(".");
            if(dot >= 0) clean = clean.substr(0, dot);

            var foundAny:Bool = false;
            var i:Int = 1;
            while(i <= 32) {
                var key:String = clean + "/spritemap" + i;
                var png:String = Paths.getPath('images/' + key + '.png', IMAGE, "shared");
                if(!Paths.assetExists(png, IMAGE)) break;
                out.push(key);
                foundAny = true;
                i++;
            }

            if(!foundAny) {
                var altKey:String = clean + "/spritemap";
                var altPng:String = Paths.getPath('images/' + altKey + '.png', IMAGE, "shared");
                if(Paths.assetExists(altPng, IMAGE)) {
                    out.push(altKey);
                    foundAny = true;
                }
            }

            if(!foundAny && clean.length > 0) out.push(clean);
        }
        return out;
    }

    private function siblingFolderOf(basePath:String):String {
        var slash:Int = basePath.lastIndexOf("/");
        if(slash < 0) return "";
        return basePath.substr(0, slash);
    }

    private function loadAnimationSymbols(folder:String):Array<String> {
        if(folder == null || folder == "") return [];
        return AnimateAtlasLoader.listSymbolNames(folder);
    }

    private function loadSymbolSpriteMap(folder:String):Map<String, Array<String>> {
        var out:Map<String, Array<String>> = new Map();
        if(folder == null || folder == "") return out;

        var animationPath:String = Paths.getPath('images/' + folder + '/Animation.json', TEXT, "shared");
        if(!Paths.assetExists(animationPath, TEXT)) return out;

        var raw:String = Paths.readText(animationPath);
        if(raw == null || raw.length == 0) return out;

        var data:Dynamic = null;
        try { data = haxe.Json.parse(raw); } catch(e:Dynamic) { return out; }
        if(data == null) return out;

        var dictionary:Dynamic = Reflect.field(data, "SD");
        if(dictionary == null) dictionary = Reflect.field(data, "SYMBOL_DICTIONARY");
        if(dictionary == null) return out;

        var symbols:Dynamic = Reflect.field(dictionary, "S");
        if(symbols == null) symbols = Reflect.field(dictionary, "Symbols");
        if(symbols == null || !Std.isOfType(symbols, Array)) return out;

        var arr:Array<Dynamic> = cast symbols;
        for(symbol in arr) {
            var symbolName:String = stringFieldDyn(symbol, ["SN", "SYMBOL_name"]);
            if(symbolName == null || symbolName == "") continue;

            var sprites:Array<String> = [];
            var seen:Map<String, Bool> = new Map();
            collectSymbolSprites(symbol, sprites, seen);
            out.set(symbolName, sprites);
        }
        return out;
    }

    private function collectSymbolSprites(symbolNode:Dynamic, out:Array<String>, seen:Map<String, Bool>):Void {
        var timeline:Dynamic = Reflect.field(symbolNode, "TL");
        if(timeline == null) timeline = Reflect.field(symbolNode, "TIMELINE");
        if(timeline == null) return;

        var layers:Dynamic = Reflect.field(timeline, "L");
        if(layers == null) layers = Reflect.field(timeline, "LAYERS");
        if(layers == null || !Std.isOfType(layers, Array)) return;

        for(layer in (cast layers : Array<Dynamic>)) {
            var fr:Dynamic = Reflect.field(layer, "FR");
            if(fr == null) fr = Reflect.field(layer, "Frames");
            if(fr == null || !Std.isOfType(fr, Array)) continue;

            for(frame in (cast fr : Array<Dynamic>)) {
                var elements:Dynamic = Reflect.field(frame, "E");
                if(elements == null) elements = Reflect.field(frame, "elements");
                if(elements == null || !Std.isOfType(elements, Array)) continue;

                for(elem in (cast elements : Array<Dynamic>)) {
                    var asi:Dynamic = Reflect.field(elem, "ASI");
                    if(asi == null) asi = Reflect.field(elem, "ATLAS_SPRITE_instance");
                    if(asi != null) {
                        var name:String = stringFieldDyn(asi, ["N", "name"]);
                        if(name != null && name != "" && !seen.exists(name)) {
                            seen.set(name, true);
                            out.push(name);
                        }
                    }
                }
            }
        }
    }

    private function stringFieldDyn(obj:Dynamic, keys:Array<String>):String {
        if(obj == null) return null;
        for(k in keys) {
            var v:Dynamic = Reflect.field(obj, k);
            if(v != null) return Std.string(v);
        }
        return null;
    }

    private function loadXmlPrefixes(xmlFile:String):Array<String> {
        if(xmlPrefixCache.exists(xmlFile)) {
            return xmlPrefixCache.get(xmlFile);
        }

        var prefixes:Array<String> = [];
        var seen:Map<String, Bool> = new Map();

        var basePath:String = xmlFile;
        var dotIndex:Int = xmlFile.lastIndexOf(".");
        if(dotIndex >= 0) basePath = xmlFile.substr(0, dotIndex);

        var dataPath:String = Paths.getPath('images/' + basePath + '.xml', TEXT, "shared");
        if(!Paths.assetExists(dataPath, TEXT)) {
            var animationFolder:String = siblingFolderOf(basePath);
            if(animationFolder == "") animationFolder = basePath;
            var animationPath:String = Paths.getPath('images/' + animationFolder + '/Animation.json', TEXT, "shared");
            if(Paths.assetExists(animationPath, TEXT)) {
                for(symbol in loadAnimationSymbols(animationFolder)) {
                    if(!seen.exists(symbol)) {
                        seen.set(symbol, true);
                        prefixes.push(symbol);
                    }
                }
            }
            xmlPrefixCache.set(xmlFile, prefixes);
            return prefixes;
        }

        var raw:String = Paths.readText(dataPath);
        if(raw == null || raw.length == 0) {
            xmlPrefixCache.set(xmlFile, prefixes);
            return prefixes;
        }

        var nameRegex:EReg = ~/name="([^"]+)"/g;
        var pos:Int = 0;
        while(nameRegex.matchSub(raw, pos)) {
            var matched:String = nameRegex.matched(1);
            var matchPos = nameRegex.matchedPos();
            pos = matchPos.pos + matchPos.len;

            var trimEnd:Int = matched.length;
            while(trimEnd > 0) {
                var c:Null<Int> = matched.charCodeAt(trimEnd - 1);
                if(c == null || c < 48 || c > 57) break;
                trimEnd--;
            }
            var prefix:String = StringTools.rtrim(matched.substr(0, trimEnd));
            if(prefix.length > 0 && !seen.exists(prefix)) {
                seen.set(prefix, true);
                prefixes.push(prefix);
            }
        }

        xmlPrefixCache.set(xmlFile, prefixes);
        return prefixes;
    }

    private function applyCombineToTarget(updateOnly:Bool):Void {
        var animName:String = getDropDownValue(combineTargetAnimDropDown, "");
        if(animName == "" || !currentConfig().animations.exists(animName)) {
            combineStatusLabel.text = "Pick a target animation.";
            return;
        }

        var info = currentConfig().animations.get(animName);

        if(updateOnly && (info.secondaryPrefix == null || info.secondaryPrefix == "")) {
            combineStatusLabel.text = "No overlay attached yet. Use Combine first.";
            return;
        }

        if(!updateOnly) {
            var overlayPrefix:String = getDropDownValue(combineOverlayPrefixDropDown, "");
            if(overlayPrefix == "") {
                combineStatusLabel.text = "Pick an overlay prefix.";
                return;
            }
            info.secondaryPrefix = overlayPrefix;
        }

        info.offset[0] = Std.int(combineBaseOffsetX.pos);
        info.offset[1] = Std.int(combineBaseOffsetY.pos);

        var overlayOffX:Int = Std.int(combineOverlayOffsetX.pos);
        var overlayOffY:Int = Std.int(combineOverlayOffsetY.pos);
        if(info.secondaryOffset == null || info.secondaryOffset.length < 2) {
            info.secondaryOffset = [overlayOffX, overlayOffY];
        } else {
            info.secondaryOffset[0] = overlayOffX;
            info.secondaryOffset[1] = overlayOffY;
        }

        reloadCharacter(currentCharacterName, updateOnly);
        selectDropDownItem(animationDropDown, animName);
        refreshAnimationFields(animName);
        selectDropDownItem(combineTargetAnimDropDown, animName);
        refreshCombineFieldsFromTarget();
        combineStatusLabel.text = updateOnly
            ? "Updated '" + animName + "'."
            : "Combined overlay into '" + animName + "'.";
    }

    private function flipCombineZOrder():Void {
        var animName:String = getDropDownValue(combineTargetAnimDropDown, "");
        if(animName == "" || !currentConfig().animations.exists(animName)) {
            combineStatusLabel.text = "Pick a target animation.";
            return;
        }

        var info = currentConfig().animations.get(animName);
        if(info.secondaryPrefix == null || info.secondaryPrefix == "") {
            combineStatusLabel.text = "No overlay attached yet. Use Combine first.";
            return;
        }

        info.secondaryBehind = !(info.secondaryBehind == true);

        reloadCharacter(currentCharacterName);
        selectDropDownItem(animationDropDown, animName);
        refreshAnimationFields(animName);
        selectDropDownItem(combineTargetAnimDropDown, animName);
        refreshCombineFieldsFromTarget();
        combineStatusLabel.text = info.secondaryBehind
            ? "Overlay moved behind base."
            : "Overlay moved in front of base.";
    }

    private function removeOverlayFromTarget():Void {
        var animName:String = getDropDownValue(combineTargetAnimDropDown, "");
        if(animName == "" || !currentConfig().animations.exists(animName)) {
            combineStatusLabel.text = "Pick a target animation.";
            return;
        }

        var info = currentConfig().animations.get(animName);
        if(info.secondaryPrefix == null || info.secondaryPrefix == "") {
            combineStatusLabel.text = "Nothing to remove.";
            return;
        }

        info.secondaryPrefix = null;
        info.secondaryOffset = null;

        reloadCharacter(currentCharacterName);
        selectDropDownItem(animationDropDown, animName);
        refreshAnimationFields(animName);
        selectDropDownItem(combineTargetAnimDropDown, animName);
        refreshCombineFieldsFromTarget();
        combineStatusLabel.text = "Removed overlay from '" + animName + "'.";
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

    private function reloadCharacter(characterName:String, ?preserveShadow:Bool = false):Void {
        currentCharacterName = characterName;
        normalizeCharacterInfo(currentConfig());
        if(!preserveShadow) {
            clearShadowCharacter();
        }

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
        rebuildCombineDropDowns();

        if(isAtlasTabActive) {
            var files = currentAtlasFiles();
            if(files.length == 0) files = [""];
            syncingUi = true;
            populateDropDown(atlasFileDropDown, files);
            syncingUi = false;
            rebuildAtlasView();
        }
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
        ensureAtlasModeDropDown();
        selectDropDownItem(atlasModeDropDown, currentAtlasMode());

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
            clippingAdjustment: [],
            isAnimateAtlas: false,
            atlasMode: MODE_SPARROW
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
        if(value.length == 0) {
            fileValidationLabel.text = "Asset missing";
            return;
        }

        var mode:String = currentAtlasMode();
        var report:String = "";

        for(entry in value.split(",")) {
            var trimmed:String = entry.trim();
            if(trimmed.length == 0) continue;
            if(report.length > 0) report += " | ";
            report += validateAtlasEntry(trimmed, mode);
        }

        fileValidationLabel.text = report.length > 0 ? report : "Asset missing";
    }

    private function validateAtlasEntry(entry:String, mode:String):String {
        var clean:String = entry;
        var dot:Int = clean.lastIndexOf(".");
        if(dot >= 0) clean = clean.substr(0, dot);

        if(mode == MODE_ANIMATE) {
            var animationPath:String = Paths.getPath('images/${clean}/Animation.json', TEXT, "shared");
            var hasAnimation:Bool = Paths.assetExists(animationPath, TEXT);

            var spritemapIdx:Int = 1;
            var spritemapsFound:Int = 0;
            while(spritemapIdx <= 32) {
                var pngPath:String = Paths.getPath('images/${clean}/spritemap${spritemapIdx}.png', IMAGE, "shared");
                var jsonPath:String = Paths.getPath('images/${clean}/spritemap${spritemapIdx}.json', TEXT, "shared");
                if(!Paths.assetExists(pngPath, IMAGE) || !Paths.assetExists(jsonPath, TEXT)) break;
                spritemapsFound++;
                spritemapIdx++;
            }

            if(spritemapsFound == 0) {
                var altPng:String = Paths.getPath('images/${clean}/spritemap.png', IMAGE, "shared");
                var altJson:String = Paths.getPath('images/${clean}/spritemap.json', TEXT, "shared");
                if(Paths.assetExists(altPng, IMAGE) && Paths.assetExists(altJson, TEXT)) spritemapsFound = 1;
            }

            if(hasAnimation && spritemapsFound > 0) {
                return clean + ": found (" + spritemapsFound + " spritemap" + (spritemapsFound == 1 ? "" : "s") + ")";
            }
            var missing:Array<String> = [];
            if(!hasAnimation) missing.push("Animation.json");
            if(spritemapsFound == 0) missing.push("spritemap1.png/json");
            return clean + ": missing " + missing.join(", ");
        }

        if(mode == MODE_PACKER) {
            var pngPath:String = Paths.getPath('images/${clean}.png', IMAGE, "shared");
            var txtPath:String = Paths.getPath('images/${clean}.txt', TEXT, "shared");
            var jsonPath:String = Paths.getPath('images/${clean}.json', TEXT, "shared");
            var hasPng:Bool = Paths.assetExists(pngPath, IMAGE);
            var hasData:Bool = Paths.assetExists(txtPath, TEXT) || Paths.assetExists(jsonPath, TEXT);
            if(hasPng && hasData) return clean + ": found";
            var missing:Array<String> = [];
            if(!hasPng) missing.push(".png");
            if(!hasData) missing.push(".txt/.json");
            return clean + ": missing " + missing.join(", ");
        }

        var pngPath:String = Paths.getPath('images/${clean}.png', IMAGE, "shared");
        var xmlPath:String = Paths.getPath('images/${clean}.xml', TEXT, "shared");
        var hasPng:Bool = Paths.assetExists(pngPath, IMAGE);
        var hasXml:Bool = Paths.assetExists(xmlPath, TEXT);
        if(hasPng && hasXml) return clean + ": found";
        var missing:Array<String> = [];
        if(!hasPng) missing.push(".png");
        if(!hasXml) missing.push(".xml");
        return clean + ": missing " + missing.join(", ");
    }

    private function renameFileFieldForMode(raw:String, mode:String):String {
        if(raw == null) return "";
        var parts:Array<String> = raw.split(",");
        var out:Array<String> = [];
        for(piece in parts) {
            var trimmed:String = piece.trim();
            if(trimmed.length == 0) continue;
            var dot:Int = trimmed.lastIndexOf(".");
            var hasSlash:Bool = trimmed.indexOf("/") >= 0;
            if(mode == MODE_ANIMATE) {
                if(dot >= 0) trimmed = trimmed.substr(0, dot);
            } else if(mode == MODE_PACKER) {
                if(dot >= 0) trimmed = trimmed.substr(0, dot);
                if(!hasSlash) trimmed = trimmed + ".json";
            } else {
                if(dot >= 0) trimmed = trimmed.substr(0, dot);
                if(!hasSlash) trimmed = trimmed + ".xml";
            }
            out.push(trimmed);
        }
        return out.join(",");
    }

    private function currentAtlasMode():String {
        var mode:String = currentConfig().atlasMode;
        if(mode != null && mode != "") return mode;
        if(currentConfig().isAnimateAtlas == true) return MODE_ANIMATE;
        return MODE_SPARROW;
    }

    private function ensureAtlasModeDropDown():Void {
        if(atlasModeDropDown == null) return;
        if(atlasModeDropDown.dataSource.size == ATLAS_MODE_LABELS.length) return;
        var prev:Bool = syncingUi;
        syncingUi = true;
        atlasModeDropDown.dataSource.clear();
        for(entry in ATLAS_MODE_LABELS) atlasModeDropDown.dataSource.add({id: entry.id, text: entry.text});
        syncingUi = prev;
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
            FunkinCursor.hide();
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

    private function bindAtlasHandlers():Void {
        mainTabView.onChange = function(_) {
            if(mainTabView.pageIndex == ATLAS_TAB_INDEX) {
                showAtlasView();
            } else if(isAtlasTabActive) {
                hideAtlasView();
            }
        };

        atlasFileDropDown.onChange = function(_) {
            if(syncingUi || !isAtlasTabActive) return;
            rebuildAtlasView();
        };

        atlasPrefixDropDown.onChange = function(_) {
            if(syncingUi || !isAtlasTabActive) return;
            refreshAtlasOverlay();
        };
    }

    private function showAtlasView():Void {
        if(isAtlasTabActive) return;
        isAtlasTabActive = true;
        characterStorage.visible = false;
        if(shadowEntity != null) shadowEntity.visible = false;

        var files = currentAtlasFiles();
        if(files.length == 0) files = [""];
        syncingUi = true;
        populateDropDown(atlasFileDropDown, files);
        syncingUi = false;

        rebuildAtlasView();
    }

    private function hideAtlasView():Void {
        if(!isAtlasTabActive) return;
        isAtlasTabActive = false;
        destroyAtlasView();
        characterStorage.visible = true;
        if(shadowEntity != null) shadowEntity.visible = true;
        camFollow.setPosition(camPos.x, camPos.y);
        camGame.focusOn(camFollow.getPosition());
    }

    private function destroyAtlasView():Void {
        atlasGroup.clear();
        atlasViewSprite = null;
        atlasViewOverlay = null;
    }

    private function rebuildAtlasView():Void {
        destroyAtlasView();
        atlasInfoLabel.text = "";

        var files = currentAtlasFiles();
        if(files.length == 0) {
            atlasInfoLabel.text = "No atlas file configured.";
            return;
        }

        var fileIdx = atlasFileDropDown.selectedIndex;
        if(fileIdx < 0 || fileIdx >= files.length) fileIdx = 0;
        var xmlFile = files[fileIdx];

        var basePath = xmlFile;
        var dotIndex = xmlFile.lastIndexOf(".");
        if(dotIndex >= 0) basePath = xmlFile.substr(0, dotIndex);

        var imagePath:String = Paths.getPath('images/${basePath}.png', IMAGE, "shared");
        if(!Paths.assetExists(imagePath, IMAGE)) {
            atlasInfoLabel.text = "Image not found: " + basePath;
            return;
        }

        var frames = loadXmlFrames(xmlFile);

        atlasViewSprite = new FlxSprite();
        atlasViewSprite.loadGraphic(Paths.image(basePath));
        atlasViewSprite.antialiasing = false;

        var atlasW = atlasViewSprite.frameWidth;
        var atlasH = atlasViewSprite.frameHeight;
        var uiPanelWidth = 540;
        var maxW = (FlxG.width - uiPanelWidth) * 0.9;
        var maxH = FlxG.height * 0.9;
        var displayScale = Math.min(maxW / atlasW, maxH / atlasH);
        if(displayScale > 1.0) displayScale = 1.0;

        atlasViewSprite.scale.set(displayScale, displayScale);
        atlasViewSprite.updateHitbox();
        var availW = FlxG.width - uiPanelWidth;
        atlasViewSprite.x = availW / 2 - atlasViewSprite.width / 2;
        atlasViewSprite.y = FlxG.height / 2 - atlasViewSprite.height / 2;
        atlasViewSprite.cameras = [camGame];
        atlasGroup.add(atlasViewSprite);

        var dispW = Std.int(Math.max(1, atlasW * displayScale));
        var dispH = Std.int(Math.max(1, atlasH * displayScale));
        atlasViewOverlay = new FlxSprite(atlasViewSprite.x, atlasViewSprite.y);
        atlasViewOverlay.makeGraphic(dispW, dispH, FlxColor.TRANSPARENT, true);
        atlasViewOverlay.cameras = [camGame];
        atlasGroup.add(atlasViewOverlay);

        var selectedPrefix = getDropDownValue(atlasPrefixDropDown, "");
        var drawnCount = drawAtlasFrameRects(frames, selectedPrefix, atlasW, displayScale);

        atlasInfoLabel.text = '${atlasW}x${atlasH} | ${drawnCount}/${frames.length} frames';

        rebuildAtlasPrefixDropDown(frames);

        camFollow.setPosition(atlasViewSprite.x + atlasViewSprite.width / 2, atlasViewSprite.y + atlasViewSprite.height / 2);
        camGame.zoom = 1.0;
        camGame.focusOn(camFollow.getPosition());
    }

    private function refreshAtlasOverlay():Void {
        if(atlasViewOverlay == null || atlasViewSprite == null) return;

        var files = currentAtlasFiles();
        if(files.length == 0) return;
        var fileIdx = atlasFileDropDown.selectedIndex;
        if(fileIdx < 0 || fileIdx >= files.length) fileIdx = 0;

        var frames = loadXmlFrames(files[fileIdx]);
        var dispW = atlasViewOverlay.frameWidth;
        var dispH = atlasViewOverlay.frameHeight;
        var atlasW = atlasViewSprite.frameWidth;
        var displayScale = dispW / atlasW;
        var selectedPrefix = getDropDownValue(atlasPrefixDropDown, "");

        var bd = atlasViewOverlay.pixels;
        bd.lock();
        bd.fillRect(new Rectangle(0, 0, dispW, dispH), 0x00000000);
        bd.unlock();

        var drawnCount = drawAtlasFrameRects(frames, selectedPrefix, atlasW, displayScale);
        atlasInfoLabel.text = '${atlasW}x${atlasViewSprite.frameHeight} | ${drawnCount}/${frames.length} frames';
    }

    private function drawAtlasFrameRects(frames:Array<AtlasFrame>, prefix:String, atlasW:Int, displayScale:Float):Int {
        if(atlasViewOverlay == null || frames.length == 0) return 0;

        var bd = atlasViewOverlay.pixels;
        var dispW = atlasViewOverlay.frameWidth;
        var dispH = atlasViewOverlay.frameHeight;
        var lineColor:UInt = 0xFF44FFAA;
        var count = 0;

        var allowedSet:Map<String, Bool> = null;
        if(prefix != "" && currentAtlasMode() == MODE_ANIMATE) {
            var folder:String = currentAnimationFolder();
            if(folder != "") {
                var symbolMap:Map<String, Array<String>> = loadSymbolSpriteMap(folder);
                if(symbolMap.exists(prefix)) {
                    allowedSet = new Map();
                    for(spriteName in symbolMap.get(prefix)) allowedSet.set(spriteName, true);
                }
            }
        }

        bd.lock();
        for(frame in frames) {
            if(prefix != "") {
                if(allowedSet != null) {
                    if(!allowedSet.exists(frame.name)) continue;
                } else if(!frame.name.startsWith(prefix)) {
                    continue;
                }
            }

            var rx = Std.int(frame.x * displayScale);
            var ry = Std.int(frame.y * displayScale);
            var rw = Math.max(2, Std.int(frame.width * displayScale));
            var rh = Math.max(2, Std.int(frame.height * displayScale));

            if(rx >= dispW || ry >= dispH) continue;
            var rRight = Std.int(Math.min(rx + rw, dispW));
            var rBottom = Std.int(Math.min(ry + rh, dispH));
            rw = rRight - rx;
            rh = rBottom - ry;
            if(rw < 1 || rh < 1) continue;

            bd.fillRect(new Rectangle(rx, ry, rw, 1), lineColor);
            bd.fillRect(new Rectangle(rx, rBottom - 1, rw, 1), lineColor);
            bd.fillRect(new Rectangle(rx, ry, 1, rh), lineColor);
            bd.fillRect(new Rectangle(rRight - 1, ry, 1, rh), lineColor);
            count++;
        }
        bd.unlock();
        atlasViewOverlay.dirty = true;

        return count;
    }

    private function currentAnimationFolder():String {
        if(currentAtlasMode() != MODE_ANIMATE) return "";
        var files:Array<String> = currentAtlasFiles();
        if(files.length == 0) return "";
        var fileIdx:Int = atlasFileDropDown.selectedIndex;
        if(fileIdx < 0 || fileIdx >= files.length) fileIdx = 0;
        var basePath:String = files[fileIdx];
        var dot:Int = basePath.lastIndexOf(".");
        if(dot >= 0) basePath = basePath.substr(0, dot);
        var folder:String = siblingFolderOf(basePath);
        return folder != "" ? folder : basePath;
    }

    private function rebuildAtlasPrefixDropDown(frames:Array<AtlasFrame>):Void {
        var currentPrefix = getDropDownValue(atlasPrefixDropDown, "");

        var items:Array<String> = [""];
        var seen:Map<String, Bool> = new Map();

        if(currentAtlasMode() == MODE_ANIMATE) {
            var folder:String = currentAnimationFolder();
            if(folder != "") {
                for(symbol in loadAnimationSymbols(folder)) {
                    if(symbol.length > 0 && !seen.exists(symbol)) {
                        seen.set(symbol, true);
                        items.push(symbol);
                    }
                }
            }
        }

        for(frame in frames) {
            var name = frame.name;
            var trimEnd = name.length;
            while(trimEnd > 0) {
                var c = name.charCodeAt(trimEnd - 1);
                if(c == null || c < 48 || c > 57) break;
                trimEnd--;
            }
            var prefix = StringTools.rtrim(name.substr(0, trimEnd));
            if(prefix.length > 0 && !seen.exists(prefix)) {
                seen.set(prefix, true);
                items.push(prefix);
            }
        }

        syncingUi = true;
        populateDropDown(atlasPrefixDropDown, items);
        if(currentPrefix != "") selectDropDownItem(atlasPrefixDropDown, currentPrefix);
        syncingUi = false;
    }

    private function loadXmlFrames(xmlFile:String):Array<AtlasFrame> {
        var frames:Array<AtlasFrame> = [];
        var basePath = xmlFile;
        var dotIndex = xmlFile.lastIndexOf(".");
        if(dotIndex >= 0) basePath = xmlFile.substr(0, dotIndex);

        var dataPath = Paths.getPath('images/' + basePath + '.xml', TEXT, "shared");
        if(!Paths.assetExists(dataPath, TEXT)) {
            var spritemapPath:String = Paths.getPath('images/' + basePath + '.json', TEXT, "shared");
            if(Paths.assetExists(spritemapPath, TEXT)) {
                return parseSpritemapFrames(Paths.readText(spritemapPath));
            }
            return frames;
        }

        var raw = Paths.readText(dataPath);
        if(raw == null || raw.length == 0) return frames;

        var tagReg = ~/<SubTexture\s[^\/]*\/>/g;
        var nameReg = ~/name="([^"]*)"/;
        var xReg = ~/\bx="(\d+)"/;
        var yReg = ~/\by="(\d+)"/;
        var wReg = ~/width="(\d+)"/;
        var hReg = ~/height="(\d+)"/;

        var pos = 0;
        while(tagReg.matchSub(raw, pos)) {
            var mp = tagReg.matchedPos();
            pos = mp.pos + mp.len;
            var tag = tagReg.matched(0);

            if(!nameReg.match(tag) || !xReg.match(tag) || !yReg.match(tag) || !wReg.match(tag) || !hReg.match(tag)) continue;

            frames.push({
                name: nameReg.matched(1),
                x: Std.parseInt(xReg.matched(1)),
                y: Std.parseInt(yReg.matched(1)),
                width: Std.parseInt(wReg.matched(1)),
                height: Std.parseInt(hReg.matched(1))
            });
        }

        return frames;
    }

    private function parseSpritemapFrames(raw:String):Array<AtlasFrame> {
        var frames:Array<AtlasFrame> = [];
        if(raw == null || raw.length == 0) return frames;

        var data:Dynamic = null;
        try { data = Json.parse(raw); } catch(e:Dynamic) { return frames; }
        if(data == null) return frames;

        var atlasNode:Dynamic = Reflect.field(data, "ATLAS");
        if(atlasNode == null) atlasNode = Reflect.field(data, "atlas");
        if(atlasNode == null) return frames;

        var spritesArr:Dynamic = Reflect.field(atlasNode, "SPRITES");
        if(spritesArr == null) spritesArr = Reflect.field(atlasNode, "sprites");
        if(spritesArr == null || !Std.isOfType(spritesArr, Array)) return frames;

        for(entry in (cast spritesArr : Array<Dynamic>)) {
            var spr:Dynamic = Reflect.field(entry, "SPRITE");
            if(spr == null) spr = Reflect.field(entry, "sprite");
            if(spr == null) spr = entry;
            if(spr == null) continue;

            var name:String = stringFieldDyn(spr, ["name", "N"]);
            if(name == null || name == "") continue;

            var x:Float = dynNum(Reflect.field(spr, "x"));
            var y:Float = dynNum(Reflect.field(spr, "y"));
            var wv:Dynamic = Reflect.field(spr, "w");
            if(wv == null) wv = Reflect.field(spr, "width");
            var hv:Dynamic = Reflect.field(spr, "h");
            if(hv == null) hv = Reflect.field(spr, "height");
            var w:Float = dynNum(wv);
            var h:Float = dynNum(hv);

            if(w <= 0 || h <= 0) continue;

            frames.push({
                name: name,
                x: Std.int(x),
                y: Std.int(y),
                width: Std.int(w),
                height: Std.int(h)
            });
        }
        return frames;
    }

    private static function dynNum(v:Dynamic):Float {
        if(v == null) return 0;
        if(Std.isOfType(v, Float)) return cast v;
        if(Std.isOfType(v, Int)) return cast(v, Int);
        var f:Float = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? 0 : f;
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
