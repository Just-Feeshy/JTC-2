package;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxState;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;

import sys.thread.Thread;
import sys.FileSystem;
import sys.io.File;

import feshixl.interfaces.IDialogue;
import lime.utils.Assets;
import haxe.Json;

import ModInitialize;

#if json2object
import json2object.JsonParser;
#end

class CacheState extends MusicBeatState {
    var target:FlxState;
	var stopMusic = false;

    var menuBG:FlxSprite;
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

        var cacheList:Array<String>;
        var dialogueList:Array<DialogueData>;
        
        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/dialogue.json', TEXT, ""))) {
            dialogueList = loadDialogue("dialogue");
        }

        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, ""))) {
            cacheList = cast Json.parse(Assets.getText(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, "")));

            for(i in 0...cacheList.length) {
                Cache.cacheAsset(cacheList[i], "");
            }
        }

        new FlxTimer().start(0.1, function(tmr:FlxTimer) {
            LoadingState.loadAndSwitchState(target, stopMusic);
        });
	}

    #if json2object
    function loadDialogue(name:String):Array<DialogueData> {
        var parser:JsonParser<Array<DialogueData>> = new JsonParser<Array<DialogueData>>();

		return parser.fromJson(File.getContent(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/$name.json', TEXT, "")), '${name}.json');
    }
    #end

    function switchStateLoad():Void {
        LoadingState.loadAndSwitchState(target, stopMusic);
    }

    static public function loadAndSwitchState(target:FlxState, ?stopMusic:Bool = true):Void {
        if(PlayState.SONG.video != null) {
            if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, ""))) {
                FlxG.switchState(new VideoState(new CacheState(new PlayState(), true), PlayState.SONG.video));
            }else {
                LoadingState.loadAndSwitchState(new VideoState(new PlayState(), PlayState.SONG.video));
            }

            return;
        }

        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, ""))) {
            FlxG.switchState(new CacheState(new PlayState(), true));
        }else {
            LoadingState.loadAndSwitchState(new PlayState());
        }
    }
}