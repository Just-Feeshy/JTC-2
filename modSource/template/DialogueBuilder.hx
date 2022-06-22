package template;

import flixel.FlxG;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.util.FlxDestroyUtil;
import flixel.system.FlxSound;
import flixel.util.FlxTimer;
import flixel.FlxCamera;
import flixel.FlxState;

import betterShit.BetterCams;
import feshixl.filters.GuassianBlur;
import feshixl.interfaces.IDialogue;
import openfl.filters.ShaderFilter;
import lime.utils.Assets;
import haxe.Json;

import SaveData.SaveType;
import ModInitialize;

using StringTools;

class DialogueBuilder extends MusicBeatSubstate implements IDialogue {
    public var finishCallback:(dialogue:IDialogue)->Void;

    var blurEffect:GuassianBlur;

    var _info:Array<DialogueData>;

    var leftPortrait:EditorSprite;
    var rightPortrait:EditorSprite;
    var speechBubble:EditorSprite;

    var displayText:DialogueText;

    var dialogueScene:Int = 0;

    var changingScene:Bool;
    var playSong:Bool;

    var girlfriend:Character;

    @:noCompletion var assetBinds:Array<String>;
    @:noCompletion var soundBinds:Array<FlxSound>;

    public function new() {
        super();

        assetBinds = [];
        soundBinds = [];

        _info = parseJSON();
    }

    function createAfterTransition():Void {
        refreshDisplay();
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

        try {
            leftPortrait.frames = Paths.getSparrowAtlas(assetBinds[_info[dialogueScene].leftPortrait.assetID]);
            rightPortrait.frames = Paths.getSparrowAtlas(assetBinds[_info[dialogueScene].rightPortrait.assetID]);
            speechBubble.frames = Paths.getSparrowAtlas(assetBinds[_info[dialogueScene].speechBubble.assetID]);
        }catch(e) {
            trace(assetBinds[_info[dialogueScene].leftPortrait.assetID] == null ? "No asset located for 'Left Portrait'" : "");
            trace(assetBinds[_info[dialogueScene].rightPortrait.assetID] == null ? "No asset located for 'Right Portrait'" : "");
            trace(assetBinds[_info[dialogueScene].speechBubble.assetID] == null ? "No asset located for 'Speech Bubble'" : "");
        }

        add(leftPortrait);
        add(rightPortrait);
        add(speechBubble);

        leftPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        rightPortrait.antialiasing = SaveData.getData(SaveType.GRAPHICS);
        speechBubble.antialiasing = SaveData.getData(SaveType.GRAPHICS);

        refreshDisplayPosition();

        implementAnimPlay("left portrait");
        implementAnimPlay("right portrait");
        implementAnimPlay("speech bubble");

        if(_info[dialogueScene].text[0] == "left portrait") {
            rightPortrait.visible = false;
            leftPortrait.visible = true;
            speechBubble.flipX = true;
        }else {
            rightPortrait.visible = true;
            leftPortrait.visible = false;
            speechBubble.flipX = false;
        }

        if(displayText == null) {
            displayText = new DialogueText(0, 0, Std.int(FlxG.width * 0.8), "", _info[dialogueScene].textSize);
            add(displayText);
        }
        
        refreshDisplayText(_info[dialogueScene].text[1]);

        changingScene = false;
        dialogueScene++;
    }

    function refreshDisplayPosition():Void {
        leftPortrait.scale.set(_info[dialogueScene].leftPortrait.size, _info[dialogueScene].leftPortrait.size);
        rightPortrait.scale.set(_info[dialogueScene].rightPortrait.size, _info[dialogueScene].rightPortrait.size);
        speechBubble.scale.set(_info[dialogueScene].speechBubble.size, _info[dialogueScene].speechBubble.size);

        leftPortrait.updateHitbox();
        rightPortrait.updateHitbox();
        speechBubble.updateHitbox();
        
        leftPortrait.x = _info[dialogueScene].leftPortrait.x;
        leftPortrait.y = _info[dialogueScene].leftPortrait.y;
        rightPortrait.x = _info[dialogueScene].rightPortrait.x;
        rightPortrait.y = _info[dialogueScene].rightPortrait.y;
        speechBubble.x = _info[dialogueScene].speechBubble.x;
        speechBubble.y = _info[dialogueScene].speechBubble.y;
    }

    function refreshDisplayText(text:String = "") {
        if(_info[dialogueScene].talkingAnimation != null) {
            if(_info[dialogueScene].text[0] == "left portrait") {
                displayText.attachSprite(leftPortrait);
            }else {
                displayText.attachSprite(rightPortrait);
            }

            displayText.shouldPlayAnim(_info[dialogueScene].talkingAnimation);
        }

        displayText.sounds = [soundBinds[_info[dialogueScene].soundIndex]];
        displayText.setPosition(speechBubble.x + 100, speechBubble.y + Std.int(speechBubble.height / 3) + 10);
        displayText.size = _info[dialogueScene].textSize;

        if(text.trim() != "") {
            displayText.resetText(text);
            displayText.start(0.04 / _info[dialogueScene].speed, true);
        }

        displayText.font = _info[dialogueScene].font;
        displayText.color = _info[dialogueScene].textColor;
    }

    function implementAnimPlay(sprString:String):Void {
        var dialogueInfo:DialogueSpriteData = null;
        var spr:EditorSprite = null;

        switch(sprString) {
            case "left portrait": spr = leftPortrait;
            case "right portrait": spr = rightPortrait;
            case "speech bubble": spr = speechBubble;
            default: return;
        }

        switch(sprString) {
            case "left portrait": dialogueInfo = _info[dialogueScene].leftPortrait;
            case "right portrait": dialogueInfo = _info[dialogueScene].rightPortrait;
            case "speech bubble": dialogueInfo = _info[dialogueScene].speechBubble;
            default: return;
        }

        if(dialogueInfo.animations.length > 0) {
            var animationInfo:AnimationInfo = dialogueInfo.animations[FlxG.random.int(0, dialogueInfo.animations.length - 1)];
            spr.animation.addByPrefix(animationInfo.name, animationInfo.prefix, animationInfo.framerate, animationInfo.looped);
            spr.animation.play(animationInfo.name);
        }
    }

    public function implementSong(path:String, bpm:Int):Void {
        if(FlxG.sound.music.playing) {
			FlxG.sound.music.stop();
        }

        Conductor.songPosition = 0;
        Conductor.changeBPM(bpm);
        FlxG.sound.playMusic(path);

        playSong = true;
    }

    public function bindAssetToID(ID:Int, path:String):Void {
        Cache.cacheAsset(path);
        assetBinds[ID] = path;
    }

    public function bindSoundToID(ID:Int, path:String):Void {
        soundBinds[ID] = new FlxSound().loadEmbedded(path);
    }

    public function bindRawSoundToID(ID:Int, sound:FlxSound):Void {
        soundBinds[ID] = sound;
    }

    public function createDialogue(state:FlxState):Void {
        var playstate:PlayState = cast(state, PlayState);

        girlfriend = playstate.gf;

        blurEffect = new GuassianBlur(0);

        new FlxTimer().start(0.1, function(tmr:FlxTimer) {
            playstate.camFollow.x = playstate.gf.getGraphicMidpoint().x;
            playstate.camFollow.y = playstate.gf.getGraphicMidpoint().y;
            playstate.camGame.focusOn(playstate.camFollow.getPosition());

            @:privateAccess
            playstate.camGame.wastefulFilters.push(new ShaderFilter(blurEffect));

            new FlxTimer().start(0.3, function(tmr:FlxTimer) {
                FlxTween.tween(blurEffect, {size: 20}, 0.75, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
                    playstate.openSubState(this);
                    createAfterTransition();
                }});
            });
        });
    }

    public function parseJSON():Array<DialogueData> {
        var dialogueData:Array<DialogueData> = cast Json.parse(Assets.getText(Paths.json(PlayState.SONG.song.toLowerCase() + "/dialogue")).trim()).info;
        return dialogueData;
    }

    public function attachToCamera(camera:FlxCamera):Void {
        cameras = [camera];
    }

    public function destroyDialogue():Void {
        close();
    }

    override function update(elapsed:Float):Void {
        if (FlxG.sound.music != null && playSong) {
			Conductor.songPosition += FlxG.elapsed * 1000;
        }

        if(controls.ACCEPT && !changingScene && dialogueScene < _info.length) {
            changingScene = true;

            refreshDisplay();
        }else if(controls.ACCEPT && !changingScene && !(dialogueScene < _info.length)) { //Too lazy
            changingScene = true;

            leftPortrait = FlxDestroyUtil.destroy(leftPortrait);
            rightPortrait = FlxDestroyUtil.destroy(rightPortrait);
            speechBubble = FlxDestroyUtil.destroy(speechBubble);

            displayText = FlxDestroyUtil.destroy(displayText);

            FlxTween.tween(blurEffect, {size: 0}, 0.75, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
                finishCallback(this);
            }});
            return;
        }

        if(FlxG.sound.volume > 0)
            soundBinds[_info[dialogueScene].soundIndex].volume = FlxG.sound.volume + 0.3;
        else
            soundBinds[_info[dialogueScene].soundIndex].volume = 0;

        super.update(elapsed);
    }

    override function beatHit():Void {
        if(curBeat % 1 == 0) {
            girlfriend.dance();
        }
    }

    override function destroy():Void {
        trace("did?");

        girlfriend = null;

        for(i in 0...soundBinds.length) {
            soundBinds[i] = FlxDestroyUtil.destroy(soundBinds[i]);
        }

        soundBinds = [];

        super.destroy();
    }
}