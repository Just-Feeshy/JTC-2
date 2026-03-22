#pragma header

uniform float curveStrength;
uniform float curveDirection;
uniform float curveOriginY;
uniform float curvePadding;

void main() {
    vec2 sampleUv = openfl_TextureCoordv;
    float yDistance = abs(sampleUv.y - curveOriginY);
    float innerWidth = max(0.001, 1.0 - (curvePadding * 2.0));
    float curvedX = sampleUv.x - (curveDirection * curveStrength * yDistance * yDistance);

    sampleUv.x = (curvedX - curvePadding) / innerWidth;

    if (sampleUv.x < 0.0 || sampleUv.x > 1.0 || sampleUv.y < 0.0 || sampleUv.y > 1.0) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }

    gl_FragColor = flixel_texture2D(bitmap, sampleUv);
}
