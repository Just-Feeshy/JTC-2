local tickSway = 0
local tweenCounter = 0
local yCons = 50

local stopSpam = false

function onCreate()
    destroyStuff()

    disableRegularInput(true) --Disable regular input so I can make my own
    setSpritePosition("grpWeekText", 0, windowHeight)

    createSprite("fadeBlackSprite")
    makeGraphic("fadeBlackSprite", windowWidth, windowHeight, "0xFF000000")
    insertSpriteToState(0, "fadeBlackSprite")

    createSprite("cheese")
    loadGraphic("cheese", "menu/story-mode-cheese")
    insertSpriteToState(0, "cheese")

    createSprite("staticText")
    loadGraphic("staticText", "menu/story-week-static-text");
    setSpriteAlpha("staticText", 0);
    addSpriteToState("staticText");

    createSprite("purple-bg")
    loadGraphic("purple-bg", "menu/purple-bg")
end

function finishedTransitionIn()
    doTweenY("fadeTween", "fadeBlackSprite", -windowHeight, 0.3, "quadOut")
end

function onUpdate(elapsed)
    if spriteExist("betterDifficulty") then
        if curDifficulty == 2 then
            setSpriteAngle("betterDifficulty", math.sin(tickSway) * 9)
            tickSway = tickSway + elapsed;
        else
            tickSway = 0
        end
    end

    if getControl("back") and not stopSpam then
        switchState("MainMenuState")
        stopSpam = true
    end
end

function onTweenCompleted(name)
    if name == "fadeTween" then
        if tweenCounter == 0 then
            removeSpriteFromState("fadeBlackSprite")
            setSpritePosition("fadeBlackSprite", 0, 0)
            insertSpriteToState(0, "fadeBlackSprite")
            insertSpriteToState(0, "purple-bg")
            doTweenY("fadeTween", "fadeBlackSprite", -windowHeight, 0.3, "quadOut")

            createSprite("betterDifficulty")
            setDifficultySprite()
            setSpritePosition("betterDifficulty", -50, 50)
            addSpriteToState("betterDifficulty")
        end

        if tweenCounter == 1 then
            doTweenY("staticGrpTween", "grpWeekText", -100, 0.3, "quadOut")
            doTweenAlpha("staticTextTween", "staticText", 1, 0.3, "quadOut")

            createSprite("lightningIcon")
            loadGraphic("lightningIcon", "menu/Lightning")
            addSpriteToState("lightningIcon")
            setSpritePosition("lightningIcon", getScreenCenter("lightningIcon", "x"), windowHeight)
            doTweenY("lightningTween", "lightningIcon", 200 + yCons, 0.4, "quadOut")

            createSprite("jtcIcon")
            loadGraphic("jtcIcon", "menu/JTC-Icon")
            addSpriteToState("jtcIcon")
            setSpritePosition("jtcIcon", -getSpriteWidth("jtcIcon"), getScreenCenter("jtcIcon", "y") - 75 + yCons)
            doTweenX("jtcTween", "jtcIcon", getScreenCenter("jtcIcon", "x") - getSpriteWidth("jtcIcon") + 40, 0.45, "elasticout")

            createSprite("bfIcon")
            loadGraphic("bfIcon", "menu/BF-Icon")
            addSpriteToState("bfIcon")
            setSpritePosition("bfIcon", windowWidth + getSpriteWidth("bfIcon"), getScreenCenter("bfIcon", "y") - 75 + yCons)
            doTweenX("bfTween", "bfIcon", getScreenCenter("bfIcon", "x") + getSpriteWidth("bfIcon") - 60, 0.45, "elasticout")

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
end

function setDifficultySprite()
    if curDifficulty == 0 then
        setSpriteAngle("betterDifficulty", 0)
        loadGraphic("betterDifficulty", "menu/easy")
    end

    if curDifficulty == 1 then
        setSpriteAngle("betterDifficulty", 0)
        loadGraphic("betterDifficulty", "menu/normal")
    end

    if curDifficulty == 2 then
        loadGraphic("betterDifficulty", "menu/cool")
    end
end

function destroyStuff() --Destroy in-game preloaded sprites.
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