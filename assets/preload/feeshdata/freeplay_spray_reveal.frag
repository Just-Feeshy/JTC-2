#pragma header

uniform vec2 sectorCenterUv;
uniform vec2 spriteSize;
uniform float sectorRadius;
uniform float sectorStartAngle;
uniform float sectorEndAngle;
uniform float edgeSoftness;
uniform float active;

const float TWO_PI = 6.28318530717958647692;

void main(void)
{
    if (active <= 0.5) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }

    vec4 color = flixel_texture2D(bitmap, openfl_TextureCoordv);
    vec2 safeSpriteSize = vec2(max(spriteSize.x, 1.0), max(spriteSize.y, 1.0));
    vec2 delta = (openfl_TextureCoordv - sectorCenterUv) * safeSpriteSize;
    float dist = length(delta);
    float innerRadius = sectorRadius * max(0.0, 1.0 - edgeSoftness);
    float radiusMask = 1.0 - smoothstep(innerRadius, sectorRadius, dist);
    float maskAlpha = 0.0;

    if (dist <= sectorRadius) {
        float angle = atan(delta.y, delta.x);
        float sweep = mod(sectorEndAngle - sectorStartAngle + TWO_PI, TWO_PI);
        float point = mod(angle - sectorStartAngle + TWO_PI, TWO_PI);

        if (sweep <= 0.0001) {
            sweep = TWO_PI;
        }

        if (point <= sweep) {
            maskAlpha = radiusMask;
        }
    }

    gl_FragColor = vec4(color.rgb * maskAlpha, color.a * maskAlpha);
}
