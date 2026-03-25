package;

import flixel.FlxG;
import flixel.FlxState;
import sys.thread.Thread;
import sys.FileSystem;
import sys.io.File;
import lime.utils.Assets;
import haxe.Json;
import SaveData.SaveType;

import IDialogue.DialogueData;
import ModInitialize;

#if json2object
import json2object.JsonParser;
#end

using StringTools;

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

		Thread.create(() -> {
			cacheStuff();
		});

        super.create();
    }

    static function getSongCacheDirectory():String {
        var candidates:Array<String> = [];

        inline function pushCandidate(name:String):Void {
            if(name == null) {
                return;
            }

            var value:String = name.toLowerCase().trim();

            if(value != "" && !candidates.contains(value)) {
                candidates.push(value);
            }
        }

        if(PlayState.SONG != null) {
            pushCandidate(PlayState.SONG.song);
            pushCandidate(CoolUtil.readableSongDirectory(PlayState.SONG.song));
        }

        if(PlayState.storyPlaylist != null && PlayState.storyPlaylist.length > 0) {
            pushCandidate(PlayState.storyPlaylist[0]);
            pushCandidate(CoolUtil.readableSongDirectory(PlayState.storyPlaylist[0]));
        }

        for(candidate in candidates) {
            if(Paths.assetExists(Paths.getPath('data/${candidate}/cache.json', TEXT, ""), TEXT)) {
                return candidate;
            }
        }

        return candidates.length > 0 ? candidates[0] : "";
    }

    static function cacheAssetEntry(entry:Dynamic):Void {
        if(entry == null) {
            return;
        }

        var key:String = null;
        var library:String = "";

        if(Std.isOfType(entry, String)) {
            var text:String = cast entry;
            var separatorIndex:Int = text.indexOf(":");

            if(separatorIndex > 0) {
                library = text.substr(0, separatorIndex).trim();
                key = text.substr(separatorIndex + 1).trim();
            }else {
                key = text.trim();
            }
        }else {
            key = Std.string(Reflect.field(entry, "key")).trim();

            if(Reflect.hasField(entry, "library")) {
                library = Std.string(Reflect.field(entry, "library")).trim();
            }
        }

        if(key == null || key == "") {
            return;
        }

        Cache.cacheAsset(key, library, false);
    }

    function cacheStuff():Void {
        Cache.clear();

        var cacheList:Array<Dynamic> = [];
        var dialogueList:Array<DialogueData>;
        var songCacheDirectory:String = getSongCacheDirectory();

        if(songCacheDirectory != "" && Paths.assetExists(Paths.getPath('data/${songCacheDirectory}/dialogue.json', TEXT, ""), TEXT)) {
            dialogueList = loadDialogue("dialogue");
        }

        if(songCacheDirectory != "" && Paths.assetExists(Paths.getPath('data/${songCacheDirectory}/cache.json', TEXT, ""), TEXT)) {
            cacheList = cast Json.parse(Paths.readText(Paths.getPath('data/${songCacheDirectory}/cache.json', TEXT, "")));

            for(i in 0...cacheList.length) {
                // Cache from worker thread without creating Context3D textures.
                // Entries may optionally use "library:key" for non-mod assets.
                cacheAssetEntry(cacheList[i]);
                loadingScene.setCacheValue(i / cacheList.length);
            }

            loadingScene.setCacheValue(1);
        }

        loadingScene.callback = function() {
            CacheState.loadAndSwitchState(target, stopMusic, true);
        }
	}

    function loadDialogue(name:String):Array<DialogueData> {
        var parser:JsonParser<Array<DialogueData>> = new JsonParser<Array<DialogueData>>();
        var songCacheDirectory:String = getSongCacheDirectory();

		return parser.fromJson(Paths.readText(Paths.getPath('data/${songCacheDirectory}/$name.json', TEXT, "")), '${name}.json');
    }

    static public function loadAndSwitchState(target:FlxState, ?stopMusic:Bool = true, ?exception:Bool = false):Void {
        Paths.setCurrentLevel("week" + PlayState.storyWeek);

		if(Std.isOfType(FlxG.state, PlayState)) {
			cast(FlxG.state, PlayState).prepareForStateSwitch();
		}

		if (stopMusic && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
        }

        var songCacheDirectory:String = getSongCacheDirectory();
        var hasSongCache:Bool = songCacheDirectory != "" && Paths.assetExists(Paths.getPath('data/${songCacheDirectory}/cache.json', TEXT, ""), TEXT);

        if(PlayState.SONG.video != null && !exception && !SaveData.getData(SaveType.SKIP_CUTSCENES)) {
            if(hasSongCache) {
                FlxG.switchState(new VideoState(new CacheState(new PlayState(), true), PlayState.SONG.video));
            }else {
                FlxG.switchState(new VideoState(new PlayState(), PlayState.SONG.video));
            }

            return;
        }

        if(hasSongCache && !exception) {
            FlxG.switchState(new CacheState(new PlayState(), true));
        }else {
            FlxG.switchState(new PlayState());
        }
    }


    static public function loadAndSwitchStateF(target:FlxState, ?stopMusic:Bool = true, ?exception:Bool = false):Void {
        Paths.setCurrentLevel("week" + PlayState.storyWeek);

		if(Std.isOfType(FlxG.state, PlayState)) {
			cast(FlxG.state, PlayState).prepareForStateSwitch();
		}

		if (stopMusic && FlxG.sound.music != null) {
			FlxG.sound.music.stop();
        }

        var songCacheDirectory:String = getSongCacheDirectory();
        var hasSongCache:Bool = songCacheDirectory != "" && Paths.assetExists(Paths.getPath('data/${songCacheDirectory}/cache.json', TEXT, ""), TEXT);

        if(hasSongCache && !exception) {
            FlxG.switchState(new CacheState(new PlayState(), true));
        }else {
            FlxG.switchState(new PlayState());
        }
    }
}
