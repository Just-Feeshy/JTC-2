package feshixl.interfaces;

import flixel.FlxCamera;
import flixel.FlxState;

interface IDialogue {
    var finishCallback:(dialogue:IDialogue)->Void;

    function createDialogue(state:FlxState):Void;
    function attachToCamera(camera:FlxCamera):Void;
    function destroyDialogue():Void;
}