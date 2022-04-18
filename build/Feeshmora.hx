package;

#if windows
import Discord.DiscordClient;
#end

import Song.SwagSong;
import flixel.addons.ui.FlxUIText;
import flixel.FlxG;
import Controls.Control;
import flixel.tweens.FlxTween;
import flixel.input.gamepad.FlxGamepad;
import flixel.graphics.FlxGraphic;
import flixel.util.FlxGradient;
import flixel.ui.FlxBar;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUITabMenu;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.math.FlxMath;
import flixel.FlxSprite;
import flixel.tweens.FlxEase;
import flixel.util.FlxTimer;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import flixel.FlxObject;
import flixel.FlxCamera;
import sys.FileSystem;
import sys.io.File;
import haxe.Json;

import ModInitialize;
import Alphabet;
import Options;

import json2object.JsonParser;

using StringTools;

typedef Example = Map<String, Array<Array<Float>>>;

class ChooseFeeshmora {
    private static var parser = new JsonParser<Example>();

    public static final avaiableColors:Array<String> = [
        "red",
        "transparent",
        "lime",
        "blue",
        "black",
        "cyan",
        "brown",
        "gray",
        "green",
        "magenta",
        "orange",
        "pink",
        "purple",
        "white",
        "yellow"
    ];

    public static var chooseSkin:Map<String, Array<Float>> = [
        "boyfriend" => new Array<Float>(),
        "health" => new Array<Float>()
    ];

    inline public static function changeMapArray(switcher:String, daGet:Int):Void {
        parser.fromJson(File.getContent(Paths.mora("skins", "json")), "skins.json").get(switcher)[daGet-1];
    }

    inline public static function getMapSize(switcher:String):Int {
        if(File.getContent(Paths.mora("skins", "json")).length < 48)
            return 0;

        trace(parser.fromJson(File.getContent(Paths.mora("skins", "json")), "skins.json").get(switcher).length);

        return parser.fromJson(File.getContent(Paths.mora("skins", "json")), "skins.json").get(switcher).length;
    }
}

class FeeshSprite extends FlxSprite {
	public var curAbstract:String = "rings";

	public function new(x:Float, y:Float, ?ab:String = "rings", ?secondSprite:Bool = false) {
		super(x, y);
		curAbstract = ab;

        antialiasing = true;

		switch (curAbstract) {
			case "rings":
                if(secondSprite)
                    loadGraphic(Paths.image('reversePoison'));
                else
				    loadGraphic(Paths.image('reverse'));
		}
	}

	override function update(elapsed:Float) {
		if(curAbstract == "rings")
			angle += Conductor.bpm/120;

		super.update(elapsed);
	}
}