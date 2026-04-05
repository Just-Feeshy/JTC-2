local school_mechanics = {}
local opponentStandTransitionActive = false

local function activateOpponentAltMode()
	setOpponentAltAnim("-alt")
	setCharacterIdleSuffix("dad", "-alt")
end

local METER_OFFSET = {x = 6, y = -271}
local METER_JITTER_DEGREES = 2.25
local METER_JITTER_SPEED = 18.0
local HUD_ICON_SIZE_RATIO = 0.06
local HUD_ICON_Y_OFFSET_BASE = 100
local HUD_ICON_GAP_RATIO = 0.01
local HUD_ICON_LEFT_NUDGE_RATIO = 0.006
local meterNoiseTime = 0

local function clamp(value, minValue, maxValue)
    return math.max(math.min(value, maxValue), minValue)
end

local function mix(a, b, t)
    return a + (b - a) * t
end

local function updateMeterAngle(elapsed)
    if not spriteExist("schoolMeterHUD") then
        return
    end

    meterNoiseTime = meterNoiseTime + elapsed * METER_JITTER_SPEED
    local healthLerp = clamp(getHealthNormalized(), 0, 1)
    local targetLerp = healthLerp
    local targetAngle = mix(-45, 45, targetLerp)
    local jitter = (math.sin(meterNoiseTime * 2.1) * 0.55
        + math.sin(meterNoiseTime * 5.3 + 0.9) * 0.3
        + math.sin(meterNoiseTime * 9.7 + 2.2) * 0.15) * METER_JITTER_DEGREES

    local finalAngle = targetAngle + jitter
    local radians = math.rad(finalAngle)
    local cosine = math.cos(radians)
    local sine = math.sin(radians)
    local meterX = (cosine * METER_OFFSET.x - sine * METER_OFFSET.y) - METER_OFFSET.x
    local meterY = (sine * METER_OFFSET.x + cosine * METER_OFFSET.y) - METER_OFFSET.y

    setSpriteTransform("schoolMeterHUD", meterX, meterY, finalAngle)
end

local function setHudSpriteVisible(spriteName, visible)
    if spriteExist(spriteName) then
        setSpriteVisible(spriteName, visible)
    end
end

local function hideDefaultHud()
    setHudSpriteVisible("healthBarBG", false)
    setHudSpriteVisible("healthBar", false)
    setHudSpriteVisible("counterTxt", false)
end

local function positionHudIcons()
    local iconSize = math.floor(windowWidth * HUD_ICON_SIZE_RATIO)
    local iconGap = math.floor(windowWidth * HUD_ICON_GAP_RATIO)
    local leftIconNudge = math.floor(windowWidth * HUD_ICON_LEFT_NUDGE_RATIO)
    local iconYOffset = HUD_ICON_Y_OFFSET_BASE

    if not downscroll then
        iconYOffset = windowHeight - (HUD_ICON_Y_OFFSET_BASE * 1.8)
    end

    local iconY = math.floor(getSpriteY("schoolBarHUD") + iconYOffset)
    local centerX = math.floor(windowWidth * 0.5)

    if spriteExist("iconP2") then
        setSpriteVisible("iconP2", true)
        setSpriteSize("iconP2", iconSize, iconSize)
        setSpritePosition("iconP2", centerX - iconSize - iconGap - leftIconNudge, iconY)
    end

    if spriteExist("iconP1") then
        setSpriteVisible("iconP1", true)
        setSpriteSize("iconP1", iconSize, iconSize)
        setSpritePosition("iconP1", centerX + iconGap, iconY)
    end
end

local function applyHudLayout()
    setHudIconsStatic(true)
    hideDefaultHud()
    positionHudIcons()
end

local function ensureHudSpritesAttached()
    addSpriteToState("schoolWeirdMenuHUD")
    addSpriteToState("schoolBarHUD")
    addSpriteToState("schoolMeterHUD")
end

local function buildWeirdMenuHud()
	createSprite("schoolWeirdMenuHUD")
	loadGraphic("schoolWeirdMenuHUD", "school_house/menu/weird-menu")
	setSpriteSize("schoolWeirdMenuHUD", windowWidth, windowHeight)
	setSpritePosition("schoolWeirdMenuHUD", 0, 0)
	setSpriteToCamera("schoolWeirdMenuHUD", "camHUD")
	addSpriteToState("schoolWeirdMenuHUD")

	if downscroll then
		spriteFlip("schoolWeirdMenuHUD", false, true)
	end
end

local function buildBar()
	createSprite("schoolBarHUD")
	loadGraphic("schoolBarHUD", "school_house/menu/bar")
	setSpriteSize("schoolBarHUD", windowWidth, windowHeight)
	setSpritePosition("schoolBarHUD", 0, 0)
	setSpriteToCamera("schoolBarHUD", "camHUD")
	addSpriteToState("schoolBarHUD")

	if downscroll then
		spriteFlip("schoolBarHUD", false, true)
	end
end

local function buildMeter()
	createSprite("schoolMeterHUD")
	loadGraphic("schoolMeterHUD", "school_house/menu/meter")
	setSpriteSize("schoolMeterHUD", windowWidth, windowHeight)
	setSpritePosition("schoolMeterHUD", 0, 0)
	setSpriteToCamera("schoolMeterHUD", "camHUD")

	if downscroll then
		spriteFlip("schoolMeterHUD", false, true)
	end
end

function school_mechanics.onCreate()
    opponentStandTransitionActive = false

    if downscroll then
	    METER_OFFSET.y = METER_OFFSET.y * -1
    end

    buildWeirdMenuHud()
    buildBar()
    buildMeter()
    applyHudLayout()
    addSpriteToState("schoolMeterHUD")
    updateMeterAngle(0)
end

function school_mechanics.onStep(step)
	if step == 504 then
		callEvent("jumpspeed", "0.75", "67")
	end
	if step == 632 then
		callEvent("time freeze", "1", "1.45")
		playAnim("dad", "stand", true)
		setCharacterCustomAnimation("dad", true)
		setCharacterSpecialAnim("dad", true)
		opponentStandTransitionActive = true
	end
	if step == 764 then
		callEvent("jumpspeed", "0.61", "21")
	end
	if step == 892 then
		callEvent("jumpspeed", "1.0", "41")
	end
	if step == 1064 then
		callEvent("jumpspeed", "0.9", "89")
	end
end

function school_mechanics.onUpdate(elapsed)
	updateMeterAngle(elapsed)

	if opponentStandTransitionActive and sprAnimFinished("dad") then
		opponentStandTransitionActive = false
		setCharacterSpecialAnim("dad", false)
		setCharacterCustomAnimation("dad", false)
		activateOpponentAltMode()
		playOpponentIdle()
		callEvent("time freeze", "0", "1.45")
	end
end

function school_mechanics.onResume()
    ensureHudSpritesAttached()
	applyHudLayout()
	updateMeterAngle(0)
end

return school_mechanics
