package;

import flixel.group.FlxGroup.FlxTypedGroup;
import sys.FileSystem;
import flixel.FlxG;
import betterShit.BetterCams;

import Note;

#if linc_luajit
import llua.LuaL;
import llua.State;
#end

class Compile { //WIP: For upcoming modchart
    public static var strumOffset:Float = 0;

    public static var sizeTimer:Int = 0; 
    public static var shakeCamTimer:Float = 0;
    public static var shakeCamTimerHUD:Float = 0;
    public static var timeFreeze:Float = 0;
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
        var arrayer:Array<String> = new Array<String>();

        for(i in 0...FileSystem.readDirectory("config/characters").length)
            arrayer.push(FileSystem.readDirectory("config/characters")[i].split(".")[0]);

        return arrayer;
    }

    static public function compilePosition(strum:Float):Float {
        var noteY:Float = strumOffset;
        noteY += (strum - strumOffset);
        
        return noteY;
    }

    static public function spawn() {
        kill();
    }

    static public function kill() {
        strumOffset = 0;
        sizeTimer = 0;
        shakeCamTimer = 0;
        shakeCamTimerHUD = 0;
        timeFreeze = 0;
        strumOffsetEvent = [0, 0];
        strumOffsetArray = [[0, 0], [0, 0]];
        camPos = [0, 0, 0];
        camAngle = [0, 0, 0];
        tempNoteAbstracts = [];
        preloadAddon = false;
        
        jitStrumSize = false;
        strumSize = new Array<Array<Float>>();
    }

    static public function update() {
        var mainCam:BetterCams = cast FlxG.camera;
        var camHUD:BetterCams = cast PlayState.camHUD;
        var noteCam:BetterCams = cast PlayState.camNOTE;

        mainCam.engineAngle = camAngle[0] + caculateShake(50, shakeCamTimer);
        camHUD.engineAngle = camAngle[1] + caculateShake(50, -shakeCamTimerHUD);
        noteCam.engineAngle = camAngle[2];

        mainCam.engineX = camPos[0];
        camHUD.engineX = camPos[1];

        noteCam.engineX = camPos[2] + caculateShake(5, shakeCamTimer);

        eventHandler();

        if(jitStrumSize || sizeTimer > 0) { //TODO: Make modchart for both c++ and lua
            PlayState.opponentStrums.forEachAlive(function(spr:Strum) {
                spr.scale.x = strumSize[spr.ID][0];
                spr.scale.y = strumSize[spr.ID][1] + (sizeTimer/100);
            });

            PlayState.playerStrums.forEachAlive(function(spr:Strum) {
                spr.scale.x = strumSize[spr.ID+4][0];
                spr.scale.y = strumSize[spr.ID+4][1] + (sizeTimer/100);
            });
        }

        PlayState.opponentStrums.x = strumOffsetArray[0][0] + strumOffsetEvent[0];
        PlayState.playerStrums.x = strumOffsetArray[0][1] + strumOffsetEvent[0];
        PlayState.opponentStrums.y = strumOffsetArray[1][0] + strumOffsetEvent[1];
        PlayState.playerStrums.y = strumOffsetArray[1][1] + strumOffsetEvent[1];
    }

    static private function eventHandler():Void { //Not for modchart
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