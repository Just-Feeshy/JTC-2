local graffitiSprites = {}
local graffitiHas = {}
local graffitiRevealed = {}
local graffitiRevealTime = {}
local graffitiRevealActive = {}
local graffitiFading = {}
local graffitiBitmapWidths = {}
local graffitiBitmapHeights = {}
local graffitiCanName = "graffiti_can"
local activeGraffitiIndex = nil

local songCount = 0

local GRAFFITI_HEIGHT = 444
local GRAFFITI_Y_OFFSET = 0
local CAN_ANIM_DURATION = 1.0
local FREEPLAY_SECTOR_NAME = "freeplay_sector"
local FREEPLAY_REVEAL_SHADER = "freeplay_spray_reveal"
local SPRAY_NOZZLE_X = 886.943 / 1280.0
local SPRAY_NOZZLE_Y = 272.0 / 720.0
local SPRAY_RADIUS = 300
local SPRAY_START_ANGLE = math.pi - math.pi / 5
local SPRAY_END_ANGLE = math.pi + math.pi / 5
local SPRAY_EDGE_SOFTNESS = 0.42
local SPRAY_REVEAL_START = 0.035
local SPRAY_VISUAL_COLORS = "[0x58CFFFF0, 0x142C7FA8, 0x002C7FA8]"
local SPRAY_TRAIL_SHIFT = 84
local SPRAY_TRAIL_RADIUS = 64

function onCreate()
    destroyStuff()

    if initLuaShader ~= nil then
        initLuaShader(FREEPLAY_REVEAL_SHADER, "feeshdata")
    end

    if clearCameraBlur ~= nil then
        clearCameraBlur("cameraBackground")
    elseif setCameraBlur ~= nil then
        setCameraBlur("cameraBackground", 0)
    end

    if not spriteExist("wall") then
        createSprite("wall")
    end

    loadGraphic("wall", "Graffiti/wall")
    setSpritePosition("wall", 0, 0)
    setSpriteToCamera("wall", "cameraBackground")
    insertSpriteToState(0, "wall")

    createFreeplaySector()
    setupGraffiti()
end

function createFreeplaySector()
    if makeGradientSectorGraphic == nil and makeSectorGraphic == nil then
        return
    end

    if not spriteExist(FREEPLAY_SECTOR_NAME) then
        createSprite(FREEPLAY_SECTOR_NAME)
    end

    if makeGradientSectorGraphic ~= nil then
        makeGradientSectorGraphic(FREEPLAY_SECTOR_NAME, SPRAY_RADIUS, SPRAY_START_ANGLE, SPRAY_END_ANGLE, SPRAY_VISUAL_COLORS, 72)
    else
        makeSectorGraphic(FREEPLAY_SECTOR_NAME, SPRAY_RADIUS, SPRAY_START_ANGLE, SPRAY_END_ANGLE, "0x2867E5C6", 72)
    end

    setSpriteToCamera(FREEPLAY_SECTOR_NAME, "cameraFreeplay")
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
    updateGraffitiPositions()
    updateGraffitiAnimation(elapsed)
end

function onFreeplaySelectionChange(index, change)
    if index == nil then
        return
    end

    resetSprayCan()

    if not graffitiHas[index] then
        activeGraffitiIndex = index
        return
    end

    if graffitiRevealed[index] then
        activeGraffitiIndex = index
        return
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

    setSpriteAlpha(sprName, 1)
    graffitiRevealTime[index] = 0
    graffitiRevealActive[index] = true
    graffitiFading[index] = false
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
    setSpriteAlpha(FREEPLAY_SECTOR_NAME, 1)
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
        setShaderFloat(sprName, "curveScaleX", scaleX)
        setShaderFloat(sprName, "curveScaleY", scaleY)
        setShaderFloat(sprName, "trailShift", SPRAY_TRAIL_SHIFT * scaleX)
        setShaderFloat(sprName, "trailRadius", SPRAY_TRAIL_RADIUS * ((scaleX + scaleY) * 0.5))
        setShaderFloat(sprName, "edgeSoftness", SPRAY_EDGE_SOFTNESS)
        setShaderFloat(sprName, "sprayT", -5)
        setShaderFloat(sprName, "pathBaseX", 0)
        setShaderFloat(sprName, "pathBaseY", 0)
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
    local sectorX = pivotX - getSpriteWidth(FREEPLAY_SECTOR_NAME) / 2
    local sectorY = pivotY - getSpriteHeight(FREEPLAY_SECTOR_NAME) / 2

    setSpritePosition(FREEPLAY_SECTOR_NAME, sectorX, sectorY)
end

function updateSprayVisuals(index, canName, progress)
    local sprName = graffitiSprites[index]

    if sprName == nil or canName == nil then
        return
    end

    -- DO NOT TOUCH!! (This goes for other programmers)
    local gWidth = getSpriteWidth(sprName)
    local gHeight = getSpriteHeight(sprName)
    local curveMin = -5
    local curveMax = math.exp(math.pi)
    local t = curveMin + (curveMax - curveMin) * progress
    local xOffset = 2.0 * t * math.exp(t / 8.0)
    local yOffset = sprayY(t) + gHeight / 2.5

    setSpritePosition(canName, xOffset + gWidth / 4.0, yOffset)
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
    local curveMin = -5
    local curveMax = math.exp(math.pi)
    local sprayT = curveMin + (curveMax - curveMin) * progress

    setShaderFloat(sprName, "active", progress >= SPRAY_REVEAL_START and 1 or 0)
    setShaderFloat(sprName, "pathBaseX", pathBaseX)
    setShaderFloat(sprName, "pathBaseY", pathBaseY)
    setShaderFloat(sprName, "curveScaleX", scaleX)
    setShaderFloat(sprName, "curveScaleY", scaleY)
    setShaderFloat(sprName, "sprayT", sprayT)
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
                graffitiFading[i] = false
                graffitiRevealed[i] = true

                updateGraffitiRevealShader(i, canName)
                setSpriteAlpha(graffitiSprites[i], 1)

                if spriteExist(graffitiCanName) then
                    setSpriteAlpha(graffitiCanName, 0)
                end

                if spriteExist(FREEPLAY_SECTOR_NAME) then
                    setSpriteAlpha(FREEPLAY_SECTOR_NAME, 0)
                end

                activeGraffitiIndex = nil
            end
        end
    end
end

function destroyStuff()
    destroySprite("menuBG")
    destroySprite(FREEPLAY_SECTOR_NAME)
    destroySprite(graffitiCanName)
end
