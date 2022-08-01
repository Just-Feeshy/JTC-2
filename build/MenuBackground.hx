package;

import flixel.FlxSprite;
import flixel.FlxG;
import flixel.group.FlxSpriteGroup;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;

class MenuBackground extends FlxSpriteGroup {
    public var sway:Float = 0;

    var allTweens:Array<FlxTween>;
    var totalWeeks:Int = 0;

    public function new(x:Float, y:Float) {
        super(x, y);

        allTweens = [];

        for(k in Paths.modJSON.weeks.keys()) {
            totalWeeks++;
        }

        for(i in 0...totalWeeks) {
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

        if(change >= 1) {
            if(prevSelected > totalWeeks)
                prevSelected = 0;
            if(prevSelected < 0)
                prevSelected = totalWeeks;
        }else if(change <= -1) {
            if(prevSelected > totalWeeks - 1)
                prevSelected = 0;
            if(prevSelected < 0)
                prevSelected = totalWeeks - 1;
        }

        for(i in 0...totalWeeks) {
            if(change >= 1) {
                if(this.members[i].ID != prevSelected && this.members[i].ID != selected)
                    this.members[i].alpha = 0;
                
                if(this.members[i].ID == selected) {
                    cleanTween();
                    allTweens.push(FlxTween.tween(this.members[i], {alpha: 1}, 0.3, {ease: FlxEase.quadOut,
                        onComplete: function(twn:FlxTween) {
                            cleanTween();
                        }
                    }));
                }
            }else if(change <= -1) {
                if(this.members[i].ID != prevSelected && this.members[i].ID != selected)
                    this.members[i].alpha = 0;
                else if(this.members[i].ID == selected)
                    this.members[i].alpha = 1;

                if(this.members[i].ID == prevSelected) {
                    trace("no no");
                    
                    cleanTween();
                    allTweens.push(FlxTween.tween(this.members[i], {alpha: 0}, 0.3, {ease: FlxEase.quadOut,
                        onComplete: function(twn:FlxTween) {
                            cleanTween();
                        }
                    }));
                }
            }
        }
    }

    function cleanTween():Void {
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

    override function destroy():Void {
        super.destroy();
        cleanTween();
    }
}