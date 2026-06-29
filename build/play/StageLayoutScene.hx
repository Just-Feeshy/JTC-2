package play;

import flixel.FlxSprite;

/**
 * Single source of truth for turning a stage's declarative `stageLayout` table into a built,
 * placed scene. Both the Stage Editor preview and gameplay (PlayState) feed the SAME table here
 * so sprites/characters end up in identical world positions, scales, scroll factors and — crucially
 * — built in the SAME ORDER, which is what makes the two render 1:1.
 *
 * The class owns the layout iteration + transform application; it does NOT create the sprites
 * itself. Each context supplies a `StageSceneFactory` that produces its native sprite/character
 * objects (the editor's `funkin.game.*`, gameplay's engine sprites + `Character`) and sets up
 * animations. After the factory creates a sprite and plays its initial animation, `build()` applies
 * position -> scale + updateHitbox -> scrollFactor in the editor's proven order, so a scaled,
 * animated prop's hitbox/offset is computed against the FINAL frame in both contexts.
 *
 * `stageLayout` shape (Reflect-readable; arrays arrive as Array, keyed tables as anon objects):
 * {
 *   sprites = {                       -- ORDERED array; order == z-order (bottom first)
 *     { name="funkroadSky", asset="funkroadSky", x=-900, y=-500, scaleX=1.2, scaleY=1.2,
 *       scrollX=0.7, scrollY=0.7 },                       -- plain graphic
 *     { name="frostbiteBG", asset="funkroad", sparrow=true, x=..., scaleX=1.2, ...,
 *       anim={ kind="prefix", name="move", arg="funkroad", fps=24, loop=true } },
 *     { name="frostbiteCAR", asset="car", animate=true, x=-178, y=58, scrollX=1, scrollY=1,
 *       anim={ kind="timeline", name="drive", fps=24, loop=true } },
 *   },
 *   characters = {                    -- keyed slot -> placement
 *     dad        = { char="skater-boi", x=64, y=540, scroll=1 },
 *     boyfriend  = { char="flying BF sings", x=-2017, y=-922.99, scroll=1 },
 *     girlfriend = { char="gf", x=400, y=130, enabled=false, scroll=0.95 },
 *   },
 * }
 */
class StageLayoutScene
{
	public static function build(layout:Dynamic, factory:StageSceneFactory):Void
	{
		if (layout == null || factory == null)
			return;

		buildSprites(field(layout, "sprites"), factory);
		buildCharacters(field(layout, "characters"), factory);
	}

	static function buildSprites(rawSprites:Dynamic, factory:StageSceneFactory):Void
	{
		if (rawSprites == null || !Std.isOfType(rawSprites, Array))
			return;

		var arr:Array<Dynamic> = cast rawSprites;
		for (entry in arr)
		{
			if (entry == null)
				continue;

			// 1) create the native sprite (plain / sparrow / animate handled by the factory),
			// 2) set up + play its initial animation, THEN
			// 3) apply transforms in the editor's order so updateHitbox sees the played frame.
			var spr:FlxSprite = factory.createSprite(entry);
			if (spr == null)
				continue;

			factory.setupAnimation(spr, entry);

			spr.x = getFloat(entry, "x", spr.x);
			spr.y = getFloat(entry, "y", spr.y);

			if (hasField(entry, "scaleX") || hasField(entry, "scaleY"))
			{
				var sx:Float = getFloat(entry, "scaleX", 1);
				var sy:Float = getFloat(entry, "scaleY", sx);
				spr.scale.set(sx, sy);
				spr.updateHitbox();
			}

			if (hasField(entry, "scrollX") || hasField(entry, "scrollY"))
			{
				var fx:Float = getFloat(entry, "scrollX", 1);
				var fy:Float = getFloat(entry, "scrollY", fx);
				spr.scrollFactor.set(fx, fy);
			}

			// z-order is the array order: each addToScene call stacks on top of the previous.
			factory.addToScene(spr, getString(entry, "name", ""));
		}
	}

	static function buildCharacters(rawChars:Dynamic, factory:StageSceneFactory):Void
	{
		if (rawChars == null)
			return;

		// Characters are a keyed table; build in a stable slot order.
		for (slot in ["dad", "boyfriend", "girlfriend"])
		{
			var entry:Dynamic = field(rawChars, slot);
			if (entry == null)
				continue;

			var enabled:Bool = !hasField(entry, "enabled") || getBool(entry, "enabled", true);
			var charName:String = getString(entry, "char", "");

			var spr:FlxSprite = factory.createCharacter(slot, charName, enabled, entry);
			if (spr == null)
				continue;

			spr.x = getFloat(entry, "x", spr.x);
			spr.y = getFloat(entry, "y", spr.y);

			if (hasField(entry, "scroll"))
			{
				var s:Float = getFloat(entry, "scroll", 1);
				spr.scrollFactor.set(s, s);
			}

			factory.addCharacterToScene(spr, slot);
		}
	}

	// ------------------------------------------------------------------
	// Reflect helpers (same approach as play.StageCamera.configure)
	// ------------------------------------------------------------------

	static inline function field(obj:Dynamic, name:String):Dynamic
		return (obj != null && Reflect.hasField(obj, name)) ? Reflect.field(obj, name) : null;

	static inline function hasField(obj:Dynamic, name:String):Bool
		return obj != null && Reflect.hasField(obj, name);

	static function getFloat(obj:Dynamic, name:String, def:Float):Float
	{
		var v:Dynamic = field(obj, name);
		if (v == null) return def;
		var f:Float = cast v;
		return Math.isNaN(f) ? def : f;
	}

	static function getString(obj:Dynamic, name:String, def:String):String
	{
		var v:Dynamic = field(obj, name);
		return (v != null) ? Std.string(v) : def;
	}

	static function getBool(obj:Dynamic, name:String, def:Bool):Bool
	{
		var v:Dynamic = field(obj, name);
		if (v == null) return def;
		if (Std.isOfType(v, Bool)) return cast v;
		// Lua may hand booleans through as 1/0 or strings.
		if (Std.isOfType(v, Float)) return (cast v : Float) != 0;
		var s = Std.string(v).toLowerCase();
		return s == "true" || s == "1";
	}
}
