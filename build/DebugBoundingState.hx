package;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.addons.display.FlxBackdrop;
import flixel.addons.display.FlxGridOverlay;
import flixel.graphics.frames.FlxFrame;
import flixel.group.FlxGroup;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.math.FlxPoint;
import flixel.text.FlxText;
import flixel.text.FlxText.FlxTextBorderStyle;
import flixel.util.FlxColor;
import flixel.util.FlxSpriteUtil.LineStyle;
import haxe.ui.components.DropDown;
import haxe.ui.containers.dialogs.CollapsibleDialog;
import haxe.ui.core.Screen;
import haxe.ui.events.UIEvent;
import haxe.ui.RuntimeComponentBuilder;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.geom.Rectangle;
import openfl.net.FileReference;
import openfl.utils.Assets as OpenFLAssets;
import openfl.utils.AssetType;

import ModInitialize.ConfigCharacters;

using flixel.util.FlxSpriteUtil;
using StringTools;

/**
 * Animation / offset editor.
 *
 * 1:1 port of Funkin's `funkin.ui.debug.anim.DebugBoundingState`, wired up to
 * JTC-2's `Character` system, `Paths`, and HaxeUI setup instead of Funkin's
 * `BaseCharacter` / `CharacterDataParser`.
 */
class DebugBoundingState extends FlxState
{
	/*
		TODAY'S TO-DO
		- Cleaner UI
	 */
	var bg:FlxBackdrop;

	var txtGrp:FlxTypedGroup<FlxText>;

	var hudCam:FlxCamera;

	var curView:ANIMDEBUGVIEW = SPRITESHEET;

	var spriteSheetView:FlxGroup;
	var offsetView:FlxGroup;
	var dropDownSetup:Bool = false;

	var onionSkinChar:FlxSprite;
	var txtOffsetShit:FlxText;

	var offsetEditorDialog:CollapsibleDialog;
	var offsetAnimationDropdown:DropDown;

	var haxeUIFocused(get, default):Bool = false;

	var currentAnimationName(get, never):String;

	function get_currentAnimationName():String
	{
		return offsetAnimationDropdown?.value?.id ?? "idle";
	}

	function get_haxeUIFocused():Bool
	{
		// get the screen position, according to the HUD camera, temp default to FlxG.camera juuust in case?
		var hudMousePos:FlxPoint = FlxG.mouse.getViewPosition(hudCam ?? FlxG.camera);
		return Screen.instance.hasSolidComponentUnderPoint(hudMousePos.x, hudMousePos.y);
	}

	override function create():Void
	{
		hudCam = new FlxCamera();
		hudCam.bgColor.alpha = 0;

		bg = new FlxBackdrop(FlxGridOverlay.createGrid(10, 10, FlxG.width, FlxG.height, true, 0xffe7e6e6, 0xffd9d5d5));
		add(bg);

		// we are setting this as the default draw camera only temporarily, to trick haxeui
		FlxG.cameras.add(hudCam);

		offsetEditorDialog = cast buildDialog(Paths.xml('ui/animation-editor/offset-editor-view'));

		// offsetEditorDialog.findComponent("btnViewSpriteSheet").onClick = _ -> curView = SPRITESHEET;
		var viewDropdown:DropDown = offsetEditorDialog.findComponent("swapper", DropDown);
		viewDropdown.onChange = function(e:UIEvent) {
			curView = cast e.data.curView;
		};

		offsetAnimationDropdown = offsetEditorDialog.findComponent("animationDropdown", DropDown);

		offsetEditorDialog.cameras = [hudCam];
		offsetEditorDialog.closable = false;

		add(offsetEditorDialog);
		offsetEditorDialog.showDialog(false);

		// Anchor to the left side by default
		offsetEditorDialog.x = 16;
		offsetEditorDialog.y = 16;

		// sets the default camera back to FlxG.camera, since we set it to hudCamera for haxeui stuff
		FlxG.cameras.setDefaultDrawTarget(FlxG.camera, true);
		FlxG.cameras.setDefaultDrawTarget(hudCam, false);

		initSpritesheetView();
		initOffsetView();

		FlxG.mouse.visible = true;

		super.create();
	}

	/**
	 * Build the HaxeUI dialog from an asset path, mirroring `HaxeUIState.buildComponent`.
	 */
	function buildDialog(assetPath:String):CollapsibleDialog
	{
		try
		{
			return cast RuntimeComponentBuilder.fromAsset(assetPath);
		}
		catch (_:Dynamic) {}

		var data:String = Paths.readText(assetPath);
		return cast RuntimeComponentBuilder.fromString(data);
	}

	var bf:FlxSprite;
	var swagOutlines:FlxSprite;

	function initSpritesheetView():Void
	{
		spriteSheetView = new FlxGroup();
		add(spriteSheetView);

		bf = new FlxSprite();

		// Load a default character to populate the spritesheet view, just like Funkin loads BOYFRIEND.
		var defaultChar:Character = null;
		try
		{
			defaultChar = new Character(0, 0, defaultCharacterId());
		}
		catch (e:Dynamic)
		{
			trace('ERROR: Failed to load default character for spritesheet view: $e');
		}

		spriteSheetView.add(bf);

		swagOutlines = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.TRANSPARENT);

		if (defaultChar != null && defaultChar.graphic != null)
		{
			bf.loadGraphic(defaultChar.graphic);
			swagOutlines.makeGraphic(Std.int(bf.width), Std.int(bf.height), FlxColor.TRANSPARENT);
			if (defaultChar.frames != null) generateOutlines(defaultChar.frames.frames);
		}

		txtGrp = new FlxTypedGroup<FlxText>();
		txtGrp.cameras = [hudCam];
		spriteSheetView.add(txtGrp);

		addInfo(defaultCharacterId() + '.json', "");
		addInfo('Width', bf.width);
		addInfo('Height', bf.height);

		spriteSheetView.add(swagOutlines);

		if (defaultChar != null) defaultChar.destroy();
	}

	function generateOutlines(frameShit:Array<FlxFrame>):Void
	{
		// swagOutlines.width = frameShit[0].parent.width;
		// swagOutlines.height = frameShit[0].parent.height;
		swagOutlines.pixels.fillRect(new Rectangle(0, 0, swagOutlines.width, swagOutlines.height), 0x00000000);

		for (i in frameShit)
		{
			var lineStyle:LineStyle = {color: FlxColor.RED, thickness: 2};

			// In flixel 6.1.2 FlxFrame.uv is a FlxUVRect: left/top are the min UV,
			// right/bottom are the max UV (what older flixel stored as width/height).
			var uvW:Float = (i.uv.right * i.parent.width) - (i.uv.left * i.parent.width);
			var uvH:Float = (i.uv.bottom * i.parent.height) - (i.uv.top * i.parent.height);

			swagOutlines.drawRect(i.uv.left * i.parent.width, i.uv.top * i.parent.height, uvW, uvH, FlxColor.TRANSPARENT, lineStyle);
		}
	}

	function updateOnionSkin():Void
	{
		if (swagChar == null) return;
		// Onion skin copies the sprite's bitmap; Animate-atlas characters have no
		// flat graphic, so skip it for them.
		if (Std.isOfType(swagChar, AnimateAtlasCharacter)) return;
		if (swagChar.hasAnimation("idle")) swagChar.playAnimation("idle", true);

		onionSkinChar.loadGraphicFromSprite(swagChar);
		onionSkinChar.frame = swagChar.frame;
		onionSkinChar.alpha = 0.6;
		onionSkinChar.flipX = swagChar.flipX;

		var onionOffsets:Array<Float> = swagChar.animOffsets.get("idle");
		if (onionOffsets != null)
		{
			onionSkinChar.offset.x = onionOffsets[0];
			onionSkinChar.offset.y = onionOffsets[1];
		}

		swagChar.playAnimation(currentAnimationName, true); // reset animation to the one it should be
	}

	function initOffsetView():Void
	{
		offsetView = new FlxGroup();
		add(offsetView);

		onionSkinChar = new FlxSprite().makeGraphic(FlxG.width * 2, FlxG.height * 2, FlxColor.TRANSPARENT);
		onionSkinChar.visible = false;
		offsetView.add(onionSkinChar);

		txtOffsetShit = new FlxText(20, 20, 0, "", 20);
		txtOffsetShit.setFormat(Paths.font("vcr.ttf"), 26, FlxColor.WHITE, LEFT, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		txtOffsetShit.cameras = [hudCam];
		txtOffsetShit.y = FlxG.height - 20 - txtOffsetShit.height;
		offsetView.add(txtOffsetShit);

		// Unlike Funkin's editor (which excludes Animate-atlas characters), we keep
		// them: AnimateAtlasCharacter renders fine here, the spritesheet view just
		// won't have a flat sheet to outline.
		var characters:Array<String> = listCharacterIds();
		characters = characters.filter(function(charId:String) {
			return Character.loadInfo('characters/$charId') != null;
		});
		characters.sort(SortUtil.alphabetically);

		var charDropdown:DropDown = offsetEditorDialog.findComponent('characterDropdown', DropDown);
		for (char in characters)
		{
			charDropdown.dataSource.add({text: char});
		}

		charDropdown.onChange = function(e:UIEvent) {
			loadAnimShit(e.data.text);
		};
	}

	public var mouseOffset:FlxPoint = FlxPoint.get(0, 0);
	public var oldPos:FlxPoint = FlxPoint.get(0, 0);
	public var movingCharacter:Bool = false;

	function mouseOffsetMovement()
	{
		if (swagChar != null)
		{
			var curOffsets:Array<Float> = swagChar.animOffsets.get(currentAnimationName);
			if (curOffsets == null) return;

			if (FlxG.mouse.justPressed && !haxeUIFocused)
			{
				movingCharacter = true;
				mouseOffset.set(FlxG.mouse.x - -curOffsets[0], FlxG.mouse.y - -curOffsets[1]);
			}

			if (!movingCharacter) return;

			if (FlxG.mouse.pressed)
			{
				var newOffsets:Array<Float> = [(FlxG.mouse.x - mouseOffset.x) * -1, (FlxG.mouse.y - mouseOffset.y) * -1];

				swagChar.animOffsets.set(currentAnimationName, newOffsets);
				swagChar.offset.set(newOffsets[0], newOffsets[1]);

				txtOffsetShit.text = 'Offset: ' + newOffsets;
				txtOffsetShit.y = FlxG.height - 20 - txtOffsetShit.height;
			}

			if (FlxG.mouse.justReleased)
			{
				movingCharacter = false;
			}
		}
	}

	function addInfo(str:String, value:Dynamic)
	{
		var swagText:FlxText = new FlxText(10, FlxG.height - 32);
		swagText.setFormat(Paths.font("vcr.ttf"), 26, FlxColor.WHITE, LEFT, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		swagText.scrollFactor.set();

		for (text in txtGrp.members)
		{
			text.y -= swagText.height;
		}
		txtGrp.add(swagText);

		swagText.text = str + ": " + Std.string(value);
	}

	function clearInfo()
	{
		txtGrp.clear();
	}

	override function update(elapsed:Float)
	{
		if (FlxG.keys.justPressed.ONE)
		{
			var lv:DropDown = offsetEditorDialog.findComponent("swapper", DropDown);
			lv.selectedIndex = 0;
			curView = SPRITESHEET;
		}

		if (FlxG.keys.justReleased.TWO)
		{
			var lv:DropDown = offsetEditorDialog.findComponent("swapper", DropDown);
			lv.selectedIndex = 1;
			curView = ANIMATIONS;
			if (swagChar != null)
			{
				FlxG.camera.focusOn(swagChar.getMidpoint());
				FlxG.camera.zoom = 0.95;
			}
		}

		switch (curView)
		{
			case SPRITESHEET:
				spriteSheetView.visible = true;
				offsetView.visible = false;
				offsetView.active = false;
				offsetAnimationDropdown.visible = false;
			case ANIMATIONS:
				spriteSheetView.visible = false;
				offsetView.visible = true;
				offsetView.active = true;
				offsetAnimationDropdown.visible = true;
				offsetControls();
				mouseOffsetMovement();
		}

		if (FlxG.keys.justPressed.H) hudCam.visible = !hudCam.visible;

		if (FlxG.keys.justPressed.F4) FlxG.switchState(new MainMenuState());

		MouseUtil.mouseCamDrag();
		if (!haxeUIFocused) MouseUtil.mouseWheelZoom();

		bg.setGraphicSize(Std.int(bg.width / FlxG.camera.zoom));

		super.update(elapsed);
	}

	function offsetControls():Void
	{
		// CTRL + S = Save Character Data
		// CTRL + SHIFT + S = Save Offsets
		// "WINDOWS" key code is the same keycode as COMMAND on mac
		if ((FlxG.keys.pressed.CONTROL || FlxG.keys.pressed.WINDOWS) && FlxG.keys.justPressed.S)
		{
			var outputString = FlxG.keys.pressed.SHIFT ? buildOutputStringOld() : buildOutputStringNew();
			saveOffsets(outputString, FlxG.keys.pressed.SHIFT ? swagChar.curCharacter + "Offsets.txt" : swagChar.curCharacter + ".json");
			return;
		}

		if (FlxG.keys.justPressed.RBRACKET || FlxG.keys.justPressed.E)
		{
			if (offsetAnimationDropdown.selectedIndex + 1 <= offsetAnimationDropdown.dataSource.size)
			{
				offsetAnimationDropdown.selectedIndex += 1;
			}
			else
			{
				offsetAnimationDropdown.selectedIndex = 0;
			}
			playCharacterAnimation(currentAnimationName, true);
		}
		if (FlxG.keys.justPressed.LBRACKET || FlxG.keys.justPressed.Q)
		{
			if (offsetAnimationDropdown.selectedIndex - 1 >= 0)
			{
				offsetAnimationDropdown.selectedIndex -= 1;
			}
			else
			{
				offsetAnimationDropdown.selectedIndex = offsetAnimationDropdown.dataSource.size - 1;
			}
			playCharacterAnimation(currentAnimationName, true);
		}

		// Keyboards controls for general WASD "movement"
		// modifies the animDrooffsetAnimationDropdownpDownMenu so that it's properly updated and shit
		// and then it's just played and updated from the offsetAnimationDropdown callback, which is set in the loadAnimShit() function probabbly
		if (FlxG.keys.justPressed.W || FlxG.keys.justPressed.S || FlxG.keys.justPressed.D || FlxG.keys.justPressed.A)
		{
			var suffix:String = '';
			var targetLabel:String = '';

			if (FlxG.keys.pressed.SHIFT) suffix = 'miss';

			if (FlxG.keys.justPressed.W) targetLabel = 'singUP$suffix';
			if (FlxG.keys.justPressed.S) targetLabel = 'singDOWN$suffix';
			if (FlxG.keys.justPressed.A) targetLabel = 'singLEFT$suffix';
			if (FlxG.keys.justPressed.D) targetLabel = 'singRIGHT$suffix';

			if (targetLabel != currentAnimationName)
			{
				offsetAnimationDropdown.value = {id: targetLabel, text: targetLabel};

				// Play the new animation if the IDs are the different.
				// Override the onion skin.
				playCharacterAnimation(currentAnimationName, true);
			}
			else
			{
				// Replay the current animation if the IDs are the same.
				// Don't override the onion skin.
				playCharacterAnimation(currentAnimationName, false);
			}
		}

		if (FlxG.keys.justPressed.F)
		{
			onionSkinChar.visible = !onionSkinChar.visible;
			if (onionSkinChar.visible) updateOnionSkin();
		}

		if (FlxG.keys.justPressed.G)
		{
			swagChar.flipX = !swagChar.flipX;
			if (onionSkinChar.visible) updateOnionSkin();
		}

		// Plays the idle animation
		if (FlxG.keys.justPressed.SPACE)
		{
			offsetAnimationDropdown.value = {id: 'idle', text: 'idle'};

			playCharacterAnimation(currentAnimationName, true);
		}

		// Playback the animation
		if (FlxG.keys.justPressed.ENTER)
		{
			playCharacterAnimation(currentAnimationName, false);
		}

		if (FlxG.keys.justPressed.RIGHT || FlxG.keys.justPressed.LEFT || FlxG.keys.justPressed.UP || FlxG.keys.justPressed.DOWN)
		{
			var animName = currentAnimationName;
			var existing:Array<Float> = swagChar.animOffsets.get(animName);
			if (existing == null) existing = [0, 0];
			var coolValues:Array<Float> = existing.copy();

			var multiplier:Int = 5;

			if (FlxG.keys.pressed.CONTROL) multiplier = 1;

			if (FlxG.keys.pressed.SHIFT) multiplier = 10;

			if (FlxG.keys.justPressed.RIGHT) coolValues[0] -= 1 * multiplier;
			else if (FlxG.keys.justPressed.LEFT) coolValues[0] += 1 * multiplier;
			else if (FlxG.keys.justPressed.UP) coolValues[1] += 1 * multiplier;
			else if (FlxG.keys.justPressed.DOWN) coolValues[1] -= 1 * multiplier;

			swagChar.animOffsets.set(animName, coolValues);
			swagChar.playAnimation(animName);
			swagChar.offset.set(coolValues[0], coolValues[1]);

			txtOffsetShit.text = 'Offset: ' + coolValues;
			txtOffsetShit.y = FlxG.height - 20 - txtOffsetShit.height;
		}
	}

	function buildOutputStringOld():String
	{
		var outputString:String = "";

		for (i in swagChar.animOffsets.keys())
		{
			outputString += i + " " + swagChar.animOffsets.get(i)[0] + " " + swagChar.animOffsets.get(i)[1] + "\n";
		}

		outputString = outputString.trim();

		return outputString;
	}

	function buildOutputStringNew():String
	{
		var charData:ConfigCharacters = Character.loadInfo('characters/${swagChar.curCharacter}');

		for (animName in charData.animations.keys())
		{
			var offsets:Array<Float> = swagChar.animOffsets.get(animName);
			if (offsets == null) continue;
			charData.animations.get(animName).offset = [Std.int(offsets[0]), Std.int(offsets[1])];
		}

		var writer = new json2object.JsonWriter<ConfigCharacters>();
		return writer.write(charData, "\t");
	}

	var swagChar:Character;

	/*
		Called when animation dropdown is changed!
	 */
	function loadAnimShit(char:String)
	{
		if (swagChar != null)
		{
			offsetView.remove(swagChar);
			swagChar.destroy();
		}

		// Use the factory so Animate-atlas characters come back as AnimateAtlasCharacter.
		swagChar = Character.build(100, 100, char);
		swagChar.debugMode = true;
		offsetView.add(swagChar);

		var isAtlas:Bool = Std.isOfType(swagChar, AnimateAtlasCharacter);

		if (swagChar == null || (!isAtlas && swagChar.frames == null))
		{
			trace('ERROR: Failed to load character ${char}!');
			return;
		}

		onionSkinChar.x = swagChar.x;
		onionSkinChar.y = swagChar.y;

		// Update the SPRITESHEET view to show the selected character's sheet.
		// Funkin does `bf.pixels = swagChar.pixels` here, but it filters atlas
		// characters out. For atlas characters the sheet lives on the FlxAtlasSprite's
		// `frames`/`graphic` (the Animate spritemap), so pull it from there instead.
		var sheetFrames:flixel.graphics.frames.FlxFramesCollection = swagChar.frames;
		var sheetGraphic:flixel.graphics.FlxGraphic = swagChar.graphic;

		if (isAtlas)
		{
			var atlasSprite:FlxAtlasSprite = cast(swagChar, AnimateAtlasCharacter).mainSprite;
			if (atlasSprite != null && atlasSprite.frames != null)
			{
				sheetFrames = atlasSprite.frames;
				// FlxAnimate's combined collection has a null `parent` (it can span
				// multiple spritemaps); the graphic lives on each frame's `parent`.
				if (sheetFrames.frames != null && sheetFrames.frames.length > 0)
				{
					sheetGraphic = sheetFrames.frames[0].parent;
				}
			}
		}

		if (sheetFrames != null && sheetGraphic != null)
		{
			bf.loadGraphic(sheetGraphic);
			swagOutlines.makeGraphic(sheetGraphic.width, sheetGraphic.height, FlxColor.TRANSPARENT);
			generateOutlines(sheetFrames.frames);
		}

		clearInfo();
		addInfo('$char.json', "");
		addInfo('Width', swagChar.width);
		addInfo('Height', swagChar.height);

		characterAnimNames = [];

		for (i in swagChar.animOffsets.keys())
		{
			characterAnimNames.push(i);
		}

		offsetAnimationDropdown.dataSource.clear();

		for (charAnim in characterAnimNames)
		{
			offsetAnimationDropdown.dataSource.add({id: charAnim, text: charAnim});
		}

		offsetAnimationDropdown.selectedIndex = 0;

		offsetAnimationDropdown.onChange = function(event:UIEvent) {
			if (event.data != null)
			{
				playCharacterAnimation(event.data.id, true);
			}
		}

		playCharacterAnimation(currentAnimationName, false);

		txtOffsetShit.text = 'Offset: ' + swagChar.animOffsets.get(currentAnimationName);
		txtOffsetShit.y = FlxG.height - 20 - txtOffsetShit.height;
		dropDownSetup = true;
	}

	private var characterAnimNames:Array<String>;

	function playCharacterAnimation(str:String, setOnionSkin:Bool = true)
	{
		if (setOnionSkin && onionSkinChar.visible) updateOnionSkin();

		var animName = str;
		swagChar.playAnimation(animName, true);

		txtOffsetShit.text = 'Offset: ' + swagChar.animOffsets.get(animName);
		txtOffsetShit.y = FlxG.height - 20 - txtOffsetShit.height;
	}

	// ====== Character listing helpers (JTC-2 flavored CharacterDataParser.listCharacterIds) ======

	function defaultCharacterId():String
	{
		var ids:Array<String> = listCharacterIds();
		return ids.contains("bf") ? "bf" : (ids.length > 0 ? ids[0] : "bf");
	}

	function listCharacterIds():Array<String>
	{
		var result:Array<String> = [];

		var characterListRaw:Array<String> = OpenFLAssets.list(TEXT);

		for (characterPath in characterListRaw)
		{
			if (characterPath == null) continue;

			if (characterPath.startsWith("mod_assets/characters/")
				|| characterPath.startsWith("assets/characters/")
				|| characterPath.startsWith("funkin_assets/preload/data/characters/"))
			{
				var fileName:String = characterPath.split("/").pop();
				if (fileName == null || !fileName.endsWith(".json")) continue;

				var characterName:String = fileName.substr(0, fileName.length - 5);
				if (!result.contains(characterName)) result.push(characterName);
			}
		}

		return result;
	}

	// ====== Saving ======

	var _file:FileReference;

	function saveOffsets(saveString:String, fileName:String)
	{
		if ((saveString != null) && (saveString.length > 0))
		{
			_file = new FileReference();
			_file.addEventListener(Event.COMPLETE, onSaveComplete);
			_file.addEventListener(Event.CANCEL, onSaveCancel);
			_file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
			_file.save(saveString, fileName);
		}
	}

	function onSaveComplete(_):Void
	{
		_file.removeEventListener(Event.COMPLETE, onSaveComplete);
		_file.removeEventListener(Event.CANCEL, onSaveCancel);
		_file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
		_file = null;
		FlxG.log.notice("Successfully saved LEVEL DATA.");
	}

	/**
	 * Called when the save file dialog is cancelled.
	 */
	function onSaveCancel(_):Void
	{
		_file.removeEventListener(Event.COMPLETE, onSaveComplete);
		_file.removeEventListener(Event.CANCEL, onSaveCancel);
		_file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
		_file = null;
	}

	/**
	 * Called if there is an error while saving the gameplay recording.
	 */
	function onSaveError(_):Void
	{
		_file.removeEventListener(Event.COMPLETE, onSaveComplete);
		_file.removeEventListener(Event.CANCEL, onSaveCancel);
		_file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
		_file = null;
		FlxG.log.error("Problem saving Level data");
	}
}

enum abstract ANIMDEBUGVIEW(String)
{
	var SPRITESHEET;
	var ANIMATIONS;
}
