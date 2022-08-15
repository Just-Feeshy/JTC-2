function onCreate()
    if(catalog == "editors") then
        insertOption("custom dev editor", "other", 1)
    end
end

function whenOptionPressed(optionName)
    if(optionName == "custom dev editor") then
        switchState("DevStateTest");
    end
end