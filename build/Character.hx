package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.math.FlxRect;
import flixel.math.FlxPoint;
import flixel.util.FlxAxes;
import flixel.animation.FlxBaseAnimation;
import flixel.animation.FlxAnimation;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFilterFrames;
import flixel.graphics.frames.FlxFrame;
import feshixl.FeshMinSprite;
import openfl.filters.BitmapFilter;
import openfl.utils.Assets;
import json2object.JsonParser;

import ModInitialize;

using StringTools;

class Character extends feshixl.FeshSprite {
	private static inline var DEFAULT_ANTIALIASING_UPDATE_MULTIPLIER:Float = 1.0;
	private static var singDirections:Array<String> = ["LEFT", "DOWN", "UP", "RIGHT"];
	private var finalizedX:Float;
	private var finalizedY:Float;

	public var animOffsets:Map<String, Array<Float>>;
	public var animations:Array<String>;
	public var animationAliases:Map<String, String>;
	public var animationSetSuffix:String = "";
	public var queuedAnimationSetSuffix:String = "";
	public var queuedAnimationSetSwitchStep:Int = -1;
	public var queuedAnimationSetSwitchOnNextNoteHit:Bool = false;
	public var debugMode:Bool = false;
	public var specialAnim:Bool = false;

	public var ogFrames(default, null):FlxFramesCollection;

	public var dancing(default, null):Bool = false;
	public var singMultiplier:Float = 4;
	public var singTimeSteps:Float = 4;

	public var curCharacter:String = 'bf';

	public var customAnimation:Bool = false;
	public var canPlayOtherAnims:Bool = false;
	public var isDead:Bool = false;

	public var holdTimer:Float = 0;

	public var isPlayer:Bool = false;
	public var stunned:Bool = false;
	public var shouldPlayDance:Bool = true;
	public var hasBePlayer:String = "";
	public var idleSuffix:String = "";

	@:isVar public var _info(get, default):ConfigCharacters;

	public var finalizedWidth(default, null):Float = 0;
	public var finalizedHeight(default, null):Float = 0;

	public var danceBeatTimer:Int = 1;
	private var cameraFocusPointCache:FlxPoint = new FlxPoint();

	private var testClip:Map<String, Array<Int>> = ["idle" => [-600, 100]];

	public function new(x:Float, y:Float, ?character:String = "bf", ?isPlayer:Bool = false, ?hardInfo:ConfigCharacters, frameOffsetApply:Bool = true)
	{
		super(x, y);

		useAdvanceClipping = false;

		finalizedX = x;
		finalizedY = y;

		animOffsets = new Map<String, Array<Float>>();
		animations = new Array<String>();
		animationAliases = new Map<String, String>();
		curCharacter = character;
		this.isPlayer = isPlayer;

		switch (character)
		{
			/**
			add a case if you want to hard code it
			**/
		    case "none":
			default:
				if(hardInfo == null)
					_info = cast loadInfo('characters/${curCharacter}');
				else
					_info = hardInfo;

				frames = loadCharacterFrames(_info.file);

				setIndexis(curCharacter);

				for(anim in _info.animations.keys()) {
					animations.push(anim);
					animation.addByPrefix(anim, _info.animations.get(anim).prefix, _info.animations.get(anim).framerate, _info.animations.get(anim).looped);
					addOffset(anim, _info.animations.get(anim).offset[0], _info.animations.get(anim).offset[1]);

					if(anim.endsWith("player") && isPlayer) {
						hasBePlayer = "player";
					}
				}

				finalizedWidth = width;
				finalizedHeight = height;

				if(_info.pixel) {
					setGraphicSize(Std.int(width * PlayState.daPixelZoom));
					updateHitbox();
				}

				if(FlxG.save.data.showAntialiasing)
					antialiasing = !_info.pixel;
				else
					antialiasing = false;

				playAnim(_info.playAnim);
				flipX = _info.isPlayer;
		}

		if(curCharacter == "dad") {
			singMultiplier = 6.1;
		}

		singTimeSteps = singMultiplier;

		dance();

		if (isPlayer)
			flipX = !flipX;
	}

	static function loadCharacterFrames(fileList:String):FlxFramesCollection {
		var files:Array<String> = [];

		if(fileList != null) {
			for(file in fileList.split(",")) {
				var trimmedFile:String = file.trim();

				if(trimmedFile.length > 0) {
					files.push(trimmedFile);
				}
			}
		}

		if(files.length <= 1) {
			return FeshMinSprite.loadFrameCollection(files.length == 1 ? files[0] : fileList);
		}

		var frameCollections:Array<FlxFramesCollection> = [];

		for(file in files) {
			frameCollections.push(FeshMinSprite.loadFrameCollection(file));
		}

		return FlxAnimationUtil.combineAtlas(frameCollections);
	}

	public function isAnimationFinished():Bool {
		if(animation.curAnim == null) {
			return false;
		}

		return animation.curAnim.finished;
	}

	public function hasAnimation(animName:String):Bool {
		var resolvedAnimName = resolveAnimationName(animName);
		return animation != null && animation.getByName(resolvedAnimName) != null;
	}

	public function setAnimationAlias(sourceAnimation:String, targetAnimation:String):Void {
		if(sourceAnimation == null || targetAnimation == null) {
			return;
		}

		animationAliases.set(sourceAnimation, targetAnimation);
	}

	public function setAnimationSetSuffix(suffix:String):Void {
		animationSetSuffix = suffix != null ? suffix : "";
	}

	public function queueAnimationSetSuffixSwitchOnNextNoteHit(step:Int, suffix:String):Void {
		queuedAnimationSetSwitchStep = step;
		queuedAnimationSetSuffix = suffix != null ? suffix : "";
		queuedAnimationSetSwitchOnNextNoteHit = true;
	}

	public function clearQueuedAnimationSetSuffixSwitch():Void {
		queuedAnimationSetSuffix = "";
		queuedAnimationSetSwitchStep = -1;
		queuedAnimationSetSwitchOnNextNoteHit = false;
	}

	public function clearAnimationAlias(sourceAnimation:String):Void {
		if(sourceAnimation == null || animationAliases == null) {
			return;
		}

		animationAliases.remove(sourceAnimation);
	}

	public function warmAnimationFrames(animName:String):Void {
		var resolvedAnimName:String = resolveAnimationName(animName);

		if(animation == null || frames == null || frames.frames == null) {
			return;
		}

		var anim:FlxAnimation = animation.getByName(resolvedAnimName);

		if(anim == null || anim.frames == null) {
			return;
		}

		for(frameIndex in anim.frames) {
			if(frameIndex < 0 || frameIndex >= frames.frames.length) {
				continue;
			}

			var frame:FlxFrame = frames.frames[frameIndex];

			if(frame != null) {
				@:privateAccess frame.cacheFrameMatrix();
			}
		}
	}

	public function warmAnimations(animNames:Array<String>):Void {
		if(animNames == null) {
			return;
		}

		for(animName in animNames) {
			warmAnimationFrames(animName);
		}
	}

	function resolveAnimationName(animName:String):String {
		if(animName == null) {
			return animName;
		}

		var resolvedAnimName = animName;

		if(animationAliases != null) {
			var aliasName = animationAliases.get(animName);

			if(aliasName != null) {
				resolvedAnimName = aliasName;
			}
		}

		if(animation != null && animationSetSuffix != null && animationSetSuffix != "") {
			var suffixedAnimName = resolvedAnimName + animationSetSuffix;

			if(animation.getByName(suffixedAnimName) != null) {
				return suffixedAnimName;
			}
		}

		return resolvedAnimName;
	}

	function applyQueuedAnimationSetSwitchOnNoteHit():Void {
		if(!queuedAnimationSetSwitchOnNextNoteHit) {
			return;
		}

		if(Conductor.instance == null || Conductor.instance.currentStep < queuedAnimationSetSwitchStep) {
			return;
		}

		setAnimationSetSuffix(queuedAnimationSetSuffix);
		clearQueuedAnimationSetSuffixSwitch();
	}

	public function playAnimation(animName:String, force:Bool = false, reversed:Bool = false, frame:Int = 0):Void {
		playAnim(animName, force, reversed, frame);
	}

	public function getCurrentAnimation():String {
		return getAnimName();
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

		if(reapplyDance) {
			dance();
		}
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

	public var cameraFocusPoint(get, never):FlxPoint;

	function get_cameraFocusPoint():FlxPoint {
		cameraFocusPointCache.set(getGraphicMidpoint().x, getGraphicMidpoint().y);

		if(_info != null && _info.position != null) {
			var camPosX:Dynamic = _info.position.get('camPosX');
			var camPosY:Dynamic = _info.position.get('camPosY');

			cameraFocusPointCache.x += camPosX != null ? camPosX : 0;
			cameraFocusPointCache.y += camPosY != null ? camPosY : 0;
		}

		return cameraFocusPointCache;
	}

	public function finishAnimation():Void {
		if(animation.curAnim == null) return;
		animation.curAnim.finish();
	}

	function repairInvalidAnimationState():Void {
		if(animation == null || animation.curAnim == null) {
			return;
		}

		if(animation.curAnim.frames != null) {
			return;
		}

		animation.play(null);

		playPreferredIdle(true);
	}

	override function update(elapsed:Float) {
		if(Std.isOfType(shader, RimShadowShader)) {
			cast(shader, RimShadowShader).updateFrameInfo(frame);
		}

		repairInvalidAnimationState();

		var currentAnimation:String = getAnimName();

		if(currentAnimation != "") {
			if(specialAnim && isAnimationFinished()) {
				if(!customAnimation) {
					specialAnim = false;
					dance();
					currentAnimation = getAnimName();
				}
			}

			if(isAnimationFinished()
				&& !currentAnimation.endsWith(Constants.ANIMATION_HOLD_SUFFIX)
				&& hasAnimation(currentAnimation + Constants.ANIMATION_HOLD_SUFFIX)) {
				playAnim(currentAnimation + Constants.ANIMATION_HOLD_SUFFIX);
				currentAnimation = getAnimName();
			}

			if(isSinging()) {
				holdTimer += elapsed;

				var singTimeSec:Float = singTimeSteps * (Conductor.instance.stepLengthMs / Constants.MS_PER_SEC);

				if(currentAnimation.endsWith("miss")) {
					singTimeSec *= 2;
				}

				var shouldStopSinging:Bool = isControlledByPlayer() ? !isHoldingNote() : true;

				if(holdTimer > singTimeSec && shouldStopSinging) {
					holdTimer = 0;

					var nextAnimation:String = currentAnimation;

					if(nextAnimation.endsWith(Constants.ANIMATION_HOLD_SUFFIX)) {
						nextAnimation = nextAnimation.substr(0, nextAnimation.length - Constants.ANIMATION_HOLD_SUFFIX.length);
					}

					var endAnimation:String = nextAnimation + Constants.ANIMATION_END_SUFFIX;

					if(hasAnimation(endAnimation)) {
						playAnim(endAnimation);
					}else {
						dance(true);
					}
				}
			}else {
				holdTimer = 0;
			}

			switch (curCharacter) {
				case 'gf' | 'fesh':
					if (currentAnimation == 'hairFall' && isAnimationFinished())
						playAnim('danceRight');
			}
		}

		super.update(elapsed * (FlxG.save.data.showAntialiasing ? 1 : DEFAULT_ANTIALIASING_UPDATE_MULTIPLIER));
	}

	override function destroy() {
		if(Std.isOfType(frames, CombinedAtlasFrames)) {
			cast(frames, CombinedAtlasFrames).destroy();
		}

		super.destroy();

		if(animOffsets != null) {
			animOffsets.clear();
		}

		if(animationAliases != null) {
			animationAliases.clear();
		}

		curCharacter = null;

		animOffsets = null;
		animationAliases = null;
		animations = null;
		_info = null;
	}

	private var danced:Bool = false;

	/**
	 * FOR GF DANCING SHIT
	 */
	public function dance(force:Bool = false)
	{
		if(isDead) {
			return;
		}

		if (!debugMode)
		{
			if(!force) {
				if(specialAnim) {
					return;
				}

				if(isSinging()) {
					return;
				}

				var currentAnimation:String = getAnimName();

				if(currentAnimation != ""
					&& !currentAnimation.startsWith("dance")
					&& !currentAnimation.startsWith("idle")
					&& !isAnimationFinished()) {
					return;
				}
			}

			dancing = true;

			switch (curCharacter)
			{
				case 'gf' | 'fesh':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim(resolveIdleAnimationName('danceRight'));
						else
							playAnim(resolveIdleAnimationName('danceLeft'));
					}

				case 'gf-christmas':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim(resolveIdleAnimationName('danceRight'));
						else
							playAnim(resolveIdleAnimationName('danceLeft'));
					}

				case 'gf-car':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim(resolveIdleAnimationName('danceRight'));
						else
							playAnim(resolveIdleAnimationName('danceLeft'));
					}
				case 'gf-pixel':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim(resolveIdleAnimationName('danceRight'));
						else
							playAnim(resolveIdleAnimationName('danceLeft'));
					}

				case 'spooky':
					danced = !danced;

					if (danced)
						playAnim(resolveIdleAnimationName('danceRight'));
					else
						playAnim(resolveIdleAnimationName('danceLeft'));
				default:
					playAnim(resolveIdleAnimationName('idle'));
			}
		}
	}

	public function getAnimName():String {
		if(animation.curAnim == null) {
			return "";
		}

		return animation.curAnim.name;
	}

	public function playPreferredIdle(force:Bool = false):Void {
		dance(force);
	}

	function resolveIdleAnimationName(baseName:String):String {
		if(idleSuffix != null && idleSuffix != "") {
			var suffixedName:String = baseName + idleSuffix;

			if(hasAnimation(suffixedName)) {
				return suffixedName;
			}
		}

		return baseName;
	}

	public function playNoDanceAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		dancing = false;
		playAnim(AnimName, Force, Reversed, Frame);
	}

	public function refreshAnims():Void {
		setIndexis(curCharacter);

		for(anim in _info.animations.keys()) {
			animation.addByPrefix(anim, _info.animations.get(anim).prefix, _info.animations.get(anim).framerate, _info.animations.get(anim).looped);
		}
	}

	override public function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		specialAnim = false;
		var resolvedAnimName = resolveAnimationName(AnimName);

		if(animations.length == 0) {
			return;
		}

		if(resolvedAnimName.startsWith('sing')) {
			dancing = false;
			animation.reset();
		}

		super.playAnim(resolvedAnimName, Force, Reversed, Frame);
		//animation.play(AnimName, Force, Reversed, Frame);

		var daOffset = animOffsets.get(AnimName);

		if(daOffset == null) {
			daOffset = animOffsets.get(resolvedAnimName);
		}

		if (daOffset != null) {
			offset.set(daOffset[0], daOffset[1]);
		}else {
			offset.set(0, 0);
		}

		if (curCharacter.startsWith('gf') || curCharacter == "fesh")
		{
			if (AnimName == 'singLEFT')
			{
				danced = true;
			}
			else if (AnimName == 'singRIGHT')
			{
				danced = false;
			}

			if (AnimName == 'singUP' || AnimName == 'singDOWN')
			{
				danced = !danced;
			}
		}
	}

	public function isSinging():Bool {
		var currentAnimation:String = getAnimName();
		return currentAnimation.startsWith("sing") && !currentAnimation.endsWith(Constants.ANIMATION_END_SUFFIX);
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
		if(singDirectionIndex < 0) {
			return "";
		}

		return 'sing${singDirections[singDirectionIndex]}${miss ? "miss" : ""}$suffix';
	}

	function isControlledByPlayer():Bool {
		return PlayState.instance != null && PlayState.instance.currentPlayer == this;
	}

	function isHoldingNote():Bool {
		if(!isControlledByPlayer()) {
			return false;
		}

		var controls = PlayerSettings.player1.controls;

		return controls != null
			&& (controls.LEFT || controls.DOWN || controls.UP || controls.RIGHT || controls.SPACE);
	}

	public function playSingAnimation(direction:Int, miss:Bool = false, ?suffix:String = ""):Void {
		var animName:String = buildSingAnimationName(direction, miss, suffix);
		if(animName != "") {
			playAnim(animName, true);
		}
	}

	public function playMissAnimation(direction:Int, ?suffix:String = ""):Void {
		if(getSingDirectionIndex(direction) < 0) {
			return;
		}

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

	public function onNoteHit(direction:Int, ?suffix:String = ""):Void {
		applyQueuedAnimationSetSwitchOnNoteHit();
		if(getSingDirectionIndex(direction) < 0) {
			return;
		}

		playSingAnimation(direction, false, suffix);
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

	public function addOffset(name:String, x:Float = 0, y:Float = 0):Void {
		animOffsets[name] = [x, y];
	}

	public function changeOffsets(name:String, value:Float, axes:FlxAxes):Void {
		if(axes == FlxAxes.X)
			animOffsets[name][0] = value;
		else if(axes == FlxAxes.Y)
			animOffsets[name][1] = value;
		else {
			animOffsets[name][0] = value;
			animOffsets[name][1] = value;
		}
	}

	public function updateFinalized(x:Float, y:Float):Void {
		finalizedX = x;
		finalizedY = y;
	}

	public static function loadInfo(character:String):ConfigCharacters {
		var parser:JsonParser<ConfigCharacters> = new JsonParser<ConfigCharacters>();

		return parser.fromJson(Paths.readText(Paths.getPreloadPath('$character.json')), '${character.split('/')[1]}.json');
	}

	public function refresh(character:String, camPos:FlxPoint) {
		this.setPosition(finalizedX, finalizedY);

		this.x += _info.position.get('x');
		this.y += _info.position.get('y');

		camPos.set(this.getGraphicMidpoint().x, this.getGraphicMidpoint().y);

		camPos.x += _info.position.get('camPosX');
		camPos.y += _info.position.get('camPosY');
	}

	function setIndexis(character:String):Void {
		switch(character) {
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

	function get__info():ConfigCharacters {
		if(_info == null) {
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
		}else {
			return DefaultHandler.setupUpdateInfo(_info);
		}
	}
}
