package example_code;

import flixel.FlxG;
import flixel.math.FlxMath;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxDestroyUtil.IFlxDestroyable;
import feshixl.group.FeshEventGroup.IFeshEvent;

using StringTools;

/**
* Not important
**/
typedef Modifiers = {
    var modSkill:String;
    var modGridY:Int;
    var modValue:String;
    var modValueTwo:String;
    var modDisplayName:String;
}

/**
* Alittle example of how to make your own events in Feeshmora.
* And also a reminder for me when I ever be dumb again.
*
* Implementing `IFlxDestroyable` is optional, only when you are storing variables
* and want to remove them to prevent memory leaks.
*
* @author Feeshy
*/
class DefaultEvents implements IFeshEvent implements IFlxDestroyable {
    private var eventTweens:Map<String, FlxTween>;
    private var offsetBounce:Int = 0;

    public function new() {
        eventTweens = new Map<String, FlxTween>();
    }

    public function whenTriggered(eventName:String, eventValue:String, eventValue2:String, playState:PlayState) {
        if(eventName == "flip chart") {
            playState.notes.forEachAlive(function(daNote:Note) {
                if(PlayState.SONG.fifthKey)
                    daNote.noteData = Std.int(Math.abs(daNote.noteData-(5-1)));
                else
                    daNote.noteData = Std.int(Math.abs(daNote.noteData-(4-1)));

                daNote.refresh(PlayState.SONG.fifthKey);
                daNote.refresh(PlayState.SONG.fifthKey, true);
            });

            for(i in 0...playState.unspawnNotes.length) {
                var note:Note = playState.unspawnNotes[i];

                if(PlayState.SONG.fifthKey)
                    note.noteData = Std.int(Math.abs(note.noteData-(5-1)));
                else
                    note.noteData = Std.int(Math.abs(note.noteData-(4-1)));

                note.refresh(PlayState.SONG.fifthKey);
                note.refresh(PlayState.SONG.fifthKey, true);
            }
        }else if(eventName == "blind effect") {
            playState.camGame.alpha = 0;
        }else if(eventName == "alt animation") {
            if(eventValue2.contains("bf") || eventValue2.contains("boyfriend"))
                playState.playerAltAnim = eventValue;
            else
                playState.opponentAltAnim = eventValue;
        }else if(eventName == "jumpspeed") {
            storeTween(eventName, FlxTween.tween(Note, {AFFECTED_SCROLLSPEED : Std.parseFloat(eventValue)}, (Conductor.stepCrochet/1000) * Std.parseFloat(eventValue2), {
                onComplete: function(tween:FlxTween) {
                    cancelTween(eventName);
                }
            }));
        }else if(eventName == "sicko shake") {
			DefaultHandler.shakeCamTimer = Std.parseInt(eventValue);
			DefaultHandler.shakeCamTimerHUD = Std.parseInt(eventValue2);
		}else if(eventName == "time freeze") {
            if(Std.parseInt(eventValue) == 0 && !FlxG.sound.music.playing)
				playState.resyncVocals();

			storeTween(eventName, FlxTween.tween(playState, {timeFreeze : Std.parseFloat(eventValue)}, (Conductor.crochet/500) * Std.parseFloat(eventValue2), {
                onComplete: function(tween:FlxTween) {
                    if(Std.parseInt(eventValue) == 1) {
                        playState.pauseMusic();
                    }

                    cancelTween(eventName);
                }
            }));
        }else if(eventName == "strum bounce") {
            offsetBounce = Std.parseInt(eventValue2);
			DefaultHandler.sizeTimer = Std.parseInt(eventValue);

			if(playState.flipWiggle >= 1)
				playState.flipWiggle = -1;
			else
				playState.flipWiggle = 1;
		}else if(eventName == "note rewind") {
			FlxTween.tween(Note, {AFFECTED_STRUMTIME : Std.parseFloat(eventValue)}, (Conductor.stepCrochet/500) * Std.parseFloat(eventValue2));
        }else if(eventName == "character change") {
            if(eventValue2.contains("dad")) {
                if(DefaultHandler.getcharacterJSON().contains(eventValue.toLowerCase())) {
                    playState.remove(playState.dad);
                    playState.dad.destroy();
                    playState.dad = new Character(100, 100, eventValue);
                    playState.dad.refresh(eventValue, playState.camPos);
                    playState.add(playState.dad);
                }
            }else if(eventValue2.contains("bf") || eventValue2.contains("boyfriend")) {
                if(DefaultHandler.getcharacterJSON().contains(eventValue.toLowerCase())) {
                    playState.remove(playState.dad);
                    playState.dad.destroy();
                    playState.dad = new Character(100, 100, eventValue);
                    playState.dad.refresh(eventValue, playState.camPos);
                    playState.add(playState.dad);
                }
            }
        }else if(eventName == "clear events") {
            if(PlayState.modStorage.contains(eventValue)) {
                PlayState.modStorage.remove(eventValue);
            }

            if(PlayState.modStorage.contains(eventValue2)) {
                PlayState.modStorage.remove(eventValue2);
            }
        }else if(eventName == "clear all") {
            PlayState.modStorage.splice(0, PlayState.modStorage.length);
            PlayState.modStorage = [];
        }
    }

    public function whenGameIsRunning(activeEvents:Array<String>, playState:PlayState):Void {
        if(activeEvents.contains("strum bounce")) {
            DefaultHandler.strumOffsetEvent[0] = FlxMath.lerp(offsetBounce * playState.flipWiggle, 0, DefaultHandler.sizeTimer/10);

            if(DefaultHandler.sizeTimer <= 0) {
                for(i in 0...activeEvents.length) {
                    if(activeEvents[i] == "strum bounce")
                        activeEvents.remove("strum bounce");
                }
            }
        }else {
            offsetBounce = 0;
        }

        if(activeEvents.contains("sicko shake")) {

        }
    }

    public function whenNoteIsPressed(note:Note, playState:PlayState):Void {
        return;
    }

    public function destroy():Void {
        if(eventTweens != null) {
            for(k in eventTweens.keys()) {
                var tween:FlxTween = eventTweens.get(k);

                if(tween != null) {
                    tween.cancel();
                    tween.destroy();
                }
            }

            eventTweens.clear();
            eventTweens = null;
        }
    }

    function cancelTween(name:String):Void {
        eventTweens.get(name).cancel();
        eventTweens.get(name).destroy();
        eventTweens.remove(name);
    }

    function storeTween(name:String, tween:FlxTween):Void {
        if(eventTweens != null) {
            if(eventTweens.exists(name)) {
                cancelTween(name);
            }

            eventTweens.set(name, tween);
        }
    }
}