package play;

#if sys
import sys.FileSystem;
#end

import flixel.FlxG;
import play.PlayCamera;
import flixel.group.FlxGroup.FlxTypedGroup;
import openfl.utils.Assets;
import openfl.events.Event;

import ModInitialize.ConfigCharacters;
import SaveData.SaveType;

/**
* New modifier algorithm WIP.
*/
private typedef Modifier = {
    var enabled:Bool;
}

private typedef Modifiers = {
    var customHell:Modifier;
    var getGoodScrub:Modifier;
    var mirrorChart:Modifier;
    var singDrain:Modifier;
    var fadeInNotes:Modifier;
    var safeBalls:Modifier;
    var blindEffect:Modifier;
    var cameraMovement:Modifier;
    var botMode:Modifier;
}

class DefaultHandler {
    private static inline var SHAKE_DECAY:Float = 0.12;
    private static inline var SHAKE_RANGE_MULTIPLIER:Float = 140;

    public static var modifiers:Modifiers;

    public static var strumOffset:Float = 0;

    public static var sizeTimer:Int = 0; 
    public static var shakeCamTimer:Float = 0;
    public static var shakeCamTimerHUD:Float = 0;
    public static var strumOffsetEvent:Array<Float> = [0, 0];
    private static var strumOffsetArray:Array<Array<Float>> = [[0, 0], [0, 0]];
    private static var camAngle:Array<Float> = [0, 0, 0];
    private static var camPos:Array<Float> = [0, 0, 0];

    public static var tempNoteAbstracts:Array<String> = [];
    public static var preloadAddon:Bool = false;

    public static var strumSize:Array<Array<Float>> = new Array<Array<Float>>();

    private static var jitStrumSize:Bool = false;

    inline static public function getNoteTime(strumTime:Float):Float {
		return strumTime + (Conductor.instance.stepLengthMs * Note.AFFECTED_STRUMTIME);
	}

    inline static public function getcharacterJSON():Array<String> {
        #if sys
        var arrayer:Array<String> = new Array<String>();

        if (FileSystem.exists("assets/preload/characters")) {
            for (entry in FileSystem.readDirectory("assets/preload/characters"))
                arrayer.push(entry.split(".")[0]);
        }

        if (FileSystem.exists("funkin_assets/preload/data/characters")) {
            for (entry in FileSystem.readDirectory("funkin_assets/preload/data/characters"))
                arrayer.push(entry.split(".")[0]);
        }

        if (FileSystem.exists("mod_assets/characters")) {
            for (entry in FileSystem.readDirectory("mod_assets/characters"))
                arrayer.push(entry.split(".")[0]);
        }
        #else
        var arrayer:Array<String> = CoolUtil.coolTextFile("assets/data/characterList.txt");

        if(Assets.exists("mod_assets/data/characterList.txt")) {
            arrayer.concat(CoolUtil.coolTextFile("mod_assets/data/characterList.txt"));
        }
        #end

        return arrayer;
    }

    static public function resolveCharacterJSON(name:String):String {
        if(name == null) {
            return null;
        }

        var trimmedName:String = StringTools.trim(name);

        if(trimmedName.length == 0) {
            return null;
        }

        var lowerName:String = trimmedName.toLowerCase();

        for(characterName in getcharacterJSON()) {
            if(characterName != null && characterName.toLowerCase() == lowerName) {
                return characterName;
            }
        }

        return null;
    }

    static public function hasCharacterJSON(name:String):Bool {
        return resolveCharacterJSON(name) != null;
    }

    static public function compilePosition(strum:Float):Float {
        var noteY:Float = strumOffset;
        noteY += (strum - strumOffset);
        
        return noteY;
    }

    static public function spawn() {
        kill();

        strumOffset = 0;
        sizeTimer = 0;
        shakeCamTimer = 0;
        shakeCamTimerHUD = 0;
        strumOffsetEvent = [0, 0];
        strumOffsetArray = [[0, 0], [0, 0]];
        camPos = [0, 0, 0];
        camAngle = [0, 0, 0];
        tempNoteAbstracts = [];

        jitStrumSize = false;
        strumSize = new Array<Array<Float>>();

        modifiers = {
            customHell: {enabled: false},
            getGoodScrub: {enabled: false},
            mirrorChart: {enabled: false},
            singDrain: {enabled: false},
            fadeInNotes: {enabled: false},
            safeBalls: {enabled: false},
            blindEffect: {enabled: false},
            cameraMovement: {enabled: false},
            botMode: {enabled: false}
        };

        FlxG.stage.addEventListener(Event.ENTER_FRAME, update);
    }

    static public function kill() {
        strumOffset = 0;
        sizeTimer = 0;
        shakeCamTimer = 0;
        shakeCamTimerHUD = 0;
        strumOffsetEvent = null;
        strumOffsetArray = null;
        camPos = null;
        camAngle = null;
        tempNoteAbstracts = null;
        preloadAddon = false;
        jitStrumSize = false;
        strumSize = null;
        modifiers = null;

        FlxG.stage.removeEventListener(Event.ENTER_FRAME, update);
    }

    static public function setupUpdateInfo(_info:ConfigCharacters):ConfigCharacters {
        if(_info.iconFile == "" || _info.iconFile == null) {
            _info.iconFile = "iconGrid";
        }

        if(_info.clippingAdjustment == null) {
            _info.clippingAdjustment = [];
        }

        return _info;
    }

    static private function update(e:Event) {
        var mainCam:PlayCamera = cast FlxG.camera;
        var camHUD:PlayCamera = cast PlayState.camHUD;
        var noteCam:PlayCamera = cast PlayState.camNOTE;

        mainCam.engineAngle = camAngle[0] + caculateShake(35, shakeCamTimer);
        camHUD.engineAngle = camAngle[1] + caculateShake(30, shakeCamTimerHUD);
        noteCam.engineAngle = camAngle[2];

        mainCam.engineX = camPos[0];
        camHUD.engineX = camPos[1];

        noteCam.engineX = camPos[2] + caculateShake(3, shakeCamTimer);

        eventHandler();

        PlayState.opponentStrums.x = strumOffsetArray[0][0] + strumOffsetEvent[0];
        PlayState.playerStrums.x = strumOffsetArray[0][1] + strumOffsetEvent[0];
        PlayState.opponentStrums.y = strumOffsetArray[1][0] + strumOffsetEvent[1];
        PlayState.playerStrums.y = strumOffsetArray[1][1] + strumOffsetEvent[1];
    }

    static private function eventHandler():Void {
        if(shakeCamTimer > 0)
            shakeCamTimer = Math.max(0, shakeCamTimer - SHAKE_DECAY);

        if(shakeCamTimerHUD > 0)
            shakeCamTimerHUD = Math.max(0, shakeCamTimerHUD - SHAKE_DECAY);

        if(sizeTimer > 0)
            sizeTimer -= 1;
    }

    static private function caculateShake(divider:Int, shaker:Float):Float { //This was a lazy way of doing it
        if(shaker > 0)
            return FlxG.random.float(-shaker * SHAKE_RANGE_MULTIPLIER, shaker * SHAKE_RANGE_MULTIPLIER) / divider;

        return 0;
    }
}
