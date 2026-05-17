package util;

import play.notes.NoteSprite;
import Conductor;

typedef HitWindow =
{
  public var start:Float;
  public var center:Float;
  public var end:Float;
}

typedef HitWindowRes =
{
  public var botplayHit:Bool;
  public var cont:Bool;
}

/**
 * Port of `funkin.util.GRhythmUtil`. Used by `Strumline` for hit-window
 * processing and y-position calculations.
 *
 * The `mirrorNoteDirection` overload accepts an explicit keyCount because
 * JTC-2 instance-ifies KEY_COUNT on `Strumline` to support 5-key strumlines.
 */
class GRhythmUtil
{
  public static function mirrorNoteDirection(noteData:Int, keyCount:Int = 4):Int
  {
    final maxKeyValue:Int = (noteData < keyCount ? keyCount : keyCount * 2);
    return (maxKeyValue - 1) - (noteData % keyCount);
  }

  public static function getHitWindow(note:NoteSprite):HitWindow
  {
    return {
      start: note.strumTime - Constants.HIT_WINDOW_MS,
      center: note.strumTime,
      end: note.strumTime + Constants.HIT_WINDOW_MS
    };
  }

  public static function processWindow(note:NoteSprite, isControlled:Bool = true, ?inUseConductor:Conductor = null):HitWindowRes
  {
    if (inUseConductor == null) inUseConductor = Conductor.instance;

    var window:HitWindow = getHitWindow(note);
    var windowStart:Float = window.start;
    var windowCenter:Float = window.center;
    var windowEnd:Float = window.end;

    if (note.hasMissed || note.hasBeenHit)
    {
      return {botplayHit: false, cont: false};
    }

    if (inUseConductor.songPosition > windowEnd)
    {
      note.tooEarly = false;
      note.hasMissed = true;
      note.mayHit = false;
      if (note.holdNoteSprite != null) note.holdNoteSprite.missedNote = true;
      return {botplayHit: false, cont: true};
    }

    if (!isControlled && inUseConductor.songPosition >= windowCenter) return {botplayHit: true, cont: true};

    if (note.holdNoteSprite != null) note.holdNoteSprite.missedNote = false;

    if (inUseConductor.songPosition >= windowStart)
    {
      note.tooEarly = false;
      note.hasMissed = false;
      note.mayHit = true;
      return {botplayHit: false, cont: true};
    }

    note.tooEarly = true;
    note.mayHit = false;
    note.hasMissed = false;

    return {botplayHit: false, cont: true};
  }

  public static function getNoteY(strumTime:Float, scrollSpeed:Float, downscroll:Bool = false, ?conductorInUse:Conductor = null):Float
  {
    if (conductorInUse == null) conductorInUse = Conductor.instance;
    return Constants.PIXELS_PER_MS * (conductorInUse.getTimeWithDelta() - strumTime) * scrollSpeed * (downscroll ? 1 : -1);
  }
}
