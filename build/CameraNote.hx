package;

import flixel.FlxG;
import flixel.graphics.frames.FlxFrame;
import flixel.math.FlxMatrix;
import flixel.system.FlxAssets.FlxShader;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import feshixl.FeshCamera;
import feshixl.shaders.FeshFilterShader;
import openfl.display.BitmapData;
import openfl.display.Bitmap;
import openfl.display.BlendMode;
import openfl.display.Graphics;
import openfl.display.ShaderInput;
import openfl.display.ShaderParameter;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.display3D.Context3DTextureFilter;
import openfl.filters.ShaderFilter;
import openfl.geom.ColorTransform;
import openfl.geom.Rectangle;

class CameraNote extends FeshCamera {
    static inline var NOTE_TARGET_NONE:Int = 0;
    static inline var NOTE_TARGET_SUSTAIN:Int = 2;

    private var sustainNoteLayer:Sprite;
    private var sustainNoteBuffer:BitmapData;
    private var dummyNoteBuffer:BitmapData;
    private var sustainCompositeBitmap:Bitmap;
    private var blitSustainShape:Shape;
    private var noteLayerRect:Rectangle;
    private var sustainCompositeShader:FeshFilterShader;
    private var sustainCompositeFilter:ShaderFilter;

    private var notePassActive:Bool = false;
    private var notePassDirty:Bool = false;
    private var currentNoteTarget:Int = NOTE_TARGET_NONE;
    private var sustainPassDirty:Bool = false;
    private var lastNoteCaptureFrame:Int = -1;

    private var quadRects = new openfl.Vector<Float>(4);
    private var quadTransforms = new openfl.Vector<Float>(6);
    private var quadAlphas:Array<Float> = [1, 1, 1, 1];
    private var quadColorMultipliers:Array<Float> = [];
    private var quadColorOffsets:Array<Float> = [];

    public function new() {
        super();

        sustainNoteLayer = new Sprite();
        blitSustainShape = new Shape();
        noteLayerRect = new Rectangle();
        dummyNoteBuffer = new BitmapData(1, 1, true, FlxColor.TRANSPARENT);
        sustainCompositeBitmap = new Bitmap(dummyNoteBuffer);
        sustainCompositeBitmap.visible = false;
        sustainCompositeBitmap.smoothing = antialiasing;
        canvas.addChild(sustainCompositeBitmap);
    }

    public function beginNotePass():Void {
        ensureNoteTargets();

        var currentFrame:Int = FlxG.game.ticks;
        var shouldClearBuffers:Bool = lastNoteCaptureFrame != currentFrame;
        lastNoteCaptureFrame = currentFrame;

        notePassActive = true;
        notePassDirty = false;
        currentNoteTarget = NOTE_TARGET_NONE;
        sustainPassDirty = false;

        if(FlxG.renderTile) {
            sustainNoteLayer.graphics.clear();
        } else {
            if(shouldClearBuffers) {
                sustainNoteBuffer.fillRect(noteLayerRect, FlxColor.TRANSPARENT);
            }
        }

        if(FlxG.renderTile && shouldClearBuffers) {
            sustainNoteBuffer.fillRect(noteLayerRect, FlxColor.TRANSPARENT);
        }
    }

    public function flushNotePass():Void {
        if(!notePassActive) {
            return;
        }

        currentNoteTarget = NOTE_TARGET_NONE;

        if(!notePassDirty) {
            notePassActive = false;
            return;
        }

        ensureNoteTargets();

        if(FlxG.renderTile) {
            if(sustainPassDirty) {
                sustainNoteBuffer.draw(sustainNoteLayer);
            }
        }

        if(FlxG.renderBlit) {
            if(sustainPassDirty) {
                drawNoteBuffersToMainBuffer();
                screen.dirty = true;
            }
        }

        notePassActive = false;
    }

    public inline function isNotePassActive():Bool {
        return notePassActive;
    }

    public function beginNoteSpriteDraw(isSustainNote:Bool):Void {
        if(!notePassActive) {
            return;
        }

        currentNoteTarget = shouldSeparateSustainPass() && isSustainNote ? NOTE_TARGET_SUSTAIN : NOTE_TARGET_NONE;
        if(currentNoteTarget != NOTE_TARGET_NONE) {
            notePassDirty = true;
            sustainPassDirty = true;
        }
    }

    public function endNoteSpriteDraw():Void {
        currentNoteTarget = NOTE_TARGET_NONE;
    }

    public function setSustainCompositeShader(shader:FeshFilterShader):Void {
        sustainCompositeShader = shader;
        sustainCompositeFilter = shader != null ? new ShaderFilter(shader) : null;
    }

    public function clearSustainCompositeShader():Void {
        sustainCompositeShader = null;
        sustainCompositeFilter = null;
    }

    public inline function hasSustainCompositeShader():Bool {
        return sustainCompositeShader != null;
    }

    private inline function shouldSeparateSustainPass():Bool {
        return sustainCompositeShader != null;
    }

    override function drawPixels(?frame:FlxFrame, ?pixels:BitmapData, matrix:FlxMatrix, ?transform:ColorTransform, ?blend:BlendMode, ?smoothing:Bool = false,
        ?shader:FlxShader):Void {
        if(currentNoteTarget != NOTE_TARGET_NONE) {
            ensureNoteTargets();
            drawPixelsToNoteBuffer(getTargetBuffer(), pixels, matrix, blend, smoothing);
        }

        super.drawPixels(frame, pixels, matrix, transform, blend, smoothing, shader);
    }

    override function copyPixels(?frame:FlxFrame, ?pixels:BitmapData, ?sourceRect:Rectangle, destPoint:openfl.geom.Point, ?transform:ColorTransform, ?blend:BlendMode,
        ?smoothing:Bool = false, ?shader:FlxShader):Void {
        if(currentNoteTarget != NOTE_TARGET_NONE) {
            ensureNoteTargets();
            copyPixelsToNoteBuffer(getTargetBuffer(), pixels, sourceRect, destPoint, blend, smoothing);
        }

        super.copyPixels(frame, pixels, sourceRect, destPoint, transform, blend, smoothing, shader);
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        ensureNoteTargets();
    }

    override function render():Void {
        super.render();

        if(FlxG.renderTile) {
            if(sustainCompositeShader != null) {
                ensureNoteTargets();
                sustainCompositeBitmap.bitmapData = sustainNoteBuffer != null ? sustainNoteBuffer : dummyNoteBuffer;
                sustainCompositeBitmap.smoothing = antialiasing;
                sustainCompositeBitmap.shader = null;
                sustainCompositeBitmap.filters = sustainCompositeFilter != null ? [sustainCompositeFilter] : null;
                sustainCompositeBitmap.visible = true;

                if(canvas != null && sustainCompositeBitmap.parent == canvas) {
                    canvas.setChildIndex(sustainCompositeBitmap, canvas.numChildren - 1);
                }
            } else {
                sustainCompositeBitmap.visible = false;
                sustainCompositeBitmap.shader = null;
                sustainCompositeBitmap.filters = null;
            }
        }
    }

    override function destroy() {
        sustainNoteBuffer = FlxDestroyUtil.dispose(sustainNoteBuffer);
        dummyNoteBuffer = FlxDestroyUtil.dispose(dummyNoteBuffer);
        if(canvas != null && sustainCompositeBitmap != null && sustainCompositeBitmap.parent == canvas) {
            canvas.removeChild(sustainCompositeBitmap);
        }
        sustainCompositeBitmap = null;
        sustainNoteLayer = null;
        blitSustainShape = null;
        noteLayerRect = null;
        sustainCompositeShader = null;
        sustainCompositeFilter = null;

        super.destroy();
    }

    private function ensureNoteTargets():Void {
        var targetWidth:Int = Std.int(width);
        var targetHeight:Int = Std.int(height);

        if(targetWidth <= 0 || targetHeight <= 0) {
            return;
        }

        if(sustainNoteBuffer == null || sustainNoteBuffer.width != targetWidth || sustainNoteBuffer.height != targetHeight) {
            sustainNoteBuffer = FlxDestroyUtil.dispose(sustainNoteBuffer);
            sustainNoteBuffer = new BitmapData(targetWidth, targetHeight, true, FlxColor.TRANSPARENT);
        }

        noteLayerRect.setTo(0, 0, targetWidth, targetHeight);
    }

    private inline function getTargetBuffer():BitmapData {
        return sustainNoteBuffer;
    }

    private inline function getTargetGraphics():Graphics {
        return sustainNoteLayer.graphics;
    }

    private function drawPixelsToNoteBuffer(target:BitmapData, pixels:BitmapData, matrix:FlxMatrix, blend:BlendMode, smoothing:Bool):Void {
        if(target == null || pixels == null) {
            return;
        }

        _helperMatrix.copyFrom(matrix);

        if(_useBlitMatrix) {
            _helperMatrix.concat(_blitMatrix);
            target.draw(pixels, _helperMatrix, null, null, null, (smoothing || antialiasing));
        } else {
            target.draw(pixels, _helperMatrix, null, blend, null, (smoothing || antialiasing));
        }
    }

    private function copyPixelsToNoteBuffer(target:BitmapData, pixels:BitmapData, sourceRect:Rectangle, destPoint:openfl.geom.Point, blend:BlendMode, smoothing:Bool):Void {
        if(target == null || pixels == null) {
            return;
        }

        if(_useBlitMatrix) {
            _helperMatrix.identity();
            _helperMatrix.translate(destPoint.x, destPoint.y);
            _helperMatrix.concat(_blitMatrix);
            target.draw(pixels, _helperMatrix, null, null, null, (smoothing || antialiasing));
        } else {
            _helperPoint.x = destPoint.x;
            _helperPoint.y = destPoint.y;
            target.copyPixels(pixels, sourceRect, _helperPoint, null, null, true);
        }
    }

    private function drawPixelsToNoteLayer(graphics:Graphics, frame:FlxFrame, matrix:FlxMatrix, transform:ColorTransform, blend:BlendMode, smoothing:Bool, shader:FlxShader):Void {
        if(graphics == null || frame == null) {
            return;
        }

        var drawShader = shader != null ? shader : frame.parent.shader;
        if(drawShader == null) {
            return;
        }

        prepareQuadShader(drawShader, frame.parent.bitmap, transform, smoothing);

        var rect = frame.frame;
        quadRects[0] = rect.x;
        quadRects[1] = rect.y;
        quadRects[2] = rect.width;
        quadRects[3] = rect.height;

        quadTransforms[0] = matrix.a;
        quadTransforms[1] = matrix.b;
        quadTransforms[2] = matrix.c;
        quadTransforms[3] = matrix.d;
        quadTransforms[4] = matrix.tx;
        quadTransforms[5] = matrix.ty;

        graphics.overrideBlendMode(blend);
        graphics.beginShaderFill(drawShader);
        graphics.drawQuads(quadRects, null, quadTransforms);
        graphics.endFill();
    }

    private function copyPixelsToNoteLayer(graphics:Graphics, frame:FlxFrame, destPoint:openfl.geom.Point, transform:ColorTransform, blend:BlendMode, smoothing:Bool, shader:FlxShader):Void {
        if(graphics == null || frame == null) {
            return;
        }

        _helperMatrix.identity();
        _helperMatrix.translate(destPoint.x + frame.offset.x, destPoint.y + frame.offset.y);
        drawPixelsToNoteLayer(graphics, frame, _helperMatrix, transform, blend, smoothing, shader);
    }

    private function prepareQuadShader(shader:Dynamic, bitmap:BitmapData, transform:ColorTransform, smoothing:Bool):Void {
        shader.bitmap.input = bitmap;
        shader.bitmap.filter = (antialiasing || smoothing) ? Context3DTextureFilter.LINEAR : Context3DTextureFilter.NEAREST;

        var alphaMultiplier:Float = transform != null ? transform.alphaMultiplier : 1.0;
        for(i in 0...4) {
            quadAlphas[i] = alphaMultiplier;
        }
        shader.alpha.value = quadAlphas;

        var hasColorTransform:Bool = transform != null && (
            transform.redMultiplier != 1 || transform.greenMultiplier != 1 || transform.blueMultiplier != 1 || transform.alphaMultiplier != 1 ||
            transform.redOffset != 0 || transform.greenOffset != 0 || transform.blueOffset != 0 || transform.alphaOffset != 0
        );
        if(hasColorTransform) {
            quadColorMultipliers.splice(0, quadColorMultipliers.length);
            quadColorOffsets.splice(0, quadColorOffsets.length);

            for(_ in 0...4) {
                quadColorMultipliers.push(transform.redMultiplier);
                quadColorMultipliers.push(transform.greenMultiplier);
                quadColorMultipliers.push(transform.blueMultiplier);
                quadColorMultipliers.push(1);

                quadColorOffsets.push(transform.redOffset);
                quadColorOffsets.push(transform.greenOffset);
                quadColorOffsets.push(transform.blueOffset);
                quadColorOffsets.push(transform.alphaOffset);
            }

            shader.colorMultiplier.value = quadColorMultipliers;
            shader.colorOffset.value = quadColorOffsets;
        } else {
            shader.colorMultiplier.value = null;
            shader.colorOffset.value = null;
        }

        setShaderBool(shader.hasTransform, true);
        setShaderBool(shader.hasColorTransform, hasColorTransform);
    }

    private inline function setShaderBool(parameter:ShaderParameter<Bool>, value:Bool):Void {
        if(parameter == null) {
            return;
        }

        if(parameter.value == null) {
            parameter.value = [];
        }

        parameter.value[0] = value;
    }

    private function drawNoteBuffersToMainBuffer():Void {
        if(sustainNoteBuffer == null) {
            return;
        }

        buffer.copyPixels(sustainNoteBuffer, noteLayerRect, _flashPoint, null, null, true);
    }
}
