package;

import hxp.Haxelib;
import hxp.Path;

class DevStateTest extends HelperStates {
    public function new() {
        super();

        var limeDirectory = Haxelib.getPath(new Haxelib("lime"), true);
		var toolsDirectory = Path.combine(limeDirectory, "tools");

        trace("get Lime Path: " + limeDirectory);
        trace("get Tools Path: " + toolsDirectory);
    }

    override function create():Void {
        super.create();
    }
}