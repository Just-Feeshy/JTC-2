package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxMath;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.FlxCamera;

import SaveData.SaveType;

class Options extends Alphabet {
    public var optionIcon:FlxSprite;
    public var inputDetector:Bool = false;
    public var optionTitle(default, set):Bool = false;
    public var optionSubState:OptionsSubState;
    public var saveType(default, null):SaveType;
    public var callback:Options->Bool->Void;
    public var description:String;

    public function new(x:Float, y:Float, text:String = "", saveType:SaveType, ?Callback:Options->Bool->Void) {
        super(0, y, text, true, false, x + 40);

        this.saveType = saveType;
        this.yMultiplier = 90;
        
        callback = Callback;

        optionIcon = new FlxSprite(x - 120, y);
        optionIcon.frames = Paths.getSparrowAtlas("circle_assets");

        optionIcon.animation.addByPrefix('off', "arrowRIGHT0");
        optionIcon.animation.addByPrefix('on', "red0");
        optionIcon.animation.addByPrefix('other', "blue0");
        optionIcon.animation.addByPrefix('section', "green0");
        optionIcon.animation.addByPrefix('modifier', "purple0");

        if(SaveData.getData(saveType))
            optionIcon.animation.play('on');   
        else
            optionIcon.animation.play('off');

        optionIcon.setGraphicSize(Std.int(optionIcon.width * 0.8));
        optionIcon.updateHitbox();

        if(SaveData.getData(SaveType.GRAPHICS))
            optionIcon.antialiasing = true;

        add(optionIcon);

        callback(this, false);

        forEach(function(letters:FlxSprite) {
            if(letters != optionIcon)
                letters.y = optionIcon.y + (optionIcon.height / 2) - (letters.height / 2);
        });
    }

    function set_optionTitle(value:Bool):Bool {
        if(value)screenCenter(X);
        optionTitle = true;
        return value;
    }

    override public function update(elapsed:Float) {
        var scaledY = FlxMath.remapToRange(targetY, 0, 1, 0, 1.3);
        y = FlxMath.lerp(y, (scaledY * yMultiplier) + (FlxG.height * 0.48) - 130, 0.16);

        if(!optionTitle) {
            if(targetY == 0)
                x = FlxMath.lerp(x, (targetY) + 140, 0.16);
            else
                x = FlxMath.lerp(x, (targetY) + 90, 0.16);
        }

        super.update(elapsed);
    }

    override public function destroy():Void {
        super.destroy();

        optionIcon = FlxDestroyUtil.destroy(optionIcon);
        optionSubState = FlxDestroyUtil.destroy(optionSubState);

        callback = null;
        saveType = null;
    }
}