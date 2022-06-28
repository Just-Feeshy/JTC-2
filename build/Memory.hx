package;

import openfl.events.Event;
import openfl.text.TextField;
import openfl.text.TextFormat;
import openfl.system.System;

class Memory extends TextField {
    var memPeak:Float = 0;

    public function new(x:Float = 10.0, y:Float = 10.0, color:Int = 0x000000) {
        super();

        this.x = x;
        this.y = y;

        this.selectable = false;

        defaultTextFormat = new TextFormat("_sans", 12, color);

        addEventListener(Event.ENTER_FRAME, onEnter);

		width = 150;
		height = 70;
    }

    function onEnter(_) {
        var mem:Float = Math.round(System.totalMemory / 1024 / 1024 * 100)/100;

		if (mem > memPeak) {
            memPeak = mem;
        }

        if (visible) {
            text = "MEM: " + mem + " MB\nMEM peak: " + memPeak + " MB";
        }
    }
}