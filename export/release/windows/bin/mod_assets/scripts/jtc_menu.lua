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

function setupCustomOptions()
    return presetOptions;
end

function onCreate()
    setScrollFactorToSprite('chainGroup', 1, 1);

    for i=0, #presetOptions - 1 do
        if not spriteExist(presetOptions[i + 1]) then
            print("yea");
            createSprite(presetOptions[i + 1]);
        end

        compileSpriteSheet(presetOptions[i + 1], "cool mainmenu assets");
        decreaseSpriteSizeBy(presetOptions[i + 1], 1.75, 1.75);
        setSpritePosition(presetOptions[i + 1], menuPos[i + 1][1], menuPos[i + 1][2] + ((i + 1) * 400));
        playAnimationByPrefix(presetOptions[i + 1], 'idle', presetOptions[i + 1], 24, true);
        setSpriteAngle(presetOptions[i + 1], menuPos[i + 1][3]);

        if not spriteExist(presetOptions[i + 1]) then
            setSpriteAsMenuItem(presetOptions[i + 1]);
        end
    end

    createSprite('chain');
    compileSpriteSheet('chain', "cool mainmenu assets");
    decreaseSpriteSizeBy('chain', 1.5, 1.5);
    setSpritePosition('chain', 0, -100);
    setScrollFactorToSprite('chain', 0, 1);
    playAnimationByPrefix('chain', 'chain', 'jtc cool chain guy thing', 24, true);
    setSpriteAsDisplayChain('chain');
end

function callOptionChoice()
    setCameraZoomTween('cameraMenu', 2, 1.5, "quartOut");
end

function pressedAnOption(item)
    if item == 'crew' then
        switchState("CrewState")
    end
end