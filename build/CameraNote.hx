package;

import flixel.FlxG;
import flixel.util.FlxDestroyUtil;
import openfl.filters.ShaderFilter;
import openfl.filters.BitmapFilter;
import WiggleEffect.WiggleEffectType;
import flash.filters.BlurFilter;
import feshixl.FeshCamera;

class CameraNote extends FeshCamera {
    public var camNoteWOBBLE:FeshCamera;

    public var wobblePower:Float = 30;

    //Personal Effects, use them as how u please :3
    private var noteWiggleFLAG:WiggleEffect = new WiggleEffect();

    public function createNoteCam(note:String) {

        switch(note) {
            default:
                if(camNoteWOBBLE != null)
                    return;

                camNoteWOBBLE = new FeshCamera();
                camNoteWOBBLE.bgColor.alpha = 0;
                camNoteWOBBLE.setFilters([new ShaderFilter(noteWiggleFLAG.shader)]);

                noteWiggleFLAG.effectType = WiggleEffectType.DREAMY;
		        noteWiggleFLAG.waveSpeed = 1;
				noteWiggleFLAG.waveFrequency = Math.PI * 3;
        }

    }

    override function setFilters(filters:Array<BitmapFilter>) {
        if(camNoteWOBBLE != null) {
            var littleShit:Array<BitmapFilter> = filters.concat([]);
            littleShit.push(new ShaderFilter(noteWiggleFLAG.shader));

            camNoteWOBBLE.setFilters(littleShit);
        }

        super.setFilters(filters);
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        if(camNoteWOBBLE != null) {
            noteWiggleFLAG.waveAmplitude = (wobblePower * Math.pow(10, -3)) / 2;

            camNoteWOBBLE.x = x;
            camNoteWOBBLE.y = y;
            camNoteWOBBLE.zoom = zoom;
            camNoteWOBBLE.angle = angle;
        }
    }

    override function destroy() {
        FlxG.cameras.remove(camNoteWOBBLE, false);

        camNoteWOBBLE = FlxDestroyUtil.destroy(camNoteWOBBLE);

        super.destroy();
    }
}