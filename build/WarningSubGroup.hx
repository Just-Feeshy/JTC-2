package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.group.FlxSpriteGroup;
import betterShit.BetterCams;

class WarningSubGroup extends FlxSpriteGroup {
    public var acceptedTermsOfService:Bool = false;

    private var sway:Float = -1;
    private var txtY:Float;
    private var pressedSwitch:Bool;

    private var warningTxt:FlxText;

    private var controls(get, never):Controls;

    inline function get_controls():Controls
		return PlayerSettings.player1.controls;

    public function new(warn:Array<String>) {
        super(0, 0);

        var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
		bg.scrollFactor.set();
		add(bg);

        warningTxt = new FlxText(0, 0, FlxG.width,
			"WARNING!\n\n"
			+ getWarning(warn),
		32);

        warningTxt.setFormat("VCR OSD Mono", 32, FlxColor.WHITE, CENTER);
        warningTxt.screenCenter();
		add(warningTxt);

        txtY = warningTxt.y;

        cameras = [PlayState.camHUD];
    }

    override function update(elapsed:Float) {
        if(controls.ACCEPT && !pressedSwitch) {
            pressedSwitch = true;

            FlxTween.tween(this, {alpha: 0}, 1, {ease: FlxEase.quadOut, onComplete: function(twn:FlxTween) {
                acceptedTermsOfService = true;
            }});
        }

        if(controls.BACK)
            FlxG.switchState(new MainMenuState(true));

        super.update(elapsed / 1.25);

        sway += 0.004;

        warningTxt.y = txtY + (Math.sin(sway * Math.PI) * 15);
    }

    private function getWarning(wrns:Array<String>):String {
        trace(wrns);

        for(v in wrns)
            if(v != null && v != "")
                return v;

        return "";
    }
}