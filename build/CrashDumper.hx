package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUITabMenu;
import flixel.util.FlxColor;
import flixel.text.FlxText;
import flixel.group.FlxSpriteGroup;
import feshixl.filters.GuassianBlur;
import openfl.events.UncaughtErrorEvent;
import openfl.utils.Assets;
import openfl.Lib;

class CrashDumper extends HelperStates {
    public function new() {
        super();

        Lib.current.loaderInfo.uncaughtErrorEvents.addEventListener(UncaughtErrorEvent.UNCAUGHT_ERROR, _onErrorDump);
    }

    override function create() {
        Lib.application.window.width = Math.ceil(FlxG.width / 2);
        Lib.application.window.height = Math.ceil(FlxG.height / 2);

        Lib.application.window.resizable = false;

        Lib.application.window.title = "Annoying Crash Log";

        var bg:FlxSprite = new FlxSprite().loadGraphic(Paths.image("default_loading_screen"));
        bg.shader = new GuassianBlur(25, Assets.getBitmapData(Paths.image("default_loading_screen")));
        add(bg);

        var gray:FlxUITabMenu = new FlxUITabMenu(null, [], true);
        gray.color = FlxColor.fromRGBFloat(0.2, 0.2, 0.2);
        gray.resize(600, 400);
        gray.screenCenter();
        gray.y -= 20;
        add(gray);

        var darkgray:FlxSprite = new FlxSprite().makeGraphic(500, 300, FlxColor.fromRGBFloat(0.05, 0.05, 0.05));
        darkgray.x = (gray.width / 2) - (darkgray.width / 2);
        darkgray.y = (gray.height / 2) - (darkgray.height / 2) + 25;
        gray.add(darkgray);

        var crashtext:FlxText = new FlxText(0, 25, 0, "Game Crashed", 32);
        crashtext.x = (gray.width / 2) - (crashtext.width / 2);
        gray.add(crashtext);

        var description:FlxText = new FlxText(0, 25 + darkgray.y, "", 16);
        description.x = (gray.width / 2) - (description.width / 2);
        gray.add(description);

        super.create();
    }



    public function _onErrorDump(e:Dynamic):Void {
        trace(e);
        return;
    }
}