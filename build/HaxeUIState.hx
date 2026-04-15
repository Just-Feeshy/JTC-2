package;

import haxe.ui.components.CheckBox;
import haxe.ui.containers.menus.MenuCheckBox;
import haxe.ui.containers.menus.MenuItem;
import haxe.ui.core.Component;
import haxe.ui.core.Screen;
import haxe.ui.events.MouseEvent;
import haxe.ui.events.UIEvent;
import haxe.ui.RuntimeComponentBuilder;
import lime.app.Application;

using StringTools;

class HaxeUIState extends MusicBeatState
{
	public var component:Component;

	var componentKey:String;

	public function new(key:String)
	{
		super();
		componentKey = key;
	}

	override function create():Void
	{
		super.create();

		if(component == null) {
			component = buildComponent(componentKey);
		}

		if(component != null) {
			Screen.instance.addComponent(component);
			component.validateNow();
		}
	}

	public function buildComponent(assetPath:String):Component
	{
		try {
			return RuntimeComponentBuilder.fromAsset(assetPath);
		} catch(_:Dynamic) {}

		var data:String = Paths.readText(assetPath);

		if(data != null && data.trim() != "") {
			try {
				return RuntimeComponentBuilder.fromString(data);
			} catch(e:Dynamic) {
				Application.current.window.alert('Error building component "$assetPath": $e', "HaxeUI Parsing Error");
				return null;
			}
		}

		Application.current.window.alert('Error building component "$assetPath": asset was not found.', "HaxeUI Parsing Error");
		return null;
	}

	public var contextMenu:Component;

	function showContextMenu(assetPath:String, xPos:Float, yPos:Float):Component
	{
		if(contextMenu != null) {
			contextMenu.destroy();
		}

		contextMenu = buildComponent(assetPath);

		if(contextMenu != null) {
			contextMenu.left = xPos;
			contextMenu.top = yPos;
			Screen.instance.addComponent(contextMenu);
		}

		return contextMenu;
	}

	public function registerContextMenu(target:Null<Component>, assetPath:String):Void
	{
		if(target == null) {
			Screen.instance.registerEvent(MouseEvent.RIGHT_CLICK, function(e:MouseEvent) {
				showContextMenu(assetPath, e.screenX, e.screenY);
			});
			return;
		}

		target.registerEvent(MouseEvent.RIGHT_CLICK, function(e:MouseEvent) {
			showContextMenu(assetPath, e.screenX, e.screenY);
		});
	}

	function addUIClickListener(key:String, callback:MouseEvent->Void):Void
	{
		var target:Component = findComponent(key);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI component: $key');
			return;
		}

		target.onClick = callback;
	}

	function addUIRightClickListener(key:String, callback:MouseEvent->Void):Void
	{
		var target:Component = findComponent(key);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI component: $key');
			return;
		}

		target.onRightClick = callback;
	}

	function setComponentText(key:String, text:String):Void
	{
		var target:Component = findComponent(key);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI component: $key');
			return;
		}

		target.text = text;
	}

	function setComponentShortcutText(key:String, text:String):Void
	{
		var target:MenuItem = findComponent(key, MenuItem);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI menu item: $key');
			return;
		}

		target.shortcutText = text;
	}

	function addTooltip(key:String, text:String):Void
	{
		var target:Component = findComponent(key);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI component: $key');
			return;
		}

		target.tooltip = text;
	}

	function addUIChangeListener(key:String, callback:UIEvent->Void):Void
	{
		var target:Component = findComponent(key);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI component: $key');
			return;
		}

		target.onChange = callback;
	}

	function setUIValue<T>(key:String, value:T):T
	{
		var target:Component = findComponent(key);

		if(target == null) {
			trace('WARN: Could not locate HaxeUI component: $key');
			return value;
		}

		return target.value = value;
	}

	public function setUICheckboxSelected(key:String, value:Bool):Bool
	{
		var targetA:CheckBox = findComponent(key, CheckBox);

		if(targetA != null) {
			return targetA.selected = value;
		}

		var targetB:MenuCheckBox = findComponent(key, MenuCheckBox);

		if(targetB != null) {
			return targetB.selected = value;
		}

		trace('WARN: Could not locate HaxeUI checkbox: $key');
		return value;
	}

	public function findComponent<T:Component>(criteria:String = null, type:Class<T> = null, recursive:Null<Bool> = null, searchType:String = "id"):Null<T>
	{
		if(component == null) {
			return null;
		}

		return component.findComponent(criteria, type, recursive == null ? true : recursive, searchType);
	}

	override function destroy():Void
	{
		if(component != null) {
			Screen.instance.removeComponent(component, false);
			component = null;
		}

		super.destroy();
	}
}
