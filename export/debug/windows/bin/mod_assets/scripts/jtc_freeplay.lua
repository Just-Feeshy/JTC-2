function onCreate()
    destroyStuff()

    createSprite("freeplay-bg")
    loadGraphic("freeplay-bg", "menu/freeplay-bg")
    insertSpriteToState(0, "freeplay-bg")


end

function destroyStuff() --Destroy in-game preloaded sprites.
    destroySprite("menuBG")
end