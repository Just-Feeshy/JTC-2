package play;

@:nullSafety
class PlayScriptEvent
{
	public static inline var CREATE:String = "create";
	public static inline var STATE_CREATE:String = "stateCreate";
	public static inline var UPDATE:String = "update";
	public static inline var DESTROY:String = "destroy";
	public static inline var SONG_STEP_HIT:String = "songStepHit";
	public static inline var SONG_BEAT_HIT:String = "songBeatHit";
	public static inline var SONG_START:String = "songStart";
	public static inline var SONG_END:String = "songEnd";
	public static inline var SONG_RETRY:String = "songRetry";
	public static inline var GAME_OVER:String = "gameOver";
	public static inline var PAUSE:String = "pause";
	public static inline var RESUME:String = "resume";
	public static inline var COUNTDOWN_START:String = "countdownStart";
	public static inline var COUNTDOWN_STEP:String = "countdownStep";
	public static inline var COUNTDOWN_END:String = "countdownEnd";
	public static inline var SONG_EVENT:String = "songEvent";
	public static inline var SUBSTATE_OPEN_BEGIN:String = "substateOpenBegin";
	public static inline var SUBSTATE_OPEN_END:String = "substateOpenEnd";
	public static inline var SUBSTATE_CLOSE_BEGIN:String = "substateCloseBegin";
	public static inline var SUBSTATE_CLOSE_END:String = "substateCloseEnd";
	public static inline var FOCUS_GAINED:String = "focusGained";
	public static inline var FOCUS_LOST:String = "focusLost";

	public var type:String;
	public var cancellable:Bool;
	public var shouldPropagate:Bool = true;
	public var payload:Dynamic;
	public var luaCallback:Null<String>;
	public var luaArguments:Array<Dynamic>;

	@:isVar public var eventCanceled(get, set):Bool = false;

	public function new(type:Dynamic, ?cancellable:Bool = false, ?payload:Dynamic = null, ?luaArguments:Array<Dynamic> = null, ?luaCallback:Null<String> = null)
	{
		this.type = type == null ? "" : Std.string(type);
		this.cancellable = cancellable == true;
		this.payload = payload;
		this.luaArguments = luaArguments != null ? luaArguments : [];
		this.luaCallback = luaCallback;
	}

	function get_eventCanceled():Bool
	{
		return eventCanceled;
	}

	function set_eventCanceled(value:Bool):Bool
	{
		if(value && !cancellable)
		{
			return eventCanceled;
		}

		eventCanceled = value;
		return eventCanceled;
	}

	public function cancel():Void
	{
		eventCanceled = true;
	}

	public function stopPropagation():Void
	{
		shouldPropagate = false;
	}
}
