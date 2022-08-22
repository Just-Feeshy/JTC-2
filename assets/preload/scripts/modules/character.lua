--Character template to make initialzing characters through lua a little easier.
--Made by Feeshy

--NOTE: Using a metadata table would cause issues, and I'm too lazy to figure out a solution.

character = {
    name = "";
    holdTimer = 0;
    singMultiplier = 4;
    stunned = 0;
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
    if character.dancing then
        print("hello world")
    end
end

return character