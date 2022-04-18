package;

import flixel.FlxG;
import flixel.FlxBasic;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

class StageBuilder extends FlxBasic {
    private var sprites:Map<String, FlxBasic>;
    private var song:String;

    public function new(song:String) {
        super();

        sprites = new Map<String, FlxBasic>();

        this.song = song;
    }

    public function addToStage(name:String, thing:FlxBasic) {
        sprites.set(name, thing);

        if(isOfType(thing, PlayState))
            FlxG.state.add(thing);
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
    }
}