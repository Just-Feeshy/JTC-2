package feshixl.shaders;

import lime.utils.Float32Array;
import openfl.display.BitmapData;
import openfl.display.ShaderInput;
import openfl.display.ShaderParameter;
import openfl.display.ShaderParameterType;
import openfl.display.GraphicsShader;

@:access(openfl.display.ShaderInput)
@:access(openfl.display3D.Context3D)
@:access(openfl.display3D.Program3D)
@:access(openfl.display.ShaderInput)
@:access(openfl.display.ShaderParameter)
class FeshBackendShader extends GraphicsShader {
    public function new() {
        super();
    }

    override function __initGL():Void {
        if (__glSourceDirty || __paramBool == null)
        {
            __glSourceDirty = false;
            program = null;

            __inputBitmapData = new Array();
            __paramBool = new Array();
            __paramFloat = new Array();
            __paramInt = new Array();

            __processGLData(glVertexSource, "attribute");
            __processGLData(glVertexSource, "uniform");
            __processGLData(glFragmentSource, "uniform");
        }

        if (__context != null && program == null)
        {
            var gl = __context.gl;

            var prefix = "#ifdef GL_ES
                "
                + (precisionHint == FULL ? "#ifdef GL_FRAGMENT_PRECISION_HIGH
                precision highp float;
                #else
                precision mediump float;
                #endif" : "precision lowp float;")
                + "
                #endif
                ";

            var vertex = prefix + glVertexSource;
            var fragment = prefix + glFragmentSource;

            var id = vertex + fragment;

            if (__context.__programs.exists(id))
            {
                program = __context.__programs.get(id);
            }
            else
            {
                program = __context.createProgram(GLSL);

                // TODO
                // program.uploadSources (vertex, fragment);
                program.__glProgram = __createGLProgram(vertex, fragment);

                __context.__programs.set(id, program);
            }

            if (program != null)
            {
                glProgram = program.__glProgram;

                for (input in __inputBitmapData)
                {
                    if (input.__isUniform)
                    {
                        input.index = gl.getUniformLocation(glProgram, input.name);
                    }
                    else
                    {
                        input.index = gl.getAttribLocation(glProgram, input.name);
                    }
                }

                for (parameter in __paramBool)
                {
                    if (parameter.__isUniform)
                    {
                        parameter.index = gl.getUniformLocation(glProgram, parameter.name);
                    }
                    else
                    {
                        parameter.index = gl.getAttribLocation(glProgram, parameter.name);
                    }
                }

                for (parameter in __paramFloat)
                {
                    if (parameter.__isUniform)
                    {
                        parameter.index = gl.getUniformLocation(glProgram, parameter.name);
                    }
                    else
                    {
                        parameter.index = gl.getAttribLocation(glProgram, parameter.name);
                    }
                }

                for (parameter in __paramInt)
                {
                    if (parameter.__isUniform)
                    {
                        parameter.index = gl.getUniformLocation(glProgram, parameter.name);
                    }
                    else
                    {
                        parameter.index = gl.getAttribLocation(glProgram, parameter.name);
                    }
                }
            }
        }
    }
    
    override function __processGLData(source:String, storageType:String):Void {
        var lastMatch = 0, position, regex, name, type;

        if (storageType == "uniform")
        {
            regex = ~/uniform ([A-Za-z0-9]+) ([A-Za-z0-9_]+)/;
        }
        else
        {
            regex = ~/attribute ([A-Za-z0-9]+) ([A-Za-z0-9_]+)/;
        }

        while (regex.matchSub(source, lastMatch))
        {
            type = regex.matched(1);
            name = regex.matched(2);

            if (StringTools.startsWith(name, "gl_"))
            {
                continue;
            }

            var isUniform = (storageType == "uniform");

            if (StringTools.startsWith(type, "sampler"))
            {
                var input = new ShaderInput<BitmapData>();
                input.name = name;
                input.__isUniform = isUniform;
                __inputBitmapData.push(input);

                switch (name)
                {
                    case "openfl_Texture":
                        __texture = input;
                    case "bitmap":
                        __bitmap = input;
                    default:
                }

                Reflect.setField(__data, name, input);
                // if (__isGenerated) Reflect.setField(this, name, input);
            }
            else if (!Reflect.hasField(__data, name) || Reflect.field(__data, name) == null)
            {
                var parameterType:ShaderParameterType = switch (type)
                {
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

                var length = switch (parameterType)
                {
                    case BOOL2, INT2, FLOAT2: 2;
                    case BOOL3, INT3, FLOAT3: 3;
                    case BOOL4, INT4, FLOAT4, MATRIX2X2: 4;
                    case MATRIX3X3: 9;
                    case MATRIX4X4: 16;
                    default: 1;
                }

                var arrayLength = switch (parameterType)
                {
                    case MATRIX2X2: 2;
                    case MATRIX3X3: 3;
                    case MATRIX4X4: 4;
                    default: 1;
                }

                switch (parameterType)
                {
                    case BOOL, BOOL2, BOOL3, BOOL4:
                        var parameter = new ShaderParameter<Bool>();
                        parameter.name = name;
                        parameter.type = parameterType;
                        parameter.__arrayLength = arrayLength;
                        parameter.__isBool = true;
                        parameter.__isUniform = isUniform;
                        parameter.__length = length;
                        __paramBool.push(parameter);

                        if (name == "openfl_HasColorTransform")
                        {
                            __hasColorTransform = parameter;
                        }

                        Reflect.setField(__data, name, parameter);
                    // if (__isGenerated) Reflect.setField(this, name, parameter);

                    case INT, INT2, INT3, INT4:
                        var parameter = new ShaderParameter<Int>();
                        parameter.name = name;
                        parameter.type = parameterType;
                        parameter.__arrayLength = arrayLength;
                        parameter.__isInt = true;
                        parameter.__isUniform = isUniform;
                        parameter.__length = length;
                        __paramInt.push(parameter);
                        Reflect.setField(__data, name, parameter);
                    // if (__isGenerated) Reflect.setField(this, name, parameter);

                    default:
                        var parameter = new ShaderParameter<Float>();
                        parameter.name = name;
                        parameter.type = parameterType;
                        parameter.__arrayLength = arrayLength;
                        #if lime
                        if (arrayLength > 0)
                            parameter.__uniformMatrix = new Float32Array(arrayLength * arrayLength);
                        #end
                        parameter.__isFloat = true;
                        parameter.__isUniform = isUniform;
                        parameter.__length = length;
                        __paramFloat.push(parameter);

                        if (StringTools.startsWith(name, "openfl_"))
                        {
                            switch (name)
                            {
                                case "openfl_Alpha": __alpha = parameter;
                                case "openfl_ColorMultiplier": __colorMultiplier = parameter;
                                case "openfl_ColorOffset": __colorOffset = parameter;
                                case "openfl_Matrix": __matrix = parameter;
                                case "openfl_Position": __position = parameter;
                                case "openfl_TextureCoord": __textureCoord = parameter;
                                case "openfl_TextureSize": __textureSize = parameter;
                                default:
                            }
                        }

                        Reflect.setField(__data, name, parameter);
                        // if (__isGenerated) Reflect.setField(this, name, parameter);
                }
            }

            position = regex.matchedPos();
            lastMatch = position.pos + position.len;
        }
    }
}