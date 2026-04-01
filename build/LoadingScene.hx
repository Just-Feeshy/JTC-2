package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.group.FlxSpriteGroup;
import flixel.ui.FlxBar;
import SaveData.SaveType;

using StringTools;

#if sys
import sys.FileSystem;
import sys.thread.Thread;
#end

class LoadingScene extends FlxSpriteGroup {
    public static var bootSongCachesReady(default, null):Bool = false;

    public var callback:Void->Void;
    public var cacheValue(default, null):Float = 0;

    var menuBG:FlxSprite;
    var loadingBar:FlxBar;
    var cacheTween:FlxTween;
    var loading:Alphabet;

    var prevCacheValue:Float = 0;
    var colorSway:Float = 0;

    public function new() {
        super();

        menuBG = new FlxSprite();
		menuBG.loadGraphic(Paths.image(Paths.modJSON.background_images[FlxG.random.int(0, Paths.modJSON.background_images.length - 1)]));
        menuBG.scrollFactor.set();
        menuBG.screenCenter();
		add(menuBG);

        if(Paths.modJSON.loading_display.show_loading_bar) {
            loadingBar = new FlxBar(0, 0, FlxBarFillDirection.LEFT_TO_RIGHT, FlxG.width, 15, this,
                "cacheValue", 0, 1);
            loadingBar.y = FlxG.height - loadingBar.height;
            loadingBar.createFilledBar(
                parseColor(Paths.modJSON.loading_display.loading_bar_colors[0]),
                parseColor(Paths.modJSON.loading_display.loading_bar_colors[1])
            );

            loadingBar.alpha = Paths.modJSON.loading_display.loading_bar_alpha;
            add(loadingBar);
        }

        loading = new Alphabet(0, 0, "Loading", true, false, 30);
        loading.y = (FlxG.height - loading.height) - 30;
        add(loading);
    }

    public function setCacheValue(cv:Float, shouldTween:Bool = true) {
		if(cacheTween != null) {
			cacheTween.cancel();
			cacheTween.destroy();

			cacheValue = prevCacheValue;
		}

		final tempCacheValue:Float = cacheValue;
		prevCacheValue = cv;

		if(Math.abs(cv - tempCacheValue) > 0.02) {
			cacheTween = FlxTween.tween(this, {cacheValue: cv}, Math.abs(cv - tempCacheValue) * 5, {ease: FlxEase.quadOut});
		}else {
			cacheValue = cv;
		}
	}

    /**
    * Default Loader
    */
    #if sys
    static function collectBootSongDirectories():Array<String> {
        var result:Array<String> = [];

        inline function addSongDirectory(path:String):Void {
            if(path == null || path.trim() == "") {
                return;
            }

            if(FileSystem.exists(path) && FileSystem.isDirectory(path)) {
                for(entry in FileSystem.readDirectory(path)) {
                    var songPath:String = path + "/" + entry;

                    if(FileSystem.exists(songPath) && FileSystem.isDirectory(songPath) && !result.contains(entry)) {
                        result.push(entry);
                    }
                }
            }
        }

        if(Paths.modJSON != null && Paths.modJSON.cache_configuration != null) {
            for(path in Paths.modJSON.cache_configuration) {
                if(path != null && path.toLowerCase().indexOf("/songs") != -1) {
                    addSongDirectory(path);
                }
            }
        }

        if(result.length == 0) {
            addSongDirectory("mod_assets/songs");
        }

        return result;
    }

    static function collectBootSongAudioEntries(songDirectories:Array<String>):Array<Array<String>> {
        var result:Array<Array<String>> = [];
        var soundFiles:Array<String> = ["Inst", "Voices", "1_Voices", "2_Voices"];

        for(songDirectory in songDirectories) {
            for(soundFile in soundFiles) {
                if(Paths.songSoundExists(songDirectory, soundFile)) {
                    result.push([songDirectory, soundFile]);
                }
            }
        }

        return result;
    }

    static function cacheSongAudio(song:String, soundFile:String):Void {
        if(Paths.songSoundExists(song, soundFile)) {
            Paths.songSound(song, soundFile);
        }
    }

    public function cacheNecessaries():Void {
        bootSongCachesReady = false;

        if(!SaveData.getData(SaveType.CACHE_ASSETS)) {
            bootSongCachesReady = true;
            setCacheValue(1, false);
            return;
        }

        Thread.create(() -> {
            var songAudioEntries:Array<Array<String>> = collectBootSongAudioEntries(collectBootSongDirectories());
            var totalEntries:Int = songAudioEntries.length;
            var cachedEntries:Int = 0;

            if(totalEntries <= 0) {
                bootSongCachesReady = true;
                setCacheValue(1, false);
                return;
            }

            for(songAudio in songAudioEntries) {
                cacheSongAudio(songAudio[0], songAudio[1]);
                cachedEntries++;
                setCacheValue(cachedEntries / totalEntries);
            }

            bootSongCachesReady = true;
            setCacheValue(1, false);
        });
    }
    #end

    override function update(elapsed:Float) {
        if(loading != null) {
            loading.forEach(function(spr:FlxSprite) {
                spr.color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
                0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
            });

            colorSway += elapsed;
        }

        if(cacheValue >= 1 && callback != null) {
            callback();
            callback = null;
        }

        super.update(elapsed);
    }

    // Parse color string safely to handle unsigned 32-bit values on Windows/CPP
    private static function parseColor(colorStr:String):Int {
        if (colorStr == null) return 0;

        var hex:String = colorStr.trim();

        // Remove 0x prefix if present
        if (hex.toLowerCase().startsWith("0x")) {
            hex = hex.substr(2);
        }

        // Pad with alpha if only RGB provided (6 chars or less)
        if (hex.length <= 6) {
            hex = "ff" + StringTools.lpad(hex, "0", 6);
        }

        // Parse in two 16-bit parts to avoid Int32 overflow on Windows/CPP
        var highStr:String = "0x" + hex.substr(0, 4);
        var lowStr:String = "0x" + hex.substr(4, 4);
        var high:Null<Int> = Std.parseInt(highStr);
        var low:Null<Int> = Std.parseInt(lowStr);

        return ((high != null ? high : 0) << 16) | (low != null ? low : 0);
    }
}
