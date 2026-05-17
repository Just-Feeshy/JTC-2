package play.notes.adapter;

import play.notes.notestyle.NoteStyle;

/**
 * Minimal stand-in for Funkin's JSON-driven `NoteStyleRegistry`.
 * Two styles are hard-wired here; mods can register more at runtime via `register`.
 */
class NoteStyleRegistry
{
  static var styles:Map<String, NoteStyle> = new Map<String, NoteStyle>();
  static var initialized:Bool = false;

  public static function fetchDefault():NoteStyle
  {
    return fetchEntry('default');
  }

  public static function fetchEntry(id:String):NoteStyle
  {
    ensureInit();
    if (id == null || id == "") id = 'default';
    var s:NoteStyle = styles.get(id);
    if (s == null) s = styles.get('default');
    return s;
  }

  public static function register(style:NoteStyle):Void
  {
    if (style == null) return;
    ensureInit();
    styles.set(style.id, style);
  }

  static function ensureInit():Void
  {
    if (initialized) return;
    initialized = true;
    styles.set('default', new NoteStyle('default', 'NOTE_assets', 'regular/NOTE_assets', false));
    styles.set('pixel', new NoteStyle('pixel', 'pixelUI/arrows-pixels', 'pixel/NOTE_assets', true));
  }
}
