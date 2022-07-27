function onCreate()
    destroyStuff()

    createSprite("cheese")
    loadGraphic("cheese", "menu/story-mode-cheese")
    setSpriteClipRect("cheese", 0, 360)
    insertSpriteToState(0, "cheese")
end

function finishedTransitionIn()
    --doTweenSpriteClipRectY("cheeseTween", "cheese", 0, 0.6, "quadout")
end

function destroyStuff() --Destroy in-game preloaded sprites.
    destroySprite("menuBG")
    destroySprite("backdrop")
    destroySprite("blackBarTop")
    destroySprite("blackBarBottom")
end

function onTweenCompleted(name)
    print(name)
end