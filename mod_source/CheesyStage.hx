package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxMath;
import flixel.math.FlxPoint;
import flixel.util.FlxDestroyUtil;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import feshixl.math.FeshMath;
import lime.utils.Assets;
import haxe.Json;

import Conductor.BPMChangeEvent;

using StringTools;

@:access(MusicBeatState)
class CheesyStage extends StorageStage {
	@:final var tripleIconColors:Array<Int> = [
		0xff31b0d1, //Boyfriend
		0xffa5004d, //Girlfriend
		0xffe9ff48 //Joul The Cool
	];

	@:final var spinSteps:Array<UInt> = [
		279,
		303,
		312,
		336,
		344,
		368,
		376,
		401,
		409,
		435,
		443,
		467,
		475,
		501,
		509,
		533,
		542,
		567,
		575,
		602
	];

	var spinIndex:UInt = 0;
	var tweenIndex:UInt = 0;

	var allTweens:Array<FlxTween>;

	var boyfriend:Character;
	var dad:Character;
	var secondPlayer:Character;

	var dadShouldDance:Bool = true;
	var phase2_switch:Bool = false;

	/*
	* Variables for lazy modcharts.
	*/
	var strumSpinning:Bool = false;

	var curStep:Float = 0;
	var curBeat:Float = 0;

	var healthBarArrayLength:UInt = 2;

    public function new(stage:String) {
        super(stage);

		var cacheList:Array<String> = [];
		allTweens = new Array<FlxTween>();

        switch(stage) {
            case "funkstreet":
                setDefaultCameraZoom(0.75);

				var bg:FlxSprite = new FlxSprite(-600, -200).loadGraphic(Paths.image('stage' + FlxG.random.int(1,3)));
				bg.antialiasing = true;
				bg.scrollFactor.set(0.95, 0.95);
				bg.active = false;
				add(bg);

				var stageCurtains:FlxSprite = new FlxSprite(-500, -300).loadGraphic(Paths.image('funklights'));
				stageCurtains.setGraphicSize(Std.int(stageCurtains.width * 0.9));
				stageCurtains.updateHitbox();
				stageCurtains.antialiasing = true;
				stageCurtains.scrollFactor.set(1.3, 1.3);
				stageCurtains.active = false;

				add(stageCurtains);
			case "funkroad":
				strumSpinning = true;

				setDefaultCameraZoom(0.50);

				var funkroadSky:FlxSprite = new FlxSprite(-900, -500).loadGraphic(Paths.image('funkroadSky'));
				funkroadSky.antialiasing = true;
				funkroadSky.scrollFactor.set(0.7, 0.7);
				funkroadSky.scale.set(1.2,1.2);
				funkroadSky.active = false;
				add(funkroadSky);

				var frostFrames = Paths.getSparrowAtlas('funkroad');

				var frostbiteBG:FlxSprite = new FlxSprite(-1300, -400);
				frostbiteBG.frames = frostFrames;
				frostbiteBG.animation.addByPrefix('move', "funkroad", 24, true);
				frostbiteBG.animation.play('move');
				frostbiteBG.antialiasing = true;
				frostbiteBG.scrollFactor.set(0.9, 0.9);
				frostbiteBG.scale.set(1.2,1.2);
				frostbiteBG.updateHitbox();
				add(frostbiteBG);

				secondPlayer = new Character(650, 100, "skater-boi-player", true, null, false);

				characterAnims = ["singRIGHT", "singUP", "singDOWN", "singLEFT"];
				characterStorage.add(secondPlayer);
        }
    }

	function tweenHealthBar(info:Array<Int>, direction:String, playstate:PlayState):Void { // I didn't expect this to be a recursive method.
		if(direction == "right" || direction == "player") {
			tweenIndex = (tweenIndex + 1) % healthBarArrayLength;
			var prevValue:Int = tweenIndex - 1;

			if(prevValue < 0) {
				prevValue = healthBarArrayLength - 1;
			}

			allTweens.push(FlxTween.color(playstate.healthBar.filledBar, Conductor.bpm/60, info[prevValue], info[tweenIndex], {ease: FlxEase.linear,
				onComplete: function(twn:FlxTween) {
					cleanTween();
					tweenHealthBar(info, direction, playstate);
				}
			}));
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

	function lazySpin(index:Int) {
		var playerStrum:Strum = PlayState.playerStrums.members[index];
		var opponentStrum:Strum = PlayState.opponentStrums.members[index];
	}

	function updateCurStep():Void {
		var lastChange:BPMChangeEvent = {
			stepTime: 0,
			songTime: 0,
			bpm: 0
		}

		for (i in 0...Conductor.bpmChangeMap.length) {
			if (playstate.songPos >= Conductor.bpmChangeMap[i].songTime)
				lastChange = Conductor.bpmChangeMap[i];
		}

		curStep = lastChange.stepTime + (playstate.songPos - lastChange.songTime) / Conductor.stepCrochet;

		/*
		* Hell yea, I can cheese my way to making my own methods! Pun intended hehe.
		*/
		playstate.setLua("curStepFloat", curStep);
	}

	function updateBeat():Void {
		curBeat = curStep * 0.25;
		playstate.setLua("curBeatFloat", curBeat);
	}

	function getLastStepIndex(index:UInt):Float {
		if(spinIndex - index >= 0) {
			return spinSteps[spinIndex - index];
		}

		return 0;
	}

	override function stepHit():Void {
		if(playstate.curStep == 631) {
			insert(FlxG.state.members.indexOf(boyfriend) + 1, characterStorage);
		}
	}

	override function configStage():Void {
		boyfriend = Register.getInGameCharacter(BOYFRIEND);
		dad = Register.getInGameCharacter(OPPONENT);

		if(PlayState.SONG.song.toLowerCase() == "frostbeat") {
			boyfriend.shouldPlayDance = false;
			dad.shouldPlayDance = false;
		}
	}

	override function whenCreatingScene():Void {
		if(playstate.iconP1.iconAnimInfo[0] == 31 && playstate.iconP1.iconAnimInfo[1] == 32) {
			playstate.healthBar.filledColor = tripleIconColors[0];
			tweenHealthBar(tripleIconColors, "player", playstate);
		}

		if(PlayState.SONG.song.toLowerCase() != "funk-off" && PlayState.SONG.song.toLowerCase() != "ping-pong") {
			playstate.iconP2.createAnim("joul", [24, 30, 24]);
		}
	}

	override function setCamPos(camPos:FlxPoint):FlxPoint {
		if(stage == "funkroad") {
			return FlxPoint.get(751.5, 458.5);
		}

		return null;
	}

	override function hasGirlfriend():Bool {
		if(stage == "funkroad") {
			return false;
		}

		return true;
	}

	override function onEvent(eventName:String, eventValue:String, eventValue2:String):Void {
		if(stage == "funkroad" && (curStep >= 630 && curStep < 632) && eventValue == "dad-car" && !phase2_switch) {
			phase2_switch = true;

			playstate.iconP1.createAnim("flying BF sings", [28, 29, 28], true);
			playstate.healthBar.emptyColor = 0xffaf66ce;
			healthBarArrayLength = 3;

			playstate.avoidHealthIssues = true;

			if(playstate.healthTween != null) {
				playstate.healthTween.cancel();
				playstate.healthTween.destroy();

				playstate.healthTween = null;
			}

			FlxTween.tween(playstate, {health: 1}, (Conductor.stepCrochet * 0.0055), {ease: FlxEase.cubeOut, 
				onComplete: function(twn:FlxTween) {
					playstate.prevHealth = playstate.health;
					playstate.avoidHealthIssues = false;
				}
			});

			boyfriend.x += 50;
		}
	}

	override function update(elapsed:Float):Void {
		updateCurStep();
		updateBeat();

		if(dad.exists) {
			if(dad.animation.curAnim != null) {
				if (!dad.animation.curAnim.name.startsWith("sing") && !dad.stunned && dadShouldDance) {
					dad.dance();
				}
			}
		}else {
			dad = Register.getInGameCharacter(OPPONENT);
			dad.scale.set(1.1, 1.1);
			dad.updateHitbox();
			dad.shouldPlayDance = false;

			boyfriend.x += 250;
		}

		if(boyfriend.animation.curAnim != null) {
			if(!boyfriend.animation.curAnim.name.startsWith("sing") && !boyfriend.stunned) {
				boyfriend.dance();
			}
		}

		if(strumSpinning) {
			for(strum in playstate.strumLineNotes) {
				strum.yAngle = FlxMath.lerp(0, strum.yAngle, 0.95);
			}
		}

		if(spinSteps[spinSteps.length - 1] < curStep && strumSpinning) {
			for(i in 0...playstate.strumLineNotes.length) {
				playstate.strumLineNotes.members[i].yAngle = 0;
			}

			strumSpinning = false;
		}

		if(strumSpinning) {
			if(getLastStepIndex(0) <= curStep) {
				spinIndex++;
			}

			for(i in 0...Std.int(playstate.strumLineNotes.length * 0.5)) {
				var playerStrum:Strum = PlayState.playerStrums.members[i];
				var opponentStrum:Strum = PlayState.opponentStrums.members[i];

				if(spinSteps[0] <= curStep) {
					var speed:Float = 1;

					if(getLastStepIndex(0) - getLastStepIndex(1) > 20) {
						speed = 1.8;
					}

					var time:Float = ((curStep - getLastStepIndex(1)) / (getLastStepIndex(0) - getLastStepIndex(1))) - (Conductor.stepCrochet * 0.0011 * (i / speed));

					playerStrum.yAngle = FlxMath.lerp(0, Math.PI * 2, FeshMath.clamp(FlxEase.quadOut(time) * speed, 0, 1));
					opponentStrum.yAngle = FlxMath.lerp(0, Math.PI * 2, FeshMath.clamp(FlxEase.quadOut(time) * speed, 0, 1));
				}
			}
		}

		super.update(elapsed);
	}

	override function destroy():Void {
		super.destroy();

		boyfriend = null;
		dad = null;

		cleanTween();
	}
}