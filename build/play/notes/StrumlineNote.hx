package play.notes;

import play.notes.notestyle.NoteStyle;

using StringTools;

/**
 * Port of `funkin.play.notes.StrumlineNote` — the receptor sprite on the strumline.
 *
 * Adapted from Funkin: extends JTC-2's `FunkinSprite` (which we extended with
 * `getCurrentAnimation` / `isAnimationDynamic` / `isAnimationFinished`).
 */
class StrumlineNote extends FunkinSprite
{
  public var isPlayer(default, null):Bool;

  public var direction(default, set):NoteDirection;

  function set_direction(value:NoteDirection):NoteDirection
  {
    this.direction = value;
    return this.direction;
  }

  /** Y offset applied during scroll layout. */
  public var yOffset:Float = 0.0;

  /**
   * Set to `true` to keep this sprite ticking even when its animation has no
   * dynamic frames (e.g. for sprites with custom `update` logic).
   */
  public var forceActive:Bool = false;

  static final CONFIRM_HOLD_TIME:Float = 0.15;

  /** How long the `confirm` animation has been playing on this receptor, in seconds. */
  var confirmHoldTimer:Float = -1;

  public function new(noteStyle:NoteStyle, isPlayer:Bool, direction:NoteDirection)
  {
    super(0, 0);

    this.isPlayer = isPlayer;
    this.direction = direction;

    setup(noteStyle);

    this.animation.onFrameChange.add(onAnimationFrame);
    this.animation.onFinish.add(onAnimationFinished);

    this.active = true;
  }

  function onAnimationFrame(name:String, frameNumber:Int, frameIndex:Int):Void {}

  function onAnimationFinished(name:String):Void
  {
    // On player, holding the confirm key falls back to press once `confirm` finishes.
    if (isPlayer && name == 'confirm') confirmHoldTimer = 0;
  }

  override function update(elapsed:Float):Void
  {
    super.update(elapsed);

    centerOrigin();

    if (confirmHoldTimer >= 0)
    {
      confirmHoldTimer += elapsed;
      if (confirmHoldTimer >= CONFIRM_HOLD_TIME)
      {
        confirmHoldTimer = -1;
        playStatic();
      }
    }
  }

  function setup(noteStyle:NoteStyle):Void
  {
    if (noteStyle == null)
    {
      throw "FATAL ERROR: Attempted to initialize StrumlineNote with a null NoteStyle.";
    }

    noteStyle.applyStrumlineFrames(this);
    noteStyle.applyStrumlineAnimations(this, this.direction);

    var scale:Float = noteStyle.getStrumlineScale();
    this.scale.set(scale, scale);
    this.updateHitbox();
    noteStyle.applyStrumlineOffsets(this);

    this.playStatic();
  }

  public function playAnimation(name:String = 'static', force:Bool = false, reversed:Bool = false, startFrame:Int = 0):Void
  {
    this.animation.play(name, force, reversed, startFrame);
    centerOffsets();
    centerOrigin();
  }

  public function playStatic():Void
  {
    this.active = (forceActive || isAnimationDynamic('static'));
    this.playAnimation('static', true);
  }

  public function playPress():Void
  {
    this.active = (forceActive || isAnimationDynamic('pressed'));
    this.playAnimation('pressed', true);
  }

  public function playConfirm():Void
  {
    this.active = (forceActive || isAnimationDynamic('confirm'));
    this.playAnimation('confirm', true);

    confirmHoldTimer = isPlayer ? -1 : 0;
  }

  public function isConfirm():Bool
  {
    return getCurrentAnimation().startsWith('confirm');
  }

  public function holdConfirm():Void
  {
    this.active = true;

    var cur:String = getCurrentAnimation();
    if (cur == 'confirm-hold') return;
    if (cur == 'confirm')
    {
      if (isAnimationFinished())
      {
        this.confirmHoldTimer = -1;
        this.playAnimation('confirm-hold', false, false);
      }
    }
    else
    {
      this.playAnimation('confirm', false, false);
    }
  }
}
