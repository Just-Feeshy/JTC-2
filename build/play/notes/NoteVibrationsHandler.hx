package play.notes;

/**
 * Port of `funkin.play.notes.NoteVibrationsHandler`.
 *
 * Funkin uses this on mobile to drive haptic feedback. JTC-2 ships a no-op
 * `HapticUtil` (and doesn't target mobile yet), so the actual vibration calls
 * are guarded behind `#if FEATURE_HAPTICS`.
 *
 * `noteStatuses` is sized by `keyCount` so 5-key strumlines get a slot for SPACE.
 */
class NoteVibrationsHandler
{
  /** Per-direction note status. Indexed by lane (0..keyCount-1). */
  public var noteStatuses:Array<NoteStatus>;

  public function new(keyCount:Int = 4)
  {
    // `noteStatuses` is indexed by `NoteDirection` (sparse: LEFT=0..RIGHT=4),
    // so we always allocate 5 slots regardless of `keyCount`. SPACE=2 may
    // remain `idle` for 4-key strumlines.
    noteStatuses = [for (_ in 0...5) NoteStatus.idle];
  }

  public function tryNoteVibration():Void
  {
    #if FEATURE_HAPTICS
    // Mobile-only. JTC-2 has no haptic backend wired yet.
    #end
  }

  public function tryHoldNoteVibration(holdNoteEnded:Bool = false):Void
  {
    #if FEATURE_HAPTICS
    // Mobile-only. JTC-2 has no haptic backend wired yet.
    #end
  }
}

/**
 * Receptor state used by `NoteVibrationsHandler` and the player-input loop in `Strumline`.
 */
enum abstract NoteStatus(Int) from Int to Int
{
  var idle = 0;
  var pressed = 1;
  var confirm = 2;
  var holdConfirm = 3;
}
