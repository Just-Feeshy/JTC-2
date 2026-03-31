package data.freeplay.player;

class PlayerRegistry
{
	public static var instance(default, null):PlayerRegistry = new PlayerRegistry();

	public function new() {}

	public function getCharacterOwnerId(_:Dynamic):String
	{
		return null;
	}

	public function fetchEntry(_:String):Dynamic
	{
		return null;
	}
}
