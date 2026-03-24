local pulseStepIntensity = {}
local baseGameZoom = 1
local baseHudZoom = 1
local baseNoteZoom = 1
local strumWaveAmplitude = 0
local strumWavePhase = 0
local strumWaveShaderActive = false
local strumWaveShaderInitialized = false
local strumWaveLaneCount = 8
local strumWaveLaneCentersA = {0, 0, 0, 0}
local strumWaveLaneCentersB = {0, 0, 0, 0}

local INTENSITY_MULTIPLIER = 1.5
local BASE_GAME_BUMP = 0.015
local BASE_HUD_BUMP = 0.03
local BASE_NOTE_BUMP = 0.03
local STRUM_WAVE_SHADER = "i_am_blue_strum_wave"
local STRUM_WAVE_CAMERA = "camNOTE"
local STRUM_WAVE_SIZE = 160 * 0.7
local STRUM_WAVE_BAND_HEIGHT = STRUM_WAVE_SIZE * 1.1
local STRUM_WAVE_LANE_RADIUS = STRUM_WAVE_SIZE * 0.95
local STRUM_WAVE_FREQUENCY = 0.08
local STRUM_WAVE_PHASE_SPEED = 12
local STRUM_WAVE_DECAY_RATE = 7.5
local STRUM_WAVE_MAX_AMPLITUDE = 18
local STRUM_WAVE_KICK = 7.5

local function addPulseStep(stepValue, intensity)
    pulseStepIntensity[stepValue] = intensity
end

local function addPulseRange(startStep, endStep, everySteps, intensity)
    if everySteps == nil or everySteps <= 0 then
        return
    end

    local stepValue = startStep

    while stepValue <= endStep do
        addPulseStep(stepValue, intensity)
        stepValue = stepValue + everySteps
    end
end

local function addPulseSteps(stepList, intensity)
    if stepList == nil then
        return
    end

    for i = 1, #stepList do
        addPulseStep(stepList[i], intensity)
    end
end

local function updateStrumWaveLaneCenters()
    if getNotePosX == nil then
        return
    end

    strumWaveLaneCount = 8

    for index = 1, 4 do
        strumWaveLaneCentersA[index] = 0
        strumWaveLaneCentersB[index] = 0
    end

    for lane = 0, strumWaveLaneCount - 1 do
        local laneX = getNotePosX(lane)

        if laneX == nil then
            laneX = 0
        end

        local centerX = laneX + (STRUM_WAVE_SIZE * 0.5)

        if lane < 4 then
            strumWaveLaneCentersA[lane + 1] = centerX
        else
            strumWaveLaneCentersB[(lane - 4) + 1] = centerX
        end
    end
end

local function ensureStrumWaveShader()
    if strumWaveShaderActive then
        return true
    end

    if not strumWaveShaderInitialized and initLuaShader ~= nil then
        strumWaveShaderInitialized = initLuaShader(STRUM_WAVE_SHADER, "shaders") == true
    end

    if not strumWaveShaderInitialized or setCameraShader == nil then
        return false
    end

    strumWaveShaderActive = setCameraShader(STRUM_WAVE_CAMERA, STRUM_WAVE_SHADER) == true
    return strumWaveShaderActive
end

local function updateStrumWaveShader()
    if not ensureStrumWaveShader() then
        return
    end

    if setShaderFloat == nil or setShaderFloatArray == nil or setShaderInt == nil then
        return
    end

    updateStrumWaveLaneCenters()

    local bandCenterY = 0.16

    if getNotePosY ~= nil and windowHeight ~= nil and windowHeight > 0 then
        local strumY = getNotePosY(0)

        if strumY ~= nil then
            bandCenterY = (strumY + (STRUM_WAVE_SIZE * 0.5)) / windowHeight
        end
    end

    setShaderFloat(STRUM_WAVE_CAMERA, "waveAmplitude", strumWaveAmplitude)
    setShaderFloat(STRUM_WAVE_CAMERA, "wavePhase", strumWavePhase)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveBandCenterY", bandCenterY)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveBandHalfHeight", (STRUM_WAVE_BAND_HEIGHT * 0.5) / math.max(windowHeight or 1, 1))
    setShaderFloat(STRUM_WAVE_CAMERA, "waveFrequency", STRUM_WAVE_FREQUENCY)
    setShaderFloat(STRUM_WAVE_CAMERA, "laneRadius", STRUM_WAVE_LANE_RADIUS)
    setShaderFloatArray(STRUM_WAVE_CAMERA, "laneCentersA", strumWaveLaneCentersA)
    setShaderFloatArray(STRUM_WAVE_CAMERA, "laneCentersB", strumWaveLaneCentersB)
    setShaderInt(STRUM_WAVE_CAMERA, "laneCount", strumWaveLaneCount)
end

local function buildPulseSteps()
    pulseStepIntensity = {}

    addPulseRange(80, 124, 4, 0.65)
    addPulseRange(128, 316, 4, 0.95)
    addPulseRange(320, 380, 4, 0.55)
    addPulseRange(384, 460, 4, 0.85)
    addPulseRange(464, 524, 4, 0.70)
    addPulseRange(528, 588, 4, 0.95)
    addPulseSteps({592, 596, 600, 604, 608, 612, 616, 620}, 1.15)
    addPulseSteps({624, 628, 632, 636}, 0.80)
end

local function pulseCamera(stepValue)
    local intensity = (pulseStepIntensity[stepValue] or 0) * INTENSITY_MULTIPLIER

    if intensity <= 0 then
        return
    end

    local tweenDuration = math.max((stepCrochet / 1000) * 1.1, 0.06)

    setCameraZoom("camGAME", getCameraZoom("camGAME") + (BASE_GAME_BUMP * intensity))
    setCameraZoom("camHUD", getCameraZoom("camHUD") + (BASE_HUD_BUMP * intensity))
    setCameraZoom("camNOTE", getCameraZoom("camNOTE") + (BASE_NOTE_BUMP * intensity))

    doTweenZoom("i_am_blue_game_zoom", "camGAME", baseGameZoom, tweenDuration, "quadOut")
    doTweenZoom("i_am_blue_hud_zoom", "camHUD", baseHudZoom, tweenDuration, "quadOut")
    doTweenZoom("i_am_blue_note_zoom", "camNOTE", baseNoteZoom, tweenDuration, "quadOut")

    strumWaveAmplitude = math.min(strumWaveAmplitude + (STRUM_WAVE_KICK * intensity), STRUM_WAVE_MAX_AMPLITUDE)
end

function onCreate()
    baseGameZoom = getCameraZoom("camGAME")
    baseHudZoom = getCameraZoom("camHUD")
    baseNoteZoom = getCameraZoom("camNOTE")

    buildPulseSteps()
    callEvent("setCameraBop", "0", "0")

    updateStrumWaveShader()
end

function onUpdatePost(elapsed)
    local safeElapsed = elapsed or 0

    strumWavePhase = strumWavePhase + (safeElapsed * STRUM_WAVE_PHASE_SPEED)
    strumWaveAmplitude = strumWaveAmplitude * math.exp(-safeElapsed * STRUM_WAVE_DECAY_RATE)

    if strumWaveAmplitude < 0.01 then
        strumWaveAmplitude = 0
    end

    updateStrumWaveShader()
end

function onStepHit()
    local stepValue = (curStep or 0) + 1

    pulseCamera(stepValue)
end

function onDestroy()
    if strumWaveShaderActive and removeCameraShader ~= nil then
        removeCameraShader(STRUM_WAVE_CAMERA)
    end
end
