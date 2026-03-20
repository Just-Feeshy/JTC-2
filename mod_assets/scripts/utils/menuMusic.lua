local menu_music = {}

local MENU_MUSIC_NAME = "Main Menu"
local MENU_MUSIC_TIME_KEY = "jtc.main_menu_music_time"
local MENU_MUSIC_ACTIVE_KEY = "jtc.main_menu_music_active"
local MENU_MUSIC_VOLUME = 0.8

local function toNumber(value, fallback)
    if type(value) == "number" then
        return value
    end

    local parsed = tonumber(value)
    if parsed ~= nil then
        return parsed
    end

    return fallback
end

function menu_music.markActive()
    if setGlobalVar ~= nil then
        setGlobalVar(MENU_MUSIC_ACTIVE_KEY, true)
    end
end

function menu_music.markInactive()
    if setGlobalVar ~= nil then
        setGlobalVar(MENU_MUSIC_ACTIVE_KEY, false)
    end
end

function menu_music.markActiveIfPlaying()
    if isMusicPlaying ~= nil and isMusicPlaying() then
        menu_music.markActive()
    end
end

function menu_music.cacheTime()
    if setGlobalVar == nil or getMusicTime == nil then
        return
    end

    setGlobalVar(MENU_MUSIC_TIME_KEY, getMusicTime())
end

function menu_music.resume()
    local alreadyActive = false

    if getGlobalVar ~= nil then
        alreadyActive = getGlobalVar(MENU_MUSIC_ACTIVE_KEY, false) == true
    end

    if alreadyActive and isMusicPlaying ~= nil and isMusicPlaying() then
        return
    end

    local resumeTime = 0
    if getGlobalVar ~= nil then
        resumeTime = toNumber(getGlobalVar(MENU_MUSIC_TIME_KEY, 0), 0)
    end

    if playMusicAt ~= nil then
        playMusicAt(MENU_MUSIC_NAME, resumeTime, MENU_MUSIC_VOLUME, true)
    elseif playMusic ~= nil then
        playMusic(MENU_MUSIC_NAME, MENU_MUSIC_VOLUME, true)

        if setMusicTime ~= nil then
            setMusicTime(resumeTime)
        end
    end

    menu_music.markActive()
end

return menu_music
