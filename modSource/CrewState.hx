package;

import flixel.FlxG;
import flixel.util.FlxGradient;
import flixel.FlxSprite;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.util.FlxColor;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;

class CrewState extends MusicBeatState {
    var officalDevTeam:FlxTypedGroup<FlxSprite>;

    var curSelected:Int = 0;

    var globalOffset:Float = 1;

    public function new() {
        super();
    }

    override function create() {
        var background:FlxSprite = FlxGradient.createGradientFlxSprite(FlxG.width, FlxG.height,
            [FlxColor.fromRGB(85, 0, 150), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(43, 8, 180, 75), FlxColor.fromRGB(85, 0, 150)
        ], 1);
        background.screenCenter();
        add(background);

        officalDevTeam = new FlxTypedGroup<FlxSprite>();
        add(officalDevTeam);

        makeCoolPeople();

        var devTeamLogo:FlxSprite = new FlxSprite().loadGraphic(Paths.image("devTeamLogo"));
        add(devTeamLogo);

        changeDev();

        super.create();
    }

    override function update(elapsed:Float) {
        super.update(elapsed);
        
        
    }

    function changeDev(change:Int = 0) {
        curSelected += 0;

        if (curSelected < 0)
			curSelected = officalDevTeam.length - 1;
		if (curSelected > officalDevTeam.length - 1)
			curSelected = 0;

        officalDevTeam.forEachAlive(function(dev:FlxSprite) {
            if(dev.ID == curSelected) {
                if(dev.color.redFloat == 0.1) {
                    //FlxTween.tween();
                }else {
                    globalOffset = 1.1;

                    
                    dev.color = FlxColor.fromRGBFloat(1, 1, 1);
                }
            }else {
                dev.color = FlxColor.fromRGBFloat(0.1, 0.1, 0.1);
            }
        });
    }

    function makeCoolPeople() {
        var suki:FlxSprite = new FlxSprite().loadGraphic(Paths.image("ThiccSuki"));
        suki.ID = 0;

        var frogtreat:FlxSprite = new FlxSprite().loadGraphic(Paths.image("TreatOfDaFrog"));
        frogtreat.ID = 1;
        officalDevTeam.add(frogtreat);

        var difi:FlxSprite = new FlxSprite().loadGraphic(Paths.image("SussyDifi"));
        difi.ID = 2;
        officalDevTeam.add(difi);

        var feeshy:FlxSprite = new FlxSprite().loadGraphic(Paths.image("FeshyFeeshy")); //Dat's Me! :D
        feeshy.ID = 3;
        officalDevTeam.add(feeshy);

        var varsavi:FlxSprite = new FlxSprite().loadGraphic(Paths.image("VarVar"));
        varsavi.ID = 4;
        officalDevTeam.add(varsavi);

        var jdst:FlxSprite = new FlxSprite().loadGraphic(Paths.image("MusicManJDST"));
        jdst.ID = 5;
        officalDevTeam.add(jdst);

        officalDevTeam.add(suki);
    }
}