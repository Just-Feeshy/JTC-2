-- First main game lua test of this "engine" to see how well it can handle lua modchart's and general scripting.
-- This is not the most organized script setup, but Frostbeat is the best song to test the "simple stuff."

--variables of components
local frost_modchart = nil
local skater_boi = nil
local string_utils = nil
local inputs = nil


local beatSection = 0
local transition = 0

-- Character stuff
local curAnimName = ""
local holdTimer = 0
local multipler = 6.1
local stunned = false
local notDancing = false

-- Constants
local phaseTwo = 643

local jtcStrumAnims = {
    "singRIGHT",
    "singUP",
    "singDOWN",
    "singLEFT"
}

local jtcOffsets = {

    -- Regular
    {191, -44},
	{-61, 61},
	{-75, -229},
	{-68, -15},

    -- Miss
	{307, 138},
	{159, 108},
	{-18, -91},
	{5, 23}
}

local daddyIsHere = false
local daddyTrans = false
local hasManageInputs = false

-- local functions

local function playAnimation(spriteName, animName)
    if animName == "idle" and notDancing then
		setSpritePosition("second", 650, 100)
		notDancing = false
    end

    playAnimRaw(spriteName, animName)
	curAnimName = animName
end

local function init()

    -- Frostbite Car stuff
    frost_modchart = nil
	skater_boi = nil
	string_utils = nil

	-- Frostbite Car stuff
	beatSection = 0
	transition = 0

	-- Character stuff
	curAnimName = ""
	holdTimer = 0
	multipler = 6.1
	stunned = false
	notDancing = false

	-- Character stuff
    daddyIsHere = false
end

local function cloudIncome()
    if curStep > 614 and curStep < (phaseTwo + 1) then
        local givenTime = (curStepFloat - 614) / ((phaseTwo + 1) - 614)
        local timeLerp = math.min(givenTime, 1)
        local easing = math.pow(math.min(timeLerp, 1), 2)

        -- print(easing)

        setSpritePosition("cloud", (10104 * easing) - 6736, -699 + math.sin(easing * math.pi * 2.0) * 250)
    end
end

--events
function generatedStage()
    init()
    setEndVideo("post.mp4")

    createSprite("frostbiteCAR")
    setSpritePosition("frostbiteCAR", -170, -35)
	--compileSpriteSheet("frostbiteCAR", "daddycar")
	createCombinedFrames("frostbiteCAR-frames", "daddycar", "daddycar2", "sparrow", "sparrow")
	addFramesToSprite("frostbiteCAR", "frostbiteCAR-frames")
	addAnimationByPrefix("frostbiteCAR", "transition", "car drive and dust0", 24, false)
    addAnimationByPrefix("frostbiteCAR", "fog", "car drive and dust t", 24, false)
    playAnimationByPrefix("frostbiteCAR", 'drive', "daddycar", 24, false)
    setScrollFactorToSprite("frostbiteCAR", 1.0, 0.9)
    insertSpriteToStage(getSpriteIndexFromStage("dad"), "frostbiteCAR")

	createSprite("second")
	setSpritePosition("second", 650, 100)
	createCombinedFrames("second-frames", "skater_assets", "skater_miss_notes", "sparrow", "sparrow")
	addFramesToSprite("second", "second-frames")
	addAnimationByPrefix("second", "idle", "skater dance IDLE0", 24, false)
	addAnimationByPrefix("second", "singDOWN", "skater dance DOWN0", 24, false)
	addAnimationByPrefix("second", "singUP", "skater dance UP0", 24, false)
	addAnimationByPrefix("second", "singLEFT", "skater dance LEFT0", 24, false)
	addAnimationByPrefix("second", "singRIGHT", "skater dance RIGHT0", 24, false)
	addAnimationByPrefix("second", "singDOWN miss", "skater dance DOWN miss", 24, false)
	addAnimationByPrefix("second", "singUP miss", "skater dance UP miss", 24, false)
	addAnimationByPrefix("second", "singLEFT miss", "skater dance LEFT miss", 24, false)
	addAnimationByPrefix("second", "singRIGHT miss", "skater dance RIGHT miss", 24, false)
	spriteFlip("second", true, false)
	playAnimation("second", "idle")

    createSprite("cloud")
	setSpritePosition("cloud", 0, 0)
    loadGraphic("cloud", "daddy_transition_cloud")
    scaleSprite("cloud", 2, 2)
    screenCenter("cloud", "y")
    setSpriteX("cloud", -6736)
    addSpriteToState("cloud")

    setupPunchHealth(3)
    frost_modchart = require("mod_assets/scripts/modcharts/frost_modchart")
    frost_modchart.initStrumsAndNotes()

	string_utils = require("mod_assets/scripts/utils/stringTools")
    inputs = require("mod_assets/scripts/utils/inputs")
end

function onStepHit()

	if curStep == 606 then
        daddyTrans = true
    end

    -- if cur

    if curStep == 630 and not daddyIsHere then
        callEvent("character change", "dad-car", "dad")

        removeSpriteFromState("frostbiteCAR")
        destroySprite("frostbiteCAR")

        daddyIsHere = true
    end

	if curStep == 631 then
        insertSpriteToStage("dad")
		addSpriteToStage("second")
	end

    if curStep == 147 and beatSection == 0 then
        callEvent("bump per beat", "2", "1.025")
        beatSection = beatSection + 1
    end

    if curStep == 210 and beatSection == 1 then
        callEvent("bump per beat", "1", "1.05")
        beatSection = beatSection + 1
    end

    if curStep == 475 and beatSection == 2 then
        callEvent("bump per beat", "4", "1")
        beatSection = beatSection + 1
    end

    if curStep == 652 and beatSection == 3 then
        callEvent("bump per beat", "2", "1.025")
        beatSection = beatSection + 1
    end

    if curStep == 772 and beatSection == 4 then
        callEvent("bump per beat", "1", "1.05")
        beatSection = beatSection + 1
    end

	if curStep == 903 then
		removeAnimationPrefix("boyfriend", "idle")
		removeAnimationPrefix("boyfriend", "singDOWN")
		removeAnimationPrefix("boyfriend", "singUP")
		removeAnimationPrefix("boyfriend", "singLEFT")
		removeAnimationPrefix("boyfriend", "singRIGHT")

		addAnimationByPrefix("boyfriend", "idle", "flying dance IDLE GF", 24, false)
		addAnimationByPrefix("boyfriend", "singDOWN", "flying dance DOWN GF", 24, false)
		addAnimationByPrefix("boyfriend", "singUP", "flying dance UP GF", 24, false)
		addAnimationByPrefix("boyfriend", "singLEFT", "flying dance LEFT GF", 24, false)
		addAnimationByPrefix("boyfriend", "singRIGHT", "flying dance RIGHT GF", 24, false)
    end

    if curStep == 904 and beatSection == 5 then
        callEvent("bump per beat", "4", "1")
        beatSection = beatSection + 1
    end
end

function goodNoteHit(caculatePos, strumTime, noteData, tag, noteAbstract, isSustainNote)
    if daddyIsHere then
        if tag == "joul" or tag == "t" then
		    playAnimation("second", jtcStrumAnims[noteData + 1])
			setSpritePosition("second", 650 - jtcOffsets[noteData + 1][1], 100 - jtcOffsets[noteData + 1][2])
			notDancing = true
        end
    end
end

function noteMiss(noteData, tag)
    print("Missed note")

    if daddyIsHere then
		if tag == "joul" or tag == "t" then
		    playAnimation("second", jtcStrumAnims[noteData + 1] .. " miss")
			setSpritePosition("second", 650 - jtcOffsets[noteData + 5][1], 100 - jtcOffsets[noteData + 5][2])
			notDancing = true
		end
    end
end

function onUpdate(elapsed)
    if startedCountdown then

		-- Character update
		do
            if string_utils.starts_with(curAnimName, "sing") then
                holdTimer = holdTimer + elapsed
            end

            if holdTimer > stepCrochet * crochetPitch * multipler then
                playAnimation("second", "idle")
                holdTimer = 0
            end

            if not stunned
                and not string_utils.starts_with(curAnimName, "sing")
                and sprAnimFinished("second") then
                    playAnimation("second", "idle")
            end
		end

        -- Transition Sprite is not possible
        if sprAnimFinished("frostbiteCAR") and daddyTrans then
            stopAnim("frostbiteCAR")

            playAnimRaw("frostbiteCAR", "transition")
            -- stopAnim("frostbiteCAR")
            -- setAnimFrame("frostbiteCAR", 0)
            setSpritePosition("frostbiteCAR", 241, 81)

            print("Execute")

            --if inDebug then
            --    freezeOrUnfreezeGame();
            --    disableInputs(true)
            --    hasManageInputs = true
            --end

            daddyTrans = false
        end

        -- Frostbite Car update
		if sprAnimFinished("frostbiteCAR") then
		    if curStep < 607 then
				playAnimRaw("frostbiteCAR", "drive")
		    end
		end

        --Modchart Section 1
        frost_modchart.sectionOne(elapsed)

        --Modchart Section 2 (There is a HELL version, try it out if you want to suffer)
		-- frost_modchart.sectionTwo_Hell(elapsed
        frost_modchart.sectionTwo_REGULAR()

        -- Cloud Incoming for transition
        cloudIncome()

        -- manageInputs()
    end
end


--functions

function setupPunchHealth(amount)
    for i = 1, amount do
        local iconX = getSpriteX("healthBarBG") + getSpriteWidth("healthBarBG") + 50
        local iconY = getMidpointY("healthBarBG") - 50

        if spriteExist("punchIcon" .. tostring(i - 1)) then
            local iconHeight = getSpriteHeight("punchIcon0");

            iconX = iconX + (getSpriteWidth("punchIcon" .. tostring(i - 1)) * (i - 1))
            iconY = iconY - (iconHeight * 0.5)
        end

        createSprite("punchIcon" .. i)
        setSpritePosition("punchIcon" .. i, iconX, iconY - 10)
        loadGraphic("punchIcon" .. i, "daddy_fist")
        setSpriteToCamera("punchIcon" .. i, "camHUD")
        scaleSprite("punchIcon" .. i, 0.7, 0.7)
        addSpriteToStage("punchIcon" .. i)
    end
end

function whenEventTriggered(skill, value, value2)
    if skill == "character change" then
        print("Add Daddy")
    end
end

function manageInputs()
    if not hasManageInputs then
        return
    end

    if checkKeyStatus(inputs.MAPPED.UP, inputs.STATUS.JUST_PRESSED) then
        setSpritePosition("frostbiteCAR",
            getSpriteX("frostbiteCAR"),
            getSpriteY("frostbiteCAR") - 1
        )
    end
    if checkKeyStatus(inputs.MAPPED.DOWN, inputs.STATUS.JUST_PRESSED) then
        setSpritePosition("frostbiteCAR",
            getSpriteX("frostbiteCAR"),
            getSpriteY("frostbiteCAR") + 1
        )
    end
    if checkKeyStatus(inputs.MAPPED.LEFT, inputs.STATUS.JUST_PRESSED) then
        setSpritePosition("frostbiteCAR",
            getSpriteX("frostbiteCAR") - 1,
            getSpriteY("frostbiteCAR")
        )
    end
    if checkKeyStatus(inputs.MAPPED.RIGHT, inputs.STATUS.JUST_PRESSED) then
        setSpritePosition("frostbiteCAR",
            getSpriteX("frostbiteCAR") + 1,
            getSpriteY("frostbiteCAR")
        )
    end
    if checkKeyStatus(inputs.MAPPED.SCALE_UP, inputs.STATUS.JUST_PRESSED) then
        setAnimFrame("frostbiteCAR", getAnimFrame("frostbiteCAR") + 1)
    end
    if checkKeyStatus(inputs.MAPPED.SCALE_DOWN, inputs.STATUS.JUST_PRESSED) then
        setAnimFrame("frostbiteCAR", getAnimFrame("frostbiteCAR") - 1)
    end
    if checkKeyStatus(inputs.MAPPED.SPACE, inputs.STATUS.JUST_PRESSED) then
        print("frostbiteCAR Position: [X]"
            .. getSpriteX("frostbiteCAR")
            .. " by [Y] " .. getSpriteY("frostbiteCAR")
        )
    end
end
