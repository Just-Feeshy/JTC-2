local pulseStepIntensity = {}
local baseGameZoom = 1
local baseHudZoom = 1
local baseNoteZoom = 1

local INTENSITY_MULTIPLIER = 1.5
local BASE_GAME_BUMP = 0.015
local BASE_HUD_BUMP = 0.03
local BASE_NOTE_BUMP = 0.03

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
end

function onCreate()
    baseGameZoom = getCameraZoom("camGAME")
    baseHudZoom = getCameraZoom("camHUD")
    baseNoteZoom = getCameraZoom("camNOTE")

    buildPulseSteps()
    callEvent("setCameraBop", "0", "0")
end

function onStepHit()
    local stepValue = (curStep or 0) + 1

    pulseCamera(stepValue)
end
