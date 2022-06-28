package;

import flixel.FlxG;
import flixel.util.FlxSave;
import flixel.util.FlxDestroyUtil;
import flixel.input.keyboard.FlxKey;

import openfl.display.FPS;

enum SaveType {
    NONE;
    DOWNSCROLL;
    PRESET_KEYBINDS;
    PERFECT_MODE_MOD;
    FLIP_CHART_MOD;
    CUSTOM_HELL_MOD;
    FAIR_BATTLE_MOD;
    FADE_BATTLE_MOD;
    SHOW_BOTTOM_BAR;
    SHOW_NOTE_SPLASH;
    GRAPHICS;
    SET_FPS_DEFAULT;
    FPS_MULTIPLIER;
    NO_BLUE_BALLS_MOD;
    BLIND_MOD;
    X_WOBBLE_MOD;
    PRESET_INPUTS;
    CACHE_ASSETS;
    CUSTOM_KEYBINDS;
    CUSTOM_UI_KEYBINDS;
    CAMERA_MOVEMENT_MOD;
    GHOST_TAPPING;
    CUSTOM_MENU_BINDS;
    GAMMA;
    VOLUME;
    ERASE_DATA;
    SHOW_FPS;
    SHOW_MEMORY;
}

class SaveData {
    @:allow(Preloader)
    @:allow(OptionsMenuState)
    static private var globalFPS:FPS;

    @:allow(Preloader)
    @:allow(OptionsMenuState)
    static private var globalMEM:Memory;

    /**
    * POSSIBLITIY: Make a `saveServer()` method.
    */

    inline static public function saveClient() {
        FlxG.save.data.helpme = getData(SaveType.DOWNSCROLL);
        FlxG.save.data.dfjk = getData(SaveType.PRESET_KEYBINDS);
        FlxG.save.data.perfectMode = getData(SaveType.PERFECT_MODE_MOD);
        FlxG.save.data.flip = getData(SaveType.FLIP_CHART_MOD);
        FlxG.save.data.customhell = getData(SaveType.CUSTOM_HELL_MOD);
        FlxG.save.data.fair = getData(SaveType.FAIR_BATTLE_MOD);
        FlxG.save.data.fade = getData(SaveType.FADE_BATTLE_MOD);
        FlxG.save.data.showstuff = getData(SaveType.SHOW_BOTTOM_BAR);
        FlxG.save.data.showEffect = getData(SaveType.SHOW_NOTE_SPLASH);
        FlxG.save.data.showAntialiasing = getData(SaveType.GRAPHICS);
        FlxG.save.data.lowFps = getData(SaveType.SET_FPS_DEFAULT);
        FlxG.save.data.fpsMulti = getData(SaveType.FPS_MULTIPLIER);
        FlxG.save.data.safeballs = getData(SaveType.NO_BLUE_BALLS_MOD);
        FlxG.save.data.blind = getData(SaveType.BLIND_MOD);
        FlxG.save.data.xWobble = getData(SaveType.X_WOBBLE_MOD);
        FlxG.save.data.simpInputs = getData(SaveType.PRESET_INPUTS);
        FlxG.save.data.preload = getData(SaveType.CACHE_ASSETS);
        FlxG.save.data.customKeys = getData(SaveType.CUSTOM_KEYBINDS);
        FlxG.save.data.customUIKeys = getData(SaveType.CUSTOM_UI_KEYBINDS);
        FlxG.save.data.camMove = getData(SaveType.CAMERA_MOVEMENT_MOD);
        FlxG.save.data.ghostTapping = getData(SaveType.GHOST_TAPPING);
        FlxG.save.data.menuBinds = getData(SaveType.CUSTOM_MENU_BINDS);
        FlxG.save.data.gamma = getData(SaveType.GAMMA);
        FlxG.save.data.volume = getData(SaveType.VOLUME);
        FlxG.save.data.showFPS = getData(SaveType.SHOW_FPS);
        FlxG.save.data.showMEM = getData(SaveType.SHOW_MEMORY);

        FlxG.save.flush();

        refreshData();
    }

    inline static public function getData(data:SaveType):Dynamic {
        switch(data) {
            case DOWNSCROLL:
                if (FlxG.save.data.helpme == null)
                    FlxG.save.data.helpme = false;
                
                return FlxG.save.data.helpme;
            case PRESET_KEYBINDS:
                #if (haxe >= "4.2.1")
                if (FlxG.save.data.dfjk == null)
                    FlxG.save.data.dfjk = 0;
                else if(!Std.isOfType(FlxG.save.data.dfjk, Int))
                    FlxG.save.data.dfjk = 0;
                #else
                if (FlxG.save.data.dfjk == null)
                    FlxG.save.data.dfjk = 0;
                else if(!Std.is(FlxG.save.data.dfjk, Int))
                    FlxG.save.data.dfjk = 0;
                #end

                return FlxG.save.data.dfjk;
            case PERFECT_MODE_MOD:
                if(FlxG.save.data.perfectMode == null)
                    FlxG.save.data.perfectMode = 0;

                return FlxG.save.data.perfectMode;
            case FLIP_CHART_MOD:
                if(FlxG.save.data.flip == null)
                    FlxG.save.data.flip = false;

                return FlxG.save.data.flip;
            case CUSTOM_HELL_MOD:
                if(FlxG.save.data.customhell == null)
                    FlxG.save.data.customhell = false;

                return FlxG.save.data.customhell;
            case FAIR_BATTLE_MOD:
                if(FlxG.save.data.fair == null)
                    FlxG.save.data.fair = false;

                return FlxG.save.data.fair;
            case FADE_BATTLE_MOD:
                if(FlxG.save.data.fade == null)
                    FlxG.save.data.fade = false;

                return FlxG.save.data.fade;
            case SHOW_BOTTOM_BAR:
                if(FlxG.save.data.showstuff == null)
                    FlxG.save.data.showstuff = true;

                return FlxG.save.data.showstuff;
            case SHOW_NOTE_SPLASH:
                if(FlxG.save.data.showEffect == null)
                    FlxG.save.data.showEffect = true;

                return FlxG.save.data.showEffect;
            case GRAPHICS:
                if(FlxG.save.data.showAntialiasing == null)
                    FlxG.save.data.showAntialiasing = true;

                return FlxG.save.data.showAntialiasing;
            case SET_FPS_DEFAULT:
                #if (haxe >= "4.2.1")
                if (FlxG.save.data.lowFps == null)
                    FlxG.save.data.lowFps = 60;
                else if(!Std.isOfType(FlxG.save.data.lowFps, Int))
                    FlxG.save.data.lowFps = 60;
                #else
                if (FlxG.save.data.lowFps == null)
                    FlxG.save.data.lowFps = 60;
                else if(!Std.is(FlxG.save.data.lowFps, Int))
                    FlxG.save.data.lowFps = 60;
                #end

                return FlxG.save.data.lowFps;
            case NO_BLUE_BALLS_MOD:
                if(FlxG.save.data.safeballs == null)
                    FlxG.save.data.safeballs = false;

                return FlxG.save.data.safeballs;
            case BLIND_MOD:
                if(FlxG.save.data.blind == null)
                    FlxG.save.data.blind = false;

                return FlxG.save.data.blind;
            case X_WOBBLE_MOD:
                if(FlxG.save.data.xWobble == null)
                    FlxG.save.data.xWobble = false;

                return FlxG.save.data.xWobble;
            case PRESET_INPUTS:
                if(FlxG.save.data.simpInputs == null)
                    FlxG.save.data.simpInputs = false;

                return FlxG.save.data.simpInputs;
            case CACHE_ASSETS:
                if(FlxG.save.data.preload == null)
                    FlxG.save.data.preload = true;

                return FlxG.save.data.preload;
            case CUSTOM_KEYBINDS:
                if(FlxG.save.data.customKeys == null) {
                    FlxG.save.data.customKeys = new Array<Array<FlxKey>>();

                    FlxG.save.data.customKeys = [
                        [FlxKey.A, FlxKey.LEFT], //LEFT
                        [FlxKey.S, FlxKey.DOWN], //DOWN
                        [FlxKey.W, FlxKey.UP], //UP
                        [FlxKey.D, FlxKey.RIGHT], //RIGHT
                        [FlxKey.SPACE] //SPACE
                    ];
                }

                return FlxG.save.data.customKeys;
            case CUSTOM_UI_KEYBINDS:
                if(FlxG.save.data.customUIKeys == null) {
                    FlxG.save.data.customUIKeys = new Array<Array<FlxKey>>();

                    FlxG.save.data.customUIKeys = [
                        [FlxKey.A, FlxKey.LEFT], //LEFT
                        [FlxKey.S, FlxKey.DOWN], //DOWN
                        [FlxKey.W, FlxKey.UP], //UP
                        [FlxKey.D, FlxKey.RIGHT], //RIGHT
                        [FlxKey.SPACE], //ACCEPT
                        [FlxKey.ENTER],  //ACCEPT
                        [FlxKey.BACKSPACE], //ESCAPE
                        [FlxKey.ESCAPE] //ESCAPE
                    ];
                }

                return FlxG.save.data.customUIKeys;
            case CAMERA_MOVEMENT_MOD:
                if(FlxG.save.data.camMove == null)
                    FlxG.save.data.camMove = false;

                return FlxG.save.data.camMove;
            case GHOST_TAPPING:
                if(FlxG.save.data.ghostTapping == null)
                    FlxG.save.data.ghostTapping = true;

                return FlxG.save.data.ghostTapping;
            case CUSTOM_MENU_BINDS:
                if(FlxG.save.data.menuBinds == null)
                    FlxG.save.data.menuBinds = ["PLUS", "MINUS"];

                return FlxG.save.data.menuBinds;
            case FPS_MULTIPLIER:
                if(FlxG.save.data.fpsMulti == null)
                    FlxG.save.data.fpsMulti = 2;

                return FlxG.save.data.fpsMulti;
            case GAMMA:
                if(FlxG.save.data.gamma == null)
                    FlxG.save.data.gamma = 1;

                return FlxG.save.data.gamma;
            case VOLUME:
                if(FlxG.save.data.volume == null)
                    FlxG.save.data.volume = 1;

                return FlxG.save.data.volume;
            case SHOW_FPS:
                if(FlxG.save.data.showFPS == null)
                    FlxG.save.data.showFPS = false;

                if(FlxG.save.data.showFPS) { //Just in case.
                    #if !mobile
                    openfl.Lib.current.addChild(SaveData.globalFPS);
                    #end
                }else {
                    #if !mobile
                    openfl.Lib.current.removeChild(SaveData.globalFPS);
                    #end
                }

                return FlxG.save.data.showFPS;
            case SHOW_MEMORY:
                if(FlxG.save.data.showMEM == null)
                    FlxG.save.data.showMEM = false;

                if(FlxG.save.data.showMEM) { //Just in case.
                    #if !mobile
                    openfl.Lib.current.addChild(SaveData.globalMEM);
                    #end
                }else {
                    #if !mobile
                    openfl.Lib.current.removeChild(SaveData.globalMEM);
                    #end
                }

                return FlxG.save.data.showMEM;
            default:
                return null;
        }
    }

    inline static function refreshData():Void {
        if(FlxG.save.data.showFPS) {
            #if !mobile
            openfl.Lib.current.addChild(SaveData.globalFPS);
            #end
        }else {
            #if !mobile
            openfl.Lib.current.removeChild(SaveData.globalFPS);
            #end
        }

        if(FlxG.save.data.showMEM) {
            #if !mobile
            openfl.Lib.current.addChild(SaveData.globalMEM);
            #end
        }else {
            #if !mobile
            openfl.Lib.current.removeChild(SaveData.globalMEM);
            #end
        }
    }

    inline static public function createNewBinds(data:SaveType):Void {
        switch(data) {
            case CUSTOM_UI_KEYBINDS:
                FlxG.save.data.customUIKeys = new Array<Array<FlxKey>>();

                FlxG.save.data.customUIKeys = [
                    [FlxKey.A, FlxKey.LEFT], //LEFT
                    [FlxKey.S, FlxKey.DOWN], //DOWN
                    [FlxKey.W, FlxKey.UP], //UP
                    [FlxKey.D, FlxKey.RIGHT], //RIGHT
                    [FlxKey.SPACE], //ACCEPT
                    [FlxKey.ENTER],  //ACCEPT
                    [FlxKey.BACKSPACE], //ESCAPE
                    [FlxKey.ESCAPE] //ESCAPE
                ];
            case CUSTOM_KEYBINDS:
                FlxG.save.data.customKeys = new Array<Array<FlxKey>>();

                FlxG.save.data.customKeys = [
                    [FlxKey.A, FlxKey.LEFT], //LEFT
                    [FlxKey.S, FlxKey.DOWN], //DOWN
                    [FlxKey.W, FlxKey.UP], //UP
                    [FlxKey.D, FlxKey.RIGHT], //RIGHT
                    [FlxKey.SPACE] //SPACE
                ];
            default:
                FlxG.save.data.customUIKeys = new Array<Array<FlxKey>>();

                FlxG.save.data.customUIKeys = [
                    [FlxKey.A, FlxKey.LEFT], //LEFT
                    [FlxKey.S, FlxKey.DOWN], //DOWN
                    [FlxKey.W, FlxKey.UP], //UP
                    [FlxKey.D, FlxKey.RIGHT], //RIGHT
                    [FlxKey.SPACE], //ACCEPT
                    [FlxKey.ENTER],  //ACCEPT
                    [FlxKey.BACKSPACE], //ESCAPE
                    [FlxKey.ESCAPE] //ESCAPE
                ];

                FlxG.save.data.customKeys = new Array<Array<FlxKey>>();

                FlxG.save.data.customKeys = [
                    [FlxKey.A, FlxKey.LEFT], //LEFT
                    [FlxKey.S, FlxKey.DOWN], //DOWN
                    [FlxKey.W, FlxKey.UP], //UP
                    [FlxKey.D, FlxKey.RIGHT], //RIGHT
                    [FlxKey.SPACE] //SPACE
                ];
        }

        throw "Sorry, could not read outdated version of keybind data.\nDon't worry, a fresh new version will be created for you. :)";
    }
}