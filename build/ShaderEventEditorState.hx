package;

#if desktop
import Discord.DiscordClient;
#end

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUITabMenu;
import flixel.math.FlxMath;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import haxe.Json;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.net.FileReference;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFLAssets;

using StringTools;

class ShaderEventEditorState extends MusicBeatState
{
	private static inline var MODE_RIM:String = "Rim Shadow Event";
	private static inline var MODE_COLOR:String = "Color Adjust Event";

	private var camHUD:FlxCamera;
	private var camGame:FlxCamera;
	private var camFollow:FlxObject;
	private var uiTabs:FlxUITabMenu;
	private var previewCharacter:Character;
	private var fileRef:FileReference;

	private var availableCharacters:Array<String> = [];
	private var currentPreviewCharacter:String = "bf";
	private var exportTarget:String = "boyfriend";
	private var previewMode:String = MODE_RIM;
	private var lastControlSignature:String = "";

	private var previewCharacterDropDown:FlxUIDropDownMenu;
	private var targetDropDown:FlxUIDropDownMenu;
	private var previewModeDropDown:FlxUIDropDownMenu;
	private var animationDropDown:FlxUIDropDownMenu;
	private var applyPreviewCheck:FlxUICheckBox;

	private var rimEnabledCheck:FlxUICheckBox;
	private var rimHexInput:FlxUIInputText;
	private var rimAngleStepper:FlxUINumericStepper;
	private var rimDistanceStepper:FlxUINumericStepper;
	private var rimThresholdStepper:FlxUINumericStepper;
	private var rimBrightnessStepper:FlxUINumericStepper;
	private var rimHueStepper:FlxUINumericStepper;
	private var rimContrastStepper:FlxUINumericStepper;
	private var rimSaturationStepper:FlxUINumericStepper;

	private var colorEnabledCheck:FlxUICheckBox;
	private var colorBrightnessStepper:FlxUINumericStepper;
	private var colorHueStepper:FlxUINumericStepper;
	private var colorContrastStepper:FlxUINumericStepper;
	private var colorSaturationStepper:FlxUINumericStepper;

	private var instructionsText:FlxText;
	private var statusText:FlxText;
	private var exportInfoText:FlxText;
	private var exportValueOneText:FlxText;
	private var exportValueTwoText:FlxText;
	private var exportComponentText:FlxText;

	override function create():Void
	{
		camHUD = new FlxCamera();
		camGame = new FlxCamera();
		camHUD.bgColor.alpha = 0;
		camGame.bgColor.alpha = 0;

		FlxG.cameras.reset(camGame);
		FlxG.cameras.add(camHUD);
		FlixelCompat.setDefaultCameras([camHUD]);

		loadCharacterList();
		setupPreviewScene();
		createUi();
		reloadPreviewCharacter(currentPreviewCharacter);
		refreshPreviewAndExport();

		#if desktop
		DiscordClient.changePresence("Shader Event Editor", null);
		#end

		super.create();
	}

	private function loadCharacterList():Void
	{
		var rawList:Array<String> = OpenFLAssets.list(TEXT);

		for(path in rawList) {
			if(path == null) {
				continue;
			}

			if(path.startsWith("mod_assets/characters/")
				|| path.startsWith("assets/characters/")
				|| path.startsWith("funkin_assets/preload/data/characters/")) {
				var fileName:String = path.split("/").pop();

				if(fileName != null && fileName.endsWith(".json")) {
					var characterName:String = fileName.substr(0, fileName.length - 5);

					if(!availableCharacters.contains(characterName)) {
						availableCharacters.push(characterName);
					}
				}
			}
		}

		availableCharacters.sort(Reflect.compare);

		if(availableCharacters.length <= 0) {
			availableCharacters = ["bf"];
		}

		if(availableCharacters.contains("bf")) {
			currentPreviewCharacter = "bf";
		} else {
			currentPreviewCharacter = availableCharacters[0];
		}
	}

	private function setupPreviewScene():Void
	{
		var bg:FlxSprite = new FlxSprite(-600, -200).loadGraphic(Paths.image("stageback"));
		bg.antialiasing = true;
		bg.active = false;
		bg.cameras = [camGame];
		add(bg);

		var stageFront:FlxSprite = new FlxSprite(-650, 600).loadGraphic(Paths.image("stagefront"));
		stageFront.setGraphicSize(Std.int(stageFront.width * 1.1));
		stageFront.updateHitbox();
		stageFront.antialiasing = true;
		stageFront.active = false;
		stageFront.cameras = [camGame];
		add(stageFront);

		var stageCurtains:FlxSprite = new FlxSprite(-500, -300).loadGraphic(Paths.image("stagecurtains"));
		stageCurtains.setGraphicSize(Std.int(stageCurtains.width * 0.9));
		stageCurtains.updateHitbox();
		stageCurtains.antialiasing = true;
		stageCurtains.active = false;
		stageCurtains.cameras = [camGame];
		add(stageCurtains);

		camFollow = new FlxObject(0, 0, 1, 1);
		add(camFollow);

		camGame.zoom = 0.9;
		camGame.follow(camFollow, LOCKON, 0.04);

		instructionsText = new FlxText(8, 16, 0, "ESC - Back | Mouse Wheel/Q/E - Zoom");
		instructionsText.cameras = [camHUD];
		add(instructionsText);

		statusText = new FlxText(8, 42, Std.int(FlxG.width * 0.48), "");
		statusText.cameras = [camHUD];
		add(statusText);
	}

	private function createUi():Void
	{
		var tabs = [
			{name: "Preview", label: "Preview"},
			{name: "Rim", label: "Rim Shadow"},
			{name: "Color", label: "Color Adjust"},
			{name: "Export", label: "Export"}
		];

		uiTabs = new FlxUITabMenu(null, tabs, true);
		uiTabs.resize(430, 470);
		uiTabs.x = Std.int(FlxG.width - uiTabs.width - 40);
		uiTabs.screenCenter(Y);
		uiTabs.scrollFactor.set();
		uiTabs.cameras = [camHUD];
		add(uiTabs);

		createPreviewTab();
		createRimTab();
		createColorTab();
		createExportTab();
	}

	private function createPreviewTab():Void
	{
		var tab = new FlxUI(null, uiTabs);
		tab.name = "Preview";

		tab.add(new FlxText(10, 10, 0, "Preview Character"));
		previewCharacterDropDown = new FlxUIDropDownMenu(10, 28, FlxUIDropDownMenu.makeStrIdLabelArray(availableCharacters, true), function(index:String) {
			var selectedIndex:Null<Int> = Std.parseInt(index);

			if(selectedIndex != null && selectedIndex >= 0 && selectedIndex < availableCharacters.length) {
				currentPreviewCharacter = availableCharacters[selectedIndex];
				reloadPreviewCharacter(currentPreviewCharacter);
				refreshPreviewAndExport();
			}
		});
		previewCharacterDropDown.selectedLabel = currentPreviewCharacter;
		tab.add(previewCharacterDropDown);

		tab.add(new FlxText(10, 70, 0, "Runtime Target"));
		targetDropDown = new FlxUIDropDownMenu(10, 88, FlxUIDropDownMenu.makeStrIdLabelArray(["boyfriend", "dad", "girlfriend"], true), function(index:String) {
			var labels = ["boyfriend", "dad", "girlfriend"];
			var selectedIndex:Null<Int> = Std.parseInt(index);

			if(selectedIndex != null && selectedIndex >= 0 && selectedIndex < labels.length) {
				exportTarget = labels[selectedIndex];
				refreshPreviewAndExport();
			}
		});
		targetDropDown.selectedLabel = exportTarget;
		tab.add(targetDropDown);

		tab.add(new FlxText(10, 130, 0, "Preview Mode"));
		previewModeDropDown = new FlxUIDropDownMenu(10, 148, FlxUIDropDownMenu.makeStrIdLabelArray([MODE_RIM, MODE_COLOR], true), function(index:String) {
			var labels = [MODE_RIM, MODE_COLOR];
			var selectedIndex:Null<Int> = Std.parseInt(index);

			if(selectedIndex != null && selectedIndex >= 0 && selectedIndex < labels.length) {
				previewMode = labels[selectedIndex];
				refreshPreviewAndExport();
			}
		});
		previewModeDropDown.selectedLabel = previewMode;
		tab.add(previewModeDropDown);

		applyPreviewCheck = new FlxUICheckBox(10, 188, null, null, "Apply Preview Shader", 120);
		applyPreviewCheck.checked = true;
		applyPreviewCheck.callback = function() {
			refreshPreviewAndExport();
		};
		tab.add(applyPreviewCheck);

		tab.add(new FlxText(10, 224, 0, "Animation"));
		animationDropDown = new FlxUIDropDownMenu(10, 242, FlxUIDropDownMenu.makeStrIdLabelArray(["idle"], true), function(index:String) {
			var selectedIndex:Null<Int> = Std.parseInt(index);
			var names = getPreviewAnimationNames();

			if(selectedIndex != null && selectedIndex >= 0 && selectedIndex < names.length) {
				playPreviewAnimation(names[selectedIndex]);
			}
		});
		tab.add(animationDropDown);

		var idleButton = new FlxUIButton(10, 292, "Idle", function() {
			playPreviewAnimation("idle");
		});
		var leftButton = new FlxUIButton(90, 292, "Left", function() {
			playPreviewAnimation("singLEFT");
		});
		var downButton = new FlxUIButton(170, 292, "Down", function() {
			playPreviewAnimation("singDOWN");
		});
		var upButton = new FlxUIButton(250, 292, "Up", function() {
			playPreviewAnimation("singUP");
		});
		var rightButton = new FlxUIButton(330, 292, "Right", function() {
			playPreviewAnimation("singRIGHT");
		});
		var danceButton = new FlxUIButton(10, 332, "Dance", function() {
			if(previewCharacter != null) {
				previewCharacter.dance(true);
			}
		});
		var clearButton = new FlxUIButton(90, 332, "Clear Shader", function() {
			if(previewCharacter != null) {
				previewCharacter.shader = null;
			}
		});

		tab.add(idleButton);
		tab.add(leftButton);
		tab.add(downButton);
		tab.add(upButton);
		tab.add(rightButton);
		tab.add(danceButton);
		tab.add(clearButton);

		uiTabs.addGroup(tab);
	}

	private function createRimTab():Void
	{
		var tab = new FlxUI(null, uiTabs);
		tab.name = "Rim";

		rimEnabledCheck = new FlxUICheckBox(10, 10, null, null, "Enabled", 80);
		rimEnabledCheck.checked = true;
		rimEnabledCheck.callback = function() {
			refreshPreviewAndExport();
		};
		tab.add(rimEnabledCheck);

		tab.add(new FlxText(10, 42, 0, "Hex Color"));
		rimHexInput = new FlxUIInputText(10, 60, 140, "D46B00", 8);
		tab.add(rimHexInput);

		rimAngleStepper = addStepper(tab, "Angle", 10, 104, 1, 125, 0, 360);
		rimDistanceStepper = addStepper(tab, "Distance", 10, 144, 0.5, 12, 0, 64, 1);
		rimThresholdStepper = addStepper(tab, "Threshold", 10, 184, 0.01, 0.15, 0, 1, 2);
		rimBrightnessStepper = addStepper(tab, "Brightness", 10, 224, 1, -35, -100, 100);
		rimHueStepper = addStepper(tab, "Hue", 10, 264, 1, -15, -100, 100);
		rimContrastStepper = addStepper(tab, "Contrast", 10, 304, 1, 10, -100, 100);
		rimSaturationStepper = addStepper(tab, "Saturation", 10, 344, 1, -20, -100, 100);

		uiTabs.addGroup(tab);
	}

	private function createColorTab():Void
	{
		var tab = new FlxUI(null, uiTabs);
		tab.name = "Color";

		colorEnabledCheck = new FlxUICheckBox(10, 10, null, null, "Enabled", 80);
		colorEnabledCheck.checked = true;
		colorEnabledCheck.callback = function() {
			refreshPreviewAndExport();
		};
		tab.add(colorEnabledCheck);

		colorBrightnessStepper = addStepper(tab, "Brightness", 10, 54, 1, 0, -100, 100);
		colorHueStepper = addStepper(tab, "Hue", 10, 94, 1, 0, -100, 100);
		colorContrastStepper = addStepper(tab, "Contrast", 10, 134, 1, 0, -100, 100);
		colorSaturationStepper = addStepper(tab, "Saturation", 10, 174, 1, 0, -100, 100);

		uiTabs.addGroup(tab);
	}

	private function createExportTab():Void
	{
		var tab = new FlxUI(null, uiTabs);
		tab.name = "Export";

		exportInfoText = new FlxText(10, 10, uiTabs.width - 30, "Use these with the chart editor's `v-slice event` entry.");
		exportValueOneText = new FlxText(10, 50, uiTabs.width - 30, "");
		exportValueTwoText = new FlxText(10, 130, uiTabs.width - 30, "");
		exportComponentText = new FlxText(10, 250, uiTabs.width - 30, "");

		tab.add(exportInfoText);
		tab.add(exportValueOneText);
		tab.add(exportValueTwoText);
		tab.add(exportComponentText);

		var savePayloadButton = new FlxUIButton(10, 400, "Save Payload JSON", function() {
			saveExport(buildSelectedPayloadJson(), buildSelectedPayloadFileName());
		});
		var saveComponentButton = new FlxUIButton(150, 400, "Save Component JSON", function() {
			saveExport(buildSelectedComponentJson(), buildSelectedComponentFileName());
		});

		tab.add(savePayloadButton);
		tab.add(saveComponentButton);

		uiTabs.addGroup(tab);
	}

	private function addStepper(tab:FlxUI, label:String, x:Float, y:Float, step:Float, value:Float, min:Float, max:Float, decimals:Int = 0):FlxUINumericStepper
	{
		tab.add(new FlxText(x, y, 0, label));

		var stepper = new FlxUINumericStepper(x + 110, y - 2, step, value, min, max, decimals);
		tab.add(stepper);
		return stepper;
	}

	private function reloadPreviewCharacter(characterName:String):Void
	{
		if(previewCharacter != null) {
			remove(previewCharacter, true);
			previewCharacter.destroy();
			previewCharacter = null;
		}

		previewCharacter = new Character(440, 100, characterName, false);
		previewCharacter.cameras = [camGame];
		add(previewCharacter);

		var followX:Float = previewCharacter.getGraphicMidpoint().x;
		var followY:Float = previewCharacter.getGraphicMidpoint().y;
		camFollow.setPosition(followX, followY);
		camGame.focusOn(camFollow.getPosition());

		rebuildAnimationDropDown();
	}

	private function rebuildAnimationDropDown():Void
	{
		if(animationDropDown == null) {
			return;
		}

		var animationNames = getPreviewAnimationNames();
		animationDropDown.setData(FlxUIDropDownMenu.makeStrIdLabelArray(animationNames, true));

		if(animationNames.length > 0) {
			animationDropDown.selectedLabel = animationNames[0];
		}
	}

	private function getPreviewAnimationNames():Array<String>
	{
		if(previewCharacter == null || previewCharacter.animations == null || previewCharacter.animations.length <= 0) {
			return ["idle"];
		}

		return previewCharacter.animations.copy();
	}

	private function playPreviewAnimation(animName:String):Void
	{
		if(previewCharacter == null || animName == null || animName.trim() == "") {
			return;
		}

		if(animName == "dance") {
			previewCharacter.dance(true);
			return;
		}

		if(previewCharacter.hasAnimation(animName)) {
			previewCharacter.playAnim(animName, true);
		} else if(previewCharacter.hasAnimation(previewCharacter._info.playAnim)) {
			previewCharacter.playAnim(previewCharacter._info.playAnim, true);
		} else {
			previewCharacter.dance(true);
		}
	}

	private function refreshPreviewAndExport():Void
	{
		if(previewCharacter == null) {
			return;
		}

		if(!applyPreviewCheck.checked) {
			previewCharacter.shader = null;
		} else if(previewMode == MODE_COLOR) {
			if(colorEnabledCheck.checked) {
				var colorShader = new AdjustColorShader();
				colorShader.brightness = colorBrightnessStepper.value;
				colorShader.hue = colorHueStepper.value;
				colorShader.contrast = colorContrastStepper.value;
				colorShader.saturation = colorSaturationStepper.value;
				previewCharacter.shader = colorShader;
			} else {
				previewCharacter.shader = null;
			}
		} else {
			if(rimEnabledCheck.checked) {
				var rimShader = new RimShadowShader();
				rimShader.color = parseHexColor(rimHexInput.text, 0xFFD46B00);
				rimShader.angle = rimAngleStepper.value;
				rimShader.distance = rimDistanceStepper.value;
				rimShader.threshold = rimThresholdStepper.value;
				rimShader.brightness = rimBrightnessStepper.value;
				rimShader.hue = rimHueStepper.value;
				rimShader.contrast = rimContrastStepper.value;
				rimShader.saturation = rimSaturationStepper.value;
				rimShader.updateFrameInfo(previewCharacter.frame);
				previewCharacter.shader = rimShader;
			} else {
				previewCharacter.shader = null;
			}
		}

		statusText.text = 'Preview: ' + previewMode
			+ '\nCharacter: ' + currentPreviewCharacter
			+ '\nTarget: ' + exportTarget;

		refreshExportText();
	}

	private function refreshExportText():Void
	{
		var kind = getSelectedEventKind();
		var payloadJson = buildSelectedPayloadJson();
		var componentJson = buildSelectedComponentJson();

		exportValueOneText.text = 'Chart Event: v-slice event\nValue 1: ' + kind;
		exportValueTwoText.text = 'Value 2:\n' + payloadJson;
		exportComponentText.text = 'Single-field component JSON:\n' + componentJson;
	}

	private function buildSelectedPayloadJson():String
	{
		return Json.stringify(previewMode == MODE_COLOR ? buildColorPayload() : buildRimPayload());
	}

	private function buildSelectedComponentJson():String
	{
		return Json.stringify({
			e: getSelectedEventKind(),
			v: previewMode == MODE_COLOR ? buildColorPayload() : buildRimPayload()
		});
	}

	private function getSelectedEventKind():String
	{
		return previewMode == MODE_COLOR ? "ColorAdjustEvent" : "RimShadowEvent";
	}

	private function buildRimPayload():Dynamic
	{
		return {
			target: exportTarget,
			enabled: rimEnabledCheck.checked,
			hexcolor: normalizeHexColor(rimHexInput.text, "D46B00"),
			angle: rimAngleStepper.value,
			distance: rimDistanceStepper.value,
			threshold: rimThresholdStepper.value,
			brightness: rimBrightnessStepper.value,
			hue: rimHueStepper.value,
			contrast: rimContrastStepper.value,
			saturation: rimSaturationStepper.value
		};
	}

	private function buildColorPayload():Dynamic
	{
		return {
			target: exportTarget,
			enabled: colorEnabledCheck.checked,
			brightness: colorBrightnessStepper.value,
			hue: colorHueStepper.value,
			contrast: colorContrastStepper.value,
			saturation: colorSaturationStepper.value
		};
	}

	private function buildSelectedPayloadFileName():String
	{
		return previewMode == MODE_COLOR ? "color-adjust-payload.json" : "rim-shadow-payload.json";
	}

	private function buildSelectedComponentFileName():String
	{
		return previewMode == MODE_COLOR ? "color-adjust-event.json" : "rim-shadow-event.json";
	}

	private function saveExport(data:String, fileName:String):Void
	{
		fileRef = new FileReference();
		fileRef.addEventListener(Event.COMPLETE, onSaveComplete);
		fileRef.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
		fileRef.save(data, fileName);
	}

	private function onSaveComplete(event:Event):Void
	{
		statusText.text += "\nSaved export file.";
		cleanupFileRef(cast(event.target, FileReference));
	}

	private function onSaveError(event:IOErrorEvent):Void
	{
		statusText.text += "\nFailed to save export file.";
		cleanupFileRef(cast(event.target, FileReference));
	}

	private function cleanupFileRef(target:FileReference):Void
	{
		if(target == null) {
			return;
		}

		target.removeEventListener(Event.COMPLETE, onSaveComplete);
		target.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);

		if(fileRef == target) {
			fileRef = null;
		}
	}

	private function normalizeHexColor(value:String, fallback:String):String
	{
		var cleaned:String = value != null ? value.trim().toUpperCase() : fallback;

		if(cleaned.startsWith("#")) {
			cleaned = cleaned.substr(1);
		}

		if(cleaned.length == 8) {
			cleaned = cleaned.substr(2);
		}

		return cleaned.length == 6 ? cleaned : fallback;
	}

	private function parseHexColor(value:String, fallback:Int):Int
	{
		var cleaned:String = value != null ? value.trim() : "";

		if(cleaned.startsWith("#")) {
			cleaned = cleaned.substr(1);
		}

		if(cleaned.length == 6) {
			cleaned = "FF" + cleaned;
		}

		if(cleaned.length != 8) {
			return fallback;
		}

		var parsed:Null<Int> = Std.parseInt("0x" + cleaned);
		return parsed == null ? fallback : parsed;
	}

	private function buildControlSignature():String
	{
		return [
			currentPreviewCharacter,
			exportTarget,
			previewMode,
			previewCharacter != null && previewCharacter.animation.curAnim != null ? previewCharacter.animation.curAnim.name : "",
			applyPreviewCheck != null ? Std.string(applyPreviewCheck.checked) : "",
			rimEnabledCheck != null ? Std.string(rimEnabledCheck.checked) : "",
			rimHexInput != null ? rimHexInput.text : "",
			rimAngleStepper != null ? Std.string(rimAngleStepper.value) : "",
			rimDistanceStepper != null ? Std.string(rimDistanceStepper.value) : "",
			rimThresholdStepper != null ? Std.string(rimThresholdStepper.value) : "",
			rimBrightnessStepper != null ? Std.string(rimBrightnessStepper.value) : "",
			rimHueStepper != null ? Std.string(rimHueStepper.value) : "",
			rimContrastStepper != null ? Std.string(rimContrastStepper.value) : "",
			rimSaturationStepper != null ? Std.string(rimSaturationStepper.value) : "",
			colorEnabledCheck != null ? Std.string(colorEnabledCheck.checked) : "",
			colorBrightnessStepper != null ? Std.string(colorBrightnessStepper.value) : "",
			colorHueStepper != null ? Std.string(colorHueStepper.value) : "",
			colorContrastStepper != null ? Std.string(colorContrastStepper.value) : "",
			colorSaturationStepper != null ? Std.string(colorSaturationStepper.value) : ""
		].join("|");
	}

	override function update(elapsed:Float):Void
	{
		if(controls.BACK) {
			FlxG.switchState(new OptionsMenuState());
			return;
		}

		if(FlxG.mouse.wheel != 0) {
			camGame.zoom = FlxMath.bound(camGame.zoom + (FlxG.mouse.wheel * 0.05), 0.2, 3.0);
		}

		if(FlxG.keys.pressed.Q) {
			camGame.zoom = FlxMath.bound(camGame.zoom + (elapsed * 0.75), 0.2, 3.0);
		}

		if(FlxG.keys.pressed.E) {
			camGame.zoom = FlxMath.bound(camGame.zoom - (elapsed * 0.75), 0.2, 3.0);
		}

		var signature = buildControlSignature();

		if(signature != lastControlSignature) {
			lastControlSignature = signature;
			refreshPreviewAndExport();
		}

		super.update(elapsed);
	}

	override function destroy():Void
	{
		if(fileRef != null) {
			cleanupFileRef(fileRef);
		}

		super.destroy();
	}
}
