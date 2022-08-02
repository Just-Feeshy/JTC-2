local curElapsed = 0

function onUpdate(elapsed)
    setCameraZoom("mainCam", lerp(1, getCameraZoom("mainCam"), 0.95))
    curElapsed = elapsed
end

function onBeatHit()
    print("OH NO")

    if getCameraZoom("mainCam") < 1.35 then
        setCameraZoom("mainCam", getCameraZoom("mainCam") + (15 * curElapsed))
    end
end

function lerp(value1, value2, ratio)
    return value1 + ratio * (value2 - value1)
end