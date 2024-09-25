package stage;

import stage.BaseDialog;
import haxe.ui.containers.dialogs.Dialog.DialogButton;
import haxe.ui.containers.dialogs.Dialog.DialogEvent;

@:build(haxe.ui.ComponentBuilder.build("assets/exclude/stage/components/newstage.xml"))
class NewDialog extends BaseDialog {
    public function new(__stageEditorState:StageDesignState, __params:DialogParams) {
        super(__stageEditorState, __params);

        this.splashCreateNew.onClick = _ -> onClickCreateNew();
    }

    public function onClickCreateNew():Void {
        this.hideDialog(DialogButton.CANCEL);
    }

    public function onClickImport():Void {
        // Browse for lua file
    }

    public static function build(state:StageDesignState, ?closable:Bool, ?modal:Bool):NewDialog {
        var dialog = new NewDialog(state, {
            closable: closable ?? false,
            modal: modal ?? true
        });

        dialog.showDialog(modal ?? true);
        return dialog;
    }
}
