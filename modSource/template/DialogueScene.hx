package template;

import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.FlxCamera;
import flixel.FlxState;

import feshixl.filters.GuassianBlur;
import feshixl.interfaces.IDialogue;
import openfl.filters.ShaderFilter;

class DialogueScene extends MusicBeatSubstate implements IDialogue {
    public var finishCallback:(dialogue:IDialogue)->Void;

    var blurEffect:GuassianBlur;

    public function new() {
        super();
    }

    function createAfterTransition():Void {

    }

    public function createDialogue(state:FlxState):Void {
        var playState:PlayState = cast(state, PlayState);

        blurEffect = new GuassianBlur(0);

        @:privateAccess
        playState.camGame.wastefulFilters.push(new ShaderFilter(blurEffect));

        FlxTween.tween(blurEffect, {size: 20}, 0.75, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
            playState.openSubState(this);
            createAfterTransition();
        }});
    }

    public function attachToCamera(camera:FlxCamera):Void {

    }

    public function destroyDialogue():Void {

    }

    override function destroy():Void {
        super.destroy();
    }
}