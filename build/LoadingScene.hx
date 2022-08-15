package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.group.FlxSpriteGroup;
import flixel.ui.FlxBar;

class LoadingScene extends FlxSpriteGroup {
    var menuBG:FlxSprite;
    var loadingBar:FlxBar;
    var cacheTween:FlxTween;
    var loading:Alphabet;

    var cacheValue:Float = 0;
    var prevCacheValue:Float = 0;
    var colorSway:Float = 0;

    public function new() {
        super();

        menuBG = new FlxSprite();
		menuBG.loadGraphic(Paths.image(Paths.modJSON.background_images[FlxG.random.int(0, Paths.modJSON.background_images.length - 1)]));
        menuBG.scrollFactor.set();
        menuBG.screenCenter();
		add(menuBG);

        if(Paths.modJSON.loading_display.show_loading_bar) {
            loadingBar = new FlxBar(0, 0, FlxBarFillDirection.LEFT_TO_RIGHT, FlxG.width, 15, this,
                "cacheValue", 0, 1);
            loadingBar.y = FlxG.height - loadingBar.height;
            loadingBar.createFilledBar(
                Std.parseInt(Paths.modJSON.loading_display.loading_bar_colors[0]),
                Std.parseInt(Paths.modJSON.loading_display.loading_bar_colors[1])
            );

            loadingBar.alpha = Paths.modJSON.loading_display.loading_bar_alpha;
            add(loadingBar);
        }

        loading = new Alphabet(0, 0, "Loading", true, false, 30);
        loading.y = (FlxG.height - loading.height) - 30;
        add(loading);
    }

    public function setCacheValue(cv:Float, shouldTween:Bool = true) {
		if(cacheTween != null) {
			cacheTween.cancel();
			cacheTween.destroy();

			cacheValue = prevCacheValue;
		}

		final tempCacheValue:Float = cacheValue;
		prevCacheValue = cv;

		if(Math.abs(cv - tempCacheValue) > 0.02) {
			cacheTween = FlxTween.tween(this, {cacheValue: cv}, Math.abs(cv - tempCacheValue) * 5, {ease: FlxEase.quadOut});
		}else {
			cacheValue = cv;
		}
	}

    override function update(elapsed:Float) {
        if(loading != null) {
            loading.forEach(function(spr:FlxSprite) {
                spr.color = FlxColor.fromRGBFloat(0.6 + Math.sin(colorSway * Math.PI) * 0.4,
                0.6 + Math.sin(colorSway * Math.PI) * 0.4, 0.6 + Math.sin(colorSway * Math.PI) * 0.4);
            });

            colorSway += elapsed;
        }

        super.update(elapsed);
    }
}