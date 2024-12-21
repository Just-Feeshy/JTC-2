package example_code;

import flixel.FlxG;
import flixel.math.FlxMath;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxDestroyUtil.IFlxDestroyable;
import feshixl.group.FeshEventGroup.IFeshEvent;
import lime.graphics.opengl.GLSync;
import lime.graphics.opengl.GL;
import SaveData.SaveType;

using StringTools;

/**
* Not important
*/
typedef EventInfo = {
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

    private var flipped:Bool = false;

    public function new() {
        eventTweens = new Map<String, FlxTween>();
    }

    public function whenTriggered(eventName:String, eventValue:String, eventValue2:String, playState:PlayState):Void {
        switch(eventName) {
            case "mirror chart":
                if(!flipped && eventValue == "0") {
                    return;
                }
    
                if(flipped && eventValue == "1") {
                    return;
                }
    
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
            case "sing drain":
                playState.singDrainValue = Std.parseInt(eventValue);
                DefaultHandler.modifiers.singDrain.enabled = true;
            case "fadein notes":
                playState.fadeInValue = Std.parseInt(eventValue);
                DefaultHandler.modifiers.fadeInNotes.enabled = true;
            case "blind effect":
                if(eventValue == "0") {
                    setModifierToDefault("blind effect");
                    playState.camGame.engineAlpha = 1;
                }
    
                if(eventValue == "1") {
                    DefaultHandler.modifiers.blindEffect.enabled = true;
                    playState.camGame.engineAlpha = 0;
                }
            case "note woggle":
                if(Std.parseFloat(eventValue) > 0) {
                    DefaultHandler.modifiers.wobbleNotes.enabled = true;
                }
    
                storeTween(eventName, FlxTween.tween(playState, {wobbleModPower : Std.parseFloat(eventValue)}, (Conductor.stepCrochet/500), {
                    onComplete: function(tween:FlxTween) {
                        if(playState.wobbleModPower == 0) {
                            setModifierToDefault("note woggle");
                        }
    
                        cancelTween(eventName);
                    }
                }));
            case "camera move":
                playState.cameraMovementInsensity = Std.parseFloat(eventValue);

                if(Std.parseFloat(eventValue) > 0) {
                    DefaultHandler.modifiers.wobbleNotes.enabled = true;
                }else {
                    setModifierToDefault("camera move");
                }
            case "alt animation":
                if(eventValue2.contains("bf") || eventValue2.contains("boyfriend"))
                    playState.playerAltAnim = eventValue;
                else
                    playState.opponentAltAnim = eventValue;
            case "jumpspeed":
                storeTween(eventName, FlxTween.tween(Note, {AFFECTED_SCROLLSPEED : Std.parseFloat(eventValue)}, (Conductor.stepCrochet/1000) * Std.parseFloat(eventValue2), {
                    onComplete: function(tween:FlxTween) {
                        cancelTween(eventName);
                    }
                }));
            case "sicko shake":
                DefaultHandler.shakeCamTimer = Std.parseInt(eventValue);
			    DefaultHandler.shakeCamTimerHUD = Std.parseInt(eventValue2);
            case "time freeze":
                if(Std.parseInt(eventValue) == 0 && !FlxG.sound.music.playing) {
                    playState.resyncVocals();
                }

                storeTween(eventName, FlxTween.tween(playState, {timeFreeze : Std.parseFloat(eventValue)}, (Conductor.crochet/500) * Std.parseFloat(eventValue2), {
                    onComplete: function(tween:FlxTween) {
                        if(Std.parseInt(eventValue) == 1) {
                            playState.pauseMusic();
                        }

                        cancelTween(eventName);
                    }
                }));
            case "strum bounce":
                offsetBounce = Std.parseInt(eventValue2);
                DefaultHandler.sizeTimer = Std.parseInt(eventValue);

                if(playState.flipWiggle >= 1)
                    playState.flipWiggle = -1;
                else
                    playState.flipWiggle = 1;
            case "note rewind":
                storeTween(eventName, FlxTween.tween(Note, {AFFECTED_STRUMTIME : Std.parseFloat(eventValue)}, (Conductor.stepCrochet/500) * Std.parseFloat(eventValue2), {
                    onComplete: function(tween:FlxTween) {
                        cancelTween(eventName);
                    }
                }));
            case "character change":
				var sync = GL.fenceSync(GL.SYNC_GPU_COMMANDS_COMPLETE, 0);
				GL.flush();
				GL.waitSync(sync, 0, GL.TIMEOUT_IGNORED);

                switch(eventValue2.toLowerCase()) {
                    case "gf" | "girlfriend":
                        if(DefaultHandler.getcharacterJSON().contains(eventValue.toLowerCase())) {
                            playState.remove(playState.gf);
                            playState.gf.destroy();
                            playState.gf = new Character(400, 130, eventValue);
                            playState.gf.refresh(eventValue, playState.camPos);
                            playState.add(playState.gf);
                        }
                    case "bf" | "boyfriend" | "player":
                        if(DefaultHandler.getcharacterJSON().contains(eventValue.toLowerCase())) {
                            playState.remove(playState.boyfriend);
                            playState.boyfriend.destroy();
                            playState.boyfriend = new Boyfriend(100, 100, eventValue);
                            playState.boyfriend.refresh(eventValue, playState.camPos);
                            playState.add(playState.boyfriend);

                            playState.iconP1.character = eventValue;
                            playState.iconP1.createAnim(playState.boyfriend.curCharacter, playState.boyfriend._info.icon, true);
                        }
                    default:
                        if(DefaultHandler.getcharacterJSON().contains(eventValue.toLowerCase())) {
                            playState.remove(playState.dad);
                            playState.dad.destroy();
                            playState.dad = new Character(100, 100, eventValue);
                            playState.dad.refresh(eventValue, playState.camPos);
                            playState.stage.add(playState.dad);

                            playState.iconP2.character = eventValue;
                            playState.iconP2.createAnim(eventValue, playState.dad._info.icon, false);
                        }
                }

				GL.deleteSync(sync);
            case "bump per beat":
                playState.bumpPerBeat = Std.parseInt(eventValue);
                playState.bumpForce = Std.parseInt(eventValue2);
            case "clear events":
                if(playState.eventStorage.contains(eventValue)) {
                    playState.eventStorage.remove(eventValue);
                    setModifierToDefault(eventValue);
                }

                if(playState.eventStorage.contains(eventValue2)) {
                    playState.eventStorage.remove(eventValue2);
                    setModifierToDefault(eventValue2);
                }
            case "clear all":
                reflushModifiers();
                playState.eventStorage.splice(0, playState.eventStorage.length);
                playState.eventStorage = [];
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

    function setModifierToDefault(mod:String):Void {
		switch(mod) {
			case "custom hell":
				DefaultHandler.modifiers.customHell.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.CUSTOM_HELL_MOD) #else false #end;
			case "get good":
				DefaultHandler.modifiers.getGoodScrub.enabled = #if TOGGLEABLE_MODIFIERS (SaveData.getData(SaveType.PERFECT_MODE_MOD) > 0 ? true : false) #else false #end;
			case "mirror chart":
				DefaultHandler.modifiers.mirrorChart.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FLIP_CHART_MOD) #else false #end;
			case "sing drain":
				DefaultHandler.modifiers.singDrain.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FAIR_BATTLE_MOD) #else false #end;
			case "fadein notes":
				DefaultHandler.modifiers.fadeInNotes.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FADE_BATTLE_MOD) #else false #end;
			case "safe balls":
				DefaultHandler.modifiers.safeBalls.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.NO_BLUE_BALLS_MOD) #else false #end;
			case "blind effect":
				DefaultHandler.modifiers.blindEffect.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.BLIND_MOD) #else false #end;
			case "note woggle":
				DefaultHandler.modifiers.wobbleNotes.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.X_WOBBLE_MOD) #else false #end;
			case "camera move":
				DefaultHandler.modifiers.cameraMovement.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.CAMERA_MOVEMENT_MOD) #else false #end;
		}
	}

    function reflushModifiers():Void {
		DefaultHandler.modifiers.customHell.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.CUSTOM_HELL_MOD) #else false #end;
		DefaultHandler.modifiers.getGoodScrub.enabled = #if TOGGLEABLE_MODIFIERS (SaveData.getData(SaveType.PERFECT_MODE_MOD) > 0 ? true : false) #else false #end;
		DefaultHandler.modifiers.mirrorChart.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FLIP_CHART_MOD) #else false #end;
		DefaultHandler.modifiers.singDrain.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FAIR_BATTLE_MOD) #else false #end;
		DefaultHandler.modifiers.fadeInNotes.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.FADE_BATTLE_MOD) #else false #end;
		DefaultHandler.modifiers.safeBalls.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.NO_BLUE_BALLS_MOD) #else false #end;
		DefaultHandler.modifiers.blindEffect.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.BLIND_MOD) #else false #end;
		DefaultHandler.modifiers.wobbleNotes.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.X_WOBBLE_MOD) #else false #end;
		DefaultHandler.modifiers.cameraMovement.enabled = #if TOGGLEABLE_MODIFIERS SaveData.getData(SaveType.CAMERA_MOVEMENT_MOD) #else false #end;
	}

}
