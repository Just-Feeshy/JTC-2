local menu_background = {}

menu_background.IMAGE = "Graffiti/wall"
menu_background.SCALE = 1.02
menu_background.OVERLAY_COLOR = "0xFF000000"
menu_background.OVERLAY_ALPHA = 0.2

local function resolveSpriteName(primaryName, fallbackName)
    local spriteName = primaryName

    if not spriteExist(spriteName) then
        spriteName = fallbackName or primaryName

        if not spriteExist(spriteName) then
            createSprite(spriteName)
        end
    end

    return spriteName
end

local function finalizeSprite(spriteName, cameraName, insertIndex)
    if cameraName ~= nil then
        setSpriteToCamera(spriteName, cameraName)
    end

    if insertIndex ~= nil then
        removeSpriteFromState(spriteName)
        insertSpriteToState(insertIndex, spriteName)
    end
end

function menu_background.applyBackground(config)
    local spriteName = resolveSpriteName(config.background_name, config.fallback_background_name)
    local scale = config.scale or menu_background.SCALE

    loadGraphic(spriteName, config.image or menu_background.IMAGE)
    setSpriteSize(spriteName, math.floor(windowWidth * scale), math.floor(windowHeight * scale))
    setSpritePosition(spriteName, config.x or 0, config.y or 0)
    finalizeSprite(spriteName, config.camera, config.insert == false and nil or (config.background_index or 0))

    return spriteName
end

function menu_background.applyOverlay(config)
    local spriteName = resolveSpriteName(config.overlay_name, config.fallback_overlay_name)

    makeGraphic(spriteName, windowWidth, windowHeight, config.overlay_color or menu_background.OVERLAY_COLOR)
    setSpriteAlpha(spriteName, config.overlay_alpha or menu_background.OVERLAY_ALPHA)
    finalizeSprite(spriteName, config.camera, config.insert == false and nil or (config.overlay_index or 1))

    return spriteName
end

function menu_background.applyWithOverlay(config)
    menu_background.applyBackground(config)
    menu_background.applyOverlay(config)
end

return menu_background
