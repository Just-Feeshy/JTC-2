package;

import flixel.FlxG;
import flixel.FlxCamera;
import flixel.FlxState;
import flixel.FlxSubState;
import flixel.FlxSprite;
import flixel.graphics.FlxGraphic;
import flixel.addons.ui.FlxUIState;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxColor;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;

import example_code.TransitionSamples;
import template.TransitionBuilder;

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
	public var modifiableSprites:Map<String, FlxSprite>;

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
		modifiableSprites = new Map<String, FlxSprite>();

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
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this)))
			HelperStates.getLua(Type.getClass(this)).execute();
		#end

		onCreate();

		super.create();

		if(!transitionSkip) {
			transitionIn();
		}
	}

	public function onCreate():Dynamic {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this)))
			return HelperStates.getLua(Type.getClass(this)).call("onCreate", []);
		#end

		return null;
	}

	public function getModLua():ModLua {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			return HelperStates.getLua(Type.getClass(this));
		}
		#end

		return null;
	}

	public function addCallback(name:String, method:Dynamic):Void {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).addCallback(name, method);
		}
		#end
	}

	public function attachCamera(name:String, cam:FlxCamera):Void {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			if(!HelperStates.getLua(Type.getClass(this)).luaCameras.exists(name))
				HelperStates.getLua(Type.getClass(this)).luaCameras.set(name, cam);
		}
		#end
	}

	public function attachSprite(name:String, spr:FlxSprite):Void {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			if(!HelperStates.getLua(Type.getClass(this)).luaSprites.exists(name))
				HelperStates.getLua(Type.getClass(this)).luaSprites.set(name, spr);
		}
		#end
	}

	public function callLua(name:String, args:Array<Dynamic>):Dynamic {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this)))
			return HelperStates.getLua(Type.getClass(this)).call(name, args);
		#end

		return null;
	}

	public function setLua(variable:String, data:Dynamic):Void {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).set(variable, data);
		}
		#end
	}

	public function resetScript() {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			var file:String = HelperStates.getLua(Type.getClass(this)).luaScript;

			Register.attachLuaToState(Type.getClass(this), new ModLua(file));
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
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this)))
			HelperStates.getLua(Type.getClass(this)).call("onUpdate", [elapsed]);
		#end

		super.update(elapsed);
	}

	override function destroy() {
		#if (USING_LUA && linc_luajit_basic)
		if(HelperStates.luaExist(Type.getClass(this))) {
			HelperStates.getLua(Type.getClass(this)).close();
		}

		resetScript();
		#end

		super.destroy();
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
				FlxG.switchState(state);
			};

			openSubState(_transition);
		}
	}
}