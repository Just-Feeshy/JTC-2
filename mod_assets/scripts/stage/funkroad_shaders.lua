local funkroad_shaders = {}

local SHADER_NAME = "funkroad_shader"
local SHADER_TAG = "funkroad_runtime"
local NOTE_SHADER_NAME = "funkroad_note_curve"
local NOTE_SHADER_TAG = "funkroad_note_curve_runtime"
local SUSTAIN_CURVE_KEY = "funkroadSustainCurveStrength"

function funkroad_shaders.init()
    if initLuaShader ~= nil then
        initLuaShader(SHADER_NAME, "feeshdata")
    end

    return true
end

function funkroad_shaders.applyToGameCamera()
    if createRuntimeShader == nil or setCameraShader == nil then
        return false
    end

    createRuntimeShader(SHADER_NAME, SHADER_TAG)
    return setCameraShader("game", SHADER_TAG)
end

function funkroad_shaders.applyToWholeGame()
    if createRuntimeShader == nil or setGameShader == nil then
        return false
    end

    createRuntimeShader (SHADER_NAME, SHADER_TAG)
    return setGameShader(SHADER_NAME, SHADER_TAG)
end

function funkroad_shaders.removeFromGameCamera()
    if removeCameraShader == nil then
        return false
    end

    return removeCameraShader("game")
end

function funkroad_shaders.removeFromWholeGame()
    if removeGameShader == nil then
        return false
    end

    return removeGameShader(SHADER_TAG)
end

function funkroad_shaders.applyToSustainCamera()
    return true
end

function funkroad_shaders.removeFromSustainCamera()
    return true
end

function funkroad_shaders.setNoteCurve(strength, originY, laneCentersA, laneCentersB, laneCentersC, laneCount, padding)
    return funkroad_shaders.setSustainCurve(strength)
end

function funkroad_shaders.setSustainCurve(strength)
    if setGlobalVar == nil then
        return false
    end

    setGlobalVar(SUSTAIN_CURVE_KEY, strength or 0)
    return true
end

return funkroad_shaders
