-- First main game lua test of this "engine" to see how well it can handle lua modchart's and general scripting.
-- This is not the most organized script setup, but Frostbeat is the best song to test the "simple stuff."

--variables
local frost_modchart = nil
local skaterboi = nil
local skaterboi_extra = nil

local beatSection = 0

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

local daddyIsHere = false

--events
function generatedStage()
    createSprite("frostbiteCAR")
    setSpritePosition("frostbiteCAR", 50, 0)
    compileSpriteSheet("frostbiteCAR", 'daddycar', "sparrow")
    playAnimationByPrefix("frostbiteCAR", 'drive', "daddycar", 24, true)
    setScrollFactorToSprite("frostbiteCAR", 1.0, 0.9)
    scaleSprite("frostbiteCAR", 0.7, 0.7)
    insertSpriteToStage(getSpriteIndexFromStage("dad"), "frostbiteCAR")

    setupPunchHealth(3)

    skaterboi = require("mod_assets/scripts/modules/character")
    skaterboi.create("skater-boi-player", "skater-boi-player", 650, 100, true)
    skaterboi.initSing(jtcStrumAnims)

    --skaterboi_extra = require("mod_assets/scripts/modules/character")
    --skaterboi_extra.create()

    frost_modchart = require("mod_assets/scripts/modcharts/frost_modchart")
    frost_modchart.initStrumsAndNotes()
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

        removeSpriteFromState("frostbiteCAR")
        destroySprite("frostbiteCAR")

        daddyIsHere = true
    end

    if curStep == 631 then
        removeSpriteToStage("boyfriend")
        insertSpriteToStage(getSpriteIndexFromStage("skater-boi-player") + 1, "boyfriend")
    end

    if curStep == 147 and beatSection == 0 then
        callEvent("bump per beat", "2", "1.025")
        beatSection = beatSection + 1
    end

    if curStep == 210 and beatSection == 1 then
        callEvent("bump per beat", "1", "1.05")
        beatSection = beatSection + 1
    end

    if curStep == 475 and beatSection == 2 then
        callEvent("bump per beat", "4", "1")
        beatSection = beatSection + 1
    end

    if curStep == 652 and beatSection == 3 then
        callEvent("bump per beat", "2", "1.025")
        beatSection = beatSection + 1
    end

    if curStep == 772 and beatSection == 4 then
        callEvent("bump per beat", "1", "1.05")
        beatSection = beatSection + 1
    end

    if curStep == 904 and beatSection == 5 then
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
    if startedCountdown then

        --Modchart Section 1
        frost_modchart.sectionOne(elapsed)

        --Modchart Section 2
        if difficulty == 2 then
            frost_modchart.sectionTwo_HELL(elapsed)
        else
            frost_modchart.sectionTwo_REGULAR()
        end
    end

    updateCharacter()
end

--functions
function setupPunchHealth(amount)
    for i = 1, amount do
        local iconX = getSpriteX("healthBarBG") + getSpriteWidth("healthBarBG") + 50
        local iconY = getMidpointY("healthBarBG")

        print("punchIcon" + tostring(i - 1))

        --if spriteExist("punchIcon" + tostring(i - 1)) then
            --iconX = iconX + (getSpriteWidth("punchIcon" + tostring(i - 1)) * (i - 1))
            --iconY = iconY - (getSpriteHeight("punchIcon" + tostring(i - 1)) * 0.5)
        --end

        --createSprite("punchIcon" + i)
        --setSpritePosition("punchIcon" + i, iconX, iconY - 10)
        --loadGraphic("punchIcon" + i, "daddy_fist")
        --setSpriteToCamera("punchIcon" + i, "camHUD")
        --addSpriteToStage("punchIcon" + i)
    end
end