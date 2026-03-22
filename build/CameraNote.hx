package;

import flixel.FlxG;
import flixel.graphics.frames.FlxFrame;
import flixel.math.FlxMatrix;
import flixel.system.FlxAssets.FlxShader;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import feshixl.FeshCamera;
import openfl.display.BitmapData;
import openfl.display.BlendMode;
import openfl.display.Graphics;
import openfl.display.ShaderParameter;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.display3D.Context3DTextureFilter;
import openfl.geom.ColorTransform;
import openfl.geom.Rectangle;

class CameraNote extends FeshCamera {
    static inline var NOTE_TARGET_NONE:Int = 0;
    static inline var NOTE_TARGET_REGULAR:Int = 1;
    static inline var NOTE_TARGET_SUSTAIN:Int = 2;

    private var regularNoteLayer:Sprite;
    private var sustainNoteLayer:Sprite;
    private var regularNoteBuffer:BitmapData;
    private var sustainNoteBuffer:BitmapData;
    private var blitSustainShape:Shape;
    private var noteLayerRect:Rectangle;
    private var sustainCompositeShader:FlxShader;

    private var notePassActive:Bool = false;
    private var notePassDirty:Bool = false;
    private var currentNoteTarget:Int = NOTE_TARGET_NONE;
    private var noteCompositePending:Bool = false;
    private var regularPassDirty:Bool = false;
    private var sustainPassDirty:Bool = false;

    private var quadRects = new openfl.Vector<Float>(4);
    private var quadTransforms = new openfl.Vector<Float>(6);
    private var quadAlphas:Array<Float> = [1, 1, 1, 1];
    private var quadColorMultipliers:Array<Float> = [];
    private var quadColorOffsets:Array<Float> = [];

    public function new() {
        super();

        regularNoteLayer = new Sprite();
        sustainNoteLayer = new Sprite();
        blitSustainShape = new Shape();
        noteLayerRect = new Rectangle();
    }

    public function beginNotePass():Void {
        ensureNoteTargets();

        notePassActive = true;
        notePassDirty = false;
        currentNoteTarget = NOTE_TARGET_NONE;
        noteCompositePending = false;
        regularPassDirty = false;
        sustainPassDirty = false;

        if(FlxG.renderTile) {
            regularNoteLayer.graphics.clear();
            sustainNoteLayer.graphics.clear();
        } else {
            regularNoteBuffer.fillRect(noteLayerRect, FlxColor.TRANSPARENT);
            sustainNoteBuffer.fillRect(noteLayerRect, FlxColor.TRANSPARENT);
        }
    }

    public function flushNotePass():Void {
        if(!notePassActive) {
            return;
        }

        currentNoteTarget = NOTE_TARGET_NONE;

        if(!notePassDirty && sustainCompositeShader == null) {
            notePassActive = false;
            return;
        }

        ensureNoteTargets();

        if(FlxG.renderTile) {
            if(regularPassDirty) {
                regularNoteBuffer.fillRect(noteLayerRect, FlxColor.TRANSPARENT);
                regularNoteBuffer.draw(regularNoteLayer);
            }

            if(sustainPassDirty) {
                sustainNoteBuffer.fillRect(noteLayerRect, FlxColor.TRANSPARENT);
                sustainNoteBuffer.draw(sustainNoteLayer);
            }

            if(regularPassDirty || sustainPassDirty || sustainCompositeShader != null) {
                noteCompositePending = true;
            }
        }

        if(FlxG.renderBlit) {
            if(regularPassDirty || sustainPassDirty || sustainCompositeShader != null) {
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

        currentNoteTarget = shouldSeparateSustainPass() ? (isSustainNote ? NOTE_TARGET_SUSTAIN : NOTE_TARGET_REGULAR) : NOTE_TARGET_NONE;
        if(currentNoteTarget != NOTE_TARGET_NONE) {
            notePassDirty = true;
            if(currentNoteTarget == NOTE_TARGET_REGULAR) {
                regularPassDirty = true;
            } else if(currentNoteTarget == NOTE_TARGET_SUSTAIN) {
                sustainPassDirty = true;
            }
        }
    }

    public function endNoteSpriteDraw():Void {
        currentNoteTarget = NOTE_TARGET_NONE;
    }

    public function setSustainCompositeShader(shader:FlxShader):Void {
        sustainCompositeShader = shader;
    }

    public function clearSustainCompositeShader():Void {
        sustainCompositeShader = null;
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

            if(FlxG.renderBlit) {
                drawPixelsToNoteBuffer(getTargetBuffer(), pixels, matrix, blend, smoothing);
            } else {
                drawPixelsToNoteLayer(getTargetGraphics(), frame, matrix, transform, blend, smoothing, shader);
            }
            return;
        }

        super.drawPixels(frame, pixels, matrix, transform, blend, smoothing, shader);
    }

    override function copyPixels(?frame:FlxFrame, ?pixels:BitmapData, ?sourceRect:Rectangle, destPoint:openfl.geom.Point, ?transform:ColorTransform, ?blend:BlendMode,
        ?smoothing:Bool = false, ?shader:FlxShader):Void {
        if(currentNoteTarget != NOTE_TARGET_NONE) {
            ensureNoteTargets();

            if(FlxG.renderBlit) {
                copyPixelsToNoteBuffer(getTargetBuffer(), pixels, sourceRect, destPoint, blend, smoothing);
            } else {
                copyPixelsToNoteLayer(getTargetGraphics(), frame, destPoint, transform, blend, smoothing, shader);
            }
            return;
        }

        super.copyPixels(frame, pixels, sourceRect, destPoint, transform, blend, smoothing, shader);
    }

    override function update(elapsed:Float) {
        super.update(elapsed);

        ensureNoteTargets();
    }

    override function render():Void {
        super.render();

        if(FlxG.renderTile && noteCompositePending) {
            drawNoteBuffersToCanvas();
            noteCompositePending = false;
        }

        if(sustainCompositeShader != null) {
            configureExternalNoteShaderSamplers();
        }
    }

    override function destroy() {
        regularNoteBuffer = FlxDestroyUtil.dispose(regularNoteBuffer);
        sustainNoteBuffer = FlxDestroyUtil.dispose(sustainNoteBuffer);
        regularNoteLayer = null;
        sustainNoteLayer = null;
        blitSustainShape = null;
        noteLayerRect = null;
        sustainCompositeShader = null;

        super.destroy();
    }

    private function ensureNoteTargets():Void {
        var targetWidth:Int = Std.int(width);
        var targetHeight:Int = Std.int(height);

        if(targetWidth <= 0 || targetHeight <= 0) {
            return;
        }

        if(regularNoteBuffer == null || regularNoteBuffer.width != targetWidth || regularNoteBuffer.height != targetHeight) {
            regularNoteBuffer = FlxDestroyUtil.dispose(regularNoteBuffer);
            regularNoteBuffer = new BitmapData(targetWidth, targetHeight, true, FlxColor.TRANSPARENT);
        }

        if(sustainNoteBuffer == null || sustainNoteBuffer.width != targetWidth || sustainNoteBuffer.height != targetHeight) {
            sustainNoteBuffer = FlxDestroyUtil.dispose(sustainNoteBuffer);
            sustainNoteBuffer = new BitmapData(targetWidth, targetHeight, true, FlxColor.TRANSPARENT);
        }

        noteLayerRect.setTo(0, 0, targetWidth, targetHeight);
    }

    private inline function getTargetBuffer():BitmapData {
        return currentNoteTarget == NOTE_TARGET_SUSTAIN ? sustainNoteBuffer : regularNoteBuffer;
    }

    private inline function getTargetGraphics():Graphics {
        return currentNoteTarget == NOTE_TARGET_SUSTAIN ? sustainNoteLayer.graphics : regularNoteLayer.graphics;
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
            _helperMatrix.translate(-viewOffsetX, -viewOffsetY);
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
            _helperPoint.x = destPoint.x - Std.int(viewOffsetX);
            _helperPoint.y = destPoint.y - Std.int(viewOffsetY);
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

    private function drawNoteBuffersToMainBuffer():Void {
        if(regularNoteBuffer == null && sustainNoteBuffer == null) {
            return;
        }

        if(regularNoteBuffer != null) {
            buffer.copyPixels(regularNoteBuffer, noteLayerRect, _flashPoint, null, null, true);
        }

        if(sustainNoteBuffer != null) {
            buffer.copyPixels(sustainNoteBuffer, noteLayerRect, _flashPoint, null, null, true);
        }
    }

    private function drawNoteBuffersToCanvas():Void {
        if(regularNoteBuffer == null && sustainNoteBuffer == null) {
            return;
        }

        if(regularNoteBuffer != null) {
            canvas.graphics.overrideBlendMode(null);
            _helperMatrix.identity();
            canvas.graphics.beginBitmapFill(regularNoteBuffer, _helperMatrix, false, antialiasing);
            canvas.graphics.drawRect(0, 0, noteLayerRect.width, noteLayerRect.height);
            canvas.graphics.endFill();
        }

        if(sustainNoteBuffer != null) {
            canvas.graphics.overrideBlendMode(null);
            _helperMatrix.identity();
            canvas.graphics.beginBitmapFill(sustainNoteBuffer, _helperMatrix, false, antialiasing);
            canvas.graphics.drawRect(0, 0, noteLayerRect.width, noteLayerRect.height);
            canvas.graphics.endFill();
        }
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

    private function configureExternalNoteShaderSamplers():Void {
        var shader:Dynamic = sustainCompositeShader;
        var regularField:Dynamic = Reflect.field(shader.data, "regularBitmap");
        var sustainField:Dynamic = Reflect.field(shader.data, "sustainBitmap");

        if(regularField != null) {
            Reflect.setProperty(regularField, "input", regularNoteBuffer);
        }

        if(sustainField != null) {
            Reflect.setProperty(sustainField, "input", sustainNoteBuffer);
        }
    }
}
