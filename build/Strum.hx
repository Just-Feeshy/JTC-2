package;

import flixel.FlxG;
import flixel.FlxCamera;
import flixel.FlxSprite;
import flixel.util.FlxColor;

using StringTools;

class Strum extends feshixl.FeshSprite {
	public var noteData(get, never):Int;
	public var direction(get, never):String;

	public var ifCustom:String = "regular";
	public var ifOpponent:Bool;
	public var onlyFans:Float;
	public var xAxis:Bool;

	public var directionAngle:Float = 0; //This is in radians.
	public var holdTimer:Float = 0;
	public var keyHeld:Bool = false;
	public var sustainHeld:Bool = false;
	public var confirmHoldUsesConfirmFallback:Bool = false;

	public var prevVisible:Bool = true;
	public var onlyVisible:Bool = true;

	private var rendered:Bool = false;

	override public function new(x:Float, y:Float) {
		super(x, y);

		onlyFans = 1;

		if(Main.feeshmoraModifiers && DefaultHandler.modifiers.blindEffect.enabled) {
			visible = false;
		}
	}

	override function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void {
		if(AnimName == 'confirm' && !rendered) {
			updateFrameSizeOffset(0, -1, 'confirm');
			rendered = true;
		}

		super.playAnim(AnimName, Force, Reversed, Frame);

		centerOffsets();
		centerOrigin();
	}

	private function getModernPrefix(base:String):Null<String> {
		var suffix:Null<String> = switch(direction) {
			case "left": "Left";
			case "down": "Down";
			case "up": "Up";
			case "right": "Right";
			default: null;
		}

		return suffix == null ? null : base + suffix;
	}

	private function atlasHasPrefix(prefix:Null<String>):Bool {
		if(prefix == null || frames == null || frames.frames == null) {
			return false;
		}

		for(frame in frames.frames) {
			if(frame != null && frame.name != null && frame.name.startsWith(prefix)) {
				return true;
			}
		}

		return false;
	}

	private function addAnimationWithFallback(name:String, prefixes:Array<Null<String>>, frameRate:Int = 24, loop:Bool = false):Null<String> {
		for(prefix in prefixes) {
			if(atlasHasPrefix(prefix)) {
				animation.addByPrefix(name, prefix, frameRate, loop);
				return prefix;
			}
		}

		return null;
	}

	public function hasAnimation(animName:String):Bool {
		return animation != null && animation.getByName(animName) != null;
	}

	public function hasDedicatedConfirmHold():Bool {
		return hasAnimation("confirm-hold") && !confirmHoldUsesConfirmFallback;
	}

	public function isConfirmAnimation():Bool {
		var animName:String = getAnimName();
		return animName == "confirm" || animName == "confirm-hold";
	}

	public function setupAnimations():Void {
		addAnimationWithFallback('static', [
			getModernPrefix('static'),
			'arrow' + direction.toUpperCase()
		], 24, false);
		addAnimationWithFallback('pressed', [
			getModernPrefix('press'),
			direction + ' press'
		], 24, false);
		addAnimationWithFallback('confirm', [
			getModernPrefix('confirm'),
			direction + ' confirm0',
			direction + ' confirm'
		], 24, false);
		var confirmPrefix:Null<String> = getModernPrefix('confirm');
		var legacyConfirmZero:String = direction + ' confirm0';
		var legacyConfirm:String = direction + ' confirm';
		var confirmHoldPrefix:Null<String> = addAnimationWithFallback('confirm-hold', [
			getModernPrefix('confirmHold'),
			confirmPrefix,
			legacyConfirmZero,
			legacyConfirm
		], 24, false);
		confirmHoldUsesConfirmFallback = confirmHoldPrefix == confirmPrefix
			|| confirmHoldPrefix == legacyConfirmZero
			|| confirmHoldPrefix == legacyConfirm;

		updateHitbox();
	}

	public function getAnimName():String {
		if(animation.curAnim == null) {
			return "";
		}

		return animation.curAnim.name;
	}

	/**
	*Use this function instead of the visible value.
	*/
	public function setVisibility(visibility:Bool):Bool {
		prevVisible = visible;
		visible = visibility;
		return visible;
	}

	function get_noteData():Int {
		return ID;
	}

	function get_direction():String {
		if(PlayState.SONG.fifthKey) {
			switch(noteData) {
				case 0: return "left";
				case 1: return "down";
				case 2: return "space";
				case 3: return "up";
				case 4: return "right";
			}
		}else {
			switch(noteData) {
				case 0: return "left";
				case 1: return "down";
				case 2: return "up";
				case 3: return "right";
			}
		}

		return "";
	}

	override function update(elapsed:Float):Void {
		if(holdTimer > 0) {
			holdTimer -= elapsed;

			if(holdTimer < 0) {
				playAnim('static');
				holdTimer = 0;
			}
		}

		if(Main.feeshmoraModifiers && DefaultHandler.modifiers != null) {
			if((animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && DefaultHandler.modifiers.blindEffect.enabled) {
				visible = false;
			}

			if(!(animation.curAnim.name == 'static' || animation.curAnim.name == 'pressed') && DefaultHandler.modifiers.blindEffect.enabled && visible == false) {
				visible = true;
			}
		}

		#if (debug || USING_MOD_DEBUG)
		if (FlxG.keys.pressed.TWO) {
			directionAngle += elapsed;
		}
		#end

		super.update(elapsed);
	}

	override function drawSimple(camera:FlxCamera):Void
	{
		var noteCamera:CameraNote = Std.isOfType(camera, CameraNote) ? cast camera : null;

		if(noteCamera != null && noteCamera.isNotePassActive()) {
			noteCamera.beginNoteSpriteDraw(false);
		}

		super.drawSimple(camera);

		if(noteCamera != null && noteCamera.isNotePassActive()) {
			noteCamera.endNoteSpriteDraw();
		}
	}

	override function drawComplex(camera:FlxCamera):Void
	{
		var noteCamera:CameraNote = Std.isOfType(camera, CameraNote) ? cast camera : null;

		if(noteCamera != null && noteCamera.isNotePassActive()) {
			noteCamera.beginNoteSpriteDraw(false);
		}

		super.drawComplex(camera);

		if(noteCamera != null && noteCamera.isNotePassActive()) {
			noteCamera.endNoteSpriteDraw();
		}
	}
}
