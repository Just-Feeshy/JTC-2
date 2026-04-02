package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import flixel.math.FlxPoint;
import flixel.util.FlxDestroyUtil;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.math.FlxMath;
import lime.utils.Assets;
import haxe.Json;
import openfl.utils.Assets as OpenFlAssets;

using StringTools;

@:access(MusicBeatState)
class CheesyStage extends StorageStage {
	private static final DEFAULT_STAGE_CAMERA_FOCUS:Array<Float> = [785, 458.5];
	private static final DEFAULT_STAGE_CAMERA_FOCUS_LERP:Float = 0.09;

	final tripleIconColors:Array<Int> = [
		0xff31b0d1, //Boyfriend
		0xffa5004d, //Girlfriend
		0xffe9ff48 //Joul The Cool
	];

	final flyingOffset:Map<String, Array<Float>> = [
		"idle" => [0, 0],
		"singDOWN" => [21, -11],
		"singUP" => [-4, 5],
		"singLEFT" => [10, 53],
		"singRIGHT" => [-21, 14],

		"singDOWNmiss" => [-6, -18],
		"singUPmiss" => [-10, -27],
		"singRIGHTmiss" => [11, -23],
		"singLEFTmiss" => [-27, -15]
	];

	final funkroadDadPhaseOneOffset:Array<Float> = [-120, 30];
	final funkroadDadPhaseTwoOffset:Array<Float> = [-480, 40];
	final funkroadBoyfriendPhaseOneOffset:Array<Float> = [120, 60];
	final funkroadBoyfriendPhaseTwoOffset:Array<Float> = [360, 70];

	var tweenIndex:UInt = 0;

	var allTweens:Array<FlxTween>;

	var boyfriend:Character;
	var dad:Character;

	var dadShouldDance:Bool = true;
	var phase2_switch:Bool = false;
	var funkroadBaseBoyfriendPos:BasicPoint;
	var funkroadBaseDadPos:BasicPoint;

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

	function addAnimation(anim:String, prefix:String):Void {
		boyfriend.animations.push(anim);
		boyfriend.animation.addByPrefix(anim, prefix, 24, false);
	}

	function cacheFunkroadBasePositions():Void {
		if(stage != "funkroad" || dad == null || boyfriend == null) {
			return;
		}

		if(funkroadBaseDadPos == null) {
			funkroadBaseDadPos = {x: dad.x, y: dad.y};
		}

		if(funkroadBaseBoyfriendPos == null) {
			funkroadBaseBoyfriendPos = {x: boyfriend.x, y: boyfriend.y};
		}
	}

	function applyFunkroadLayout(phaseTwo:Bool = false):Void {
		if(stage != "funkroad") {
			return;
		}

		cacheFunkroadBasePositions();

		if(dad != null && funkroadBaseDadPos != null) {
			var dadOffset = phaseTwo ? funkroadDadPhaseTwoOffset : funkroadDadPhaseOneOffset;
			dad.setPosition(funkroadBaseDadPos.x + dadOffset[0], 130);
		}

		if(boyfriend != null && funkroadBaseBoyfriendPos != null) {
			var boyfriendOffset = phaseTwo ? funkroadBoyfriendPhaseTwoOffset : funkroadBoyfriendPhaseOneOffset;
			boyfriend.setPosition(funkroadBaseBoyfriendPos.x + boyfriendOffset[0], funkroadBaseBoyfriendPos.y + boyfriendOffset[1]);
		}
	}

	override function configStage():Void {
		boyfriend = Register.getInGameCharacter(BOYFRIEND);
		dad = Register.getInGameCharacter(OPPONENT);

		if(PlayState.SONG.song.toLowerCase() == "frostbeat") {
			var oldGraphic:FlxGraphic = boyfriend.graphic;
		    boyfriend.frames = FlxAnimationUtil.combineAtlas([
				Paths.getSparrowAtlas("flying notes BF SINGS"),
				Paths.getSparrowAtlas("flying notes GF SINGS")
			]);
			boyfriend.animation.destroyAnimations();
			boyfriend.animations = [];
			boyfriend.animOffsets = new Map<String, Array<Float>>();
			if(oldGraphic != null && oldGraphic != boyfriend.graphic) {
				oldGraphic.persist = false;
				oldGraphic.destroyOnNoUse = true;
				if(oldGraphic.assetsKey != null) {
					OpenFlAssets.cache.removeBitmapData(oldGraphic.assetsKey);
				} else if(oldGraphic.key != null) {
					OpenFlAssets.cache.removeBitmapData(oldGraphic.key);
				}
			}
			boyfriend.animOffsets = flyingOffset;

			addAnimation("idle", "flying dance IDLE0");
			addAnimation("singDOWN", "flying dance DOWN0");
			addAnimation("singUP", "flying dance UP0");
			addAnimation("singLEFT", "flying dance LEFT0");
			addAnimation("singRIGHT", "flying dance RIGHT0");
			addAnimation("singDOWNmiss", "flying miss DOWN0");
			addAnimation("singUPmiss", "flying miss UP0");
			addAnimation("singRIGHTmiss", "flying miss RIGHT0");
			addAnimation("singLEFTmiss", "flying miss LEFT0");

			boyfriend.shouldPlayDance = false;
			dad.shouldPlayDance = false;
			boyfriend.playAnim("idle", true);
		}
	}

	override function configIcons(iconP1:HealthIcon, iconP2:HealthIcon):Void {
		if(stage == "funkroad") {
			iconP1.createAnim("flying BF sings", [31, 32, 31], true);
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

		applyFunkroadLayout(false);
	}

	override function setCamPos(camPos:FlxPoint):FlxPoint {
		if(stage == "funkroad") {
			return FlxPoint.get(
				FlxMath.lerp(DEFAULT_STAGE_CAMERA_FOCUS[0], camPos.x, DEFAULT_STAGE_CAMERA_FOCUS_LERP),
				FlxMath.lerp(DEFAULT_STAGE_CAMERA_FOCUS[1], camPos.y, DEFAULT_STAGE_CAMERA_FOCUS_LERP)
			);
		}

		return null;
	}

	override function hasGirlfriend():Bool {
		if(stage == "funkroad" || stage == "school_house") {
			return false;
		}

		return true;
	}

	override function onEvent(eventName:String, eventValue:String, eventValue2:String):Void {
		if(stage == "funkroad" && eventValue == "dad-car") {
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

			FlxTween.tween(playstate, {health: 1}, (Conductor.instance.stepLengthMs * 0.0055), {ease: FlxEase.cubeOut,
				onComplete: function(twn:FlxTween) {
					playstate.prevHealth = playstate.health;
					playstate.avoidHealthIssues = false;
				}
			});

			applyFunkroadLayout(true);
		}
	}

	override function resetStage():Void {
		applyFunkroadLayout(false);
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
			applyFunkroadLayout(phase2_switch);
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

private typedef BasicPoint = { x:Float, y:Float };
