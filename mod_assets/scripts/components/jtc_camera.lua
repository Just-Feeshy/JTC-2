local jtc_camera = {}

local gameplayCameras = {
    "camGame",
    "camNOTE",
    "camNoteSustain"
}

local defaultHiddenSprites = {
    "healthBarBG",
    "healthBar",
    "iconP1",
    "iconP2",
    "counterTxt",
    "debugText"
}

jtc_camera.revealStep = nil
jtc_camera.hidden = false
jtc_camera.hiddenSprites = {}
jtc_camera.showNoteCamerasOnReveal = true

local function setGameplayVisibility(gameVisible, noteVisible)
    setCameraVisible("camGame", gameVisible)
    setCameraVisible("camNOTE", noteVisible)
    setCameraVisible("camNoteSustain", noteVisible)
end

local function setSpriteVisibility(spriteName, visible)
    setCustomFieldToSprite(spriteName, "visible", visible)
end

local function spriteNameExists(spriteName)
    for _, existingName in ipairs(jtc_camera.hiddenSprites) do
        if existingName == spriteName then
            return true
        end
    end

    return false
end

local function setManagedSpriteVisibility(visible)
    for _, spriteName in ipairs(defaultHiddenSprites) do
        setSpriteVisibility(spriteName, visible)
    end

    for _, spriteName in ipairs(jtc_camera.hiddenSprites) do
        setSpriteVisibility(spriteName, visible)
    end
end

function jtc_camera.reset()
    jtc_camera.revealStep = nil
    jtc_camera.hidden = false
    jtc_camera.hiddenSprites = {}
    jtc_camera.showNoteCamerasOnReveal = true
end

function jtc_camera.registerHiddenSprites(spriteNames)
    if type(spriteNames) ~= "table" then
        return
    end

    for _, spriteName in ipairs(spriteNames) do
        if type(spriteName) == "string" and spriteName ~= "" and not spriteNameExists(spriteName) then
            table.insert(jtc_camera.hiddenSprites, spriteName)

            if jtc_camera.hidden then
                setSpriteVisibility(spriteName, false)
            end
        end
    end
end

function jtc_camera.hideGameplayCameras()
    jtc_camera.hidden = true
    setGameplayVisibility(false, false)
    setManagedSpriteVisibility(false)
end

function jtc_camera.showGameplayCameras()
    jtc_camera.hidden = false
    jtc_camera.revealStep = nil
    setGameplayVisibility(true, jtc_camera.showNoteCamerasOnReveal)
    setManagedSpriteVisibility(true)
end

function jtc_camera.hideGameplayUntilStep(step, showNoteCamerasOnReveal)
    jtc_camera.revealStep = step
    if showNoteCamerasOnReveal ~= nil then
        jtc_camera.showNoteCamerasOnReveal = showNoteCamerasOnReveal
    end
    jtc_camera.hideGameplayCameras()
end

function jtc_camera.onStepHit(step)
    if jtc_camera.hidden and jtc_camera.revealStep ~= nil and step >= jtc_camera.revealStep then
        jtc_camera.showGameplayCameras()
    end
end

return jtc_camera
