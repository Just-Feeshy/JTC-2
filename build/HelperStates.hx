package;

import flixel.FlxG;
import flixel.FlxCamera;
import flixel.FlxState;
import flixel.FlxSubState;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.graphics.FlxGraphic;
import flixel.addons.ui.FlxUIState;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;

import example_code.TransitionSamples;
import play.PlayScriptEvent;
import play.PlayScriptEventDispatcher;
import template.TransitionBuilder;
import Controls;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

/**
* Basically another extendy that should clean up the game more.
* Also extend on the main game/mod.
*/
class HelperStates extends FlxState {
	public var modifiableTexts:Map<String, FlxText>;
	public var modifiableSprites:Map<String, FlxSprite>;
	public var modifiableCameras:Map<String, FlxCamera>;

	public static var transitionSkip:Bool = false;
	public static var skipNextTransitionIn:Bool = false;
	public static var nextTransitionInType:String = null;

	private static var scriptsInStates:Map<String, ModLua> = new Map<String, ModLua>();
	private static var transitionBuilds:Map<String, Class<TransitionBuilder>> = new Map<String, Class<TransitionBuilder>>();

	private var controls(get, never):Controls;

	var transOutFinished:Bool = false;
    var initOnCreate:Bool = true;

	var transInType:String;
	var transOutType:String;

	inline function get_controls():Controls
		return PlayerSettings.player1.controls;

	public function new(?transInType:String, ?transOutType:String, ?initOnCreate:Bool = true) {
		super();

        this.initOnCreate = initOnCreate;

		modifiableTexts = new Map<String, FlxText>();
		modifiableSprites = new Map<String, FlxSprite>();
		modifiableCameras = new Map<String, FlxCamera>();

		if(transInType != null) {
			this.transInType = transInType;
		}else {
			this.transInType = "void";
		}

		if(transOutType != null) {
			this.transOutType = transOutType;
		}else {
			this.transOutType = "void";
		}
	}

	function whenCreate() {
		/**
		* Interesting, I know. Not in a good way.
		*/
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).execute();

			addCallback("getControl", function(control:String) {
				if(control == Action.UP) {return controls.UP;}
				if(control == Action.LEFT) {return controls.LEFT;}
				if(control == Action.RIGHT) {return controls.RIGHT;}
				if(control == Action.SPACE) {return controls.SPACE;}
				if(control == Action.DOWN) {return controls.DOWN;}
				if(control == Action.UP_P) {return controls.UP_P;}
				if(control == Action.LEFT_P) {return controls.LEFT_P;}
				if(control == Action.RIGHT_P) {return controls.RIGHT_P;}
				if(control == Action.SPACE_P) {return controls.SPACE_P;}
				if(control == Action.DOWN_P) {return controls.DOWN_P;}
				if(control == Action.UP_R) {return controls.UP_R;}
				if(control == Action.LEFT_R) {return controls.LEFT_R;}
				if(control == Action.RIGHT_R) {return controls.RIGHT_R;}
				if(control == Action.SPACE_R) {return controls.SPACE_R;}
				if(control == Action.DOWN_R) {return controls.DOWN_R;}
				if(control == Action.GAME_UP) {return controls.GAME_UP;}
				if(control == Action.GAME_LEFT) {return controls.GAME_LEFT;}
				if(control == Action.GAME_RIGHT) {return controls.GAME_RIGHT;}
				if(control == Action.GAME_SPACE) {return controls.GAME_SPACE;}
				if(control == Action.GAME_DOWN) {return controls.GAME_DOWN;}
				if(control == Action.GAME_UP_P) {return controls.GAME_UP_P;}
				if(control == Action.GAME_LEFT_P) {return controls.GAME_LEFT_P;}
				if(control == Action.GAME_RIGHT_P) {return controls.GAME_RIGHT_P;}
				if(control == Action.GAME_SPACE_P) {return controls.GAME_SPACE_P;}
				if(control == Action.GAME_DOWN_P) {return controls.GAME_DOWN_P;}
				if(control == Action.GAME_UP_R) {return controls.GAME_UP_R;}
				if(control == Action.GAME_LEFT_R) {return controls.GAME_LEFT_R;}
				if(control == Action.GAME_RIGHT_R) {return controls.GAME_RIGHT_R;}
				if(control == Action.GAME_SPACE_R) {return controls.GAME_SPACE_R;}
				if(control == Action.GAME_DOWN_R) {return controls.GAME_DOWN_R;}
				if(control == Action.ACCEPT) {return controls.ACCEPT;}
				if(control == Action.BACK) {return controls.BACK;}
				if(control == Action.PAUSE) {return controls.PAUSE;}
				if(control == Action.RESET) {return controls.RESET;}
				if(control == Action.CHEAT) {return controls.CHEAT;}

				return false;
			});

			addCallback("setTransitionIn", function(name:String) {
				this.transInType = name;
			});

			addCallback("setTransitionOut", function(name:String) {
				this.transOutType = name;
			});
		}
		#end
	}

    override function create():Void {
        whenCreate();

		super.create();

        if(initOnCreate) {
            onCreate();
        }

		var transitionType:String = transInType;

		if(nextTransitionInType != null) {
			transitionType = nextTransitionInType;
			nextTransitionInType = null;
		}

		if(skipNextTransitionIn) {
			skipNextTransitionIn = false;
		}else if(!transitionSkip) {
			transitionIn(transitionType);
		}
    }

	public function onCreate():Dynamic {
		#if (USING_LUA && cpp)
		setLua("curElapsed", 0);

		if(HelperStates.luaExist(Type.getClass(this)))
			return HelperStates.getLua(Type.getClass(this)).call("onCreate", []);
		#end

		return null;
	}

	public function getModLua():ModLua {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			return HelperStates.getLua(Type.getClass(this));
		}
		#end

		return null;
	}

	public function addCallback(name:String, method:Dynamic):Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).addCallback(name, method);
		}
		#end
	}

	public function attachSprite(name:String, spr:FlxSprite):Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			if(!HelperStates.getLua(Type.getClass(this)).luaSprites.exists(name))
				HelperStates.getLua(Type.getClass(this)).luaSprites.set(name, spr);
		}
		#end
	}

	public function callLua(name:String, args:Array<Dynamic>):Dynamic {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this)))
			return HelperStates.getLua(Type.getClass(this)).call(name, args);
		#end

		return null;
	}

	public function dispatchEvent(event:PlayScriptEvent):Void {
		PlayScriptEventDispatcher.callEvent(this, event);
	}

	public function setLua(variable:String, data:Dynamic):Void {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).set(variable, data);
		}
		#end
	}

	public function resetScript() {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			var file:String = HelperStates.getLua(Type.getClass(this)).luaScript;

			Register.attachLuaToState(Type.getClass(this), file);
		}
		#end
	}

	public function openSubStateCustom(SubState:FlxSubState):Void {
		openSubState(SubState);
	}

    function clearStuff():Void {
		if(!isOfType(this, PlayState)) {
			if(PlayState.camNOTE != null) {
				FlxG.cameras.remove(PlayState.camHUD);
				FlxG.cameras.remove(PlayState.camNOTE);

				PlayState.camHUD = FlxDestroyUtil.destroy(PlayState.camHUD);
				PlayState.camNOTE = FlxDestroyUtil.destroy(PlayState.camNOTE);
			}
		}
	}

	override function update(elapsed:Float):Void {
		if(isOfType(this, PlayState)) {
			var playState:PlayState = cast this;
			playState.updateLuaVars();

			#if (USING_LUA && cpp)
			// Call onUpdate on the song-specific script (playLua)
			var songLua:ModLua = playState.getModLua();
			if(songLua != null) {
				songLua.set("curElapsed", elapsed);
				songLua.set("curTicks", FlxG.game.ticks);
				songLua.call("onUpdate", [elapsed]);
			}
			#end
		}

		{
			setLua("curElapsed", elapsed);
        	setLua("curTicks", FlxG.game.ticks);
			callLua("onUpdate", [elapsed]);
		}

		super.update(elapsed);
	}

	override function destroy() {
		#if (USING_LUA && cpp)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).close();
		}

		resetScript();
		#end

		super.destroy();

		if(modifiableSprites != null) {
            for(k in modifiableSprites.keys()) {
                var spr:FlxSprite = modifiableSprites.get(k);

                if(spr != null) {
                    spr.destroy();
                }
            }

            modifiableSprites.clear();
            modifiableSprites = null;
        }

        if(modifiableCameras != null) {
            for(k in modifiableCameras.keys()) {
                var cam:FlxCamera = modifiableCameras.get(k);

                if(cam != null && cam != FlxG.camera) {
                    cam.destroy();
                }
            }

            modifiableCameras.clear();
            modifiableCameras = null;
        }

		if(modifiableTexts != null) {
            for(k in modifiableTexts.keys()) {
                var spr:FlxText = modifiableTexts.get(k);

                if(spr != null) {
                    spr.destroy();
                }
            }

            modifiableTexts.clear();
            modifiableTexts = null;
        }
	}

	static public function getLua(state:Class<Dynamic>):ModLua {
		return scriptsInStates.get(Type.getClassName(state));
	}

	static public function luaExist(state:Class<Dynamic>):Bool {
		return scriptsInStates.exists(Type.getClassName(state));
	}

	override function startOutro(onOutroComplete:()->Void):Void {
		if(transitionSkip || transOutFinished) {
			onOutroComplete();
			return;
		}

		transitionOut(onOutroComplete);
	}

	/**
	* Based off of `FlxTransitionableState` class from HaxeFlixel.
	*/
	function createTransition(transType:String, fade:TransitionFade):TransitionBuilder {
		var transitionDuration:Float = transType == "void" ? 0.18 : 0.5;
		return Type.createInstance(transitionBuilds.get(transType), [transitionDuration, fade]);
	}

	function finishedTransition() {
		transOutFinished = true;
	}

	@:noCompletion
	public function transitionIn(?transitionType:String):Void {
		var useTransitionType:String = transitionType != null ? transitionType : transInType;

		if(useTransitionType != null && useTransitionType != "none") {
			var _transition = createTransition(useTransitionType, IN);

			if(_transition == null) {
				return;
			}

			#if (USING_LUA && cpp)
			_transition.finishCallback = function() {
				callLua("finishedTransitionIn", []);
			}
			#end

			openSubState(_transition);
		}
	}

	@:noCompletion
	public function transitionOut(?onOutroComplete:()->Void):Void {
		if(transOutType != null && transOutType != "none") {
			var _transition = createTransition(transOutType, OUT);

			if(_transition == null) {
				transOutFinished = true;
				if(onOutroComplete != null) {
					onOutroComplete();
				}
				return;
			}

			_transition.finishCallback = function() {
				finishedTransition();

				#if (USING_LUA && cpp)
				callLua("finishedTransitionOut", []);
				#end

				if(onOutroComplete != null) {
					onOutroComplete();
				}
			};

			openSubState(_transition);
		}else {
			transOutFinished = true;

			if(onOutroComplete != null) {
				onOutroComplete();
			}
		}
	}
}
