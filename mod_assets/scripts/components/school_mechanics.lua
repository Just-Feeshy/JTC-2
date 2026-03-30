local school_mechanics = {}

local METER_OFFSET = {x = 6, y = -271}
local HUD_ICON_SIZE_RATIO = 0.07
local HUD_ICON_Y_OFFSET = 100
local HUD_ICON_GAP_RATIO = 0.01
local HUD_ICON_LEFT_NUDGE_RATIO = 0.003

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
	if downscroll then
		HUD_ICON_Y_OFFSET = HUD_ICON_Y_OFFSET * -1
	end

    local iconSize = math.floor(windowWidth * HUD_ICON_SIZE_RATIO)
    local iconGap = math.floor(windowWidth * HUD_ICON_GAP_RATIO)
    local leftIconNudge = math.floor(windowWidth * HUD_ICON_LEFT_NUDGE_RATIO)
    local iconY = math.floor(getSpriteY("schoolBarHUD") - HUD_ICON_Y_OFFSET)
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

local function buildWeirdMenuHud()
	createSprite("schoolWeirdMenuHUD")
	loadGraphic("schoolWeirdMenuHUD", "school_house/menu/weird-menu")
	setSpriteSize("schoolWeirdMenuHUD", windowWidth, windowHeight)
	setSpritePosition("schoolWeirdMenuHUD", 0, 0)
	setSpriteToCamera("schoolWeirdMenuHUD", "camHUD")
	addSpriteToStage("schoolWeirdMenuHUD")

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
	addSpriteToStage("schoolBarHUD")

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
	addSpriteToStage("schoolMeterHUD")

	if downscroll then
		spriteFlip("schoolMeterHUD", false, true)
	end
end

function school_mechanics.onCreate()
	if downscroll then
		METER_OFFSET.y = METER_OFFSET.y * -1
	end

	buildWeirdMenuHud()
	buildBar()
	buildMeter()
    applyHudLayout()
    registerOrbitSprite("schoolMeterHUD", METER_OFFSET.x, METER_OFFSET.y, 1, 0)
end

function school_mechanics.onSongRestart()
    applyHudLayout()
end

function school_mechanics.onStep(step)
	if step == 504 then
		callEvent("jumpspeed", "0.75", "67")
	end
	if step == 764 then
		callEvent("jumpspeed", "0.61", "21")
	end
	if step == 892 then
		callEvent("jumpspeed", "1.0", "41")
	end
	if step == 1064 then
		callEvent("jumpspeed", "1.1", "89")
	end
end

function school_mechanics.onUpdate(elapsed)
end

return school_mechanics
