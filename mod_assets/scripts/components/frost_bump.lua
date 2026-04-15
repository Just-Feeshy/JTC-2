local frost_bump = {}

local pulseStepIntensity = {}
local lastPulseStep = -1
local INTENSITY_MULTIPLIER = 1.5

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

    addPulseSteps({
        187, 228, 294, 304, 339, 370, 372, 397, 438, 445, 463, 504,
        518, 520, 545, 578, 584, 633, 652, 656, 689, 693, 734, 738,
        775, 800, 837, 870, 1199, 1207, 1302, 1347, 1483, 1528, 1532,
        1594, 1639
    }, 0.78)

    addPulseSteps({
        154, 158, 191, 195, 199, 224, 232, 257, 265, 298, 331, 364,
        376, 405, 409, 430, 442, 512, 551, 553, 586, 660, 726, 792,
        804, 840, 1162, 1170, 1203, 1236, 1240, 1269, 1277, 1310,
        1343, 1376, 1384, 1409, 1417, 1450, 1454, 1458, 1487, 1491,
        1520, 1524, 1561, 1565, 1598, 1602, 1631, 1635, 1664, 1744,
        1777, 1810
    }, 1.08)
end

local function pulseCamera(stepValue)
    local intensity = (pulseStepIntensity[stepValue] or 0) * INTENSITY_MULTIPLIER

    if intensity <= 0 then
        return
    end

    if triggerGameplayCameraBop ~= nil then
        triggerGameplayCameraBop(intensity)
    end
end

function frost_bump.reset()
    lastPulseStep = -1
    buildPulseSteps()
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
