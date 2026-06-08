function onCreate()
	playMusic("ending/" .. ending, 1, true)

	createSprite("background")
	loadGraphic("background", "school_house/ending/" .. ending)
	setSpriteAlpha("background", 0)
	doTweenAlpha("bt", "background", 1, 2.4, "quadout")
	addSpriteToState("background")

    createText("endHint", 0, 0, windowWidth - 60, "Press " .. keyToSkip .. " to Return", 24)
    setTextFont("endHint", "cheese.otf")
    setTextBorder("endHint", "OUTLINE", 2, "0xFF000000")
    setTextPosition("endHint", 0, 20)
    addTextToState("endHint")
    screenCenter("endHint", "x")
end
