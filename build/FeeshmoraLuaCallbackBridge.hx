package;

#if (USING_LUA && cpp)
import llua.Convert;
import llua.Lua;
import llua.LuaL;
import llua.State;
#end

using StringTools;

class FeeshmoraLuaCallbackBridge {
    public static inline function init(l:State):Void {
        #if (USING_LUA && cpp)
        Lua.set_callbacks_function(cpp.Callable.fromStaticFunction(callback_handler));
        #end
    }

    #if (USING_LUA && cpp)
    public static function callback_handler(l:State, fname:String):Int {
        var cbf = Lua_helper.callbacks.get(fname);

        if(cbf == null) {
            return 0;
        }

        var args:Array<Dynamic> = [];

        for(i in 0...Lua.gettop(l)) {
            args[i] = Convert.fromLua(l, i + 1);
        }

        try {
            var ret:Dynamic = Reflect.callMethod(null, cbf, args);

            if(ret != null) {
                Convert.toLua(l, ret);
            } else {
                Lua.pushnil(l);
            }

            return 1;
        } catch(e:haxe.Exception) {
            return raiseLuaCallbackError(l, fname, e.message, haxe.CallStack.toString(e.stack));
        } catch(e:Dynamic) {
            return raiseLuaCallbackError(l, fname, Std.string(e), haxe.CallStack.toString(haxe.CallStack.exceptionStack()));
        }
    }

    static function raiseLuaCallbackError(l:State, fname:String, message:String, stackTrace:String):Int {
        var output:String = formatLuaCallbackError(fname, message, stackTrace);

        LuaL.where(l, 1);
        Lua.pushstring(l, output);
        Lua.concat(l, 2);
        return Lua.error(l);
    }

    static function formatLuaCallbackError(fname:String, message:String, stackTrace:String):String {
        if(message == null || message.trim() == "") {
            message = "Unknown callback error";
        }

        var output:String = 'Lua callback "' + fname + '" failed: ' + message;

        if(stackTrace != null) {
            stackTrace = stackTrace.trim();

            if(stackTrace != "") {
                output += "\n" + stackTrace;
            }
        }

        return output;
    }
    #end
}
