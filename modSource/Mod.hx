import flixel.FlxG;

import example_code.DefaultDialogueBox;

import TranslationSelector;
import CrewState;

class Mod {
    static function onInit() {
        Register.attachLuaToState(MainMenuState, new ModLua(Paths.lua("jtc_menu")));
        Register.attachLuaToState(OptionsMenuState, new ModLua(Paths.lua("modSettings")));
        Register.add(STAGE, CheesyStage);

        /**
        * HaxeFlixel's way of doing saves is really good.
        */
        if(FlxG.save.data.spanish != null) {
            FlxG.save.data.spanish = false;
        }
    }
}