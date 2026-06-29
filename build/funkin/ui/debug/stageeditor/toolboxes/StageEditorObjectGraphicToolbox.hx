package stageeditor.toolboxes;

#if FEATURE_STAGE_EDITOR
import haxe.ui.components.Button;
import haxe.ui.components.Image;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextArea;
import haxe.ui.events.UIEvent;
import stageeditor.handlers.AssetDataHandler;

/**
 * Object Graphic toolbox. Pickers for the selected object's underlying image
 * and frame data. JTC2 uses OpenFL assets directly (no Polymod), so "Load From
 * Internet" is hidden and "Load Image" defers to a Paths-resolved lookup.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/toolboxes/object-graphic.xml"))
class StageEditorObjectGraphicToolbox extends StageEditorDefaultToolbox
{
    var objImage:Image;
    var objLoad:Button;
    var objLoadNet:Button;
    var objReset:Button;
    var objResetFrames:Button;
    var objFrameTxt:TextArea;
    var objLoadFrames:Button;
    var objSetSparrow:Button;
    var objSetPacker:Button;
    var objImageWidth:NumberStepper;
    var objImageHeight:NumberStepper;
    var objSplit:Button;

    public function new(state:StageEditorState)
    {
        super(state);

        if (objLoadNet != null) objLoadNet.hidden = true;

        if (objReset != null) objReset.onClick = function(_) onReset();
        if (objResetFrames != null) objResetFrames.onClick = function(_) onResetFrames();
        // The remaining buttons are stubs until file-dialog integration lands.

        refresh();
        this.onDialogClosed = function(_:UIEvent) dialogVisible = false;
    }

    override public function refresh():Void
    {
        var obj = currentObject();
        var hasTarget = obj != null;

        for (b in [objLoad, objReset, objResetFrames, objLoadFrames, objSetSparrow, objSetPacker, objSplit])
            if (b != null) b.disabled = !hasTarget;
        for (f in [objImageWidth, objImageHeight])
            if (f != null) f.disabled = !hasTarget;
        if (objFrameTxt != null) objFrameTxt.disabled = !hasTarget;

        if (objImage != null && hasTarget)
        {
            // FlxSprite.graphic.imageFrame.parent.bitmap is the BitmapData backing the sprite.
            // Skip wiring until we have a real graphic path tracked on StageEditorObject.
        }
    }

    function onReset():Void
    {
        var obj = currentObject();
        if (obj == null) return;
        obj.makeGraphic(64, 64, 0xFFFFFFFF);
        stageEditorState.markDirty();
    }

    function onResetFrames():Void
    {
        var obj = currentObject();
        if (obj == null) return;
        obj.animation.destroyAnimations();
        obj.animDatas = [];
        stageEditorState.markDirty();
    }

    function currentObject():StageEditorObject
    {
        var spr = stageEditorState == null ? null : stageEditorState.selectedSprite;
        return Std.isOfType(spr, StageEditorObject) ? cast spr : null;
    }
}
#end
