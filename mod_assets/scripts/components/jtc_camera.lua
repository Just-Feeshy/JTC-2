local jtc_camera = {}

local gameplayCameras = {
    "camGame",
    "camNOTE",
    "camNoteSustain"
}

local defaultStrumRevealDuration = 0.35
local defaultStrumRevealDelay = 0.02
local strumCount = 8
local strumLaneCount = 4

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
jtc_camera.strumDefaults = {}
jtc_camera.strumReveal = nil

local function setGameplayVisibility(gameVisible, noteVisible)
    setCameraVisible("camGame", gameVisible)
    setCameraVisible("camNOTE", noteVisible)
    setCameraVisible("camNoteSustain", noteVisible)
end

local function setNoteCameraVisibility(visible)
    setCameraVisible("camNOTE", visible)
    setCameraVisible("camNoteSustain", visible)
end

local function getDefaultStrumAxis(side, axis, lane)
    local globalName = "default" .. side .. "Strum" .. axis .. tostring(lane)
    local globalValue = _G[globalName]

    if type(globalValue) == "number" then
        return globalValue
    end

    local id = lane

    if side == "Player" then
        id = lane + 4
    end

    if axis == "X" then
        return getNotePosX(id)
    end

    return getNotePosY(id)
end

local function captureStrumDefaults()
    for id = 0, strumCount - 1 do
        local side = "Opponent"
        local lane = id

        if id >= 4 then
            side = "Player"
            lane = id - 4
        end

        jtc_camera.strumDefaults[id + 1] = {
            x = getDefaultStrumAxis(side, "X", lane),
            y = getDefaultStrumAxis(side, "Y", lane)
        }
    end
end

local function restoreStrumDefaults()
    if #jtc_camera.strumDefaults == 0 then
        captureStrumDefaults()
    end

    for id = 0, strumCount - 1 do
        local defaultPos = jtc_camera.strumDefaults[id + 1]

        if defaultPos ~= nil then
            setNoteStrumPos(id, defaultPos.x, defaultPos.y)
            setNoteAlpha(id, 1)
        end
    end
end

local function moveStrumsOffscreenTop()
    if #jtc_camera.strumDefaults == 0 then
        captureStrumDefaults()
    end

    for id = 0, strumCount - 1 do
        local defaultPos = jtc_camera.strumDefaults[id + 1]

        if defaultPos ~= nil then
            setNoteStrumPos(id, defaultPos.x, -getNotePosY(id) / 2.0)
            setNoteAlpha(id, 0)
        end
    end
end

local function moveStrumsOffscreenBottom()
    if #jtc_camera.strumDefaults == 0 then
        captureStrumDefaults()
    end

    for id = 0, strumCount - 1 do
        local defaultPos = jtc_camera.strumDefaults[id + 1]

        if defaultPos ~= nil then
            setNoteStrumPos(id, defaultPos.x, windowHeight + (getNotePosY(id) / 2.0))
            setNoteAlpha(id, 0)
        end
    end
end

local function startStrumReveal(duration, delay)
    if downscroll then
        moveStrumsOffscreenBottom()
    else
        moveStrumsOffscreenTop()
    end

    setNoteCameraVisibility(true)
    jtc_camera.strumReveal = {
        elapsed = 0,
        nextLane = 0,
        duration = duration or defaultStrumRevealDuration,
        delay = delay or defaultStrumRevealDelay
    }
    jtc_camera.strumReveal.finishTime = ((strumLaneCount - 1) * jtc_camera.strumReveal.delay) + jtc_camera.strumReveal.duration
end

local function revealStrum(id, duration)
    local defaultPos = jtc_camera.strumDefaults[id + 1]

    if defaultPos ~= nil then
        noteTweenY("jtcCameraStrumRevealY" .. tostring(id), id, defaultPos.y, duration, "cubeOut")
        noteTweenAlpha("jtcCameraStrumRevealAlpha" .. tostring(id), id, 1, duration, "cubeOut")
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
    jtc_camera.showNoteCamerasOnReveal = true
    jtc_camera.strumDefaults = {}
    jtc_camera.strumReveal = nil
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
    jtc_camera.strumReveal = nil
    captureStrumDefaults()
    moveStrumsOffscreenTop()
    setGameplayVisibility(false, false)
    setManagedSpriteVisibility(false)
end

function jtc_camera.showGameplayCameras()
    jtc_camera.hidden = false
    jtc_camera.revealStep = nil
    setGameplayVisibility(true, jtc_camera.showNoteCamerasOnReveal)
    setManagedSpriteVisibility(true)

    if jtc_camera.showNoteCamerasOnReveal then
        startStrumReveal()
    else
        restoreStrumDefaults()
    end
end

function jtc_camera.hideGameplayUntilStep(step, showNoteCamerasOnReveal)
    jtc_camera.revealStep = step
    if showNoteCamerasOnReveal ~= nil then
        jtc_camera.showNoteCamerasOnReveal = showNoteCamerasOnReveal
    end
    jtc_camera.hideGameplayCameras()
end

function jtc_camera.revealNoteCameras(duration, delay)
    startStrumReveal(duration, delay)
end

function jtc_camera.onStepHit(step)
    if jtc_camera.hidden and jtc_camera.revealStep ~= nil and step >= jtc_camera.revealStep then
        jtc_camera.showGameplayCameras()
    end
end

function jtc_camera.onUpdate(elapsed)
    local currentStep = curStep or -1

    if jtc_camera.hidden and jtc_camera.revealStep ~= nil and currentStep >= jtc_camera.revealStep then
        jtc_camera.showGameplayCameras()
    end

    if jtc_camera.strumReveal == nil then
        return
    end

    jtc_camera.strumReveal.elapsed = jtc_camera.strumReveal.elapsed + elapsed

    while jtc_camera.strumReveal.nextLane < strumLaneCount and
        jtc_camera.strumReveal.elapsed >= (jtc_camera.strumReveal.nextLane * jtc_camera.strumReveal.delay) do
        local lane = jtc_camera.strumReveal.nextLane
        revealStrum(lane, jtc_camera.strumReveal.duration)
        revealStrum(lane + strumLaneCount, jtc_camera.strumReveal.duration)
        jtc_camera.strumReveal.nextLane = jtc_camera.strumReveal.nextLane + 1
    end

    if jtc_camera.strumReveal.elapsed >= jtc_camera.strumReveal.finishTime then
        jtc_camera.strumReveal = nil
    end
end

return jtc_camera
