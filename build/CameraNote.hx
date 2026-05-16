package;

import flixel.FlxG;
import flixel.util.FlxDestroyUtil;
import play.PlayCamera;

class CameraNote extends PlayCamera {
    public var camNoteSustain:PlayCamera;
    public var camNoteSplash:PlayCamera;

    public function createSustainCam() {
        if(camNoteSustain != null)
            return;

        camNoteSustain = new PlayCamera();
        camNoteSustain.bgColor.alpha = 0;
    }

    public function createSplashCam() {
        if(camNoteSplash != null)
            return;

        camNoteSplash = new PlayCamera();
        camNoteSplash.bgColor.alpha = 0;
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        if(camNoteSustain != null) {
            camNoteSustain.x = x;
            camNoteSustain.y = y;
            camNoteSustain.zoom = zoom;
            camNoteSustain.angle = angle;
            camNoteSustain.visible = visible;
        }

        if(camNoteSplash != null) {
            camNoteSplash.x = x;
            camNoteSplash.y = y;
            camNoteSplash.zoom = zoom;
            camNoteSplash.angle = angle;
            camNoteSplash.visible = visible;
        }
    }

    override function destroy() {
        if(camNoteSustain != null) {
            FlxG.cameras.remove(camNoteSustain, false);
            camNoteSustain = FlxDestroyUtil.destroy(camNoteSustain);
        }

        if(camNoteSplash != null) {
            FlxG.cameras.remove(camNoteSplash, false);
            camNoteSplash = FlxDestroyUtil.destroy(camNoteSplash);
        }

        super.destroy();
    }
}
