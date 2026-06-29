package stageeditor.components;

#if FEATURE_STAGE_EDITOR
import flixel.FlxG;
import haxe.ui.components.Link;
import haxe.ui.containers.Box;
import haxe.ui.containers.VBox;
import haxe.ui.containers.dialogs.Dialog;

/**
 * Welcome dialog shown on New Stage. Mirrors Funkin's three panels:
 * "Open Recent" (left), "Browse for Stage" (center), "Open from Presets" (right).
 *
 * JTC2 differences:
 * - Recent files come from `FlxG.save.data.stageEditorRecent` (set by pass 2's
 *   File menu), not Funkin's `Save.instance.stageEditorPreviousFiles`.
 * - No drag-and-drop yet — `boxDrag` is wired as a click-to-browse fallback.
 * - "Open from Presets" is empty until JTC2 grows a stage registry.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/dialogs/welcome.xml"))
class WelcomeDialog extends Dialog
{
    var contentRecent:VBox;
    var contentPresets:VBox;
    var boxDrag:Box;
    var buttonNew:haxe.ui.components.Button;

    var stageEditorState:StageEditorState;

    public function new(state:StageEditorState)
    {
        super();
        stageEditorState = state;

        top = (FlxG.height - height) * 0.5;
        left = (FlxG.width - width) * 0.5;

        if (buttonNew != null) buttonNew.onClick = function(_)
        {
            stageEditorState.doNewStageFromDialog();
            close();
        };

        if (boxDrag != null) boxDrag.onClick = function(_)
        {
            stageEditorState.onMenuItemClick("open stage");
            close();
        };

        populateRecent();
        // contentPresets intentionally empty until JTC2 has a stage registry.
    }

    function populateRecent():Void
    {
        if (contentRecent == null) return;

        var recent:Array<String> = stageEditorState.loadRecentFilesPublic();
        if (recent.length == 0)
        {
            var lbl:Link = new Link();
            lbl.percentWidth = 100;
            lbl.text = "(no recent stages)";
            lbl.disabled = true;
            contentRecent.addComponent(lbl);
            return;
        }

        for (file in recent)
        {
            var captured:String = file;
            var link:Link = new Link();
            link.percentWidth = 100;
            link.text = file;
            link.onClick = function(_)
            {
                stageEditorState.openRecentByPath(captured);
                close();
            };
            contentRecent.addComponent(link);
        }
    }

    inline function close():Void
    {
        hide();
        destroy();
    }
}
#end
