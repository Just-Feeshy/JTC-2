package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.utils.AssetType;

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

		var atlasKey = 'holdCover' + colorName;
		var localDescriptionPath = Paths.file('images/' + atlasKey + '.xml', TEXT, "shared");

		if(Paths.assetExists(localDescriptionPath, AssetType.TEXT)) {
			setupLoadedAnimations(Paths.getSparrowAtlas(atlasKey, "shared"));
		}else {
			Paths.loadRemoteSharedSparrowAtlas(atlasKey, setupLoadedAnimations);
		}
	}

	function setupLoadedAnimations(loadedFrames:FlxAtlasFrames):Void {
		if(loadedFrames == null || colorName == null) {
			return;
		}

		frames = loadedFrames;
		animation.addByPrefix('start', 'holdCoverStart' + colorName, 24, false);
		animation.addByPrefix('hold', 'holdCover' + colorName, 24, true);
		animation.addByPrefix('end', 'holdCoverEnd' + colorName, 24, false);
		animation.finishCallback = onAnimationFinished;

		available = animation.getByName('start') != null
			&& animation.getByName('hold') != null
			&& animation.getByName('end') != null;

		updateHitbox();

		if(activeHold) {
			visible = true;
			active = true;
			playCoverAnim('start', true);
		}
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
		activeHold = true;
		ending = false;
		visible = available;
		active = available;
		alpha = 1;

		if(!available) {
			return;
		}

		if(animation.curAnim == null || animation.curAnim.name == 'end' || ending) {
			playCoverAnim('start', true);
		}
	}

	public function refreshHold():Void {
		activeHold = true;
		ending = false;

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
		if(!activeHold && !ending) {
			return;
		}

		if(!available) {
			activeHold = false;
			ending = false;
			visible = false;
			active = false;
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
