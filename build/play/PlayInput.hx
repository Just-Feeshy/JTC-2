package play;

import Controls.Control;
import Conductor;
import CustomNoteHandler;
import GhostTapping;
import Note;
import PlayState;
import SaveData.SaveType;
import Strum;
import flixel.FlxG;
import flixel.input.gamepad.FlxGamepadInputID;
import flixel.input.keyboard.FlxKey;
import openfl.events.Event;
import openfl.events.KeyboardEvent;

using StringTools;

@:access(PlayState)
class PlayInput
{
	private var playState:PlayState;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function controllerInput():Void
	{
		if(playState.modifierCheckList('bot mode')) {
			return;
		}

		var controlPressArray = getGamepadPressArray();
		var controlReleaseArray = getGamepadReleaseArray();
		var index:Int = 0;

		while(index < playState.getLaneCount()) {
			if (controlPressArray[index]) {
				queueLaneInput(index, true, getCurrentInputSongTime());
				playState.playLua.call('onKeyPress', [getPrimaryLaneKeyCode(index)]);
			}

			if (controlReleaseArray[index]) {
				queueLaneInput(index, false, getCurrentInputSongTime());
				playState.playLua.call('onKeyRelease', [getPrimaryLaneKeyCode(index)]);
			}

			index++;
		}
	}

	public function getReleased(event:Event):Void
	{
		if(playState.paused || playState.inCutscene || playState.modifierCheckList('bot mode'))
			return;

		var getEvent:KeyboardEvent = cast event;
		var index:Int = getKeyOrButton(getEvent.keyCode);

		if(index < 0 || index >= playState.getLaneCount()) {
			return;
		}

		var laneHeldKeys:Array<Int> = playState.heldLaneKeys[index];

		if(laneHeldKeys != null) {
			laneHeldKeys.remove(getEvent.keyCode);

			if(laneHeldKeys.length <= 0) {
				queueLaneInput(index, false, getCurrentInputSongTime());
			}
		}

		playState.playLua.call('onKeyRelease', [getEvent.keyCode]);
	}

	public function defaultGameStuff():Void
	{
		if(playState.paused || playState.inCutscene)
			return;

		var botMode:Bool = playState.modifierCheckList('bot mode');
		var controlHoldArray = botMode ? getBotControlHoldArray() : getControlHoldArray();

		if(botMode) {
			processBotplayNotes();
		}

		processInputQueue(controlHoldArray);
		refreshHeldStrums(controlHoldArray);
		processHeldNotes(controlHoldArray, getCurrentInputSongTime());
		playState.updateHoldCoverSprites(true, controlHoldArray);
		playState.updateHoldCoverSprites(false);

		if(playState.boyfriend.holdTimer > Conductor.instance.stepLengthMs * (0.0011 #if FLX_PITCH / FlxG.sound.music.pitch #end)
			* playState.boyfriend.singMultiplier
			&& playState.boyfriend.animation.curAnim.name.startsWith('sing')
			&& !playState.boyfriend.animation.curAnim.name.endsWith('miss')) {
			playState.boyfriend.dance();
		}
	}

	public function getPressed(event:Event):Void
	{
		if(playState.paused || playState.inCutscene || playState.disableInputs || playState.modifierCheckList('bot mode')) {
			return;
		}

		var getEvent:KeyboardEvent = cast event;
		var index:Int = getKeyOrButton(getEvent.keyCode);

		if(index < 0 || index >= playState.getLaneCount() || !playState.generatedMusic) {
			return;
		}

		var laneHeldKeys:Array<Int> = playState.heldLaneKeys[index];

		if(laneHeldKeys == null) {
			laneHeldKeys = [];
			playState.heldLaneKeys[index] = laneHeldKeys;
		}

		if(laneHeldKeys.contains(getEvent.keyCode)) {
			return;
		}

		laneHeldKeys.push(getEvent.keyCode);
		queueLaneInput(index, true, getCurrentInputSongTime());
		playState.playLua.call('onKeyPress', [getEvent.keyCode]);
	}

	function getLaneGamepadBinds():Array<FlxGamepadInputID>
	{
		var savedBinds:Array<Dynamic> = cast SaveData.getData(CUSTOM_GAMEPAD_BINDS);
		var defaultBinds:Array<FlxGamepadInputID> = [
			FlxGamepadInputID.LEFT_TRIGGER,
			FlxGamepadInputID.LEFT_SHOULDER,
			FlxGamepadInputID.RIGHT_SHOULDER,
			FlxGamepadInputID.RIGHT_TRIGGER,
			FlxGamepadInputID.X
		];

		inline function resolveBind(index:Int):FlxGamepadInputID {
			if(savedBinds != null && index < savedBinds.length && savedBinds[index] != null) {
				return cast savedBinds[index];
			}

			return defaultBinds[index];
		}

		if(PlayState.SONG.fifthKey) {
			return [resolveBind(0), resolveBind(1), resolveBind(4), resolveBind(2), resolveBind(3)];
		}

		return [resolveBind(0), resolveBind(1), resolveBind(2), resolveBind(3)];
	}

	function getControlHoldArray():Array<Bool>
	{
		if(PlayState.SONG.fifthKey) {
			return [
				playState.controls.GAME_LEFT,
				playState.controls.GAME_DOWN,
				playState.controls.GAME_SPACE,
				playState.controls.GAME_UP,
				playState.controls.GAME_RIGHT
			];
		}

		return [
			playState.controls.GAME_LEFT,
			playState.controls.GAME_DOWN,
			playState.controls.GAME_UP,
			playState.controls.GAME_RIGHT
		];
	}

	function getBotControlHoldArray():Array<Bool>
	{
		var values:Array<Bool> = [];
		var index:Int = 0;
		var songTime:Float = getCurrentInputSongTime();

		while(index < playState.getLaneCount()) {
			values.push(false);
			index++;
		}

		playState.notes.forEachAlive(function(daNote:Note) {
			if(daNote.mustPress
				&& daNote.isSustainNote
				&& !daNote.wasGoodHit
				&& daNote.noteData >= 0
				&& daNote.noteData < values.length
				&& daNote.canHoldHit(songTime)
				&& songTime >= daNote.getNoteTime()) {
				values[daNote.noteData] = true;
			}
		});

		return values;
	}

	function getGamepadPressArray():Array<Bool>
	{
		var gamepadBinds = getLaneGamepadBinds();
		var values:Array<Bool> = [];
		var index:Int = 0;

		while(index < playState.getLaneCount()) {
			var bind = gamepadBinds[index];
			values.push(FlxG.gamepads.anyJustPressed(bind));
			index++;
		}

		return values;
	}

	function getGamepadReleaseArray():Array<Bool>
	{
		var gamepadBinds = getLaneGamepadBinds();
		var values:Array<Bool> = [];
		var index:Int = 0;

		while(index < playState.getLaneCount()) {
			var bind = gamepadBinds[index];
			values.push(FlxG.gamepads.anyJustReleased(bind));
			index++;
		}

		return values;
	}

	function getPrimaryLaneKeyCode(lane:Int):Int
	{
		if(lane < 0 || lane >= playState.keys2DArray.length || playState.keys2DArray[lane] == null || playState.keys2DArray[lane].length == 0) {
			return FlxKey.NONE;
		}

		return playState.keys2DArray[lane][0];
	}

	function getCurrentInputSongTime():Float
	{
		if(FlxG.sound.music != null) {
			return FlxG.sound.music.time;
		}

		return Conductor.instance.trackedSongPosition;
	}

	function processBotplayNotes():Void
	{
		if(!playState.generatedMusic || playState.disableInputs) {
			return;
		}

		var songTime:Float = getCurrentInputSongTime();
		var lane:Int = 0;

		while(lane < playState.getLaneCount()) {
			var targetNote:Note = findTapNote(lane, songTime);

			while(targetNote != null && targetNote.shouldAutoHit(songTime)) {
				playStrumPress(lane);
				playState.goodNoteHit(targetNote, targetNote.getNoteTime());
				targetNote = findTapNote(lane, songTime);
			}

			lane++;
		}
	}

	function queueLaneInput(lane:Int, pressed:Bool, songTime:Float):Void
	{
		if(lane < 0 || lane >= playState.getLaneCount()) {
			return;
		}

		playState.inputQueue.push({lane: lane, pressed: pressed, songTime: songTime});

		if(pressed) {
			playStrumPress(lane);
		}else {
			var spr:Strum = playState.currentStrums.members[lane];

			if(spr != null) {
				spr.keyHeld = false;
			}
		}
	}

	function processInputQueue(controlHoldArray:Array<Bool>):Void
	{
		if(playState.inputQueue.length == 0) {
			return;
		}

		if(FlxG.sound.music != null) {
			playState.setSongPosition(FlxG.sound.music.time);
		}

		while(playState.inputQueue.length > 0) {
			var input = playState.inputQueue.shift();

			if(input == null) {
				continue;
			}

			if(input.pressed) {
				handleLanePress(input.lane, input.songTime);
			}else {
				handleLaneRelease(input.lane, controlHoldArray);
			}
		}
	}

	function getActiveSustainHoldArray(controlHoldArray:Array<Bool>):Array<Bool>
	{
		var values:Array<Bool> = [];
		var index:Int = 0;
		var songTime:Float = getCurrentInputSongTime();

		while(index < playState.getLaneCount()) {
			values.push(false);
			index++;
		}

		playState.notes.forEachAlive(function(daNote:Note) {
			var lane:Int = daNote.noteData;
			var chainActive:Bool = false;

			if(daNote.mustPress
				&& daNote.isSustainNote
				&& lane >= 0
				&& lane < values.length
				&& controlHoldArray[lane]) {
				if(daNote.wasGoodHit || daNote.shouldBeDead) {
					chainActive = true;
				}else if(daNote.canHoldHit(songTime)) {
					chainActive = true;
				}else if(songTime < daNote.getNoteTime()
					&& daNote.prevNote != null
					&& (daNote.prevNote.wasGoodHit || daNote.prevNote.shouldBeDead)) {
					chainActive = true;
				}
			}

			if(chainActive) {
				values[lane] = true;
			}
		});

		return values;
	}

	function refreshHeldStrums(controlHoldArray:Array<Bool>):Void
	{
		var sustainHoldArray:Array<Bool> = getActiveSustainHoldArray(controlHoldArray);

		playState.currentStrums.forEachAlive(function(spr:Strum) {
			if(!controlHoldArray[spr.ID]) {
				spr.keyHeld = false;
				spr.sustainHeld = false;

				if(spr.animation.curAnim != null
					&& (spr.animation.curAnim.name == "pressed" || spr.animation.curAnim.name == "confirm-hold")) {
					spr.playAnim('static');
					spr.holdTimer = 0;
				}
			}else {
				spr.keyHeld = true;
				spr.sustainHeld = sustainHoldArray[spr.ID];

				if(spr.animation.curAnim != null) {
					if(spr.sustainHeld) {
						if((spr.animation.curAnim.name == "static" || spr.animation.curAnim.name == "pressed")
							&& !CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)
							&& spr.hasDedicatedConfirmHold()) {
							spr.playAnim("confirm-hold");
						}else if(spr.animation.curAnim.name == "confirm"
							&& spr.animation.curAnim.finished
							&& spr.hasDedicatedConfirmHold()) {
							if(spr.hasDedicatedConfirmHold()) {
								spr.playAnim("confirm-hold");
							}
						}
					}else {
						if(spr.animation.curAnim.name == "static"
							&& !CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)) {
							spr.playAnim("pressed");
						}else if(spr.animation.curAnim.name == "confirm-hold"
							|| (spr.animation.curAnim.name == "confirm" && spr.holdTimer <= 0 && spr.animation.curAnim.finished)) {
							spr.playAnim("pressed");
						}
					}
				}
			}
		});
	}

	function shouldCatchHeldSustainNote(daNote:Note, currentSongTime:Float):Bool
	{
		if(playState.previousHeldInputSongTime == null || currentSongTime <= playState.previousHeldInputSongTime) {
			return false;
		}

		if(daNote.prevNote != null && !daNote.prevNote.wasGoodHit && !daNote.prevNote.shouldBeDead) {
			return false;
		}

		var noteTime:Float = daNote.getNoteTime();

		return noteTime > playState.previousHeldInputSongTime && noteTime <= currentSongTime;
	}

	function processHeldNotes(controlHoldArray:Array<Bool>, songTime:Float):Void
	{
		playState.notes.forEachAlive(function(daNote:Note) {
			if (daNote.mustPress && daNote.isSustainNote && !daNote.wasGoodHit
				&& controlHoldArray[daNote.noteData] && !playState.disableInputs
				&& (daNote.canHoldHit(songTime) || shouldCatchHeldSustainNote(daNote, songTime))) {
				playState.goodNoteHit(daNote, daNote.getNoteTime());
			}
		});

		playState.previousHeldInputSongTime = songTime;
	}

	function handleLanePress(lane:Int, hitSongTime:Float):Void
	{
		if(!playState.generatedMusic || playState.disableInputs) {
			return;
		}

		var targetNote = findTapNote(lane, hitSongTime);

		if(targetNote != null) {
			playState.goodNoteHit(targetNote, hitSongTime);
			return;
		}

		if(!GhostTapping.ghostTap) {
			playState.takeDamage(lane, true);
			playState.songScore -= 10;
			playState.setHealth(playState.health - 0.08);
			playState.missClicks++;
		}
	}

	function handleLaneRelease(lane:Int, controlHoldArray:Array<Bool>):Void
	{
		var spr:Strum = playState.currentStrums.members[lane];

		if(spr == null) {
			return;
		}

		spr.keyHeld = false;
		spr.sustainHeld = false;
		spr.holdTimer = 0;
		spr.playAnim('static');
		playState.endHoldCoverForLane(lane, true);
	}

	function findTapNote(lane:Int, hitSongTime:Float):Note
	{
		var inputNotes = playState.notes.members.filter(function(note:Note):Bool {
			return note != null
				&& note.mustPress
				&& note.noteData == lane
				&& !note.wasGoodHit
				&& !note.isSustainNote
				&& note.canPlayerHit(hitSongTime);
		});

		inputNotes.sort(function(a:Note, b:Note):Int {
			var timeDiff = a.getNoteTime() - b.getNoteTime();

			if(timeDiff < 0) return -1;
			if(timeDiff > 0) return 1;

			return 0;
		});

		if(inputNotes.length == 0) {
			return null;
		}

		var targetNote = inputNotes[0];
		var index:Int = 1;

		while(index < inputNotes.length) {
			var stackedNote = inputNotes[index];

			if(!targetNote.getNoteHittable(stackedNote)) {
				break;
			}

			playState.removeNote(stackedNote);
			index++;
		}

		return targetNote;
	}

	function playStrumPress(lane:Int):Void
	{
		var spr:Strum = playState.currentStrums.members[lane];

		if(spr == null || CustomNoteHandler.noNoteAbstractStrum.contains(spr.ifCustom)) {
			return;
		}

		spr.keyHeld = true;

		if(spr.animation.curAnim == null || !spr.isConfirmAnimation()) {
			spr.playAnim('pressed');
			spr.holdTimer = 0;
		}
	}

	function getKeyOrButton(keyCode:Int):Int
	{
		var index:Int = 0;

		if (keyCode != FlxKey.NONE) {
			while(index < playState.keys2DArray.length) {
				if(playState.keys2DArray[index].contains(keyCode)) {
					return index;
				}

				index++;
			}
		}

		return -1;
	}
}
