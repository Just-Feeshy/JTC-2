package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxMath;
import flixel.util.FlxSort;
import flixel.util.FlxTimer;
import ModInitialize.StickerTransitionConfig;
import openfl.media.Sound;
import template.TransitionBuilder;

class FunkinTransitionState extends TransitionBuilder {
	static var defaultClickIndices:Array<Int> = [1, 2, 3, 4, 5, 7, 8, 9];
	static var pendingStickers:Array<StickerTransitionSprite> = null;

	public var grpStickers:FlxTypedGroup<StickerTransitionSprite>;

	var stickerGraphics:Array<FlxGraphic> = [];
	var clickSounds:Array<Sound> = [];
	var switchingState:Bool = false;

	public function new(duration:Float, fade:TransitionFade) {
		super(duration, fade);

		loadStickerAssets();
		loadClickSounds();

		grpStickers = new FlxTypedGroup<StickerTransitionSprite>();
		add(grpStickers);
		grpStickers.cameras = FlxG.cameras.list;

		if (fade == TransitionFade.OUT) {
			regenStickers();
		} else if (pendingStickers != null && pendingStickers.length > 0) {
			attachPendingStickers();
			degenStickers();
		} else {
			close();
		}
	}

	function getStickerConfig():StickerTransitionConfig {
		if (Paths.modJSON == null || Paths.modJSON.transitions == null) {
			return null;
		}

		return Paths.modJSON.transitions.sticker;
	}

	function loadStickerAssets():Void {
		var config = getStickerConfig();
		if (config == null || config.assets == null) {
			return;
		}

		for (stickerKey in config.assets) {
			var graphic = Paths.image(stickerKey);
			if (graphic != null && !stickerGraphics.contains(graphic)) {
				stickerGraphics.push(graphic);
			}
		}
	}

	function loadClickSounds():Void {
		var config = getStickerConfig();
		var clickIndices = config != null && config.click_sound_indices != null ? config.click_sound_indices : defaultClickIndices;

		for (soundIndex in clickIndices) {
			var soundKey = 'stickersounds/keys/keyClick$soundIndex';
			Paths.loadRemoteSharedSound(soundKey, function(sound) {
				if (sound != null && !clickSounds.contains(sound)) {
					clickSounds.push(sound);
				}
			});
		}
	}

	function playStickerSound():Void {
		if (clickSounds.length <= 0) {
			return;
		}

		var sound = FlxG.random.getObject(clickSounds);
		if (sound != null) {
			FlxG.sound.play(sound);
		}
	}

	function getRandomStickerGraphic():FlxGraphic {
		if (stickerGraphics.length <= 0) {
			return null;
		}

		return FlxG.random.getObject(stickerGraphics);
	}

	function createStickerSprite(graphic:FlxGraphic):StickerTransitionSprite {
		if (graphic == null || graphic.bitmap == null) {
			return null;
		}

		return new StickerTransitionSprite(0, 0, graphic);
	}

	function attachPendingStickers():Void {
		var carriedStickers = pendingStickers;
		pendingStickers = null;

		if (carriedStickers == null) {
			return;
		}

		for (sticker in carriedStickers) {
			if (sticker != null) {
				grpStickers.add(sticker);
			}
		}

		grpStickers.cameras = FlxG.cameras.list;
	}

	function stashCurrentStickers():Void {
		pendingStickers = [];

		if (grpStickers == null || grpStickers.members == null) {
			return;
		}

		for (sticker in grpStickers.members) {
			if (sticker == null) {
				continue;
			}

			pendingStickers.push(sticker);
		}
	}

	public function degenStickers():Void {
		grpStickers.cameras = FlxG.cameras.list;

		if (grpStickers.members == null || grpStickers.members.length == 0) {
			switchingState = false;
			close();
			return;
		}

		for (ind => sticker in grpStickers.members) {
			if (sticker == null) {
				continue;
			}

			var stickerIndex = ind;
			var stickerRef = sticker;
			var hideDelay = stickerRef.timing;

			new FlxTimer().start(hideDelay, _ -> {
				if (stickerRef == null) {
					return;
				}

				stickerRef.visible = false;
				playStickerSound();

				if (grpStickers == null || stickerIndex == grpStickers.members.length - 1) {
					switchingState = false;
					close();
				}
			});
		}
	}

	function regenStickers():Void {
		if (grpStickers.members.length > 0) {
			grpStickers.clear();
		}

		if (stickerGraphics.length <= 0) {
			HelperStates.nextTransitionInType = null;
			callback();
			return;
		}

		var xPos:Float = -100;
		var yPos:Float = -100;
		while (xPos <= FlxG.width) {
			var stickerGraphic = getRandomStickerGraphic();
			if (stickerGraphic == null || stickerGraphic.bitmap == null) {
				break;
			}

			var sticker = createStickerSprite(stickerGraphic);
			if (sticker == null) {
				break;
			}

			sticker.visible = false;
			sticker.x = xPos;
			sticker.y = yPos;
			xPos += sticker.frameWidth * 0.5;

			if (xPos >= FlxG.width && yPos <= FlxG.height) {
				xPos = -100;
				yPos += FlxG.random.float(70, 120);
			}

			sticker.angle = FlxG.random.int(-60, 70);
			grpStickers.add(sticker);
		}

		FlxG.random.shuffle(grpStickers.members);

		var lastGraphic = getRandomStickerGraphic();
		if (lastGraphic != null && lastGraphic.bitmap != null) {
			var lastSticker = createStickerSprite(lastGraphic);
			if (lastSticker != null) {
				lastSticker.visible = false;
				lastSticker.updateHitbox();
				lastSticker.angle = 0;
				lastSticker.screenCenter();
				grpStickers.add(lastSticker);
			}
		}

		for (ind => sticker in grpStickers.members) {
			if (sticker == null) {
				continue;
			}

			sticker.timing = FlxMath.remapToRange(ind, 0, grpStickers.members.length, 0, 0.9);
			var stickerIndex = ind;
			var stickerRef = sticker;
			var showDelay = stickerRef.timing;

			new FlxTimer().start(showDelay, _ -> {
				if (grpStickers == null || stickerRef == null) {
					return;
				}

				stickerRef.visible = true;
				playStickerSound();

				var frameTimer:Int = FlxG.random.int(0, 2);
				if (stickerIndex == grpStickers.members.length - 1) {
					frameTimer = 2;
				}

				new FlxTimer().start((1 / 24) * frameTimer, _ -> {
					if (stickerRef == null) {
						return;
					}

					var jitter = FlxG.random.float(0.97, 1.02);
					stickerRef.scale.x = jitter;
					stickerRef.scale.y = jitter;

					if (stickerIndex == grpStickers.members.length - 1) {
						switchingState = true;
						HelperStates.nextTransitionInType = "sticker";
						stashCurrentStickers();
						callback();
					}
				});
			});
		}

		grpStickers.sort((ord, a, b) -> {
			return FlxSort.byValues(ord, a.timing, b.timing);
		});
	}

	override public function close():Void {
		if (switchingState && fade == TransitionFade.OUT) {
			return;
		}

		super.close();
	}

	override public function destroy():Void {
		if (switchingState && fade == TransitionFade.OUT && grpStickers != null) {
			var carriedStickers = pendingStickers != null ? pendingStickers.copy() : grpStickers.members.copy();
			for (sticker in carriedStickers) {
				if (sticker != null) {
					grpStickers.remove(sticker, true);
				}
			}
		}

		super.destroy();
	}
}

class StickerTransitionSprite extends FlxSprite {
	public var timing:Float = 0;

	public function new(x:Float, y:Float, graphic:FlxGraphic) {
		super(x, y);
		loadGraphic(graphic);
		updateHitbox();
		scrollFactor.set();
	}
}
