package;

import flixel.FlxSprite;
import flixel.addons.text.FlxTypeText;

import SaveData.SaveType;

class DialogueText extends FlxTypeText {
    var attachedSprite:FlxSprite;
    var animationShould:String;

	public function new(X:Float, Y:Float, Width:Int, Text:String, Size:Int = 8, EmbeddedFont:Bool = true) {
        super(X, Y, Width, Text, Size, EmbeddedFont);

        antialiasing = SaveData.getData(SaveType.GRAPHICS);
    }

    override function update(elapsed:Float):Void {
        super.update(elapsed);

        if (_typing || _erasing) {
            if ((_typing && _timer >= delay) || (_erasing && _timer >= eraseDelay)) {
                if(attachedSprite != null) {
                    attachedSprite.animation.play(animationShould);
                }
            }
        }
    }

    public function shouldPlayAnim(anim:String):Void {
        animationShould = anim;
    }

    public function attachSprite(sprite:FlxSprite):Void {
        attachedSprite = sprite;
    }

    public function dettachSprite():Void {
        attachedSprite = null;
    }

    override function destroy():Void {
        attachedSprite = null;

        super.destroy();
    }
}