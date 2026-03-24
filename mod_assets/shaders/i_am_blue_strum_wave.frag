#pragma header

uniform float waveAmplitude;
uniform float wavePhase;
uniform float waveBandCenterY;
uniform float waveBandHalfHeight;
uniform float waveFrequency;
uniform float laneRadius;
uniform float laneCentersA[4];
uniform float laneCentersB[4];
uniform int laneCount;

float getLaneCenter(int index) {
    if (index == 0) return laneCentersA[0];
    if (index == 1) return laneCentersA[1];
    if (index == 2) return laneCentersA[2];
    if (index == 3) return laneCentersA[3];
    if (index == 4) return laneCentersB[0];
    if (index == 5) return laneCentersB[1];
    if (index == 6) return laneCentersB[2];
    if (index == 7) return laneCentersB[3];
    return 0.0;
}

float getNearestLaneCenter(float xPx) {
    float bestCenter = 0.0;
    float bestDistance = 999999.0;

    for (int i = 0; i < 8; i++) {
        if (i >= laneCount) {
            break;
        }

        float center = getLaneCenter(i);
        float distanceToLane = abs(xPx - center);

        if (distanceToLane < bestDistance) {
            bestDistance = distanceToLane;
            bestCenter = center;
        }
    }

    return bestCenter;
}

vec4 sampleColor(vec2 uv) {
    if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
        return vec4(0.0);
    }

    return flixel_texture2D(bitmap, uv);
}

void main() {
    vec2 uv = openfl_TextureCoordv;

    if (waveAmplitude <= 0.001 || laneCount <= 0 || waveBandHalfHeight <= 0.0001) {
        gl_FragColor = sampleColor(uv);
        return;
    }

    vec2 posPx = uv * openfl_TextureSize;
    float bandCenterPx = waveBandCenterY * openfl_TextureSize.y;
    float bandHalfHeightPx = waveBandHalfHeight * openfl_TextureSize.y;
    float laneCenterPx = getNearestLaneCenter(posPx.x);
    float laneDistancePx = abs(posPx.x - laneCenterPx);

    float laneMask = 1.0 - smoothstep(laneRadius * 0.35, laneRadius, laneDistancePx);
    float bandDistancePx = abs(posPx.y - bandCenterPx);
    float bandMask = 1.0 - smoothstep(bandHalfHeightPx * 0.35, bandHalfHeightPx, bandDistancePx);

    float wave = sin(((posPx.x - laneCenterPx) * waveFrequency) + wavePhase);
    float offsetPx = wave * waveAmplitude * laneMask * bandMask;

    vec2 warpedUv = uv;
    warpedUv.y -= offsetPx / max(openfl_TextureSize.y, 1.0);
    warpedUv.x += (offsetPx * 0.15) / max(openfl_TextureSize.x, 1.0);

    gl_FragColor = sampleColor(warpedUv);
}
