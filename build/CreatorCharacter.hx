package;

import flixel.FlxG;

import ModInitialize;

class CreatorCharacter extends Character {
	public function new(x:Float, y:Float, ?character:String = "bf", ?isPlayer:Bool = false, ?hardInfo:ConfigCharacters, frameOffsetApply:Bool = true) {
		super(x, y, character, isPlayer, hardInfo, frameOffsetApply);
	}

	override public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
        /**
        * Just to be safe.
        * Basically, if it can't find the animation it's looking for to play, then it'll execute a random one.
        */
        @:privateAccess
        if(!animation._animations.exists(AnimName)) {
            var getRandom:Int = FlxG.random.int(0, Lambda.count(animation._animations) - 1);
            var index = 0;

            var tempAnimName:String = "";

            for(k in animation._animations.keys()) {
                if(index >= getRandom) {
                    tempAnimName = animation._animations.get(k).name;
                    break;
                }

                index++;
            }

		    super.playAnim(tempAnimName, Force, Reversed, Frame);

            AnimName = tempAnimName;
        }else {
            super.playAnim(AnimName, Force, Reversed, Frame);
        }
    }
}
