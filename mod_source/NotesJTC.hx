package;

import template.CustomNote;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.animation.FlxAnimationController;

/**
* All these are extremely simple.
*/

class DeathNote extends CustomNoteTemplate {
    override function useCustomPrefix(animation:FlxAnimationController):Bool {
        animation.addByPrefix('greenScroll', 'DEATHup', 48);
        animation.addByPrefix('redScroll', 'DEATHright', 48);
        animation.addByPrefix('blueScroll', 'DEATHdown', 48);
        animation.addByPrefix('purpleScroll', 'DEATHleft', 48);

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
