package;

import flixel.addons.ui.FlxUIText;
import haxe.zip.Writer;
import Conductor.BPMChangeEvent;
import Section.SwagSection;
import Song.SwagSong;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.addons.display.FlxGridOverlay;
import flixel.addons.ui.FlxInputText;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUITabMenu;
import flixel.addons.ui.FlxUITooltip.FlxUITooltipStyle;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.group.FlxGroup;
import flixel.math.FlxMath;
import flixel.math.FlxPoint;
import flixel.system.FlxSound;
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

	var UI_box:FlxUITabMenu;
	var UI_Modifiers:FlxUITabMenu;

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
	var writingNotesText:FlxText;
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

	var typingShit:FlxInputText;
	/*
	 * WILL BE THE CURRENT / LAST PLACED NOTE
	**/
	var curSelectedNote:Array<Dynamic>;
	var prevSelectedNote:Array<Dynamic>;

	var tempBpm:Int = 0;
	var vocals:FlxSound;

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
			['note woggle', "Notes sway back and forth.\n\nValue - Wobble intensity. (30 recommended)"],
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
			['clear events', "Value 1 - Event's name.\nValue 2 - Second event's name. (optional)"],
			['clear all', "Value 1 - nothing.\nValue 2 - nothing."]
		]
	];

	private var eventCatalog:Map<String, String> = [
		'mirror chart' => "Modifiers",
		'sing drain' => "Modifiers",
		'blind effect' => "Modifiers",
		'fadein notes' => "Modifiers",
		'note woggle' => "Modifiers",
		'camera move' => "Modifiers",
		'alt animation' => "Regular",
		'jumpspeed' => "Regular",
		'sicko shake' => "Regular",
		'time freeze' => "Regular",
		'strum bounce' => "Regular",
		'note rewind' => "Regular",
		'character change' => "Regular",
		'clear events' => "Regular",
		'clear all' => "Regular"
	];

	private var selectingShader:BuiltInShaders;

	var zoomText:FlxText;

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

		bpmTxt = new FlxText(1000, 50, 0, "", 16);

		if(_song.fifthKey) {
			bpmTxt.x = 1050;
			mainGrid = 10;
		}

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

		if(_song.fifthKey) {
			leftIcon.setPosition(30, -100);
			rightIcon.setPosition((gridBG.width / 2) + 30, -100);
		}else {
			leftIcon.setPosition(0, -100);
			rightIcon.setPosition(gridBG.width / 2, -100);
		}

		curRenderedNotes = new FlxTypedGroup<Note>();
		curRenderedSustains = new FlxTypedGroup<FlxSprite>();

		FlxG.mouse.visible = true;
		FlxG.save.bind('funkin', 'ninjamuffin99');

		tempBpm = _song.bpm;

		addSection();

		// sections = _song.notes;

		updateGrid();

		updateEvents();


		loadSong(_song.song);
		Conductor.changeBPM(_song.bpm);
		Conductor.mapBPMChanges(_song);

		bpmTxt.scrollFactor.set();
		add(bpmTxt);

		strumLine = new FlxSprite(0, 50).makeGraphic(Std.int(GRID_SIZE * mainGrid), 4);
		add(strumLine);

		var tabs = [
			{name: "Song", label: 'Song'},
			{name: "Section", label: 'Section'},
			{name: "Video", label: 'Video'},
			{name: "Note", label: 'Note'},
			{name: "SF Map", label: 'Map'}
		];

		var mod_tabs;

		if(Main.feeshmoraModifiers) {
			mod_tabs = [
				{name: "Modifiers", label: 'Modifiers'},
				{name: "F Regular", label: "Regular"},
				{name: "OZ Yours", label: 'Yours'},
				{name: "Settings", label: "Settings"}
			];
		}else {
			mod_tabs = [
				{name: "F Regular", label: "Regular"},
				{name: "OZ Yours", label: 'Yours'},
				{name: "Settings", label: "Settings"}
			];
		}	

		UI_box = new FlxUITabMenu(null, tabs, true);
		UI_Modifiers = new FlxUITabMenu(null, mod_tabs, true);

		UI_box.resize(325, 450);
		UI_Modifiers.resize(275, 250);

		if(_song.fifthKey)
			UI_box.x = FlxG.width / 2 + GRID_SIZE;
		else
			UI_box.x = FlxG.width / 2;

		selectingShader = new BuiltInShaders();
		selectingShader.shader = ShaderType.GLIM_SELECTION;

		instrucTxt = new FlxText(UI_box.x, UI_box.y + UI_box.height + GRID_SIZE, FlxG.width,
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

		UI_box.y = 20;
		add(UI_box);

		if(_song.fifthKey)
			UI_Modifiers.x = FlxG.width / 2 + GRID_SIZE + UI_box.width;
		else
			UI_Modifiers.x = FlxG.width / 2 + UI_box.width;

		UI_Modifiers.y = UI_box.height - UI_Modifiers.height + 20;

		add(UI_Modifiers);

		super.create();

		addSongUI();
		addSectionUI();
		addNoteUI();
		addWorldMapUI();
		addVideoUI();

		//Options
		addModifierUI();
		addRegularEventUI();
		addYourEventUI();
		addSettingsEventUI();

		add(curRenderedSustains);
		add(curRenderedNotes);

		updateHeads();
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

	var stepperSpeed:FlxUINumericStepper;
	var speedLabel:FlxText;

	var unableLabel:FlxText;
	var watchButton:FlxButton;
	var tab_group_video:FlxUI;

	function addVideoUI():Void {
		tab_group_video = new FlxUI(null, UI_box);
		tab_group_video.name = "Video";

		var videoInstructions:FlxText = new FlxText(10, 10, "The video you selected must be located in the video folder.");

		var getVideo:FlxButton = new FlxButton(10, videoInstructions.y + 20, "Get Video", function() {
			_file = new FileReference();
			_file.addEventListener(Event.SELECT, onSelect);
			_file.addEventListener(Event.CANCEL, onCancel);

			fileType = [".mp4", ".mov", ".webm"];

			_file.browse();
		});

		watchButton = new FlxButton(getVideo.width + getVideo.x + 10, videoInstructions.y + 20, "Watch", function() {
			if(_song.video != null) {
				FlxG.switchState(new VideoState(new ChartingState(), _song.video));
			}
		});
		watchButton.color = FlxColor.RED;
		watchButton.label.color = FlxColor.WHITE;

		if(_song.video != null) {
			tab_group_video.add(watchButton);
		}

		unableLabel = new FlxText(10, 50, "");
		unableLabel.color = FlxColor.RED;

		tab_group_video.add(videoInstructions);
		tab_group_video.add(getVideo);
		tab_group_video.add(unableLabel);

		UI_box.addGroup(tab_group_video);
		UI_box.scrollFactor.set();
	}

	function addModifierUI():Void {
		var makeModName = new FlxUIInputText(185, 20, 80, "Modifier Pog", 8);

		var modLabel = new FlxText(115, 20, 'Event Name:');
		var howToTutorial:FlxText = new FlxText(5, 100, '');

		var makeModifierValue:FlxUIInputText = new FlxUIInputText(150, 85, 80, "", 8);
		var modifierValueLabel:FlxText = new FlxText(105, 85, 'Value:');

		var createEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 75, "Create Event", function() {
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
				case "note woggle":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(Math.abs(Std.parseInt(makeModifierValue.text)));
					else
						createEvent.modValue = "30";
				case "camera move":
					if(Std.parseInt(makeModifierValue.text) != null)
						createEvent.modValue = Std.string(Math.abs(Std.parseFloat(makeModifierValue.text)));
					else
						createEvent.modValue = "1";
			}

			_song.modifiers.push(createEvent);

			createPhysicalEvent(_song.modifiers.length-1, curStep, createEvent.modValue, null);
		});

		var removeEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 50, "Remove Event", function() {
			if(curStep < 0 || curStep < curSection*16)
				return;

			removePhysicalEvent(curStep);
		});

		var eventList:Array<String> = [];

		for (i in 0...simpleList.get("Modifiers").length)
			eventList.push(simpleList.get("Modifiers")[i][0]);

		howToTutorial.text = simpleList.get("Modifiers")[0][1];

		var modList:FlxUIDropDownMenu = new FlxUIDropDownMenu(150, 50, FlxUIDropDownMenu.makeStrIdLabelArray(eventList, true), function(choose:String) {
			wtfIsEvent = eventList[Std.parseInt(choose)];
			makeModifierValue.text = "";
			howToTutorial.text = simpleList.get("Modifiers")[Std.parseInt(choose)][1];
		});

		var tab_group_modifiers = new FlxUI(null, UI_Modifiers);
		tab_group_modifiers.name = "Modifiers";
		tab_group_modifiers.add(makeModName);
		tab_group_modifiers.add(modLabel);
		tab_group_modifiers.add(createEventButton);
		tab_group_modifiers.add(removeEventButton);
		tab_group_modifiers.add(makeModifierValue);
		tab_group_modifiers.add(modifierValueLabel);
		tab_group_modifiers.add(howToTutorial);
		tab_group_modifiers.add(modList);

		UI_Modifiers.addGroup(tab_group_modifiers);
		UI_Modifiers.scrollFactor.set();
	}

	function addYourEventUI():Void {
		var makeYoursName:FlxUIInputText = new FlxUIInputText(185, 20, 80, "Yours Pog", 8);

		var yoursLabel:FlxText = new FlxText(115, 20, 'Event Name:');

		var makeYourValue:FlxUIInputText = new FlxUIInputText(150, 85, 80, "", 8);
		var makeYourTwoValue:FlxUIInputText = new FlxUIInputText(150, 105, 80, "", 8);

		var yourValueLabel:FlxText = new FlxText(100, 85, 'Value 1:');
		var yourTwoValueLabel:FlxText = new FlxText(100, 105, 'Value 2:');

		var howToTutorial:FlxText = new FlxText(5, 125, '');

		var createEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 75, "Create Event", function() {
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
		});

		var removeEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 50, "Remove Event", function() {
			if(curStep < 0 || curStep < curSection*16)
				return;

			if(!removeDelay)
				removePhysicalEvent(curStep);
		});

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

		var yourList:FlxUIDropDownMenu = new FlxUIDropDownMenu(150, 50, FlxUIDropDownMenu.makeStrIdLabelArray(eventList, true), function(choose:String) {
			if(eventList[Std.parseInt(choose)].trim() != "") {
				wtfIsEvent = eventList[Std.parseInt(choose)];

				makeYourValue.text = "";
				makeYourTwoValue.text = "";
				howToTutorial.text = simpleList.get("Yours")[Std.parseInt(choose)][1];
			}
		});

		var tab_group_yourEvent:FlxUI = new FlxUI(null, UI_Modifiers);
		tab_group_yourEvent.name = "OZ Yours";
		tab_group_yourEvent.add(makeYoursName);
		tab_group_yourEvent.add(createEventButton);
		tab_group_yourEvent.add(removeEventButton);
		tab_group_yourEvent.add(yoursLabel);
		tab_group_yourEvent.add(makeYourValue);
		tab_group_yourEvent.add(makeYourTwoValue);
		tab_group_yourEvent.add(yourValueLabel);
		tab_group_yourEvent.add(yourTwoValueLabel);
		tab_group_yourEvent.add(howToTutorial);
		tab_group_yourEvent.add(yourList);
		UI_Modifiers.addGroup(tab_group_yourEvent);
		UI_Modifiers.scrollFactor.set();
	}

	function addRegularEventUI():Void {
		var makeRegularName:FlxUIInputText = new FlxUIInputText(185, 20, 80, "Regular Pog", 8);

		var RegularLabel:FlxText = new FlxText(115, 20, 'Event Name:');

		var makeRegularValue:FlxUIInputText = new FlxUIInputText(150, 85, 80, "", 8);
		var makeRegularTwoValue:FlxUIInputText = new FlxUIInputText(150, 105, 80, "", 8);

		var RegularValueLabel:FlxText = new FlxText(100, 85, 'Value 1:');
		var RegularTwoValueLabel:FlxText = new FlxText(100, 105, 'Value 2:');

		var howToTutorial:FlxText = new FlxText(5, 125, '');

		var createEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 75, "Create Event", function() {
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
					createEvent.modValueTwo = RegularTwoValueLabel.text.toLowerCase();
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
					createEvent.modValueTwo = RegularTwoValueLabel.text.toLowerCase();
				case "clear all":
					createEvent.modValue = null;
					createEvent.modValueTwo = null;
			}

			_song.modifiers.push(createEvent);

			createPhysicalEvent(_song.modifiers.length-1, curStep, createEvent.modValue, createEvent.modValueTwo);
		});

		var removeEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 50, "Remove Event", function() {
			if(curStep < 0 || curStep < curSection*16)
				return;

			if(!removeDelay)
				removePhysicalEvent(curStep);
		});

		var eventList:Array<String> = [];

		for (i in 0...simpleList.get("Regular").length)
			eventList.push(simpleList.get("Regular")[i][0]);

		howToTutorial.text = simpleList.get("Regular")[0][1];

		var RegularList:FlxUIDropDownMenu = new FlxUIDropDownMenu(150, 50, FlxUIDropDownMenu.makeStrIdLabelArray(eventList, true), function(choose:String) {
			wtfIsEvent = eventList[Std.parseInt(choose)];

			makeRegularValue.text = "";
			makeRegularTwoValue.text = "";
			howToTutorial.text = simpleList.get("Regular")[Std.parseInt(choose)][1];
		});

		var tab_group_RegularEvent:FlxUI = new FlxUI(null, UI_Modifiers);
		tab_group_RegularEvent.name = "F Regular";
		tab_group_RegularEvent.add(makeRegularName);
		tab_group_RegularEvent.add(createEventButton);
		tab_group_RegularEvent.add(removeEventButton);
		tab_group_RegularEvent.add(makeRegularValue);
		tab_group_RegularEvent.add(makeRegularTwoValue);
		tab_group_RegularEvent.add(RegularLabel);
		tab_group_RegularEvent.add(RegularValueLabel);
		tab_group_RegularEvent.add(RegularTwoValueLabel);
		tab_group_RegularEvent.add(howToTutorial);
		tab_group_RegularEvent.add(RegularList);

		UI_Modifiers.addGroup(tab_group_RegularEvent);
		UI_Modifiers.scrollFactor.set();
	}

	function addSettingsEventUI():Void {
		var stepperCopy:FlxUINumericStepper = new FlxUINumericStepper(110, 15, 1, 1, -999, 999, 0);

		var copyButton:FlxButton = new FlxButton(5, 10, "Copy Last", function() {
			copyEvent(-Std.int(stepperCopy.value));		
		});

		var clearSectionButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 75, "Clear Section", function() {
			clearEvents(false);
		});

		var clearAllButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 50, "Clear All", function() {
			clearEvents(true);
		});

		var tab_group_setting:FlxUI = new FlxUI(null, UI_Modifiers);
		tab_group_setting.name = "Settings";
		tab_group_setting.add(copyButton);
		tab_group_setting.add(stepperCopy);
		tab_group_setting.add(clearSectionButton);
		tab_group_setting.add(clearAllButton);

		UI_Modifiers.addGroup(tab_group_setting);
		UI_Modifiers.scrollFactor.set();
	}

	var check_mute_inst:FlxUICheckBox;

	var playOSU_Sound_RIGHT:Bool;
	var playOSU_Sound_LEFT:Bool;

	var metronome:Bool;

	function addSongUI():Void
	{
		var UI_songTitle = new FlxUIInputText(10, 10, 70, _song.song, 8);
		typingShit = UI_songTitle;

		var check_voices:FlxUICheckBox = new FlxUICheckBox(10, 25+UI_songTitle.y, null, null, "Voice Track", 100);
		check_voices.checked = _song.needsVoices;
		// _song.needsVoices = check_voices.checked;
		check_voices.callback = function()
		{
			_song.needsVoices = check_voices.checked;
			trace('CHECKED!');
		};

		check_mute_inst = new FlxUICheckBox(10, 145, null, null, "Mute Instrumental (in editor)", 100);
		check_mute_inst.checked = false;
		check_mute_inst.callback = function()
		{
			var vol:Float = 1;

			if (check_mute_inst.checked)
				vol = 0;

			FlxG.sound.music.volume = vol;
		};

		var check_fifth:FlxUICheckBox = new FlxUICheckBox(10, 145-(check_mute_inst.height*2), null, null, "5 keys", 50);
		check_fifth.checked = _song.fifthKey;
		check_fifth.callback = function()
		{
			_song.fifthKey = check_fifth.checked;

			if(check_fifth.checked) {
				UI_box.x = FlxG.width / 2 + GRID_SIZE;
				bpmTxt.x = 1050;
				mainGrid = 10;

				leftIcon.setPosition(30, -100);
				rightIcon.setPosition((gridBG.width / 2) + (rightIcon.width/2.1), -100);
			}else {
				UI_box.x = FlxG.width / 2;
				bpmTxt.x = 1000;
				mainGrid = 8;

				leftIcon.setPosition(0, -100);
				rightIcon.setPosition((gridBG.width / 2) - 30, -100);	
			}

			updateGrid();
		};

		var mod_check:FlxUICheckBox = new FlxUICheckBox(75, 145-(check_mute_inst.height*2), null, null, "Modify FPS", 70);
		mod_check.checked = false;
		mod_check.callback = function() {
			_song.modifyFPS = mod_check.checked;
		}

		var metronome_check:FlxUICheckBox = new FlxUICheckBox(80 + mod_check.width, mod_check.y, null, null, "Metronome", 70);
		metronome_check.checked = false;
		metronome_check.callback = function() {
			metronome = metronome_check.checked;
		}

		var check_mute_inst_game:FlxUICheckBox = new FlxUICheckBox(10, 145+(check_mute_inst.height*1.5), null, null, "Mute Instrumental (in game)", 100);
		check_mute_inst_game.checked = PlayState.muteInst;
		check_mute_inst_game.callback = function()
		{
			muteInGame = check_mute_inst_game.checked;
		};

		var check_hit_right:FlxUICheckBox = new FlxUICheckBox(check_mute_inst_game.x + check_mute_inst_game.width + 10, 145, null, null, "OSU Hit Sounds (Right)", 100);
		check_hit_right.checked = false;
		check_hit_right.callback = function() {
			playOSU_Sound_RIGHT = check_hit_right.checked;
		}

		var check_hit_left:FlxUICheckBox = new FlxUICheckBox(check_mute_inst_game.x + check_mute_inst_game.width + 10, check_mute_inst_game.y, null, null, "OSU Hit Sounds (Left)", 100);
		check_hit_left.checked = false;
		check_hit_left.callback = function() {
			playOSU_Sound_LEFT = check_hit_left.checked;
		}

		var saveButton:FlxButton = new FlxButton(110, 8, "Save", function()
		{
			saveLevel();
		});

		var reloadSong:FlxButton = new FlxButton(saveButton.x + saveButton.width + 10, saveButton.y, "Reload Audio", function()
		{
			loadSong(_song.song);
		});

		var reloadSongJson:FlxButton = new FlxButton(reloadSong.x, saveButton.y + 30, "Reload JSON", function()
		{
			loadJson(_song.song.toLowerCase());
		});

		
		var restart = new FlxButton(110, saveButton.y + 30, "Reset", function()
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
    	});

		var loadAutosaveBtn:FlxButton = new FlxButton(reloadSongJson.x, reloadSongJson.y + 30, 'load autosave', loadAutosave);

		stepperSpeed = new FlxUINumericStepper(10, 80, 0.1, 1, 0.1, 10, 1);
		stepperSpeed.value = _song.speed;
		stepperSpeed.name = 'song_speed';

		speedLabel = new FlxText(stepperSpeed.x + 65,stepperSpeed.y,'Scroll Speed');

		var stepperBPM:FlxUINumericStepper = new FlxUINumericStepper(10, 65, 1, 1, 1.0, 5000.0, 0);
		stepperBPM.value = Conductor.bpm;
		stepperBPM.name = 'song_bpm';

		var bpmLabel:FlxText = new FlxText(stepperBPM.x + 65, stepperBPM.y, "BPM");

		var stepperFps:FlxUINumericStepper = new FlxUINumericStepper(10, 95, 1, songFPS, 60, 600, 0);
		stepperFps.value = songFPS;
		stepperFps.name = 'song_framerate';

		var fpsLabel = new FlxText(stepperFps.x + 65, stepperFps.y, "FPS");

		var player1DropDown = new FlxUIDropDownMenu(140, 215, FlxUIDropDownMenu.makeStrIdLabelArray(DefaultHandler.getcharacterJSON(), true), function(character:String)
		{
			_song.player1 = DefaultHandler.getcharacterJSON()[Std.parseInt(character)];
			updateHeads();
		});
		player1DropDown.selectedLabel = _song.player1;

		var player2DropDown = new FlxUIDropDownMenu(10, 215, FlxUIDropDownMenu.makeStrIdLabelArray(DefaultHandler.getcharacterJSON(), true), function(character:String)
		{
			_song.player2 = DefaultHandler.getcharacterJSON()[Std.parseInt(character)];
			updateHeads();
		});
		player2DropDown.selectedLabel = _song.player2;

		var player1Txt:FlxText = new FlxText(player1DropDown.x, player1DropDown.y - 15, "Player");
		var player2Txt:FlxText = new FlxText(player2DropDown.x, player2DropDown.y - 15, "Opponent");

		var tab_group_song = new FlxUI(null, UI_box);
		tab_group_song.name = "Song";
		tab_group_song.add(UI_songTitle);
		tab_group_song.add(restart);
		tab_group_song.add(check_voices);
		tab_group_song.add(check_mute_inst);
		tab_group_song.add(check_mute_inst_game);
		tab_group_song.add(check_hit_right);
		tab_group_song.add(check_hit_left);
		tab_group_song.add(metronome_check);
		tab_group_song.add(check_fifth);
		tab_group_song.add(mod_check);
		tab_group_song.add(saveButton);
		tab_group_song.add(reloadSong);
		tab_group_song.add(reloadSongJson);
		tab_group_song.add(loadAutosaveBtn);
		tab_group_song.add(stepperBPM);
		tab_group_song.add(bpmLabel);
		tab_group_song.add(stepperSpeed);
		tab_group_song.add(speedLabel);
		tab_group_song.add(stepperFps);
		tab_group_song.add(fpsLabel);
		tab_group_song.add(player1DropDown);
		tab_group_song.add(player2DropDown);
		tab_group_song.add(player1Txt);
		tab_group_song.add(player2Txt);

		UI_box.addGroup(tab_group_song);
		UI_box.scrollFactor.set();

		camFollow = new FlxObject(360, 0, 1, 1);
		add(camFollow);

		FlxG.camera.follow(camFollow);
	}

	var stepperLength:FlxUINumericStepper;
	var check_mustHitSection:FlxUICheckBox;
	var check_changeBPM:FlxUICheckBox;
	var check_show_extra:FlxUICheckBox;
	var stepperSectionBPM:FlxUINumericStepper;

	function addSectionUI():Void
	{
		var tab_group_section = new FlxUI(null, UI_box);
		tab_group_section.name = 'Section';

		stepperLength = new FlxUINumericStepper(10, 10, 4, 0, 0, 999, 0);
		stepperLength.value = getSectionLength(curSection);
		stepperLength.name = "section_length";

		stepperSectionBPM = new FlxUINumericStepper(10, 80, 1, Conductor.bpm, 0, 999, 0);
		stepperSectionBPM.value = Conductor.bpm;
		stepperSectionBPM.name = 'section_bpm';

		var stepperCopy:FlxUINumericStepper = new FlxUINumericStepper(110, 130, 1, 1, -999, 999, 0);

		var copyButton:FlxButton = new FlxButton(10, 130, "Copy Last", function()
		{
			copySection(Std.int(stepperCopy.value));
		});

		var clearSectionButton:FlxButton = new FlxButton(10, 150, "Clear", clearSection);

		var swapSection:FlxButton = new FlxButton(10, 170, "Copy Swap", function()
		{
			swapCopy(Std.int(stepperCopy.value));
		});

		check_mustHitSection = new FlxUICheckBox(10, 30, null, null, "Must Hit Section", 80);
		check_mustHitSection.name = 'check_mustHit';
		check_mustHitSection.checked = true;
		// _song.needsVoices = check_mustHit.checked;

		check_changeBPM = new FlxUICheckBox(10, 60, null, null, 'Change BPM', 80);
		check_changeBPM.name = 'check_changeBPM';

		check_show_extra = new FlxUICheckBox(check_mustHitSection.width + 15, 60, null, null, 'Show Extra Section', 70);
		check_show_extra.name = 'check_extra_section';

		check_show_extra.callback = function() {
			updateGrid();
		}

		tab_group_section.add(stepperLength);
		tab_group_section.add(stepperSectionBPM);
		tab_group_section.add(stepperCopy);
		tab_group_section.add(check_mustHitSection);
		tab_group_section.add(check_changeBPM);
		tab_group_section.add(check_show_extra);
		tab_group_section.add(copyButton);
		tab_group_section.add(clearSectionButton);
		tab_group_section.add(swapSection);

		UI_box.addGroup(tab_group_section);
	}

	var stepperSusLength:FlxUINumericStepper;
	var noteTypeEffect:FlxUIDropDownMenu;
	var noteAddonEffect:FlxUIDropDownMenu;

	var tab_group_note:FlxUI;

	var check_extra_stuff:FlxUICheckBox;
	var subDivideDummy:FlxUINumericStepper;
	var subLabel:FlxText;
	var noteTagInput:FlxUIInputText;
	var noteTagText:FlxText;
	var playAnimCheck:FlxUICheckBox;
	
	function addNoteUI():Void
	{
		final DaNotes:Array<String> = CoolUtil.coolTextFile(Paths.pak('mapHandler'));

		var noteAddons:Array<String> = new Array<String>();

		for(v in CustomNoteHandler.customNoteAddon.keys()) {
			if(!noteAddons.contains(v) && !DaNotes.contains(v))
				noteAddons.push(v);
		}

		tab_group_note = new FlxUI(null, UI_box);
		tab_group_note.name = 'Note';

		writingNotesText = new FlxUIText(20,100, 0, "");
		writingNotesText.setFormat("Arial",20,FlxColor.WHITE,FlxTextAlign.LEFT,FlxTextBorderStyle.OUTLINE,FlxColor.BLACK);

		stepperSusLength = new FlxUINumericStepper(10, 10, Conductor.stepCrochet / 2, 0, 0, Conductor.stepCrochet * getSectionLength(curSection) * 4);
		stepperSusLength.value = 0;
		stepperSusLength.name = 'note_susLength';

		var susLabel = new FlxText(stepperSusLength.x + 65,stepperSusLength.y,'SUS Note Length');

		check_extra_stuff = new FlxUICheckBox(10, 30 + stepperSusLength.y, null, null, "", 250);
		check_extra_stuff.checked = false;
		check_extra_stuff.callback = function()
		{
			subDivideDummy.visible = check_extra_stuff.checked;
			subLabel.visible = check_extra_stuff.checked;
			noteTagInput.visible = check_extra_stuff.checked;
			noteTagText.visible = check_extra_stuff.checked;
			playAnimCheck.visible = check_extra_stuff.checked;
		};

		var checkBoxLabel:FlxText = new FlxText(check_extra_stuff.x+20, check_extra_stuff.y-5, "Use Extra Note Features \n (This may Disable Regular Chart Features)");

		noteTypeEffect = new FlxUIDropDownMenu(10, 90 + check_extra_stuff.y, FlxUIDropDownMenu.makeStrIdLabelArray(DaNotes, true), function(chooseType:String) {
			wtfIsNote = DaNotes[Std.parseInt(chooseType)];
		});

		if(noteAddons[0] != null) {
			noteAddonEffect = new FlxUIDropDownMenu(UI_box.width - 130, 90 + check_extra_stuff.y, FlxUIDropDownMenu.makeStrIdLabelArray(noteAddons, true), function(chooseType:String) {
				wtfIsNote = noteAddons[Std.parseInt(chooseType)];
			});
		}	

		subDivideDummy = new FlxUINumericStepper(150, 42 + check_extra_stuff.y, 1, 1, 1, 4, 0);
		subDivideDummy.value = 1;
		subDivideDummy.name = 'dummy_divide';
		subDivideDummy.visible = false;

		subLabel = new FlxText(subDivideDummy.x + 65,subDivideDummy.y,'Subdivide Placement');
		subLabel.visible = false;

		noteTagInput = new FlxUIInputText(noteTypeEffect.x, subDivideDummy.y, 80, "");
		noteTagInput.visible = false;

		noteTagText = new FlxText(noteTagInput.x, noteTagInput.y - noteTagInput.height - 2, 'Custom Tag');
		noteTagText.visible = false;

		playAnimCheck = new FlxUICheckBox(noteTypeEffect.x, noteTagInput.y + noteTagInput.height + 5, null, null, "Play Any Animations", 70);
		playAnimCheck.checked = true;
		playAnimCheck.visible = false;

		var commitChangesButton:FlxButton = new FlxButton(10, 0, "Save Changes", function() {
			modifyNote(curSelectedNote);

			updateGrid();
			updateNoteUI();
		});
		commitChangesButton.y = UI_box.height - commitChangesButton.height - 30;

		tab_group_note.add(writingNotesText);
		tab_group_note.add(stepperSusLength);
		tab_group_note.add(susLabel);
		tab_group_note.add(check_extra_stuff);
		tab_group_note.add(checkBoxLabel);
		tab_group_note.add(subDivideDummy);
		tab_group_note.add(subLabel);
		tab_group_note.add(noteTypeEffect);
		tab_group_note.add(noteTagInput);
		tab_group_note.add(noteTagText);
		tab_group_note.add(playAnimCheck);
		tab_group_note.add(commitChangesButton);

		if(noteAddons[0] != null)
			tab_group_note.add(noteAddonEffect);

		UI_box.addGroup(tab_group_note);
	}

	var plr1X:FlxUINumericStepper;
	var plr1Y:FlxUINumericStepper;

	var plr2X:FlxUINumericStepper;
	var plr2Y:FlxUINumericStepper;

	function addWorldMapUI():Void {
		var tab_group_map = new FlxUI(null, UI_box);
		tab_group_map.name = "SF Map";

		var plr1Text = new FlxText(10,30,0,'Player 1');
		plr1X = new FlxUINumericStepper(10, 50, 1, _song.player1X, -999, 999, 0);
		plr1X.value = _song.player1X;
		plr1X.name = "player1_X";

		var x1Label = new FlxText(plr1X.x + 65, plr1X.y, "X");

		plr1Y = new FlxUINumericStepper(10, 65, 1, _song.player1Y, -999, 999, 0);
		plr1Y.value = _song.player1Y;
		plr1Y.name = "player1_Y";

		var y1Label = new FlxText(plr1Y.x + 65, plr1Y.y, "Y");

		var plr2Text = new FlxText(150,30,0,'Player 2');
		plr2X = new FlxUINumericStepper(150, 50, 1, _song.player2X, -999, 999, 0);
		plr2X.value = _song.player2X;
		plr2X.name = "player2_X";

		var x2Label = new FlxText(plr2X.x + 65, plr2X.y, "X");

		plr2Y = new FlxUINumericStepper(150, 65, 1, _song.player2Y, -999, 999, 0);
		plr2Y.value = _song.player2Y;
		plr2Y.name = "player2_Y";

		var y2Label = new FlxText(plr2Y.x + 65, plr2Y.y, "Y");

		var girlfriendDropDown = new FlxUIDropDownMenu(10, 110, FlxUIDropDownMenu.makeStrIdLabelArray(DefaultHandler.getcharacterJSON(), true), function(character:String) {
			_song.girlfriend = DefaultHandler.getcharacterJSON()[Std.parseInt(character)];
		});
		girlfriendDropDown.selectedLabel = _song.girlfriend;

		var girlfriendTxt:FlxText = new FlxText(girlfriendDropDown.x, girlfriendDropDown.y - 15, "Girlfriend");

		var stageDropDown = new FlxUIDropDownMenu(UI_box.width - 130, 110, FlxUIDropDownMenu.makeStrIdLabelArray(Paths.modJSON.mod.stages, true), function(stage:String) {
			_song.stage = Paths.modJSON.mod.stages[Std.parseInt(stage)];
		});
		stageDropDown.selectedLabel = _song.stage;

		var stageTxt:FlxText = new FlxText(stageDropDown.x, stageDropDown.y - 15, "Stage");

		tab_group_map.add(plr1Text);
		tab_group_map.add(plr1X);
		tab_group_map.add(x1Label);
		tab_group_map.add(plr1Y);
		tab_group_map.add(y1Label);
		tab_group_map.add(plr2Text);
		tab_group_map.add(plr2X);
		tab_group_map.add(x2Label);
		tab_group_map.add(plr2Y);
		tab_group_map.add(y2Label);
		tab_group_map.add(girlfriendDropDown);
		tab_group_map.add(girlfriendTxt);
		tab_group_map.add(stageDropDown);
		tab_group_map.add(stageTxt);

		UI_box.addGroup(tab_group_map);
	}

	function loadSong(daSong:String):Void
	{
		if (FlxG.sound.music != null) {
			FlxG.sound.music.stop();
		}
		
		vocals = new FlxSound().loadEmbedded(Paths.voices(daSong));
		FlxG.sound.list.add(vocals);

		setupSong(daSong);
		FlxG.sound.music.pause();
		Conductor.songPosition = sectionStartTime(curSection);
		FlxG.sound.music.time = Conductor.songPosition;
	}

	function setupSong(daSong:String):Void {
		FlxG.sound.playMusic(Paths.inst(daSong), 0.6);

		if(check_mute_inst != null && check_mute_inst.checked) {
			FlxG.sound.music.volume = 0;
		}

		FlxG.sound.music.onComplete = function() {
			FlxG.sound.music.pause();
			Conductor.songPosition = 0;

			if(vocals != null) {
				vocals.pause();
				vocals.time = 0;
			}

			changeSection();
			curSection = 0;
			updateGrid();
			updateSectionUI();
			vocals.play();
		};
	}

	function generateUI():Void
	{
		while (bullshitUI.members.length > 0)
		{
			bullshitUI.remove(bullshitUI.members[0], true);
		}

		// general shit
		var title:FlxText = new FlxText(UI_box.x + 20, UI_box.y + 20, 0);
		bullshitUI.add(title);
	}

	override function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>)
	{
		if (id == FlxUICheckBox.CLICK_EVENT)
		{
			var check:FlxUICheckBox = cast sender;
			var label = check.getLabel().text;
			switch (label)
			{
				case 'Must hit section':
					_song.notes[curSection].mustHitSection = check.checked;

					updateHeads();

				case 'Change BPM':
					_song.notes[curSection].changeBPM = check.checked;
					FlxG.log.add('changed bpm shit');
				case "Alt Animation":
					_song.notes[curSection].altAnim = check.checked;
			}
		}
		else if (id == FlxUINumericStepper.CHANGE_EVENT && (sender is FlxUINumericStepper))
		{
			var nums:FlxUINumericStepper = cast sender;
			var wname = nums.name;
			FlxG.log.add(wname);
			if (wname == 'section_length')
			{
				if (nums.value <= 4)
					nums.value = 4;
				_song.notes[curSection].lengthInSteps = Std.int(nums.value);
				updateGrid();
			}
			else if (wname == 'song_bpm')
			{
				if (nums.value <= 0)
					nums.value = 1;
				tempBpm = Std.int(nums.value);
				Conductor.mapBPMChanges(_song);
				Conductor.changeBPM(Std.int(nums.value));
			}
			else if (wname == 'song_framerate')
			{
				if (nums.value <= 60)
					nums.value = 60;

				if(_song.modifyFPS)
					Lib.current.stage.frameRate = Std.int(nums.value) * SaveData.getData(SaveType.FPS_MULTIPLIER);
				_song.fps = Std.int(nums.value);
			}
			else if (wname == 'song_mapping') {
				if (nums.value <= 0)
					nums.value = 0;

				_song.colorMapping = Std.int(nums.value);
			}
			else if (wname == 'note_susLength')
			{
				if (curSelectedNote == null)
					return;

				if (nums.value <= 0)
					nums.value = 0;
				curSelectedNote[2] = nums.value;
				updateGrid();
			}
			else if (wname == 'section_bpm')
			{
				if (nums.value <= 0.1)
					nums.value = 0.1;
				_song.notes[curSection].bpm = Std.int(nums.value);
				updateGrid();
			}
			else if(wname == 'player1_X') {
				_song.player1X = Std.int(nums.value);
				updateGrid();
			}
			else if(wname == 'player1_Y') {
				_song.player1Y = Std.int(nums.value);
				updateGrid();
			}
			else if(wname == 'player2_X') {
				_song.player2X = Std.int(nums.value);
				updateGrid();
			}
			else if(wname == 'player2_Y') {
				_song.player2Y = Std.int(nums.value);
				updateGrid();
			}
		}
	}

	var updatedSection:Bool = false;

	function sectionStartTime(section:Int):Float
	{
		var daBPM:Int = _song.bpm;
		var daPos:Float = 0;
		for (i in 0...section)
		{
			if (_song.notes[i].changeBPM)
			{
				daBPM = _song.notes[i].bpm;
			}
			daPos += (getSectionLength(section) / 4) * (1000 * 60 / daBPM);
		}
		return daPos;
	}

	var writingNotes:Bool = false;
	var lastSongPosition:Float = 0;
	var lastMetronomeStep:Int = 0;

	override function update(elapsed:Float)
	{
		curStep = recalculateSteps();

		if(selectingShader != null)
			selectingShader.shaderValue.value[0] += elapsed;

		if(!check_extra_stuff.checked && subDivideDummy.visible) {
			subDivideDummy.visible = false;
			subLabel.visible = false;
			noteTagInput.visible = false;
			noteTagText.visible = false;
			playAnimCheck.visible = false;
			speedLabel.visible = true;
		}

		if(FlxG.sound.music.time < 0) {
			FlxG.sound.music.pause();
			FlxG.sound.music.time = 0;
		}

		if(subDivideDummy.value > 1 && !check_extra_stuff.checked)
			subDivideDummy.value = 1;

		if (FlxG.keys.justPressed.ALT && UI_box.selected_tab == 0) {
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

		Conductor.songPosition = FlxG.sound.music.time;
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
							if (note[0] == Conductor.songPosition && note[1] % (mainGrid/2) == i)
							{
								trace('GAMING');
								_song.notes[curSection].sectionNotes.remove(note);
							}
						}
					trace('adding note');
					_song.notes[curSection].sectionNotes.push([Conductor.songPosition, i, 0]);
					updateGrid();
				}
			}

		}

		strumLine.y = getYfromStrum((Conductor.songPosition - sectionStartTime(curSection)) / (zoomList[zoomMeter]/100) % (Conductor.stepCrochet * getSectionLength(curSection)));
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
			dummyArrow.x = Math.floor(FlxG.mouse.x / GRID_SIZE) * GRID_SIZE;
			if (FlxG.keys.pressed.SHIFT && !check_extra_stuff.checked)
				dummyArrow.y = FlxG.mouse.y;
			else
				dummyArrow.y = Math.floor(FlxG.mouse.y / (GRID_SIZE/subDivideDummy.value)) * (GRID_SIZE/subDivideDummy.value);
		}

		if (FlxG.keys.justPressed.ENTER)
		{
			lastSection = curSection;

			PlayState.SONG = _song;
			FlxG.sound.music.stop();
			vocals.stop();
			
			#if cpp
			CacheState.loadAndSwitchState(new PlayState(muteInGame));
			#else
			LoadingState.loadAndSwitchState(new PlayState(muteInGame));
			#end
		}

		if (FlxG.keys.justPressed.E)
		{
			changeNoteSustain(Conductor.stepCrochet);
		}
		if (FlxG.keys.justPressed.Q)
		{
			changeNoteSustain(-Conductor.stepCrochet);
		}

		if (FlxG.keys.justPressed.TAB)
		{
			if (FlxG.keys.pressed.SHIFT)
			{
				UI_box.selected_tab -= 1;
				if (UI_box.selected_tab < 0)
					UI_box.selected_tab = 2;
			}
			else
			{
				UI_box.selected_tab += 1;
				if (UI_box.selected_tab >= 3)
					UI_box.selected_tab = 0;
			}
		}

		if (!typingShit.hasFocus)
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
					vocals.pause();
				}
				else
				{
					vocals.play();
					vocals.pause();
					vocals.time = FlxG.sound.music.time;
					vocals.play();

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
				vocals.pause();

				FlxG.sound.music.time -= FlxG.mouse.wheel * Conductor.stepCrochet * 0.4;
				vocals.time = FlxG.sound.music.time;
			}

			if (!FlxG.keys.pressed.SHIFT)
			{
				if (FlxG.keys.pressed.W || FlxG.keys.pressed.S)
				{
					FlxG.sound.music.pause();
					vocals.pause();

					var daTime:Float = 700 * FlxG.elapsed;

					if (FlxG.keys.pressed.W)
					{
						FlxG.sound.music.time -= daTime;
					}
					else
						FlxG.sound.music.time += daTime;

					vocals.time = FlxG.sound.music.time;
				}
			}
			else
			{
				if (FlxG.keys.justPressed.W || FlxG.keys.justPressed.S)
				{
					FlxG.sound.music.pause();
					vocals.pause();

					var daTime:Float = Conductor.stepCrochet * 2;

					if (FlxG.keys.justPressed.W)
					{
						FlxG.sound.music.time -= daTime;
					}
					else
						FlxG.sound.music.time += daTime;

					vocals.time = FlxG.sound.music.time;
				}
			}
		}

		curRenderedNotes.forEachAlive(function(note:Note) {
			if(note.strumTime <= Conductor.songPosition) {
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

		if(Conductor.songPosition != lastSongPosition && FlxG.sound.music.playing && curStep % 4 == 0 && lastMetronomeStep != curStep && metronome) {
			FlxG.sound.play(Paths.sound('metronome'), 2);
		}

		_song.bpm = tempBpm;

		/* if (FlxG.keys.justPressed.UP)
				Conductor.changeBPM(Conductor.bpm + 1);
			if (FlxG.keys.justPressed.DOWN)
				Conductor.changeBPM(Conductor.bpm - 1); */

		bpmTxt.text = bpmTxt.text = Std.string(FlxMath.roundDecimal(Conductor.songPosition / 1000, 2))
			+ " / "
			+ Std.string(FlxMath.roundDecimal(FlxG.sound.music.length / 1000, 2))
			+ "\nSection: "
			+ curSection 
			+ "\nStep Sis Counter: " 
			+ Math.max(0, curStep)
			+ "\nBeat Counter: "
			+ Math.max(0, curBeat)
			+ "\n"
			+ "\nMade By: Feeshy";

		lastSongPosition = Conductor.songPosition;
		lastMetronomeStep = curStep;

		super.update(elapsed);
	}

	function checkSectionsY():Float {
		if(check_show_extra != null) {
			if(check_show_extra.checked && _song.notes[curSection + 1] != null) {
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
		var lastChange:BPMChangeEvent = {
			stepTime: 0,
			songTime: 0,
			bpm: 0
		}
		for (i in 0...Conductor.bpmChangeMap.length)
		{
			if (FlxG.sound.music.time > Conductor.bpmChangeMap[i].songTime)
				lastChange = Conductor.bpmChangeMap[i];
		}

		curStep = lastChange.stepTime + Math.floor((FlxG.sound.music.time - lastChange.songTime) / Conductor.stepCrochet);
		updateBeat();

		return curStep;
	}

	function resetSection(songBeginning:Bool = false):Void
	{
		updateGrid();

		FlxG.sound.music.pause();
		vocals.pause();

		// Basically old shit from changeSection???
		FlxG.sound.music.time = sectionStartTime(curSection);

		if (songBeginning) {
			FlxG.sound.music.time = 0;
			curSection = 0;
		}

		vocals.time = FlxG.sound.music.time;

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
				vocals.pause();

				/*var daNum:Int = 0;
					var daLength:Float = 0;
					while (daNum <= sec)
					{
						daLength += lengthBpmBullshit();
						daNum++;
				}*/

				FlxG.sound.music.time = sectionStartTime(curSection);
				vocals.time = FlxG.sound.music.time;
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
				FlxTween.tween(eventSpr, {alpha: 0, angle: 0}, Conductor.stepCrochet/300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
					eventSpr.kill();
					curPhysicalEvents.remove(eventSpr, true);
					eventSpr.destroy();
				}});
			}
		});

		eventDisplay.forEachAlive(function(eventTxt:FlxText) {

			if(eventStep.contains(eventTxt.ID)) {
				FlxTween.tween(eventTxt, {alpha: 0}, Conductor.stepCrochet/300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
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
			var strum = note[0] + Conductor.stepCrochet * (getSectionLength(daSec) * sectionNum);
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
			var strum = note[0] + Conductor.stepCrochet * (getSectionLength(daSec) * sectionNum);
			var copiedNote:Array<Dynamic>;

			note[1] = (note[1] + (mainGrid/2)) % mainGrid;
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

		FlxTween.tween(eventNote, {alpha: 1, angle: 360}, Conductor.stepCrochet/200, {ease: FlxEase.quadOut});
		FlxTween.tween(eventText, {alpha: 1, x: -GRID_SIZE*4.5}, Conductor.stepCrochet/200, {ease: FlxEase.quadOut});
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
					FlxTween.tween(eventSpr, {alpha: 0, angle: 0}, Conductor.stepCrochet/300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
						eventSpr.kill();
						curPhysicalEvents.remove(eventSpr, true);
						eventSpr.destroy();
					}});
				}
			});

			eventDisplay.forEachAlive(function(eventTxt:FlxText) {
				if(eventTxt.ID == stepSis) {
					FlxTween.tween(eventTxt, {alpha: 0}, Conductor.stepCrochet/300, {ease: FlxEase.quadIn, onComplete: function(twn:FlxTween) {
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

		stepperLength.value = getSectionLength(curSection);
		check_mustHitSection.checked = sec.mustHitSection;
		check_changeBPM.checked = sec.changeBPM;
		stepperSectionBPM.value = sec.bpm;

		updateHeads();
	}

	function updateHeads():Void
	{
		if (check_mustHitSection.checked)
		{
			leftIcon.animation.play(_song.player1);
			rightIcon.animation.play(_song.player2);
		}
		else
		{
			leftIcon.animation.play(_song.player2);
			rightIcon.animation.play(_song.player1);
		}
	}

	function updateNoteUI():Void
	{
		if (curSelectedNote != null) {
			stepperSusLength.value = curSelectedNote[2];
			noteTagInput.text = curSelectedNote[4];
		}
	}

	function updateGrid():Void
	{
		while(gridLayout.members.length > 0) {
			gridLayout.remove(gridLayout.members[0], true);
		}

		gridBG = FlxDestroyUtil.destroy(gridBG);
		gridBG = FlxGridOverlay.create(GRID_SIZE, GRID_SIZE, GRID_SIZE * mainGrid, Std.int(GRID_SIZE * getSectionLength(curSection) * (zoomList[zoomMeter]/100)));

		if(strumLine != null) {
			strumLine.makeGraphic(Std.int(GRID_SIZE * mainGrid), 4);
			strumLine.updateHitbox();
		}

		var totalHeight:Float = gridBG.height;

		if(UI_Modifiers != null)
			UI_Modifiers.x = UI_box.x + UI_box.width;

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
			Conductor.changeBPM(_song.notes[curSection].bpm);
			FlxG.log.add('CHANGED BPM!');
		}
		else
		{
			// get last bpm
			var daBPM:Int = _song.bpm;
			for (i in 0...curSection)
				if (_song.notes[i].changeBPM)
					daBPM = _song.notes[i].bpm;
			Conductor.changeBPM(daBPM);
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

			if(_song.fifthKey)
				camFollow.x = 400;
			else
				camFollow.x = 360;
		}

		gridLayout.remove(gridBG2);
		gridBG2 = FlxDestroyUtil.destroy(gridBG2);

		if(check_show_extra != null) {
			if(check_show_extra.checked) {
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
			if(check_show_extra.checked) {
				var gridBlackLineH:FlxSprite = new FlxSprite(-1, gridBG2.height).makeGraphic(GRID_SIZE * mainGrid, 2, FlxColor.BLACK);
				gridLayout.add(gridBlackLineH);
			}
		}

		var gridBlackLineV:FlxSprite = new FlxSprite(gridBG.x + gridBG.width / 2, -1).makeGraphic(2, Std.int(totalHeight), FlxColor.BLACK);
		gridLayout.add(gridBlackLineV);
			
		setupNotes(sectionInfo, curSection, 0);

		if(curRenderedNotes.members[0] != null && !_song.fifthKey) {
			for(i in 0...curRenderedNotes.length) {
				if(curRenderedNotes.members[i].x >= 320)
					curRenderedNotes.members[i].visible = false;
			}
		}

		if(curRenderedSustains.members[0] != null && !_song.fifthKey) {
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
			var daSus = curSel[2];
			var daNoteType = curSel[3];
			var daTag = curSel[4];
			var daAnimPlay = curSel[5];

			daNoteType = wtfIsNote;

			if(check_extra_stuff.checked) {
				daTag = noteTagInput.text;
				daAnimPlay = playAnimCheck.checked;
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

			var note:Note = new Note(daStrumTime, daNoteInfo % Math.floor(mainGrid/2), null, false, daNoteType);
			note.sustainLength = daSus;
			note.setGraphicSize(GRID_SIZE, GRID_SIZE);
			note.updateHitbox();
			note.x = Math.floor(daNoteInfo * GRID_SIZE);
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

		if(curRenderedNotes.members[0] != null && !_song.fifthKey) {
			for(i in 0...curRenderedNotes.length) {
				if(curRenderedNotes.members[i].x >= 320)
					curRenderedNotes.members[i].visible = false;
			}
		}
		if(curRenderedSustains.members[0] != null && !_song.fifthKey) {
			for(i in 0...curRenderedSustains.length) {
				if(curRenderedSustains.members[i].x > 320)
					curRenderedSustains.members[i].visible = false;
			}
		}
	}

	function makeSusNote(note:Note, susValue:Float, section:Int):FlxSprite {
		var height:Int = Math.floor(FlxMath.remapToRange(susValue, 0, Conductor.stepCrochet * 16, 0, GRID_SIZE * 16 * (zoomList[zoomMeter]/100)));

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
		for (i in _song.notes[curSection].sectionNotes)
		{
			if (i[0] == note.strumTime && i[1] == Math.floor(note.x / GRID_SIZE))
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


	function deleteNote(note:Note):Void
	{
		lastNote = note;
		for (i in _song.notes[curSection].sectionNotes)
		{
			if (i[0] == note.strumTime && i[1] % mainGrid == Math.floor(note.x / GRID_SIZE))
			{
				_song.notes[curSection].sectionNotes.remove(i);
			}
		}

		if(check_show_extra != null) {
			if(check_show_extra.checked && _song.notes[curSection + 1] != null) {
				for (i in _song.notes[curSection + 1].sectionNotes)
				{
					if (i[0] == note.strumTime && i[1] % mainGrid == Math.floor(note.x / GRID_SIZE))
					{
						_song.notes[curSection + 1].sectionNotes.remove(i);
					}
				}
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
		var noteData = Math.floor(FlxG.mouse.x / GRID_SIZE);
		var noteTag:String = null;
		var playAnyAnim:Bool = true;
		var noteSus = 0;
			
		if(check_extra_stuff.checked) {
			noteTag = noteTagInput.text;
			playAnyAnim = playAnimCheck.checked;
		}

		if (n != null) {
			n.noteAbstract = wtfIsNote;
			_song.notes[curSection + extraSection].sectionNotes.push([n.strumTime, n.noteData + (n.mustPress ? mainGrid/2 : 0), n.sustainLength, n.noteAbstract, n.tag, n.playAnyAnimation]);
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
		return FlxMath.remapToRange(yPos, gridBG.y, gridBG.y + gridBG.height * totalGrids, 0, 16 * Conductor.stepCrochet * totalGrids);
	}

	function getYfromStrum(strumTime:Float):Float
	{
		return FlxMath.remapToRange(strumTime, 0, 16 * Conductor.stepCrochet * totalGrids, gridBG.y, gridBG.y + gridBG.height * (zoomList[zoomMeter]/100) * totalGrids);
	}

	function getYfromNotes(strumTime:Float):Float { //long
		return GRID_SIZE * 16 * (zoomList[zoomMeter]/100) * (strumTime / (16 * Conductor.stepCrochet)) + gridBG.y;
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

		if(_song.video != null) {
			tab_group_video.add(watchButton);
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