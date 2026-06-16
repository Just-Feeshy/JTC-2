package;

import flixel.FlxG;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxAxes;
import flixel.math.FlxPoint;
import flxanimate.FlxAnimate;
import json2object.JsonParser;

import ModInitialize;

using StringTools;

/**
 * Character port modelled 1:1 on FNF-PlusEngine's `objects/Character.hx`
 * (loadCharacterFile / Animate-atlas support / danceIdle / draw override),
 * but reading from the engine's own `ConfigCharacters` typedef instead of FNF's `CharacterFile`.
 *
 * NOTE: extends `feshixl.FeshSprite` (the engine base, which IS-A `FlxSprite` and adds the
 * advanced clip-rect rendering) rather than plain `FlxSprite`, and keeps the engine's default
 * animation controller (this engine has no `PsychAnimationController`). The JTC public API
 * (`getAnimName`, `onNoteHit`, `singMultiplier`, ...) is preserved as thin aliases so existing
 * callers keep compiling.
 */
class Character extends feshixl.FeshSprite
{
	/**
	 * In case a character is missing, it will use this on its place
	**/
	public static final DEFAULT_CHARACTER:String = 'bf';

	private static inline var DEFAULT_ANTIALIASING_UPDATE_MULTIPLIER:Float = 1.0;
	private static var singDirections:Array<String> = ["LEFT", "DOWN", "UP", "RIGHT"];

	public var animOffsets:Map<String, Array<Float>>;
	public var animations:Array<String>;
	public var debugMode:Bool = false;
	public var extraData:Map<String, Dynamic> = new Map<String, Dynamic>();

	public var isPlayer:Bool = false;
	public var curCharacter:String = DEFAULT_CHARACTER;

	public var holdTimer:Float = 0;
	public var heyTimer:Float = 0;
	public var specialAnim:Bool = false;
	public var customAnimation:Bool = false;
	public var canPlayOtherAnims:Bool = false;
	public var isDead:Bool = false;
	public var stunned:Bool = false;

	public var singMultiplier:Float = 4; // Multiplier of how long a character holds the sing pose
	public var singTimeSteps:Float = 4;
	public var idleSuffix:String = '';
	public var danceIdle:Bool = false; // Character uses "danceLeft"/"danceRight" instead of "idle"
	public var skipDance:Bool = false;
	public var shouldPlayDance:Bool = true;
	public var hasBePlayer:String = "";

	public var hasMissAnimations:Bool = false;

	public var missingCharacter:Bool = false;
	public var missingText:FlxText;

	public var dancing(default, null):Bool = false;

	@:isVar public var _info(get, default):ConfigCharacters;

	// Used by PlayState/editors for repositioning.
	private var finalizedX:Float;
	private var finalizedY:Float;
	public var finalizedWidth(default, null):Float = 0;
	public var finalizedHeight(default, null):Float = 0;

	public var danceBeatTimer:Int = 1;
	private var cameraFocusPointCache:FlxPoint = new FlxPoint();

	private var hardInfo:ConfigCharacters;

	// Adobe Animate texture atlas support (like mod_assets/images/fonz).
	// special thanks ne_eo / FNF-PlusEngine for the references, you're the goat!!
	public var isAnimateAtlas(default, null):Bool = false;
	public var atlas:FlxAnimate;
	var _lastPlayedAnimation:String = "";

	public function new(x:Float, y:Float, ?character:String = "bf", ?isPlayer:Bool = false, ?hardInfo:ConfigCharacters, frameOffsetApply:Bool = true)
	{
		super(x, y);

		useAdvanceClipping = false;

		finalizedX = x;
		finalizedY = y;

		animOffsets = new Map<String, Array<Float>>();
		animations = new Array<String>();
		this.isPlayer = isPlayer;
		this.hardInfo = hardInfo;

		changeCharacter(character);

		if (curCharacter == "dad")
			singMultiplier = 6.1;

		singTimeSteps = singMultiplier;

		// flipX is finalised in loadCharacterFile() as (_info.isPlayer != isPlayer), FNF-style.
		dance();
	}

	public function changeCharacter(character:String):Void
	{
		animations = [];
		animOffsets = new Map<String, Array<Float>>();
		curCharacter = character;

		switch (character)
		{
			/**
			add a case if you want to hard code it
			**/
			case "none":
				return;
			default:
				if (hardInfo != null)
					_info = hardInfo;
				else
					_info = cast loadInfo('characters/${curCharacter}');

				if (_info == null || _info.file == null || _info.file == "")
				{
					missingCharacter = true;
					missingText = new FlxText(0, 0, 300, 'ERROR:\n$character', 16);
					missingText.alignment = CENTER;
				}

				loadCharacterFile(_info);
		}

		skipDance = false;
		hasMissAnimations = hasAnimation('singLEFTmiss') || hasAnimation('singDOWNmiss') || hasAnimation('singUPmiss') || hasAnimation('singRIGHTmiss');
		recalculateDanceIdle();
	}

	public function loadCharacterFile(json:ConfigCharacters):Void
	{
		isAnimateAtlas = false;

		// Detect an Adobe Animate texture atlas (folder with Animation.json, e.g. mod_assets/images/fonz/).
		if (json != null && json.file != null && Paths.hasAnimateAtlas(json.file))
			isAnimateAtlas = true;

		scale.set(1, 1);
		updateHitbox();

		if (!isAnimateAtlas)
		{
			frames = Paths.getMultiAtlas(json.file.split(','), "shared");
		}
		else
		{
			atlas = new FlxAnimate(x, y);
			atlas.showPivot = false;
			try
			{
				Paths.loadAnimateAtlas(atlas, json.file);
			}
			catch (e:haxe.Exception)
			{
				FlxG.log.warn('Could not load atlas ${json.file}: $e');
				isAnimateAtlas = false;
				frames = Paths.getMultiAtlas(json.file.split(','), "shared");
			}
		}

		// Engine-specific hard-coded index animations (gf/spooky), sparrow only.
		if (!isAnimateAtlas)
			setIndexis(curCharacter);

		// animations
		for (anim in _info.animations.keys())
		{
			var animInfo:AnimationInfo = _info.animations.get(anim);
			animations.push(anim);

			if (!isAnimateAtlas)
				animation.addByPrefix(anim, animInfo.prefix, animInfo.framerate, animInfo.looped);
			else
				atlas.anim.addBySymbol(anim, animInfo.prefix, animInfo.framerate, animInfo.looped);

			if (animInfo.offset != null && animInfo.offset.length > 1)
				addOffset(anim, animInfo.offset[0], animInfo.offset[1]);
			else
				addOffset(anim, 0, 0);

			if (anim.endsWith("player") && isPlayer)
				hasBePlayer = "player";
		}

		finalizedWidth = width;
		finalizedHeight = height;

		// pixel sizing (sparrow only; atlas width is 0 until first draw)
		if (_info.pixel && !isAnimateAtlas)
		{
			setGraphicSize(Std.int(width * PlayState.daPixelZoom));
			updateHitbox();
		}

		antialiasing = FlxG.save.data.showAntialiasing ? !_info.pixel : false;

		playAnim(_info.playAnim);
		flipX = (_info.isPlayer != isPlayer);

		// Sync the embedded atlas transform once so the first drawn frame is positioned correctly.
		if (isAnimateAtlas && atlas != null)
			copyAtlasValues();
	}

	override function update(elapsed:Float)
	{
		if (isAnimateAtlas && atlas != null)
			atlas.update(elapsed);

		if (!isAnimateAtlas && Std.isOfType(shader, RimShadowShader))
			cast(shader, RimShadowShader).updateFrameInfo(frame);

		repairInvalidAnimationState();

		if (debugMode || isAnimationNull())
		{
			super.update(elapsed * (FlxG.save.data.showAntialiasing ? 1 : DEFAULT_ANTIALIASING_UPDATE_MULTIPLIER));
			return;
		}

		if (isDead)
		{
			super.update(elapsed * (FlxG.save.data.showAntialiasing ? 1 : DEFAULT_ANTIALIASING_UPDATE_MULTIPLIER));
			return;
		}

		if (heyTimer > 0)
		{
			heyTimer -= elapsed;
			if (heyTimer <= 0)
			{
				var anim:String = getAnimationName();
				if (specialAnim && (anim == 'hey' || anim == 'cheer'))
				{
					specialAnim = false;
					dance();
				}
				heyTimer = 0;
			}
		}

		var currentAnimation:String = getAnimationName();

		if (currentAnimation != "")
		{
			if (specialAnim && isAnimationFinished())
			{
				if (!customAnimation)
				{
					specialAnim = false;
					dance();
					currentAnimation = getAnimationName();
				}
			}

			if (isAnimationFinished()
				&& !currentAnimation.endsWith(Constants.ANIMATION_HOLD_SUFFIX)
				&& hasAnimation(currentAnimation + Constants.ANIMATION_HOLD_SUFFIX))
			{
				playAnim(currentAnimation + Constants.ANIMATION_HOLD_SUFFIX);
				currentAnimation = getAnimationName();
			}

			if (isSinging())
			{
				holdTimer += elapsed;

				var singTimeSec:Float = singTimeSteps * (Conductor.instance.stepLengthMs / Constants.MS_PER_SEC);

				if (currentAnimation.endsWith("miss"))
					singTimeSec *= 2;

				var shouldStopSinging:Bool = isControlledByPlayer() ? !isHoldingNote() : true;

				if (holdTimer > singTimeSec && shouldStopSinging)
				{
					holdTimer = 0;

					var nextAnimation:String = currentAnimation;

					if (nextAnimation.endsWith(Constants.ANIMATION_HOLD_SUFFIX))
						nextAnimation = nextAnimation.substr(0, nextAnimation.length - Constants.ANIMATION_HOLD_SUFFIX.length);

					var endAnimation:String = nextAnimation + Constants.ANIMATION_END_SUFFIX;

					if (hasAnimation(endAnimation))
						playAnim(endAnimation);
					else
						dance(true);
				}
			}
			else
				holdTimer = 0;

			switch (curCharacter)
			{
				case 'gf' | 'fesh':
					if (currentAnimation == 'hairFall' && isAnimationFinished())
						playAnim('danceRight');
			}
		}

		super.update(elapsed * (FlxG.save.data.showAntialiasing ? 1 : DEFAULT_ANTIALIASING_UPDATE_MULTIPLIER));
	}

	inline public function isAnimationNull():Bool
	{
		return !isAnimateAtlas ? (animation.curAnim == null) : (atlas == null || atlas.anim.curInstance == null || atlas.anim.curSymbol == null);
	}

	inline public function getAnimationName():String
	{
		return _lastPlayedAnimation != null ? _lastPlayedAnimation : "";
	}

	// JTC API aliases.
	inline public function getAnimName():String
		return getAnimationName();

	inline public function getCurrentAnimation():String
		return getAnimationName();

	public function isAnimationFinished():Bool
	{
		if (isAnimationNull())
			return false;
		return !isAnimateAtlas ? animation.curAnim.finished : atlas.anim.finished;
	}

	public function finishAnimation():Void
	{
		if (isAnimationNull())
			return;

		if (!isAnimateAtlas)
			animation.curAnim.finish();
		else
			atlas.anim.curFrame = atlas.anim.length - 1;
	}

	public function hasAnimation(anim:String):Bool
	{
		if (animOffsets.exists(anim))
			return true;

		// Engine deviation from FNF-PlusEngine: some sparrow anims (gf/spooky) are registered by
		// `setIndexis` without an offset entry, so fall back to the real animation list for them.
		return !isAnimateAtlas && animation != null && animation.getByName(anim) != null;
	}

	public var animPaused(get, set):Bool;

	private function get_animPaused():Bool
	{
		if (isAnimationNull())
			return false;
		return !isAnimateAtlas ? animation.curAnim.paused : !atlas.anim.isPlaying;
	}

	private function set_animPaused(value:Bool):Bool
	{
		if (isAnimationNull())
			return value;

		if (!isAnimateAtlas)
			animation.curAnim.paused = value;
		else
		{
			if (value)
				atlas.anim.pause();
			else
				atlas.anim.resume();
		}

		return value;
	}

	public var danced:Bool = false;

	/**
	 * FOR GF DANCING SHIT
	 */
	public function dance(force:Bool = false)
	{
		if (isDead || debugMode || skipDance || specialAnim)
			return;

		if (!force)
		{
			if (isSinging())
				return;

			var currentAnimation:String = getAnimationName();

			// don't interrupt gf's hair animations
			if (currentAnimation.startsWith('hair'))
				return;

			if (currentAnimation != ""
				&& !currentAnimation.startsWith("dance")
				&& !currentAnimation.startsWith("idle")
				&& !isAnimationFinished())
				return;
		}

		dancing = true;

		if (danceIdle)
		{
			danced = !danced;

			if (danced)
				playAnim('danceRight' + idleSuffix);
			else
				playAnim('danceLeft' + idleSuffix);
		}
		else if (hasAnimation('idle' + idleSuffix))
			playAnim('idle' + idleSuffix);
	}

	public function playPreferredIdle(force:Bool = false):Void
		dance(force);

	public function playNoDanceAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void
	{
		dancing = false;
		playAnim(AnimName, Force, Reversed, Frame);
	}

	override public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void
	{
		specialAnim = false;

		if (animations.length == 0)
			return;

		if (AnimName.startsWith('sing'))
		{
			dancing = false;
			if (!isAnimateAtlas)
				animation.reset();
		}

		if (!isAnimateAtlas)
			animation.play(AnimName, Force, Reversed, Frame);
		else
		{
			atlas.anim.play(AnimName, Force, Reversed, Frame);
			atlas.update(0);
		}
		_lastPlayedAnimation = AnimName;

		if (hasAnimation(AnimName))
		{
			var daOffset = animOffsets.get(AnimName);
			offset.set(daOffset[0], daOffset[1]);
		}
		else
			offset.set(0, 0);

		if (curCharacter.startsWith('gf') || curCharacter == "fesh")
		{
			if (AnimName == 'singLEFT')
				danced = true;
			else if (AnimName == 'singRIGHT')
				danced = false;

			if (AnimName == 'singUP' || AnimName == 'singDOWN')
				danced = !danced;
		}
	}

	// JTC API alias.
	inline public function playAnimation(animName:String, force:Bool = false, reversed:Bool = false, frame:Int = 0):Void
		playAnim(animName, force, reversed, frame);

	public var danceEveryNumBeats:Int = 2;
	private var settingCharacterUp:Bool = true;

	public function recalculateDanceIdle():Void
	{
		var lastDanceIdle:Bool = danceIdle;
		danceIdle = (hasAnimation('danceLeft' + idleSuffix) && hasAnimation('danceRight' + idleSuffix));

		if (settingCharacterUp)
		{
			danceEveryNumBeats = (danceIdle ? 1 : 2);
		}
		else if (lastDanceIdle != danceIdle)
		{
			var calc:Float = danceEveryNumBeats;
			if (danceIdle)
				calc /= 2;
			else
				calc *= 2;

			danceEveryNumBeats = Math.round(Math.max(calc, 1));
		}
		settingCharacterUp = false;

		// keep the engine's per-beat field (used by PlayState) in sync
		danceBeatTimer = danceEveryNumBeats;
	}

	public function addOffset(name:String, x:Float = 0, y:Float = 0):Void
		animOffsets[name] = [x, y];

	public function changeOffsets(name:String, value:Float, axes:FlxAxes):Void
	{
		if (axes == FlxAxes.X)
			animOffsets[name][0] = value;
		else if (axes == FlxAxes.Y)
			animOffsets[name][1] = value;
		else
		{
			animOffsets[name][0] = value;
			animOffsets[name][1] = value;
		}
	}

	public function quickAnimAdd(name:String, anim:String):Void
		animation.addByPrefix(name, anim, 24, false);

	public function refreshAnims():Void
	{
		if (!isAnimateAtlas)
			setIndexis(curCharacter);

		for (anim in _info.animations.keys())
		{
			var animInfo:AnimationInfo = _info.animations.get(anim);
			if (!isAnimateAtlas)
				animation.addByPrefix(anim, animInfo.prefix, animInfo.framerate, animInfo.looped);
			else
				atlas.anim.addBySymbol(anim, animInfo.prefix, animInfo.framerate, animInfo.looped);
		}
	}

	// ---------------------------------------------------------------------------
	// Atlas support
	// ---------------------------------------------------------------------------

	public override function draw():Void
	{
		var lastAlpha:Float = alpha;
		var lastColor:FlxColor = color;
		if (missingCharacter)
		{
			alpha *= 0.6;
			color = FlxColor.BLACK;
		}

		if (isAnimateAtlas && atlas != null)
		{
			if (atlas.anim.curInstance != null)
			{
				copyAtlasValues();
				atlas.draw();

				// Mirror atlas dimensions back so getGraphicMidpoint()/getMidpoint() behave.
				width = atlas.width;
				height = atlas.height;

				alpha = lastAlpha;
				color = lastColor;

				if (missingCharacter && visible)
				{
					missingText.x = getMidpoint().x - 150;
					missingText.y = getMidpoint().y - 10;
					missingText.draw();
				}
			}
			return;
		}

		super.draw();

		if (missingCharacter && visible)
		{
			alpha = lastAlpha;
			color = lastColor;
			missingText.x = getMidpoint().x - 150;
			missingText.y = getMidpoint().y - 10;
			missingText.draw();
		}
	}

	/**
	 * Copies this sprite's transform onto the embedded `FlxAnimate` before drawing it.
	 *
	 * FLICKER FIX: the bundled (older) flxanimate applies `flipX` in `FlxAnimate.draw()` via
	 * `_matrix.tx += width`, where `width` is only recomputed AFTER the symbol is rendered — i.e.
	 * it uses the PREVIOUS frame's width. On animations whose bounding box changes size each frame
	 * (e.g. sings), a flipped (player) character then jitters horizontally every frame. FNF-PlusEngine
	 * avoids this only because it ships a newer flxanimate. So instead of `atlas.flipX`, we flip via a
	 * negative `scale.x` around the symbol's `transformationPoint` origin (which `drawLimb` already
	 * pivots on) — no `width` dependency, no jitter. We must therefore NOT overwrite `atlas.origin`.
	 */
	function copyAtlasValues():Void
	{
		@:privateAccess
		{
			atlas.cameras = cameras;
			atlas.scrollFactor = scrollFactor;
			atlas.offset = offset;
			atlas.x = x;
			atlas.y = y;
			atlas.angle = angle;
			atlas.alpha = alpha;
			atlas.visible = visible;
			atlas.shader = shader;
			atlas.antialiasing = antialiasing;
			atlas.colorTransform = colorTransform;
			atlas.color = color;

			// Flip with negative scale around the atlas's own (transformationPoint) origin.
			atlas.flipX = false;
			atlas.flipY = false;
			atlas.scale.set(flipX ? -Math.abs(scale.x) : Math.abs(scale.x), flipY ? -Math.abs(scale.y) : Math.abs(scale.y));
		}
	}

	public override function destroy():Void
	{
		if (atlas != null)
		{
			atlas.destroy();
			atlas = null;
		}

		super.destroy();

		if (animOffsets != null)
			animOffsets.clear();

		curCharacter = null;
		animOffsets = null;
		animations = null;
		_info = null;
	}

	// ---------------------------------------------------------------------------
	// JTC sing / note logic (kept for PlayState & co.)
	// ---------------------------------------------------------------------------

	function repairInvalidAnimationState():Void
	{
		if (isAnimateAtlas || animation == null || animation.curAnim == null)
			return;

		if (animation.curAnim.frames != null)
			return;

		animation.play(null);
		playPreferredIdle(true);
	}

	public function isSinging():Bool
	{
		var currentAnimation:String = getAnimationName();
		return currentAnimation.startsWith("sing") && !currentAnimation.endsWith(Constants.ANIMATION_END_SUFFIX);
	}

	private function getSingDirectionIndex(direction:Int):Int
	{
		var lane:Int = Std.int(Math.abs(direction));

		if (PlayState.SONG != null && PlayState.SONG.fifthKey)
		{
			return switch (lane)
			{
				case 0: 0;
				case 1: 1;
				case 3: 2;
				case 4: 3;
				default: -1;
			}
		}

		return lane >= 0 && lane < singDirections.length ? lane : -1;
	}

	function buildSingAnimationName(direction:Int, miss:Bool = false, ?suffix:String = ""):String
	{
		var singDirectionIndex:Int = getSingDirectionIndex(direction);
		if (singDirectionIndex < 0)
			return "";

		return 'sing${singDirections[singDirectionIndex]}${miss ? "miss" : ""}$suffix';
	}

	function isControlledByPlayer():Bool
		return PlayState.instance != null && PlayState.instance.currentPlayer == this;

	function isHoldingNote():Bool
	{
		if (!isControlledByPlayer())
			return false;

		var controls = PlayerSettings.player1.controls;

		return controls != null && (controls.LEFT || controls.DOWN || controls.UP || controls.RIGHT || controls.SPACE);
	}

	public function playSingAnimation(direction:Int, miss:Bool = false, ?suffix:String = ""):Void
	{
		var animName:String = buildSingAnimationName(direction, miss, suffix);
		if (animName != "")
			playAnim(animName, true);
	}

	public function playMissAnimation(direction:Int, ?suffix:String = ""):Void
	{
		if (getSingDirectionIndex(direction) < 0)
			return;

		var candidates:Array<String> = [
			buildSingAnimationName(direction, true, suffix),
			buildSingAnimationName(direction, true),
			buildSingAnimationName(direction, false, suffix),
			buildSingAnimationName(direction, false)
		];

		for (animName in candidates)
		{
			if (hasAnimation(animName))
			{
				playNoDanceAnim(animName, true);
				holdTimer = 0;
				return;
			}
		}
	}

	public function onNoteHit(direction:Int, ?suffix:String = ""):Void
	{
		if (getSingDirectionIndex(direction) < 0)
			return;

		playSingAnimation(direction, false, suffix);
		holdTimer = 0;
	}

	public function onNoteMiss(direction:Int, ?suffix:String = ""):Void
		playMissAnimation(direction, suffix);

	public function onNoteGhostMiss(direction:Int, ?suffix:String = ""):Void
		playMissAnimation(direction, suffix);

	public function onNoteHoldDrop(direction:Int, ?suffix:String = ""):Void
		playMissAnimation(direction, suffix);

	// ---------------------------------------------------------------------------
	// Misc engine hooks
	// ---------------------------------------------------------------------------

	public function resetCharacter(reapplyDance:Bool = true):Void
	{
		visible = true;
		alpha = 1;
		color = FlxColor.WHITE;
		angle = 0;
		specialAnim = false;
		customAnimation = false;
		holdTimer = 0;
		stunned = false;

		if (reapplyDance)
			dance();
	}

	public function getDeathCameraOffsets():Array<Float>
		return [0, 0];

	public function getDeathCameraZoom():Float
		return 1;

	public function getDeathQuote():String
		return null;

	public var cameraFocusPoint(get, never):FlxPoint;

	function get_cameraFocusPoint():FlxPoint
	{
		cameraFocusPointCache.set(getGraphicMidpoint().x, getGraphicMidpoint().y);

		if (_info != null && _info.position != null)
		{
			var camPosX:Dynamic = _info.position.get('camPosX');
			var camPosY:Dynamic = _info.position.get('camPosY');

			cameraFocusPointCache.x += camPosX != null ? camPosX : 0;
			cameraFocusPointCache.y += camPosY != null ? camPosY : 0;
		}

		return cameraFocusPointCache;
	}

	public function updateFinalized(x:Float, y:Float):Void
	{
		finalizedX = x;
		finalizedY = y;
	}

	public function refresh(character:String, camPos:FlxPoint)
	{
		this.setPosition(finalizedX, finalizedY);

		this.x += _info.position.get('x');
		this.y += _info.position.get('y');

		camPos.set(this.getGraphicMidpoint().x, this.getGraphicMidpoint().y);

		camPos.x += _info.position.get('camPosX');
		camPos.y += _info.position.get('camPosY');
	}

	function setIndexis(character:String):Void
	{
		switch (character)
		{
			case 'gf' | 'fesh':
				animations = ['sad', 'danceLeft', 'danceRight', 'hairBlow', 'hairFall'];

				animation.addByIndices('sad', 'gf sad', [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], "", 24, false);
				animation.addByIndices('danceLeft', 'GF Dancing Beat', [30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14], "", 24, false);
				animation.addByIndices('danceRight', 'GF Dancing Beat', [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29], "", 24, false);
				animation.addByIndices('hairBlow', "GF Dancing Beat Hair blowing", [0, 1, 2, 3], "", 24);
				animation.addByIndices('hairFall', "GF Dancing Beat Hair Landing", [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], "", 24, false);
			case 'gf-christmas':
				animations = ['sad', 'danceLeft', 'danceRight', 'hairBlow', 'hairFall'];

				animation.addByIndices('sad', 'gf sad', [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], "", 24, false);
				animation.addByIndices('danceLeft', 'GF Dancing Beat', [30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14], "", 24, false);
				animation.addByIndices('danceRight', 'GF Dancing Beat', [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29], "", 24, false);
				animation.addByIndices('hairBlow', "GF Dancing Beat Hair blowing", [0, 1, 2, 3], "", 24);
				animation.addByIndices('hairFall', "GF Dancing Beat Hair Landing", [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], "", 24, false);
			case 'gf-car':
				animations = ['singUP', 'danceLeft', 'danceRight'];

				animation.addByIndices('singUP', 'GF Dancing Beat Hair blowing CAR', [0], "", 24, false);
				animation.addByIndices('danceLeft', 'GF Dancing Beat Hair blowing CAR', [30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14], "", 24, false);
				animation.addByIndices('danceRight', 'GF Dancing Beat Hair blowing CAR', [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29], "", 24, false);
			case 'gf-pixel':
				animations = ['singUP', 'danceLeft', 'danceRight'];

				animation.addByIndices('singUP', 'GF IDLE', [2], "", 24, false);
				animation.addByIndices('danceLeft', 'GF IDLE', [30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14], "", 24, false);
				animation.addByIndices('danceRight', 'GF IDLE', [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29], "", 24, false);
			case 'spooky':
				animations = ['danceLeft', 'danceRight'];

				animation.addByIndices('danceLeft', 'spooky dance idle', [0, 2, 6], "", 12, false);
				animation.addByIndices('danceRight', 'spooky dance idle', [8, 10, 12, 14], "", 12, false);
		}
	}

	private static var infoCache:Map<String, ConfigCharacters> = new Map<String, ConfigCharacters>();

	public static function loadInfo(character:String):ConfigCharacters
	{
		if (infoCache.exists(character))
			return infoCache.get(character);

		var parser:JsonParser<ConfigCharacters> = new JsonParser<ConfigCharacters>();
		var result:ConfigCharacters = parser.fromJson(Paths.readText(Paths.getPreloadPath('$character.json')), '${character.split('/')[1]}.json');

		if (result != null)
			infoCache.set(character, result);

		return result;
	}

	public static function clearInfoCache():Void
		infoCache = new Map<String, ConfigCharacters>();

	function get__info():ConfigCharacters
	{
		if (_info == null)
		{
			return {
				file: "",
				animations: [],
				position: [],
				icon: [],
				playAnim: "",
				isPlayer: false,
				pixel: false,

				iconFile: "iconGrid",
				clippingAdjustment: []
			};
		}
		else
			return DefaultHandler.setupUpdateInfo(_info);
	}
}
