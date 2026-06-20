package;

import animate.FlxAnimateFrames;
import animate.FlxAnimateFrames.SpritemapInput;
import flixel.graphics.frames.FlxFramesCollection;
import haxe.Json;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;

#if sys
import sys.FileSystem;
#end

using StringTools;

/**
 * Compatibility loader for older Adobe Animate/CS-style atlas JSON exports.
 *
 * The flixel-animate fork understands most long-form keys already, but these
 * exports tend to rely on graphic-symbol timelines. Normalizing the JSON and
 * loading it through the raw-input path lets us patch that behavior without
 * editing the haxelib source.
 */
class Cs4AtlasCompat
{
  static inline var CACHE_SUFFIX:String = ":cs4compat:v2";

  public static function loadIfNeeded(directory:String, ?settings:Dynamic):Null<FlxFramesCollection>
  {
    var animationPath:String = '$directory/Animation.json';
    var raw:String = Paths.readText(animationPath);
    if (!isLegacyAnimation(raw)) return null;

    var spritemaps:Array<SpritemapInput> = loadSpritemaps(directory);
    if (spritemaps.length <= 0)
    {
      trace('[CS4 Compat] Skipping "$directory": no spritemaps were found.');
      return null;
    }

    var stats:Cs4AtlasCompatStats = {
      symbols: 0,
      frames: 0,
      symbolInstances: 0,
      atlasInstances: 0,
      graphicInstances: 0
    };
    var normalized:String = normalizeAnimation(raw, stats);
    var compatSettings:Dynamic = cloneSettings(settings);

    trace('[CS4 Compat] Loading "$directory" with ${spritemaps.length} spritemap(s), ${stats.symbols} symbol(s), ${stats.frames} frame(s), ${stats.symbolInstances} symbol instance(s), ${stats.graphicInstances} graphic instance(s).');
    return FlxAnimateFrames.fromAnimate(normalized, spritemaps, null, '$directory$CACHE_SUFFIX', false, compatSettings);
  }

  public static function isLegacyAnimation(raw:String):Bool
  {
    if (raw == null || raw.trim() == "") return false;

    try
    {
      var json:Dynamic = Json.parse(raw);
      return Reflect.hasField(json, "ANIMATION") || Reflect.hasField(json, "SYMBOL_DICTIONARY");
    }
    catch (e:Dynamic)
    {
      return false;
    }
  }

  static function normalizeAnimation(raw:String, stats:Cs4AtlasCompatStats):String
  {
    var json:Dynamic = Json.parse(raw);

    var animation:Dynamic = readObjectField(json, ["AN", "ANIMATION"]);
    if (animation != null)
    {
      Reflect.setField(json, "AN", animation);
      normalizeAnimationBlock(animation, stats);
    }

    var dictionary:Dynamic = readObjectField(json, ["SD", "SYMBOL_DICTIONARY"]);
    if (dictionary != null)
    {
      var symbols:Dynamic = readObjectField(dictionary, ["S", "Symbols"]);
      if (symbols != null)
      {
        Reflect.setField(dictionary, "S", symbols);
        Reflect.setField(json, "SD", dictionary);

        if (Std.isOfType(symbols, Array))
        {
          for (symbol in (symbols:Array<Dynamic>))
          {
            stats.symbols++;
            normalizeSymbol(symbol, stats);
          }
        }
      }
    }

    var metadata:Dynamic = readObjectField(json, ["MD", "metadata"]);
    if (metadata != null)
    {
      Reflect.setField(json, "MD", metadata);
      normalizeMetadata(metadata);
    }

    return Json.stringify(json);
  }

  static function normalizeAnimationBlock(animation:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    copyField(animation, "N", ["name"]);
    copyField(animation, "SN", ["SYMBOL_name"]);

    var stageInstance:Dynamic = readObjectField(animation, ["STI", "StageInstance"]);
    if (stageInstance != null)
    {
      var symbolInstance:Dynamic = readObjectField(stageInstance, ["SI", "SYMBOL_Instance"]);
      if (symbolInstance != null)
      {
        Reflect.setField(stageInstance, "SI", symbolInstance);
        normalizeSymbolInstance(symbolInstance, stats);
      }

      Reflect.setField(animation, "STI", stageInstance);
    }

    var timeline:Dynamic = readObjectField(animation, ["TL", "TIMELINE"]);
    if (timeline != null)
    {
      Reflect.setField(animation, "TL", timeline);
      normalizeTimeline(timeline, stats);
    }
  }

  static function normalizeSymbol(symbol:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    copyField(symbol, "SN", ["SYMBOL_name"]);

    var timeline:Dynamic = readObjectField(symbol, ["TL", "TIMELINE"]);
    if (timeline != null)
    {
      Reflect.setField(symbol, "TL", timeline);
      normalizeTimeline(timeline, stats);
    }
  }

  static function normalizeTimeline(timeline:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    var layers:Dynamic = readObjectField(timeline, ["L", "LAYERS"]);
    if (layers == null) return;

    Reflect.setField(timeline, "L", layers);
    if (!Std.isOfType(layers, Array)) return;

    for (layer in (layers:Array<Dynamic>))
    {
      normalizeLayer(layer, stats);
    }
  }

  static function normalizeLayer(layer:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    copyField(layer, "LN", ["Layer_name"]);
    copyField(layer, "LT", ["Layer_type"]);
    copyField(layer, "Clpb", ["Clipped_by"]);

    var frames:Dynamic = readObjectField(layer, ["FR", "Frames"]);
    if (frames == null) return;

    Reflect.setField(layer, "FR", frames);
    if (!Std.isOfType(frames, Array)) return;

    for (frame in (frames:Array<Dynamic>))
    {
      normalizeFrame(frame, stats);
    }
  }

  static function normalizeFrame(frame:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    stats.frames++;
    copyField(frame, "I", ["index"]);
    copyField(frame, "DU", ["duration"]);
    copyField(frame, "N", ["name"]);
    copyField(frame, "B", ["blend"]);

    var elements:Dynamic = readObjectField(frame, ["E", "elements"]);
    if (elements == null) return;

    Reflect.setField(frame, "E", elements);
    if (!Std.isOfType(elements, Array)) return;

    for (element in (elements:Array<Dynamic>))
    {
      normalizeElement(element, stats);
    }
  }

  static function normalizeElement(element:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    var symbolInstance:Dynamic = readObjectField(element, ["SI", "SYMBOL_Instance"]);
    if (symbolInstance != null)
    {
      Reflect.setField(element, "SI", symbolInstance);
      normalizeSymbolInstance(symbolInstance, stats);
    }

    var atlasInstance:Dynamic = readObjectField(element, ["ASI", "ATLAS_SPRITE_instance"]);
    if (atlasInstance != null)
    {
      stats.atlasInstances++;
      Reflect.setField(element, "ASI", atlasInstance);
      normalizeAtlasInstance(atlasInstance);
    }

    var textInstance:Dynamic = readObjectField(element, ["TFI", "textFIELD_Instance"]);
    if (textInstance != null)
    {
      Reflect.setField(element, "TFI", textInstance);
      normalizeTextInstance(textInstance);
    }
  }

  static function normalizeSymbolInstance(instance:Dynamic, stats:Cs4AtlasCompatStats):Void
  {
    stats.symbolInstances++;
    copyField(instance, "SN", ["SYMBOL_name"]);
    copyField(instance, "FF", ["firstFrame"]);
    copyField(instance, "TRP", ["transformationPoint"]);
    copyField(instance, "MX", ["Matrix"]);
    copyField(instance, "B", ["blend"]);
    copyField(instance, "C", ["color"]);
    copyField(instance, "F", ["filters"]);

    var symbolType:String = readStringFields(instance, ["ST", "symbolType"], "");
    if (symbolType != "")
    {
      var normalizedType:String = normalizeSymbolType(symbolType);
      var lowerType:String = symbolType.toLowerCase();
      if (lowerType == "graphic" || lowerType == "g")
        stats.graphicInstances++;

      Reflect.setField(instance, "ST", normalizedType);
    }

    var loopType:String = readStringFields(instance, ["LP", "loop"], "");
    if (loopType != "")
    {
      Reflect.setField(instance, "LP", normalizeLoopType(loopType));
    }
  }

  static function normalizeAtlasInstance(instance:Dynamic):Void
  {
    copyField(instance, "N", ["name"]);
    copyField(instance, "MX", ["Matrix"]);
  }

  static function normalizeTextInstance(instance:Dynamic):Void
  {
    copyField(instance, "MX", ["Matrix"]);
  }

  static function normalizeMetadata(metadata:Dynamic):Void
  {
    copyField(metadata, "FRT", ["framerate"]);
    copyField(metadata, "W", ["width"]);
    copyField(metadata, "H", ["height"]);
    copyField(metadata, "BGC", ["backgroundColor"]);
  }

  static function normalizeSymbolType(symbolType:String):String
  {
    return switch (symbolType.toLowerCase())
    {
      case "b" | "button": "B";
      case "mc" | "movieclip": "MC";
      case "g" | "graphic": "G";
      default: symbolType;
    }
  }

  static function normalizeLoopType(loopType:String):String
  {
    return switch (loopType.toLowerCase())
    {
      case "po" | "playonce" | "play_once": "PO";
      case "sf" | "singleframe" | "single_frame": "SF";
      case "lp" | "loop": "LP";
      default: loopType;
    }
  }

  static function loadSpritemaps(directory:String):Array<SpritemapInput>
  {
    var jsonFiles:Array<String> = listSpritemapJsonFiles(directory);
    var spritemaps:Array<SpritemapInput> = [];

    for (jsonFile in jsonFiles)
    {
      var base:String = jsonFile.substr(0, jsonFile.length - ".json".length);
      var imagePath:String = findSpritemapImage(directory, base);
      if (imagePath == "") continue;

      var jsonText:String = Paths.readText('$directory/$jsonFile');
      if (jsonText == "") continue;

      var bitmap = Paths.loadBitmap(imagePath);
      if (bitmap == null) continue;

      spritemaps.push({
        source: bitmap,
        json: jsonText
      });
    }

    return spritemaps;
  }

  static function listSpritemapJsonFiles(directory:String):Array<String>
  {
    var files:Array<String> = [];

    #if sys
    if (FileSystem.exists(directory) && FileSystem.isDirectory(directory))
    {
      for (file in FileSystem.readDirectory(directory))
      {
        if (isSpritemapJson(file) && !files.contains(file)) files.push(file);
      }
    }
    #end

    var prefix:String = directory.endsWith("/") ? directory : '$directory/';
    for (asset in OpenFlAssets.list(AssetType.TEXT))
    {
      if (asset.startsWith(prefix))
      {
        var file:String = asset.substr(prefix.length);
        if (file.indexOf("/") < 0 && isSpritemapJson(file) && !files.contains(file)) files.push(file);
      }
    }

    files.sort(function(a, b) return compareSpritemaps(a, b));
    return files;
  }

  static function isSpritemapJson(file:String):Bool
  {
    return file != null && file.startsWith("spritemap") && file.endsWith(".json");
  }

  static function findSpritemapImage(directory:String, base:String):String
  {
    for (extension in ["png", "jpg", "jpeg"])
    {
      var path:String = '$directory/$base.$extension';
      if (Paths.assetExists(path, AssetType.IMAGE)) return path;
    }

    return "";
  }

  static function compareSpritemaps(a:String, b:String):Int
  {
    var ai:Int = spritemapIndex(a);
    var bi:Int = spritemapIndex(b);
    if (ai != bi) return ai - bi;
    return a < b ? -1 : (a > b ? 1 : 0);
  }

  static function spritemapIndex(file:String):Int
  {
    var raw:String = file.substr("spritemap".length);
    raw = raw.substr(0, raw.length - ".json".length);
    var parsed:Null<Int> = Std.parseInt(raw);
    return parsed == null ? 0 : parsed;
  }

  static function cloneSettings(settings:Dynamic):Dynamic
  {
    var result:Dynamic = {};
    if (settings == null) return result;

    if (Reflect.hasField(settings, "swfMode")) Reflect.setField(result, "swfMode", Reflect.field(settings, "swfMode"));
    if (Reflect.hasField(settings, "cacheOnLoad")) Reflect.setField(result, "cacheOnLoad", Reflect.field(settings, "cacheOnLoad"));
    if (Reflect.hasField(settings, "filterQuality")) Reflect.setField(result, "filterQuality", Reflect.field(settings, "filterQuality"));
    if (Reflect.hasField(settings, "onSymbolCreate")) Reflect.setField(result, "onSymbolCreate", Reflect.field(settings, "onSymbolCreate"));

    return result;
  }

  static function copyField(value:Dynamic, target:String, sources:Array<String>):Void
  {
    if (value == null || Reflect.hasField(value, target)) return;

    for (source in sources)
    {
      if (Reflect.hasField(value, source))
      {
        Reflect.setField(value, target, Reflect.field(value, source));
        return;
      }
    }
  }

  static function readObjectField(value:Dynamic, fields:Array<String>):Dynamic
  {
    if (value == null) return null;

    for (field in fields)
    {
      if (Reflect.hasField(value, field))
      {
        var result:Dynamic = Reflect.field(value, field);
        if (result != null) return result;
      }
    }

    return null;
  }

  static function readStringFields(value:Dynamic, fields:Array<String>, fallback:String):String
  {
    if (value == null) return fallback;

    for (field in fields)
    {
      if (!Reflect.hasField(value, field)) continue;

      var raw:Dynamic = Reflect.field(value, field);
      if (raw != null)
      {
        var result:String = Std.string(raw);
        if (result != "") return result;
      }
    }

    return fallback;
  }
}

typedef Cs4AtlasCompatStats =
{
  var symbols:Int;
  var frames:Int;
  var symbolInstances:Int;
  var atlasInstances:Int;
  var graphicInstances:Int;
}
