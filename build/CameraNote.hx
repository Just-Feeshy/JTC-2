package;

import flixel.FlxG;
import flixel.util.FlxDestroyUtil;
import feshixl.FeshCamera;

class CameraNote extends FeshCamera {
    public var camNoteSustain:FeshCamera;

    public function createSustainCam() {
        if(camNoteSustain != null)
            return;

        camNoteSustain = new FeshCamera();
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
        FlxG.cameras.remove(camNoteSustain, false);

        camNoteSustain = FlxDestroyUtil.destroy(camNoteSustain);

        super.destroy();
    }
}
