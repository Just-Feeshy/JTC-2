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
import feshixl.shaders.FeshShader;
import openfl.display.BitmapData;
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

/**
* Honestly, modcharts are my least concern, since this is mostly object-orientated based.
*/

class ModLua {
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
    public var luaShaders(default, null):Map<String, FeshShader> = new Map<String, FeshShader>();
	public var luaBitmaps(default, null):Map<String, BitmapData> = new Map<String, BitmapData>();

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

        set('getCwd', Sys.getCwd());

        #if debug
        set("debug", true);
        #else
        set("debug", false);
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

		Lua_helper.add_callback(lua, "loadBitmapData", function(name:String, path:String, x:Int, y:Int) {
		    var bmp:BitmapData = luaBitmaps.get(name);

		    if(bmp == null) {
		        return;
		    }

		    var image = Image.fromFile(Paths.getPath('images/$path.png', IMAGE, ""));

			{ // I want to make this confusing as possible lmao.
				var imgBytes = image.getPixels(new Rectangle(0, 0, image.width, image.height));
				bmp.setPixels(new OpenFlRectangle(x, y, x|image.width, y|image.height), imgBytes);
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

        Lua_helper.add_callback(lua, "makeGraphic", function(name:String, width:Int, height:Int, colorStr:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                var color:Int = Std.parseInt(colorStr);

                if(!colorStr.startsWith('0x')) {
                    color = Std.parseInt('0xff' + colorStr);
                }

                spr.makeGraphic(width, height, color);
            }
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

        Lua_helper.add_callback(lua, "sprAnimFinished", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null ) {
                return false;
            }

            if(spr.animation.curAnim == null) {
                return false;
            }

            return spr.animation.curAnim.finished;
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

        Lua_helper.add_callback(lua, "getSpriteX", function(name:String, x:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr != null) {
                return spr.x;
            }

            return 0;
        });

        Lua_helper.add_callback(lua, "getSpriteY", function(name:String, y:Float) {
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
        * shaders (Don't work yet)
        */
        Lua_helper.add_callback(lua, "createShaderTemplate", function(name:String, shader:String, path:String = "shaders") {
            storeShaders(name, shader, path);
        });

        Lua_helper.add_callback(lua, "attachShaderToCamera", function(name:String, path:String) {

        });

        Lua_helper.add_callback(lua, "attachShaderToObject", function(name:String, spriteName:String) {

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
        if(luaShaders.exists(name)) {
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
            luaShaders.set(name, new FeshShader(vertHeader, fragHeader));
            return true;
        }

        Log.error('Missing shader `$name` .frag AND .vert files!');
        #end

        return false;
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
                return 0;
            }

            Lua.getglobal(lua, event);

            var type:Int = Lua.type(lua, -1);

            if(type != Lua.LUA_TFUNCTION) {
                if(type > Lua.LUA_TNIL) {
                    Log.error(event + " - Attempt to call a '" + typeToString(type) + "' value!");
                }

                Lua.pop(lua, 1);
                return 0;
            }

            for (arg in args) {
                Convert.toLua(lua, arg);
            }

            var status:Int = Lua.pcall(lua, args.length, 1, 0);

            if (status != Lua.LUA_OK) {
				Log.error(event + " - " + getErrorMessage(status));
				return 0;
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
            if(curState.modifiableCharacters.exists(name))
                spr = curState.modifiableCharacters.get(name);
        }

        return spr;
    }

    public function getCamera(name:String):FlxCamera {
        var cam:FlxCamera = luaCameras.get(name);
        var curState = cast FlxG.state;

        if(cam == null && curState is HelperStates) {
            if(curState.modifiableCameras.exists(name))
                cam = curState.modifiableCameras.get(name);
        }

        return cam;
    }

    public function getText(name:String):FlxText {
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
		#if LUA_ALLOWED
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
		#end
		return null;
	}

    function typeToString(type:Int):String {
		#if LUA_ALLOWED
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
