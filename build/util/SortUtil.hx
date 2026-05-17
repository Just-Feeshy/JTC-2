package util;

import flixel.graphics.frames.FlxFrame;
#if !macro
import flixel.util.FlxSort;
#end
import play.notes.NoteSprite;
import play.notes.adapter.SongNoteData;

/**
 * Port of `funkin.util.SortUtil`, adapted for JTC-2's local packages.
 *
 * Funkin's `byZIndex` was dropped here: stock Flixel doesn't expose a `zIndex`
 * field on `FlxBasic` / `FlxTypedSpriteGroup`. The ported `Strumline` instead
 * layers its children by add-order — see the ctor comment.
 */
class SortUtil
{
  public static inline function byStrumtime(order:Int, a:NoteSprite, b:NoteSprite):Int
  {
    return noteDataByTime(order, a.noteData, b.noteData);
  }

  public static inline function noteDataByTime(order:Int, a:SongNoteData, b:SongNoteData):Int
  {
    return FlxSort.byValues(order, a.time, b.time);
  }

  public static inline function byFrameName(a:FlxFrame, b:FlxFrame):Int
  {
    return alphabetically(a.name, b.name);
  }

  public static function alphabetically(a:String, b:String):Int
  {
    a = a.toUpperCase();
    b = b.toUpperCase();
    return a == b ? 0 : a > b ? 1 : -1;
  }

  public static function defaultThenAlphabetically(defaultValue:String, a:String, b:String):Int
  {
    if (a == b) return 0;
    if (a == defaultValue) return -1;
    if (b == defaultValue) return 1;
    return alphabetically(a, b);
  }

  public static function defaultsThenAlphabetically(defaultValues:Array<String>, a:String, b:String):Int
  {
    if (a == b) return 0;
    if (defaultValues.contains(a) && defaultValues.contains(b))
    {
      return defaultValues.indexOf(a) - defaultValues.indexOf(b);
    };
    if (defaultValues.contains(a)) return -1;
    if (defaultValues.contains(b)) return 1;
    return alphabetically(a, b);
  }
}
