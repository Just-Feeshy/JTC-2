local school_stage = require("mod_assets/scripts/components/school_stage")
local school_mechanics = require("mod_assets/scripts/components/school_mechanics")

function generatedStage()
    school_mechanics.onCreate()

    if setOpponentAltAnim ~= nil then
        setOpponentAltAnim("")
    end

    if setCharacterIdleSuffix ~= nil then
        setCharacterIdleSuffix("dad", "")
    end

    school_stage.generatedStage()
end

function onStepHit()
    school_mechanics.onStep(curStep)
end

function onUpdate(elapsed)
    school_mechanics.onUpdate(elapsed)
end

function goodNoteHit(caculatePos, strumTime, noteData, tag, noteAbstract, isSustainNote)
    school_mechanics.onGoodNote()
end
