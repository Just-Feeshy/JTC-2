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

    override function giveHealth(isSustain:Bool):Float {
        return -2;
    }

    override function playerShouldntHit():Bool {
        return true;
    }

    override function cantHaveHold():Bool {
        return true;
    }
}

class CheeseNote extends CustomNoteTemplate {
    override function useCustomPrefix(animation:FlxAnimationController):Bool {
        animation.addByPrefix('greenScroll', 'CHEESEup', 24);
        animation.addByPrefix('redScroll', 'CHEESEright', 24);
        animation.addByPrefix('blueScroll', 'CHEESEdown', 24);
        animation.addByPrefix('purpleScroll', 'CHEESEleft', 24);

        return true;
    }

    override function createSpriteWhenHit():FlxSprite {
        var ogSize:Int = FlxG.random.int(2, 3);

        var sprite = new FlxSprite().loadGraphic(Paths.image("cheese slice"));
        sprite.scale.x /= ogSize;
        sprite.scale.y /= ogSize;
        sprite.updateHitbox();
        sprite.x = FlxG.random.int(0, Std.int(FlxG.width - sprite.width));
        sprite.y = FlxG.random.int(0, Std.int(FlxG.height - sprite.height));
        sprite.angle = FlxG.random.int(0, 360);

        return sprite;
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

    override function getWobblePower():UInt {
        return 30;
    }
}