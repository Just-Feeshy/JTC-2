package stageeditor.handlers;

#if FEATURE_STAGE_EDITOR
import haxe.Json;

/**
 * In-memory model the editor mutates. Persisted as JSON via `StageEditorData.toJson` /
 * `StageEditorData.fromJson`, written via `FileReference.save` (download dialog on the
 * web, save-as dialog on desktop), same pattern ChartingState uses.
 *
 * Mirrors the shape of Funkin's stage data (`funkin.data.stage.StageData`) but lean:
 * just what the JTC2 port needs in early passes.
 */
typedef StageEditorObjectData =
{
    var name:String;
    var x:Float;
    var y:Float;
    var ?z:Int;
    var ?scale:Array<Float>;
    var ?scrollFactor:Array<Float>;
    var ?graphic:String;
    var ?startingAnimation:String;
    var ?danceEvery:Float;
}

typedef StageEditorCharacterData =
{
    var character:String;
    var x:Float;
    var y:Float;
    var ?camOffsetX:Float;
    var ?camOffsetY:Float;
}

typedef StageEditorDataModel =
{
    var version:String;
    var stageName:String;
    var displayName:String;
    var cameraZoom:Float;
    var objects:Array<StageEditorObjectData>;
    var characters:Array<StageEditorCharacterData>;
}

class StageEditorData
{
    public static inline final FILE_EXTENSION:String = "stage.json";
    public static inline final CURRENT_VERSION:String = "1.0.0";

    public static function makeEmpty(?name:String):StageEditorDataModel
    {
        return {
            version: CURRENT_VERSION,
            stageName: name == null ? "untitled" : name,
            displayName: name == null ? "Untitled Stage" : name,
            cameraZoom: 1.0,
            objects: [],
            characters: []
        };
    }

    public static function toJson(model:StageEditorDataModel):String
    {
        return Json.stringify(model, null, "  ");
    }

    public static function fromJson(raw:String):StageEditorDataModel
    {
        if (raw == null || raw.length == 0) return makeEmpty();

        try
        {
            var parsed:Dynamic = Json.parse(raw);
            if (parsed == null) return makeEmpty();

            // Tolerant of older/partial JSON — fill in defaults for missing fields.
            return {
                version: readString(parsed, "version", CURRENT_VERSION),
                stageName: readString(parsed, "stageName", "untitled"),
                displayName: readString(parsed, "displayName", readString(parsed, "stageName", "untitled")),
                cameraZoom: readFloat(parsed, "cameraZoom", 1.0),
                objects: cast readArray(parsed, "objects"),
                characters: cast readArray(parsed, "characters")
            };
        }
        catch (e:Dynamic)
        {
            trace("StageEditorData.fromJson failed: " + Std.string(e));
            return makeEmpty();
        }
    }

    static function readString(o:Dynamic, key:String, fallback:String):String
    {
        if (o == null || !Reflect.hasField(o, key)) return fallback;
        var v:Dynamic = Reflect.field(o, key);
        return v == null ? fallback : Std.string(v);
    }

    static function readFloat(o:Dynamic, key:String, fallback:Float):Float
    {
        if (o == null || !Reflect.hasField(o, key)) return fallback;
        var v:Dynamic = Reflect.field(o, key);
        if (v == null) return fallback;
        if (Std.isOfType(v, Float) || Std.isOfType(v, Int)) return cast v;
        var f:Float = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? fallback : f;
    }

    static function readArray(o:Dynamic, key:String):Array<Dynamic>
    {
        if (o == null || !Reflect.hasField(o, key)) return [];
        var v:Dynamic = Reflect.field(o, key);
        return Std.isOfType(v, Array) ? cast v : [];
    }
}
#end
