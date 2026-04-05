-- This is from the learned mistakes of frostbeat
-- I really screwed up the code for that song, it's just a jumbled mess

local school_mechanics = {}

-- Ok to touch variable
local BF_AND_GF_POS = {x = 0, y = -100}

-- Broken Variables (Don't touch)
local ARTBOARD_WIDTH = 2362
local ARTBOARD_HEIGHT = 1496
local STAGE_LAYOUT_SCALE_MULTIPLIER = 2.15
local DEFAULT_STAGE_CAMERA_ZOOM = 0.6
local STAGE_SAFE_FRAME_MULTIPLIER = 1.0
local DEFAULT_STAGE_CAMERA_FOCUS = {x = ARTBOARD_WIDTH * 0.5, y = ARTBOARD_HEIGHT * 0.505}
local DEFAULT_STAGE_CAMERA_FOCUS_LERP = 0.09
local DAD_LAYOUT = {x = 238, y = 520}
local GF_LAYOUT = {x = 1102, y = 786}
local BOYFRIEND_LAYOUT = {x = 1452, y = 908}
local PICO_PROP_LAYOUT = {x = 1478, y = 122}
local LITTLE_HEANCHY_LAYOUT = {x = 390, y = 430}

local stageScale = 1
local stageOriginX = 0
local stageOriginY = 0
local backInsertIndex = 0

local schoolSpeakerNames = {
    "schoolSpeakerLeftA",
    "schoolSpeakerLeftB",
    "schoolSpeakerCenterLeft",
    "schoolSpeakerCenterRight",
    "schoolSpeakerRightA",
    "schoolSpeakerRightB"
}

local schoolSpeakerLayout = {
    {x = 284, y = 30, angle = -17, flip = true},
    {x = 390, y = -6, angle = -7, flip = true},
    {x = 760, y = -20, angle = -2, flip = false},
    {x = 1148, y = -20, angle = 2, flip = false},
    {x = 1608, y = -6, angle = 7, flip = false},
    {x = 1718, y = 30, angle = 17, flip = false}
}

local function placeX(artX)
    return stageOriginX + (artX * stageScale)
end

local function placeY(artY)
    return stageOriginY + (artY * stageScale)
end

local function addBackSprite(name)
    insertSpriteToStage(backInsertIndex, name)
    backInsertIndex = backInsertIndex + 1
end

local function applyCharacterLayout()
    if spriteExist("dad") then
        setSpritePosition("dad", placeX(DAD_LAYOUT.x), placeY(DAD_LAYOUT.y))
    end

    if spriteExist("boyfriend") then
        setSpritePosition("boyfriend", placeX(BOYFRIEND_LAYOUT.x + BF_AND_GF_POS.x), placeY(BOYFRIEND_LAYOUT.y + BF_AND_GF_POS.y))
        scaleSprite("boyfriend", 1.2, 1.2)
    end

end

local function buildCharacterProps()
    createSprite("schoolGirlfriendProp")
    compileSpriteSheet("schoolGirlfriendProp", "school_house/Dearest_GF", "sparrow")
    addAnimationByPrefix("schoolGirlfriendProp", "idle", "gf full idle", 24, true)
    playAnim("schoolGirlfriendProp", "idle", true)
    setSpritePosition("schoolGirlfriendProp", placeX(GF_LAYOUT.x + BF_AND_GF_POS.x), placeY(GF_LAYOUT.y + BF_AND_GF_POS.y))

    createSprite("schoolPicoProp")
    compileSpriteSheet("schoolPicoProp", "school_house/Dearest_PICO_", "sparrow")
    addAnimationByPrefix("schoolPicoProp", "idle", "idle pico", 24, true)
    playAnim("schoolPicoProp", "idle", true)
    setSpritePosition("schoolPicoProp", placeX(PICO_PROP_LAYOUT.x), placeY(PICO_PROP_LAYOUT.y))
end

local function setupStageMetrics()
    stageScale = math.min(windowWidth / ARTBOARD_WIDTH, windowHeight / ARTBOARD_HEIGHT)
    stageScale = stageScale * STAGE_SAFE_FRAME_MULTIPLIER
    stageScale = stageScale * STAGE_LAYOUT_SCALE_MULTIPLIER
    stageOriginX = (windowWidth - (ARTBOARD_WIDTH * stageScale)) * 0.5
    stageOriginY = (windowHeight - (ARTBOARD_HEIGHT * stageScale)) * 0.5
    backInsertIndex = 0
end

local function addStaticLayer(name, asset, artX, artY, alpha, scaleMultiplier, centerInStage)
    createSprite(name)
    loadGraphic(name, asset)

    local finalScale = stageScale * (scaleMultiplier or 1)
    local finalX = placeX(artX)
    local finalY = placeY(artY)

    if centerInStage then
        local scaledWidth = getSpriteWidth(name) * finalScale
        local scaledHeight = getSpriteHeight(name) * finalScale
        local stageWidth = ARTBOARD_WIDTH * stageScale
        local stageHeight = ARTBOARD_HEIGHT * stageScale

        finalX = stageOriginX - ((scaledWidth - stageWidth) * 0.5)
        finalY = stageOriginY - ((scaledHeight - stageHeight) * 0.5)
    end

    scaleSprite(name, finalScale, finalScale)
    setSpritePosition(name, finalX, finalY)

    addBackSprite(name)
end

local function addAnimatedLayer(name, asset, animationName, prefix, artX, artY, scaleMultiplier, alpha, looped, fps)
    createSprite(name)
    compileSpriteSheet(name, asset, "sparrow")
    addAnimationByPrefix(name, animationName, prefix, fps or 24, looped ~= false)
    playAnim(name, animationName, true)
    scaleSprite(name, stageScale * (scaleMultiplier or 1), stageScale * (scaleMultiplier or 1))
    setSpritePosition(name, placeX(artX), placeY(artY))

    addBackSprite(name)
end

local function addLittleHeanchy()
    createSprite("schoolLittleHeanchy")
    compileSpriteSheet("schoolLittleHeanchy", "school_house/little heanchy", "sparrow")
    addAnimationByPrefix("schoolLittleHeanchy", "idle", "3 little guys", 14, true)
    playAnim("schoolLittleHeanchy", "idle", true)
    scaleSprite("schoolLittleHeanchy", stageScale * 0.82, stageScale * 0.82)
    setSpritePosition("schoolLittleHeanchy", placeX(LITTLE_HEANCHY_LAYOUT.x), placeY(LITTLE_HEANCHY_LAYOUT.y))
    addBackSprite("schoolLittleHeanchy")
end

local function buildSpeakers()
    local i = 1

    while i <= #schoolSpeakerNames do
        local name = schoolSpeakerNames[i]
        local layout = schoolSpeakerLayout[i]

        createSprite(name)
        compileSpriteSheet(name, "school_house/BG/Speaker bump", "sparrow")
        addAnimationByPrefix(name, "bump", "speaker bump", 24, true)
        playAnim(name, "bump", true)
        scaleSprite(name, stageScale * 0.28, stageScale * 0.28)
        setSpritePosition(name, placeX(layout.x), placeY(layout.y))
        setSpriteAngle(name, layout.angle)

        if layout.flip then
            spriteFlip(name, true, false)
        end

        addBackSprite(name)
        i = i + 1
    end
end

local function applyGameplayCameraSetup()
    setGameplayCameraFocus(placeX(DEFAULT_STAGE_CAMERA_FOCUS.x), placeY(DEFAULT_STAGE_CAMERA_FOCUS.y), true)
    setGameplayCameraFocusLerp(DEFAULT_STAGE_CAMERA_FOCUS_LERP)
    setGameplayCameraZoom(DEFAULT_STAGE_CAMERA_ZOOM, false, true)
end

function generatedStage()
	school_mechanics = require("mod_assets/scripts/components/school_mechanics")
	school_mechanics.onCreate()
    setOpponentAltAnim("")
    setCharacterIdleSuffix("dad", "")

    setupStageMetrics()
    applyCharacterLayout()
    applyGameplayCameraSetup()


    addStaticLayer("schoolHouseBG", "school_house/BG/BG", 0, 0, nil, 1.0, true)
    addStaticLayer("schoolWindowOutline", "school_house/BG/window outline", 953, 238)
    addAnimatedLayer("schoolEyes", "school_house/BG/Wood crack eyes", "idle", "wood crack eyes", 10, 724, 1, 0.82, true, 18)
    addLittleHeanchy()
    buildSpeakers()
    addStaticLayer("schoolWindowGlow", "school_house/BG/window blur", 838, 118, 0.88)
    addAnimatedLayer("schoolSmokeBack", "school_house/BG/Smoke", "idle", "bg smoke_ring_animation", 210, 736, 1, 0.72, true, 16)
    buildCharacterProps()
    addBackSprite("schoolGirlfriendProp")
    addBackSprite("schoolPicoProp")

    createSprite("schoolSmokeFront")
    compileSpriteSheet("schoolSmokeFront", "school_house/BG/Smoke2", "sparrow")
    addAnimationByPrefix("schoolSmokeFront", "idle", "fg smoke_ring_animation copy", 16, true)
    playAnim("schoolSmokeFront", "idle", true)
    scaleSprite("schoolSmokeFront", stageScale, stageScale)
    setSpritePosition("schoolSmokeFront", placeX(350), placeY(1320))
    addSpriteToStage("schoolSmokeFront")

    createSprite("schoolVignette")
    compileSpriteSheet("schoolVignette", "school_house/BG/Vignette", "sparrow")
    addAnimationByPrefix("schoolVignette", "idle", "Vignette01", 24, false)
    playAnim("schoolVignette", "idle", true)
    scaleSprite("schoolVignette", stageScale, stageScale)
    setSpritePosition("schoolVignette", placeX(0), placeY(0))
    addSpriteToStage("schoolVignette")
end

function onStepHit()
	school_mechanics.onStep(curStep)
end

function onBeatHit()
end

function onUpdate(elapsed)
	school_mechanics.onUpdate(elapsed)
end
