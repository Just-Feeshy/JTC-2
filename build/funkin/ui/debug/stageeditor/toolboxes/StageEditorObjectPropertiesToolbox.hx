package stageeditor.toolboxes;

#if FEATURE_STAGE_EDITOR
import flixel.FlxSprite;
import flixel.util.FlxColor;
import haxe.ui.components.CheckBox;
import haxe.ui.components.DropDown;
import haxe.ui.components.NumberStepper;
import haxe.ui.events.UIEvent;
import openfl.display.BlendMode;

/**
 * Object Properties toolbox — position/scale/angle/scroll/dance/AA/flip/blend/tint
 * for the selected stage object. UI from
 * `assets/exclude/data/ui/stage-editor/toolboxes/object-properties.xml`.
 *
 * The fields read/write whatever `stageEditorState.selectedSprite` is; if no
 * sprite is selected, fields are disabled.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/toolboxes/object-properties.xml"))
class StageEditorObjectPropertiesToolbox extends StageEditorDefaultToolbox
{
    var objPosX:NumberStepper;
    var objPosY:NumberStepper;
    var objZIdx:NumberStepper;
    var objAlpha:NumberStepper;
    var objAngle:NumberStepper;
    var objScaleX:NumberStepper;
    var objScaleY:NumberStepper;
    var objScrollX:NumberStepper;
    var objScrollY:NumberStepper;
    var objDance:NumberStepper;
    var objPixel:CheckBox;
    var objFlipX:CheckBox;
    var objFlipY:CheckBox;
    var objBlend:DropDown;
    var objTint:DropDown;

    var suppressWrite:Bool = false;

    public function new(state:StageEditorState)
    {
        super(state);

        wireField(objPosX, function(v:Float) writeIfTarget(function(s) s.x = v));
        wireField(objPosY, function(v:Float) writeIfTarget(function(s) s.y = v));
        wireField(objAlpha, function(v:Float) writeIfTarget(function(s) s.alpha = v));
        wireField(objAngle, function(v:Float) writeIfTarget(function(s) s.angle = v));
        wireField(objScaleX, function(v:Float) writeIfTarget(function(s) s.scale.x = v));
        wireField(objScaleY, function(v:Float) writeIfTarget(function(s) s.scale.y = v));
        wireField(objScrollX, function(v:Float) writeIfTarget(function(s) s.scrollFactor.x = v));
        wireField(objScrollY, function(v:Float) writeIfTarget(function(s) s.scrollFactor.y = v));
        wireField(objDance, function(v:Float) writeDance(v));
        wireField(objZIdx, function(v:Float) writeZIndex(Std.int(v)));

        if (objPixel != null) objPixel.onChange = function(_)
        {
            if (suppressWrite) return;
            writeIfTarget(function(s) s.antialiasing = objPixel.selected);
        };
        if (objFlipX != null) objFlipX.onChange = function(_)
        {
            if (suppressWrite) return;
            writeIfTarget(function(s) s.flipX = objFlipX.selected);
        };
        if (objFlipY != null) objFlipY.onChange = function(_)
        {
            if (suppressWrite) return;
            writeIfTarget(function(s) s.flipY = objFlipY.selected);
        };
        if (objBlend != null) objBlend.onChange = function(_)
        {
            if (suppressWrite) return;
            if (objBlend.selectedItem == null) return;
            writeIfTarget(function(s) s.blend = blendFromName(Std.string(objBlend.selectedItem.text)));
        };
        if (objTint != null) objTint.onChange = function(_)
        {
            if (suppressWrite) return;
            if (objTint.selectedItem == null) return;
            var raw:String = Std.string(objTint.selectedItem.text);
            writeIfTarget(function(s) s.color = parseColor(raw));
        };

        refresh();
        this.onDialogClosed = function(_:UIEvent) dialogVisible = false;
    }

    inline function wireField(field:NumberStepper, onChange:Float->Void):Void
    {
        if (field == null) return;
        field.onChange = function(_)
        {
            if (suppressWrite) return;
            onChange(field.pos);
        };
    }

    function writeIfTarget(apply:FlxSprite->Void):Void
    {
        var spr:FlxSprite = stageEditorState.selectedSprite;
        if (spr == null) return;
        apply(spr);
        stageEditorState.markDirty();
    }

    function writeZIndex(v:Int):Void
    {
        if (stageEditorState.selectedSprite == null) return;
        stageEditorState.setSelectedZIndex(v);
        stageEditorState.markDirty();
    }

    function writeDance(v:Float):Void
    {
        if (stageEditorState.selectedSprite == null) return;
        stageEditorState.setSelectedDanceEvery(v);
        stageEditorState.markDirty();
    }

    override public function refresh():Void
    {
        suppressWrite = true;

        var spr:FlxSprite = stageEditorState == null ? null : stageEditorState.selectedSprite;
        var hasTarget:Bool = spr != null;
        setAllDisabled(!hasTarget);

        if (!hasTarget)
        {
            suppressWrite = false;
            return;
        }

        objPosX.pos = spr.x;
        objPosY.pos = spr.y;
        objAlpha.pos = spr.alpha;
        objAngle.pos = spr.angle;
        objScaleX.pos = spr.scale.x;
        objScaleY.pos = spr.scale.y;
        objScrollX.pos = spr.scrollFactor.x;
        objScrollY.pos = spr.scrollFactor.y;
        objPixel.selected = spr.antialiasing;
        objFlipX.selected = spr.flipX;
        objFlipY.selected = spr.flipY;
        objZIdx.pos = stageEditorState.getSelectedZIndex();
        objDance.pos = stageEditorState.getSelectedDanceEvery();
        objBlend.selectedItem = blendName(spr.blend);

        suppressWrite = false;
    }

    function setAllDisabled(disabled:Bool):Void
    {
        for (field in [objPosX, objPosY, objZIdx, objAlpha, objAngle, objScaleX, objScaleY, objScrollX, objScrollY, objDance])
            if (field != null) field.disabled = disabled;
        for (chk in [objPixel, objFlipX, objFlipY])
            if (chk != null) chk.disabled = disabled;
        if (objBlend != null) objBlend.disabled = disabled;
        if (objTint != null) objTint.disabled = disabled;
    }

    // ────────────────────────────────────────────────────────────────────────
    // Helpers for BlendMode <-> string name and FlxColor parsing.
    // ────────────────────────────────────────────────────────────────────────

    static function blendFromName(name:String):BlendMode
    {
        return switch (name == null ? "" : name.toUpperCase())
        {
            case "ADD": BlendMode.ADD;
            case "DARKEN": BlendMode.DARKEN;
            case "DIFFERENCE": BlendMode.DIFFERENCE;
            case "HARDLIGHT": BlendMode.HARDLIGHT;
            case "INVERT": BlendMode.INVERT;
            case "LIGHTEN": BlendMode.LIGHTEN;
            case "MULTIPLY": BlendMode.MULTIPLY;
            case "OVERLAY": BlendMode.OVERLAY;
            case "SCREEN": BlendMode.SCREEN;
            case "SUBTRACT": BlendMode.SUBTRACT;
            #if !flash
            case "SHADER": BlendMode.SHADER;
            #end
            default: BlendMode.NORMAL;
        }
    }

    static function blendName(b:BlendMode):String
    {
        if (b == null) return "NONE";
        return switch (b)
        {
            case BlendMode.ADD: "ADD";
            case BlendMode.DARKEN: "DARKEN";
            case BlendMode.DIFFERENCE: "DIFFERENCE";
            case BlendMode.HARDLIGHT: "HARDLIGHT";
            case BlendMode.INVERT: "INVERT";
            case BlendMode.LIGHTEN: "LIGHTEN";
            case BlendMode.MULTIPLY: "MULTIPLY";
            case BlendMode.OVERLAY: "OVERLAY";
            case BlendMode.SCREEN: "SCREEN";
            case BlendMode.SUBTRACT: "SUBTRACT";
            default: "NONE";
        }
    }

    static function parseColor(hex:String):FlxColor
    {
        if (hex == null) return FlxColor.WHITE;
        var trimmed:String = hex;
        if (StringTools.startsWith(trimmed, "0x") || StringTools.startsWith(trimmed, "0X"))
            trimmed = trimmed.substr(2);
        if (StringTools.startsWith(trimmed, "#"))
            trimmed = trimmed.substr(1);
        if (trimmed.length == 6) trimmed = "FF" + trimmed;
        var parsed:Null<Int> = Std.parseInt("0x" + trimmed);
        return parsed == null ? FlxColor.WHITE : (parsed : FlxColor);
    }
}
#end
