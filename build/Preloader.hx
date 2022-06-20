package;

import flixel.FlxG;
import flixel.FlxState;
import flixel.input.keyboard.FlxKey;
import sys.io.File;
import openfl.Lib;
import openfl.display.FPS;
import openfl.filters.ShaderFilter;
import openfl.events.KeyboardEvent;
import haxe.Json;

import SaveData.SaveType;

using StringTools;

class Preloader extends FlxState {
    override public function create():Void {
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

        SaveData.saveClient();

        Main.trueFramerate = FlxG.save.data.lowFps;
        Lib.current.stage.frameRate = Main.trueFramerate * fpsMulti;

        var gammaShaders = new BuiltInShaders();
        gammaShaders.shader = GAMMA;
        gammaShaders.position = SaveData.getData(SaveType.GAMMA);

        FlxG.game.setFilters([new ShaderFilter(gammaShaders)]);

        trace("FPS: " + Lib.current.stage.frameRate);

        FlxG.autoPause = false;

        FlxG.stage.addEventListener(KeyboardEvent.KEY_DOWN, saveVolumeChanges);

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

    override function update(elapsed:Float):Void {
        super.update(elapsed / 2);
    }
}