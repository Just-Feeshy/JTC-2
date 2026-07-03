package play;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxMath;

class StageCamera
{
	var playState:PlayState;

	public var enabled:Bool = true;
	public var configured:Bool = false;

	var defaultZoom:Float = 1.0;
	var focusLerp:Float = 0.04;
	var baseFocusX:Float = 0;
	var baseFocusY:Float = 0;

	var charOffsetX:Map<String, Float> = new Map<String, Float>();
	var charOffsetY:Map<String, Float> = new Map<String, Float>();

	var keyframes:Array<CameraKeyframe> = [];
	var bumps:Array<BumpSeg> = [];
	var activeSegments:Map<String, Bool> = new Map<String, Bool>();

	var curIndex:Int = -1;

	var appliedFocusX:Float = 0;
	var appliedFocusY:Float = 0;
	var appliedZoom:Float = 1.0;
	var appliedLerp:Float = 0;
	var hasApplied:Bool = false;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function setEnabled(value:Bool):Void
	{
		enabled = value;
	}

	public function triggerSegment(name:String):Void
	{
		if(name == null) return;
		activeSegments.set(name, true);
	}

	public function clearSegment(name:String):Void
	{
		if(name == null) return;
		activeSegments.remove(name);
	}

	public function reset():Void
	{
		curIndex = -1;
		hasApplied = false;
		lastBumpStep = -1;
		activeSegments = new Map<String, Bool>();
		appliedFocusX = baseFocusX;
		appliedFocusY = baseFocusY;
		appliedZoom = defaultZoom;
		appliedLerp = focusLerp;
	}

	public function configure(config:Dynamic):Void
	{
		if(config == null)
			return;

		keyframes = [];
		charOffsetX = new Map<String, Float>();
		charOffsetY = new Map<String, Float>();

		defaultZoom = getFloat(config, "defaultZoom", 1.0);
		focusLerp = getFloat(config, "focusLerp", 0.04);

		var baseFocus:Dynamic = field(config, "baseFocus");
		if(baseFocus != null) {
			baseFocusX = getFloat(baseFocus, "x", 0);
			baseFocusY = getFloat(baseFocus, "y", 0);
		}

		var characters:Dynamic = field(config, "characters");
		if(characters != null) {
			for(charName in Reflect.fields(characters)) {
				var charCfg:Dynamic = Reflect.field(characters, charName);
				var off:Dynamic = field(charCfg, "focusOffset");
				if(off != null) {
					charOffsetX.set(charName.toLowerCase(), getFloat(off, "x", 0));
					charOffsetY.set(charName.toLowerCase(), getFloat(off, "y", 0));
				}
			}
		}

		var rawFrames:Dynamic = field(config, "keyframes");
		if(rawFrames != null && Std.isOfType(rawFrames, Array)) {
			var arr:Array<Dynamic> = cast rawFrames;
			for(raw in arr) {
				if(raw == null) continue;
				keyframes.push(parseKeyframe(raw));
			}
		}

		// Keep keyframes ordered by their activation step.
		keyframes.sort(function(a, b) {
			var av:Float = a.activationStep();
			var bv:Float = b.activationStep();
			return (av < bv) ? -1 : (av > bv ? 1 : 0);
		});

		bumps = [];
		var rawBumps:Dynamic = field(config, "bumps");
		if(rawBumps != null && Std.isOfType(rawBumps, Array)) {
			var arr:Array<Dynamic> = cast rawBumps;
			for(raw in arr) {
				if(raw == null) continue;
				var b:BumpSeg = new BumpSeg();
				b.step = getFloat(raw, "step", 0);
				b.perStep = Std.int(getFloat(raw, "perStep", 4));
				b.force = getFloat(raw, "force", 1);
				b.count = Std.int(getFloat(raw, "count", 0));
				bumps.push(b);
			}
			bumps.sort(function(a, b) return (a.step < b.step) ? -1 : (a.step > b.step ? 1 : 0));
		}
		playState.hasAuthoredBumps = bumps.length > 0;

		configured = true;
		reset();
	}

	function parseKeyframe(raw:Dynamic):CameraKeyframe
	{
		var kf:CameraKeyframe = new CameraKeyframe();
		kf.step = getFloat(raw, "step", 0);
		kf.fromStep = hasField(raw, "fromStep") ? getFloat(raw, "fromStep", kf.step) : Math.NaN;
		kf.duration = getFloat(raw, "duration", 0);
		kf.ease = getString(raw, "ease", "linear");
		kf.segment = getString(raw, "segment", "");

		kf.zoom = hasField(raw, "zoom") ? getFloat(raw, "zoom", 1.0) : Math.NaN;
		kf.lerp = hasField(raw, "lerp") ? getFloat(raw, "lerp", 0) : Math.NaN;

		var focus:Dynamic = field(raw, "focus");
		if(focus != null) {
			kf.hasFocus = true;
			kf.focusX = getFloat(focus, "x", 0);
			kf.focusY = getFloat(focus, "y", 0);
		}

		kf.target = getString(raw, "target", "");
		if(kf.target != "") {
			var anchor:Dynamic = field(raw, "anchor");
			if(anchor != null) {
				kf.anchorX = getFloat(anchor, "x", 0.5);
				kf.anchorY = getFloat(anchor, "y", 0.5);
			}
			var offset:Dynamic = field(raw, "offset");
			if(offset != null) {
				kf.offsetX = getFloat(offset, "x", 0);
				kf.offsetY = getFloat(offset, "y", 0);
			}
		}

		return kf;
	}

	// ------------------------------------------------------------------
	// Per-frame update
	// ------------------------------------------------------------------

	/**
	 * Drive the gameplay camera as a PURE function of the conductor — no wall-clock tween state — so
	 * the in-game framing matches the Stage Builder preview exactly (see StageCameraTimeline.updateFraming).
	 * The active keyframe is the last eligible one at/before `stepFloat`; it eases FROM the previous
	 * keyframe's settled framing (stage base focus before the first) over its `duration` seconds, with
	 * song-time progress derived solely from the conductor. Zero duration SNAPS.
	 */
	public function update(elapsed:Float, stepFloat:Float, stepLengthMs:Float):Void
	{
		if(!enabled || !configured)
			return;

		applyBumps(stepFloat);

		if(keyframes.length == 0)
			return;

		var idx:Int = pickKeyframe(stepFloat);
		if(idx < 0)
			return; // No keyframe active yet; leave the default camera alone.

		curIndex = idx;
		var kf:CameraKeyframe = keyframes[idx];

		// Target framing for the active keyframe.
		resolveFocus(kf, focusTmp);
		var targetFocusX:Float = focusTmp[0];
		var targetFocusY:Float = focusTmp[1];
		var targetZoom:Float = (!Math.isNaN(kf.zoom) && kf.zoom > 0) ? kf.zoom : defaultZoom;
		var targetLerp:Float = Math.isNaN(kf.lerp) ? focusLerp : kf.lerp;

		// Origin framing: the previous keyframe's settled framing (stage base focus before the first),
		// resolved fresh each frame so we ease from a fixed point rather than the live camera. This is
		// what makes gameplay reproducible and identical to the editor preview.
		var startFocusX:Float;
		var startFocusY:Float;
		var startZoom:Float;
		if(idx > 0) {
			var prev:CameraKeyframe = keyframes[idx - 1];
			resolveFocus(prev, focusTmp);
			startFocusX = focusTmp[0];
			startFocusY = focusTmp[1];
			startZoom = (!Math.isNaN(prev.zoom) && prev.zoom > 0) ? prev.zoom : defaultZoom;
		} else {
			startFocusX = baseFocusX;
			startFocusY = baseFocusY;
			startZoom = defaultZoom;
		}

		// Progress measured purely in song time (exact under frame lag / scrubbing). Zero-duration snaps.
		var progress:Float = 1.0;
		if(!Math.isNaN(kf.fromStep)) {
			// Step-based ease anchor.
			var span:Float = kf.step - kf.fromStep;
			progress = (span <= 0) ? 1.0 : FlxMath.bound((stepFloat - kf.fromStep) / span, 0, 1);
		} else if(kf.duration > 0 && stepLengthMs > 0) {
			var sinceSec:Float = (stepFloat - kf.step) * stepLengthMs / 1000;
			progress = FlxMath.bound(sinceSec / kf.duration, 0, 1);
		}

		var eased:Float = applyEase(kf.ease, progress);

		appliedFocusX = lerp(startFocusX, targetFocusX, eased);
		appliedFocusY = lerp(startFocusY, targetFocusY, eased);
		appliedZoom = lerp(startZoom, targetZoom, eased);
		appliedLerp = targetLerp;
		hasApplied = true;

		// Frame at the EXACT authored focus so gameplay matches the Stage Builder preview. The keyframe's
		// `lerp` is consumed by PlayState as a blend weight that drags the focus toward the live gameplay
		// auto-focus (camPos) — e.g. toward the flying BF parked at (-2017,-922) — which the editor never
		// models, so it produced a large divergence. The editor owns `lerp` as round-trip metadata only;
		// the conductor-driven keyframe duration/ease already handle the move, and FlxCamera's own follow
		// lerp still smooths the result, so we pass 0 here to suppress the camPos drift entirely.
		playState.setScriptedCameraFocus(appliedFocusX, appliedFocusY, false);
		playState.setScriptedCameraFocusLerp(0);
		playState.setScriptedCameraZoom(appliedZoom, true, false);
	}

	var lastBumpStep:Int = -1;

	/**
	 * Fire authored camera bumps with the SAME per-integer-step timing as the Stage Editor preview
	 * (StageEditor.updatePreviewBump): one bop per new step, on steps where (step - segStep) % perStep
	 * == 0 within the active segment's window. Bops go straight to triggerCameraBop with bypass=true so
	 * they ride over the stage's suppress-while-scripted-zoom flag. No reliance on stepHit/bumpPerStep,
	 * so there's no frame-order drift between setting the interval and reading it (that drift was
	 * dropping/mistiming bops in gameplay while the preview stayed clean).
	 */
	function applyBumps(stepFloat:Float):Void
	{
		if(bumps.length == 0)
			return;

		var curStep:Int = Std.int(stepFloat);
		if(curStep == lastBumpStep)
			return; // one bop per integer step
		lastBumpStep = curStep;

		var seg:BumpSeg = null;
		for(b in bumps) {
			if(b.step <= curStep) seg = b;
			else break;
		}
		if(seg == null)
			return; // before the first segment

		var within:Bool = (seg.count <= 0) || (curStep < seg.step + (seg.count * seg.perStep));
		if(within && seg.perStep > 0 && (curStep - Std.int(seg.step)) % seg.perStep == 0)
			playState.triggerCameraBop(seg.force, true);
	}

	var focusTmp:Array<Float> = [0, 0];

	function pickKeyframe(stepFloat:Float):Int
	{
		var best:Int = -1;
		for(i in 0...keyframes.length) {
			var kf:CameraKeyframe = keyframes[i];
			if(kf.segment != "" && !activeSegments.exists(kf.segment))
				continue;
			if(kf.activationStep() <= stepFloat)
				best = i;
		}
		return best;
	}

	function resolveFocus(kf:CameraKeyframe, out:Array<Float>):Void
	{
		if(kf.target != "") {
			var spr:FlxSprite = resolveSprite(kf.target);
			if(spr != null) {
				var key:String = kf.target.toLowerCase();
				var extraX:Float = charOffsetX.exists(key) ? charOffsetX.get(key) : 0;
				var extraY:Float = charOffsetY.exists(key) ? charOffsetY.get(key) : 0;
				out[0] = spr.x + (spr.width * kf.anchorX) + kf.offsetX + extraX;
				out[1] = spr.y + (spr.height * kf.anchorY) + kf.offsetY + extraY;
				return;
			}
		}

		if(kf.hasFocus) {
			out[0] = kf.focusX;
			out[1] = kf.focusY;
			return;
		}

		out[0] = baseFocusX;
		out[1] = baseFocusY;
	}

	function resolveSprite(target:String):FlxSprite
	{
		switch(target.toLowerCase()) {
			case "opponent", "dad", "p2":
				return playState.dad != null ? cast(playState.dad, FlxSprite) : null;
			case "boyfriend", "bf", "player", "p1":
				return playState.boyfriend != null ? cast(playState.boyfriend, FlxSprite) : null;
			case "gf", "girlfriend":
				return playState.gf != null ? cast(playState.gf, FlxSprite) : null;
			default:
				return playState.getStageCameraSprite(target);
		}
	}

	// ------------------------------------------------------------------
	// Helpers
	// ------------------------------------------------------------------

	static inline function lerp(a:Float, b:Float, t:Float):Float
	{
		return a + ((b - a) * t);
	}

	static function applyEase(ease:String, t:Float):Float
	{
		switch(ease) {
			case null, "", "linear":
				return t;
			case "smootherStep", "smoothstep":
				var c:Float = t < 0 ? 0 : (t > 1 ? 1 : t);
				return c * c * c * (c * ((c * 6) - 15) + 10);
			default:
				// Resolve any FlxEase function by name (e.g. "expoOut", "sineInOut").
				var fn:Dynamic = Reflect.field(flixel.tweens.FlxEase, ease);
				if (fn != null && Reflect.isFunction(fn)) {
					var r:Dynamic = Reflect.callMethod(null, fn, [t]);
					var rf:Float = cast r;
					return Math.isNaN(rf) ? t : rf;
				}
				return t;
		}
	}

	static inline function field(obj:Dynamic, name:String):Dynamic
	{
		return (obj != null && Reflect.hasField(obj, name)) ? Reflect.field(obj, name) : null;
	}

	static inline function hasField(obj:Dynamic, name:String):Bool
	{
		return obj != null && Reflect.hasField(obj, name);
	}

	static function getFloat(obj:Dynamic, name:String, def:Float):Float
	{
		var v:Dynamic = field(obj, name);
		if(v == null) return def;
		var f:Float = cast v;
		return Math.isNaN(f) ? def : f;
	}

	static function getString(obj:Dynamic, name:String, def:String):String
	{
		var v:Dynamic = field(obj, name);
		return (v != null) ? Std.string(v) : def;
	}
}

private class CameraKeyframe
{
	public var step:Float = 0;
	public var fromStep:Float = Math.NaN;
	public var duration:Float = 0;
	public var ease:String = "linear";
	public var segment:String = "";

	public var zoom:Float = Math.NaN;
	public var lerp:Float = Math.NaN;

	public var hasFocus:Bool = false;
	public var focusX:Float = 0;
	public var focusY:Float = 0;

	public var target:String = "";
	public var anchorX:Float = 0.5;
	public var anchorY:Float = 0.5;
	public var offsetX:Float = 0;
	public var offsetY:Float = 0;

	public function new() {}

	public inline function activationStep():Float
	{
		return Math.isNaN(fromStep) ? step : fromStep;
	}
}

private class BumpSeg
{
	public var step:Float = 0;
	public var perStep:Int = 4;
	public var force:Float = 1;
	public var count:Int = 0;

	public function new() {}
}
