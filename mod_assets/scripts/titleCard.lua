function onUpdate(elapsed)
    setCameraZoom("mainCam", lerp(1, getCameraZoom("mainCam"), 0.95))
end

function onBeatHit()
    if getCameraZoom("mainCam") < 1.35 then
        setCameraZoom("mainCam", getCameraZoom("mainCam") + (6 * curElapsed))
    end
end

function onStartIntro()
    decreaseSpriteSizeBy("gfDance", 1.25, 1.25)
    setSpriteX("gfDance", windowWidth * 0.3)

    compileSpriteSheet("logoBl", "JTC logo bumpin")
    playAnimationByPrefix("logoBl", "bump", "JTC logobumpin")
    decreaseSpriteSizeBy("logoBl", 1.25, 1.25)
    setSpritePosition("logoBl", 0, -50)
end

function lerp(value1, value2, ratio)
    return value1 + ratio * (value2 - value1)
end