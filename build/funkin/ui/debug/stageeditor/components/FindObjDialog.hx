package stageeditor.components;

#if FEATURE_STAGE_EDITOR
import flixel.FlxG;
import haxe.ui.components.CheckBox;
import haxe.ui.components.Label;
import haxe.ui.components.TextField;
import haxe.ui.containers.dialogs.Dialog;
import haxe.ui.containers.dialogs.Dialog.DialogButton;

using StringTools;

/**
 * Find Object dialog — searches `state.spriteArray` by name with Caps / Whole-Word
 * modifiers. Find Next cycles through matches, selecting each in turn.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/dialogs/find-object.xml"))
class FindObjDialog extends Dialog
{
    var nameField:TextField;
    var capsCheck:CheckBox;
    var wordCheck:CheckBox;
    var indicator:Label;

    var stageEditorState:StageEditorState;
    var matches:Array<StageEditorObject> = [];
    var cursor:Int = 0;

    public function new(state:StageEditorState, searchFor:String = "")
    {
        super();
        stageEditorState = state;

        if (nameField != null)
        {
            nameField.text = searchFor;
            nameField.onChange = function(_) updateIndicator();
        }

        if (indicator != null) indicator.hide();

        top = 20;
        left = FlxG.width - width - 20;

        buttons = DialogButton.CANCEL | "{{Find Next}}";
        defaultButton = "{{Find Next}}";
    }

    function updateIndicator():Void
    {
        recomputeMatches();

        if (indicator == null) return;

        if (matches.length == 0)
        {
            indicator.text = "No Matches Found";
        }
        else
        {
            var sel = stageEditorState.selectedSprite;
            var idx = sel == null ? 0 : matches.indexOf(asObject(sel));
            if (idx < 0) idx = 0;
            indicator.text = "Selected: " + (idx + 1) + " / " + matches.length;
        }

        if (nameField != null && nameField.text != null && nameField.text != "") indicator.show();
        else indicator.hide();
    }

    function recomputeMatches():Void
    {
        matches = [];
        if (stageEditorState == null) return;
        if (nameField == null) return;

        var caps = capsCheck != null && capsCheck.selected;
        var whole = wordCheck != null && wordCheck.selected;
        var needle:String = nameField.text == null ? "" : nameField.text;
        if (!caps) needle = needle.toLowerCase();

        for (obj in stageEditorState.spriteArray)
        {
            if (!obj.visible) continue;
            var n:String = obj.name == null ? "" : obj.name;
            if (!caps) n = n.toLowerCase();

            var hit = whole ? (n == needle) : (n.indexOf(needle) >= 0);
            if (hit) matches.push(obj);
        }
    }

    public override function validateDialog(button:DialogButton, fn:Bool->Void):Void
    {
        if (button != "{{Find Next}}")
        {
            fn(true);
            return;
        }

        recomputeMatches();
        if (matches.length == 0)
        {
            fn(false);
            return;
        }

        cursor = matches.indexOf(asObject(stageEditorState.selectedSprite));
        cursor++;
        if (cursor >= matches.length) cursor = 0;

        stageEditorState.selectSprite(matches[cursor]);
        if (indicator != null)
            indicator.text = "Selected: " + (cursor + 1) + " / " + matches.length;

        fn(false); // keep dialog open
    }

    static inline function asObject(spr:Dynamic):StageEditorObject
    {
        return Std.isOfType(spr, StageEditorObject) ? cast spr : null;
    }
}
#end
