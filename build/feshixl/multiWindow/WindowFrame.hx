package feshixl.multiWindow;

import lime.ui.Window;
import openfl.events.Event;
import openfl.Assets;

import flixel.system.frontEnds.BitmapFrontEnd;

class WindowFrame extends Sprite {
    var window:Window;

    var cacheFrontEnd:BitmapFrontEnd;

    public function new(window:Window) {
        super();

        addEventListener(Event.ADDED_TO_STAGE, create);

        this.window = window;
    }

    function create(_):Void {
        if(window.stage == null)
            return;

        removeEventListener(Event.ADDED_TO_STAGE, create);


    }
}