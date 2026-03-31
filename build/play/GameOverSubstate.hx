package play;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxCamera.FlxCameraFollowStyle;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;
import FunkinSound;
import util.HapticUtil;
import lime.utils.Assets;
import openfl.utils.AssetType;
import CharacterRole;
import FreeplayState;
import MusicBeatSubstate;
import StoryMenuState;
import util.MathUtil;
import effects.RetroCameraFade;

using StringTools;

/**
 * A substate which renders over the PlayState when the player dies.
 * Displays the player death animation, plays the music, and handles restarting the song.
 *
 * The newest implementation uses a substate, which prevents having to reload the song and stage each reset.
 */
@:access(PlayState)
@:nullSafety
class GameOverSubstate extends MusicBeatSubstate
{
  public static var instance:Null<GameOverSubstate> = null;
  public static var animationSuffix:String = '';
  public static var musicSuffix:String = '';
  public static var blueBallSuffix:String = '';
  static var blueballed:Bool = false;
  var boyfriend:Null<Character> = null;
  var cameraFollowPoint:FlxObject;
  var gameOverMusic:Null<FunkinSound> = null;
  var isEnding:Bool = false;
  var isStarting:Bool = true;
  var isChartingMode:Bool = false;
  var mustNotExit:Bool = false;
  static final CAMERA_ZOOM_DURATION:Float = 0.5;
  var targetCameraZoom:Float = 1.0;
  var canInput:Bool = false;
  var hasStartedAnimation:Bool = false;

  public function new()
  {
    super();

    cameraFollowPoint = new FlxObject(0, 0, 1, 1);
  }

  public var parentPlayState:Null<PlayState>;
  public static function reset():Void
  {
    animationSuffix = '';
    musicSuffix = '';
    blueBallSuffix = '';
    blueballed = false;
  }

  public override function create():Void
  {
    if (instance != null)
    {
      FlxG.log.warn('WARNING: GameOverSubstate instance already exists. This should not happen.');
    }
    instance = this;

    super.create();

    parentPlayState = cast _parentState;

    //
    // Set up the visuals
    //

    // Add a black background to the screen.
    var bg:FunkinSprite = new FunkinSprite().makeSolidColor(FlxG.width * 2, FlxG.height * 2, FlxColor.BLACK);
    bg.alpha = 1.0;
    bg.scrollFactor.set();
    bg.screenCenter();
    add(bg);

    // Pluck Boyfriend from the PlayState and place him (in the same position) in the GameOverSubState.
    // We can then play the character's `firstDeath` animation.
    if ((parentPlayState?.isMinimalMode ?? true))
    {
    }
    else
    {
      boyfriend = parentPlayState?.extractGameOverCharacter();
      if (boyfriend != null)
      {
        boyfriend.canPlayOtherAnims = true;
        boyfriend.isDead = true;
        boyfriend.specialAnim = false;
        boyfriend.customAnimation = false;
        boyfriend.holdTimer = 0;
        add(boyfriend);
        boyfriend.resetCharacter(false);
      }
    }

    setCameraTarget();

    //
    // Set up the audio
    //

    // The conductor now represents the BPM of the game over music.
    Conductor.instance.update(0);

    #if mobile
    addBackButton(FlxG.width - 230, FlxG.height - 200, FlxColor.WHITE, goBack);
    #end

    HapticUtil.vibrate(0, Constants.DEFAULT_VIBRATION_DURATION);

    // Allow input a second later to prevent accidental gameover skips.
    new FlxTimer().start(1, function(tmr:FlxTimer)
    {
      canInput = true;
    });
  }

  function setCameraTarget():Void
  {
    if (parentPlayState == null || parentPlayState.isMinimalMode || boyfriend == null) return;

    cameraFollowPoint = new FlxObject(parentPlayState.cameraFollowPoint.x, parentPlayState.cameraFollowPoint.y, 1, 1);
    cameraFollowPoint.x = boyfriend.cameraFocusPoint.x;
    cameraFollowPoint.y = boyfriend.cameraFocusPoint.y;

    var offsets:Array<Float> = boyfriend.getDeathCameraOffsets();
    if (offsets != null && offsets.length >= 2)
    {
      cameraFollowPoint.x += offsets[0];
      cameraFollowPoint.y += offsets[1];
    }

    add(cameraFollowPoint);

    @:nullSafety(Off)
    FlxG.camera.target = null;
    FlxG.camera.follow(cameraFollowPoint, FlxCameraFollowStyle.LOCKON, Constants.DEFAULT_CAMERA_FOLLOW_RATE / 2);
    targetCameraZoom = (parentPlayState?.currentStage?.camZoom ?? 1.0) * boyfriend.getDeathCameraZoom();
  }

  /**
   * Forcibly reset the camera zoom level to that of the current stage.
   * This prevents camera zoom events from adversely affecting the game over state.
   */
  public function resetCameraZoom():Void
  {
    FlxG.camera.zoom = parentPlayState?.currentStage?.camZoom ?? 1.0;
  }

  override function update(elapsed:Float):Void
  {
    if (!hasStartedAnimation)
    {
      startDeathAnimation();
    }

    // Smoothly lerp the camera
    FlxG.camera.zoom = MathUtil.smoothLerpPrecision(FlxG.camera.zoom, targetCameraZoom, elapsed, CAMERA_ZOOM_DURATION);

    //
    // Handle user inputs.
    //

    // Restart the level when pressing the assigned key.
    if ((controls.ACCEPT)
      && blueballed
      && !mustNotExit)
    {
      blueballed = false;
      confirmDeath();
    }

    if (controls.BACK && !mustNotExit && !isEnding && canInput) goBack();

    if (gameOverMusic != null && gameOverMusic.playing)
    {
      // Match the conductor to the music.
      // This enables the stepHit and beatHit events.
      Conductor.instance.update(gameOverMusic.time);
    }
    else if (boyfriend != null)
    {
      if ((parentPlayState?.isMinimalMode ?? true))
      {
        // Do nothing?
      }
      else
      {
        // Music hasn't started yet.

        if (boyfriend.getDeathQuote() != null)
        {
          if (boyfriend.getCurrentAnimation().startsWith('firstDeath') && boyfriend.isAnimationFinished() && !hasPlayedDeathQuote)
          {
            hasPlayedDeathQuote = true;
            playDeathQuote();
          }
        }
        else
        {
          // Start music at normal volume once the initial death animation finishes.
          if (boyfriend.getCurrentAnimation().startsWith('firstDeath') && boyfriend.isAnimationFinished())
          {
            startDeathMusic(1.0, false);
            boyfriend.playAnimation('deathLoop' + animationSuffix);
          }
        }
      }
    }

    // Start death music before firstDeath gets replaced
    super.update(elapsed);
  }

  var deathQuoteSound:Null<FunkinSound> = null;

  function startDeathAnimation():Void
  {
    if (hasStartedAnimation)
    {
      return;
    }

    hasStartedAnimation = true;

    if (boyfriend == null || (parentPlayState?.isMinimalMode ?? true))
    {
      playBlueBalledSFX();
      return;
    }

    if (boyfriend.hasAnimation('fakeoutDeath') && FlxG.random.bool((1 / 4096) * 100))
    {
      boyfriend.playAnimation('fakeoutDeath', true, false);
      return;
    }

    var deathAnim:String = 'firstDeath' + animationSuffix;
    if (!boyfriend.hasAnimation(deathAnim))
    {
      deathAnim = 'firstDeath';
    }

    if (boyfriend.hasAnimation(deathAnim))
    {
      boyfriend.playAnimation(deathAnim, true, false);
    }

    playBlueBalledSFX();
  }

  function playDeathQuote():Void
  {
    if (isEnding) return;
    if (boyfriend == null) return;
    if (parentPlayState == null) return;

    var deathQuote:Null<String> = boyfriend.getDeathQuote();
    if (deathQuote == null) return;

    if (deathQuoteSound != null)
    {
      deathQuoteSound.stop();
      deathQuoteSound = null;
    }

    // Start music at lower volume
    startDeathMusic(0.2, false);
    boyfriend.playAnimation('deathLoop' + animationSuffix);
    deathQuoteSound = FunkinSound.playOnce(deathQuote, function()
    {
      // Once the quote ends, fade in the game over music.
      if (!isEnding && gameOverMusic != null)
      {
        gameOverMusic.fadeIn(4, 0.2, 1);
      }
    });
  }

  /**
   * Do behavior which occurs when you confirm and move to restart the level.
   */
  function confirmDeath():Void
  {
    if (!isEnding)
    {
      isEnding = true;

      // Stop death quotes immediately.
      hasPlayedDeathQuote = true;
      if (deathQuoteSound != null)
      {
        deathQuoteSound.stop();
        deathQuoteSound = null;
      }

      startDeathMusic(1.0, true);

      if ((parentPlayState?.isMinimalMode ?? true) || boyfriend == null)
      {
      }
      else
      {
        boyfriend.playAnimation('deathConfirm' + animationSuffix, true);
      }

      final FADE_TIMER:Float = (gameOverMusic?.length ?? 0) / 7000;
      new FlxTimer().start(FADE_TIMER, function(tmr:FlxTimer)
      {
        var resetPlaying = function(pixel:Bool = false)
        {
          if (pixel) RetroCameraFade.fadeBlack(FlxG.camera, 10, 1);
          else
            FlxG.camera.fade(FlxColor.BLACK, 1, true, null, true);
          if (parentPlayState != null) parentPlayState.needsReset = true;

          if ((parentPlayState?.isMinimalMode ?? true) || boyfriend == null)
          {
          }
          else
          {
            boyfriend.isDead = false;
            remove(boyfriend);
            parentPlayState?.restoreGameOverCharacter(boyfriend);
          }

          resetCameraZoom();
          close();
        };

        if (musicSuffix.contains('-pixel'))
        {
          RetroCameraFade.fadeToBlack(FlxG.camera, 10, 2);
          new FlxTimer().start(2, _ ->
          {
            FlxG.camera.setFilters([]);
            resetPlaying(true);
          });
        }
        else
        {
          FlxG.camera.fade(FlxColor.BLACK, 2, false, function()
          {
            resetPlaying();
          }, true);
        }
      });
    }
  }

  /**
   * Rather than hardcoding stuff, we look for the presence of a music file
   * with the given suffix, and strip it down until we find one that's valid.
   */
  function resolveMusicPath(suffix:String, starting:Bool = false, ending:Bool = false):Null<String>
  {
    var basePath:String = 'gameOver';
    if (ending) basePath += 'End';
    else if (starting) basePath += 'Start';

    // Use Paths.getPath with "shared" library to find music in assets/shared/music/
    var musicPath:String = Paths.getPath('music/' + basePath + suffix + '.' + Paths.SOUND_EXT, AssetType.MUSIC, "shared");
    while (!Paths.assetExists(musicPath, AssetType.MUSIC) && suffix.length > 0)
    {
      suffix = suffix.split('-').slice(0, -1).join('-');
      musicPath = Paths.getPath('music/' + basePath + suffix + '.' + Paths.SOUND_EXT, AssetType.MUSIC, "shared");
    }
    if (!Paths.assetExists(musicPath, AssetType.MUSIC)) return null;
    trace('Resolved music path: ' + musicPath);
    return musicPath;
  }

  /**
   * Starts the death music at the appropriate volume.
   * @param startingVolume The initial volume for the music.
   * @param force Whether or not to force the music to restart.
   */
  public function startDeathMusic(startingVolume:Float = 1, force:Bool = false):Void
  {
    var musicPath:Null<String> = resolveMusicPath(musicSuffix, isStarting, isEnding);
    var onComplete:Void->Void = () -> {};

    if (isStarting)
    {
      if (musicPath == null)
      {
        isStarting = false;
        musicPath = resolveMusicPath(musicSuffix, isStarting, isEnding);
      }
      else
      {
        onComplete = function()
        {
          isStarting = false;
          startDeathMusic(1.0, true);
        };
      }
    }

    if (musicPath == null)
    {
      FlxG.log.warn('[GAMEOVER] Could not find game over music at path ($musicPath)!');
      return;
    }
    else if (gameOverMusic == null || !gameOverMusic.playing || force)
    {
      if (gameOverMusic != null) gameOverMusic.stop();

      gameOverMusic = FunkinSound.load(musicPath);
      if (gameOverMusic == null) return;

      gameOverMusic.volume = startingVolume;
      gameOverMusic.looped = !(isEnding || isStarting);
      gameOverMusic.onComplete = onComplete;
      gameOverMusic.play();
    }
  }

  /**
   * Pressing BACK from the Game Over screen should return the player to the Story/Freeplay menu as appropriate.
   */
  public function goBack():Void
  {
    if (!blueballed || mustNotExit) return;
    isEnding = true;
    blueballed = false;
    if (parentPlayState != null) parentPlayState.deathCounter = 0;
    if (gameOverMusic != null) gameOverMusic.stop();

    // Stop death quotes immediately.
    hasPlayedDeathQuote = true;
    if (deathQuoteSound != null)
    {
      deathQuoteSound.stop();
      deathQuoteSound = null;
    }

    if (isChartingMode)
    {
      this.close();
      if (FlxG.sound.music != null) FlxG.sound.music.pause();
      parentPlayState = null;
      return;
    }
    else
    {
      if (parentPlayState != null && parentPlayState.playLua != null)
      {
        parentPlayState.playLua.set("inGameOver", false);
      }

      if (PlayState.isStoryMode)
        FlxG.switchState(new StoryMenuState());
      else
        FlxG.switchState(new FreeplayState());
    }
  }

  /**
   * Play the sound effect that occurs when
   * boyfriend's testicles get utterly annihilated.
   */
  public static function playBlueBalledSFX():Void
  {
    blueballed = true;
    // Use Paths.getPath with "shared" library to find sounds in assets/shared/sounds/
    var soundPath:String = Paths.getPath('sounds/fnf_loss_sfx' + blueBallSuffix + '.' + Paths.SOUND_EXT, AssetType.SOUND, "shared");

    if (Paths.assetExists(soundPath, AssetType.SOUND))
    {
      FunkinSound.playOnce(soundPath);
    }
    else
    {
      FlxG.log.error('Missing blue ball sound effect: ' + soundPath);
    }
  }

  var hasPlayedDeathQuote:Bool = false;

  public override function destroy():Void
  {
    super.destroy();
    if (gameOverMusic != null)
    {
      gameOverMusic.stop();
      gameOverMusic = null;
    }
    blueballed = false;
    instance = null;
  }

  public override function toString():String
  {
    return 'GameOverSubstate';
  }
}
