package play.notes.notekind;

import play.notes.NoteSprite;
import SustainTrail;

/**
 * Catch-all `NoteKind` that bridges to JTC-2's pre-port modding surface:
 *   - `PlayLua` script callbacks (`goodNoteHit`, `noteMiss`, `opponentNoteHit`)
 *   - `CustomNoteHandler` / `ICustomNote` legacy notes (via `Note.hasCustomAddon`)
 *
 * Per the port plan, this fires only when no specific `NoteKind` is registered
 * for the note's `kind` — so adopting a real `NoteKind` automatically opts that
 * kind out of the legacy bridge (avoiding double-mutation of score/health).
 *
 * `NoteSprite.legacyNote` holds the original `Note` when present, which is how
 * we recover the full `playLua.call(...)` argument shape (`caculatePos`, `tag`,
 * `noteAbstract`, `isSustainNote`).
 */
@:access(PlayState)
class LegacyLuaNoteKind extends NoteKind
{
  public function new()
  {
    super("__legacy_lua__", null);
    this.scoreable = true;
  }

  override public function onNoteIncoming(note:NoteSprite):Void
  {
    callLua("onNoteIncoming", legacyArgs(note));
  }

  override public function onNoteHit(note:NoteSprite, judgement:String):Void
  {
    var args:Array<Dynamic> = legacyArgs(note);
    // Append judgement so existing scripts that want the rating can read it.
    args.push(judgement);
    callLua("goodNoteHit", args);

    // Fire the ICustomNote hook on the legacy note, if any.
    if (note.legacyNote != null && note.legacyNote.hasCustomAddon != null)
    {
      // `whenNoteIsHit(strumNote)` — strumNote is the receptor `Strum`. The new
      // strumline doesn't expose a `Strum`, so pass null; ICustomNote impls that
      // need the receptor must be migrated to a real `NoteKind`.
      try
      {
        note.legacyNote.hasCustomAddon.whenNoteIsHit(null);
      }
      catch (e:Dynamic) {}
    }
  }

  override public function onNoteMiss(note:NoteSprite):Void
  {
    callLua("noteMiss", legacyArgs(note));
  }

  override public function onNoteHoldDrop(holdNote:SustainTrail):Void
  {
    if (holdNote == null) return;
    callLua("noteHoldDrop", [holdNote.noteDirection, holdNote.strumTime]);
  }

  // --- helpers ---

  static inline function callLua(name:String, args:Array<Dynamic>):Void
  {
    if (PlayState.instance == null) return;
    var lua = PlayState.instance.playLua;
    if (lua == null) return;
    try
    {
      lua.call(name, args);
    }
    catch (e:Dynamic) {}
  }

  /**
   * Build the standard JTC-2 Lua note-hook argument list:
   * `[caculatePos, strumTime, lane, tag, noteAbstract, isSustainNote]`.
   *
   * When `legacyNote` is set we use its fields verbatim (matches the existing
   * call shape in PlayState before the refactor); otherwise we synthesize from
   * the NoteSprite + SongNoteData.
   */
  static function legacyArgs(note:NoteSprite):Array<Dynamic>
  {
    var lane:Int = note.noteData != null ? note.noteData.data : (note.direction : Int);
    var kindStr:String = (note.kind == null || note.kind == "") ? "regular" : note.kind;

    if (note.legacyNote != null)
    {
      var ln:Note = note.legacyNote;
      return [ln.caculatePos, ln.strumTime, ln.noteData, ln.tag, ln.noteAbstract, ln.isSustainNote];
    }
    return [note.y, note.strumTime, lane, "", kindStr, note.holdNoteSprite != null];
  }
}
