package;

import flixel.FlxG;
import flixel.FlxState;
import flixel.input.keyboard.FlxKey;

import openfl.Lib;
import openfl.display.FPS;
import openfl.filters.ShaderFilter;
import openfl.events.KeyboardEvent;
import openfl.events.UncaughtErrorEvent;
import openfl.errors.Error;

import haxe.CallStack;
import lime.ui.Window;
import haxe.Json;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

#if sys
import sys.FileSystem;
import sys.io.File;
#end

import Discord.DiscordClient;
import SaveData.SaveType;

using StringTools;

class Preloader extends FlxState {
    override function create():Void {
        SaveData.globalFPS = new FPS(10, 3, 0xFFFFFF);
        SaveData.globalMEM = new Memory(10, 18, 0xFFFFFF);

        var fpsMulti:Int = SaveData.getData(SaveType.FPS_MULTIPLIER);

        if(File.getContent(Paths.mora("shaders", "json")).length < 11)
            File.saveContent(Paths.mora("shaders", "json"), Json.stringify([0,0,0,0,0]));

        FlxG.mouse.visible = false;

        if(fpsMulti < 1)
            fpsMulti = 1;

        SaveData.saveClient();
        Highscore.load();

        Main.trueFramerate = FlxG.save.data.lowFps;
        Lib.current.stage.frameRate = Main.trueFramerate * fpsMulti;

        var gammaShaders = new BuiltInShaders();
        gammaShaders.shader = GAMMA;
        gammaShaders.position = SaveData.getData(SaveType.GAMMA);

        FlxG.game.setFilters([new ShaderFilter(gammaShaders)]);

        trace("FPS: " + Lib.current.stage.frameRate);

        //FlxG.autoPause = false;
        
        //Initalize events
        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, saveVolumeChanges);
        Lib.current.loaderInfo.uncaughtErrorEvents.addEventListener(UncaughtErrorEvent.UNCAUGHT_ERROR, createLogReport);

        FlxG.sound.volume = FlxG.save.data.volume;

        super.create();

        Register.setup();

        FlxG.switchState(new TitleState());

        Register.compile();
    }

    /**
    * Don't you just hate when Friday Night Funkin' blast your ears evertime.
    */
    static function saveVolumeChanges(event:KeyboardEvent):Void {
        var key:FlxKey = event.keyCode;

        if(key == FlxKey.PLUS && FlxG.save.data.volume < 1) {
            FlxG.save.data.volume += 0.1;
            FlxG.save.flush();
        }

        if(key == FlxKey.MINUS && FlxG.save.data.volume > 0) {
            FlxG.save.data.volume -= 0.1;
            FlxG.save.flush();
        }
    }

    static function createLogReport(event:UncaughtErrorEvent):Void {
        var error:Error = null;

        if(event.error != null && isOfType(event.error, String)) {
            error = new Error(cast event.error);
        }

        #if sys
        if(!FileSystem.exists("./crash-reports")) {
            FileSystem.createDirectory("./crash-reports");
        }

        final contactInfo:String = "";

        var timeStap:String = Date.now().toString();

		timeStap = timeStap.replace(" ", "_");
		timeStap = timeStap.replace(":", ".");

        var modName:String = Paths.modJSON.mod.name.replace(" ", "-");

        try {
            File.saveContent("./crash-reports/" + modName + "_" + timeStap + ".txt",
                "Uncaught Error: " + Std.string(event.error) + "\n\n" + error.getStackTrace() + "\n\n" + contactInfo
            );

        var callStack:Array<StackItem> = CallStack.exceptionStack(true);

        var errMsg:String = "";

        for (stackItem in callStack) {
            switch (stackItem) {
                case FilePos(s, file, line, column):
                    errMsg += "Called from " + file + " (line " + line + ")\n";
                default:
                    Sys.println(stackItem);
            }
        }

        FlxG.sound.music.stop();
        DiscordClient.shutdown();

        FlxG.sound.muted = true;

        var prevWindow:Window = Lib.current.stage.window;
        new CrashLogDisplay(prevWindow).attachReport([errMsg, "Uncaught Error: " + Std.string(event.error)]);
        #end
        }catch(e:haxe.Exception) {
            trace(event.error);
        }
    }

    override function update(elapsed:Float):Void {
        super.update(elapsed / 2);
    }
}