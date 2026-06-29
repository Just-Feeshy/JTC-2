package stageeditor;

#if FEATURE_STAGE_EDITOR
import flixel.FlxSprite;
import flixel.util.FlxColor;

/**
 * JTC2-friendly port of Funkin's `StageEditorObject` (Funkin/source/funkin/ui/debug/stageeditor/StageEditorObject.hx).
 *
 * Funkin extends `FunkinSprite` (a 922-line subclass with a custom filter
 * pipeline + memory hooks); we extend plain `FlxSprite` since the editor never
 * runs the gameplay-frame filters. Selection feedback is a flat color tint
 * instead of Funkin's `InverseDotsShader`.
 *
 * The dance / playAnim / animDatas semantics match Funkin's so saved stages
 * round-trip cleanly even if they were authored against either editor.
 */
class StageEditorObject extends FlxSprite
{
    /** Internal display name. */
    public var name:String = "Unnamed";

    /** Anim to play once `isDebugged` becomes false (i.e. in test mode). */
    public var startingAnimation:String = "";

    /** Beats between dance triggers (0 = no auto-dance). */
    public var danceEvery:Float = 0;

    /** Z-index used by the editor to reorder; not the same as FlxSprite.zIndex. */
    public var zIndex:Int = 0;

    /**
     * name → {prefix, offsets:[x,y], looped, frameRate, flipX, flipY, indices}
     * Stored as plain anonymous objects for easy JSON serialization.
     */
    public var animDatas:Map<String, Dynamic> = [];

    /**
     * Whether the object is currently being edited. When true, the live
     * animation is stopped (so the object stays put). When false (test mode),
     * `startingAnimation` plays.
     */
    public var isDebugged(default, set):Bool = true;

    /** Original color before selection — restored when selection moves away. */
    private var _baseColor:FlxColor = FlxColor.WHITE;

    /** Used by `dance()` to alternate between danceLeft / danceRight. */
    private var _danced:Bool = true;

    public function new()
    {
        super();
    }

    function set_isDebugged(value:Bool):Bool
    {
        this.isDebugged = value;

        if (!value)
        {
            playAnim(startingAnimation, true);
        }
        else if (animation.curAnim != null)
        {
            animation.stop();
            offset.set();
            updateHitbox();
        }

        return value;
    }

    /**
     * Visual selection cue. JTC2 doesn't have Funkin's `InverseDotsShader`, so
     * we tint the sprite. Calling code restores the original via `setSelected(false)`.
     */
    public function setSelected(selected:Bool):Void
    {
        if (selected)
        {
            if (color != 0xFF66CCFF) _baseColor = color;
            color = 0xFF66CCFF;
        }
        else
        {
            color = _baseColor;
        }
    }

    public function playAnim(name:String, restart:Bool = false, reversed:Bool = false):Void
    {
        if (name == null || name == "") return;
        if (!animation.getNameList().contains(name)) return;

        animation.play(name, restart, reversed, 0);

        if (animDatas.exists(name))
        {
            var entry:Dynamic = animDatas.get(name);
            var off:Array<Dynamic> = entry == null ? null : entry.offsets;
            if (off != null && off.length >= 2)
            {
                offset.set(readFloat(off, 0), readFloat(off, 1));
                return;
            }
        }

        offset.set();
    }

    public function dance(restart:Bool = false):Void
    {
        if (isDebugged) return;

        var names = animation.getNameList();
        var hasIdle = names.contains("idle");
        var hasDance = names.contains("danceLeft") && names.contains("danceRight");

        if (!hasIdle && !hasDance) return;

        if (hasDance)
        {
            if (_danced) playAnim("danceRight", restart);
            else playAnim("danceLeft", restart);
            _danced = !_danced;
        }
        else
        {
            playAnim("idle", restart);
        }
    }

    public function addAnim(name:String, prefix:String, offsets:Array<Float>, indices:Array<Int>,
        frameRate:Int = 24, looped:Bool = true, flipX:Bool = false, flipY:Bool = false):Void
    {
        if (indices != null && indices.length > 0)
            animation.addByIndices(name, prefix, indices, "", frameRate, looped, flipX, flipY);
        else
            animation.addByPrefix(name, prefix, frameRate, looped, flipX, flipY);

        if (!animation.getNameList().contains(name)) return;

        animDatas.set(name, {
            name: name,
            prefix: prefix,
            offsets: offsets == null ? [0.0, 0.0] : offsets,
            looped: looped,
            frameRate: frameRate,
            flipX: flipX,
            flipY: flipY,
            frameIndices: indices == null ? [] : indices
        });
    }

    /**
     * Serialize the editor-visible properties of this object to a plain object
     * that can be JSON-encoded directly. Mirrors `StageEditorObjectData` in
     * `handlers/StageEditorData.hx`.
     */
    public function toData():Dynamic
    {
        return {
            name: this.name,
            x: this.x,
            y: this.y,
            z: this.zIndex,
            scale: [this.scale.x, this.scale.y],
            scrollFactor: [this.scrollFactor.x, this.scrollFactor.y],
            graphic: Reflect.field(this, "_graphicKey"),
            startingAnimation: this.startingAnimation,
            danceEvery: this.danceEvery
        };
    }

    /**
     * Inverse of `toData`. Returns `this` for chaining.
     */
    public function fromData(data:Dynamic):StageEditorObject
    {
        if (data == null) return this;

        this.name = readString(data, "name", this.name);
        this.x = readFloatField(data, "x", this.x);
        this.y = readFloatField(data, "y", this.y);
        this.zIndex = Std.int(readFloatField(data, "z", this.zIndex));
        this.startingAnimation = readString(data, "startingAnimation", this.startingAnimation);
        this.danceEvery = readFloatField(data, "danceEvery", this.danceEvery);

        var sc:Array<Dynamic> = readArray(data, "scale");
        if (sc.length >= 2) this.scale.set(readFloat(sc, 0), readFloat(sc, 1));

        var sf:Array<Dynamic> = readArray(data, "scrollFactor");
        if (sf.length >= 2) this.scrollFactor.set(readFloat(sf, 0), readFloat(sf, 1));

        return this;
    }

    // ────────────────────────────────────────────────────────────────────────
    // small read helpers (avoid pulling in a util class for these)
    // ────────────────────────────────────────────────────────────────────────

    static inline function readFloat(arr:Array<Dynamic>, i:Int):Float
    {
        if (arr == null || i < 0 || i >= arr.length) return 0;
        var v:Dynamic = arr[i];
        if (v == null) return 0;
        if (Std.isOfType(v, Float) || Std.isOfType(v, Int)) return cast v;
        var f:Float = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? 0 : f;
    }

    static inline function readFloatField(o:Dynamic, key:String, fallback:Float):Float
    {
        if (o == null || !Reflect.hasField(o, key)) return fallback;
        var v:Dynamic = Reflect.field(o, key);
        if (v == null) return fallback;
        if (Std.isOfType(v, Float) || Std.isOfType(v, Int)) return cast v;
        var f:Float = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? fallback : f;
    }

    static inline function readString(o:Dynamic, key:String, fallback:String):String
    {
        if (o == null || !Reflect.hasField(o, key)) return fallback;
        var v:Dynamic = Reflect.field(o, key);
        return v == null ? fallback : Std.string(v);
    }

    static inline function readArray(o:Dynamic, key:String):Array<Dynamic>
    {
        if (o == null || !Reflect.hasField(o, key)) return [];
        var v:Dynamic = Reflect.field(o, key);
        return Std.isOfType(v, Array) ? cast v : [];
    }
}
#end
