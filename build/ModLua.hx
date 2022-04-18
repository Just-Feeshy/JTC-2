package;

#if (USING_LUA && linc_luajit)
import llua.Lua;
import llua.LuaL;
import llua.State;
import llua.Convert;
#end

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.tweens.FlxTween;
import flixel.tweens.FlxEase;
import flixel.FlxSprite;

import SaveData.SaveType;

using StringTools;

class ModLua {
    #if (USING_LUA && linc_luajit)
    private var lua:State = null;
    #end

    public var luaScript(default, null):String;

    public var luaSprites(default, null):Map<String, FlxSprite> = new Map<String, FlxSprite>();
    public var luaCameras(default, null):Map<String, FlxCamera> = new Map<String, FlxCamera>();

    private var luaTweens:Map<String, FlxTween> = new Map<String, FlxTween>();

    public function new(luaScript:String) {
        this.luaScript = luaScript;
    }

    public function execute() {
        #if (USING_LUA && linc_luajit)
        lua = LuaL.newstate();
		LuaL.openlibs(lua);
		Lua.init_callbacks(lua);

        var resultFile:Dynamic = LuaL.dofile(lua, luaScript);
		var luaResults:String = Lua.tostring(lua, resultFile);

        if(luaResults != null && resultFile != 0) {
            throw 'Error loading lua script: "$luaScript"\n' + luaResults;
        }

        trace("Successfully loaded script: " + this.luaScript);

        set("windowWidth", FlxG.width);
        set("windowHeight", FlxG.height);

        set("inRapBattle", false);

        set('curBpm', Conductor.bpm);

        /**
        * No really point on this, unless if you homebrew a mod made with this "engine" to the switch.
        */
        #if switch
        set('onSwitch', true);
        #else
        set('onSwitch', false);
        #end

        Lua_helper.add_callback(lua, "createSprite", function(name:String) {
            if(luaSprites.exists(name)) {
                return;
            }

            name = name.replace('.', '');

            var sprite:FlxSprite = new FlxSprite();
            sprite.antialiasing = SaveData.getData(SaveType.GRAPHICS);
            sprite.active = true;

            luaSprites.set(name, sprite);
        });

        Lua_helper.add_callback(lua, "spriteExist", function(name:String) {
            if(getSprite(name) == null)
                return false;

            return true;
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

        Lua_helper.add_callback(lua, "setCustomPropertyToSprite", function(name:String, prop:String, value:Dynamic) {
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

        Lua_helper.add_callback(lua, "setSpriteAngle", function(name:String, angle:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.angle = angle;
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

        Lua_helper.add_callback(lua, "decreaseSpriteSizeBy", function(name:String, width:Float, height:Float) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            spr.setGraphicSize(Std.int(spr.width / width), Std.int(spr.height / height));
            spr.updateHitbox();
        });

        Lua_helper.add_callback(lua, "addSpriteToState", function(name:String) {
            var spr:FlxSprite = getSprite(name);

            if(spr == null) {
                return;
            }

            FlxG.state.add(spr);
        });

        Lua_helper.add_callback(lua, "setCameraZoom", function(name:String, zoom:Int) {
            var cam:FlxCamera = luaCameras.get(name);

            if(cam == null) {
                return;
            }

            cam.zoom = zoom;
        });

        Lua_helper.add_callback(lua, "switchState", function(state:String) {
            FlxG.switchState(Register.forNameClass(state, []));
        });

        //tweens
        Lua_helper.add_callback(lua, "setCameraZoomTween", function(name:String, value:Float, duration:Float, easing:String) {
            var cam:FlxCamera = luaCameras.get(name);

            if(cam == null) {
                return;
            }

            luaTweens.set(name, FlxTween.tween(cam, {zoom: value}, duration, {ease: Register.getFlxEaseByString(easing), onComplete: function(twn:FlxTween) {
                this.call("onTweenComplete", [name]);
                luaTweens.remove(name);
            }}));
        });
        #end
    }

    public function addCallback(name:String, method:Dynamic) {
        #if (USING_LUA && linc_luajit)
        Lua_helper.add_callback(lua, name, method);
        #end
    }

    public function set(variable:String, data:Dynamic) {
		#if (USING_LUA && linc_luajit)
		if(lua == null) {
			return;
		}

		Convert.toLua(lua, data);
		Lua.setglobal(lua, variable);
		#end
	}

    public function call(event:String, args:Array<Dynamic>, index:Int = 0):Dynamic {
        #if (USING_LUA && linc_luajit)
        if(lua == null) {
            trace("Error: Something went wrong with lua.");
            return 0;
        }

        Lua.getglobal(lua, event);

        if(convertToLua(args, index) == 1) {
            var luaResults:Null<Int> = Lua.pcall(lua, args.length, 1, 0);

            if(luaResults != null) {
                if(Lua.type(lua, -1) == Lua.LUA_TSTRING) {
                    var error:String = Lua.tostring(lua, -1);
                    Lua.pop(lua, 1);

                    if(error == 'attempt to call a nil value') {
                        return null;
                    }
                }
            }

            var output:Dynamic = Convert.fromLua(lua, luaResults);
            return output;
        }
        #end

        return null;
    }

    public function getSprite(name:String):FlxSprite {
        var spr:FlxSprite = luaSprites.get(name);

        if(spr == null) {
            var curState:HelperStates = cast(FlxG.state, HelperStates);

            if(curState.modifiableSprites.exists(name))
                spr = curState.modifiableSprites.get(name);
        }

        return spr;
    }

    public function close() {
        #if (USING_LUA && linc_luajit)
        if(lua == null) {
            return;
        }

        if(luaSprites != null) {
            luaSprites.clear();
            luaSprites = null;
        }

        if(luaCameras != null) {
            luaCameras.clear();
            luaCameras = null;
        }

        Lua.close(lua);
        lua = null;
        #end
    }

    /**
    * It's a recursion function to allow for smoother execution.
    */
    #if (USING_LUA && linc_luajit)
    public function convertToLua(args:Array<Dynamic>, index:Int = 0):Int {
        if(index < args.length) {
            Convert.toLua(lua, args[index]);
            return convertToLua(args, index + 1);
        }

        return 1;
    }
    #end
}