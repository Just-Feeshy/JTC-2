package;

import flixel.FlxG;
import flixel.util.FlxDestroyUtil;
import play.PlayCamera;

class CameraNote extends PlayCamera {
    public var camNoteSustain:PlayCamera;

    public function createSustainCam() {
        if(camNoteSustain != null)
            return;

        camNoteSustain = new PlayCamera();
        camNoteSustain.bgColor.alpha = 0;
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
    }

    override function destroy() {
        if(camNoteSustain != null) {
            FlxG.cameras.remove(camNoteSustain, false);
            camNoteSustain = FlxDestroyUtil.destroy(camNoteSustain);
        }

        super.destroy();
    }
}
