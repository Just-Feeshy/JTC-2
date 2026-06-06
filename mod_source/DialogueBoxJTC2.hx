package;

import flixel.FlxG;
import flixel.sound.FlxSound;
import template.DialogueBuilderV2;
import data.dialogue.DialogueSceneData;

using StringTools;

class DialogueBoxJTC2 extends DialogueBuilderV2 {
    public function new() {
        super();

        bindSoundToName("jtcText", Paths.sound("jtcText"));
        bindRawSoundToName("bfngfText", UselessShit.beep());
        bindSoundToName("picoText", Paths.sound("picoText"));
        bindSoundToName("quackText", Paths.sound("quackText"));
        bindSoundToName("teacherText", Paths.sound("teacherText"));

        implementShadowText();
    }

    override function resolveSound(s:DialogueSceneData):FlxSound {
        var key = soundKeyForScene(s);
        if (key != null && soundBindsByName.exists(key)) {
            return soundBindsByName.get(key);
        }
        return super.resolveSound(s);
    }

    override function triggerSceneShake(s:DialogueSceneData):Void {
        super.triggerSceneShake(s);
        if (s.shakeCamera && s.shakeAmplitude > 0) {
            FlxG.sound.play(Paths.sound("ANGRY_TEXT_BOX"));
        }
    }

    function soundKeyForScene(s:DialogueSceneData):String {
        var speaking = (s.text[0] == "left portrait") ? s.leftPortrait : s.rightPortrait;
        if (speaking == null || speaking.assetName == null) return null;

        var name = speaking.assetName;
        if (name.startsWith("JTC Sexy")) return "jtcText";
        if (name.startsWith("BF GF")) return "bfngfText";
        if (name.startsWith("Pico")) return "picoText";
        if (name.startsWith("Duck")) return "quackText";
        if (name.startsWith("Teacher")) return "teacherText";
        return null;
    }
}
