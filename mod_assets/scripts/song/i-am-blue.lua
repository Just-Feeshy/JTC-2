local jtc_camera = require("mod_assets/scripts/components/jtc_camera")
local frost_modchart = {}
local pulseStepIntensity = {}
local strumWavePulse = 0
local strumWaveTime = 0
local strumWaveSeed = 0
local strumWaveShaderActive = false
local strumWaveShaderInitialized = false
local strumWaveLaneCount = 8
local strumWaveLaneCentersA = {0, 0, 0, 0}
local strumWaveLaneCentersB = {0, 0, 0, 0}
local bounceStoppedAtOutro = false

local INTENSITY_MULTIPLIER = 1.5
local STRUM_WAVE_SHADER = "i_am_blue_strum_wave"
local STRUM_WAVE_CAMERA = "camNoteSustain"
local STRUM_WAVE_SIZE = 160 * 0.7
local STRUM_WAVE_LANE_RADIUS = STRUM_WAVE_SIZE * 1.2
local STRUM_WAVE_TRAVEL_SPEED = 160
local STRUM_WAVE_LENGTH_MIN = STRUM_WAVE_SIZE * 1.5
local STRUM_WAVE_LENGTH_MAX = STRUM_WAVE_SIZE * 3.0
local STRUM_WAVE_DECAY_RATE = 4.2
local STRUM_WAVE_MAX_PULSE = 36
local STRUM_WAVE_KICK = 18
local FOCUS_HOLD_ZOOM = 0.92
local FOCUS_SWITCH_ZOOM_OUT = 0.67
local FOCUS_SWITCH_OUT_DURATION_STEPS = 2
local FOCUS_SWITCH_IN_DURATION_STEPS = 4
local FOCUS_SWITCH_DELAY = 0.045
local FOCUS_FOLLOW_LERP = 0.28

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
    updateStrumWaveLaneCenters()
    setShaderFloat(STRUM_WAVE_CAMERA, "waveAmplitude", strumWavePulse)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveTime", strumWaveTime)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveTravelSpeed", STRUM_WAVE_TRAVEL_SPEED)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveSeed", strumWaveSeed)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveLengthMin", STRUM_WAVE_LENGTH_MIN)
    setShaderFloat(STRUM_WAVE_CAMERA, "waveLengthMax", STRUM_WAVE_LENGTH_MAX)
    setShaderFloat(STRUM_WAVE_CAMERA, "laneRadius", STRUM_WAVE_LANE_RADIUS)
    setShaderFloat4(STRUM_WAVE_CAMERA, "laneCentersA",
        strumWaveLaneCentersA[1], strumWaveLaneCentersA[2], strumWaveLaneCentersA[3], strumWaveLaneCentersA[4])
    setShaderFloat4(STRUM_WAVE_CAMERA, "laneCentersB",
        strumWaveLaneCentersB[1], strumWaveLaneCentersB[2], strumWaveLaneCentersB[3], strumWaveLaneCentersB[4])
    setShaderInt(STRUM_WAVE_CAMERA, "laneCount", strumWaveLaneCount)
end

local function buildPulseSteps()
    pulseStepIntensity = {}

    addPulseRange(64, 124, 4, 0.65)
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

    if triggerGameplayCameraBop ~= nil then
        triggerGameplayCameraBop(intensity)
    end

    strumWavePulse = math.min(strumWavePulse + (STRUM_WAVE_KICK * intensity), STRUM_WAVE_MAX_PULSE)
    strumWaveTime = 0
    strumWaveSeed = strumWaveSeed + 1
end

function onCreate()
    frost_modchart = {}

    buildPulseSteps()
    jtc_camera.reset()
    jtc_camera.configureFocusSwitch({
        enabled = true,
        holdZoom = FOCUS_HOLD_ZOOM,
        switchZoomOut = FOCUS_SWITCH_ZOOM_OUT,
        switchOutDurationSteps = FOCUS_SWITCH_OUT_DURATION_STEPS,
        switchInDurationSteps = FOCUS_SWITCH_IN_DURATION_STEPS,
        switchDelay = FOCUS_SWITCH_DELAY,
        followLerp = FOCUS_FOLLOW_LERP
    })

	frost_modchart = require("mod_assets/scripts/modcharts/frostbeat") or {}
	if frost_modchart.initStrumsAndNotes ~= nil then
		frost_modchart.initStrumsAndNotes()
	end

	ensureStrumWaveShader()
	updateStrumWaveShader()
end

function onUpdate(elapsed)
    local safeElapsed = elapsed or 0

    jtc_camera.onUpdate(safeElapsed)

    if strumWavePulse > 0 then
        strumWaveTime = strumWaveTime + safeElapsed
        strumWavePulse = strumWavePulse * math.exp(-safeElapsed * STRUM_WAVE_DECAY_RATE)
    end

    if strumWavePulse < 0.01 then
        strumWavePulse = 0
        strumWaveTime = 0
    end

	if curStep >= 256 and curStep < 636 then
		frost_modchart.applyNormalBounce(9, 1)
		bounceStoppedAtOutro = false
	elseif not bounceStoppedAtOutro and frost_modchart.resetNormalStrums ~= nil then
		frost_modchart.resetNormalStrums()
		bounceStoppedAtOutro = true
	end

	ensureStrumWaveShader()

    if strumWaveShaderActive then
        updateStrumWaveShader()
    end
end

function onStepHit()
    local stepValue = (curStep or 0) + 1

    pulseCamera(stepValue)
end

function onResume()
    strumWavePulse = math.max(strumWavePulse, STRUM_WAVE_KICK)
    strumWaveTime = 0
end

function onPause()
end

function whenEventTriggered(skill, value, value2)
    jtc_camera.whenEventTriggered(skill, value, value2)
end

function onDestroy()
    if strumWaveShaderActive and removeCameraShader ~= nil then
        removeCameraShader(STRUM_WAVE_CAMERA)
    end
end
