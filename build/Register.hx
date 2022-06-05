package;

import haxe.macro.Context;
import haxe.macro.Expr;
import haxe.macro.Type;

#if !macro
import example_code.TransitionSamples;

import example_code.DefaultEvents;
import example_code.DefaultStage;
import template.TransitionBuilder;
import template.CustomNote;
import template.StageBuilder;
import feshixl.group.FeshEventGroup;
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

/**
#if (crashdumper && !macro)
import crashdumper.SessionData;
import crashdumper.CrashDumper;
import feshixl.FeshCrashDumper;
#end
**/

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
    private static var events:FeshEventGroup = new FeshEventGroup();

    @:allow(PlayState)
    private static var stages:Array<Class<StageBuilder>> = [DefaultStage];

    @:allow(Preloader)
    @:access(HelperStates.transitionBuilds)
    private static function setup() {
        events.add(new DefaultEvents());

        HelperStates.transitionBuilds.set("fade", FadeTransition);
        HelperStates.transitionBuilds.set("tile", TileTransition);
    }

    @:access(HelperStates)
    public static function attachLuaToState(state:Class<Dynamic>, luaClass:ModLua) {
		#if (USING_LUA && linc_luajit)
		HelperStates.scriptsInStates.set(Type.getClassName(state), luaClass);
		#end
	}

    @:access(HelperStates)
    public static function detachLuaFromState(state:Class<Dynamic>) {
        #if (USING_LUA && linc_luajit)
        HelperStates.scriptsInStates.remove(Type.getClassName(state));
        #end
    }

    @:access(HelperStates.transitionBuilds)
    public static function addCustomTransition(transition:String, transOBJ:Class<TransitionBuilder>) {
        HelperStates.transitionBuilds.set(transition, transOBJ);
    }

    @:access(HelperStates.transitionBuilds)
    public static function removeCustomTransition(transition:String) {
        HelperStates.transitionBuilds.remove(transition);
    }

    public static function getInGameCharacter(character:CharacterRole):Character {
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

    public static function add(addonType:ClassType, addonClass:Dynamic):Void {
        switch(addonType) {
            case EVENT:
                var daEvent:IFeshEvent = addonClass;

                if(!events.members.contains(daEvent))
                    events.add(daEvent);
            case STAGE:
                stages.push(addonClass);
        }
    }

    public static function implementCustomNote(name:String, addonClass:Class<CustomNote>) {
        CustomNoteHandler.customNoteAddon.set(name, addonClass);
    }

    public static function getWeekFromSong(song:String):Int {
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

        throw "Error: song not found in method - getWeekFromSong";
        return -1;
    }

    public static function forNameClass(type:String, args:Array<Dynamic>):Dynamic {
        return Type.createInstance(Type.resolveClass(type), args);
    }

    public static function getFlxEaseByString(ease:String) {
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