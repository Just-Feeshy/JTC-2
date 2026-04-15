package;

#if desktop
import Discord.DiscordClient;
#end

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.math.FlxMath;
import haxe.Json;
import haxe.ui.backend.flixel.UIState;
import haxe.ui.components.Button;
import haxe.ui.components.CheckBox;
import haxe.ui.components.DropDown;
import haxe.ui.components.Label;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextArea;
import haxe.ui.components.TextField;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.net.FileReference;
import openfl.utils.Assets as OpenFLAssets;

using StringTools;

@:build(haxe.ui.ComponentBuilder.build("assets/preload/data/shader-event-editor.xml"))
class ShaderEventEditorState extends UIState
{
	private static inline var MODE_RIM:String = "Rim Shadow Event";
	private static inline var MODE_COLOR:String = "Color Adjust Event";

	private var camHUD:FlxCamera;
	private var camGame:FlxCamera;
	private var camFollow:FlxObject;
	private var previewCharacter:Character;
	private var fileRef:FileReference;

	private var availableCharacters:Array<String> = [];
	private var currentPreviewCharacter:String = "bf";
	private var exportTarget:String = "boyfriend";
	private var previewMode:String = MODE_RIM;

	var instructionsLabel:Label;
	var statusLabel:Label;
	var eventNameLabel:Label;
	var payloadTextArea:TextArea;
	var componentTextArea:TextArea;
	var handlerTextArea:TextArea;

	var previewCharacterDropDown:DropDown;
	var targetDropDown:DropDown;
	var previewModeDropDown:DropDown;
	var animationDropDown:DropDown;
	var applyPreviewCheck:CheckBox;

	var rimEnabledCheck:CheckBox;
	var rimHexInput:TextField;
	var rimAngleStepper:NumberStepper;
	var rimDistanceStepper:NumberStepper;
	var rimThresholdStepper:NumberStepper;
	var rimBrightnessStepper:NumberStepper;
	var rimHueStepper:NumberStepper;
	var rimContrastStepper:NumberStepper;
	var rimSaturationStepper:NumberStepper;

	var colorEnabledCheck:CheckBox;
	var colorBrightnessStepper:NumberStepper;
	var colorHueStepper:NumberStepper;
	var colorContrastStepper:NumberStepper;
	var colorSaturationStepper:NumberStepper;

	var idleButton:Button;
	var leftButton:Button;
	var downButton:Button;
	var upButton:Button;
	var rightButton:Button;
	var danceButton:Button;
	var clearShaderButton:Button;
	var savePayloadButton:Button;
	var saveComponentButton:Button;

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

		super.create();

		this.root.cameras = [camHUD];

		setupUiState();
		reloadPreviewCharacter(currentPreviewCharacter);
		refreshPreviewAndExport();

		#if desktop
		DiscordClient.changePresence("Shader Event Editor", null);
		#end
	}

	private function loadCharacterList():Void
	{
		var rawList:Array<String> = OpenFLAssets.list(TEXT);

		for(path in rawList) {
			if(path == null) continue;

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

		currentPreviewCharacter = availableCharacters.contains("bf") ? "bf" : availableCharacters[0];
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
	}

	private function setupUiState():Void
	{
		instructionsLabel.text = "ESC - Back | Mouse Wheel/Q/E - Zoom";

		populateDropDown(previewCharacterDropDown, availableCharacters);
		selectDropDownItem(previewCharacterDropDown, currentPreviewCharacter);

		populateDropDown(targetDropDown, ["boyfriend", "dad", "girlfriend"]);
		selectDropDownItem(targetDropDown, exportTarget);

		populateDropDown(previewModeDropDown, [MODE_RIM, MODE_COLOR]);
		selectDropDownItem(previewModeDropDown, previewMode);

		populateDropDown(animationDropDown, ["idle"]);
		selectDropDownItem(animationDropDown, "idle");

		previewCharacterDropDown.onChange = function(_) {
			currentPreviewCharacter = getDropDownValue(previewCharacterDropDown, currentPreviewCharacter);
			reloadPreviewCharacter(currentPreviewCharacter);
			refreshPreviewAndExport();
		};

		targetDropDown.onChange = function(_) {
			exportTarget = getDropDownValue(targetDropDown, exportTarget);
			refreshPreviewAndExport();
		};

		previewModeDropDown.onChange = function(_) {
			previewMode = getDropDownValue(previewModeDropDown, previewMode);
			refreshPreviewAndExport();
		};

		animationDropDown.onChange = function(_) {
			playPreviewAnimation(getDropDownValue(animationDropDown, "idle"));
			refreshPreviewAndExport();
		};

		registerRefreshHandlers();

		idleButton.onClick = function(_) playPreviewAnimation("idle");
		leftButton.onClick = function(_) playPreviewAnimation("singLEFT");
		downButton.onClick = function(_) playPreviewAnimation("singDOWN");
		upButton.onClick = function(_) playPreviewAnimation("singUP");
		rightButton.onClick = function(_) playPreviewAnimation("singRIGHT");

		danceButton.onClick = function(_) {
			if(previewCharacter != null) {
				previewCharacter.dance(true);
				refreshPreviewAndExport();
			}
		};

		clearShaderButton.onClick = function(_) {
			if(previewCharacter != null) {
				previewCharacter.shader = null;
			}
		};

		savePayloadButton.onClick = function(_) {
			saveExport(buildSelectedPayloadJson(), buildSelectedPayloadFileName());
		};

		saveComponentButton.onClick = function(_) {
			saveExport(buildSelectedComponentJson(), buildSelectedComponentFileName());
		};
	}

	private function registerRefreshHandlers():Void
	{
		applyPreviewCheck.onChange = function(_) refreshPreviewAndExport();
		rimEnabledCheck.onChange = function(_) refreshPreviewAndExport();
		rimHexInput.onChange = function(_) refreshPreviewAndExport();
		rimAngleStepper.onChange = function(_) refreshPreviewAndExport();
		rimDistanceStepper.onChange = function(_) refreshPreviewAndExport();
		rimThresholdStepper.onChange = function(_) refreshPreviewAndExport();
		rimBrightnessStepper.onChange = function(_) refreshPreviewAndExport();
		rimHueStepper.onChange = function(_) refreshPreviewAndExport();
		rimContrastStepper.onChange = function(_) refreshPreviewAndExport();
		rimSaturationStepper.onChange = function(_) refreshPreviewAndExport();
		colorEnabledCheck.onChange = function(_) refreshPreviewAndExport();
		colorBrightnessStepper.onChange = function(_) refreshPreviewAndExport();
		colorHueStepper.onChange = function(_) refreshPreviewAndExport();
		colorContrastStepper.onChange = function(_) refreshPreviewAndExport();
		colorSaturationStepper.onChange = function(_) refreshPreviewAndExport();
	}

	private function populateDropDown(dropDown:DropDown, items:Array<String>):Void
	{
		dropDown.dataSource.clear();

		for(item in items) {
			dropDown.dataSource.add({id: item, text: item});
		}
	}

	private function selectDropDownItem(dropDown:DropDown, value:String):Void
	{
		for(index in 0...dropDown.dataSource.size) {
			var item:Dynamic = dropDown.dataSource.get(index);
			var itemId:Dynamic = item != null ? Reflect.field(item, "id") : null;
			var itemText:Dynamic = item != null ? Reflect.field(item, "text") : null;

			if(Std.string(itemId) == value || Std.string(itemText) == value) {
				dropDown.selectedIndex = index;
				return;
			}
		}

		if(dropDown.dataSource.size > 0) {
			dropDown.selectedIndex = 0;
		}
	}

	private function getDropDownValue(dropDown:DropDown, fallback:String):String
	{
		var selected:Dynamic = dropDown.selectedItem;

		if(selected != null) {
			var idValue:Dynamic = Reflect.field(selected, "id");
			if(idValue != null && Std.string(idValue) != "") return Std.string(idValue);

			var textValue:Dynamic = Reflect.field(selected, "text");
			if(textValue != null && Std.string(textValue) != "") return Std.string(textValue);
		}

		return fallback;
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
		var animationNames = getPreviewAnimationNames();
		populateDropDown(animationDropDown, animationNames);
		selectDropDownItem(animationDropDown, animationNames[0]);
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

		if(!applyPreviewCheck.selected) {
			previewCharacter.shader = null;
		} else if(previewMode == MODE_COLOR) {
			if(colorEnabledCheck.selected) {
				var colorShader = new AdjustColorShader();
				colorShader.brightness = colorBrightnessStepper.pos;
				colorShader.hue = colorHueStepper.pos;
				colorShader.contrast = colorContrastStepper.pos;
				colorShader.saturation = colorSaturationStepper.pos;
				previewCharacter.shader = colorShader;
			} else {
				previewCharacter.shader = null;
			}
		} else {
			if(rimEnabledCheck.selected) {
				var rimShader = new RimShadowShader();
				rimShader.color = parseHexColor(rimHexInput.text, 0xFFD46B00);
				rimShader.angle = rimAngleStepper.pos;
				rimShader.distance = rimDistanceStepper.pos;
				rimShader.threshold = rimThresholdStepper.pos;
				rimShader.brightness = rimBrightnessStepper.pos;
				rimShader.hue = rimHueStepper.pos;
				rimShader.contrast = rimContrastStepper.pos;
				rimShader.saturation = rimSaturationStepper.pos;
				rimShader.updateFrameInfo(previewCharacter.frame);
				previewCharacter.shader = rimShader;
			} else {
				previewCharacter.shader = null;
			}
		}

		statusLabel.text = 'Preview: $previewMode\nCharacter: $currentPreviewCharacter\nTarget: $exportTarget';
		refreshExportText();
	}

	private function refreshExportText():Void
	{
		var kind:String = getSelectedEventKind();
		eventNameLabel.text = 'Chart Event: v-slice event\nValue 1: $kind';
		payloadTextArea.text = buildSelectedPayloadJson();
		componentTextArea.text = buildSelectedComponentJson();
		handlerTextArea.text = extractRuntimeHandlerSnippet(kind);
	}

	private function buildSelectedPayloadJson():String
	{
		return Json.stringify(previewMode == MODE_COLOR ? buildColorPayload() : buildRimPayload(), null, "  ");
	}

	private function buildSelectedComponentJson():String
	{
		return Json.stringify({
			e: getSelectedEventKind(),
			v: previewMode == MODE_COLOR ? buildColorPayload() : buildRimPayload()
		}, null, "  ");
	}

	private function getSelectedEventKind():String
	{
		return previewMode == MODE_COLOR ? "ColorAdjustEvent" : "RimShadowEvent";
	}

	private function buildRimPayload():Dynamic
	{
		return {
			target: exportTarget,
			enabled: rimEnabledCheck.selected,
			hexcolor: normalizeHexColor(rimHexInput.text, "D46B00"),
			angle: rimAngleStepper.pos,
			distance: rimDistanceStepper.pos,
			threshold: rimThresholdStepper.pos,
			brightness: rimBrightnessStepper.pos,
			hue: rimHueStepper.pos,
			contrast: rimContrastStepper.pos,
			saturation: rimSaturationStepper.pos
		};
	}

	private function buildColorPayload():Dynamic
	{
		return {
			target: exportTarget,
			enabled: colorEnabledCheck.selected,
			brightness: colorBrightnessStepper.pos,
			hue: colorHueStepper.pos,
			contrast: colorContrastStepper.pos,
			saturation: colorSaturationStepper.pos
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
		statusLabel.text += "\nSaved export file.";
		cleanupFileRef(cast(event.target, FileReference));
	}

	private function onSaveError(event:IOErrorEvent):Void
	{
		statusLabel.text += "\nFailed to save export file.";
		cleanupFileRef(cast(event.target, FileReference));
	}

	private function cleanupFileRef(target:FileReference):Void
	{
		if(target == null) return;

		target.removeEventListener(Event.COMPLETE, onSaveComplete);
		target.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);

		if(fileRef == target) {
			fileRef = null;
		}
	}

	private function normalizeHexColor(value:String, fallback:String):String
	{
		var cleaned:String = value != null ? value.trim().toUpperCase() : fallback;

		if(cleaned.startsWith("#")) cleaned = cleaned.substr(1);
		if(cleaned.length == 8) cleaned = cleaned.substr(2);

		return cleaned.length == 6 ? cleaned : fallback;
	}

	private function parseHexColor(value:String, fallback:Int):Int
	{
		var cleaned:String = value != null ? value.trim() : "";

		if(cleaned.startsWith("#")) cleaned = cleaned.substr(1);
		if(cleaned.length == 6) cleaned = "FF" + cleaned;
		if(cleaned.length != 8) return fallback;

		var parsed:Null<Int> = Std.parseInt("0x" + cleaned);
		return parsed == null ? fallback : parsed;
	}

	private function extractRuntimeHandlerSnippet(eventKind:String):String
	{
		var methodName:String = switch(eventKind) {
			case "ColorAdjustEvent": "handleColorAdjustEvent";
			default: "handleRimShadowEvent";
		};

		var sourceText:String = Paths.readText("build/VSliceEvent.hx");
		if(sourceText == null || sourceText.trim() == "") return "";

		var signature:String = "private function " + methodName;
		var startIndex:Int = sourceText.indexOf(signature);
		if(startIndex == -1) return "";

		var searchIndex:Int = startIndex + signature.length;
		var nextIndex:Int = sourceText.indexOf("\n    private function ", searchIndex);

		if(nextIndex == -1) nextIndex = sourceText.indexOf("\n    private static function ", searchIndex);
		if(nextIndex == -1) nextIndex = sourceText.length;

		return sourceText.substr(startIndex, nextIndex - startIndex).trim();
	}

	override function update(elapsed:Float):Void
	{
		if(FlxG.keys.justPressed.ESCAPE) {
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

		if(previewCharacter != null && Std.isOfType(previewCharacter.shader, RimShadowShader)) {
			cast(previewCharacter.shader, RimShadowShader).updateFrameInfo(previewCharacter.frame);
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
