package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.system.FlxSound;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

class CheeseSliceSprite extends FlxSprite {
    private static inline var OPPOSITE_SIDE_WEIGHT:Float = 0.4;

    private var targetCenterX:Float = 0;
    private var targetCenterY:Float = 0;
    private var targetScale:Float = 1;

    private var angleTween:FlxTween;
    private var scaleTween:FlxTween;
    private var hitSound:FlxSound;

    public function new(sourceWasPlayerSide:Bool = false) {
        super();

        loadGraphic(Paths.image("cheese slice"));

        targetScale = 1 / FlxG.random.int(2, 3);
        angle = FlxG.random.int(0, 360);

        targetCenterX = sampleBiasedCenterX(sourceWasPlayerSide);
        targetCenterY = FlxG.random.float(0, FlxG.height);

        scale.set(targetScale * 0.08, targetScale * 0.08);
        refreshBounds();

        angleTween = FlxTween.tween(this, {angle: angle + 270}, 0.45, {
            ease: FlxEase.cubeOut
        });

        scaleTween = FlxTween.tween(scale, {x: targetScale, y: targetScale}, 0.45, {
            ease: FlxEase.backOut,
            onUpdate: function(_:FlxTween) {
                refreshBounds();
            }
        });

        hitSound = new FlxSound().loadEmbedded(Paths.sound("splat"));
        FlxG.sound.list.add(hitSound);
        hitSound.play();
    }

    private function sampleBiasedCenterX(sourceWasPlayerSide:Bool):Float {
        if (FlxG.random.float() >= OPPOSITE_SIDE_WEIGHT) {
            return FlxG.random.float(0, FlxG.width);
        }

        var sideMidpoint = FlxG.width * 0.5;
        var sideStart = sourceWasPlayerSide ? 0.0 : sideMidpoint;
        var sideEnd = sourceWasPlayerSide ? sideMidpoint : FlxG.width;
        var sideT = (FlxG.random.float() + FlxG.random.float()) * 0.5;

        return sideStart + ((sideEnd - sideStart) * sideT);
    }

    private function refreshBounds():Void {
        updateHitbox();
        centerOffsets();
        centerOrigin();
        setPosition(targetCenterX - (width * 0.5), targetCenterY - (height * 0.5));
    }

    override function update(elapsed:Float):Void {
        super.update(elapsed);

        if (hitSound != null && !hitSound.playing)
        {
            FlxG.sound.list.remove(hitSound, true);
            hitSound = null;
        }
    }

    override function destroy():Void {
        if (angleTween != null) {
            angleTween.cancel();
            angleTween = null;
        }

        if (scaleTween != null) {
            scaleTween.cancel();
            scaleTween = null;
        }

        if (hitSound != null) {
            FlxG.sound.list.remove(hitSound, true);
            hitSound = null;
        }

        super.destroy();
    }
}
