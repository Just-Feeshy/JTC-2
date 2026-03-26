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
	static var pendingStickerSourceGroup:FlxTypedGroup<StickerTransitionSprite> = null;

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
		grpStickers.cameras = this.cameras;

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

	function getMinimumStickerSize():{width:Float, height:Float} {
		var minWidth:Float = 99999;
		var minHeight:Float = 99999;

		for (graphic in stickerGraphics) {
			if (graphic == null || graphic.bitmap == null) {
				continue;
			}

			minWidth = Math.min(minWidth, graphic.bitmap.width);
			minHeight = Math.min(minHeight, graphic.bitmap.height);
		}

		if (minWidth == 99999 || minHeight == 99999) {
			return {width: 128, height: 128};
		}

		return {width: minWidth, height: minHeight};
	}

	function findFirstUncoveredCell(coverage:Array<Bool>):Int {
		for (index in 0...coverage.length) {
			if (!coverage[index]) {
				return index;
			}
		}

		return -1;
	}

	function markStickerCoverage(graphic:FlxGraphic, stickerX:Float, stickerY:Float, stickerAngle:Float, coverage:Array<Bool>, gridWidth:Int, gridHeight:Int, cellSize:Int):Void {
		if (graphic == null || graphic.bitmap == null) {
			return;
		}

		var bitmap = graphic.bitmap;
		var radians = stickerAngle * Math.PI / 180;
		var cosAngle = Math.abs(Math.cos(radians));
		var sinAngle = Math.abs(Math.sin(radians));
		var rotatedWidth = (bitmap.width * cosAngle) + (bitmap.height * sinAngle);
		var rotatedHeight = (bitmap.width * sinAngle) + (bitmap.height * cosAngle);
		var centerX = stickerX + (bitmap.width * 0.5);
		var centerY = stickerY + (bitmap.height * 0.5);
		var boundX = centerX - (rotatedWidth * 0.5);
		var boundY = centerY - (rotatedHeight * 0.5);
		var startCellX = Std.int(Math.max(0, Math.floor(boundX / cellSize)));
		var endCellX = Std.int(Math.min(gridWidth - 1, Math.ceil((boundX + rotatedWidth) / cellSize)));
		var startCellY = Std.int(Math.max(0, Math.floor(boundY / cellSize)));
		var endCellY = Std.int(Math.min(gridHeight - 1, Math.ceil((boundY + rotatedHeight) / cellSize)));
		var inverseCos = Math.cos(-radians);
		var inverseSin = Math.sin(-radians);

		for (cellY in startCellY...endCellY + 1) {
			for (cellX in startCellX...endCellX + 1) {
				var worldX = (cellX * cellSize) + (cellSize * 0.5);
				var worldY = (cellY * cellSize) + (cellSize * 0.5);
				var translatedX = worldX - centerX;
				var translatedY = worldY - centerY;
				var localX = (translatedX * inverseCos) - (translatedY * inverseSin) + (bitmap.width * 0.5);
				var localY = (translatedX * inverseSin) + (translatedY * inverseCos) + (bitmap.height * 0.5);

				if (localX < 0 || localX >= bitmap.width || localY < 0 || localY >= bitmap.height) {
					continue;
				}

				var alpha = (bitmap.getPixel32(Std.int(localX), Std.int(localY)) >> 24) & 0xFF;
				if (alpha > 32) {
					coverage[(cellY * gridWidth) + cellX] = true;
				}
			}
		}
	}

	function attachPendingStickers():Void {
		var carriedStickers = pendingStickers;
		var sourceGroup = pendingStickerSourceGroup;
		pendingStickers = null;
		pendingStickerSourceGroup = null;

		if (carriedStickers == null) {
			return;
		}

		for (sticker in carriedStickers) {
			if (sticker != null) {
				if (sourceGroup != null && sourceGroup.members != null && sourceGroup.members.indexOf(sticker) != -1) {
					sourceGroup.remove(sticker, true);
				}
				grpStickers.add(sticker);
			}
		}

		grpStickers.cameras = this.cameras;
	}

	function stashCurrentStickers():Void {
		pendingStickers = [];
		pendingStickerSourceGroup = grpStickers;

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
		grpStickers.cameras = this.cameras;

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

		var minStickerSize = getMinimumStickerSize();
		var coverageCellSize = Std.int(Math.max(12, Math.min(minStickerSize.width, minStickerSize.height) * 0.18));
		var coverageGridWidth = Std.int(Math.ceil(FlxG.width / coverageCellSize)) + 1;
		var coverageGridHeight = Std.int(Math.ceil(FlxG.height / coverageCellSize)) + 1;
		var coverage:Array<Bool> = [for (_ in 0...(coverageGridWidth * coverageGridHeight)) false];
		var attempts = 0;
		var maxAttempts = coverage.length * 4;

		while (attempts < maxAttempts) {
			var uncoveredIndex = findFirstUncoveredCell(coverage);
			if (uncoveredIndex == -1) {
				break;
			}

			var stickerGraphic = getRandomStickerGraphic();
			if (stickerGraphic == null || stickerGraphic.bitmap == null) {
				break;
			}

			var sticker = createStickerSprite(stickerGraphic);
			if (sticker == null) {
				break;
			}

			var cellX = uncoveredIndex % coverageGridWidth;
			var cellY = Std.int(uncoveredIndex / coverageGridWidth);
			var targetX = (cellX * coverageCellSize) + (coverageCellSize * 0.5);
			var targetY = (cellY * coverageCellSize) + (coverageCellSize * 0.5);

			sticker.visible = false;
			sticker.x = targetX - (sticker.frameWidth * 0.5);
			sticker.y = targetY - (sticker.frameHeight * 0.5);
			sticker.angle = FlxG.random.int(-60, 70);
			grpStickers.add(sticker);

			markStickerCoverage(stickerGraphic, sticker.x, sticker.y, sticker.angle, coverage, coverageGridWidth, coverageGridHeight, coverageCellSize);
			attempts++;
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
				if (sticker != null && grpStickers.members != null && grpStickers.members.indexOf(sticker) != -1) {
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
