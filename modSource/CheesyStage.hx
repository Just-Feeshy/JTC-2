package;

import template.StageBuilder;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxPoint;
import flixel.util.FlxDestroyUtil;
import lime.utils.Assets;
import haxe.Json;

class CheesyStage extends StageBuilder {
    public function new(stage:String) {
        super(stage);

		var cacheList:Array<String> = [];

		if(Assets.exists(Paths.getPath('data/frostbeat/cache.json', TEXT, ""))) {
            cacheList = cast Json.parse(Assets.getText(Paths.getPath('data/frostbeat/cache.json', TEXT, "")));

			for(i in 0...cacheList.length) {
				if(!Cache.permanentCache.contains(cacheList[i])) {
					Cache.permanentCache.push(cacheList[i]);
				}
			}
		}

        switch(stage) {
            case "funkstreet":
                setDefaultCameraZoom(0.75);

				var bg:FlxSprite = new FlxSprite(-600, -200).loadGraphic(Paths.image('stage' + FlxG.random.int(1,3)));
				bg.antialiasing = true;
				bg.scrollFactor.set(0.95, 0.95);
				bg.active = false;
				addToStage(bg);

				var stageCurtains:FlxSprite = new FlxSprite(-500, -300).loadGraphic(Paths.image('funklights'));
				stageCurtains.setGraphicSize(Std.int(stageCurtains.width * 0.9));
				stageCurtains.updateHitbox();
				stageCurtains.antialiasing = true;
				stageCurtains.scrollFactor.set(1.3, 1.3);
				stageCurtains.active = false;

				addToStage(stageCurtains);
			case "funkroad":
				setDefaultCameraZoom(0.50);

				var funkroadSky:FlxSprite = new FlxSprite(-900, -500).loadGraphic(Paths.image('funkroadSky'));
				funkroadSky.antialiasing = true;
				funkroadSky.scrollFactor.set(0.7, 0.7);
				funkroadSky.scale.set(1.2,1.2);
				funkroadSky.active = false;
				addToStage(funkroadSky);

				var frostFrames = Paths.getSparrowAtlas('funkroad');

				var frostbiteBG:FlxSprite = new FlxSprite(-1300, -400);
				frostbiteBG.frames = frostFrames;
				frostbiteBG.animation.addByPrefix('move', "funkroad", 24, true);
				frostbiteBG.animation.play('move');
				frostbiteBG.antialiasing = true;
				frostbiteBG.scrollFactor.set(0.9, 0.9);
				frostbiteBG.scale.set(1.2,1.2);
				frostbiteBG.updateHitbox();
				addToStage(frostbiteBG);

				var frostCarFrames = Paths.getSparrowAtlas('daddycar');

				var frostbiteCAR:FlxSprite = new FlxSprite(50, 100);
				frostbiteCAR.frames = frostCarFrames;
				frostbiteCAR.animation.addByPrefix('drive', "daddycar", 24, true);
				frostbiteCAR.animation.play('drive');
				frostbiteCAR.antialiasing = true;
				frostbiteCAR.scrollFactor.set(1.0, 0.9);
				frostbiteCAR.scale.set(0.7,0.7);
				frostbiteCAR.updateHitbox();
				addToStage(frostbiteCAR);
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
}