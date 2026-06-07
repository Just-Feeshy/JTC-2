package;

import flixel.FlxG;

class EndState extends MusicBeatState {
	public function new() {
		super();
	}

	override function create() {
		persistentUpdate = persistentDraw = true;
		super.create();
	}

	override function update(elapsed:Float) {
		super.update(elapsed);

		if(controls.ACCEPT) {
			FlxG.switchState(new MainMenuState());
		}
	}
}
