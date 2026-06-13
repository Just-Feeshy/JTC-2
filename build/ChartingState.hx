package;

import haxe.zip.Writer;
import Section.SwagSection;
import Song.SwagSong;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.addons.display.FlxGridOverlay;
import haxe.ui.RuntimeComponentBuilder;
import haxe.ui.core.Screen;
import haxe.ui.core.Component;
import haxe.ui.containers.TabView;
import haxe.ui.components.Button;
import haxe.ui.components.CheckBox;
import haxe.ui.components.DropDown;
import haxe.ui.components.NumberStepper;
import haxe.ui.components.TextField;
import haxe.ui.components.Label;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.group.FlxGroup;
import flixel.math.FlxMath;
import flixel.math.FlxPoint;
import flixel.sound.FlxSound;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.ui.FlxSpriteButton;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import haxe.Json;
import lime.utils.Assets;
import lime.utils.Log;
import example_code.DefaultEvents.EventInfo;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.media.Sound;
import openfl.net.FileReference;
import openfl.utils.ByteArray;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import feshixl.math.FeshMath;
import openfl.display.FPS;
import openfl.Lib;
#if sys
import sys.FileSystem;
#end

import example_code.DefaultStage;

import SaveData.SaveType;
import ModInitialize;
import BuiltInShaders;
import DefaultHandler;

using StringTools;

class ChartingState extends MusicBeatState
{
	private var muteInGame:Bool = PlayState.muteInst;
	private var mainGrid:Int = 8;
	private var totalGrids:Int = 1;

	private var isInDrop:Bool = false;

	var _file:FileReference;

	var UI_box:Component;
	var UI_Modifiers:Component;

	/**
	 * Array of notes showing when each section STARTS in STEPS
	 * Usually rounded up??
	 */
	var curSection:Int = 0;

	public static var lastSection:Int = 0;

	var bpmTxt:FlxText;

	var strumLine:FlxSprite;
	var curSong:String = 'Dadbattle';
	var amountSteps:Int = 0;
	var bullshitUI:FlxGroup;
	var writingNotesText:Label;
	var highlight:FlxSprite;

	var instrucTxt:FlxText;

	final GRID_SIZE:Int = 40;

	var zoomMeter:Int = 2;

	final zoomList:Array<Int> = [
		25,
		50,
		100,
		125,
		150,
		200,
		250,
		300,
		400,
		500,
		750,
		1000
	];

	var dummyArrow:FlxSprite;

	var curRenderedNotes:FlxTypedGroup<Note>;
	var curRenderedSustains:FlxTypedGroup<FlxSprite>;

	var curPhysicalEvents:FlxTypedGroup<FlxSprite>;

	var gridBG:FlxSprite;
	var gridBG2:FlxSprite;

	var _song:SwagSong;

	var typingShit:TextField;
	/*
	 * WILL BE THE CURRENT / LAST PLACED NOTE
	**/
	var curSelectedNote:Array<Dynamic>;
	var prevSelectedNote:Array<Dynamic>;

	var tempBpm:Int = 0;
	var vocals:FlxSound;
	var opponentVocals:FlxSound;
	var extraVocals:Array<FlxSound> = [];

	var leftIcon:HealthIcon;
	var rightIcon:HealthIcon;

	var camFollow:FlxObject;

	var lastNote:Note;

	var eventDisplay:FlxTypedGroup<FlxText>;

	var wtfIsNote:String = "regular";
	var wtfIsEvent:String = "mirror chart";

	var songFPS:Null<Int> = 100;
	var colorMap:Null<Int> = 0;

	var fileType:Array<String> = [];

	var osuManiaSounds:Array<Note> = [];

	final gfSideDefault:Array<String> = [
		'gf',
		'gf',
		'gf',
		'gf-car',
		'gf-christmas',
		'gf-pixel'
	];

	//Event Stuff
	private var simpleList:Map<String, Array<Array<String>>> = [
		"Modifiers" => [
			['mirror chart', "Mirror mode.\n\nValue -\n0 = Revert back to normal.\n1 = Should mirror regular chart."],
			['sing drain', "Drains health when opponent sings.\n\nValue - How much health should be drained. (1 recommended)"],
			['fadein notes', "Whether notes should have a fade-in effect.\n\nValue - Note position where note should fade in.\n(400 recommended)"],
			['blind effect', "Follow your opponent's pattern. Well...\n\nValue -\n0 = Revert back to normal.\n1 = Should enable."],
			['camera move', "The camera follows the direction of each singing pose.\n\nValue - Camera movement intensity. (1 recommended)"]
		],
		"Regular" => [
			['alt animation', "Value 1 - Sets a suffix after the idle and sing\nanimation name.\nValue 2 - Character side to set.\n(Boyfriend's Side or Dad's Side)"],
			['jumpspeed', "Value 1 - Multiply regular scroll speed by this value.\nValue 2 - Set tween value of scroll speed transition."],
			['sicko shake', "Value 1 - Regular camera shake.\nValue 2 - HUD camera shake."],
			['time freeze', "Value 1 - 0 = Unfreeze time of music. 1 = Freeze time\nof music.\nValue 2 - Set tween value."],
			['strum bounce', "Value 1 - Set size value.\nValue 2 - Set X offset value for player strum."],
			['note rewind', "Value 1 - Set rewind value.\nValue 2 - Set tween value to the rewind speed."],
			['character change', "Value 1 - New character's name.\nValue 2 - Character to change \n(bf: Boyfriend's Side, dad: Dad's Side, gf: Girlfriend's Side)"],
			['bump per beat', "Value 1 - Each bump for beat.\nValue 2 - The amount of force for each bump."],
			['v-slice event', "Value 1 - V-Slice event kind or a full component JSON.\nValue 2 - V-Slice payload JSON when Value 1 is only the event kind.\nExamples:\nFocusCamera + {\"char\":1}\nZoomCamera + {\"zoom\":1.2,\"duration\":4,\"mode\":\"stage\"}"],
			['clear events', "Value 1 - Event's name.\nValue 2 - Second event's name. (optional)"],
			['clear all', "Value 1 - nothing.\nValue 2 - nothing."]
		]
	];

	private var eventCatalog:Map<String, String> = [
		'mirror chart' => "Modifiers",
		'sing drain' => "Modifiers",
		'blind effect' => "Modifiers",
		'fadein notes' => "Modifiers",
		'camera move' => "Modifiers",
		'alt animation' => "Regular",
		'jumpspeed' => "Regular",
		'sicko shake' => "Regular",
		'time freeze' => "Regular",
		'strum bounce' => "Regular",
		'note rewind' => "Regular",
		'character change' => "Regular",
		'bump per beat' => "Regular",
		'v-slice event' => "Regular",
		'clear events' => "Regular",
		'clear all' => "Regular"
	];

	private var selectingShader:BuiltInShaders;

	var zoomText:FlxText;
	var adjustNotes5kButton:Button;

	var gridLayout:FlxTypedGroup<FlxSprite>;

	override function create()
	{
		curSection = lastSection;

		if (PlayState.SONG != null)
			_song = PlayState.SONG;
		else
		{
			_song = {
				song: 'Test',
				notes: [],
				modifiers: [],
				bpm: 150,
				needsVoices: true,
				player1: 'bf',
				player2: 'dad',
				stage: null,
				video: null,
				girlfriend: null,
				speed: 1,
				validScore: false,
				fifthKey: false,
				modifyFPS: false,
				colorMapping: 0,
				fps: 100,

				player1X: 0,
				player1Y: 0,
				
				player2X: 0,
				player2Y: 0
			};
		}

		if(_song.stage == null)
			setStage();

		if(_song.girlfriend == null)
			setGirlfriend();

		if (_song.modifiers == null)
			_song.modifiers = [];

		songFPS = _song.fps;

		if(songFPS == null || songFPS < 60)
			songFPS = Main.framerate;

		colorMap = _song.colorMapping;

		if(colorMap == null)
			colorMap = 0;

		var noColorShader:BuiltInShaders = new BuiltInShaders();
		noColorShader.shader = ShaderType.MINING_SIM_LOADING;

		var bg:FlxSprite = new FlxSprite();
		bg.loadGraphic(Paths.image(Paths.modJSON.background_images[FlxG.random.int(0, Paths.modJSON.background_images.length - 1)]));
		bg.shader = noColorShader;
		bg.alpha = 0.5;
		bg.scrollFactor.set();
		bg.screenCenter();
		add(bg);
		attachSprite("chartEditorBackground", bg);

		bpmTxt = new FlxText(1000, 50, 0, "", 14);
		refreshChartLaneLayout();

		dummyArrow = new FlxSprite().makeGraphic(GRID_SIZE, GRID_SIZE);

		gridLayout = new FlxTypedGroup<FlxSprite>();
		add(gridLayout);

		gridBG = FlxGridOverlay.create(GRID_SIZE, GRID_SIZE, GRID_SIZE * mainGrid, GRID_SIZE * 16);
		gridLayout.add(gridBG);

		leftIcon = new HealthIcon(_song.player1);
		rightIcon = new HealthIcon(_song.player2);
		leftIcon.scrollFactor.set(1, 1);
		rightIcon.scrollFactor.set(1, 1);

		leftIcon.setGraphicSize(0, 45);
		rightIcon.setGraphicSize(0, 45);

		add(leftIcon);
		add(rightIcon);
		positionChartIcons();

		curRenderedNotes = new FlxTypedGroup<Note>();
		curRenderedSustains = new FlxTypedGroup<FlxSprite>();

		FunkinCursor.show();
		SaveData.bindProjectSave();

		tempBpm = _song.bpm;

		addSection();

		// sections = _song.notes;

		updateGrid();

		updateEvents();


		loadSong(_song.song);
		Conductor.instance.mapTimeChangesFromSong(_song);
		Conductor.instance.forceBPM(_song.bpm);

		bpmTxt.scrollFactor.set();
		add(bpmTxt);

		strumLine = new FlxSprite(0, 50).makeGraphic(Std.int(GRID_SIZE * mainGrid), 4);
		add(strumLine);

		UI_box = RuntimeComponentBuilder.fromAsset("assets/exclude/data/ui/chart-editor/song-box.xml");
		UI_Modifiers = RuntimeComponentBuilder.fromAsset("assets/exclude/data/ui/chart-editor/mod-box.xml");

		UI_box.left = FlxG.width - 335;
		UI_box.top = 10;

		UI_Modifiers.left = FlxG.width - 285;
		UI_Modifiers.top = 440;

		if(!Main.feeshmoraModifiers) {
			var modTab:Component = UI_Modifiers.findComponent("tabModifiers", Component, true);
			if(modTab != null && Std.isOfType(UI_Modifiers, TabView))
				cast(UI_Modifiers, TabView).removeComponent(modTab);
		}

		Screen.instance.addComponent(UI_box);
		Screen.instance.addComponent(UI_Modifiers);

		selectingShader = new BuiltInShaders();
		selectingShader.shader = ShaderType.GLIM_SELECTION;

		instrucTxt = new FlxText(10, FlxG.height - 230, FlxG.width,
            "Q/E - Change Strum.\n\n" +
            "CTRL & Click Note - Select Note.\n\n" +
            "SPACE - Stop or Resume.\n\n" +
			"I/O - Zoom In/Out. (I prefer I/O over Z/X)\n\n" +
			"Hold Control - Select Note.\n\n" +
			"C - Do the same changes to selected note as the previous selected note.\n\n" +
			"Hold UP/DOWN and C - Autoselected above/below selected note.\n(If no note selected, nothing will happen)"
        , 12);

		instrucTxt.scrollFactor.set();
		add(instrucTxt);

		zoomText = new FlxText(15, 15, "Zoom: " + zoomList[zoomMeter] + "%", 16);
		zoomText.scrollFactor.set();
		add(zoomText);

		refreshChartLaneLayout();

		super.create();
		loadEditorStagePreview();

		addSongUI();
		addSectionUI();
		addNoteUI();
		addWorldMapUI();
		addVideoUI();

		//Options
		if(Main.feeshmoraModifiers)
			addModifierUI();
		addRegularEventUI();
		addYourEventUI();
		addSettingsEventUI();

		add(curRenderedSustains);
		add(curRenderedNotes);

		updateHeads();
	}

	function loadEditorStagePreview():Void {
		var songName:String = _song != null && _song.song != null ? _song.song.toLowerCase() : "";
		var songDirectory:String = songName.length > 0 ? CoolUtil.readableSongDirectory(songName) : "";
		var stageName:String = _song != null && _song.stage != null ? _song.stage.toLowerCase() : "";

		setLua("chartSongName", songName);
		setLua("chartSongDirectory", songDirectory);
		setLua("chartStageName", stageName);
		callLua("loadEditorStage", []);
	}

	function setStage() {
		_song.stage = DefaultStage.setMainGameStage(_song.song.toLowerCase());
	}

	function setGirlfriend() {
		if(_song.song.toLowerCase() == "satin-panties" || _song.song.toLowerCase() == "high" || _song.song.toLowerCase() == "milf")
			_song.girlfriend = "gf-car";
		else if(_song.song.toLowerCase() == "cocoa" || _song.song.toLowerCase() == "eggnog" || _song.song.toLowerCase() == "winter-horrorland")
			_song.girlfriend = "gf-christmas";
		else if(_song.song.toLowerCase() == "senpai" || _song.song.toLowerCase() == "roses" || _song.song.toLowerCase() == "thorns")
			_song.girlfriend = "gf-pixel";
		else
			_song.girlfriend = "gf";
	}

	var stepperSpeed:NumberStepper;
	var speedLabel:Label;

	var unableLabel:Label;
	var watchButton:Button;

	// ---- haxeui helpers ----
	inline function findC<T:Component>(box:Component, id:String, type:Class<T>):T
		return box.findComponent(id, type, true);

	function ddSetData(dd:DropDown, items:Array<String>):Void {
		if(dd == null || dd.dataSource == null) return;
		dd.dataSource.clear();
		for(it in items) dd.dataSource.add({text: it});
	}

	function ddSelectLabel(dd:DropDown, label:String):Void {
		if(dd == null || dd.dataSource == null) return;
		for(i in 0...dd.dataSource.size) {
			if(dd.dataSource.get(i).text == label) { dd.selectedIndex = i; return; }
		}
	}

	inline function ddLabel(dd:DropDown):String
		return (dd != null && dd.selectedItem != null) ? dd.selectedItem.text : "";

	inline function boxTab(box:Component):Int
		return Std.isOfType(box, TabView) ? cast(box, TabView).pageIndex : 0;

	inline function setBoxTab(box:Component, idx:Int):Void
		if(Std.isOfType(box, TabView)) cast(box, TabView).pageIndex = idx;

	function addVideoUI():Void {
		var getVideo:Button = findC(UI_box, "getVideo", Button);
		getVideo.onClick = function(_) {
			_file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

			fileType = [".mp4", ".mov", ".webm"];

			_file.browse();
		};

		watchButton = findC(UI_box, "watchButton", Button);
		watchButton.onClick = function(_) {
			if(_song.video != null) {
				FlxG.switchState(new VideoState(new ChartingState(), _song.video));
			}
		};
		watchButton.hidden = (_song.video == null);

		unableLabel = findC(UI_box, "videoUnableLabel", Label);
	}

	function addModifierUI():Void {
		var makeModName:TextField = findC(UI_Modifiers, "makeModName", TextField);
		var makeModifierValue:TextField = findC(UI_Modifiers, "makeModifierValue", TextField);
		var howToTutorial:Label = findC(UI_Modifiers, "howToTutorial_mod", Label);

		var eventList:Array<String> = [];

		for (i in 0...simpleList.get("Modifiers").length)
			eventList.push(simpleList.get("Modifiers")[i][0]);

		howToTutorial.text = simpleList.get("Modifiers")[0][1];

		var modList:DropDown = findC(UI_Modifiers, "modList", DropDown);
		ddSetData(modList, eventList);
		modList.onChange = function(_) {
			var idx:Int = modList.selectedIndex;
			if(idx < 0) return;
			wtfIsEvent = eventList[idx];
			makeModifierValue.text = "";
			howToTutorial.text = simpleList.get("Modifiers")[idx][1];
		};

		findC(UI_Modifiers, "createEventButton_mod", Button).onClick = function(_) {
			if(curStep < 0 || curStep < curSection*16 || makeModName.text == "")
				return;

			for(i in 0..._song.modifiers.length) {
				var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");

				if(gridY == GRID_SIZE*curStep)
					return;
			}

			var createEvent:EventInfo = {modSkill: wtfIsEvent, modGridY: GRID_SIZE*curStep, modValue: null, modValueTwo: null, modDisplayName: makeModName.text};

			switch(createEvent.modSkill) {
				case "mirror chart":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(Math.min(1, Math.max(0, Std.parseFloat(makeModifierValue.text))));
					else
						createEvent.modValue = "1";
				case "sing drain":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(-Math.abs(Std.parseFloat(makeModifierValue.text)));
					else
						createEvent.modValue = "1";
				case "fadein notes":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(Math.abs(Std.parseInt(makeModifierValue.text)));
					else
						createEvent.modValue = "400";
				case "blind effect":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(Math.min(1, Math.max(0, Std.parseFloat(makeModifierValue.text))));
					else
						createEvent.modValue = "1";
				case "camera move":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(Math.abs(Std.parseFloat(makeModifierValue.text)));
					else
						createEvent.modValue = "1";
			}

			_song.modifiers.push(createEvent);

			createPhysicalEvent(_song.modifiers.length-1, curStep, createEvent.modValue, null);
		};

		findC(UI_Modifiers, "removeEventButton_mod", Button).onClick = function(_) {
			if(curStep < 0 || curStep < curSection*16)
				return;

			removePhysicalEvent(curStep);
		};
	}

	function addYourEventUI():Void {
		var makeYoursName:TextField = findC(UI_Modifiers, "makeYoursName", TextField);
		var makeYourValue:TextField = findC(UI_Modifiers, "makeYourValue", TextField);
		var makeYourTwoValue:TextField = findC(UI_Modifiers, "makeYourTwoValue", TextField);
		var howToTutorial:Label = findC(UI_Modifiers, "howToTutorial_your", Label);

		findC(UI_Modifiers, "createEventButton_your", Button).onClick = function(_) {
			if(curStep < 0 || curStep < curSection*16 || makeYoursName.text == "")
				return;

			for(i in 0..._song.modifiers.length) {
				var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");

				if(gridY == GRID_SIZE*curStep)
					return;
			}

			var createEvent:EventInfo = {modSkill: wtfIsEvent, modGridY: GRID_SIZE*curStep, modValue: null, modValueTwo: null, modDisplayName: makeYoursName.text};

			var getModValue:String = callLua("getEventValueFromLua", [createEvent.modSkill, makeYourValue.text.toLowerCase()]);
			var getModTwoValue:String = callLua("getEventSecondValueFromLua", [createEvent.modSkill, makeYourTwoValue.text.toLowerCase()]);

			if(getModValue == null) {
				getModValue = makeYourValue.text.toLowerCase();
			}

			if(getModTwoValue == null) {
				getModTwoValue =  makeYourTwoValue.text.toLowerCase();
			}

			createEvent.modValue = getModValue;
			createEvent.modValueTwo = getModTwoValue;

			_song.modifiers.push(createEvent);
			createPhysicalEvent(_song.modifiers.length-1, curStep, createEvent.modValue, createEvent.modValueTwo);
		};

		findC(UI_Modifiers, "removeEventButton_your", Button).onClick = function(_) {
			if(curStep < 0 || curStep < curSection*16)
				return;

			if(!removeDelay)
				removePhysicalEvent(curStep);
		};

		//Setup Premise
		simpleList.set("Yours", []);

		for(i in 0...Paths.modJSON.mod.events.length) {
			var events:ConfigEvent = Paths.modJSON.mod.events[i];

			simpleList.get("Yours").push([events.name, events.description]);
			eventCatalog.set(events.name, "Yours");
		}

		var eventList:Array<String> = [];

		for(i in 0...simpleList.get("Yours").length) {
			eventList.push(simpleList.get("Yours")[i][0]);
		}

		howToTutorial.text = simpleList.get("Yours")[0][1];

		var yourList:DropDown = findC(UI_Modifiers, "yourList", DropDown);
		ddSetData(yourList, eventList);
		yourList.onChange = function(_) {
			var idx:Int = yourList.selectedIndex;
			if(idx < 0) return;
			if(eventList[idx].trim() != "") {
				wtfIsEvent = eventList[idx];

				makeYourValue.text = "";
				makeYourTwoValue.text = "";
				howToTutorial.text = simpleList.get("Yours")[idx][1];
			}
		};
	}

	function addRegularEventUI():Void {
		var makeRegularName:TextField = findC(UI_Modifiers, "makeRegularName", TextField);
		var makeRegularValue:TextField = findC(UI_Modifiers, "makeRegularValue", TextField);
		var makeRegularTwoValue:TextField = findC(UI_Modifiers, "makeRegularTwoValue", TextField);
		var howToTutorial:Label = findC(UI_Modifiers, "howToTutorial_reg", Label);

		findC(UI_Modifiers, "createEventButton_reg", Button).onClick = function(_) {
			if(curStep < 0 || curStep < curSection*16 || makeRegularName.text == "")
				return;

			for(i in 0..._song.modifiers.length) {
				var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");

				if(gridY == GRID_SIZE*curStep)
					return;
			}

			var createEvent:EventInfo = {modSkill: wtfIsEvent, modGridY: GRID_SIZE*curStep, modValue: null, modValueTwo: null, modDisplayName: makeRegularName.text};

			switch(createEvent.modSkill) {
				case "alt animation":
					createEvent.modValue = makeRegularValue.text.toLowerCase();
					createEvent.modValueTwo = "value 2:";
				case "jumpspeed":
					if(Std.parseInt(makeRegularValue.text) != null)
						createEvent.modValue = Std.string(Math.min(3, Math.max(0.5, Std.parseFloat(makeRegularValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeRegularTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(6, Math.max(1, Std.parseFloat(makeRegularTwoValue.text))));
					else
						createEvent.modValueTwo = "1";
				case "sicko shake":
					if(Std.parseInt(makeRegularValue.text) != null)
						createEvent.modValue = Std.string(Math.min(10, Math.max(1, Std.parseInt(makeRegularValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeRegularTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(10, Math.max(1, Std.parseInt(makeRegularTwoValue.text))));
					else
						createEvent.modValueTwo = "0";
				case "time freeze":
					if(Std.parseInt(makeRegularValue.text) != null)
						createEvent.modValue = Std.string(Math.min(1, Math.max(0, Std.parseInt(makeRegularValue.text))));
					else
						createEvent.modValue = "0";

					if(Std.parseInt(makeRegularTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(4, Math.max(0, Std.parseFloat(makeRegularTwoValue.text))));
					else
						createEvent.modValueTwo = "1";
				case "strum bounce":
					if(Std.parseInt(makeRegularValue.text) != null)
						createEvent.modValue = Std.string(Math.min(200, Math.max(-200, Std.parseInt(makeRegularValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeRegularTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(30, Math.max(0, Std.parseInt(makeRegularTwoValue.text))));
					else
						createEvent.modValueTwo = "10";
				case "note rewind":
					if(Std.parseInt(makeRegularValue.text) != null)
						createEvent.modValue = Std.string(Math.min(16, Math.max(0, Std.parseInt(makeRegularValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeRegularTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(9, Math.max(1, Std.parseFloat(makeRegularTwoValue.text))));
					else
						createEvent.modValueTwo = "1";
				case "opponent change":
					createEvent.modValue = makeRegularValue.text.toLowerCase();
					createEvent.modValueTwo = "value 2:";
				case "bump per beat":
					if(Std.parseInt(makeRegularValue.text) != null)
						createEvent.modValue = Std.string(Math.max(0, Std.parseInt(makeRegularValue.text)));
					else
						createEvent.modValue = "1";
				case "v-slice event":
					createEvent.modValue = makeRegularValue.text;
					createEvent.modValueTwo = makeRegularTwoValue.text;
				case "clear all":
					createEvent.modValue = null;
					createEvent.modValueTwo = null;
			}

			_song.modifiers.push(createEvent);

			createPhysicalEvent(_song.modifiers.length-1, curStep, createEvent.modValue, createEvent.modValueTwo);
		};

		findC(UI_Modifiers, "removeEventButton_reg", Button).onClick = function(_) {
			if(curStep < 0 || curStep < curSection*16)
				return;

			if(!removeDelay)
				removePhysicalEvent(curStep);
		};

		var eventList:Array<String> = [];

		for (i in 0...simpleList.get("Regular").length)
			eventList.push(simpleList.get("Regular")[i][0]);

		howToTutorial.text = simpleList.get("Regular")[0][1];

		var RegularList:DropDown = findC(UI_Modifiers, "RegularList", DropDown);
		ddSetData(RegularList, eventList);
		RegularList.onChange = function(_) {
			var idx:Int = RegularList.selectedIndex;
			if(idx < 0) return;
			wtfIsEvent = eventList[idx];

			makeRegularValue.text = "";
			makeRegularTwoValue.text = "";
			howToTutorial.text = simpleList.get("Regular")[idx][1];
		};
	}

	function addSettingsEventUI():Void {
		var stepperCopy:NumberStepper = findC(UI_Modifiers, "stepperCopy_set", NumberStepper);

		findC(UI_Modifiers, "copyButton_set", Button).onClick = function(_) {
			copyEvent(-Std.int(stepperCopy.pos));
		};

		findC(UI_Modifiers, "clearSectionButton_set", Button).onClick = function(_) {
			clearEvents(false);
		};

		findC(UI_Modifiers, "clearAllButton", Button).onClick = function(_) {
			clearEvents(true);
		};
	}

	var check_mute_inst:CheckBox;

	var playOSU_Sound_RIGHT:Bool;
	var playOSU_Sound_LEFT:Bool;

	var metronome:Bool;

	function addSongUI():Void
	{
		typingShit = findC(UI_box, "songTitle", TextField);
		typingShit.text = _song.song;

		var check_voices:CheckBox = findC(UI_box, "check_voices", CheckBox);
		check_voices.selected = _song.needsVoices;
		check_voices.onChange = function(_)
		{
			_song.needsVoices = check_voices.selected;
			trace('CHECKED!');
		};

		check_mute_inst = findC(UI_box, "check_mute_inst", CheckBox);
		check_mute_inst.selected = false;
		check_mute_inst.onChange = function(_)
		{
			var vol:Float = 1;

			if (check_mute_inst.selected)
				vol = 0;

			FlxG.sound.music.volume = vol;
		};

		var check_fifth:CheckBox = findC(UI_box, "check_fifth", CheckBox);
		check_fifth.selected = _song.fifthKey;
		check_fifth.onChange = function(_)
		{
			if (check_fifth.selected)
				adjustChartNotesToFiveKey();
			else
				_song.fifthKey = false;

			refreshChartLaneLayout();
			updateGrid();
		};

		var check_mute_inst_game:CheckBox = findC(UI_box, "check_mute_inst_game", CheckBox);
		check_mute_inst_game.selected = PlayState.muteInst;
		check_mute_inst_game.onChange = function(_)
		{
			muteInGame = check_mute_inst_game.selected;
		};

		var metronome_check:CheckBox = findC(UI_box, "metronome_check", CheckBox);
		metronome_check.selected = false;
		metronome_check.onChange = function(_) {
			metronome = metronome_check.selected;
		};

		var check_hit_right:CheckBox = findC(UI_box, "check_hit_right", CheckBox);
		check_hit_right.selected = false;
		check_hit_right.onChange = function(_) {
			playOSU_Sound_RIGHT = check_hit_right.selected;
		};

		var check_hit_left:CheckBox = findC(UI_box, "check_hit_left", CheckBox);
		check_hit_left.selected = false;
		check_hit_left.onChange = function(_) {
			playOSU_Sound_LEFT = check_hit_left.selected;
		};

		findC(UI_box, "saveButton", Button).onClick = function(_)
		{
			saveLevel();
		};

		findC(UI_box, "reloadSong", Button).onClick = function(_)
		{
			loadSong(_song.song);
		};

		findC(UI_box, "reloadSongJson", Button).onClick = function(_)
		{
			loadJson(_song.song.toLowerCase());
		};

		findC(UI_box, "restart", Button).onClick = function(_)
        {
            for (ii in 0..._song.notes.length)
            {
                for (i in 0..._song.notes[ii].sectionNotes.length)
                    {
                        _song.notes[ii].sectionNotes = [];
                    }
            }

            resetSection(true);
			clearEvents(true);
    	};

		adjustNotes5kButton = findC(UI_box, "adjustNotes5kButton", Button);
		adjustNotes5kButton.onClick = function(_)
		{
			adjustChartNotesToFiveKey();
			check_fifth.selected = _song.fifthKey;
			refreshChartLaneLayout();
			updateGrid();
		};
		refreshChartLaneLayout();

		findC(UI_box, "loadAutosaveBtn", Button).onClick = function(_) loadAutosave();

		stepperSpeed = findC(UI_box, "stepperSpeed", NumberStepper);
		stepperSpeed.pos = _song.speed;
		stepperSpeed.onChange = function(_) {
			_song.speed = stepperSpeed.pos;
		};

		speedLabel = findC(UI_box, "speedLabel", Label);

		var stepperBPM:NumberStepper = findC(UI_box, "stepperBPM", NumberStepper);
		stepperBPM.pos = Conductor.instance.activeBpm;
		stepperBPM.onChange = function(_) {
			if (stepperBPM.pos <= 0)
				stepperBPM.pos = 1;
			tempBpm = Std.int(stepperBPM.pos);
			Conductor.instance.mapTimeChangesFromSong(_song);
			Conductor.instance.forceBPM(stepperBPM.pos);
		};

		var player1DropDown:DropDown = findC(UI_box, "player1DropDown", DropDown);
		ddSetData(player1DropDown, DefaultHandler.getcharacterJSON());
		player1DropDown.onChange = function(_)
		{
			var idx:Int = player1DropDown.selectedIndex;
			if(idx < 0) return;
			_song.player1 = DefaultHandler.getcharacterJSON()[idx];
			updateHeads();
		};
		ddSelectLabel(player1DropDown, _song.player1);

		var player2DropDown:DropDown = findC(UI_box, "player2DropDown", DropDown);
		ddSetData(player2DropDown, DefaultHandler.getcharacterJSON());
		player2DropDown.onChange = function(_)
		{
			var idx:Int = player2DropDown.selectedIndex;
			if(idx < 0) return;
			_song.player2 = DefaultHandler.getcharacterJSON()[idx];
			updateHeads();
		};
		ddSelectLabel(player2DropDown, _song.player2);

		camFollow = new FlxObject(360, 0, 1, 1);
		add(camFollow);

		FlxG.camera.follow(camFollow);
	}

	var stepperLength:NumberStepper;
	var check_mustHitSection:CheckBox;
	var check_changeBPM:CheckBox;
	var check_show_extra:CheckBox;
	var stepperSectionBPM:NumberStepper;

	function addSectionUI():Void
	{
		stepperLength = findC(UI_box, "stepperLength", NumberStepper);
		stepperLength.pos = getSectionLength(curSection);
		stepperLength.onChange = function(_) {
			if (stepperLength.pos <= 4)
				stepperLength.pos = 4;
			_song.notes[curSection].lengthInSteps = Std.int(stepperLength.pos);
			updateGrid();
		};

		stepperSectionBPM = findC(UI_box, "stepperSectionBPM", NumberStepper);
		stepperSectionBPM.pos = Conductor.instance.activeBpm;
		stepperSectionBPM.onChange = function(_) {
			if (stepperSectionBPM.pos <= 0.1)
				stepperSectionBPM.pos = 0.1;
			_song.notes[curSection].bpm = Std.int(stepperSectionBPM.pos);
			updateGrid();
		};

		var stepperCopy:NumberStepper = findC(UI_box, "stepperCopy_section", NumberStepper);

		findC(UI_box, "copyButton_section", Button).onClick = function(_)
		{
			copySection(Std.int(stepperCopy.pos));
		};

		findC(UI_box, "clearSectionButton", Button).onClick = function(_) clearSection();

		findC(UI_box, "swapSection", Button).onClick = function(_)
		{
			swapCopy(0);
		};

		check_mustHitSection = findC(UI_box, "check_mustHitSection", CheckBox);
		check_mustHitSection.selected = true;
		check_mustHitSection.onChange = function(_) {
			_song.notes[curSection].mustHitSection = check_mustHitSection.selected;
			updateHeads();
		};

		check_changeBPM = findC(UI_box, "check_changeBPM", CheckBox);
		check_changeBPM.onChange = function(_) {
			_song.notes[curSection].changeBPM = check_changeBPM.selected;
		};

		check_show_extra = findC(UI_box, "check_show_extra", CheckBox);
		check_show_extra.onChange = function(_) {
			updateGrid();
		};
	}

	var stepperSusLength:NumberStepper;
	var noteTypeEffect:DropDown;
	var noteAddonEffect:DropDown;

	var check_extra_stuff:CheckBox;
	var subDivideDummy:NumberStepper;
	var subLabel:Label;
	var noteTagInput:TextField;
	var noteTagText:Label;
	var playAnimCheck:CheckBox;
	
	function addNoteUI():Void
	{
		final DaNotes:Array<String> = CoolUtil.coolTextFile(Paths.pak('mapHandler'));

		var noteAddons:Array<String> = new Array<String>();

		for(v in CustomNoteHandler.customNoteAddon.keys()) {
			if(!noteAddons.contains(v) && !DaNotes.contains(v))
				noteAddons.push(v);
		}

		writingNotesText = findC(UI_box, "writingNotesText", Label);

		stepperSusLength = findC(UI_box, "stepperSusLength", NumberStepper);
		stepperSusLength.step = Conductor.instance.stepLengthMs / 2;
		stepperSusLength.max = Conductor.instance.stepLengthMs * getSectionLength(curSection) * 4;
		stepperSusLength.pos = 0;
		stepperSusLength.onChange = function(_) {
			if (curSelectedNote == null)
				return;
			if (stepperSusLength.pos <= 0)
				stepperSusLength.pos = 0;
			curSelectedNote[2] = stepperSusLength.pos;
			updateGrid();
		};

		check_extra_stuff = findC(UI_box, "check_extra_stuff", CheckBox);
		check_extra_stuff.selected = false;
		check_extra_stuff.onChange = function(_)
		{
			var vis:Bool = check_extra_stuff.selected;
			subDivideDummy.hidden = !vis;
			subLabel.hidden = !vis;
			noteTagInput.hidden = !vis;
			noteTagText.hidden = !vis;
			playAnimCheck.hidden = !vis;
		};

		noteTypeEffect = findC(UI_box, "noteTypeEffect", DropDown);
		ddSetData(noteTypeEffect, DaNotes);
		noteTypeEffect.onChange = function(_) {
			var idx:Int = noteTypeEffect.selectedIndex;
			if(idx >= 0) wtfIsNote = DaNotes[idx];
		};

		noteAddonEffect = findC(UI_box, "noteAddonEffect", DropDown);
		if(noteAddons[0] != null) {
			ddSetData(noteAddonEffect, noteAddons);
			noteAddonEffect.onChange = function(_) {
				var idx:Int = noteAddonEffect.selectedIndex;
				if(idx >= 0) wtfIsNote = noteAddons[idx];
			};
		} else {
			noteAddonEffect.hidden = true;
		}

		subDivideDummy = findC(UI_box, "subDivideDummy", NumberStepper);
		subDivideDummy.pos = 1;
		subDivideDummy.hidden = true;

		subLabel = findC(UI_box, "subLabel", Label);
		subLabel.hidden = true;

		noteTagInput = findC(UI_box, "noteTagInput", TextField);
		noteTagInput.hidden = true;

		noteTagText = findC(UI_box, "noteTagText", Label);
		noteTagText.hidden = true;

		playAnimCheck = findC(UI_box, "playAnimCheck", CheckBox);
		playAnimCheck.selected = true;
		playAnimCheck.hidden = true;

		findC(UI_box, "commitChangesButton", Button).onClick = function(_) {
			modifyNote(curSelectedNote);

			updateGrid();
			updateNoteUI();
		};
	}

	var plr1X:NumberStepper;
	var plr1Y:NumberStepper;

	var plr2X:NumberStepper;
	var plr2Y:NumberStepper;

	function addWorldMapUI():Void {
		plr1X = findC(UI_box, "plr1X", NumberStepper);
		plr1X.pos = _song.player1X;
		plr1X.onChange = function(_) { _song.player1X = Std.int(plr1X.pos); updateGrid(); };

		plr1Y = findC(UI_box, "plr1Y", NumberStepper);
		plr1Y.pos = _song.player1Y;
		plr1Y.onChange = function(_) { _song.player1Y = Std.int(plr1Y.pos); updateGrid(); };

		plr2X = findC(UI_box, "plr2X", NumberStepper);
		plr2X.pos = _song.player2X;
		plr2X.onChange = function(_) { _song.player2X = Std.int(plr2X.pos); updateGrid(); };

		plr2Y = findC(UI_box, "plr2Y", NumberStepper);
		plr2Y.pos = _song.player2Y;
		plr2Y.onChange = function(_) { _song.player2Y = Std.int(plr2Y.pos); updateGrid(); };

		var girlfriendDropDown:DropDown = findC(UI_box, "girlfriendDropDown", DropDown);
		ddSetData(girlfriendDropDown, DefaultHandler.getcharacterJSON());
		girlfriendDropDown.onChange = function(_) {
			var idx:Int = girlfriendDropDown.selectedIndex;
			if(idx >= 0) _song.girlfriend = DefaultHandler.getcharacterJSON()[idx];
		};
		ddSelectLabel(girlfriendDropDown, _song.girlfriend);

		var stageDropDown:DropDown = findC(UI_box, "stageDropDown", DropDown);
		ddSetData(stageDropDown, Paths.modJSON.mod.stages);
		stageDropDown.onChange = function(_) {
			var idx:Int = stageDropDown.selectedIndex;
			if(idx >= 0) _song.stage = Paths.modJSON.mod.stages[idx];
		};
		ddSelectLabel(stageDropDown, _song.stage);
	}

	function loadSong(daSong:String):Void
	{
		if (FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}

		loadSongVocals(daSong);

		setupSong(daSong);
		FlxG.sound.music.pause();
		Conductor.instance.trackedSongPosition = sectionStartTime(curSection);
		FlxG.sound.music.time = Conductor.instance.trackedSongPosition;
		setVocalsTime(Conductor.instance.trackedSongPosition);
	}

	function setupSong(daSong:String):Void {
		FlxG.sound.playMusic(Paths.inst(daSong), 0.6);

		if(check_mute_inst != null && check_mute_inst.selected) {
			FlxG.sound.music.volume = 0;
		}

		FlxG.sound.music.onComplete = function() {
			FlxG.sound.music.pause();
			Conductor.instance.trackedSongPosition = 0;

			pauseVocals();
			setVocalsTime(0);

			changeSection();
			curSection = 0;
			updateGrid();
			updateSectionUI();
			playVocals();
		};
	}

	private function loadSongVocals(song:String):Void
	{
		destroyVocals();
		opponentVocals = null;
		extraVocals = [];

		if (_song.needsVoices)
		{
			var hasSplitVocals:Bool = Paths.songSoundExists(song, "1_Voices") && Paths.songSoundExists(song, "2_Voices");
			var hasSingleVocals:Bool = Paths.songSoundExists(song, "Voices");

			if (hasSplitVocals)
			{
				vocals = new FlxSound().loadEmbedded(Paths.songSound(song, "1_Voices"));
				opponentVocals = new FlxSound().loadEmbedded(Paths.songSound(song, "2_Voices"));
			}
			else if (hasSingleVocals)
			{
				vocals = new FlxSound().loadEmbedded(Paths.voices(song));
			}
			else
			{
				trace("Warning: no vocals found for " + song + ", continuing without vocals.");
				vocals = new FlxSound();
			}
		}
		else
		{
			vocals = new FlxSound();
		}

		FlxG.sound.list.add(vocals);

		if (opponentVocals != null)
		{
			FlxG.sound.list.add(opponentVocals);
		}

		for (extraVoiceFile in discoverExtraVoiceFiles(song))
		{
			var extraTrack = new FlxSound().loadEmbedded(Paths.songSound(song, extraVoiceFile));
			extraVocals.push(extraTrack);
			FlxG.sound.list.add(extraTrack);
		}
	}

	private function discoverExtraVoiceFiles(song:String):Array<String>
	{
		var results:Array<String> = [];

		#if sys
		var normalizedSong = song.toLowerCase();
		var candidateDirectories:Array<String> = [
			Paths.getCoreAssets() + 'mod_assets/songs/$normalizedSong',
			'mod_assets/songs/$normalizedSong',
			Paths.getCoreAssets() + 'funkin_assets/songs/$normalizedSong',
			'funkin_assets/songs/$normalizedSong'
		];

		for (directory in candidateDirectories)
		{
			if (!FileSystem.exists(directory) || !FileSystem.isDirectory(directory))
				continue;

			for (entry in FileSystem.readDirectory(directory))
			{
				var normalizedEntry = entry.toLowerCase();
				var extension = '.${Paths.SOUND_EXT}';

				if (!normalizedEntry.endsWith(extension))
					continue;

				var fileName = entry.substr(0, entry.length - extension.length);
				if (!fileName.endsWith("_Voices"))
					continue;

				if (fileName == "1_Voices" || fileName == "2_Voices" || fileName == "Voices")
					continue;

				if (!results.contains(fileName) && Paths.songSoundExists(song, fileName))
					results.push(fileName);
			}
		}
		#end

		results.sort(Reflect.compare);
		return results;
	}

	private function destroyVocals():Void
	{
		destroyVocalTrack(vocals);
		destroyVocalTrack(opponentVocals);
		for (track in extraVocals)
			destroyVocalTrack(track);

		vocals = null;
		opponentVocals = null;
		extraVocals = [];
	}

	private function destroyVocalTrack(track:FlxSound):Void
	{
		if (track == null)
			return;

		track.stop();
		FlxG.sound.list.remove(track);
		track.destroy();
	}

	private inline function pauseVocals():Void
	{
		if (vocals != null)
			vocals.pause();

		if (opponentVocals != null)
			opponentVocals.pause();

		for (track in extraVocals)
			track.pause();
	}

	private inline function playVocals():Void
	{
		if (vocals != null)
			vocals.play();

		if (opponentVocals != null)
			opponentVocals.play();

		for (track in extraVocals)
			track.play();
	}

	private inline function stopVocals():Void
	{
		if (vocals != null)
			vocals.stop();

		if (opponentVocals != null)
			opponentVocals.stop();

		for (track in extraVocals)
			track.stop();
	}

	private inline function setVocalsTime(time:Float):Void
	{
		if (vocals != null)
			vocals.time = time;

		if (opponentVocals != null)
			opponentVocals.time = time;

		for (track in extraVocals)
			track.time = time;
	}

	private function applyIconCharacter(icon:HealthIcon, character:String, isPlayer:Bool):Void
	{
		if (icon == null || character == null || character.trim() == "")
			return;

		var iconFile:String = icon.getIconFileJSON(character);
		var iconAnimInfo:Array<Int> = icon.getIconJSON(character);

		if (iconFile == null || iconFile.trim() == "")
			iconFile = "iconGrid";

		if (icon.character == character && icon.iconFile == iconFile && icon.animation.getByName(character) != null)
		{
			icon.animation.play(character);
			return;
		}

		icon.animation.destroyAnimations();
		icon.loadNewIcons(iconFile);
		icon.createAnim(character, cast iconAnimInfo, isPlayer);
		icon.setGraphicSize(0, 45);
		icon.updateHitbox();
	}

	private function positionChartIcons():Void
	{
		if (leftIcon == null || rightIcon == null || gridBG == null)
			return;

		var halfWidth:Float = gridBG.width * 0.5;

		leftIcon.setPosition((halfWidth * 0.5) - (leftIcon.width * 0.5), -100);
		rightIcon.setPosition(halfWidth + (halfWidth * 0.5) - (rightIcon.width * 0.5), -100);
	}

	inline function getChartLaneCountPerSide():Int
	{
		return _song.fifthKey ? 5 : 4;
	}

	inline function getChartGridCount():Int
	{
		return getChartLaneCountPerSide() * 2;
	}

	inline function getDisplayLaneCountPerSide():Int
	{
		return getChartLaneCountPerSide();
	}

	inline function getDisplayGridCount():Int
	{
		return getDisplayLaneCountPerSide() * 2;
	}

	inline function usesExpandedGridLayout():Bool
	{
		return _song.fifthKey;
	}

	inline function shouldHideCompactFourKeyOverflow():Bool
	{
		return !_song.fifthKey;
	}

	function getDisplayColumnFromStoredData(noteData:Int):Int
	{
		return noteData;
	}

	function getStoredDataFromDisplayColumn(column:Int):Int
	{
		if (column < 0 || column >= getDisplayGridCount())
			return -1;

		return column;
	}

	function getDisplayColumnFromMouseX(mouseX:Float):Int
	{
		return Math.floor((mouseX - gridBG.x) / GRID_SIZE);
	}

	function getStoredDataFromNoteX(noteX:Float):Int
	{
		return getStoredDataFromDisplayColumn(Math.floor((noteX - gridBG.x) / GRID_SIZE));
	}

	function refreshChartLaneLayout():Void
	{
		mainGrid = getDisplayGridCount();

		if (bpmTxt != null)
			bpmTxt.x = usesExpandedGridLayout() ? 1050 : 1000;

		if (UI_box != null)
			UI_box.left = usesExpandedGridLayout() ? FlxG.width / 2 + GRID_SIZE : FlxG.width / 2;

		if (UI_Modifiers != null && UI_box != null)
			UI_Modifiers.left = usesExpandedGridLayout() ? FlxG.width / 2 + GRID_SIZE + UI_box.width : FlxG.width / 2 + UI_box.width;

		if (instrucTxt != null && UI_box != null)
			instrucTxt.x = UI_box.left;

		if (camFollow != null)
			camFollow.x = usesExpandedGridLayout() ? 400 : 360;

		positionChartIcons();
	}

	function adjustChartNotesToFiveKey():Void
	{
		if (_song.fifthKey && chartAlreadyUsesExpandedFiveKeyData())
		{
			_song.fifthKey = true;
			return;
		}

		for (section in _song.notes)
		{
			if (section == null || section.sectionNotes == null)
				continue;

				for (note in section.sectionNotes)
				{
					if (note == null || note.length < 2 || note[1] == null)
						continue;

					var noteData:Int = Std.int(note[1]);
					if (noteData < 0 || noteData >= 8)
						continue;

					var side:Int = noteData >= 4 ? 1 : 0;
					var lane:Int = noteData % 4;

					if (lane >= 2)
					lane += 1;

				note[1] = lane + (side * 5);
			}
		}

		_song.fifthKey = true;
	}

	function chartAlreadyUsesExpandedFiveKeyData():Bool
	{
		for (section in _song.notes)
		{
			if (section == null || section.sectionNotes == null)
				continue;

			for (note in section.sectionNotes)
			{
				if (note == null || note.length < 2 || note[1] == null)
					continue;

				if (Std.int(note[1]) >= 8)
					return true;
			}
		}

		return false;
	}

	function generateUI():Void {}

	var updatedSection:Bool = false;

	function sectionStartTime(section:Int):Float
	{
		var totalSteps:Float = 0;
		for (i in 0...section)
		{
			totalSteps += getSectionLength(i);
		}
		return Conductor.instance.getStepTimeInMs(totalSteps);
	}

	var writingNotes:Bool = false;
	var lastSongPosition:Float = 0;
	var lastMetronomeStep:Int = 0;
	var lastSusLengthStepperValue:Float = 0;

	override function update(elapsed:Float)
	{
		curStep = recalculateSteps();

		if(FlxG.sound.music.time < 0) {
			FlxG.sound.music.pause();
			FlxG.sound.music.time = 0;
		}
		else if(FlxG.sound.music.time > FlxG.sound.music.length) {
			FlxG.sound.music.pause();
			FlxG.sound.music.time = 0;
			changeSection();
		}

		Conductor.instance.trackedSongPosition = FlxG.sound.music.time;

		if (stepperSusLength != null && curSelectedNote != null)
		{
			var stepperSusValue = Math.max(0, stepperSusLength.pos);
			var selectedSusValue:Float = curSelectedNote[2] == null ? 0 : curSelectedNote[2];

			if (Math.abs(stepperSusValue - lastSusLengthStepperValue) > 0.001 && Math.abs(stepperSusValue - selectedSusValue) > 0.001)
			{
				curSelectedNote[2] = stepperSusValue;
				updateGrid();
			}

			lastSusLengthStepperValue = stepperSusLength.pos;
		}

		if(selectingShader != null)
			selectingShader.shaderValue.value[0] += elapsed;

		if(!check_extra_stuff.selected && !subDivideDummy.hidden) {
			subDivideDummy.hidden = true;
			subLabel.hidden = true;
			noteTagInput.hidden = true;
			noteTagText.hidden = true;
			playAnimCheck.hidden = true;
			speedLabel.hidden = false;
		}

		if(subDivideDummy.pos > 1 && !check_extra_stuff.selected)
			subDivideDummy.pos = 1;

		if (FlxG.keys.justPressed.ALT && boxTab(UI_box) == 0) {
			writingNotes = !writingNotes;
		}

		if(FlxG.keys.justPressed.I) {
			zoomMeter--;
			changeZoomDisplay();
		}

		if(FlxG.keys.justPressed.O) {
			zoomMeter++;
			changeZoomDisplay();
		}

		if(FlxG.keys.justPressed.C && curSelectedNote != null) {
			if(FlxG.keys.pressed.UP && _song.notes[curSection].sectionNotes.indexOf(curSelectedNote) > 0) {
				prevSelectedNote = curSelectedNote;

				for(i in 0...(_song.notes[curSection].sectionNotes.indexOf(curSelectedNote) - 1)) {
					curSelectedNote = _song.notes[curSection].sectionNotes[i];

					if(curSelectedNote != null) {
						break;
					}
				}
			}
			
			if(FlxG.keys.pressed.DOWN && _song.notes[curSection].sectionNotes.indexOf(curSelectedNote) < _song.notes[curSection].sectionNotes.length) {
				prevSelectedNote = curSelectedNote;

				for(i in (_song.notes[curSection].sectionNotes.indexOf(curSelectedNote) + 1)..._song.notes[curSection].sectionNotes.length) {
					curSelectedNote = _song.notes[curSection].sectionNotes[i];

					if(curSelectedNote != null) {
						break;
					}
				}
			}

			modifyNote(curSelectedNote, prevSelectedNote);

			updateNoteUI();
			updateGrid();
		}

		if (writingNotes)
			writingNotesText.text = "WRITING NOTES";
		else
			writingNotesText.text = "";

		_song.song = typingShit.text;

		var upP = controls.GAME_UP_P;
		var rightP = controls.GAME_RIGHT_P;
		var downP = controls.GAME_DOWN_P;
		var leftP = controls.GAME_LEFT_P;

		var controlArray:Array<Bool> = [leftP, downP, upP, rightP];

		if (controlArray.contains(true) && writingNotes)
		{
			for(i in 0...controlArray.length)
			{
				if (controlArray[i])
				{
					for (n in 0..._song.notes[curSection].sectionNotes.length)
						{
							var note = _song.notes[curSection].sectionNotes[n];
							if (note == null)
								continue;
							if (note[0] == Conductor.instance.trackedSongPosition && note[1] % getChartLaneCountPerSide() == i)
							{
								trace('GAMING');
								_song.notes[curSection].sectionNotes.remove(note);
							}
						}
					trace('adding note');
					_song.notes[curSection].sectionNotes.push([Conductor.instance.trackedSongPosition, i, 0]);
					updateGrid();
				}
			}

		}

		strumLine.y = getYfromStrum((Conductor.instance.trackedSongPosition - sectionStartTime(curSection)) / (zoomList[zoomMeter]/100) % (Conductor.instance.stepLengthMs * getSectionLength(curSection)));
		camFollow.y = strumLine.y;

		if (curBeat % 4 == 0 && curStep >= 16 * (curSection + 1))
		{
			if (_song.notes[curSection + 1] == null)
			{
				addSection();
			}

			changeSection(curSection + 1, false);
		}else if(curStep < curSection * 16 && FlxG.mouse.wheel != 0) {
			changeSection(curSection - 1, false);
		}

		FlxG.watch.addQuick('daBeat', curBeat);
		FlxG.watch.addQuick('daStep', curStep);

		if (FlxG.mouse.justPressed)
		{
			if (FlxG.mouse.overlaps(curRenderedNotes))
			{
				curRenderedNotes.forEachAlive(function(note:Note)
				{
					//TODO: Replace overlaps with a custom made function

					if (FlxG.mouse.overlaps(note))
					{
						if (FlxG.keys.pressed.CONTROL)
						{
							selectNote(note);
						}
						else
						{
							deleteNote(note);
						}
					}
				});
			}
			else
			{
				if (FlxG.mouse.x > gridBG.x
					&& FlxG.mouse.x < gridBG.x + gridBG.width
					&& FlxG.mouse.y > gridBG.y
					&& FlxG.mouse.y < gridBG.y + checkSectionsY() * (zoomList[zoomMeter]/100))
				{
					FlxG.log.add('added note');
					addNote();
				}
			}
		}

		if (FlxG.mouse.x > gridBG.x
			&& FlxG.mouse.x < gridBG.x + gridBG.width
			&& FlxG.mouse.y > gridBG.y
			&& FlxG.mouse.y < gridBG.y + checkSectionsY() * (zoomList[zoomMeter]/100))
		{
			dummyArrow.x = getDisplayColumnFromMouseX(FlxG.mouse.x) * GRID_SIZE;
			if (FlxG.keys.pressed.SHIFT && !check_extra_stuff.selected)
				dummyArrow.y = FlxG.mouse.y;
			else
				dummyArrow.y = Math.floor(FlxG.mouse.y / (GRID_SIZE/subDivideDummy.pos)) * (GRID_SIZE/subDivideDummy.pos);
		}

		if (FlxG.keys.justPressed.ENTER)
		{
			lastSection = curSection;

			PlayState.SONG = _song;
			FlxG.sound.music.stop();
			stopVocals();
			
			CacheState.loadAndSwitchState(new PlayState(muteInGame));
		}

		if (FlxG.keys.justPressed.E)
		{
			changeNoteSustain(Conductor.instance.stepLengthMs);
		}
		if (FlxG.keys.justPressed.Q)
		{
			changeNoteSustain(-Conductor.instance.stepLengthMs);
		}

		if (FlxG.keys.justPressed.TAB)
		{
			if (FlxG.keys.pressed.SHIFT)
			{
				var t:Int = boxTab(UI_box) - 1;
				if (t < 0) t = 2;
				setBoxTab(UI_box, t);
			}
			else
			{
				var t:Int = boxTab(UI_box) + 1;
				if (t >= 3) t = 0;
				setBoxTab(UI_box, t);
			}
		}

		if (!typingShit.focus)
		{

			if (FlxG.keys.pressed.CONTROL)
			{
				if (FlxG.keys.justPressed.Z && lastNote != null)
				{
					trace(curRenderedNotes.members.contains(lastNote) ? "delete note" : "add note");
					if (curRenderedNotes.members.contains(lastNote))
						deleteNote(lastNote);
					else 
						addNote(lastNote);
				}
			}

			var shiftThing:Int = 1;
			if (FlxG.keys.pressed.SHIFT)
				shiftThing = 4;
			if (!writingNotes)
			{
				if (FlxG.keys.justPressed.RIGHT || FlxG.keys.justPressed.D)
					changeSection(curSection + shiftThing);
				if (FlxG.keys.justPressed.LEFT || FlxG.keys.justPressed.A)
					changeSection(curSection - shiftThing);
			}	
			if (FlxG.keys.justPressed.SPACE)
			{
				if (FlxG.sound.music.playing)
				{
					FlxG.sound.music.pause();
					pauseVocals();
				}
				else
				{
					setVocalsTime(FlxG.sound.music.time);
					playVocals();

					FlxG.sound.music.play();
				}
			}

			if (FlxG.keys.justPressed.R)
			{
				if (FlxG.keys.pressed.SHIFT)
					resetSection(true);
				else
					resetSection();
			}

			if (FlxG.mouse.wheel != 0)
			{
				FlxG.sound.music.pause();
				pauseVocals();

				FlxG.sound.music.time -= FlxG.mouse.wheel * Conductor.instance.stepLengthMs * 0.4;
				setVocalsTime(FlxG.sound.music.time);
			}

			if (!FlxG.keys.pressed.SHIFT)
			{
				if (FlxG.keys.pressed.W || FlxG.keys.pressed.S)
				{
					FlxG.sound.music.pause();
					pauseVocals();

					var daTime:Float = 700 * FlxG.elapsed;

					if (FlxG.keys.pressed.W)
					{
						FlxG.sound.music.time -= daTime;
					}
					else
						FlxG.sound.music.time += daTime;

					setVocalsTime(FlxG.sound.music.time);
				}
			}
			else
			{
				if (FlxG.keys.justPressed.W || FlxG.keys.justPressed.S)
				{
					FlxG.sound.music.pause();
					pauseVocals();

					var daTime:Float = Conductor.instance.stepLengthMs * 2;

					if (FlxG.keys.justPressed.W)
					{
						FlxG.sound.music.time -= daTime;
					}
					else
						FlxG.sound.music.time += daTime;

					setVocalsTime(FlxG.sound.music.time);
				}
			}
		}

		curRenderedNotes.forEachAlive(function(note:Note) {
			if(note.strumTime <= Conductor.instance.trackedSongPosition) {
				if(note.strumTime > lastSongPosition && FlxG.sound.music.playing && note.noteData > -1) {
					if(playOSU_Sound_RIGHT && Math.ceil(note.x / GRID_SIZE) > Math.ceil(mainGrid/2) - 1) {
						FlxG.sound.play(Paths.sound('hitChart'), 2);
					}

					if(playOSU_Sound_LEFT && Math.ceil(note.x / GRID_SIZE) < Math.ceil(mainGrid/2)) {
						FlxG.sound.play(Paths.sound('hitChart'), 2);
					}
				}
			}
		});

		if(Conductor.instance.trackedSongPosition != lastSongPosition && FlxG.sound.music.playing && curStep % 4 == 0 && lastMetronomeStep != curStep && metronome) {
			FlxG.sound.play(Paths.sound('metronome'), 2);
		}

		_song.bpm = tempBpm;

		/* if (FlxG.keys.justPressed.UP)
				Conductor.instance.forceBPM(Conductor.instance.activeBpm + 1);
			if (FlxG.keys.justPressed.DOWN)
				Conductor.instance.forceBPM(Conductor.instance.activeBpm - 1); */

		bpmTxt.text = bpmTxt.text = Std.string(FlxMath.roundDecimal(Conductor.instance.trackedSongPosition / 1000, 2))
			+ " / "
			+ Std.string(FlxMath.roundDecimal(FlxG.sound.music.length / 1000, 2))
			+ "\nSection: "
			+ curSection 
			+ "\nStep Sis Counter: " 
			+ Math.max(0, curStep)
			+ "\nBeat Counter: "
			+ Math.max(0, curBeat)
			+ "\n"
			+ "\nMade By: Just-Feeshy";

		lastSongPosition = Conductor.instance.trackedSongPosition;
		lastMetronomeStep = curStep;

		super.update(elapsed);
	}

	function checkSectionsY():Float {
		if(check_show_extra != null) {
			if(check_show_extra.selected && _song.notes[curSection + 1] != null) {
				return (GRID_SIZE * getSectionLength(curSection)) + (GRID_SIZE * getSectionLength(curSection + 1));
			}
		}

		return GRID_SIZE * getSectionLength(curSection);
	}

	function changeZoomDisplay():Void {
		zoomMeter = Math.ceil(FeshMath.clamp(zoomMeter, 0, zoomList.length-1));
		zoomText.text =  "Zoom: " + zoomList[zoomMeter] + "%";
		updateGrid();
	}

	function changeNoteSustain(value:Float):Void
	{
		if (curSelectedNote != null)
		{
			if (curSelectedNote[2] != null)
			{
				curSelectedNote[2] += value;
				curSelectedNote[2] = Math.max(curSelectedNote[2], 0);
			}
		}

		updateNoteUI();
		updateGrid();
	}

	function recalculateSteps():Int
	{
		curStep = Math.floor(Conductor.instance.getTimeInSteps(FlxG.sound.music.time));
		curBeat = Math.floor(curStep / 4);
		updateBeat();

		return curStep;
	}

	function resetSection(songBeginning:Bool = false):Void
	{
		updateGrid();

		FlxG.sound.music.pause();
		pauseVocals();

		// Basically old shit from changeSection???
		FlxG.sound.music.time = sectionStartTime(curSection);

		if (songBeginning) {
			FlxG.sound.music.time = 0;
			curSection = 0;
		}

			setVocalsTime(FlxG.sound.music.time);

			updateCurStep();

			updateGrid();
			updateSectionUI();
	}

	function changeSection(sec:Int = 0, ?updateMusic:Bool = true):Void
	{
		if(osuManiaSounds[0] != null) {
			osuManiaSounds.splice(0, osuManiaSounds.length);
			osuManiaSounds = [];
		}	

		if (_song.notes[sec] != null)
		{
			curSection = sec;

			eventDisplay.clear();

			updateEvents();
			updateGrid();

			if (updateMusic)
			{
				FlxG.sound.music.pause();
				pauseVocals();

				/*var daNum:Int = 0;
					var daLength:Float = 0;
					while (daNum <= sec)
					{
						daLength += lengthBpmBullshit();
						daNum++;
				}*/

					FlxG.sound.music.time = sectionStartTime(curSection);
					setVocalsTime(FlxG.sound.music.time);
					updateCurStep();
				}

			updateGrid();
			updateSectionUI();
		}
	}

	function clearEvents(everything:Bool) {
		var eventStep:Array<Int> = [];

		if(everything) {
			for(i in 0..._song.modifiers.length) {
				for(v in _song.modifiers) {
					var gridY:Int = Reflect.field(v, "modGridY");

					eventStep.push(Std.int(gridY/GRID_SIZE));
					_song.modifiers.remove(v);
				}
			}		
		}else {
			for(i in 0..._song.modifiers.length) {
				for(v in _song.modifiers) {
					var gridY:Int = Reflect.field(v, "modGridY");

					if(gridY/GRID_SIZE >= curSection * 16 && gridY/GRID_SIZE < (curSection + 1) * 16) {
						eventStep.push(Std.int(gridY/GRID_SIZE));
						_song.modifiers.remove(v);
					}
				}
			}
		}	

		curPhysicalEvents.forEachAlive(function(eventSpr:FlxSprite) {

			if(eventStep.contains(eventSpr.ID)) {
				FlxTween.tween(eventSpr, {alpha: 0, angle: 0}, Conductor.instance.stepLengthMs / 300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
					eventSpr.kill();
					curPhysicalEvents.remove(eventSpr, true);
					eventSpr.destroy();
				}});
			}
		});

		eventDisplay.forEachAlive(function(eventTxt:FlxText) {

			if(eventStep.contains(eventTxt.ID)) {
				FlxTween.tween(eventTxt, {alpha: 0}, Conductor.instance.stepLengthMs / 300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
					eventTxt.kill();
					eventDisplay.remove(eventTxt, true);
					eventTxt.destroy();
				}});
			}		
		});

		eventStep = [];
	}

	function copyEvent(section:Int) {
		var eventPos:Array<Int> = [];

		for(v in _song.modifiers) {
			var gridY:Int = Reflect.field(v, "modGridY");
			eventPos.push(Std.int(gridY/GRID_SIZE));
		}	

		for(i in 0..._song.modifiers.length) {
			var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");
			var value:String = Reflect.field(_song.modifiers[i], "modValue");
			var value2:String = Reflect.field(_song.modifiers[i], "modValueTwo");
			var skill:String = Reflect.field(_song.modifiers[i], "modSkill");
			var name:String = Reflect.field(_song.modifiers[i], "modDisplayName");

			if(gridY/GRID_SIZE >= (curSection + section) * 16 && gridY/GRID_SIZE < (curSection + 1 + section) * 16) {
				if(!eventPos.contains(Std.int(gridY/GRID_SIZE) - (section * 16))) {
					var copyE:EventInfo = {modSkill: skill, modGridY: (Std.int(gridY/GRID_SIZE) - (section * 16))*GRID_SIZE, modValue: value, modValueTwo: value2, modDisplayName: name};

					_song.modifiers.push(copyE);
					createPhysicalEvent(i, Std.int(copyE.modGridY/GRID_SIZE), copyE.modValue, copyE.modValueTwo);
				}
			}
		}
		
		eventPos = [];
	}

	function copySection(?sectionNum:Int = 1)
	{
		var daSec = FlxMath.maxInt(curSection, sectionNum);

		if(sectionNum == 0)
			return;

		for (note in _song.notes[daSec - sectionNum].sectionNotes)
		{
			var strum = note[0] + (sectionStartTime(daSec) - sectionStartTime(daSec - sectionNum));
			trace(note);
			var copiedNote:Array<Dynamic> = [strum, note[1], note[2], note[3]];
			_song.notes[daSec].sectionNotes.push(copiedNote);
		}

		updateGrid();
	}

	function swapCopy(?sectionNum:Int = 1)
	{
		var daSec = FlxMath.maxInt(curSection, sectionNum);
	
		for (note in _song.notes[daSec - sectionNum].sectionNotes)
		{
			var strum = note[0] + (sectionStartTime(daSec) - sectionStartTime(daSec - sectionNum));
			var copiedNote:Array<Dynamic>;

			note[1] = (note[1] + getChartLaneCountPerSide()) % getChartGridCount();
			copiedNote = [strum, note[1], note[2], note[3]];

			if(sectionNum != 0)
				_song.notes[daSec].sectionNotes.push(copiedNote);
			else
				_song.notes[daSec].sectionNotes[_song.notes[curSection].sectionNotes.indexOf(note)] = copiedNote;
		}
	
		updateGrid();
	}

	function updateEvents():Void {
		if(curPhysicalEvents == null) {
			curPhysicalEvents = new FlxTypedGroup<FlxSprite>();
			add(curPhysicalEvents);
			eventDisplay = new FlxTypedGroup<FlxText>();
			add(eventDisplay);
		}else {
			while(curPhysicalEvents.members.length > 0) {
				curPhysicalEvents.remove(curPhysicalEvents.members[0], true);
			}
		}

		for(i in curPhysicalEvents.length..._song.modifiers.length) {
			var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");
			var value:String = Reflect.field(_song.modifiers[i], "modValue");
			var value2:String = Reflect.field(_song.modifiers[i], "modValueTwo");

			if(gridY/GRID_SIZE >= curSection * 16 && gridY/GRID_SIZE < (curSection + 1) * 16)
				createPhysicalEvent(i, Std.int(gridY/GRID_SIZE), value, value2);
		}
	}

	function createPhysicalEvent(getMod:Int, stepBro:Int, value:String, value2:String) {
		var skill:String = Reflect.field(_song.modifiers[getMod], "modSkill");
		var name:String = Reflect.field(_song.modifiers[getMod], "modDisplayName");
		var gridY:Int = Reflect.field(_song.modifiers[getMod], "modGridY");

		var eventNote:FlxSprite = new FlxSprite();
		eventNote.frames = Paths.getSparrowAtlas('EventHandler');
		eventNote.animation.addByPrefix(eventCatalog.get(skill), "EventHandler " + eventCatalog.get(skill));
		eventNote.animation.play(eventCatalog.get(skill));

		eventNote.setGraphicSize(GRID_SIZE, GRID_SIZE);
		eventNote.updateHitbox();
		eventNote.antialiasing = true;

		eventNote.setPosition(-GRID_SIZE, GRID_SIZE * ((gridY/GRID_SIZE) % 16));
		eventNote.alpha = 0;
		eventNote.ID = stepBro;

		var eventText:FlxText = new FlxText(-GRID_SIZE*4, GRID_SIZE * ((gridY/GRID_SIZE) % 16), '');

		if(value != null) {
			if(value2 != null)
				eventText.text = 'Name: ${name}\n'+'Event Type: ${skill}\n'+'Event Value 1: ${value}\n'+'Event Value 2: ${value2}\n'+'Event Class: ${eventCatalog.get(skill)}';
			else
				eventText.text = 'Name: ${name}\n'+'Event Type: ${skill}\n'+'Event Value: ${value}\n'+'Event Class: ${eventCatalog.get(skill)}';
		}else {
			eventText.text = 'Name: ${name}\n'+'Event Type: ${skill}\n'+'Event Class: ${eventCatalog.get(skill)}';
		}

		eventText.alpha = 0;
		eventText.ID = stepBro;

		curPhysicalEvents.add(eventNote);
		eventDisplay.add(eventText);

		FlxTween.tween(eventNote, {alpha: 1, angle: 360}, Conductor.instance.stepLengthMs / 200, {ease: FlxEase.quadOut});
		FlxTween.tween(eventText, {alpha: 1, x: -GRID_SIZE*4.5}, Conductor.instance.stepLengthMs / 200, {ease: FlxEase.quadOut});
	}

	var removeDelay:Bool = false;

	function removePhysicalEvent(stepSis:Int):Void {

		if(!removeDelay) {
			removeDelay = true;

			//This is the problem (Not anymore)
			for(i in _song.modifiers)
				if(Reflect.field(i, "modGridY") == GRID_SIZE*stepSis)
					_song.modifiers.remove(i);
				else
					removeDelay = false;

			curPhysicalEvents.forEachAlive(function(eventSpr:FlxSprite) {
				trace(eventSpr.y*(curSection+1) + " " + GRID_SIZE*stepSis);

				if(eventSpr.ID == stepSis) {
					FlxTween.tween(eventSpr, {alpha: 0, angle: 0}, Conductor.instance.stepLengthMs / 300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
						eventSpr.kill();
						curPhysicalEvents.remove(eventSpr, true);
						eventSpr.destroy();
					}});
				}
			});

			eventDisplay.forEachAlive(function(eventTxt:FlxText) {
				if(eventTxt.ID == stepSis) {
					FlxTween.tween(eventTxt, {alpha: 0}, Conductor.instance.stepLengthMs / 300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
						eventTxt.kill();
						eventDisplay.remove(eventTxt, true);
						eventTxt.destroy();

						removeDelay = false;
					}});
				}		
			});

			trace("EACH MODIFIER ALIVE: "+_song.modifiers);
		}	
	}

	function updateSectionUI():Void {
		var sec = _song.notes[curSection];

		stepperLength.pos = getSectionLength(curSection);
		check_mustHitSection.selected = sec.mustHitSection;
		check_changeBPM.selected = sec.changeBPM;
		stepperSectionBPM.pos = sec.bpm;

		updateHeads();
	}

	function updateHeads():Void
	{
		if (check_mustHitSection.selected)
		{
			applyIconCharacter(leftIcon, _song.player1, true);
			applyIconCharacter(rightIcon, _song.player2, false);
		}
		else
		{
			applyIconCharacter(leftIcon, _song.player2, false);
			applyIconCharacter(rightIcon, _song.player1, true);
		}

		positionChartIcons();
	}

	function updateNoteUI():Void
	{
		if (curSelectedNote != null) {
			stepperSusLength.pos = curSelectedNote[2];
			lastSusLengthStepperValue = stepperSusLength.pos;
			noteTagInput.text = curSelectedNote[4] != null ? Std.string(curSelectedNote[4]) : "";
			playAnimCheck.selected = curSelectedNote[5] != null ? curSelectedNote[5] : true;
		}
	}

	function updateGrid():Void
	{
		while(gridLayout.members.length > 0) {
			gridLayout.remove(gridLayout.members[0], true);
		}

		gridBG = FlxDestroyUtil.destroy(gridBG);
		gridBG = FlxGridOverlay.create(GRID_SIZE, GRID_SIZE, GRID_SIZE * mainGrid, Std.int(GRID_SIZE * getSectionLength(curSection) * (zoomList[zoomMeter]/100)));
		positionChartIcons();

		if(strumLine != null) {
			strumLine.makeGraphic(Std.int(GRID_SIZE * mainGrid), 4);
			strumLine.updateHitbox();
		}

		var totalHeight:Float = gridBG.height;

		if(UI_Modifiers != null)
			UI_Modifiers.left = UI_box.left + UI_box.width;

		while (curRenderedNotes.members.length > 0)
		{
			remove(curRenderedNotes.members[0].modifiedSymbol);
			curRenderedNotes.remove(curRenderedNotes.members[0], true);
		}

		while (curRenderedSustains.members.length > 0)
		{
			curRenderedSustains.remove(curRenderedSustains.members[0], true);
		}

		var sectionInfo:Array<Dynamic> = _song.notes[curSection].sectionNotes;

		if (_song.notes[curSection].changeBPM && _song.notes[curSection].bpm > 0)
		{
			Conductor.instance.forceBPM(_song.notes[curSection].bpm);
			FlxG.log.add('CHANGED BPM!');
		}
		else
		{
			// get last bpm
			var daBPM:Int = _song.bpm;
			for (i in 0...curSection)
				if (_song.notes[i].changeBPM)
					daBPM = _song.notes[i].bpm;
			Conductor.instance.forceBPM(daBPM);
		}

		/* // PORT BULLSHIT, INCASE THERE'S NO SUSTAIN DATA FOR A NOTE
			for (sec in 0..._song.notes.length)
			{
				for (notesse in 0..._song.notes[sec].sectionNotes.length)
				{
					if (_song.notes[sec].sectionNotes[notesse][2] == null)
					{
						trace('SUS NULL');
						_song.notes[sec].sectionNotes[notesse][2] = 0;
					}
				}
			}
		 */

		if(camFollow != null) {
			camFollow.x = usesExpandedGridLayout() ? 400 : 360;
		}

		gridLayout.remove(gridBG2);
		gridBG2 = FlxDestroyUtil.destroy(gridBG2);

		if(check_show_extra != null) {
			if(check_show_extra.selected) {
				createSecondGrid();
			}
		}

		if(gridBG2 != null) {
			totalHeight += gridBG2.height;
		}

		gridLayout.add(gridBG2);
		gridLayout.add(gridBG);
		gridLayout.add(dummyArrow);

		if(check_show_extra != null) {
			if(check_show_extra.selected) {
				var gridBlackLineH:FlxSprite = new FlxSprite(-1, gridBG2.height).makeGraphic(GRID_SIZE * mainGrid, 2, FlxColor.BLACK);
				gridLayout.add(gridBlackLineH);
			}
		}

		var gridBlackLineV:FlxSprite = new FlxSprite(gridBG.x + gridBG.width / 2, -1).makeGraphic(2, Std.int(totalHeight), FlxColor.BLACK);
		gridLayout.add(gridBlackLineV);
			
		setupNotes(sectionInfo, curSection, 0);

		if(curRenderedNotes.members[0] != null && shouldHideCompactFourKeyOverflow()) {
			for(i in 0...curRenderedNotes.length) {
				if(curRenderedNotes.members[i].x >= 320)
					curRenderedNotes.members[i].visible = false;
			}
		}

		if(curRenderedSustains.members[0] != null && shouldHideCompactFourKeyOverflow()) {
			for(i in 0...curRenderedSustains.length) {
				if(curRenderedSustains.members[i].x > 320)
					curRenderedSustains.members[i].visible = false;
			}
		}
	}

	function createSecondGrid():Void {
		if(sectionStartTime(curSection + 1) <= FlxG.sound.music.length) {
			gridBG2 = FlxGridOverlay.create(GRID_SIZE, GRID_SIZE, GRID_SIZE * mainGrid, Std.int(GRID_SIZE * getSectionLength(curSection) * (zoomList[zoomMeter]/100)));

			var sectionInfo:Array<Dynamic> = _song.notes[curSection + 1].sectionNotes;

			if(_song.notes[curSection + 1] != null)
				setupNotes(sectionInfo, curSection + 1, gridBG.height);
		}else {
			gridBG2 = new FlxSprite().makeGraphic(GRID_SIZE * mainGrid, Std.int(GRID_SIZE * getSectionLength(curSection) * (zoomList[zoomMeter]/100)), 0x333333);
			gridBG2.alpha = 0.4;
		}

		gridBG2.y = gridBG.height;
	}

	function modifyNote(curSel:Array<Dynamic>, ?otherSel:Array<Dynamic> = null):Void {
		if(otherSel != null || curSel == otherSel) {
			try {
				curSelectedNote[3] = otherSel[3];
				curSelectedNote[4] = otherSel[4];
				curSelectedNote[5] = otherSel[5];
			}catch(e:haxe.Exception) {
				Log.warn("oops! WE caught an unexpected error! Reselect the note your tying to modify.\nDon't worry these issues are being looked at as soon as possible! ;)");
			}
		}else {
			var daStrumTime = curSel[0];
			var daNoteInfo = curSel[1];
			var daSus:Float = curSel[2];
			var daNoteType = curSel[3];
			var daTag = curSel[4];
			var daAnimPlay = curSel[5];

			daNoteType = wtfIsNote;
			daSus = Math.max(0, stepperSusLength.pos);

			if(check_extra_stuff.selected) {
				daTag = noteTagInput.text;
				daAnimPlay = playAnimCheck.selected;
			}

			curSelectedNote[0] = daStrumTime;
			curSelectedNote[1] = daNoteInfo;
			curSelectedNote[2] = daSus;
			curSelectedNote[3] = daNoteType;
			curSelectedNote[4] = daTag;
			curSelectedNote[5] = daAnimPlay;
		}
	}

	function setupNotes(sectionInfo:Array<Dynamic>, section:Int, yOffset:Float):Void {
		for (i in sectionInfo)
		{
			var daStrumTime = i[0];
			var daNoteInfo = i[1];
			var daSus = i[2];
			var daNoteType = i[3];
			var daTag = i[4];
			var daAnimPlay = i[5];

			var note:Note = new Note(daStrumTime, daNoteInfo % getChartLaneCountPerSide(), null, false, daNoteType);
			note.sustainLength = daSus;
			note.setGraphicSize(GRID_SIZE, GRID_SIZE);
			note.updateHitbox();
			note.x = Math.floor(getDisplayColumnFromStoredData(daNoteInfo) * GRID_SIZE);
			note.y = getYfromNotes((daStrumTime - sectionStartTime(section))) + yOffset;
			
			if(daTag != null) {
				if(StringTools.trim(daTag) != "") {
					note.tag = daTag;
				}
			}

			if(StringTools.trim(note.tag) != "") {
				note.placeModifierSymbol("T");
			}

			if(!daAnimPlay && i[5] != null) {
				note.placeModifierSymbol("A");
			}

			add(note.modifiedSymbol);

			note.refresh(_song.fifthKey);

			if (curSelectedNote != null) {
				if (curSelectedNote[0] == note.strumTime && curSelectedNote[1] == daNoteInfo) {
					lastNote = note;
					lastNote.shader = selectingShader;
					lastNote.color = FlxColor.fromRGBFloat(0.8, 0.8, 0.8);
				}
			}	

			curRenderedNotes.add(note);

			if (daSus > 0) {
				curRenderedSustains.add(makeSusNote(note, daSus, section));
			}
		}

		if(curRenderedNotes.members[0] != null && shouldHideCompactFourKeyOverflow()) {
			for(i in 0...curRenderedNotes.length) {
				if(curRenderedNotes.members[i].x >= 320)
					curRenderedNotes.members[i].visible = false;
			}
		}
		if(curRenderedSustains.members[0] != null && shouldHideCompactFourKeyOverflow()) {
			for(i in 0...curRenderedSustains.length) {
				if(curRenderedSustains.members[i].x > 320)
					curRenderedSustains.members[i].visible = false;
			}
		}
	}

	function makeSusNote(note:Note, susValue:Float, section:Int):FlxSprite {
		var height:Int = Math.floor(FlxMath.remapToRange(susValue, 0, Conductor.instance.stepLengthMs * 16, 0, GRID_SIZE * 16 * (zoomList[zoomMeter]/100)));

		height = Std.int(Math.max(1, height));
		var sustainVis:FlxSprite = new FlxSprite(0, note.y + GRID_SIZE).makeGraphic(8, height);
		sustainVis.x = note.x + (GRID_SIZE / 2) - (sustainVis.width / 2);
		return sustainVis;
	}

	private function addSection(lengthInSteps:Int = 16):Void
	{
		var sec:SwagSection = {
			lengthInSteps: lengthInSteps,
			bpm: _song.bpm,
			changeBPM: false,
			mustHitSection: true,
			sectionNotes: [],
			altAnim: false,
		};

		_song.notes.push(sec);
	}

	/**
	* If chart from Psych Engine.
	*/
	function getSectionLength(section:Int) {
		var value:Float = 16;
		
		if(_song.notes[section] != null) {
			if(_song.notes[section].lengthInSteps > 0) {
				value = _song.notes[section].lengthInSteps;
			}
		}

		return value;
	}

	function selectNote(note:Note):Void
	{
		var storedNoteData:Int = getStoredDataFromNoteX(note.x);

		for (i in _song.notes[curSection].sectionNotes)
		{
			if (i[0] == note.strumTime && i[1] == storedNoteData)
			{
				prevSelectedNote = curSelectedNote;
				curSelectedNote = i;

				curSelectedNote[3] = note.noteAbstract;
				curSelectedNote[4] = note.tag;
				curSelectedNote[5] = note.playAnyAnimation;

				wtfIsNote = curSelectedNote[3];
			}
		}

		updateGrid();
		updateNoteUI();
	}


	function removeNoteSec(note:Note, section:Int):Void {
		var storedNoteData:Int = getStoredDataFromNoteX(note.x);

		for (i in _song.notes[section].sectionNotes) {
			if (i[0] == note.strumTime && i[1] == storedNoteData) {
				if(i == curSelectedNote) {
					curSelectedNote = null;
				}

				if(i == prevSelectedNote) {
					prevSelectedNote = null;
				}

				_song.notes[section].sectionNotes.remove(i);
				break;
			}
		}
	}


	function deleteNote(note:Note):Void
	{
		lastNote = note;
		removeNoteSec(note, curSection);

		if(check_show_extra != null) {
			if(check_show_extra.selected && _song.notes[curSection + 1] != null) {
				removeNoteSec(note, curSection + 1);
			}
		}
	
		updateGrid();
	}

	function clearSection():Void
	{
		_song.notes[curSection].sectionNotes = [];

		updateGrid();
	}

	function clearSong():Void
	{
		for (daSection in 0..._song.notes.length)
		{
			_song.notes[daSection].sectionNotes = [];
		}

		updateGrid();
	}

	private function addNote(?n:Note):Void
	{
		final extraSection:Int = Math.floor(dummyArrow.y / (gridBG.y + gridBG.height));

		var noteStrum = getStrumTime(dummyArrow.y % (gridBG.y + gridBG.height)) + sectionStartTime(curSection + extraSection);
		var noteData = getStoredDataFromDisplayColumn(getDisplayColumnFromMouseX(FlxG.mouse.x));
		var noteTag:String = null;
		var playAnyAnim:Bool = true;
		var noteSus = 0;

		if (n == null && noteData < 0) {
			return;
		}
			
		if(check_extra_stuff.selected) {
			noteTag = noteTagInput.text;
			playAnyAnim = playAnimCheck.selected;
		}

		if (n != null) {
			n.noteAbstract = wtfIsNote;
			_song.notes[curSection + extraSection].sectionNotes.push([n.strumTime, n.noteData + (n.mustPress ? getChartLaneCountPerSide() : 0), n.sustainLength, n.noteAbstract, n.tag, n.playAnyAnimation]);
		}else {
			_song.notes[curSection + extraSection].sectionNotes.push([noteStrum, noteData, noteSus, wtfIsNote, noteTag, playAnyAnim]);
		}

		curSelectedNote = _song.notes[curSection + extraSection].sectionNotes[_song.notes[curSection + extraSection].sectionNotes.length - 1];

		updateGrid();
		updateNoteUI();

		autosaveSong();
	}

	function getStrumTime(yPos:Float):Float
	{
		return FlxMath.remapToRange(yPos, gridBG.y, gridBG.y + gridBG.height * totalGrids, 0, 16 * Conductor.instance.stepLengthMs * totalGrids);
	}

	function getYfromStrum(strumTime:Float):Float
	{
		return FlxMath.remapToRange(strumTime, 0, 16 * Conductor.instance.stepLengthMs * totalGrids, gridBG.y, gridBG.y + gridBG.height * (zoomList[zoomMeter]/100) * totalGrids);
	}

	function getYfromNotes(strumTime:Float):Float { //long
		return GRID_SIZE * 16 * (zoomList[zoomMeter]/100) * (strumTime / (16 * Conductor.instance.stepLengthMs)) + gridBG.y;
	}

	private var daSpacing:Float = 0.3;

	function loadLevel():Void
	{
		trace(_song.notes);
	}

	function getNotes():Array<Dynamic>
	{
		var noteData:Array<Dynamic> = [];

		for (i in _song.notes)
		{
			noteData.push(i.sectionNotes);
		}

		return noteData;
	}

	function loadJson(song:String):Void
	{
		PlayState.SONG = Song.loadFromJson(song.toLowerCase(), song.toLowerCase());
		FlxG.resetState();
	}

	function loadAutosave():Void
	{
		PlayState.SONG = Song.parseJSONshit(FlxG.save.data.autosave);
		FlxG.resetState();
	}

	function autosaveSong():Void
	{
		FlxG.save.data.autosave = Json.stringify({
			"song": _song
		});
		FlxG.save.flush();
	}

	override function destroy():Void
	{
		if(UI_box != null) {
			Screen.instance.removeComponent(UI_box, false);
			UI_box = null;
		}
		if(UI_Modifiers != null) {
			Screen.instance.removeComponent(UI_Modifiers, false);
			UI_Modifiers = null;
		}

		destroyVocals();
		Cache.clearSongSoundCache();
		super.destroy();
	}

	private function saveLevel()
	{
		var json = {
			"song": _song
		};

		var data:String = Json.stringify(json, "\t");

		if ((data != null) && (data.length > 0))
		{
			_file = new FileReference();
			_file.addEventListener(Event.COMPLETE, onSaveComplete);
			_file.addEventListener(Event.CANCEL, onCancel);
			_file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
			_file.save(data.trim(), _song.song.toLowerCase() + ".json");
		}
	}

	function onSelect(event:Event):Void {
        _file = cast(event.target, FileReference);
        _file.addEventListener(Event.COMPLETE, onComplete);
        _file.load();
    }

	function onSaveComplete(_):Void {
		clearEvent();
		FlxG.log.notice("Successfully saved LEVEL DATA.");
	}

	function onComplete(event:Event):Void {
		_file = cast(event.target, FileReference);
        _file.removeEventListener(Event.COMPLETE, onComplete);

		unableLabel.text = "";

		var foundFile:Bool = false;

		for(i in 0...fileType.length) {
			if(_file.type == fileType[i]) {
				foundFile = true;
			}
		}

		fileType = [];

		if(!foundFile) {
			unableLabel.text = "Unable to compile video file: " + _file.name;
			return;
		}

		if(Paths.video(_file.name) == null) {
			unableLabel.text = "Unable to compile video file: " + _file.name;
			return;
		}

		_song.video = Paths.video(_file.name);

		if(_song.video != null && watchButton != null) {
			watchButton.hidden = false;
		}
	}

	/**
	 * Called when the save file dialog is cancelled.
	 */
	function onCancel(_):Void {
		clearEvent();
	}

	function onSaveError(_):Void {
		clearEvent();
		FlxG.log.error("Problem saving Level data");
	}

	function clearEvent():Void {
        _file.removeEventListener(Event.COMPLETE, onSaveComplete);
        _file.removeEventListener(Event.CANCEL, onCancel);
        _file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
        _file.removeEventListener(Event.SELECT, onSelect);
        _file = null;
    }
}
