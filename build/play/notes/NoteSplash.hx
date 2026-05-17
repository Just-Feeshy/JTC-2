package play.notes;

import flixel.FlxG;
import flixel.FlxSprite;
import play.notes.notestyle.NoteStyle;

using StringTools;

/**
 * Port of `funkin.play.notes.NoteSplash`.
 *
 * Funkin expects all per-direction splash animations to live on one sprite,
 * named `splash${nameUpper}${variant}` (e.g. `splashLEFT0`, `splashSPACE0`).
 * JTC-2's existing `regular/splash.xml` provides the underlying frames;
 * `NoteStyle.buildSplashSprite` is responsible for naming the animations
 * the way this class expects.
 */
class NoteSplash extends FlxSprite
{
  public var splashFramerate:Int = 24;
  public var splashFramerateVariance:Int = 2;

  public function new(noteStyle:NoteStyle)
  {
    super(0, 0);

    setupSplashGraphic(noteStyle);

    this.animation.onFinish.add(this.onAnimationFinished);
  }

  function setupSplashGraphic(noteStyle:NoteStyle):Void
  {
    if (frames == null) noteStyle.buildSplashSprite(this);
  }

  public function playAnimation(name:String, force:Bool = false, reversed:Bool = false, startFrame:Int = 0):Void
  {
    this.animation.play(name, force, reversed, startFrame);
  }

  /**
   * Play the splash for a direction. Picks a random `splash${nameUpper}${variant}`
   * variant if `variant` is null.
   */
  public function play(direction:NoteDirection, ?variant:Null<Int>):Void
  {
    var prefix:String = 'splash${direction.nameUpper}';
    if (variant == null)
    {
      var count:Int = animation.getAnimationList().filter(function(anim) return anim.name.startsWith(prefix)).length - 1;
      variant = count <= 0 ? 0 : FlxG.random.int(0, count);
    }

    this.playAnimation('${prefix}${variant}');

    if (animation.curAnim == null) return;

    animation.curAnim.frameRate = splashFramerate + FlxG.random.int(-splashFramerateVariance, splashFramerateVariance);

    offset.set(width * 0.3, height * 0.3);
  }

  function onAnimationFinished(animationName:String):Void
  {
    this.kill();
  }
}
