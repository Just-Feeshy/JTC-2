--Character template to make initialzing characters through lua easier.
--Made by Feeshy

Character = {}
Character.__index = Character

local instance = {
    stunned = false;
    dancing = true;
}

function Character.new(name, characterName, x, y)
    local instance = setmetatable({}, Character)

    createCharacterSprite(name, characterName, x, y)
    addSpriteToStage(name)

    instance.name = name
    instance.holdTimer = 0
    instance.singMultiplier = 4
    instance.stunned = false
    instance.dancing = true

    return instance
end

--function Character:initSingAnims(args)
--    self.sing = args
--end

--function Character:playSingAnimFromNote(note)
--    if not note[6] or (note[6] and self.dancing) then
--        self.dancing = false
--        --playAnim(self.sing[note[3] + 1], true)
--    end
--end

function Character:dance(name)
    print("dancing: " + self.dancing)

    --if self.dancing and not self.stunned then
    --    self.dancing = true
    --    print("haha")
    --    playAnim(name, false)
    --end
end

return Character