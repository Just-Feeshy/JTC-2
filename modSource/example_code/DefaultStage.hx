package example_code;

import template.StageBuilder;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.effects.FlxTrail;
import flixel.addons.effects.chainable.FlxWaveEffect;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.system.FlxSound;
import flixel.util.FlxTimer;
import flixel.util.FlxDestroyUtil;

class DefaultStage extends StageBuilder {
    var halloweenBG:FlxSprite;
    var phillyCityLights:FlxTypedGroup<FlxSprite>;
    var grpLimoDancers:FlxTypedGroup<BackgroundDancer>;
    var phillyTrain:FlxSprite;
    var limo:FlxSprite;
    var upperBoppers:FlxSprite;
    var bottomBoppers:FlxSprite;
    var fastCar:FlxSprite;
    var santa:FlxSprite;
    var bgGirls:BackgroundGirls;
    var trainSound:FlxSound;

    var trainFrameTiming:Float = 0;
    var lightningStrikeBeat:Int = 0;
	var lightningOffset:Int = 8;
    var trainCooldown:Int = 0;
    var curLight:Int = 0;
    var trainCars:Int = 8;

    var isPixel:Bool = false;
    var isHalloween:Bool = false;
    var trainMoving:Bool = false;
    var fastCarCanDrive:Bool = true;
    var startedMoving:Bool = false;
    var trainFinishing:Bool = false;

    public function new(stage:String) {
        super(stage);

        switch (stage) {
			case 'spooky': {
                directory = "week2";

                isHalloween = true;

                var hallowTex = Paths.getSparrowAtlas('halloween_bg');

                halloweenBG = new FlxSprite(-200, -100);
                halloweenBG.frames = hallowTex;
                halloweenBG.animation.addByPrefix('idle', 'halloweem bg0');
                halloweenBG.animation.addByPrefix('lightning', 'halloweem bg lightning strike', 24, false);
                halloweenBG.animation.play('idle');
                halloweenBG.antialiasing = FlxG.save.data.showAntialiasing;
                addToStage(halloweenBG);
			}
			case 'philly': {
                directory = "week3";

				var bg:FlxSprite = new FlxSprite(-100).loadGraphic(Paths.image('philly/sky'));
				bg.scrollFactor.set(0.1, 0.1);
				addToStage(bg);

				var city:FlxSprite = new FlxSprite(-10).loadGraphic(Paths.image('philly/city'));
				city.scrollFactor.set(0.3, 0.3);
				city.setGraphicSize(Std.int(city.width * 0.85));
				city.updateHitbox();
				addToStage(city);

				phillyCityLights = new FlxTypedGroup<FlxSprite>();
				addToStage(phillyCityLights);

				for (i in 0...5) {
						var light:FlxSprite = new FlxSprite(city.x).loadGraphic(Paths.image('philly/win' + i));
						light.scrollFactor.set(0.3, 0.3);
						light.visible = false;
						light.setGraphicSize(Std.int(light.width * 0.85));
						light.updateHitbox();
						light.antialiasing = true;
						phillyCityLights.add(light);
				}

				var streetBehind:FlxSprite = new FlxSprite(-40, 50).loadGraphic(Paths.image('philly/behindTrain'));
				addToStage(streetBehind);

				phillyTrain = new FlxSprite(2000, 360).loadGraphic(Paths.image('philly/train'));
                addToStage(phillyTrain);

				trainSound = new FlxSound().loadEmbedded(Paths.sound('train_passes'));
				FlxG.sound.list.add(trainSound);

				// var cityLights:FlxSprite = new FlxSprite().loadGraphic(AssetPaths.win0.png);

				var street:FlxSprite = new FlxSprite(-40, streetBehind.y).loadGraphic(Paths.image('philly/street'));
				addToStage(street);
			}
			case 'limo': {
                directory = "week4";

				setDefaultCameraZoom(0.90);

				var skyBG:FlxSprite = new FlxSprite(-120, -50).loadGraphic(Paths.image('limo/limoSunset'));
				skyBG.scrollFactor.set(0.1, 0.1);
				addToStage(skyBG);

				var bgLimo:FlxSprite = new FlxSprite(-200, 480);
				bgLimo.frames = Paths.getSparrowAtlas('limo/bgLimo');
				bgLimo.animation.addByPrefix('drive', "background limo pink", 24);
				bgLimo.animation.play('drive');
				bgLimo.scrollFactor.set(0.4, 0.4);
				addToStage(bgLimo);

				grpLimoDancers = new FlxTypedGroup<BackgroundDancer>();
				addToStage(grpLimoDancers);

				for (i in 0...5)
				{
                    var dancer:BackgroundDancer = new BackgroundDancer((370 * i) + 130, bgLimo.y - 400);
                    dancer.scrollFactor.set(0.4, 0.4);
                    grpLimoDancers.add(dancer);
				}

				var overlayShit:FlxSprite = new FlxSprite(-500, -600).loadGraphic(Paths.image('limo/limoOverlay'));
				overlayShit.alpha = 0.5;
				// add(overlayShit);

				// var shaderBullshit = new BlendModeEffect(new OverlayShader(), FlxColor.RED);

				// FlxG.camera.setFilters([new ShaderFilter(cast shaderBullshit.shader)]);

				// overlayShit.shader = shaderBullshit;

				var limoTex = Paths.getSparrowAtlas('limo/limoDrive');

				limo = new FlxSprite(-120, 550);
				limo.frames = limoTex;
				limo.animation.addByPrefix('drive', "Limo stage", 24);
				limo.animation.play('drive');
				limo.antialiasing = true;

				fastCar = new FlxSprite(-300, 160).loadGraphic(Paths.image('limo/fastCarLol'));
			}
			case 'mall': {
                directory = "week5";

				setDefaultCameraZoom(0.80);

				var bg:FlxSprite = new FlxSprite(-1000, -500).loadGraphic(Paths.image('christmas/bgWalls'));
				bg.antialiasing = true;
				bg.scrollFactor.set(0.2, 0.2);
				bg.active = false;
				bg.setGraphicSize(Std.int(bg.width * 0.8));
				bg.updateHitbox();
				addToStage(bg);

				upperBoppers = new FlxSprite(-240, -90);
				upperBoppers.frames = Paths.getSparrowAtlas('christmas/upperBop');
				upperBoppers.animation.addByPrefix('bop', "Upper Crowd Bob", 24, false);
				upperBoppers.antialiasing = true;
				upperBoppers.scrollFactor.set(0.33, 0.33);
				upperBoppers.setGraphicSize(Std.int(upperBoppers.width * 0.85));
				upperBoppers.updateHitbox();
				addToStage(upperBoppers);

				var bgEscalator:FlxSprite = new FlxSprite(-1100, -600).loadGraphic(Paths.image('christmas/bgEscalator'));
				bgEscalator.antialiasing = true;
				bgEscalator.scrollFactor.set(0.3, 0.3);
				bgEscalator.active = false;
				bgEscalator.setGraphicSize(Std.int(bgEscalator.width * 0.9));
				bgEscalator.updateHitbox();
				addToStage(bgEscalator);

				var tree:FlxSprite = new FlxSprite(370, -250).loadGraphic(Paths.image('christmas/christmasTree'));
				tree.antialiasing = true;
				tree.scrollFactor.set(0.40, 0.40);
				addToStage(tree);

				bottomBoppers = new FlxSprite(-300, 140);
				bottomBoppers.frames = Paths.getSparrowAtlas('christmas/bottomBop');
				bottomBoppers.animation.addByPrefix('bop', 'Bottom Level Boppers', 24, false);
				bottomBoppers.antialiasing = true;
					bottomBoppers.scrollFactor.set(0.9, 0.9);
					bottomBoppers.setGraphicSize(Std.int(bottomBoppers.width * 1));
				bottomBoppers.updateHitbox();
				addToStage(bottomBoppers);

				var fgSnow:FlxSprite = new FlxSprite(-600, 700).loadGraphic(Paths.image('christmas/fgSnow'));
				fgSnow.active = false;
				fgSnow.antialiasing = true;
				addToStage(fgSnow);

				santa = new FlxSprite(-840, 150);
				santa.frames = Paths.getSparrowAtlas('christmas/santa');
				santa.animation.addByPrefix('idle', 'santa idle in fear', 24, false);
				santa.antialiasing = true;
				addToStage(santa);
			}
			case 'mallEvil': {
                directory = "week5";

				var bg:FlxSprite = new FlxSprite(-400, -500).loadGraphic(Paths.image('christmas/evilBG'));
				bg.antialiasing = true;
				bg.scrollFactor.set(0.2, 0.2);
				bg.active = false;
				bg.setGraphicSize(Std.int(bg.width * 0.8));
				bg.updateHitbox();
				addToStage(bg);

				var evilTree:FlxSprite = new FlxSprite(300, -300).loadGraphic(Paths.image('christmas/evilTree'));
				evilTree.antialiasing = true;
				evilTree.scrollFactor.set(0.2, 0.2);
				addToStage(evilTree);

				var evilSnow:FlxSprite = new FlxSprite(-200, 700).loadGraphic(Paths.image("christmas/evilSnow"));
				evilSnow.antialiasing = true;
                addToStage(evilSnow);
			}
			case 'school': {
                directory = "week6";

				setPixel(true);

				var bgSky = new FlxSprite().loadGraphic(Paths.image('weeb/weebSky'));
				bgSky.scrollFactor.set(0.1, 0.1);
				addToStage(bgSky);

				var repositionShit = -200;

				var bgSchool:FlxSprite = new FlxSprite(repositionShit, 0).loadGraphic(Paths.image('weeb/weebSchool'));
				bgSchool.scrollFactor.set(0.6, 0.90);
				addToStage(bgSchool);

				var bgStreet:FlxSprite = new FlxSprite(repositionShit).loadGraphic(Paths.image('weeb/weebStreet'));
				bgStreet.scrollFactor.set(0.95, 0.95);
				addToStage(bgStreet);

				var fgTrees:FlxSprite = new FlxSprite(repositionShit + 170, 130).loadGraphic(Paths.image('weeb/weebTreesBack'));
				fgTrees.scrollFactor.set(0.9, 0.9);
				addToStage(fgTrees);

				var bgTrees:FlxSprite = new FlxSprite(repositionShit - 380, -800);
				var treetex = Paths.getPackerAtlas('weeb/weebTrees');
				bgTrees.frames = treetex;
				bgTrees.animation.add('treeLoop', [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18], 12);
				bgTrees.animation.play('treeLoop');
				bgTrees.scrollFactor.set(0.85, 0.85);
				addToStage(bgTrees);

				var treeLeaves:FlxSprite = new FlxSprite(repositionShit, -40);
				treeLeaves.frames = Paths.getSparrowAtlas('weeb/petals');
				treeLeaves.animation.addByPrefix('leaves', 'PETALS ALL', 24, true);
				treeLeaves.animation.play('leaves');
				treeLeaves.scrollFactor.set(0.85, 0.85);
				addToStage(treeLeaves);

				var widShit = Std.int(bgSky.width * 6);

				bgSky.setGraphicSize(widShit);
				bgSchool.setGraphicSize(widShit);
				bgStreet.setGraphicSize(widShit);
				bgTrees.setGraphicSize(Std.int(widShit * 1.4));
				fgTrees.setGraphicSize(Std.int(widShit * 0.8));
				treeLeaves.setGraphicSize(widShit);

				fgTrees.updateHitbox();
				bgSky.updateHitbox();
				bgSchool.updateHitbox();
				bgStreet.updateHitbox();
				bgTrees.updateHitbox();
				treeLeaves.updateHitbox();

				bgGirls = new BackgroundGirls(-100, 190);
				bgGirls.scrollFactor.set(0.9, 0.9);

				if (PlayState.SONG.song.toLowerCase() == 'roses') {
					bgGirls.getScared();
				}

				bgGirls.setGraphicSize(Std.int(bgGirls.width * 6));
				bgGirls.updateHitbox();
				addToStage(bgGirls);
			}
			case 'schoolEvil': {
                directory = "week6";

                setPixel(true);

                var waveEffectBG = new FlxWaveEffect(FlxWaveMode.ALL, 2, -1, 3, 2);
                var waveEffectFG = new FlxWaveEffect(FlxWaveMode.ALL, 2, -1, 5, 2);

                var posX = 400;
                var posY = 200;

                var bg:FlxSprite = new FlxSprite(posX, posY);
                bg.frames = Paths.getSparrowAtlas('weeb/animatedEvilSchool');
                bg.animation.addByPrefix('idle', 'background 2', 24);
                bg.animation.play('idle');
                bg.scrollFactor.set(0.8, 0.9);
                bg.scale.set(6, 6);
                addToStage(bg);
			}
			case 'stage': {
                directory = "week1";

                setDefaultCameraZoom(0.90);

                var bg:FlxSprite = new FlxSprite(-600, -200).loadGraphic(Paths.image('stageback'));
                bg.antialiasing = true;
                bg.scrollFactor.set(0.9, 0.9);
                bg.active = false;
                addToStage(bg);

                var stageFront:FlxSprite = new FlxSprite(-650, 600).loadGraphic(Paths.image('stagefront'));
                stageFront.setGraphicSize(Std.int(stageFront.width * 1.1));
                stageFront.updateHitbox();
                stageFront.antialiasing = true;
                stageFront.scrollFactor.set(0.9, 0.9);
                stageFront.active = false;
                addToStage(stageFront);

                var stageCurtains:FlxSprite = new FlxSprite(-500, -300).loadGraphic(Paths.image('stagecurtains'));
                stageCurtains.setGraphicSize(Std.int(stageCurtains.width * 0.9));
                stageCurtains.updateHitbox();
                stageCurtains.antialiasing = true;
                stageCurtains.scrollFactor.set(1.3, 1.3);
                stageCurtains.active = false;

                addToStage(stageCurtains);
			}
		}
    }

    override public function configStage():Void {
        super.configStage();

        switch (stage) {
			case 'limo':
				Register.getInGameCharacter(BOYFRIEND).y -= 220;
				Register.getInGameCharacter(BOYFRIEND).x += 260;

				resetFastCar();
				addToStage(fastCar);

			case 'mall':
				Register.getInGameCharacter(BOYFRIEND).x += 200;
			case 'mallEvil':
				Register.getInGameCharacter(BOYFRIEND).x += 320;
				Register.getInGameCharacter(OPPONENT).y -= 80;
			case 'school':
				Register.getInGameCharacter(BOYFRIEND).x += 200;
				Register.getInGameCharacter(BOYFRIEND).y += 220;
				Register.getInGameCharacter(GIRLFRIEND).x += 180;
				Register.getInGameCharacter(GIRLFRIEND).y += 300;
			case 'schoolEvil':
				var evilTrail = new FlxTrail(Register.getInGameCharacter(OPPONENT), null, 4, 24, 0.3, 0.069);
				addToStage(evilTrail);

				Register.getInGameCharacter(BOYFRIEND).x += 200;
				Register.getInGameCharacter(BOYFRIEND).y += 220;
				Register.getInGameCharacter(GIRLFRIEND).x += 180;
				Register.getInGameCharacter(GIRLFRIEND).y += 300;
		}
    }

    override public function whenCreatingScene():Void {
        super.whenCreatingScene();

        addToStage(limo);
    }

    function lightningStrikeShit():Void {
        var playstate:PlayState = cast(FlxG.state, PlayState);

        FlxG.sound.play(Paths.soundRandom('thunder_', 1, 2));
        halloweenBG.animation.play('lightning');

        @:privateAccess
        lightningStrikeBeat = playstate.curBeat;
		lightningOffset = FlxG.random.int(8, 24);

        Register.getInGameCharacter(BOYFRIEND).playAnim('scared', true);
        Register.getInGameCharacter(GIRLFRIEND).playAnim('scared', true);
    }

    function trainStart():Void {
        trainMoving = true;

        if (!trainSound.playing)
            trainSound.play(true);
    }

    function updateTrainPos():Void {
        if (trainSound.time >= 4700) {
            startedMoving = true;
            Register.getInGameCharacter(GIRLFRIEND).playAnim('hairBlow');
        }

        if (startedMoving) {
            phillyTrain.x -= 400;

            if (phillyTrain.x < -2000 && !trainFinishing) {
                phillyTrain.x = -1150;
                trainCars -= 1;

                if (trainCars <= 0)
                    trainFinishing = true;
            }

            if (phillyTrain.x < -4000 && trainFinishing)
                trainReset();
        }
    }

    function trainReset():Void {
        Register.getInGameCharacter(GIRLFRIEND).playAnim('hairFall');
        phillyTrain.x = FlxG.width + 200;
        trainMoving = false;
        trainCars = 8;
        trainFinishing = false;
        startedMoving = false;
    }

    function resetFastCar():Void {
        fastCar.x = -12600;
        fastCar.y = FlxG.random.int(140, 250);
        fastCar.velocity.x = 0;
        fastCarCanDrive = true;
    }

    function fastCarDrive() {
        FlxG.sound.play(Paths.soundRandom('carPass', 0, 1), 0.7);

        fastCar.velocity.x = (FlxG.random.int(170, 220) / FlxG.elapsed) * 3;
        fastCarCanDrive = false;
        new FlxTimer().start(2, function(tmr:FlxTimer)
        {
            resetFastCar();
        });
    }

    override function curBeat():Void {
        var playstate:PlayState = cast(FlxG.state, PlayState);

        switch (stage) {
			case 'school':
				bgGirls.dance();

			case 'mall':
				upperBoppers.animation.play('bop', true);
				bottomBoppers.animation.play('bop', true);
				santa.animation.play('idle', true);

			case 'limo':
				grpLimoDancers.forEach(function(dancer:BackgroundDancer) {
					dancer.dance();
				});

				if (FlxG.random.bool(10) && fastCarCanDrive)
					fastCarDrive();
			case "philly":
				if (!trainMoving)
					trainCooldown += 1;

                
				if (@:privateAccess playstate.curBeat % 4 == 0) {
					phillyCityLights.forEach(function(light:FlxSprite) {
						light.visible = false;
					});

					curLight = FlxG.random.int(0, phillyCityLights.length - 1);

					phillyCityLights.members[curLight].visible = true;
				}

				if (@:privateAccess playstate.curBeat % 8 == 4 && FlxG.random.bool(30) && !trainMoving && trainCooldown > 8) {
					trainCooldown = FlxG.random.int(-4, 0);
					trainStart();
				}
		}

        if (isHalloween && FlxG.random.bool(10) && @:privateAccess playstate.curBeat > lightningStrikeBeat + lightningOffset) {
            lightningStrikeShit();
        }

        super.curBeat();
    }

    override function update(elapsed:Float):Void {
        switch(stage) {
			case 'philly':
				if (trainMoving) {
					trainFrameTiming += elapsed;

					if (trainFrameTiming >= 1 / 24) {
						updateTrainPos();
						trainFrameTiming = 0;
					}
				}
		}

        super.update(elapsed);
    }

    override function destroy():Void {
        super.destroy();

        halloweenBG = FlxDestroyUtil.destroy(halloweenBG);
        phillyCityLights = FlxDestroyUtil.destroy(phillyCityLights);
        grpLimoDancers = FlxDestroyUtil.destroy(grpLimoDancers);
        phillyTrain = FlxDestroyUtil.destroy(phillyTrain);
        limo = FlxDestroyUtil.destroy(limo);
        upperBoppers = FlxDestroyUtil.destroy(upperBoppers);
        bottomBoppers = FlxDestroyUtil.destroy(bottomBoppers);
        fastCar = FlxDestroyUtil.destroy(fastCar);
        santa = FlxDestroyUtil.destroy(santa);
        bgGirls = FlxDestroyUtil.destroy(bgGirls);
    }

    /**
    * Not important, if you want to make your own stage builder.
    */
    static public function setMainGameStage(song:String):String {
        switch(song.toLowerCase()) {
            case 'spookeez' | 'monster' | 'south':
                return 'spooky';
            case 'pico' | 'blammed' | 'philly':
                return 'philly';
            case 'milf' | 'satin-panties' | 'high':
                return 'limo';
            case 'cocoa' | 'eggnog':
                return 'mall';
            case 'winter-horrorland':
                return 'mallEvil';
            case 'senpai' | 'roses':
                return 'school';
            case 'thorns':
                return 'schoolEvil';
            default:
                return 'stage';
        }
    }
}