package stageeditor.components;

#if FEATURE_STAGE_EDITOR
import haxe.ui.containers.dialogs.Dialog;
import haxe.ui.containers.dialogs.Dialog.DialogButton;

@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/dialogs/exit-confirm.xml"))
class ExitConfirmDialog extends Dialog
{
    var onComplete:Void->Void = null;

    public function new(onComp:Void->Void)
    {
        super();

        onComplete = onComp;

        buttons = DialogButton.CANCEL | "{{Proceed}}";
        defaultButton = "{{Proceed}}";

        destroyOnClose = true;
    }

    public override function validateDialog(button:DialogButton, fn:Bool->Void):Void
    {
        if (button == "{{Proceed}}" && onComplete != null)
            onComplete();

        fn(true);
    }
}
#end
