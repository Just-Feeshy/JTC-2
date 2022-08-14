package;

import flixel.FlxG;
import template.DialogueBuilder;
import flixel.util.FlxColor;

class DialogueBoxJTC extends DialogueBuilder {
    /**
    * Determines whether both characters show on display.
    */
    var bothScene:Array<Int>;

    public function new() {
        switch(PlayState.SONG.song.toLowerCase()) {
            case "ping-pong":
                bothScene = [0, 1, 2, 3];
            default:
                bothScene = [];
        }

        super();

        implementSong(Paths.music("bluebastard"), 128);

        bindAssetToID(0, "dialogue/jtcDialogueBox");
        bindAssetToID(1, "dialogue/jtcPortraitShout");
        bindAssetToID(2, "dialogue/jtcPortraitSas");
        bindAssetToID(3, "dialogue/jtcPortraitDamn");
        bindAssetToID(4, "dialogue/bfPortraitNormal");
        bindAssetToID(5, "dialogue/bfPortraitCool"); 
        bindAssetToID(6, "dialogue/jtcPortraitTogether");
        bindAssetToID(7, "dialogue/jtcPortraitShrug");
        bindAssetToID(8, "dialogue/jtcPortraitPingPong");

        bindSoundToID(0, Paths.sound("jtcText"));
        bindRawSoundToID(1, UselessShit.beep());

        implementShadowText();
    }

    override function refreshDisplay():Void {
        super.refreshDisplay();

        speechBubble.flipX = !speechBubble.flipX;

        if(displayText.color == 16766208) {
            implementShadowTextColor(FlxColor.fromInt(0xcc7800));
            displayText.color = 15117568;
        }else if(displayText.color == 3200456) {
            implementShadowTextColor(FlxColor.fromInt(2338724));
        }

        if(bothScene.contains(dialogueScene - 1)) {
            leftPortrait.visible = true;
            rightPortrait.visible = true;
        }
    }
}