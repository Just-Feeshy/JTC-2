package feshixl.interfaces;

import flixel.FlxCamera;
import flixel.FlxState;

import openfl.utils.ByteArray;
import openfl.display.BitmapData;

interface IDialogue {
    var finishCallback:(dialogue:IDialogue)->Void;

    function createDialogue(state:FlxState):Void;
    function attachToCamera(camera:FlxCamera):Void;
    function destroyDialogue():Void;
}

typedef DialogueFileData = {
    var spriteData:BitmapData;
    var xmlData:String;
}

typedef DialogueData = {
    var leftPortrait:DialogueFileData;
    var rightPortait:DialogueFileData;
}