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
import feshixl.interfaces.IDialogue;
import flixel.FlxState;
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

import sys.io.File;

using StringTools;

enum ClassType {
    EVENT;
    STAGE;
}

/**
* Basically the FlxG for Feeshmora.
* Yes, this is a helper class for Feeshmora mods.
*/
class Register {
    private static var regJSON(get, never):String;

    public static macro function compile() {
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
    @:allow(PlayState)
    private static var events:Array<Class<IFeshEvent>> = [];

    @:allow(PlayState)
    private static var stages:Array<Class<StageBuilder>> = [DefaultStage];

    @:allow(PlayState)
    private static var dialogues:Map<String, Class<IDialogue>> = new Map<String, Class<IDialogue>>();

    @:allow(Preloader)
    private inline static function setup() {
        /**
        * Default initialization for game.
        */

        add(EVENT, DefaultEvents);

        addCustomTransition("fade", FadeTransition);
        addCustomTransition("tile", TileTransition);
        addCustomTransition("void", VoidTransition);

        implementCustomNote("reverse", ReverseNote);
        implementCustomNote("poison", PoisonNote);
        implementCustomNote("reverse poison", ReversePoisonNote);
    }

    @:access(HelperStates)
    public inline static function attachLuaToState(state:Class<Dynamic>, luaClass:ModLua) {
		#if (USING_LUA && linc_luajit)
		HelperStates.scriptsInStates.set(Type.getClassName(state), luaClass);
		#end
	}

    @:access(HelperStates)
    public inline static function detachLuaFromState(state:Class<Dynamic>) {
        #if (USING_LUA && linc_luajit)
        if(HelperStates.scriptsInStates.exists(Type.getClassName(state)))
            HelperStates.scriptsInStates.remove(Type.getClassName(state));
        #end
    }

    @:access(HelperStates.transitionBuilds)
    public inline static function addCustomTransition(transition:String, transOBJ:Class<TransitionBuilder>) {
        HelperStates.transitionBuilds.set(transition, transOBJ);
    }

    @:access(HelperStates.transitionBuilds)
    public inline static function removeCustomTransition(transition:String) {
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

    public inline static function add(addonType:ClassType, addonClass:Dynamic):Void {
        switch(addonType) {
            case EVENT:
                var daEvent:Class<IFeshEvent> = addonClass;

                if(!events.contains(daEvent))
                    events.push(daEvent);
            case STAGE:
                if(!stages.contains(addonClass))
                    stages.push(addonClass);
        }
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