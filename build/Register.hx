package;

import haxe.macro.Context;
import haxe.macro.Expr;
import haxe.macro.Type;

#if !macro
import example_code.TransitionSamples;
import example_code.NoteSamples;
import example_code.DefaultEvents;
import example_code.DefaultStage;

import template.TransitionBuilder;
import template.CustomNote;
import template.StageBuilder;
import feshixl.group.FeshEventGroup;
import flixel.tweens.FlxEase;
import flixel.FlxG;
import haxe.Json;
import lime.utils.Assets;
#end

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

#if sys
import sys.io.File;
#end

using StringTools;

/**
* Basically the FlxG for Feeshmora.
*/
class Register {
    private static var regJSON(get, never):String;

    public inline static macro function compile() {
        if(regJSON.length > 0)
		    return Context.parse("{@:privateAccess " + regJSON + ".onInit();}", Context.currentPos());
        else
            return macro {
                return;
            };
	}

    static function get_regJSON() {
        return File.getContent("config/mod.json").split(':')[1].split('"')[1];
    }

    #if !macro
    @:allow(PlayState) private static var events:Array<Class<IFeshEvent>> = [];
    @:allow(PlayState) private static var dialogues:Map<String, Class<IDialogue>> = new Map<String, Class<IDialogue>>();
    @:allow(PlayState) private static var stage:Class<StageBuilder> = DefaultStage;

    @:allow(Main) private static var initialState:Class<HelperStates> = TitleState;

    @:allow(Preloader)
    private inline static function setup() {
        /**
        * Default initialization for game.
        */

        addEvent(DefaultEvents);

        addCustomTransition("fade", FadeTransition);
        addCustomTransition("tile", TileTransition);
        addCustomTransition("void", VoidTransition);

        implementCustomNote("reverse", ReverseNote);
        implementCustomNote("poison", PoisonNote);
        implementCustomNote("reverse poison", ReversePoisonNote);
    }

    @:access(Preloader)
    public inline static function attachInitalState(state:Class<HelperStates>):Void {
        Preloader._initialState = state;
    }

    @:access(HelperStates)
    public inline static function attachLuaToState<T:HelperStates>(state:Class<T>, path:String):Void { //Won't work with PlayState.
		#if USING_LUA
        if(HelperStates.scriptsInStates.exists(Type.getClassName(state))) {
            HelperStates.scriptsInStates.get(Type.getClassName(state)).close();
            HelperStates.scriptsInStates.remove(Type.getClassName(state));
        }

		HelperStates.scriptsInStates.set(Type.getClassName(state), new ModLua(path));
		#end
	}

    @:access(HelperStates)
    public inline static function detachLuaFromState<T:HelperStates>(state:Class<T>):Void { //Won't work with PlayState.
        #if USING_LUA
        if(HelperStates.scriptsInStates.exists(Type.getClassName(state))) {
            HelperStates.scriptsInStates.get(Type.getClassName(state)).close();
            HelperStates.scriptsInStates.remove(Type.getClassName(state));
        }
        #end
    }

    @:access(HelperStates.transitionBuilds)
    public inline static function addCustomTransition(transition:String, transOBJ:Class<TransitionBuilder>):Void {
        HelperStates.transitionBuilds.set(transition, transOBJ);
    }

    @:access(HelperStates.transitionBuilds)
    public inline static function removeCustomTransition(transition:String):Void {
        HelperStates.transitionBuilds.remove(transition);
    }

    public inline static function getInGameCharacter(character:CharacterRole):Character {
        if(isOfType(FlxG.state, PlayState)) {
            var playstate:PlayState = cast(FlxG.state, PlayState);

            switch (character) {
                case BOYFRIEND:
                    return playstate.boyfriend;
                case GIRLFRIEND:
                    return playstate.gf;
                default:
                    return playstate.dad;
            }
        }

        return null;
    }

    public inline static function setStageForMod(stage:Class<StageBuilder>):Void {
        Register.stage = stage;
    }

    public inline static function addEvent(daEvent:Class<IFeshEvent>):Void {
        if(!events.contains(daEvent))
            events.insert(0, daEvent);
    }

    public inline static function removeEvent(daEvent:Class<IFeshEvent>):Void {
        if(events.contains(daEvent))
            events.remove(daEvent);
    }

    public inline static function implementDialogueToSong(name:String, dialogueClass:Class<IDialogue>) {
        dialogues.set(name, dialogueClass);
    }

    public inline static function implementCustomNote(name:String, addonClass:Class<ICustomNote>) {
        CustomNoteHandler.customNoteAddon.set(name, addonClass);
    }

    public inline static function getWeekFromSong(song:String):Int {
        var week:Int = 0;

        /*
        * Faster run time.
        **/
        while(Paths.modJSON.weeks.get("week_" + week) != null) {
            if(Paths.modJSON.weeks.get("week_" + week).week_data.contains(song)) {
                return week;
            }

            week++;
        }

        trace("Error: song not found in method - getWeekFromSong");
        return -1;
    }

    public inline static function forNameClass(type:String, args:Array<Dynamic>):Dynamic {
        return Type.createInstance(Type.resolveClass(type), args);
    }

    public inline static function updateFramerate(fps:Int):Void {
        if(FlxG.updateFramerate == fps) {
            return;
        }

        if (fps > FlxG.updateFramerate) {
            FlxG.updateFramerate = fps;
            FlxG.drawFramerate = fps;
        }else {
            FlxG.drawFramerate = fps;
            FlxG.updateFramerate = fps;
        }

        FlxG.game.focusLostFramerate = fps;
        openfl.Lib.current.stage.frameRate = fps;
    }

    public inline static function getFlxEaseByString(ease:String) {
		switch(ease.toLowerCase().trim()) {
			case 'backin':
                return FlxEase.backIn;
			case 'backinout':
                return FlxEase.backInOut;
			case 'backout':
                return FlxEase.backOut;
			case 'bouncein':
                return FlxEase.bounceIn;
			case 'bounceinout':
                return FlxEase.bounceInOut;
			case 'bounceout':
                return FlxEase.bounceOut;
			case 'circin':
                return FlxEase.circIn;
			case 'circinout':
                return FlxEase.circInOut;
			case 'circout':
                return FlxEase.circOut;
			case 'cubein':
                return FlxEase.cubeIn;
			case 'cubeinout':
                return FlxEase.cubeInOut;
			case 'cubeout':
                return FlxEase.cubeOut;
			case 'elasticin':
                return FlxEase.elasticIn;
			case 'elasticinout':
                return FlxEase.elasticInOut;
			case 'elasticout':
                return FlxEase.elasticOut;
			case 'expoin':
                return FlxEase.expoIn;
			case 'expoinout':
                return FlxEase.expoInOut;
			case 'expoout':
                return FlxEase.expoOut;
			case 'quadin':
                return FlxEase.quadIn;
			case 'quadinout':
                return FlxEase.quadInOut;
			case 'quadout':
                return FlxEase.quadOut;
			case 'quartin':
                return FlxEase.quartIn;
			case 'quartinout':
                return FlxEase.quartInOut;
			case 'quartout':
                return FlxEase.quartOut;
			case 'quintin':
                return FlxEase.quintIn;
			case 'quintinout':
                return FlxEase.quintInOut;
			case 'quintout':
                return FlxEase.quintOut;
			case 'sinein':
                return FlxEase.sineIn;
			case 'sineinout':
                return FlxEase.sineInOut;
			case 'sineout':
                return FlxEase.sineOut;
			case 'smoothstepin':
                return FlxEase.smoothStepIn;
			case 'smoothstepinout':
                return FlxEase.smoothStepInOut;
			case 'smoothstepout':
                return FlxEase.smoothStepInOut;
			case 'smootherstepin':
                return FlxEase.smootherStepIn;
			case 'smootherstepinout':
                return FlxEase.smootherStepInOut;
			case 'smootherstepout':
                return FlxEase.smootherStepOut;
            default:
                return FlxEase.linear;
		}
	}
    #end
}
