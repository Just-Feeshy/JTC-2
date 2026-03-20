local menu_music = require("mod_assets/scripts/utils/menuMusic")

local menuPos = { --Positioning for menu stuff
    {90, -260, -12},
    {-90 * 7, -220, -16},
    {90 * 3.5, -520, -24},
    {-90 * 3.7, -230, -36}
};

local presetOptions = {
    'story mode',
    'freeplay',
    'crew',
    'settings'
}

local chainRestX = 0
local chainHiddenX = 0
local chainHiddenRightX = 0
local pendingOption = nil
local pendingExitDelay = 0
local chainExitStarted = false
local appliedWallBackground = false

local function applyFreeplayBackground()
    if appliedWallBackground then
        return
    end

    appliedWallBackground = true

    if spriteExist("menuBGOverlay") then
        setSpriteAlpha("menuBGOverlay", 0.2)
    end
end

function setupCustomOptions()
    return presetOptions;
end

function onCreate()
    pendingOption = nil
    pendingExitDelay = 0
    chainExitStarted = false

    cancelTween('chainIntro')
    cancelTween('chainExit')
    cancelTween('camMenuZoom')
    setCameraZoom('cameraMenu', 1.1)

    setBackgroundBlur(menuBackgroundBlur or 0)
    setBackgroundSaturation(1.5)
    setMenuSaturation(1.1)
    applyFreeplayBackground()
    menu_music.resume()

    setScrollFactorToSprite('chainGroup', 1, 1);

    for i=0, #presetOptions - 1 do
        if not spriteExist(presetOptions[i + 1]) then
            createSprite(presetOptions[i + 1]);
        end

        compileSpriteSheet(presetOptions[i + 1], "cool_mainmenu_assets");
        decreaseSpriteSizeBy(presetOptions[i + 1], 1.75, 1.75);
        setSpritePosition(presetOptions[i + 1], menuPos[i + 1][1], menuPos[i + 1][2] + ((i + 1) * 400));
        playAnimationByPrefix(presetOptions[i + 1], 'idle', presetOptions[i + 1], 24, true);
        setSpriteAngle(presetOptions[i + 1], menuPos[i + 1][3]);

        if not spriteExist(presetOptions[i + 1]) then
            setSpriteAsMenuItem(presetOptions[i + 1]);
        end
    end

    createSprite('chain');
    compileSpriteSheet('chain', "cool_mainmenu_assets");
    decreaseSpriteSizeBy('chain', 1.5, 1.5);
    chainHiddenX = -windowWidth - 800
    chainHiddenRightX = windowWidth + 800
    setSpritePosition('chain', 0, -100);
    setScrollFactorToSprite('chain', 0, 1);
    playAnimationByPrefix('chain', 'chain', 'jtc cool chain guy thing', 24, true);
    setSpriteAsDisplayChain('chain');
    setSpritePosition('chainGroup', chainHiddenX, 0);

    doTweenX('chainIntro', 'chainGroup', chainRestX, 0.6, "quartOut");
end

function callOptionChoice(item)
    pendingOption = item
    pendingExitDelay = 0.2
    chainExitStarted = false

    cancelTween('chainIntro')
    cancelTween('chainExit')
    doTweenZoom('camMenuZoom', 'cameraMenu', 2, 1.5, "quartOut");
end

local function startChainExit()
    local exitX = chainHiddenX

    if pendingOption == 'settings' or pendingOption == 'options' then
        exitX = chainHiddenRightX
    end

    chainExitStarted = true
    doTweenX('chainExit', 'chainGroup', exitX, 0.45, "quartIn")
end

function onUpdate(elapsed)
    menu_music.cacheTime()

    if pendingOption ~= nil and not chainExitStarted then
        pendingExitDelay = pendingExitDelay - elapsed

        if pendingExitDelay <= 0 then
            startChainExit()
        end
    end
end

function onTweenCompleted(name)

    if name == 'chainExit' and pendingOption ~= nil then
        pressedAnOption(pendingOption)
        pendingOption = nil
        pendingExitDelay = 0
        chainExitStarted = false
    end
end

function pressedAnOption(item)
    if finishMenuOptionChoice ~= nil then
        finishMenuOptionChoice(item)
    end
end
