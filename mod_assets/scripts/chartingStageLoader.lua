local school_stage = require("mod_assets/scripts/components/school_stage")

local stageLoaded = false

local function normalizedString(value)
    if type(value) ~= "string" then
        return ""
    end

    return string.lower(value)
end

local function shouldLoadSchoolStage()
    if stageLoaded then
        return false
    end

    local stageName = normalizedString(chartStageName)
    local songDirectory = normalizedString(chartSongDirectory)
    return stageName == "school_house" or songDirectory == "under-your-spell"
end

function onCreate()
end

function loadEditorStage()
    if not shouldLoadSchoolStage() then
        return
    end

    stageLoaded = true

    if spriteExist ~= nil and spriteExist("chartEditorBackground") then
        setSpriteVisible("chartEditorBackground", false)
    end

    school_stage.generatedStage()
end
