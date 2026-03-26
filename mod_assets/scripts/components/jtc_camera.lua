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

local function setGameplayVisibility(visible)
    for _, cameraName in ipairs(gameplayCameras) do
        setCameraVisible(cameraName, visible)
    end
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
    setGameplayVisibility(false)
    setManagedSpriteVisibility(false)
end

function jtc_camera.showGameplayCameras()
    jtc_camera.hidden = false
    jtc_camera.revealStep = nil
    setGameplayVisibility(true)
    setManagedSpriteVisibility(true)
end

function jtc_camera.hideGameplayUntilStep(step)
    jtc_camera.revealStep = step
    jtc_camera.hideGameplayCameras()
end

function jtc_camera.onStepHit(step)
    if not jtc_camera.hidden or jtc_camera.revealStep == nil then
        return
    end

    if step >= jtc_camera.revealStep then
        jtc_camera.showGameplayCameras()
    end
end

return jtc_camera
