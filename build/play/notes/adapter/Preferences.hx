package play.notes.adapter;

import flixel.FlxG;

/**
 * Funkin-shape `Preferences` shim used by the ported `Strumline` / notes code.
 * Reads from JTC-2's existing `FlxG.save.data.*` keys.
 */
class Preferences
{
  public static var downscroll(get, never):Bool;

  static inline function get_downscroll():Bool
  {
    return FlxG.save.data.helpme == true;
  }

  /** JTC-2 does not render a strumline background by default. */
  public static var strumlineBackgroundOpacity(get, never):Int;

  static inline function get_strumlineBackgroundOpacity():Int
  {
    return 0;
  }

  /** Reserved for mobile control schemes — JTC-2 is keyboard-only for now. */
  public static var controlsScheme(get, never):Int;

  static inline function get_controlsScheme():Int
  {
    return 0;
  }
}
