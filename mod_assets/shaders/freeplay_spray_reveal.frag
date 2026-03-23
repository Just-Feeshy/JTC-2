#pragma header

uniform float pathBaseX;
uniform float pathBaseY;
uniform float curveScaleX;
uniform float curveScaleY;
uniform float sprayT;
uniform float trailShift;
uniform float trailRadius;
uniform float edgeSoftness;
uniform float active;
uniform float fullReveal;

const float BASE_CURVE_MAX = 23.140692632779267;
const float CURVE_MIN = -5.0;
const float CURVE_MAX = BASE_CURVE_MAX * 1.32;
const float PI = 3.14159265358979323846;
const int TRAIL_SAMPLES = 96;

float smin(float a, float b, float k0)
{
    float k = k0 * 2.0;
    float x = b - a;
    return 0.5 * (a + b - sqrt(x * x + k * k));
}

float logChirp(float x, float a, float b, float n)
{
    float shift = exp(-(2.0 * n) / 8.0);
    float u = x / b + shift;
    float phase = a * log(u);
    float env = exp(0.5 - (x / (b * n)));
    return 6.0 * env * cos(phase / 2.0);
}

float sprayCurveY(float x)
{
    float yOffset = 18.0 * logChirp(max(x, 0.001) + 3.0 * PI / 2.0, 48.0, 24.0, PI);
    return -smin(yOffset, 150.0 * x + 170.0, 10.0);
}

vec2 trailPoint(float t)
{
    float x = (t * exp(t / 8.0)) * curveScaleX + pathBaseX - trailShift;
    float y = sprayCurveY(t) * curveScaleY + pathBaseY;
    return vec2(x, y);
}

float segmentDistance(vec2 p, vec2 a, vec2 b)
{
    vec2 ab = b - a;
    float denom = max(dot(ab, ab), 0.0001);
    float t = clamp(dot(p - a, ab) / denom, 0.0, 1.0);
    return distance(p, a + ab * t);
}

void main(void)
{
    vec4 color = flixel_texture2D(bitmap, openfl_TextureCoordv);

    if (active <= 0.5) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }

    vec2 pos = openfl_TextureCoordv * openfl_TextureSize;
    float headT = clamp(sprayT, CURVE_MIN, CURVE_MAX);
    if (headT <= CURVE_MIN + 0.05) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }

    float minDist = 1000000.0;
    vec2 prevPoint = trailPoint(CURVE_MIN);

    for (int i = 1; i < TRAIL_SAMPLES; i++) {
        float sampleProgress = float(i) / float(TRAIL_SAMPLES - 1);
        float sampleT = mix(CURVE_MIN, headT, sampleProgress);
        vec2 nextPoint = trailPoint(sampleT);
        minDist = min(minDist, segmentDistance(pos, prevPoint, nextPoint));
        prevPoint = nextPoint;
    }

    float safeRadius = max(1.0, trailRadius);
    float feather = max(1.0, safeRadius * clamp(edgeSoftness, 0.01, 0.44));
    float solidRadius = max(0.0, safeRadius - feather);
    float mask = minDist <= solidRadius ? 1.0 : 1.0 - smoothstep(solidRadius, safeRadius, minDist);
    mask = mix(mask, 1.0, clamp(fullReveal, 0.0, 1.0));

    gl_FragColor = vec4(color.rgb * mask, color.a * mask);
}
