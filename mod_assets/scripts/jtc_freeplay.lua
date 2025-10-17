function onCreate()
    destroyStuff()

    createSprite("wall")
    loadGraphic("wall", "Graffiti/wall")
    insertSpriteToState(0, "wall")
end

function destroyStuff() --Destroy in-game preloaded sprites.
    destroySprite("menuBG")
end