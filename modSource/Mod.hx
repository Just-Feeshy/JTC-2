import flixel.FlxG;

import template.DialogueBuilder;

import ImportModStuff;
import NotesJTC;

class Mod {
    static function onInit() {
        Register.attachLuaToState(MainMenuState, new ModLua(Paths.lua("jtc_menu")));
        Register.attachLuaToState(OptionsMenuState, new ModLua(Paths.lua("modSettings")));
        Register.implementDialogueToSong("funk-off", DialogueBoxJTC);
        Register.implementDialogueToSong("ping-pong", DialogueBoxJTC);
        Register.implementDialogueToSong("i-am-blue", DialogueBoxJTC);
        Register.implementCustomNote("cool", CoolNote);
        Register.implementCustomNote("cheese", CheeseNote);
        Register.implementCustomNote("death", DeathNote);
        Register.add(STAGE, CheesyStage);

        /**
        * HaxeFlixel's way of doing saves is really good.
        */
        if(FlxG.save.data.spanish == null) {
            FlxG.save.data.spanish = false;
        }
    }
}