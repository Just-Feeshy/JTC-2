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

    print("display")
end

function onUpdateAfterCountdown(elapsed)
    --for i = 0, (totalKeysForStrum - 1) * 2 do
        --print(allStrumsX[1])
        --setNoteStrumPos(i, allStrumsX[1] + (math.cos(a) * constant), allStrumsY[1] + (math.sin(a * 4) / constant))
    --end
    
    a = a + (elapsed * (curBpm/120))
end