package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.input.keyboard.FlxKey;
import flixel.sound.FlxSound;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import openfl.media.Sound;
import haxe.Json;
import haxe.io.Bytes;
import haxe.io.Path;
import haxe.ui.backend.flixel.UIState;
import haxe.ui.components.Button;
import haxe.ui.components.CheckBox;
import haxe.ui.components.ColorPicker;
import haxe.ui.components.DropDown;
import haxe.ui.components.Label;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextArea;
import haxe.ui.components.TextField;
import haxe.ui.util.Color;
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
    var ConversationJson = "json";
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
    var animSlotSelector:DropDown;
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
    var textColorPicker:ColorPicker;
    var fontStyleInput:TextField;
    var speedStepper:NumberStepper;
    var textSizeStepper:NumberStepper;
    var textYStepper:NumberStepper;
    var soundIndexStepper:NumberStepper;
    var talkCheckbox:CheckBox;
    var shakeCameraCheckbox:CheckBox;
    var shakeAmplitudeStepper:NumberStepper;
    var playSceneButton:Button;
    var newSceneButton:Button;
    var sceneErrorLabel:Label;
    var exportButton:Button;
    var importButton:Button;
    var exportStatusLabel:Label;
    var consoleLog:TextArea;
    var clearLogButton:Button;
    var toggleLogButton:Button;
    var rightPanel:haxe.ui.containers.VBox;
    var minimizePanelButton:Button;
    var rightPanelCollapsed:Bool = false;
    var rightPanelTween:FlxTween;
    var lastLoadedSig:Map<DialogueSlot, String> = new Map();
    var previewSoundCache:Map<String, FlxSound> = new Map();
    var rightPanelVisibleLeft:Float = 0;
    var rightPanelHiddenLeft:Float = 0;
    static inline var RIGHT_PANEL_W:Float = 480;

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
            textY: 0,
            soundIndex: 0,
            shakeCamera: false,
            shakeAmplitude: 0.01,
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
    }

    function wireUi():Void {
        instructionsLabel.text = "ESC - Back to Editors";
        statusLabel.text = "";

        if (consoleLog != null) consoleLog.text = "";
        if (clearLogButton != null) {
            clearLogButton.onClick = function(_) {
                if (consoleLog != null) consoleLog.text = "";
            };
        }
        if (toggleLogButton != null) {
            toggleLogButton.onClick = function(_) {
                if (consoleLog == null) return;
                consoleLog.hidden = !consoleLog.hidden;
                toggleLogButton.text = consoleLog.hidden ? "Show" : "Hide";
            };
        }
        if (minimizePanelButton != null) {
            minimizePanelButton.onClick = function(_) toggleRightPanel();
        }
        haxe.Timer.delay(setupRightPanelLayout, 16);
        log("INFO", "Dialogue Creator ready.");

        // ---- Dialogue tab ----
        populateDropDown(slotSelector, [for (s in DialogueSlot.ALL) (s : String)]);
        selectDropDownItem(slotSelector, (slot : String));

        slotSelector.onChange = function(_) {
            if (suppressEvents) return;
            slot = cast getDropDownValue(slotSelector, (slot : String));
            syncSlotSelectors();
            refreshSlotWidgets();
            refreshAnimDropdowns();
        };

        if (animSlotSelector != null) {
            populateDropDown(animSlotSelector, [for (s in DialogueSlot.ALL) (s : String)]);
            selectDropDownItem(animSlotSelector, (slot : String));
            animSlotSelector.onChange = function(_) {
                if (suppressEvents) return;
                slot = cast getDropDownValue(animSlotSelector, (slot : String));
                syncSlotSelectors();
                refreshSlotWidgets();
                refreshAnimDropdowns();
            };
        }

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
            if (parsed != null) {
                scene().textColor = (0xFF << 24) | (parsed & 0xFFFFFF);
                syncTextColorWidgets(false);
                refreshPreviewText(scene().text[1]);
            }
        };

        if (textColorPicker != null) {
            textColorPicker.onChange = function(_) {
                if (suppressEvents) return;
                var c = textColorPicker.currentColor;
                if (c == null) return;
                var rgb = (c : Color).toInt() & 0xFFFFFF;
                scene().textColor = (0xFF << 24) | rgb;
                syncTextColorWidgets(true);
                refreshPreviewText(scene().text[1]);
            };
        }

        fontStyleInput.onChange = function(_) {
            if (suppressEvents) return;
            var t = fontStyleInput.text.trim();
            if (t == "") return;
            scene().font = t;
            refreshPreviewText(scene().text[1]);
        };

        speedStepper.onChange = function(_) {
            if (suppressEvents) return;
            scene().speed = speedStepper.pos;
        };
        textSizeStepper.onChange = function(_) {
            if (suppressEvents) return;
            scene().textSize = Std.int(textSizeStepper.pos);
            refreshPreviewText(scene().text[1]);
        };
        if (textYStepper != null) {
            textYStepper.onChange = function(_) {
                if (suppressEvents) return;
                scene().textY = textYStepper.pos;
                refreshPreviewText(scene().text[1]);
            };
        }
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

        if (shakeCameraCheckbox != null) {
            shakeCameraCheckbox.onChange = function(_) {
                if (suppressEvents) return;
                scene().shakeCamera = shakeCameraCheckbox.selected;
            };
        }
        if (shakeAmplitudeStepper != null) {
            shakeAmplitudeStepper.onChange = function(_) {
                if (suppressEvents) return;
                scene().shakeAmplitude = shakeAmplitudeStepper.pos;
            };
        }

        playSceneButton.onClick = function(_) playScene();

        newSceneButton.onClick = function(_) {
            data.scenes.push(cloneScene(scene()));
            sceneIndex = data.scenes.length - 1;
            refreshSlotWidgets();
            refreshSceneWidgets();
            refreshAnimDropdowns();
            freezePortraitOnLastFrame();
        };

        // ---- Import / Export tab ----
        exportButton.onClick = function(_) exportToJson();
        if (importButton != null) importButton.onClick = function(_) startImport(ConversationJson);
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
        var narrator = scene().text[0];
        var leftAnim = pickPortraitAnim(LeftPortrait, narrator == "left portrait");
        var rightAnim = pickPortraitAnim(RightPortrait, narrator == "right portrait");
        var bubbleAnim = (speechBubble.animation.name != null) ? speechBubble.animation.name : null;

        loadSpriteFromCatalog(leftPortrait, slotDataFor(LeftPortrait), LeftPortrait, leftAnim);
        loadSpriteFromCatalog(rightPortrait, slotDataFor(RightPortrait), RightPortrait, rightAnim);
        loadSpriteFromCatalog(speechBubble, slotDataFor(SpeechBubble), SpeechBubble, bubbleAnim);

        refreshPreviewPosition();
        refreshPreviewText(scene().text[1]);

        applyNarratorVisibility(narrator);
        refreshAnimDropdowns();
        refreshSlotWidgets();
        refreshSceneWidgets();
    }

    function syncSlotSelectors():Void {
        var prev = suppressEvents;
        suppressEvents = true;
        if (slotSelector != null) selectDropDownItem(slotSelector, (slot : String));
        if (animSlotSelector != null) selectDropDownItem(animSlotSelector, (slot : String));
        if (selectedSlotLabel != null) selectedSlotLabel.text = "Selected slot: " + (slot : String);
        suppressEvents = prev;
    }

    function cloneScene(src:DialogueSceneData):DialogueSceneData {
        return haxe.Json.parse(haxe.Json.stringify(src));
    }

    function freezePortraitOnLastFrame():Void {
        var narrator = scene().text[0];
        var spr = (narrator == "left portrait") ? leftPortrait : rightPortrait;
        if (spr == null || spr.animation.curAnim == null) return;
        var n = spr.animation.curAnim.numFrames;
        if (n <= 0) return;
        spr.animation.curAnim.curFrame = n - 1;
        spr.animation.curAnim.pause();
    }

    function syncTextColorWidgets(skipPicker:Bool):Void {
        var prev = suppressEvents;
        suppressEvents = true;
        var rgb = scene().textColor & 0xFFFFFF;
        var hex = StringTools.hex(rgb, 6);
        if (hexColorInput != null && hexColorInput.text != hex) hexColorInput.text = hex;
        if (!skipPicker && textColorPicker != null) textColorPicker.currentColor = rgb;
        suppressEvents = prev;
    }

    function pickPortraitAnim(s:DialogueSlot, isNarrator:Bool):String {
        if (isNarrator && scene().talkingAnimation != null) return scene().talkingAnimation;
        var anims = slotDataFor(s).animations;
        if (anims.length > 0) return anims[0].name;
        var current = spriteForSlot(s).animation.name;
        return current;
    }

    function playScene():Void {
        var narrator = scene().text[0];
        applyNarratorVisibility(narrator);

        var slot:DialogueSlot = (narrator == "left portrait") ? LeftPortrait : RightPortrait;
        var spr:FeshSprite = spriteForSlot(slot);
        var animName:String = scene().talkingAnimation;
        if (animName == null || spr.animation.getByName(animName) == null) {
            var anims = slotDataFor(slot).animations;
            if (anims.length > 0) animName = anims[0].name;
            else if (spr.animation.name != null) animName = spr.animation.name;
        }
        if (animName != null && spr.animation.getByName(animName) != null) {
            spr.playAnim(animName);
        }

        refreshPreviewText(scene().text[1]);

        if (scene().shakeCamera && scene().shakeAmplitude > 0) {
            camGame.shake(scene().shakeAmplitude, 0.35);
        }
    }

    function loadSpriteFromCatalog(spr:FeshSprite, spriteData:DialogueSpriteData, which:DialogueSlot, preserveAnim:String):Void {
        var entry = resolveCatalogEntry(spriteData);
        var sig = (entry == null) ? "<none>" : (entry.spritePath + "|" + entry.xmlPath);
        var prevSig = lastLoadedSig.get(which);

        if (sig == prevSig && spr.frames != null) {
            implementSlotAnimations(spr, which);
            applyPreserveAnim(spr, which, preserveAnim);
            return;
        }
        lastLoadedSig.set(which, sig);

        var spriteBytes:Bytes = (entry != null) ? readPathBytes(entry.spritePath) : null;
        var xmlBytes:Bytes = (entry != null) ? readPathBytes(entry.xmlPath) : null;

        try {
            spr.implementXML(xmlBytes);
        } catch (e:Dynamic) {
            warn("XML parse failed for " + (which : String) + " (" + (entry != null ? entry.xmlPath : "<none>") + "): " + Std.string(e));
            spr.implementXML(null);
        }
        spr.implementBitmap(spriteBytes);

        spr.completeCallback = function() {
            implementSlotAnimations(spr, which);
            applyPreserveAnim(spr, which, preserveAnim);
        }

        spr.compileSprite();
    }

    function applyPreserveAnim(spr:FeshSprite, which:DialogueSlot, preserveAnim:String):Void {
        var animToPlay = pickValidAnim(spr, preserveAnim);
        if (animToPlay == null) {
            for (a in slotDataFor(which).animations) {
                var fx = spr.animation.getByName(a.name);
                if (fx != null && fx.numFrames > 0) { animToPlay = a.name; break; }
            }
        }
        if (animToPlay != null) spr.playAnim(animToPlay);

        if (which == SpeechBubble && spr.animation.curAnim != null) {
            var n = spr.animation.curAnim.numFrames;
            if (n > 0) {
                spr.animation.curAnim.curFrame = n - 1;
                spr.animation.curAnim.pause();
            }
        }
    }

    static function pickValidAnim(spr:FeshSprite, name:String):String {
        if (name == null) return null;
        var fx = spr.animation.getByName(name);
        if (fx != null && fx.numFrames > 0) return name;
        return null;
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

        var baseY = speechBubble.y + Std.int(speechBubble.height / 3) + 10;
        displayText.setPosition(speechBubble.x + 100, baseY + scene().textY);
        displayText.size = scene().textSize;
        var resolvedFont = (scene().font != null) ? Paths.font(scene().font) : "";
        displayText.font = (resolvedFont != null && resolvedFont != "") ? resolvedFont : scene().font;
        displayText.color = scene().textColor;

        var snd = resolvePreviewSound(scene());
        displayText.sounds = (snd != null) ? [snd] : null;

        if (text != null && text.trim() != "") {
            displayText.resetText(text);
            displayText.start(0.04 / scene().speed, true);
        }
    }

    function resolvePreviewSound(s:DialogueSceneData):FlxSound {
        if (data.soundCatalog == null || data.soundCatalog.length == 0) return null;
        var entry:DialogueSoundEntry = null;
        if (s.soundName != null) {
            for (e in data.soundCatalog) if (e.name == s.soundName) { entry = e; break; }
        }
        if (entry == null && s.soundIndex >= 0 && s.soundIndex < data.soundCatalog.length) {
            entry = data.soundCatalog[s.soundIndex];
        }
        if (entry == null || entry.path == null || entry.path == "") return null;
        return loadPreviewSound(entry.path);
    }

    function loadPreviewSound(path:String):FlxSound {
        var cached = previewSoundCache.get(path);
        if (cached != null) return cached;
        if (!FileSystem.exists(path)) return null;
        var snd = new FlxSound().loadEmbedded(Sound.fromFile(path));
        previewSoundCache.set(path, snd);
        return snd;
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
        if (textYStepper != null) textYStepper.pos = scene().textY;
        syncTextColorWidgets(false);
        if (fontStyleInput != null && fontStyleInput.text != scene().font) fontStyleInput.text = scene().font;
        talkCheckbox.selected = (scene().talkingAnimation != null);
        if (shakeCameraCheckbox != null) shakeCameraCheckbox.selected = scene().shakeCamera;
        if (shakeAmplitudeStepper != null) shakeAmplitudeStepper.pos = scene().shakeAmplitude;

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

            case ConversationJson:
                try {
                    var raw = Json.parse(fileRef.data.toString());
                    data = LegacyDialogueAdapter.up(raw);
                    sanitizeCatalogPaths();
                    sceneIndex = 0;
                    slot = SpeechBubble;
                    refreshAll();
                    exportStatusLabel.text = "Loaded: " + path;
                    log("INFO", "Imported conversation: " + path);
                } catch (e:Dynamic) {
                    warn("Failed to load JSON: " + Std.string(e));
                    exportStatusLabel.text = "Load failed.";
                }

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

    function sanitizeCatalogPaths():Void {
        if (data == null || data.assetCatalog == null) return;
        for (e in data.assetCatalog) {
            if (e.spritePath != null) e.spritePath = normalizeAssetPath(e.spritePath);
            if (e.xmlPath != null) e.xmlPath = normalizeAssetPath(e.xmlPath);
        }
        if (data.soundCatalog != null) {
            for (s in data.soundCatalog) {
                if (s.path != null) s.path = normalizeAssetPath(s.path);
            }
        }
    }

    static function normalizeAssetPath(path:String):String {
        if (path == null || path.trim() == "") return "";
        var n = Path.normalize(path);
        var cwd = Path.normalize(Sys.getCwd());
        if (n.startsWith(cwd)) {
            n = n.substr(cwd.length);
            while (n.startsWith("/") || n.startsWith("\\")) n = n.substr(1);
            return n;
        }
        for (marker in ["mod_assets/", "assets/"]) {
            var idx = n.indexOf(marker);
            if (idx >= 0) return n.substr(idx);
        }
        return n;
    }

    static function readPathBytes(path:String):Bytes {
        if (path == null || path.trim() == "") return null;
        if (FileSystem.exists(path)) return File.getBytes(path);
        return null;
    }

    function setupRightPanelLayout():Void {
        if (rightPanel == null) return;
        rightPanel.includeInLayout = false;
        rightPanel.width = RIGHT_PANEL_W;
        rightPanel.top = 0;
        rightPanel.height = FlxG.height;
        rightPanelVisibleLeft = FlxG.width - RIGHT_PANEL_W - 40;
        rightPanelHiddenLeft = FlxG.width;
        rightPanel.left = rightPanelCollapsed ? rightPanelHiddenLeft : rightPanelVisibleLeft;

        if (minimizePanelButton != null) {
            minimizePanelButton.includeInLayout = false;
            minimizePanelButton.top = 16;
            syncMinimizeButtonPos();
        }
    }

    function syncMinimizeButtonPos():Void {
        if (minimizePanelButton == null || rightPanel == null) return;
        minimizePanelButton.left = rightPanel.left - minimizePanelButton.width - 48;
    }

    function toggleRightPanel():Void {
        if (rightPanel == null) return;
        rightPanelCollapsed = !rightPanelCollapsed;
        var target = rightPanelCollapsed ? rightPanelHiddenLeft : rightPanelVisibleLeft;
        if (minimizePanelButton != null) {
            minimizePanelButton.text = rightPanelCollapsed ? "<<" : ">>";
        }
        if (rightPanelTween != null) rightPanelTween.cancel();
        var start = rightPanel.left;
        rightPanelTween = FlxTween.num(start, target, 0.9, {ease: FlxEase.elasticOut}, function(v) {
            if (rightPanel != null) {
                rightPanel.left = v;
                syncMinimizeButtonPos();
            }
        });
    }

    function warn(msg:String):Void {
        log("WARN", msg);
        if (catalogErrorLabel != null) catalogErrorLabel.text = "Warning: " + msg;
        if (statusLabel != null) statusLabel.text = "Warning: " + msg;
    }

    function log(level:String, msg:String):Void {
        var line = "[" + level + "] " + msg;
        trace("[DialogueCreator] " + line);
        if (consoleLog != null) {
            var prev = consoleLog.text;
            consoleLog.text = (prev == null || prev == "") ? line : prev + "\n" + line;
        }
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
        for (k in previewSoundCache.keys()) {
            previewSoundCache.set(k, FlxDestroyUtil.destroy(previewSoundCache.get(k)));
        }
        previewSoundCache.clear();
        super.destroy();
    }
}
