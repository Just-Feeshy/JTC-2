package example_code;

import flixel.FlxCamera;
import flixel.FlxState;

import feshixl.interfaces.IDialogue;

class DefaultDialogueBox extends MusicBeatSubstate implements IDialogue {
    public var finishCallback:(dialogue:IDialogue)->Void;

    public function new() {
        super();
    }

    public function createDialogue(state:FlxState):Void {

    }

    public function attachToCamera(camera:FlxCamera):Void {

    }

    public function destroyDialogue():Void {

    }
}