--imports
local luaCharacter = require("/assets/scripts/extraCharacterScript")

--variables
local a = 0
local constant = 2

local allStrumsX = {}
local allStrumsY = {}

local skaterJoul = nil

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

--functions
function generatedStage()
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

    skaterJoul = luaCharacter.new("skater-boi", "skater-boi", 100, 100)

    removeSpriteToStage("dad")
    scaleSprite("dad", 1.1, 1.1)
    setSpritePosition("dad", -585, 0)
end

function onUpdateAfterCountdown(elapsed)
    --for i = 0, (totalKeysForStrum - 1) * 2 do
        --print(allStrumsX[1])
        --setNoteStrumPos(i, allStrumsX[1] + (math.cos(a) * constant), allStrumsY[1] + (math.sin(a * 4) / constant))
    --end
    
    a = a + (elapsed * (curBpm/120))
end

function updateCharacter()
    if skaterJoul ~= nil then
        skaterJoul.dance("idle")
    end
end

function onUpdate(elapsed)
    updateCharacter()
end