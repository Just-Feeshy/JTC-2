#pragma header

uniform vec2 sectorCenterUv;
uniform vec2 spriteSize;
uniform float sectorRadius;
uniform float sectorStartAngle;
uniform float sectorEndAngle;
uniform float edgeSoftness;
uniform float active;

const float PI = 3.14159265358979323846;
const float TWO_PI = 6.28318530717958647692;

float normalizeAngle(float angle)
{
    float wrapped = mod(angle, TWO_PI);
    return wrapped < 0.0 ? wrapped + TWO_PI : wrapped;
}

float angleDistance(float start, float angle)
{
    float diff = normalizeAngle(angle) - normalizeAngle(start);
    return diff < 0.0 ? diff + TWO_PI : diff;
}

void main(void)
{
    vec4 color = flixel_texture2D(bitmap, openfl_TextureCoordv);
    vec2 safeSpriteSize = max(spriteSize, vec2(1.0, 1.0));
    vec2 delta = (openfl_TextureCoordv - sectorCenterUv) * safeSpriteSize;
    float dist = length(delta);
    float maskAlpha = 0.0;

    if (active > 0.5 && dist <= sectorRadius) {
        float angle = atan(delta.y, delta.x);
        float sweep = angleDistance(sectorStartAngle, sectorEndAngle);
        float point = angleDistance(sectorStartAngle, angle);

        if (sweep <= 0.0) {
            sweep = TWO_PI;
        }

        if (point <= sweep) {
            float innerRadius = sectorRadius * max(0.0, 1.0 - edgeSoftness);
            maskAlpha = 1.0 - smoothstep(innerRadius, sectorRadius, dist);
        }
    }

    color *= maskAlpha;

    gl_FragColor = color * maskAlpha;
}
