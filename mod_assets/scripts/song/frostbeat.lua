-- Frostbeat song modchart (gameplay only).
--
-- Stage scenery (the frostbiteCAR prop + base character layout) now lives in
-- scripts/stage/frostbeat/frostbeat_stage.lua, and the camera choreography is declarative
-- data in scripts/stage/frostbeat/frostbeat_camera.lua (applied by the engine's StageCamera
-- layer). Both run in their own Lua VM alongside this one (see build/play/PlayLua.hx).
--
-- What remains here: HUD/punch mechanics, the death-note logic, the static-shader / jumpscare
-- "slender" transition, the phase-two character swaps, song tracks/vocals, the note-reactive
-- skater opponent ("second"), and the GPU-warm precache trick.

-- ============================================================================
-- Modules
-- ============================================================================
local jtc_camera = require("mod_assets/scripts/components/jtc_camera")
local frost_modchart = {}

-- ============================================================================
-- Phase-two layout deltas (gameplay character repositioning)
-- ============================================================================
local phaseTwoDadDeltaX = -394
local phaseTwoDadDeltaY = 510
local phaseTwoBoyfriendDeltaX = 240
local phaseTwoBoyfriendDeltaY = 10

-- Atlas-backed phase-two skater opponent (frostbeat-second.json -> images/skater).
local secondBaseX = 1320
local secondBaseY = 559
local secondHiddenAlpha = 0.00001

local originalDadCharacter = "joul"
local originalBoyfriendCharacter = "flying BF sings"

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

local shaderTrans = { -- In steps
    608,
    656,
    629
}

local STATIC_SHADER_NAME = "static_shader"
local STATIC_SHADER_CAMERA = "camHUD"

-- Bop is suppressed through the intro (the camera is on scripted face-shots until ~step 68).
local introBopSuppressUntilStep = 68
local introBeginStep = 18
local introNoteRevealStartStep = 36
local introNoteRevealEndStep = 54
local introNoteRevealLanePairs = 4
local introClearDuration = 0.35
local introWarmupTotalSteps = 5

-- ============================================================================
-- Runtime state
-- ============================================================================

-- Static shader / slender transition
local staticShaderInitialized = false
local staticShaderInitFailed = false
local staticShaderActive = false
local staticShaderTime = 0
local staticShaderCleared = false
local staticShaderSoundPlayed = false

-- Opponent animation pacing
local curAnimName = ""
local holdTimer = 0
local multipler = 6.1
local stunned = false

-- Phase / character swap flags
local daddyIsHere = false
local secondActive = false
local boyfriendGFSwitched = false

-- Intro warmup / cover
local introWarmupIndex = 0
local introWarmupDone = false
local introCoverRemoved = false
local introNoteRevealDone = false

-- Punch / vocals
local jtcVocalsSwitchedToPlayer = false
local jtcVocalsMutedForPunch = false
local pendingVoiceUnmuteAllowed = true
local punchCount = 0
local punchIconNames = {}

-- ============================================================================
-- Math & easing helpers (shader transition)
-- ============================================================================

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

-- ============================================================================
-- Asset warming (pay first-draw GPU/audio cost up front behind the intro cover)
-- ============================================================================

local function precacheFrostbeatAssets()
    if precacheImage ~= nil then
        precacheImage("daddy_fist")
        precacheImage("daddy_fisted")
    end

    if precacheSound ~= nil then
        precacheSound("punch")
        precacheSound("slenderdad")
    end

    if precacheAtlas ~= nil then
        precacheAtlas("notes/regular/NOTE_assets", "sparrow")
        precacheAtlas("notes/death/NOTE_assets", "sparrow")
    end

    if precacheCharacter ~= nil then
        precacheCharacter("dad-car")
        precacheCharacter("frostbeat-second")
        precacheCharacter("flying BF sings gf")
    end

    if addCharacterToList ~= nil then
        addCharacterToList("dad-car", "dad")
        addCharacterToList("flying BF sings gf", "boyfriend")
    end
end

local frostbeatWarmSpriteNames = {
    "frostWarm_deathRegular",
    "frostWarm_deathNote",
    "frostWarm_daddyFisted",
    "frostWarm_jumpscare"
}

local function spawnFrostbeatWarmSprite(spriteName, imageName)
    if spriteExist(spriteName) then
        return
    end

    createSprite(spriteName)
    loadGraphic(spriteName, imageName)
    setSpritePosition(spriteName, 0, 0)
    scaleSprite(spriteName, 0.001, 0.001)
    setSpriteAlpha(spriteName, 0.00001)
    setSpriteToCamera(spriteName, "camHUD")
    addSpriteToState(spriteName)
end

local function clearFrostbeatWarmSprites()
    for _, spriteName in ipairs(frostbeatWarmSpriteNames) do
        if spriteExist(spriteName) then
            removeSpriteFromState(spriteName)
            destroySprite(spriteName)
        end
    end
end

local frostbeatAtlasesWarmed = false

local function warmFrostbeatAtlases()
    if frostbeatAtlasesWarmed then
        return
    end

    if primeCharacterAnimations ~= nil and spriteExist("second") then
        primeCharacterAnimations("second", {"idle", "punched", "singLEFT", "singLEFT miss"})
    end

    if primeCharacterAnimations ~= nil then
        primeCharacterAnimations("boyfriend", {"firstDeath"})
    end

    if primeLoadedCharacterAnimations ~= nil then
        primeLoadedCharacterAnimations("dad-car", "dad", {"punch"})
        primeLoadedCharacterAnimations("flying BF sings gf", "boyfriend", {"idle", "firstDeath"})
    end

    if playSound ~= nil then
        playSound("punch", 0)
    end

    frostbeatAtlasesWarmed = true
end

-- ============================================================================
-- Static shader (slender transition)
-- ============================================================================

local function shaderTransitionUpdate()
    if not staticShaderActive then
        return
    end

    local opacity = (curStepFloat - shaderTrans[1]) / (shaderTrans[3] - shaderTrans[1])

    if shaderTrans[1] < curStepFloat and shaderTrans[2] > curStepFloat then
        setShaderFloat(STATIC_SHADER_CAMERA, "opacity", math.min(0.5 * bounceOut(opacity), 0.5))
    end

    if shaderTrans[1] < curStepFloat and shaderTrans[3] > curStepFloat then
        setSpriteAlpha("jumpscare", bounceIn(opacity))
    end
end

local function initStaticShader()
    if staticShaderInitialized then
        return true
    end

    if staticShaderInitFailed or initLuaShader == nil then
        return false
    end

    local ok, result = pcall(initLuaShader, STATIC_SHADER_NAME, "shaders")

    if ok and result == true then
        staticShaderInitialized = true
    else
        staticShaderInitFailed = true
    end

    return staticShaderInitialized
end

local function ensureStaticShader()
    if staticShaderActive then
        return true
    end

    if not initStaticShader() or setCameraShader == nil then
        return false
    end

    staticShaderActive = setCameraShader(STATIC_SHADER_CAMERA, STATIC_SHADER_NAME) == true

    if staticShaderActive then
        setShaderFloat(STATIC_SHADER_CAMERA, "time", staticShaderTime)
        setShaderFloat(STATIC_SHADER_CAMERA, "opacity", 0.0)
    end

    return staticShaderActive
end

local function startStaticShaderEffect()
    if not staticShaderSoundPlayed then
        playSound("slenderdad", 1.0)
        staticShaderSoundPlayed = true
    end

    if not ensureStaticShader() then
        return
    end

    staticShaderTime = math.max(staticShaderTime, 1.0)
    setShaderFloat(STATIC_SHADER_CAMERA, "time", staticShaderTime)
    setShaderFloat(STATIC_SHADER_CAMERA, "opacity", 0.0)
    staticShaderCleared = false
end

local function clearStaticShaderEffect()
    if staticShaderCleared then
        return
    end

    if spriteExist("jumpscare") then
        setSpriteAlpha("jumpscare", 0)
        removeSpriteFromState("jumpscare")
    end

    if staticShaderActive then
        setShaderFloat(STATIC_SHADER_CAMERA, "opacity", 0.0)
        if clearCameraShaders ~= nil then
            clearCameraShaders(STATIC_SHADER_CAMERA)
        elseif removeCameraShader ~= nil then
            removeCameraShader(STATIC_SHADER_CAMERA)
        end
        staticShaderActive = false
    end

    staticShaderCleared = true
end

-- Detach the static shader after the intro-warmup link pass without touching the jumpscare
-- sprite or the "cleared" latch (leaves the linked shader program ready for step 608).
local function detachWarmStaticShader()
    if not staticShaderActive then
        return
    end

    setShaderFloat(STATIC_SHADER_CAMERA, "opacity", 0.0)

    if clearCameraShaders ~= nil then
        clearCameraShaders(STATIC_SHADER_CAMERA)
    elseif removeCameraShader ~= nil then
        removeCameraShader(STATIC_SHADER_CAMERA)
    end

    staticShaderActive = false
end

-- ============================================================================
-- Jumpscare
-- ============================================================================

local function createJumpscare()
    createSprite("jumpscare")
    loadGraphic("jumpscare", "jumpscare")
    setSpriteAlpha("jumpscare", 0.0)
    setSpriteToCamera("jumpscare", "camHUD")
    setSpriteSize("jumpscare", windowWidth, windowHeight)
    addSpriteToStage("jumpscare")
end

-- ============================================================================
-- Runtime-state resets + init
-- ============================================================================

local function resetIntroRuntimeState()
    introWarmupIndex = 0
    introWarmupDone = false
    introCoverRemoved = false
    introNoteRevealDone = false
end

local function resetPhaseTwoRuntimeState()
    daddyIsHere = false
    secondActive = false
    boyfriendGFSwitched = false
end

local function resetPunchRuntimeState()
    curAnimName = ""
    holdTimer = 0
    multipler = 6.1
    stunned = false
    notDancing = false
    jtcVocalsSwitchedToPlayer = false
    jtcVocalsMutedForPunch = false
    punchCount = 0
    punchIconNames = {}
end

local function resetShaderRuntimeState()
    staticShaderTime = 0
    baseGameZoom = getCameraZoom("camGAME") or 1
    baseHudZoom = getCameraZoom("camHUD") or 1
    baseNoteZoom = getCameraZoom("camNOTE") or 1
    staticShaderInitialized = false
    staticShaderInitFailed = false
    staticShaderActive = false
    staticShaderCleared = false
    staticShaderSoundPlayed = false
end

local function init()
    frost_modchart = {}
    clearFrostbeatWarmSprites()
    frostbeatAtlasesWarmed = false
    resetIntroRuntimeState()
    resetPhaseTwoRuntimeState()
    resetPunchRuntimeState()
    resetShaderRuntimeState()
    initStaticShader()
    createJumpscare()
    -- Camera bumps are declarative now (bumps table in frostbeat_camera.lua, applied by StageCamera).
    -- Suppress the engine beat-bump through the intro (the camera is on scripted shots).
    if setSuppressGameplayCameraBop ~= nil then
        setSuppressGameplayCameraBop(true)
    end
    if setSuppressGameplayCameraBopWhileZoom ~= nil then
        setSuppressGameplayCameraBopWhileZoom(true)
    end
    jtc_camera.reset()
end

-- ============================================================================
-- Second (skater) sprite + phase-two layout/entry
-- ============================================================================

local function setupSecondSprite()
    if makeCharacter ~= nil then
        if not spriteExist("second") then
            makeCharacter("second", "frostbeat-second", secondBaseX, secondBaseY)
        end
    else
        if not spriteExist("second") then
            createCharacterSprite("second", "frostbeat-second", secondBaseX, secondBaseY)
        end
    end

    if addCharacter ~= nil then
        addCharacter("second", "dad")
    else
        local dadIndex = getSpriteIndexFromStage("dad")

        if dadIndex ~= nil and dadIndex >= 0 then
            insertSpriteToStage(dadIndex, "second")
        else
            addSpriteToStage("second")
        end
    end

    spriteFlip("second", true, false)
    setSpritePosition("second", secondBaseX, secondBaseY)
    setSpriteAlpha("second", secondHiddenAlpha)
    setSpriteVisible("second", true)
    playCharacterAnim("second", "idle", true)
end

local function playSecondAnimation(animName)
    if animName ~= "punched" and spriteExist("second") and curAnimName == "punched" and not sprAnimFinished("second") then
        return
    end

    playCharacterAnim("second", animName, true)
    curAnimName = animName
end

local function isSecondPunchLocked()
    return spriteExist("second") and curAnimName == "punched" and not sprAnimFinished("second")
end

local function applyPhaseTwoFunkroadLayout()
    if spriteExist("dad") then
        setSpritePosition("dad", getSpriteX("dad") + phaseTwoDadDeltaX, getSpriteY("dad") + phaseTwoDadDeltaY)
    end

    if spriteExist("boyfriend") then
        setSpritePosition("boyfriend", getSpriteX("boyfriend") + phaseTwoBoyfriendDeltaX, getSpriteY("boyfriend") + phaseTwoBoyfriendDeltaY)
    end
end

local function enterPhaseTwo()
    if daddyIsHere then
        return
    end

    -- "character change" to dad-car is now triggered by frostbeat_stage.lua (stageCharacterChanges).
    if removeLoadedCharacter ~= nil then
        removeLoadedCharacter(originalDadCharacter, "dad")
    end
    setSpriteY("dad", 90)
    -- The frostbiteCAR prop is destroyed by frostbeat_stage.lua at step 630, and the
    -- camera opens up to 1.0 via the step-630 keyframe in frostbeat_camera.lua.
    daddyIsHere = true
    secondActive = true

    applyPhaseTwoFunkroadLayout()

    if spriteExist("second") then
        setSpriteAlpha("second", 1)
        setSpriteVisible("second", true)
        local dadIndex = getSpriteIndexFromStage("dad")

        if dadIndex ~= nil and dadIndex >= 0 then
            insertSpriteToStage(dadIndex, "second")
        else
            addSpriteToStage("second")
        end

        playSecondAnimation("idle")
    end

    if setHealthIconAnimation ~= nil then
        setHealthIconAnimation("player", "flying BF sings", 28, 29, 28, true)
    end
end

-- ============================================================================
-- HUD / health icons / punch
-- ============================================================================

local function applyPhaseOneHud()
    if setHealthIconAnimation ~= nil then
        setHealthIconAnimation("player", "flying BF sings", 31, 32, 31, true)
        setHealthIconAnimation("opponent", "joul", 24, 30, 24, false)
    end
end

local function updatePunchIcon(index)
    local iconName = punchIconNames[index]

    if iconName == nil or not spriteExist(iconName) then
        return
    end

    loadGraphic(iconName, "daddy_fisted")
    scaleSprite(iconName, 0.7, 0.7)
end

local function refreshPunchIcons()
    for index, iconName in ipairs(punchIconNames) do
        if iconName ~= nil and spriteExist(iconName) then
            if index <= punchCount then
                loadGraphic(iconName, "daddy_fisted")
            else
                loadGraphic(iconName, "daddy_fist")
            end

            scaleSprite(iconName, 0.7, 0.7)
        end
    end
end

local function triggerDeathNotePunch()
    if daddyIsHere then
        playCharacterAnim("dad", "punch", true)
    end

    if spriteExist("second") then
        holdTimer = 0
        playSecondAnimation("punched")
        notDancing = true
    end

    if setSongTrackBaseVolume ~= nil then
        if hasSongTrack ~= nil and hasSongTrack("jtcVocals") then
            setSongTrackBaseVolume("jtcVocals", 0)
        end
        jtcVocalsMutedForPunch = true
        pendingVoiceUnmuteAllowed = true
    end

    punchCount = punchCount + 1
    updatePunchIcon(punchCount)
    playSound("punch", 2)

    if punchCount >= 3 then
        instaKillPlayer()
    end
end

local function noteAllowsPunchVoiceUnmute(noteAbstract)
    if noteAllowsVoiceAudioUnmute ~= nil then
        return noteAllowsVoiceAudioUnmute(noteAbstract)
    end

    return true
end

local function recoverPunchCharge()
    if punchCount <= 0 then
        return
    end

    punchCount = math.max(punchCount - 1, 0)
    refreshPunchIcons()
end

-- ============================================================================
-- Intro note reveal + warmup cover (note cameras + GPU warm only)
-- ============================================================================

local function applyIntroNoteReveal()
    local totalRevealWindow = math.max(introClearDuration, ((introNoteRevealEndStep - introNoteRevealStartStep) * stepCrochet) / 1000)
    local revealDuration = totalRevealWindow * 0.67 -- Just-Feeshy: AAAAAYYYYYYY 6 7!!!!!
    local revealDelay = 0

    if introNoteRevealLanePairs > 1 then
        revealDelay = math.max(0, (totalRevealWindow - revealDuration) / (introNoteRevealLanePairs - 1))
    end

    jtc_camera.revealNoteCameras(revealDuration, revealDelay)
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

-- Keep the warm sprites alive for a few frames so their textures GPU-upload behind the
-- cover, then clear them and detach the warmed static shader. The camera shots that used
-- to run here are now driven from frostbeat_camera.lua.
local function updateIntroWarmup()
    if introWarmupDone then
        return
    end

    ensureIntroWarmupCover()

    if introWarmupIndex == 4 then
        clearFrostbeatWarmSprites()
        detachWarmStaticShader()
    end

    if finishGPUCommands ~= nil then
        finishGPUCommands()
    end

    introWarmupIndex = introWarmupIndex + 1

    if introWarmupIndex >= introWarmupTotalSteps then
        introWarmupDone = true
    end
end

local function resetSecondSprite()
    if not spriteExist("second") then
        return
    end

    setSpritePosition("second", secondBaseX, secondBaseY)
    setSpriteAlpha("second", secondHiddenAlpha)
    setSpriteVisible("second", true)
    playCharacterAnim("second", "idle", true)
    curAnimName = "idle"
    holdTimer = 0
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

-- ============================================================================
-- Lifecycle entry points
-- ============================================================================

function generatedStage()
    -- Mirror Funkin: pay the asset-load cost synchronously at song start.
    precacheFrostbeatAssets()
    init()
    applyPhaseOneHud()
    if clearCameraShaders ~= nil then
        clearCameraShaders(STATIC_SHADER_CAMERA)
    else
        removeCameraShader(STATIC_SHADER_CAMERA)
    end

    setGameOverBlueBallSuffix("-cheese")
    setEndVideo("post.mp4")
    setCountdownPresentation(false, false)
    if skipCountdown ~= nil then
        skipCountdown()
    end
    addSongTrack("gfVocals", "GF_Voices", "player", 1)
    addSongTrack("jtcVocals", "JTC_Voices", "opponent", 1)
    jtc_camera.hideGameplayUntilStep(12, false)
    setCameraVisible("camGame", true)
    ensureIntroWarmupCover()

    -- "second" is the phase-two skater opponent. Create it hidden up front so phase 2
    -- entry (step 630) is just an alpha/visibility flip.
    setupSecondSprite()
    resetSecondSprite()

    setupPunchHealth(3)
    refreshFrostbeatRuntimeState()

    -- Force GPU upload while the intro cover hides everything.
    spawnFrostbeatWarmSprite("frostWarm_deathRegular", "notes/regular/NOTE_assets")
    spawnFrostbeatWarmSprite("frostWarm_deathNote", "notes/death/NOTE_assets")
    spawnFrostbeatWarmSprite("frostWarm_daddyFisted", "daddy_fisted")

    spawnFrostbeatWarmSprite("frostWarm_jumpscare", "jumpscare")
    if ensureStaticShader() then
        setShaderFloat(STATIC_SHADER_CAMERA, "opacity", 0.0)
    end

    warmFrostbeatAtlases()

    if finishGPUCommands ~= nil then
        finishGPUCommands()
    end
end

function onStepHit()
    jtc_camera.onStepHit(curStep)

    if curStep >= introBopSuppressUntilStep and setSuppressGameplayCameraBop ~= nil then
        setSuppressGameplayCameraBop(false)
    end

    if curStep == shaderTrans[1] then
        startStaticShaderEffect()
    end

    if curStep == shaderTrans[2] then
        clearStaticShaderEffect()
    end

    if curStep >= 630 then
        enterPhaseTwo()
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
        recoverPunchCharge()
        -- "character change" to flying-BF-sings-gf is now triggered by frostbeat_stage.lua.
        if removeLoadedCharacter ~= nil then
            removeLoadedCharacter(originalBoyfriendCharacter, "boyfriend")
        end
        if setHealthIconAnimation ~= nil then
            setHealthIconAnimation("player", "flying BF sings", 28, 29, 28, true)
        end
        -- Phase-two flying camera is now a declarative segment driven by the stage camera.
        if triggerStageCameraSegment ~= nil then
            triggerStageCameraSegment("phaseTwoFlying")
        end
        boyfriendGFSwitched = true
    end

    if noteAbstract == "death" then
        triggerDeathNotePunch()
        return
    end

    if jtcVocalsMutedForPunch then
        pendingVoiceUnmuteAllowed = noteAllowsPunchVoiceUnmute(noteAbstract)

        if not pendingVoiceUnmuteAllowed then
            return
        end
    end

    if not secondActive or isSecondPunchLocked() then
        return
    end

    playSecondAnimation(jtcStrumAnims[noteData + 1])
end

function noteMiss(noteData, tag)
    if not secondActive or isSecondPunchLocked() then
        return
    end

    playSecondAnimation(jtcStrumAnims[noteData + 1] .. " miss")
end

function onUpdate(elapsed)
    updateIntroWarmup()

    if not startedCountdown then
        return
    end

    local stepFloat = curStepFloat
    local step = curStep

    if not daddyIsHere and stepFloat ~= nil and stepFloat >= 630 then
        enterPhaseTwo()
    end

    if not jtcVocalsSwitchedToPlayer and stepFloat ~= nil and stepFloat >= 630 then
        removeSongTrack("jtcVocals")
        addSongTrack("jtcVocals", "JTC_Voices", "player", 1)
        jtcVocalsSwitchedToPlayer = true
    end

    -- Only attach + drive the static shader inside its visible window.
    if stepFloat ~= nil and stepFloat >= shaderTrans[1] and stepFloat < shaderTrans[2] then
        if not staticShaderActive then
            startStaticShaderEffect()
        end

        if ensureStaticShader() then
            staticShaderTime = staticShaderTime + elapsed
            setShaderFloat(STATIC_SHADER_CAMERA, "time", staticShaderTime)
        end
    elseif stepFloat ~= nil and stepFloat >= shaderTrans[2] then
        clearStaticShaderEffect()
    end

    if not introCoverRemoved and step ~= nil and step >= introBeginStep and spriteExist("introWarmupCover") then
        removeSpriteFromState("introWarmupCover")
        destroySprite("introWarmupCover")
        introCoverRemoved = true
    end

    if not introNoteRevealDone and step ~= nil and step >= introNoteRevealStartStep then
        applyIntroNoteReveal()
        introNoteRevealDone = true
    end

    jtc_camera.onUpdate(elapsed)

    -- Precompute once; used twice below to avoid duplicate string ops.
    local animIsSing = curAnimName:sub(1, 4) == "sing"

    if animIsSing then
        holdTimer = holdTimer + elapsed
    end

    local secondExists = spriteExist("second")

    if secondExists and jtcVocalsMutedForPunch and pendingVoiceUnmuteAllowed and curAnimName == "punched" and sprAnimFinished("second") then
        if setSongTrackBaseVolume ~= nil then
            if hasSongTrack ~= nil and hasSongTrack("jtcVocals") then
                setSongTrackBaseVolume("jtcVocals", 1)
            end
        end
        jtcVocalsMutedForPunch = false
    end

    if holdTimer > stepCrochet * crochetPitch * multipler then
        playSecondAnimation("idle")
        holdTimer = 0
    end

    if secondExists and not stunned and not animIsSing and sprAnimFinished("second") then
        if step == nil or step < 906 then
            playSecondAnimation("idle")
        else
            playSecondAnimation("idleExtra")
        end
    end

    shaderTransitionUpdate()
end

function onDestroy()
    if staticShaderActive and removeCameraShader ~= nil then
        removeCameraShader(STATIC_SHADER_CAMERA)
    end
end

function onResume()
    holdTimer = 0
end

function setupPunchHealth(amount)
    local punchIcons = {}
    local iconOffset = -10

    if downscroll then
        iconOffset = 10
    end

    for i = 1, amount do
        local iconX = getSpriteX("healthBarBG") + getSpriteWidth("healthBarBG") + 50
        local iconY = getMidpointY("healthBarBG") - 50

        createSprite("punchIcon" .. i)
        loadGraphic("punchIcon" .. i, "daddy_fist")
        setSpriteToCamera("punchIcon" .. i, "camHUD")
        scaleSprite("punchIcon" .. i, 0.7, 0.7)
        addSpriteToStage("punchIcon" .. i)
        setSpritePosition("punchIcon" .. i, iconX + (i - 1) * getSpriteWidth("punchIcon" .. i) * 1.05, iconY + iconOffset)
        table.insert(punchIcons, "punchIcon" .. i)
    end

    punchIconNames = punchIcons
    jtc_camera.registerHiddenSprites(punchIcons)
end
