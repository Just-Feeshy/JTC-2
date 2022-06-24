package feshixl.shaders;

import flixel.system.FlxAssets.FlxShader;
import openfl.display.BitmapData;
import lime.utils.Assets;

class ShaderHandler extends FlxShader {
    var bitmapData:BitmapData;

    @:glFragmentSource('
        #pragma header

        uniform sampler2D t0;
        uniform bool useExternalBit;

        vec4 color(vec2 pt) {
            if(useExternalBit == true)
                return texture2D(bit, pt);
            else
                return texture2D(bitmap, pt);
        }\n\n
    ')
    public function new() {
        super();
    }

    public function implementFragmentShader(path:String) {
        glFragmentSource += Assets.getText(path);
    }

    public function attachBitmapData(bitmapData:BitmapData):Void {
        this.bitmapData = bitmapData;

        if(bitmapData != null) {
            useExternalBit.value = [true];
            t0.input = this.bitmapData;
        }else {
            useExternalBit.value = [false];
        }
    }
}