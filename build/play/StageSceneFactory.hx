package play;

import flixel.FlxSprite;

/**
 * Per-context sprite/character creation for `StageLayoutScene`. The editor implements this with
 * `funkin.game.*` objects; gameplay implements it with engine sprites + `Character`. The shared
 * builder calls these in a fixed order and applies the position/scale/scroll transforms itself, so
 * all placement math lives in one place and both contexts end up identical.
 */
interface StageSceneFactory
{
	/** Create the prop sprite for a `sprites` entry (plain / sparrow=true / animate=true). No transforms yet. */
	function createSprite(entry:Dynamic):FlxSprite;

	/** Add + play the entry's initial `anim` (if any) BEFORE the shared scale/updateHitbox runs. */
	function setupAnimation(spr:FlxSprite, entry:Dynamic):Void;

	/** Add the finished prop to the scene; call order defines z-order (later = on top). */
	function addToScene(spr:FlxSprite, name:String):Void;

	/** Create the character for a slot ("dad"/"boyfriend"/"girlfriend"). No transforms yet. */
	function createCharacter(slot:String, charName:String, enabled:Bool, entry:Dynamic):FlxSprite;

	/** Add the placed character to the scene. */
	function addCharacterToScene(spr:FlxSprite, slot:String):Void;
}
