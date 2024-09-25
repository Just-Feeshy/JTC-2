package stage;

import haxe.ui.containers.dialogs.Dialog;
import haxe.ui.containers.dialogs.Dialog.DialogEvent;

// Based on Funkin's `ChartEditorBaseDialog.hx`

@:access(StageDesignState)
class BaseDialog extends Dialog {
    private var stageEditorState:StageDesignState;
    private var params:DialogParams;

    var locked:Bool = false;

    public function new(stageEditorState:StageDesignState, params:DialogParams) {
        super();

        this.stageEditorState = stageEditorState;
        this.params = params;
        this.closable = params.closable ?? false;
        this.destroyOnClose = true;

        this.onDialogClosed = event -> onClose(event);
    }

    public function onClose(event:DialogEvent):Void {
        stageEditorState.isHaxeUIDialogOpen = false;
    }

    public override function showDialog(modal:Bool = true):Void {
        super.showDialog(modal);
    }

    public function lock():Void {
        this.locked = true;
        this.closable = false;
    }

    public function unlock():Void {
        this.locked = false;
        this.closable = params.closable ?? false;
    }
}

typedef DialogParams = {
    ?closable:Bool,
    ?modal:Bool
};
