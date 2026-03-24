local CAMERA_BOP_INTENSITY = 0.7
local CAMERA_BOP_RATE = 1

function onCreate()
    callEvent("setCameraBop", tostring(CAMERA_BOP_INTENSITY), tostring(CAMERA_BOP_RATE))
end
