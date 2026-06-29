package play;

import flixel.FlxSprite;
import funkin.backend.FunkinSprite;

/**
 * Gameplay-side `StageSceneFactory` for `StageLayoutScene`. It builds scenery props the EXACT same
 * way the Stage Editor does (`funkin.backend.FunkinSprite` + `Paths.getAnimateAtlas`/`getSparrowAtlas`/
 * `loadGraphic`, same animation setup) — mirroring `funkin.game.Stage.createSprite` — so the Adobe-
 * Animate registration / frame data is identical and there's no per-class drift. (Gameplay's own
 * `ModLua.createAnimateSprite` uses a different `FunkinSprite` + `loadTextureAtlas`, which is what put
 * the car in the wrong spot.) Created props are registered in the stage lua's sprite store by name so
 * the stage script's dynamic logic (`getSprite`, the car transition/fog) still finds them.
 *
 * Characters are NOT built here — PlayState already creates/positions boyfriend/dad/gf (their
 * positions already match the editor), so `createCharacter` returns null and the shared builder
 * skips them.
 */
class GameplayStageSceneFactory implements StageSceneFactory
{
	var playState:PlayState;
	var zIndex:Int = 0;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function createSprite(entry:Dynamic):FlxSprite
	{
		var name:String = str(entry, "name", "");
		var asset:String = str(entry, "asset", name);

		var spr = new FunkinSprite();
		spr.name = name;

		var isAnimate:Bool = bool(entry, "animate");
		var isSparrow:Bool = bool(entry, "sparrow");

		if (isAnimate)
		{
			try { spr.frames = Paths.getAnimateAtlas(asset); }
			catch (e:Dynamic) {}
			if (spr.frames == null)
			{
				try { spr.frames = Paths.getFrames(asset); }
				catch (e:Dynamic) {}
			}
		}
		else if (isSparrow)
		{
			try { spr.frames = Paths.getSparrowAtlas(asset); }
			catch (e:Dynamic) {}
		}
		else
		{
			try { spr.loadGraphic(Paths.image(asset)); }
			catch (e:Dynamic) {}
		}

		if (spr.graphic == null && spr.frames == null)
			spr.makeGraphic(100, 100, 0x88FFFFFF);

		// Register by name so the stage lua's getSprite-based dynamic logic finds it.
		playState.registerStageSprite(name, spr);
		return spr;
	}

	public function setupAnimation(spr:FlxSprite, entry:Dynamic):Void
	{
		var anim:Dynamic = (entry != null && Reflect.hasField(entry, "anim")) ? Reflect.field(entry, "anim") : null;
		if (anim == null || !(spr is FunkinSprite))
			return;

		var fa:FunkinSprite = cast spr;
		var kind:String = str(anim, "kind", "");
		var an:String = str(anim, "name", "anim");
		var arg:String = str(anim, "arg", an);
		var fps:Float = num(anim, "fps", 24);
		var loop:Bool = bool(anim, "loop");

		try
		{
			switch (kind)
			{
				case "prefix":
					fa.animation.addByPrefix(an, arg, Std.int(fps), loop);
					fa.animation.play(an);
				case "symbol" if (fa.isAnimate && fa.anim != null):
					fa.anim.addBySymbol(an, arg, fps, loop);
					fa.anim.play(an);
				case "timeline" if (fa.isAnimate && fa.anim != null):
					var tl = fa.anim.getDefaultTimeline();
					if (tl != null) { fa.anim.addByTimeline(an, tl, fps, loop); fa.anim.play(an, true); }
				default:
			}
		}
		catch (e:Dynamic) { trace('[StageLayoutScene] anim setup failed for "${fa.name}": ' + e); }
	}

	public function addToScene(spr:FlxSprite, name:String):Void
	{
		// Scenery sits below the characters (which PlayState added to the stage in createScene,
		// before this runs). Insert at incrementing indices to keep declared z-order among props.
		if (playState.stage != null)
			playState.stage.insert(zIndex++, spr);
	}

	public function createCharacter(slot:String, charName:String, enabled:Bool, entry:Dynamic):FlxSprite
		return null; // PlayState owns character creation/placement.

	public function addCharacterToScene(spr:FlxSprite, slot:String):Void {}

	// ---- small Reflect helpers ----
	static inline function rf(o:Dynamic, n:String):Dynamic
		return (o != null && Reflect.hasField(o, n)) ? Reflect.field(o, n) : null;

	static function str(o:Dynamic, n:String, def:String):String
	{
		var v = rf(o, n);
		return v != null ? Std.string(v) : def;
	}

	static function num(o:Dynamic, n:String, def:Float):Float
	{
		var v = rf(o, n);
		if (v == null) return def;
		var f:Float = cast v;
		return Math.isNaN(f) ? def : f;
	}

	static function bool(o:Dynamic, n:String):Bool
	{
		var v = rf(o, n);
		if (v == null) return false;
		if (Std.isOfType(v, Bool)) return cast v;
		if (Std.isOfType(v, Float)) return (cast v : Float) != 0;
		var s = Std.string(v).toLowerCase();
		return s == "true" || s == "1";
	}
}
