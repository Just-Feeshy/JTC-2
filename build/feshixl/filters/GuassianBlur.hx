package feshixl.filters;

import flixel.system.FlxAssets.FlxShader;
import openfl.display.BitmapData;
import flixel.FlxG;

class GuassianBlur extends FlxShader {
    public var size(get, set):Float;

    @:glFragmentSource('
        #pragma header

        uniform sampler2D bit;
        uniform float _size;

        uniform bool useExternalBit;

        const float directions = 16.0;
        const float quality = 4.0;

        const float PI = 3.14159265358979323846;

        vec4 color(vec2 pt) {
            if(useExternalBit == true)
                return texture2D(bit, pt);
            else
                return texture2D(bitmap, pt);
        }

        void main() {
            vec4 Color = color(openfl_TextureCoordv);

            for(float d = 0.0; d < PI * 2.0; d += (PI * 2.0)/directions) {
                for(float i = 1.0 / quality; i <= 1.0; i += 1.0/quality) {
                    Color += color(openfl_TextureCoordv + vec2(cos(d), sin(d)) * (_size / 1280.0) * i);
                }
            }

            Color /= quality * directions;
            gl_FragColor = Color;
        }
    ')
    public function new(sizeValue:Float = 8, ?spriteBit:BitmapData):Void {
        super();

        if(spriteBit != null) {
            useExternalBit.value = [true];
            bit.input = spriteBit;
        }else {
            useExternalBit.value = [false];
        }

        _size.value = [sizeValue];
    }

    public function setSpriteBitmap(spriteBit:BitmapData):Void {
        if(spriteBit != null) {
            useExternalBit.value = [true];
            bit.input = spriteBit;
        }else {
            useExternalBit.value = [false];
        }
    }

    function set_size(Value:Float):Float {
        _size.value = [Value];
        return Value;
    }

    function get_size():Float {
        return _size.value[0];
    }
}