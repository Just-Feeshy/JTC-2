package;

import flixel.system.FlxAssets.FlxShader;
import openfl.display.BitmapData;

enum ShaderType {
    MINING_SIM_LOADING;
    GLIM_SELECTION;
    GAUSSIAN_BLUR;
}

class BuiltInShaders extends FlxShader {
    public var shader(default, set):ShaderType;
    public var position(default, set):Float;

    @:glFragmentSource('
        #pragma header

        uniform sampler2D bit;
        uniform float shaderValue;
        uniform bool useExternalBit;
        uniform int shad;

        const int MINING_SIM_LOADING = 0;
        const int GLIM_SELECTION = 1;

        mat2 setAngle(float rotation) {
            return mat2(cos(rotation), -sin(rotation), sin(rotation), cos(rotation));
        }

        float drawRect(vec2 pixelCoord, vec2 width) {
            vec2 bL = step(width, pixelCoord);
            vec2 tR = step(width, 1.0 - pixelCoord);

            return (bL.x * bL.y) * (tR.x * tR.y);
        }

        vec4 color() {
            if(useExternalBit == true)
                return flixel_texture2D(bit, openfl_TextureCoordv);
            else
                return flixel_texture2D(bitmap, openfl_TextureCoordv);
        }

        void robloxIntro() {
            gl_FragColor = vec4((vec3(color().r+color().g+color().b)/3.0) * (1 - shaderValue) + color().rgb * shaderValue, color().a);
        }

        void objSelect() {
            const float PI = 3.14159265358979323846;

            vec2 pixelCoord = openfl_TextureCoordv;

            pixelCoord -= vec2(sin(shaderValue * 3.0) / 2.0) + 0.5;
            pixelCoord = setAngle(PI / 4.0) * pixelCoord;
            pixelCoord += vec2(0.5);

            float box = drawRect(pixelCoord, vec2(0.45, -0.45));

            if(color().a != 0.0) {
                if(box == 0.0) {
                    gl_FragColor = color();
                } else {
                    gl_FragColor = vec4(vec3(1.0), color().a);
                }
            }
        }

        void main() {
            if(shad == MINING_SIM_LOADING)
                robloxIntro();
            else if(shad == GLIM_SELECTION)
                objSelect();
        }
    ')
    public function new(?spriteBit:BitmapData):Void {
        super();

        if(spriteBit != null) {
            useExternalBit.value = [true];
            bit.input = spriteBit;
        }else {
            useExternalBit.value = [false];
        }

        shaderValue.value = [0];
    }

    function set_shader(v:ShaderType):ShaderType {
        shader = v;
        shad.value = [ShaderType.getConstructors().indexOf(Std.string(v))];
        return v;
    }

    function set_position(v:Float):Float {
        position = v;
        shaderValue.value = [position];
        return v;
    }

    public function updateBitmap(v:BitmapData):BitmapData {
        bit.input = v;
        return v;
    }
}