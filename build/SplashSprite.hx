package;

import flixel.FlxSprite;
import flixel.animation.FlxAnimationController;

class SplashSprite extends FlxSprite {
    public var texture(default, set):String = "";

    public var buildAnim:Void->Void;

    private var prevTexture:String = "";

    public function new() {
        super(0, 0);
    }

    public function loadAnims(txtr:String):Void {
        animation.destroyAnimations();
        frames = Paths.getNoteAtlas(txtr);

        setGraphicSize(Std.int(Note.swagWidth*4));
		updateHitbox();

        if(txtr == "regular/splash")
            defaultStrumAnim();
    }

    function defaultStrumAnim():Void {
        if(PlayState.SONG.fifthKey) {
            animation.addByPrefix('sploosh0', 'left splash', 24, false);
            animation.addByPrefix('sploosh1', 'down splash', 24, false);
            animation.addByPrefix('sploosh2', 'reverse splash', 24, false);
            animation.addByPrefix('sploosh3', 'up splash', 24, false);
            animation.addByPrefix('sploosh4', 'right splash', 24, false);
        }else {
            animation.addByPrefix('sploosh0', 'left splash', 24, false);
            animation.addByPrefix('sploosh1', 'down splash', 24, false);
            animation.addByPrefix('sploosh2', 'up splash', 24, false);
            animation.addByPrefix('sploosh3', 'right splash', 24, false);
        }
    }

    function set_texture(value:String):String {
        if(value != prevTexture) {
            prevTexture = value;
            loadAnims(value);
        }

        texture = value;
        return value;
    }
}