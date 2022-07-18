package;

import template.StageBuilder;

import flixel.FlxG;
import flixel.FlxSprite;

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


        }
    }

	override function setCamPos(camPos:FlxPoint):FlxPoint {
		if(stage == "funkroad") {
			return FlxPoint.get(Register.getInGameCharacter(GIRLFRIEND).x, Register.getInGameCharacter(GIRLFRIEND).y);
		}

		return null;
	}
}