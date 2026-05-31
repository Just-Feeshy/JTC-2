package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.input.keyboard.FlxKey;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import haxe.Json;
import haxe.io.Bytes;
import haxe.io.Path;
import haxe.ui.backend.flixel.UIState;
import haxe.ui.components.Button;
import haxe.ui.components.CheckBox;
import haxe.ui.components.DropDown;
import haxe.ui.components.Label;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextArea;
import haxe.ui.components.TextField;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.events.KeyboardEvent;
import openfl.net.FileReference;
import sys.FileSystem;
import sys.io.File;

import data.dialogue.ConversationData;
import data.dialogue.ConversationData.DialogueAssetEntry;
import data.dialogue.ConversationData.DialogueSoundEntry;
import data.dialogue.DialogueAnimationData;
import data.dialogue.DialogueSceneData;
import data.dialogue.DialogueSlot;
import data.dialogue.DialogueSpriteData;
import data.dialogue.LegacyDialogueAdapter;

import feshixl.FeshSprite;

import SaveData.SaveType;

using StringTools;

private enum abstract ImportKind(String) from String to String {
    var CatalogXml = "xml";
    var CatalogPng = "png";
    var SceneTxt = "txt";
    var SceneSound = "ogg";
}

/**
 * Editor for v2 ConversationData dialogue files.
 *
 * Built on HaxeUI (see assets/preload/data/dialogue-creator.xml) following the same
 * pattern as ShaderEventEditorState. The state owns one in-memory ConversationData;
 * every widget edit mutates that, and refreshes are pull-based: rebuild widgets from
 * data, never the other direction implicitly.
 */
@:build(haxe.ui.ComponentBuilder.build("assets/preload/data/dialogue-creator.xml"))
class DialogueCreatorState extends UIState {
    // --- Cameras ---
    var camHUD:FlxCamera;
    var camGame:FlxCamera;

    // --- Data being edited ---
    var data:ConversationData;
    var sceneIndex:Int = 0;
    var slot:DialogueSlot = SpeechBubble;

    // --- Preview sprites (live on camGame) ---
    var leftPortrait:FeshSprite;
    var rightPortrait:FeshSprite;
    var speechBubble:FeshSprite;
    var displayText:DialogueText;

    // --- File IO ---
    var fileRef:FileReference;
    var pendingImport:ImportKind;

    // --- Re-entrancy guard ---
    var suppressEvents:Bool = false;

    // --- HaxeUI component refs (matched to ids in dialogue-creator.xml) ---
    var instructionsLabel:Label;
    var statusLabel:Label;
    var slotSelector:DropDown;
    var assetSelector:DropDown;
    var attachAssetButton:Button;
    var centerXButton:Button;
    var xPosStepper:NumberStepper;
    var yPosStepper:NumberStepper;
    var sizeStepper:NumberStepper;
    var catalogSelector:DropDown;
    var importXmlButton:Button;
    var importPngButton:Button;
    var newAssetNameInput:TextField;
    var createAssetButton:Button;
    var catalogErrorLabel:Label;
    var selectedSlotLabel:Label;
    var existingAnimSelector:DropDown;
    var sourcePrefixSelector:DropDown;
    var animNameInput:TextField;
    var framerateStepper:NumberStepper;
    var loopedCheckbox:CheckBox;
    var createAnimButton:Button;
    var setMainAnimButton:Button;
    var sceneStepper:NumberStepper;
    var narratorDropDown:DropDown;
    var importTxtButton:Button;
    var importSoundButton:Button;
    var sceneTextArea:TextArea;
    var hexColorInput:TextField;
    var fontStyleInput:TextField;
    var speedStepper:NumberStepper;
    var textSizeStepper:NumberStepper;
    var soundIndexStepper:NumberStepper;
    var talkCheckbox:CheckBox;
    var playSceneButton:Button;
    var newSceneButton:Button;
    var sceneErrorLabel:Label;
    var exportButton:Button;
    var exportStatusLabel:Label;

    public function new() {
        super();
    }

    override function create():Void {
        camHUD = new FlxCamera();
        camGame = new FlxCamera();
        camHUD.bgColor.alpha = 0;

        FlxG.cameras.reset(camGame);
        FlxG.cameras.add(camHUD);
        FlixelCompat.setDefaultCameras([camHUD]);

        data = makeDefaultConversation();

        super.create();
        this.root.cameras = [camHUD];

        setupPreviewSprites();
        wireUi();
        refreshAll();

        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, onGlobalKey);
    }

    // ------------------------------------------------------------------------
    // Setup
    // ------------------------------------------------------------------------

    static function makeDefaultConversation():ConversationData {
        return {
            version: "2.0.0",
            scenes: [makeDefaultScene()],
            assetCatalog: [],
            soundCatalog: []
        };
    }

    static function makeDefaultScene():DialogueSceneData {
        return {
            speed: 1.0,
            talkingAnimation: null,
            text: ["left portrait", ""],
            font: "PhantomMuff.ttf",
            textColor: 0xFF000000,
            textSize: 32,
            soundIndex: 0,
            leftPortrait: {assetID: 2, animations: [], size: 0.8, x: 200, y: 60},
            rightPortrait: {assetID: 1, animations: [], size: 0.8, x: 720, y: 60},
            speechBubble: {assetID: 0, animations: [], size: 0.8, x: 144, y: 400}
        };
    }

    function setupPreviewSprites():Void {
        leftPortrait = new FeshSprite();
        rightPortrait = new FeshSprite();
        speechBubble = new FeshSprite();

        for (s in [leftPortrait, rightPortrait, speechBubble]) {
            s.antialiasing = SaveData.getData(SaveType.GRAPHICS);
            s.cameras = [camGame];
            add(s);
        }

        speechBubble.defaultCompiler = function() {
            speechBubble.frames = Paths.getSparrowAtlas("speech_bubble_talking", "shared");
            speechBubble.animation.addByPrefix("normal", "speech bubble normal", 24, true);
            speechBubble.playAnim("normal");
        }

        var escText:FlxText = new FlxText(30, 30, "ESCAPE - To Exit\n\nDialogue Creator v2");
        escText.cameras = [camGame];
        add(escText);
    }

    function wireUi():Void {
        instructionsLabel.text = "ESC - Back to Editors";
        statusLabel.text = "";

        // ---- Dialogue tab ----
        populateDropDown(slotSelector, [for (s in DialogueSlot.ALL) (s : String)]);
        selectDropDownItem(slotSelector, (slot : String));

        slotSelector.onChange = function(_) {
            if (suppressEvents) return;
            slot = cast getDropDownValue(slotSelector, (slot : String));
            selectedSlotLabel.text = "Selected slot: " + (slot : String);
            refreshSlotWidgets();
        };

        assetSelector.onChange = function(_) {/* selection commits on attach */};

        attachAssetButton.onClick = function(_) {
            var name = getDropDownValue(assetSelector, null);
            if (name == null || name == "") return;
            var idx = catalogIndex(name);
            slotData().assetName = name;
            slotData().assetID = idx;
            rebuildPreview();
        };

        centerXButton.onClick = function(_) {
            switch (slot) {
                case SpeechBubble:
                    speechBubble.screenCenter(X);
                    slotData().x = speechBubble.x;
                case RightPortrait:
                    rightPortrait.x = FlixelCompat.getScreenCenter(rightPortrait, X) + 300;
                    slotData().x = rightPortrait.x;
                case LeftPortrait:
                    leftPortrait.x = FlixelCompat.getScreenCenter(leftPortrait, X) - 300;
                    slotData().x = leftPortrait.x;
            }
            refreshSlotWidgets();
            refreshPreviewPosition();
        };

        xPosStepper.onChange = function(_) {
            if (suppressEvents) return;
            slotData().x = xPosStepper.pos;
            refreshPreviewPosition();
        };
        yPosStepper.onChange = function(_) {
            if (suppressEvents) return;
            slotData().y = yPosStepper.pos;
            refreshPreviewPosition();
        };
        sizeStepper.onChange = function(_) {
            if (suppressEvents) return;
            slotData().size = sizeStepper.pos;
            refreshPreviewPosition();
        };

        // ---- Sprites tab ----
        importXmlButton.onClick = function(_) startImport(CatalogXml);
        importPngButton.onClick = function(_) startImport(CatalogPng);

        createAssetButton.onClick = function(_) {
            var name = StringTools.trim(newAssetNameInput.text);
            catalogErrorLabel.text = "";
            if (name == "") {
                catalogErrorLabel.text = "Asset name required.";
                return;
            }
            if (catalogIndex(name) >= 0) {
                catalogErrorLabel.text = "Asset name already exists.";
                return;
            }
            data.assetCatalog.push({name: name, spritePath: null, xmlPath: null});
            newAssetNameInput.text = "";
            refreshCatalogDropdowns();
        };

        // ---- Animation tab ----
        createAnimButton.onClick = function(_) {
            var name = StringTools.trim(animNameInput.text);
            var prefix = getDropDownValue(sourcePrefixSelector, "");
            if (name == "" || prefix == "") return;
            slotData().animations.push({
                name: name,
                prefix: prefix,
                framerate: Std.int(framerateStepper.pos),
                looped: loopedCheckbox.selected,
                offset: []
            });
            animNameInput.text = "";
            framerateStepper.pos = 24;
            loopedCheckbox.selected = false;
            rebuildPreview();
        };

        setMainAnimButton.onClick = function(_) {
            implementSlotAnimations(spriteForSlot(SpeechBubble), SpeechBubble);
            implementSlotAnimations(spriteForSlot(LeftPortrait), LeftPortrait);
            implementSlotAnimations(spriteForSlot(RightPortrait), RightPortrait);

            var animName = getDropDownValue(existingAnimSelector, "");
            if (animName == "") return;

            spriteForSlot(slot).playAnim(animName);

            if (talkCheckbox.selected) {
                scene().talkingAnimation = animName;
                if (displayText != null) displayText.shouldPlayAnim(animName);
            } else {
                scene().talkingAnimation = null;
            }
        };

        // ---- Scene tab ----
        sceneStepper.onChange = function(_) {
            if (suppressEvents) return;
            var target:Int = Std.int(sceneStepper.pos) - 1;
            if (target == sceneIndex) return;
            sceneIndex = clampScene(target);
            rebuildPreview();
        };

        narratorDropDown.onChange = function(_) {
            if (suppressEvents) return;
            var choice = getDropDownValue(narratorDropDown, "left portrait");
            scene().text[0] = choice;
            applyNarratorVisibility(choice);
            if (displayText != null) {
                if (choice == "left portrait") displayText.attachSprite(leftPortrait);
                else displayText.attachSprite(rightPortrait);
            }
        };

        importTxtButton.onClick = function(_) startImport(SceneTxt);
        importSoundButton.onClick = function(_) startImport(SceneSound);

        sceneTextArea.onChange = function(_) {
            if (suppressEvents) return;
            scene().text[1] = sceneTextArea.text;
        };

        hexColorInput.onChange = function(_) {
            if (suppressEvents) return;
            var t = hexColorInput.text.replace("#", "").trim();
            if (t == "") return;
            var parsed = Std.parseInt("0x" + t);
            if (parsed != null) scene().textColor = parsed;
        };

        fontStyleInput.onChange = function(_) {
            if (suppressEvents) return;
            var t = fontStyleInput.text.trim();
            if (t == "") return;
            var resolved = Paths.font(t);
            scene().font = (resolved != null) ? resolved : t;
        };

        speedStepper.onChange = function(_) {
            if (suppressEvents) return;
            scene().speed = speedStepper.pos;
        };
        textSizeStepper.onChange = function(_) {
            if (suppressEvents) return;
            scene().textSize = Std.int(textSizeStepper.pos);
        };
        soundIndexStepper.onChange = function(_) {
            if (suppressEvents) return;
            scene().soundIndex = Std.int(soundIndexStepper.pos);
        };
        talkCheckbox.onChange = function(_) {
            if (suppressEvents) return;
            if (talkCheckbox.selected) {
                var animName = getDropDownValue(existingAnimSelector, "");
                scene().talkingAnimation = (animName == "") ? null : animName;
            } else {
                scene().talkingAnimation = null;
            }
        };

        playSceneButton.onClick = function(_) {
            var narrator = scene().text[0];
            if (narrator == "left portrait") leftPortrait.playAnim(leftPortrait.animation.name);
            else rightPortrait.playAnim(rightPortrait.animation.name);
            refreshPreviewText(scene().text[1]);
        };

        newSceneButton.onClick = function(_) {
            data.scenes.push(makeDefaultScene());
            sceneIndex = data.scenes.length - 1;
            rebuildPreview();
        };

        // ---- Export tab ----
        exportButton.onClick = function(_) exportToJson();
    }

    // ------------------------------------------------------------------------
    // Refresh helpers
    // ------------------------------------------------------------------------

    function refreshAll():Void {
        refreshCatalogDropdowns();
        rebuildPreview();
    }

    /**
     * Full refresh: rebuild preview sprites from current scene's slot data, sync
     * every widget that depends on the scene/slot.
     */
    function rebuildPreview():Void {
        var leftAnim = (leftPortrait.animation.name != null) ? leftPortrait.animation.name : null;
        var rightAnim = (rightPortrait.animation.name != null) ? rightPortrait.animation.name : null;
        var bubbleAnim = (speechBubble.animation.name != null) ? speechBubble.animation.name : null;

        loadSpriteFromCatalog(leftPortrait, slotDataFor(LeftPortrait), LeftPortrait, leftAnim);
        loadSpriteFromCatalog(rightPortrait, slotDataFor(RightPortrait), RightPortrait, rightAnim);
        loadSpriteFromCatalog(speechBubble, slotDataFor(SpeechBubble), SpeechBubble, bubbleAnim);

        refreshPreviewPosition();
        refreshPreviewText(scene().text[1]);

        applyNarratorVisibility(scene().text[0]);
        refreshAnimDropdowns();
        refreshSlotWidgets();
        refreshSceneWidgets();
    }

    function loadSpriteFromCatalog(spr:FeshSprite, spriteData:DialogueSpriteData, which:DialogueSlot, preserveAnim:String):Void {
        var entry = resolveCatalogEntry(spriteData);

        var spriteBytes:Bytes = (entry != null) ? readPathBytes(entry.spritePath) : null;
        var xmlBytes:Bytes = (entry != null) ? readPathBytes(entry.xmlPath) : null;

        spr.implementXML(xmlBytes);
        spr.implementBitmap(spriteBytes);

        spr.completeCallback = function() {
            implementSlotAnimations(spr, which);
            if (preserveAnim != null && spr.animation.getByName(preserveAnim) != null) {
                spr.playAnim(preserveAnim);
            }
        }

        spr.compileSprite();
    }

    function refreshPreviewPosition():Void {
        for (s in DialogueSlot.ALL) {
            var spr = spriteForSlot(s);
            var sd = slotDataFor(s);
            spr.scale.set(sd.size, sd.size);
            spr.updateHitbox();
            spr.x = sd.x;
            spr.y = sd.y;
        }
    }

    function refreshPreviewText(text:String):Void {
        if (displayText == null) {
            displayText = new DialogueText(speechBubble.x + 100, speechBubble.y + Std.int(speechBubble.height / 3) + 10,
                Std.int(FlxG.width * 0.8), "", scene().textSize);
            displayText.cameras = [camGame];
            add(displayText);
        }

        displayText.setPosition(speechBubble.x + 100, speechBubble.y + Std.int(speechBubble.height / 3) + 10);
        displayText.size = scene().textSize;
        displayText.font = scene().font;
        displayText.color = scene().textColor;

        if (text != null && text.trim() != "") {
            displayText.resetText(text);
            displayText.start(0.04 / scene().speed, true);
        }
    }

    function applyNarratorVisibility(narrator:String):Void {
        if (narrator == "left portrait") {
            leftPortrait.visible = true;
            rightPortrait.visible = false;
            speechBubble.flipX = true;
        } else {
            leftPortrait.visible = false;
            rightPortrait.visible = true;
            speechBubble.flipX = false;
        }
    }

    function refreshSlotWidgets():Void {
        suppressEvents = true;
        var sd = slotData();
        xPosStepper.pos = sd.x;
        yPosStepper.pos = sd.y;
        sizeStepper.pos = sd.size;
        selectedSlotLabel.text = "Selected slot: " + (slot : String);
        suppressEvents = false;
    }

    function refreshSceneWidgets():Void {
        suppressEvents = true;
        sceneStepper.max = data.scenes.length;
        sceneStepper.pos = sceneIndex + 1;

        soundIndexStepper.max = Math.max(0, data.soundCatalog.length - 1);
        soundIndexStepper.pos = scene().soundIndex;

        speedStepper.pos = scene().speed;
        textSizeStepper.pos = scene().textSize;
        talkCheckbox.selected = (scene().talkingAnimation != null);

        if (sceneTextArea.text != scene().text[1]) sceneTextArea.text = scene().text[1];

        populateDropDown(narratorDropDown, ["left portrait", "right portrait"]);
        selectDropDownItem(narratorDropDown, scene().text[0]);
        suppressEvents = false;
    }

    function refreshCatalogDropdowns():Void {
        suppressEvents = true;

        var names:Array<String> = [for (e in data.assetCatalog) e.name];
        if (names.length == 0) names = [""];

        var prevAsset = getDropDownValue(assetSelector, "");
        populateDropDown(assetSelector, names);
        selectDropDownItem(assetSelector, prevAsset != "" ? prevAsset : names[0]);

        var prevCat = getDropDownValue(catalogSelector, "");
        populateDropDown(catalogSelector, names);
        selectDropDownItem(catalogSelector, prevCat != "" ? prevCat : names[0]);

        suppressEvents = false;
    }

    function refreshAnimDropdowns():Void {
        suppressEvents = true;
        var spr = spriteForSlot(slot);
        var prefixes = spr.getSourceAnimationName();
        if (prefixes.length == 0) prefixes = [""];
        populateDropDown(sourcePrefixSelector, prefixes);

        var existing:Array<String> = [for (a in slotData().animations) a.name];
        if (existing.length == 0) existing = [""];
        populateDropDown(existingAnimSelector, existing);
        suppressEvents = false;
    }

    // ------------------------------------------------------------------------
    // Slot routing
    // ------------------------------------------------------------------------

    inline function scene():DialogueSceneData return data.scenes[sceneIndex];
    inline function slotData():DialogueSpriteData return slotDataFor(slot);

    function slotDataFor(s:DialogueSlot):DialogueSpriteData {
        return switch (s) {
            case SpeechBubble: scene().speechBubble;
            case LeftPortrait: scene().leftPortrait;
            case RightPortrait: scene().rightPortrait;
        }
    }

    function spriteForSlot(s:DialogueSlot):FeshSprite {
        return switch (s) {
            case SpeechBubble: speechBubble;
            case LeftPortrait: leftPortrait;
            case RightPortrait: rightPortrait;
        }
    }

    function implementSlotAnimations(spr:FeshSprite, s:DialogueSlot):Void {
        spr.animation.destroyAnimations();
        for (a in slotDataFor(s).animations) {
            spr.animation.addByPrefix(a.name, a.prefix, a.framerate, a.looped);
        }
    }

    // ------------------------------------------------------------------------
    // Catalog resolution
    // ------------------------------------------------------------------------

    function catalogIndex(name:String):Int {
        if (name == null) return -1;
        for (i in 0...data.assetCatalog.length) {
            if (data.assetCatalog[i].name == name) return i;
        }
        return -1;
    }

    function resolveCatalogEntry(sd:DialogueSpriteData):DialogueAssetEntry {
        if (sd == null) return null;
        if (sd.assetName != null) {
            for (e in data.assetCatalog) if (e.name == sd.assetName) return e;
        }
        if (sd.assetID >= 0 && sd.assetID < data.assetCatalog.length) {
            return data.assetCatalog[sd.assetID];
        }
        return null;
    }

    function clampScene(target:Int):Int {
        if (target < 0) return 0;
        if (target >= data.scenes.length) return data.scenes.length - 1;
        return target;
    }

    // ------------------------------------------------------------------------
    // HaxeUI dropdown helpers (same shape as ShaderEventEditorState)
    // ------------------------------------------------------------------------

    function populateDropDown(dd:DropDown, items:Array<String>):Void {
        dd.dataSource.clear();
        for (item in items) dd.dataSource.add({id: item, text: item});
    }

    function selectDropDownItem(dd:DropDown, value:String):Void {
        for (i in 0...dd.dataSource.size) {
            var item:Dynamic = dd.dataSource.get(i);
            var id:Dynamic = item != null ? Reflect.field(item, "id") : null;
            if (Std.string(id) == value) {
                dd.selectedIndex = i;
                return;
            }
        }
        if (dd.dataSource.size > 0) dd.selectedIndex = 0;
    }

    function getDropDownValue(dd:DropDown, fallback:String):String {
        if (dd.selectedIndex < 0 || dd.selectedIndex >= dd.dataSource.size) return fallback;
        var item:Dynamic = dd.dataSource.get(dd.selectedIndex);
        if (item == null) return fallback;
        var id:Dynamic = Reflect.field(item, "id");
        return id == null ? fallback : Std.string(id);
    }

    // ------------------------------------------------------------------------
    // File IO
    // ------------------------------------------------------------------------

    function startImport(kind:ImportKind):Void {
        pendingImport = kind;
        fileRef = new FileReference();
        fileRef.addEventListener(Event.SELECT, onFileSelect);
        fileRef.addEventListener(Event.CANCEL, onFileCancel);
        fileRef.browse();
    }

    function onFileSelect(e:Event):Void {
        fileRef = cast(e.target, FileReference);
        fileRef.addEventListener(Event.COMPLETE, onFileLoaded);
        fileRef.load();
    }

    function onFileLoaded(e:Event):Void {
        fileRef = cast(e.target, FileReference);

        var expectedExt = "." + (pendingImport : String);
        if (fileRef.type != expectedExt) {
            statusLabel.text = "File type mismatch: expected " + expectedExt;
            cleanupFileRef();
            return;
        }

        var path = normalizeAssetPath(getSelectedPath());

        switch (pendingImport) {
            case CatalogXml | CatalogPng:
                var name = getDropDownValue(catalogSelector, "");
                if (name == "") {
                    catalogErrorLabel.text = "Create or select a catalog entry first.";
                    cleanupFileRef();
                    return;
                }
                var idx = catalogIndex(name);
                if (idx < 0) {
                    catalogErrorLabel.text = "Catalog entry not found: " + name;
                    cleanupFileRef();
                    return;
                }
                if (pendingImport == CatalogXml) data.assetCatalog[idx].xmlPath = path;
                else data.assetCatalog[idx].spritePath = path;
                catalogErrorLabel.text = "Bound " + (pendingImport : String) + ": " + path;
                rebuildPreview();

            case SceneTxt:
                scene().text[0] = getDropDownValue(narratorDropDown, "left portrait");
                scene().text[1] = fileRef.data.toString();
                refreshSceneWidgets();
                refreshPreviewText(scene().text[1]);

            case SceneSound:
                data.soundCatalog.push({
                    name: Path.withoutExtension(Path.withoutDirectory(path)),
                    path: path
                });
                scene().soundIndex = data.soundCatalog.length - 1;
                refreshSceneWidgets();
        }

        cleanupFileRef();
    }

    function onFileCancel(_):Void {
        cleanupFileRef();
    }

    function onFileSaveComplete(_):Void {
        exportStatusLabel.text = "Saved.";
        cleanupFileRef();
    }

    function onFileSaveError(_):Void {
        exportStatusLabel.text = "Save failed.";
        cleanupFileRef();
    }

    function cleanupFileRef():Void {
        if (fileRef == null) return;
        fileRef.removeEventListener(Event.SELECT, onFileSelect);
        fileRef.removeEventListener(Event.CANCEL, onFileCancel);
        fileRef.removeEventListener(Event.COMPLETE, onFileLoaded);
        fileRef.removeEventListener(Event.COMPLETE, onFileSaveComplete);
        fileRef.removeEventListener(IOErrorEvent.IO_ERROR, onFileSaveError);
        fileRef = null;
    }

    function getSelectedPath():String {
        #if sys
        return @:privateAccess fileRef.__path;
        #else
        return fileRef.name;
        #end
    }

    static function normalizeAssetPath(path:String):String {
        if (path == null || path.trim() == "") return "";
        var n = Path.normalize(path);
        var cwd = Path.normalize(Sys.getCwd());
        if (n.startsWith(cwd)) {
            n = n.substr(cwd.length);
            while (n.startsWith("/") || n.startsWith("\\")) n = n.substr(1);
        }
        return n;
    }

    static function readPathBytes(path:String):Bytes {
        if (path == null || path.trim() == "") return null;
        if (FileSystem.exists(path)) return File.getBytes(path);
        return null;
    }

    // ------------------------------------------------------------------------
    // Export
    // ------------------------------------------------------------------------

    function exportToJson():Void {
        var json = Json.stringify(data, "\t");
        if (json == null || json.length == 0) return;

        fileRef = new FileReference();
        fileRef.addEventListener(Event.COMPLETE, onFileSaveComplete);
        fileRef.addEventListener(Event.CANCEL, onFileCancel);
        fileRef.addEventListener(IOErrorEvent.IO_ERROR, onFileSaveError);
        fileRef.save(json.trim(), "dialogue.json");
    }

    // ------------------------------------------------------------------------
    // Lifecycle
    // ------------------------------------------------------------------------

    function onGlobalKey(event:KeyboardEvent):Void {
        var key:FlxKey = event.keyCode;
        if (key == FlxKey.ESCAPE) {
            FlxG.switchState(new OptionsMenuState("editors"));
        }
    }

    override function destroy():Void {
        cleanupFileRef();
        FlxG.stage.removeEventListener(KeyboardEvent.KEY_DOWN, onGlobalKey);
        leftPortrait = FlxDestroyUtil.destroy(leftPortrait);
        rightPortrait = FlxDestroyUtil.destroy(rightPortrait);
        speechBubble = FlxDestroyUtil.destroy(speechBubble);
        displayText = FlxDestroyUtil.destroy(displayText);
        super.destroy();
    }
}
