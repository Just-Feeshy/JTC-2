package play.notes.adapter;

/**
 * Lightweight stand-in for `funkin.data.song.SongData.SongNoteData`.
 * The ported `NoteSprite` / `Strumline` / `SustainTrail` only touch a handful of
 * fields, so we keep this minimal and convert from JTC-2's legacy `Note` on demand.
 *
 * @see fromLegacy
 */
class SongNoteData
{
  /** Strum time in milliseconds. */
  public var time:Float;

  /** Raw lane index from the chart (0..3 for 4-key, 0..4 for 5-key). */
  public var data:Int;

  /** Sustain length in milliseconds. 0 for tap notes. */
  public var length:Float;

  /** Note kind id. Empty string and "default" / "normal" mean "regular". */
  public var kind:String;

  /** Free-form params bag — mirrors Funkin's `Array<NoteParamData>` but as a String map. */
  public var params:Map<String, Dynamic>;

  public function new(time:Float = 0, data:Int = 0, length:Float = 0, kind:String = "", ?params:Map<String, Dynamic>)
  {
    this.time = time;
    this.data = data;
    this.length = length;
    this.kind = kind;
    this.params = params ?? new Map<String, Dynamic>();
  }

  /**
   * Resolve the chart's raw lane index into a `NoteDirection`.
   * In 4-key mode, lane 4 falls back to RIGHT.
   */
  public inline function getDirection(fifthKey:Bool = false):NoteDirection
  {
    return NoteDirection.fromLane(data, fifthKey);
  }

  public inline function getStrumTime():Float return time;

  public inline function getKind():String return kind;

  public function clone():SongNoteData
  {
    return new SongNoteData(time, data, length, kind, params == null ? null : params.copy());
  }

  public function toString():String
  {
    return 'SongNoteData(t=$time, lane=$data, len=$length, kind="$kind")';
  }

  /**
   * Build a `SongNoteData` from a JTC-2 legacy `Note`.
   * Sustain *segments* are skipped — they're represented by `length` on the head note.
   */
  public static function fromLegacy(note:Note):SongNoteData
  {
    if (note == null) return null;

    var kind:String = note.noteAbstract;
    if (kind == null || kind == "regular" || kind == "default" || kind == "normal") kind = "";

    return new SongNoteData(note.strumTime, note.noteData, note.sustainLength, kind);
  }
}
