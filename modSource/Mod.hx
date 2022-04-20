import CrewState;

import lime.utils.Assets;

class Test1 {
    public function new() {
        return;
    }
}

class Test2 extends Test1{
    public function new() {
        super();
    }
}

class Mod {
    static public function onInit() {
        var classy:Class<Test1>;

        Register.attachLuaToState(MainMenuState, new ModLua(Paths.lua("jtc_menu")));
        //trace(Assets.getText("config/mod.json"));

        classy = Test2;
    }
}