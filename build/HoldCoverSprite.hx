package;

import flixel.FlxG;
import flixel.FlxSprite;

class HoldCoverSprite extends FlxSprite {
	public var direction(default, null):String;
	public var activeHold(default, null):Bool = false;
	public var ending(default, null):Bool = false;
	public var available(default, null):Bool = false;

	var colorName:Null<String>;

	public function new(direction:String) {
		super();

		this.direction = direction;
		antialiasing = FlxG.save.data.showAntialiasing;
		scrollFactor.set();

		setupAnimations();

		visible = false;
		active = false;
		alpha = 1;
	}

	function setupAnimations():Void {
		colorName = switch(direction) {
			case "left": "Purple";
			case "down": "Blue";
			case "up": "Green";
			case "right": "Red";
			default: null;
		}

		if(colorName == null) {
			return;
		}

		frames = Paths.getSparrowAtlas('holdCover' + colorName, null, true);

		if(frames == null) {
			return;
		}

		animation.addByPrefix('start', 'holdCoverStart' + colorName, 24, false);
		animation.addByPrefix('hold', 'holdCover' + colorName, 24, true);
		animation.addByPrefix('end', 'holdCoverEnd' + colorName, 24, false);
		animation.finishCallback = onAnimationFinished;

		available = animation.getByName('start') != null
			&& animation.getByName('hold') != null
			&& animation.getByName('end') != null;

		updateHitbox();
	}

	function playCoverAnim(name:String, force:Bool = false):Void {
		if(!available) {
			return;
		}

		animation.play(name, force);
		centerOffsets();
		centerOrigin();
	}

	function onAnimationFinished(name:String):Void {
		switch(name) {
			case 'start':
				if(activeHold) {
					playCoverAnim('hold', true);
				}else {
					ending = true;
					visible = true;
					active = true;
					playCoverAnim('end', true);
				}
			case 'end':
				activeHold = false;
				ending = false;
				visible = false;
				active = false;
		}
	}

	public function beginHold():Void {
		if(!available) {
			return;
		}

		activeHold = true;
		ending = false;
		visible = true;
		active = true;
		alpha = 1;

		if(animation.curAnim == null || animation.curAnim.name == 'end' || ending) {
			playCoverAnim('start', true);
		}
	}

	public function refreshHold():Void {
		if(!available) {
			return;
		}

		if(!activeHold || ending || animation.curAnim == null || animation.curAnim.name == 'end') {
			beginHold();
			return;
		}

		visible = true;
		active = true;
	}

	public function endHold():Void {
		if(!available || (!activeHold && !ending)) {
			return;
		}

		activeHold = false;

		if(animation.curAnim != null && animation.curAnim.name == 'start') {
			ending = true;
			return;
		}

		if(!ending) {
			ending = true;
			visible = true;
			active = true;
			playCoverAnim('end', true);
		}
	}

	public function hideInstant():Void {
		activeHold = false;
		ending = false;
		visible = false;
		active = false;
	}
}
