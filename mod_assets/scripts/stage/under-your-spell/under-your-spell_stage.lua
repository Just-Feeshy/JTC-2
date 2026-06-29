-- School-house stage for under-your-spell.
-- Runs in its own Lua VM alongside scripts/song/under-your-spell.lua (see build/play/PlayLua.hx).
-- Loaded via the per-song stage dir (resolveScriptKeys falls back to the song directory).

local school_stage = require("mod_assets/scripts/components/school_stage")
local camera = require("mod_assets/scripts/stage/under-your-spell/under-your-spell_camera")

function generatedStage()
    school_stage.generatedStage()

    -- Register the declarative camera config (school's camera is also set imperatively by
    -- school_stage; with no keyframes the StageCamera layer stays idle, so they don't fight).
    if setStageCameraConfig ~= nil then
        setStageCameraConfig(camera)
    end
end
