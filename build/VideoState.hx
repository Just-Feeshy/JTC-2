package;

import flixel.addons.transition.Transition;
import flixel.FlxState;

#if web
import openfl.net.NetConnection;
import openfl.net.NetStream;
import openfl.events.NetStatusEvent;
import openfl.media.Video;
#end

#if desktop
import vlc.VlcBitmap;
#end

/*
* Ducky was here :D
**/
class VideoState extends HelperStates {
    public static var VIDEO_FPS_CAP = 60;

    public var repeat:Bool = false;
    public var isFullscreen:Bool = false;
    public var inWindow:Bool = false;

    var state:FlxState;
    var path:String;

    var skip:Bool = false;

    #if desktop
	var bitmap:VlcBitmap;
	#end

    #if web
	var video:Video;
	var netStream:NetStream;
    #end

    public function new(state:FlxState, path:String) {
        this.state = state;
        this.path = path;
        
        super();
    }

    override function create() {
        super.create();

        if (FlxG.sound.music != null) {
            FlxG.sound.music.stop();
        }

        playVideo();
    }

    public function playVideo() {
        #if desktop
        var bitmap = new VlcBitmap();

        if(FlxG.stage.stageHeight / 9 < FlxG.stage.stageWidth / 16) {
            bitmap.set_width(FlxG.stage.stageHeight * (16 / 9));
            bitmap.set_height(FlxG.stage.stageHeight);
        }else {
            bitmap.set_width(FlxG.stage.stageWidth);
            bitmap.set_height(FlxG.stage.stageWidth / (16 / 9));
        }

        bitmap.onComplete = onVLCComplete;
        bitmap.onError = onVLCError;

        if(repeat)
            bitmap.repeat = -1;
        else
            bitmap.repeat = 0;

        /**precaution*/
        bitmap.isFullscreen = this.isFullscreen;
        bitmap.inWindow = this.inWindow;

        FlxG.addChildBelowMouse(bitmap);
        bitmap.play(checkFile(path));
        #end

        #if web
        var player:Video = new Video();
		player.x = 0;
		player.y = 0;
		FlxG.addChildBelowMouse(player);

        var netConnect = new NetConnection();
		netConnect.connect(null);
		var netStream = new NetStream(netConnect);
		netStream.client = {
			onMetaData: function() {
				player.attachNetStream(netStream);
				player.width = FlxG.width;
				player.height = FlxG.height;
			}
		};
		netConnect.addEventListener(NetStatusEvent.NET_STATUS, function(event:NetStatusEvent) {
			if(event.info.code == "NetStream.Play.Complete") {
				netStream.dispose();
				if(FlxG.game.contains(player)) FlxG.game.removeChild(player);

				FlxG.switchState(state);
			}
		});
		netStream.play(name);
        #end
    }

    override function update(elapsed) {
        super.update(elapsed);

        #if desktop
        if(controls.ACCEPT) {
            if (bitmap.isPlaying) {
                onVLCComplete();
            }
        }

        bitmap.volume = FlxG.sound.volume + 0.3;

        if (FlxG.sound.volume < 0.1) {
            bitmap.volume = 0;
        }
        #end
    }

    override public function switchTo(nextState:FlxState):Bool {


        super.switchTo(nextState);
    }

    #if desktop
    function onVLCComplete() {
        bitmap.stop();
        bitmap.dispose();

        if (FlxG.game.contains(vlcBitmap)) {
            FlxG.game.removeChild(vlcBitmap);
        }

        FlxG.switchState(state);
    }

    function onVLCError() {
        trace("Error: could not locate video.");
        FlxG.switchState(state);
    }

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
}