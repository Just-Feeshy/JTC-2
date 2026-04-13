package;

import template.CustomNote;

import flixel.FlxSprite;
import flixel.animation.FlxAnimationController;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.math.FlxMath;
import flixel.tweens.FlxEase;
import flixel.util.FlxColor;

/**
* All these are extremely simple (Except Death).
*/

class DeathNote extends CustomNoteTemplate {
    private static inline var TRANSITION_START_OFFSET:Int = 350;
    private static inline var TRANSITION_SPIN_OFFSET:Int = 175;
    private static final REGULAR_TRANSITION_TINT:FlxColor = FlxColor.fromRGB(214, 214, 214);
    private static var combinedFrames:FlxFramesCollection;

    function setupRegularPrefixes(animation:FlxAnimationController):Void {
        animation.addByPrefix('greenScroll', 'green0');
        animation.addByPrefix('redScroll', 'red0');
        animation.addByPrefix('blueScroll', 'blue0');
        animation.addByPrefix('purpleScroll', 'purple0');
        animation.addByPrefix('diamondScroll', 'diamond0');
    }

    function setupDeathPrefixes(animation:FlxAnimationController):Void {
        animation.addByPrefix('greenDeathScroll', 'DEATHup', 48);
        animation.addByPrefix('redDeathScroll', 'DEATHright', 48);
        animation.addByPrefix('blueDeathScroll', 'DEATHdown', 48);
        animation.addByPrefix('purpleDeathScroll', 'DEATHleft', 48);
        animation.addByPrefix('diamondDeathScroll', 'DEATHdown', 48);
    }

    inline function getScrollAnimName(note:Note):String {
        return Note.getColorFacing(note.noteData) + "Scroll";
    }

    inline function getDeathAnimName(note:Note):String {
        return Note.getColorFacing(note.noteData) + "DeathScroll";
    }

    function getCombinedFrames():FlxFramesCollection {
        if(combinedFrames == null) {
            combinedFrames = FlxAnimationUtil.combineAtlas([
                Paths.getNoteAtlas('regular/NOTE_assets'),
                Paths.getNoteAtlas('death/NOTE_assets')
            ]);
        }

        return combinedFrames;
    }

    inline function updateRevealAnimation(note:Note, transitionProgress:Float):Void {
        var regularAnimName = getScrollAnimName(note);
        var deathAnimName = getDeathAnimName(note);
        var targetAnimName = transitionProgress >= 0.5 ? deathAnimName : regularAnimName;

        if(note.animation.curAnim == null || note.animation.curAnim.name != targetAnimName) {
            note.playAnim(targetAnimName, true);
        }
    }

    inline function updateRevealTint(note:Note, transitionProgress:Float):Void {
        if(transitionProgress < 0.5) {
            var tintProgress:Float = FlxMath.bound(transitionProgress / 0.5, 0, 1);
            note.color = FlxColor.interpolate(FlxColor.WHITE, REGULAR_TRANSITION_TINT, tintProgress);
        } else {
            note.color = FlxColor.WHITE;
        }
    }

    function setupCombinedAnimations(animation:FlxAnimationController):Void {
        animation.destroyAnimations();
        setupRegularPrefixes(animation);
        setupDeathPrefixes(animation);
    }

    override function whenIsFirstRendered(note:Note, totalNotesInSection:Int):Void {
        var currentScaleX:Float = note.scale.x;
        var currentScaleY:Float = note.scale.y;
        var currentAntialiasing:Bool = note.antialiasing;

        note.frames = getCombinedFrames();
        setupCombinedAnimations(note.animation);
        note.antialiasing = currentAntialiasing;
        updateRevealAnimation(note, 0);
        updateRevealTint(note, 0);
    }

    override function setNoteAngle(note:Note, value:Float):Float {
		var angle:Float = value;

        if(note.getNoteStrumPosition(TRANSITION_SPIN_OFFSET) / 25 <= 1) {
            angle = FlxMath.lerp(360, 0, FlxEase.backOut(note.getNoteStrumPosition(TRANSITION_SPIN_OFFSET) / 25)) + value;
        }

        return angle % 360;
    }

    override function noteUpdate(note:Note):Void {
        var transitionProgress = note.getTransitionProgress(TRANSITION_START_OFFSET);
        updateRevealAnimation(note, transitionProgress);
        updateRevealTint(note, transitionProgress);
    }

    override function useCustomPrefix(animation:FlxAnimationController):Bool {
        setupDeathPrefixes(animation);
        return true;
    }

    override function playerShouldntHit():Bool {
        return true;
    }

    override function cantHaveHold():Bool {
        return true;
    }

    override function shouldBeIgnored():Bool {
        return true;
    }

    override function noDefaultSplash():Bool {
        return true;
    }
}

/**
 * A cheese note for the fifth key that does nothing special.
 * Uses the JTC_SPECIAL_NOTE_assets from the fifth folder.
 */
class CheeseFifthNote extends CustomNoteTemplate {
	public static var fifthKeySize:Float = 1.0;
	public static var fifthKeyOffsetX:Float = -18;

    override function getCustomAssetPath():String {
        return "fifth/JTC_SPECIAL_NOTE_assets";
    }

    override function useCustomPrefix(animation:FlxAnimationController):Bool {
        animation.addByPrefix('diamondScroll', 'Cheese note');
        animation.addByPrefix('purpleScroll', 'Cheese note');
        animation.addByPrefix('blueScroll', 'Cheese note');
        animation.addByPrefix('greenScroll', 'Cheese note');
        animation.addByPrefix('redScroll', 'Cheese note');
        return true;
    }

    override function getNoteOffsetX(isSustain:Bool):Float {
        return fifthKeyOffsetX;
    }

    override function whenIsFirstRendered(note:Note, totalNotesInSection:Int):Void {
        note.scale.set(note.scale.x * fifthKeySize, note.scale.y * fifthKeySize);
        note.updateHitbox();
    }

    override function cantHaveHold():Bool {
        return true; // No sustains for this note
    }
}

class CheeseNote extends CustomNoteTemplate {
    private var sourceWasPlayerSide:Bool = false;

    override function useCustomPrefix(animation:FlxAnimationController):Bool {
        animation.addByPrefix('greenScroll', 'CHEESEup', 24);
        animation.addByPrefix('redScroll', 'CHEESEright', 24);
        animation.addByPrefix('blueScroll', 'CHEESEdown', 24);
        animation.addByPrefix('purpleScroll', 'CHEESEleft', 24);

        return true;
    }

    override function pressedByPlayer(note:Note, player:Character, opponent:Character, girlfriend:Character):Void {
        sourceWasPlayerSide = note.mustPress;
    }

    override function createSpriteWhenHit():FlxSprite {
        return new CheeseSliceSprite(sourceWasPlayerSide);
    }

	override function shouldBeIgnored():Bool {
		return true;
	}

    override function playerShouldntHit():Bool {
        return true;
    }

    override function cantHaveHold():Bool {
        return true;
    }

    override function noDefaultSplash():Bool {
        return true;
    }
}

class CoolNote extends CustomNoteTemplate {
    override function useCustomPrefix(animation:FlxAnimationController):Bool {
        animation.addByPrefix('greenScroll', 'COMBOup', 24);
        animation.addByPrefix('redScroll', 'COMBOright', 24);
        animation.addByPrefix('blueScroll', 'COMBOdown', 24);
        animation.addByPrefix('purpleScroll', 'COMBOleft', 24);

        animation.addByPrefix('purplehold end', 'COMBOhold end', 24);
        animation.addByPrefix('greenhold end', 'COMBOhold end', 24);
        animation.addByPrefix('redhold end', 'COMBOhold end', 24);
        animation.addByPrefix('bluehold end', 'COMBOhold end', 24);

        animation.addByPrefix('purplehold', 'COMBOhold piece', 24);
        animation.addByPrefix('greenhold', 'COMBOhold piece', 24);
        animation.addByPrefix('redhold', 'COMBOhold piece', 24);
        animation.addByPrefix('bluehold', 'COMBOhold piece', 24);

        return true;
    }

    override function giveHealth(isSustain:Bool):Float {
        return 0.046;
    }

    override function missNoteDamage():Float {
        return 0.138;
    }

    override function getWobblePower():UInt {
        return 30;
    }
}
