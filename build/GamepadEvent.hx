package;

import openfl.events.Event;
import openfl.events.EventType;

class GamepadEvent extends Event {
    public static inline var BUTTON_DOWN:EventType<GamepadEvent> = "buttonDown";
    public static inline var BUTTON_UP:EventType<GamepadEvent> = "buttonUp";

    public var buttonCode:Int = -1; //NONE

    public function new(type:String, bubbles:Bool = false, cancelable:Bool = false, buttonCode:Int = -1) {
        this.buttonCode = buttonCode;

        super(type, bubbles, cancelable);
    }
}