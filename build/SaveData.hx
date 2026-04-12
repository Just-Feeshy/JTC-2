package;

import Controls.KeyboardScheme;
import flixel.FlxG;
import flixel.util.FlxSave;
import flixel.util.FlxDestroyUtil;
import flixel.input.keyboard.FlxKey;
import flixel.input.gamepad.FlxGamepadInputID;
import openfl.display.FPS;
#if lime
import lime.graphics.opengl.GL;
#end

using StringTools;

enum SaveType {
    NONE;
    DOWNSCROLL;
    PRESET_KEYBINDS;
    PERFECT_MODE_MOD;
    FLIP_CHART_MOD;
    CUSTOM_HELL_MOD;
    FAIR_BATTLE_MOD;
    FADE_BATTLE_MOD;
    NO_BLUE_BALLS_MOD;
    CAMERA_MOVEMENT_MOD;
    BOT_MODE_MOD;
    BLIND_MOD;
    X_WOBBLE_MOD;
    SHOW_BOTTOM_BAR;
    SHOW_NOTE_SPLASH;
    GRAPHICS;
    SET_FPS_DEFAULT;
    FPS_MULTIPLIER;
    CACHE_ASSETS;
    CUSTOM_KEYBINDS;
    CUSTOM_UI_KEYBINDS;
    CUSTOM_GAMEPAD_BINDS;
    GHOST_TAPPING;
    CUSTOM_MENU_BINDS;
    GAMMA;
    VOLUME;
    ERASE_DATA;
    SHOW_FPS;
    SHOW_MEMORY;
    NOTE_OFFSET;
    SKIP_CUTSCENES;
    PLAY_AS_OPPONENT;
    MISS_SOUND_VOLUME;
	GPU_CACHE;
}

class SaveData {
    public static inline var PROJECT_SAVE_NAME:String = "jtc-2";
    public static inline var PROJECT_SAVE_COMPANY:String = "ninjamuffin99";
    public static inline var MODERN_BASE_GAME_SAVE_NAME:String = "Funkin1";
    public static inline var MODERN_BASE_GAME_SAVE_COMPANY:String = "FunkinCrew";
    public static inline var BASE_GAME_SAVE_NAME:String = "funkin";
    public static inline var BASE_GAME_SAVE_COMPANY:String = "ninjamuffin99";

    @:allow(Preloader)
    @:allow(OptionsMenuState)
    static private var globalFPS:FPS;

    @:allow(Preloader)
    @:allow(OptionsMenuState)
    static private var globalMEM:Memory;

    /**
    * POSSIBLITIY: Make a `saveServer()` method.
    */

    inline static public function bindProjectSave():Void {
        FlxG.save.bind(PROJECT_SAVE_NAME, PROJECT_SAVE_COMPANY);
    }

    static public function shouldShowBaseGameSyncPrompt():Bool {
        if(FlxG.save == null || FlxG.save.data == null) {
            return false;
        }

        if(FlxG.save.data.baseGameSyncPromptEnabled == null) {
            FlxG.save.data.baseGameSyncPromptEnabled = true;
        }

        if(FlxG.save.data.baseGameSyncPromptEnabled != true) {
            return false;
        }

        if(FlxG.save.data.baseGameSyncPromptSeen == true) {
            return false;
        }

        return hasBaseGameOptionsToImport();
    }

    static public function isBaseGameSyncPromptEnabled():Bool {
        if(FlxG.save == null || FlxG.save.data == null) {
            return true;
        }

        if(FlxG.save.data.baseGameSyncPromptEnabled == null) {
            FlxG.save.data.baseGameSyncPromptEnabled = true;
        }

        return FlxG.save.data.baseGameSyncPromptEnabled;
    }

    static public function setBaseGameSyncPromptEnabled(enabled:Bool):Void {
        if(FlxG.save == null || FlxG.save.data == null) {
            return;
        }

        FlxG.save.data.baseGameSyncPromptEnabled = enabled;

        if(enabled) {
            FlxG.save.data.baseGameSyncPromptSeen = false;
        }

        FlxG.save.flush();
    }

    static public function resetBaseGameSyncPromptState():Void {
        if(FlxG.save == null || FlxG.save.data == null) {
            return;
        }

        FlxG.save.data.baseGameSyncPromptSeen = false;
        FlxG.save.data.baseGameSyncImported = false;
        FlxG.save.flush();
    }

    static public function markBaseGameSyncPromptSeen(imported:Bool = false):Void {
        if(FlxG.save == null || FlxG.save.data == null) {
            return;
        }

        FlxG.save.data.baseGameSyncPromptSeen = true;

        if(imported) {
            FlxG.save.data.baseGameSyncImported = true;
        }

        FlxG.save.flush();
    }

    static public function hasBaseGameOptionsToImport():Bool {
        return readAnyBaseGameOptionValues().keys().hasNext();
    }

    static public function importBaseGameOptions():Bool {
        var importedAnything:Bool = false;
        var syncData = readAnyBaseGameOptionValues();

        for(field in syncData.keys()) {
            Reflect.setField(FlxG.save.data, field, syncData.get(field));
            importedAnything = true;
        }

        if(!importedAnything) {
            markBaseGameSyncPromptSeen(false);
            return false;
        }

        FlxG.save.data.baseGameSyncPromptSeen = true;
        FlxG.save.data.baseGameSyncImported = true;

        saveClient();
        applyImportedControls();

        FlxG.sound.volume = FlxG.save.data.volume;
        Main.trueFramerate = FlxG.save.data.lowFps;
        Main.framerate = Main.trueFramerate;
        Register.updateFramerate(Main.trueFramerate * getData(SaveType.FPS_MULTIPLIER));
        FlxG.save.flush();

        return true;
    }

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
        FlxG.save.data.botMode = getData(SaveType.BOT_MODE_MOD);
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
        FlxG.save.data.gamepadBinds = getData(SaveType.CUSTOM_GAMEPAD_BINDS);
        FlxG.save.data.noteOffset = getData(SaveType.NOTE_OFFSET);
        FlxG.save.data.skipCutscenes = getData(SaveType.SKIP_CUTSCENES);
        FlxG.save.data.playAsOpponent = getData(SaveType.PLAY_AS_OPPONENT);
        FlxG.save.data.missVolume = getData(SaveType.MISS_SOUND_VOLUME);
		FlxG.save.data.gpuCache = getData(SaveType.GPU_CACHE);

        FlxG.save.flush();

        refreshData();
    }

    static public function ensureGPUCacheDefault():Void {
        if(FlxG.save == null || FlxG.save.data == null || FlxG.save.data.gpuCache != null) {
            return;
        }

        FlxG.save.data.gpuCache = shouldEnableGPUCacheByDefault();

        var rendererInfo = getRendererInfo();
        trace('GPU cache default set to ${FlxG.save.data.gpuCache}' + (rendererInfo != null ? ' [' + rendererInfo + ']' : ''));
    }

    static function shouldEnableGPUCacheByDefault():Bool {
        var rendererInfo = getRendererInfo();

        if(rendererInfo == null || rendererInfo.length == 0) {
            return true;
        }

        var normalized = rendererInfo.toLowerCase();
        var disabledKeywords = [
            "swiftshader",
            "llvmpipe",
            "softpipe",
            "software",
            "basic render",
            "gdi generic",
            "mesa offscreen",
            "rasterizer"
        ];

        for(keyword in disabledKeywords) {
            if(normalized.contains(keyword)) {
                return false;
            }
        }

        return true;
    }

    static function getRendererInfo():Null<String> {
        #if lime
        if(FlxG.stage == null || FlxG.stage.context3D == null) {
            return null;
        }

        try {
            var vendor = GL.getString(GL.VENDOR);
            var renderer = GL.getString(GL.RENDERER);
            var info = "";

            if(vendor != null && vendor.length > 0) {
                info = vendor;
            }

            if(renderer != null && renderer.length > 0) {
                if(info.length > 0) {
                    info += " / ";
                }

                info += renderer;
            }

            return info.length > 0 ? info : null;
        } catch(e) {
            return null;
        }
        #else
        return null;
        #end
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
            case CUSTOM_GAMEPAD_BINDS:
                if(FlxG.save.data.gamepadBinds == null) {
                    FlxG.save.data.gamepadBinds = new Array<Int>();

                    FlxG.save.data.gamepadBinds = [
                        FlxGamepadInputID.LEFT_TRIGGER, //LEFT
                        FlxGamepadInputID.LEFT_SHOULDER, //DOWN
                        FlxGamepadInputID.RIGHT_SHOULDER, //UP
                        FlxGamepadInputID.RIGHT_TRIGGER, //RIGHT
                        FlxGamepadInputID.X //SPACE
                    ];
                }

                return FlxG.save.data.gamepadBinds;
            case CAMERA_MOVEMENT_MOD:
                if(FlxG.save.data.camMove == null)
                    FlxG.save.data.camMove = false;

                return FlxG.save.data.camMove;
            case BOT_MODE_MOD:
                if(FlxG.save.data.botMode == null)
                    FlxG.save.data.botMode = false;

                return FlxG.save.data.botMode;
            case GHOST_TAPPING:
                if(FlxG.save.data.ghostTapping == null)
                    FlxG.save.data.ghostTapping = false;

                return FlxG.save.data.ghostTapping;
            case CUSTOM_MENU_BINDS:
                if(FlxG.save.data.menuBinds == null)
                    FlxG.save.data.menuBinds = ["PLUS", "MINUS"];

                return FlxG.save.data.menuBinds;
            case FPS_MULTIPLIER:
                // This multiplier is not user-facing anymore; keep gameplay on the
                // configured cap instead of doubling the whole app to 120 FPS by default.
                if(FlxG.save.data.fpsMulti == null || FlxG.save.data.fpsMulti != 1)
                    FlxG.save.data.fpsMulti = 1;

                return 1;
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
            case NOTE_OFFSET:
                if(FlxG.save.data.noteOffset == null) {
                    FlxG.save.data.noteOffset = 0;
                }

                return FlxG.save.data.noteOffset;
            case SKIP_CUTSCENES:
                if(FlxG.save.data.skipCutscenes == null) {
                    FlxG.save.data.skipCutscenes = false;
                }

                return FlxG.save.data.skipCutscenes;
            case PLAY_AS_OPPONENT:
                if(FlxG.save.data.playAsOpponent == null) {
                    FlxG.save.data.playAsOpponent = false;
                }

                return FlxG.save.data.playAsOpponent;
            case MISS_SOUND_VOLUME:
                if(FlxG.save.data.missVolume == null) {
                    FlxG.save.data.missVolume = 1;
                }

                return FlxG.save.data.missVolume;
		    case GPU_CACHE:
                ensureGPUCacheDefault();

				if(FlxG.save.data.gpuCache == null) {
					FlxG.save.data.gpuCache = true;
				}

				return FlxG.save.data.gpuCache;
            default:
                return null;
        }
    }

    static function readAnyBaseGameOptionValues():Map<String, Dynamic> {
        var modernData = readBoundSaveOptionValues(MODERN_BASE_GAME_SAVE_NAME, MODERN_BASE_GAME_SAVE_COMPANY, true);
        if(modernData.keys().hasNext()) {
            return modernData;
        }

        return readBoundSaveOptionValues(BASE_GAME_SAVE_NAME, BASE_GAME_SAVE_COMPANY, false);
    }

    static function readBoundSaveOptionValues(saveName:String, saveCompany:String, isModernFunkin:Bool):Map<String, Dynamic> {
        var baseSave = new FlxSave();
        var importedData:Map<String, Dynamic> = new Map<String, Dynamic>();

        try {
            if(baseSave.bind(saveName, saveCompany) && baseSave.data != null) {
                importedData = extractBaseGameOptionValues(baseSave.data, isModernFunkin);
            }
        } catch(e) {
            importedData = new Map<String, Dynamic>();
        }

        FlxDestroyUtil.destroy(baseSave);
        return importedData;
    }

    static function extractBaseGameOptionValues(baseData:Dynamic, isModernFunkin:Bool = false):Map<String, Dynamic> {
        var importedData:Map<String, Dynamic> = new Map<String, Dynamic>();
        var optionData:Dynamic = isModernFunkin && Reflect.hasField(baseData, "options") ? Reflect.field(baseData, "options") : baseData;

        inline function copyField(targetField:String, value:Dynamic):Void {
            if(value != null) {
                importedData.set(targetField, value);
            }
        }

        copyField("helpme", findImportedValue(optionData, ["downscroll", "downScroll", "helpme"], normalizeBool));
        copyField("noteOffset", resolveImportedNoteOffset(optionData, isModernFunkin));
        copyField("lowFps", findImportedValue(optionData, ["framerate", "lowFps", "fpsCap", "fps"], normalizeFramerate));
        copyField("skipCutscenes", findImportedValue(optionData, ["skipCutscenes"], normalizeBool));

        if(isModernFunkin) {
            var debugDisplay:Dynamic = findImportedValue(optionData, ["debugDisplay"]);
            if(debugDisplay != null) {
                var debugDisplayValue:String = Std.string(debugDisplay).toLowerCase();
                copyField("showFPS", debugDisplayValue != "off");
                copyField("showMEM", debugDisplayValue == "memory" || debugDisplayValue == "all");
            }

            importModernControlData(baseData, importedData);
        } else {
            copyField("ghostTapping", findImportedValue(optionData, ["ghostTapping", "ghostTap", "ghost"], normalizeBool));
            copyField("showFPS", findImportedValue(optionData, ["showFPS", "fpsCounter"], normalizeBool));
            copyField("showMEM", findImportedValue(optionData, ["showMEM", "memCounter", "memoryCounter"], normalizeBool));
            copyField("showEffect", findImportedValue(optionData, ["showEffect", "noteSplashes", "notesplashes"], normalizeBool));
            copyField("showstuff", findImportedValue(optionData, ["showstuff", "accuracyDisplay"], normalizeBool));
            copyField("botMode", findImportedValue(optionData, ["botMode", "botplay", "botPlay", "cpuControlled"], normalizeBool));
            copyField("missVolume", findImportedValue(optionData, ["missVolume"], normalizeVolume));
            copyField("dfjk", findImportedValue(optionData, ["dfjk"], normalizePresetBinds));
            copyField("customKeys", findImportedValue(optionData, ["customKeys"]));
            copyField("customUIKeys", findImportedValue(optionData, ["customUIKeys"]));
            copyField("gamepadBinds", findImportedValue(optionData, ["gamepadBinds"]));
            copyField("menuBinds", findImportedValue(optionData, ["menuBinds"]));
        }

        copyField("volume", findImportedValue(baseData, ["volume", "masterVolume"], normalizeVolume));

        var antialiasingValue:Dynamic = findImportedValue(optionData, ["showAntialiasing", "antialiasing"], normalizeBool);
        if(antialiasingValue == null) {
            antialiasingValue = findImportedValue(optionData, ["lowQuality"], invertImportedBool);
        }
        copyField("showAntialiasing", antialiasingValue);

        return importedData;
    }

    static function importModernControlData(baseData:Dynamic, importedData:Map<String, Dynamic>):Void {
        if(baseData == null || !Reflect.hasField(baseData, "options")) {
            return;
        }

        var optionsData:Dynamic = Reflect.field(baseData, "options");
        if(optionsData == null || !Reflect.hasField(optionsData, "controls")) {
            return;
        }

        var controlsData:Dynamic = Reflect.field(optionsData, "controls");
        if(controlsData == null || !Reflect.hasField(controlsData, "p1")) {
            return;
        }

        var playerOneControls:Dynamic = Reflect.field(controlsData, "p1");
        if(playerOneControls == null) {
            return;
        }

        var keyboardData:Dynamic = Reflect.hasField(playerOneControls, "keyboard") ? Reflect.field(playerOneControls, "keyboard") : null;
        if(keyboardData != null) {
            importModernKeyboardControls(keyboardData, importedData);
        }

        var gamepadData:Dynamic = Reflect.hasField(playerOneControls, "gamepad") ? Reflect.field(playerOneControls, "gamepad") : null;
        if(gamepadData != null) {
            importModernGamepadControls(gamepadData, importedData);
        }
    }

    static function importModernKeyboardControls(keyboardData:Dynamic, importedData:Map<String, Dynamic>):Void {
        var laneKeys = [
            normalizeImportedKeyArray(Reflect.field(keyboardData, "NOTE_LEFT")),
            normalizeImportedKeyArray(Reflect.field(keyboardData, "NOTE_DOWN")),
            normalizeImportedKeyArray(Reflect.field(keyboardData, "NOTE_UP")),
            normalizeImportedKeyArray(Reflect.field(keyboardData, "NOTE_RIGHT"))
        ];

        if(allImportedBindingsPresent(laneKeys)) {
            var matchedPreset:Null<Int> = detectImportedPresetKeybind(laneKeys);

            if(matchedPreset != null) {
                importedData.set("dfjk", matchedPreset);
            } else {
                var importedCustomKeys:Array<Array<FlxKey>> = cast getData(SaveType.CUSTOM_KEYBINDS);
                importedCustomKeys = cloneKeyMatrix(importedCustomKeys);
                for(i in 0...4) {
                    importedCustomKeys[i] = laneKeys[i].copy();
                }
                importedData.set("customKeys", importedCustomKeys);
                importedData.set("dfjk", 3);
            }
        }

        var uiLeft = normalizeImportedKeyArray(Reflect.field(keyboardData, "UI_LEFT"));
        var uiDown = normalizeImportedKeyArray(Reflect.field(keyboardData, "UI_DOWN"));
        var uiUp = normalizeImportedKeyArray(Reflect.field(keyboardData, "UI_UP"));
        var uiRight = normalizeImportedKeyArray(Reflect.field(keyboardData, "UI_RIGHT"));
        var acceptKeys = normalizeImportedKeyArray(Reflect.field(keyboardData, "ACCEPT"));
        var backKeys = normalizeImportedKeyArray(Reflect.field(keyboardData, "BACK"));
        var pauseKeys = normalizeImportedKeyArray(Reflect.field(keyboardData, "PAUSE"));
        var volumeUpKeys = normalizeImportedKeyArray(Reflect.field(keyboardData, "VOLUME_UP"));
        var volumeDownKeys = normalizeImportedKeyArray(Reflect.field(keyboardData, "VOLUME_DOWN"));

        var importedCustomUIKeys:Array<Array<FlxKey>> = cast getData(SaveType.CUSTOM_UI_KEYBINDS);
        importedCustomUIKeys = cloneKeyMatrix(importedCustomUIKeys);

        if(uiLeft != null) importedCustomUIKeys[0] = uiLeft.copy();
        if(uiDown != null) importedCustomUIKeys[1] = uiDown.copy();
        if(uiUp != null) importedCustomUIKeys[2] = uiUp.copy();
        if(uiRight != null) importedCustomUIKeys[3] = uiRight.copy();

        if(acceptKeys != null) {
            var selectedAcceptKeys = pickPreferredKeys(acceptKeys, [FlxKey.SPACE, FlxKey.ENTER], 2);
            importedCustomUIKeys[4] = [selectedAcceptKeys[0]];
            if(selectedAcceptKeys.length > 1) {
                importedCustomUIKeys[5] = [selectedAcceptKeys[1]];
            }
        }

        if(backKeys != null) {
            var selectedBackKeys = pickPreferredKeys(backKeys, [FlxKey.BACKSPACE, FlxKey.ESCAPE], 2);
            importedCustomUIKeys[6] = [selectedBackKeys[0]];
            if(selectedBackKeys.length > 1) {
                importedCustomUIKeys[7] = [selectedBackKeys[1]];
            } else if(pauseKeys != null && pauseKeys.length > 0) {
                importedCustomUIKeys[7] = [pauseKeys[0]];
            }
        }

        importedData.set("customUIKeys", importedCustomUIKeys);

        var importedMenuBinds:Array<String> = cast getData(SaveType.CUSTOM_MENU_BINDS);
        importedMenuBinds = importedMenuBinds.copy();

        if(volumeUpKeys != null && volumeUpKeys.length > 0) {
            importedMenuBinds[0] = keyToMenuBind(volumeUpKeys[0]);
        }

        if(volumeDownKeys != null && volumeDownKeys.length > 0) {
            importedMenuBinds[1] = keyToMenuBind(volumeDownKeys[0]);
        }

        importedData.set("menuBinds", importedMenuBinds);
    }

    static function importModernGamepadControls(gamepadData:Dynamic, importedData:Map<String, Dynamic>):Void {
        var left = normalizeImportedButton(Reflect.field(gamepadData, "NOTE_LEFT"));
        var down = normalizeImportedButton(Reflect.field(gamepadData, "NOTE_DOWN"));
        var up = normalizeImportedButton(Reflect.field(gamepadData, "NOTE_UP"));
        var right = normalizeImportedButton(Reflect.field(gamepadData, "NOTE_RIGHT"));

        if(left == null || down == null || up == null || right == null) {
            return;
        }

        var importedGamepadBinds:Array<Int> = cast getData(SaveType.CUSTOM_GAMEPAD_BINDS);
        importedGamepadBinds = importedGamepadBinds.copy();
        importedGamepadBinds[0] = left;
        importedGamepadBinds[1] = down;
        importedGamepadBinds[2] = up;
        importedGamepadBinds[3] = right;
        importedData.set("gamepadBinds", importedGamepadBinds);
    }

    static function resolveImportedNoteOffset(optionData:Dynamic, isModernFunkin:Bool):Dynamic {
        if(optionData == null) {
            return null;
        }

        if(isModernFunkin) {
            var globalOffset = findImportedValue(optionData, ["globalOffset"], normalizeInt);
            var audioVisualOffset = findImportedValue(optionData, ["audioVisualOffset"], normalizeInt);

            if(globalOffset != null || audioVisualOffset != null) {
                return (globalOffset != null ? globalOffset : 0) + (audioVisualOffset != null ? audioVisualOffset : 0);
            }
        }

        return findImportedValue(optionData, ["noteOffset", "offset", "inputOffset", "globalOffset", "audioVisualOffset"], normalizeInt);
    }

    static function findImportedValue(data:Dynamic, fieldNames:Array<String>, ?transform:Dynamic->Dynamic):Dynamic {
        if(data == null) {
            return null;
        }

        for(fieldName in fieldNames) {
            if(!Reflect.hasField(data, fieldName)) {
                continue;
            }

            var value:Dynamic = Reflect.field(data, fieldName);

            if(value == null) {
                continue;
            }

            return transform != null ? transform(value) : value;
        }

        return null;
    }

    static inline function invertImportedBool(value:Dynamic):Dynamic {
        return !normalizeBool(value);
    }

    static function normalizeBool(value:Dynamic):Bool {
        if(value == null) {
            return false;
        }

        var stringValue:String = Std.string(value).trim().toLowerCase();
        var parsedNumber:Float = Std.parseFloat(stringValue);

        if(!Math.isNaN(parsedNumber)) {
            return parsedNumber != 0;
        }

        return stringValue == "true" || stringValue == "yes" || stringValue == "on";
    }

    static function normalizeInt(value:Dynamic):Int {
        if(value == null) {
            return 0;
        }

        var parsedNumber:Float = Std.parseFloat(Std.string(value).trim());
        return Math.isNaN(parsedNumber) ? 0 : Std.int(parsedNumber);
    }

    static function normalizeFramerate(value:Dynamic):Int {
        var fps:Int = normalizeInt(value);

        if(fps <= 0) {
            return 60;
        }

        return Std.int(Math.max(30, Math.min(240, fps)));
    }

    static function normalizePresetBinds(value:Dynamic):Int {
        var preset:Int = normalizeInt(value);
        return Std.int(Math.max(0, Math.min(3, preset)));
    }

    static function normalizeVolume(value:Dynamic):Float {
        if(value == null) {
            return 1;
        }

        var volume:Float = Std.parseFloat(Std.string(value).trim());

        if(Math.isNaN(volume)) {
            return 1;
        }

        if(volume > 1) {
            volume /= 100;
        }

        return Math.max(0, Math.min(1, volume));
    }

    static function normalizeImportedKeyArray(value:Dynamic):Null<Array<FlxKey>> {
        if(value == null || !Std.isOfType(value, Array)) {
            return null;
        }

        var result:Array<FlxKey> = [];
        for(entry in cast(value, Array<Dynamic>)) {
            var keyCode:Int = normalizeInt(entry);
            if(keyCode == FlxKey.NONE) {
                continue;
            }

            var importedKey:FlxKey = cast keyCode;
            if(!result.contains(importedKey)) {
                result.push(importedKey);
            }
        }

        return result.length > 0 ? result : null;
    }

    static function normalizeImportedButton(value:Dynamic):Null<Int> {
        if(value == null || !Std.isOfType(value, Array)) {
            return null;
        }

        for(entry in cast(value, Array<Dynamic>)) {
            var button:Int = normalizeInt(entry);
            if(button >= 0) {
                return button;
            }
        }

        return null;
    }

    static function detectImportedPresetKeybind(laneKeys:Array<Array<FlxKey>>):Null<Int> {
        var presetLayouts:Array<Array<Array<FlxKey>>> = [
            [
                [FlxKey.A, FlxKey.LEFT],
                [FlxKey.S, FlxKey.DOWN],
                [FlxKey.W, FlxKey.UP],
                [FlxKey.D, FlxKey.RIGHT]
            ],
            [
                [FlxKey.D, FlxKey.LEFT],
                [FlxKey.F, FlxKey.DOWN],
                [FlxKey.J, FlxKey.UP],
                [FlxKey.K, FlxKey.RIGHT]
            ],
            [
                [FlxKey.Z, FlxKey.LEFT],
                [FlxKey.X, FlxKey.DOWN],
                [FlxKey.ONE, FlxKey.NUMPADONE, FlxKey.UP],
                [FlxKey.TWO, FlxKey.NUMPADTWO, FlxKey.RIGHT]
            ]
        ];

        for(presetIndex in 0...presetLayouts.length) {
            var matchesPreset = true;
            for(i in 0...presetLayouts[presetIndex].length) {
                if(!sameKeyList(presetLayouts[presetIndex][i], laneKeys[i])) {
                    matchesPreset = false;
                    break;
                }
            }

            if(matchesPreset) {
                return presetIndex;
            }
        }

        return null;
    }

    static function sameKeyList(expected:Array<FlxKey>, actual:Array<FlxKey>):Bool {
        if(expected == null || actual == null) {
            return false;
        }

        var normalizedExpected:Array<FlxKey> = [];
        var normalizedActual:Array<FlxKey> = [];

        for(key in expected) {
            if(!normalizedExpected.contains(key)) {
                normalizedExpected.push(key);
            }
        }

        for(key in actual) {
            if(!normalizedActual.contains(key)) {
                normalizedActual.push(key);
            }
        }

        if(normalizedExpected.length != normalizedActual.length) {
            return false;
        }

        for(key in normalizedExpected) {
            if(!normalizedActual.contains(key)) {
                return false;
            }
        }

        return true;
    }

    static function cloneKeyMatrix(source:Array<Array<FlxKey>>):Array<Array<FlxKey>> {
        var result:Array<Array<FlxKey>> = [];
        for(keys in source) {
            result.push(keys != null ? keys.copy() : []);
        }
        return result;
    }

    static function allImportedBindingsPresent(bindings:Array<Null<Array<FlxKey>>>):Bool {
        for(binding in bindings) {
            if(binding == null || binding.length == 0) {
                return false;
            }
        }

        return true;
    }

    static function keyToMenuBind(key:FlxKey):String {
        return Std.string(key).toUpperCase();
    }

    static function pickPreferredKeys(source:Array<FlxKey>, preferred:Array<FlxKey>, limit:Int):Array<FlxKey> {
        var result:Array<FlxKey> = [];

        for(key in preferred) {
            if(source.contains(key) && !result.contains(key)) {
                result.push(key);
            }
        }

        for(key in source) {
            if(!result.contains(key)) {
                result.push(key);
            }
        }

        if(result.length > limit) {
            result.resize(limit);
        }

        return result;
    }

    static function applyImportedControls():Void {
        if(PlayerSettings.player1 == null) {
            return;
        }

        switch(getData(SaveType.PRESET_KEYBINDS)) {
            case 0:
                PlayerSettings.player1.controls.setKeyboardScheme(KeyboardScheme.Duo(true), true);
            case 1:
                PlayerSettings.player1.controls.setKeyboardScheme(KeyboardScheme.Solo, true);
            case 2:
                PlayerSettings.player1.controls.setKeyboardScheme(KeyboardScheme.Duo(false), true);
            case 3:
                PlayerSettings.player1.controls.setKeyboardScheme(KeyboardScheme.Custom, true);
            default:
                PlayerSettings.player1.controls.setKeyboardScheme(KeyboardScheme.Duo(true), true);
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
