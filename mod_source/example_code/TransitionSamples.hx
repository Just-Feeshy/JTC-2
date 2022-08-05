package example_code;

import flixel.FlxG;
import flixel.util.FlxColor;
import flixel.util.FlxGradient;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxTimer;
import flixel.group.FlxSpriteGroup.FlxTypedSpriteGroup;
import flixel.graphics.FlxGraphic;
import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

import flixel.addons.transition.FlxTransitionSprite.GraphicTransTileCircle;

import template.TransitionBuilder;

import DelaySprite;

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
            }, ease: FlxEase.linear}));
        }else {
            transFade.y = -transFade.height;
            tweenManager.push(FlxTween.tween(transFade, {y: transFade.height + 50}, duration, {onComplete: function(twn:FlxTween) {
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
                close();
            }, ease: FlxEase.quadIn}));
        }else {
            transBlack.alpha = 0;
            tweenManager.push(FlxTween.tween(transBlack, {alpha: 1}, duration, {onComplete: function(twn:FlxTween) {
                callback();
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

class TileTransition extends TransitionBuilder {
    var _particles:FlxTypedSpriteGroup<DelaySprite>;

    public function new(duration:Float, fade:TransitionFade) {
        super(duration, fade);

        _particles = new FlxTypedSpriteGroup<DelaySprite>();

        var customDelaySprite:DelaySprite;

        var customSprite:DelaySprite = defaultSpriteBuild();

        final borderX:Int = 0;
        final borderY:Int = 0;

        final tileWidth:Int = Math.ceil(FlxG.width / customSprite.width);
        final tileHeight:Int = Math.ceil(FlxG.height / customSprite.height);

        final maxTiles:Int = tileWidth > tileHeight ? tileWidth : tileHeight;

        var totalDelay:Float = 0;

        var addX:Int = Std.int(customSprite.width);
		var addY:Int = Std.int(customSprite.height);

        var totalX:Int = 0;
        var totalY:Int = 0;

        var startX:Int = borderX;
        var startY:Int = borderY;

        if(FlxG.width - borderX <= 0) {
            addX *= -1;
            startX += addX;
        }

        if(FlxG.height - borderY <= 0) {
            addY *= -1;
            startY += addY;
        }

        totalX = startX;
        totalY = startY;

        for(i_y in 0...tileHeight) {
            for(i_x in 0...tileWidth) {
                var transitionSprite:DelaySprite = defaultSpriteBuild();

                if(fade == OUT) {
                    transitionSprite.animation.play("empty");
                }else {
                    transitionSprite.animation.play("full");
                }

                transitionSprite.setPosition(totalX, totalY);
                transitionSprite.color = FlxColor.BLACK;
                transitionSprite.scrollFactor.set();
                _particles.add(transitionSprite);

                totalX += addX;

                if(fade == OUT) {
                    transitionSprite.playAnim("in", totalDelay);
                }else {
                    transitionSprite.playAnim("out", totalDelay);
                }
                
                totalDelay += duration / (maxTiles * 50);
            }

            totalY += addY;
            totalX = startX;
        }

        _particles.members[_particles.length - 1].onFinishedAnimation = function(name:String) {
            if(fade == IN) {
                close();
            }else {
                callback();
            }
        }

        add(_particles);
    }

    function defaultSpriteBuild():DelaySprite {
        var temp:DelaySprite = new DelaySprite(0, 0);
        temp.loadGraphic(FlxGraphic.fromClass(GraphicTransTileCircle), true, 32, 32);

        var transInArray:Array<Int> = [];

        for(i in 0...temp.numFrames) {
            transInArray.push(i);
        }

        var transOutArray:Array<Int> = transInArray.copy();
        transOutArray.reverse();

        temp.animation.add("empty", [0], 0, false);
        temp.animation.add("in", transInArray, 40 / duration, false);
        temp.animation.add("out", transOutArray, 40 / duration, false);
        temp.animation.add("full", [temp.numFrames - 1], 0, false);

        return temp;
    }

    override function destroy() {
        _particles = FlxDestroyUtil.destroy(_particles);

        super.destroy();
    }
}