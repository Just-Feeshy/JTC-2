package;

#if (USING_LUA && cpp)
import llua.Lua;
import llua.LuaL;
import llua.State;
import llua.Convert;
#end

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxCamera;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.util.FlxGradient;
import flixel.util.FlxColor;
import flixel.math.FlxRect;
import flixel.text.FlxText;
import flixel.system.FlxSound;
import flixel.graphics.frames.FlxFramesCollection;
import feshixl.shaders.FeshShader;
import openfl.display.BitmapData;
import openfl.display.GradientType;
import openfl.display.InterpolationMethod;
import openfl.display.Shape;
import openfl.filters.BlurFilter;
import openfl.filters.BitmapFilter;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.ShaderFilter;
import openfl.display.SpreadMethod;
import openfl.geom.Matrix;
import openfl.geom.Point as OpenFlPoint;
import openfl.utils.Assets as OpenFlAssets;
import openfl.geom.Rectangle as OpenFlRectangle;
import lime.graphics.opengl.GL;
import lime.graphics.Image;
import lime.math.Rectangle;
import lime.ui.Window;
import lime.utils.Log;

#if sys
import sys.FileSystem;
import sys.io.File;
#end

import SaveData.SaveType;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

using StringTools;

typedef LuaShaderSource = {
    var vertexSource:String;
    var fragmentSource:String;
}

/**
* Honestly, modcharts are my least concern, since this is mostly object-orientated based.
*/

class ModLua {
    private static var sharedVariables:Map<String, Dynamic> = new Map<String, Dynamic>();
    private var executed:Bool = false;

    #if (USING_LUA && cpp)
    private var lua:State = null;
    #end

    public var luaScript(default, null):String;

    public var luaTexts(default, null):Map<String, FlxText> = new Map<String, FlxText>();
    public var luaSprites(default, null):Map<String, FlxSprite> = new Map<String, FlxSprite>();
    public var luaCameras(default, null):Map<String, FlxCamera> = new Map<String, FlxCamera>();
    public var luaTweens(default, null):Map<String, FlxTween> = new Map<String, FlxTween>();
    public var luaSounds(default, null):Map<String, FlxSound> = new Map<String, FlxSound>();
    public var luaShaderSources(default, null):Map<String, LuaShaderSource> = new Map<String, LuaShaderSource>();
    public var luaShaders(default, null):Map<String, FeshShader> = new Map<String, FeshShader>();
    public var luaCameraShaderFilters(default, null):Map<String, ShaderFilter> = new Map<String, ShaderFilter>();
	public var luaBitmaps(default, null):Map<String, BitmapData> = new Map<String, BitmapData>();
	public var luaFrameCollections(default, null):Map<String, FlxFramesCollection> = new Map<String, FlxFramesCollection>();

    public var closed:Bool = false;

    public function new(luaScript:String) {
        this.luaScript = luaScript;
    }

    public function execute() {
        if(!executed) {
            executed = true;
        }else {
            return;
        }

        #if (USING_LUA && cpp)
        lua = LuaL.newstate();
		LuaL.openlibs(lua);
		Lua.init_callbacks(lua);

        var resultFile:Dynamic = LuaL.dofile(lua, luaScript);
		var luaResults:String = Lua.tostring(lua, resultFile);

        if(luaResults != null && resultFile != 0) {
            var prevWindow:Window = openfl.Lib.current.stage.window;
            new CrashLogDisplay(prevWindow).attachReport([luaResults, 'Script: $luaScript']);
            return;
        }

        trace("Successfully loaded script: " + this.luaScript);

        set("glslVersion", GL.VERSION);

        set("windowWidth", FlxG.width);
        set("windowHeight", FlxG.height);

        set("inRapBattle", false);

        set('curBpm', Conductor.bpm);

        set('crochet', Conductor.crochet);
        set('stepCrochet', Conductor.stepCrochet);
		set('crochetPitch', 0.0011 #if FLX_PITCH / FlxG.sound.music.pitch #end);

        set('getCwd', Sys.getCwd());

        #if debug
        set("inDebug", true);
        #else
        set("inDebug", false);
        #end

		Lua_helper.add_callback(lua, "getImageWidth", function(path:String) {
		    var image = Image.fromFile(Paths.getPath('images/$path.png', IMAGE, ""));
			return image.width;
		});

		Lua_helper.add_callback(lua, "getImageHeight", function(path:String) {
		    var image = Image.fromFile(Paths.getPath('images/$path.png', IMAGE, ""));
			return image.height;
		});

		Lua_helper.add_callback(lua, "createBitmapData", function(name:String, width:Int, height:Int) {
		    if(luaBitmaps.exists(name)) {
		        return;
		    }

		    var bmp:BitmapData = new BitmapData(width, height, true, 0x00000000);
		    luaBitmaps.set(name, bmp);
		});

		Lua_helper.add_callback(lua, "fillBitmapData", function(name:String, colorStr:String = "0x00000000") {
		    var bmp:BitmapData = luaBitmaps.get(name);

		    if(bmp == null) {
		        return;
		    }

		    bmp.fillRect(bmp.rect, parseLuaColor(colorStr));
		});

		Lua_helper.add_callback(lua, "makeBitmapSectorGraphic", function(name:String, radius:Float, startAngle:Float, endAngle:Float, colorStr:String, segments:Int = 48) {
		    if(radius <= 0) {
		        return;
		    }

		    luaBitmaps.set(name, createSectorBitmapData(radius, startAngle, endAngle, parseLuaColor(colorStr), segments));
		});

		Lua_helper.add_callback(lua, "makeBitmapGradientSectorGraphic", function(name:String, radius:Float, startAngle:Float, endAngle:Float, colors:String, segments:Int = 48) {
		    if(radius <= 0) {
		        return;
		    }

		    var gradientColors:Array<Int> = parseLuaColorArray(colors);

		    if(gradientColors.length == 0) {
		        return;
		    }

		    luaBitmaps.set(name, createSectorGradientBitmapData(radius, startAngle, endAngle, gradientColors, segments));
		});

		Lua_helper.add_callback(lua, "makeBitmapSoftSectorGraphic", function(name:String, radius:Float, startAngle:Float, endAngle:Float, colorStr:String = "0xFFFFFFFF", edgePercent:Float = 0.35, steps:Int = 24, segments:Int = 48) {
		    if(radius <= 0) {
		        return;
		    }

		    luaBitmaps.set(name, createSoftSectorBitmapData(radius, startAngle, endAngle, parseLuaColor(colorStr), edgePercent, steps, segments));
		});

		Lua_helper.add_callback(lua, "drawBitmapData", function(target:String, source:String, x:Float = 0, y:Float = 0) {
		    var targetBitmap:BitmapData = luaBitmaps.get(target);
		    var sourceBitmap:BitmapData = resolveShaderBitmap(source);

		    if(targetBitmap == null || sourceBitmap == null) {
		        return;
		    }

		    var matrix:Matrix = new Matrix();
		    matrix.translate(x, y);
		    targetBitmap.draw(sourceBitmap, matrix, null, null, null, true);
		});

		Lua_helper.add_callback(lua, "stampBitmapMask", function(target:String, source:String, mask:String, x:Float = 0, y:Float = 0) {
		    var targetBitmap:BitmapData = luaBitmaps.get(target);
		    var sourceBitmap:BitmapData = resolveShaderBitmap(source);
		    var maskBitmap:BitmapData = resolveShaderBitmap(mask);

		    if(targetBitmap == null || sourceBitmap == null || maskBitmap == null) {
		        return;
		    }

		    var destX:Int = Std.int(Math.floor(x));
		    var destY:Int = Std.int(Math.floor(y));
		    var left:Int = Std.int(Math.max(destX, 0));
		    var top:Int = Std.int(Math.max(destY, 0));
		    var right:Int = Std.int(Math.min(destX + maskBitmap.width, targetBitmap.width));
		    var bottom:Int = Std.int(Math.min(destY + maskBitmap.height, targetBitmap.height));

		    if(right <= left || bottom <= top) {
		        return;
		    }

		    var sourceRect = new OpenFlRectangle(left, top, right - left, bottom - top);
		    var destPoint = new OpenFlPoint(left, top);
		    var alphaPoint = new OpenFlPoint(left - destX, top - destY);
		    targetBitmap.copyPixels(sourceBitmap, sourceRect, destPoint, maskBitmap, alphaPoint, true);
		});

		Lua_helper.add_callback(lua, "createCombinedFrames", function(name:String, first:String, second:String, type1:String, type2:String) {
		    var firstFrames:FlxFramesCollection;
			var secondFrames:FlxFramesCollection;

            switch(type1.toLowerCase().trim()) {
                case "packer" | "packeratlas" | "pac":
                    firstFrames = Paths.getPackerAtlas(first);
                default:
                    firstFrames = Paths.getSparrowAtlas(first);
            }

			switch(type2.toLowerCase().trim()) {
				case "packer" | "packeratlas" | "pac":
					secondFrames = Paths.getPackerAtlas(second);
				default:
					secondFrames = Paths.getSparrowAtlas(second);
		    }

			var combinedFrames = feshixl.FeshSprite.twoInOneFrames(firstFrames, secondFrames);

			//firstFrames.destroy();
			//secondFrames.destroy();

			luaFrameCollections.set(name, combinedFrames);
		});

		Lua_helper.add_callback(lua, "addFramesToSprite", function(name:String, frameName:String) {
		    var spr:FlxSprite = getSprite(name);
			var frames:FlxFramesCollection = luaFrameCollections.get(frameName);

			if(spr == null || frames == null) {
				return;
			}

			spr.frames = frames;
		});

		Lua_helper.add_callback(lua, "loadBitmapData", function(name:String, path:String, x:Int, y:Int) {
		    var bmp:BitmapData = luaBitmaps.get(name);

		    if(bmp == null) {
		        return;
		    }

		    var image = Image.fromFile(Paths.getPath('images/$path.png', IMAGE, ""));

			{ // I want to make this confusing as possible lmao.
				var imgBytes = image.getPixels(new Rectangle(0, 0, image.width, image.height));
				bmp.setPixels(new OpenFlRectangle(x, y, image.width, image.height), imgBytes);
			}
		});

        Lua_helper.add_callback(lua, "createSprite", function(name:String) {
            if(luaSprites.exists(name)) {
                return;
            }

            var sprite:FlxSprite = new FlxSprite();
            sprite.antialiasing = SaveData.getData(SaveType.GRAPHICS);
            sprite.active = true;

            luaSprites.set(name, sprite);
        });

        Lua_helper.add_callback(lua, "createGradientSprite", function(name:String, width:Int, height:Int, colors:String) {
            if(luaSprites.exists(name)) {
                return;
            }

            colors = colors.trim();

            if(colors.substring(0, 1) == "[") {
                colors = colors.substring(1, colors.length);
            }

            if(colors.substring(colors.length - 1, colors.length) == "]") {
                colors = colors.substring(0, colors.length - 1);
            }

            var colorStrArray:Array<String> = colors.split(',');
            var colorArray:Array<Int> = [];

            var index:Int = 0;

			while(index < colorStrArray.length) {
				colorArray.push(Std.parseInt(colorStrArray[index].trim()));
                index++;
			}

            var sprite:FlxSprite = FlxGradient.createGradientFlxSprite(width, height, colorArray, 1);
            sprite.antialiasing = SaveData.getData(SaveType.GRAPHICS);
            sprite.active = true;

            luaSprites.set(name, sprite);
        });

        Lua_helper.add_callback(lua, "spriteExist", function(name:String) {
            if(getSprite(name) == null)
                return false;

            return true;
        });

        Lua_helper.add_callback(lua, "scaleSprite", function(name:String, x:Float, y:Float, shouldUpdateHitbox:Bool = true) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.scale.set(x, y);

            if(shouldUpdateHitbox) {
                spr.updateHitbox();
            }
        });

        Lua_helper.add_callback(lua, "loadGraphic", function(name:String, image:String, gridX:Int = 0, gridY:Int = 0) {
			var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

			var animated = gridX !=0 || gridY !=0;

			if(image != null && image.trim().length > 0) {
                image = image.split('.')[0];
				spr.loadGraphic(Paths.image(image), animated, gridX, gridY);
			}
		});

        Lua_helper.add_callback(lua, "loadSpriteBitmapData", function(name:String, bitmapName:String) {
			var spr:FlxSprite = getSprite(name);
            var bmp:BitmapData = luaBitmaps.get(bitmapName);

            if(spr == null || bmp == null) {
                return;
            }

            spr.pixels = bmp;
            spr.dirty = true;
            spr.updateHitbox();
		});

        Lua_helper.add_callback(lua, "makeGraphic", function(name:String, width:Int, height:Int, colorStr:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                var color:Int = parseLuaColor(colorStr);

                spr.makeGraphic(width, height, color);
            }
		});

        Lua_helper.add_callback(lua, "makeSectorGraphic", function(name:String, radius:Float, startAngle:Float, endAngle:Float, colorStr:String, segments:Int = 48) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null || radius <= 0) {
                return;
            }

            spr.loadGraphic(createSectorBitmapData(radius, startAngle, endAngle, parseLuaColor(colorStr), segments));
            spr.updateHitbox();
        });

        Lua_helper.add_callback(lua, "makeGradientSectorGraphic", function(name:String, radius:Float, startAngle:Float, endAngle:Float, colors:String, segments:Int = 48) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null || radius <= 0) {
                return;
            }

            var gradientColors:Array<Int> = parseLuaColorArray(colors);

            if(gradientColors.length == 0) {
                return;
            }

            spr.loadGraphic(createSectorGradientBitmapData(radius, startAngle, endAngle, gradientColors, segments));
            spr.updateHitbox();
        });

        Lua_helper.add_callback(lua, "screenCenter", function(name:String, ?axis:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            switch(axis.toLowerCase()) {
                case "x": spr.screenCenter(X);
                case "y": spr.screenCenter(Y);
                default: spr.screenCenter();
            }
		});

        Lua_helper.add_callback(lua, "getScreenCenter", function(name:String, ?axis:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                switch(axis.toLowerCase()) {
                    case "x": return spr.getScreenCenter(X);
                    case "y": return spr.getScreenCenter(Y);
                }
            }

            return 0;
		});

        Lua_helper.add_callback(lua, "compileSpriteSheet", function(name:String, spritesheet:String, type:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            switch(type.toLowerCase().trim()) {
                case "packer" | "packeratlas" | "pac":
                    spr.frames = Paths.getPackerAtlas(spritesheet);
                default:
                    spr.frames = Paths.getSparrowAtlas(spritesheet);
            }
        });

		Lua_helper.add_callback(lua, "addAnimationByPrefix", function(name:String, animation:String, prefix:String, framerate:Int = 24, loop:Bool = true) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            /**
            * While making this, I was using an older version of `HaxeFlixel`.
            */
            @:privateAccess
            if(spr.animation._animations.exists(animation)) {
                spr.animation.remove(animation);
            }

            spr.animation.addByPrefix(animation, prefix, framerate, loop);
		});

		Lua_helper.add_callback(lua, "removeAnimationPrefix", function(name:String, animation:String) {
				var spr:FlxSprite = getSprite(name);

				if(spr == null) {
				    return;
				}

				/**
				* While making this, I was using an older version of `HaxeFlixel`.
				*/
				@:privateAccess
				if(spr.animation._animations.exists(animation)) {
				    spr.animation.remove(animation);
				}
		});

        Lua_helper.add_callback(lua, "playAnimationByPrefix", function(name:String, animation:String, prefix:String, framerate:Int = 24, loop:Bool = true) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            /**
            * While making this, I was using an older version of `HaxeFlixel`.
            */
            @:privateAccess
            if(spr.animation._animations.exists(animation)) {
                spr.animation.remove(animation);
            }

            spr.animation.addByPrefix(animation, prefix, framerate, loop);
            spr.animation.play(animation);
        });

		Lua_helper.add_callback(lua, "addAnimationByIndices", function(name:String, animation:String, prefix:String, indices:String, framerate:Int = 24) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            /**
            * While making this, I was using an older version of `HaxeFlixel`.
            */
            @:privateAccess
            if(spr.animation._animations.exists(animation)) {
                spr.animation.remove(animation);
            }

            indices = indices.trim();

            if(indices.substring(0, 1) == "[") {
                indices = indices.substring(1, indices.length);
            }

            if(indices.substring(indices.length - 1, indices.length) == "]") {
                indices = indices.substring(0, indices.length - 1);
            }

            var stringIndices:Array<String> = indices.split(',');
			var indices:Array<Int> = [];

            var index:Int = 0;

			while(index < stringIndices.length) {
				indices.push(Std.parseInt(stringIndices[index++]));
			}

            spr.animation.addByIndices(animation, prefix, indices, "", framerate, false);
		});

        Lua_helper.add_callback(lua, "playAnimationByIndices", function(name:String, animation:String, prefix:String, indices:String, framerate:Int = 24) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            /**
            * While making this, I was using an older version of `HaxeFlixel`.
            */
            @:privateAccess
            if(spr.animation._animations.exists(animation)) {
                spr.animation.remove(animation);
            }

            indices = indices.trim();

            if(indices.substring(0, 1) == "[") {
                indices = indices.substring(1, indices.length);
            }

            if(indices.substring(indices.length - 1, indices.length) == "]") {
                indices = indices.substring(0, indices.length - 1);
            }

            var stringIndices:Array<String> = indices.split(',');
			var indices:Array<Int> = [];

            var index:Int = 0;

			while(index < stringIndices.length) {
				indices.push(Std.parseInt(stringIndices[index++]));
			}

            spr.animation.addByIndices(animation, prefix, indices, "", framerate, false);
            spr.animation.play(animation);
        });

        Lua_helper.add_callback(lua, "playAnim", function(name:String, animation:String, forced:Bool = false, ?reverse:Bool = false, ?startFrame:Int = 0) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return false;
            }

            @:privateAccess
            if(spr.animation._animations.exists(animation)) {
                if(Std.isOfType(spr, Character)) {
                    var obj:Dynamic = spr;
					var spr:Character = obj;
                    spr.playNoDanceAnim(animation, forced, reverse, startFrame);
                }else if(Std.isOfType(spr, feshixl.FeshSprite)) {
                    var obj:Dynamic = spr;
					var spr:feshixl.FeshSprite = obj;
                    spr.playAnim(animation, forced, reverse, startFrame);
                }else {
                    spr.animation.play(animation, forced, reverse, startFrame);
                }
            }

            return true;
        });

		Lua_helper.add_callback(lua, "playAnimRaw", function(name:String, animation:String, forced:Bool = false, ?reverse:Bool = false, ?startFrame:Int = 0) {
				var spr:FlxSprite = getSprite(name);

				if(spr == null) {
				    return false;
				}

				@:privateAccess
				if(spr.animation._animations.exists(animation)) {
				    spr.animation.play(animation, forced, reverse, startFrame);
				}

				return true;
		});

		Lua_helper.add_callback(lua, "stopAnim", function(name:String) {
				var spr:FlxSprite = getSprite(name);

				if(spr == null) {
				    return;
				}

				spr.animation.stop();
		});

		Lua_helper.add_callback(lua, "setAnimFrame", function(name:String, frame:Int) {
				var spr:FlxSprite = getSprite(name);

				if(spr == null) {
				    return;
				}

				spr.animation.frameIndex = frame;
		});

        Lua_helper.add_callback(lua, "getAnimFrame", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return 0;
            }

            return spr.animation.frameIndex;
        });

        Lua_helper.add_callback(lua, "sprAnimFinished", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return false;
            }

            if(spr.animation.curAnim == null) {
                return false;
            }

            return spr.animation.curAnim.finished;
        });

		Lua_helper.add_callback(lua, "spriteFlip", function(name:String, flipX:Bool, flipY:Bool) {
		    var spr:FlxSprite = getSprite(name);

			if(spr == null) {
				return;
			}

			spr.flipX = flipX;
			spr.flipY = flipY;
		});

        Lua_helper.add_callback(lua, "setCustomFieldToSprite", function(name:String, prop:String, value:Dynamic) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            Reflect.setField(spr, prop, value);
        });

        Lua_helper.add_callback(lua, "setSpritePosition", function(name:String, x:Float, y:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.setPosition(x, y);
        });

        Lua_helper.add_callback(lua, "setSpriteX", function(name:String, x:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.x = x;
        });

        Lua_helper.add_callback(lua, "setSpriteY", function(name:String, y:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.y = y;
        });

        Lua_helper.add_callback(lua, "setSpriteAngle", function(name:String, angle:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.angle = angle;
        });

        Lua_helper.add_callback(lua, "setSpriteColor", function(name:String, colorStr:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                var color:Int = Std.parseInt(colorStr);

                if(!colorStr.startsWith('0x')) {
                    color = Std.parseInt('0xff' + colorStr);
                }

                spr.color = color;
            }
        });

        Lua_helper.add_callback(lua, "setSpriteAlpha", function(name:String, alpha:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.alpha = alpha;
        });

        Lua_helper.add_callback(lua, "setScrollFactorToSprite", function(name:String, x:Int, y:Int) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.scrollFactor.set(x, y);
        });

        Lua_helper.add_callback(lua, "setSpriteSize", function(name:String, width:Int, height:Int) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.setGraphicSize(width, height);
            spr.updateHitbox();
        });

        Lua_helper.add_callback(lua, "getSpriteX", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.x;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "getSpriteY", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.y;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "getSpriteWidth", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.width;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "getSpriteHeight", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.height;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "getMidpointX", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.getMidpoint().x;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "getMidpointY", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.getMidpoint().y;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "setSpriteClipRect", function(name:String, x:Float = 0, y:Float = 0, ?width:Float, ?height:Float) {
            var spr:FlxSprite = getSprite(name);

            var sprWidth:Float = width == null ? spr.width : width;
            var sprHeight:Float = height == null ? spr.height : height;

            if(spr == null) {
                return;
            }

            spr.clipRect = new FlxRect(x, y, sprWidth, sprHeight);
        });

        Lua_helper.add_callback(lua, "spriteExist", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return false;
            }

            return true;
        });

        Lua_helper.add_callback(lua, "increaseSpriteSizeBy", function(name:String, width:Float, height:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.setGraphicSize(Std.int(spr.width * width), Std.int(spr.height * height));
            spr.updateHitbox();
        });

        Lua_helper.add_callback(lua, "decreaseSpriteSizeBy", function(name:String, width:Float, height:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.setGraphicSize(Std.int(spr.width / width), Std.int(spr.height / height));
            spr.updateHitbox();
        });

        Lua_helper.add_callback(lua, "setSpriteToCamera", function(name:String, camera:String) {
            var cam:FlxCamera = getCamera(camera);
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            if(cam == null) {
                return;
            }

            spr.cameras = [cam];
        });

        Lua_helper.add_callback(lua, "getSpriteIndexFromState", function(name:String) {
			var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return -1;
            }

			return FlxG.state.members.indexOf(spr);
		});

        Lua_helper.add_callback(lua, "addSpriteToState", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            FlxG.state.add(spr);
        });

        Lua_helper.add_callback(lua, "insertSpriteToState", function(position:Int, name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            FlxG.state.insert(position, spr);
        });

        Lua_helper.add_callback(lua, "destroySprite", function(name:String) {
            var spr:FlxSprite = getSprite(name);
            var curState = cast FlxG.state;

            if(spr == null) {
                return;
            }

            spr.kill();
            spr.destroy();

            if(curState is HelperStates && curState.modifiableSprites.exists(name)) {
                curState.modifiableSprites.remove(name);
            }

            if(luaSprites.exists(name)) {
                luaSprites.remove(name);
            }
        });

        Lua_helper.add_callback(lua, "setText", function(name:String, text:String) {
            var txt:FlxText = getText(name);

            if(txt == null) {
                return;
            }

            txt.text = text;
        });

        Lua_helper.add_callback(lua, "setTextFont", function(name:String, font:String) {
            var txt:FlxText = getText(name);

            if(txt == null) {
                return;
            }

            txt.font = Paths.font(font);
        });

        Lua_helper.add_callback(lua, "setTextSize", function(name:String, size:Int) {
            var txt:FlxText = getText(name);

            if(txt == null) {
                return;
            }

            txt.size = size;
        });

        Lua_helper.add_callback(lua, "removeSpriteFromState", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            FlxG.state.remove(spr);
        });

        Lua_helper.add_callback(lua, "doTweenX", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {x: value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenY", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {y: value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenScaleX", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {"scale.x": value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
                        //obj.updateHitbox();
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenScaleY", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {"scale.y": value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
                        //obj.updateHitbox();
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenAngle", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {angle: value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenAlpha", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {alpha: value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenZoom", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
			var obj:Dynamic = getObjectFromMap(vars);

			if(obj != null) {
                cancelTween(name);
				luaTweens.set(name, FlxTween.tween(obj, {zoom: value}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

        Lua_helper.add_callback(lua, "doTweenColor", function(name:String, vars:String, colorStr:String, duration:Float, ease:String) {
            var obj:Dynamic = getObjectFromMap(vars);

            if(obj != null) {
                var curColor:FlxColor = obj.color;
                curColor.alphaFloat = obj.alpha;
                var color:Int = Std.parseInt(colorStr);

                if(!colorStr.startsWith('0x')) {
                    color = Std.parseInt('0xff' + colorStr);
                }

                cancelTween(name);
                luaTweens.set(name, FlxTween.color(obj, duration, curColor, color, {ease: Register.getFlxEaseByString(ease),
                    onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
						call('onTweenCompleted', [name]);
                    }
                }));
            }
        });

        Lua_helper.add_callback(lua, "doTweenSpriteClipRectX", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
            var obj:Dynamic = getObjectFromMap(vars);
            var frameHandler:LuaFrameCollection = new LuaFrameCollection(obj);

            if(obj != null) {
                cancelTween(name);
                luaTweens.set(name, FlxTween.tween(frameHandler, {x: value}, duration, {ease: Register.getFlxEaseByString(ease),
                    onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
                        call('onTweenCompleted', [name]);
                    }
                }));
            }
        });

        Lua_helper.add_callback(lua, "doTweenSpriteClipRectY", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
            var obj:Dynamic = getObjectFromMap(vars);
            var frameHandler:LuaFrameCollection = new LuaFrameCollection(obj);

            if(obj != null) {
                cancelTween(name);
                luaTweens.set(name, FlxTween.tween(frameHandler, {y: value}, duration, {ease: Register.getFlxEaseByString(ease),
                    onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
                        call('onTweenCompleted', [name]);
                    }
                }));
            }
        });

        Lua_helper.add_callback(lua, "doTweenSpriteClipRectWidth", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
            var obj:Dynamic = getObjectFromMap(vars);
            var frameHandler:LuaFrameCollection = new LuaFrameCollection(obj);

            if(obj != null) {
                cancelTween(name);
                luaTweens.set(name, FlxTween.tween(frameHandler, {width: value}, duration, {ease: Register.getFlxEaseByString(ease),
                    onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
                        call('onTweenCompleted', [name]);
                    }
                }));
            }
        });

        Lua_helper.add_callback(lua, "doTweenSpriteClipRectHeight", function(name:String, vars:String, value:Dynamic, duration:Float, ease:String) {
            var obj:Dynamic = getObjectFromMap(vars);
            var frameHandler:LuaFrameCollection = new LuaFrameCollection(obj);

            if(obj != null) {
                cancelTween(name);
                luaTweens.set(name, FlxTween.tween(frameHandler, {height: value}, duration, {ease: Register.getFlxEaseByString(ease),
                    onComplete: function(twn:FlxTween) {
                        luaTweens.remove(name);
                        call('onTweenCompleted', [name]);
                    }
                }));
            }
        });

        Lua_helper.add_callback(lua, "cancelTween", function(name:String) {
			cancelTween(name);
		});

        /**
        * Sound WIP.
        */
        Lua_helper.add_callback(lua, "playMusic", function(sound:String, volume:Float = 1, loop:Bool = false) {
			FlxG.sound.playMusic(Paths.music(sound), volume, loop);
		});

        Lua_helper.add_callback(lua, "playMusicAt", function(sound:String, startTime:Float = 0, volume:Float = 1, loop:Bool = true) {
			FlxG.sound.playMusic(Paths.music(sound), volume, loop);

            if(FlxG.sound.music != null) {
                var targetTime:Float = Math.max(0, startTime);

                if(FlxG.sound.music.length > 0) {
                    targetTime = Math.min(targetTime, Math.max(0, FlxG.sound.music.length - 1));
                }

                FlxG.sound.music.time = targetTime;
            }
		});

        Lua_helper.add_callback(lua, "playInst", function(song:String, volume:Float = 1, loop:Bool = false) {
            FlxG.sound.playMusic(Paths.inst(song), volume, loop);
        });

        Lua_helper.add_callback(lua, "playInstAt", function(song:String, startTime:Float = 0, volume:Float = 1, loop:Bool = true) {
            FlxG.sound.playMusic(Paths.inst(song), volume, loop);

            if(FlxG.sound.music != null) {
                var targetTime:Float = Math.max(0, startTime);

                if(FlxG.sound.music.length > 0) {
                    targetTime = Math.min(targetTime, Math.max(0, FlxG.sound.music.length - 1));
                }

                FlxG.sound.music.time = targetTime;
            }
        });

        Lua_helper.add_callback(lua, "getMusicTime", function() {
            if(FlxG.sound.music != null) {
                return FlxG.sound.music.time;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "setMusicTime", function(time:Float) {
            if(FlxG.sound.music == null) {
                return;
            }

            var targetTime:Float = Math.max(0, time);

            if(FlxG.sound.music.length > 0) {
                targetTime = Math.min(targetTime, Math.max(0, FlxG.sound.music.length - 1));
            }

            FlxG.sound.music.time = targetTime;
        });

        Lua_helper.add_callback(lua, "isMusicPlaying", function() {
            return FlxG.sound.music != null && FlxG.sound.music.playing;
        });

        Lua_helper.add_callback(lua, "setGlobalVar", function(name:String, value:Dynamic) {
            sharedVariables.set(name, value);
        });

        Lua_helper.add_callback(lua, "getGlobalVar", function(name:String, ?defaultValue:Dynamic = null) {
            if(sharedVariables.exists(name)) {
                return sharedVariables.get(name);
            }

            return defaultValue;
        });

        Lua_helper.add_callback(lua, "playSound", function(sound:String, volume:Float = 1, ?tag:String = "") {
            if(tag != null && tag.trim() != "") {
                tag = tag.replace('.', '');
                cancelSound(tag);

                luaSounds.set(tag, FlxG.sound.play(Paths.sound(sound), volume, false, function() {
                    call('onSoundFinished', [tag]);
                    cancelSound(tag);
                }));
            }else {
                FlxG.sound.play(Paths.sound(sound), volume);
            }
        });

        Lua_helper.add_callback(lua, "setCameraZoom", function(name:String, zoom:Float) {
            var cam:FlxCamera = getCamera(name);

            if(cam == null) {
                return;
            }

            cam.zoom = zoom;
        });

        Lua_helper.add_callback(lua, "getCameraZoom", function(name:String) {
            var cam:FlxCamera = getCamera(name);

            if(cam != null) {
                return cam.zoom;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "setCameraBlur", function(name:String, blurX:Float = 0, ?blurY:Null<Float>, quality:Int = 1) {
            return setCameraBlurFilter(name, blurX, blurY, quality);
        });

        Lua_helper.add_callback(lua, "clearCameraBlur", function(name:String) {
            return setCameraBlurFilter(name, 0, 0, 1);
        });

        Lua_helper.add_callback(lua, "switchState", function(state:String) {
            FlxG.switchState(Register.forNameClass(state, []));
        });

        /**
        * @param subState name of the substate class.
        */
        Lua_helper.add_callback(lua, "openSubState", function(subState:String) {
            var state = cast FlxG.state;

            if(state is HelperStates)
                state.openSubStateCustom(Register.forNameClass(subState, []));
            else
                state.openSubState(Register.forNameClass(subState, []));
        });

        /**
        * Psych-style runtime shaders for Lua.
        */
        Lua_helper.add_callback(lua, "initLuaShader", function(name:String, path:String = "shaders") {
            return storeShaders(name, name, path);
        });

        Lua_helper.add_callback(lua, "createShaderTemplate", function(name:String, shader:String, path:String = "shaders") {
            return storeShaders(name, shader, path);
        });

        Lua_helper.add_callback(lua, "initLuaShaderSource", function(name:String, fragmentSource:String, vertexSource:String = "") {
            if(name == null || name.trim() == "" || fragmentSource == null || fragmentSource.trim() == "") {
                return false;
            }

            luaShaderSources.set(name, {
                vertexSource: vertexSource == null ? "" : vertexSource,
                fragmentSource: fragmentSource
            });
            return true;
        });

        Lua_helper.add_callback(lua, "createRuntimeShader", function(name:String, tag:String = null) {
            if(tag == null || tag.trim() == "") {
                tag = name;
            }

            return createShaderInstance(name, tag) != null ? tag : null;
        });

        Lua_helper.add_callback(lua, "setSpriteShader", function(spriteName:String, shaderName:String) {
            return attachShaderToSprite(shaderName, spriteName);
        });

        Lua_helper.add_callback(lua, "setObjectShader", function(spriteName:String, shaderName:String) {
            return attachShaderToSprite(shaderName, spriteName);
        });

        Lua_helper.add_callback(lua, "removeSpriteShader", function(spriteName:String) {
            return removeShaderFromSprite(spriteName);
        });

        Lua_helper.add_callback(lua, "setCameraShader", function(cameraName:String, shaderName:String) {
            return attachShaderToCamera(shaderName, cameraName);
        });

        Lua_helper.add_callback(lua, "removeCameraShader", function(cameraName:String) {
            return removeShaderFromCamera(cameraName);
        });

        Lua_helper.add_callback(lua, "attachShaderToCamera", function(name:String, cameraName:String) {
            return attachShaderToCamera(name, cameraName);
        });

        Lua_helper.add_callback(lua, "attachShaderToObject", function(name:String, spriteName:String) {
            return attachShaderToSprite(name, spriteName);
        });

        Lua_helper.add_callback(lua, "setShaderFloat", function(target:String, property:String, value:Float) {
            return setShaderFloatValue(target, property, [value]);
        });

        Lua_helper.add_callback(lua, "setShaderFloat2", function(target:String, property:String, x:Float, y:Float) {
            return setShaderFloatValue(target, property, [x, y]);
        });

        Lua_helper.add_callback(lua, "getShaderFloat", function(target:String, property:String) {
            var values:Array<Dynamic> = getShaderValue(target, property);
            return values.length > 0 ? values[0] : 0.0;
        });

        Lua_helper.add_callback(lua, "setShaderFloatArray", function(target:String, property:String, values:Array<Dynamic>) {
            return setShaderFloatValue(target, property, normalizeFloatArray(values));
        });

        Lua_helper.add_callback(lua, "getShaderFloatArray", function(target:String, property:String) {
            return getShaderValue(target, property);
        });

        Lua_helper.add_callback(lua, "setShaderInt", function(target:String, property:String, value:Int) {
            return setShaderIntValue(target, property, [value]);
        });

        Lua_helper.add_callback(lua, "getShaderInt", function(target:String, property:String) {
            var values:Array<Dynamic> = getShaderValue(target, property);
            return values.length > 0 ? Std.int(values[0]) : 0;
        });

        Lua_helper.add_callback(lua, "setShaderIntArray", function(target:String, property:String, values:Array<Dynamic>) {
            return setShaderIntValue(target, property, normalizeIntArray(values));
        });

        Lua_helper.add_callback(lua, "getShaderIntArray", function(target:String, property:String) {
            return getShaderValue(target, property);
        });

        Lua_helper.add_callback(lua, "setShaderBool", function(target:String, property:String, value:Bool) {
            return setShaderBoolValue(target, property, [value]);
        });

        Lua_helper.add_callback(lua, "getShaderBool", function(target:String, property:String) {
            var values:Array<Dynamic> = getShaderValue(target, property);
            return values.length > 0 ? values[0] == true : false;
        });

        Lua_helper.add_callback(lua, "setShaderBoolArray", function(target:String, property:String, values:Array<Dynamic>) {
            return setShaderBoolValue(target, property, normalizeBoolArray(values));
        });

        Lua_helper.add_callback(lua, "getShaderBoolArray", function(target:String, property:String) {
            return getShaderValue(target, property);
        });

        Lua_helper.add_callback(lua, "setShaderSampler2D", function(target:String, property:String, texture:String) {
            return setShaderSampler(target, property, texture);
        });

        /*
        * User Inputs
        */
        Lua_helper.add_callback(lua, "mouseClicked", function(button:String) {
            var confirm:Bool = FlxG.mouse.justPressed;

            switch(button.toLowerCase()) {
				case 'middle':
					confirm = FlxG.mouse.justPressedMiddle;
				case 'right':
					confirm = FlxG.mouse.justPressedRight;
			}

            return confirm;
        });

        Lua_helper.add_callback(lua, "mousePressed", function(button:String) {
            var confirm:Bool = FlxG.mouse.pressed;

            switch(button.toLowerCase()) {
				case 'middle':
					confirm = FlxG.mouse.pressedMiddle;
				case 'right':
					confirm = FlxG.mouse.pressedRight;
			}

            return confirm;
        });

        Lua_helper.add_callback(lua, "mouseReleased", function(button:String) {
            var confirm:Bool = FlxG.mouse.justReleased;

            switch(button.toLowerCase()) {
				case 'middle':
					confirm = FlxG.mouse.justReleasedMiddle;
				case 'right':
					confirm = FlxG.mouse.justReleasedRight;
			}

            return confirm;
        });

        Lua_helper.add_callback(lua, "keyboardJustPressed", function(name:String) {
            return Reflect.getProperty(FlxG.keys.justPressed, name);
        });

        Lua_helper.add_callback(lua, "keyboardPressed", function(name:String) {
            return Reflect.getProperty(FlxG.keys.pressed, name);
        });

        Lua_helper.add_callback(lua, "keyboardReleased", function(name:String) {
            return Reflect.getProperty(FlxG.keys.justReleased, name);
        });

        Lua_helper.add_callback(lua, "keyJustPressed", function(name:String) {
            return Reflect.getProperty(FlxG.keys.justPressed, name);
        });

        Lua_helper.add_callback(lua, "keyPressed", function(name:String) {
            return Reflect.getProperty(FlxG.keys.pressed, name);
        });

        Lua_helper.add_callback(lua, "keyReleased", function(name:String) {
            return Reflect.getProperty(FlxG.keys.justReleased, name);
        });

        Lua_helper.add_callback(lua, "anyGamepadJustPressed", function(name:String) {
            return FlxG.gamepads.anyJustPressed(name);
        });

        Lua_helper.add_callback(lua, "anyGamepadPressed", function(name:String) {
            return FlxG.gamepads.anyPressed(name);
        });

        Lua_helper.add_callback(lua, "anyGamepadReleased", function(name:String) {
            return FlxG.gamepads.anyJustReleased(name);
        });

        Lua_helper.add_callback(lua, "gamepadAnalogX", function(id:Int, ?leftStick:Bool = true) {
            var controller = FlxG.gamepads.getByID(id);

            if (controller == null) {
                return 0.0;
            }

            return controller.getXAxis(leftStick ? LEFT_ANALOG_STICK : RIGHT_ANALOG_STICK);
        });

        Lua_helper.add_callback(lua, "gamepadAnalogY", function(id:Int, ?leftStick:Bool = true) {
            var controller = FlxG.gamepads.getByID(id);

            if (controller == null) {
                return 0.0;
            }

            return controller.getYAxis(leftStick ? LEFT_ANALOG_STICK : RIGHT_ANALOG_STICK);
        });

        Lua_helper.add_callback(lua, "gamepadJustPressed", function(id:Int, name:String) {
            var controller = FlxG.gamepads.getByID(id);

            if (controller == null) {
                return false;
            }

            return Reflect.field(controller.justPressed, name) == true;
        });

        Lua_helper.add_callback(lua, "gamepadPressed", function(id:Int, name:String) {
            var controller = FlxG.gamepads.getByID(id);

            if (controller == null) {
                return false;
            }

            return Reflect.field(controller.pressed, name) == true;
        });

        Lua_helper.add_callback(lua, "gamepadReleased", function(id:Int, name:String) {
            var controller = FlxG.gamepads.getByID(id);

            if (controller == null) {
                return false;
            }

            return Reflect.field(controller.justReleased, name) == true;
        });

        Lua_helper.add_callback(lua, "close", function() {
			closed = true;
			return closed;
		});

        call("initialized", []);
        #end
    }

    function storeShaders(name:String, shader:String, path:String = "shaders", ?glslVersion:Null<UInt>):Bool {
        #if sys
        if(luaShaderSources.exists(name)) {
            Log.info('Shader `$name` was already stored!');
			return true;
        }

        var fragHeader:String = Paths.getPreloadPath(path + "/" + shader + ".frag");
        var vertHeader:String = Paths.getPreloadPath(path + "/" + shader + ".vert");

        var foundAtLeastOne:Bool = false;

        if(FileSystem.exists(fragHeader)) {
            fragHeader = File.getContent(fragHeader);
            foundAtLeastOne = true;
        }else {
            fragHeader = "";
        }

        if(FileSystem.exists(vertHeader)) {
            vertHeader = File.getContent(vertHeader);
            foundAtLeastOne = true;
        }else {
            vertHeader = "";
        }

        if(foundAtLeastOne) {
            luaShaderSources.set(name, {
                vertexSource: vertHeader,
                fragmentSource: fragHeader
            });
            return true;
        }

        Log.error('Missing shader `$shader` .frag AND .vert files!');
        #end

        return false;
    }

    function createShaderInstance(name:String, ?tag:String):FeshShader {
        var shaderSource:LuaShaderSource = luaShaderSources.get(name);

        if(shaderSource == null) {
            Log.error('Shader `$name` was not initialized!');
            return null;
        }

        var shader:FeshShader = new FeshShader(shaderSource.fragmentSource, shaderSource.vertexSource);
        if(tag != null && tag.trim() != "") {
            luaShaders.set(tag, shader);
        }

        return shader;
    }

    function getShaderInstance(name:String):FeshShader {
        if(name == null) {
            return null;
        }

        var shader:FeshShader = luaShaders.get(name);

        if(shader != null) {
            return shader;
        }

        var spr:FlxSprite = getSprite(name);

        if(spr != null && spr.shader != null && isOfType(spr.shader, FeshShader)) {
            return cast spr.shader;
        }

        var shaderFilter:ShaderFilter = luaCameraShaderFilters.get(name);

        if(shaderFilter != null && shaderFilter.shader != null && isOfType(shaderFilter.shader, FeshShader)) {
            return cast shaderFilter.shader;
        }

        return null;
    }

    function getCameraFilters(camera:FlxCamera):Array<BitmapFilter> {
        if(camera == null) {
            return [];
        }

        var filters:Dynamic = Reflect.getProperty(camera, "filters");

        if(filters == null) {
            return [];
        }

        return (cast filters:Array<BitmapFilter>).concat([]);
    }

    function parseLuaColor(colorStr:String):Int {
        var color:Int = Std.parseInt(colorStr);

        if(colorStr != null && !colorStr.startsWith('0x')) {
            color = Std.parseInt('0xff' + colorStr);
        }

        return color;
    }

    function parseLuaColorArray(colors:String):Array<Int> {
        var output:Array<Int> = [];

        if(colors == null) {
            return output;
        }

        colors = colors.trim();

        if(colors.length == 0) {
            return output;
        }

        if(colors.substring(0, 1) == "[") {
            colors = colors.substring(1, colors.length);
        }

        if(colors.substring(colors.length - 1, colors.length) == "]") {
            colors = colors.substring(0, colors.length - 1);
        }

        for(color in colors.split(',')) {
            var trimmed:String = color.trim();

            if(trimmed.length > 0) {
                output.push(parseLuaColor(trimmed));
            }
        }

        return output;
    }

    function createSectorBitmapData(radius:Float, startAngle:Float, endAngle:Float, color:Int, segments:Int = 48):BitmapData {
        var sanitizedSegments:Int = segments;

        if(sanitizedSegments < 3) {
            sanitizedSegments = 3;
        }

        var start:Float = startAngle;
        var finish:Float = endAngle;

        if(finish < start) {
            finish += Math.PI * 2;
        }

        var sweep:Float = finish - start;

        if(sweep == 0) {
            sweep = Math.PI * 2;
        }

        var diameter:Int = Std.int(Math.ceil(radius * 2)) + 2;
        var center:Float = radius + 1;
        var bitmap:BitmapData = new BitmapData(diameter, diameter, true, 0x00000000);
        var shape:Shape = new Shape();
        var alpha:Float = ((color >> 24) & 0xFF) / 255;

        shape.graphics.beginFill(color & 0xFFFFFF, alpha);
        shape.graphics.moveTo(center, center);

        var firstX:Float = center + Math.cos(start) * radius;
        var firstY:Float = center + Math.sin(start) * radius;
        shape.graphics.lineTo(firstX, firstY);

        for(i in 1...sanitizedSegments + 1) {
            var progress:Float = i / sanitizedSegments;
            var angle:Float = start + sweep * progress;
            var x:Float = center + Math.cos(angle) * radius;
            var y:Float = center + Math.sin(angle) * radius;
            shape.graphics.lineTo(x, y);
        }

        shape.graphics.lineTo(center, center);
        shape.graphics.endFill();
        bitmap.draw(shape);

        return bitmap;
    }

    function createSectorGradientBitmapData(radius:Float, startAngle:Float, endAngle:Float, colors:Array<Int>, segments:Int = 48):BitmapData {
        var sanitizedColors:Array<Int> = colors.copy();

        if(sanitizedColors.length == 1) {
            return createSectorBitmapData(radius, startAngle, endAngle, sanitizedColors[0], segments);
        }

        var sanitizedSegments:Int = segments;

        if(sanitizedSegments < 3) {
            sanitizedSegments = 3;
        }

        var start:Float = startAngle;
        var finish:Float = endAngle;

        if(finish < start) {
            finish += Math.PI * 2;
        }

        var sweep:Float = finish - start;

        if(sweep == 0) {
            sweep = Math.PI * 2;
        }

        var diameter:Int = Std.int(Math.ceil(radius * 2)) + 2;
        var center:Float = radius + 1;
        var bitmap:BitmapData = new BitmapData(diameter, diameter, true, 0x00000000);
        var shape:Shape = new Shape();
        var matrix:Matrix = new Matrix();
        var alphas:Array<Float> = [];
        var ratios:Array<Int> = [];

        matrix.createGradientBox(diameter, diameter, 0, 0, 0);

        for(i in 0...sanitizedColors.length) {
            alphas.push(((sanitizedColors[i] >> 24) & 0xFF) / 255);

            if(sanitizedColors.length == 1) {
                ratios.push(0);
            }else {
                ratios.push(Std.int((255 * i) / (sanitizedColors.length - 1)));
            }
        }

        shape.graphics.beginGradientFill(GradientType.LINEAR, sanitizedColors, alphas, ratios, matrix, SpreadMethod.PAD, InterpolationMethod.RGB, 0);
        shape.graphics.moveTo(center, center);

        var firstX:Float = center + Math.cos(start) * radius;
        var firstY:Float = center + Math.sin(start) * radius;
        shape.graphics.lineTo(firstX, firstY);

        for(i in 1...sanitizedSegments + 1) {
            var progress:Float = i / sanitizedSegments;
            var angle:Float = start + sweep * progress;
            var x:Float = center + Math.cos(angle) * radius;
            var y:Float = center + Math.sin(angle) * radius;
            shape.graphics.lineTo(x, y);
        }

        shape.graphics.lineTo(center, center);
        shape.graphics.endFill();
        bitmap.draw(shape);

        return bitmap;
    }

    function createSoftSectorBitmapData(radius:Float, startAngle:Float, endAngle:Float, color:Int, edgePercent:Float = 0.35, steps:Int = 24, segments:Int = 48):BitmapData {
        var maxRadius:Float = Math.max(radius, 1);
        var fadePercent:Float = edgePercent;

        if(fadePercent < 0) {
            fadePercent = 0;
        }else if(fadePercent > 1) {
            fadePercent = 1;
        }

        var sanitizedSteps:Int = steps;

        if(sanitizedSteps < 2) {
            sanitizedSteps = 2;
        }

        var diameter:Int = Std.int(Math.ceil(maxRadius * 2)) + 2;
        var center:Float = maxRadius + 1;
        var bitmap:BitmapData = new BitmapData(diameter, diameter, true, 0x00000000);
        var innerRadius:Float = maxRadius * (1 - fadePercent);
        var baseAlpha:Int = (color >> 24) & 0xFF;
        var rgb:Int = color & 0xFFFFFF;

        for(i in 0...sanitizedSteps) {
            var progress:Float = i / (sanitizedSteps - 1);
            var layerRadius:Float = innerRadius + (maxRadius - innerRadius) * progress;
            var alphaFactor:Float = 1 - progress;
            var layerAlpha:Int = Std.int(baseAlpha * alphaFactor);

            if(layerAlpha <= 0 || layerRadius <= 0) {
                continue;
            }

            var layerColor:Int = (layerAlpha << 24) | rgb;
            var layerBitmap:BitmapData = createSectorBitmapData(layerRadius, startAngle, endAngle, layerColor, segments);
            var matrix:Matrix = new Matrix();
            var layerCenter:Float = layerRadius + 1;

            matrix.translate(center - layerCenter, center - layerCenter);
            bitmap.draw(layerBitmap, matrix, null, null, null, true);
            layerBitmap.dispose();
        }

        return bitmap;
    }

    function setCameraBlurFilter(cameraName:String, blurX:Float = 0, ?blurY:Null<Float>, quality:Int = 1):Bool {
        var cam:FlxCamera = getCamera(cameraName);

        if(cam == null) {
            Log.error('Camera `$cameraName` could not be found!');
            return false;
        }

        if(blurY == null) {
            blurY = blurX;
        }

        var filters:Array<BitmapFilter> = [];

        for(filter in getCameraFilters(cam)) {
            if(!isOfType(filter, BlurFilter)) {
                filters.push(filter);
            }
        }

        if(blurX > 0 || blurY > 0) {
            var blurQualityValue:Int = quality;

            if(blurQualityValue < 1) {
                blurQualityValue = 1;
            }else if(blurQualityValue > 3) {
                blurQualityValue = 3;
            }

            filters.unshift(new BlurFilter(blurX, blurY, cast blurQualityValue));
        }

        cam.setFilters(filters);
        return true;
    }

    function attachShaderToSprite(shaderName:String, spriteName:String):Bool {
        try {
        var spr:FlxSprite = getSprite(spriteName);

        if(spr == null) {
            Log.error('Object `$spriteName` could not be found!');
            return false;
        }

        var shader:FeshShader = luaShaders.exists(shaderName) ? luaShaders.get(shaderName) : createShaderInstance(shaderName, spriteName);

        if(shader == null) {
            return false;
        }

        spr.shader = cast shader;

        spr.dirty = true;
        luaShaders.set(spriteName, shader);
        return true;
        } catch(e:Dynamic) {
            Log.error('Failed to attach shader `$shaderName` to sprite `$spriteName`: $e');
            return false;
        }
    }

    function attachShaderToCamera(shaderName:String, cameraName:String):Bool {
        var cam:FlxCamera = getCamera(cameraName);

        if(cam == null) {
            Log.error('Camera `$cameraName` could not be found!');
            return false;
        }

        var shader:FeshShader = luaShaders.exists(shaderName) ? luaShaders.get(shaderName) : createShaderInstance(shaderName, cameraName);

        if(shader == null) {
            return false;
        }

        var filters:Array<BitmapFilter> = getCameraFilters(cam);
        var previousFilter:ShaderFilter = luaCameraShaderFilters.get(cameraName);

        if(previousFilter != null) {
            filters.remove(previousFilter);
        }

        var shaderFilter:ShaderFilter = new ShaderFilter(cast shader);
        filters.push(shaderFilter);

        cam.setFilters(filters);
        luaCameraShaderFilters.set(cameraName, shaderFilter);
        luaShaders.set(cameraName, shader);
        return true;
    }

    function removeShaderFromSprite(spriteName:String):Bool {
        try {
        var spr:FlxSprite = getSprite(spriteName);

        if(spr == null) {
            return false;
        }

        spr.shader = null;

        spr.dirty = true;
        luaShaders.remove(spriteName);
        return true;
        } catch(e:Dynamic) {
            Log.error('Failed to remove shader from sprite `$spriteName`: $e');
            return false;
        }
    }

    function removeShaderFromCamera(cameraName:String):Bool {
        var cam:FlxCamera = getCamera(cameraName);
        var previousFilter:ShaderFilter = luaCameraShaderFilters.get(cameraName);

        if(cam == null || previousFilter == null) {
            return false;
        }

        var filters:Array<BitmapFilter> = getCameraFilters(cam);
        filters.remove(previousFilter);

        cam.setFilters(filters);
        luaCameraShaderFilters.remove(cameraName);
        luaShaders.remove(cameraName);
        return true;
    }

    function getShaderDataField(target:String, property:String):Dynamic {
        var shader:FeshShader = getShaderInstance(target);

        if(shader == null) {
            Log.error('Shader target `$target` could not be found!');
            return null;
        }

        var shaderField:Dynamic = Reflect.field(shader.data, property);

        if(shaderField == null) {
            Log.error('Shader property `$property` was not found on `$target`!');
            return null;
        }

        return shaderField;
    }

    function getShaderValue(target:String, property:String):Array<Dynamic> {
        var shaderField:Dynamic = getShaderDataField(target, property);

        if(shaderField == null) {
            return [];
        }

        var value:Dynamic = Reflect.getProperty(shaderField, "value");
        return value != null ? cast value : [];
    }

    function setShaderFloatValue(target:String, property:String, values:Array<Float>):Bool {
        try {
        var shaderField:Dynamic = getShaderDataField(target, property);

        if(shaderField == null) {
            return false;
        }

        Reflect.setProperty(shaderField, "value", cast values);
        return true;
        } catch(e:Dynamic) {
            Log.error('Failed to set float shader property `$property` on `$target`: $e');
            return false;
        }
    }

    function setShaderIntValue(target:String, property:String, values:Array<Int>):Bool {
        try {
        var shaderField:Dynamic = getShaderDataField(target, property);

        if(shaderField == null) {
            return false;
        }

        Reflect.setProperty(shaderField, "value", cast values);
        return true;
        } catch(e:Dynamic) {
            Log.error('Failed to set int shader property `$property` on `$target`: $e');
            return false;
        }
    }

    function setShaderBoolValue(target:String, property:String, values:Array<Bool>):Bool {
        try {
        var shaderField:Dynamic = getShaderDataField(target, property);

        if(shaderField == null) {
            return false;
        }

        Reflect.setProperty(shaderField, "value", cast values);
        return true;
        } catch(e:Dynamic) {
            Log.error('Failed to set bool shader property `$property` on `$target`: $e');
            return false;
        }
    }

    function setShaderSampler(target:String, property:String, texture:String):Bool {
        try {
        var shaderField:Dynamic = getShaderDataField(target, property);
        var bitmapData:BitmapData = resolveShaderBitmap(texture);

        if(shaderField == null || bitmapData == null) {
            return false;
        }

        Reflect.setProperty(shaderField, "input", bitmapData);
        return true;
        } catch(e:Dynamic) {
            Log.error('Failed to set sampler shader property `$property` on `$target`: $e');
            return false;
        }
    }

    function resolveShaderBitmap(texture:String):BitmapData {
        if(texture == null || texture.trim() == "") {
            return null;
        }

        if(luaBitmaps.exists(texture)) {
            return luaBitmaps.get(texture);
        }

        if(OpenFlAssets.exists(texture, IMAGE)) {
            return OpenFlAssets.getBitmapData(texture);
        }

        var assetPath:String = texture.startsWith("images/") ? texture : 'images/$texture.png';
        var resolvedPath:String = Paths.getPath(assetPath, IMAGE, null);

        if(OpenFlAssets.exists(resolvedPath, IMAGE)) {
            return OpenFlAssets.getBitmapData(resolvedPath);
        }

        Log.error('Bitmap `$texture` could not be found for shader input!');
        return null;
    }

    function normalizeFloatArray(values:Array<Dynamic>):Array<Float> {
        var output:Array<Float> = [];

        if(values == null) {
            return output;
        }

        for(value in values) {
            output.push(value == null ? 0 : Std.parseFloat(Std.string(value)));
        }

        return output;
    }

    function normalizeIntArray(values:Array<Dynamic>):Array<Int> {
        var output:Array<Int> = [];

        if(values == null) {
            return output;
        }

        for(value in values) {
            output.push(value == null ? 0 : Std.int(Std.parseFloat(Std.string(value))));
        }

        return output;
    }

    function normalizeBoolArray(values:Array<Dynamic>):Array<Bool> {
        var output:Array<Bool> = [];

        if(values == null) {
            return output;
        }

        for(value in values) {
            if(value == null) {
                output.push(false);
            }else if(isOfType(value, Bool)) {
                output.push(cast value);
            }else if(isOfType(value, Int) || isOfType(value, Float)) {
                output.push(value != 0);
            }else {
                output.push(Std.string(value).toLowerCase().trim() == "true");
            }
        }

        return output;
    }

    public function getObjectFromMap(name:String):Dynamic {
        var spr:FlxSprite = getSprite(name);
        var cam:FlxCamera = getCamera(name);

        if(spr != null)return spr;
        if(cam != null)return cam;

        return null;
    }

    public function cancelTween(name:String):Void {
        if(luaTweens.exists(name)) {
            luaTweens.get(name).cancel();
            luaTweens.get(name).destroy();
            luaTweens.remove(name);
        }
    }

    public function cancelSound(name:String):Void {
        if(luaSounds.exists(name)) {
            luaSounds.get(name).stop();
            luaSounds.remove(name);
        }
    }

    public function addCallback(name:String, method:Dynamic):Void {
        #if (USING_LUA && cpp)
        Lua_helper.add_callback(lua, name, method);
        #end
    }

    public function set(variable:String, data:Dynamic):Void {
		#if (USING_LUA && cpp)
		if(lua == null) {
			return;
		}

		Convert.toLua(lua, data);
		Lua.setglobal(lua, variable);
		#end
	}

    public function call(event:String, args:Array<Dynamic>, index:Int = 0):Dynamic {
        #if (USING_LUA && cpp)
        if(closed) {
            return 0;
        }

        try {
            if(lua == null) {
                trace("Error: Something went wrong with lua.");
                return LuaUtils.Function_Continue;
            }

            Lua.getglobal(lua, event);
            var type:Int = Lua.type(lua, -1);

            if(type != Lua.LUA_TFUNCTION) {
                if(type > Lua.LUA_TNIL) {
                    Log.error(event + " - Attempt to call a '" + typeToString(type) + "' value!");
                }

                Lua.pop(lua, 1);
                return LuaUtils.Function_Continue;
            }

            for (arg in args) {
                Convert.toLua(lua, arg);
            }

            var status:Int = Lua.pcall(lua, args.length, 1, 0);

            if (status != Lua.LUA_OK) {
                var error:String = getErrorMessage(status);
				Log.error("Error (" + event + ") - " + error);
				return LuaUtils.Function_Continue;
			}

            var result:Dynamic = cast Convert.fromLua(lua, -1);

            if (result == null) {
                return 0;
            }

            Lua.pop(lua, 1);
			return result;
        }catch(e:Dynamic) {
            trace(e);
        }
        #end

        return 0;
    }

    public function getSprite(name:String):FlxSprite {
        if(name == null) {
            return null;
        }

        var spr:FlxSprite = luaSprites.get(name);
        var curState = cast FlxG.state;

        if(spr == null && curState is HelperStates) {
            if(curState.modifiableSprites.exists(name))
                spr = curState.modifiableSprites.get(name);
        }

        if(spr != null) {
            return spr;
        }

        spr = luaTexts.get(name);

        if(spr == null && curState is HelperStates) {
            if(curState.modifiableTexts.exists(name))
                spr = curState.modifiableTexts.get(name);
        }

        if(spr != null) {
            return spr;
        }

        if(curState is PlayState) {
            var playState:PlayState = cast curState;

            switch(name.toLowerCase().trim()) {
                case "boyfriend", "bf":
                    spr = playState.boyfriend;
                case "dad", "opponent":
                    spr = playState.dad;
                case "gf", "girlfriend":
                    spr = playState.gf;
                default:
            }

            if(spr == null && playState.modifiableCharacters.exists(name))
                spr = playState.modifiableCharacters.get(name);
        }

        if(spr == null) {
            var reflectedObject:Dynamic = Reflect.getProperty(curState, name);

            if(isOfType(reflectedObject, FlxSprite)) {
                spr = cast reflectedObject;
            }
        }

        return spr;
    }

    public function getCamera(name:String):FlxCamera {
        if(name == null) {
            return null;
        }

        var cam:FlxCamera = luaCameras.get(name);
        var curState = cast FlxG.state;

        if(cam == null && curState is HelperStates) {
            if(curState.modifiableCameras.exists(name))
                cam = curState.modifiableCameras.get(name);
        }

        if(cam == null) {
            switch(name.toLowerCase().trim()) {
                case "camhud", "hud":
                    cam = PlayState.camHUD;
                case "camgame", "game":
                    var reflectedCam:Dynamic = Reflect.getProperty(curState, "camGame");

                    if(isOfType(reflectedCam, FlxCamera)) {
                        cam = cast reflectedCam;
                    }else {
                        cam = FlxG.camera;
                    }
                case "camera", "default":
                    cam = FlxG.camera;
                default:
            }
        }

        if(cam == null) {
            var reflectedObject:Dynamic = Reflect.getProperty(curState, name);

            if(isOfType(reflectedObject, FlxCamera)) {
                cam = cast reflectedObject;
            }
        }

        return cam;
    }

    public function getText(name:String):FlxText {
        if(name == null) {
            return null;
        }

        var text:FlxText = luaTexts.get(name);
        var curState = cast FlxG.state;

        if(text == null && curState is HelperStates) {
            if(curState.modifiableTexts.exists(name))
                text = curState.modifiableTexts.get(name);
        }

        return text;
    }

    public function close():Void {
        #if (USING_LUA && cpp)
        if(lua == null) {
            return;
        }

        if(luaCameraShaderFilters != null) {
            var cameraShaderNames:Array<String> = [];

            for(k in luaCameraShaderFilters.keys()) {
                cameraShaderNames.push(k);
            }

            for(k in cameraShaderNames) {
                removeShaderFromCamera(k);
            }

            luaCameraShaderFilters.clear();
            luaCameraShaderFilters = null;
        }

        if(luaShaders != null) {
            for(k in luaShaders.keys()) {
                var spr:FlxSprite = getSprite(k);
                var runtimeShader:FeshShader = luaShaders.get(k);

                if(spr != null && spr.shader == cast runtimeShader) {
                    spr.shader = null;
                }
            }

            luaShaders.clear();
            luaShaders = null;
        }

        if(luaShaderSources != null) {
            luaShaderSources.clear();
            luaShaderSources = null;
        }

        if(luaSprites != null) {
            for(k in luaSprites.keys()) {
                var spr:FlxSprite = luaSprites.get(k);

                if(spr != null) {
                    spr.destroy();
                }
            }

            luaSprites.clear();
            luaSprites = null;
        }

        if(luaCameras != null) {
            for(k in luaCameras.keys()) {
                var cam:FlxCamera = getCamera(k);

                if(cam != null) {
                    cam.destroy();
                }
            }

            luaCameras.clear();
            luaCameras = null;
        }

        if(luaTweens != null) {
            for(k in luaTweens.keys()) {
                var tween:FlxTween = luaTweens.get(k);

                if(tween != null) {
                    tween.cancel();
                    tween.destroy();
                }
            }

            luaTweens.clear();
            luaTweens = null;
        }

        if(luaTexts != null) {
            for(k in luaTexts.keys()) {
                var text:FlxText = luaTexts.get(k);

                if(text != null) {
                    text.destroy();
                }
            }

            luaTexts.clear();
            luaTexts = null;
        }

		if(luaBitmaps != null) {
				for(k in luaBitmaps.keys()) {
						var bmp:BitmapData = luaBitmaps.get(k);

						if(bmp != null) {
						    bmp.disposeImage();
							bmp.dispose();
						}
				}

				luaBitmaps.clear();
				luaBitmaps = null;
		}

		if(luaFrameCollections != null) {
		    luaFrameCollections.clear();
			luaFrameCollections = null;
		}

        Lua.close(lua);
        lua = null;
        #end
    }

    /*
    * Most of it copied from psych engine
    * because I don't wanna make my own.
    */
    #if (USING_LUA && cpp)
    function getErrorMessage(status:Int):String {
		#if USING_LUA
		var v:String = Lua.tostring(lua, -1);
		Lua.pop(lua, 1);

		if (v != null) v = v.trim();
		if (v == null || v == "") {
			switch(status) {
				case Lua.LUA_ERRRUN: return "Runtime Error";
				case Lua.LUA_ERRMEM: return "Memory Allocation Error";
				case Lua.LUA_ERRERR: return "Critical Error";
			}
			return "Unknown Error";
		}

		return v;
        #else

        Log.warn("Lua is not allowed");
		return null;
		#end
	}

    function typeToString(type:Int):String {
		#if USING_LUA
		switch(type) {
			case Lua.LUA_TBOOLEAN: return "boolean";
			case Lua.LUA_TNUMBER: return "number";
			case Lua.LUA_TSTRING: return "string";
			case Lua.LUA_TTABLE: return "table";
			case Lua.LUA_TFUNCTION: return "function";
		}

		if (type <= Lua.LUA_TNIL) {
            return "nil";
        }
		#end

		return "unknown";
	}
    #end
}

@:access(flixel.FlxSprite)
private class LuaFrameCollection {
    public var x(default, set):Float = 0;
    public var y(default, set):Float = 0;
    public var width(default, set):Float = 0;
    public var height(default, set):Float = 0;

    var sprite:FlxSprite;

    public function new(sprite:FlxSprite) {
        this.sprite = sprite;
    }

    function set_x(value:Float):Float {
        if(sprite != null) {
            sprite.clipRect.x = value;

            if (sprite.frames != null) {
                sprite.frame = sprite.frames.frames[sprite.animation.frameIndex];
            }

            sprite._frame = sprite.frame.clipTo(sprite.clipRect, sprite._frame);
        }

        return x = value;
    }

    function set_y(value:Float):Float {
        if(sprite != null) {
            sprite.clipRect.y = value;

            if (sprite.frames != null) {
                sprite.frame = sprite.frames.frames[sprite.animation.frameIndex];
            }

            sprite._frame = sprite.frame.clipTo(sprite.clipRect, sprite._frame);
        }

        return y = value;
    }

    function set_width(value:Float):Float {
        if(sprite != null) {
            sprite.clipRect.width = value;

            if (sprite.frames != null) {
                sprite.frame = sprite.frames.frames[sprite.animation.frameIndex];
            }

            sprite._frame = sprite.frame.clipTo(sprite.clipRect, sprite._frame);
        }

        return width = value;
    }

    function set_height(value:Float):Float {
        if(sprite != null) {
            sprite.clipRect.height = value;

            if (sprite.frames != null) {
                sprite.frame = sprite.frames.frames[sprite.animation.frameIndex];
            }

            sprite._frame = sprite.frame.clipTo(sprite.clipRect, sprite._frame);
        }

        return height = value;
    }
}
