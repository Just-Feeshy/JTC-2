package play.notes.notekind;

import play.notes.NoteSprite;
import SustainTrail;

/**
 * Port of `funkin.play.notes.notekind.NoteKind`, trimmed of Hscript scripting.
 *
 * A NoteKind defines per-kind behavior (visuals, scoring, hooks) for a chart
 * note whose `kind` string matches `this.noteKind`. Register kinds at startup
 * via `NoteKindManager.register(...)`.
 *
 * For backward compat with JTC-2's existing Lua hooks and `CustomNoteHandler`
 * mods, the manager falls back to a `LegacyLuaNoteKind` catch-all whenever no
 * specific kind matches — see `NoteKindManager.dispatchHit`.
 */
class NoteKind
{
  /** Identifier matching `SongNoteData.kind` (and `NoteSprite.kind`). */
  public var noteKind:String;

  /** Optional human-readable description (for editor UIs). */
  public var description:String = "";

  /** Note style this kind prefers. `null` means "use the strumline's style". */
  public var noteStyleId:Null<String> = null;

  /** If `false`, the note doesn't contribute to ratings/score/accuracy. */
  public var scoreable:Bool = true;

  public function new(noteKind:String, ?noteStyleId:String)
  {
    this.noteKind = noteKind;
    this.noteStyleId = noteStyleId;
  }

  /** Fired as the note enters the strumline's render window. */
  public function onNoteIncoming(note:NoteSprite):Void {}

  /** Fired when the player (or bot) successfully hits the note. */
  public function onNoteHit(note:NoteSprite, judgement:String):Void {}

  /** Fired when the note times out without being hit. */
  public function onNoteMiss(note:NoteSprite):Void {}

  /** Fired when the player lets go of a hold note early. */
  public function onNoteHoldDrop(holdNote:SustainTrail):Void {}
}
