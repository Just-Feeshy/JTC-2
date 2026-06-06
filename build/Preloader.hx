package;

import flixel.system.FlxBasePreloader;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.Lib;
import openfl.ui.Mouse;

@:bitmap("art/preloaderArt.png") class PreloaderLogoImage extends BitmapData {}

class Preloader extends FlxBasePreloader {
    public static var _initialState:Class<HelperStates> = TitleState;

    var logo:Sprite;

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

        super.create();
    }
}
