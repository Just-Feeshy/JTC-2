package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import haxe.ui.backend.flixel.CursorHelper;
import openfl.display.BitmapData;

class FunkinCursor
{
	public static var cursorMode(get, set):Null<CursorMode>;
	static var _cursorMode:Null<CursorMode> = null;

	public static inline function show():Void
	{
		FlxG.mouse.visible = true;
		FunkinCursor.cursorMode = Default;
	}

	public static inline function hide():Void
	{
		FlxG.mouse.visible = false;
		FunkinCursor.cursorMode = null;
	}

	public static inline function toggle():Void
	{
		if (FlxG.mouse.visible) hide();
		else show();
	}

	public static final CURSOR_DEFAULT_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-default.png",
		scale: 1.0,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_CROSS_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-cross.png",
		scale: 1.0,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_ERASER_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-eraser.png",
		scale: 1.0,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_GRABBING_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-grabbing.png",
		scale: 1.0,
		offsetX: -8,
		offsetY: 0,
	};

	public static final CURSOR_HOURGLASS_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-hourglass.png",
		scale: 1.0,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_POINTER_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-pointer.png",
		scale: 1.0,
		offsetX: -8,
		offsetY: 0,
	};

	public static final CURSOR_TEXT_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-text.png",
		scale: 0.2,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_TEXT_VERTICAL_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-text-vertical.png",
		scale: 0.2,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_ZOOM_IN_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-zoom-in.png",
		scale: 1.0,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_ZOOM_OUT_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-zoom-out.png",
		scale: 1.0,
		offsetX: 0,
		offsetY: 0,
	};

	public static final CURSOR_CROSSHAIR_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-crosshair.png",
		scale: 1.0,
		offsetX: -16,
		offsetY: -16,
	};

	public static final CURSOR_CELL_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-cell.png",
		scale: 1.0,
		offsetX: -16,
		offsetY: -16,
	};

	public static final CURSOR_SCROLL_PARAMS:CursorParams = {
		graphic: "preload/images/cursor/cursor-scroll.png",
		scale: 0.2,
		offsetX: -15,
		offsetY: -15,
	};

	static var assetCursorDefault:FlxGraphic = null;
	static var assetCursorCross:FlxGraphic = null;
	static var assetCursorEraser:FlxGraphic = null;
	static var assetCursorGrabbing:FlxGraphic = null;
	static var assetCursorHourglass:FlxGraphic = null;
	static var assetCursorPointer:FlxGraphic = null;
	static var assetCursorText:FlxGraphic = null;
	static var assetCursorTextVertical:FlxGraphic = null;
	static var assetCursorZoomIn:FlxGraphic = null;
	static var assetCursorZoomOut:FlxGraphic = null;
	static var assetCursorCrosshair:FlxGraphic = null;
	static var assetCursorCell:FlxGraphic = null;
	static var assetCursorScroll:FlxGraphic = null;

	static inline function get_cursorMode():Null<CursorMode>
	{
		return _cursorMode;
	}

	static function set_cursorMode(value:Null<CursorMode>):Null<CursorMode>
	{
		if (value != null && _cursorMode != value)
		{
			_cursorMode = value;
			loadCursorGraphic(_cursorMode);
		}
		else if (value == null)
		{
			_cursorMode = null;
			FlxG.mouse.unload();
		}
		return _cursorMode;
	}

	static var haxeUIRegistered:Bool = false;

	public static function load():Void
	{
		FlxG.mouse.visible = true;
		cursorMode = Default;
		registerHaxeUICursors();
		preloadAll();
	}

	public static function registerHaxeUICursors():Void
	{
		if (haxeUIRegistered) return;
		haxeUIRegistered = true;

		CursorHelper.useCustomCursors = true;

		// HaxeUI calls this with a graphic path and expects a synchronous
		// BitmapData. If it's already in our URL cache we return it. If not,
		// kick off the fetch AND, once it lands, force-apply the cursor via
		// FlxG.mouse.load directly - HaxeUI's _cursor already matches, so it
		// wouldn't trigger a refresh on its own.
		CursorHelper.mouseLoadFunction = function(path:String):BitmapData {
			var graphic = Paths.getCachedRemoteGraphic(path);
			if (graphic != null) return graphic.bitmap;

			Paths.loadRemoteGraphic(path, function(g:FlxGraphic) {
				if (g == null) return;
				var params = paramsByPath.get(path);
				if (params == null) return;
				FlxG.mouse.load(g.bitmap, params.scale, params.offsetX, params.offsetY);
				FlxG.mouse.visible = true;
			});
			return null;
		};

		registerHaxeUICursor("default", CURSOR_DEFAULT_PARAMS);
		registerHaxeUICursor("cross", CURSOR_CROSS_PARAMS);
		registerHaxeUICursor("eraser", CURSOR_ERASER_PARAMS);
		registerHaxeUICursor("grabbing", CURSOR_GRABBING_PARAMS);
		registerHaxeUICursor("move", CURSOR_GRABBING_PARAMS);
		registerHaxeUICursor("hourglass", CURSOR_HOURGLASS_PARAMS);
		registerHaxeUICursor("wait", CURSOR_HOURGLASS_PARAMS);
		registerHaxeUICursor("pointer", CURSOR_POINTER_PARAMS);
		registerHaxeUICursor("text", CURSOR_TEXT_PARAMS);
		registerHaxeUICursor("text-vertical", CURSOR_TEXT_VERTICAL_PARAMS);
		registerHaxeUICursor("zoom-in", CURSOR_ZOOM_IN_PARAMS);
		registerHaxeUICursor("zoom-out", CURSOR_ZOOM_OUT_PARAMS);
		registerHaxeUICursor("crosshair", CURSOR_CROSSHAIR_PARAMS);
		registerHaxeUICursor("cell", CURSOR_CELL_PARAMS);
		registerHaxeUICursor("scroll", CURSOR_SCROLL_PARAMS);
	}

	static var paramsByPath:Map<String, CursorParams> = new Map();

	static inline function registerHaxeUICursor(id:String, params:CursorParams):Void
	{
		CursorHelper.registerCursor(id, params.graphic, params.scale, params.offsetX, params.offsetY);
		paramsByPath.set(params.graphic, params);
	}

	static function preloadAll():Void
	{
		for (params in [
			CURSOR_DEFAULT_PARAMS, CURSOR_CROSS_PARAMS, CURSOR_ERASER_PARAMS,
			CURSOR_GRABBING_PARAMS, CURSOR_HOURGLASS_PARAMS, CURSOR_POINTER_PARAMS,
			CURSOR_TEXT_PARAMS, CURSOR_TEXT_VERTICAL_PARAMS, CURSOR_ZOOM_IN_PARAMS,
			CURSOR_ZOOM_OUT_PARAMS, CURSOR_CROSSHAIR_PARAMS, CURSOR_CELL_PARAMS,
			CURSOR_SCROLL_PARAMS,
		])
		{
			Paths.loadRemoteGraphic(params.graphic, function(_:FlxGraphic) {});
		}
	}

	static inline function lookupCached(path:String):FlxGraphic
	{
		return Paths.getCachedRemoteGraphic(path);
	}

	static function loadCursorGraphic(mode:Null<CursorMode>):Void
	{
		if (mode == null)
		{
			FlxG.mouse.unload();
			return;
		}

		var params:CursorParams = paramsFor(mode);
		var cached:FlxGraphic = cacheFor(mode);

		if (params == null)
		{
			FlxG.mouse.unload();
			return;
		}

		if (cached != null)
		{
			applyGraphic(cached, params);
			return;
		}

		Paths.loadRemoteGraphic(params.graphic, function(graphic:FlxGraphic) {
			if (graphic == null)
			{
				trace("FunkinCursor: failed to load cursor graphic for " + mode);
				return;
			}

			setCacheFor(mode, graphic);

			// Only apply if the requested mode is still the active one.
			if (cursorMode == mode) applyGraphic(graphic, params);
		});
	}

	static inline function applyGraphic(graphic:FlxGraphic, params:CursorParams):Void
	{
		FlxG.mouse.load(graphic.bitmap, params.scale, params.offsetX, params.offsetY);
		FlxG.mouse.visible = true;
	}

	static function paramsFor(mode:CursorMode):CursorParams
	{
		return switch (mode)
		{
			case Default: CURSOR_DEFAULT_PARAMS;
			case Cross: CURSOR_CROSS_PARAMS;
			case Eraser: CURSOR_ERASER_PARAMS;
			case Grabbing: CURSOR_GRABBING_PARAMS;
			case Hourglass: CURSOR_HOURGLASS_PARAMS;
			case Pointer: CURSOR_POINTER_PARAMS;
			case Text: CURSOR_TEXT_PARAMS;
			case TextVertical: CURSOR_TEXT_VERTICAL_PARAMS;
			case ZoomIn: CURSOR_ZOOM_IN_PARAMS;
			case ZoomOut: CURSOR_ZOOM_OUT_PARAMS;
			case Crosshair: CURSOR_CROSSHAIR_PARAMS;
			case Cell: CURSOR_CELL_PARAMS;
			case Scroll: CURSOR_SCROLL_PARAMS;
		}
	}

	static function cacheFor(mode:CursorMode):FlxGraphic
	{
		return switch (mode)
		{
			case Default: assetCursorDefault;
			case Cross: assetCursorCross;
			case Eraser: assetCursorEraser;
			case Grabbing: assetCursorGrabbing;
			case Hourglass: assetCursorHourglass;
			case Pointer: assetCursorPointer;
			case Text: assetCursorText;
			case TextVertical: assetCursorTextVertical;
			case ZoomIn: assetCursorZoomIn;
			case ZoomOut: assetCursorZoomOut;
			case Crosshair: assetCursorCrosshair;
			case Cell: assetCursorCell;
			case Scroll: assetCursorScroll;
		}
	}

	static function setCacheFor(mode:CursorMode, graphic:FlxGraphic):Void
	{
		switch (mode)
		{
			case Default: assetCursorDefault = graphic;
			case Cross: assetCursorCross = graphic;
			case Eraser: assetCursorEraser = graphic;
			case Grabbing: assetCursorGrabbing = graphic;
			case Hourglass: assetCursorHourglass = graphic;
			case Pointer: assetCursorPointer = graphic;
			case Text: assetCursorText = graphic;
			case TextVertical: assetCursorTextVertical = graphic;
			case ZoomIn: assetCursorZoomIn = graphic;
			case ZoomOut: assetCursorZoomOut = graphic;
			case Crosshair: assetCursorCrosshair = graphic;
			case Cell: assetCursorCell = graphic;
			case Scroll: assetCursorScroll = graphic;
		}
	}
}

enum CursorMode
{
	Default;
	Cross;
	Eraser;
	Grabbing;
	Hourglass;
	Pointer;
	Text;
	TextVertical;
	ZoomIn;
	ZoomOut;
	Crosshair;
	Cell;
	Scroll;
}

typedef CursorParams =
{
	graphic:String,
	scale:Float,
	offsetX:Int,
	offsetY:Int,
}
