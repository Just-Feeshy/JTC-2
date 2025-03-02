package;

import flixel.FlxG;
import flixel.input.FlxInput;
import flixel.input.actions.FlxAction;
import flixel.input.actions.FlxActionInput;
import flixel.input.actions.FlxActionInputDigital;
import flixel.input.actions.FlxActionManager;
import flixel.input.actions.FlxActionSet;
import flixel.input.gamepad.FlxGamepadButton;
import flixel.input.gamepad.FlxGamepadInputID;
import flixel.input.keyboard.FlxKey;

#if (haxe >= "4.0.0")
enum abstract Action(String) to String from String
{
	var UP = "up";
	var LEFT = "left";
	var RIGHT = "right";
	var SPACE = "space";
	var DOWN = "down";
	var UP_P = "up-press";
	var LEFT_P = "left-press";
	var RIGHT_P = "right-press";
	var DOWN_P = "down-press";
	var SPACE_P = "space-press";
	var UP_R = "up-release";
	var LEFT_R = "left-release";
	var RIGHT_R = "right-release";
	var DOWN_R = "down-release";
	var SPACE_R = "space-release";
	var GAME_UP = "up";
	var GAME_LEFT = "left";
	var GAME_RIGHT = "right";
	var GAME_SPACE = "space";
	var GAME_DOWN = "down";
	var GAME_UP_P = "up-press";
	var GAME_SPACE_P = "space-press";
	var GAME_LEFT_P = "left-press";
	var GAME_RIGHT_P = "right-press";
	var GAME_DOWN_P = "down-press";
	var GAME_UP_R = "up-release";
	var GAME_LEFT_R = "left-release";
	var GAME_RIGHT_R = "right-release";
	var GAME_DOWN_R = "down-release";
	var GAME_SPACE_R = "space-release";
	var ACCEPT = "accept";
	var BACK = "back";
	var PAUSE = "pause";
	var RESET = "reset";
	var CHEAT = "cheat";
}
#else
@:enum
abstract Action(String) to String from String
{
	var UP = "up";
	var LEFT = "left";
	var RIGHT = "right";
	var SPACE = "space";
	var DOWN = "down";
	var UP_P = "up-press";
	var SPACE_P = "space-press";
	var LEFT_P = "left-press";
	var RIGHT_P = "right-press";
	var DOWN_P = "down-press";
	var UP_R = "up-release";
	var LEFT_R = "left-release";
	var RIGHT_R = "right-release";
	var DOWN_R = "down-release";
	var SPACE_R = "space-release";
	var GAME_UP = "up";
	var GAME_LEFT = "left";
	var GAME_RIGHT = "right";
	var GAME_SPACE = "space";
	var GAME_DOWN = "down";
	var GAME_UP_P = "up-press";
	var GAME_SPACE_P = "space-press";
	var GAME_LEFT_P = "left-press";
	var GAME_RIGHT_P = "right-press";
	var GAME_DOWN_P = "down-press";
	var GAME_UP_R = "up-release";
	var GAME_LEFT_R = "left-release";
	var GAME_RIGHT_R = "right-release";
	var GAME_DOWN_R = "down-release";
	var GAME_SPACE_R = "space-release";
	var ACCEPT = "accept";
	var BACK = "back";
	var PAUSE = "pause";
	var RESET = "reset";
	var CHEAT = "cheat";
}
#end

enum Device
{
	Keys;
	Gamepad(id:Int);
}

/**
 * Since, in many cases multiple actions should use similar keys, we don't want the
 * rebinding UI to list every action. ActionBinders are what the user percieves as
 * an input so, for instance, they can't set jump-press and jump-release to different keys.
 */
enum Control
{
	UP;
	LEFT;
	RIGHT;
	DOWN;
	SPACE;
	GAME_UP;
	GAME_LEFT;
	GAME_RIGHT;
	GAME_DOWN;
	GAME_SPACE;
	RESET;
	ACCEPT;
	BACK;
	PAUSE;
	CHEAT;
}

enum KeyboardScheme
{
	Solo;
	Duo(first:Bool);
	None;
	Custom;
}

/**
 * A list of actions that a player would invoke via some input device.
 * Uses FlxActions to funnel various inputs to a single action.
 */
class Controls extends FlxActionSet
{
	var _up = new FlxActionDigital(Action.UP);
	var _left = new FlxActionDigital(Action.LEFT);
	var _right = new FlxActionDigital(Action.RIGHT);
	var _down = new FlxActionDigital(Action.DOWN);
	var _space = new FlxActionDigital(Action.SPACE);
	var _upP = new FlxActionDigital(Action.UP_P);
	var _leftP = new FlxActionDigital(Action.LEFT_P);
	var _rightP = new FlxActionDigital(Action.RIGHT_P);
	var _downP = new FlxActionDigital(Action.DOWN_P);
	var _spaceP = new FlxActionDigital(Action.SPACE_P);
	var _upR = new FlxActionDigital(Action.UP_R);
	var _leftR = new FlxActionDigital(Action.LEFT_R);
	var _rightR = new FlxActionDigital(Action.RIGHT_R);
	var _downR = new FlxActionDigital(Action.DOWN_R);
	var _spaceR = new FlxActionDigital(Action.SPACE_R);
	var _game_up = new FlxActionDigital(Action.GAME_UP);
	var _game_left = new FlxActionDigital(Action.GAME_LEFT);
	var _game_right = new FlxActionDigital(Action.GAME_RIGHT);
	var _game_down = new FlxActionDigital(Action.GAME_DOWN);
	var _game_space = new FlxActionDigital(Action.GAME_SPACE);
	var _game_upP = new FlxActionDigital(Action.GAME_UP_P);
	var _game_leftP = new FlxActionDigital(Action.GAME_LEFT_P);
	var _game_rightP = new FlxActionDigital(Action.GAME_RIGHT_P);
	var _game_downP = new FlxActionDigital(Action.GAME_DOWN_P);
	var _game_spaceP = new FlxActionDigital(Action.GAME_SPACE_P);
	var _game_upR = new FlxActionDigital(Action.GAME_UP_R);
	var _game_leftR = new FlxActionDigital(Action.GAME_LEFT_R);
	var _game_rightR = new FlxActionDigital(Action.GAME_RIGHT_R);
	var _game_downR = new FlxActionDigital(Action.GAME_DOWN_R);
	var _game_spaceR = new FlxActionDigital(Action.GAME_SPACE_R);
	var _accept = new FlxActionDigital(Action.ACCEPT);
	var _back = new FlxActionDigital(Action.BACK);
	var _pause = new FlxActionDigital(Action.PAUSE);
	var _reset = new FlxActionDigital(Action.RESET);
	var _cheat = new FlxActionDigital(Action.CHEAT);

	#if (haxe >= "4.0.0")
	var byName:Map<String, FlxActionDigital> = [];
	#else
	var byName:Map<String, FlxActionDigital> = new Map<String, FlxActionDigital>();
	#end

	public var gamepadsAdded:Array<Int> = [];
	public var keyboardScheme = KeyboardScheme.None;

	public var UP(get, never):Bool;

	inline function get_UP()
		return _up.check();

	public var LEFT(get, never):Bool;

	inline function get_LEFT()
		return _left.check();

	public var RIGHT(get, never):Bool;

	inline function get_RIGHT()
		return _right.check();

	public var DOWN(get, never):Bool;

	inline function get_DOWN()
		return _down.check();

	public var SPACE(get, never):Bool;

	inline function get_SPACE()
		return _space.check();

	public var SPACE_P(get, never):Bool;

	inline function get_SPACE_P()
		return _spaceP.check();

	public var UP_P(get, never):Bool;

	inline function get_UP_P()
		return _upP.check();

	public var LEFT_P(get, never):Bool;

	inline function get_LEFT_P()
		return _leftP.check();

	public var RIGHT_P(get, never):Bool;

	inline function get_RIGHT_P()
		return _rightP.check();

	public var DOWN_P(get, never):Bool;

	inline function get_DOWN_P()
		return _downP.check();

	public var UP_R(get, never):Bool;

	inline function get_UP_R()
		return _upR.check();

	public var LEFT_R(get, never):Bool;

	inline function get_LEFT_R()
		return _leftR.check();

	public var RIGHT_R(get, never):Bool;

	inline function get_RIGHT_R()
		return _rightR.check();

	public var DOWN_R(get, never):Bool;

	inline function get_DOWN_R()
		return _downR.check();

	public var SPACE_R(get, never):Bool;

	inline function get_SPACE_R()
		return _spaceR.check();

	public var GAME_UP(get, never):Bool;

	inline function get_GAME_UP()
		return _game_up.check();

	public var GAME_LEFT(get, never):Bool;

	inline function get_GAME_LEFT()
		return _game_left.check();

	public var GAME_RIGHT(get, never):Bool;

	inline function get_GAME_RIGHT()
		return _game_right.check();

	public var GAME_DOWN(get, never):Bool;

	inline function get_GAME_DOWN()
		return _game_down.check();

	public var GAME_SPACE(get, never):Bool;

	inline function get_GAME_SPACE()
		return _game_space.check();

	public var GAME_SPACE_P(get, never):Bool;

	inline function get_GAME_SPACE_P()
		return _game_spaceP.check();

	public var GAME_UP_P(get, never):Bool;

	inline function get_GAME_UP_P()
		return _game_upP.check();

	public var GAME_LEFT_P(get, never):Bool;

	inline function get_GAME_LEFT_P()
		return _game_leftP.check();

	public var GAME_RIGHT_P(get, never):Bool;

	inline function get_GAME_RIGHT_P()
		return _game_rightP.check();

	public var GAME_DOWN_P(get, never):Bool;

	inline function get_GAME_DOWN_P()
		return _game_downP.check();

	public var GAME_UP_R(get, never):Bool;

	inline function get_GAME_UP_R()
		return _game_upR.check();

	public var GAME_LEFT_R(get, never):Bool;

	inline function get_GAME_LEFT_R()
		return _game_leftR.check();

	public var GAME_RIGHT_R(get, never):Bool;

	inline function get_GAME_RIGHT_R()
		return _game_rightR.check();

	public var GAME_DOWN_R(get, never):Bool;

	inline function get_GAME_DOWN_R()
		return _game_downR.check();

	public var GAME_SPACE_R(get, never):Bool;

	inline function get_GAME_SPACE_R()
		return _game_spaceR.check();

	public var ACCEPT(get, never):Bool;

	inline function get_ACCEPT()
		return _accept.check();

	public var BACK(get, never):Bool;

	inline function get_BACK()
		return _back.check();

	public var PAUSE(get, never):Bool;

	inline function get_PAUSE()
		return _pause.check();

	public var RESET(get, never):Bool;

	inline function get_RESET()
		return _reset.check();

	public var CHEAT(get, never):Bool;

	inline function get_CHEAT()
		return _cheat.check();

	#if (haxe >= "4.0.0")
	public function new(name, scheme = None)
	{
		super(name);

		add(_up);
		add(_left);
		add(_right);
		add(_down);
		add(_space);
		add(_upP);
		add(_leftP);
		add(_rightP);
		add(_downP);
		add(_spaceP);
		add(_upR);
		add(_leftR);
		add(_rightR);
		add(_downR);
		add(_spaceR);
		add(_game_up);
		add(_game_left);
		add(_game_right);
		add(_game_down);
		add(_game_space);
		add(_game_upP);
		add(_game_leftP);
		add(_game_rightP);
		add(_game_downP);
		add(_game_spaceP);
		add(_game_upR);
		add(_game_leftR);
		add(_game_rightR);
		add(_game_downR);
		add(_game_spaceR);
		add(_accept);
		add(_back);
		add(_pause);
		add(_reset);
		add(_cheat);

		for (action in digitalActions)
			byName[action.name] = action;

		setKeyboardScheme(scheme, false);
	}
	#else
	public function new(name, scheme:KeyboardScheme = null)
	{
		super(name);

		add(_up);
		add(_left);
		add(_right);
		add(_down);
		add(_space);
		add(_upP);
		add(_leftP);
		add(_rightP);
		add(_downP);
		add(_spaceP)
		add(_upR);
		add(_leftR);
		add(_rightR);
		add(_downR);
		add(_spaceR);
		add(_accept);
		add(_game_up);
		add(_game_left);
		add(_game_right);
		add(_game_down);
		add(_game_space);
		add(_game_upP);
		add(_game_leftP);
		add(_game_rightP);
		add(_game_downP);
		add(_game_spaceP)
		add(_game_upR);
		add(_game_leftR);
		add(_game_rightR);
		add(_game_downR);
		add(_game_spaceR);
		add(_accept);
		add(_back);
		add(_pause);
		add(_reset);
		add(_cheat);

		for (action in digitalActions)
			byName[action.name] = action;
			
		setKeyboardScheme(scheme, false);
	}
	#end

	// inline
	public function checkByName(name:Action):Bool
	{
		#if debug
		if (!byName.exists(name))
			throw 'Invalid name: $name';
		#end
		return byName[name].check();
	}

	public function getDialogueName(action:FlxActionDigital):String
	{
		var input = action.inputs[0];
		return switch input.device
		{
			case KEYBOARD: return '[${(input.inputID : FlxKey)}]';
			case GAMEPAD: return '(${(input.inputID : FlxGamepadInputID)})';
			case device: throw 'unhandled device: $device';
		}
	}

	public function getDialogueNameFromToken(token:String):String
	{
		return getDialogueName(getActionFromControl(Control.createByName(token.toUpperCase())));
	}

	function getActionFromControl(control:Control):FlxActionDigital
	{
		return switch (control)
		{
			case UP: _up;
			case DOWN: _down;
			case LEFT: _left;
			case RIGHT: _right;
			case SPACE: _space;
			case GAME_UP: _game_up;
			case GAME_DOWN: _game_down;
			case GAME_LEFT: _game_left;
			case GAME_RIGHT: _game_right;
			case GAME_SPACE: _game_space;
			case ACCEPT: _accept;
			case BACK: _back;
			case PAUSE: _pause;
			case RESET: _reset;
			case CHEAT: _cheat;
		}
	}

	static function init():Void
	{
		var actions = new FlxActionManager();
		FlxG.inputs.add(actions);
	}

	/**
	 * Calls a function passing each action bound by the specified control
	 * @param control
	 * @param func
	 * @return ->Void)
	 */
	function forEachBound(control:Control, func:FlxActionDigital->FlxInputState->Void)
	{
		switch (control)
		{
			case UP:
				func(_up, PRESSED);
				func(_upP, JUST_PRESSED);
				func(_upR, JUST_RELEASED);
			case LEFT:
				func(_left, PRESSED);
				func(_leftP, JUST_PRESSED);
				func(_leftR, JUST_RELEASED);
			case RIGHT:
				func(_right, PRESSED);
				func(_rightP, JUST_PRESSED);
				func(_rightR, JUST_RELEASED);
			case DOWN:
				func(_down, PRESSED);
				func(_downP, JUST_PRESSED);
				func(_downR, JUST_RELEASED);
			case SPACE:
				func(_space, PRESSED);
				func(_spaceP, JUST_PRESSED);
				func(_spaceR, JUST_RELEASED);
			case GAME_UP:
				func(_game_up, PRESSED);
				func(_game_upP, JUST_PRESSED);
				func(_game_upR, JUST_RELEASED);
			case GAME_LEFT:
				func(_game_left, PRESSED);
				func(_game_leftP, JUST_PRESSED);
				func(_game_leftR, JUST_RELEASED);
			case GAME_RIGHT:
				func(_game_right, PRESSED);
				func(_game_rightP, JUST_PRESSED);
				func(_game_rightR, JUST_RELEASED);
			case GAME_DOWN:
				func(_game_down, PRESSED);
				func(_game_downP, JUST_PRESSED);
				func(_game_downR, JUST_RELEASED);
			case GAME_SPACE:
				func(_game_space, PRESSED);
				func(_game_spaceP, JUST_PRESSED);
				func(_game_spaceR, JUST_RELEASED);
			case ACCEPT:
				func(_accept, JUST_PRESSED);
			case BACK:
				func(_back, JUST_PRESSED);
			case PAUSE:
				func(_pause, JUST_PRESSED);
			case RESET:
				func(_reset, JUST_PRESSED);
			case CHEAT:
				func(_cheat, JUST_PRESSED);
		}
	}

	public function replaceBinding(control:Control, device:Device, ?toAdd:Int, ?toRemove:Int)
	{
		if (toAdd == toRemove)
			return;

		switch (device)
		{
			case Keys:
				if (toRemove != null)
					unbindKeys(control, [toRemove]);
				if (toAdd != null)
					bindKeys(control, [toAdd]);

			case Gamepad(id):
				if (toRemove != null)
					unbindButtons(control, id, [toRemove]);
				if (toAdd != null)
					bindButtons(control, id, [toAdd]);
		}
	}

	public function copyFrom(controls:Controls, ?device:Device)
	{
		#if (haxe >= "4.0.0")
		for (name => action in controls.byName)
		{
			for (input in action.inputs)
			{
				if (device == null || isDevice(input, device))
					byName[name].add(cast input);
			}
		}
		#else
		for (name in controls.byName.keys())
		{
			var action = controls.byName[name];
			for (input in action.inputs)
			{
				if (device == null || isDevice(input, device))
					byName[name].add(cast input);
			}
		}
		#end

		switch (device)
		{
			case null:
				// add all
				#if (haxe >= "4.0.0")
				for (gamepad in controls.gamepadsAdded)
					if (!gamepadsAdded.contains(gamepad))
						gamepadsAdded.push(gamepad);
				#else
				for (gamepad in controls.gamepadsAdded)
					if (gamepadsAdded.indexOf(gamepad) == -1)
						gamepadsAdded.push(gamepad);
				#end

				mergeKeyboardScheme(controls.keyboardScheme);

			case Gamepad(id):
				gamepadsAdded.push(id);
			case Keys:
				mergeKeyboardScheme(controls.keyboardScheme);
		}
	}

	inline public function copyTo(controls:Controls, ?device:Device)
	{
		controls.copyFrom(this, device);
	}

	function mergeKeyboardScheme(scheme:KeyboardScheme):Void
	{
		if (scheme != None)
		{
			switch (keyboardScheme)
			{
				case None:
					keyboardScheme = scheme;
				default:
					keyboardScheme = Custom;
			}
		}
	}

	/**
	 * Sets all actions that pertain to the binder to trigger when the supplied keys are used.
	 * If binder is a literal you can inline this
	 */
	public function bindKeys(control:Control, keys:Array<FlxKey>)
	{
		#if (haxe >= "4.0.0")
		inline forEachBound(control, (action, state) -> addKeys(action, keys, state));
		#else
		forEachBound(control, function(action, state) addKeys(action, keys, state));
		#end
	}

	/**
	 * Sets all actions that pertain to the binder to trigger when the supplied keys are used.
	 * If binder is a literal you can inline this
	 */
	public function unbindKeys(control:Control, keys:Array<FlxKey>)
	{
		#if (haxe >= "4.0.0")
		inline forEachBound(control, (action, _) -> removeKeys(action, keys));
		#else
		forEachBound(control, function(action, _) removeKeys(action, keys));
		#end
	}

	inline static function addKeys(action:FlxActionDigital, keys:Array<FlxKey>, state:FlxInputState)
	{
		for (key in keys)
			action.addKey(key, state);
	}

	static function removeKeys(action:FlxActionDigital, keys:Array<FlxKey>)
	{
		var i = action.inputs.length;
		while (i-- > 0)
		{
			var input = action.inputs[i];
			if (input.device == KEYBOARD && keys.indexOf(cast input.inputID) != -1)
				action.remove(input);
		}
	}

	public function setKeyboardScheme(scheme:KeyboardScheme, reset = true)
	{
		removeKeyboard();

		keyboardScheme = scheme;
		
		//Suffer :3

		#if (haxe >= "4.0.0")
		switch (scheme)
		{
			case Solo:
				inline bindKeys(Control.LEFT, SaveData.getData(CUSTOM_UI_KEYBINDS)[0]);
				inline bindKeys(Control.DOWN, SaveData.getData(CUSTOM_UI_KEYBINDS)[1]);
				inline bindKeys(Control.UP, SaveData.getData(CUSTOM_UI_KEYBINDS)[2]);
				inline bindKeys(Control.RIGHT, SaveData.getData(CUSTOM_UI_KEYBINDS)[3]);
				inline bindKeys(Control.GAME_UP, [J, FlxKey.UP]);
				inline bindKeys(Control.GAME_DOWN, [F, FlxKey.DOWN]);
				inline bindKeys(Control.GAME_LEFT, [D, FlxKey.LEFT]);
				inline bindKeys(Control.GAME_RIGHT, [K, FlxKey.RIGHT]);
				inline bindKeys(Control.ACCEPT, [FlxKey.SPACE, ENTER]);
				inline bindKeys(Control.BACK, [ESCAPE, BACKSPACE]);
				inline bindKeys(Control.PAUSE, [ENTER, ESCAPE]);
				inline bindKeys(Control.RESET, [R]);
				inline bindKeys(Control.CHEAT, []);
			case Duo(true):
				inline bindKeys(Control.LEFT, SaveData.getData(CUSTOM_UI_KEYBINDS)[0]);
				inline bindKeys(Control.DOWN, SaveData.getData(CUSTOM_UI_KEYBINDS)[1]);
				inline bindKeys(Control.UP, SaveData.getData(CUSTOM_UI_KEYBINDS)[2]);
				inline bindKeys(Control.RIGHT, SaveData.getData(CUSTOM_UI_KEYBINDS)[3]);
				inline bindKeys(Control.GAME_UP, [W, FlxKey.UP]);
				inline bindKeys(Control.GAME_DOWN, [S, FlxKey.DOWN]);
				inline bindKeys(Control.GAME_LEFT, [A, FlxKey.LEFT]);
				inline bindKeys(Control.GAME_RIGHT, [D, FlxKey.RIGHT]);
				inline bindKeys(Control.ACCEPT, [FlxKey.SPACE, ENTER]);
				inline bindKeys(Control.BACK, [ESCAPE, BACKSPACE]);
				inline bindKeys(Control.PAUSE, [ENTER, ESCAPE]);
				inline bindKeys(Control.RESET, [R]);
				inline bindKeys(Control.CHEAT, []);
			case Duo(false):
				inline bindKeys(Control.LEFT, SaveData.getData(CUSTOM_UI_KEYBINDS)[0]);
				inline bindKeys(Control.DOWN, SaveData.getData(CUSTOM_UI_KEYBINDS)[1]);
				inline bindKeys(Control.UP, SaveData.getData(CUSTOM_UI_KEYBINDS)[2]);
				inline bindKeys(Control.RIGHT, SaveData.getData(CUSTOM_UI_KEYBINDS)[3]);
				inline bindKeys(Control.GAME_UP, [ONE, NUMPADONE, FlxKey.UP]);
				inline bindKeys(Control.GAME_DOWN, [X, FlxKey.DOWN]);
				inline bindKeys(Control.GAME_LEFT, [Z, FlxKey.LEFT]);
				inline bindKeys(Control.GAME_RIGHT, [TWO, NUMPADTWO, FlxKey.RIGHT]);
				inline bindKeys(Control.ACCEPT, [FlxKey.SPACE, ENTER]);
				inline bindKeys(Control.BACK, [ESCAPE, BACKSPACE, P]);
				inline bindKeys(Control.PAUSE, [ENTER, ESCAPE]);
				inline bindKeys(Control.RESET, [R]);
				inline bindKeys(Control.CHEAT, []);
			case None: // nothing
			case Custom:
				inline bindKeys(Control.LEFT, SaveData.getData(CUSTOM_UI_KEYBINDS)[0]);
				inline bindKeys(Control.DOWN, SaveData.getData(CUSTOM_UI_KEYBINDS)[1]);
				inline bindKeys(Control.UP, SaveData.getData(CUSTOM_UI_KEYBINDS)[2]);
				inline bindKeys(Control.RIGHT, SaveData.getData(CUSTOM_UI_KEYBINDS)[3]);
				inline bindKeys(Control.GAME_LEFT, SaveData.getData(CUSTOM_KEYBINDS)[0]);
				inline bindKeys(Control.GAME_DOWN, SaveData.getData(CUSTOM_KEYBINDS)[1]);
				inline bindKeys(Control.GAME_UP, SaveData.getData(CUSTOM_KEYBINDS)[2]);
				inline bindKeys(Control.GAME_RIGHT, SaveData.getData(CUSTOM_KEYBINDS)[3]);
				inline bindKeys(Control.ACCEPT, [SaveData.getData(CUSTOM_UI_KEYBINDS)[4][0], SaveData.getData(CUSTOM_UI_KEYBINDS)[5][0]]);
				inline bindKeys(Control.BACK, [SaveData.getData(CUSTOM_UI_KEYBINDS)[6][0], SaveData.getData(CUSTOM_UI_KEYBINDS)[7][0]]);
				inline bindKeys(Control.PAUSE, [ENTER, ESCAPE]);
				inline bindKeys(Control.RESET, [R]);
				inline bindKeys(Control.CHEAT, []);
		}

		inline bindKeys(Control.GAME_SPACE, SaveData.getData(CUSTOM_KEYBINDS)[4]);
		inline bindKeys(Control.SPACE, SaveData.getData(CUSTOM_KEYBINDS)[4]);
		#end
	}

	function removeKeyboard()
	{
		for (action in this.digitalActions)
		{
			var i = action.inputs.length;
			while (i-- > 0)
			{
				var input = action.inputs[i];
				if (input.device == KEYBOARD)
					action.remove(input);
			}
		}
	}

	public function addGamepad(id:Int, ?buttonMap:Map<Control, Array<FlxGamepadInputID>>):Void
	{
		gamepadsAdded.push(id);
		
		#if (haxe >= "4.0.0")
		for (control => buttons in buttonMap)
			inline bindButtons(control, id, buttons);
		#else
		for (control in buttonMap.keys())
			bindButtons(control, id, buttonMap[control]);
		#end
	}

	inline function addGamepadLiteral(id:Int, ?buttonMap:Map<Control, Array<FlxGamepadInputID>>):Void
	{
		gamepadsAdded.push(id);

		#if (haxe >= "4.0.0")
		for (control => buttons in buttonMap)
			inline bindButtons(control, id, buttons);
		#else
		for (control in buttonMap.keys())
			bindButtons(control, id, buttonMap[control]);
		#end
	}

	public function removeGamepad(deviceID:Int = FlxInputDeviceID.ALL):Void
	{
		for (action in this.digitalActions)
		{
			var i = action.inputs.length;
			while (i-- > 0)
			{
				var input = action.inputs[i];
				if (input.device == GAMEPAD && (deviceID == FlxInputDeviceID.ALL || input.deviceID == deviceID))
					action.remove(input);
			}
		}

		gamepadsAdded.remove(deviceID);
	}

	public function addDefaultGamepad(id):Void
	{
		#if !switch
		addGamepadLiteral(id, [
			Control.ACCEPT => [A],
			Control.BACK => [B],
			Control.UP => [DPAD_UP, LEFT_STICK_DIGITAL_UP],
			Control.DOWN => [DPAD_DOWN, LEFT_STICK_DIGITAL_DOWN],
			Control.LEFT => [DPAD_LEFT, LEFT_STICK_DIGITAL_LEFT],
			Control.RIGHT => [DPAD_RIGHT, LEFT_STICK_DIGITAL_RIGHT],
			Control.GAME_LEFT => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[0]],
			Control.GAME_DOWN => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[1]],
			Control.GAME_UP => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[2]],
			Control.GAME_RIGHT => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[3]],
			Control.GAME_SPACE => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[4]],
			Control.PAUSE => [START],
			Control.RESET => [Y]
		]);
		#else
		addGamepadLiteral(id, [
			//Swap A and B for switch
			Control.ACCEPT => [B],
			Control.BACK => [A],
			Control.UP => [DPAD_UP, LEFT_STICK_DIGITAL_UP, RIGHT_STICK_DIGITAL_UP],
			Control.DOWN => [DPAD_DOWN, LEFT_STICK_DIGITAL_DOWN, RIGHT_STICK_DIGITAL_DOWN],
			Control.LEFT => [DPAD_LEFT, LEFT_STICK_DIGITAL_LEFT, RIGHT_STICK_DIGITAL_LEFT],
			Control.RIGHT => [DPAD_RIGHT, LEFT_STICK_DIGITAL_RIGHT, RIGHT_STICK_DIGITAL_RIGHT],
			Control.GAME_LEFT => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[0]],
			Control.GAME_DOWN => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[1]],
			Control.GAME_UP => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[2]],
			Control.GAME_RIGHT => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[3]],
			Control.GAME_SPACE => [SaveData.getData(CUSTOM_GAMEPAD_BINDS)[4]],
			Control.PAUSE => [START],
			//Swap Y and X for switch
			Control.RESET => [Y],
		]);
		#end
	}

	/**
	 * Sets all actions that pertain to the binder to trigger when the supplied keys are used.
	 * If binder is a literal you can inline this
	 */
	public function bindButtons(control:Control, id, buttons)
	{
		#if (haxe >= "4.0.0")
		inline forEachBound(control, (action, state) -> addButtons(action, buttons, state, id));
		#else
		forEachBound(control, function(action, state) addButtons(action, buttons, state, id));
		#end
	}

	/**
	 * Sets all actions that pertain to the binder to trigger when the supplied keys are used.
	 * If binder is a literal you can inline this
	 */
	public function unbindButtons(control:Control, gamepadID:Int, buttons)
	{
		#if (haxe >= "4.0.0")
		inline forEachBound(control, (action, _) -> removeButtons(action, gamepadID, buttons));
		#else
		forEachBound(control, function(action, _) removeButtons(action, gamepadID, buttons));
		#end
	}

	inline static function addButtons(action:FlxActionDigital, buttons:Array<FlxGamepadInputID>, state, id)
	{
		for (button in buttons)
			action.addGamepad(button, state, id);
	}

	static function removeButtons(action:FlxActionDigital, gamepadID:Int, buttons:Array<FlxGamepadInputID>)
	{
		var i = action.inputs.length;
		while (i-- > 0)
		{
			var input = action.inputs[i];
			if (isGamepad(input, gamepadID) && buttons.indexOf(cast input.inputID) != -1)
				action.remove(input);
		}
	}

	public function getInputsFor(control:Control, device:Device, ?list:Array<Int>):Array<Int>
	{
		if (list == null)
			list = [];

		switch (device)
		{
			case Keys:
				for (input in getActionFromControl(control).inputs)
				{
					if (input.device == KEYBOARD)
						list.push(input.inputID);
				}
			case Gamepad(id):
				for (input in getActionFromControl(control).inputs)
				{
					if (input.deviceID == id)
						list.push(input.inputID);
				}
		}
		return list;
	}

	public function removeDevice(device:Device)
	{
		switch (device)
		{
			case Keys:
				setKeyboardScheme(None);
			case Gamepad(id):
				removeGamepad(id);
		}
	}

	static function isDevice(input:FlxActionInput, device:Device)
	{
		return switch device
		{
			case Keys: input.device == KEYBOARD;
			case Gamepad(id): isGamepad(input, id);
		}
	}

	inline static function isGamepad(input:FlxActionInput, deviceID:Int)
	{
		return input.device == GAMEPAD && (deviceID == FlxInputDeviceID.ALL || input.deviceID == deviceID);
	}
}
