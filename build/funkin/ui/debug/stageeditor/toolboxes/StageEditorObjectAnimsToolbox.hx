package stageeditor.toolboxes;

#if FEATURE_STAGE_EDITOR
import haxe.ui.components.Button;
import haxe.ui.components.CheckBox;
import haxe.ui.components.DropDown;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextField;
import haxe.ui.containers.ListView;
import haxe.ui.events.UIEvent;

/**
 * Object Animations toolbox. Lets the user list, define, save, and remove
 * animations on the selected `StageEditorObject`. Animation data is stored in
 * `obj.animDatas` (see StageEditorObject); refresh()/save()/remove() round-trip
 * between the UI fields and that map.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/toolboxes/object-anims.xml"))
class StageEditorObjectAnimsToolbox extends StageEditorDefaultToolbox
{
    var objAnims:DropDown;
    var objAnimName:TextField;
    var objFrameList:ListView;
    var objAnimPrefix:TextField;
    var objAnimIndices:TextField;
    var objAnimLooped:CheckBox;
    var objAnimFlipX:CheckBox;
    var objAnimFlipY:CheckBox;
    var objAnimStart:CheckBox;
    var objAnimFramerate:NumberStepper;
    var objAnimOffsetX:NumberStepper;
    var objAnimOffsetY:NumberStepper;
    var objAnimSave:Button;
    var objAnimDelete:Button;

    var suppressWrite:Bool = false;

    public function new(state:StageEditorState)
    {
        super(state);

        if (objAnims != null) objAnims.onChange = function(_) onPickAnim();
        if (objAnimSave != null) objAnimSave.onClick = function(_) onSave();
        if (objAnimDelete != null) objAnimDelete.onClick = function(_) onDelete();

        refresh();
        this.onDialogClosed = function(_:UIEvent) dialogVisible = false;
    }

    override public function refresh():Void
    {
        suppressWrite = true;

        var obj = currentObject();
        var hasTarget = obj != null;
        setAllDisabled(!hasTarget);

        if (objAnims != null && objAnims.dataSource != null)
        {
            objAnims.dataSource.clear();
            if (hasTarget)
            {
                for (animName in obj.animDatas.keys())
                    objAnims.dataSource.add({text: animName});
            }
        }

        clearFields();
        suppressWrite = false;
    }

    function onPickAnim():Void
    {
        if (objAnims == null || objAnims.selectedItem == null) return;
        var obj = currentObject();
        if (obj == null) return;

        var key:String = Std.string(objAnims.selectedItem.text);
        if (!obj.animDatas.exists(key)) return;
        var d:Dynamic = obj.animDatas.get(key);
        if (d == null) return;

        suppressWrite = true;
        if (objAnimName != null) objAnimName.text = key;
        if (objAnimPrefix != null) objAnimPrefix.text = readString(d, "prefix", "");
        if (objAnimIndices != null)
        {
            var idx:Array<Dynamic> = readArray(d, "frameIndices");
            objAnimIndices.text = idx.length == 0 ? "" : idx.join(",");
        }
        if (objAnimLooped != null) objAnimLooped.selected = readBool(d, "looped", true);
        if (objAnimFlipX != null) objAnimFlipX.selected = readBool(d, "flipX", false);
        if (objAnimFlipY != null) objAnimFlipY.selected = readBool(d, "flipY", false);
        if (objAnimFramerate != null) objAnimFramerate.pos = readFloat(d, "frameRate", 24);

        var offsets:Array<Dynamic> = readArray(d, "offsets");
        if (objAnimOffsetX != null) objAnimOffsetX.pos = offsets.length > 0 ? readFloatAt(offsets, 0) : 0;
        if (objAnimOffsetY != null) objAnimOffsetY.pos = offsets.length > 1 ? readFloatAt(offsets, 1) : 0;

        if (objAnimStart != null) objAnimStart.selected = obj.startingAnimation == key;

        suppressWrite = false;
    }

    function onSave():Void
    {
        var obj = currentObject();
        if (obj == null) return;
        if (objAnimName == null) return;

        var name = objAnimName.text;
        if (name == null || name == "") return;

        var prefix = objAnimPrefix == null ? "" : objAnimPrefix.text;
        var indices:Array<Int> = parseIndices(objAnimIndices == null ? "" : objAnimIndices.text);
        var offX = objAnimOffsetX == null ? 0 : objAnimOffsetX.pos;
        var offY = objAnimOffsetY == null ? 0 : objAnimOffsetY.pos;
        var fps = objAnimFramerate == null ? 24 : Std.int(objAnimFramerate.pos);
        var looped = objAnimLooped == null ? true : objAnimLooped.selected;
        var fx = objAnimFlipX == null ? false : objAnimFlipX.selected;
        var fy = objAnimFlipY == null ? false : objAnimFlipY.selected;

        obj.addAnim(name, prefix, [offX, offY], indices, fps, looped, fx, fy);

        if (objAnimStart != null && objAnimStart.selected)
            obj.startingAnimation = name;

        stageEditorState.markDirty();
        refresh();
    }

    function onDelete():Void
    {
        var obj = currentObject();
        if (obj == null) return;
        if (objAnimName == null || objAnimName.text == "") return;

        obj.animDatas.remove(objAnimName.text);
        if (obj.startingAnimation == objAnimName.text) obj.startingAnimation = "";

        stageEditorState.markDirty();
        refresh();
    }

    // ────────────────────────────────────────────────────────────────────────

    function currentObject():StageEditorObject
    {
        var spr = stageEditorState == null ? null : stageEditorState.selectedSprite;
        return Std.isOfType(spr, StageEditorObject) ? cast spr : null;
    }

    function setAllDisabled(disabled:Bool):Void
    {
        for (f in [objAnimPrefix, objAnimIndices, objAnimName])
            if (f != null) f.disabled = disabled;
        for (chk in [objAnimLooped, objAnimFlipX, objAnimFlipY, objAnimStart])
            if (chk != null) chk.disabled = disabled;
        for (ns in [objAnimFramerate, objAnimOffsetX, objAnimOffsetY])
            if (ns != null) ns.disabled = disabled;
        if (objAnimSave != null) objAnimSave.disabled = disabled;
        if (objAnimDelete != null) objAnimDelete.disabled = disabled;
    }

    function clearFields():Void
    {
        if (objAnimName != null) objAnimName.text = "";
        if (objAnimPrefix != null) objAnimPrefix.text = "";
        if (objAnimIndices != null) objAnimIndices.text = "";
        if (objAnimLooped != null) objAnimLooped.selected = true;
        if (objAnimFlipX != null) objAnimFlipX.selected = false;
        if (objAnimFlipY != null) objAnimFlipY.selected = false;
        if (objAnimStart != null) objAnimStart.selected = false;
        if (objAnimFramerate != null) objAnimFramerate.pos = 24;
        if (objAnimOffsetX != null) objAnimOffsetX.pos = 0;
        if (objAnimOffsetY != null) objAnimOffsetY.pos = 0;
    }

    static function parseIndices(raw:String):Array<Int>
    {
        if (raw == null) return [];
        var out:Array<Int> = [];
        for (chunk in raw.split(","))
        {
            var t = StringTools.trim(chunk);
            if (t == "") continue;
            var n = Std.parseInt(t);
            if (n != null) out.push(n);
        }
        return out;
    }

    static inline function readString(o:Dynamic, k:String, fb:String):String
    {
        if (o == null || !Reflect.hasField(o, k)) return fb;
        var v:Dynamic = Reflect.field(o, k);
        return v == null ? fb : Std.string(v);
    }

    static inline function readBool(o:Dynamic, k:String, fb:Bool):Bool
    {
        if (o == null || !Reflect.hasField(o, k)) return fb;
        var v:Dynamic = Reflect.field(o, k);
        if (v == null) return fb;
        if (Std.isOfType(v, Bool)) return cast v;
        return Std.string(v) == "true";
    }

    static inline function readFloat(o:Dynamic, k:String, fb:Float):Float
    {
        if (o == null || !Reflect.hasField(o, k)) return fb;
        var v:Dynamic = Reflect.field(o, k);
        if (v == null) return fb;
        if (Std.isOfType(v, Float) || Std.isOfType(v, Int)) return cast v;
        var f = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? fb : f;
    }

    static inline function readArray(o:Dynamic, k:String):Array<Dynamic>
    {
        if (o == null || !Reflect.hasField(o, k)) return [];
        var v:Dynamic = Reflect.field(o, k);
        return Std.isOfType(v, Array) ? cast v : [];
    }

    static inline function readFloatAt(arr:Array<Dynamic>, i:Int):Float
    {
        if (arr == null || i < 0 || i >= arr.length) return 0;
        var v:Dynamic = arr[i];
        if (v == null) return 0;
        if (Std.isOfType(v, Float) || Std.isOfType(v, Int)) return cast v;
        var f = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? 0 : f;
    }
}
#end
