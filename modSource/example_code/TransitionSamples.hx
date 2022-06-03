package example_code;

import flixel.FlxG;
import flixel.util.FlxColor;
import flixel.util.FlxGradient;
import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

import template.TransitionBuilder;

class FadeTransition extends TransitionBuilder {
    var transBlack:FlxSprite;
    var transFade:FlxSprite;

    var tweenManager:Array<FlxTween>;

    public function new(duration:Float, fade:TransitionFade) {
        super(duration, fade);

        tweenManager = new Array<FlxTween>();

        transFade = FlxGradient.createGradientFlxSprite(FlxG.width, FlxG.height, (fade == IN ? [0x0, FlxColor.BLACK] : [FlxColor.BLACK, 0x0]));
        transFade.scrollFactor.set();
        add(transFade);

        transBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		transBlack.scrollFactor.set();
		add(transBlack);

        if(fade == IN) {
            transFade.y = transBlack.y - transBlack.height;
            transBlack.alpha = 0;

            tweenManager.push(FlxTween.tween(transBlack, {alpha: 1}, duration, {ease: FlxEase.quadOut}));
            tweenManager.push(FlxTween.tween(transFade, {y: transFade.height + 50}, duration, {onComplete: function(twn:FlxTween) {
                close();
            }, ease: FlxEase.linear}));
        }else {
            transFade.y = -transFade.height;
            transBlack.alpha = 1;

            tweenManager.push(FlxTween.tween(transBlack, {alpha: 0}, duration, {ease: FlxEase.quadIn}));
            tweenManager.push(FlxTween.tween(transFade, {y: transFade.height + 50}, duration, {onComplete: function(twn:FlxTween) {
                close();
            }, ease: FlxEase.linear}));
        }
    }

    function cleanTween() {
        if (tweenManager != null) {
            var index:Int = 0;
            var tween:FlxTween = null;

            while (index < tweenManager.length) {
                tween = tweenManager[index++];

                if (tween != null) {
                    tween.cancel();
                    tween.destroy();
                }

                tweenManager.remove(tween);
            }
        }
    }

    override function destroy() {
		if(tweenManager.length > 0) {
			cleanTween();
		}

		super.destroy();
	}
}