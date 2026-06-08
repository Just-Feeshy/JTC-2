#pragma header

uniform float intensity;
uniform float bloomStrength;
uniform float dialogueBlur;

float redness(vec3 c) {
    return max(0.0, c.r - max(c.g, c.b));
}

void main() {
    vec2 uv = openfl_TextureCoordv;
    vec4 texColor = flixel_texture2D(bitmap, uv);
    vec3 color = texColor.rgb;

    vec3 purpleMul = vec3(0.65, 0.30, 1.0);
    vec3 lit = color * purpleMul;

    vec2 t = 1.0 / openfl_TextureSize;
    float r = 5.0;
    float d = r * 0.7071;

    vec3 s0 = color;
    vec3 s1 = flixel_texture2D(bitmap, uv + vec2( r,  0.0) * t).rgb;
    vec3 s2 = flixel_texture2D(bitmap, uv + vec2(-r,  0.0) * t).rgb;
    vec3 s3 = flixel_texture2D(bitmap, uv + vec2( 0.0,  r) * t).rgb;
    vec3 s4 = flixel_texture2D(bitmap, uv + vec2( 0.0, -r) * t).rgb;
    vec3 s5 = flixel_texture2D(bitmap, uv + vec2( d,  d) * t).rgb;
    vec3 s6 = flixel_texture2D(bitmap, uv + vec2(-d,  d) * t).rgb;
    vec3 s7 = flixel_texture2D(bitmap, uv + vec2( d, -d) * t).rgb;
    vec3 s8 = flixel_texture2D(bitmap, uv + vec2(-d, -d) * t).rgb;

    vec3 sf1 = flixel_texture2D(bitmap, uv + vec2( r * 2.0,  0.0) * t).rgb;
    vec3 sf2 = flixel_texture2D(bitmap, uv + vec2(-r * 2.0,  0.0) * t).rgb;
    vec3 sf3 = flixel_texture2D(bitmap, uv + vec2( 0.0,  r * 2.0) * t).rgb;
    vec3 sf4 = flixel_texture2D(bitmap, uv + vec2( 0.0, -r * 2.0) * t).rgb;

    float wCenter = 0.25;
    float wNear   = 0.10;
    float wDiag   = 0.07;
    float wFar    = 0.05;

    float red = redness(s0) * wCenter
              + (redness(s1) + redness(s2) + redness(s3) + redness(s4)) * wNear
              + (redness(s5) + redness(s6) + redness(s7) + redness(s8)) * wDiag
              + (redness(sf1) + redness(sf2) + redness(sf3) + redness(sf4)) * wFar;

    red = pow(red, 0.85) * bloomStrength;

    vec3 bloomColor = vec3(red * 1.0, red * 0.18, red * 0.12);

    vec3 result = lit + bloomColor;

    result = mix(color, result, clamp(intensity, 0.0, 1.0));

    float db = clamp(dialogueBlur, 0.0, 1.0);
    if (db > 0.0) {
        float blurR = 8.0 * db;
        float blurD = blurR * 0.7071;
        vec3 blurred = result;
        blurred += flixel_texture2D(bitmap, uv + vec2( blurR, 0.0) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2(-blurR, 0.0) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2( 0.0,  blurR) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2( 0.0, -blurR) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2( blurD,  blurD) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2(-blurD,  blurD) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2( blurD, -blurD) * t).rgb;
        blurred += flixel_texture2D(bitmap, uv + vec2(-blurD, -blurD) * t).rgb;
        blurred /= 9.0;

        vec3 dialoguePurple = blurred * vec3(0.55, 0.25, 1.05);
        float luma = dot(blurred, vec3(0.299, 0.587, 0.114));
        dialoguePurple = mix(dialoguePurple, vec3(0.45, 0.15, 0.85) * (0.4 + luma), 0.35);

        result = mix(result, dialoguePurple, db);
    }

    gl_FragColor = vec4(result, texColor.a);
}
