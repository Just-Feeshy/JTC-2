package stageeditor.components;

#if FEATURE_STAGE_EDITOR
import haxe.ui.containers.dialogs.Dialog;

/**
 * About dialog — pure XML, no logic. Mirrors Funkin's `AboutDialog.hx`.
 */
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/dialogs/about.xml"))
class AboutDialog extends Dialog
{
    public function new()
    {
        super();
        destroyOnClose = true;
    }
}
#end
