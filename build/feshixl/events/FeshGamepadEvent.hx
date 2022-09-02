package feshixl.events;

import openfl.events.Event;
import openfl.events.EventType;

class FeshGamepadEvent extends Event {
    /**
	* The `FeshGamepadEvent.BUTTON_DOWN` constant defines the value of the `type`
	**/
    public static inline var BUTTON_DOWN:EventType<FeshGamepadEvent> = "buttonDown";

    /**
	* The `FeshGamepadEvent.BUTTON_UP` constant defines the value of the `type`
	**/
    public static inline var BUTTON_UP:EventType<FeshGamepadEvent> = "buttonUp";

    /**
        The button code value of the gamepad button pressed or released.
        
        NOTE: This is still in development! If there are any issues with
        the gamepad event or anything else; contact me through my discord: 
        `Feeshy#5928`
    **/
    public var buttonCode:Int;

    public function new(type:String, bubbles:Bool = false, cancelable:Bool = false, buttonCode:Int = 0) {
        super(type, bubbles, cancelable);

        this.buttonCode = buttonCode;
    }

    public override function clone():FeshGamepadEvent {
        var event = new FeshGamepadEvent(type, bubbles, cancelable, buttonCode);

        event.target = target;
        event.currentTarget = currentTarget;
        event.eventPhase = eventPhase;
        return event;
    }

    public override function toString():String {
        return __formatToString("FeshGamepadEvent", [
            "type",
            "bubbles",
            "cancelable",
            "buttonCode"
        ]);
    }

    @:noCompletion private override function __init():Void {
        super.__init();
        buttonCode = 0;
    }
}