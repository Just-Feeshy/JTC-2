package;

import template.StageBuilder;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxPoint;

class CheesyStage extends StageBuilder {
    public function new(stage:String) {
        super(stage);

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

	override public function whenCreatingScene():Void {
		if(stage == "funkroad") {
			removeFromStage(Register.getInGameCharacter(GIRLFRIEND));
		}
	}

	override function setCamPos(camPos:FlxPoint):FlxPoint {
		if(stage == "funkroad") {
			return FlxPoint.get(Register.getInGameCharacter(GIRLFRIEND).getMidpoint().x, Register.getInGameCharacter(GIRLFRIEND).getMidpoint().y);
		}

		return null;
	}
}