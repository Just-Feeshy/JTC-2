package play.notes;

import flixel.FlxSprite;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.utils.AssetType;
import play.notes.notestyle.NoteStyle;

using StringTools;

/**
 * Port of `funkin.play.notes.NoteHoldCover`, adapted for JTC-2's
 * per-color hold cover atlases (`holdCoverPurple`, `holdCoverBlue`, etc.).
 *
 * Funkin puts all four colors in one atlas with named animations; JTC-2
 * has separate XMLs per direction. This wrapper loads the per-direction
 * atlas lazily the first time `playStart` is called for a given direction,
 * and caches frames after that.
 */
class NoteHoldCover extends FlxSprite
{
  public var noteStyle:NoteStyle;
  public var holdNote:SustainTrail = null;

  /** The direction whose frames are currently loaded into `this.frames`. */
  var loadedDirection:Null<NoteDirection> = null;

  /** Per-direction frame cache so repeated holds don't re-decode the XML. */
  var frameCache:Map<Int, FlxAtlasFrames> = new Map<Int, FlxAtlasFrames>();

  public function new(noteStyle:NoteStyle)
  {
    super(0, 0);
    this.noteStyle = noteStyle;
    this.antialiasing = true;
    this.visible = false;
    kill();

    this.animation.onFinish.add(onAnimationFinished);
  }

  public function playStart():Void
  {
    if (holdNote == null) return;
    if (!ensureFramesFor(holdNote.noteDirection)) return;

    var colorName:String = getColorTitleCase(holdNote.noteDirection);
    revive();
    this.visible = true;
    this.alpha = 1.0;
    setPosition(holdNote.x, holdNote.y);

    if (animation.getByName('holdCoverStart$colorName') != null)
    {
      animation.play('holdCoverStart$colorName', true);
    }
  }

  public function playContinue():Void
  {
    if (holdNote == null) return;
    var colorName:String = getColorTitleCase(holdNote.noteDirection);
    if (animation.getByName('holdCover$colorName') != null)
    {
      animation.play('holdCover$colorName', true);
    }
  }

  public function playEnd():Void
  {
    if (holdNote == null) return;
    var colorName:String = getColorTitleCase(holdNote.noteDirection);
    if (animation.getByName('holdCoverEnd$colorName') != null)
    {
      animation.play('holdCoverEnd$colorName', true);
    }
  }

  override public function kill():Void
  {
    super.kill();
    this.visible = false;
    if (holdNote != null) holdNote.cover = null;
    holdNote = null;
  }

  override public function revive():Void
  {
    super.revive();
    this.visible = true;
    this.alpha = 1.0;
  }

  function onAnimationFinished(animationName:String):Void
  {
    if (animationName.startsWith('holdCoverStart'))
    {
      playContinue();
    }
    else if (animationName.startsWith('holdCoverEnd'))
    {
      this.visible = false;
      this.kill();
    }
  }

  function ensureFramesFor(direction:NoteDirection):Bool
  {
    if (loadedDirection == direction && this.frames != null) return true;

    var dirKey:Int = (direction : Int);
    var cached:FlxAtlasFrames = frameCache.get(dirKey);
    if (cached != null)
    {
      this.frames = cached;
      this.loadedDirection = direction;
      return true;
    }

    var colorName:String = getColorTitleCase(direction);
    var atlasKey:String = 'holdCover$colorName';
    var descriptionPath:String = Paths.file('images/' + atlasKey + '.xml', TEXT, "shared");
    if (!Paths.assetExists(descriptionPath, AssetType.TEXT)) return false;

    var loaded:FlxAtlasFrames = Paths.getSparrowAtlas(atlasKey, "shared");
    if (loaded == null) return false;

    this.frames = loaded;
    this.loadedDirection = direction;
    frameCache.set(dirKey, loaded);

    animation.addByPrefix('holdCoverStart$colorName', 'holdCoverStart$colorName', 24, false);
    animation.addByPrefix('holdCover$colorName', 'holdCover$colorName', 24, true);
    animation.addByPrefix('holdCoverEnd$colorName', 'holdCoverEnd$colorName', 24, false);

    return true;
  }

  static inline function getColorTitleCase(direction:NoteDirection):String
  {
    var c:String = direction.colorName;
    if (c == null || c.length == 0) return c;
    return c.charAt(0).toUpperCase() + c.substr(1);
  }
}
