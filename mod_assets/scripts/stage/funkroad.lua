--variables
local skaterboi = nil

local a = 0
local constant = 2

local allStrumsX = {}
local allStrumsY = {}

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

local daddyIshere = false

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

    skaterboi = require("assets/scripts/modules/character")
    skaterboi.create("skater-boi", "skater-boi", 100, 100)

    removeSpriteToStage("dad")
    scaleSprite("dad", 1.1, 1.1)
    setSpritePosition("dad", -585, 0)
end

function updateCharacter()
    --if skaterboi ~= nil then
    --    skaterboi.dance("idle")
    --end
end

function onUpdate(elapsed)
    updateCharacter()

    if startedCountdown then
        --for i = 0, (totalKeysForStrum - 1) * 2 do
            --print(allStrumsX[1])
            --setNoteStrumPos(i, allStrumsX[1] + (math.cos(a) * constant), allStrumsY[1] + (math.sin(a * 4) / constant))
        --end

        a = a + (elapsed * (curBpm/120))
    end
end