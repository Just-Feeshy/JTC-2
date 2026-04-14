package;

import haxe.Json;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.math.FlxPoint;
import flixel.tweens.FlxTween;
import flixel.util.FlxDestroyUtil.IFlxDestroyable;
import feshixl.group.FeshEventGroup.IFeshEvent;

using StringTools;

class VSliceEvent implements IFeshEvent implements IFlxDestroyable {
    private static inline var WRAPPER_EVENT:String = "v-slice event";
    private static inline var WRAPPER_COMPONENT:String = "v-slice component";

    private var focusXTween:FlxTween;
    private var focusYTween:FlxTween;
    private var stageZoomTween:FlxTween;
    private var directZoomTween:FlxTween;

    public function new() {}

    public static function usesRawValues(eventName:String):Bool {
        if(eventName == null) {
            return false;
        }

        switch(eventName.toLowerCase().trim()) {
            case WRAPPER_EVENT
                | WRAPPER_COMPONENT
                | "focuscamera"
                | "zoomcamera"
                | "setcamerabop"
                | "playanimation"
                | "rimshadowevent"
                | "rimshadow"
                | "coloradjustevent"
                | "coloradjust":
                return true;
        }

        return false;
    }

    public function whenTriggered(eventName:String, eventValue:String, eventValue2:String, playState:PlayState):Void {
        var resolved:ResolvedVSliceEvent = resolveEvent(eventName, eventValue, eventValue2);

        if(resolved == null || resolved.kind == null || resolved.kind == "") {
            return;
        }

        switch(resolved.kind.toLowerCase().trim()) {
            case "focuscamera":
                handleFocusCamera(resolved.payload, playState);
            case "zoomcamera":
                handleZoomCamera(resolved.payload, playState);
            case "setcamerabop":
                handleSetCameraBop(resolved.payload, playState);
            case "playanimation":
                handlePlayAnimation(resolved.payload, playState);
            case "rimshadowevent" | "rimshadow":
                handleRimShadowEvent(resolved.payload, playState);
            case "coloradjustevent" | "coloradjust":
                handleColorAdjustEvent(resolved.payload, playState);
        }
    }

    public function whenGameIsRunning(activeEvents:Array<String>, playState:PlayState):Void {}

    public function whenNoteIsPressed(note:Note, playState:PlayState):Void {}

    public function destroy():Void {
        cancelTween(focusXTween);
        cancelTween(focusYTween);
        cancelTween(stageZoomTween);
        cancelTween(directZoomTween);
    }

    private function handleFocusCamera(payload:Dynamic, playState:PlayState):Void {
        var targetText:String = null;
        var targetKindValue:Dynamic = readDynamic(payload, "char");

        if(targetKindValue != null) {
            targetText = Std.string(targetKindValue);
        } else {
            var targetField:Dynamic = readDynamic(payload, "target");

            if(targetField != null) {
                targetText = Std.string(targetField);
            } else if(payload != null && !isPayloadObject(payload)) {
                targetText = Std.string(payload);
            }
        }

        var targetKind:Int = parseFocusTarget(targetText);

        if(targetKind == -2) {
            playState.vSliceCameraFocusEnabled = false;
            cancelTween(focusXTween);
            cancelTween(focusYTween);
            return;
        }

        var offsetX:Float = readFloat(payload, "x", 0);
        var offsetY:Float = readFloat(payload, "y", 0);
        var durationSteps:Float = readFloat(payload, "duration", 4);
        var easeName:String = readString(payload, "ease", "CLASSIC");
        var focusPoint:FlxPoint = resolveFocusPoint(targetKind, playState);

        if(focusPoint == null) {
            return;
        }

        var targetX:Float = focusPoint.x + offsetX;
        var targetY:Float = focusPoint.y + offsetY;
        var currentX:Float = playState.vSliceCameraFocusEnabled ? playState.vSliceCameraFocusX : playState.camPos.x;
        var currentY:Float = playState.vSliceCameraFocusEnabled ? playState.vSliceCameraFocusY : playState.camPos.y;
        var durationSeconds:Float = Math.max(0, (Conductor.instance.stepLengthMs / 1000) * durationSteps);

        playState.vSliceCameraFocusEnabled = true;

        if(easeName.toUpperCase() == "CLASSIC") {
            cancelTween(focusXTween);
            cancelTween(focusYTween);
            playState.vSliceCameraFocusX = targetX;
            playState.vSliceCameraFocusY = targetY;
            playState.camFollow.setPosition(targetX, targetY);
            return;
        }

        if(easeName.toUpperCase() == "INSTANT" || durationSeconds <= 0) {
            cancelTween(focusXTween);
            cancelTween(focusYTween);
            playState.vSliceCameraFocusX = targetX;
            playState.vSliceCameraFocusY = targetY;
            playState.camFollow.setPosition(targetX, targetY);
            FlxG.camera.focusOn(playState.camFollow.getPosition());
            return;
        }

        var easeFunction = Register.getFlxEaseByString(easeName);

        cancelTween(focusXTween);
        cancelTween(focusYTween);

        focusXTween = FlxTween.num(currentX, targetX, durationSeconds, {ease: easeFunction}, function(value:Float) {
            playState.vSliceCameraFocusX = value;
        });

        focusYTween = FlxTween.num(currentY, targetY, durationSeconds, {ease: easeFunction}, function(value:Float) {
            playState.vSliceCameraFocusY = value;
        });
    }

    private function handleZoomCamera(payload:Dynamic, playState:PlayState):Void {
        var zoomFallback:Float = playState.vSliceDirectZoomEnabled ? playState.vSliceDirectZoomValue : FlxG.camera.zoom;
        var zoom:Float = readFloat(payload, "zoom", safeParseFloat(Std.string(payload), zoomFallback));
        var durationSteps:Float = readFloat(payload, "duration", 4);
        var durationSeconds:Float = Math.max(0, (Conductor.instance.stepLengthMs / 1000) * durationSteps);
        var mode:String = readString(payload, "mode", "stage").toLowerCase().trim();
        var easeName:String = readString(payload, "ease", "linear");
        var instant:Bool = easeName.toUpperCase() == "INSTANT" || durationSeconds <= 0;
        var easeFunction = Register.getFlxEaseByString(easeName);

        if(mode == "direct") {
            var currentZoom:Float = playState.vSliceDirectZoomEnabled ? playState.vSliceDirectZoomValue : FlxG.camera.zoom;

            cancelTween(directZoomTween);
            playState.vSliceDirectZoomEnabled = true;
            playState.vSliceDirectZoomValue = currentZoom;

            if(instant) {
                playState.vSliceDirectZoomValue = zoom;
                return;
            }

            directZoomTween = FlxTween.num(currentZoom, zoom, durationSeconds, {ease: easeFunction}, function(value:Float) {
                playState.vSliceDirectZoomValue = value;
            });

            return;
        }

        playState.vSliceDirectZoomEnabled = false;
        cancelTween(directZoomTween);
        cancelTween(stageZoomTween);

        if(instant) {
            playState.defaultCamZoom = zoom;
            return;
        }

        var currentStageZoom:Float = playState.defaultCamZoom;

        stageZoomTween = FlxTween.num(currentStageZoom, zoom, durationSeconds, {ease: easeFunction}, function(value:Float) {
            playState.defaultCamZoom = value;
        });
    }

    private function handleSetCameraBop(payload:Dynamic, playState:PlayState):Void {
        playState.bumpForce = readFloat(payload, "intensity", 1);
        playState.bumpPerBeat = Std.int(Math.max(0, readInt(payload, "rate", 4)));
        playState.bumpOffset = readInt(payload, "offset", 0);
    }

    private function handlePlayAnimation(payload:Dynamic, playState:PlayState):Void {
        var targetName:String = readString(payload, "target", "boyfriend").toLowerCase().trim();
        var animName:String = readString(payload, "anim", readString(payload, "animation", "idle"));
        var force:Bool = readBool(payload, "force", false);
        var target:FlxSprite = null;

        switch(targetName) {
            case "boyfriend" | "bf" | "player":
                target = playState.boyfriend;
            case "dad" | "opponent":
                target = playState.dad;
            case "girlfriend" | "gf":
                target = playState.gf;
            default:
                if(playState.modifiableCharacters != null && playState.modifiableCharacters.exists(targetName)) {
                    target = playState.modifiableCharacters.get(targetName);
                } else if(playState.stage != null) {
                    var stageTarget:Dynamic = Reflect.field(playState.stage, targetName);

                    if(Std.isOfType(stageTarget, FlxSprite)) {
                        target = cast stageTarget;
                    }
                }
        }

        if(target == null || animName == null || animName == "") {
            return;
        }

        if(Std.isOfType(target, Character)) {
            cast(target, Character).playAnim(animName, force);
        } else if(target.animation != null) {
            target.animation.play(animName, force);
        }
    }

    private function handleRimShadowEvent(payload:Dynamic, playState:PlayState):Void {
        var character:Character = resolveShaderTarget(readString(payload, "target", "boyfriend"), playState);

        if(character == null) {
            return;
        }

        if(!readBool(payload, "enabled", true)) {
            character.shader = null;
            return;
        }

        var shader = new RimShadowShader();
        shader.color = parseHexColor(readString(payload, "hexcolor", "D46B00"), 0xFFD46B00);
        shader.angle = readFloat(payload, "angle", 125);
        shader.distance = readFloat(payload, "distance", 12);
        shader.threshold = readFloat(payload, "threshold", 0.15);
        shader.brightness = readFloat(payload, "brightness", -35);
        shader.hue = readFloat(payload, "hue", -15);
        shader.contrast = readFloat(payload, "contrast", 10);
        shader.saturation = readFloat(payload, "saturation", -20);
        shader.updateFrameInfo(character.frame);
        character.shader = shader;
    }

    private function handleColorAdjustEvent(payload:Dynamic, playState:PlayState):Void {
        var character:Character = resolveShaderTarget(readString(payload, "target", "boyfriend"), playState);

        if(character == null) {
            return;
        }

        if(!readBool(payload, "enabled", true)) {
            character.shader = null;
            return;
        }

        var shader = new AdjustColorShader();
        shader.brightness = readFloat(payload, "brightness", 0);
        shader.hue = readFloat(payload, "hue", 0);
        shader.contrast = readFloat(payload, "contrast", 0);
        shader.saturation = readFloat(payload, "saturation", 0);
        character.shader = shader;
    }

    private function resolveEvent(eventName:String, eventValue:String, eventValue2:String):ResolvedVSliceEvent {
        var normalizedName:String = eventName != null ? eventName.toLowerCase().trim() : "";
        var directKind:String = resolveDirectKind(normalizedName);

        if(directKind != null) {
            return {
                kind: directKind,
                payload: resolvePayloadForKind(directKind, eventValue, eventValue2)
            };
        }

        if(normalizedName != WRAPPER_EVENT && normalizedName != WRAPPER_COMPONENT) {
            return null;
        }

        var eventValueText:String = eventValue != null ? eventValue.trim() : "";

        if(looksLikeJson(eventValueText)) {
            var component:Dynamic = parseJson(eventValueText);

            if(component != null) {
                var componentKind:String = readString(component, "e", readString(component, "event", readString(component, "eventKind", "")));
                var payload:Dynamic = readDynamic(component, "v");

                if(payload == null) {
                    payload = readDynamic(component, "value");
                }

                if(componentKind != null && componentKind != "") {
                    return {
                        kind: componentKind,
                        payload: payload
                    };
                }
            }
        }

        return {
            kind: eventValueText,
            payload: resolvePayloadForKind(eventValueText, eventValue2, null)
        };
    }

    private function resolvePayloadForKind(kind:String, rawPrimary:String, rawSecondary:String):Dynamic {
        var primaryText:String = rawPrimary != null ? rawPrimary.trim() : "";
        var secondaryText:String = rawSecondary != null ? rawSecondary.trim() : "";

        if(looksLikeJson(primaryText)) {
            var parsedPrimary:Dynamic = parseJson(primaryText);

            if(parsedPrimary != null) {
                if(readDynamic(parsedPrimary, "v") != null) {
                    return readDynamic(parsedPrimary, "v");
                }

                return parsedPrimary;
            }
        }

        if(looksLikeJson(secondaryText)) {
            var parsedSecondary:Dynamic = parseJson(secondaryText);

            if(parsedSecondary != null) {
                return parsedSecondary;
            }
        }

        switch(kind.toLowerCase().trim()) {
            case "focuscamera":
                return {char: primaryText};
            case "zoomcamera":
                return {
                    zoom: safeParseFloat(primaryText, FlxG.camera.zoom),
                    duration: safeParseFloat(secondaryText, 4),
                    mode: "stage",
                    ease: "linear"
                };
            case "setcamerabop":
                return {
                    intensity: safeParseFloat(primaryText, 1),
                    rate: safeParseInt(secondaryText, 4),
                    offset: 0
                };
            case "playanimation":
                return {
                    anim: primaryText,
                    target: secondaryText,
                    force: false
                };
            case "rimshadowevent" | "rimshadow":
                return {
                    target: "boyfriend",
                    enabled: true,
                    hexcolor: "D46B00",
                    angle: 125,
                    distance: 12,
                    threshold: 0.15,
                    brightness: -35,
                    hue: -15,
                    contrast: 10,
                    saturation: -20
                };
            case "coloradjustevent" | "coloradjust":
                return {
                    target: "boyfriend",
                    enabled: true,
                    brightness: 0,
                    hue: 0,
                    contrast: 0,
                    saturation: 0
                };
        }

        return {};
    }

    private function resolveDirectKind(normalizedName:String):String {
        switch(normalizedName) {
            case "focuscamera":
                return "FocusCamera";
            case "zoomcamera":
                return "ZoomCamera";
            case "setcamerabop":
                return "SetCameraBop";
            case "playanimation":
                return "PlayAnimation";
            case "rimshadowevent" | "rimshadow":
                return "RimShadowEvent";
            case "coloradjustevent" | "coloradjust":
                return "ColorAdjustEvent";
        }

        return null;
    }

    private function resolveFocusPoint(targetKind:Int, playState:PlayState):FlxPoint {
        switch(targetKind) {
            case -1:
                return new FlxPoint(0, 0);
            case 0:
                if(playState.boyfriend == null) {
                    return null;
                }

                var boyfriendPoint = playState.boyfriend.getMidpoint();
                return new FlxPoint(boyfriendPoint.x - 100, boyfriendPoint.y - 100);
            case 1:
                if(playState.dad == null) {
                    return null;
                }

                var dadPoint = playState.dad.getMidpoint();
                return new FlxPoint(dadPoint.x + 150, dadPoint.y - 100);
            case 2:
                if(playState.gf == null) {
                    return null;
                }

                var girlfriendPoint = playState.gf.getMidpoint();
                return new FlxPoint(girlfriendPoint.x, girlfriendPoint.y);
        }

        return null;
    }

    private function resolveShaderTarget(value:String, playState:PlayState):Character {
        if(playState == null) {
            return null;
        }

        switch(value != null ? value.toLowerCase().trim() : "") {
            case "dad" | "opponent":
                return playState.dad;
            case "girlfriend" | "gf":
                return playState.gf;
            default:
                return playState.boyfriend;
        }
    }

    private function parseFocusTarget(value:String):Int {
        if(value == null) {
            return 0;
        }

        var normalized:String = value.toLowerCase().trim();

        switch(normalized) {
            case "-1" | "position" | "static":
                return -1;
            case "0" | "boyfriend" | "bf" | "player":
                return 0;
            case "1" | "dad" | "opponent":
                return 1;
            case "2" | "girlfriend" | "gf":
                return 2;
            case "-2" | "default" | "section" | "reset":
                return -2;
        }

        return safeParseInt(normalized, 0);
    }

    private function looksLikeJson(value:String):Bool {
        if(value == null) {
            return false;
        }

        var trimmed:String = value.trim();
        return trimmed.startsWith("{") || trimmed.startsWith("[");
    }

    private function parseJson(value:String):Dynamic {
        try {
            return Json.parse(value);
        } catch(e:Dynamic) {
            return null;
        }
    }

    private function parseHexColor(value:String, fallback:Int):Int {
        if(value == null) {
            return fallback;
        }

        var trimmed:String = value.trim();

        if(trimmed.startsWith("#")) {
            trimmed = trimmed.substr(1);
        }

        if(trimmed.length == 6) {
            trimmed = "FF" + trimmed;
        }

        if(trimmed.length != 8) {
            return fallback;
        }

        var parsed:Null<Int> = Std.parseInt("0x" + trimmed);
        return parsed == null ? fallback : parsed;
    }

    private function isPayloadObject(value:Dynamic):Bool {
        return value != null && (Reflect.isObject(value) || Std.isOfType(value, Array));
    }

    private function readDynamic(payload:Dynamic, field:String):Dynamic {
        if(payload == null || field == null || field == "") {
            return null;
        }

        try {
            if(Reflect.hasField(payload, field)) {
                return Reflect.field(payload, field);
            }
        } catch(e:Dynamic) {}

        return null;
    }

    private function readString(payload:Dynamic, field:String, fallback:String):String {
        var value:Dynamic = readDynamic(payload, field);

        if(value == null) {
            return fallback;
        }

        return Std.string(value);
    }

    private function readFloat(payload:Dynamic, field:String, fallback:Float):Float {
        var value:Dynamic = readDynamic(payload, field);
        return value == null ? fallback : safeParseFloat(Std.string(value), fallback);
    }

    private function readInt(payload:Dynamic, field:String, fallback:Int):Int {
        var value:Dynamic = readDynamic(payload, field);
        return value == null ? fallback : safeParseInt(Std.string(value), fallback);
    }

    private function readBool(payload:Dynamic, field:String, fallback:Bool):Bool {
        var value:Dynamic = readDynamic(payload, field);

        if(value == null) {
            return fallback;
        }

        if(Std.isOfType(value, Bool)) {
            return cast value;
        }

        switch(Std.string(value).toLowerCase().trim()) {
            case "1" | "true" | "yes":
                return true;
            case "0" | "false" | "no":
                return false;
            default:
                return fallback;
        }
    }

    private function safeParseFloat(value:String, fallback:Float):Float {
        var parsed:Float = Std.parseFloat(value);
        return Math.isNaN(parsed) ? fallback : parsed;
    }

    private function safeParseInt(value:String, fallback:Int):Int {
        var parsed:Null<Int> = Std.parseInt(value);
        return parsed == null ? fallback : parsed;
    }

    private function cancelTween(tween:FlxTween):Void {
        if(tween != null) {
            tween.cancel();
            tween.destroy();
        }
    }
}

private typedef ResolvedVSliceEvent = {
    var kind:String;
    var payload:Dynamic;
}
