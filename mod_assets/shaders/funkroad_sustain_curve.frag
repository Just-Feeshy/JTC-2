#pragma header

uniform float curveStrength;
uniform float curveOriginY;
uniform float laneCentersA[4];
uniform float laneCentersB[4];
uniform float laneCentersC[4];
uniform float laneOffsetXA[4];
uniform float laneOffsetXB[4];
uniform float laneOffsetXC[4];
uniform float laneTravelYA[4];
uniform float laneTravelYB[4];
uniform float laneTravelYC[4];
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
    if (index == 8) return laneCentersC[0];
    if (index == 9) return laneCentersC[1];
    if (index == 10) return laneCentersC[2];
    if (index == 11) return laneCentersC[3];
    return 0.0;
}

float getLaneOffsetX(int index) {
    if (index == 0) return laneOffsetXA[0];
    if (index == 1) return laneOffsetXA[1];
    if (index == 2) return laneOffsetXA[2];
    if (index == 3) return laneOffsetXA[3];
    if (index == 4) return laneOffsetXB[0];
    if (index == 5) return laneOffsetXB[1];
    if (index == 6) return laneOffsetXB[2];
    if (index == 7) return laneOffsetXB[3];
    if (index == 8) return laneOffsetXC[0];
    if (index == 9) return laneOffsetXC[1];
    if (index == 10) return laneOffsetXC[2];
    if (index == 11) return laneOffsetXC[3];
    return 0.0;
}

float getLaneTravelY(int index) {
    if (index == 0) return laneTravelYA[0];
    if (index == 1) return laneTravelYA[1];
    if (index == 2) return laneTravelYA[2];
    if (index == 3) return laneTravelYA[3];
    if (index == 4) return laneTravelYB[0];
    if (index == 5) return laneTravelYB[1];
    if (index == 6) return laneTravelYB[2];
    if (index == 7) return laneTravelYB[3];
    if (index == 8) return laneTravelYC[0];
    if (index == 9) return laneTravelYC[1];
    if (index == 10) return laneTravelYC[2];
    if (index == 11) return laneTravelYC[3];
    return 1.0;
}

vec4 sampleSustain(vec2 uv) {
    if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
        return vec4(0.0);
    }

    return flixel_texture2D(bitmap, uv);
}

void getNearestLaneData(float xPx, out float laneCenterPx, out float laneOffsetPx, out float laneTravelPx) {
    laneCenterPx = 0.0;
    laneOffsetPx = 0.0;
    laneTravelPx = 1.0;

    if (laneCount <= 0) {
        return;
    }

    float bestDistance = 999999.0;

    for (int i = 0; i < 12; i++) {
        if (i >= laneCount) {
            break;
        }

        float currentCenter = getLaneCenter(i);
        float currentDistance = abs(xPx - currentCenter);

        if (currentDistance < bestDistance) {
            bestDistance = currentDistance;
            laneCenterPx = currentCenter;
            laneOffsetPx = getLaneOffsetX(i);
            laneTravelPx = max(getLaneTravelY(i), 1.0);
        }
    }
}

void main() {
    vec2 uv = openfl_TextureCoordv;
    if (curveStrength <= 0.0001 || laneCount <= 0) {
        gl_FragColor = sampleSustain(uv);
        return;
    }

    float xPx = uv.x * openfl_TextureSize.x;
    float yPx = uv.y * openfl_TextureSize.y;
    float strumY = curveOriginY * openfl_TextureSize.y;

    float laneCenterPx;
    float laneOffsetPx;
    float laneTravelPx;
    getNearestLaneData(xPx, laneCenterPx, laneOffsetPx, laneTravelPx);

    float timeDistancePx = yPx - strumY;
    float travelT = timeDistancePx / laneTravelPx;
    float curveOffsetPx = laneOffsetPx * travelT * curveStrength;

    vec2 curvedUv = uv;
    curvedUv.x -= curveOffsetPx / openfl_TextureSize.x;

    gl_FragColor = sampleSustain(curvedUv);
}
