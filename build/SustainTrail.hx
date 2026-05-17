package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import flixel.graphics.tile.FlxDrawTrianglesItem.DrawData;
import flixel.math.FlxMath;

/**
 * Port of Funkin's `funkin.play.notes.SustainTrail` (rendering only).
 * Draws an entire hold note as a single triangle-meshed strip with the cap
 * baked into the texture via UV mapping — eliminating the head/trail seam
 * that segmented holds suffer from.
 *
 * `hitNote` / `missedNote` / `sustainLength` are externally driven by
 * PlayState based on the underlying segmented sustain chain; this class
 * is purely visual.
 */
class SustainTrail extends FlxSprite {
	static final TRIANGLE_VERTEX_INDICES:Array<Int> = [0, 1, 2, 1, 2, 3, 4, 5, 6, 5, 6, 7];
	static inline final HOLD_STRIP_COLOR_COUNT:Int = 5;

	public static inline var PIXELS_PER_MS:Float = 0.45;

	public var strumTime:Float = 0;
	public var noteDirection:Int = 0;
	public var fullSustainLength:Float = 0;
	public var sustainLength(default, set):Float = 0;

	public var headNote:Note = null;
	public var mustPress:Bool = false;

	public var hitNote:Bool = false;
	public var missedNote:Bool = false;

	public var vertices:DrawData<Float> = new DrawData<Float>();
	public var indices:DrawData<Int> = new DrawData<Int>();
	public var uvtData:DrawData<Float> = new DrawData<Float>();

	public var yOffset:Float = 0.0;

	public var zoom:Float = 1.0;
	public var endOffset:Float = 0.5;
	public var bottomClip:Float = 1.0;

	public var scrollSpeed:Float = 1.0;

	var graphicWidth:Float = 0;
	var graphicHeight:Float = 0;

	public function new(noteDirection:Int, sustainLength:Float, atlasKey:String, scrollSpeed:Float = 1.0, downscroll:Bool = false) {
		super(0, 0);

		this.noteDirection = noteDirection;
		this.scrollSpeed = scrollSpeed;

		setIndices(TRIANGLE_VERTEX_INDICES);

		var stripGraphic = HoldNoteStrip.build(atlasKey);
		if (stripGraphic == null) {
			active = false;
			visible = false;
			return;
		}

		loadGraphic(stripGraphic);
		if (graphic == null) {
			active = false;
			visible = false;
			return;
		}
		antialiasing = FlxG.save.data.showAntialiasing;

		zoom = 0.7;
		flipY = downscroll;
		alpha = 1.0;

		graphicWidth = graphic.width / (HOLD_STRIP_COLOR_COUNT * 2) * zoom;

		this.fullSustainLength = sustainLength;
		this.sustainLength = sustainLength;

		this.active = true;
	}

	public function setIndices(idx:Array<Int>):Void {
		if (this.indices.length == idx.length) {
			for (i in 0...idx.length) this.indices[i] = idx[i];
		} else {
			this.indices = new DrawData<Int>(idx.length, false, idx);
		}
	}

	public static inline function sustainHeight(susLength:Float, scroll:Float):Float {
		return susLength * PIXELS_PER_MS * scroll;
	}

	function set_sustainLength(s:Float):Float {
		if (s < 0.0) s = 0.0;
		this.sustainLength = s;
		triggerRedraw();
		return this.sustainLength;
	}

	function triggerRedraw():Void {
		updateVisualLength(sustainLength);
		updateClipping();
	}

	public function updateVisualLength(visualLength:Float):Void {
		var nextHeight:Float = sustainHeight(Math.max(0, visualLength), scrollSpeed);
		if(Math.abs(graphicHeight - nextHeight) <= 0.001) {
			return;
		}

		graphicHeight = nextHeight;
		updateHitbox();
	}

	override public function updateHitbox():Void {
		width = graphicWidth;
		height = graphicHeight;
		offset.set(0, 0);
		origin.set(width * 0.5, height * 0.5);
	}

	public function updateClipping(songTime:Float = 0, ?visualElapsed:Null<Float>, ?visualFullLength:Null<Float>):Void {
		if (graphic == null) return;

		var fullLength:Float = visualFullLength != null ? visualFullLength : sustainLength;
		updateVisualLength(fullLength);

		var elapsed:Float = visualElapsed != null ? visualElapsed : songTime - strumTime;
		var clipHeight:Float = FlxMath.bound(sustainHeight(fullLength - elapsed, scrollSpeed), 0, graphicHeight);
		if (clipHeight <= 0.1) {
			visible = false;
			return;
		} else {
			visible = true;
		}

		var bottomHeight:Float = graphic.height * zoom * endOffset;
		var partHeight:Float = clipHeight - bottomHeight;

		ensureLen(vertices, 16);

		vertices[0 * 2] = 0.0;
		vertices[0 * 2 + 1] = flipY ? clipHeight : graphicHeight - clipHeight;

		vertices[1 * 2] = graphicWidth;
		vertices[1 * 2 + 1] = vertices[0 * 2 + 1];

		vertices[2 * 2] = 0.0;
		vertices[2 * 2 + 1] = if (partHeight > 0) {
			flipY ? 0.0 + bottomHeight : vertices[1] + partHeight;
		} else {
			vertices[0 * 2 + 1];
		}

		vertices[3 * 2] = graphicWidth;
		vertices[3 * 2 + 1] = vertices[2 * 2 + 1];

		ensureLen(uvtData, 16);

		var colorIndex:Int = getHoldStripColorIndex();
		var bodyU:Float = colorIndex / HOLD_STRIP_COLOR_COUNT;
		var capU:Float = bodyU + (1 / (HOLD_STRIP_COLOR_COUNT * 2));
		var segmentUWidth:Float = 1 / (HOLD_STRIP_COLOR_COUNT * 2);

		uvtData[0 * 2] = bodyU;
		uvtData[0 * 2 + 1] = (-partHeight) / graphic.height / zoom;

		uvtData[1 * 2] = uvtData[0 * 2] + segmentUWidth;
		uvtData[1 * 2 + 1] = uvtData[0 * 2 + 1];

		uvtData[2 * 2] = uvtData[0 * 2];
		uvtData[2 * 2 + 1] = 0.0;

		uvtData[3 * 2] = uvtData[1 * 2];
		uvtData[3 * 2 + 1] = uvtData[2 * 2 + 1];

		vertices[4 * 2] = vertices[2 * 2];
		vertices[4 * 2 + 1] = vertices[2 * 2 + 1];

		vertices[5 * 2] = vertices[3 * 2];
		vertices[5 * 2 + 1] = vertices[3 * 2 + 1];

		vertices[6 * 2] = vertices[2 * 2];
		vertices[6 * 2 + 1] = flipY
			? (graphic.height * (-bottomClip + endOffset) * zoom)
			: (graphicHeight + graphic.height * (bottomClip - endOffset) * zoom);

		vertices[7 * 2] = vertices[3 * 2];
		vertices[7 * 2 + 1] = vertices[6 * 2 + 1];

		uvtData[4 * 2] = capU;
		uvtData[4 * 2 + 1] = if (partHeight > 0) 0 else (bottomHeight - clipHeight) / zoom / graphic.height;

		uvtData[5 * 2] = uvtData[4 * 2] + segmentUWidth;
		uvtData[5 * 2 + 1] = uvtData[4 * 2 + 1];

		uvtData[6 * 2] = uvtData[4 * 2];
		uvtData[6 * 2 + 1] = bottomClip;

		uvtData[7 * 2] = uvtData[5 * 2];
		uvtData[7 * 2 + 1] = uvtData[6 * 2 + 1];
	}

	function getHoldStripColorIndex():Int {
		if(PlayState.SONG != null && PlayState.SONG.fifthKey) {
			return Std.int(FlxMath.bound(noteDirection, 0, HOLD_STRIP_COLOR_COUNT - 1));
		}

		return switch(noteDirection % 4) {
			case 0: 0; // purple
			case 1: 1; // blue
			case 2: 3; // green
			case 3: 4; // red
			default: 0;
		}
	}

	static inline function ensureLen(v:DrawData<Float>, n:Int):Void {
		while (v.length < n) v.push(0.0);
	}

	@:access(flixel.FlxCamera)
	override public function draw():Void {
		if (alpha == 0 || graphic == null || vertices == null) return;

		for (camera in cameras) {
			if (!camera.visible || !camera.exists) continue;

			getScreenPosition(_point, camera).subtractPoint(offset);
			camera.drawTriangles(graphic, vertices, indices, uvtData, null, _point, blend, true, antialiasing, colorTransform, shader);
		}
	}

	override public function destroy():Void {
		vertices = null;
		indices = null;
		uvtData = null;
		headNote = null;
		super.destroy();
	}
}
