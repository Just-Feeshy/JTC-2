package example_code;

import template.CustomNote;

import flixel.FlxG;
import flixel.math.FlxRect;
import flixel.math.FlxMath;
import flixel.util.FlxColor;
import feshixl.math.FeshMath;

/**
* A tad bit simpler to understand compared to the others.
*/
class PoisonNote extends CustomNoteTemplate {
    override function whenIsSpawned(note:Note):Void {
        if(note.prevNote != null) {
            if(note.prevNote.isSustainNote) {
                note.prevNote.setGraphicSize(Std.int(note.prevNote.width * FlxG.random.float(0.75, 1.5)));
                note.prevNote.updateHitbox();
            }
        }
    }

    override function whenNoteIsHit(strumNote:Strum):Bool {
        return false;
    }

    override function createSplashSprite(splash:SplashSprite, strumInfo:FlxRect, rating:String) {
        if(splash != null) {
            splash.setPosition(strumInfo.x-(splash.width/3), strumInfo.y-(splash.height/3));
            splash.animation.addByPrefix('poison sploosh', "poisonEffect skull", 24, false);
            splash.animation.play('poison sploosh');
        }

        strumInfo.put();
    }

    override function getSplashTexture():String {
        return "poison/poisonEffect";
    }

    override function getNoteOffsetX(isSustain:Bool):Float {
        if(isSustain) {
            return FlxG.random.float(-Note.swagWidth / 3, Note.swagWidth / 3);
        }

        return 0;
    }

    override function playSoundWhenNoteIsHit(mustPress:Bool, isSustain:Bool):String {
        return "poison";
    }

    override function giveHealth(isSustain:Bool):Float {
        if(isSustain) {
            return -0.004;
        }

        return -0.2;
    }

    override function noDefaultSplash():Bool {
        return true;
    }

    override function playerShouldntHit():Bool {
        return true;
    }

    override function shouldBeIgnored():Bool {
        return true;
    }

    override function makeLongNoteLong():Bool {
        return false;
    }

    override function customEndSustainNotePosition():Bool {
        return true;
    }
}

class ReverseNote extends CustomNoteTemplate {
    var anotherSplash:Bool = false;
    var customStrum:Bool = true;

    var oppositeID:Int = 0;
    var angle:Float = 0;

    public function new(customStrum:Bool = false, anotherSplash:Bool = false) {
        this.customStrum = customStrum;
        this.anotherSplash = anotherSplash;
    }

    override function whenIsFirstRendered(note:Note, totalNotesInSection:Int) {
        oppositeID = Std.int(Math.abs(note.noteData - (totalNotesInSection - 1)));
        note.playAnim(Note.getColorFacing(oppositeID) + "Scroll");
    }

    override function whenNoteIsHit(strumNote:Strum):Bool {
        if(!customStrum) {

            /**
            * Basically add a second sprite sheet to the strum.
            */
            @:privateAccess
            if(!strumNote.animation._animations.exists("confirm reverse")) {
                strumNote.animation.destroyAnimations();
                strumNote.twoInOneFrames(strumNote.frames, Paths.getSparrowAtlas('notes/reverse/CONFIRM_assets'));
                strumNote.animation.addByPrefix("confirm reverse", strumNote.direction + " confirm reverse", 24, false);
                strumNote.setupAnimations();
            }

            strumNote.setColorTransform(1,1,1,1,0,0,0,0);
            strumNote.playAnim('confirm reverse', true);
        }

        return false;
    }

    override function createSplashSprite(splash:SplashSprite, strumInfo:FlxRect, rating:String):Void {
        if(!anotherSplash) {
            if(splash != null && (rating == "sick" || rating == "good")) {
                splash.setPosition(strumInfo.x-(splash.width / 3), strumInfo.y-(splash.height / 3));
                splash.animation.play('reverse sploosh');
            }
        }

        strumInfo.put();
    }

    override function setNoteAngle(note:Note, value:Float):Float {
        if(note.getNoteStrumPosition(100) < 1) {
            angle = FlxMath.lerp(180, 0, note.getNoteStrumPosition(100));

            if(angle > 90 && note.animation.curAnim.name == Note.getColorFacing(oppositeID) + "Scroll") {
                note.playAnim(Note.getColorFacing(note.noteData) + "Scroll");
            }
        }

        if(!note.isSustainNote) {
            if(angle > 90) {
                return value + (180 - angle);
            }else {
                return value + angle;
            }
        }

        return value;
    }

    override function setXPosition(note:Note, strums:Array<Strum>, x:Float):Float {
        var anglePos:Float = 1 - FeshMath.cbrt(Math.min(1, note.getNoteStrumPosition(100)));
        var angleLerp:Float = FlxMath.lerp(strums[note.noteData].angle, strums[oppositeID].angle, anglePos);

        if(!note.isSustainNote) {
            if(note.getNoteStrumPosition(100) < 1) {
                return angleMeasurements(FlxMath.lerp(x, strums[oppositeID].x, anglePos), note, angleLerp);
            }

            return angleMeasurements(strums[oppositeID].x, note, strums[oppositeID].angle);
        }

        return x;
    }

    override function missNoteDamage():Float {
        return 0.14;
    }

    override function noDefaultSplash():Bool {
        return true;
    }

    override function cantHaveHold():Bool {
        return true;
    }

    function angleMeasurements(x:Float, note:Note, angle:Float):Float {
        return (x + note.noteOffset.x) + Math.sin(angle) * note.caculatePos;
    }
}

class ReversePoisonNote extends ReverseNote {
    public function new(customStrum:Bool = true, anotherSplash:Bool = true) {
        super(customStrum, anotherSplash);
    }

    override function whenIsSpawned(note:Note):Void {
        if(note.prevNote != null) {
            if(note.prevNote.isSustainNote) {
                note.prevNote.setGraphicSize(Std.int(note.prevNote.width * FlxG.random.float(0.75, 1.5)));
                note.prevNote.updateHitbox();
            }
        }
    }

    override function playSoundWhenNoteIsHit(mustPress:Bool, isSustain:Bool):String {
        return "poison";
    }

    override function createSplashSprite(splash:SplashSprite, strumInfo:FlxRect, rating:String) {
        if(splash != null) {
            splash.setPosition(strumInfo.x-(splash.width/3), strumInfo.y-(splash.height/3));
            splash.animation.addByPrefix('poison sploosh', "poisonEffect skull", 24, false);
            splash.animation.play('poison sploosh');
        }
    }

    override function getSplashTexture():String {
        return "poison/poisonEffect";
    }

    override function getNoteOffsetX(isSustain:Bool):Float {
        if(isSustain) {
            return FlxG.random.float(-Note.swagWidth / 3, Note.swagWidth / 3);
        }

        return 0;
    }

    override function giveHealth(isSustain:Bool):Float {
        if(isSustain) {
            return -0.004;
        }

        return -0.2;
    }

    override function setXPosition(note:Note, strums:Array<Strum>, x:Float):Float {
        if(note.isSustainNote && note.prevNote != null) {
            return note.prevNote.getInverseAxis();
        }

        return super.setXPosition(note, strums, x);
    }

    override function missNoteDamage():Float {
        return 0;
    }

    override function makeLongNoteLong():Bool {
        return false;
    }

    override function cantHaveHold():Bool {
        return false;
    }

    override function customEndSustainNotePosition():Bool {
        return true;
    }
}