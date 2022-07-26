package;

import flixel.FlxG;
import flixel.util.FlxGradient;
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
    var selected:Bool = false;

    public function new() {
        super();
    }

    override function create() {
        persistentUpdate = persistentDraw = true;

        allTweens = new Array<FlxTween>();

        var background:FlxSprite = FlxGradient.createGradientFlxSprite(FlxG.width, FlxG.height,
            [FlxColor.fromRGB(85, 0, 150), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(85, 0, 150)
        ], 1);
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

            if(controls.BACK) {
                FlxG.switchState(new MainMenuState());
                selected = true;
            }
        }
    }

    function changeDev(change:Int = 0) {
        curSelected += change;

        if (curSelected < 0)
			curSelected = officalDevTeam.length - 1;
		if (curSelected > officalDevTeam.length - 1)
			curSelected = 0;

        officalDevTeam.forEachAlive(function(dev:CreditSprites) {
            if(dev.ID == curSelected) {
                cleanTween();
                allTweens.push(FlxTween.tween(dev, {redFloat: 1, blueFloat: 1, greenFloat: 1, y: -10}, 0.5, {ease: FlxEase.quadOut}));
            }else {
                dev.color = FlxColor.fromRGBFloat(0.1, 0.1, 0.1);
                dev.y = 0;
            }
        });
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

    function makeCoolPeople() {
        var suki:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("ThiccSuki"));
        suki.scrollFactor.set(0, 1);
        suki.ID = 0;

        var frogtreat:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("TreatOfDaFrog"));
        frogtreat.scrollFactor.set(0, 1);
        frogtreat.ID = 1;

        var difi:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("SussyDifi"));
        difi.scrollFactor.set(0, 1);
        difi.ID = 2;

        var feeshy:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("FeshyFeeshy")); //Dat's Me! :D
        feeshy.scrollFactor.set(0, 1);
        feeshy.ID = 3;
        officalDevTeam.add(feeshy);

        var varsavi:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("VarVar"));
        varsavi.scrollFactor.set(0, 1);
        varsavi.ID = 4;
        officalDevTeam.add(varsavi);

        var jdst:CreditSprites = cast new CreditSprites().loadGraphic(Paths.image("MusicManJDST"));
        jdst.scrollFactor.set(0, 1);
        jdst.ID = 5;
        officalDevTeam.add(jdst);

        officalDevTeam.add(frogtreat);
        officalDevTeam.add(difi);
        officalDevTeam.add(suki);
    }
}