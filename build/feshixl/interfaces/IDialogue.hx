package feshixl.interfaces;

import flixel.FlxCamera;
import flixel.FlxState;

import openfl.utils.ByteArray;

import ModInitialize;

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
    var animations:Array<AnimationInfo>;

    var assetID:Int;
    var size:Float;

    var x:Float;
    var y:Float;
}

typedef DialogueData = {
    var speed:Float;

    var protagonistTalking:Bool;
    var soundTalking:ByteArray;

    var text:Array<String>;

    var leftPortrait:DialogueSpriteData;
    var rightPortrait:DialogueSpriteData;
    var speechBubble:DialogueSpriteData;
}

/**
* Main export/import data.
*/
typedef DialogueInfo = {
    var info:Array<DialogueData>;
    var totalSprites:Array<DialogueFileData>;
}