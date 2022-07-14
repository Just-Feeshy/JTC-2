package template;

import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;

interface ICustomNote {
    function pressedByPlayer(note:Note, player:Character, opponent:Character, girlfriend:Character):Void; //What happens when this note is press by the player.
    function useCustomPrefix(note:Note):Bool; //Use your own animation prefixes for this note.
    function shouldBeIgnored():Bool; //Should the opponent ignore this note.
    function whenNoteIsHit(strumNote:Strum):Bool; //When this note is either hit by player or opponent.
    function createSplashSprite(splash:SplashSprite, strumNote:Strum, rating:String):Void; //Create a custom splash effect for this note when it is hit.
    function whenIsFirstRendered(note:Note, totalNotesInSection:Int):Void; //When the note is first rendered in game.
    function whenIsSpawned(note:Note):Void; //What happens when this note is spawned in the game.
    function trailUpdate(trail:FlxTypedGroup<FlxSprite>):Void; //Update trail attaced to this note. @param trail could be null.
    function noteUpdate(note:Note):Void; //Update this note in game.
    function makeLongNoteLong():Bool; //Make the long of this note long in size.
    function setNoteAlpha(note:Note, alpha:Float):Float; //Set custom alpha value for this note.
    function setNoteAngle(note:Note, angle:Float):Float; //Set custom angle value for this note.
    function setXPosition(note:Note, strums:Array<Strum>, x:Float):Float; //Set custom x value for this regular note.
    function setSustainXPosition(note:Note, strums:Array<Strum>, x:Float):Float; //Set custom x value for this long note.
    function setVisibility(note:Note, staticArrowVisible:Bool):Bool; //Set this note visible.
    function getTrailGroup():FlxTypedGroup<FlxSprite>; //Add a custom trail to this note.
    function hasOppositeScroll():Bool; //If this note goes on the scroll intended to be in.
    function cantHaveHold():Bool; //If this note should have holds or not.
    function getIndividualSpeed():Float; //How much faster this note is compared to a regular note.
    function playerShouldntHit():Bool; //If player shouldn't hit this note.
    function noDefaultSplash():Bool; //If this note shouldn't play the default note splash.
    function giveHealth():Float; //How much health is given to the player when this note is hit.
    function getWobblePower():Int; //How much wobble effect should this note have.
}

class CustomNoteTemplate implements ICustomNote {
    public function pressedByPlayer(note:Note, player:Character, opponent:Character, girlfriend:Character):Void {
        return;
    }

    public function useCustomPrefix(note:Note):Bool {
        return false;
    }

    public function shouldBeIgnored():Bool {
        return false;
    }

    public function whenNoteIsHit(strumNote:Strum):Bool {
        return true; //Should play the default glow animation for strum.
    }

    public function createSplashSprite(splash:SplashSprite, strumNote:Strum, rating:String):Void {
        return;
    }

    public function whenIsFirstRendered(note:Note, totalNotesInSection:Int):Void {
        return;
    }

    public function whenIsSpawned(note:Note):Void {
        return;
    }

    public function trailUpdate(trail:FlxTypedGroup<FlxSprite>):Void {
        return;
    }

    public function noteUpdate(note:Note):Void {
        return;
    }

    public function makeLongNoteLong():Bool {
        return true;
    }

    public function setNoteAlpha(note:Note, alpha:Float):Float {
        return alpha;
    }

    public function setNoteAngle(note:Note, angle:Float):Float {
        return angle;
    }

    public function setXPosition(note:Note, strums:Array<Strum>, x:Float) {
        return x;
    }

    public function setSustainXPosition(note:Note, strums:Array<Strum>, x:Float) {
        return x;
    }

    public function setVisibility(note:Note, staticArrowVisible:Bool) {
        return staticArrowVisible;
    }

    public function getTrailGroup():FlxTypedGroup<FlxSprite> {
        return null;
    }

    public function hasOppositeScroll():Bool {
        return false;
    }

    public function cantHaveHold():Bool {
        return false;
    }

    public function getIndividualSpeed():Float {
        return 0;
    }

    public function playerShouldntHit():Bool {
        return false;
    }

    public function noDefaultSplash():Bool {
        return false;
    }

    public function giveHealth():Float {
        return 0;
    }

    public function getWobblePower():Int {
        return 0;
    }
}