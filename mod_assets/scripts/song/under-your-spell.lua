local school_stage = require("mod_assets/scripts/components/school_stage")
local school_mechanics = require("mod_assets/scripts/components/school_mechanics")
local school_shader = require("mod_assets/scripts/components/school_shader")

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

function onBeatHit()
    school_mechanics.onBeatHit()
end

function noteMiss(noteData, tag, noteAbstract, isSustainNote)
    school_mechanics.onNoteMiss(noteData, tag, noteAbstract, isSustainNote)
end

function onUpdate(elapsed)
    school_mechanics.onUpdate(elapsed)
end

function goodNoteHit(caculatePos, strumTime, noteData, tag, noteAbstract, isSustainNote)
    school_mechanics.onGoodNote()
end

function onDialoguePreShow()
    school_mechanics.hideHud()
    school_shader.startDialogueBlur(0.0)
end

function onDialogueFinished()
    school_mechanics.tweenInHud()
    school_shader.endDialogueBlur(0.6)
end

function onEnd()
	school_mechanics.onEnd()
    return true
end

function onSoundFinished(tag)
    school_mechanics.onSoundFinished(tag)
end
