package;

import flixel.FlxSprite;
import flixel.system.FlxAssets.FlxGraphicAsset;

typedef DelayedAnimation = {
    var animation:String;
    var timer:Float;
}

class DelaySprite extends FlxSprite {
    public var onFinishedAnimation:Void->Void;

    var readyPlayAnim:Array<DelayedAnimation>;

    public function new(?X:Float = 0, ?Y:Float = 0, ?SimpleGraphic:FlxGraphicAsset) {
        super(X, Y, SimpleGraphic);

        readyPlayAnim = [];
    }

    public function playAnim(Anim:String, Timer:Float) {
        readyPlayAnim.push({animation: Anim, timer: Timer});
    }

    override public function update(elapsed:Float):Void {
        super.update(elapsed);

        var index:Int = 0;

        while(index < readyPlayAnim.length) {
            var delayedAnim:DelayedAnimation = readyPlayAnim[index++];

            if(delayedAnim.timer <= 0) {
                
            }else {
                delayedAnim.timer -= elapsed;
            }
        }
    }
}