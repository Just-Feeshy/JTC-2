#pragma header

uniform float opacity;
uniform float time;

float random(vec2 st) {
    return fract(sin(dot(st.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

void main() {
    vec2 fragCoord = openfl_TextureCoordv * openfl_TextureSize;
    vec2 uv = fragCoord / openfl_TextureSize;

    // Original texture
    vec4 texColor = flixel_texture2D(bitmap, openfl_TextureCoordv);

    // Time varying pixel color
    vec3 col = vec3((length(uv - 0.5) + 0.5), 0.1, 0.1);

    // Apply random effect with time-based seed
    vec3 overlayColor = col * random(uv * time);

    // Blend as overlay with opacity control
    vec3 result = mix(texColor.rgb, overlayColor, opacity);

    gl_FragColor = vec4(result, texColor.a);
}
