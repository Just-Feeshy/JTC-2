--Modchart for the Frostbeat song in lua.
--Jesus the modchart took almost 400 lines of code.
--Author Feeshy

local a = 0
local constant = 2
local size = 20

local wheelAngle = 0
local AverageSpin = 0
local megaSpin = 0
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

local frost_modchart = {}

local transitionToWheel = { --In steps
    614,
    640,
    652,
    760,
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

--Initialize Strums And Notes Info
function frost_modchart.initStrumsAndNotes()
    allStrumsX = {
        defaultOpponentStrumX0;
        defaultOpponentStrumX1;
        defaultOpponentStrumX2;
        defaultOpponentStrumX3;
        defaultPlayerStrumX0;
        defaultPlayerStrumX1;
        defaultPlayerStrumX2;
        defaultPlayerStrumX3;
    }

    allStrumsY = {
        defaultOpponentStrumY0;
        defaultOpponentStrumY1;
        defaultOpponentStrumY2;
        defaultOpponentStrumY3;
        defaultPlayerStrumY0;
        defaultPlayerStrumY1;
        defaultPlayerStrumY2;
        defaultPlayerStrumY3;
    }

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

--Modchart Section 1
function frost_modchart.sectionOne(elapsed)
    if not wheelIsHere then
        for i = 0, 7 do
            setNoteStrumPos(i, defaultNoteMovement(i, a), (allStrumsY[i + 1] + (math.sin(a * 4) / constant) * size) - (math.abs(math.sin(getNoteStrumAngleY(i) * 0.5)) * 30))

            local Xdistance = allStrumsX[i + 1] - defaultNoteMovement(i, a)
            local Ydistance = (windowHeight * 0.5) - allStrumsY[i + 1]

            local angle = getOppositeAngle(math.atan(Ydistance / Xdistance))

            setNoteDirection(i, (math.pi * 0.5) - angle)
        end

        a = a + (elapsed * 0.5) * (curBpm / 120)
    end
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
        bounceNormal(bounceStrength, 1)
    end
end

function frost_modchart.sectionTwo_HELL(elapsed)
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

    if transitionToWheel[2] < curStep then
        for i = 1, 4 do
            local xNote = getNoteScreenCenter((i - 1) + 4, "X") - (noteSwagWidth + bounceWheel[i]) * math.cos(wheelAngle + noteWheelAngle[i])
            local yNote = getNoteScreenCenter((i - 1) + 4, "Y") + (noteSwagWidth + bounceWheel[i]) * math.sin(wheelAngle + noteWheelAngle[i])

            setNoteStrumPos((i - 1) + 4, xNote, yNote)
            setNoteDirection((i - 1) + 4, wheelAngle + noteWheelAngle[i] - (math.pi * 0.5))
            setNoteStrumAngle((i - 1) + 4, -wheelAngle)

            if transitionToWheel[3] > curStep then
                local givenTime = (curStepFloat - transitionToWheel[2]) / (transitionToWheel[3] - transitionToWheel[2])
                local timeLerp = quadOut(givenTime)

                wheelAngle = lerp(0, math.pi * 2, timeLerp)
                setCameraZoom("camNOTE", 1 + parabola(timeLerp, 2) * 0.25)
            else
                AverageSpin = AverageSpin + (elapsed * elapsed * math.pi * (curBpm / 120) * (math.max(bounceStrength * 0.1, 1)))
                wheelAngle = AverageSpin + megaSpin

                if not wheelFinished then
                    wheelFinished = true
                end
            end
        end
    end

    if wheelFinished then
        bounceDaWheel(bounceStrength, -1)
    end

    if transitionToWheel[4] < curStep and transitionToWheel[5] > curStep then
        local givenTime = (curStepFloat - transitionToWheel[4]) / (transitionToWheel[5] - transitionToWheel[4])
        local timeLerp = quadOut(givenTime)

        megaSpin = lerp(0, math.pi * 2, timeLerp)
        bounceStrength = lerp(10, 18, timeLerp)

        setCameraZoom("camNOTE", 1 + parabola(timeLerp, 2) * 0.25)
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

function bounceNormal(strength, direction)
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

function getOppositeAngle(angle)
    if math.floor(angle) <= -1 then
        return math.pi + angle
    end

    return angle
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

return frost_modchart
