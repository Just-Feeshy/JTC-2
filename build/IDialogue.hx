package;

import flixel.FlxState;
import flixel.FlxCamera;
import flixel.util.FlxDestroyUtil.IFlxDestroyable;
import haxe.io.Bytes;

import ModInitialize;

interface IDialogue extends IFlxDestroyable {
    var finishCallback:(dialogue:IDialogue)->Void;

    function createDialogue(state:FlxState):Void;
    function attachToCamera(camera:FlxCamera):Void;
    function destroyDialogue():Void;
}

typedef DialogueFileData = {
    var name:String;
    var spriteData:Bytes;
    var xmlData:Bytes;
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

    var talkingAnimation:String;

    var text:Array<String>;
    var font:String;
    var textColor:Int;
    var textSize:Int;
    var soundIndex:Int;

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
    var totalSounds:Array<Bytes>;
}