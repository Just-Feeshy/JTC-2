package feshixl.shaders;

class FeshShader extends FeshBackendShader {
	var glVertexHeader:String = "
        attribute float openfl_Alpha;
		attribute vec4 openfl_ColorMultiplier;
		attribute vec4 openfl_ColorOffset;
		attribute vec4 openfl_Position;
		attribute vec2 openfl_TextureCoord;
		varying float openfl_Alphav;
		varying vec4 openfl_ColorMultiplierv;
		varying vec4 openfl_ColorOffsetv;
		varying vec2 openfl_TextureCoordv;
		uniform mat4 openfl_Matrix;
		uniform bool openfl_HasColorTransform;
		uniform vec2 openfl_TextureSize;
    ";

	var glVertexBody:String = "
        openfl_Alphav = openfl_Alpha;
		openfl_TextureCoordv = openfl_TextureCoord;

		if (openfl_HasColorTransform) {
			openfl_ColorMultiplierv = openfl_ColorMultiplier;
			openfl_ColorOffsetv = openfl_ColorOffset / 255.0;
		}

		gl_Position = openfl_Matrix * openfl_Position;
    ";

	var glFragmentHeader:String = "
        varying float openfl_Alphav;
		varying vec4 openfl_ColorMultiplierv;
		varying vec4 openfl_ColorOffsetv;
		varying vec2 openfl_TextureCoordv;
		uniform bool openfl_HasColorTransform;
		uniform vec2 openfl_TextureSize;
		uniform sampler2D bitmap;";

	var glFragmentBody:String = "
        vec4 color = texture2D (bitmap, openfl_TextureCoordv);

		if (color.a == 0.0) {
			gl_FragColor = vec4 (0.0, 0.0, 0.0, 0.0);
		} else if (openfl_HasColorTransform) {
			color = vec4 (color.rgb / color.a, color.a);
			mat4 colorMultiplier = mat4 (0);
			colorMultiplier[0][0] = openfl_ColorMultiplierv.x;
			colorMultiplier[1][1] = openfl_ColorMultiplierv.y;
			colorMultiplier[2][2] = openfl_ColorMultiplierv.z;
			colorMultiplier[3][3] = 1.0; // openfl_ColorMultiplierv.w;
			color = clamp (openfl_ColorOffsetv + (color * colorMultiplier), 0.0, 1.0);

			if (color.a > 0.0) {
				gl_FragColor = vec4 (color.rgb * color.a * openfl_Alphav, color.a * openfl_Alphav);
			} else {
				gl_FragColor = vec4 (0.0, 0.0, 0.0, 0.0);
			}
		} else {
			gl_FragColor = color * openfl_Alphav;
		}";

	public function new(glVertexSource:String = "", glFragmentSource:String = "", initialize:Bool = true) {
		super();

		if(glFragmentSource != "" && glFragmentSource != null) {
			this.glFragmentSource = glFragmentSource;
		}else {
			this.glFragmentSource = "
				#pragma header
				
				void main(void)
				{
					#pragma body
				}
			";
		}

		if(glVertexSource != "" && glVertexSource != null) {
			this.glVertexSource = glVertexSource;
		}else {
			this.glVertexSource = "
				#pragma header
				
				void main(void)
				{
					#pragma body
				}
			";
		}

        if(initialize) {
            __initGL();
        }
	}

    public function processShader(glFragmentSource:String = null, glVertexSource:String = null):Void {
        if(glFragmentSource != null) {
            this.glFragmentSource = glFragmentSource; 
        }

        if(glVertexSource != null) {
            this.glVertexSource = glVertexSource;
        }

        __initGL();
    }

    function processFragment():Void {
        if (glFragmentSource != null && glFragmentHeader != null && glFragmentBody != null) {
            glFragmentSource = StringTools.replace(glFragmentSource, "#pragma header", glFragmentHeader);
			glFragmentSource = StringTools.replace(glFragmentSource, "#pragma body", glFragmentBody);
        }
    }

    function processVertex():Void {
        if (glVertexSource != null && glVertexHeader != null && glVertexBody != null) {
            glVertexSource = StringTools.replace(glVertexSource, "#pragma header", glVertexHeader);
			glVertexSource = StringTools.replace(glVertexSource, "#pragma body", glVertexBody);
        }
    }

    override public function __initGL() {
        processFragment();
        processVertex();

        __isGenerated = true;
        super.__initGL();

        bitmap = data.bitmap;
    }
}