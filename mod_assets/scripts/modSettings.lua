function onCreate()
    if(catalog == "none") then
        insertOption("mod settings", "section", 2)
    elseif(catalog == "mod") then
        insertOption("dialogue language", "other", 0)
    elseif(catalog == "editors") then
        insertOption("custom dev editor", "other", 1)
    end
end

function whenOptionPressed(optionName)
    if(optionName == "mod settings") then
        enterOptionState("mod")
    elseif(optionName == "custom dev editor") then
        switchState("DevStateTest");
    end
end

function createOptionSubState(optionName)
    if(optionName == "dialogue language") then
        return "TranslationSelector"
    end

    return nil;
end