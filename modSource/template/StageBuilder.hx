package template;

import flixel.FlxG;
import flixel.FlxBasic;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

abstract class StageBuilder extends FlxBasic {
    private var sprites:Map<String, FlxBasic>;
    private var song:String;
    private var directory:String;

    public function new(song:String) {
        super();

        sprites = new Map<String, FlxBasic>();

        this.song = song;
    }

    public function addToStageAndMap(name:String, thing:FlxBasic) {
        sprites.set(name, thing);

        if(isOfType(FlxG.state, PlayState))
            FlxG.state.add(thing);
    }

    public function addToStage(thing:FlxBasic) {
        if(isOfType(FlxG.state, PlayState))
            FlxG.state.add(thing);
    }

    public function whenCreatingScene() {
        //empty method
    }

    public function setDefaultCameraZoom(zoom:Float) {
        if(isOfType(FlxG.state, PlayState)) {
            var state:PlayState = cast FlxG.state;

            @:privateAccess
            state.defaultCamZoom = zoom;
        }
    }

    public function setPixel(is:Bool) {
        if(isOfType(FlxG.state, PlayState)) {
            var state:PlayState = cast FlxG.state;

            @:privateAccess
            state.isPixel = is;
        }
    }

    override public function destroy() {
        if(sprites != null) {
            for(k in sprites.keys()) {
                sprites.get(k).destroy();
            }

            sprites.clear();
        }

        sprites = null;
        song = null;
        directory = null;
    }
}