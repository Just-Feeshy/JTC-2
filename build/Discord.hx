package;

#if windows
class DiscordClient
{
	public function new() {}

	public static function shutdown():Void {}

	public static function initialize():Void {}

	public static function changePresence(details:String, state:Null<String>, ?smallImageKey:String, ?hasStartTimestamp:Bool, ?endTimestamp:Float):Void {}
}
#end
