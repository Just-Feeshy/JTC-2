local menu_music = require("mod_assets/scripts/utils/menuMusic")
local menu_background = require("mod_assets/scripts/utils/menuBackground")

local tweenCounter = 0
local yCons = 50
local tickCounter = 0
local curSelect = 0
local STORY_PURPLE_NAME = "storyPurpleBG"
local STORY_PURPLE_COLOR = "0xFF4E2A84"
local STORY_PURPLE_SCALE = 1.08

local stopSpam = false
local selectedWeek = false

local graphicsSpr = {
	["bfIcon"] = { "menu/BF-Icon", "school_house/story/bfIcon" },
	["jtcIcon"] = { "menu/JTC-Icon", "school_house/story/jtcIcon" }
}

local weeks = {
	"menu",
	"school_house/story"
}

local function resetIcon()
	for name, paths in pairs(graphicsSpr) do
		loadGraphic(name, paths[curSelect + 1])
        setSpritePosition(name, -getSpriteWidth(name), getScreenCenter(name, "y") - 75 + yCons)
	end

	doTweenX("jtcTween", "jtcIcon", getScreenCenter("jtcIcon", "x") - getSpriteWidth("jtcIcon") + 40, 0.45, "elasticout")
	doTweenX("bfTween", "bfIcon", getScreenCenter("bfIcon", "x") + getSpriteWidth("bfIcon") - 60, 0.45, "elasticout")
end

local function refreshStatic()
    loadGraphic("staticText", weeks[curSelect + 1] .. "/story-week-static-text")
    loadGraphic("trackList", weeks[curSelect + 1] .. "/story-week-track-list")
end

local function createPhaseOne()
	createSprite("lightningIcon")
	loadGraphic("lightningIcon", "menu/Lightning")
	addSpriteToState("lightningIcon")
	setSpritePosition("lightningIcon", getScreenCenter("lightningIcon", "x"), windowHeight)

	for name, paths in pairs(graphicsSpr) do
		createSprite(name)
		loadGraphic(name, paths[curSelect + 1])
		addSpriteToState(name)
        setSpritePosition(name, -getSpriteWidth(name), getScreenCenter(name, "y") - 75 + yCons)
	end

    setSpriteAlpha("staticText", 0)
end

function onCreate()
    destroyStuff()
    menu_music.markActiveIfPlaying()

    disableRegularInput(true) --Disable regular input so I can make my own
    setSpritePosition("grpWeekText", 0, windowHeight / 2)

    setDisplayScoreText("")
    setTextFont("scoreText", "PhantomMuff.ttf")
    setSpriteColor("scoreText", "0x302650")
    setTextSize("scoreText", 48)
    removeSpriteFromState("scoreText")

    createSprite("fadeBlackSprite")
    makeGraphic("fadeBlackSprite", windowWidth, windowHeight, "0xFF000000")

    createSprite("staticText")
    createSprite("trackList")
	refreshStatic()

    createSprite("cheese")
    loadGraphic("cheese", "menu/story-mode-cheese")


    createSprite(STORY_PURPLE_NAME)
    makeGraphic(STORY_PURPLE_NAME, windowWidth, windowHeight, STORY_PURPLE_COLOR)
    setSpritePosition(STORY_PURPLE_NAME, 0, 0)

	createPhaseOne()

	-- State Adder
    insertSpriteToState(0, "fadeBlackSprite")
    insertSpriteToState(0, "trackList")
    insertSpriteToState(0, "cheese")
    addSpriteToState("staticText")

	createSprite("betterDifficulty")
	setDifficultySprite()
	setSpritePosition("betterDifficulty", windowWidth / 2, 50)
	addSpriteToState("betterDifficulty")
end

function finishedTransitionIn()
    doTweenY("fadeTween", "fadeBlackSprite", -windowHeight, 0.3, "quadOut")
end

function onUpdate(elapsed)
    if not selectedWeek then
        if getControl("back") and not stopSpam then
            switchState("MainMenuState")
            stopSpam = true
        end

        if getControl("accept") and not stopSpam then
            stopSpam = true
            selectedWeek = true
            menu_music.markInactive()

            setTransitionOut("void")
		    doTweenAngle("lightningShake", "lightningIcon", 12, 0.1, "quadOut")
            doTweenX("finishX", "betterDifficulty", windowWidth / 2, 0.3, "backIn")
            doTweenY("finishY", "grpWeekText", windowHeight / 2, 0.3, "backIn")
            playSound("confirmMenu", 1, "confirm")
        end

        if getControl("up-press") then
            changeWeek(1)
        end

        if getControl("down-press") then
            changeWeek(-1)
        end

        setSpritePosition("scoreText", getMidpointX("bubble") - (getSpriteWidth("scoreText") / 2) - 25, getMidpointY("bubble") - (getSpriteHeight("scoreText") / 2) + 15)
    end

    setSpriteAngle("grpWeekText", math.sin(tickCounter * (math.pi / 2)) * 6)
    tickCounter = tickCounter + elapsed
end

function onTweenCompleted(name)
    if name == "fadeTween" then
        if tweenCounter == 0 then
            removeSpriteFromState("fadeBlackSprite")
            setSpritePosition("fadeBlackSprite", 0, 0)
            insertSpriteToState(0, STORY_PURPLE_NAME)
            insertSpriteToState(1, "fadeBlackSprite")
            doTweenScaleX("storyPurpleScaleX", STORY_PURPLE_NAME, STORY_PURPLE_SCALE, 0.75, "quadOut")
            doTweenScaleY("storyPurpleScaleY", STORY_PURPLE_NAME, STORY_PURPLE_SCALE, 0.75, "quadOut")
            doTweenX("storyPurpleX", STORY_PURPLE_NAME, -(windowWidth * (STORY_PURPLE_SCALE - 1)) / 2, 0.75, "quadOut")
            doTweenY("storyPurpleY", STORY_PURPLE_NAME, -(windowHeight * (STORY_PURPLE_SCALE - 1)) / 2, 0.75, "quadOut")
            doTweenY("fadeTween", "fadeBlackSprite", -windowHeight, 0.3, "quadOut")
        end

        if tweenCounter == 1 then
            doTweenX("difX", "betterDifficulty", -45, 0.3, "quadOut")
            doTweenY("staticGrpTween", "grpWeekText", -120, 0.3, "quadOut")
            doTweenAlpha("staticTextTween", "staticText", 1, 0.3, "quadOut")

			-- Tween only for icons
            doTweenY("lightningTween", "lightningIcon", 200 + yCons, 0.4, "quadOut")
			resetIcon()

            createSprite("bubble")
            loadGraphic("bubble", "menu/bubble-story")
            setSpritePosition("bubble", -getSpriteWidth("bubble"), getScreenCenter("bubble", "y") - (getSpriteHeight("bubble") / 1.5) + yCons)
            addSpriteToState("bubble")
            doTweenX("bubbleTween", "bubble", 10, 0.45, "elasticout")
            addSpriteToState("scoreText")

            tweenCounter = 0
        end

        tweenCounter = tweenCounter + 1
    end

    if name == "bfTween" then
        doTweenAngle("lightningShake", "lightningIcon", 12, 0.1, "quadOut")
    end

    if name == "lightningShake" then
        doTweenAngle("lightningShake2", "lightningIcon", -12, 0.1, "quadOut")
    end

    if name == "lightningShake2" then
        doTweenAngle("lightningNormal", "lightningIcon", 0, 0.1, "quadOut")
    end

    if name == "finishY" then
        selectWeekFromLua(false)
    end
end

function changedWeek()
	curSelect = curWeek
	resetIcon()
	refreshStatic()
end

function changedDifficulty()
    if not spriteExist("betterDifficulty") then
        return
    end

    setDifficultySprite()
    setSpriteY("betterDifficulty", 60)
    doTweenY("difficultyTween", "betterDifficulty", 50, 0.11, "quadOut")
end

function setDifficultySprite()
    if not spriteExist("betterDifficulty") then
        return
    end

    local currentDifficultyName = difficultyName ~= nil and string.lower(difficultyName) or ""

    if currentDifficultyName == "easy" then
        loadGraphic("betterDifficulty", "menu/easy")
    elseif currentDifficultyName == "normal" then
        loadGraphic("betterDifficulty", "menu/normal")
    else
        loadGraphic("betterDifficulty", "menu/cool")
    end
end

function destroyStuff() --Destroy in-game preloaded sprites.
    destroySprite(STORY_PURPLE_NAME)
    destroySprite("menuBG")
    destroySprite("backdrop")
    destroySprite("blackBarTop")
    destroySprite("blackBarBottom")
    destroySprite("txtTracklist")
    destroySprite("txtWeekTitle")
    destroySprite("rightArrow")
    destroySprite("leftArrow")
    destroySprite("sprDifficulty")
end
