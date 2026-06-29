local camera = require("mod_assets/scripts/stage/frostbeat/frostbeat_camera")

-- Declarative stage layout: the single source of truth for prop + character placement.
-- The Stage Builder editor reads this table (via the real Lua interpreter) to show exactly
-- what the game loads, and the runtime logic below sources all of its numbers from here.
-- `sprites` is ordered (array) so its order is the stage z-order.
stageLayout = {
    sprites = {
        { name = "funkroadSky", asset = "funkroadSky",
          x = -900, y = -500, scaleX = 1.2, scaleY = 1.2, scrollX = 0.7, scrollY = 0.7 },
        { name = "frostbiteBG", asset = "funkroad", sparrow = true,
          x = -1300, y = -400, scaleX = 1.2, scaleY = 1.2, scrollX = 0.9, scrollY = 0.9,
          anim = { kind = "prefix", name = "move", arg = "funkroad", fps = 24, loop = true } },
        { name = "frostbiteCAR", asset = "car", animate = true,
          x = -178, y = 58, scrollX = 1, scrollY = 1,
          anim = { kind = "timeline", name = "drive", fps = 24, loop = true } },
    },
    -- Character scroll matches how the Stage Editor / engine handle them (getDefaultPos):
    -- dad/bf at 1.0, gf at 0.95. The camera keyframes are authored against these, so the
    -- runtime leaves them at their engine defaults (no forced override).
    characters = {
        dad        = { char = "skater-boi",      x = 64, y = 540, scroll = 1 },
        boyfriend  = { char = "flying BF sings", x = -2017, y = -922.999999999783, scroll = 1 },
        girlfriend = { char = "gf",              x = 400, y = 130, enabled = false, scroll = 0.95 },
    },
}

-- Scenery (sprites in stageLayout) is now built + placed by the engine's shared StageLayoutScene
-- (same code path the Stage Editor preview uses) via setStageLayout(stageLayout) below, so gameplay
-- and the editor place props 1:1. The script keeps only the dynamic/lifecycle logic.

local phaseOneDadBaseX = stageLayout.characters.dad.x
local phaseOneDadBaseY = stageLayout.characters.dad.y
local phaseOneBoyfriendBaseX = stageLayout.characters.boyfriend.x
local phaseOneBoyfriendBaseY = stageLayout.characters.boyfriend.y

stageVocals = { "1_Voices", "2_Voices", "JTC_Voices" }

local stageCharacterChanges = {
    { step = 630, slot = "dad",       char = "dad-car" },
    { step = 906, slot = "boyfriend", char = "flying BF sings gf" },
}
local appliedCharacterChanges = {}
local carTransitionStep = 606
local phaseTwoStep = 630
local daddyTrans = false
local phaseTwoStarted = false

local function destroyCar()
    if not spriteExist("frostbiteCAR") then
        return
    end

    removeSpriteFromStage("frostbiteCAR")
    removeSpriteFromState("frostbiteCAR")
    destroySprite("frostbiteCAR")
end

-- The car sprite + its initial "drive" animation are built by StageLayoutScene (from the
-- stageLayout `anim` spec). The transition/fog symbols are only used by the dynamic logic below,
-- so they're registered here after the shared builder has created the car.
local function addFrostbiteCarExtraAnims()
    if not spriteExist("frostbiteCAR") then
        return
    end
    addAnimationBySymbol("frostbiteCAR", "transition", "car drive and dust", 24, false)
    addAnimationBySymbol("frostbiteCAR", "fog", "car drive and dust", 24, false)
end

local function refreshCarAnimation()
    if not spriteExist("frostbiteCAR") then
        return
    end

    local stepValue = curStep or 0

    if daddyTrans and stepValue < phaseTwoStep then
        setSpritePosition("frostbiteCAR", -186, 41)
        playAnimRaw("frostbiteCAR", "transition", true)
        return
    end

    if stepValue < carTransitionStep + 1 then
        playAnimRaw("frostbiteCAR", "drive", true)
    end
end

local function applyPhaseOneBaseline()
    if spriteExist("dad") then
        setSpritePosition("dad", phaseOneDadBaseX, phaseOneDadBaseY)
    end
    if spriteExist("boyfriend") then
        setSpritePosition("boyfriend", phaseOneBoyfriendBaseX, phaseOneBoyfriendBaseY)
    end
end

function generatedStage()
    daddyTrans = false
    phaseTwoStarted = false

    applyPhaseOneBaseline()

    -- Build + place the scenery via the engine's shared StageLayoutScene (same path the Stage
    -- Editor preview uses), then register the car's extra symbols for the dynamic logic.
    if setStageLayout ~= nil then
        setStageLayout(stageLayout)
    end
    addFrostbiteCarExtraAnims()

    if setStageCameraConfig ~= nil then
        setStageCameraConfig(camera)
    end
end

function onStepHit()
    for i, cc in ipairs(stageCharacterChanges) do
        if not appliedCharacterChanges[i] and curStep ~= nil and curStep >= cc.step then
            appliedCharacterChanges[i] = true
            if callEvent ~= nil then
                callEvent("character change", cc.char, cc.slot)
            end
        end
    end

    if curStep == carTransitionStep then
        daddyTrans = true
    end

    if curStep ~= nil and curStep >= phaseTwoStep and not phaseTwoStarted then
        phaseTwoStarted = true
        destroyCar()
    end
end

function onUpdate(elapsed)
    if phaseTwoStarted or not spriteExist("frostbiteCAR") then
        return
    end

    local step = curStep or 0

    -- The car is a normal world object at its layout position; the camera frames it (exactly
    -- like the Stage Editor shows it). No per-frame repositioning — that's what made it jump
    -- around the screen as the camera panned/zoomed.
    local carAnimDone = sprAnimFinished("frostbiteCAR")

    if carAnimDone and daddyTrans then
        stopAnim("frostbiteCAR")
        playAnimRaw("frostbiteCAR", "transition")
        setSpritePosition("frostbiteCAR", 775, 269)
        daddyTrans = false
    elseif carAnimDone and step < carTransitionStep + 1 then
        playAnimRaw("frostbiteCAR", "drive")
    end
end

function onResume()
    refreshCarAnimation()
end
