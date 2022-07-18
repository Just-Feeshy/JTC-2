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
    private var stage:String;
    private var directory(default, set):String;

    public function new(stage:String) {
        super();

        sprites = new Map<String, FlxBasic>();

        this.stage = stage;
    }

    public function addToStageAndMap(name:String, thing:FlxBasic):Void {
        sprites.set(name, thing);

        if(isOfType(FlxG.state, PlayState))
            FlxG.state.add(thing);
    }

    public function addToStage(thing:FlxBasic):Void {
        if(isOfType(FlxG.state, PlayState))
            FlxG.state.add(thing);
    }

    public function removeFromStage(thing:FlxBasic):Void {
        if(isOfType(FlxG.state, PlayState))
            FlxG.state.remove(thing);
    }

    public function configStage():Void {
        //empty method
    }

    public function whenCreatingScene():Void {
        //empty method
    }

    public function setDefaultCameraZoom(zoom:Float):Void {
        if(isOfType(FlxG.state, PlayState)) {
            var state:PlayState = cast FlxG.state;

            @:privateAccess
            state.defaultCamZoom = zoom;
        }
    }

    public function setPixel(isA:Bool):Void {
        if(isOfType(FlxG.state, PlayState)) {
            var state:PlayState = cast FlxG.state;

            @:privateAccess
            state.isPixel = isA;
        }
    }

    @:allow(PlayState)
    private function setCamPos(camPos:FlxPoint):FlxPoint {
        return null;
    }

    @:allow(PlayState)
    private function curBeat():Void {
        //Empty
    }

    @:allow(PlayState)
    private function curStep():Void {
        //Empty
    }

    inline function set_directory(value:String) {
        Paths.setCurrentLevel(value);

        directory = value;
        return value;
    }

    override public function destroy():Void {
        if(sprites != null) {
            for(k in sprites.keys()) {
                sprites.get(k).destroy();
            }

            sprites.clear();
        }

        sprites = null;
        stage = null;
        directory = null;
    }
}