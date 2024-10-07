
local inputs = {}

-- measurements
inputs.MAPPED = {}
inputs.STATUS = {}

inputs.MAPPED.UP = 87 -- W
inputs.MAPPED.DOWN = 83 -- S
inputs.MAPPED.LEFT = 65 -- A
inputs.MAPPED.RIGHT = 68 -- D
inputs.MAPPED.SPACE = 32 -- SPACE
inputs.MAPPED.SCALE_UP = 81 -- Q
inputs.MAPPED.SCALE_DOWN = 69 -- E

inputs.STATUS.JUST_RELEASED = -1
inputs.STATUS.RELEASED = 0
inputs.STATUS.PRESSED = 1
inputs.STATUS.JUST_PRESSED = 2

return inputs
