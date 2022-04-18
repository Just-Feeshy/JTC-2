package;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.FlxState;

import sys.thread.Thread;
import sys.FileSystem;
import sys.io.File;

import json2object.JsonParser;
import lime.utils.Assets;

import ModInitialize;

class CacheState extends MusicBeatState {
    var target:FlxState;
	var stopMusic = false;

    var menuBG:FlxSprite;

    public function new(target:FlxState, stopMusic:Bool) {
        super();

        this.target = target;
        this.stopMusic = stopMusic;
    }

    override function create() {
        menuBG = new FlxSprite();
		menuBG.loadGraphic(Paths.image("default_loading_screen"));
        menuBG.screenCenter();
		add(menuBG);

		Thread.create(() -> {
			cacheStuff();
		});

        super.create();
    }

    function cacheStuff() {
		if(!FlxG.save.data.preload) {
			LoadingState.loadAndSwitchState(target, stopMusic);
			return;
		}

		LoadingState.loadAndSwitchState(target, stopMusic);
	}

    static public function loadAndSwitchState(target:FlxState, ?stopMusic:Bool = true) {
        var parser = new JsonParser<Array<String>>();

        if(Assets.exists(Paths.getPath('data/${PlayState.SONG.song.toLowerCase()}/cache.json', TEXT, ""))) {
            FlxG.switchState(new CacheState(new PlayState(), true));
        }else {
            LoadingState.loadAndSwitchState(new PlayState());
        }

        //parser.fromJson(File.getContent(Paths.json(PlayState.SONG.song.toLowerCase() + "/cache"))
    }
}