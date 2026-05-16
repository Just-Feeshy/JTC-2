package;

import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFrame;
import openfl.display.BitmapData;
import openfl.geom.Point;
import openfl.geom.Rectangle;

/**
 * Composes JTC's per-color hold-piece + hold-end frames into the 8-segment
 * horizontal strip that Funkin's SustainTrail UV math expects.
 *
 * Layout (left→right): [purple body][purple cap][blue body][blue cap]
 *                      [green body][green cap][red body][red cap]
 *
 * noteData → column index: body = noteData*2, cap = noteData*2 + 1.
 */
class HoldNoteStrip {
	static var cache:Map<String, FlxGraphic> = new Map();

	static final COLORS:Array<String> = ["purple", "blue", "green", "red"];

	static function getPieceFrame(atlas:FlxAtlasFrames, color:String):FlxFrame {
		return atlas.getByName('$color hold piece0000');
	}

	static function getCapFrame(atlas:FlxAtlasFrames, color:String):FlxFrame {
		if (color == "purple") {
			var typoed = atlas.getByName('pruple end hold0000');
			if (typoed != null) return typoed;
		}
		return atlas.getByName('$color hold end0000');
	}

	public static function clear():Void {
		cache = new Map();
	}

	public static function build(atlasKey:String):FlxGraphic {
		var cacheKey = 'hold_strip:$atlasKey';
		if (cache.exists(cacheKey)) {
			var cached = cache.get(cacheKey);
			if (cached != null && cached.bitmap != null && cached.bitmap.width > 0) return cached;
			cache.remove(cacheKey);
		}

		var atlas = Paths.getNoteAtlas(atlasKey);
		if (atlas == null) return null;

		var segW = 0;
		var segH = 0;
		for (color in COLORS) {
			var piece = getPieceFrame(atlas, color);
			var cap = getCapFrame(atlas, color);
			if (piece == null || cap == null) return null;
			segW = Std.int(Math.max(segW, Math.max(piece.frame.width, cap.frame.width)));
			segH = Std.int(Math.max(segH, Math.max(piece.frame.height, cap.frame.height)));
		}

		var totalW = segW * 8;
		var totalH = segH;
		var composite = new BitmapData(totalW, totalH, true, 0);
		var sourceBitmap = atlas.parent.bitmap;

		for (i in 0...COLORS.length) {
			var color = COLORS[i];
			var piece = getPieceFrame(atlas, color);
			var cap = getCapFrame(atlas, color);

			var bodyX = i * 2 * segW;
			var pieceH = Std.int(piece.frame.height);
			var pieceW = Std.int(piece.frame.width);
			var y = 0;
			while (y < totalH) {
				var sliceH = Std.int(Math.min(pieceH, totalH - y));
				var srcRect = new Rectangle(piece.frame.x, piece.frame.y, pieceW, sliceH);
				composite.copyPixels(sourceBitmap, srcRect, new Point(bodyX, y));
				y += pieceH;
			}

			var capX = (i * 2 + 1) * segW;
			var capW = Std.int(cap.frame.width);
			var capH = Std.int(cap.frame.height);
			var capSrc = new Rectangle(cap.frame.x, cap.frame.y, capW, capH);
			composite.copyPixels(sourceBitmap, capSrc, new Point(capX, totalH - capH));
		}

		var graphic = FlxGraphic.fromBitmapData(composite, false, cacheKey);
		cache.set(cacheKey, graphic);
		return graphic;
	}
}
