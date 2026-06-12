package;

import flixel.FlxG;
import flixel.math.FlxPoint;
import openfl.utils.AssetType;

import ModInitialize.ConfigCharacters;

using StringTools;

/**
 * A `Character` rendered from an Adobe Animate texture atlas via flxanimate.
 *
 * This mirrors how Funkin's `funkin.play.character.AnimateAtlasCharacter` wraps a
 * `FlxAtlasSprite`. Because JTC-2 types every character as `Character`, this
 * subclasses `Character` and drives a `FlxAtlasSprite` child (composition),
 * syncing transform properties to it each frame rather than multiple-inheriting
 * or copying FlxSpriteGroup's full setter surface.
 *
 * IMPORTANT: fields used by `buildAnimateAtlas()` are declared WITHOUT
 * initializers. `buildAnimateAtlas()` runs from the base `Character` constructor
 * (during `super()`), but Haxe runs subclass field initializers AFTER `super()`,
 * which would otherwise clobber values set during construction.
 */
class AnimateAtlasCharacter extends Character
{
	public var mainSprite:FlxAtlasSprite;

	var currentAnimName:String;
	var animationPrefixes:Map<String, String>;
	var animationLooped:Map<String, Bool>;

	public function new(x:Float, y:Float, ?character:String = "bf", ?isPlayer:Bool = false, ?hardInfo:ConfigCharacters, frameOffsetApply:Bool = true)
	{
		super(x, y, character, isPlayer, hardInfo, frameOffsetApply);
	}

	override function isAnimateAtlasRenderer():Bool
	{
		return true;
	}

	override function buildAnimateAtlas():Void
	{
		currentAnimName = "";
		animationPrefixes = new Map<String, String>();
		animationLooped = new Map<String, Bool>();

		var atlasPath:String = resolveAtlasPath(stripAtlasExtension(_info.file));

		mainSprite = new FlxAtlasSprite(x, y, atlasPath);
		mainSprite.antialiasing = FlxG.save.data.showAntialiasing && !_info.pixel;
		// Don't let "sing" animations get interrupted by idle dancing mid-hold.
		mainSprite.ignoreExclusionPref = ["sing"];

		for (anim in _info.animations.keys())
		{
			var animInfo = _info.animations.get(anim);
			animations.push(anim);

			var prefix:String = (animInfo.prefix != null && animInfo.prefix != "") ? animInfo.prefix : anim;
			animationPrefixes.set(anim, prefix);
			animationLooped.set(anim, animInfo.looped);
			addOffset(anim, animInfo.offset[0], animInfo.offset[1]);

			if (anim.endsWith("player") && isPlayer) hasBePlayer = "player";
		}

		// Force the atlas to compute its real width/height (Funkin does the same dance).
		mainSprite.alpha = 0.0001;
		mainSprite.draw();
		mainSprite.alpha = 1.0;

		var startAnim:String = (_info.playAnim != null && _info.playAnim != "") ? _info.playAnim : "idle";
		playAnim(startAnim);
		flipX = _info.isPlayer;
	}

	/**
	 * Resolves the folder path that flxanimate expects (the directory holding
	 * `Animation.json`/`spritemap*`), using JTC-2's `Paths` resolution.
	 */
	function resolveAtlasPath(folder:String):String
	{
		var jsonPath:String = Paths.getPath('images/${folder}/Animation.json', TEXT, "shared");
		var suffix:String = "/Animation.json";

		if (jsonPath != null && jsonPath.endsWith(suffix))
		{
			return jsonPath.substr(0, jsonPath.length - suffix.length);
		}

		return 'mod_assets/images/${folder}';
	}

	static function stripAtlasExtension(file:String):String
	{
		if (file == null) return "";

		// Atlas characters use a single folder; ignore any extra comma list / extension.
		var comma:Int = file.indexOf(",");
		if (comma >= 0) file = file.substr(0, comma);
		file = file.trim();

		var dot:Int = file.lastIndexOf(".");
		if (dot >= 0) file = file.substr(0, dot);

		return file;
	}

	// ===== Animation API overrides (delegate to the FlxAtlasSprite) =====

	override public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void
	{
		if (mainSprite == null) return;

		var resolved:String = resolveAnimationName(AnimName);

		var prefix:String = animationPrefixes.exists(resolved) ? animationPrefixes.get(resolved) : (animationPrefixes.exists(AnimName) ? animationPrefixes.get(AnimName) : resolved);

		if (prefix == null || prefix == "") prefix = resolved;
		if (!mainSprite.hasAnimation(prefix))
		{
			trace('[ATLASCHAR] ${curCharacter}: prefix "${prefix}" (anim "${AnimName}") not found in atlas');
			return;
		}

		specialAnim = false;
		if (resolved.startsWith("sing")) dancing = false;

		currentAnimName = resolved;

		var looped:Bool = animationLooped.exists(resolved) ? animationLooped.get(resolved) : false;
		mainSprite.playAnimation(prefix, true, false, looped);

		var off:Array<Float> = animOffsets.exists(resolved) ? animOffsets.get(resolved) : animOffsets.get(AnimName);
		if (off != null) offset.set(off[0], off[1]);
		else offset.set(0, 0);
	}

	override public function getAnimName():String
	{
		return currentAnimName;
	}

	override public function isAnimationFinished():Bool
	{
		return mainSprite != null && mainSprite.isAnimationFinished();
	}

	override public function hasAnimation(animName:String):Bool
	{
		if (animationPrefixes == null) return false;
		var resolved:String = resolveAnimationName(animName);
		return animationPrefixes.exists(resolved) || animationPrefixes.exists(animName);
	}

	// ===== Transform sync + rendering =====

	function syncMainSprite():Void
	{
		if (mainSprite == null) return;

		mainSprite.x = x;
		mainSprite.y = y;
		mainSprite.offset.set(offset.x, offset.y);
		mainSprite.flipX = flipX;
		mainSprite.flipY = flipY;
		mainSprite.alpha = alpha;
		mainSprite.color = color;
		mainSprite.visible = visible;
		mainSprite.angle = angle;
		mainSprite.antialiasing = antialiasing;
		mainSprite.scale.set(scale.x, scale.y);
		mainSprite.scrollFactor.set(scrollFactor.x, scrollFactor.y);
		mainSprite.shader = shader;
		mainSprite.cameras = cameras;
		// NOTE: origin is intentionally NOT synced — FlxAnimate uses it as the
		// atlas pivot (symbol transformation point); overwriting it breaks rendering.
	}

	override function update(elapsed:Float):Void
	{
		syncMainSprite();
		if (mainSprite != null) mainSprite.update(elapsed);

		// Run the base gameplay logic (sing/hold-timer/dance). It only relies on the
		// overridden animation queries above, so it works for atlas characters too.
		super.update(elapsed);
	}

	override public function draw():Void
	{
		syncMainSprite();
		if (mainSprite != null) mainSprite.draw();
	}

	override public function getGraphicMidpoint(?point:FlxPoint):FlxPoint
	{
		if (mainSprite == null) return super.getGraphicMidpoint(point);
		mainSprite.x = x;
		mainSprite.y = y;
		return mainSprite.getGraphicMidpoint(point);
	}

	override function get_width():Float
	{
		return mainSprite == null ? super.get_width() : mainSprite.width;
	}

	override function get_height():Float
	{
		return mainSprite == null ? super.get_height() : mainSprite.height;
	}

	override function set_width(value:Float):Float
	{
		return value;
	}

	override function set_height(value:Float):Float
	{
		return value;
	}

	override function destroy():Void
	{
		if (mainSprite != null)
		{
			mainSprite.destroy();
			mainSprite = null;
		}

		super.destroy();
	}
}
