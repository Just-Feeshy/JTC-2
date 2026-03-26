
-- From Just-Feeshy: Thank you so much FLX (aka. Erdene or Kira) for designing the Freeplay Menu
-- Very talented UI/UX programmer, go check him out! (https://erdene.dev/)

local menu_music = require("mod_assets/scripts/utils/menuMusic")

local graffitiSprites = {}
local graffitiHas = {}
local graffitiRevealed = {}
local graffitiRevealTime = {}
local graffitiRevealActive = {}
local graffitiFading = {}
local graffitiFullRevealTime = {}
local graffitiBitmapWidths = {}
local graffitiBitmapHeights = {}
local graffitiCanName = "graffiti_can"
local activeGraffitiIndex = nil
local TOP_SECTION_CARET = "freeplay_section_caret_top"
local BOTTOM_SECTION_CARET = "freeplay_section_caret_bottom"
local TOP_SECTION_CARET_OUT_TWEEN = "freeplaySectionCaretTopOut"
local BOTTOM_SECTION_CARET_OUT_TWEEN = "freeplaySectionCaretBottomOut"
local TOP_SECTION_CARET_BACK_TWEEN = "freeplaySectionCaretTopBack"
local BOTTOM_SECTION_CARET_BACK_TWEEN = "freeplaySectionCaretBottomBack"
local SECTION_CARET_TEXT = "^"
local SECTION_CARET_SIZE = 116
local SECTION_CARET_TOP_Y = 8
local SECTION_CARET_BOTTOM_MARGIN = 142
local SECTION_CARET_BUMP = 18
local SECTION_CARET_COLOR = "0xFFFFFFFF"
local SECTION_CARET_BORDER_COLOR = "0xFF000000"
local SECTION_CARET_BORDER_SIZE = 4

local songCount = 0
local topSectionCaretBaseY = SECTION_CARET_TOP_Y
local bottomSectionCaretBaseY = 0

local BASE_SPRAY_CURVE_MIN = -5
local BASE_SPRAY_CURVE_MAX = math.exp(math.pi)
local SPRAY_CURVE_MIN = BASE_SPRAY_CURVE_MIN
local SPRAY_CURVE_MAX = BASE_SPRAY_CURVE_MAX * 1.32
local SPRAY_DURATION_SCALE = (SPRAY_CURVE_MAX - SPRAY_CURVE_MIN) / (BASE_SPRAY_CURVE_MAX - BASE_SPRAY_CURVE_MIN)

local GRAFFITI_HEIGHT = 444
local GRAFFITI_Y_OFFSET = 0
local CAN_ANIM_DURATION = 1.0 * SPRAY_DURATION_SCALE
local FULL_REVEAL_DURATION = 0.2
local FREEPLAY_SECTOR_NAME = "freeplay_sector"
local FREEPLAY_REVEAL_SHADER = "freeplay_spray_reveal"
local SHOW_SPRAY_VISUAL = true
local SPRAY_VISUAL_BASE_WIDTH = 0
local SPRAY_VISUAL_BASE_HEIGHT = 0
local SPRAY_NOZZLE_X = 886.943 / 1280.0
local SPRAY_NOZZLE_Y = 272.0 / 720.0
local SPRAY_RADIUS = 300
local SPRAY_EDGE_SOFTNESS = 0.42
local SPRAY_REVEAL_START = 0.035
local SPRAY_VISUAL_ALPHA = 0.45
local SPRAY_VISUAL_COLOR = "0xFF26F7FD"
local SPRAY_VISUAL_PIVOT_X = 1.06
local SPRAY_VISUAL_PIVOT_Y = 0.55
local SPRAY_VISUAL_SCALE_MIN = 0.82
local SPRAY_VISUAL_SCALE_MAX = 1.14
local SPRAY_TRAIL_SHIFT = 275
local SPRAY_TRAIL_START_RADIUS = 112
local SPRAY_TRAIL_RADIUS = 224

local function curveStep(edge0, edge1, value)
    if edge0 == edge1 then
        return value >= edge1 and 1 or 0
    end

    local t = (value - edge0) / (edge1 - edge0)
    t = math.max(0, math.min(t, 1))
    return t * t * (3 - 2 * t)
end

function onCreate()
    destroyStuff()
    menu_music.markInactive()

    local backgroundBlur = menuBackgroundBlur or 0

    if initLuaShader ~= nil then
        initLuaShader(FREEPLAY_REVEAL_SHADER, "shaders")
    end

    if backgroundBlur > 0 and setCameraBlur ~= nil then
        setCameraBlur("cameraBackground", backgroundBlur)
    elseif clearCameraBlur ~= nil then
        clearCameraBlur("cameraBackground")
    elseif setCameraBlur ~= nil then
        setCameraBlur("cameraBackground", 0)
    end

    createFreeplaySector()
    createSectionCarets()
    setupGraffiti()
end

function createSectionCarets()
    if createText == nil then
        return
    end

    bottomSectionCaretBaseY = windowHeight - SECTION_CARET_BOTTOM_MARGIN

    createText(TOP_SECTION_CARET, 0, topSectionCaretBaseY, 0, SECTION_CARET_TEXT, SECTION_CARET_SIZE)
    setTextFont(TOP_SECTION_CARET, "PhantomMuff.ttf")
    setTextSize(TOP_SECTION_CARET, SECTION_CARET_SIZE)
    setText(TOP_SECTION_CARET, SECTION_CARET_TEXT)
    if setTextColor ~= nil then
        setTextColor(TOP_SECTION_CARET, SECTION_CARET_COLOR)
    else
        setSpriteColor(TOP_SECTION_CARET, SECTION_CARET_COLOR)
    end
    if setTextBorder ~= nil then
        setTextBorder(TOP_SECTION_CARET, "outline", SECTION_CARET_BORDER_SIZE, SECTION_CARET_BORDER_COLOR)
    end
    setSpriteToCamera(TOP_SECTION_CARET, "cameraFreeplay")
    addSpriteToState(TOP_SECTION_CARET)
    centerSectionCaret(TOP_SECTION_CARET, topSectionCaretBaseY)

    createText(BOTTOM_SECTION_CARET, 0, bottomSectionCaretBaseY, 0, SECTION_CARET_TEXT, SECTION_CARET_SIZE)
    setTextFont(BOTTOM_SECTION_CARET, "PhantomMuff.ttf")
    setTextSize(BOTTOM_SECTION_CARET, SECTION_CARET_SIZE)
    setText(BOTTOM_SECTION_CARET, SECTION_CARET_TEXT)
    if setTextColor ~= nil then
        setTextColor(BOTTOM_SECTION_CARET, SECTION_CARET_COLOR)
    else
        setSpriteColor(BOTTOM_SECTION_CARET, SECTION_CARET_COLOR)
    end
    if setTextBorder ~= nil then
        setTextBorder(BOTTOM_SECTION_CARET, "outline", SECTION_CARET_BORDER_SIZE, SECTION_CARET_BORDER_COLOR)
    end
    setSpriteToCamera(BOTTOM_SECTION_CARET, "cameraFreeplay")
    addSpriteToState(BOTTOM_SECTION_CARET)
    setSpriteAngle(BOTTOM_SECTION_CARET, 180)
    centerSectionCaret(BOTTOM_SECTION_CARET, bottomSectionCaretBaseY)
end

function centerSectionCaret(name, y)
    local width = getSpriteWidth(name)
    local x = (windowWidth - width) * 0.5
    setSpritePosition(name, x, y)
end

function bumpSectionCarets(change)
    if change == nil or change == 0 then
        return
    end

    if change < 0 then
        nudgeSectionCaret(TOP_SECTION_CARET, topSectionCaretBaseY, -SECTION_CARET_BUMP, TOP_SECTION_CARET_OUT_TWEEN)
    elseif change > 0 then
        nudgeSectionCaret(BOTTOM_SECTION_CARET, bottomSectionCaretBaseY, SECTION_CARET_BUMP, BOTTOM_SECTION_CARET_OUT_TWEEN)
    end
end

function nudgeSectionCaret(name, baseY, offset, tweenName)
    if not spriteExist(name) then
        return
    end

    cancelTween(tweenName)

    if tweenName == TOP_SECTION_CARET_OUT_TWEEN then
        cancelTween(TOP_SECTION_CARET_BACK_TWEEN)
    else
        cancelTween(BOTTOM_SECTION_CARET_BACK_TWEEN)
    end

    setSpriteY(name, baseY)
    doTweenY(tweenName, name, baseY + offset, 0.07, "quadOut")
end

function createFreeplaySector()
    if not SHOW_SPRAY_VISUAL or compileSpriteSheet == nil or playAnimationByPrefix == nil then
        return
    end

    if not spriteExist(FREEPLAY_SECTOR_NAME) then
        createSprite(FREEPLAY_SECTOR_NAME)
    end

    compileSpriteSheet(FREEPLAY_SECTOR_NAME, "Graffiti/Fart", "sparrow")
    playAnimationByPrefix(FREEPLAY_SECTOR_NAME, "loop", "fart", 24, true)

    local fartWidth = getSpriteWidth(FREEPLAY_SECTOR_NAME)
    local fartHeight = getSpriteHeight(FREEPLAY_SECTOR_NAME)
    if fartWidth > 0 and fartHeight > 0 then
        local targetWidth = math.floor(SPRAY_RADIUS * 1.2)
        local targetHeight = math.floor(fartHeight * (targetWidth / fartWidth))
        SPRAY_VISUAL_BASE_WIDTH = targetWidth
        SPRAY_VISUAL_BASE_HEIGHT = targetHeight
        setSpriteSize(FREEPLAY_SECTOR_NAME, targetWidth, targetHeight)
    end

    setSpriteToCamera(FREEPLAY_SECTOR_NAME, "cameraFreeplay")
    setSpriteColor(FREEPLAY_SECTOR_NAME, SPRAY_VISUAL_COLOR)
    setSpriteAlpha(FREEPLAY_SECTOR_NAME, 0)
    addSpriteToState(FREEPLAY_SECTOR_NAME)
end

function setupGraffiti()
    if getFreeplaySongCount == nil then
        return
    end

    songCount = getFreeplaySongCount()

    for i = 0, songCount - 1 do
        if setFreeplayAlphabetVisible ~= nil then
            setFreeplayAlphabetVisible(i, false)
        end

        if setFreeplayAlphabetAlpha ~= nil then
            setFreeplayAlphabetAlpha(i, 0)
        end

        local hasCustom = hasFreeplayGraffiti ~= nil and hasFreeplayGraffiti(i)

        if hasCustom then
            local sprName = "graffiti_" .. i
            createSprite(sprName)
            local songName = string.lower(getFreeplaySongName(i))
            local imagePath = "Graffiti/" .. songName
            local bmpWidth = getImageWidth(imagePath)
            local bmpHeight = getImageHeight(imagePath)
            loadGraphic(sprName, imagePath)
            setSpriteToCamera(sprName, "cameraFreeplay")
            addSpriteToState(sprName)

            if bmpHeight > 0 then
                local scale = GRAFFITI_HEIGHT / bmpHeight
                local newWidth = math.floor(bmpWidth * scale)
                local newHeight = math.floor(bmpHeight * scale)
                setSpriteSize(sprName, newWidth, newHeight)
            end

            setSpriteAlpha(sprName, 0)
            graffitiSprites[i] = sprName
            graffitiBitmapWidths[i] = bmpWidth
            graffitiBitmapHeights[i] = bmpHeight
            graffitiHas[i] = true
            graffitiRevealed[i] = false
            graffitiRevealTime[i] = 0
            graffitiRevealActive[i] = false
            graffitiFading[i] = false
            graffitiFullRevealTime[i] = 0
        else
            graffitiHas[i] = false
            graffitiRevealed[i] = true
        end

        local iconName = "freeplayIcon_" .. i
        if spriteExist(iconName) then
            setSpriteAlpha(iconName, 0)

            if removeSpriteFromState ~= nil then
                removeSpriteFromState(iconName)
            end
        end
    end
end

function onUpdate(elapsed)
    updateGraffitiAnimation(elapsed)
end

function onFreeplaySelectionChange(index, change)
    if index == nil then
        return
    end

    bumpSectionCarets(change)

    resetSprayCan()

    if not graffitiHas[index] then
        activeGraffitiIndex = index
        return
    end

    graffitiRevealed[index] = false
    graffitiRevealActive[index] = false
    graffitiFading[index] = false
    graffitiRevealTime[index] = 0
    graffitiFullRevealTime[index] = 0

    local sprName = graffitiSprites[index]
    if sprName ~= nil then
        clearGraffitiRevealShader(index)
        setSpriteAlpha(sprName, 0)
    end

    startGraffitiReveal(index)
end

function onTweenCompleted(tag)
    local prefix = "graffitiFade_"
    if string.sub(tag, 1, #prefix) == prefix then
        local index = tonumber(string.sub(tag, #prefix + 1))

        if index ~= nil then
            graffitiFading[index] = false
            graffitiRevealed[index] = true
            setSpriteAlpha(graffitiSprites[index], 1)
        end
    elseif tag == TOP_SECTION_CARET_OUT_TWEEN then
        doTweenY(TOP_SECTION_CARET_BACK_TWEEN, TOP_SECTION_CARET, topSectionCaretBaseY, 0.14, "backOut")
    elseif tag == BOTTOM_SECTION_CARET_OUT_TWEEN then
        doTweenY(BOTTOM_SECTION_CARET_BACK_TWEEN, BOTTOM_SECTION_CARET, bottomSectionCaretBaseY, 0.14, "backOut")
    end
end

function updateGraffitiPositions()
    if songCount <= 0 or getFreeplayAlphabetInfo == nil then
        return
    end

    local selectedIndex = getFreeplaySelection ~= nil and getFreeplaySelection() or activeGraffitiIndex

    for i = 0, songCount - 1 do
        local sprName = graffitiSprites[i]

        if sprName ~= nil then
            local width = getSpriteWidth(sprName)
            local height = getSpriteHeight(sprName)
            local x = (windowWidth - width) / 2
            local y = (windowHeight - height) / 2 + GRAFFITI_Y_OFFSET

            setSpritePosition(sprName, x, y)

            if i ~= selectedIndex then
                setSpriteAlpha(sprName, 0)
            elseif graffitiRevealActive[i] then
                setSpriteAlpha(sprName, 1)
            elseif graffitiRevealed[i] and not graffitiFading[i] then
                setSpriteAlpha(sprName, 1)
            end
        end
    end
end

function positionGraffiti(index)
    local sprName = graffitiSprites[index]

    if sprName == nil then
        return
    end

    local width = getSpriteWidth(sprName)
    local height = getSpriteHeight(sprName)
    local x = (windowWidth - width) / 2
    local y = (windowHeight - height) / 2 + GRAFFITI_Y_OFFSET

    setSpritePosition(sprName, x, y)
end

function startGraffitiReveal(index)
    if not graffitiHas[index] then
        activeGraffitiIndex = nil
        return
    end

    if graffitiRevealed[index] or graffitiRevealActive[index] then
        activeGraffitiIndex = index
        return
    end

    local sprName = graffitiSprites[index]
    if sprName == nil then
        return
    end

    positionGraffiti(index)
    setSpriteAlpha(sprName, 1)
    graffitiRevealTime[index] = 0

    if playSoundAt ~= nil then
        playSoundAt("spray", 1500, 2, "freeplaySpray")
    elseif playSound ~= nil then
        playSound("spray", 2, "freeplaySpray")
    end

    graffitiRevealActive[index] = true
    graffitiFading[index] = false
    graffitiFullRevealTime[index] = 0
    prepareGraffitiRevealShader(index)

    ensureSprayCan()
    local canName = graffitiCanName
    bringSprayVisualsToFront()

    local targetHeight = getSpriteHeight(sprName)
    local currentHeight = getSpriteHeight(canName)
    if currentHeight > 0 and targetHeight > 0 then
        local scale = targetHeight / currentHeight
        local newWidth = math.floor(getSpriteWidth(canName) * scale)
        local newHeight = math.floor(currentHeight * scale)
        setSpriteSize(canName, newWidth, newHeight)
    end

    setSpriteAlpha(canName, 1)
    updateSprayVisuals(index, canName, 0)
    if spriteExist(FREEPLAY_SECTOR_NAME) then
        playAnimationByPrefix(FREEPLAY_SECTOR_NAME, "loop", "fart", 48, true)
        setSpriteAlpha(FREEPLAY_SECTOR_NAME, SPRAY_VISUAL_ALPHA)
    end
    activeGraffitiIndex = index
end

function ensureSprayCan()
    if not spriteExist(graffitiCanName) then
        createSprite(graffitiCanName)
        loadGraphic(graffitiCanName, "Graffiti/can")
        setSpriteToCamera(graffitiCanName, "cameraFreeplay")
        addSpriteToState(graffitiCanName)
    end
end

function resetSprayCan()
    if activeGraffitiIndex ~= nil then
        local previousIndex = activeGraffitiIndex
        graffitiRevealActive[previousIndex] = false
        graffitiFading[previousIndex] = false

        if not graffitiRevealed[previousIndex] then
            clearGraffitiRevealShader(previousIndex)
            local previousSprite = graffitiSprites[previousIndex]
            if previousSprite ~= nil then
                setSpriteAlpha(previousSprite, 0)
            end
        end
    end

    if spriteExist(graffitiCanName) then
        setSpriteAlpha(graffitiCanName, 0)
    end

    if spriteExist(FREEPLAY_SECTOR_NAME) then
        setSpriteAlpha(FREEPLAY_SECTOR_NAME, 0)
    end

    activeGraffitiIndex = nil
end

function bringSprayVisualsToFront()
    if removeSpriteFromState ~= nil then
        if spriteExist(FREEPLAY_SECTOR_NAME) then
            removeSpriteFromState(FREEPLAY_SECTOR_NAME)
        end

        if spriteExist(graffitiCanName) then
            removeSpriteFromState(graffitiCanName)
        end
    end

    if spriteExist(FREEPLAY_SECTOR_NAME) then
        addSpriteToState(FREEPLAY_SECTOR_NAME)
    end

    if spriteExist(graffitiCanName) then
        addSpriteToState(graffitiCanName)
    end
end

function prepareGraffitiRevealShader(index)
    local sprName = graffitiSprites[index]

    if sprName == nil or setSpriteShader == nil then
        return
    end

    setSpriteShader(sprName, FREEPLAY_REVEAL_SHADER)

    local spriteWidth = math.max(getSpriteWidth(sprName), 1)
    local spriteHeight = math.max(getSpriteHeight(sprName), 1)
    local sourceWidth = math.max(graffitiBitmapWidths[index] or spriteWidth, 1)
    local sourceHeight = math.max(graffitiBitmapHeights[index] or spriteHeight, 1)
    local scaleX = sourceWidth / spriteWidth
    local scaleY = sourceHeight / spriteHeight

    if setShaderFloat ~= nil then
        setShaderFloat(sprName, "active", 0)
        setShaderFloat2(sprName, "curveScale", scaleX, scaleY)
        setShaderFloat(sprName, "trailShift", SPRAY_TRAIL_SHIFT * scaleX)
        setShaderFloat(sprName, "trailRadius", SPRAY_TRAIL_START_RADIUS * ((scaleX + scaleY) * 0.5))
        setShaderFloat(sprName, "edgeSoftness", SPRAY_EDGE_SOFTNESS)
        setShaderFloat(sprName, "fullReveal", 0)
        setShaderFloat(sprName, "sprayT", -5)
        setShaderFloat2(sprName, "pathBase", 0, 0)
    end
end

function clearGraffitiRevealShader(index)
    local sprName = graffitiSprites[index]

    if sprName == nil then
        return
    end

    if removeSpriteShader ~= nil then
        removeSpriteShader(sprName)
    end
end

function updateSpraySector(canName)
    if not spriteExist(FREEPLAY_SECTOR_NAME) or not spriteExist(canName) then
        return
    end

    local pivotX = getSpriteX(canName) + getSpriteWidth(canName) * SPRAY_NOZZLE_X
    local pivotY = getSpriteY(canName) + getSpriteHeight(canName) * SPRAY_NOZZLE_Y
    local sectorX = pivotX - getSpriteWidth(FREEPLAY_SECTOR_NAME) * SPRAY_VISUAL_PIVOT_X
    local sectorY = pivotY - getSpriteHeight(FREEPLAY_SECTOR_NAME) * SPRAY_VISUAL_PIVOT_Y

    setSpritePosition(FREEPLAY_SECTOR_NAME, sectorX, sectorY)
end

function updateSprayScale(progress)
    if not spriteExist(FREEPLAY_SECTOR_NAME) then
        return
    end

    if SPRAY_VISUAL_BASE_WIDTH <= 0 or SPRAY_VISUAL_BASE_HEIGHT <= 0 then
        return
    end

    local grow = curveStep(0.0, 0.07, progress)
    local shrink = curveStep(0.07, 0.58, progress)
    local pulse = grow - shrink
    local scale = SPRAY_VISUAL_SCALE_MIN + (SPRAY_VISUAL_SCALE_MAX - SPRAY_VISUAL_SCALE_MIN) * pulse

    setSpriteSize(
        FREEPLAY_SECTOR_NAME,
        math.floor(SPRAY_VISUAL_BASE_WIDTH * scale),
        math.floor(SPRAY_VISUAL_BASE_HEIGHT * scale)
    )
end

function updateSprayVisuals(index, canName, progress)
    local sprName = graffitiSprites[index]

    if sprName == nil or canName == nil then
        return
    end

    -- DO NOT TOUCH!! (This goes for other programmers)
    local gWidth = getSpriteWidth(sprName)
    local gHeight = getSpriteHeight(sprName)
    local t = SPRAY_CURVE_MIN + (SPRAY_CURVE_MAX - SPRAY_CURVE_MIN) * progress
    local xOffset = t * math.exp(t / 8.0)
    local yOffset = sprayY(t) + gHeight / 2.5

    setSpritePosition(canName, xOffset + gWidth / 4.0, yOffset)
    updateSprayScale(progress)
    updateSpraySector(canName)
end

function updateGraffitiRevealShader(index, canName)
    local sprName = graffitiSprites[index]
    local bitmapWidth = graffitiBitmapWidths[index]
    local bitmapHeight = graffitiBitmapHeights[index]

    if sprName == nil or setShaderFloat == nil then
        return
    end

    local spriteWidth = math.max(getSpriteWidth(sprName), 1)
    local spriteHeight = math.max(getSpriteHeight(sprName), 1)
    local sourceWidth = math.max(bitmapWidth or spriteWidth, 1)
    local sourceHeight = math.max(bitmapHeight or spriteHeight, 1)
    local scaleX = sourceWidth / spriteWidth
    local scaleY = sourceHeight / spriteHeight
    local gWidth = spriteWidth
    local gHeight = spriteHeight
    local canWidth = getSpriteWidth(canName)
    local canHeight = getSpriteHeight(canName)
    local pathBaseX = (gWidth / 4.0 + canWidth * SPRAY_NOZZLE_X - getSpriteX(sprName)) * scaleX
    local pathBaseY = (gHeight / 2.5 + canHeight * SPRAY_NOZZLE_Y - getSpriteY(sprName)) * scaleY
    local progress = math.min(graffitiRevealTime[index] / CAN_ANIM_DURATION, 1)
    local sprayT = SPRAY_CURVE_MIN + (SPRAY_CURVE_MAX - SPRAY_CURVE_MIN) * progress
    local radiusProgress = math.max(0, (progress - SPRAY_REVEAL_START) / (1 - SPRAY_REVEAL_START))
    local easedRadiusProgress = math.pow(math.min(radiusProgress, 1), 4)
    local trailRadius = (SPRAY_TRAIL_START_RADIUS + (SPRAY_TRAIL_RADIUS - SPRAY_TRAIL_START_RADIUS) * easedRadiusProgress) * ((scaleX + scaleY) * 0.5)

    setShaderFloat(sprName, "active", progress >= SPRAY_REVEAL_START and 1 or 0)
    setShaderFloat2(sprName, "pathBase", pathBaseX, pathBaseY)
    setShaderFloat2(sprName, "curveScale", scaleX, scaleY)
    setShaderFloat(sprName, "trailRadius", trailRadius)
    setShaderFloat(sprName, "fullReveal", 0)
    setShaderFloat(sprName, "sprayT", sprayT)
end

function updateGraffitiFullReveal(index, progress)
    local sprName = graffitiSprites[index]

    if sprName == nil or setShaderFloat == nil then
        return
    end

    setShaderFloat(sprName, "active", 1)
    setShaderFloat(sprName, "fullReveal", math.min(math.max(progress, 0), 1))
end

function smin(a, b, k_0)
    local k = k_0 * 2.0
    local x = b - a
    return 0.5*( a+b-math.sqrt(x*x+k*k) )
end

function logChirp(x, a, b, n)
    local shift = math.exp(-(2.0 * n) / 8.0)
    local u = x / b + shift
    local phase = a * math.log(u)
    local env = math.exp(0.5 - (x / (b * n)))
    return 6.0 * env * math.cos(phase / 3.0)
end

function sprayY(x)
    local yOffset = 18.0 * logChirp(math.max(x,0.001) + 3.0 * math.pi / 2.0, 48.0, 24.0, math.pi)
    return -smin(yOffset, 150 * x + 170, 10)
end

function updateGraffitiAnimation(elapsed)
    if songCount <= 0 or getFreeplayAlphabetInfo == nil then
        return
    end

    for i = 0, songCount - 1 do
        if graffitiRevealActive[i] and graffitiSprites[i] ~= nil and activeGraffitiIndex == i then
            local info = getFreeplayAlphabetInfo(i)
            local canName = graffitiCanName

            if info ~= nil and canName ~= nil then
                graffitiRevealTime[i] = graffitiRevealTime[i] + elapsed
                local progress = math.min(graffitiRevealTime[i] / CAN_ANIM_DURATION, 1)

                updateSprayVisuals(i, canName, progress)
                updateGraffitiRevealShader(i, canName)
            end

            if graffitiRevealTime[i] >= CAN_ANIM_DURATION then
                graffitiRevealActive[i] = false
                graffitiFading[i] = true
                graffitiFullRevealTime[i] = 0

                updateGraffitiRevealShader(i, canName)
                setSpriteAlpha(graffitiSprites[i], 1)

                if spriteExist(graffitiCanName) then
                    setSpriteAlpha(graffitiCanName, 0)
                end

                if spriteExist(FREEPLAY_SECTOR_NAME) then
                    setSpriteAlpha(FREEPLAY_SECTOR_NAME, 0)
                end
            end
        end

        if graffitiFading[i] and graffitiSprites[i] ~= nil then
            graffitiFullRevealTime[i] = graffitiFullRevealTime[i] + elapsed
            local revealProgress = math.min(graffitiFullRevealTime[i] / FULL_REVEAL_DURATION, 1)
            updateGraffitiFullReveal(i, revealProgress)

            if revealProgress >= 1 then
                graffitiFading[i] = false
                graffitiRevealed[i] = true
                clearGraffitiRevealShader(i)
                setSpriteAlpha(graffitiSprites[i], 1)

                if activeGraffitiIndex == i then
                    activeGraffitiIndex = nil
                end
            end
        end
    end
end

function destroyStuff()
    destroySprite(FREEPLAY_SECTOR_NAME)
    destroySprite(graffitiCanName)
    destroySprite(TOP_SECTION_CARET)
    destroySprite(BOTTOM_SECTION_CARET)
end
