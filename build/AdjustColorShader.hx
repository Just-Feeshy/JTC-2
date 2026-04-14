package;

import flixel.system.FlxAssets.FlxShader;

class AdjustColorShader extends FlxShader
{
	public var brightness(default, set):Float = 0;
	public var hue(default, set):Float = 0;
	public var contrast(default, set):Float = 0;
	public var saturation(default, set):Float = 0;

	@:glFragmentSource('
		#pragma header

		uniform float uBrightness;
		uniform float uHue;
		uniform float uContrast;
		uniform float uSaturation;

		const float PI = 3.14159265358979323846;

		vec3 applyHue(vec3 color, float hueShift) {
			const mat3 rgbToYiq = mat3(
				0.299, 0.587, 0.114,
				0.596, -0.275, -0.321,
				0.212, -0.523, 0.311
			);

			const mat3 yiqToRgb = mat3(
				1.0, 0.956, 0.621,
				1.0, -0.272, -0.647,
				1.0, -1.106, 1.703
			);

			vec3 yiq = rgbToYiq * color;
			float currentHue = atan(yiq.b, yiq.g);
			float chroma = sqrt((yiq.g * yiq.g) + (yiq.b * yiq.b));
			float nextHue = currentHue + hueShift;
			vec3 shifted = vec3(yiq.r, chroma * cos(nextHue), chroma * sin(nextHue));
			return clamp(yiqToRgb * shifted, 0.0, 1.0);
		}

		vec3 applyAdjustColor(vec3 color) {
			float hueShift = (uHue / 100.0) * PI;
			float contrastScale = max(0.0, 1.0 + (uContrast / 100.0));
			float saturationScale = max(0.0, 1.0 + (uSaturation / 100.0));
			float brightnessOffset = uBrightness / 100.0;

			color = applyHue(color, hueShift);

			float luma = dot(color, vec3(0.299, 0.587, 0.114));
			color = mix(vec3(luma), color, saturationScale);
			color = ((color - 0.5) * contrastScale) + 0.5;
			color += brightnessOffset;

			return clamp(color, 0.0, 1.0);
		}

		void main() {
			vec4 source = flixel_texture2D(bitmap, openfl_TextureCoordv);

			if(source.a <= 0.0) {
				gl_FragColor = source;
				return;
			}

			vec3 straightColor = source.rgb / source.a;
			vec3 adjustedColor = applyAdjustColor(clamp(straightColor, 0.0, 1.0));
			gl_FragColor = vec4(adjustedColor * source.a, source.a);
		}
	')
	public function new()
	{
		super();

		set_brightness(0);
		set_hue(0);
		set_contrast(0);
		set_saturation(0);
	}

	function set_brightness(value:Float):Float
	{
		brightness = value;
		uBrightness.value = [value];
		return value;
	}

	function set_hue(value:Float):Float
	{
		hue = value;
		uHue.value = [value];
		return value;
	}

	function set_contrast(value:Float):Float
	{
		contrast = value;
		uContrast.value = [value];
		return value;
	}

	function set_saturation(value:Float):Float
	{
		saturation = value;
		uSaturation.value = [value];
		return value;
	}
}
