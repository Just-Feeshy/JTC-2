package;

import WiggleEffect.WiggleEffectType;
import flixel.FlxCamera;
import flixel.FlxG;
import openfl.filters.ShaderFilter;
import openfl.filters.BitmapFilter;
import flash.filters.BlurFilter;
import betterShit.BetterCams;

class CameraNote extends BetterCams {
    public var camNoteWOBBLE:FlxCamera;

    //Personal Effects, use them as how u please :3
    private var noteWiggleFLAG:WiggleEffect = new WiggleEffect();

    public function createNoteCam(note:String) {

        switch(note) {
            default:
                if(camNoteWOBBLE != null)
                    return;

                camNoteWOBBLE = new FlxCamera();
                camNoteWOBBLE.bgColor.alpha = 0;
                camNoteWOBBLE.setFilters([new ShaderFilter(noteWiggleFLAG.shader)]);
                FlxG.cameras.add(camNoteWOBBLE);

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
            noteWiggleFLAG.waveAmplitude = 0.02;
            //noteWiggleFLAG.waveAmplitude = Math.sin((camSway*(Conductor.bpm/120)) * Math.PI * Note.AFFECTED_SCROLLSPEED)/40;

            camNoteWOBBLE.x = x;
            camNoteWOBBLE.y = y;
            camNoteWOBBLE.zoom = zoom;
            camNoteWOBBLE.angle = angle;
        }
    }

    override function destroy() {
        if(camNoteWOBBLE != null)
            camNoteWOBBLE.destroy();
    }
}