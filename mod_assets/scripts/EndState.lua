function onCreate()

    createText("endHint", 0, 0, windowWidth, "Press ACCEPT to return to Freeplay", 24)
    setTextFont("endHint", "phantom.ttf")
    setTextColor("endHint", "0xFFCCCCCC")
    setTextBorder("endHint", "OUTLINE", 2, "0xFF000000")
    setTextPosition("endHint", 0, windowHeight / 2 + 40)
    addTextToState("endHint")
    screenCenter("endHint", "x")
end
