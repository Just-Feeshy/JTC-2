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
class HelperStates extends FlxUIState {
	public var modifiableTexts:Map<String, FlxText>;
	public var modifiableSprites:Map<String, FlxSprite>;
	public var modifiableCameras:Map<String, FlxCamera>;

	public static var transitionSkip:Bool = false;

	private static var scriptsInStates:Map<String, ModLua> = new Map<String, ModLua>();
	private static var transitionBuilds:Map<String, Class<TransitionBuilder>> = new Map<String, Class<TransitionBuilder>>();

	private var controls(get, never):Controls;

	var transOutFinished:Bool = false;

	var transInType:String;
	var transOutType:String;

	inline function get_controls():Controls
		return PlayerSettings.player1.controls;

	public function new(?transInType:String, ?transOutType:String) {
		modifiableTexts = new Map<String, FlxText>();
		modifiableSprites = new Map<String, FlxSprite>();
		modifiableCameras = new Map<String, FlxCamera>();

		if(transInType != null) {
			this.transInType = transInType;
		}else {
			this.transInType = "fade";
		}

		if(transOutType != null) {
			this.transOutType = transOutType;
		}else {
			this.transOutType = "tile";
		}

		super();
	}

	override function create() {
		/**
		* Interesting, I know.
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

		onCreate();

		super.create();

		if(!transitionSkip) {
			transitionIn();
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
		callLua("onUpdate", [elapsed]);
		setLua("curElapsed", elapsed);

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

                if(cam != null) {
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

	override function switchTo(state:FlxState):Bool {
		if(transitionSkip) {
			return true;
		}

		if(!transOutFinished) {
			transitionOut(state);
		}

		return transOutFinished;
	}

	/**
	* Based off of `FlxTransitionableState` class from HaxeFlixel.
	*/
	function createTransition(transType:String, fade:TransitionFade):TransitionBuilder {
		return Type.createInstance(transitionBuilds.get(transType), [0.5, fade]);
	}

	function finishedTransition() {
		transOutFinished = true;
	}

	@:noCompletion
	public function transitionIn():Void {
		if(transInType != null && transInType != "none") {
			var _transition = createTransition(transInType, IN);

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
	public function transitionOut(state:FlxState):Void {
		if(transOutType != null && transOutType != "none") {
			var _transition = createTransition(transOutType, OUT);

			if(_transition == null) {
				transOutFinished = true;
				return;
			}

			_transition.finishCallback = function() {
				finishedTransition();

				#if (USING_LUA && cpp)
				_transition.finishCallback = function() {
					callLua("finishedTransitionOut", []);
				}
				#end

				FlxG.switchState(state);
			};

			openSubState(_transition);
		}
	}
}