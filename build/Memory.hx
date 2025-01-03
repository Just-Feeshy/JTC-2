package;

import openfl.events.Event;
import openfl.text.TextField;
import openfl.text.TextFormat;
import openfl.system.System;

class Memory extends TextField {
    public var memPeak(default, null):Float = 0;
    public var memory(default, null):Float = 0;

    public function new(x:Float = 10.0, y:Float = 10.0, color:Int = 0x000000) {
        super();

        this.x = x;
        this.y = y;

        this.selectable = false;

        defaultTextFormat = new TextFormat("_sans", 12, color);

        addEventListener(Event.ENTER_FRAME, onEnter);

		width = 200;
		height = 70;
    }

    function onEnter(_) {
        memory = Math.round(System.totalMemory * 0.00098 * 0.00098 * 100) * 0.01;

		if (memory > Math.abs(memPeak)) {
            memPeak = memory;
        }

        if (visible) {
            text = "MEM: " + memory + " MB\nMEM peak: " + memPeak + " MB";
        }
    }
}