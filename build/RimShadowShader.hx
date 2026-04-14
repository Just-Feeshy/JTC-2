package;

import flixel.graphics.frames.FlxFrame;
import flixel.system.FlxAssets.FlxShader;
import flixel.util.FlxColor;

class RimShadowShader extends FlxShader
{
	public var color(default, set):Int = 0xFFD46B00;
	public var angle(default, set):Float = 125;
	public var distance(default, set):Float = 12;
	public var threshold(default, set):Float = 0.15;
	public var brightness(default, set):Float = -35;
	public var hue(default, set):Float = -15;
	public var contrast(default, set):Float = 10;
	public var saturation(default, set):Float = -20;

	@:glFragmentSource('
		#pragma header

		uniform vec4 uShadowColor;
		uniform float uAngle;
		uniform float uDistance;
		uniform float uThreshold;
		uniform float uBrightness;
		uniform float uHue;
		uniform float uContrast;
		uniform float uSaturation;
		uniform vec4 uFrameBounds;

		const float PI = 3.14159265358979323846;

		bool isInsideFrame(vec2 uv) {
			return uv.x >= uFrameBounds.x
				&& uv.x <= uFrameBounds.z
				&& uv.y >= uFrameBounds.y
				&& uv.y <= uFrameBounds.w;
		}

		vec4 sampleFrame(vec2 uv) {
			if(!isInsideFrame(uv)) {
				return vec4(0.0, 0.0, 0.0, 0.0);
			}

			return flixel_texture2D(bitmap, uv);
		}

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
			vec2 uv = openfl_TextureCoordv;
			vec4 source = sampleFrame(uv);
			float radiansValue = radians(uAngle);
			vec2 offset = vec2(cos(radiansValue), -sin(radiansValue)) * (uDistance / openfl_TextureSize);
			vec4 shifted = sampleFrame(uv - offset);
			float baseMask = step(uThreshold, source.a);
			float shadowMask = step(uThreshold, shifted.a) * (1.0 - baseMask);
			float shadowAlpha = shadowMask * shifted.a * uShadowColor.a;
			vec3 shadowRgb = applyAdjustColor(uShadowColor.rgb);
			vec3 straightSource = source.a > 0.0 ? clamp(source.rgb / source.a, 0.0, 1.0) : vec3(0.0, 0.0, 0.0);
			vec3 combinedRgb = (shadowRgb * shadowAlpha * (1.0 - source.a)) + (straightSource * source.a);
			float combinedAlpha = shadowAlpha * (1.0 - source.a) + source.a;

			gl_FragColor = vec4(combinedRgb, combinedAlpha);
		}
	')
	public function new()
	{
		super();

		set_color(0xFFD46B00);
		set_angle(125);
		set_distance(12);
		set_threshold(0.15);
		set_brightness(-35);
		set_hue(-15);
		set_contrast(10);
		set_saturation(-20);
		uFrameBounds.value = [0, 0, 1, 1];
	}

	public function updateFrameInfo(frame:FlxFrame):Void
	{
		if(frame == null || frame.parent == null || frame.parent.width <= 0 || frame.parent.height <= 0) {
			uFrameBounds.value = [0, 0, 1, 1];
			return;
		}

		var atlasWidth:Float = frame.parent.width;
		var atlasHeight:Float = frame.parent.height;
		var frameRect = frame.frame;
		var left:Float = frameRect.x / atlasWidth;
		var top:Float = frameRect.y / atlasHeight;
		var right:Float = (frameRect.x + frameRect.width) / atlasWidth;
		var bottom:Float = (frameRect.y + frameRect.height) / atlasHeight;
		uFrameBounds.value = [left, top, right, bottom];
	}

	function set_color(value:Int):Int
	{
		color = value;

		var resolved:FlxColor = FlxColor.fromInt(value);
		uShadowColor.value = [
			resolved.redFloat,
			resolved.greenFloat,
			resolved.blueFloat,
			resolved.alphaFloat
		];

		return value;
	}

	function set_angle(value:Float):Float
	{
		angle = value;
		uAngle.value = [value];
		return value;
	}

	function set_distance(value:Float):Float
	{
		distance = value;
		uDistance.value = [value];
		return value;
	}

	function set_threshold(value:Float):Float
	{
		threshold = value;
		uThreshold.value = [value];
		return value;
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
