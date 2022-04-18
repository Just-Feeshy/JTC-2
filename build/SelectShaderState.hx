package;

import Song.SwagSong;
import flixel.FlxG;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxTimer;
import lime.utils.Assets;
import sys.FileSystem;
import sys.io.File;
import haxe.Json;

#if json2object
import json2object.JsonParser;
#end

#if windows
import Discord.DiscordClient;
#end

import Feeshmora;

class SelectShaderState extends MusicBeatState { //WIP
    private static var shaderName:Array<String> = new Array<String>();
    private static var parserShader = new JsonParser<Array<Int>>();
    private static final shadedCat:Array<String> = ["boyfriend", "main game", "girlfriend", "opponent", "note assets"];

    private var song:SwagSong;

    private var boyfriendAgain:Boyfriend;
    private var selectSprite:HealthIcon;

    private var getShaders:Array<Array<String>> = new Array<Array<String>>();

    private var maxSelect:Array<Int> = new Array<Int>();
    private var selected:Array<Int>;
    private var selector:Int = 0;

    private var ifCatalog:Bool = true;
    private var transition:Bool;

    private var shaderGroup:FlxTypedGroup<Alphabet>;

    public function new(song:SwagSong) {
        this.song = song;

        super();
    }

    override function create() {
        FlxG.mouse.visible = false;

        #if windows
		DiscordClient.changePresence("Selecting Certain Shaders", null);
		#end

        boyfriendAgain = new Boyfriend(FlxG.width, FlxG.height/2, "bf");
        boyfriendAgain.scrollFactor.set();
        boyfriendAgain.setGraphicSize(Std.int(boyfriendAgain.width/1.5));
        boyfriendAgain.updateHitbox();
        boyfriendAgain.x -= boyfriendAgain.width + 100;

        boyfriendAgain.playAnim('idle');

        add(boyfriendAgain);

        selectSprite = new HealthIcon("bf", false, song.bpm);
        add(selectSprite);

        persistentUpdate = true;

        createList();
        createStaticMenu();

        super.create();
    }

    function createStaticMenu():Void {
        var maxLoop:Int = ifCatalog ? shadedCat.length : getShaders.length;

        var sv:Int = -1;

        if(shaderGroup == null) {
            shaderGroup = new FlxTypedGroup<Alphabet>();
            add(shaderGroup);
        }    

        if(shaderGroup.members[0] != null)
            shaderGroup.clear();

        for(i in 0...maxLoop) {       
            if(getShaders[i][0] == shadedCat[selector] || ifCatalog) {
                if(sv == -1)sv = i;

                var label:Alphabet = new Alphabet(0, (70 * (i-sv)) + 30, (ifCatalog ? shadedCat[i] : getShaders[i][1]), true, false);
                label.isMenuItem = true;
                
                label.targetY = i-sv;

                shaderGroup.add(label);

                if(!ifCatalog) {
                    selectSprite.visible = true;

                    if(i-sv == selected[shadedCat.indexOf(shadedCat[selector])])
                        selectSprite.sprTracker = label;
                }else {
                    selectSprite.visible = false;
                }
            }
        }

        selector = 0;

        if(!ifCatalog) {
            if(shaderGroup.members[selector].y == selectSprite.sprTracker.y)
                selectSprite.alpha = 1;
            else
                selectSprite.alpha = 0.6;
        }    
    }

    function createList():Void {
        var catHandler:String;

        for(i in shadedCat) {
            catHandler = "";

            getShaders.push([i, "None"]);

            if(FileSystem.readDirectory('assets/linc/shaders/${i.toLowerCase()}') != null) {
                for(v in FileSystem.readDirectory('assets/linc/shaders/${i.toLowerCase()}')) {
                    if(Paths.cpp(v.split(".")[0], 'shaders/'+i.toLowerCase()) != null) {
                        getShaders.push([i, v.split(".")[0]]);
                        catHandler = catHandler + i + "#";
                    }
                }

                maxSelect.push(catHandler.split("#").length - 1);
            }
        }

        selected = getMax_SV(parserShader.fromJson(File.getContent(Paths.mora("shaders", "json")), "shaders.json"));
    }

    function getMax_SV(messyArray:Array<Int>):Array<Int> {
        var buildUp:Array<Int> = [];

        while(buildUp.length < messyArray.length) {
            if(messyArray[Std.int(Math.max(0, buildUp.length - 1))] <= maxSelect[Std.int(Math.max(0, buildUp.length - 1))])
                buildUp.push(messyArray[Std.int(Math.max(0, buildUp.length))]);
            else
                buildUp.push(0);
        }

        trace(
            "JSON FILE: " + messyArray + " " +
            "ALL FILES: " + maxSelect + " " +
            "COMPILER: " + buildUp
        );

        File.saveContent(Paths.mora("shaders", "json"), Json.stringify(buildUp));

        return buildUp;
    }

    override function beatHit() {
        super.beatHit();

        if(boyfriendAgain.animation.finished)
            boyfriendAgain.playAnim('idle');
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        if (FlxG.sound.music != null)
			Conductor.songPosition = FlxG.sound.music.time;

        if (controls.BACK && !transition) {

            if(ifCatalog) {
                Options.catalogs.splice(0, Options.catalogs.length);
                FlxG.switchState(new InGameOptions(song));
            }else {
                transition = true;

                for (i in shaderGroup.members) {for(v in i.members) {FlxTween.tween(v, {alpha: 0}, 0.2, {ease: FlxEase.quadOut});}}   
                
                new FlxTimer().start(0.25, function(tmr:FlxTimer) {
                    ifCatalog = true;
                    createStaticMenu();
                    transition = false;
                });
            }
        }

        if(controls.ACCEPT && !transition) {

            if(ifCatalog) {
                transition = true;

                FlxG.sound.play(Paths.sound("scrollMenu"), 0.5);

                for (i in shaderGroup.members) {for(v in i.members) {FlxTween.tween(v, {alpha: 0}, 0.2, {ease: FlxEase.quadOut});}}   
                
                new FlxTimer().start(0.25, function(tmr:FlxTimer) {
                    ifCatalog = false;
                    createStaticMenu();
                    transition = false;
                });
            }else {
                selected[shadedCat.indexOf(getShaders[selector][0])] = selector;
                selectSprite.sprTracker = shaderGroup.members[selector];
                selectSprite.alpha = 1;

                File.saveContent(Paths.mora("shaders", "json"), Json.stringify(selected));
            }
        }

        if (controls.UP_P && !transition)
            changeSelection(1);
        if (controls.DOWN_P && !transition)
            changeSelection(-1);
    }

    private function changeSelection(change:Int) {
        selector -= change;

        if((selector >= 0 && selector < shaderGroup.length && shaderGroup.members[1] != null) || ifCatalog)
            FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);

        if (selector < 0)
			selector = shaderGroup.length - 1;
		if (selector >= shaderGroup.length)
			selector = 0;

        var trulyBullShit:Int = 0;

        for (v in shaderGroup.members) {
			v.targetY = trulyBullShit - selector;
			trulyBullShit++;

			v.alpha = 0.6;

			if (v.targetY == 0)
				v.alpha = 1;
		}

        if(!ifCatalog)
            selectSprite.alpha = selectSprite.sprTracker.alpha;
    }
    
    //Get Shader Info
    inline public static function getShadeList():Array<Int> {
        return parserShader.fromJson(File.getContent(Paths.mora("shaders", "json")), "shaders.json");
    }

    static public function getExactShaders(folder:String):String {
        shaderName.splice(0, shaderName.length);

        if(FileSystem.readDirectory('assets/linc/shaders/${folder}') != null) {
            for(v in FileSystem.readDirectory('assets/linc/shaders/${folder}')) {
                if(Paths.cpp(v.split(".")[0], 'shaders/$folder') != null) {
                    shaderName.push(v.split(".")[0]);
                }
            }
        }

        if(shaderName[SelectShaderState.getShadeList()[shadedCat.indexOf(folder)]-1] != null)
            return shaderName[SelectShaderState.getShadeList()[shadedCat.indexOf(folder)]-1];
        else
            return "
        #pragma header

        void main() {
            gl_FragColor = texture2D(bitmap, openfl_TextureCoordv);
        }"; //Preloads each pixel of the sprite it's slapped on, just incase it has no shader file.
    }
}