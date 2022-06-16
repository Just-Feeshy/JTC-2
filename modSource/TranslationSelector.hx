package;

import flixel.FlxG;
import flixel.tweens.FlxTween;
import flixel.text.FlxText;
import flixel.util.FlxColor;

class TranslationSelector extends OptionsSubState {
    var choices:Alphabet;
    
    var languageOptions:FlxText;

    private var section:Int = 0;

	private var colorSway:Float = 0;

	private var changingKeys:Bool = false;

    public function new() {
        super();
    }

    override function finishTransition(twn:FlxTween) {
		choices = new Alphabet(0, 0, "spanish english", true, false);
		choices.screenCenter();
		add(choices);

		languageOptions = new FlxText(0, 0, FlxG.width, "Select Language", 32);
		languageOptions.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		languageOptions.borderSize = 2;
		languageOptions.screenCenter(X);
		languageOptions.y = languageOptions.getScreenCenter(Y) + (choices.height * 1.5);
		add(languageOptions);
	}

    override function update(elapsed:Float) {
		if(choices != null) {
			colorSway += elapsed;

			for(i in 0...choices.letters.length) {
				if(choices.letters[i].spaceLocation == section) {
					choices.letters[i].color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
					0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
				}else {
					choices.letters[i].color = FlxColor.fromRGBFloat(1, 1, 1);
				}
			}
		}

		if(changingKeys == false) {
			changingKeys = true;

			if(controls.LEFT_P) {
				colorSway = 0;
				section -= 1;
			}

			if(controls.RIGHT_P) {
				colorSway = 0;
				section += 1;
			}

			section %= 2;

			if(controls.ACCEPT) {
				if(section == 0) {
					FlxG.save.data.spanish = true;
					SaveData.saveClient();
				}else {
                    FlxG.save.data.spanish = false;
					SaveData.saveClient();
                }

				close();
			}

			changingKeys = false;
		}

		super.update(elapsed);
	}
}