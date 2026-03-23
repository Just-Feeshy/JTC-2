package feshixl.shaders;

import lime.utils.Float32Array;
import openfl.display.BitmapData;
import openfl.display.ShaderInput;
import openfl.display.ShaderParameter;
import openfl.display.ShaderParameterType;
import openfl.filters.BitmapFilterShader;

@:access(openfl.display.Shader)
@:access(openfl.display.ShaderInput)
@:access(openfl.display.ShaderParameter)
class FeshFilterShader extends BitmapFilterShader {
    static final DEFAULT_FRAGMENT_SOURCE = "#pragma header\n\nvoid main(void)\n{\n\t#pragma body\n}\n";
    static final RUNTIME_FRAGMENT_HEADER = "varying vec2 openfl_TextureCoordv;\n\n"
        + "uniform sampler2D openfl_Texture;\n"
        + "uniform vec2 openfl_TextureSize;";
    static final RUNTIME_FRAGMENT_BODY = "gl_FragColor = texture2D(openfl_Texture, openfl_TextureCoordv);";

    public function new(?glFragmentSource:String, ?glVertexSource:String) {
        super();

        this.glFragmentSource = glFragmentSource;

        if(glVertexSource != null && glVertexSource != "") {
            this.glVertexSource = glVertexSource;
        }

        __isGenerated = true;
        __initGL();
    }

    public function processShader(glFragmentSource:String = null, glVertexSource:String = null):Void {
        this.glFragmentSource = glFragmentSource;

        if(glVertexSource != null && glVertexSource != "") {
            this.glVertexSource = glVertexSource;
        }

        __initGL();
    }

    override function set_glFragmentSource(value:String):String {
        if (value == null || value == "") {
            value = DEFAULT_FRAGMENT_SOURCE;
        }

        value = StringTools.replace(value, "#pragma header", RUNTIME_FRAGMENT_HEADER);
        value = StringTools.replace(value, "#pragma body", RUNTIME_FRAGMENT_BODY);
        return super.set_glFragmentSource(value);
    }

    override function __processGLData(source:String, storageType:String):Void {
        var lastMatch = 0;
        var position;
        var regex = (storageType == "uniform") ? ~/uniform ([A-Za-z0-9]+) ([A-Za-z0-9_]+)/ : ~/attribute ([A-Za-z0-9]+) ([A-Za-z0-9_]+)/;

        @:privateAccess while (regex.matchSub(source, lastMatch)) {
            var type = regex.matched(1);
            var name = regex.matched(2);

            if (StringTools.startsWith(name, "gl_")) {
                continue;
            }

            var isUniform = (storageType == "uniform");

            if (StringTools.startsWith(type, "sampler")) {
                var input = new ShaderInput<BitmapData>();
                input.name = name;
                input.__isUniform = isUniform;
                __inputBitmapData.push(input);

                switch (name) {
                    case "openfl_Texture":
                        __texture = input;
                    default:
                }

                Reflect.setField(__data, name, input);
            } else if (!Reflect.hasField(__data, name) || Reflect.field(__data, name) == null) {
                var parameterType:ShaderParameterType = switch (type) {
                    case "bool": BOOL;
                    case "double", "float": FLOAT;
                    case "int", "uint": INT;
                    case "bvec2": BOOL2;
                    case "bvec3": BOOL3;
                    case "bvec4": BOOL4;
                    case "ivec2", "uvec2": INT2;
                    case "ivec3", "uvec3": INT3;
                    case "ivec4", "uvec4": INT4;
                    case "vec2", "dvec2": FLOAT2;
                    case "vec3", "dvec3": FLOAT3;
                    case "vec4", "dvec4": FLOAT4;
                    case "mat2", "mat2x2": MATRIX2X2;
                    case "mat2x3": MATRIX2X3;
                    case "mat2x4": MATRIX2X4;
                    case "mat3x2": MATRIX3X2;
                    case "mat3", "mat3x3": MATRIX3X3;
                    case "mat3x4": MATRIX3X4;
                    case "mat4x2": MATRIX4X2;
                    case "mat4x3": MATRIX4X3;
                    case "mat4", "mat4x4": MATRIX4X4;
                    default: null;
                }

                var length = switch (parameterType) {
                    case BOOL2, INT2, FLOAT2: 2;
                    case BOOL3, INT3, FLOAT3: 3;
                    case BOOL4, INT4, FLOAT4, MATRIX2X2: 4;
                    case MATRIX3X3: 9;
                    case MATRIX4X4: 16;
                    default: 1;
                }

                var arrayLength = switch (parameterType) {
                    case MATRIX2X2: 2;
                    case MATRIX3X3: 3;
                    case MATRIX4X4: 4;
                    default: 1;
                }

                switch (parameterType) {
                    case BOOL, BOOL2, BOOL3, BOOL4:
                        var parameter = new ShaderParameter<Bool>();
                        parameter.name = name;
                        Reflect.setField(parameter, "type", parameterType);
                        parameter.__arrayLength = arrayLength;
                        parameter.__isBool = true;
                        parameter.__isUniform = isUniform;
                        parameter.__length = length;
                        __paramBool.push(parameter);

                        if (name == "openfl_HasColorTransform") {
                            __hasColorTransform = parameter;
                        }

                        Reflect.setField(__data, name, parameter);

                    case INT, INT2, INT3, INT4:
                        var parameter = new ShaderParameter<Int>();
                        parameter.name = name;
                        Reflect.setField(parameter, "type", parameterType);
                        parameter.__arrayLength = arrayLength;
                        parameter.__isInt = true;
                        parameter.__isUniform = isUniform;
                        parameter.__length = length;
                        __paramInt.push(parameter);
                        Reflect.setField(__data, name, parameter);

                    default:
                        var parameter = new ShaderParameter<Float>();
                        parameter.name = name;
                        Reflect.setField(parameter, "type", parameterType);
                        parameter.__arrayLength = arrayLength;

                        if (arrayLength > 0) {
                            parameter.__uniformMatrix = new Float32Array(arrayLength * arrayLength);
                        }

                        parameter.__isFloat = true;
                        parameter.__isUniform = isUniform;
                        parameter.__length = length;
                        __paramFloat.push(parameter);

                        if (StringTools.startsWith(name, "openfl_")) {
                            switch (name) {
                                case "openfl_TextureSize":
                                    __textureSize = parameter;
                                default:
                            }
                        }

                        Reflect.setField(__data, name, parameter);
                }
            }

            position = regex.matchedPos();
            lastMatch = position.pos + position.len;
        }
    }
}
