local menuItems = {
    "Resume",
    "Restart Song",
    "Change Controls",
    "Exit to menu"
}

local assetNames = {
    "pause-menu_resume",
    "pause-menu_restart",
    "pause-menu_controls",
    "pause-menu_menu"
}

local introTweenCount = 0
local introTweenTotal = #assetNames

local function tweenDuration()
    return 0.4 * (curBpm / 120)
end

local function menuBaseX(index)
    return (#menuItems - index + 1) * 30
end

local function updateSelectionColors(selectedIndex)
    for i = 1, #assetNames do
        local spriteName = "pauseOption" .. i
        if spriteExist(spriteName) then
            setSpriteColor(spriteName, "0xFFFFFFFF")
            if (i - 1) == selectedIndex then
                setSpriteAlpha(spriteName, 1)
            else
                setSpriteAlpha(spriteName, 0.6)
            end
        end
    end
end

local function updateSelectionPositions(selectedIndex, tween)
    for i = 1, #assetNames do
        local spriteName = "pauseOption" .. i
        if spriteExist(spriteName) then
            local targetX = menuBaseX(i)
            if (i - 1) == selectedIndex then
                targetX = targetX - 30
            end

            if tween then
                cancelTween("pauseOptionMove" .. i)
                doTweenX("pauseOptionMove" .. i, spriteName, targetX, tweenDuration(), "quadOut")
            else
                setSpriteX(spriteName, targetX)
            end
        end
    end
end

local function getIntroTargetX(index)
    local targetX = menuBaseX(index)
    if (index - 1) == getPauseSelection() then
        targetX = targetX - 30
    end
    return targetX
end

function onCreate()
    setDefaultPauseMenuVisible(false)

    setTextFont("pauseLevelInfo", "PhantomMuff.ttf")
    setTextFont("pauseLevelDifficulty", "PhantomMuff.ttf")
    setTextFont("pauseOtherStuff", "PhantomMuff.ttf")

    local infoHeight = getSpriteHeight("pauseLevelInfo")
    local difficultyHeight = getSpriteHeight("pauseLevelDifficulty")
    local otherHeight = getSpriteHeight("pauseOtherStuff")
    local textX = 20

    setSpriteX("pauseLevelInfo", textX)
    setSpriteX("pauseLevelDifficulty", textX)
    setSpriteX("pauseOtherStuff", textX)
    setSpriteY("pauseLevelInfo", windowHeight - infoHeight - 111)
    setSpriteY("pauseLevelDifficulty", windowHeight - difficultyHeight - infoHeight - 10)
    setSpriteY("pauseOtherStuff", windowHeight - otherHeight - 22.5)

    setSpriteAlpha("pauseLevelInfo", 0)
    setSpriteAlpha("pauseLevelDifficulty", 0)
    setSpriteAlpha("pauseOtherStuff", 0)
    setSpriteAlpha("pauseBackground", 0)

    doTweenAlpha("pauseBGAlpha", "pauseBackground", 0.6, tweenDuration(), "quadOut")
    doTweenAlpha("pauseInfoAlpha", "pauseLevelInfo", 1, tweenDuration(), "quadOut")
    doTweenY("pauseInfoY", "pauseLevelInfo", windowHeight - infoHeight - 116, tweenDuration(), "quadOut")
    doTweenAlpha("pauseDifficultyAlpha", "pauseLevelDifficulty", 1, tweenDuration(), "quadOut")
    doTweenY("pauseDifficultyY", "pauseLevelDifficulty", getSpriteY("pauseLevelDifficulty") - 10, tweenDuration(), "quadOut")

    createSprite("pauseBanner")
    loadGraphic("pauseBanner", "pause-menu_paused")
    setSpritePosition("pauseBanner", -windowWidth, 0)
    setSpriteToCamera("pauseBanner", "camHUD")
    insertPauseSprite(1, "pauseBanner")
    doTweenX("pauseBannerX", "pauseBanner", 0, tweenDuration(), "quadOut")

    for i = 1, #assetNames do
        local spriteName = "pauseOption" .. i
        createSprite(spriteName)
        loadGraphic(spriteName, "pause_options/" .. assetNames[i])
        setSpritePosition(spriteName, windowWidth, 0)
        setSpriteToCamera(spriteName, "camHUD")
        addPauseSprite(spriteName)
        doTweenX("pauseOptionIntro" .. i, spriteName, getIntroTargetX(i), tweenDuration(), "quadOut")
    end

    updateSelectionColors(getPauseSelection())
end

function onSelectionChange(selectedIndex)
    updateSelectionColors(selectedIndex)

    if introTweenCount >= introTweenTotal then
        updateSelectionPositions(selectedIndex, true)
    end
end

function onTweenCompleted(name)
    if string.sub(name, 1, 16) == "pauseOptionIntro" then
        introTweenCount = introTweenCount + 1
        if introTweenCount >= introTweenTotal then
            updateSelectionPositions(getPauseSelection(), false)
        end
    end
end
