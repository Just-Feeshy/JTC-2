package;

import flixel.FlxG;
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
@:access(vlc.VlcBitmap)
class VideoState extends HelperStates {
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
        
        super("void", "void");
    }

    override function create() {
        FlxG.mouse.visible = false;

        super.create();

        if (FlxG.sound.music != null) {
            FlxG.sound.music.stop();
        }

        FlxG.camera.bgColor.alpha = 0;

        playVideo();
    }

    public function playVideo() {
        #if desktop
        bitmap = new VlcBitmap();

        if(FlxG.stage.stageHeight / 9 < FlxG.stage.stageWidth / 16) {
            bitmap.set_width(FlxG.stage.stageHeight * (16 / 9));
            bitmap.set_height(FlxG.stage.stageHeight);
        }else {
            bitmap.set_width(FlxG.stage.stageWidth);
            bitmap.set_height(FlxG.stage.stageWidth / (16 / 9));
        }

        bitmap.onComplete = finishedVideo;
        bitmap.onError = onVLCError;

        if(repeat) {
            bitmap.repeat = -1;
        }else {
            bitmap.repeat = 0;
        }

        /**precaution*/
        bitmap.fullscreen = this.isFullscreen;
        bitmap.inWindow = this.inWindow;

        FlxG.game.addChildAt(bitmap, 0);
        bitmap.play(checkFile(path));
        #end

        #if web
        var player:Video = new Video();
		player.x = 0;
		player.y = 0;
		FlxG.game.addChildAt(player, 0);

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
				if(FlxG.game.contains(player)) {
                    FlxG.game.removeChild(player);
                }

				FlxG.switchState(state);
			}
		});
		netStream.play(name);
        #end
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        #if desktop
        //Just incase
        if(bitmap != null) {
            if(controls.ACCEPT) {
                if (bitmap.isPlaying) {
                    FlxG.switchState(state);
                }
            }

            if (FlxG.sound.volume < 0.1) {
                bitmap.volume = 0;
            }else {
                bitmap.volume = FlxG.sound.volume + 0.3;
            }
        }
        #end
    }

    override function finishedTransition() {
        #if desktop
        onVLCComplete();
        #end

        super.finishedTransition();
    }

    function finishedVideo() {
        FlxG.switchState(state);
    }

    #if desktop
    function onVLCComplete() {
        bitmap.stop();
        bitmap.dispose();

        if (FlxG.game.contains(bitmap)) {
            FlxG.game.removeChild(bitmap);
        }

        bitmap = null;

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