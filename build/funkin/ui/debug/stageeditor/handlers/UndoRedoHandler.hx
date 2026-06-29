package stageeditor.handlers;

#if FEATURE_STAGE_EDITOR

/**
 * Undo/redo stack for the Stage Editor. Mirrors the shape of Funkin's
 * `funkin.ui.debug.stageeditor.handlers.UndoRedoHandler` but trimmed to the
 * action types JTC2 supports in pass 5+ (no `CHARACTER_MOVED` until characters
 * are wired in pass 6).
 *
 * Usage: extension methods on `StageEditorState` via `using stageeditor.handlers.UndoRedoHandler`.
 */
@:access(stageeditor.StageEditorState)
class UndoRedoHandler
{
    public static function performLastAction(state:StageEditorState, redo:Bool = false):Void
    {
        if (state == null) return;
        var src = redo ? state.redoArray : state.undoArray;
        if (src.length == 0) return;

        var action = src.pop();
        if (action == null) return;

        switch (action.type)
        {
            case OBJECT_MOVED:
                var id:Int = readInt(action.data, "ID", -1);
                var pos:Array<Float> = readFloatArray(action.data, "pos");
                if (pos.length < 2) return;

                var obj = findById(state, id);
                if (obj == null) return;

                state.selectedSprite = obj;
                createAndPushAction(state, action.type, !redo);

                obj.x = pos[0];
                obj.y = pos[1];

            case OBJECT_ROTATED:
                var id:Int = readInt(action.data, "ID", -1);
                var angle:Float = readFloat(action.data, "angle", 0);

                var obj = findById(state, id);
                if (obj == null) return;

                state.selectedSprite = obj;
                createAndPushAction(state, action.type, !redo);
                obj.angle = angle;

            case OBJECT_CREATED:
                // Inverse: delete the object that was created.
                var id:Int = readInt(action.data, "ID", -1);
                var obj = findById(state, id);
                if (obj == null) return;

                state.selectedSprite = obj;
                createAndPushAction(state, OBJECT_DELETED, !redo);

                state.spriteArray.remove(obj);
                state.remove(obj, true);
                obj.kill();
                obj.destroy();
                state.selectedSprite = null;

            case OBJECT_DELETED:
                // Inverse: re-create the object from the saved data.
                var data:Dynamic = action.data == null ? null : Reflect.field(action.data, "data");
                if (data == null) return;

                var obj = new StageEditorObject().fromData(data);
                state.spriteArray.push(obj);
                state.add(obj);
                state.selectedSprite = obj;

                createAndPushAction(state, OBJECT_CREATED, !redo);

            default:
                // unhandled
        }

        state.markDirty();
    }

    public static function createAndPushAction(state:StageEditorState, action:UndoActionType, redo:Bool = false):Void
    {
        if (state == null) return;

        var record:UndoAction = {type: action, data: null};

        // Pushing a new normal action invalidates the redo stack.
        if (!redo && state.redoArray.length > 0) state.redoArray = [];

        switch (action)
        {
            case OBJECT_MOVED:
                if (state.selectedSprite == null) return;
                record.data = {ID: state.selectedSprite.ID, pos: [state.selectedSprite.x, state.selectedSprite.y]};

            case OBJECT_ROTATED:
                if (state.selectedSprite == null) return;
                record.data = {ID: state.selectedSprite.ID, angle: state.selectedSprite.angle};

            case OBJECT_CREATED:
                if (state.selectedSprite == null) return;
                record.data = {ID: state.selectedSprite.ID};

            case OBJECT_DELETED:
                if (state.selectedSprite == null) return;
                var obj = asObject(state.selectedSprite);
                record.data = {
                    ID: state.selectedSprite.ID,
                    data: obj == null ? null : obj.toData()
                };

            default:
                return;
        }

        if (record.data == null) return;

        if (redo) state.redoArray.push(record);
        else state.undoArray.push(record);
    }

    // ────────────────────────────────────────────────────────────────────────

    static function findById(state:StageEditorState, id:Int):StageEditorObject
    {
        if (id < 0) return null;
        for (obj in state.spriteArray) if (obj.ID == id) return obj;
        return null;
    }

    static inline function asObject(spr:Dynamic):StageEditorObject
    {
        return Std.isOfType(spr, StageEditorObject) ? cast spr : null;
    }

    static inline function readInt(o:Dynamic, key:String, fallback:Int):Int
    {
        if (o == null || !Reflect.hasField(o, key)) return fallback;
        var v:Dynamic = Reflect.field(o, key);
        if (v == null) return fallback;
        if (Std.isOfType(v, Int)) return cast v;
        if (Std.isOfType(v, Float)) return Std.int(cast v);
        var p:Null<Int> = Std.parseInt(Std.string(v));
        return p == null ? fallback : p;
    }

    static inline function readFloat(o:Dynamic, key:String, fallback:Float):Float
    {
        if (o == null || !Reflect.hasField(o, key)) return fallback;
        var v:Dynamic = Reflect.field(o, key);
        if (v == null) return fallback;
        if (Std.isOfType(v, Float) || Std.isOfType(v, Int)) return cast v;
        var f:Float = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? fallback : f;
    }

    static function readFloatArray(o:Dynamic, key:String):Array<Float>
    {
        if (o == null || !Reflect.hasField(o, key)) return [];
        var v:Dynamic = Reflect.field(o, key);
        if (!Std.isOfType(v, Array)) return [];
        var arr:Array<Dynamic> = cast v;
        return [for (item in arr)
        {
            if (item == null) 0.0;
            else if (Std.isOfType(item, Float) || Std.isOfType(item, Int)) cast item;
            else
            {
                var f = Std.parseFloat(Std.string(item));
                Math.isNaN(f) ? 0.0 : f;
            }
        }];
    }
}

typedef UndoAction =
{
    var type:UndoActionType;
    var data:Dynamic;
}

enum abstract UndoActionType(String) from String
{
    var OBJECT_DELETED = "object_deleted";
    var OBJECT_CREATED = "object_created";
    var OBJECT_MOVED = "object_moved";
    var OBJECT_ROTATED = "object_rotated";
}
#end
