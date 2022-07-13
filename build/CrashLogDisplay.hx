package;

import openfl.Lib;
import openfl.Assets;
import openfl.display.Stage;
import openfl.display.Application;
import openfl.display.BitmapData;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.ui.Mouse;
import openfl.geom.Rectangle;
import openfl.geom.Point;
import lime.ui.WindowAttributes;
import lime.ui.Window;

import flixel.FlxG;
import flixel.util.FlxColor;
import flixel.text.FlxText;

import SaveData.SaveType;

using StringTools;

class CrashLogDisplay extends Sprite {
    var backgroundData:BitmapData;
    var _panel:Rectangle;
    
    public function new(prevWindow:Window) {
        super();

        @:privateAccess var attributes:WindowAttributes = Reflect.copy(prevWindow.__attributes);

        attributes.width = 480;
        attributes.height = 280;
        attributes.resizable = false;
        attributes.fullscreen = false;
        attributes.title = Paths.modJSON.mod.name + " - Crash Report!";

        Mouse.show();

        var window:Window = Lib.current.stage.application.createWindow(attributes);
        window.onClose.add(__closeApplication.bind(window));

        @:privateAccess {
            Lib.current.stage.application.__windows.shift();
            Lib.current.stage = window.stage;
        }

        window.stage.addChild(this);

        //Background Image
        final backgroundPath:String = Paths.getPreloadPath("images/" + Paths.modJSON.background_images[FlxG.random.int(0, Paths.modJSON.background_images.length - 1)] + ".png");

        backgroundData = Assets.getBitmapData(backgroundPath);

        /**
         * Lmao
         */
        var erect:Rectangle = createRectPanel(backgroundData);
        _panel = createPanel(backgroundData, erect, new Point(0, -5), 0);

        var _title:FlxText = createText("Game Crashed!", Paths.font("OpenSans-Bold.ttf"), 64);

        @:privateAccess {
            _title._matrix.translate((backgroundData.width - _title.width) / 2, 5);
            _title.drawTextFieldTo(backgroundData);
        }

        var _background:Bitmap = new Bitmap(backgroundData);
        _background.smoothing = SaveData.getData(SaveType.GRAPHICS);

        _background.scaleX = Lib.current.stage.stageWidth / _background.width;
        _background.scaleY = Lib.current.stage.stageHeight / _background.height;

        addChild(_background);
    }

    public function attachReport(info:Array<String>):Void {
        var _frontEndInfo:FlxText = createText(info[0].trim(), Paths.font("OpenSans-Regular.ttf"), 24);
        var _uncaughtInfo:FlxText = createText(info[1].trim(), Paths.font("OpenSans-Regular.ttf"), 24);

        @:privateAccess {
            _frontEndInfo._matrix.translate((backgroundData.width - _frontEndInfo.width) / 2, _panel.y + 5);
            _frontEndInfo.drawTextFieldTo(backgroundData);

            _uncaughtInfo._matrix.translate(5, backgroundData.height - _uncaughtInfo.height - 5);
            _uncaughtInfo.drawTextFieldTo(backgroundData);
        }
    }

    function createText(_text:String, font:String, size:Int):FlxText {
        var _backendText = new FlxText(100, 0, 0, _text, size);
        _backendText.setFormat(font, size, FlxColor.WHITE, CENTER, FlxTextBorderStyle.OUTLINE, 0);

        return _backendText;
    }

    function createRectPanel(bitmapData:BitmapData):Rectangle {
        final width:Int = Math.ceil(bitmapData.width / 1.25);
        final height:Int = Math.ceil(bitmapData.height / 1.5);

        var _sourceRect:Rectangle = new Rectangle(
            (bitmapData.width - width) / 2,
            (bitmapData.height - height) / 2,
            width,
            height + 5
        );

        return _sourceRect;
    }

    function createPanel(bitmapData:BitmapData, _rect:Rectangle, _offset:Point, _borderSize:Int):Rectangle {
        final xPos:Int = Math.ceil(_rect.x + _offset.x);
        final yPos:Int = Math.ceil(_rect.y + _offset.y);

        for(column in 0...Math.ceil(_rect.width)) {
            for(row in 0...Math.ceil(_rect.height)) {
                var colorOfPixel:Int = bitmapData.getPixel32(column + xPos, row + yPos);

                if(colorOfPixel != 0) {

                    /**
                     * Makes darker shade of original pixel color.
                     */
                    var newColor:FlxColor = FlxColor.fromInt(colorOfPixel);
                    newColor.redFloat /= 4;
                    newColor.blueFloat /= 4;
                    newColor.greenFloat /= 4;

                    /**
                     * I don't know if a border looks better or not, so I added this just in case.
                     */
                    if(_borderSize > 0) {
                        if((column >= 0 && column <= _borderSize) || (column >= _rect.width - _borderSize && column <= _rect.width)) {
                            newColor.redFloat = (newColor.redFloat + newColor.blueFloat + newColor.greenFloat) / 6;
                            newColor.blueFloat = (newColor.redFloat + newColor.blueFloat + newColor.greenFloat) / 6;
                            newColor.greenFloat = (newColor.redFloat + newColor.blueFloat + newColor.greenFloat) / 6;
                        }

                        if((row >= 0 && row <= _borderSize) || (row >= _rect.height - _borderSize && row <= _rect.height)) {
                            newColor.redFloat = (newColor.redFloat + newColor.blueFloat + newColor.greenFloat) / 6;
                            newColor.blueFloat = (newColor.redFloat + newColor.blueFloat + newColor.greenFloat) / 6;
                            newColor.greenFloat = (newColor.redFloat + newColor.blueFloat + newColor.greenFloat) / 6;
                        }
                    }

                    bitmapData.setPixel32(column + xPos, row + yPos, newColor);
                }
            }
        }

        return new Rectangle(xPos, yPos, _rect.width, _rect.height);
    }

    @:noCompletion
    function __closeApplication(window:Window):Void {
        Sys.exit(0);
    }
}