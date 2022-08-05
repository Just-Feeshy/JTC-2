package template;

import flixel.FlxG;
import flixel.FlxSubState;
import flixel.util.FlxDestroyUtil;
import flixel.FlxCamera;

@:enum
abstract TransitionFade(String) {
    var IN = "in";
    var OUT = "out";
}

/**
* Small, I know.
*/
class TransitionBuilder extends FlxSubState {
    /**
    * What happens after the transition.
    */
    public var finishCallback:Void->Void;

    var fade:TransitionFade;
    var duration:Float;

    /**
    * No BetterCams WAAAAAA!
    */
    var transCamera:FlxCamera;

    public function new(duration:Float, fade:TransitionFade) {
        super();

        this.fade = fade;
        this.duration = duration;

        transCamera = new FlxCamera();
        transCamera.bgColor.alpha = 0;
        FlxG.cameras.add(transCamera, false);

        this.cameras = [transCamera];

    }

    function callback():Void {
        if(finishCallback != null) {
            finishCallback();
            finishCallback = null;
        }
    }

    override function close():Void {
        super.close();

        if(finishCallback != null) {
            finishCallback();
        }
    }

    override function destroy():Void {
        finishCallback = null;

        this.cameras = [];

        FlxG.cameras.remove(transCamera);

        transCamera = FlxDestroyUtil.destroy(transCamera);

        super.destroy();
    }
}