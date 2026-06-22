package;

import flixel.FlxG;
import flixel.math.FlxPoint;
import flixel.util.FlxAxes;
import flixel.util.FlxColor;
import funkin.graphics.FunkinSprite;

import ModInitialize;

using StringTools;

class AtlasCharacter extends FunkinSprite implements ICharacter {
	private static var singDirections:Array<String> = ["LEFT", "DOWN", "UP", "RIGHT"];

	private var finalizedX:Float;
	private var finalizedY:Float;
	private var cameraFocusPointCache:FlxPoint = new FlxPoint();
	private var danced:Bool = false;
	private var currentAnimation:String = "";

	public var animOffsets:Map<String, Array<Float>>;
	public var animations:Array<String>;
	public var canPlayOtherAnims:Bool = false;
	public var customAnimation:Bool = false;
	public var danceBeatTimer:Int = 1;
	public var dancing(default, null):Bool = false;
	public var debugMode:Bool = false;
	public var hasBePlayer:String = "";
	public var holdTimer:Float = 0;
	public var idleSuffix:String = "";
	public var isDead:Bool = false;
	public var isPlayer:Bool = false;
	public var shouldPlayDance:Bool = true;
	public var singMultiplier:Float = 4;
	public var singTimeSteps:Float = 4;
	public var specialAnim:Bool = false;
	public var stunned:Bool = false;

	public var curCharacter:String = "bf";
	@:isVar public var _info(get, default):ConfigCharacters;

	public var cameraFocusPoint(get, never):FlxPoint;

	public function new(x:Float, y:Float, ?character:String = "bf", ?isPlayer:Bool = false, ?hardInfo:ConfigCharacters, frameOffsetApply:Bool = true) {
		super(x, y);

		finalizedX = x;
		finalizedY = y;
		curCharacter = character;
		this.isPlayer = isPlayer;

		animOffsets = new Map<String, Array<Float>>();
		animations = [];

		if(character != "none") {
			_info = hardInfo != null ? hardInfo : Character.loadInfo('characters/${curCharacter}');
			loadCharacterAssets();
			loadCharacterAnimations();

			if(_info.pixel) {
				setGraphicSize(Std.int(width * PlayState.daPixelZoom));
				updateHitbox();
			}

			antialiasing = FlxG.save.data.showAntialiasing ? !_info.pixel : false;
			playAnim(_info.playAnim, true);
			flipX = _info.isPlayer;
		}

		if(curCharacter == "dad") {
			singMultiplier = 6.1;
		}

		singTimeSteps = singMultiplier;
		dance(true);

		if(isPlayer) {
			flipX = !flipX;
		}
	}

	function loadCharacterAssets():Void {
		frames = Paths.getFrames(_info.file);
	}

	function loadCharacterAnimations():Void {
		if(_info == null || _info.animations == null) return;

		for(animName in _info.animations.keys()) {
			var animInfo:AnimationInfo = _info.animations.get(animName);
			animations.push(animName);
			addAnimationFromInfo(animName, animInfo);
			addOffset(animName, animInfo.offset[0], animInfo.offset[1]);

			if(animName.endsWith("player") && isPlayer) {
				hasBePlayer = "player";
			}
		}
	}

	function addAnimationFromInfo(animName:String, animInfo:AnimationInfo):Void {
		// Optional frame range (relative to the label/symbol), Codename-style. Lets a single
		// Animate symbol be split into sub-animations (e.g. GF's "GF Dancing Beat" -> danceLeft/danceRight).
		var indices:Array<Int> = animInfo.indices;
		var hasIndices:Bool = indices != null && indices.length > 0;

		if(isAnimate && anim != null) {
			if(anim.findFrameLabelIndices(animInfo.prefix).length > 0) {
				if(hasIndices)
					anim.addByFrameLabelIndices(animName, animInfo.prefix, indices, animInfo.framerate, animInfo.looped);
				else
					anim.addByFrameLabel(animName, animInfo.prefix, animInfo.framerate, animInfo.looped);
				if(anim.exists(animName)) return;
			}

			var symbol:Dynamic = library != null ? library.getSymbol(animInfo.prefix) : null;
			if(symbol != null && !Std.isOfType(symbol, Bool)) {
				if(hasIndices)
					anim.addBySymbolIndices(animName, animInfo.prefix, indices, animInfo.framerate, animInfo.looped);
				else
					anim.addBySymbol(animName, animInfo.prefix, animInfo.framerate, animInfo.looped);
				if(anim.exists(animName)) return;
			}

			if(hasIndices)
				anim.addByFrameLabelIndices(animName, animInfo.prefix, indices, animInfo.framerate, animInfo.looped);
			else
				anim.addByFrameLabel(animName, animInfo.prefix, animInfo.framerate, animInfo.looped);
		} else if(animation != null) {
			if(hasIndices)
				animation.addByIndices(animName, animInfo.prefix, indices, "", animInfo.framerate, animInfo.looped);
			else
				animation.addByPrefix(animName, animInfo.prefix, animInfo.framerate, animInfo.looped);
		}
	}

	public function addOffset(name:String, x:Float = 0, y:Float = 0):Void {
		animOffsets.set(name, [x, y]);
	}

	public function changeOffsets(name:String, value:Float, axes:FlxAxes):Void {
		if(!animOffsets.exists(name)) addOffset(name);

		if(axes == FlxAxes.X) animOffsets[name][0] = value;
		else if(axes == FlxAxes.Y) animOffsets[name][1] = value;
		else {
			animOffsets[name][0] = value;
			animOffsets[name][1] = value;
		}
	}

	public function hasAnimation(animName:String):Bool {
		if(animName == null) return false;
		if(isAnimate) return anim != null && anim.exists(animName);
		return animation != null && animation.getByName(animName) != null;
	}

	public function isAnimationFinished():Bool {
		if(isAnimate) return anim == null || anim.finished;
		return animation != null && animation.curAnim != null && animation.curAnim.finished;
	}

	public function finishAnimation():Void {
		if(isAnimate) {
			if(anim != null && anim.curAnim != null) anim.curAnim.curFrame = anim.curAnim.numFrames - 1;
		} else if(animation != null && animation.curAnim != null) {
			animation.curAnim.finish();
		}
	}

	public function getCurrentAnimation():String {
		if(!isAnimate && animation != null && animation.curAnim != null) {
			return animation.curAnim.name;
		}

		return currentAnimation;
	}

	public function getAnimName():String {
		return getCurrentAnimation();
	}

	public function playAnimation(animName:String, force:Bool = false, reversed:Bool = false, frame:Int = 0):Void {
		playAnim(animName, force, reversed, frame);
	}

	public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		specialAnim = false;
		if(AnimName == null || animations.length == 0) return;

		var resolvedAnimName:String = resolveAnimationName(AnimName);
		if(resolvedAnimName == null) return;

		if(resolvedAnimName.startsWith("sing")) {
			dancing = false;
			if(animation != null) animation.reset();
		}

		if(isAnimate && anim != null) {
			anim.play(resolvedAnimName, Force, Reversed);
		} else if(animation != null) {
			animation.play(resolvedAnimName, Force, Reversed, Frame);
		}

		currentAnimation = resolvedAnimName;

		var daOffset:Array<Float> = animOffsets.get(resolvedAnimName);
		if(daOffset != null) {
			if(isAnimate) frameOffset.set(daOffset[0], daOffset[1]);
			else offset.set(daOffset[0], daOffset[1]);
		} else {
			if(isAnimate) frameOffset.set(0, 0);
			else offset.set(0, 0);
		}

		if(isAnimate) offset.set(0, 0);
	}

	function resolveAnimationName(animName:String):String {
		if(hasAnimation(animName)) return animName;

		if(animName.lastIndexOf("-") != -1) {
			return resolveAnimationName(animName.substring(0, animName.lastIndexOf("-")));
		}

		return null;
	}

	public function dance(force:Bool = false):Void {
		if(isDead || debugMode || !shouldPlayDance) return;

		if(!force && (specialAnim || isSinging())) {
			return;
		}

		if(hasAnimation("danceLeft" + idleSuffix) && hasAnimation("danceRight" + idleSuffix)) {
			playAnim((danced ? "danceRight" : "danceLeft") + idleSuffix, force);
			danced = !danced;
			dancing = true;
		} else if(hasAnimation("idle" + idleSuffix)) {
			playAnim("idle" + idleSuffix, force);
			dancing = true;
		}
	}

	public function playPreferredIdle(force:Bool = false):Void {
		dance(force);
	}

	public function playNoDanceAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		dancing = false;
		playAnim(AnimName, Force, Reversed, Frame);
	}

	public function isSinging():Bool {
		var current:String = getCurrentAnimation();
		return current != null && current.startsWith("sing") && !current.endsWith(Constants.ANIMATION_END_SUFFIX);
	}

	private function getSingDirectionIndex(direction:Int):Int {
		var lane:Int = Std.int(Math.abs(direction));

		if(PlayState.SONG != null && PlayState.SONG.fifthKey) {
			return switch(lane) {
				case 0: 0;
				case 1: 1;
				case 3: 2;
				case 4: 3;
				default: -1;
			}
		}

		return lane >= 0 && lane < singDirections.length ? lane : -1;
	}

	function buildSingAnimationName(direction:Int, miss:Bool = false, ?suffix:String = ""):String {
		var singDirectionIndex:Int = getSingDirectionIndex(direction);
		if(singDirectionIndex < 0) return "";
		return 'sing${singDirections[singDirectionIndex]}${miss ? "miss" : ""}$suffix';
	}

	public function onNoteHit(direction:Int, ?suffix:String = ""):Void {
		var animName:String = buildSingAnimationName(direction, false, suffix);
		if(animName != "") playAnim(animName, true);
		holdTimer = 0;
	}

	public function onNoteMiss(direction:Int, ?suffix:String = ""):Void {
		playMissAnimation(direction, suffix);
	}

	public function onNoteGhostMiss(direction:Int, ?suffix:String = ""):Void {
		playMissAnimation(direction, suffix);
	}

	public function onNoteHoldDrop(direction:Int, ?suffix:String = ""):Void {
		playMissAnimation(direction, suffix);
	}

	function playMissAnimation(direction:Int, ?suffix:String = ""):Void {
		var candidates:Array<String> = [
			buildSingAnimationName(direction, true, suffix),
			buildSingAnimationName(direction, true),
			buildSingAnimationName(direction, false, suffix),
			buildSingAnimationName(direction, false)
		];

		for(animName in candidates) {
			if(hasAnimation(animName)) {
				playNoDanceAnim(animName, true);
				holdTimer = 0;
				return;
			}
		}
	}

	public function resetCharacter(reapplyDance:Bool = true):Void {
		visible = true;
		alpha = 1;
		color = FlxColor.WHITE;
		angle = 0;
		specialAnim = false;
		customAnimation = false;
		holdTimer = 0;
		stunned = false;

		if(reapplyDance) dance(true);
	}

	public function updateFinalized(x:Float, y:Float):Void {
		finalizedX = x;
		finalizedY = y;
	}

	public function refresh(character:String, camPos:FlxPoint):Void {
		setPosition(finalizedX, finalizedY);

		if(_info != null && _info.position != null) {
			x += _info.position.get("x");
			y += _info.position.get("y");

			camPos.set(getGraphicMidpoint().x, getGraphicMidpoint().y);
			camPos.x += _info.position.get("camPosX");
			camPos.y += _info.position.get("camPosY");
		}
	}

	function get_cameraFocusPoint():FlxPoint {
		cameraFocusPointCache.set(getGraphicMidpoint().x, getGraphicMidpoint().y);

		if(_info != null && _info.position != null) {
			cameraFocusPointCache.x += _info.position.get("camPosX");
			cameraFocusPointCache.y += _info.position.get("camPosY");
		}

		return cameraFocusPointCache;
	}

	public function getDeathCameraOffsets():Array<Float> {
		return [0, 0];
	}

	public function getDeathCameraZoom():Float {
		return 1;
	}

	public function getDeathQuote():String {
		return null;
	}

	override function update(elapsed:Float):Void {
		if(!isDead && !debugMode) {
			var current:String = getCurrentAnimation();

			if(specialAnim && isAnimationFinished() && !customAnimation) {
				specialAnim = false;
				dance();
			}

			if(isSinging()) {
				holdTimer += elapsed;
				var singTimeSec:Float = singTimeSteps * (Conductor.instance.stepLengthMs / Constants.MS_PER_SEC);
				if(current != null && current.endsWith("miss")) singTimeSec *= 2;

				if(holdTimer > singTimeSec) {
					holdTimer = 0;
					dance(true);
				}
			} else {
				holdTimer = 0;
			}
		}

		super.update(elapsed);
	}

	function get__info():ConfigCharacters {
		if(_info == null) {
			return {
				file: "",
				animations: [],
				position: [],
				icon: [0, 0, 0],
				playAnim: "idle",
				isPlayer: false,
				pixel: false,
				iconFile: "iconGrid",
				clippingAdjustment: []
			};
		}

		return DefaultHandler.setupUpdateInfo(_info);
	}
}
