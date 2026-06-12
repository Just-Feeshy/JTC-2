package;

import flixel.FlxG;
import flixel.util.FlxSignal.FlxTypedSignal;
import flxanimate.FlxAnimate;
import flxanimate.FlxAnimate.Settings;
import flixel.graphics.frames.FlxFrame;
import flixel.system.FlxAssets.FlxGraphicAsset;
import flixel.math.FlxPoint;
import flxanimate.animate.FlxKeyFrame;
import openfl.utils.Assets;

/**
 * A sprite which provides convenience functions for rendering a texture atlas with animations.
 *
 * Ported from Funkin's `funkin.graphics.adobeanimate.FlxAtlasSprite` (FunkinCrew/flxanimate),
 * flattened to the no-package layout JTC-2 uses.
 */
@:nullSafety
class FlxAtlasSprite extends FlxAnimate
{
	static final SETTINGS:Settings =
		{
			// ?ButtonSettings:Map<String, flxanimate.animate.FlxAnim.ButtonSettings>,
			FrameRate: 24.0,
			Reversed: false,
			// ?OnComplete:Void -> Void,
			ShowPivot: false,
			Antialiasing: true,
			ScrollFactor: null,
			// Offset: new FlxPoint(0, 0), // This is just FlxSprite.offset
		};

	/**
	 * Signal dispatched when an animation advances to the next frame.
	 */
	public var onAnimationFrame:FlxTypedSignal<String->Int->Void> = new FlxTypedSignal();

	/**
	 * Signal dispatched when a non-looping animation finishes playing.
	 */
	public var onAnimationComplete:FlxTypedSignal<String->Void> = new FlxTypedSignal();

	/**
	 * Signal dispatched when a looping animation finishes playing.
	 */
	public var onAnimationLoop:FlxTypedSignal<String->Void> = new FlxTypedSignal();

	var currentAnimation:String = '';

	var canPlayOtherAnims:Bool = true;

	@:nullSafety(Off) // null safety HATES new classes atm, it'll be fixed in haxe 4.0.0?
	public function new(x:Float, y:Float, ?path:String, ?settings:Settings)
	{
		if (settings == null) settings = SETTINGS;

		if (path == null)
		{
			throw 'Null path specified for FlxAtlasSprite!';
		}

		// Validate asset path.
		if (!Assets.exists('${path}/Animation.json'))
		{
			throw 'FlxAtlasSprite does not have an Animation.json file at the specified path (${path})';
		}

		super(x, y, path, settings);

		if (this.anim.stageInstance == null)
		{
			throw 'FlxAtlasSprite not initialized properly. Are you sure the path (${path}) exists?';
		}

		onAnimationComplete.add(cleanupAnimation);

		// This defaults the sprite to play the first animation in the atlas,
		// then pauses it. This ensures symbols are initialized properly.
		this.anim.play('');
		this.anim.pause();

		this.anim.onComplete.add(_onAnimationComplete);
		this.anim.onFrame.add(_onAnimationFrame);
	}

	/**
	 * @return A list of all the animations this sprite has available.
	 */
	public function listAnimations():Array<String>
	{
		var mainSymbol = this.anim.symbolDictionary[this.anim.stageInstance.symbol.name];
		if (mainSymbol == null)
		{
			FlxG.log.error('FlxAtlasSprite does not have its main symbol!');
			return [];
		}
		// Funkin uses an Array.filterNull() extension here; inline it to stay dependency-free.
		var result:Array<String> = [];
		for (keyFrame in mainSymbol.getFrameLabels())
		{
			if (keyFrame.name != null) result.push(keyFrame.name);
		}
		return result;
	}

	/**
	 * @param id A string ID of the animation.
	 * @return Whether the animation was found on this sprite.
	 */
	public function hasAnimation(id:String):Bool
	{
		return getLabelIndex(id) != -1 || anim.symbolDictionary.exists(id);
	}

	/**
	 * @return The current animation being played.
	 */
	public function getCurrentAnimation():String
	{
		return this.currentAnimation;
	}

	var _completeAnim:Bool = false;

	var fr:Null<FlxKeyFrame> = null;

	var looping:Bool = false;

	public var ignoreExclusionPref:Array<String> = [];

	/**
	 * Plays an animation.
	 * @param id A string ID of the animation to play.
	 * @param restart Whether to restart the animation if it is already playing.
	 * @param ignoreOther Whether to ignore all other animation inputs, until this one is done playing
	 * @param loop Whether to loop the animation
	 * @param startFrame The frame to start the animation on
	 * NOTE: `loop` and `ignoreOther` are not compatible with each other!
	 */
	public function playAnimation(id:String, restart:Bool = false, ignoreOther:Bool = false, loop:Bool = false, startFrame:Int = 0):Void
	{
		// Skip if not allowed to play animations.
		if ((!canPlayOtherAnims))
		{
			if (this.currentAnimation == id && restart) {}
			else if (ignoreExclusionPref != null && ignoreExclusionPref.length > 0)
			{
				var detected:Bool = false;
				for (entry in ignoreExclusionPref)
				{
					if (StringTools.startsWith(id, entry))
					{
						detected = true;
						break;
					}
				}
				if (!detected) return;
			}
			else
				return;
		}

		if (anim == null) return;

		if (id == null || id == '') id = this.currentAnimation;

		if (this.currentAnimation == id && !restart)
		{
			if (!anim.isPlaying)
			{
				if (fr != null) anim.curFrame = fr.index + startFrame;
				else
					anim.curFrame = startFrame;

				// Resume animation if it's paused.
				anim.resume();
			}

			return;
		}
		else if (!hasAnimation(id))
		{
			// Skip if the animation doesn't exist
			trace('Animation ' + id + ' not found');
			return;
		}

		this.currentAnimation = id;
		anim.onComplete.removeAll();
		anim.onComplete.add(function() {
			_onAnimationComplete();
		});

		looping = loop;

		// Prevent other animations from playing if `ignoreOther` is true.
		if (ignoreOther) canPlayOtherAnims = false;

		// Move to the first frame of the animation.
		// When `id` is a frame label on the main timeline, play it via the label
		// path ONLY. Funkin's atlases name their symbols differently from their
		// frame labels, so the symbol branch below never fires for them. But atlases
		// like DD_assets reuse the SAME name for the frame label and the symbol, so
		// running both the symbol-direct play AND goToFrameLabel composites two
		// conflicting playbacks on top of each other (garbled / leftover layers).
		var frameLabelNames = getFrameLabelNames();
		var isFrameLabel:Bool = frameLabelNames != null && frameLabelNames.indexOf(id) != -1;

		if (!isFrameLabel && ((id == null || id == "") || this.anim.symbolDictionary.exists(id) || (this.anim.getByName(id) != null)))
		{
			this.anim.play(id, restart, false, startFrame);

			this.currentAnimation = anim.curSymbol.name;

			fr = null;
		}

		// Only call goToFrameLabel if there is a frame label with that name. This prevents annoying warnings!
		if (isFrameLabel)
		{
			goToFrameLabel(id);
			fr = anim.getFrameLabel(id);
			anim.curFrame += startFrame;
			// Resume animation if it's paused.
			anim.resume();
		}
	}

	override public function update(elapsed:Float):Void
	{
		super.update(elapsed);
	}

	/**
	 * Returns true if the animation has finished playing.
	 * @return Whether the animation has finished playing.
	 */
	public function isAnimationFinished():Bool
	{
		return isLoopComplete();
	}

	/**
	 * Returns true if the animation has reached the last frame.
	 * Can be true even if animation is configured to loop.
	 * @return Whether the animation has reached the last frame.
	 */
	public function isLoopComplete():Bool
	{
		if (this.anim == null) return false;
		if (!this.anim.isPlaying) return false;

		if (fr != null)
		{
			var curFrame = anim.curFrame;

			var startFrame = fr.index;
			var endFrame = (fr.index + fr.duration);

			return (anim.reversed) ? (curFrame < startFrame) : (curFrame >= endFrame);
		}

		return (anim.reversed && anim.curFrame == 0 || !(anim.reversed) && (anim.curFrame) >= (anim.length - 1));
	}

	/**
	 * Stops the current animation.
	 */
	public function stopAnimation():Void
	{
		if (this.currentAnimation == null) return;

		this.anim.removeAllCallbacksFrom(getNextFrameLabel(this.currentAnimation));

		goToFrameIndex(0);
	}

	function addFrameCallback(label:String, callback:Void->Void):Void
	{
		var frameLabel = this.anim.getFrameLabel(label);
		frameLabel.add(callback);
	}

	function goToFrameLabel(label:String):Void
	{
		this.anim.goToFrameLabel(label);
	}

	function getFrameLabelNames(?layer:haxe.extern.EitherType<Int, String>):Null<Array<String>>
	{
		var labels = this.anim.getFrameLabels(layer);
		var array = [];
		for (label in labels)
		{
			array.push(label.name);
		}

		return array;
	}

	function getNextFrameLabel(label:String):String
	{
		return listAnimations()[(getLabelIndex(label) + 1) % listAnimations().length];
	}

	function getLabelIndex(label:String):Int
	{
		return listAnimations().indexOf(label);
	}

	function goToFrameIndex(index:Int):Void
	{
		this.anim.curFrame = index;
	}

	public function cleanupAnimation(_:String):Void
	{
		canPlayOtherAnims = true;
		// this.currentAnimation = null;
		this.anim.pause();
	}

	function _onAnimationFrame(frame:Int):Void
	{
		if (currentAnimation != null)
		{
			onAnimationFrame.dispatch(currentAnimation, frame);

			if (isLoopComplete())
			{
				anim.pause();

				if (looping)
				{
					anim.curFrame = (fr != null) ? fr.index : 0;
					anim.resume();
					_onAnimationLoop();
				}
				else if (fr != null && anim.curFrame != anim.length - 1)
				{
					anim.curFrame--;
					_onAnimationComplete();
				}
			}
		}
	}

	function _onAnimationComplete():Void
	{
		if (currentAnimation != null)
		{
			onAnimationComplete.dispatch(currentAnimation);
		}
		else
		{
			onAnimationComplete.dispatch('');
		}
	}

	function _onAnimationLoop():Void
	{
		if (currentAnimation != null)
		{
			onAnimationLoop.dispatch(currentAnimation);
		}
		else
		{
			onAnimationLoop.dispatch('');
		}
	}

	var prevFrames:Map<Int, FlxFrame> = [];

	public function replaceFrameGraphic(index:Int, ?graphic:FlxGraphicAsset):Void
	{
		var cond = false;

		if (graphic == null) cond = true;
		else
		{
			if ((graphic is String)) cond = !Assets.exists(graphic)
			else
				cond = false;
		}
		if (cond)
		{
			var prevFrame:Null<FlxFrame> = prevFrames.get(index);
			if (prevFrame == null) return;

			prevFrame.copyTo(frames.getByIndex(index));
			return;
		}

		var prevFrame:FlxFrame = prevFrames.get(index) ?? frames.getByIndex(index).copyTo();
		prevFrames.set(index, prevFrame);

		@:nullSafety(Off) // TODO: Remove this once flixel.system.frontEnds.BitmapFrontEnd has been null safed
		var frame = FlxG.bitmap.add(graphic).imageFrame.frame;
		frame.copyTo(frames.getByIndex(index));

		// Funkin applies an additional `tileMatrix` sizing fix here, but this flixel
		// build exposes tileMatrix as a non-indexable MatrixVector. This method is
		// unused by atlas characters, so the refinement is omitted.
	}

	public function getBasePosition():Null<FlxPoint>
	{
		// var stagePos = new FlxPoint(anim.stageInstance.matrix.tx, anim.stageInstance.matrix.ty);
		var instancePos = new FlxPoint(anim.curInstance.matrix.tx, anim.curInstance.matrix.ty);
		var firstElement = anim.curSymbol.timeline?.get(0)?.get(0)?.get(0);
		if (firstElement == null) return instancePos;
		var firstElementPos = new FlxPoint(firstElement.matrix.tx, firstElement.matrix.ty);

		return instancePos + firstElementPos;
	}

	public function getPivotPosition():Null<FlxPoint>
	{
		return anim.curInstance.symbol.transformationPoint;
	}

	public override function destroy():Void
	{
		for (prevFrameId in prevFrames.keys())
		{
			replaceFrameGraphic(prevFrameId, null);
		}

		super.destroy();
	}
}
