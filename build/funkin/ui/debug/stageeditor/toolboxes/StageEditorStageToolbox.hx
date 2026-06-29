package stageeditor.toolboxes;

#if FEATURE_STAGE_EDITOR
import haxe.ui.components.DropDown;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextField;
import haxe.ui.events.UIEvent;

/**
 * Stage Properties toolbox — name, camera zoom, asset folder.
 * UI from `assets/exclude/data/ui/stage-editor/toolboxes/stage-settings.xml`.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/toolboxes/stage-settings.xml"))
class StageEditorStageToolbox extends StageEditorDefaultToolbox
{
    var stageNameText:TextField;
    var stageZoomStepper:NumberStepper;
    var stageLibraryDrop:DropDown;

    public function new(state:StageEditorState)
    {
        super(state);

        stageNameText.onChange = function(_)
        {
            stageEditorState.model.stageName = stageNameText.text;
            stageEditorState.markDirty();
        };

        stageZoomStepper.onChange = function(_)
        {
            stageEditorState.model.cameraZoom = stageZoomStepper.pos;
            stageEditorState.markDirty();
        };

        // Asset libraries — JTC2 keeps a flat assets/ tree rather than Funkin's
        // multi-library OpenFL setup. Populate from the well-known top-level
        // folders the project ships with.
        for (lib in ["preload", "shared", "tutorial", "week1", "week2", "week3", "week4", "week5", "week6", "songs"])
            stageLibraryDrop.dataSource.add({text: lib});

        stageLibraryDrop.onChange = function(_)
        {
            if (stageLibraryDrop.selectedItem == null) return;
            // Stored alongside displayName for now; later passes may key on this
            // to filter which assets show in the Object Graphic toolbox.
            Reflect.setField(stageEditorState.model, "assetFolder", stageLibraryDrop.selectedItem.text);
            stageEditorState.markDirty();
        };

        refresh();

        this.onDialogClosed = onClose;
    }

    function onClose(event:UIEvent):Void
    {
        dialogVisible = false;
    }

    override public function refresh():Void
    {
        if (stageEditorState == null || stageEditorState.model == null) return;

        stageNameText.text = stageEditorState.model.stageName;
        stageZoomStepper.pos = stageEditorState.model.cameraZoom;

        var folder:Dynamic = Reflect.field(stageEditorState.model, "assetFolder");
        if (folder != null) stageLibraryDrop.selectedItem = Std.string(folder);
    }
}
#end
