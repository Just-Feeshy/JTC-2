package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxDestroyUtil;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import lime.utils.Assets;
import haxe.Json;

using StringTools;

@:access(MusicBeatState)
class CheesyStage extends StorageStage {
	final tripleIconColors:Array<Int> = [
		0xff31b0d1, //Boyfriend
		0xffa5004d, //Girlfriend
		0xffe9ff48 //Joul The Cool
	];

	var tweenIndex:UInt = 0;

	var allTweens:Array<FlxTween>;

	var boyfriend:Character;
	var dad:Character;

	var dadShouldDance:Bool = true;
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
        }
    }

	function tweenHealthBar(info:Array<Int>, direction:String, playstate:PlayState):Void { // I didn't expect this to be a recursive method.
		if(direction == "right" || direction == "player") {
			tweenIndex = (tweenIndex + 1) % healthBarArrayLength;
			var prevValue:Int = tweenIndex - 1;

			if(prevValue < 0) {
				prevValue = healthBarArrayLength - 1;
			}

			allTweens.push(FlxTween.color(playstate.healthBar.filledBar, Conductor.instance.activeBpm / 60, info[prevValue], info[tweenIndex], {ease: FlxEase.linear,
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

	function updateCurStep():Void {
		curStep = Conductor.instance.getTimeInSteps(playstate.songPos);

		/*
		* Hell yea, I can cheese my way to making my own methods! Pun intended hehe.
		*/
		playstate.setLua("curStepFloat", curStep);
	}

	function updateBeat():Void {
		curBeat = curStep * 0.25;
		playstate.setLua("curBeatFloat", curBeat);
	}

	override function configStage():Void {
		boyfriend = Register.getInGameCharacter(BOYFRIEND);
		dad = Register.getInGameCharacter(OPPONENT);

		if(stage == "funkroad" && PlayState.SONG.song.toLowerCase() == "frostbeat") {
			boyfriend.shouldPlayDance = false;
			dad.shouldPlayDance = false;
			boyfriend.playAnim("idle", true);
		}
	}

	override function whenCreatingScene():Void {
		if(stage == "funkroad" && PlayState.SONG.song.toLowerCase() == "frostbeat") {
			playstate.healthBar.filledColor = tripleIconColors[0];
			tweenHealthBar(tripleIconColors, "player", playstate);
		}

	}

	override function hasGirlfriend():Bool {
		if(stage == "funkroad" || stage == "school_house") {
			return false;
		}

		return true;
	}

	override function onEvent(eventName:String, eventValue:String, eventValue2:String):Void {
		if(eventName == "character change") {
			switch(eventValue2.toLowerCase()) {
				case "bf" | "boyfriend" | "player":
					boyfriend = Register.getInGameCharacter(BOYFRIEND);
				case "dad" | "opponent":
					dad = Register.getInGameCharacter(OPPONENT);
			}
		}

		if(stage == "funkroad" && eventValue == "dad-car") {
			playstate.healthBar.emptyColor = 0xffaf66ce;
			healthBarArrayLength = 3;

			playstate.avoidHealthIssues = true;

			if(playstate.healthTween != null) {
				playstate.healthTween.cancel();
				playstate.healthTween.destroy();

				playstate.healthTween = null;
			}

			FlxTween.tween(playstate, {health: 1}, (Conductor.instance.stepLengthMs * 0.0055), {ease: FlxEase.cubeOut,
				onComplete: function(twn:FlxTween) {
					playstate.prevHealth = playstate.health;
					playstate.avoidHealthIssues = false;
				}
			});

			// Update dad reference since character changed; Frostbeat phase-two positioning is handled in Lua.
			dad = Register.getInGameCharacter(OPPONENT);
		}
	}

	override function resetStage():Void {
		// Update character references in case they changed
		boyfriend = Register.getInGameCharacter(BOYFRIEND);
		dad = Register.getInGameCharacter(OPPONENT);

		// Reset characters to their base positions.
		if(stage == "funkroad") {
			if(boyfriend != null) {
				boyfriend.refresh(boyfriend.curCharacter, playstate.camPos);
				boyfriend.playAnim("idle", true);
			}

			if(dad != null) {
				dad.refresh(dad.curCharacter, playstate.camPos);
			}

			// Reset health bar settings to phase 1
			healthBarArrayLength = 2;
			playstate.healthBar.filledColor = tripleIconColors[0];

			// Cancel existing health bar color tween
			cleanTween();

			// Restart the health bar tween with original colors
			tweenHealthBar(tripleIconColors, "player", playstate);
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
		}

		if(boyfriend.animation.curAnim != null) {
			if(!boyfriend.animation.curAnim.name.startsWith("sing") && !boyfriend.stunned) {
				boyfriend.dance();
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
