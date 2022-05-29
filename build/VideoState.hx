package;

import flixel.FlxState;
import vlc.VlcBitmap;

/*
* Non stolen but based off of PolybiusProxy's VideoHandler code.
**/

class VideoState extends FlxState {
    public static var VIDEO_FPS_CAP = 60;

    var skip:Bool = false;

    public var mute(default, set):Bool = false;

    #if desktop
	var vlcBitmap:VlcBitmap;
	#end

    #if web
	var video:Video;
	var netStream:NetStream;
    #end

    #if desktop
    function checkFile(fileName:String):String {
        var pDir = "";
        var appDir = "file:///" + Sys.getCwd() + "/";
        if (fileName.indexOf(":") == -1) // Not a path
            pDir = appDir;
        else if (fileName.indexOf("file://") == -1 || fileName.indexOf("http") == -1) // C:, D: etc? ..missing "file:///" ?
            pDir = "file:///";

        return pDir + fileName;
    }
    #end

    function set_mute(value:Bool):Bool {

        mute = value;
        return value;
    }
}