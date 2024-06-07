package;

import flixel.FlxG;
import feshixl.utils.FeshGradient;
import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.util.FlxColor;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.FlxObject;

class CrewState extends MusicBeatState {
    var camFollow:FlxObject;

    var officalDevTeam:FlxTypedGroup<CreditSprites>;
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

        var background:FlxSprite = FeshGradient.createGradientFlxSprite(FlxG.width, FlxG.height,
            [FlxColor.fromRGB(85, 0, 150), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(85, 0, 150)
		]);
        background.screenCenter();
        background.scrollFactor.set();
        add(background);

        officalDevTeam = new FlxTypedGroup<CreditSprites>();
        add(officalDevTeam);

        makeCoolPeople();

        var devTeamLogo:FlxSprite = new FlxSprite().loadGraphic(Paths.image("devTeamLogo"));
        devTeamLogo.scrollFactor.set(0, 1);
        add(devTeamLogo);

        officalDevTeam.forEachAlive(function(dev:CreditSprites) {
            if(dev.ID != curSelected) {
                dev.color = FlxColor.fromRGBFloat(0.1, 0.1, 0.1);
            }else {
                dev.y = -10;
            }
        });

        camFollow = new FlxObject(0, 0, 1, 1);
		add(camFollow);

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
        curSelected += change;

        if (curSelected < 0)
			curSelected = officalDevTeam.length - 1;
		if (curSelected > officalDevTeam.length - 1)
			curSelected = 0;

        officalDevTeam.forEachAlive(function(dev:CreditSprites) {
            if(dev.ID & 0xFFFF == curSelected) {
                cleanTween();
                allTweens.push(FlxTween.tween(dev, {redFloat: 1, blueFloat: 1, greenFloat: 1, y: -10}, 0.5, {ease: FlxEase.quadOut}));
				curSprite = dev;
            }else {
                dev.color = FlxColor.fromRGBFloat(0.1, 0.1, 0.1);
                dev.y = 0;
            }
        });
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
        var suki:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/ThiccSuki"));
		suki.linkTree = "https://www.youtube.com/channel/UCMI12jyPsfv8ncm5VjD8h5w";
        suki.scrollFactor.set(0, 1);
        suki.ID = 0;

        var frogtreat:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/TreatOfDaFrog"));
		frogtreat.linkTree = "https://linktr.ee/FrogTreat";
        frogtreat.scrollFactor.set(0, 1);
        frogtreat.ID = 1;

        var difi:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/SussyDifi"));
		difi.linkTree = "https://twitter.com/DiFicuz";
        difi.scrollFactor.set(0, 1);
        difi.ID = 2;

        var feeshy:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/FeshyFeeshy")); //Dat's Me! :D
		feeshy.linkTree = "https://kung.foo/feeshy";
        feeshy.scrollFactor.set(0, 1);
        feeshy.ID = 3;
        officalDevTeam.add(feeshy);

        var varsavi:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/VarVar"));
		varsavi.linkTree = "https://mariawasak.wixsite.com/mariawasak";
        varsavi.scrollFactor.set(0, 1);
        varsavi.ID = 4;
        officalDevTeam.add(varsavi);

        var jdst:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("credits/menu/MusicManJDST"));
		jdst.linkTree = "https://twitter.com/JDSTtwt";
        jdst.scrollFactor.set(0, 1);
        jdst.ID = 5;
        officalDevTeam.add(jdst);

        officalDevTeam.add(frogtreat);
        officalDevTeam.add(difi);
        officalDevTeam.add(suki);
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
