package example_code;

import template.CustomNote;

import flixel.FlxG;
import flixel.math.FlxMath;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;

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

    override function shouldBeIgnored():Bool {
        return true;
    }

    override function makeLongNoteLong():Bool {
        return false;
    }
}

/**
* A tad bit more difficult to understand compared to the others.
*/
class ReverseNote extends CustomNoteTemplate {
    var oppositeID:Int = 0;
    var angle:Float = 0;

    override function whenIsFirstRendered(note:Note, totalNotesInSection:Int) {
        oppositeID = Std.int(Math.abs(note.noteData - (totalNotesInSection - 1)));
        note.playAnim(Note.getColorFacing(oppositeID) + "Scroll");
    }

    override function whenNoteIsHit(strumNote:Strum):Bool {
        @:privateAccess
        if(!strumNote.animation._animations.exists("confirm reverse")) {
            strumNote.animation.destroyAnimations();
            strumNote.twoInOneFrames(Paths.getSparrowAtlas('NOTE_assets', null, true), Paths.getSparrowAtlas('notes/reverse/CONFIRM_assets'));
            strumNote.animation.addByPrefix("confirm reverse", strumNote.direction + " confirm reverse", 24, false);
            strumNote.setupAnimations();
        }

        strumNote.setColorTransform(1,1,1,1,0,0,0,0);
        strumNote.playAnim('confirm reverse', true);

        return false;
    }

    override function createSplashSprite(splash:SplashSprite, strumNote:Strum, rating:String) {
        splash.texture = "regular/splash";
        splash.setPosition(strumNote.x-(splash.width/3), strumNote.y-(splash.height/3));
        splash.animation.play('reverse sploosh');
    }

    override function setNoteAngle(note:Note, value:Float):Float {
        if(note.getNoteStrumPosition(100) < 1) {
            angle = FlxMath.lerp(180, 0, note.getNoteStrumPosition(100));

            if(angle > 90 && note.animation.curAnim.name == Note.getColorFacing(oppositeID) + "Scroll") {
                note.playAnim(Note.getColorFacing(note.noteData) + "Scroll");
            }
        }

        if(angle > 90) {
            return 180 - angle;
        }else {
            return angle;
        }
    }

    override function setXPosition(note:Note, strums:Array<Strum>, x:Float):Float {
        if(note.getNoteStrumPosition(100) < 1) {
            return FlxMath.lerp(x, strums[oppositeID].x, note.getNoteStrumPosition(100));
        }

        return strums[oppositeID].x;
    }

    override function noDefaultSplash():Bool {
        return true;
    }

    override function cantHaveHold():Bool {
        return true;
    }
}