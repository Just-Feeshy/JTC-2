package template;

import flixel.FlxG;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.graphics.frames.FlxAtlasFrames;
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

import SaveData.SaveType;
import IDialogue.IDialogue;
import ModInitialize;

import data.dialogue.ConversationData;
import data.dialogue.ConversationData.DialogueAssetEntry;
import data.dialogue.DialogueAnimationData;
import data.dialogue.DialogueSceneData;
import data.dialogue.DialogueSlot;
import data.dialogue.DialogueSpriteData;
import data.dialogue.LegacyDialogueAdapter;

using StringTools;

/**
 * Runtime presenter for v2 ConversationData.
 *
 * The JSON file can be either v1 (`{info: [...]}`) or v2 (`{version, scenes: [...]}`):
 * `parseJSON` runs both through `LegacyDialogueAdapter.up` so the rest of this class
 * only ever touches the v2 shape.
 *
 * Asset/sound resolution prefers name-based lookups (`assetName` / `soundName`) when
 * the mod has registered them via `bindAssetToName` / `bindSoundToName`, falling back
 * to the legacy `assetID` / `soundIndex` positional tables.
 */
class DialogueBuilder extends MusicBeatSubstate implements IDialogue {
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

    @:noCompletion var shadowText:FlxText;

    @:noCompletion var assetBinds:Array<String>;
    @:noCompletion var assetBindsByName:Map<String, String>;
    @:noCompletion var soundBinds:Array<FlxSound>;
    @:noCompletion var soundBindsByName:Map<String, FlxSound>;

    public function new() {
        _info = parseJSON();

        super();

        assetBinds = [];
        assetBindsByName = new Map();
        soundBinds = [];
        soundBindsByName = new Map();
    }

    function createAfterTransition():Void {
        leftPortrait = new FeshSprite();
        rightPortrait = new FeshSprite();
        speechBubble = new FeshSprite();

        add(leftPortrait);
        add(rightPortrait);
        add(speechBubble);

        leftPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        rightPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        speechBubble.antialiasing = SaveData.getData(SaveType.GRAPHICS);

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

        changingScene = false;
        dialogueScene++;
    }

    function applyAssetToSlot(spr:FeshSprite, sceneIdx:Int, s:DialogueSlot):Void {
        var sd = slotDataFor(sceneIdx, s);
        var path = resolveAssetPath(sd);
        spr.animation.destroyAnimations();
        if (path != null) {
            spr.frames = Paths.getSparrowAtlas(path);
        }
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
        if (sound != null) displayText.sounds = [sound];

        displayText.setPosition(speechBubble.x + 100, speechBubble.y + Std.int(speechBubble.height / 3) + 10);
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

        var anim = sd.animations[FlxG.random.int(0, sd.animations.length - 1)];
        spr.animation.addByPrefix(anim.name, anim.prefix, anim.framerate, anim.looped);
        spr.animation.play(anim.name);
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

    function resolveSound(s:DialogueSceneData):FlxSound {
        if (s.soundName != null && soundBindsByName.exists(s.soundName)) {
            return soundBindsByName.get(s.soundName);
        }
        if (s.soundIndex >= 0 && s.soundIndex < soundBinds.length) {
            return soundBinds[s.soundIndex];
        }
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

            var targetFocus = playstate.gf.getGraphicMidpoint();
            playstate.camFollow.setPosition(
                playstate.camGame.scroll.x + (playstate.camGame.width * 0.5),
                playstate.camGame.scroll.y + (playstate.camGame.height * 0.5)
            );

            dialogueCameraTween = FlxTween.tween(playstate.camFollow, {x: targetFocus.x, y: targetFocus.y}, 0.55, {
                ease: FlxEase.quadOut
            });

            targetFocus.put();

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

        super.destroy();
    }
}
