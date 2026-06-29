package stageeditor.toolboxes;

#if FEATURE_STAGE_EDITOR
import haxe.ui.containers.dialogs.CollapsibleDialog;

/**
 * Base for all StageEditor toolboxes. Mirrors Funkin's
 * `funkin.ui.debug.stageeditor.toolboxes.StageEditorDefaultToolbox` but without
 * `FunkinSound.playOnce` (JTC2 plays UI sounds differently).
 */
class StageEditorDefaultToolbox extends CollapsibleDialog
{
    private var stageEditorState:StageEditorState;

    public var dialogVisible:Bool = false;

    // Param name intentionally differs from subclasses' `state` — haxeui's
    // ComponentMacros.build generates `_constructorParam_<name>` helpers and
    // duplicates between base and subclass cause a redefinition error.
    private function new(stageEditorState:StageEditorState)
    {
        super();
        this.stageEditorState = stageEditorState;

        closable = true;
        modal = false;
        destroyOnClose = false;
    }

    /**
     * Show/hide. Subclasses can override to also play SFX or wire to menu toggles.
     */
    public function toggle(on:Bool):Void
    {
        if (on) showDialog(false);
        else hide();

        dialogVisible = on;
    }

    /**
     * Pull current state from the editor's model into the UI fields. Override.
     */
    public function refresh():Void {}
}
#end
