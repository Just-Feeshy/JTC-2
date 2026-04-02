package play;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxPoint;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.utils.Assets;
import SaveData.SaveType;

using StringTools;

/**
 * A standalone death character sprite that can be fully customized via Lua.
 * Unlike Character, this is a simple FlxSprite with animation support
 * designed specifically for game over screens.
 */
class DeathCharacter extends FlxSprite {
    public var characterName:String = "bf-dead";
    public var cameraOffsetX:Float = 0;
    public var cameraOffsetY:Float = 0;
    public var cameraZoom:Float = 1.0;

    // Animation names (can be overridden via Lua)
    public var firstDeathAnim:String = "firstDeath";
    public var deathLoopAnim:String = "deathLoop";
    public var deathConfirmAnim:String = "deathConfirm";

    // Sound paths (can be overridden via Lua)
    public var deathSoundPath:String = "";
    public var deathMusicPath:String = "";
    public var deathMusicLoopPath:String = "";
    public var deathConfirmMusicPath:String = "";

    // State tracking
    public var isAnimationFinished:Bool = false;
    private var currentAnimName:String = "";

    public function new(x:Float = 0, y:Float = 0) {
        super(x, y);
        antialiasing = SaveData.getData(SaveType.GRAPHICS);
    }

    /**
     * Load a spritesheet for the death character
     */
    public function loadDeathGraphic(imagePath:String, ?xmlPath:String):Void {
        if (imagePath == null || imagePath.trim() == "") return;

        var atlasPath = imagePath.replace(".png", "").replace(".xml", "");

        if (xmlPath != null && xmlPath.trim() != "") {
            // Custom XML path
            frames = FlxAtlasFrames.fromSparrow(Paths.image(atlasPath), Paths.getPath('images/$xmlPath.xml', TEXT, ""));
        } else {
            // Standard sparrow atlas
            frames = Paths.getSparrowAtlas(atlasPath);
        }

        antialiasing = SaveData.getData(SaveType.GRAPHICS);
    }

    /**
     * Load a simple graphic (non-animated)
     */
    public function loadSimpleGraphic(imagePath:String):Void {
        if (imagePath == null || imagePath.trim() == "") return;
        loadGraphic(Paths.image(imagePath));
        antialiasing = SaveData.getData(SaveType.GRAPHICS);
    }

    /**
     * Add an animation by prefix
     */
    public function addDeathAnimation(name:String, prefix:String, frameRate:Int = 24, looped:Bool = false):Void {
        if (frames == null) return;
        animation.addByPrefix(name, prefix, frameRate, looped);
    }

    /**
     * Add an animation by indices
     */
    public function addDeathAnimationByIndices(name:String, prefix:String, indices:Array<Int>, frameRate:Int = 24, looped:Bool = false):Void {
        if (frames == null) return;
        animation.addByIndices(name, prefix, indices, "", frameRate, looped);
    }

    /**
     * Play an animation
     */
    public function playDeathAnimation(name:String, force:Bool = false):Void {
        if (animation == null) return;

        currentAnimName = name;
        isAnimationFinished = false;
        animation.play(name, force);

        animation.finishCallback = function(animName:String) {
            if (animName == currentAnimName) {
                isAnimationFinished = true;
            }
        };
    }

    /**
     * Check if an animation exists
     */
    public function hasDeathAnimation(name:String):Bool {
        if (animation == null) return false;
        return animation.getByName(name) != null;
    }

    /**
     * Get the current animation name
     */
    public function getCurrentAnimationName():String {
        return currentAnimName;
    }

    /**
     * Play the first death animation
     */
    public function playFirstDeath():Void {
        if (hasDeathAnimation(firstDeathAnim)) {
            playDeathAnimation(firstDeathAnim, true);
        }
    }

    /**
     * Play the death loop animation
     */
    public function playDeathLoop():Void {
        if (hasDeathAnimation(deathLoopAnim)) {
            playDeathAnimation(deathLoopAnim, true);
        }
    }

    /**
     * Play the death confirm animation
     */
    public function playDeathConfirm():Void {
        if (hasDeathAnimation(deathConfirmAnim)) {
            playDeathAnimation(deathConfirmAnim, true);
        }
    }

    /**
     * Get camera focus point (center of sprite + offsets)
     */
    public function getCameraFocusPoint():FlxPoint {
        return FlxPoint.get(
            x + (width / 2) + cameraOffsetX,
            y + (height / 2) + cameraOffsetY
        );
    }

    /**
     * Set position with optional offset
     */
    public function setDeathPosition(newX:Float, newY:Float, offsetX:Float = 0, offsetY:Float = 0):Void {
        x = newX + offsetX;
        y = newY + offsetY;
    }

    /**
     * Copy position from another sprite
     */
    public function copyPositionFrom(sprite:FlxSprite, offsetX:Float = 0, offsetY:Float = 0):Void {
        if (sprite == null) return;
        x = sprite.x + offsetX;
        y = sprite.y + offsetY;
    }

    override function update(elapsed:Float):Void {
        super.update(elapsed);

        // Check animation finished status
        if (animation != null && animation.curAnim != null) {
            if (animation.curAnim.finished && !isAnimationFinished) {
                isAnimationFinished = true;
            }
        }
    }

    override function destroy():Void {
        super.destroy();
    }
}
