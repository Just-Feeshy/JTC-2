package feshixl.shaders;

import haxe.macro.Context;
import haxe.macro.Expr;
import haxe.macro.Type;
using haxe.macro.ExprTools;

class FeshShaderMacro {
    public static macro function retrieveMetadata(metaName:String, overwrite:Bool = true):Expr {
        var result:String = null;
        final localClass:ClassType = Context.getLocalClass().get();
        result = checkClassForMetadata(localClass, metaName, overwrite, result);

        var parent:ClassType = localClass.superClass != null ? localClass.superClass.t.get() : null;

        while (parent != null) {
            result = checkClassForMetadata(parent, metaName, overwrite, result);
            parent = parent.superClass != null ? parent.superClass.t.get() : null;
        }

        return macro $v{result};
    }

    #if macro
    @:noCompletion private static function checkClassForMetadata(classType:ClassType, metaName:String, overwrite:Bool, currentResult:String):String {
        var result:String = currentResult;

        for (field in [classType.constructor.get()].concat(classType.fields.get())) {
            for (meta in field.meta.get()) {
                if (meta.name == metaName || meta.name == ":" + metaName) {
                    final value:Dynamic = meta.params[0].getValue();

                    if (!(value is String)) {
                        continue;
                    }

                    if (overwrite) {
                        result = result == null ? value : value + "\n" + result;
                    } else if (result == null) {
                        result = value;
                        break;
                    }
                }
            }

            if (!overwrite && result != null) {
                break;
            }
        }

        return result;
    }
    #end
}
