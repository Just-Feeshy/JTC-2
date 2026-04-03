-- First main game lua test of this "engine" to see how well it can handle lua modchart's and general scripting.
-- This is not the most organized script setup, but Frostbeat is the best song to test the "simple stuff."

--variables of components
local jtc_camera = require("mod_assets/scripts/components/jtc_camera")
local static_shader = require("mod_assets/scripts/utils/static_shader")
local frost_modchart = {}

local beatSection = 0
local pulseStepIntensity = {}
local baseGameZoom = 1
local staticShaderInstance = nil
local staticShaderTime = 0
local baseHudZoom = 1
local baseNoteZoom = 1

local curAnimName = ""
local holdTimer = 0
local multipler = 6.1
local stunned = false
local notDancing = false

local phaseTwo = 643
local daddyIsHere = false
local daddyTrans = false

local secondBaseX = 670
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
local introBeginStep = 18

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

local shaderTrans = { --In steps
	608,
	656,
	629
}

local currentIntroFocusX = baseFunkroadCameraX
local currentIntroFocusY = baseFunkroadCameraY
local currentIntroZoom = baseFunkroadCameraZoom
local currentIntroCarX = baseFrostbiteCarX
local currentIntroCarY = baseFrostbiteCarY
local introClearTween = nil
local introWarmupIndex = 0
local introWarmupDone = false
local introCoverRemoved = false
local introGirlfriendShotDone = false
local introBoyfriendShotDone = false
local introNoteRevealDone = false
local introBaseCameraDone = false
local introClearDone = false
local secondActive = false
local boyfriendGFSwitched = false
local jtcVocalsSwitchedToPlayer = false
local INTENSITY_MULTIPLIER = 1.5
local BASE_GAME_BUMP = 0.015
local BASE_HUD_BUMP = 0.03
local BASE_NOTE_BUMP = 0.03
local CAMERA_BOP_DECAY_RATE = 0.95

local B1 = 1 / 2.75
local B2 = 2 / 2.75
local B3 = 1.5 / 2.75
local B4 = 2.5 / 2.75
local B5 = 2.25 / 2.75
local B6 = 2.625 / 2.75

local function bounceOut(t)
    if t < B1 then
        return 7.5625 * t * t
    elseif t < B2 then
        return 7.5625 * (t - B3) * (t - B3) + 0.75
    elseif t < B4 then
        return 7.5625 * (t - B5) * (t - B5) + 0.9375
    else
        return 7.5625 * (t - B6) * (t - B6) + 0.984375
    end
end

local function bounceIn(t)
    return 1 - bounceOut(1 - t)
end

local function addPulseStep(stepValue, intensity)
    pulseStepIntensity[stepValue] = intensity
end

local function addPulseRange(startStep, endStep, everySteps, intensity)
    if everySteps == nil or everySteps <= 0 then
        return
    end

    local stepValue = startStep

    while stepValue <= endStep do
        addPulseStep(stepValue, intensity)
        stepValue = stepValue + everySteps
    end
end

local function buildPulseSteps()
    pulseStepIntensity = {}

	addPulseRange(150, 212, 4, 0.67)
	addPulseRange(216, 282, 4, 1.0)
	addPulseRange(286, 474, 4, 1.41)
end

local function pulseCamera(stepValue)
    local intensity = (pulseStepIntensity[stepValue] or 0) * INTENSITY_MULTIPLIER

    if intensity <= 0 then
        return
    end

    local gameZoom = getCameraZoom("camGAME") or baseGameZoom
    local hudZoom = getCameraZoom("camHUD") or baseHudZoom
    local noteZoom = getCameraZoom("camNOTE") or baseNoteZoom

    setCameraZoom("camGAME", gameZoom + (BASE_GAME_BUMP * intensity))
    setCameraZoom("camHUD", hudZoom + (BASE_HUD_BUMP * intensity))
    setCameraZoom("camNOTE", noteZoom + (BASE_NOTE_BUMP * intensity))
end

local function decayCameraZooms(elapsed)
    local safeElapsed = math.max(elapsed or 0, 0)
    local dt = safeElapsed * 60
    local decay = math.pow(CAMERA_BOP_DECAY_RATE, dt)

    local gameZoom = getCameraZoom("camGAME")
    local hudZoom = getCameraZoom("camHUD")
    local noteZoom = getCameraZoom("camNOTE")

    if gameZoom ~= nil then
        setCameraZoom("camGAME", baseGameZoom + ((gameZoom - baseGameZoom) * decay))
    end

    if hudZoom ~= nil then
        setCameraZoom("camHUD", baseHudZoom + ((hudZoom - baseHudZoom) * decay))
    end

    if noteZoom ~= nil then
        setCameraZoom("camNOTE", baseNoteZoom + ((noteZoom - baseNoteZoom) * decay))
    end
end

local function shaderTransitionUpdate()
	local opacity = (curStepFloat - shaderTrans[1]) / (shaderTrans[3] - shaderTrans[1])

	if shaderTrans[1] < curStepFloat and shaderTrans[2] > curStepFloat then
        staticShaderInstance:setProperty("opacity", math.min(0.5 * bounceOut(opacity), 0.5))
	end

	if shaderTrans[1] < curStepFloat and shaderTrans[3] > curStepFloat then
		setSpriteAlpha("jumpscare", bounceIn(opacity))
	end
end

local function startsWith(value, prefix)
    if type(value) ~= "string" or type(prefix) ~= "string" then
        return false
    end

    return value:sub(1, #prefix) == prefix
end

local function smootherStep(value)
    local clamped = math.max(0, math.min(value, 1))
    return clamped * clamped * clamped * (clamped * ((clamped * 6) - 15) + 10)
end

local function lerp(a, b, t)
    return a + ((b - a) * t)
end

local function createJumpscare()
	createSprite("jumpscare")
	loadGraphic("jumpscare", "jumpscare")
	setSpriteAlpha("jumpscare", 0.0)
	setSpriteToCamera("jumpscare", "camHUD")
	setSpriteSize("jumpscare", windowWidth, windowHeight)
	addSpriteToStage("jumpscare")
end

local function init()
    beatSection = 0
    frost_modchart = {}
    pulseStepIntensity = {}
    staticShaderTime = 0
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
    introCoverRemoved = false
    introGirlfriendShotDone = false
    introBoyfriendShotDone = false
    introNoteRevealDone = false
    introBaseCameraDone = false
    introClearDone = false
    secondActive = false
    boyfriendGFSwitched = false
    jtcVocalsSwitchedToPlayer = false
    baseGameZoom = getCameraZoom("camGAME") or 1
    baseHudZoom = getCameraZoom("camHUD") or 1
    baseNoteZoom = getCameraZoom("camNOTE") or 1
	precacheCharacter("dad-car")
	precacheCharacter("flying BF sings gf")
	addCharacterToList("flying BF sings gf", "boyfriend")
	createJumpscare()
    buildPulseSteps()
    callEvent("setCameraBop", "0", "0")
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
    if introWarmupDone or curStep >= introBeginStep then
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

	finishGPUCommands() -- This clears up the tiny lag spike

    introWarmupIndex = introWarmupIndex + 1

    if introWarmupIndex >= 4 then
        introWarmupDone = true
        applyIntroOpponentFaceShot()
    end
end

local function performIntroWarmup()
    if introWarmupDone then
        return
    end

    ensureIntroWarmupCover()

    applyIntroGirfriendFaceShot()
    finishGPUCommands()

    applyIntroBoyfriendFaceShot()
    finishGPUCommands()

    applyIntroBaseCameraShot()
    finishGPUCommands()

    applyIntroOpponentFaceShot()
    finishGPUCommands()

    introWarmupIndex = 4
    introWarmupDone = true
end

local function updateIntroClearTween(elapsed)
    if introClearTween == nil then
        return
    end

    introClearTween.elapsed = introClearTween.elapsed + elapsed
    local t = math.min(introClearTween.elapsed / introClearTween.duration, 1)
    local eased = smootherStep(t)

    local focusX = lerp(introClearTween.startFocusX, introClearTween.targetFocusX, eased)
    local focusY = lerp(introClearTween.startFocusY, introClearTween.targetFocusY, eased)
    local zoom = lerp(introClearTween.startZoom, introClearTween.targetZoom, eased)
    local carX = lerp(introClearTween.startCarX, introClearTween.targetCarX, eased)
    local carY = lerp(introClearTween.startCarY, introClearTween.targetCarY, eased)

    currentIntroFocusX = focusX
    currentIntroFocusY = focusY
    currentIntroZoom = zoom
    currentIntroCarX = carplX
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

local function refreshFrostbiteCarAnimation()
    if not spriteExist("frostbiteCAR") then
        return
    end

    local stepValue = curStep or 0

    if daddyTrans and stepValue < 630 then
        setSpritePosition("frostbiteCAR", 241, 81)
        playAnimRaw("frostbiteCAR", "transition", true)
        return
    end

    if stepValue < 607 then
        playAnimRaw("frostbiteCAR", "drive", true)
    end
end

local function destroyManagedSprite(spriteName)
    if not spriteExist(spriteName) then
        return
    end

    removeSpriteFromStage(spriteName)
    removeSpriteFromState(spriteName)
    destroySprite(spriteName)
end

local function ensureFrostbiteCar()
	local smallestIndex = math.min(getSpriteIndexFromStage("boyfriend"), getSpriteIndexFromStage("dad"))

    destroyManagedSprite("frostbiteCAR")
    createSprite("frostbiteCAR")
    setSpritePosition("frostbiteCAR", baseFrostbiteCarX, baseFrostbiteCarY)
    createCombinedFrames("frostbiteCAR-frames", "daddycar", "daddycar2", "sparrow", "sparrow")
    addFramesToSprite("frostbiteCAR", "frostbiteCAR-frames")
    addAnimationByPrefix("frostbiteCAR", "drive", "daddycar", 24, true)
    addAnimationByPrefix("frostbiteCAR", "transition", "car drive and dust0", 24, false)
    addAnimationByPrefix("frostbiteCAR", "fog", "car drive and dust t", 24, false)
    playAnimRaw("frostbiteCAR", "drive", true)
    setScrollFactorToSprite("frostbiteCAR", 1.0, 0.9)
    insertSpriteToStage(smallestIndex, "frostbiteCAR")
end

local function resetSecondSprite()
    if not spriteExist("second") then
        return
    end

    setSpritePosition("second", secondBaseX, secondBaseY)
    setSpriteVisible("second", false)
    playAnimation("second", "idle")
    removeSpriteFromStage("second")
end

local function refreshFrostbeatRuntimeState()
    frost_modchart = require("mod_assets/scripts/modcharts/frostbeat") or {}

    if frost_modchart.initStrumsAndNotes ~= nil then
        frost_modchart.initStrumsAndNotes()
    end

    jtc_camera.registerHiddenSprites({
        "punchIcon1",
        "punchIcon2",
        "punchIcon3"
    })
end

function generatedStage()
    init()
    staticShaderInstance = static_shader.new("static_shader"):init()
    setEndVideo("post.mp4")
    setCountdownPresentation(false, false)
    addSongTrack("gfVocals", "GF_Voices", "extra", 1)
    addSongTrack("jtcVocals", "JTC_Voices", "opponent", 1)
    jtc_camera.hideGameplayUntilStep(12, false)
    setCameraVisible("camGame", true)
    ensureIntroWarmupCover()

    ensureFrostbiteCar()
    applyIntroOpponentFaceShot()
    performIntroWarmup()

    resetSecondSprite()

    setupPunchHealth(3)
    refreshFrostbeatRuntimeState()
end

function onStepHit()
    jtc_camera.onStepHit(curStep)

    pulseCamera(curStep)

    if curStep == 606 then
        daddyTrans = true
    end

    if curStep == shaderTrans[1] then
		playSound("slenderdad", 1.0)
        staticShaderInstance:bindToCamera("camHUD")
        staticShaderInstance:setProperty("time", 1.0)
    end

	if curStep == shaderTrans[2] then
		setSpriteAlpha("jumpscare", 0)
		removeSpriteFromState("jumpscare")
        staticShaderInstance:unbindFromCamera()
	end

    if curStep >= 630 and not daddyIsHere then
		callEvent("character change", "dad-car", "dad")
		setSpriteVisible("frostbiteCAR", false)
        removeSpriteFromState("frostbiteCAR")
        daddyIsHere = true
        secondActive = true

        -- Add second sprite right after character change
        if spriteExist("second") then
            setSpriteVisible("second", true)
            addSpriteToStage("second")
        end
    end

    if curStep >= 630 and not jtcVocalsSwitchedToPlayer then
        removeSongTrack("jtcVocals")
        addSongTrack("jtcVocals", "JTC_Voices", "player", 1)
        jtcVocalsSwitchedToPlayer = true
    end

    if curStep > 906 then
        secondActive = false
    end

end

function goodNoteHit(caculatePos, strumTime, noteData, tag, noteAbstract, isSustainNote)
	if not boyfriendGFSwitched and curStep ~= nil and curStep >= 906 then
		callEvent("character change", "flying BF sings gf", "boyfriend")
		boyfriendGFSwitched = true
	end

	if not secondActive then
		return
	end

	playAnimation("second", jtcStrumAnims[noteData + 1])
	setSpritePosition("second", secondBaseX - jtcOffsets[noteData + 1][1], secondBaseY - jtcOffsets[noteData + 1][2])
	notDancing = true
end

function noteMiss(noteData, tag)
	if not secondActive then
		return
	end

	playAnimation("second", jtcStrumAnims[noteData + 1] .. " miss")
	setSpritePosition("second", secondBaseX - jtcOffsets[noteData + 5][1], secondBaseY - jtcOffsets[noteData + 5][2])
	notDancing = true
end

function onUpdate(elapsed)
    if not startedCountdown then
        return
    end

    -- Update shader time animation
    if staticShaderInstance and staticShaderInstance:getBoundCamera() then
        staticShaderTime = staticShaderTime + elapsed
        staticShaderInstance:setProperty("time", staticShaderTime)
    end

    if not introCoverRemoved and curStep ~= nil and curStep >= introBeginStep and spriteExist("introWarmupCover") then
        removeSpriteFromState("introWarmupCover")
        destroySprite("introWarmupCover")
        introCoverRemoved = true
    end

    if not introGirlfriendShotDone and curStep ~= nil and curStep >= 26 then
        applyIntroGirfriendFaceShot()
        introGirlfriendShotDone = true
    end

    if not introBoyfriendShotDone and curStep ~= nil and curStep >= 34 then
        applyIntroBoyfriendFaceShot()
        introBoyfriendShotDone = true
    end

    if not introNoteRevealDone and curStep ~= nil and curStep >= introNoteRevealStartStep then
        applyIntroNoteReveal()
        introNoteRevealDone = true
    end

    if not introBaseCameraDone and curStep ~= nil and curStep >= introBaseCameraStep then
        applyIntroBaseCameraShot()
        introBaseCameraDone = true
    end

    if not introClearDone and curStep ~= nil and curStep >= introClearStep then
        clearIntroCameraShot()
        introClearDone = true
    end

    jtc_camera.onUpdate(elapsed)
    updateIntroClearTween(elapsed)
    decayCameraZooms(elapsed)

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

	shaderTransitionUpdate()
end

function onResume()
    holdTimer = 0

    refreshFrostbiteCarAnimation()
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
