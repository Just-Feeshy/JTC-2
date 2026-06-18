package;

import flixel.FlxCamera;
import flixel.FlxSprite;
import flixel.animation.FlxAnimationController;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.math.FlxPoint;
import flixel.util.FlxAxes;
import flixel.util.FlxColor;

import ModInitialize.ConfigCharacters;

interface ICharacter extends IFlxSprite {
	var animation:FlxAnimationController;
	var cameras(get, set):Array<FlxCamera>;
	var color(default, set):FlxColor;
	var flipX(default, set):Bool;
	var frames(default, set):FlxFramesCollection;
	var height(get, set):Float;
	var width(get, set):Float;

	var animOffsets:Map<String, Array<Float>>;
	var animations:Array<String>;
	var canPlayOtherAnims:Bool;
	var cameraFocusPoint(get, never):FlxPoint;
	var curCharacter:String;
	var customAnimation:Bool;
	var danceBeatTimer:Int;
	var dancing(default, null):Bool;
	var debugMode:Bool;
	var hasBePlayer:String;
	var holdTimer:Float;
	var idleSuffix:String;
	var isDead:Bool;
	var isPlayer:Bool;
	var shouldPlayDance:Bool;
	var singMultiplier:Float;
	var singTimeSteps:Float;
	var specialAnim:Bool;
	var stunned:Bool;

	var _info(get, default):ConfigCharacters;

	function addOffset(name:String, x:Float = 0, y:Float = 0):Void;
	function changeOffsets(name:String, value:Float, axes:FlxAxes):Void;
	function dance(force:Bool = false):Void;
	function drawFrame(Force:Bool = false):Void;
	function finishAnimation():Void;
	function getCurrentAnimation():String;
	function getGraphicMidpoint(?point:FlxPoint):FlxPoint;
	function getScreenPosition(?result:FlxPoint, ?camera:FlxCamera):FlxPoint;
	function hasAnimation(animName:String):Bool;
	function isAnimationFinished():Bool;
	function isSinging():Bool;
	function onNoteGhostMiss(direction:Int, ?suffix:String = ""):Void;
	function onNoteHit(direction:Int, ?suffix:String = ""):Void;
	function onNoteHoldDrop(direction:Int, ?suffix:String = ""):Void;
	function onNoteMiss(direction:Int, ?suffix:String = ""):Void;
	function playAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void;
	function playAnimation(animName:String, force:Bool = false, reversed:Bool = false, frame:Int = 0):Void;
	function playNoDanceAnim(AnimName:String, Force:Bool = false, Reversed:Bool = false, Frame:Int = 0):Void;
	function playPreferredIdle(force:Bool = false):Void;
	function refresh(character:String, camPos:FlxPoint):Void;
	function resetCharacter(reapplyDance:Bool = true):Void;
	function setColorTransform(redMultiplier:Float = 1, greenMultiplier:Float = 1, blueMultiplier:Float = 1, alphaMultiplier:Float = 1,
		redOffset:Float = 0, greenOffset:Float = 0, blueOffset:Float = 0, alphaOffset:Float = 0):Void;
	function updateFinalized(x:Float, y:Float):Void;
}
