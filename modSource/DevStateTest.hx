package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.graphics.frames.FlxFramesCollection;
import openfl.display.BitmapData;
import openfl.geom.Point;

class DevStateTest extends HelperStates {
    var animLength:Int = 0;
    var spr:EditorSprite;
    var index:Int = 0;

    public function new() {
        super();
    }

    override function create():Void {
        spr = new EditorSprite();
        spr.twoInOneFrames(Paths.getSparrowAtlas('NOTE_assets', null, true), Paths.getSparrowAtlas('notes/reverse/CONFIRM_assets', "shared"));
        add(spr);

        spr.animation.addByPrefix('confirm0', 'left confirm0', 24, false);
        spr.animation.addByPrefix('confirm1', 'down confirm0', 24, false);
        spr.animation.addByPrefix('confirm2', 'up confirm0', 24, false);
        spr.animation.addByPrefix('confirm3', 'right confirm0', 24, false);

        spr.animation.addByPrefix('confirm reverse0', 'left confirm reverse', 24, false);
        spr.animation.addByPrefix('confirm reverse1', 'down confirm reverse', 24, false);
        spr.animation.addByPrefix('confirm reverse2', 'up confirm reverse', 24, false);
        spr.animation.addByPrefix('confirm reverse3', 'right confirm reverse', 24, false);

        animLength = spr.animation.getNameList().length;
        spr.animation.play(spr.animation.getNameList()[index], true);

        super.create();
    }

    override function update(elapsed:Float):Void {
        if(controls.ACCEPT) {
            index = (index + 1) % animLength;
            spr.animation.play(spr.animation.getNameList()[index], true);
            trace(spr.animation.getNameList()[index]);
        }

        super.update(elapsed);
    }
}