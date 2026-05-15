package stageeditor.toolboxes;

#if FEATURE_STAGE_EDITOR
import haxe.ui.components.Button;
import haxe.ui.components.NumberStepper;
import haxe.ui.events.UIEvent;

/**
 * Character Properties toolbox. The character system in JTC2 differs from
 * Funkin's (Lua-defined characters, no BaseCharacter / CharacterType / camera
 * focus offsets baked into the character JSON), so this pass renders the UI
 * disabled until pass 6 wires real characters.
 */
@:access(stageeditor.StageEditorState)
@:build(haxe.ui.macros.ComponentMacros.build("assets/exclude/data/ui/stage-editor/toolboxes/character-properties.xml"))
class StageEditorCharacterToolbox extends StageEditorDefaultToolbox
{
    var charPosX:NumberStepper;
    var charPosY:NumberStepper;
    var charZIdx:NumberStepper;
    var charScale:NumberStepper;
    var charCamX:NumberStepper;
    var charCamY:NumberStepper;
    var charAlpha:NumberStepper;
    var charAngle:NumberStepper;
    var charScrollX:NumberStepper;
    var charScrollY:NumberStepper;
    var charType:Button;

    public function new(state:StageEditorState)
    {
        super(state);
        refresh();
        this.onDialogClosed = function(_:UIEvent) dialogVisible = false;
    }

    override public function refresh():Void
    {
        // No character backend yet — disable all fields so users get visual
        // feedback that the panel is reserved for a future pass.
        for (f in [charPosX, charPosY, charZIdx, charScale, charCamX, charCamY,
                   charAlpha, charAngle, charScrollX, charScrollY])
            if (f != null) f.disabled = true;
        if (charType != null) charType.disabled = true;
    }
}
#end
