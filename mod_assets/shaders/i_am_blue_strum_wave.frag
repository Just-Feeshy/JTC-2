#pragma header

uniform float waveAmplitude;
uniform float waveTime;
uniform float waveTravelSpeed;
uniform float waveSeed;
uniform float waveLengthMin;
uniform float waveLengthMax;
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

void getNearestLaneData(float xPx, out float laneCenter, out float laneIndex) {
    float bestCenter = 0.0;
    float bestDistance = 999999.0;
    float bestIndex = 0.0;

    for (int i = 0; i < 8; i++) {
        if (i >= laneCount) {
            break;
        }

        float center = getLaneCenter(i);
        float distanceToLane = abs(xPx - center);

        if (distanceToLane < bestDistance) {
            bestDistance = distanceToLane;
            bestCenter = center;
            bestIndex = float(i);
        }
    }

    laneCenter = bestCenter;
    laneIndex = bestIndex;
}

vec4 sampleColor(vec2 uv) {
    if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
        return vec4(0.0);
    }

    return flixel_texture2D(bitmap, uv);
}

float hash11(float p) {
    return fract(sin(p * 127.1) * 43758.5453123);
}

float getSegmentLength(float segmentIndex) {
    return mix(waveLengthMin, waveLengthMax, hash11(segmentIndex + (waveSeed * 17.0)));
}

void main() {
    vec2 uv = openfl_TextureCoordv;

    if (waveAmplitude <= 0.001 || laneCount <= 0) {
        gl_FragColor = sampleColor(uv);
        return;
    }

    vec2 posPx = uv * openfl_TextureSize;
    float laneCenterPx;
    float laneIndex;
    getNearestLaneData(posPx.x, laneCenterPx, laneIndex);
    float headAnchor = smoothstep(0.035, 0.16, uv.y);
    float waveCoord = max(posPx.y - (waveTime * waveTravelSpeed), 0.0);

    float accumulated = 0.0;
    float segmentIndex = 0.0;
    float segmentLength = waveLengthMin;

    for (int i = 0; i < 12; i++) {
        segmentIndex = float(i);
        segmentLength = getSegmentLength(segmentIndex);

        if (waveCoord <= accumulated + segmentLength || i == 11) {
            break;
        }

        accumulated += segmentLength;
    }

    float localT = clamp((waveCoord - accumulated) / max(segmentLength, 1.0), 0.0, 1.0);
    float segmentAmplitude = mix(0.55, 0.95, hash11(segmentIndex + (waveSeed * 29.0)));
    float segmentDirection = mod(segmentIndex, 2.0) < 1.0 ? 1.0 : -1.0;
    float verticalWave = sin(localT * 3.14159265) * segmentAmplitude * segmentDirection;
    float offsetPx = verticalWave * waveAmplitude * headAnchor;

    vec2 warpedUv = uv;
    warpedUv.x += offsetPx / max(openfl_TextureSize.x, 1.0);

    gl_FragColor = sampleColor(warpedUv);
}
