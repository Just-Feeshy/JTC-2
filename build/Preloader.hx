package;

import flixel.FlxG;
import flixel.FlxState;
import sys.io.File;
import openfl.Lib;
import openfl.display.FPS;
import haxe.Json;

import SaveData.SaveType;

using StringTools;

class Preloader extends FlxState {
    override public function create() {
        var fpsMulti:Int = SaveData.getData(SaveType.FPS_MULTIPLIER);

        /**
        if(true) {
            FlxG.switchState(new CrashDumper());
            return;
        }
        **/

        #if !mobile
		Lib.current.addChild(new FPS(10, 3, 0xFFFFFF));
		#end

        if(File.getContent(Paths.mora("shaders", "json")).length < 11)
            File.saveContent(Paths.mora("shaders", "json"), Json.stringify([0,0,0,0,0]));

        FlxG.mouse.visible = false;

        if(fpsMulti < 1)
            fpsMulti = 1;

        Main.trueFramerate = FlxG.save.data.lowFps;
        Lib.current.stage.frameRate = Main.trueFramerate * fpsMulti;

        trace("FPS: " + Lib.current.stage.frameRate);

        FlxG.autoPause = false;

        super.create();

        Register.setup();

        FlxG.switchState(new TitleState());

        //trace();
        Register.compile();
    }

    override function update(elapsed:Float) {
        super.update(elapsed / 2);
    }
}