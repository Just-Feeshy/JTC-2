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
local baseFunkroadCameraX = 785
local baseFunkroadCameraY = 458.5
local baseFunkroadCameraZoom = 0.5
local introNoteRevealStartStep = 36
local introNoteRevealEndStep = 54
local introBaseCameraStep = 40
local introClearStep = 50
local introBaseCameraZoom = 0.9
local introClearDuration = 0.35
local introNoteRevealLanePairs = 4
local baseFrostbiteCarX = -170
local baseFrostbiteCarY = -35
local introOpponentFaceAnchorX = 0.53
local introOpponentFaceAnchorY = 0.20
local introOpponentFaceOffsetX = 6
local introOpponentFaceOffsetY = -16
local introOpponentFaceZoom = 1.95
local introGirlfriendFaceAnchorX = 0.29
local introGirlfriendFaceAnchorY = 0.24
local introGirlfriendFaceOffsetX = 10
local introGirlfriendFaceOffsetY = 30
local introGirlfriendFaceZoom = 2.15
local introBoyfriendFaceAnchorX = 0.29
local introBoyfriendFaceAnchorY = 0.48
local introBoyfriendFaceOffsetX = 10
local introBoyfriendFaceOffsetY = 310
local introBoyfriendFaceZoom = 2.15

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

local currentIntroFocusX = baseFunkroadCameraX
local currentIntroFocusY = baseFunkroadCameraY
local currentIntroZoom = baseFunkroadCameraZoom
local currentIntroCarX = baseFrostbiteCarX
local currentIntroCarY = baseFrostbiteCarY
local introClearTween = nil
local introWarmupIndex = 0
local introWarmupDone = false

local function startsWith(value, prefix)
    if type(value) ~= "string" or type(prefix) ~= "string" then
        return false
    end

    return value:sub(1, #prefix) == prefix
end

local function easeOutCubic(value)
    local inverse = 1 - value
    return 1 - (inverse * inverse * inverse)
end

local function lerp(a, b, t)
    return a + ((b - a) * t)
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
    currentIntroFocusX = baseFunkroadCameraX
    currentIntroFocusY = baseFunkroadCameraY
    currentIntroZoom = baseFunkroadCameraZoom
    currentIntroCarX = baseFrostbiteCarX
    currentIntroCarY = baseFrostbiteCarY
    introClearTween = nil
    introWarmupIndex = 0
    introWarmupDone = false
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

local function getIntroOpponentFaceFocus()
    local opponentX = getSpriteX("opponent")
    local opponentY = getSpriteY("opponent")
    local opponentWidth = getSpriteWidth("opponent")
    local opponentHeight = getSpriteHeight("opponent")

    return opponentX + (opponentWidth * introOpponentFaceAnchorX) + introOpponentFaceOffsetX,
        opponentY + (opponentHeight * introOpponentFaceAnchorY) + introOpponentFaceOffsetY
end

local function getIntroBoyfriendFaceFocus()
    local boyfriendX = getSpriteX("boyfriend")
    local boyfriendY = getSpriteY("boyfriend")
    local boyfriendWidth = getSpriteWidth("boyfriend")
    local boyfriendHeight = getSpriteHeight("boyfriend")

    return boyfriendX + (boyfriendWidth * introBoyfriendFaceAnchorX) + introBoyfriendFaceOffsetX,
        boyfriendY + (boyfriendHeight * introBoyfriendFaceAnchorY) + introBoyfriendFaceOffsetY
end

local function getIntroGirlfriendFaceFocus()
    local girlfriendX = getSpriteX("boyfriend")
    local girlfriendY = getSpriteY("boyfriend")
    local girlfriendWidth = getSpriteWidth("boyfriend")
    local girlfriendHeight = getSpriteHeight("boyfriend")

    return girlfriendX + (girlfriendWidth * introGirlfriendFaceAnchorX) + introGirlfriendFaceOffsetX,
        girlfriendY + (girlfriendHeight * introGirlfriendFaceAnchorY) + introGirlfriendFaceOffsetY
end

local function getIntroCompensatedCarPosition(focusX, focusY, zoom)
    local originalHalfWidth = windowWidth / (2 * baseFunkroadCameraZoom)
    local originalHalfHeight = windowHeight / (2 * baseFunkroadCameraZoom)
    local introHalfWidth = windowWidth / (2 * zoom)
    local introHalfHeight = windowHeight / (2 * zoom)
    local originalCarScreenX = baseFrostbiteCarX - baseFunkroadCameraX + originalHalfWidth
    local originalCarScreenY = baseFrostbiteCarY - baseFunkroadCameraY + originalHalfHeight

    return originalCarScreenX + focusX - introHalfWidth,
        originalCarScreenY + focusY - introHalfHeight
end

local function applyIntroCameraState(focusX, focusY, zoom, carX, carY)
    introClearTween = nil
    currentIntroFocusX = focusX
    currentIntroFocusY = focusY
    currentIntroZoom = zoom
    currentIntroCarX = carX
    currentIntroCarY = carY

    setGameplayCameraFocus(focusX, focusY, true)
    setGameplayCameraZoom(zoom, true, true)
    setSpritePosition("frostbiteCAR", carX, carY)
end

local function applyIntroOpponentFaceShot()
    local focusX, focusY = getIntroOpponentFaceFocus()
    local introCarX, introCarY = getIntroCompensatedCarPosition(focusX, focusY, introOpponentFaceZoom)
    applyIntroCameraState(focusX, focusY, introOpponentFaceZoom, introCarX, introCarY)
end

local function applyIntroGirfriendFaceShot()
    local focusX, focusY = getIntroGirlfriendFaceFocus()
    local introCarX, introCarY = getIntroCompensatedCarPosition(focusX, focusY, introGirlfriendFaceZoom)
    applyIntroCameraState(focusX, focusY, introGirlfriendFaceZoom, introCarX, introCarY)
end

local function applyIntroBoyfriendFaceShot()
    local focusX, focusY = getIntroBoyfriendFaceFocus()
    local introCarX, introCarY = getIntroCompensatedCarPosition(focusX, focusY, introBoyfriendFaceZoom)
    applyIntroCameraState(focusX, focusY, introBoyfriendFaceZoom, introCarX, introCarY)
end

local function applyIntroBaseCameraShot()
    applyIntroCameraState(
        baseFunkroadCameraX,
        baseFunkroadCameraY,
        introBaseCameraZoom,
        baseFrostbiteCarX,
        baseFrostbiteCarY
    )
end

local function applyIntroNoteReveal()
    local totalRevealWindow = math.max(introClearDuration, ((introNoteRevealEndStep - introNoteRevealStartStep) * stepCrochet) / 1000)
    local revealDuration = totalRevealWindow * 0.67 -- Just-Feeshy: AAAAAYYYYYYY 6 7!!!!!
    local revealDelay = 0

    if introNoteRevealLanePairs > 1 then
        revealDelay = math.max(0, (totalRevealWindow - revealDuration) / (introNoteRevealLanePairs - 1))
    end

    jtc_camera.revealNoteCameras(revealDuration, revealDelay)
end

local function clearIntroCameraShot()
    introClearTween = {
        elapsed = 0,
        duration = introClearDuration,
        startFocusX = currentIntroFocusX,
        startFocusY = currentIntroFocusY,
        startZoom = currentIntroZoom,
        startCarX = currentIntroCarX,
        startCarY = currentIntroCarY,
        targetFocusX = baseFunkroadCameraX,
        targetFocusY = baseFunkroadCameraY,
        targetZoom = baseFunkroadCameraZoom,
        targetCarX = baseFrostbiteCarX,
        targetCarY = baseFrostbiteCarY
    }
end

local function ensureIntroWarmupCover()
    if spriteExist("introWarmupCover") then
        return
    end

    createSprite("introWarmupCover")
    makeGraphic("introWarmupCover", windowWidth, windowHeight, "0xFF000000")
    setSpriteToCamera("introWarmupCover", "camHUD")
    setSpritePosition("introWarmupCover", 0, 0)
    addSpriteToState("introWarmupCover")
end

local function updateIntroWarmup()
    if introWarmupDone or curStep >= 12 then
        return
    end

    if introWarmupIndex == 0 then
        applyIntroGirfriendFaceShot()
    elseif introWarmupIndex == 1 then
        applyIntroBoyfriendFaceShot()
    elseif introWarmupIndex == 2 then
        applyIntroBaseCameraShot()
    elseif introWarmupIndex == 3 then
        applyIntroOpponentFaceShot()
    end

    finishGPUCommands()

    introWarmupIndex = introWarmupIndex + 1

    if introWarmupIndex >= 4 then
        introWarmupDone = true
        applyIntroOpponentFaceShot()
    end
end

local function updateIntroClearTween(elapsed)
    if introClearTween == nil then
        return
    end

    introClearTween.elapsed = introClearTween.elapsed + elapsed
    local t = math.min(introClearTween.elapsed / introClearTween.duration, 1)
    local eased = easeOutCubic(t)

    local focusX = lerp(introClearTween.startFocusX, introClearTween.targetFocusX, eased)
    local focusY = lerp(introClearTween.startFocusY, introClearTween.targetFocusY, eased)
    local zoom = lerp(introClearTween.startZoom, introClearTween.targetZoom, eased)
    local carX = lerp(introClearTween.startCarX, introClearTween.targetCarX, eased)
    local carY = lerp(introClearTween.startCarY, introClearTween.targetCarY, eased)

    currentIntroFocusX = focusX
    currentIntroFocusY = focusY
    currentIntroZoom = zoom
    currentIntroCarX = carX
    currentIntroCarY = carY

    setGameplayCameraFocus(focusX, focusY, true)
    setGameplayCameraZoom(zoom, true, true)
    setSpritePosition("frostbiteCAR", carX, carY)

    if t >= 1 then
        introClearTween = nil
        clearGameplayCameraFocus(true)
        clearGameplayCameraZoom(true)
        setSpritePosition("frostbiteCAR", baseFrostbiteCarX, baseFrostbiteCarY)
        currentIntroFocusX = baseFunkroadCameraX
        currentIntroFocusY = baseFunkroadCameraY
        currentIntroZoom = baseFunkroadCameraZoom
        currentIntroCarX = baseFrostbiteCarX
        currentIntroCarY = baseFrostbiteCarY
    end
end

function generatedStage()
    init()
    setEndVideo("post.mp4")
    setCountdownPresentation(false, false)
    addSongTrack("gfVocals", "GF_Voices", "extra", 1)
    addSongTrack("jtcVocals", "JTC_Voices", "player", 1, false, "t,joul")
    jtc_camera.hideGameplayUntilStep(12, false)
    setCameraVisible("camGame", true)
    ensureIntroWarmupCover()

    createSprite("frostbiteCAR")
    setSpritePosition("frostbiteCAR", baseFrostbiteCarX, baseFrostbiteCarY)
    createCombinedFrames("frostbiteCAR-frames", "daddycar", "daddycar2", "sparrow", "sparrow")
    addFramesToSprite("frostbiteCAR", "frostbiteCAR-frames")
    addAnimationByPrefix("frostbiteCAR", "transition", "car drive and dust0", 24, false)
    addAnimationByPrefix("frostbiteCAR", "fog", "car drive and dust t", 24, false)
    playAnimationByPrefix("frostbiteCAR", "drive", "daddycar", 24, false)
    setScrollFactorToSprite("frostbiteCAR", 1.0, 0.9)
    insertSpriteToStage(getSpriteIndexFromStage("dad"), "frostbiteCAR")
    applyIntroOpponentFaceShot()

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

    if curStep == 12 and spriteExist("introWarmupCover") then
        removeSpriteFromState("introWarmupCover")
        destroySprite("introWarmupCover")
    end

    if curStep == 24 then
        applyIntroGirfriendFaceShot()
    end

    if curStep == 34 then
        applyIntroBoyfriendFaceShot()
    end

    if curStep == introNoteRevealStartStep then
        applyIntroNoteReveal()
    end

    if curStep == introBaseCameraStep then
        applyIntroBaseCameraShot()
    end

    if curStep == introClearStep then
        clearIntroCameraShot()
    end

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

    updateIntroWarmup()
    jtc_camera.onUpdate(elapsed)
    updateIntroClearTween(elapsed)

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
