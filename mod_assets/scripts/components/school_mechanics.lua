local cursed_queue = require("mod_assets/scripts/components/cursed_queue")

local school_mechanics = {}
local opponentStandTransitionActive = false
local totalMissedCheese = 0

local function activateOpponentAltMode()
	setOpponentAltAnim("-alt")
	setCharacterIdleSuffix("dad", "-alt")
end

local METER_OFFSET = {x = 6, y = -271}
local METER_JITTER_DEGREES = 2.25
local METER_JITTER_SPEED = 18.0
local HUD_ICON_SIZE_RATIO = 0.06
local HUD_ICON_Y_OFFSET_BASE = 97
local HUD_ICON_GAP_RATIO = 0.01
local HUD_ICON_LEFT_NUDGE_RATIO = 0.01
local COUNTER_FONT = "PhantomMuff.ttf"
local COUNTER_FONT_SIZE = 28
local COUNTER_BORDER_SIZE = 3
local COUNTER_COLOR = "0xFF791EFF"
local COUNTER_BORDER_COLOR = "0xFF000000"
local meterNoiseTime = 0
local notesHit = 0

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
	local downscroll_angle = downscroll and -1 or 1
    local targetAngle = mix(-45, 45, targetLerp) * downscroll_angle
    local jitter = (math.sin(meterNoiseTime * 2.1) * 0.55
        + math.sin(meterNoiseTime * 5.3 + 0.9) * 0.3
        + math.sin(meterNoiseTime * 9.7 + 2.2) * 0.15) * METER_JITTER_DEGREES

    local finalAngle = targetAngle + jitter
    local radians = math.rad(finalAngle)
    local cosine = math.cos(radians)
    local sine = math.sin(radians)
    local meterX = (cosine * METER_OFFSET.x - sine * METER_OFFSET.y) - METER_OFFSET.x
    local meterY = (sine * METER_OFFSET.x + cosine * METER_OFFSET.y) - METER_OFFSET.y

    local introOffsetY = 0
    if spriteExist("schoolBarHUD") then
        introOffsetY = getSpriteY("schoolBarHUD")
    end

    setSpriteTransform("schoolMeterHUD", meterX, meterY + introOffsetY, finalAngle)
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

local function getFirstHudIconIndex()
    local iconP1Index = getSpriteIndexFromState("iconP1")
    local iconP2Index = getSpriteIndexFromState("iconP2")

    if iconP1Index < 0 then
        return iconP2Index
    end

    if iconP2Index < 0 then
        return iconP1Index
    end

    if iconP1Index < iconP2Index then
        return iconP1Index
    end

    return iconP2Index
end

local function getLastHudIconIndex()
    local iconP1Index = getSpriteIndexFromState("iconP1")
    local iconP2Index = getSpriteIndexFromState("iconP2")

    if iconP1Index > iconP2Index then
        return iconP1Index
    end

    return iconP2Index
end

local function ensureHudSpritesAttached()
    local firstIconIndex = getFirstHudIconIndex()
    local lastIconIndex = getLastHudIconIndex()

    removeSpriteFromState("schoolWeirdMenuHUD")
    removeSpriteFromState("schoolBarHUD")
    removeSpriteFromState("schoolMeterHUD")

    if firstIconIndex >= 0 then
        insertSpriteToState(firstIconIndex, "schoolWeirdMenuHUD")
        insertSpriteToState(firstIconIndex + 1, "schoolBarHUD")
    else
        addSpriteToState("schoolWeirdMenuHUD")
        addSpriteToState("schoolBarHUD")
    end

    if lastIconIndex >= 0 then
        insertSpriteToState(lastIconIndex + 1, "schoolMeterHUD")
    else
        addSpriteToState("schoolMeterHUD")
    end
end

local function buildWeirdMenuHud()
	createSprite("schoolWeirdMenuHUD")

	if downscroll then
		loadGraphic("schoolWeirdMenuHUD", "school_house/menu/weird-menu-downscroll")
	else
		loadGraphic("schoolWeirdMenuHUD", "school_house/menu/weird-menu")
	end

	setSpriteSize("schoolWeirdMenuHUD", windowWidth, windowHeight)
	setSpritePosition("schoolWeirdMenuHUD", 0, 0)
	setSpriteToCamera("schoolWeirdMenuHUD", "camHUD")
	addSpriteToState("schoolWeirdMenuHUD")
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

local function getCounterPositions()
	local missX, scoreX
	local baseY = 1;

	missX = windowWidth * (475 / 1280)
	scoreX = windowWidth * (920 / 1280)

	if not downscroll then
		baseY = windowHeight - getTextHeight("missCountTxt") - baseY
	end
	return missX, scoreX, baseY
end

local function styleCounterText(name)
	setTextFont(name, COUNTER_FONT)
	setTextSize(name, COUNTER_FONT_SIZE)
	setTextColor(name, COUNTER_COLOR)
	setTextBorder(name, "outline", COUNTER_BORDER_SIZE, COUNTER_BORDER_COLOR)
	setTextToCamera(name, "camHUD")
end

local function buildHudCounters()
	if createText == nil then
		return
	end

	createText("missCountTxt", 0, 0, 0, "0", COUNTER_FONT_SIZE)
	styleCounterText("missCountTxt")
	addTextToState("missCountTxt")

	createText("scoreCountTxt", 0, 0, 0, "0", COUNTER_FONT_SIZE)
	styleCounterText("scoreCountTxt")
	addTextToState("scoreCountTxt")
end

local function updateHudCounters()
	if not spriteExist("missCountTxt") and not spriteExist("scoreCountTxt") then
		return
	end

	local missX, scoreX, baseY = getCounterPositions()
	local introOffsetY = 0
	if spriteExist("schoolWeirdMenuHUD") then
		introOffsetY = getSpriteY("schoolWeirdMenuHUD")
	end

	if spriteExist("missCountTxt") then
		setText("missCountTxt", tostring(math.floor(misses or 0)))
		setSpritePosition("missCountTxt", missX, baseY + introOffsetY)
	end

	if spriteExist("scoreCountTxt") then
		setText("scoreCountTxt", tostring(math.floor(score or 0)))
		setSpritePosition("scoreCountTxt", scoreX, baseY + introOffsetY)
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
	totalMissedCheese = 0
	notesHit = 0
	cursed_queue.clear()

    if downscroll then
	    METER_OFFSET.y = METER_OFFSET.y * -1
    end

    buildWeirdMenuHud()
    buildBar()
    buildMeter()
    buildHudCounters()
    applyHudLayout()
    ensureHudSpritesAttached()
    updateMeterAngle(0)
    updateHudCounters()
end

function school_mechanics.onStep(step)
	if step == 0 then
		callEvent("jumpspeed", "1", "0")
	end
	if step == 504 then
		callEvent("jumpspeed", "0.75", "67")
	end
	if step == 632 then
		callEvent("time freeze", "1", "2.9")
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
    updateHudCounters()
    cursed_queue.onUpdate(elapsed)

    if opponentStandTransitionActive then

		if sprAnimFinished("dad") then
			opponentStandTransitionActive = false
			setCharacterSpecialAnim("dad", false)
			setCharacterCustomAnimation("dad", false)
			activateOpponentAltMode()
			playOpponentIdle()
			callEvent("time freeze", "0", "1.45")
		end
    end
end

function school_mechanics.onGoodNote()
	notesHit = notesHit + 1;
end

function school_mechanics.onBeatHit()
	cursed_queue.onBeatHit()
end

function school_mechanics.onNoteMiss(noteData, tag, noteAbstract, isSustainNote)
	if isSustainNote then
		return
	end

	if noteAbstract == "cheese fifth" then
		cursed_queue.enqueue(2)
		totalMissedCheese = totalMissedCheese + 1

		local totalCheese = getNoteCountByAbstract("cheese fifth")
		if totalCheese > 0 then
			local ratio = totalMissedCheese / totalCheese
			if ratio > 1 then ratio = 1 end
			setMaxHealth(2 * (1 - ratio * 6))
		end
	end
end

function school_mechanics.queueCursed(count)
	cursed_queue.enqueue(count)
end

function school_mechanics.clearCursedQueue()
	cursed_queue.clear()
end

function school_mechanics.pendingCursed()
	return cursed_queue.pending()
end

function school_mechanics.hideHud()
	if spriteExist("schoolWeirdMenuHUD") then setSpriteVisible("schoolWeirdMenuHUD", false) end
	if spriteExist("schoolBarHUD") then setSpriteVisible("schoolBarHUD", false) end
	if spriteExist("schoolMeterHUD") then setSpriteVisible("schoolMeterHUD", false) end
	if spriteExist("missCountTxt") then setSpriteVisible("missCountTxt", false) end
	if spriteExist("scoreCountTxt") then setSpriteVisible("scoreCountTxt", false) end
end

function school_mechanics.tweenInHud()
	local offset = downscroll and (-windowHeight) or windowHeight

	if spriteExist("schoolWeirdMenuHUD") then
		setSpriteVisible("schoolWeirdMenuHUD", true)
		setSpriteY("schoolWeirdMenuHUD", offset)
		doTweenY("schoolHudMenuIntro", "schoolWeirdMenuHUD", 0, 0.9, "cubeout")
	end

	if spriteExist("schoolBarHUD") then
		setSpriteVisible("schoolBarHUD", true)
		setSpriteY("schoolBarHUD", offset)
		doTweenY("schoolHudBarIntro", "schoolBarHUD", 0, 0.9, "cubeout")
	end

	if spriteExist("schoolMeterHUD") then
		setSpriteVisible("schoolMeterHUD", true)
	end

	if spriteExist("missCountTxt") then setSpriteVisible("missCountTxt", true) end
	if spriteExist("scoreCountTxt") then setSpriteVisible("scoreCountTxt", true) end
end

function school_mechanics.onEnd()
	if getHealthNormalized() < 0.67 then
		switchState("BadEndState")
		return
	end

	switchState("GoodEndState")
end

return school_mechanics
