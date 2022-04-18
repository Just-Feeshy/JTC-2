package;

import flixel.FlxG;

class GhostTapping extends Options {
    public static var consequence(get, never):Float;
    public static var ghostTap(get, never):Bool;

    static function get_consequence():Float {
        if(FlxG.save.data.ghostTapping)
            return 2;
        else
            return 1;
    }

    static function get_ghostTap():Bool {
        return FlxG.save.data.ghostTapping;
    }
}