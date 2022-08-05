package;

import Controls.KeyboardScheme;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.system.FlxSound;
import flixel.text.FlxText;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;

import SaveData.SaveType;

/**
* Completely override the `PauseSubState` for JTC mod.
*/
class PauseSubState extends MusicBeatSubstate {
    private var doneHover:Bool;
    private var otherStuff:FlxText;

    var grpMenuShit:FlxTypedGroup<FlxSprite>;
    var allTweens:Array<FlxTween>;

    var menuItems:Array<String> = ['Resume', 'Restart Song', 'Change Controls', 'Exit to menu'];
    var curSelected:Int = 0;

    var completeTweens:Int = 0;

    var pauseMusic:FlxSound;

    var assetName:Array<String> = [
		"pause-menu_resume",
		"pause-menu_restart",
		"pause-menu_controls",
		"pause-menu_menu"
	];

    public function new(x:Float, y:Float) {
        super();

        pauseMusic = new FlxSound().loadEmbedded(Paths.music('breakfast'), true, true);
		pauseMusic.volume = 0;
		pauseMusic.play(false, FlxG.random.int(0, Std.int(pauseMusic.length / 2)));

        FlxG.sound.list.add(pauseMusic);

        var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bg.alpha = 0;
		bg.scrollFactor.set();
		add(bg);

        var paused:FlxSprite = new FlxSprite().loadGraphic(Paths.image("pause-menu_paused"));
        paused.x = -FlxG.width;
        add(paused);

        var levelInfo:FlxText = new FlxText(20, 0, 0, "", 32);
		levelInfo.text += PlayState.SONG.song;
        levelInfo.y = FlxG.height - levelInfo.height - (15 + 96);
		levelInfo.scrollFactor.set();
		levelInfo.setFormat(Paths.font("PhantomMuff.ttf"), 32);
		levelInfo.updateHitbox();
		add(levelInfo);

        var levelDifficulty:FlxText = new FlxText(20, FlxG.height - (15 + 32), 0, "", 32);
		levelDifficulty.text += CoolUtil.difficultyString();
        levelDifficulty.y = FlxG.height - levelDifficulty.height - levelInfo.height - 10;
		levelDifficulty.scrollFactor.set();
		levelDifficulty.setFormat(Paths.font('PhantomMuff.ttf'), 32);
		levelDifficulty.updateHitbox();
		add(levelDifficulty);

        otherStuff = new FlxText(20, 15, 0, "", 32);
		otherStuff.scrollFactor.set();
        otherStuff.y = FlxG.height - otherStuff.height - 15;
		otherStuff.setFormat(Paths.font('PhantomMuff.ttf'), 32);
		otherStuff.updateHitbox();
		add(otherStuff);

        levelDifficulty.alpha = 0;
		levelInfo.alpha = 0;
		otherStuff.alpha = 0;

        FlxTween.tween(bg, {alpha: 0.6}, 0.4 * (Conductor.bpm / 120), {ease: FlxEase.quadOut});
        FlxTween.tween(paused, {x: 0}, 0.4 * (Conductor.bpm / 120), {ease: FlxEase.quadOut});
        FlxTween.tween(levelInfo, {alpha: 1, y: FlxG.height - levelInfo.height - (20 + 96)}, 0.4 * (Conductor.bpm / 120), {ease: FlxEase.quadOut, startDelay: 0.3});
		FlxTween.tween(levelDifficulty, {alpha: 1, y: levelDifficulty.y - 10}, 0.4 * (Conductor.bpm / 120), {ease: FlxEase.quadOut, startDelay: 0.5});

        grpMenuShit = new FlxTypedGroup<FlxSprite>();
		add(grpMenuShit);

        allTweens = new Array<FlxTween>();

        for (i in 0...menuItems.length) {
			var songText:FlxSprite = new FlxSprite(FlxG.width, 0);
			songText.loadGraphic(Paths.image("pause_options/" + assetName[i]));
			grpMenuShit.add(songText);
            updateSpriteAlpha();

            FlxTween.tween(songText, {x: (menuItems.length - i) * 30}, 0.4 * (Conductor.bpm / 120), {ease: FlxEase.quadOut, startDelay: 0.03 * i, 
                onComplete: function(twn:FlxTween) {
                    completeTweens++;
                }     
            });
		}

        cameras = [PlayState.camHUD];
    }

    override function update(elapsed:Float) {
		if (pauseMusic.volume < 0.5) {
			pauseMusic.volume += 0.01 * elapsed;
        }

		super.update(elapsed);

        var upP = controls.UP_P;
		var downP = controls.DOWN_P;
		var accepted = controls.ACCEPT;

        if (upP || FlxG.mouse.wheel > 0.1)
        {
            changeSelection(-1);
        }
        
        if (downP || FlxG.mouse.wheel < -0.1)
        {
            changeSelection(1);
        }

        if (accepted || FlxG.mouse.justPressed) {
            var daSelected:String = menuItems[curSelected];

            switch (daSelected)
            {
                case "Resume":
                    close();
                case "Restart Song":
                    FlxG.resetState();
                case "Exit to menu":
                    cleanTween();
                    FlxG.switchState(new MainMenuState());
                case "Change Controls":
                    FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);

                    FlxG.save.data.dfjk += 1;

                    if (FlxG.save.data.dfjk > 3)
                        FlxG.save.data.dfjk = 0;

                    switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
                        case 0:
                            controls.setKeyboardScheme(KeyboardScheme.Duo(true), true);
                        case 1:
                            controls.setKeyboardScheme(KeyboardScheme.Solo, true);
                        case 2:
                            controls.setKeyboardScheme(KeyboardScheme.Duo(false), true);
                        case 3:
                            controls.setKeyboardScheme(KeyboardScheme.Custom, true);
                    }

                    switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
                        case 0:							
                            otherStuff.text = "SCHEME: "+"WASD";
                        case 1:
                            otherStuff.text = "SCHEME: "+"DFJK";
                        case 2:
                            otherStuff.text = "SCHEME: "+"ZX12";
                        case 3:
                            otherStuff.text = "SCHEME: "+"CUSTOM";
                    }
            }
        }

        if(menuItems[curSelected] == "Change Controls") {
            if(!doneHover) {
                doneHover = true;
                FlxTween.tween(otherStuff, {alpha: 1, y: otherStuff.y - 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0});
            }
        }else{
            if(doneHover) {
                doneHover = false;
                FlxTween.tween(otherStuff, {alpha: 0, y: otherStuff.y + 5}, 0.4, {ease: FlxEase.quartInOut, startDelay: 0});
            }
        }
    }

    function changeSelection(change:Int = 0):Void {
        curSelected += change;

        FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);

        if (curSelected < 0)
            curSelected = menuItems.length - 1;
        if (curSelected >= menuItems.length)
            curSelected = 0;

        if(menuItems[curSelected] == "Change Controls") {
            switch(SaveData.getData(SaveType.PRESET_KEYBINDS)) {
                case 0:
                    otherStuff.text = "SCHEME: "+"WASD";
                case 1:
                    otherStuff.text = "SCHEME: "+"DFJK";
                case 2:
                    otherStuff.text = "SCHEME: "+"ZX12";
                case 3:
                    otherStuff.text = "SCHEME: "+"CUSTOM";
            }
        }

        if(completeTweens == menuItems.length) {
            cleanTween();

            for(i in 0...grpMenuShit.length) {
                if(curSelected == i) {
                    var prevX:Float = grpMenuShit.members[i].x;

                    allTweens.push(FlxTween.tween(grpMenuShit.members[i], {x: prevX - 30}, 0.4 * (Conductor.bpm / 120), {ease: FlxEase.quadOut, 
                        onComplete: function(twn:FlxTween) {
                            cleanTween();
                        }     
                    }));
                }else {
                    grpMenuShit.members[i].x = (menuItems.length - i) * 30;
                }
            }
        }

        updateSpriteAlpha();
    }

    function updateSpriteAlpha():Void {
        var index:Int = 0;

        while(index < grpMenuShit.length){
            if(index != curSelected) {
                grpMenuShit.members[index].color = FlxColor.fromRGBFloat(0.6,0.6,0.6);
            }else {
                grpMenuShit.members[curSelected].color = FlxColor.fromRGBFloat(1,1,1);
            }

            index++;
        }
    }

    function cleanTween() {
        if (allTweens != null) {
            var index:Int = 0;
            var tween:FlxTween = null;

            while (index < allTweens.length) {
                tween = allTweens[index++];

                if (tween != null) {
                    tween.cancel();
                    tween.destroy();
                }

                allTweens.remove(tween);
            }
        }
    }
}