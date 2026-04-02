package;

import openfl.events.Event;
import openfl.text.TextField;
import openfl.text.TextFormat;
import openfl.system.System;
import flixel.math.FlxMath;

class Memory extends TextField {
	private var units:Array<String> = ["Bytes", "kB", "MB", "GB", "TB", "PB"];

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
        memory = System.totalMemoryNumber;

		if (memory > Math.abs(memPeak)) {
            memPeak = memory;
        }

        if (visible) {
            text = "GC MEM: " + formatBytes(memory).toLowerCase() + "\nMEM peak: " + formatBytes(memPeak).toLowerCase();
        }
    }

	function formatBytes(Bytes:Float, Precision:Int = 2):String {
		var curUnit = 0;
		while (Bytes >= 1024 && curUnit < units.length - 1) {
			Bytes /= 1024;
			curUnit++;
		}

		return FlxMath.roundDecimal(Bytes, Precision) + units[curUnit];
	}
}
