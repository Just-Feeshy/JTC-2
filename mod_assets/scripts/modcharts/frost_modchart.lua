--Modchart for the Frostbeat song in lua.
--Jesus the modchart took almost 400 lines of code.
--Author Feeshy

local a = 0
local constant = 2
local size = 20

local wheelAngle = 0
local AverageSpin = 0
local bounceStrength = 10

local allStrumsX = {}
local allStrumsY = {}

local allStrumsX2 = {}
local allStrumsY2 = {}

local noteWheelOffsetX = {}
local noteWheelOffsetY = {}
local noteWheelAngle = {}

local wheelIsHere = false
local wheelFinished = false

local noteSwagWidth = 160 * 0.7
local sectionTwoHellTransitionSlowdown = 1
local sectionTwoHellWheelSpinSlowdown = 410
local lastSectionTwoHellStepFloat = nil
local sectionTwoHellSpinInitialized = false

local frost_modchart = {}

local transitionToWheel = { --In steps
    134,
    164,
    216,
    286,
    772,
    904,
    1661,
    1827
}

local bounceWheel = {
    0,
    0,
    0,
    0
}

local spinWheel = {
    0,
    0,
    0,
    0
}

local function cacheStrumPositions()
    for lane = 0, 7 do
        local x = nil
        local y = nil

        if getNotePosX ~= nil then
            x = getNotePosX(lane)
        end

        if getNotePosY ~= nil then
            y = getNotePosY(lane)
        end

        if x == nil then
            if lane < 4 then
                x = _G["defaultOpponentStrumX" .. tostring(lane)]
            else
                x = _G["defaultPlayerStrumX" .. tostring(lane - 4)]
            end
        end

        if y == nil then
            if lane < 4 then
                y = _G["defaultOpponentStrumY" .. tostring(lane)]
            else
                y = _G["defaultPlayerStrumY" .. tostring(lane - 4)]
            end
        end

        allStrumsX[lane + 1] = x
        allStrumsY[lane + 1] = y
    end
end

local function ensureStrumPositions()
    if allStrumsX[1] == nil or allStrumsY[1] == nil or allStrumsX[8] == nil or allStrumsY[8] == nil then
        cacheStrumPositions()
    end

    return allStrumsX[1] ~= nil and allStrumsY[1] ~= nil and allStrumsX[8] ~= nil and allStrumsY[8] ~= nil
end

--Initialize Strums And Notes Info
function frost_modchart.initStrumsAndNotes()
    allStrumsX = {}
    allStrumsY = {}
    cacheStrumPositions()
    lastSectionTwoHellStepFloat = nil
    sectionTwoHellSpinInitialized = false
    AverageSpin = 0
    wheelAngle = 0

    noteWheelOffsetX = {
        -noteSwagWidth;
        0;
        0;
        noteSwagWidth;
    }

    noteWheelOffsetY = {
        0;
        noteSwagWidth;
        -noteSwagWidth;
        0;
    }

    noteWheelAngle = {
        0,
        math.pi * 0.5,
        (3 * math.pi) * 0.5,
        math.pi
    }
end

local function consumeSectionTwoHellStepDelta()
    local stepValue = curStepFloat

    if stepValue == nil then
        stepValue = curStep or 0
    end

    if type(stepValue) ~= "number" then
        stepValue = 0
    end

    if lastSectionTwoHellStepFloat == nil or stepValue < lastSectionTwoHellStepFloat then
        lastSectionTwoHellStepFloat = stepValue
        return 0
    end

    local delta = stepValue - lastSectionTwoHellStepFloat
    lastSectionTwoHellStepFloat = stepValue
    return delta
end

local function getSectionTwoHellSpinSlowdown()
    return math.max(sectionTwoHellWheelSpinSlowdown, 1)
end

--Modchart Section 2
function frost_modchart.sectionTwo_REGULAR()
    if transitionToWheel[1] < curStep and transitionToWheel[2] > curStep then
        for i = 4, 1, -1 do
            local givenTime = (curStepFloat - transitionToWheel[1]) / (transitionToWheel[2] - transitionToWheel[1])
            local timeLerp = givenTime + (stepCrochet * 0.0011 * i) * math.min(givenTime, 1)
            local easing = frost_modchart.smootherStep(math.min(timeLerp, 1))

            if not wheelIsHere then
                allStrumsX2[i] = getNotePosX(i - 1)
                allStrumsY2[i] = getNotePosY(i - 1)
                allStrumsX2[i + 4] = getNotePosX((i - 1) + 4)
                allStrumsY2[i + 4] = getNotePosY((i - 1) + 4)
            end

            setNoteStrumPos(i - 1,
                swirlerpX(allStrumsX2[i], allStrumsX[i], easing),
                swirlerpY(allStrumsY2[i], allStrumsY[i], easing)
            )

            setNoteStrumPos((i - 1) + 4,
                swirlerpX(allStrumsX2[i + 4], allStrumsX[i + 4], easing),
                swirlerpY(allStrumsY2[i + 4], allStrumsY[i + 4], easing)
            )

            if not wheelIsHere then
                setNoteDirection(i - 1, 0)
                setNoteDirection((i - 1) + 4, 0)
            end
        end

        wheelIsHere = true
    end

    if transitionToWheel[2] < curStep and transitionToWheel[8] > curStep then
        for i = 1, 4 do
            setNoteStrumPos(i - 1,
                allStrumsX[i],
                allStrumsY[i] - bounceWheel[i]
            )

            setNoteStrumPos((i - 1) + 4,
                allStrumsX[i + 4],
                allStrumsY[i + 4] - bounceWheel[i]
            )
        end

        if not wheelFinished then
            wheelFinished = true
        end
    end

    if transitionToWheel[4] < curStep and transitionToWheel[5] > curStep then
        local givenTime = (curStepFloat - transitionToWheel[4]) / (transitionToWheel[5] - transitionToWheel[4])
        local timeLerp = quadOut(givenTime)

        bounceStrength = lerp(10, 18, timeLerp)
    end

    if transitionToWheel[5] < curStep and transitionToWheel[6] > curStep then
        local givenTime = (curStepFloat - transitionToWheel[5]) / (transitionToWheel[6] - transitionToWheel[5])
        local timeLerp = quadOut(givenTime)

        bounceStrength = lerp(18, 10, timeLerp)
    end

    if transitionToWheel[7] < curStep and transitionToWheel[8] > curStep then
        local givenTime = (curStepFloat - transitionToWheel[7]) / (transitionToWheel[8] - transitionToWheel[7])
        local timeLerp = quadOut(givenTime)

        bounceStrength = lerp(10, 0, timeLerp)
    end

    if wheelFinished then
        frost_modchart.bounceNormal(bounceStrength, 1)
    end
end

function frost_modchart.sectionTwo_HELL(elapsed)
    local stepDelta = consumeSectionTwoHellStepDelta()
    local hellTransitionEnd = transitionToWheel[1] + ((transitionToWheel[2] - transitionToWheel[1]) * (1 / sectionTwoHellTransitionSlowdown))
    local hellSpinIntroStart = hellTransitionEnd

    if transitionToWheel[1] < curStepFloat and hellTransitionEnd > curStepFloat then
        for i = 4, 1, -1 do
            local givenTime = (curStepFloat - transitionToWheel[1]) / (hellTransitionEnd - transitionToWheel[1])
            local timeLerp = givenTime + (stepCrochet * 0.0011 * i) * math.min(givenTime, 1)
            local easing = frost_modchart.smootherStep(math.min(timeLerp, 1))

            if not wheelIsHere then
                allStrumsX2[i] = getNotePosX(i - 1)
                allStrumsY2[i] = getNotePosY(i - 1)
                allStrumsX2[i + 4] = getNotePosX((i - 1) + 4)
                allStrumsY2[i + 4] = getNotePosY((i - 1) + 4)
            end

            setNoteStrumPos(i - 1,
                swirlerpX(allStrumsX2[i], -noteSwagWidth, easing),
                swirlerpY(allStrumsY2[i], windowHeight + noteSwagWidth, easing)
            )

            setNoteStrumPos((i - 1) + 4,
                swirlerpX(allStrumsX2[i + 4], getNoteScreenCenter((i - 1) + 4, "X") + noteWheelOffsetX[i], easing),
                swirlerpY(allStrumsY2[i + 4], getNoteScreenCenter((i - 1) + 4, "Y") + noteWheelOffsetY[i], easing)
            )
        end

        wheelIsHere = true
    end

    if hellSpinIntroStart < curStepFloat then
        local currentWheelAngle = wheelAngle

        if not sectionTwoHellSpinInitialized then
            AverageSpin = wheelAngle
            sectionTwoHellSpinInitialized = true
        end

        AverageSpin = AverageSpin + (stepDelta * 0.5 * math.pi * (curBpm / 120) * (1 / getSectionTwoHellSpinSlowdown()))
        currentWheelAngle = AverageSpin

        if not wheelFinished then
            wheelFinished = true
        end

        wheelAngle = currentWheelAngle

        for i = 1, 4 do
            local xNote = getNoteScreenCenter((i - 1) + 4, "X") - (noteSwagWidth + bounceWheel[i]) * math.cos(currentWheelAngle + noteWheelAngle[i])
            local yNote = getNoteScreenCenter((i - 1) + 4, "Y") + (noteSwagWidth + bounceWheel[i]) * math.sin(currentWheelAngle + noteWheelAngle[i])

            setNoteStrumPos((i - 1) + 4, xNote, yNote)
            setNoteDirection((i - 1) + 4, currentWheelAngle + noteWheelAngle[i] - (math.pi * 0.5))
            setNoteStrumAngle((i - 1) + 4, radiansToDegrees(-currentWheelAngle))
        end
    end

    if transitionToWheel[3] < curStep and transitionToWheel[5] > curStep then
	bounceDaWheel(18, 1)
    end
end

--Helper Functions
function bounceDaWheel(strength, d)
    local curBeatM = curBeat * 2
    local curBeatFloatM = curBeatFloat * 2

    if curBeatM % 2 == 0 then
        local givenTime = (curBeatFloatM - curBeatM) / ((curBeatM + 1) - curBeatM)

        if curBeatM % 4 == 0 then
            for i = 0, 3, 3 do
                local direction = 1

                if i > 1 == 0 then
                    direction = d
                end

                bounceWheel[i + 1] = lerp(0, strength * direction, parabola(math.min(givenTime, 1), 3))
            end

            return;
        end

        for i = 1, 2 do
            local direction = 1

            if i > 1 == 0 then
                direction = d
            end

            bounceWheel[i + 1] = lerp(0, strength * direction, parabola(math.min(givenTime, 1), 3))
        end
    else
        for i = 0, 3 do
            bounceWheel[i + 1] = 0
        end
    end
end

function spinDaWheel(strength, d)
    local curBeatM = curBeat * 2
    local curBeatFloatM = curBeatFloat * 2

    if curBeatM % 2 == 0 then
        local givenTime = (curBeatFloatM - curBeatM) / ((curBeatM + 1) - curBeatM)

        if curBeatM % 4 == 0 then
            for i = 0, 3, 3 do
                local direction = 1

                if i > 1 == 0 then
                    direction = d
                end

                spinWheel[i + 1] = lerp(0, strength * direction, parabola(math.min(givenTime, 1), 3))
            end

            return;
        end

        for i = 1, 2 do
            local direction = 1

            if i > 1 == 0 then
                direction = d
            end

            spinWheel[i + 1] = lerp(0, strength * direction, parabola(math.min(givenTime, 1), 3))
        end
    else
        for i = 0, 3 do
            spinWheel[i + 1] = 0
        end
    end
end

function frost_modchart.bounceNormal(strength, direction)
    local curBeatM = curBeat * 2
    local curBeatFloatM = curBeatFloat * 2

    if curBeatM % 2 == 0 then
        local givenTime = (curBeatFloatM - curBeatM) / ((curBeatM + 1) - curBeatM)

        if curBeatM % 4 == 0 then
            for i = 0, 2, 2 do
                bounceWheel[i + 1] = lerp(0, strength * direction, parabola(math.min(givenTime, 1), 3))
            end

            return;
        end

        for i = 1, 3, 2 do
            bounceWheel[i + 1] = lerp(0, strength * direction, parabola(math.min(givenTime, 1), 3))
        end
    else
        for i = 0, 3 do
            bounceWheel[i + 1] = 0
        end
    end
end

function frost_modchart.applyNormalBounce(strength, direction)
    if not ensureStrumPositions() then
        return
    end

    frost_modchart.bounceNormal(strength, direction)

    for i = 1, 4 do
        setNoteStrumPos(i - 1, allStrumsX[i], allStrumsY[i] - bounceWheel[i])
        setNoteStrumPos((i - 1) + 4, allStrumsX[i + 4], allStrumsY[i + 4] - bounceWheel[i])
        setNoteDirection(i - 1, 0)
        setNoteDirection((i - 1) + 4, 0)
    end
end

function frost_modchart.resetNormalStrums()
    if not ensureStrumPositions() then
        return
    end

    for i = 1, 4 do
        bounceWheel[i] = 0
        setNoteStrumPos(i - 1, allStrumsX[i], allStrumsY[i])
        setNoteStrumPos((i - 1) + 4, allStrumsX[i + 4], allStrumsY[i + 4])
        setNoteDirection(i - 1, 0)
        setNoteDirection((i - 1) + 4, 0)
        setNoteStrumAngle(i - 1, 0)
        setNoteStrumAngle((i - 1) + 4, 0)
    end
end

function defaultNoteMovement(i, var)
    return allStrumsX[i + 1] + (math.cos(var) * constant) * size
end

--Math Functions
function parabola(t, k)
    return (4 * t * (1 - t)) ^ k
end

function quadOut(t)
    return -t * (t - 2)
end

function frost_modchart.smootherStep(t)
    return t * t * t * (t * (t * 6 - 15) + 10);
end

function clamp(value, min, max)
    if value < min then
        return min
    elseif value > max then
        return max
    end

    return value
end

function swirlerpX(p, q, t)
    local circleTime = 2 * math.pi - (t * (2 * math.pi))
    local degrees90 = math.pi * 0.5 --In radians

    return q + ((1 - math.cos(circleTime - degrees90) * (1 + t)) * circleTime * (p - q)) / (math.pi * 2)
end

function swirlerpY(p, q, t)
    local circleTime = 2 * math.pi - (t * (2 * math.pi))
    local degrees90 = math.pi * 0.5 --In radians

    return q + (math.sin(circleTime - degrees90) * (1 + t) * -circleTime * (p - q)) / (math.pi * 2)
end

function lerp(value1, value2, ratio)
    return value1 + ratio * (value2 - value1)
end

function radiansToDegrees(value)
    return value * (180 / math.pi)
end

return frost_modchart
