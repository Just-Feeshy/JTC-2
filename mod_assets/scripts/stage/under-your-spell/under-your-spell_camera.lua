-- Declarative camera config for the school-house stage (under-your-spell).
-- Read by build/play/StageCamera.hx. Add keyframes for choreography; see frostbeat_camera.lua.

return {
    defaultZoom = 0.6,
    focusLerp = 0.09,
    characters = {
        dad = { focusOffset = { x = 0, y = 0 } },
        boyfriend = { focusOffset = { x = 0, y = 0 } },
        gf = { focusOffset = { x = 0, y = 0 } },
    },
    keyframes = {},
}
