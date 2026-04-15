local frost_bump = {}

local pulseStepIntensity = {}
local lastPulseStep = -1
local bumpSuppressed = false
local suppressUntilStep = nil

local function addPulseStep(stepValue, intensity)
    pulseStepIntensity[stepValue] = intensity
end

local function addPulseSteps(steps, intensity)
    if steps == nil then
        return
    end

    for _, stepValue in ipairs(steps) do
        addPulseStep(stepValue, intensity)
    end
end

local function buildPulseSteps()
    pulseStepIntensity = {}

    local index = 1
    for i = 150, 216, 4 do
	    pulseStepIntensity[index] = i
	    index = index + 1
    end
    addPulseSteps(pulseStepIntensity, 0.67)

    index = 1
    for i = 216, 480, 4 do
	    pulseStepIntensity[index] = i
	    index = index + 1
    end
    addPulseSteps(pulseStepIntensity, 0.89)
end

local function pulseCamera(stepValue)
    local currentStep = curStep or stepValue or 0

    if bumpSuppressed and (suppressUntilStep == nil or currentStep < suppressUntilStep) then
        return
    end

    local intensity = (pulseStepIntensity[stepValue] or 0)

    if intensity <= 0 then
        return
    end

    if triggerGameplayCameraBop ~= nil then
        triggerGameplayCameraBop(intensity)
    end
end

function frost_bump.reset()
    lastPulseStep = -1
    bumpSuppressed = false
    suppressUntilStep = nil
    buildPulseSteps()
end

function frost_bump.setSuppressed(value, untilStep)
    bumpSuppressed = value == true
    suppressUntilStep = untilStep
end

function frost_bump.onUpdate()
    if curStepFloat == nil then
        return
    end

    local currentPulseStep = math.floor(curStepFloat)

    if currentPulseStep < 0 or currentPulseStep <= lastPulseStep then
        return
    end

    local startPulseStep = math.max(lastPulseStep + 1, 0)

    for pulseStep = startPulseStep, currentPulseStep do
        pulseCamera(pulseStep)
    end

    lastPulseStep = currentPulseStep
end

return frost_bump
