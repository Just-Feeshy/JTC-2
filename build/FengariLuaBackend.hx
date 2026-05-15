package;

#if (USING_LUA && web)
import js.Browser;
import js.Lib;

using StringTools;

class FengariLuaBackend {
    static var loaded:Bool = false;
    static var fengari:Dynamic = null;
    static var lua:Dynamic = null;
    static var lauxlib:Dynamic = null;
    static var lualib:Dynamic = null;

    public var state(default, null):Dynamic;

    public function new() {}

    public function loadScript(scriptPath:String):String {
        ensureLoaded();

        state = lauxlib.luaL_newstate();
        lualib.luaL_openlibs(state);
        installPackageLoader();

        var source:String = Paths.readText(scriptPath);
        if(source == null || source.trim() == "") {
            return 'Unable to read Lua script: ' + scriptPath;
        }

        var loadStatus:Int = lauxlib.luaL_loadstring(state, fengari.to_luastring(source));
        if(loadStatus != lua.LUA_OK) {
            return popError();
        }

        var status:Int = lua.lua_pcall(state, 0, 0, 0);
        if(status != lua.LUA_OK) {
            return popError();
        }

        return null;
    }

    public function registerCallback(name:String, method:Dynamic):Void {
        if(state == null) {
            return;
        }

        lua.lua_pushjsfunction(state, function(L:Dynamic) {
            var argc:Int = lua.lua_gettop(L);
            var args:Array<Dynamic> = [];

            for(i in 0...argc) {
                args.push(readValue(L, i + 1));
            }

            var result:Dynamic = Reflect.callMethod(null, method, args);
            pushValue(L, result);
            return 1;
        });
        lua.lua_setglobal(state, fengari.to_luastring(name));
    }

    public function setGlobal(name:String, value:Dynamic):Void {
        if(state == null) {
            return;
        }

        pushValue(state, value);
        lua.lua_setglobal(state, fengari.to_luastring(name));
    }

    public function callGlobal(name:String, args:Array<Dynamic>):{ value:Dynamic, error:String } {
        if(state == null) {
            return { value: null, error: "Lua state is not initialized" };
        }

        lua.lua_getglobal(state, fengari.to_luastring(name));
        if(lua.lua_type(state, -1) != lua.LUA_TFUNCTION) {
            lua.lua_pop(state, 1);
            return { value: null, error: null };
        }

        for(arg in args) {
            pushValue(state, arg);
        }

        var status:Int = lua.lua_pcall(state, args.length, 1, 0);
        if(status != lua.LUA_OK) {
            return { value: LuaUtils.Function_Continue, error: popError() };
        }

        var value = readValue(state, -1);
        lua.lua_pop(state, 1);
        return { value: value, error: null };
    }

    public function close():Void {
        if(state != null) {
            lua.lua_close(state);
            state = null;
        }
    }

    static function ensureLoaded():Void {
        if(loaded) {
            return;
        }

        var source:String = Paths.readText("vendor/fengari/dist/fengari-web.bundle.js");
        if(source == null || source.trim() == "") {
            throw "Missing vendored Fengari runtime";
        }

        var bootstrap = "(function(){var module={exports:{}};var exports=module.exports;" + source + ";return module.exports || window.fengari || null;})()";
        fengari = Lib.eval(bootstrap);
        if(fengari == null) {
            fengari = Reflect.field(Browser.window, "fengari");
        }
        if(fengari == null) {
            throw "Fengari runtime failed to initialize";
        }

        lua = fengari.lua;
        lauxlib = fengari.lauxlib;
        lualib = fengari.lualib;
        loaded = true;
    }

    function installPackageLoader():Void {
        registerCallback("__hx_require_loader", function(moduleName:String) {
            return resolveModule(moduleName);
        });

        var packageSetup = [
            "local package = package",
            "local insert = table.insert",
            "insert(package.searchers, 1, function(name)",
            "  local resolved = __hx_require_loader(name)",
            "  if resolved == nil or resolved.source == nil then",
            "    return \"\\n\\tno repo loader for '\" .. name .. \"'\"",
            "  end",
            "  local chunk, err = load(resolved.source, \"@\" .. (resolved.path or name))",
            "  if chunk == nil then",
            "    return err",
            "  end",
            "  return chunk",
            "end)",
            "package.path = \"\"",
            "package.cpath = \"\""
        ].join("\n");

        var loadStatus:Int = lauxlib.luaL_loadstring(state, fengari.to_luastring(packageSetup));
        if(loadStatus != lua.LUA_OK) {
            throw popError();
        }

        var status:Int = lua.lua_pcall(state, 0, 0, 0);
        if(status != lua.LUA_OK) {
            throw popError();
        }
    }

    function resolveModule(moduleName:String):Dynamic {
        if(moduleName == null || moduleName.trim() == "") {
            return null;
        }

        var normalized = moduleName.replace(".", "/");
        var exact = moduleName;
        var candidates:Array<String> = [];

        for(base in [exact, normalized]) {
            if(base == null || base.trim() == "") {
                continue;
            }

            candidates.push(base + ".lua");
            candidates.push(base + "/init.lua");

            if(!base.startsWith("mod_assets/")) {
                candidates.push("mod_assets/scripts/" + base + ".lua");
                candidates.push("mod_assets/scripts/" + base + "/init.lua");
            }
        }

        for(path in candidates) {
            var source = Paths.readText(path);
            if(source != null && source.trim() != "") {
                return {
                    source: source,
                    path: path
                };
            }
        }

        return null;
    }

    function popError():String {
        var message:String = Std.string(lua.lua_tojsstring(state, -1));
        lua.lua_pop(state, 1);
        return message;
    }

    function pushValue(L:Dynamic, value:Dynamic, depth:Int = 0):Void {
        if(depth > 6) {
            lua.lua_pushnil(L);
            return;
        }

        if(value == null) {
            lua.lua_pushnil(L);
            return;
        }

        if(Std.isOfType(value, Bool)) {
            lua.lua_pushboolean(L, value);
            return;
        }

        if(Std.isOfType(value, Int)) {
            lua.lua_pushinteger(L, value);
            return;
        }

        if(Std.isOfType(value, Float)) {
            lua.lua_pushnumber(L, value);
            return;
        }

        if(Std.isOfType(value, String)) {
            lua.lua_pushstring(L, fengari.to_luastring(value));
            return;
        }

        if(Std.isOfType(value, Array)) {
            var arr:Array<Dynamic> = cast value;
            lua.lua_createtable(L, arr.length, 0);

            for(i in 0...arr.length) {
                pushValue(L, arr[i], depth + 1);
                lua.lua_rawseti(L, -2, i + 1);
            }
            return;
        }

        if(Reflect.isFunction(value)) {
            lua.lua_pushjsfunction(L, function(inner:Dynamic) {
                var argc:Int = lua.lua_gettop(inner);
                var args:Array<Dynamic> = [];

                for(i in 0...argc) {
                    args.push(readValue(inner, i + 1));
                }

                var result:Dynamic = Reflect.callMethod(null, value, args);
                pushValue(inner, result, depth + 1);
                return 1;
            });
            return;
        }

        var fields = Reflect.fields(value);
        if(fields != null && fields.length > 0) {
            lua.lua_createtable(L, 0, fields.length);

            for(field in fields) {
                pushValue(L, Reflect.field(value, field), depth + 1);
                lua.lua_setfield(L, -2, fengari.to_luastring(field));
            }
            return;
        }

        lua.lua_pushstring(L, fengari.to_luastring(Std.string(value)));
    }

    function readValue(L:Dynamic, index:Int, depth:Int = 0):Dynamic {
        if(depth > 6) {
            return null;
        }

        var valueType:Int = lua.lua_type(L, index);
        switch(valueType) {
            case 0:
                return null;
            case 1:
                return lua.lua_toboolean(L, index);
            case 3:
                return lua.lua_isinteger(L, index) ? lua.lua_tointeger(L, index) : lua.lua_tonumber(L, index);
            case 4:
                return Std.string(lua.lua_tojsstring(L, index));
            case 5:
                return readTable(L, index, depth + 1);
            default:
                return null;
        }
    }

    function readTable(L:Dynamic, index:Int, depth:Int):Dynamic {
        var absIndex:Int = index;
        if(index < 0) {
            absIndex = lua.lua_gettop(L) + index + 1;
        }

        var length:Int = lua.lua_rawlen(L, absIndex);
        if(length > 0) {
            var array:Array<Dynamic> = [];

            for(i in 1...length + 1) {
                lua.lua_rawgeti(L, absIndex, i);
                array.push(readValue(L, -1, depth + 1));
                lua.lua_pop(L, 1);
            }

            return array;
        }

        var object:Dynamic = {};
        lua.lua_pushnil(L);
        while(lua.lua_next(L, absIndex) != 0) {
            var key:String = Std.string(readValue(L, -2, depth + 1));
            Reflect.setField(object, key, readValue(L, -1, depth + 1));
            lua.lua_pop(L, 1);
        }

        return object;
    }
}
#end
