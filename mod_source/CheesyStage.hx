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

	// Typed as the atlas-safe interface: these may be Sparrow `Character`/`Boyfriend` or
	// Adobe Animate `AtlasCharacter` instances depending on the character's `useAtlas` flag.
	var boyfriend:ICharacter;
	var dad:ICharacter;

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
				// Scenery (funkroadSky + animated frostbiteBG) moved to
				// scripts/stage/frostbeat/frostbeat_stage.lua so the stage editor can see it.
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
			// Let bf/dad bop on the beat (beatHit). They were left with shouldPlayDance = false
			// for the whole song, which froze them on idle.
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
		// Declarative: a stage's lua can disable the standalone girlfriend via its stageCharacters
		// table (girlfriend = { ..., enabled = false }). This replaces the old hardcoded stage check.
		var luaPref = stageGirlfriendEnabled();
		if(luaPref != null) {
			return luaPref;
		}

		// Fallback for stages without a lua girlfriend flag.
		if(stage == "school_house") {
			return false;
		}

		return true;
	}

	/**
	 * Reads the current song's stage lua (mod_assets/scripts/stage/<song>/<song>_stage.lua) and
	 * returns its declared girlfriend `enabled` flag, or null if the file/flag is absent.
	 */
	function stageGirlfriendEnabled():Null<Bool> {
		var song:String = (PlayState.SONG != null && PlayState.SONG.song != null) ? PlayState.SONG.song.toLowerCase() : null;
		if(song == null || song == "") {
			return null;
		}

		var src:String = null;
		var path:String = 'mod_assets/scripts/stage/$song/${song}_stage.lua';
		#if sys
		if(sys.FileSystem.exists(path)) {
			src = try sys.io.File.getContent(path) catch(e:Dynamic) null;
		}
		#end
		if(src == null) {
			var assetPath:String = 'assets/scripts/stage/$song/${song}_stage.lua';
			if(Assets.exists(assetPath)) {
				src = try Assets.getText(assetPath) catch(e:Dynamic) null;
			}
		}
		if(src == null) {
			return null;
		}

		var r = new EReg('girlfriend\\s*=\\s*\\{[^}]*enabled\\s*=\\s*(true|false)', "");
		if(r.match(src)) {
			return r.matched(1) == "true";
		}
		return null;
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

		// Atlas-safe: `getCurrentAnimation()`/`isSinging()` work for both Sparrow and Animate
		// characters, unlike `animation.curAnim` which is never populated for atlas chars.
		if(dad.exists) {
			if(dad.getCurrentAnimation() != "") {
				if (!dad.isSinging() && !dad.stunned && dadShouldDance) {
					dad.dance();
				}
			}
		}else {
			dad = Register.getInGameCharacter(OPPONENT);
			dad.scale.set(1.1, 1.1);
			dad.updateHitbox();
		}

		if(boyfriend.getCurrentAnimation() != "") {
			if(!boyfriend.isSinging() && !boyfriend.stunned) {
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
