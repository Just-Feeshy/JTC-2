package stageeditor.components;

#if FEATURE_STAGE_EDITOR
import haxe.ui.containers.dialogs.Dialog;

/**
 * User Guide dialog — pure XML, no logic. Mirrors Funkin's `UserGuideDialog.hx`.
 */
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/dialogs/user-guide.xml"))
class UserGuideDialog extends Dialog
{
    public function new()
    {
        super();
        destroyOnClose = true;
    }
}
#end
