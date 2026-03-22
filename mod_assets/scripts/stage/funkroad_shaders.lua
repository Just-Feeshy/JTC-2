local funkroad_shaders = {}

local SHADER_NAME = "funkroad_shader"
local SHADER_TAG = "funkroad_runtime"

function funkroad_shaders.init()
    if initLuaShaderSource == nil then
        return false
    end

    return initLuaShaderSource(SHADER_NAME, [[
        #pragma header

        void main() {
            gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
        }
    ]], "")
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

return funkroad_shaders
