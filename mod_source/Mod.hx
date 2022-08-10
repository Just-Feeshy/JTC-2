import flixel.FlxG;

import template.DialogueBuilder;
import example_code.DefaultStage;

import ImportModStuff;
import NotesJTC;

class Mod {
    static function onInit() {
        Register.remove(STAGE, DefaultStage); //Remove unwanted data from the game.

        //Register.attachLuaToState(OptionsMenuState, Paths.lua("modSettings"));
        Register.attachLuaToState(MainMenuState, Paths.lua("jtc_menu"));
        Register.attachLuaToState(StoryMenuState, Paths.lua("jtc_storymenu"));
        Register.attachLuaToState(FreeplayState, Paths.lua("jtc_freeplay"));
        Register.attachLuaToState(TitleState, Paths.lua("titleCard"));
        Register.implementDialogueToSong("funk-off", DialogueBoxJTC);
        Register.implementDialogueToSong("ping-pong", DialogueBoxJTC);
        Register.implementDialogueToSong("i-am-blue", DialogueBoxJTC);
        Register.implementCustomNote("cool", CoolNote);
        Register.implementCustomNote("cheese", CheeseNote);
        Register.implementCustomNote("death", DeathNote);
        Register.add(STAGE, CheesyStage);
    }
}