package;

#if (desktop && cpp)
import hxdiscord_rpc.Discord;
import sys.thread.Thread;
#end

using StringTools;

typedef DiscordClientPresenceParams =
{
	var state:Null<String>;
	var details:Null<String>;
	var ?largeImageKey:String;
	var ?smallImageKey:String;
	var ?endTimestamp:Float;
}

class DiscordClient
{
	#if (desktop && cpp)
	private static inline var CLIENT_ID_ENV:String = "DISCORD_CLIENT_ID";
	private static inline var DEFAULT_CLIENT_ID:String = "969002129182314526";
	private static inline var DEFAULT_LARGE_IMAGE_TEXT:String = "Friday Night Funkin': JTC";

	private static var handlers:hxdiscord_rpc.Types.DiscordEventHandlers;
	private static var callbackThread:Thread;
	private static var initialized:Bool = false;
	private static var available:Bool = true;
	#end

	public function new() {}

	public static function shutdown():Void
	{
		#if (desktop && cpp)
		if(!initialized) {
			return;
		}

		initialized = false;
		Discord.ClearPresence();
		Discord.Shutdown();
		callbackThread = null;
		#end
	}

	public static function initialize():Void
	{
		#if (desktop && cpp)
		if(initialized || !available) {
			return;
		}

		var clientId = resolveClientId();

		if(clientId == null) {
			available = false;
			trace('[Discord RPC] Disabled: no valid Discord application ID configured.');
			return;
		}

		handlers = new hxdiscord_rpc.Types.DiscordEventHandlers();
		handlers.ready = cpp.Function.fromStaticFunction(onReady);
		handlers.disconnected = cpp.Function.fromStaticFunction(onDisconnected);
		handlers.errored = cpp.Function.fromStaticFunction(onError);

		Discord.Initialize(clientId, cpp.RawPointer.addressOf(handlers), false, null);

		initialized = true;
		callbackThread = Thread.create(runCallbacks);
		#end
	}

	public static function setPresence(params:DiscordClientPresenceParams):Void
	{
		#if (desktop && cpp)
		if(!initialized) {
			return;
		}

		var state:Null<String> = params.state;
		var details:Null<String> = params.details;
		var largeImageKey:Null<String> = params.largeImageKey;
		var smallImageKey:Null<String> = params.smallImageKey;

		var presence = new hxdiscord_rpc.Types.DiscordRichPresence();
		presence.type = hxdiscord_rpc.Types.DiscordActivityType.DiscordActivityType_Playing;
		presence.state = state != null ? cast state : null;
		presence.details = details != null ? cast details : null;
		presence.largeImageText = DEFAULT_LARGE_IMAGE_TEXT;
		presence.largeImageKey = largeImageKey != null ? cast largeImageKey : null;
		presence.smallImageKey = smallImageKey != null ? cast smallImageKey : null;

		Discord.UpdatePresence(cpp.RawConstPointer.addressOf(presence));
		#end
	}

	public static function changePresence(details:String, state:Null<String>, ?smallImageKey:String, ?hasStartTimestamp:Bool, ?endTimestamp:Float):Void
	{
		setPresence({
			state: state,
			details: details,
			smallImageKey: smallImageKey,
			endTimestamp: hasStartTimestamp ? endTimestamp : null
		});
	}

	#if (desktop && cpp)
	private static function resolveClientId():Null<String>
	{
		var clientId = Sys.getEnv(CLIENT_ID_ENV);

		if(clientId != null) {
			clientId = clientId.trim();
			if(clientId.length > 0) {
				return clientId;
			}
		}

		return DEFAULT_CLIENT_ID;
	}

	private static function runCallbacks():Void
	{
		while(initialized)
		{
			#if DISCORD_DISABLE_IO_THREAD
			Discord.UpdateConnection();
			#end

			Discord.RunCallbacks();
			Sys.sleep(2);
		}
	}

	private static function onReady(request:cpp.RawConstPointer<hxdiscord_rpc.Types.DiscordUser>):Void
	{
		final username:String = request[0].username;
		trace('[Discord RPC] Connected as ' + username);
	}

	private static function onDisconnected(errorCode:Int, message:cpp.ConstCharStar):Void
	{
		trace('[Discord RPC] Disconnected (' + errorCode + '): ' + cast(message, String));
	}

	private static function onError(errorCode:Int, message:cpp.ConstCharStar):Void
	{
		trace('[Discord RPC] Error (' + errorCode + '): ' + cast(message, String));
	}
	#end
}
