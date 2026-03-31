package play;

import HelperStates;
import ModLua;
import PlayState;

@:nullSafety
class PlayScriptEventDispatcher
{
	public static function callEvent(target:Dynamic, event:PlayScriptEvent):Void
	{
		if(target == null || event == null)
		{
			return;
		}

		callHaxeHook(target, "onScriptEvent", [event]);

		if(!event.shouldPropagate)
		{
			return;
		}

		pushLuaEventState(target, event);
		callLuaHook(target, "onScriptEvent", [event]);

		var callbackName:Null<String> = resolveLuaCallbackName(event);
		if(callbackName != null)
		{
			callLuaHook(target, callbackName, event.luaArguments);
		}

		applyLuaEventResult(target, event);
	}

	static function callHaxeHook(target:Dynamic, methodName:String, args:Array<Dynamic>):Void
	{
		if(target == null || methodName == null)
		{
			return;
		}

		var method:Dynamic = Reflect.field(target, methodName);
		if(method == null)
		{
			return;
		}

		Reflect.callMethod(target, method, args);
	}

	static function callLuaHook(target:Dynamic, callbackName:String, args:Array<Dynamic>):Dynamic
	{
		if(callbackName == null || callbackName == "")
		{
			return null;
		}

		var callLuaMethod:Dynamic = Reflect.field(target, "callLua");
		if(callLuaMethod != null)
		{
			return Reflect.callMethod(target, callLuaMethod, [callbackName, args != null ? args : []]);
		}

		var lua:Null<ModLua> = resolveLua(target);
		if(lua != null)
		{
			return lua.call(callbackName, args != null ? args : []);
		}

		return null;
	}

	static function pushLuaEventState(target:Dynamic, event:PlayScriptEvent):Void
	{
		if(Std.isOfType(target, PlayState))
		{
			var playState:PlayState = cast target;
			playState.updateLuaVars();
			playState.updatePerSectionLuaVars();
		}

		setLuaField(target, "scriptEventType", event.type);
		setLuaField(target, "scriptEventCanceled", event.eventCanceled);
		setLuaField(target, "scriptEventShouldPropagate", event.shouldPropagate);
		setLuaField(target, "scriptEventPayload", event.payload);
	}

	static function applyLuaEventResult(_target:Dynamic, _event:PlayScriptEvent):Void
	{
		// Lua event dispatch is write-only for now.
	}

	static function setLuaField(target:Dynamic, variable:String, data:Dynamic):Void
	{
		var setLuaMethod:Dynamic = Reflect.field(target, "setLua");
		if(setLuaMethod != null)
		{
			Reflect.callMethod(target, setLuaMethod, [variable, data]);
			return;
		}

		var lua:Null<ModLua> = resolveLua(target);
		if(lua != null)
		{
			lua.set(variable, data);
		}
	}

	static function resolveLua(target:Dynamic):Null<ModLua>
	{
		if(target == null)
		{
			return null;
		}

		var getModLuaMethod:Dynamic = Reflect.field(target, "getModLua");
		if(getModLuaMethod != null)
		{
			return cast Reflect.callMethod(target, getModLuaMethod, []);
		}

		var targetClass:Class<Dynamic> = Type.getClass(target);
		if(targetClass != null && HelperStates.luaExist(targetClass))
		{
			return HelperStates.getLua(targetClass);
		}

		return null;
	}

	static function resolveLuaCallbackName(event:PlayScriptEvent):Null<String>
	{
		if(event.luaCallback != null && event.luaCallback != "")
		{
			return event.luaCallback;
		}

		return switch(event.type)
		{
			case PlayScriptEvent.CREATE, PlayScriptEvent.STATE_CREATE: "onCreate";
			case PlayScriptEvent.UPDATE: "onUpdate";
			case PlayScriptEvent.DESTROY: "onDestroy";
			case PlayScriptEvent.SONG_STEP_HIT: "onStepHit";
			case PlayScriptEvent.SONG_BEAT_HIT: "onBeatHit";
			case PlayScriptEvent.SONG_START: "onSongStart";
			case PlayScriptEvent.SONG_END: "onSongEnd";
			case PlayScriptEvent.SONG_RETRY: "onSongRestart";
			case PlayScriptEvent.GAME_OVER: "onGameOver";
			case PlayScriptEvent.PAUSE: "onPause";
			case PlayScriptEvent.RESUME: "onResume";
			case PlayScriptEvent.COUNTDOWN_START: "onCountdownStart";
			case PlayScriptEvent.COUNTDOWN_STEP: "onCountdownStep";
			case PlayScriptEvent.COUNTDOWN_END: "onCountdownEnd";
			case PlayScriptEvent.SONG_EVENT: "onSongEvent";
			case PlayScriptEvent.SUBSTATE_OPEN_BEGIN: "onSubStateOpenBegin";
			case PlayScriptEvent.SUBSTATE_OPEN_END: "onSubStateOpenEnd";
			case PlayScriptEvent.SUBSTATE_CLOSE_BEGIN: "onSubStateCloseBegin";
			case PlayScriptEvent.SUBSTATE_CLOSE_END: "onSubStateCloseEnd";
			case PlayScriptEvent.FOCUS_GAINED: "onFocusGained";
			case PlayScriptEvent.FOCUS_LOST: "onFocusLost";
			default: null;
		}
	}
}
