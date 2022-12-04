--Character template to make initialzing characters through lua a little easier.
--NOTE: Using a metadata table would cause issues, and I'm too lazy to figure out a solution.

local character = {
    name = "";

    sings = {};
}

function character.create(name, characterName, x, y, isPlayer)
    createCharacterSprite(name, characterName, x, y, isPlayer)
    character.name = name
end

function character.initSing(args)
    character.sings = args
end

function character.dance()
    if getCharacterDancing(character.name) and not getCharacterStunned(character.name) then
        characterDance(character.name)
    end

    if getCharacterIsPlayer(character.name) then
        if getCharacterHoldTimer(character.name) > stepCrochet * 0.0044 and not getCharacterDancing(character.name) and not getCharacterStunned(character.name) then
            characterDance(character.name)
        end
    end
end

function character.singByNote(noteData, isSustainNote)
    if not isSustainNote or (isSustainNote and getCharacterDancing(character.name)) then
        playAnim(character.name, character.sings[noteData + 1], true)
    end

    setCharacterHoldTimer(character.name, 0)
end

function character.missByNote(noteData)
    playAnim(character.name, character.sings[noteData + 1] + "miss", true)
end

return character