local frostbeat = require("mod_assets/scripts/modcharts/frost_modchart")

local spinSteps = {
    279,
    303,
    312,
    336,
    344,
    368,
    376,
    401,
    409,
    435,
    443,
    467,
    475,
    501,
    509,
    533,
    542,
    567,
    575,
    602
}

local spinIndex = 1
local strumSpinning = true
local strumSideCount = 4

local originalInitStrumsAndNotes = frostbeat.initStrumsAndNotes

local function setSpinAngle(index, angle)
    if setNoteStrumAngleY == nil then
        return
    end

    setNoteStrumAngleY(index, angle)
    setNoteStrumAngleY(index + 4, angle)
end

local function resetStrumSpin()
    spinIndex = 1
    strumSpinning = true

    for i = 0, strumSideCount - 1 do
        setSpinAngle(i, 0)
    end
end

local function getLastStepIndex(index)
    local targetIndex = spinIndex - index

    if targetIndex >= 1 then
        return spinSteps[targetIndex]
    end

    return 0
end

local function updateStrumSpinStep()
    if not strumSpinning then
        resetStrumSpin()
        return
    end

    if spinSteps[#spinSteps] < curStep then
        for i = 0, strumSideCount - 1 do
            setSpinAngle(i, 0)
        end
        strumSpinning = false
        return
    end

    if getLastStepIndex(0) <= curStep and spinIndex < #spinSteps then
        spinIndex = spinIndex + 1
    end

    if spinSteps[1] > curStep then
        return
    end

    for i = 0, strumSideCount - 1 do
        local speed = 1
        local currentStep = getLastStepIndex(0)
        local previousStep = getLastStepIndex(1)
        local stepDelta = currentStep - previousStep

        if stepDelta > 20 then
            speed = 1.8
        end

        if stepDelta <= 0 then
            stepDelta = 1
        end

        local time = ((curStepFloat - previousStep) / stepDelta) - (stepCrochet * 0.0011 * (i / speed))
        local angle = lerp(0, math.pi * 2, clamp(quadOut(time) * speed, 0, 1))
        setSpinAngle(i, angle)
    end
end

function frostbeat.initStrumsAndNotes()
    if originalInitStrumsAndNotes ~= nil then
        originalInitStrumsAndNotes()
    end

    resetStrumSpin()
end

function frostbeat.updateStrumSpin()
    updateStrumSpinStep()
end

return frostbeat
