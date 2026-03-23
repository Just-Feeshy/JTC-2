#pragma header

uniform float curveStrength;
uniform float curveOriginY;
uniform float curvePadding;
uniform float laneCentersA[4];
uniform float laneCentersB[4];
uniform float laneCentersC[4];
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
    return 0.5;
}

vec4 sampleSustain(vec2 uv) {
    if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
        return vec4(0.0);
    }

    return texture2D(openfl_Texture, uv);
}

void getNearestLaneData(float x, out float laneCenter, out float curveDirection) {
    laneCenter = 0.5;
    curveDirection = 0.0;

    if (laneCount <= 0) {
        return;
    }

    float bestDistance = 9999.0;

    for (int i = 0; i < 12; i++) {
        if (i >= laneCount) {
            break;
        }

        float currentCenter = getLaneCenter(i);
        float currentDistance = abs(x - currentCenter);

        if (currentDistance < bestDistance) {
            bestDistance = currentDistance;
            laneCenter = currentCenter;
        }
    }

    curveDirection = laneCenter < 0.5 ? 1.0 : -1.0;
}

void main() {
    vec2 uv = openfl_TextureCoordv;

    if (curveStrength <= 0.0001 || laneCount <= 0) {
        gl_FragColor = sampleSustain(uv);
        return;
    }

    float laneCenter;
    float curveDirection;
    getNearestLaneData(uv.x, laneCenter, curveDirection);

    float yDistance = abs(uv.y - curveOriginY);
    float laneDistance = abs(uv.x - laneCenter);
    float laneFade = 1.0 - smoothstep(curvePadding, curvePadding * 1.5, laneDistance);
    float curveOffset = curveDirection * curveStrength * yDistance * yDistance * laneFade;

    vec2 curvedUv = uv;
    curvedUv.x -= curveOffset;

    vec4 curvedSustain = sampleSustain(curvedUv);
    gl_FragColor = curvedSustain;
}
