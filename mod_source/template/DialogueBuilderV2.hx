package template;

import flixel.FlxG;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.text.FlxText;
import flixel.sound.FlxSound;
import flixel.util.FlxTimer;
import flixel.FlxCamera;
import flixel.FlxState;
import feshixl.filters.GuassianBlur;
import feshixl.FeshSprite;
import openfl.media.Sound;
import openfl.filters.ShaderFilter;
import haxe.Json;
import haxe.io.Bytes;
import haxe.io.Path;
import sys.FileSystem;
import sys.io.File;

import SaveData.SaveType;
import IDialogue.IDialogue;
import play.DefaultHandler;

import data.dialogue.ConversationData;
import data.dialogue.ConversationData.DialogueAssetEntry;
import data.dialogue.ConversationData.DialogueSoundEntry;
import data.dialogue.DialogueAnimationData;
import data.dialogue.DialogueSceneData;
import data.dialogue.DialogueSlot;
import data.dialogue.DialogueSpriteData;
import data.dialogue.LegacyDialogueAdapter;

using StringTools;

/**
 * Runtime presenter for v2 ConversationData, paired with DialogueCreatorState.
 *
 * Differences from `DialogueBuilder`:
 *  - Auto-resolves assets and sounds from the JSON catalog when present. Code-side
 *    `bindAssetTo*` / `bindSoundTo*` calls still win over the catalog so mod scripts
 *    keep working.
 *  - Honors per-scene `textY`, `shakeCamera`, and `shakeAmplitude` from the new editor.
 *  - Reads catalog sprite/xml bytes directly from disk (matching the editor preview),
 *    falling back to `Paths.getSparrowAtlas` with a derived key when bytes aren't loadable.
 *
 * Subclasses bind extra runtime-only assets in `new()` then call `super()`.
 */
class DialogueBuilderV2 extends MusicBeatSubstate implements IDialogue {
    public var finishCallback:(dialogue:IDialogue)->Void;

    var blurEffect:GuassianBlur;
    var blurFilter:ShaderFilter;
    var playstateRef:PlayState;

    var _info:ConversationData;

    var leftPortrait:FeshSprite;
    var rightPortrait:FeshSprite;
    var speechBubble:FeshSprite;

    var displayText:DialogueText;

    var dialogueScene:Int = 0;

    var changingScene:Bool;
    var playSong:Bool;
    var dialogueSongPosition:Float = 0;
    var dialogueBeatLengthMs:Float = 0;
    var lastDialogueBeat:Int = -1;
    var dialogueCameraTween:FlxTween;

    var girlfriend:Character;

    /** Duration applied to the per-scene shake. Override in subclasses if needed. */
    var shakeDuration:Float = 0.35;

    @:noCompletion var shadowText:FlxText;

    @:noCompletion var assetBinds:Array<String>;
    @:noCompletion var assetBindsByName:Map<String, String>;
    @:noCompletion var soundBinds:Array<FlxSound>;
    @:noCompletion var soundBindsByName:Map<String, FlxSound>;

    /** Tracks per-slot catalog signatures so we only rebuild the sprite when the asset actually changes. */
    @:noCompletion var lastLoadedSig:Map<DialogueSlot, String>;

    public function new() {
        _info = parseJSON();

        super();

        assetBinds = [];
        assetBindsByName = new Map();
        soundBinds = [];
        soundBindsByName = new Map();
        lastLoadedSig = new Map();
    }

    function createAfterTransition():Void {
        leftPortrait = new FeshSprite();
        rightPortrait = new FeshSprite();
        speechBubble = new FeshSprite();

        add(leftPortrait);
        add(rightPortrait);
        add(speechBubble);

        var aa = SaveData.getData(SaveType.GRAPHICS);
        leftPortrait.antialiasing = aa;
        rightPortrait.antialiasing = aa;
        speechBubble.antialiasing = aa;

        syncDialogueDanceBeat();
        refreshDisplay();
    }

    // ------------------------------------------------------------------------
    // Scene render
    // ------------------------------------------------------------------------

    function refreshDisplay():Void {
        var prevScene = Std.int(Math.max(0, dialogueScene - 1));

        if (assetChanged(prevScene, dialogueScene, LeftPortrait) || dialogueScene == 0) {
            applyAssetToSlot(leftPortrait, dialogueScene, LeftPortrait);
            implementAnimPlay(LeftPortrait);
        }
        if (assetChanged(prevScene, dialogueScene, RightPortrait) || dialogueScene == 0) {
            applyAssetToSlot(rightPortrait, dialogueScene, RightPortrait);
            implementAnimPlay(RightPortrait);
        }
        if (assetChanged(prevScene, dialogueScene, SpeechBubble) || dialogueScene == 0) {
            applyAssetToSlot(speechBubble, dialogueScene, SpeechBubble);
            implementAnimPlay(SpeechBubble);
        }

        refreshDisplayPosition();

        if (sceneData(dialogueScene).text[0] == "left portrait") {
            rightPortrait.visible = false;
            leftPortrait.visible = true;
            speechBubble.flipX = true;
        } else {
            rightPortrait.visible = true;
            leftPortrait.visible = false;
            speechBubble.flipX = false;
        }

        if (shadowText != null) add(shadowText);

        if (displayText == null) {
            displayText = new DialogueText(0, 0, Std.int(FlxG.width * 0.8), "", sceneData(dialogueScene).textSize);
            add(displayText);
        }

        refreshDisplayText(sceneData(dialogueScene).text[1]);
        if (shadowText != null) refreshShadowText();

        triggerSceneShake(sceneData(dialogueScene));

        changingScene = false;
        dialogueScene++;
    }

    function triggerSceneShake(s:DialogueSceneData):Void {
        if (!s.shakeCamera || s.shakeAmplitude <= 0) return;

        var t = s.shakeAmplitude * 20;
        DefaultHandler.shakeCamTimer = t;
        DefaultHandler.shakeCamTimerHUD = t;
    }

    function applyAssetToSlot(spr:FeshSprite, sceneIdx:Int, s:DialogueSlot):Void {
        var sd = slotDataFor(sceneIdx, s);
        spr.animation.destroyAnimations();

        var catalogEntry = resolveCatalogEntry(sd);
        var sig = catalogEntry != null
            ? (catalogEntry.spritePath + "|" + catalogEntry.xmlPath)
            : "key:" + Std.string(resolveAssetPath(sd));

        if (lastLoadedSig.get(s) == sig && spr.frames != null) return;
        lastLoadedSig.set(s, sig);

        if (catalogEntry != null && tryLoadFromCatalog(spr, catalogEntry)) return;

        var key = resolveAssetPath(sd);
        if (key != null) spr.frames = Paths.getSparrowAtlas(key);
    }

    function tryLoadFromCatalog(spr:FeshSprite, entry:DialogueAssetEntry):Bool {
        var spriteBytes:Bytes = readPathBytes(entry.spritePath);
        var xmlBytes:Bytes = readPathBytes(entry.xmlPath);
        if (spriteBytes == null && xmlBytes == null) return false;

        try {
            spr.implementXML(xmlBytes);
        } catch (e:Dynamic) {
            spr.implementXML(null);
        }
        spr.implementBitmap(spriteBytes);
        spr.compileSprite();
        return true;
    }

    function assetChanged(prev:Int, curr:Int, s:DialogueSlot):Bool {
        var a = slotDataFor(prev, s);
        var b = slotDataFor(curr, s);
        if (a.assetName != null || b.assetName != null) return a.assetName != b.assetName;
        return a.assetID != b.assetID;
    }

    function refreshDisplayPosition():Void {
        for (s in DialogueSlot.ALL) {
            var spr = spriteForSlot(s);
            var sd = slotDataFor(dialogueScene, s);
            spr.scale.set(sd.size, sd.size);
            spr.updateHitbox();
            spr.x = sd.x;
            spr.y = sd.y;
        }
    }

    function refreshDisplayText(text:String = ""):Void {
        var s = sceneData(dialogueScene);

        if (s.talkingAnimation != null) {
            if (s.text[0] == "left portrait") displayText.attachSprite(leftPortrait);
            else displayText.attachSprite(rightPortrait);
            displayText.shouldPlayAnim(s.talkingAnimation);
        }

        var sound = resolveSound(s);
        displayText.sounds = (sound != null) ? [sound] : null;

        var baseY = speechBubble.y + Std.int(speechBubble.height / 3) + 10;
        displayText.setPosition(speechBubble.x + 100, baseY + s.textY);
        displayText.size = s.textSize;
        displayText.font = s.font;
        displayText.color = s.textColor;

        if (text.trim() != "") {
            displayText.resetText(text);
            displayText.start(0.04 / s.speed, true);
        }
    }

    function refreshShadowText():Void {
        var s = sceneData(dialogueScene);
        shadowText.setPosition(displayText.x + 2, displayText.y + 2);
        shadowText.size = s.textSize;
        shadowText.font = s.font;
    }

    function implementAnimPlay(s:DialogueSlot):Void {
        var sd = slotDataFor(dialogueScene, s);
        var spr = spriteForSlot(s);
        if (sd.animations.length == 0) return;

        for (a in sd.animations) {
            spr.animation.addByPrefix(a.name, a.prefix, a.framerate, a.looped);
        }

        var validNames:Array<String> = [];
        for (a in sd.animations) {
            var added = spr.animation.getByName(a.name);
            if (added != null && added.numFrames > 0) validNames.push(a.name);
        }
        if (validNames.length == 0) return;

        var name = validNames[FlxG.random.int(0, validNames.length - 1)];
        spr.animation.play(name);
    }

    // ------------------------------------------------------------------------
    // Slot routing
    // ------------------------------------------------------------------------

    inline function sceneData(i:Int):DialogueSceneData return _info.scenes[i];

    function slotDataFor(sceneIdx:Int, s:DialogueSlot):DialogueSpriteData {
        return switch (s) {
            case SpeechBubble: _info.scenes[sceneIdx].speechBubble;
            case LeftPortrait: _info.scenes[sceneIdx].leftPortrait;
            case RightPortrait: _info.scenes[sceneIdx].rightPortrait;
        }
    }

    function spriteForSlot(s:DialogueSlot):FeshSprite {
        return switch (s) {
            case SpeechBubble: speechBubble;
            case LeftPortrait: leftPortrait;
            case RightPortrait: rightPortrait;
        }
    }

    // ------------------------------------------------------------------------
    // Asset / sound resolution
    // ------------------------------------------------------------------------

    function resolveAssetPath(sd:DialogueSpriteData):String {
        if (sd == null) return null;
        if (sd.assetName != null && assetBindsByName.exists(sd.assetName)) {
            return assetBindsByName.get(sd.assetName);
        }
        if (sd.assetID >= 0 && sd.assetID < assetBinds.length) {
            return assetBinds[sd.assetID];
        }
        return null;
    }

    function resolveCatalogEntry(sd:DialogueSpriteData):DialogueAssetEntry {
        if (sd == null || _info.assetCatalog == null) return null;
        if (sd.assetName != null) {
            for (e in _info.assetCatalog) if (e.name == sd.assetName) return e;
        }
        if (sd.assetID >= 0 && sd.assetID < _info.assetCatalog.length) {
            return _info.assetCatalog[sd.assetID];
        }
        return null;
    }

    function resolveSound(s:DialogueSceneData):FlxSound {
        if (s.soundName != null && soundBindsByName.exists(s.soundName)) {
            return soundBindsByName.get(s.soundName);
        }
        if (s.soundIndex >= 0 && s.soundIndex < soundBinds.length) {
            return soundBinds[s.soundIndex];
        }
        // catalog fallback: lazy-load from path the editor saved
        if (_info.soundCatalog != null) {
            if (s.soundName != null) {
                for (entry in _info.soundCatalog) {
                    if (entry.name == s.soundName) return lazyLoadCatalogSound(entry, s.soundIndex);
                }
            }
            if (s.soundIndex >= 0 && s.soundIndex < _info.soundCatalog.length) {
                return lazyLoadCatalogSound(_info.soundCatalog[s.soundIndex], s.soundIndex);
            }
        }
        return null;
    }

    function lazyLoadCatalogSound(entry:DialogueSoundEntry, slotIdx:Int):FlxSound {
        if (entry == null || entry.path == null || entry.path == "") return null;
        if (!FileSystem.exists(entry.path)) return null;
        var snd = new FlxSound().loadEmbedded(Sound.fromFile(entry.path));
        if (slotIdx >= 0) soundBinds[slotIdx] = snd;
        if (entry.name != null) soundBindsByName.set(entry.name, snd);
        return snd;
    }

    static function readPathBytes(path:String):Bytes {
        if (path == null || path.trim() == "") return null;
        if (FileSystem.exists(path)) return File.getBytes(path);
        return null;
    }

    // ------------------------------------------------------------------------
    // Beat / dance / song
    // ------------------------------------------------------------------------

    public function implementShadowText():Void {
        shadowText = new FlxText(0, 0, Std.int(FlxG.width * 0.8), "", sceneData(dialogueScene).textSize);
    }

    public function implementShadowTextColor(color:FlxColor):Void {
        if (shadowText != null) shadowText.color = color;
    }

    public function implementSong(path:Sound, bpm:Int):Void {
        if (FlxG.sound.music.playing) FlxG.sound.music.stop();

        dialogueSongPosition = 0;
        dialogueBeatLengthMs = (60 / Math.max(bpm, 1)) * 1000;
        lastDialogueBeat = -1;
        FlxG.sound.playMusic(path);

        playSong = true;
    }

    function syncDialogueDanceBeat():Void {
        if (FlxG.sound.music == null || dialogueBeatLengthMs <= 0) {
            lastDialogueBeat = -1;
            return;
        }
        lastDialogueBeat = Math.floor(FlxG.sound.music.time / dialogueBeatLengthMs);
    }

    function updateDialogueGirlfriendDance():Void {
        if (FlxG.sound.music == null || !playSong || dialogueBeatLengthMs <= 0) return;

        dialogueSongPosition = FlxG.sound.music.time;
        var dialogueBeat:Int = Math.floor(dialogueSongPosition / dialogueBeatLengthMs);
        if (dialogueBeat == lastDialogueBeat) return;
        lastDialogueBeat = dialogueBeat;

        if (girlfriend == null || girlfriend.animation.curAnim == null) return;

        if (dialogueBeat % girlfriend.danceBeatTimer == 0
            && !girlfriend.isSinging()
            && !girlfriend.stunned
            && girlfriend.shouldPlayDance) {
            girlfriend.dance();
        }
    }

    // ------------------------------------------------------------------------
    // Binding API (called by per-mod subclasses)
    // ------------------------------------------------------------------------

    public function bindAssetToID(ID:Int, path:String):Void {
        Cache.cacheAsset(path);
        assetBinds[ID] = path;
    }

    public function bindAssetToName(name:String, path:String):Void {
        Cache.cacheAsset(path);
        assetBindsByName.set(name, path);
    }

    public function bindSoundToID(ID:Int, path:Sound):Void {
        soundBinds[ID] = new FlxSound().loadEmbedded(path);
    }

    public function bindSoundToName(name:String, path:Sound):Void {
        soundBindsByName.set(name, new FlxSound().loadEmbedded(path));
    }

    public function bindRawSoundToName(name:String, sound:FlxSound):Void {
        soundBindsByName.set(name, sound);
    }

    public function bindRawSoundToID(ID:Int, sound:FlxSound):Void {
        soundBinds[ID] = sound;
    }

    // ------------------------------------------------------------------------
    // Lifecycle
    // ------------------------------------------------------------------------

    public function createDialogue(state:FlxState):Void {
        var playstate:PlayState = cast(state, PlayState);

        playstateRef = playstate;
        girlfriend = playstate.gf;

        blurEffect = new GuassianBlur(0);
        blurFilter = new ShaderFilter(blurEffect);

        new FlxTimer().start(0.1, function(tmr:FlxTimer) {
            playstate.camGame.setTrashFilters([blurFilter]);

            playstate.camFollow.setPosition(
                playstate.camGame.scroll.x + (playstate.camGame.width * 0.5),
                playstate.camGame.scroll.y + (playstate.camGame.height * 0.5)
            );

            if (playstate.gf != null) {
                var targetFocus = playstate.gf.getGraphicMidpoint();
                dialogueCameraTween = FlxTween.tween(playstate.camFollow, {x: targetFocus.x, y: targetFocus.y}, 0.55, {
                    ease: FlxEase.quadOut
                });
                targetFocus.put();
            }

            new FlxTimer().start(0.2, function(tmr:FlxTimer) {
                FlxTween.tween(blurEffect, {size: 20}, 0.75, {
                    ease: FlxEase.quadOut,
                    onUpdate: function(_:FlxTween) {
                        if (playstateRef != null && playstateRef.camGame != null) {
                            playstateRef.camGame.invalidateFilters();
                        }
                    },
                    onComplete: function(twn:FlxTween) {
                        if (playstateRef != null && playstateRef.camGame != null) {
                            playstateRef.camGame.invalidateFilters();
                        }

                        playstate.openSubState(this);
                        createAfterTransition();
                    }
                });
            });
        });
    }

    public function parseJSON():ConversationData {
        var raw:Dynamic = Json.parse(Paths.readText(Paths.json(PlayState.SONG.song.toLowerCase() + "/dialogue")).trim());
        return LegacyDialogueAdapter.up(raw);
    }

    public function attachToCamera(camera:FlxCamera):Void {
        cameras = [camera];
    }

    public function destroyDialogue():Void {
        close();
    }

    override function update(elapsed:Float):Void {
        updateDialogueGirlfriendDance();

        if (controls.ACCEPT && !changingScene && dialogueScene < _info.scenes.length) {
            changingScene = true;
            refreshDisplay();
        } else if (controls.ACCEPT && !changingScene && !(dialogueScene < _info.scenes.length)) {
            changingScene = true;

            leftPortrait = FlxDestroyUtil.destroy(leftPortrait);
            rightPortrait = FlxDestroyUtil.destroy(rightPortrait);
            speechBubble = FlxDestroyUtil.destroy(speechBubble);
            displayText = FlxDestroyUtil.destroy(displayText);
            shadowText = FlxDestroyUtil.destroy(shadowText);

            FlxTween.tween(blurEffect, {size: 0}, 0.75, {
                ease: FlxEase.quadOut,
                onUpdate: function(_:FlxTween) {
                    if (playstateRef != null && playstateRef.camGame != null) {
                        playstateRef.camGame.invalidateFilters();
                    }
                },
                onComplete: function(twn:FlxTween) {
                    if (playstateRef != null && playstateRef.camGame != null) {
                        playstateRef.camGame.invalidateFilters();
                    }
                    finishCallback(this);
                }
            });
        }

        if (shadowText != null && displayText != null) {
            shadowText.text = displayText.text;
        }

        if (dialogueScene < _info.scenes.length) {
            var s = sceneData(dialogueScene);
            var snd = resolveSound(s);
            if (snd != null) {
                snd.volume = (FlxG.sound.volume > 0) ? (FlxG.sound.volume + 0.3) : 0;
            }
        }

        super.update(elapsed);
    }

    override function destroy():Void {
        dialogueCameraTween = FlxDestroyUtil.destroy(dialogueCameraTween);
        girlfriend = null;
        playstateRef = null;
        blurFilter = null;
        blurEffect = null;

        for (i in 0...soundBinds.length) {
            soundBinds[i] = FlxDestroyUtil.destroy(soundBinds[i]);
        }
        soundBinds = [];

        for (name in soundBindsByName.keys()) {
            soundBindsByName.set(name, FlxDestroyUtil.destroy(soundBindsByName.get(name)));
        }
        soundBindsByName.clear();

        lastLoadedSig = null;

        super.destroy();
    }
}
