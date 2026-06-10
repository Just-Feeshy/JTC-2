package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxSpriteGroup;
import flixel.util.FlxColor;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.FlxObject;
import feshixl.FeshCamera;

class CrewState extends MusicBeatState {
	private static var byHowMuch = 40;

	private static var fileName:Array<String> = [
		"TreatOfDaFrog",
		"SussyDifi",
		"FeshyFeeshy", // Das Me! :D
		"VarVar",
		"Flx",
	];

    var officalDevTeam:FlxTypedSpriteGroup<CreditSprites>;
    var allTweens:Array<FlxTween>;

    var curSelected:Int = 0;
	var curSprite:CreditSprites;
    var selected:Bool = false;

    public function new() {
        super();
    }

    override function create() {
        persistentUpdate = persistentDraw = true;

        allTweens = new Array<FlxTween>();

        var background:MenuBackground = new MenuBackground(0, 0);
        add(background);

        var backgroundOverlay:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
        backgroundOverlay.alpha = 0.2;
        backgroundOverlay.scrollFactor.set();
        add(backgroundOverlay);

        officalDevTeam = new FlxTypedSpriteGroup<CreditSprites>(0, 50);
        add(officalDevTeam);

        makeCoolPeople();

        var devTeamLogo:FlxSprite = new FlxSprite().loadGraphic(Paths.image("devTeamLogo"));
		devTeamLogo.y = byHowMuch;
        devTeamLogo.scrollFactor.set(0, 1);
        add(devTeamLogo);

        officalDevTeam.forEachAlive(function(dev:CreditSprites) {
            if(dev.ID != curSelected) {
                dev.color = FlxColor.fromRGBFloat(0.1, 0.1, 0.1);
            }else {
                dev.y = -10 + byHowMuch;
            }
        });

		changeDev(0);

        super.create();
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        if(!selected) {
            if(controls.RIGHT_P) {
                changeDev(1);
            }

            if(controls.LEFT_P) {
                changeDev(-1);
            }


		    if(controls.ACCEPT) {
				openLink(curSprite.linkTree);
		    }

            if(controls.BACK) {
                FlxG.switchState(new MainMenuState());
                selected = true;
            }
        }
    }

    function changeDev(change:Int = 0):Void {
        if(change != 0) {
            FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);
        }

        curSelected += change;

        if (curSelected < 0)
			curSelected = officalDevTeam.length - 1;
		if (curSelected > officalDevTeam.length - 1)
			curSelected = 0;

        officalDevTeam.forEachAlive(function(dev:CreditSprites) {
            if(dev.ID & 0xFFFF == curSelected) {
                cleanTween();
                allTweens.push(FlxTween.tween(dev, {redFloat: 1, blueFloat: 1, greenFloat: 1, y: -10 + byHowMuch}, 0.5, {ease: FlxEase.quadOut}));
				curSprite = dev;
            }else {
                dev.color = FlxColor.fromRGBFloat(0.1, 0.1, 0.1);
                dev.y = byHowMuch;
            }
        });

		#if USING_LUA
		callLua("changeDev", [curSelected]);
		#end
    }

    function cleanTween():Void {
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

    function makeCoolPeople():Void {
        var frogtreat:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/" + fileName[0]));
		frogtreat.linkTree = "https://linktr.ee/FrogTreat";
        frogtreat.scrollFactor.set(0, 1);
        frogtreat.ID = 0;

        var difi:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/" + fileName[1]));
		difi.linkTree = "https://twitter.com/DiFicuz";
        difi.scrollFactor.set(0, 1);
        difi.ID = 1;

        var feeshy:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/" + fileName[2]));
		feeshy.linkTree = "https://portfolio.just-feeshy.world/";
        feeshy.scrollFactor.set(0, 1);
        feeshy.ID = 2;

        var varsavi:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/" + fileName[3]));
		varsavi.linkTree = "https://mariawasak.wixsite.com/mariawasak";
        varsavi.scrollFactor.set(0, 1);
        varsavi.ID = 3;

        var flx:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/" + fileName[4]));
		flx.linkTree = "https://erdene.dev/";
        flx.scrollFactor.set(0, 1);
        flx.ID = 4;

        officalDevTeam.add(feeshy);
        officalDevTeam.add(varsavi);
        officalDevTeam.add(flx);
        officalDevTeam.add(frogtreat);
        officalDevTeam.add(difi);
    }

	function addOfficalDev(dev:CreditSprites):Void {
		dev.ID |= officalDevTeam.length << 16;
		officalDevTeam.add(dev);
	}

	function openLink(link:String):Void {
		#if !CAN_OPEN_LINKS
		throw "Can't open links on this platform!";
		#end

		#if linux
		Sys.command('/usr/bin/xdg-open', [link, '&']);
		#else
		FlxG.openURL(link);
		#end
	}

    override function destroy() {
        super.destroy();
        cleanTween();
        allTweens = null;
    }
}
