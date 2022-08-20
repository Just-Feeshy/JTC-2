package template;

import flixel.FlxG;
import flixel.group.FlxGroup;
import flixel.math.FlxPoint;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

/**
* If you want to include the default game stage
* then extend your stage class off of the `DefaultStage`.
*/
abstract class StageBuilder extends FlxGroup {
    private var stage:String;
    private var directory(default, set):String;

    private var playstate(get, never):PlayState;

    public function new(stage:String) {
        this.stage = stage;

        super();
    }

    public function configStage():Void {
        //empty method
    }

    public function whenCreatingScene():Void {
        //empty method
    }

    public function setDefaultCameraZoom(zoom:Float):Void {
        if(isOfType(FlxG.state, PlayState)) {
            @:privateAccess playstate.defaultCamZoom = zoom;
        }
    }

    public function setPixel(isA:Bool):Void {
        if(isOfType(FlxG.state, PlayState)) {
            @:privateAccess playstate.isPixel = isA;
        }
    }

    public function modifyNotesDirectly(note:Note) {
        //empty
    }

    public function setCamPos(camPos:FlxPoint):FlxPoint {
        return null;
    }

    public function hasGirlfriend():Bool {
        return true;
    }

    @:allow(PlayState)
    private function curBeat():Void {
        //Empty
    }

    @:allow(PlayState)
    private function curStep():Void {
        //Empty
    }

    inline function set_directory(value:String):String {
        Paths.setCurrentLevel(value);

        directory = value;
        return value;
    }

    inline function get_playstate():PlayState {
        return cast(FlxG.state, PlayState);
    }

    override public function destroy():Void {
        stage = null;
        directory = null;
    }
}