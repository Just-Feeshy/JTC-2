package;

import flixel.FlxG;
import flixel.FlxCamera;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxDestroyUtil;
import openfl.display.BitmapData;
import openfl.display.DisplayObject;
import openfl.geom.Matrix;
import openfl.geom.Rectangle;

import template.TransitionBuilder;

class StateBlendTransition extends TransitionBuilder {
    static inline var DEFAULT_DURATION:Float = 0.5;
    static var capturedFrame:BitmapData;

    var overlay:FlxSprite;
    var transitionTween:FlxTween;

    public function new(duration:Float, fade:TransitionFade) {
        super(duration, fade);

        if(fade == OUT) {
            captureCurrentFrame();
        }
    }

    override function create():Void {
        super.create();

        if(fade == OUT) {
            callback();
            return;
        }

        if(capturedFrame == null) {
            close();
            return;
        }

        overlay = new FlxSprite().loadGraphic(capturedFrame);
        overlay.antialiasing = false;
        overlay.scrollFactor.set();
        add(overlay);

        transitionTween = FlxTween.tween(overlay, {alpha: 0}, duration, {
            ease: FlxEase.quadOut,
            onComplete: function(twn:FlxTween) {
                close();
            }
        });
    }

    public static function captureCurrentFrame():Void {
        clearCapturedFrame();

        var captureWidth:Int = FlxG.width;
        var captureHeight:Int = FlxG.height;

        if(captureWidth <= 0 || captureHeight <= 0) {
            captureWidth = Std.int(FlxG.game.width);
            captureHeight = Std.int(FlxG.game.height);
        }

        capturedFrame = new BitmapData(captureWidth, captureHeight, true, 0x00000000);

        for(camera in FlxG.cameras.list) {
            if(camera == null || !camera.visible) {
                continue;
            }

            var cameraBuffer:BitmapData = FlxG.renderBlit ? getCameraBuffer(camera) : null;
            if(cameraBuffer != null) {
                var matrix:Matrix = new Matrix();
                matrix.translate(camera.x, camera.y);
                capturedFrame.draw(cameraBuffer, matrix, null, null, null, false);
                continue;
            }

            var flashSprite:DisplayObject = getCameraFlashSprite(camera);
            if(flashSprite != null) {
                capturedFrame.draw(flashSprite, null, null, null, null, false);
            }
        }
    }

    public static function hasCapturedFrame():Bool {
        return capturedFrame != null;
    }

    public static function applyPendingToState(state:FlxState, ?duration:Float):Bool {
        if(state == null || capturedFrame == null) {
            return false;
        }

        var blendDuration:Float = duration != null ? duration : DEFAULT_DURATION;
        var blendCamera:FlxCamera = new FlxCamera();
        blendCamera.bgColor.alpha = 0;
        FlxG.cameras.add(blendCamera, false);

        var fallbackBitmap:BitmapData = null;
        var overlayBitmap:BitmapData = capturedFrame;
        if(isBitmapEmpty(overlayBitmap)) {
            fallbackBitmap = new BitmapData(FlxG.width, FlxG.height, true, 0xFF000000);
            overlayBitmap = fallbackBitmap;
        }

        var blendOverlay:FlxSprite = new FlxSprite().loadGraphic(overlayBitmap);
        blendOverlay.antialiasing = false;
        blendOverlay.scrollFactor.set();
        blendOverlay.cameras = [blendCamera];
        state.add(blendOverlay);

        FlxTween.tween(blendOverlay, {alpha: 0}, blendDuration, {
            ease: FlxEase.quadOut,
            onComplete: function(twn:FlxTween) {
                if(state.members != null) {
                    state.remove(blendOverlay, true);
                }

                blendOverlay = FlxDestroyUtil.destroy(blendOverlay);
                FlxG.cameras.remove(blendCamera);
                blendCamera = FlxDestroyUtil.destroy(blendCamera);

                if(fallbackBitmap != null) {
                    fallbackBitmap.dispose();
                }

                clearCapturedFrame();
            }
        });

        return true;
    }

    static function getCameraBuffer(camera:FlxCamera):BitmapData {
        return cast Reflect.field(camera, "buffer");
    }

    static function getCameraFlashSprite(camera:FlxCamera):DisplayObject {
        return cast Reflect.field(camera, "flashSprite");
    }

    static function isBitmapEmpty(bitmap:BitmapData):Bool {
        if(bitmap == null || bitmap.width <= 0 || bitmap.height <= 0) {
            return true;
        }

        var bounds:Rectangle = bitmap.getColorBoundsRect(0xFF000000, 0x00000000, false);
        return bounds == null || bounds.width <= 0 || bounds.height <= 0;
    }

    static function clearCapturedFrame():Void {
        if(capturedFrame != null) {
            capturedFrame.dispose();
            capturedFrame = null;
        }
    }

    override function destroy():Void {
        if(transitionTween != null) {
            transitionTween.cancel();
            transitionTween.destroy();
            transitionTween = null;
        }

        overlay = FlxDestroyUtil.destroy(overlay);

        if(fade == IN) {
            clearCapturedFrame();
        }

        super.destroy();
    }
}
