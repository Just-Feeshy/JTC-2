package;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.group.FlxSpriteGroup;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;

class MenuBackground extends FlxSpriteGroup {
    public var sway:Float = 0;

    public function new(x:Float, y:Float) {
        super(x, y);

        for(i in 0...Lambda.count(Paths.modJSON.weeks)) {
            var bg:FlxSprite = new FlxSprite().loadGraphic(Paths.image(Paths.modJSON.weeks.get("week_" + i).week_background));
            bg.setGraphicSize(Std.int(FlxG.width * 1.02), Std.int(FlxG.height * 1.02));
		    bg.updateHitbox();

            if(i > 0)
                bg.alpha = 0;

            bg.ID = i;

            this.add(bg);
        }
    }

    public function changeBackground(selected:Int, change:Int) {
        var prevSelected:Int = selected - change;

        if(prevSelected > Lambda.count(Paths.modJSON.weeks))
            prevSelected = 0;
        if(prevSelected < 0)
            prevSelected = Lambda.count(Paths.modJSON.weeks);

        for(i in 0...Lambda.count(Paths.modJSON.weeks)) {
            if(change >= 1) {
                if(this.members[i].ID != prevSelected && this.members[i].ID != selected)
                    this.members[i].alpha = 0;
                if(this.members[i].ID == selected)
                    FlxTween.tween(this.members[i], {alpha: 1}, 0.3, {ease: FlxEase.quadOut});
            }else if(change <= -1) {
                if(this.members[i].ID != prevSelected && this.members[i].ID != selected)
                    this.members[i].alpha = 0;
                else if(this.members[i].ID == selected)
                    this.members[i].alpha = 1;

                if(this.members[i].ID == prevSelected)
                    FlxTween.tween(this.members[i], {alpha: 0}, 0.3, {ease: FlxEase.quadOut});
            }
        }
    }
}