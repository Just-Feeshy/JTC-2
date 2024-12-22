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

function onBeatHit()
end

function onStartIntro()
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
end

function onSkipIntro()
end
