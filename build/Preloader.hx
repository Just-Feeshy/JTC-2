package;

import flixel.system.FlxBasePreloader;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.Lib;
import openfl.ui.Mouse;

@:bitmap("art/preloaderArt.png") class PreloaderLogoImage extends BitmapData {}

class Preloader extends FlxBasePreloader {
    public static var _initialState:Class<HelperStates> = TitleState;

    static inline var BAR_HEIGHT:Int = 15;
    static inline var BAR_BG_COLOR:Int = 0x5A5A5A;
    static inline var BAR_FILL_COLOR:Int = 0xB5B5B5;
    static inline var BAR_ALPHA:Float = 0.6;
    static inline var FADE_TIME:Float = 2.5;
    static inline var FADE_START_PERCENT:Float = 0.95;

    var logo:Sprite;
    var loadingBar:Sprite;
    var loadingBarFill:Shape;
    var completeTime:Float = -1;
    var actuallyLoaded:Bool = false;

    public function new(minDisplayTime:Float = 3, ?allowedURLs:Array<String>) {
        super(minDisplayTime, allowedURLs);
    }

    override function create():Void {

        this._width = Lib.current.stage.stageWidth;
        this._height = Lib.current.stage.stageHeight;

        var ratio:Float = this._width / 2560;

        logo = new Sprite();
        logo.addChild(new Bitmap(new PreloaderLogoImage(0, 0)));
        logo.scaleX = logo.scaleY = ratio;
        logo.x = (this._width / 2) - (logo.width / 2);
        logo.y = (this._height / 2) - (logo.height / 2);
        addChild(logo);

        loadingBar = new Sprite();
        loadingBar.alpha = BAR_ALPHA;

        var bg:Shape = new Shape();
        bg.graphics.beginFill(BAR_BG_COLOR);
        bg.graphics.drawRect(0, 0, this._width, BAR_HEIGHT);
        bg.graphics.endFill();
        loadingBar.addChild(bg);

        loadingBarFill = new Shape();
        loadingBarFill.graphics.beginFill(BAR_FILL_COLOR);
        loadingBarFill.graphics.drawRect(0, 0, this._width, BAR_HEIGHT);
        loadingBarFill.graphics.endFill();
        loadingBarFill.scaleX = 0;
        loadingBar.addChild(loadingBarFill);

        loadingBar.y = this._height - BAR_HEIGHT;
        addChild(loadingBar);

        super.create();
    }

    override function update(Percent:Float):Void {
        super.update(Percent);

        if (loadingBarFill != null) {
            loadingBarFill.scaleX = Percent;
        }

        if (Percent >= FADE_START_PERCENT && completeTime < 0) {
            completeTime = (#if hl Sys.time() * 1000.0 #else Date.now().getTime() #end - this._startTime) / 1000.0;
        }

        if (completeTime >= 0) {
            var elapsed:Float = (#if hl Sys.time() * 1000.0 #else Date.now().getTime() #end - this._startTime) / 1000.0;
            var elapsedFinished:Float = elapsed - completeTime;
            var alphaToFade:Float = 1.0 - easeInOutCirc(Math.min(elapsedFinished / FADE_TIME, 1.0));

            if (logo != null) logo.alpha = alphaToFade;
            if (loadingBar != null) loadingBar.alpha = alphaToFade * BAR_ALPHA;

            if (actuallyLoaded && elapsedFinished >= FADE_TIME) {
                _loaded = true;
            }
        }
    }

    override function onLoaded():Void {
        super.onLoaded();
        // Base class set _loaded = true, which would destroy the preloader on the next frame.
        // Hold it open so the fade-out can play; we'll re-set _loaded once the fade finishes.
        _loaded = false;
        actuallyLoaded = true;
    }

    static function easeInOutCirc(x:Float):Float {
        return x < 0.5
            ? (1 - Math.sqrt(1 - Math.pow(2 * x, 2))) / 2
            : (Math.sqrt(1 - Math.pow(-2 * x + 2, 2)) + 1) / 2;
    }
}
