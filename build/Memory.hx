package;

import openfl.events.Event;
import openfl.text.TextField;
import openfl.text.TextFormat;
import flixel.math.FlxMath;

class Memory extends TextField {
	private var units:Array<String> = ["Bytes", "kB", "MB", "GB", "TB", "PB"];

    public var gcPeak(default, null):Float = 0;
    public var gcMemory(default, null):Float = 0;
    public var taskPeak(default, null):Float = 0;
    public var taskMemory(default, null):Float = 0;

    public function new(x:Float = 10.0, y:Float = 10.0, color:Int = 0x000000) {
        super();

        this.x = x;
        this.y = y;

        this.selectable = false;

        defaultTextFormat = new TextFormat("_sans", 12, color);

        addEventListener(Event.ENTER_FRAME, onEnter);

		width = 260;
		height = 90;
    }

    function onEnter(_) {
        gcMemory = MemoryUtil.getGCMemory();
        taskMemory = MemoryUtil.supportsTaskMem() ? MemoryUtil.getTaskMemory() : 0;

		if (gcMemory > Math.abs(gcPeak)) {
            gcPeak = gcMemory;
        }

		if (taskMemory > Math.abs(taskPeak)) {
            taskPeak = taskMemory;
        }

        if (visible) {
            var lines:Array<String> = [];
            lines.push("GC MEM: " + formatBytes(gcMemory).toLowerCase() + " / " + formatBytes(gcPeak).toLowerCase());

            if (MemoryUtil.supportsTaskMem()) {
                lines.push("TASK MEM: " + formatBytes(taskMemory).toLowerCase() + " / " + formatBytes(taskPeak).toLowerCase());
            }

            text = lines.join("\n");
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
