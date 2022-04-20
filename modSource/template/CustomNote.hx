package template;

import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;

abstract class CustomNote {
    public var ID(default, set):Int; //Puts a specific number for this addon to get proper location.

    public function new() {}

    public function pressedByPlayer(note:Note, player:Character, opponent:Character, girlfriend:Character):Void { //What happens when this note is press by the player.
        return;
    }

    public function useCustomPrefix(note:Note):Bool { //Use your own animation prefixes for this note.
        return false;
    }

    public function shouldBeIgnored():Bool { //Should the opponent ignore this note.
        return false;
    }

    public function createSplashSprite(splash:SplashSprite, strumNote:Strum, rating:String):Void { //Create splash when this note is hit.
        return;
    }

    public function whenIsSpawned(note:Note):Void { //What happens when this note is spawned in the game. (This event function is looped)
        return;
    }

    public function whenTiggerSceneActived():Void { //When this note first appears in game.
        return;
    }

    public function trailUpdate(note:Note):Void { //Give these notes bonus sprites some coded animation.
        return;
    }

    public function noteUpdate(note:Note):Void { //Update this note in game.
        return;
    }

    public function allowRatingUssage():Bool { //
        return false;
    }

    public function setNoteAlpha(alpha:Float) { //Set custom alpha value for this note.
        return alpha;
    }

    public function setNoteAngle(angle:Float) { //Set custom angle value for this note.
        return angle;
    }

    public function setXPosition(x:Float) { //Set custom x value for this note.
        return x;
    }

    public function setVisibility(staticArrowVisible:Bool) { //Set this note visible.
        return staticArrowVisible;
    }

    public function getTrailGroup():FlxTypedGroup<FlxSprite> { //Add a custom trail to this note.
        return null;
    }

    public function hasOppositeScroll():Bool { //If this note goes on the scroll intended to be in.
        return false;
    }

    public function cantHaveHold():Bool { //If this note should have holds or not.
        return false;
    }

    public function getIndividualSpeed():Float { //How much faster this note is compared to a regular note.
        return 0;
    }

    public function playerShouldntHit():Bool { //If player shouldn't hit this note.
        return false;
    }

    public function noDefaultSplash():Bool { //If this note shouldn't play the default note splash.
        return false;
    }

    public function giveHealth():Float { //How much health is given to the player when this note is hit.
        return 0;
    }

    public function getWobblePower():Int { //How much wobble effect should this note have.
        return 0;
    }

    inline function set_ID(compileID:Int):Int {
        if(Compile.tempNoteAbstracts.length > 0 && Compile.preloadAddon)
            return compileID;

        return ID;
    }
}

class EventAddon {

    //This addon is still in development.

    public function new(){};

    public function update():Void { //
    
    }
}