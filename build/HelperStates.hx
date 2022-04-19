package;

import flixel.FlxG;
import flixel.addons.transition.FlxTransitionableState;
import flixel.addons.ui.FlxUIState;
import flixel.FlxSprite;

#if (haxe_ver >= 4.2)
import Std.isOfType;
#else
import Std.is as isOfType;
#end

/**
* Basically another extendy that should clean up the game more.
* Also extend on the main game/mod.
**/
abstract class HelperStates extends FlxUIState {
	public var modifiableSprites:Map<String, FlxSprite>;

	private static var scriptsInStates:Map<String, ModLua> = new Map<String, ModLua>();

	public function new() {
		super();

		modifiableSprites = new Map<String, FlxSprite>();
	}

	override function create() {
		super.create();

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
}