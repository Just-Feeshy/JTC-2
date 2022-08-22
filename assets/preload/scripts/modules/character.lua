--Character template to make initialzing characters through lua easier.
--Made by Feeshy

--NOTE: Using a metadata table would cause issues, and I'm too lazy to figure out a solution.

character = {
    name = "";
    holdTimer = 0;
    singMultiplier = 4;
    stunned = false;
    dancing = 1;
}

function character.add(name, characterName, x, y)
    createCharacterSprite(name, characterName, x, y)
    addSpriteToStage(name)

    character.name = name
    character.holdTimer = 0
    character.singMultiplier = 4
    character.stunned = 0
    character.dancing = 1
end

function character.dance()
    print(tonumber(character.dancing))
end

return character