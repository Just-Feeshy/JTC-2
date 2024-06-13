package;

import flixel.FlxG;
import flixel.text.FlxText;
import flixel.addons.transition.Transition;
import flixel.input.gamepad.FlxGamepadInputID;
import flixel.input.keyboard.FlxKey;
import flixel.util.FlxColor;
import flixel.FlxState;

#if web
import openfl.net.NetConnection;
import openfl.net.NetStream;
import openfl.events.NetStatusEvent;
import openfl.media.Video;
#end

#if cpp
import hxvlc.externs.Types;
import hxvlc.openfl.Video;
import sys.FileSystem;
#end

import SaveData.SaveType;

@:access(hxvlc.openfl.Video)
class VideoState extends HelperStates {
    public var isFullscreen:Bool = false;
    public var inWindow:Bool = false;

    var SPACE:FlxText;

    var state:FlxState;
    var path:String;

    var skip:Bool = false;

    #if cpp
	var bitmap:Video;
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

        if (FlxG.sound.music != null) {
            FlxG.sound.music.stop();
        }

        FlxG.camera.bgColor.alpha = 0;

        playVideo();

        var keytoSkip:String;

        if(FlxG.gamepads.lastActive != null) {
            keytoSkip = "A";
        }else {
            keytoSkip = FlxKey.toStringMap.get(SaveData.getData(CUSTOM_UI_KEYBINDS)[4][0]).toUpperCase();
        }

        SPACE = new FlxText(20, 20, "Press " + keytoSkip + " to skip", 16);
        SPACE.setBorderStyle(FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
        SPACE.borderSize = 2;
        add(SPACE);

        super.create();
    }

    public function playVideo() {
        #if cpp
        bitmap = new Video(SaveData.getData(SaveType.GRAPHICS));
/*
        if(FlxG.stage.stageHeight / 9 < FlxG.stage.stageWidth / 16) {
            bitmap.set_width(FlxG.stage.stageHeight * (16 / 9));
            bitmap.set_height(FlxG.stage.stageHeight);
        }else {
            bitmap.set_width(FlxG.stage.stageWidth);
            bitmap.set_height(FlxG.stage.stageWidth / (16 / 9));
        }
*/
        bitmap.onEndReached.add(finishedVideo);
        bitmap.onEncounteredError.add(onVLCError);

        FlxG.game.addChildAt(bitmap, 0);
		bitmap.load(checkFile(path), []);
        bitmap.play();

		bitmap.onOpening.add(function():Void {
		    bitmap.role = LibVLC_Role_Game;

		    if(!FlxG.signals.postUpdate.has(postUpdate)) {
				FlxG.signals.postUpdate.add(postUpdate);
			}
		});
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
		#if cpp
		if(bitmap.isPlaying && controls.ACCEPT) {
		     FlxG.switchState(state);
		}
		#end

        super.update(elapsed);
    }

    override function finishedTransition() {
        SPACE.destroy();
        SPACE = null;

        #if cpp
        onVLCComplete();
        #end

        super.finishedTransition();
    }

    function finishedVideo() {
        FlxG.switchState(state);
    }

    #if cpp
    @:noCompletion function onVLCComplete() {
		bitmap.onEndReached.remove(finishedVideo);
		bitmap.onEncounteredError.remove(onVLCError);

		FlxG.signals.postUpdate.remove(postUpdate);
        FlxG.game.removeChild(bitmap);

        bitmap.stop();
        bitmap.dispose();

        bitmap = null;

        FlxG.switchState(state);
    }

    @:noCompletion function onVLCError(message:String) {
        trace("Error: could not locate video because of [" + message + "]");
        // FlxG.switchState(state);
    }

    @:noCompletion function checkFile(fileName:String):String {
		return FileSystem.absolutePath(Paths.getCoreAssets() + fileName);
	}

	@:noCompletion function postUpdate() {
		{
			bitmap.width = FlxG.scaleMode.gameSize.x;
			bitmap.height = FlxG.scaleMode.gameSize.y;
		}

		#if FLX_SOUND_SYSTEM
		{

			final curVolume:Int = Math.floor((FlxG.sound.muted ? 0 : 1) * FlxG.sound.volume * 300);

			if (bitmap.volume != curVolume)
				bitmap.volume = curVolume;
		}
		#end

	}
    #end
}
