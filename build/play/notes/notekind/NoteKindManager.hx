package play.notes.notekind;

import play.notes.NoteSprite;
import play.notes.notestyle.NoteStyle;
import play.notes.adapter.NoteStyleRegistry;
import SustainTrail;

/**
 * Port of `funkin.play.notes.notekind.NoteKindManager`.
 *
 * Dispatch model (per design decision A=ii in the port plan):
 *   - If a `NoteKind` is registered under `note.kind`, only that kind's hook fires.
 *   - Otherwise the singleton `LegacyLuaNoteKind` catch-all fires — which forwards
 *     to JTC-2's existing `PlayLua` callbacks and `CustomNoteHandler` mods so old
 *     content keeps working.
 *
 * A specific kind can also opt out of any further dispatch by setting
 * `note.suppressLegacy = true` from its own hook (matters only if the model
 * is later flipped back to a chained dispatch).
 */
class NoteKindManager
{
  static var noteKinds:Map<String, NoteKind> = new Map<String, NoteKind>();
  static var legacyFallback:NoteKind = null;

  public static function register(kind:NoteKind):Void
  {
    if (kind == null) return;
    noteKinds.set(kind.noteKind, kind);
  }

  public static function getNoteKind(?name:String):Null<NoteKind>
  {
    if (name == null || name == "") return null;
    return noteKinds.get(name);
  }

  /**
   * Resolve a note style for a given kind. If `parentStyleId` is provided and
   * the kind's style id doesn't match it, we still return the kind's style —
   * Funkin's two-pass lookup is preserved at the call site in `Strumline`.
   */
  public static function getNoteStyle(?name:String, ?parentStyleId:String):Null<NoteStyle>
  {
    var kind:NoteKind = getNoteKind(name);
    if (kind == null || kind.noteStyleId == null) return null;
    return NoteStyleRegistry.fetchEntry(kind.noteStyleId);
  }

  // --- Dispatch ---

  public static function dispatchIncoming(note:NoteSprite):Void
  {
    if (note == null) return;
    var kind:NoteKind = getNoteKind(note.kind);
    if (kind != null) kind.onNoteIncoming(note);
    else ensureLegacy().onNoteIncoming(note);
  }

  public static function dispatchHit(note:NoteSprite, judgement:String):Void
  {
    if (note == null) return;
    var kind:NoteKind = getNoteKind(note.kind);
    if (kind != null) kind.onNoteHit(note, judgement);
    else if (!note.suppressLegacy) ensureLegacy().onNoteHit(note, judgement);
  }

  public static function dispatchMiss(note:NoteSprite):Void
  {
    if (note == null) return;
    var kind:NoteKind = getNoteKind(note.kind);
    if (kind != null) kind.onNoteMiss(note);
    else if (!note.suppressLegacy) ensureLegacy().onNoteMiss(note);
  }

  public static function dispatchHoldDrop(hold:SustainTrail):Void
  {
    if (hold == null) return;
    var kindName:String = hold.noteData != null ? hold.noteData.kind : null;
    var kind:NoteKind = getNoteKind(kindName);
    if (kind != null) kind.onNoteHoldDrop(hold);
    else ensureLegacy().onNoteHoldDrop(hold);
  }

  // --- Internals ---

  static function ensureLegacy():NoteKind
  {
    if (legacyFallback == null) legacyFallback = new LegacyLuaNoteKind();
    return legacyFallback;
  }
}
