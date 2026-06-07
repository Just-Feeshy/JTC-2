package;

import flixel.FlxG;
import flixel.input.keyboard.FlxKey;

class EndState extends MusicBeatState {
	private var ending:String = "";

	public function new(ending:String) {
		super();

		this.ending = ending;
	}

	override function create() {
		persistentUpdate = persistentDraw = true;
		super.create();
	}

	override public function onCreate():Dynamic {
        var keytoSkip:String;

        if(FlxG.gamepads.lastActive != null) {
            keytoSkip = "A";
        }else {
            keytoSkip = FlxKey.toStringMap.get(SaveData.getData(CUSTOM_UI_KEYBINDS)[4][0]).toUpperCase();
        }

		setLua("keyToSkip", keytoSkip);
		setLua("ending", ending);
		return super.onCreate();
	}

	override function update(elapsed:Float) {
		super.update(elapsed);

		if(controls.ACCEPT || controls.BACK) {
			FlxG.switchState(new MainMenuState());
		}
	}
}
