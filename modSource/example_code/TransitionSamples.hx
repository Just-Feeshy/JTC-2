package example_code;

import flixel.FlxG;
import flixel.util.FlxColor;
import flixel.util.FlxGradient;
import flixel.util.FlxDestroyUtil;
import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

import template.TransitionBuilder;

/**
* Extends off of VoidTransition because i'm lazy.
*/
class FadeTransition extends VoidTransition {
    var transBlack2:FlxSprite;
    var transFade:FlxSprite;

    public function new(duration:Float, fade:TransitionFade) {
        super(duration, fade);

        transFade = FlxGradient.createGradientFlxSprite(FlxG.width, FlxG.height, (fade == IN ? [0x0, FlxColor.BLACK] : [FlxColor.BLACK, 0x0]));
        transFade.scrollFactor.set();
        add(transFade);

        transBlack2 = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		transBlack2.scrollFactor.set();
		add(transBlack2);

        if(fade == IN) {
            transFade.y = transBlack.y - transBlack.height;
            tweenManager.push(FlxTween.tween(transFade, {y: transFade.height + 50}, duration, {onComplete: function(twn:FlxTween) {
                close();
            }, ease: FlxEase.linear}));
        }else {
            transFade.y = -transFade.height;
            tweenManager.push(FlxTween.tween(transFade, {y: transFade.height + 50}, duration, {onComplete: function(twn:FlxTween) {
                if(finishCallback != null) {
                    finishCallback();
                }
            }, ease: FlxEase.linear}));
        }
    }

    override function update(elapsed:Float) {
        if(fade == IN) {
			transBlack2.y = transFade.y + transFade.height;
		} else {
			transBlack2.y = transFade.y - transBlack2.height;
		}

        super.update(elapsed);

        if(fade == IN) {
			transBlack2.y = transFade.y + transFade.height;
		} else {
			transBlack2.y = transFade.y - transBlack2.height;
		}
    }

    override function destroy() {
		if(tweenManager.length > 0) {
			cleanTween();
		}

        transBlack2 = FlxDestroyUtil.destroy(transBlack2);
        transFade = FlxDestroyUtil.destroy(transFade);

		super.destroy();
	}
}

class VoidTransition extends TransitionBuilder {
    var transBlack:FlxSprite;

    var tweenManager:Array<FlxTween>;

    public function new(duration:Float, fade:TransitionFade) {
        super(duration, fade);

        tweenManager = new Array<FlxTween>();

        transBlack = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		transBlack.scrollFactor.set();
		add(transBlack);

        if(fade == IN) {
            transBlack.alpha = 1;
            tweenManager.push(FlxTween.tween(transBlack, {alpha: 0}, duration, {onComplete: function(twn:FlxTween) {
            }, ease: FlxEase.quadIn}));
        }else {
            transBlack.alpha = 0;
            tweenManager.push(FlxTween.tween(transBlack, {alpha: 1}, duration, {onComplete: function(twn:FlxTween) {
            }, ease: FlxEase.quadIn}));
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

        transBlack = FlxDestroyUtil.destroy(transBlack);

		super.destroy();
	}
}