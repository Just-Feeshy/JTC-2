local menu_background = require("mod_assets/scripts/utils/menuBackground")
local menu_music = require("mod_assets/scripts/utils/menuMusic")

local appliedWallBackground = false

local function applyFreeplayBackground()
    if appliedWallBackground then
        return
    end

    appliedWallBackground = true

    menu_background.applyWithOverlay({
        background_name = "menuBG",
        fallback_background_name = "options_wall",
        overlay_name = "menuBGOverlay",
        fallback_overlay_name = "options_wall_overlay",
        camera = "cameraBackground"
    })
end

function onCreate()
    local backgroundBlur = menuBackgroundBlur or 0

    menu_music.markActiveIfPlaying()

    if backgroundBlur > 0 and setCameraBlur ~= nil then
        setCameraBlur("cameraBackground", backgroundBlur)
    elseif clearCameraBlur ~= nil then
        clearCameraBlur("cameraBackground")
    elseif setCameraBlur ~= nil then
        setCameraBlur("cameraBackground", 0)
    end

    applyFreeplayBackground()

    if(catalog == "editors") then
        insertOption("custom dev editor", "other", 1)
    end
end

function whenOptionPressed(optionName)
    if(optionName == "custom dev editor") then
        switchState("DevStateTest");
    end
end
