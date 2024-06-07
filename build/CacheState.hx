package;

import flixel.FlxG;
import flixel.FlxState;
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

class CacheState extends HelperStates {
    var target:FlxState;
	var stopMusic = false;
    var timer:Float = 0;

    var loadingScene:LoadingScene;

    public function new(target:FlxState, stopMusic:Bool):Void {
        super("void", "void");

        this.target = target;
        this.stopMusic = stopMusic;
    }

    override function create() {
        loadingScene = new LoadingScene();
        add(loadingScene);

		addCallback("cacheBitmapData", function(name:String) {
		    Cache.cacheAsset(name, "");
		});

		Thread.create(() -> {
			cacheStuff();
		});

        super.create();
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
                loadingScene.setCacheValue(i / cacheList.length);
            }

            loadingScene.setCacheValue(1);
        }

		callLua("cache", []);

        loadingScene.callback = function() {
            CacheState.loadAndSwitchState(target, stopMusic, true);
        }
	}

    function loadDialogue(name:String):Array<DialogueData> {
        var parser:JsonParser<Array<DialogueData>> = new JsonParser<Array<DialogueData>>();

		return parser.fromJson(File.getContent(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/$name.json', TEXT, "")), '${name}.json');
    }

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


    static public function loadAndSwitchStateF(target:FlxState, ?stopMusic:Bool = true, ?exception:Bool = false):Void {
        Paths.setCurrentLevel("week" + PlayState.storyWeek);

		if (stopMusic && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
        }

        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, "")) && !exception) {
            FlxG.switchState(new CacheState(new PlayState(), true));
        }else {
            FlxG.switchState(new PlayState());
        }
    }
}
