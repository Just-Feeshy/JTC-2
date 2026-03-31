local FrostShader = {}
FrostShader.__index = FrostShader

-- Constructor - references existing shader
function FrostShader.new(shaderName)
	local self = setmetatable({}, FrostShader)

	self.name = shaderName
	self.properties = {}
	self.boundCamera = nil
	self.initialized = false

	return self
end

-- Initialize shader
function FrostShader:init()
	if not self.initialized and initLuaShader ~= nil then
		initLuaShader(self.name, "shaders")
		self.initialized = true
	end
	return self
end

-- Bind shader to a camera
function FrostShader:bindToCamera(cameraName)
	if cameraName and setCameraShader ~= nil then
		self:init()
		setCameraShader(cameraName, self.name)
		self.boundCamera = cameraName
	end
	return self
end

-- Unbind from camera
function FrostShader:unbindFromCamera()
	if self.boundCamera and removeCameraShader ~= nil then
		removeCameraShader(self.boundCamera)
		self.boundCamera = nil
	end
	return self
end

-- Set shader property (float)
function FrostShader:setProperty(name, value)
	if self.boundCamera and setShaderFloat ~= nil then
		setShaderFloat(self.boundCamera, name, value)
	end
	self.properties[name] = value
	return self
end

-- Get currently bound camera
function FrostShader:getBoundCamera()
	return self.boundCamera
end

return FrostShader
