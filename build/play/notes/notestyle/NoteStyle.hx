package play.notes.notestyle;

import flixel.graphics.frames.FlxAtlasFrames;
import play.notes.NoteDirection;
import play.notes.NoteSprite;
import play.notes.StrumlineNote;
import play.notes.NoteSplash;
import play.notes.NoteHoldCover;

using StringTools;

/**
 * JTC-2 adapter for `funkin.play.notes.notestyle.NoteStyle`.
 *
 * Funkin's NoteStyle is JSON-driven (~1150 lines). JTC-2 doesn't have that
 * registry yet, so this adapter exposes the same call surface but routes to
 * JTC-2's `Paths`, `Register`, and existing atlas-prefix conventions.
 *
 * Two concrete styles are wired up in `play.notes.adapter.NoteStyleRegistry`:
 *   - `"default"` — `NOTE_assets` Sparrow atlas
 *   - `"pixel"`   — pixel notes
 *
 * Most of these methods are no-ops or simple value-returners in commit 2 —
 * commit 3 fills in the actual sprite-frame application when `StrumlineNote`,
 * `NoteSprite`, `NoteSplash`, and `NoteHoldCover` are properly ported.
 */
class NoteStyle
{
  public final id:String;

  /** Tunable params, keyed by the same names Funkin's JSON registry uses. */
  public var params:Map<String, Dynamic>;

  /** Atlas key passed to `Paths.getSparrowAtlas`. */
  public var noteAssetKey:String;

  /**
   * Atlas key passed to `HoldNoteStrip.build` / `Paths.getNoteAtlas` for
   * sustain trails. Differs from `noteAssetKey` because hold strips live
   * under `assets/shared/images/notes/<this>.xml` (e.g.
   * `notes/regular/NOTE_assets.xml`).
   */
  public var holdNoteAssetKey:String;

  /** Whether this style uses nearest-neighbor (pixel) filtering. */
  public var pixel:Bool;

  public function new(id:String, noteAssetKey:String, ?holdNoteAssetKey:String, pixel:Bool = false)
  {
    this.id = id;
    this.noteAssetKey = noteAssetKey;
    this.holdNoteAssetKey = holdNoteAssetKey ?? "regular/NOTE_assets";
    this.pixel = pixel;
    this.params = new Map<String, Dynamic>();
  }

  // --- Note sprite ---

  public function buildNoteSprite(target:NoteSprite):Void
  {
    if (target == null) return;
    var frames:FlxAtlasFrames = Paths.getSparrowAtlas(noteAssetKey, null, true);
    if (frames == null) return;
    target.frames = frames;
    target.antialiasing = !pixel;

    // Wire `*Scroll` animations that NoteSprite.playNoteAnimation looks up. The
    // prefixes mirror `Note.setupPrefixes` in the legacy path so the same atlas
    // works without modification.
    target.animation.addByPrefix('purpleScroll', 'purple0', 24, false);
    target.animation.addByPrefix('blueScroll', 'blue0', 24, false);
    target.animation.addByPrefix('diamondScroll', 'diamond0', 24, false);
    target.animation.addByPrefix('greenScroll', 'green0', 24, false);
    target.animation.addByPrefix('redScroll', 'red0', 24, false);

    target.scale.set(getNoteScale(), getNoteScale());
    target.updateHitbox();
  }

  public function isNoteAnimated():Bool return true;

  public function getNoteScale():Float return pixel ? 6.0 : 0.7;

  public function getNoteOffsets():Array<Float> return [0, 0];

  // --- Hold note (sustain trail) ---

  public function getHoldNoteAssetPath(raw:Bool = false):Null<String>
  {
    // Raw form is the key `HoldNoteStrip.build` / `Paths.getNoteAtlas` want
    // (it prepends `notes/`); decorated form is the full XML path under
    // `assets/shared/images/`.
    return raw ? holdNoteAssetKey : 'notes/$holdNoteAssetKey';
  }

  public function isHoldNotePixel():Bool return pixel;

  public function fetchHoldNoteScale():Float return getNoteScale();

  public function getHoldNoteOffsets():Array<Float> return [0, 0];

  // --- Strumline (receptor) ---

  public function applyStrumlineFrames(target:StrumlineNote):Void
  {
    if (target == null) return;
    var frames:FlxAtlasFrames = Paths.getSparrowAtlas(noteAssetKey, null, true);
    if (frames != null) target.frames = frames;
    target.antialiasing = !pixel;
  }

  /**
   * Wire `static` / `pressed` / `confirm` / `confirm-hold` animations onto a receptor.
   * Mirrors the `getModernPrefix` + fallback logic from `build/Strum.hx`.
   */
  public function applyStrumlineAnimations(target:StrumlineNote, dir:NoteDirection):Void
  {
    if (target == null) return;

    var suffix:String = switch ((dir : Int))
    {
      case NoteDirection.LEFT: 'Left';
      case NoteDirection.DOWN: 'Down';
      case NoteDirection.UP: 'Up';
      case NoteDirection.RIGHT: 'Right';
      case NoteDirection.SPACE: 'Space';
      default: '';
    }
    var directionLower:String = dir.name;

    addAnimWithFallback(target, 'static', [
      'static' + suffix,
      'arrow' + directionLower.toUpperCase(),
      directionLower + ' static',
      directionLower + ' press'
    ]);
    addAnimWithFallback(target, 'pressed', [
      'press' + suffix,
      directionLower + ' press',
      'arrow' + directionLower.toUpperCase() + ' press'
    ]);
    addAnimWithFallback(target, 'confirm', [
      'confirm' + suffix,
      directionLower + ' confirm0',
      directionLower + ' confirm'
    ]);
    addAnimWithFallback(target, 'confirm-hold', [
      'confirmHold' + suffix,
      'confirm' + suffix,
      directionLower + ' confirm0',
      directionLower + ' confirm'
    ]);
  }

  function addAnimWithFallback(target:StrumlineNote, name:String, prefixes:Array<String>):Void
  {
    if (target.frames == null || target.frames.frames == null) return;
    for (prefix in prefixes)
    {
      if (atlasHasPrefix(target, prefix))
      {
        target.animation.addByPrefix(name, prefix, 24, false);
        return;
      }
      // Funkin atlases sometimes prefix frames with a leading space.
      if (atlasHasPrefix(target, ' ' + prefix))
      {
        target.animation.addByPrefix(name, ' ' + prefix, 24, false);
        return;
      }
    }
  }

  static function atlasHasPrefix(target:StrumlineNote, prefix:String):Bool
  {
    if (prefix == null || target.frames == null) return false;
    for (frame in target.frames.frames)
    {
      if (frame != null && frame.name != null && frame.name.startsWith(prefix)) return true;
    }
    return false;
  }

  public function getStrumlineOffsets():Array<Float> return [0, 0];

  public function applyStrumlineOffsets(target:StrumlineNote):Void
  {
    if (target == null) return;
    var off:Array<Float> = getStrumlineOffsets();
    target.x += off[0];
    target.y += off[1];
  }

  public function getStrumlineScale():Float return getNoteScale();

  public function isNoteSplashEnabled():Bool return true;

  public function isHoldNoteCoverEnabled():Bool return true;

  // --- Splash ---

  public function buildSplashSprite(target:NoteSplash):Void
  {
    if (target == null) return;
    var frames:FlxAtlasFrames = Paths.getNoteAtlas('regular/splash');
    if (frames == null) return;
    target.frames = frames;
    target.antialiasing = !pixel;

    // Map atlas prefixes from JTC-2's regular/splash.xml to the names NoteSplash expects:
    //   `splash${nameUpper}${variant}` — e.g. splashLEFT0, splashSPACE0
    addSplashAnims(target, 'LEFT', 'left splash');
    addSplashAnims(target, 'DOWN', 'down splash');
    addSplashAnims(target, 'UP', 'up splash');
    addSplashAnims(target, 'RIGHT', 'right splash');
    addSplashAnims(target, 'SPACE', 'reverse splash');
  }

  static function addSplashAnims(target:NoteSplash, dirUpper:String, atlasPrefix:String):Void
  {
    // Match Funkin's splash variant model: try numbered (`splashLEFT0`, `splashLEFT1`)
    // first, fall back to a single un-numbered animation.
    var addedAny:Bool = false;
    for (variant in 0...4)
    {
      var prefix:String = atlasPrefix + variant;
      if (atlasHasPrefixNamed(target, prefix))
      {
        target.animation.addByPrefix('splash$dirUpper$variant', prefix, 24, false);
        addedAny = true;
      }
    }
    if (!addedAny && atlasHasPrefixNamed(target, atlasPrefix))
    {
      target.animation.addByPrefix('splash${dirUpper}0', atlasPrefix, 24, false);
    }
  }

  static function atlasHasPrefixNamed(target:flixel.FlxSprite, prefix:String):Bool
  {
    if (target.frames == null) return false;
    for (frame in target.frames.frames)
    {
      if (frame != null && frame.name != null && frame.name.startsWith(prefix)) return true;
    }
    return false;
  }

  public function getSplashScale():Float return pixel ? 6.0 : 1.0;

  public function getSplashOffsets():Array<Float> return [0, 0];

  public function getSplashFramerate():Int return 24;

  public function getSplashFramerateVariance():Int return 2;

  // --- Hold cover ---

  public function buildHoldCoverSprite(target:NoteHoldCover):Void
  {
    if (target == null) return;
    // Cover frames are direction-specific in JTC-2 (`holdCoverPurple`/Blue/Green/Red/Diamond).
    // The actual loading happens per-cover in commit 3 when NoteHoldCover is fleshed out.
    target.antialiasing = !pixel;
  }

  public function getHoldCoverOffsets():Array<Float> return [0, 0];

  public function getHoldCoverDirectionAssetPath(direction:NoteDirection, raw:Bool = false):Null<String>
  {
    var color:String = direction.colorName;
    var key:String = 'holdCover' + capitalize(color);
    return raw ? key : key;
  }

  static inline function capitalize(s:String):String
  {
    return s == null || s.length == 0 ? s : s.charAt(0).toUpperCase() + s.substr(1);
  }

  // --- Misc ---

  public function getFallbackID():Null<String> return id == 'default' ? null : 'default';

  public function toString():String return 'NoteStyle($id)';
}
