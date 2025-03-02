package;

import flixel.FlxG;
import flixel.math.FlxRect;
import flixel.math.FlxPoint;
import flixel.util.FlxAxes;
import flixel.animation.FlxBaseAnimation;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.graphics.frames.FlxFilterFrames;
import feshixl.ui.FeshFramesHelper;
import openfl.filters.BitmapFilter;
import openfl.utils.Assets;
import json2object.JsonParser;

import ModInitialize;

using StringTools;

class Character extends feshixl.FeshSprite {
	private var finalizedX:Float;
	private var finalizedY:Float;

	public var animOffsets:Map<String, Array<Float>>;
	public var animations:Array<String>;
	public var debugMode:Bool = false;
	public var specialAnim:Bool = false;

	public var ogFrames(default, null):FlxFramesCollection;

	public var dancing(default, null):Bool = false;
	public var singMultiplier:Float = 4;

	public var curCharacter:String = 'bf';

	public var customAnimation:Bool = false;

	public var holdTimer:Float = 0;

	public var isPlayer:Bool = false;
	public var stunned:Bool = false;
	public var shouldPlayDance:Bool = true;
	public var hasBePlayer:String = "";

	@:isVar public var _info(get, default):ConfigCharacters;

	public var finalizedWidth(default, null):Float = 0;
	public var finalizedHeight(default, null):Float = 0;

	public var danceBeatTimer:Int = 1;

	private var testClip:Map<String, Array<Int>> = ["idle" => [-600, 100]];

	public function new(x:Float, y:Float, ?character:String = "bf", ?isPlayer:Bool = false, ?hardInfo:ConfigCharacters, frameOffsetApply:Bool = true)
	{
		super(x, y);

		useAdvanceClipping = false;

		finalizedX = x;
		finalizedY = y;

		animOffsets = new Map<String, Array<Float>>();
		animations = new Array<String>();
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

				if(_info.file.split(".")[1] == "xml")
					frames = Paths.getSparrowAtlas(_info.file.split(".")[0], "shared", true);
				else if(_info.file.split(".")[1] == "json")
					frames = Paths.getPackerAtlas(_info.file.split(".")[0], "shared", true);

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

				//#if windows // mac has a high DPI which does the fix for me
				#if (windows)
				if(frameOffsetApply && _info.clippingAdjustment.toString() != "{}") {
					ogFrames = FeshFramesHelper.copyFrames(frames);
				    frames = FeshFramesHelper.addOffsetInfo(ogFrames, _info.clippingAdjustment, false);
				    @:privateAccess animation.destroyAnimations();
					refreshAnims();
				}
				#end

				playAnim(_info.playAnim);
				flipX = _info.isPlayer;
		}

		dance();

		if (isPlayer)
			flipX = !flipX;
	}

	public function isAnimationFinished():Bool {
		if(animation.curAnim == null) {
			return false;
		}

		return animation.curAnim.finished;
	}

	public function finishAnimation():Void {
		if(animation.curAnim == null) return;
		animation.curAnim.finish();
	}

	override function update(elapsed:Float) {
		if(animation.curAnim == null) {
			return;
		}

		if (!isPlayer) {
			if (animation.curAnim.name.startsWith('sing')) {
				holdTimer += elapsed;
			}

			if (curCharacter == 'dad') {
				singMultiplier = 6.1;
			}

			if (holdTimer >= Conductor.stepCrochet * singMultiplier * 0.0011) {
				dance();
				holdTimer = 0;
			}
		}


		if(animation.curAnim.name.endsWith('miss') && isAnimationFinished()) {
		     dance();
			 finishAnimation();
		}

		switch (curCharacter) {
			case 'gf' | 'fesh':
				if (animation.curAnim.name == 'hairFall' && animation.curAnim.finished)
					playAnim('danceRight');
		}

		super.update(elapsed * (FlxG.save.data.showAntialiasing ? 1 : 0.75));
	}

	override function destroy() {
		super.destroy();

		if(animOffsets != null) {
			animOffsets.clear();
		}

		curCharacter = null;

		animOffsets = null;
		animations = null;
		_info = null;
	}

	private var danced:Bool = false;

	/**
	 * FOR GF DANCING SHIT
	 */
	public function dance()
	{
		if (!debugMode)
		{
			dancing = true;

			switch (curCharacter)
			{
				case 'gf' | 'fesh':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim('danceRight');
						else
							playAnim('danceLeft');
					}

				case 'gf-christmas':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim('danceRight');
						else
							playAnim('danceLeft');
					}

				case 'gf-car':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim('danceRight');
						else
							playAnim('danceLeft');
					}
				case 'gf-pixel':
					if (!animation.curAnim.name.startsWith('hair'))
					{
						danced = !danced;

						if (danced)
							playAnim('danceRight');
						else
							playAnim('danceLeft');
					}

				case 'spooky':
					danced = !danced;

					if (danced)
						playAnim('danceRight');
					else
						playAnim('danceLeft');
				default:
					playAnim('idle');
			}
		}
	}

	public function getAnimName():String {
		if(animation.curAnim == null) {
			return "";
		}

		return animation.curAnim.name;
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

		if(animations.length == 0) {
			return;
		}

		if(AnimName.startsWith('sing')) {
			animation.reset();
		}

		super.playAnim(AnimName, Force, Reversed, Frame);
		//animation.play(AnimName, Force, Reversed, Frame);

		var daOffset = animOffsets.get(AnimName);

		if (animOffsets.exists(AnimName)) {
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

		return parser.fromJson(Assets.getText(Paths.getPreloadPath('$character.json')), '${character.split('/')[1]}.json');
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
