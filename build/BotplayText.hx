package;

import openfl.Assets;
import openfl.events.Event;
import openfl.text.TextField;
import openfl.text.TextFormat;

class BotplayText extends TextField {
	public function new(color:Int = 0xFFFFFF) {
		super();

		selectable = false;
		mouseEnabled = false;
		multiline = false;
		wordWrap = false;
		alpha = 0.85;

		defaultTextFormat = new TextFormat(Assets.getFont(Paths.font("PhantomMuff.ttf")).fontName, 32, color);
		text = "BOTPLAY";

		addEventListener(Event.ENTER_FRAME, onEnter);
	}

	function onEnter(_):Void {
		if(stage == null) {
			return;
		}

		text = "BOTPLAY";
		width = textWidth + 8;
		height = textHeight + 8;
		x = (stage.stageWidth - width) * 0.5;
		y = 80;
	}

	public function dispose():Void {
		removeEventListener(Event.ENTER_FRAME, onEnter);
	}
}
