local graffitiSprites = {}
local graffitiHas = {}
local graffitiRevealed = {}
local graffitiRevealTime = {}
local graffitiRevealActive = {}
local graffitiFading = {}
local graffitiCans = {}

local songCount = 0

local GRAFFITI_HEIGHT = 444
local GRAFFITI_Y_OFFSET = 0
local DEFAULT_SPACING = 320
local CAN_ANIM_DURATION = 1.0

function onCreate()
    destroyStuff()

    if not spriteExist("wall") then
        createSprite("wall")
    end

    loadGraphic("wall", "Graffiti/wall")
    setSpritePosition("wall", 0, 0)
    setSpriteToCamera("wall", "cameraBackground")
    insertSpriteToState(0, "wall")

    setupGraffiti()
end

function setupGraffiti()
    if getFreeplaySongCount == nil then
        return
    end

    songCount = getFreeplaySongCount()

    for i = 0, songCount - 1 do
        local hasCustom = hasFreeplayGraffiti ~= nil and hasFreeplayGraffiti(i)

        if hasCustom then
            local sprName = "graffiti_" .. i
            createSprite(sprName)
            local songName = string.lower(getFreeplaySongName(i))
            loadGraphic(sprName, "Graffiti/" .. songName)
            setSpriteToCamera(sprName, "cameraFreeplay")
            addSpriteToState(sprName)

            local currentHeight = getSpriteHeight(sprName)
            if currentHeight > 0 then
                local scale = GRAFFITI_HEIGHT / currentHeight
                local newWidth = math.floor(getSpriteWidth(sprName) * scale)
                local newHeight = math.floor(currentHeight * scale)
                setSpriteSize(sprName, newWidth, newHeight)
            end

            setSpriteAlpha(sprName, 0)
            graffitiSprites[i] = sprName
            graffitiHas[i] = true
            graffitiRevealed[i] = false
            graffitiRevealTime[i] = 0
            graffitiRevealActive[i] = false
            graffitiFading[i] = false

            if setFreeplayAlphabetVisible ~= nil then
                setFreeplayAlphabetVisible(i, false)
            end
        else
            graffitiHas[i] = false
            graffitiRevealed[i] = true
        end

        if setFreeplayAlphabetYMultiplier ~= nil then
            setFreeplayAlphabetYMultiplier(i, DEFAULT_SPACING)
        end

        local iconName = "freeplayIcon_" .. i
        if spriteExist(iconName) then
            setSpriteAlpha(iconName, 0)
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

    for i = 0, songCount - 1 do
        local info = getFreeplayAlphabetInfo(i)
        local sprName = graffitiSprites[i]

        if info ~= nil and sprName ~= nil then
            local width = getSpriteWidth(sprName)
            local height = getSpriteHeight(sprName)
            local x = (windowWidth - width) / 2
            local y = info.y + (info.height - height) / 2 + GRAFFITI_Y_OFFSET
            setSpritePosition(sprName, x, y)

            if graffitiRevealed[i] and not graffitiFading[i] then
                setSpriteAlpha(sprName, info.alpha)
            end
        end
    end
end

function startGraffitiReveal(index)
    if not graffitiHas[index] then
        return
    end

    if graffitiRevealed[index] or graffitiRevealActive[index] then
        return
    end

    local sprName = graffitiSprites[index]
    if sprName == nil then
        return
    end

    setSpriteAlpha(sprName, 0)
    graffitiRevealTime[index] = 0
    graffitiRevealActive[index] = true

    local canName = "graffiti_can_" .. index
    createSprite(canName)
    loadGraphic(canName, "Graffiti/can")
    setSpriteToCamera(canName, "cameraFreeplay")
    addSpriteToState(canName)

    local targetHeight = getSpriteHeight(sprName) * 2
    local currentHeight = getSpriteHeight(canName)
    if currentHeight > 0 and targetHeight > 0 then
        local scale = targetHeight / currentHeight
        local newWidth = math.floor(getSpriteWidth(canName) * scale)
        local newHeight = math.floor(currentHeight * scale)
        setSpriteSize(canName, newWidth, newHeight)
    end

    graffitiCans[index] = canName
end

function updateGraffitiAnimation(elapsed)
    if songCount <= 0 or getFreeplayAlphabetInfo == nil then
        return
    end

    for i = 0, songCount - 1 do
        if graffitiRevealActive[i] and graffitiSprites[i] ~= nil then
            local info = getFreeplayAlphabetInfo(i)
            local canName = graffitiCans[i]

            if info ~= nil and canName ~= nil then
                graffitiRevealTime[i] = graffitiRevealTime[i] + elapsed
                local t = math.min(graffitiRevealTime[i] / CAN_ANIM_DURATION, 1)

                local gWidth = getSpriteWidth(graffitiSprites[i])
                local gHeight = getSpriteHeight(graffitiSprites[i])
                local canWidth = getSpriteWidth(canName)
                local left = (windowWidth - gWidth) / 2 - canWidth * 0.5
                local midY = info.y + info.height / 2
                local xOffset = gWidth * t
                local yOffset = logChirp(t * 48.0, 48.0, 24.0, 1.0, math.max(6.0, gHeight * 0.06))

                setSpritePosition(canName, left + xOffset, midY + yOffset - getSpriteHeight(canName) / 2)
            end

            if graffitiRevealTime[i] >= CAN_ANIM_DURATION then
                graffitiRevealActive[i] = false
                graffitiFading[i] = true
                local fadeTag = "graffitiFade_" .. i
                doTweenAlpha(fadeTag, graffitiSprites[i], 1, 0.4, "quadOut")

                if canName ~= nil then
                    destroySprite(canName)
                    graffitiCans[i] = nil
                end
            end
        end
    end
end

function logChirp(x, a, b, n, A)
    local shift = math.exp(-4.0 * math.pi / a)
    local u = x / b + shift
    local phase = a * math.log(u)
    local env = math.exp(0.5 - (x / (b * n)))
    return A * 4.0 * env * math.sin(phase)
end

function destroyStuff()
    destroySprite("menuBG")
end
