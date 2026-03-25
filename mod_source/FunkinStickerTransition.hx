import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.math.FlxMath;
import flixel.util.FlxTimer;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.media.Sound;
import template.TransitionBuilder;

typedef StickerVisual = {
	var container:Sprite;
	var timing:Float;
	var width:Float;
}

class FunkinStickerTransition extends TransitionBuilder {
	static var localStickerKeys:Array<String> = [
		"transitionSwag/Stickers0001",
		"transitionSwag/Stickers0002",
		"transitionSwag/Stickers0003",
		"transitionSwag/Stickers0011",
		"transitionSwag/Stickers0012",
		"transitionSwag/Stickers0013"
	];

	static var availableClickIndices:Array<Int> = [1, 2, 3, 4, 5, 7, 8, 9];

	static var pendingOverlay:Sprite = null;
	static var pendingVisuals:Array<StickerVisual> = null;

	var stickerGraphics:Array<FlxGraphic> = [];
	var clickSounds:Array<Sound> = [];

	public function new(duration:Float, fade:TransitionFade) {
		super(duration, fade);

		loadLocalStickers();
		loadClickSounds();

		if (fade == TransitionFade.OUT) {
			regenStickers();
		} else if (pendingOverlay != null && pendingVisuals != null && pendingVisuals.length > 0) {
			degenStickers();
		} else {
			close();
		}
	}

	function loadLocalStickers():Void {
		for (stickerKey in localStickerKeys) {
			var graphic = Paths.image(stickerKey);
			if (graphic != null && !stickerGraphics.contains(graphic)) {
				stickerGraphics.push(graphic);
			}
		}
	}

	function loadClickSounds():Void {
		for (soundIndex in availableClickIndices) {
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

	function createStickerContainer(graphic:FlxGraphic):Sprite {
		var bitmapData:BitmapData = graphic != null ? graphic.bitmap : null;

		if (bitmapData == null) {
			return null;
		}

		var container = new Sprite();
		container.mouseChildren = false;
		container.mouseEnabled = false;
		container.visible = false;

		var bitmap = new Bitmap(bitmapData);
		bitmap.x = -bitmap.width * 0.5;
		bitmap.y = -bitmap.height * 0.5;
		container.addChild(bitmap);

		return container;
	}

	function createVisual(container:Sprite, width:Float):StickerVisual {
		return {
			container: container,
			timing: 0,
			width: width
		};
	}

	function clearOverlay():Void {
		if (pendingOverlay != null && pendingOverlay.parent != null) {
			pendingOverlay.parent.removeChild(pendingOverlay);
		}

		pendingOverlay = null;
		pendingVisuals = null;
	}

	function degenStickers():Void {
		if (pendingOverlay == null || pendingVisuals == null || pendingVisuals.length == 0) {
			clearOverlay();
			close();
			return;
		}

		for (ind => visual in pendingVisuals) {
			var visualIndex = ind;
			var visualRef = visual;
			var hideDelay = visualRef.timing;

			new FlxTimer().start(hideDelay, _ -> {
				if (visualRef == null || visualRef.container == null) {
					return;
				}

				visualRef.container.visible = false;
				playStickerSound();

				if (pendingVisuals == null || visualIndex == pendingVisuals.length - 1) {
					clearOverlay();
					close();
				}
			});
		}
	}

	function regenStickers():Void {
		if (stickerGraphics.length <= 0) {
			HelperStates.nextTransitionInType = null;
			callback();
			return;
		}

		clearOverlay();

		pendingOverlay = new Sprite();
		pendingOverlay.mouseChildren = false;
		pendingOverlay.mouseEnabled = false;
		pendingVisuals = [];
		FlxG.game.addChild(pendingOverlay);

		var xPos:Float = -100;
		var yPos:Float = -100;

		while (xPos <= FlxG.width) {
			var stickerGraphic = getRandomStickerGraphic();
			if (stickerGraphic == null || stickerGraphic.bitmap == null) {
				break;
			}

			var container = createStickerContainer(stickerGraphic);
			if (container == null) {
				break;
			}

			var halfWidth = stickerGraphic.bitmap.width * 0.5;
			var halfHeight = stickerGraphic.bitmap.height * 0.5;
			container.x = xPos + halfWidth;
			container.y = yPos + halfHeight;
			container.rotation = FlxG.random.int(-60, 70);

			pendingOverlay.addChild(container);
			pendingVisuals.push(createVisual(container, stickerGraphic.bitmap.width));

			xPos += stickerGraphic.bitmap.width * 0.5;

			if (xPos >= FlxG.width && yPos <= FlxG.height) {
				xPos = -100;
				yPos += FlxG.random.float(70, 120);
			}
		}

		var lastGraphic = getRandomStickerGraphic();
		if (lastGraphic != null && lastGraphic.bitmap != null) {
			var lastContainer = createStickerContainer(lastGraphic);
			if (lastContainer != null) {
				lastContainer.x = FlxG.width * 0.5;
				lastContainer.y = FlxG.height * 0.5;
				lastContainer.rotation = 0;
				pendingOverlay.addChild(lastContainer);
				pendingVisuals.push(createVisual(lastContainer, lastGraphic.bitmap.width));
			}
		}

		FlxG.random.shuffle(pendingVisuals);

		for (ind => visual in pendingVisuals) {
			if (visual == null) {
				continue;
			}

			visual.timing = FlxMath.remapToRange(ind, 0, pendingVisuals.length, 0, 0.9);
			var visualIndex = ind;
			var visualRef = visual;
			var showDelay = visualRef.timing;

			new FlxTimer().start(showDelay, _ -> {
				if (pendingOverlay == null || visualRef == null || visualRef.container == null) {
					return;
				}

				visualRef.container.visible = true;
				playStickerSound();

				var frameTimer:Int = FlxG.random.int(0, 2);
				if (visualIndex == pendingVisuals.length - 1) {
					frameTimer = 2;
				}

				new FlxTimer().start((1 / 24) * frameTimer, _ -> {
					if (visualRef == null || visualRef.container == null) {
						return;
					}

					var jitter = FlxG.random.float(0.97, 1.02);
					visualRef.container.scaleX = jitter;
					visualRef.container.scaleY = jitter;

					if (visualIndex == pendingVisuals.length - 1) {
						HelperStates.nextTransitionInType = "sticker";
						callback();
					}
				});
			});
		}
	}

	override function destroy():Void {
		if (fade != TransitionFade.OUT || pendingOverlay == null || pendingOverlay.parent == null) {
			clearOverlay();
		}

		super.destroy();
	}
}
