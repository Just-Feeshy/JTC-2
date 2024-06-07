import flixel.FlxG;

import feshixl.math.FeshMath;

import template.DialogueBuilder;
import example_code.DefaultStage;

import ImportModStuff;
import NotesJTC;

class Mod {
    static function onInit() {
        Register.setStageForMod(CheesyStage); //Remove unwanted data from the game.

		// Add the lua files to the game
        Register.attachLuaToState(OptionsMenuState, Paths.lua("modSettings"));
        Register.attachLuaToState(MainMenuState, Paths.lua("jtc_menu"));
        Register.attachLuaToState(StoryMenuState, Paths.lua("jtc_storymenu"));
        Register.attachLuaToState(FreeplayState, Paths.lua("jtc_freeplay"));
        Register.attachLuaToState(TitleState, Paths.lua("titleCard"));

		// Add the custom notes to the game
        Register.implementDialogueToSong("funk-off", DialogueBoxJTC);
        Register.implementDialogueToSong("ping-pong", DialogueBoxJTC);
        Register.implementDialogueToSong("i-am-blue", DialogueBoxJTC);
        Register.implementCustomNote("cool", CoolNote);
        Register.implementCustomNote("cheese", CheeseNote);
        Register.implementCustomNote("death", DeathNote);
    }
}
