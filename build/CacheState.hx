package;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxState;
import flixel.ui.FlxBar;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import sys.thread.Thread;
import sys.FileSystem;
import sys.io.File;
import lime.utils.Assets;
import haxe.Json;

import IDialogue.DialogueData;
import ModInitialize;

#if json2object
import json2object.JsonParser;
#end

class CacheState extends MusicBeatState {
    public var cacheBar:Float = 0;

    var target:FlxState;
	var stopMusic = false;

    var menuBG:FlxSprite;
    var loadingBar:FlxBar;
    var cacheTween:FlxTween;
    var loading:Alphabet;

    var colorSway:Float = 0;
    var timer:Float = 0;

    public function new(target:FlxState, stopMusic:Bool):Void {
        super();

        this.target = target;
        this.stopMusic = stopMusic;
    }

    override function create() {
        menuBG = new FlxSprite();
		menuBG.loadGraphic(Paths.image(Paths.modJSON.background_images[FlxG.random.int(0, Paths.modJSON.background_images.length - 1)]));
        menuBG.scrollFactor.set();
        menuBG.screenCenter();
		add(menuBG);

        if(Paths.modJSON.loading_display.show_loading_bar) {
            loadingBar = new FlxBar(0, 0, FlxBarFillDirection.LEFT_TO_RIGHT, FlxG.width, 10, this,
                "cacheBar", 0, 1);
        }

        loading = new Alphabet(0, 0, "Loading", true, false, 30);
        loading.y = (FlxG.height - loading.height) - 30;
        add(loading);

		Thread.create(() -> {
			cacheStuff();
		});

        super.create();
    }

    override function update(elapsed:Float):Void {
        if(loading != null) {
            loading.forEach(function(spr:FlxSprite) {
                spr.color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
                0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
            });

            colorSway += elapsed;
        }
        
        super.update(elapsed);
    }

    function cacheStuff():Void {
        Cache.clear();

        var cacheList:Array<String> = [];
        var dialogueList:Array<DialogueData>;
        
        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/dialogue.json', TEXT, ""))) {
            dialogueList = loadDialogue("dialogue");
        }

        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, ""))) {
            cacheList = cast Json.parse(Assets.getText(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, "")));

            for(i in 0...cacheList.length) {
                Cache.cacheAsset(cacheList[i], "");
                cacheBar = i / cacheList.length;
            }

            cacheBar = cacheList.length;
        }

        new FlxTimer().start(0.1, function(tmr:FlxTimer) {
            CacheState.loadAndSwitchState(target, stopMusic, true);
        });
	}

    #if json2object
    function loadDialogue(name:String):Array<DialogueData> {
        var parser:JsonParser<Array<DialogueData>> = new JsonParser<Array<DialogueData>>();

		return parser.fromJson(File.getContent(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/$name.json', TEXT, "")), '${name}.json');
    }
    #end

    static public function loadAndSwitchState(target:FlxState, ?stopMusic:Bool = true, ?exception:Bool = false):Void {
        Paths.setCurrentLevel("week" + PlayState.storyWeek);

		if (stopMusic && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
        }

        if(PlayState.SONG.video != null && !exception) {
            if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, ""))) {
                FlxG.switchState(new VideoState(new CacheState(new PlayState(), true), PlayState.SONG.video));
            }else {
                FlxG.switchState(new VideoState(new PlayState(), PlayState.SONG.video));
            }

            return;
        }

        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, "")) && !exception) {
            FlxG.switchState(new CacheState(new PlayState(), true));
        }else {
            FlxG.switchState(new PlayState());
        }
    }
}