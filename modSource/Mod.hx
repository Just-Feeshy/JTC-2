import CrewState;

import lime.utils.Assets;

class Mod {
    static public function onInit() {
        Register.attachLuaToState(MainMenuState, new ModLua(Paths.lua("jtc_menu")));
        //trace(Assets.getText("config/mod.json"));
    }
}