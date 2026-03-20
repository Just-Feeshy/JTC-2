local TITLE_ACCEPT_ZOOM = 1.6
local TITLE_ACCEPT_SCENE_ANGLE = -15
local TITLE_ACCEPT_TIME = 1.0
local TITLE_SWITCH_DELAY = 0.85
local TITLE_MUSIC_NAME = "i-am-blue"
local TITLE_MUSIC_VOLUME = 0.7
local TITLE_TEXT_NAME = "titlePrompt"
local TITLE_TEXT_TARGET_X = 100
local TITLE_TEXT_TARGET_Y_FACTOR = 0.8
local TITLE_TEXT_ENTRY_OFFSET = 80
local TITLE_TEXT_ENTRY_TIME = 0.6

local introSkipped = false
local titleTransitioning = false
local titleSwitchQueued = false
local switchDelay = 0
local TITLE_ACCEPT_EASE = "expoIn"
local titleSceneSprites = {
    "bg",
    "swirl",
    "thingy",
    "logo",
    "skater",
    "bf",
    "gf",
    "purple",
    "logoBl",
    "gfDance",
}

local function tweenTitleSceneAngle(targetAngle)
    for i = 1, #titleSceneSprites do
        local spriteName = titleSceneSprites[i]

        if spriteExist(spriteName) then
            cancelTween("titleSceneAngle_" .. spriteName)
            doTweenAngle("titleSceneAngle_" .. spriteName, spriteName, targetAngle, TITLE_ACCEPT_TIME, TITLE_ACCEPT_EASE)
        end
    end
end

local function placeTitleText(shouldTween)
    if spriteExist("titleText") then
        removeSpriteFromState("titleText")
        destroySprite("titleText")
    end

    if spriteExist(TITLE_TEXT_NAME) then
        cancelTween("titleTextIntroY")
        removeSpriteFromState(TITLE_TEXT_NAME)
        destroySprite(TITLE_TEXT_NAME)
    end

    createSprite(TITLE_TEXT_NAME)
    compileSpriteSheet(TITLE_TEXT_NAME, "titleEnter", "sparrow")
    addAnimationByPrefix(TITLE_TEXT_NAME, "idle", "Press Enter to Begin", 24, true)
    addAnimationByPrefix(TITLE_TEXT_NAME, "press", "ENTER PRESSED", 24, true)
    setSpriteToCamera(TITLE_TEXT_NAME, "flashCam")
    setSpriteX(TITLE_TEXT_NAME, TITLE_TEXT_TARGET_X)

    if shouldTween then
        setSpriteY(TITLE_TEXT_NAME, windowHeight * TITLE_TEXT_TARGET_Y_FACTOR + TITLE_TEXT_ENTRY_OFFSET)
    else
        setSpriteY(TITLE_TEXT_NAME, windowHeight * TITLE_TEXT_TARGET_Y_FACTOR)
    end

    addSpriteToState(TITLE_TEXT_NAME)
    playAnim(TITLE_TEXT_NAME, "idle", true)

    if shouldTween then
        doTweenY("titleTextIntroY", TITLE_TEXT_NAME, windowHeight * TITLE_TEXT_TARGET_Y_FACTOR, TITLE_TEXT_ENTRY_TIME, "expoOut")
    end
end

local function titleAcceptPressed()
    if keyJustPressed ~= nil and keyJustPressed("ENTER") then
        return true
    end

    if anyGamepadJustPressed ~= nil then
        if anyGamepadJustPressed("START") or anyGamepadJustPressed("B") then
            return true
        end
    end

    if mouseClicked ~= nil and mouseClicked("left") then
        return true
    end

    return false
end

function logo()
    local scrnAspectRatio = windowWidth / windowHeight

    createSprite("logo")
    loadGraphic("logo", "JTC-logo")
    scaleSprite("logo", windowWidth / (2.0 * getSpriteWidth("logo")), windowWidth / (2.0 * getSpriteWidth("logo")))

    setSpritePosition(
        "logo",
        ((windowWidth - getSpriteWidth("logo")) * 0.5) - (32),
        ((windowHeight - getSpriteHeight("logo")) * 0.5) - (12)
    )

    addSpriteToState("logo")
end

function eye()
    createSprite("eye")
    loadGraphic("eye", "title/eye")
    scaleSprite("eye", windowWidth / getSpriteWidth("eye"), windowHeight / getSpriteHeight("eye"))
    addSpriteToState("eye")
end

function onUpdate(elapsed)
    local scrnAspectRatio = windowWidth / windowHeight
    local acceptPressed = titleAcceptPressed()

    if acceptPressed and not introSkipped then
        skipIntro(false)
    end

    if acceptPressed and introSkipped and not titleTransitioning then
        titleTransitioning = true
        titleSwitchQueued = false
        switchDelay = TITLE_SWITCH_DELAY

        if playAnim ~= nil and spriteExist(TITLE_TEXT_NAME) then
            playAnim(TITLE_TEXT_NAME, "press", true)
        end

        if playSound ~= nil then
            playSound("confirmMenu", 0.7)
        end

        if doTweenZoom ~= nil then
            cancelTween("titleAcceptZoom")
            doTweenZoom("titleAcceptZoom", "mainCam", TITLE_ACCEPT_ZOOM, TITLE_ACCEPT_TIME, TITLE_ACCEPT_EASE)
        end

        tweenTitleSceneAngle(TITLE_ACCEPT_SCENE_ANGLE)
    end

    if titleTransitioning then
        switchDelay = switchDelay - elapsed

        if switchDelay <= 0 then
            if not titleSwitchQueued then
                titleSwitchQueued = true
                switchState("MainMenuState")
            end

            return
        end
    end

    if not titleTransitioning then
        setSpritePosition("skater", (128 * math.pi * math.cos(titleTicks)) / 64, (120 * math.pi * math.sin(titleTicks)) / 64)
        setSpriteAngle("skater", (180 / math.pi) * ((math.pi * math.sin(titleTicks)) / 128))
        setSpriteAngle("logo", (180 / math.pi) * -(math.cos(titleTicks) / 30))

        local b_x = 1.25 * math.cos(titleTicks - 0.25) * 0.1 + 0.925
        local g_y = (0.05) * (0.5 * math.cos(2.5 * titleTicks) + 0.5)
        local g_x = 1.25 * math.cos(titleTicks) * 0.1 + 0.125

        setSpritePosition("bf", b_x * 128, -(g_y * 0.5 - 0.62) * 120)
        setSpritePosition("gf", g_x * 128, -g_y * 120)
        --setSpritePosition("eye", g_x * 128, -g_y * 120)
    end
end

function onBeatHit()
end

function onStartIntro()
    disableRegularInput(true)

    if playInstAt ~= nil then
        playInstAt(TITLE_MUSIC_NAME, 0, TITLE_MUSIC_VOLUME, true)
    elseif playInst ~= nil then
        playInst(TITLE_MUSIC_NAME, TITLE_MUSIC_VOLUME, true)
    elseif playMusicAt ~= nil then
        playMusicAt(TITLE_MUSIC_NAME, 0, TITLE_MUSIC_VOLUME, true)
    elseif playMusic ~= nil then
        playMusic(TITLE_MUSIC_NAME, TITLE_MUSIC_VOLUME, true)
    end

    createSprite("bg")
    loadGraphic("bg", "title/BackgroundTitle")
    scaleSprite("bg", windowWidth / getSpriteWidth("bg"), windowHeight / getSpriteHeight("bg"))
    addSpriteToState("bg")

    createSprite("swirl")
    loadGraphic("swirl", "title/swirl")
    scaleSprite("swirl", windowWidth / getSpriteWidth("swirl"), windowHeight / getSpriteHeight("swirl"))
    addSpriteToState("swirl")

    createSprite("thingy")
    loadGraphic("thingy", "title/thingy")
    scaleSprite("thingy", windowWidth / getSpriteWidth("thingy"), windowHeight / getSpriteHeight("thingy"))
    addSpriteToState("thingy")

    logo()

    createSprite("skater")
    loadGraphic("skater", "title/Skater")
    scaleSprite("skater", windowWidth / getSpriteWidth("skater"), windowHeight / getSpriteHeight("skater"))
    addSpriteToState("skater")

    createSprite("bf")
    loadGraphic("bf", "title/BF")
    scaleSprite("bf", windowWidth / getSpriteWidth("bf"), windowHeight / getSpriteHeight("bf"))
    addSpriteToState("bf")

    createSprite("gf")
    loadGraphic("gf", "title/GF")
    scaleSprite("gf", windowWidth / getSpriteWidth("gf"), windowHeight / getSpriteHeight("gf"))
    addSpriteToState("gf")

    --eye()

    createSprite("purple")
    loadGraphic("purple", "title/Purple")
    scaleSprite("purple", windowWidth / getSpriteWidth("purple"), windowHeight / getSpriteHeight("purple"))
    addSpriteToState("purple")

    placeTitleText(true)

end

function onSkipIntro()
    introSkipped = true
    placeTitleText(false)
end
