local jtc_camera = require("mod_assets/scripts/components/jtc_camera")

local beatSection = 0

local curAnimName = ""
local holdTimer = 0
local multipler = 6.1
local stunned = false
local notDancing = false

local phaseTwo = 643
local daddyIsHere = false
local daddyTrans = false

local secondBaseX = 560
local secondBaseY = 130

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

local jtcOffsets = {
    {191, -44},
    {-61, 61},
    {-75, -229},
    {-68, -15},

    {307, 138},
    {159, 108},
    {-18, -91},
    {5, 23}
}

local function startsWith(value, prefix)
    if type(value) ~= "string" or type(prefix) ~= "string" then
        return false
    end

    return value:sub(1, #prefix) == prefix
end

local function init()
    beatSection = 0
    curAnimName = ""
    holdTimer = 0
    multipler = 6.1
    stunned = false
    notDancing = false
    daddyIsHere = false
    daddyTrans = false
    jtc_camera.reset()
end

local function playAnimation(spriteName, animName)
    if animName == "idle" and notDancing then
        setSpritePosition("second", secondBaseX, secondBaseY)
        notDancing = false
    end

    playAnimRaw(spriteName, animName)
    curAnimName = animName
end

local function cloudIncome()
    if curStep > 614 and curStep < (phaseTwo + 1) then
        local givenTime = (curStepFloat - 614) / ((phaseTwo + 1) - 614)
        local timeLerp = math.min(givenTime, 1)
        local easing = math.pow(math.min(timeLerp, 1), 2)

        setSpritePosition("cloud", (10104 * easing) - 6736, -699 + math.sin(easing * math.pi * 2.0) * 250)
    end
end

function generatedStage()
    init()
    setEndVideo("post.mp4")
    setCountdownPresentation(false, false)
    addSongTrack("gfVocals", "GF_Voices", "extra", 1)
    addSongTrack("jtcVocals", "JTC_Voices", "player", 1, false, "t,joul")
    jtc_camera.hideGameplayUntilStep(12)

    createSprite("frostbiteCAR")
    setSpritePosition("frostbiteCAR", -170, -35)
    createCombinedFrames("frostbiteCAR-frames", "daddycar", "daddycar2", "sparrow", "sparrow")
    addFramesToSprite("frostbiteCAR", "frostbiteCAR-frames")
    addAnimationByPrefix("frostbiteCAR", "transition", "car drive and dust0", 24, false)
    addAnimationByPrefix("frostbiteCAR", "fog", "car drive and dust t", 24, false)
    playAnimationByPrefix("frostbiteCAR", "drive", "daddycar", 24, false)
    setScrollFactorToSprite("frostbiteCAR", 1.0, 0.9)
    insertSpriteToStage(getSpriteIndexFromStage("dad"), "frostbiteCAR")

    createSprite("second")
    setSpritePosition("second", secondBaseX, secondBaseY)
    createCombinedFrames("second-frames", "skater_assets", "skater_miss_notes", "sparrow", "sparrow")
    addFramesToSprite("second", "second-frames")
    addAnimationByPrefix("second", "idle", "skater dance IDLE0", 24, false)
    addAnimationByPrefix("second", "singDOWN", "skater dance DOWN0", 24, false)
    addAnimationByPrefix("second", "singUP", "skater dance UP0", 24, false)
    addAnimationByPrefix("second", "singLEFT", "skater dance LEFT0", 24, false)
    addAnimationByPrefix("second", "singRIGHT", "skater dance RIGHT0", 24, false)
    addAnimationByPrefix("second", "singDOWN miss", "skater dance DOWN miss", 24, false)
    addAnimationByPrefix("second", "singUP miss", "skater dance UP miss", 24, false)
    addAnimationByPrefix("second", "singLEFT miss", "skater dance LEFT miss", 24, false)
    addAnimationByPrefix("second", "singRIGHT miss", "skater dance RIGHT miss", 24, false)
    spriteFlip("second", true, false)
    playAnimation("second", "idle")

    createSprite("cloud")
    setSpritePosition("cloud", 0, 0)
    loadGraphic("cloud", "daddy_transition_cloud")
    scaleSprite("cloud", 2, 2)
    screenCenter("cloud", "y")
    setSpriteX("cloud", -6736)
    addSpriteToState("cloud")

    setupPunchHealth(3)
end

function onStepHit()
    jtc_camera.onStepHit(curStep)

    if curStep == 606 then
        daddyTrans = true
    end

    if curStep == 630 and not daddyIsHere then
        callEvent("character change", "dad-car", "dad")
        removeSpriteFromState("frostbiteCAR")
        destroySprite("frostbiteCAR")
        daddyIsHere = true
    end

    if curStep == 631 then
        insertSpriteToStage("dad")
        addSpriteToStage("second")
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

    if curStep == 903 then
        removeAnimationPrefix("boyfriend", "idle")
        removeAnimationPrefix("boyfriend", "singDOWN")
        removeAnimationPrefix("boyfriend", "singUP")
        removeAnimationPrefix("boyfriend", "singLEFT")
        removeAnimationPrefix("boyfriend", "singRIGHT")

        addAnimationByPrefix("boyfriend", "idle", "flying dance IDLE GF", 24, false)
        addAnimationByPrefix("boyfriend", "singDOWN", "flying dance DOWN GF", 24, false)
        addAnimationByPrefix("boyfriend", "singUP", "flying dance UP GF", 24, false)
        addAnimationByPrefix("boyfriend", "singLEFT", "flying dance LEFT GF", 24, false)
        addAnimationByPrefix("boyfriend", "singRIGHT", "flying dance RIGHT GF", 24, false)
    end

    if curStep == 904 and beatSection == 5 then
        callEvent("bump per beat", "4", "1")
        beatSection = beatSection + 1
    end
end

function goodNoteHit(caculatePos, strumTime, noteData, tag, noteAbstract, isSustainNote)
    if daddyIsHere and (tag == "joul" or tag == "t") then
        playAnimation("second", jtcStrumAnims[noteData + 1])
        setSpritePosition("second", secondBaseX - jtcOffsets[noteData + 1][1], secondBaseY - jtcOffsets[noteData + 1][2])
        notDancing = true
    end
end

function noteMiss(noteData, tag)
    print("Missed note")

    if daddyIsHere and (tag == "joul" or tag == "t") then
        playAnimation("second", jtcStrumAnims[noteData + 1] .. " miss")
        setSpritePosition("second", secondBaseX - jtcOffsets[noteData + 5][1], secondBaseY - jtcOffsets[noteData + 5][2])
        notDancing = true
    end
end

function onUpdate(elapsed)
    if not startedCountdown then
        return
    end

    if startsWith(curAnimName, "sing") then
        holdTimer = holdTimer + elapsed
    end

    if holdTimer > stepCrochet * crochetPitch * multipler then
        playAnimation("second", "idle")
        holdTimer = 0
    end

    if not stunned and not startsWith(curAnimName, "sing") and sprAnimFinished("second") then
        playAnimation("second", "idle")
    end

    if sprAnimFinished("frostbiteCAR") and daddyTrans then
        stopAnim("frostbiteCAR")
        playAnimRaw("frostbiteCAR", "transition")
        setSpritePosition("frostbiteCAR", 241, 81)
        daddyTrans = false
    end

    if sprAnimFinished("frostbiteCAR") and curStep < 607 then
        playAnimRaw("frostbiteCAR", "drive")
    end

    cloudIncome()
end

function setupPunchHealth(amount)
    local punchIcons = {}

    for i = 1, amount do
        local iconX = getSpriteX("healthBarBG") + getSpriteWidth("healthBarBG") + 50
        local iconY = getMidpointY("healthBarBG") - 50

        if spriteExist("punchIcon" .. tostring(i - 1)) then
            local iconHeight = getSpriteHeight("punchIcon0")

            iconX = iconX + (getSpriteWidth("punchIcon" .. tostring(i - 1)) * (i - 1))
            iconY = iconY - (iconHeight * 0.5)
        end

        createSprite("punchIcon" .. i)
        setSpritePosition("punchIcon" .. i, iconX, iconY - 10)
        loadGraphic("punchIcon" .. i, "daddy_fist")
        setSpriteToCamera("punchIcon" .. i, "camHUD")
        scaleSprite("punchIcon" .. i, 0.7, 0.7)
        addSpriteToStage("punchIcon" .. i)
        table.insert(punchIcons, "punchIcon" .. i)
    end

    jtc_camera.registerHiddenSprites(punchIcons)
end
