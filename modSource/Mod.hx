import example_code.DefaultDialogueBox;

class Mod {
    static public function onInit() {
        Register.attachLuaToState(MainMenuState, new ModLua(Paths.lua("jtc_menu")));
        Register.add(STAGE, CheesyStage);
    }
}