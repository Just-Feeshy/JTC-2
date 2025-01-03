package;

#if sys
import sys.FileSystem;
#end

import flixel.FlxG;
import feshixl.FeshCamera;
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
    var wobbleNotes:Modifier;
    var cameraMovement:Modifier;
}

class DefaultHandler {
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
		return strumTime + (Conductor.stepCrochet * Note.AFFECTED_STRUMTIME);
	}

    inline static public function getcharacterJSON():Array<String> {
        #if sys
        var arrayer:Array<String> = new Array<String>();

        for(i in 0...FileSystem.readDirectory("assets/characters").length)
            arrayer.push(FileSystem.readDirectory("assets/characters")[i].split(".")[0]);

        for(i in 0...FileSystem.readDirectory("mod_assets/characters").length)
            arrayer.push(FileSystem.readDirectory("mod_assets/characters")[i].split(".")[0]);
        #else
        var arrayer:Array<String> = CoolUtil.coolTextFile("assets/data/characterList.txt");

        if(Assets.exists("mod_assets/data/characterList.txt")) {
            arrayer.concat(CoolUtil.coolTextFile("mod_assets/data/characterList.txt"));
        }
        #end

        return arrayer;
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
            wobbleNotes: {enabled: false},
            cameraMovement: {enabled: false}
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
        var mainCam:FeshCamera = cast FlxG.camera;
        var camHUD:FeshCamera = cast PlayState.camHUD;
        var noteCam:FeshCamera = cast PlayState.camNOTE;

        mainCam.engineAngle = camAngle[0] + caculateShake(50, shakeCamTimer);
        camHUD.engineAngle = camAngle[1] + caculateShake(50, -shakeCamTimerHUD);
        noteCam.engineAngle = camAngle[2];

        mainCam.engineX = camPos[0];
        camHUD.engineX = camPos[1];

        noteCam.engineX = camPos[2] + caculateShake(5, shakeCamTimer);

        eventHandler();

        if(jitStrumSize || sizeTimer > 0) {
            PlayState.opponentStrums.forEachAlive(function(spr:Strum) {
                spr.engineWidth = strumSize[spr.ID][0];
                spr.engineHeight = strumSize[spr.ID][1] + (sizeTimer/100);
            });

            PlayState.playerStrums.forEachAlive(function(spr:Strum) {
                spr.engineWidth = strumSize[spr.ID+4][0];
                spr.engineHeight = strumSize[spr.ID+4][1] + (sizeTimer/100);
            });
        }

        PlayState.opponentStrums.x = strumOffsetArray[0][0] + strumOffsetEvent[0];
        PlayState.playerStrums.x = strumOffsetArray[0][1] + strumOffsetEvent[0];
        PlayState.opponentStrums.y = strumOffsetArray[1][0] + strumOffsetEvent[1];
        PlayState.playerStrums.y = strumOffsetArray[1][1] + strumOffsetEvent[1];
    }

    static private function eventHandler():Void {
        if(shakeCamTimer > 0)
            shakeCamTimer -= 0.2;

        if(shakeCamTimerHUD > 0)
            shakeCamTimerHUD -= 0.2;

        if(sizeTimer > 0)
            sizeTimer -= 1;
    }

    static private function caculateShake(divider:Int, shaker:Float):Float { //This was a lazy way of doing it
        if(shakeCamTimer > 0)
            return FlxG.random.float(-shakeCamTimer * 100, shakeCamTimer * 100) / divider;
        else
            return 0;
    }
}