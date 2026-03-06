package feshixl.shaders;

import lime.utils.Float32Array;
import openfl.display.BitmapData;
import openfl.display.ShaderInput;
import openfl.display.ShaderParameter;
import openfl.display.ShaderParameterType;

class FeshShader extends FeshBackendShader {
    static final DEFAULT_FRAGMENT_SOURCE = "#pragma header\n\nvoid main(void)\n{\n\t#pragma body\n}\n";
    static final DEFAULT_VERTEX_SOURCE = "#pragma header\n\nvoid main(void)\n{\n\t#pragma body\n}\n";

    static final RUNTIME_VERTEX_HEADER = "attribute float openfl_Alpha;\n"
        + "attribute vec4 openfl_ColorMultiplier;\n"
        + "attribute vec4 openfl_ColorOffset;\n"
        + "attribute vec4 openfl_Position;\n"
        + "attribute vec2 openfl_TextureCoord;\n"
        + "attribute float alpha;\n"
        + "attribute vec4 colorMultiplier;\n"
        + "attribute vec4 colorOffset;\n\n"
        + "varying float openfl_Alphav;\n"
        + "varying vec4 openfl_ColorMultiplierv;\n"
        + "varying vec4 openfl_ColorOffsetv;\n"
        + "varying vec2 openfl_TextureCoordv;\n\n"
        + "uniform mat4 openfl_Matrix;\n"
        + "uniform bool openfl_HasColorTransform;\n"
        + "uniform bool hasColorTransform;\n"
        + "uniform vec2 openfl_TextureSize;";

    static final RUNTIME_VERTEX_BODY = "openfl_Alphav = openfl_Alpha;\n"
        + "openfl_TextureCoordv = openfl_TextureCoord;\n\n"
        + "if (openfl_HasColorTransform)\n{\n"
        + "\topenfl_ColorMultiplierv = openfl_ColorMultiplier;\n"
        + "\topenfl_ColorOffsetv = openfl_ColorOffset / 255.0;\n"
        + "}\n\n"
        + "gl_Position = openfl_Matrix * openfl_Position;\n\n"
        + "openfl_Alphav = openfl_Alpha * alpha;\n\n"
        + "if (hasColorTransform)\n{\n"
        + "\topenfl_ColorOffsetv = colorOffset / 255.0;\n"
        + "\topenfl_ColorMultiplierv = colorMultiplier;\n"
        + "}";

    static final RUNTIME_FRAGMENT_HEADER = "varying float openfl_Alphav;\n"
        + "varying vec4 openfl_ColorMultiplierv;\n"
        + "varying vec4 openfl_ColorOffsetv;\n"
        + "varying vec2 openfl_TextureCoordv;\n\n"
        + "uniform bool openfl_HasColorTransform;\n"
        + "uniform vec2 openfl_TextureSize;\n"
        + "uniform sampler2D bitmap;\n"
        + "uniform bool hasTransform;\n"
        + "uniform bool hasColorTransform;\n\n"
        + "vec4 flixel_texture2D(sampler2D bitmap, vec2 coord)\n"
        + "{\n"
        + "\tvec4 color = texture2D(bitmap, coord);\n"
        + "\tif (!hasTransform)\n\t{\n"
        + "\t\treturn color;\n"
        + "\t}\n\n"
        + "\tif (color.a == 0.0)\n\t{\n"
        + "\t\treturn vec4(0.0, 0.0, 0.0, 0.0);\n"
        + "\t}\n\n"
        + "\tif (!hasColorTransform)\n\t{\n"
        + "\t\treturn color * openfl_Alphav;\n"
        + "\t}\n\n"
        + "\tcolor = vec4(color.rgb / color.a, color.a);\n\n"
        + "\tmat4 colorMultiplier = mat4(0);\n"
        + "\tcolorMultiplier[0][0] = openfl_ColorMultiplierv.x;\n"
        + "\tcolorMultiplier[1][1] = openfl_ColorMultiplierv.y;\n"
        + "\tcolorMultiplier[2][2] = openfl_ColorMultiplierv.z;\n"
        + "\tcolorMultiplier[3][3] = openfl_ColorMultiplierv.w;\n\n"
        + "\tcolor = clamp(openfl_ColorOffsetv + (color * colorMultiplier), 0.0, 1.0);\n\n"
        + "\tif (color.a > 0.0)\n\t{\n"
        + "\t\treturn vec4(color.rgb * color.a * openfl_Alphav, color.a * openfl_Alphav);\n"
        + "\t}\n"
        + "\treturn vec4(0.0, 0.0, 0.0, 0.0);\n"
        + "}";

    static final RUNTIME_FRAGMENT_BODY = "gl_FragColor = flixel_texture2D(bitmap, openfl_TextureCoordv);";

    public function new(?glFragmentSource:String, ?glVertexSource:String) {
        if (glFragmentSource != null) {
            this.glFragmentSource = glFragmentSource;
        }

        if (glVertexSource != null) {
            this.glVertexSource = glVertexSource;
        }

        super();
        __isGenerated = true;
        __initGL();
    }

    public function processShader(glFragmentSource:String = null, glVertexSource:String = null):Void {
        if (glFragmentSource != null) {
            this.glFragmentSource = glFragmentSource;
        }

        if (glVertexSource != null) {
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

    override function set_glVertexSource(value:String):String {
        if (value == null || value == "") {
            value = DEFAULT_VERTEX_SOURCE;
        }

        value = StringTools.replace(value, "#pragma header", RUNTIME_VERTEX_HEADER);
        value = StringTools.replace(value, "#pragma body", RUNTIME_VERTEX_BODY);
        return super.set_glVertexSource(value);
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
                    case "bitmap":
                        __bitmap = input;
                    default:
                }

                Reflect.setField(__data, name, input);
                if (__isGenerated) {
                    bindKnownField(name, input);
                }
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
                        if (__isGenerated) {
                            bindKnownField(name, parameter);
                        }

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
                        if (__isGenerated) {
                            bindKnownField(name, parameter);
                        }

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
                                case "openfl_Alpha":
                                    __alpha = parameter;
                                case "openfl_ColorMultiplier":
                                    __colorMultiplier = parameter;
                                case "openfl_ColorOffset":
                                    __colorOffset = parameter;
                                case "openfl_Matrix":
                                    __matrix = parameter;
                                case "openfl_Position":
                                    __position = parameter;
                                case "openfl_TextureCoord":
                                    __textureCoord = parameter;
                                case "openfl_TextureSize":
                                    __textureSize = parameter;
                                default:
                            }
                        }

                        Reflect.setField(__data, name, parameter);
                        if (__isGenerated) {
                            bindKnownField(name, parameter);
                        }
                }
            }

            position = regex.matchedPos();
            lastMatch = position.pos + position.len;
        }
    }

    @:privateAccess function bindKnownField(name:String, value:Dynamic):Void {
        switch (name) {
            case "bitmap":
                bitmap = cast value;
            case "alpha":
                alpha = cast value;
            case "colorMultiplier":
                colorMultiplier = cast value;
            case "colorOffset":
                colorOffset = cast value;
            case "hasTransform":
                hasTransform = cast value;
            case "hasColorTransform":
                hasColorTransform = cast value;
            default:
        }
    }
}
