package stageeditor.components;

#if FEATURE_STAGE_EDITOR
import haxe.ui.components.TextField;
import haxe.ui.containers.dialogs.Dialog;
import haxe.ui.containers.dialogs.Dialog.DialogButton;
import haxe.ui.notifications.NotificationManager;
import haxe.ui.notifications.NotificationType;
import stageeditor.handlers.UndoRedoHandler;

using stageeditor.handlers.UndoRedoHandler;

/**
 * New Object dialog — name prompt; on Create, instantiates a `StageEditorObject`
 * via `state.spawnNamedObject(name)` and pushes an OBJECT_CREATED undo step.
 *
 * Funkin's version also lets you pre-seed the object with a `BitmapData`
 * (drag-and-drop or paste); JTC2's port falls back to the default 64x64 white
 * placeholder until the Object Graphic toolbox loads a real image.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/dialogs/new-object.xml"))
class NewObjDialog extends Dialog
{
    var field:TextField;
    var stageEditorState:StageEditorState;

    public function new(state:StageEditorState)
    {
        super();
        stageEditorState = state;

        if (field != null) field.onChange = function(_)
        {
            field.removeClasses(["invalid-value", "valid-value"]);
        };

        buttons = DialogButton.CANCEL | "{{Create}}";
        defaultButton = "{{Create}}";
        destroyOnClose = true;
    }

    public override function validateDialog(button:DialogButton, fn:Bool->Void):Void
    {
        if (button != "{{Create}}")
        {
            fn(true);
            return;
        }

        var nameText:String = (field == null || field.text == null) ? "" : field.text;
        var existing:Array<String> = [for (o in stageEditorState.spriteArray) o.name];

        if (nameText == "" || existing.contains(nameText))
        {
            field.swapClass("invalid-value", "valid-value");
            try
            {
                NotificationManager.instance.addNotification({
                    title: "Problem Creating an Object",
                    body: existing.contains(nameText) ? 'Object with the name "$nameText" already exists.' : "Invalid object name.",
                    type: NotificationType.Error
                });
            }
            catch (_:Dynamic) {}
            fn(false);
            return;
        }

        var spr = new StageEditorObject();
        spr.name = nameText;
        spr.makeGraphic(64, 64, 0xFFFFFFFF);
        spr.screenCenter();
        spr.zIndex = stageEditorState.spriteArray.length == 0 ? 0 : (stageEditorState.spriteArray[stageEditorState.spriteArray.length - 1].zIndex + 1);

        stageEditorState.spriteArray.push(spr);
        stageEditorState.add(spr);
        stageEditorState.selectSprite(spr);
        stageEditorState.createAndPushAction(OBJECT_CREATED, false);
        stageEditorState.markDirty();

        try
        {
            NotificationManager.instance.addNotification({
                title: "Object Created",
                body: 'Created object "$nameText".',
                type: NotificationType.Success
            });
        }
        catch (_:Dynamic) {}

        fn(true);
    }
}
#end
