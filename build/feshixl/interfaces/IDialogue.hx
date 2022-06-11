package feshixl.interfaces;

import flixel.FlxCamera;
import flixel.FlxState;

import openfl.utils.ByteArray;

interface IDialogue {
    var finishCallback:(dialogue:IDialogue)->Void;

    function createDialogue(state:FlxState):Void;
    function attachToCamera(camera:FlxCamera):Void;
    function destroyDialogue():Void;
}

typedef DialogueFileData = {
    var name:String;
    var spriteData:ByteArray;
    var xmlData:ByteArray;
}

typedef DialogueSpriteData = {
    var assetID:Int;
    var size:Float;
}

/**
* Should be stored in an array to have more than one line.
*/
typedef DialogueData = {
    var speed:Float;

    var protagonistTalking:Bool;
    var soundTalking:ByteArray;

    var text:Array<Array<String>>;

    var totalSprites:Array<DialogueFileData>;

    var leftPortrait:DialogueSpriteData;
    var rightPortrait:DialogueSpriteData;
    var speechBubble:DialogueSpriteData;
}