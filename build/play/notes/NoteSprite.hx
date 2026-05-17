package play.notes;

import play.notes.adapter.SongNoteData;
import play.notes.notestyle.NoteStyle;

/**
 * Port of `funkin.play.notes.NoteSprite`.
 *
 * JTC-2 differences vs upstream:
 *   - Extends `FunkinSprite` (which is FlxSprite + a few anim helpers).
 *   - `HSVShader` is not available; `desaturate()` / `setHue()` fall back to alpha.
 *   - `params` is a `Map<String, Dynamic>` (see `SongNoteData`) instead of `Array<NoteParamData>`.
 *   - `DIRECTION_COLORS` includes `diamond` for the 5th key (SPACE).
 */
class NoteSprite extends FunkinSprite
{
  static final DIRECTION_COLORS:Array<String> = ['purple', 'blue', 'diamond', 'green', 'red'];

  /** The hold-note trail bound to this head, or null for tap notes. */
  public var holdNoteSprite:SustainTrail;

  public var strumTime(get, set):Float;

  function get_strumTime():Float return this.noteData != null ? this.noteData.time : 0.0;
  function set_strumTime(value:Float):Float
  {
    if (this.noteData == null) return value;
    return this.noteData.time = value;
  }

  /** Sustain length in ms (0 for taps). */
  public var length(get, set):Float;

  function get_length():Float return this.noteData != null ? this.noteData.length : 0.0;
  function set_length(value:Float):Float
  {
    if (this.noteData == null) return value;
    return this.noteData.length = value;
  }

  public var kind(get, set):Null<String>;

  function get_kind():Null<String> return this.noteData != null ? this.noteData.kind : null;
  function set_kind(value:String):String
  {
    if (this.noteData == null) return value;
    return this.noteData.kind = value;
  }

  /** Free-form note params bag. Backed by `SongNoteData.params`. */
  public var params(get, set):Map<String, Dynamic>;

  function get_params():Map<String, Dynamic> return this.noteData != null ? this.noteData.params : new Map<String, Dynamic>();
  function set_params(value:Map<String, Dynamic>):Map<String, Dynamic>
  {
    if (this.noteData == null) return value;
    return this.noteData.params = value;
  }

  public var direction(default, set):NoteDirection;

  function set_direction(value:Int):Int
  {
    if (frames == null)
    {
      this.direction = value;
      return this.direction;
    }
    playNoteAnimation(value);
    this.direction = value;
    return this.direction;
  }

  public var noteData:SongNoteData;

  /** `false` disables scoring (no ratings/points/accuracy). */
  public var scoreable:Bool = true;

  public var isHoldNote(get, never):Bool;
  function get_isHoldNote():Bool return noteData != null && noteData.length > 0;

  public var yOffset:Float = 0.0;

  public var hasBeenHit:Bool = false;
  public var lowPriority:Bool = false;
  public var hasMissed:Bool = false;
  public var tooEarly:Bool = true;
  public var mayHit:Bool = false;
  public var handledMiss:Bool = false;

  /**
   * Suppresses the `LegacyLuaNoteKind` fallback hook for this specific note.
   * Set by a concrete `NoteKind.onNoteHit` that doesn't want Lua double-applying.
   */
  public var suppressLegacy:Bool = false;

  /**
   * The legacy `Note` this sprite was built from, if any. PlayState sets this during
   * chart load so `LegacyLuaNoteKind` can forward to Lua callbacks with the original
   * argument shape (`caculatePos`, `tag`, `noteAbstract`, etc.).
   */
  public var legacyNote:Null<Note> = null;

  public function new(noteStyle:NoteStyle, direction:Int = 0)
  {
    super(0, -9999);
    this.noteData = new SongNoteData(0, direction);
    this.direction = direction;
    this.alpha = 1;
    setupNoteGraphic(noteStyle);
  }

  /** Build frames + animations from the active `NoteStyle`. */
  public function setupNoteGraphic(noteStyle:NoteStyle):Void
  {
    noteStyle.buildNoteSprite(this);

    // For static (non-animated) styles, disable update() for perf.
    this.active = noteStyle.isNoteAnimated();

    // Bind direction-specific scroll animation if it exists.
    if (frames != null) playNoteAnimation(this.direction);
  }

  public function getParam(name:String):Null<Dynamic>
  {
    return params != null ? params.get(name) : null;
  }

  function playNoteAnimation(value:Int):Void
  {
    if (value < 0 || value >= DIRECTION_COLORS.length) return;
    var animName:String = DIRECTION_COLORS[value] + 'Scroll';
    if (animation != null && animation.getByName(animName) != null)
    {
      animation.play(animName);
    }
  }

  /** Visual indicator that this note is "dead" — fades alpha. */
  public function desaturate():Void
  {
    this.alpha = 0.6;
  }

  /** No-op on JTC-2 (no HSVShader). Kept for API parity with Funkin. */
  public function setHue(hue:Float):Void {}

  override public function revive():Void
  {
    super.revive();
    this.visible = true;
    this.alpha = 1.0;
    this.active = false;
    this.tooEarly = false;
    this.hasBeenHit = false;
    this.mayHit = false;
    this.hasMissed = false;
    this.handledMiss = false;
    this.holdNoteSprite = null;
    this.shader = null;
  }
}
