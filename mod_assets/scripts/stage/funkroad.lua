--variables
local skaterboi = nil

local beatSection = 0

local a = 0
local constant = 2
local size = 20

local allStrumsX = {}
local allStrumsY = {}

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

local daddyIsHere = false

--functions
function generatedStage()
    createSprite("frostbiteCAR")
    setSpritePosition("frostbiteCAR", 50, 0)
    compileSpriteSheet("frostbiteCAR", 'daddycar', "sparrow")
    playAnimationByPrefix("frostbiteCAR", 'drive', "daddycar", 24, true)
    setScrollFactorToSprite("frostbiteCAR", 1.0, 0.9)
    scaleSprite("frostbiteCAR", 0.7, 0.7)
    insertSpriteToStage(getSpriteIndexFromStage("dad"), "frostbiteCAR")

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

    skaterboi = require("mod_assets/scripts/modules/character")
    skaterboi.create("skater-boi-player", "skater-boi-player", 600, 100, true)
    skaterboi.initSing(jtcStrumAnims)
end

function updateCharacter()
    if skaterboi ~= nil and daddyIsHere then
        skaterboi.dance()
    end
end

function onStepHit()
    if curStep == 630 and not daddyIsHere then
        callEvent("character change", "dad-car", "dad")
        addSpriteToStage("skater-boi-player")
        daddyIsHere = true
    end

    if curStep == 631 then
        removeSpriteToStage("boyfriend")
        insertSpriteToStage(getSpriteIndexFromStage("skater-boi-player") + 1, "boyfriend")
    end

    if curStep == 147 and beatSection == 0 then
        callEvent("bump per beat", "2", "1.05")
        beatSection = beatSection + 1
    end

    if(curStep == 210 and beatSection == 1) then
        callEvent("bump per beat", "1", "1.1")
        beatSection = beatSection + 1
    end

    if(curStep == 475 and beatSection == 2) then
        callEvent("bump per beat", "4", "1")
        beatSection = beatSection + 1
    end
end

function goodNoteHit(caculatePos, strumTime, noteData, tag, noteAbstract, isSustainNote)
    if skaterboi ~= nil and daddyIsHere then
        if tag == "joul" or tag == "t" then
            skaterboi.singByNote(noteData, isSustainNote)
        end
    end
end

function onUpdate(elapsed)
    updateCharacter()

    if startedCountdown then
        for i = 0, (totalKeysForStrum * 2) - 1 do
            setNoteStrumPos(i, defaultNoteMovement(i, a), (allStrumsY[i + 1] + (math.sin(a * 4) / constant) * size) - (math.abs(math.sin(getNoteStrumAngleY(i) * 0.5)) * 30))

            local Xdistance = allStrumsX[i + 1] - defaultNoteMovement(i, a)
            local Ydistance = (windowHeight * 0.5) - allStrumsY[i + 1]

            local angle = getOppositeAngle(math.atan(Ydistance / Xdistance))

            setPlayerStrumDirection(i, (math.pi * 0.5) - angle)
        end

        a = a + (elapsed * 0.5) * (curBpm/120)
    end
end

--math functions
function getOppositeAngle(angle)
    if math.floor(angle) <= -1 then
        return math.pi + angle
    end

    return angle
end

function defaultNoteMovement(i, var)
    return allStrumsX[i + 1] + (math.cos(var) * constant) * size
end