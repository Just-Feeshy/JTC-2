import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.graphics.frames.FlxAtlasFrames;
import flixel.graphics.frames.FlxFrame.FlxFrameAngle;
import flixel.graphics.frames.FlxFramesCollection;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import haxe.Json;

using StringTools;

typedef AtlasSpriteRegion = {
    var x:Float;
    var y:Float;
    var w:Float;
    var h:Float;
    var rotated:Bool;
}

typedef AtlasComposedFrame = {
    var name:String;
    var spriteName:String;
    var tx:Float;
    var ty:Float;
}

/**
 * Reads an Adobe Animate Texture Atlas (spritemap*.json + Animation.json) and
 * returns a flat FlxFramesCollection where each frame is named
 * `${symbolName}${frameIdx:0000}` so existing prefix-based animation playback
 * (FlxAnimationController.addByPrefix) keeps working.
 */
class AnimateAtlasLoader {
    public static function loadFromFolder(folder:String, ?library:String = "shared"):FlxFramesCollection {
        if(folder == null || folder == "") return null;
        var basePath:String = stripTrailingSlash(folder);

        var animationJsonPath:String = findFile(basePath, "Animation.json", library);
        if(animationJsonPath == null) return null;

        var animationRaw:String = Paths.readText(animationJsonPath);
        if(animationRaw == null || animationRaw.length == 0) return null;

        var animationData:Dynamic = null;
        try { animationData = Json.parse(animationRaw); } catch(e:Dynamic) { return null; }
        if(animationData == null) return null;

        var spriteIndex:Map<String, AtlasSpriteRegion> = new Map();
        var spriteOwner:Map<String, FlxAtlasFrames> = new Map();
        var spriteSourceSize:Map<String, FlxPoint> = new Map();
        var perAtlas:Array<FlxAtlasFrames> = [];

        var idx:Int = 1;
        while(true) {
            var jsonName:String = 'spritemap${idx}.json';
            var pngName:String = 'spritemap${idx}.png';
            var jsonPath:String = findFile(basePath, jsonName, library);
            var pngKey:String = '${basePath}/spritemap${idx}';
            var pngPath:String = Paths.getPath('images/${pngKey}.png', IMAGE, library);

            if(jsonPath == null && idx == 1) {
                jsonName = "spritemap.json";
                pngName = "spritemap.png";
                jsonPath = findFile(basePath, jsonName, library);
                pngKey = '${basePath}/spritemap';
                pngPath = Paths.getPath('images/${pngKey}.png', IMAGE, library);
            }

            if(jsonPath == null) break;
            if(!Paths.assetExists(pngPath, IMAGE)) break;

            var raw:String = Paths.readText(jsonPath);
            if(raw == null || raw.length == 0) break;

            var data:Dynamic = null;
            try { data = Json.parse(raw); } catch(e:Dynamic) { break; }
            if(data == null) break;

            var graphic:FlxGraphic = Paths.image(pngKey, library);
            if(graphic == null) break;

            var frames:FlxAtlasFrames = new FlxAtlasFrames(graphic);
            perAtlas.push(frames);
            indexSpritemap(data, frames, spriteIndex, spriteOwner, spriteSourceSize);

            idx++;
            if(idx > 32) break;
        }

        if(perAtlas.length == 0) return null;

        var composed:Array<AtlasComposedFrame> = composeFromAnimation(animationData);

        for(frame in composed) {
            var region:AtlasSpriteRegion = spriteIndex.get(frame.spriteName);
            var atlas:FlxAtlasFrames = spriteOwner.get(frame.spriteName);
            if(region == null || atlas == null) continue;

            var rect:FlxRect = FlxRect.get(region.x, region.y, region.w, region.h);
            var sourceSize:FlxPoint = FlxPoint.get(region.w, region.h);
            var offset:FlxPoint = FlxPoint.get(frame.tx, frame.ty);
            var angle:FlxFrameAngle = region.rotated ? FlxFrameAngle.ANGLE_NEG_90 : FlxFrameAngle.ANGLE_0;

            if(region.rotated) sourceSize.set(region.h, region.w);

            atlas.addAtlasFrame(rect, sourceSize, offset, frame.name, angle, false, false);
        }

        return perAtlas.length == 1 ? perAtlas[0] : FlxAnimationUtil.combineAtlas(cast perAtlas);
    }

    static function stripTrailingSlash(s:String):String {
        var v:String = s;
        while(v.length > 0 && (v.charAt(v.length - 1) == "/" || v.charAt(v.length - 1) == "\\")) {
            v = v.substr(0, v.length - 1);
        }
        return v;
    }

    static function findFile(basePath:String, name:String, library:String):String {
        var path:String = Paths.getPath('images/${basePath}/${name}', TEXT, library);
        if(Paths.assetExists(path, TEXT)) return path;
        return null;
    }

    static function indexSpritemap(data:Dynamic, frames:FlxAtlasFrames,
                                   index:Map<String, AtlasSpriteRegion>,
                                   owner:Map<String, FlxAtlasFrames>,
                                   sourceSize:Map<String, FlxPoint>):Void {
        var atlasNode:Dynamic = pick(data, ["ATLAS", "atlas"]);
        if(atlasNode == null) return;
        var spritesArr:Array<Dynamic> = pickArray(atlasNode, ["SPRITES", "sprites"]);
        if(spritesArr == null) return;

        for(entry in spritesArr) {
            var spr:Dynamic = pick(entry, ["SPRITE", "sprite"]);
            if(spr == null) spr = entry;
            if(spr == null) continue;

            var name:String = stringField(spr, ["name", "n", "N"]);
            if(name == null || name == "") continue;

            var region:AtlasSpriteRegion = {
                x: floatField(spr, ["x"]),
                y: floatField(spr, ["y"]),
                w: floatField(spr, ["w", "width"]),
                h: floatField(spr, ["h", "height"]),
                rotated: boolField(spr, ["rotated"])
            };

            if(region.w <= 0 || region.h <= 0) continue;

            index.set(name, region);
            owner.set(name, frames);
            sourceSize.set(name, FlxPoint.get(region.w, region.h));
        }
    }

    static function composeFromAnimation(data:Dynamic):Array<AtlasComposedFrame> {
        var out:Array<AtlasComposedFrame> = [];
        var dictionary:Dynamic = pick(data, ["SD", "SYMBOL_DICTIONARY"]);
        var symbols:Array<Dynamic> = dictionary == null ? null : pickArray(dictionary, ["S", "Symbols"]);

        if(symbols == null) {
            var an:Dynamic = pick(data, ["AN", "ANIMATION"]);
            if(an != null) {
                var stageName:String = stringField(an, ["STN", "SYMBOL_name", "SN"]);
                if(stageName == null || stageName == "") stageName = "animation";
                appendSymbolFrames(stageName, an, out);
            }
            return out;
        }

        for(symbol in symbols) {
            var symbolName:String = stringField(symbol, ["SN", "SYMBOL_name"]);
            if(symbolName == null || symbolName == "") continue;
            appendSymbolFrames(symbolName, symbol, out);
        }

        var an:Dynamic = pick(data, ["AN", "ANIMATION"]);
        if(an != null) {
            var stageName:String = stringField(an, ["STN", "SYMBOL_name", "SN"]);
            if(stageName != null && stageName != "") {
                appendSymbolFrames(stageName, an, out);
            }
        }

        return out;
    }

    static function appendSymbolFrames(symbolName:String, symbolNode:Dynamic, out:Array<AtlasComposedFrame>):Void {
        var timeline:Dynamic = pick(symbolNode, ["TL", "TIMELINE"]);
        if(timeline == null) return;
        var layers:Array<Dynamic> = pickArray(timeline, ["L", "LAYERS"]);
        if(layers == null || layers.length == 0) return;

        var maxIndex:Int = 0;
        for(layer in layers) {
            var fr:Array<Dynamic> = pickArray(layer, ["FR", "Frames"]);
            if(fr == null) continue;
            for(frame in fr) {
                var i:Int = intField(frame, ["I", "index"]);
                var du:Int = intField(frame, ["DU", "duration"]);
                if(du <= 0) du = 1;
                if(i + du > maxIndex) maxIndex = i + du;
            }
        }

        if(maxIndex <= 0) return;

        for(absIdx in 0...maxIndex) {
            var picked:{ spriteName:String, tx:Float, ty:Float } = null;

            for(li in 0...layers.length) {
                var layer:Dynamic = layers[li];
                var fr:Array<Dynamic> = pickArray(layer, ["FR", "Frames"]);
                if(fr == null) continue;

                var matchedFrame:Dynamic = null;
                for(frame in fr) {
                    var i:Int = intField(frame, ["I", "index"]);
                    var du:Int = intField(frame, ["DU", "duration"]);
                    if(du <= 0) du = 1;
                    if(absIdx >= i && absIdx < i + du) {
                        matchedFrame = frame;
                        break;
                    }
                }
                if(matchedFrame == null) continue;

                var elements:Array<Dynamic> = pickArray(matchedFrame, ["E", "elements"]);
                if(elements == null) continue;

                for(elem in elements) {
                    var asi:Dynamic = pick(elem, ["ASI", "ATLAS_SPRITE_instance"]);
                    if(asi == null) continue;

                    var spriteName:String = stringField(asi, ["N", "name"]);
                    if(spriteName == null || spriteName == "") continue;

                    var matrix:Array<Dynamic> = pickArray(asi, ["M3D", "Matrix3D"]);
                    var tx:Float = 0;
                    var ty:Float = 0;
                    if(matrix != null && matrix.length >= 14) {
                        tx = numberToFloat(matrix[12]);
                        ty = numberToFloat(matrix[13]);
                    } else {
                        var pos:Dynamic = pick(asi, ["Pos", "Position"]);
                        if(pos != null) {
                            tx = floatField(pos, ["x"]);
                            ty = floatField(pos, ["y"]);
                        }
                    }

                    picked = { spriteName: spriteName, tx: tx, ty: ty };
                    break;
                }

                if(picked != null) break;
            }

            if(picked == null) continue;

            out.push({
                name: symbolName + zeroPad(absIdx, 4),
                spriteName: picked.spriteName,
                tx: picked.tx,
                ty: picked.ty
            });
        }
    }

    static function zeroPad(value:Int, width:Int):String {
        var s:String = Std.string(value);
        while(s.length < width) s = "0" + s;
        return s;
    }

    static function pick(obj:Dynamic, keys:Array<String>):Dynamic {
        if(obj == null) return null;
        for(k in keys) {
            var v:Dynamic = Reflect.field(obj, k);
            if(v != null) return v;
        }
        return null;
    }

    static function pickArray(obj:Dynamic, keys:Array<String>):Array<Dynamic> {
        var v:Dynamic = pick(obj, keys);
        if(v == null) return null;
        if(Std.isOfType(v, Array)) return cast v;
        return null;
    }

    static function stringField(obj:Dynamic, keys:Array<String>):String {
        var v:Dynamic = pick(obj, keys);
        if(v == null) return null;
        return Std.string(v);
    }

    static function intField(obj:Dynamic, keys:Array<String>):Int {
        var v:Dynamic = pick(obj, keys);
        if(v == null) return 0;
        if(Std.isOfType(v, Int)) return cast v;
        if(Std.isOfType(v, Float)) return Std.int(cast(v, Float));
        return Std.parseInt(Std.string(v));
    }

    static function floatField(obj:Dynamic, keys:Array<String>):Float {
        var v:Dynamic = pick(obj, keys);
        if(v == null) return 0;
        return numberToFloat(v);
    }

    static function boolField(obj:Dynamic, keys:Array<String>):Bool {
        var v:Dynamic = pick(obj, keys);
        if(v == null) return false;
        if(Std.isOfType(v, Bool)) return cast v;
        var s:String = Std.string(v).toLowerCase();
        return s == "true" || s == "1";
    }

    static function numberToFloat(v:Dynamic):Float {
        if(v == null) return 0;
        if(Std.isOfType(v, Float)) return cast v;
        if(Std.isOfType(v, Int)) return cast(v, Int);
        var f:Float = Std.parseFloat(Std.string(v));
        return Math.isNaN(f) ? 0 : f;
    }

    public static function listSymbolNames(folder:String, ?library:String = "shared"):Array<String> {
        var out:Array<String> = [];
        if(folder == null || folder == "") return out;
        var basePath:String = stripTrailingSlash(folder);

        var animationJsonPath:String = findFile(basePath, "Animation.json", library);
        if(animationJsonPath == null) return out;

        var raw:String = Paths.readText(animationJsonPath);
        if(raw == null || raw.length == 0) return out;

        var data:Dynamic = null;
        try { data = Json.parse(raw); } catch(e:Dynamic) { return out; }
        if(data == null) return out;

        var dictionary:Dynamic = pick(data, ["SD", "SYMBOL_DICTIONARY"]);
        var symbols:Array<Dynamic> = dictionary == null ? null : pickArray(dictionary, ["S", "Symbols"]);
        if(symbols != null) {
            for(symbol in symbols) {
                var symbolName:String = stringField(symbol, ["SN", "SYMBOL_name"]);
                if(symbolName != null && symbolName != "") out.push(symbolName);
            }
        }

        var an:Dynamic = pick(data, ["AN", "ANIMATION"]);
        if(an != null) {
            var stageName:String = stringField(an, ["STN", "SYMBOL_name", "SN"]);
            if(stageName != null && stageName != "" && out.indexOf(stageName) < 0) out.push(stageName);
        }

        return out;
    }
}
