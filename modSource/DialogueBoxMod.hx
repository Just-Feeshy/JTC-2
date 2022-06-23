package;

import flixel.FlxG;
import template.DialogueBuilder;
import flixel.util.FlxColor;

class DialogueBoxMod extends DialogueBuilder {
    public function new() {
        super();

        implementSong(Paths.music("bluebastard"), 128);

        bindAssetToID(0, "dialogue/jtcDialogueBox");
        bindAssetToID(1, "dialogue/jtcPortraitShout");
        bindAssetToID(2, "dialogue/jtcPortraitSas");
        bindAssetToID(4, "dialogue/bfPortraitNormal");

        bindSoundToID(0, Paths.sound("jtcText"));
        bindRawSoundToID(1, UselessShit.beep());

        implementShadowText();

        if(FlxG.save.data.spanish) {
            _info[0].text[1] = "Tú!";
        }
    }

    override function refreshDisplay():Void {
        super.refreshDisplay();

        if(displayText.color == 16766208) {
            implementShadowTextColor(FlxColor.fromInt(15117568));
        }else if(displayText.color == 3200456) {
            implementShadowTextColor(FlxColor.fromInt(2338724));
        }
    }
}