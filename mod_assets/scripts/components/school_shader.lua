local school_shader = {}

local SHADER_NAME = "school_lighting"
local TARGET_CAMERA = "camGame"
local DEFAULT_INTENSITY = 0.5
local DEFAULT_BLOOM = 1.15

local initialized = false
local active = false
local currentIntensity = 0
local targetIntensity = 0
local fadeRate = 0
local currentBloom = DEFAULT_BLOOM

local function ensureShader()
	if active then
		return true
	end

	if initLuaShader == nil then
		print("[school_shader] initLuaShader callback missing")
		return false
	end

	if not initialized then
		local ok = initLuaShader(SHADER_NAME, "shaders")
		print("[school_shader] initLuaShader returned: " .. tostring(ok))
		initialized = ok == true
	end

	if not initialized then
		print("[school_shader] shader not initialized, aborting")
		return false
	end

	if setCameraShader == nil then
		print("[school_shader] setCameraShader callback missing")
		return false
	end

	local attached = setCameraShader(TARGET_CAMERA, SHADER_NAME)
	print("[school_shader] setCameraShader(" .. TARGET_CAMERA .. ", " .. SHADER_NAME .. ") returned: " .. tostring(attached))
	active = attached == true

	if active then
		setShaderFloat(TARGET_CAMERA, "intensity", currentIntensity)
		setShaderFloat(TARGET_CAMERA, "bloomStrength", currentBloom)
		print("[school_shader] shader ACTIVE on " .. TARGET_CAMERA)
	end

	return active
end

function school_shader.enable(intensity, fadeSeconds)
	if intensity == nil then
		intensity = DEFAULT_INTENSITY
	end

	if not ensureShader() then
		return
	end

	targetIntensity = math.max(0, math.min(1, intensity))

	if fadeSeconds == nil or fadeSeconds <= 0 then
		currentIntensity = targetIntensity
		fadeRate = 0
		setShaderFloat(TARGET_CAMERA, "intensity", currentIntensity)
	else
		fadeRate = (targetIntensity - currentIntensity) / fadeSeconds
	end
end

function school_shader.disable(fadeSeconds)
	if not active then
		return
	end

	targetIntensity = 0

	if fadeSeconds == nil or fadeSeconds <= 0 then
		currentIntensity = 0
		fadeRate = 0
		setShaderFloat(TARGET_CAMERA, "intensity", 0)
		if removeCameraShader ~= nil then
			removeCameraShader(TARGET_CAMERA)
		end
		active = false
	else
		fadeRate = (targetIntensity - currentIntensity) / fadeSeconds
	end
end

function school_shader.setIntensity(intensity)
	school_shader.enable(intensity, 0)
end

function school_shader.setBloom(value)
	currentBloom = math.max(0, value)
	if active then
		setShaderFloat(TARGET_CAMERA, "bloomStrength", currentBloom)
	end
end

function school_shader.onUpdate(elapsed)
	if not active then
		return
	end

	if setCameraShader ~= nil then
		setCameraShader(TARGET_CAMERA, SHADER_NAME)
		setShaderFloat(TARGET_CAMERA, "bloomStrength", currentBloom)
	end

	if fadeRate ~= 0 then
		currentIntensity = currentIntensity + fadeRate * elapsed

		if (fadeRate > 0 and currentIntensity >= targetIntensity)
			or (fadeRate < 0 and currentIntensity <= targetIntensity) then
			currentIntensity = targetIntensity
			fadeRate = 0
		end
	end

	setShaderFloat(TARGET_CAMERA, "intensity", currentIntensity)

	if currentIntensity <= 0 and targetIntensity <= 0 then
		if removeCameraShader ~= nil then
			removeCameraShader(TARGET_CAMERA)
		end
		active = false
	end
end

function school_shader.isActive()
	return active
end

return school_shader
