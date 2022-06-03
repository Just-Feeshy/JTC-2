package template;

import flixel.FlxG;
import flixel.FlxSubState;
import flixel.util.FlxDestroyUtil;
import flixel.FlxCamera;

@:enum
abstract TransitionFade(String) {
    var IN = "in";
    var OUT = "out";
    var NONE = "none";
}

class TransitionBuilder extends FlxSubState {
    /**
    * What happens after the transition.
    */
    public var finishCallback:Void->Void;

    var fade:TransitionFade;

    /**
    * No BetterCams WAAAAAA!
    */
    var transCamera:FlxCamera;

    public function new(duration:Float, fade:TransitionFade) {
        super();

        this.fade = fade;

        transCamera = new FlxCamera();
        transCamera.bgColor.alpha = 0;
        FlxG.cameras.add(transCamera, false);

        this.cameras = [transCamera];

    }

    override function destroy() {
        this.cameras = [];

        FlxG.cameras.remove(transCamera);

        transCamera = FlxDestroyUtil.destroy(transCamera);

        if(finishCallback != null) {
            finishCallback();
            finishCallback = null;
        }

        super.destroy();
    }
}