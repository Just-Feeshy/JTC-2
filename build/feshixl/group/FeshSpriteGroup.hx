package feshixl.group;

import feshixl.FeshSprite;
import flixel.group.FlxGroup.FlxTypedGroup;

typedef FeshSpriteGroup = FeshTypedSpriteGroup<FeshSprite>;

/**
 * `FeshSpriteGroup` is a special `FeshSprite` that can be treated like
 * a single sprite even if it's made up of several member sprites.
 * Unlike `FlxSpriteGroup` you can render graphics on the group itself.
 */
class FeshTypedSpriteGroup<T:FeshSprite> extends FeshSprite {
    /**
	 * The actual group which holds all sprites.
	 */
	public var group:FlxTypedGroup<T>;

	/**
	 * `Array` of all the members in this group.
	 */
	public var members(get, never):Array<T>;

    /**
	 * The number of entries in the members array. For performance and safety you should check this
	 * variable instead of `members.length` unless you really know what you're doing!
	 */
	public var length(get, never):Int;

    /**
	 * The maximum capacity of this group. Default is `0`, meaning no max capacity, and the group can just grow.
	 */
	public var maxSize(get, set):Int;

    /**
	 * Optimization to allow setting position of group without transforming children twice.
	 */
	var _skipTransformChildren:Bool = false;

	/**
	 * Array of all the `FeshSprite`s that exist in this group for
	 * optimization purposes / static typing on cpp targets.
	 */
	var _sprites:Array<FeshSprite>;

    public function new(x:Float = 0, y:Float = 0, maxSize:Int = 0) {
        super(x, y);
        group = new FlxTypedGroup<T>(maxSize);
        _sprites = cast group.members;
    }

    override function initVars():Void {
        flixelType = SPRITEGROUP;

        offset = new FlxCallbackPoint(offsetCallback);
        origin = new FlxCallbackPoint(originCallback);
        scale = new FlxCallbackPoint(scaleCallback);
        scrollFactor = new FlxCallbackPoint(scrollFactorCallback);

        scale.set(1, 1);
        scrollFactor.set(1, 1);

        initMotionVars();
    }

    override public function destroy():Void {
        // normally don't have to destroy FlxPoints, but these are FlxCallbackPoints!
        offset = FlxDestroyUtil.destroy(offset);
        origin = FlxDestroyUtil.destroy(origin);
        scale = FlxDestroyUtil.destroy(scale);
        scrollFactor = FlxDestroyUtil.destroy(scrollFactor);

        group = FlxDestroyUtil.destroy(group);
        _sprites = null;

        super.destroy();
    }

    override public function clone():FeshTypedSpriteGroup<T> {
        var newGroup = new FeshTypedSpriteGroup<T>(x, y, maxSize);

        for (sprite in group.members) {
            if (sprite != null) {
                newGroup.add(cast sprite.clone());
            }
        }
        
        return newGroup;
    }
}