package template;

import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.animation.FlxAnimationController;
import flixel.math.FlxRect;

interface ICustomNote {
    function pressedByPlayer(note:Note, player:Character, opponent:Character, girlfriend:Character):Void; //What happens when this note is press by the player.
    function useCustomPrefix(animation:FlxAnimationController):Bool; //Use your own animation prefixes for this note.
    function shouldBeIgnored():Bool; //Should the opponent ignore this note.
    function whenNoteIsHit(strumNote:Strum):Bool; //When this note is either hit by player or opponent.
    function createSpriteWhenHit():FlxSprite; //When this note is hit, then the sprite returned will be added in the game. (If null, nothing will be added.)
    function playSoundWhenNoteIsHit(mustPress:Bool, isSustain:Bool):String; //When this note is it would play a sound. (If sound file is left empty, nothing will play.)
    function getSplashTexture():String; //Get default splash texture for this note.
    function createSplashSprite(splash:SplashSprite, strumInfo:FlxRect, rating:String):Void; //Create a custom splash effect for this note when it is hit.
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
    function getNoteOffsetX(isSustain:Bool):Float; //Set the x offset of this note. (This method doesn't loop.)
    function getNoteOffsetY(isSustain:Bool):Float; //Set the y offset of this note. (This method doesn't loop.)
    function getTrailGroup():FlxTypedGroup<FlxSprite>; //Add a custom trail to this note.
    function hasOppositeScroll():Bool; //If this note goes on the scroll intended to be in.
    function cantHaveHold():Bool; //If this note should have holds or not.
    function addToNoteSpeed():Float; //How much faster this note is compared to a regular note.
    function playerShouldntHit():Bool; //If player shouldn't hit this note.
    function noDefaultSplash():Bool; //If this note shouldn't play the default note splash.
    function giveHealth(isSustain:Bool):Float; //How much health is given to the player when this note is hit.
    function missNoteDamage():Float; //How much damage is given to the player when this note is missed.
    function getWobblePower():Int; //How much wobble effect should this note have.
}

class CustomNoteTemplate implements ICustomNote {
    public function pressedByPlayer(note:Note, player:Character, opponent:Character, girlfriend:Character):Void {
        return;
    }

    public function useCustomPrefix(animation:FlxAnimationController):Bool {
        return false;
    }

    public function shouldBeIgnored():Bool {
        return false;
    }

    public function whenNoteIsHit(strumNote:Strum):Bool {
        return true; //Should play the default glow animation for strum.
    }

    public function createSpriteWhenHit():FlxSprite {
        return null;
    }

    public function playSoundWhenNoteIsHit(mustPress:Bool, isSustain:Bool):String {
        return "";
    }

    public function getSplashTexture():String {
        return "regular/splash";
    }

    public function createSplashSprite(splash:SplashSprite, strumInfo:FlxRect, rating:String):Void {
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

    public function setVisibility(note:Note, staticArrowVisible:Bool):Bool {
        return staticArrowVisible;
    }

    public function getNoteOffsetX(isSustain:Bool):Float {
        return 0;
    }

    public function getNoteOffsetY(isSustain:Bool):Float {
        return 0;
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

    public function addToNoteSpeed():Float {
        return 0;
    }

    public function playerShouldntHit():Bool {
        return false;
    }

    public function noDefaultSplash():Bool {
        return false;
    }

    public function giveHealth(isSustain:Bool):Float {
        return 0.023;
    }

    public function missNoteDamage():Float {
        return 0.069;
    }

    public function getWobblePower():UInt {
        return 0;
    }
}