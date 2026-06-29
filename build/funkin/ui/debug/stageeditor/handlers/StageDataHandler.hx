package stageeditor.handlers;

#if FEATURE_STAGE_EDITOR
import haxe.Json;

/**
 * JTC2-friendly stand-in for Funkin's `funkin.ui.debug.stageeditor.handlers.StageDataHandler`.
 *
 * Funkin's handler bundles object bitmaps + JSON into a `.fnfs` zip. JTC2 ships
 * stages as plain JSON, so this handler is a thin wrapper around the existing
 * `StageEditorData.toJson` / `fromJson` plus a few state-level convenience
 * methods (apply-to-state, snapshot-from-state).
 *
 * Usage: extension methods on `StageEditorState` via
 * `using stageeditor.handlers.StageDataHandler;`.
 */
@:access(stageeditor.StageEditorState)
class StageDataHandler
{
    /**
     * Serialize the editor's current state (model + placed objects) to JSON.
     */
    public static function snapshot(state:StageEditorState):String
    {
        if (state == null) return "";
        flushObjectsToModel(state);
        return StageEditorData.toJson(state.model);
    }

    /**
     * Parse `json` and apply it to the editor's state. Replaces any current
     * objects with the ones described in the JSON; characters are left to the
     * caller (pass 6 wires them).
     */
    public static function applyJson(state:StageEditorState, json:String):Void
    {
        if (state == null) return;
        var model = StageEditorData.fromJson(json);
        applyModel(state, model);
    }

    /**
     * Apply a parsed model directly. Used by `applyJson` and any UI that
     * already has a typed model in hand (e.g. an undo of "open file").
     */
    public static function applyModel(state:StageEditorState, model:StageEditorData.StageEditorDataModel):Void
    {
        if (state == null || model == null) return;

        state.model = model;

        // Replace placed objects.
        rebuildSpritesFromModel(state);

        // Reset selection and dirty bit.
        state.selectedSprite = null;
        state.saved = true;
    }

    /**
     * Reconcile `state.model.objects` against any in-scene `spriteArray` so
     * future saves persist the live edits.
     */
    public static function flushObjectsToModel(state:StageEditorState):Void
    {
        if (state == null || state.model == null) return;
        state.model.objects = [for (obj in state.spriteArray) toObjectData(obj)];
    }

    static function rebuildSpritesFromModel(state:StageEditorState):Void
    {
        // Tear down existing.
        for (obj in state.spriteArray.copy())
        {
            state.remove(obj, true);
            obj.kill();
            obj.destroy();
        }
        state.spriteArray = [];

        if (state.model.objects == null) return;

        for (data in state.model.objects)
        {
            var obj = new StageEditorObject();
            obj.fromData(data);
            // Placeholder pixels until pass 6 wires real graphics.
            obj.makeGraphic(64, 64, 0xFFFFFFFF);
            state.spriteArray.push(obj);
            state.add(obj);
        }
    }

    static function toObjectData(obj:StageEditorObject):StageEditorData.StageEditorObjectData
    {
        return {
            name: obj.name,
            x: obj.x,
            y: obj.y,
            z: obj.zIndex,
            scale: [obj.scale.x, obj.scale.y],
            scrollFactor: [obj.scrollFactor.x, obj.scrollFactor.y],
            graphic: null,
            startingAnimation: obj.startingAnimation,
            danceEvery: obj.danceEvery
        };
    }
}
#end
