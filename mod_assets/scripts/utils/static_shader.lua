local StaticShader = {}
StaticShader.__index = StaticShader

-- Constructor - references existing shader
function StaticShader.new(shaderName)
	local self = setmetatable({}, StaticShader)

	self.name = shaderName
	self.properties = {}
	self.boundCamera = nil
	self.initialized = false

	return self
end

-- Initialize shader
function StaticShader:init()
	if not self.initialized and initLuaShader ~= nil then
		initLuaShader(self.name, "shaders")
		self.initialized = true
	end
	return self
end

-- Bind shader to a camera
function StaticShader:bindToCamera(cameraName)
	if cameraName and setCameraShader ~= nil then
		self:init()
		setCameraShader(cameraName, self.name)
		self.boundCamera = cameraName
	end
	return self
end

-- Unbind from camera
function StaticShader:unbindFromCamera()
	if self.boundCamera and removeCameraShader ~= nil then
		removeCameraShader(self.boundCamera)
		self.boundCamera = nil
	end
	return self
end

-- Set shader property (float)
function StaticShader:setProperty(name, value)
	if self.boundCamera and setShaderFloat ~= nil then
		setShaderFloat(self.boundCamera, name, value)
	end
	self.properties[name] = value
	return self
end

-- Get currently bound camera
function StaticShader:getBoundCamera()
	return self.boundCamera
end

return StaticShader
