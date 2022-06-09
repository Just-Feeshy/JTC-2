package;

import flixel.FlxG;
import flixel.graphics.FlxGraphic;
import flixel.FlxState;
import flixel.addons.ui.FlxUIState;
import flixel.math.FlxPoint;
import flixel.math.FlxRect;
import flixel.util.FlxColor;
import flixel.FlxSprite;

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
		super.create();

		if(!transitionSkip) {
			transitionIn();
		}

		/**
		* Interesting, I know.
		*/
		#if (USING_LUA && linc_luajit)
		if(HelperStates.luaExist(Type.getClass(this)))
			HelperStates.getLua(Type.getClass(this)).execute();
		#end
	}

	public function onCreate():Dynamic {
		#if (USING_LUA && linc_luajit)
		if(HelperStates.luaExist(Type.getClass(this)))
			return HelperStates.getLua(Type.getClass(this)).call("onCreate", []);
		#end

		return null;
	}

	public function callLua(name:String, args:Array<Dynamic>) {
		#if (USING_LUA && linc_luajit)
		if(HelperStates.luaExist(Type.getClass(this)))
			HelperStates.getLua(Type.getClass(this)).call(name, args);
		#end
	}

	public function resetScript() {
		#if (USING_LUA && linc_luajit)
		if(HelperStates.luaExist(Type.getClass(this))) {
			var file:String = HelperStates.getLua(Type.getClass(this)).luaScript;

			Register.attachLuaToState(Type.getClass(this), new ModLua(file));
		}
		#end
	}

    function clearStuff():Void {
		if(!isOfType(this, PlayState)) {
			if(PlayState.camNOTE != null) {
				PlayState.camHUD = null;
				PlayState.camNOTE = null;
			}

			PlayState.modStorage = [];
		}
	}

	override function destroy() {
		#if (USING_LUA && linc_luajit)
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