--Character template to make initialzing characters through lua a little easier.
--NOTE: Using a metadata table would cause issues, and I'm too lazy to figure out a solution.

character = {
    name = "";
    holdTimer = 0;
    singMultiplier = 4;
    stunned = 0;
    dancing = 1;

    sings = {};
}

function character.create(name, characterName, x, y)
    createCharacterSprite(name, characterName, x, y)

    character.name = name
    character.holdTimer = 0
    character.singMultiplier = 4
    character.stunned = 0
    character.dancing = 1
end

function character.initSing(args)
    character.sings = args
end

function character.dance(name)
    if character.dancing == 1 and character.stunned == 0 then
        playAnim(character.name, name)
    end

    if character.holdTimer >= stepCrochet * 0.0044 then
        character.dancing = 1
        playAnim(character.name, name)
        character.holdTimer = 0
    end
end

function character.singByNote(noteData, isSustainNote)
    if not isSustainNote or (isSustainNote and character.dancing == 1) then
        character.dancing = 0
        playAnim(character.name, character.sings[noteData + 1], true)
        character.holdTimer = character.holdTimer + curElapsed
    end

    character.holdTimer = 0
end

return character