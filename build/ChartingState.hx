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
import haxe.Json;
import lime.utils.Assets;
import example_code.DefaultEvents.Modifiers;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.events.IOErrorEvent;
import openfl.events.IOErrorEvent;
import openfl.media.Sound;
import openfl.net.FileReference;
import openfl.utils.ByteArray;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import openfl.display.FPS;
import openfl.Lib;

import example_code.DefaultStage;

import SaveData.SaveType;
import BuiltInShaders;
import Feeshmora;
import Compile;

using StringTools;

class ChartingState extends MusicBeatState
{
	private var muteInGame:Bool = PlayState.muteInst;

	private var mainGrid:Int = 8;

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

	var dummyArrow:FlxSprite;

	var curRenderedNotes:FlxTypedGroup<Note>;
	var curRenderedSustains:FlxTypedGroup<FlxSprite>;

	var curPhysicalEvents:FlxTypedGroup<FlxSprite>;

	var gridBG:FlxSprite;

	var _song:SwagSong;

	var typingShit:FlxInputText;
	/*
	 * WILL BE THE CURRENT / LAST PLACED NOTE
	**/
	var curSelectedNote:Array<Dynamic>;

	var tempBpm:Int = 0;
	var gridBlackLine:FlxSprite;
	var vocals:FlxSound;

	var leftIcon:HealthIcon;
	var rightIcon:HealthIcon;

	var camFollow:FlxObject;

	var lastNote:Note;

	var eventDisplay:FlxTypedGroup<FlxText>;

	var wtfIsNote:String = "regular";
	var wtfIsEvent:String = "flip chart";

	var songFPS:Null<Int> = 100;
	var colorMap:Null<Int> = 0;

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
	public static final daList:Array<String> = ['flip chart', 'fair battle', 'fade battle', 'blind effect', 'X Sway', 'note woggle', 'camera move', 'clear stuff'];
	private static final simpleList:Array<Array<String>> = [
		['alt animation', "Value 1 - Sets a suffix after the idle and sing\nanimation name.\nValue 2 - Character side to set (Boyfriend's Side or Dad's Side)"],
		['jumpspeed', "Value 1 - Multiply regular scroll speed by this value.\nValue 2 - Set tween value of scroll speed transition."],
		['sicko shake', "Value 1 - Regular camera shake.\nValue 2 - HUD camera shake."],
		['time freeze', "Value 1 - 0 = Unfreeze time of music. 1 = Freeze time\nof music.\nValue 2 - Set tween value."],
		['strum bounce', "Value 1 - Set size value.\nValue 2 - Set X offset value for player strum."],
		['note rewind', "Value 1 - Set rewind value.\nValue 2 - Set tween value to the rewind speed."],
		['character change', "Value 1 - New character's name.\nValue 2 - Character to change \n(Boyfriend's Side, Dad's Side, Girlfriend's Side)"],
		['clear stuff', "Value 1 - nothing.\nValue 2 - nothing."]
	];

	private var selectingShader:BuiltInShaders;

	private var eventCatalog:Map<String, String> = [
		'flip chart' => "Modifiers",
		'fair battle' => "Modifiers",
		'blind effect' => "Modifiers",
		'fade battle' => "Modifiers",
		'X Sway' => "Modifiers",
		'note woggle' => "Modifiers",
		'camera move' => "Modifiers",
		'alt animation' => "Other",
		'jumpspeed' => "Other",
		'sicko shake' => "Other",
		'time freeze' => "Other",
		'strum bounce' => "Other",
		'note rewind' => "Other",
		'character change' => "Other",
		'clear stuff' => "Other"
	];

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
				girlfriend: null,
				speed: 1,
				validScore: false,
				fifthKey: false,
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

		bpmTxt = new FlxText(1000, 50, 0, "", 16);

		if(_song.fifthKey) {
			bpmTxt.x = 1050;
			mainGrid = 10;
		}	

		gridBG = FlxGridOverlay.create(GRID_SIZE, GRID_SIZE, GRID_SIZE * mainGrid, GRID_SIZE * 16);
		add(gridBG);

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

		gridBlackLine = new FlxSprite(gridBG.x + gridBG.width / 2).makeGraphic(2, Std.int(gridBG.height), FlxColor.BLACK);
		add(gridBlackLine);

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

		dummyArrow = new FlxSprite().makeGraphic(GRID_SIZE, GRID_SIZE);
		add(dummyArrow);

		var tabs = [
			{name: "Song", label: 'Song'},
			{name: "Section", label: 'Section'},
			{name: "Note", label: 'Note'},
			{name: "SF Map", label: 'Map'}
		];

		var mod_tabs;

		if(Main.feeshmoraModifiers) {
			mod_tabs = [
				{name: "F Modifiers", label: 'Modifiers'},
				//{name: "Game Modes", label: 'Game Modes'},
				{name: "Other", label: "Other"},
				{name: "Settings", label: "Settings"}
			];
		}else {
			mod_tabs = [
				{name: "Other", label: "Other"},
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

		UI_box.y = 20;
		add(UI_box);

		if(_song.fifthKey)
			UI_Modifiers.x = FlxG.width / 2 + GRID_SIZE + UI_box.width;
		else
			UI_Modifiers.x = FlxG.width / 2 + UI_box.width;

		UI_Modifiers.y = UI_box.height - UI_Modifiers.height + 20;

		add(UI_Modifiers);

		selectingShader = new BuiltInShaders();
		selectingShader.shader = ShaderType.GLIM_SELECTION;

		addSongUI();
		addSectionUI();
		addNoteUI();
		addWorldMapUI();

		//Options
		addModifierUI();
		addOtherEventUI();
		addSettingsEventUI();

		add(curRenderedNotes);
		add(curRenderedSustains);

		instrucTxt = new FlxText(UI_box.x, UI_box.y + UI_box.height + GRID_SIZE, FlxG.width,
            "Q/E - Change Strum\n\n" +
            "CTRL & Click Note - Select Note\n\n" +
            "SPACE - Stop or Resume",
        16);

		instrucTxt.scrollFactor.set();
		add(instrucTxt);

		super.create();
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

	function addModifierUI():Void {
		var makeModName = new FlxUIInputText(160, 20, 80, "Modifier Pog", 8);

		var modLabel = new FlxText(90, 20, 'Event Name:');

		var createEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 75, "Create Event", function() {
			if(curStep < 0 || curStep < curSection*16 || makeModName.text == "")
				return;

			for(i in 0..._song.modifiers.length) {
				var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");

				if(gridY == GRID_SIZE*curStep)
					return;
			}

			var createMod:Modifiers = {modSkill: wtfIsEvent, modGridY: GRID_SIZE*curStep, modValue: null, modValueTwo: null, modDisplayName: makeModName.text};

			_song.modifiers.push(createMod);

			createPhysicalEvent(_song.modifiers.length-1, curStep, null, null);
		});

		var removeEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 50, "Remove Event", function() {
			if(curStep < 0 || curStep < curSection*16)
				return;

			removePhysicalEvent(curStep);
		});

		var modList:FlxUIDropDownMenu = new FlxUIDropDownMenu(125, 50, FlxUIDropDownMenu.makeStrIdLabelArray(daList, true), function(choose:String) {
			wtfIsEvent = daList[Std.parseInt(choose)];
		});

		var tab_group_modifiers = new FlxUI(null, UI_Modifiers);
		tab_group_modifiers.name = "F Modifiers";
		tab_group_modifiers.add(makeModName);
		tab_group_modifiers.add(modLabel);
		tab_group_modifiers.add(createEventButton);
		tab_group_modifiers.add(removeEventButton);
		tab_group_modifiers.add(modList);

		UI_Modifiers.addGroup(tab_group_modifiers);
		UI_Modifiers.scrollFactor.set();
	}

	function addOtherEventUI():Void {
		var makeOtherName = new FlxUIInputText(185, 20, 80, "Other Pog", 8);

		var otherLabel:FlxText = new FlxText(115, 20, 'Event Name:');

		var makeOtherValue:FlxUIInputText = new FlxUIInputText(150, 85, 80, "", 8);
		var makeOtherTwoValue:FlxUIInputText = new FlxUIInputText(150, 105, 80, "", 8);

		var otherValueLabel:FlxText = new FlxText(100, 85, 'Value 1:');
		var otherTwoValueLabel:FlxText = new FlxText(100, 105, 'Value 2:');

		var howToTutorial:FlxText = new FlxText(5, 125, '');

		var createEventButton:FlxButton = new FlxButton(5, UI_Modifiers.height - 75, "Create Event", function() {
			if(curStep < 0 || curStep < curSection*16 || makeOtherName.text == "")
				return;

			for(i in 0..._song.modifiers.length) {
				var gridY:Int = Reflect.field(_song.modifiers[i], "modGridY");

				if(gridY == GRID_SIZE*curStep)
					return;
			}

			var createEvent:Modifiers = {modSkill: wtfIsEvent, modGridY: GRID_SIZE*curStep, modValue: null, modValueTwo: null, modDisplayName: makeOtherName.text};

			switch(createEvent.modSkill) {
				case "alt animation":
					createEvent.modValue = makeOtherValue.text.toLowerCase();
					createEvent.modValueTwo = otherTwoValueLabel.text.toLowerCase();
				case "jumpspeed":
					if(Std.parseInt(makeOtherValue.text) != null)
						createEvent.modValue = Std.string(Math.min(3, Math.max(0.5, Std.parseFloat(makeOtherValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeOtherTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(6, Math.max(1, Std.parseFloat(makeOtherTwoValue.text))));
					else
						createEvent.modValueTwo = "1";
				case "sicko shake":
					if(Std.parseInt(makeOtherValue.text) != null)
						createEvent.modValue = Std.string(Math.min(10, Math.max(1, Std.parseInt(makeOtherValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeOtherTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(10, Math.max(1, Std.parseInt(makeOtherTwoValue.text))));
					else
						createEvent.modValueTwo = "0";
				case "time freeze":
					if(Std.parseInt(makeOtherValue.text) != null)
						createEvent.modValue = Std.string(Math.min(1, Math.max(0, Std.parseInt(makeOtherValue.text))));
					else
						createEvent.modValue = "0";

					if(Std.parseInt(makeOtherTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(4, Math.max(0, Std.parseFloat(makeOtherTwoValue.text))));
					else
						createEvent.modValueTwo = "1";
				case "strum bounce":
					if(Std.parseInt(makeOtherValue.text) != null)
						createEvent.modValue = Std.string(Math.min(200, Math.max(-200, Std.parseInt(makeOtherValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeOtherTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(30, Math.max(0, Std.parseInt(makeOtherTwoValue.text))));
					else
						createEvent.modValueTwo = "10";
				case "note rewind":
					if(Std.parseInt(makeOtherValue.text) != null)
						createEvent.modValue = Std.string(Math.min(16, Math.max(0, Std.parseInt(makeOtherValue.text))));
					else
						createEvent.modValue = "1";

					if(Std.parseInt(makeOtherTwoValue.text) != null)
						createEvent.modValueTwo = Std.string(Math.min(9, Math.max(1, Std.parseFloat(makeOtherTwoValue.text))));
					else
						createEvent.modValueTwo = "1";
				case "opponent change":
					createEvent.modValue = makeOtherValue.text.toLowerCase();
					createEvent.modValueTwo = otherTwoValueLabel.text.toLowerCase();
				case "clear array":
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

		for (i in 0...simpleList.length)
			eventList.push(simpleList[i][0]);

		var otherList:FlxUIDropDownMenu = new FlxUIDropDownMenu(150, 50, FlxUIDropDownMenu.makeStrIdLabelArray(eventList, true), function(choose:String) {
			wtfIsEvent = simpleList[Std.parseInt(choose)][0];

			makeOtherValue.text = "";
			howToTutorial.text = simpleList[Std.parseInt(choose)][1];
		});

		var tab_group_otherEvent:FlxUI = new FlxUI(null, UI_Modifiers);
		tab_group_otherEvent.name = "Other";
		tab_group_otherEvent.add(makeOtherName);
		tab_group_otherEvent.add(createEventButton);
		tab_group_otherEvent.add(removeEventButton);
		tab_group_otherEvent.add(makeOtherValue);
		tab_group_otherEvent.add(makeOtherTwoValue);
		tab_group_otherEvent.add(otherLabel);
		tab_group_otherEvent.add(otherValueLabel);
		tab_group_otherEvent.add(otherTwoValueLabel);
		tab_group_otherEvent.add(howToTutorial);
		tab_group_otherEvent.add(otherList);

		UI_Modifiers.addGroup(tab_group_otherEvent);
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

	var playOSU_Sound:Bool;

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

		var check_mute_inst:FlxUICheckBox = new FlxUICheckBox(10, 145, null, null, "Mute Instrumental (in editor)", 100);
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

			strumLine.makeGraphic(Std.int(GRID_SIZE * mainGrid), 4);
			strumLine.updateHitbox();

			updateGrid();
		};

		var check_hit:FlxUICheckBox = new FlxUICheckBox(75, 145-(check_mute_inst.height*2), null, null, "OSU Hit Sounds", 100);
		check_hit.checked = false;
		check_hit.callback = function() {
			playOSU_Sound = check_hit.checked;
		}

		var check_mute_inst_game:FlxUICheckBox = new FlxUICheckBox(10, 145+(check_mute_inst.height*1.5), null, null, "Mute Instrumental (in game)", 100);
		check_mute_inst_game.checked = PlayState.muteInst;
		check_mute_inst_game.callback = function()
		{
			muteInGame = check_mute_inst_game.checked;
		};

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

		var stepperBPM:FlxUINumericStepper = new FlxUINumericStepper(10, 65, 0.1, 1, 1.0, 5000.0, 1);
		stepperBPM.value = Conductor.bpm;
		stepperBPM.name = 'song_bpm';

		var bpmLabel:FlxText = new FlxText(stepperBPM.x + 65, stepperBPM.y, "BPM");

		var stepperFps:FlxUINumericStepper = new FlxUINumericStepper(10, 95, 1, songFPS, 60, 600, 0);
		stepperFps.value = songFPS;
		stepperFps.name = 'song_framerate';

		var fpsLabel = new FlxText(stepperFps.x + 65, stepperFps.y, "FPS");

		var stepperMap:FlxUINumericStepper = new FlxUINumericStepper(140, 95, 1, colorMap, 0, ChooseFeeshmora.getMapSize("boyfriend"), 0);
		stepperMap.value = colorMap;
		stepperMap.name = 'song_mapping';

		var mapLabel = new FlxText(stepperMap.x + 65, stepperMap.y, "Feeshmora Skins");

		var player1DropDown = new FlxUIDropDownMenu(140, 215, FlxUIDropDownMenu.makeStrIdLabelArray(Compile.getcharacterJSON(), true), function(character:String)
		{
			_song.player1 = Compile.getcharacterJSON()[Std.parseInt(character)];
			updateHeads();
		});
		player1DropDown.selectedLabel = _song.player1;

		var player2DropDown = new FlxUIDropDownMenu(10, 215, FlxUIDropDownMenu.makeStrIdLabelArray(Compile.getcharacterJSON(), true), function(character:String)
		{
			_song.player2 = Compile.getcharacterJSON()[Std.parseInt(character)];
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
		tab_group_song.add(check_hit);
		tab_group_song.add(check_fifth);
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
		//tab_group_song.add(stepperMap);
		//tab_group_song.add(mapLabel);
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
	var stepperSectionBPM:FlxUINumericStepper;

	function addSectionUI():Void
	{
		var tab_group_section = new FlxUI(null, UI_box);
		tab_group_section.name = 'Section';

		stepperLength = new FlxUINumericStepper(10, 10, 4, 0, 0, 999, 0);
		stepperLength.value = _song.notes[curSection].lengthInSteps;
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

		check_mustHitSection = new FlxUICheckBox(10, 30, null, null, "Must hit section", 100);
		check_mustHitSection.name = 'check_mustHit';
		check_mustHitSection.checked = true;
		// _song.needsVoices = check_mustHit.checked;

		check_changeBPM = new FlxUICheckBox(10, 60, null, null, 'Change BPM', 100);
		check_changeBPM.name = 'check_changeBPM';

		tab_group_section.add(stepperLength);
		tab_group_section.add(stepperSectionBPM);
		tab_group_section.add(stepperCopy);
		tab_group_section.add(check_mustHitSection);
		tab_group_section.add(check_changeBPM);
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
	var singleNoteSpeed:FlxUINumericStepper;
	var noteSpeedLabel:FlxText;
	
	function addNoteUI():Void
	{
		final DaNotes:Array<String> = CoolUtil.coolTextFile(Paths.pak('mapHandler'));

		var noteAddons:Array<String> = new Array<String>();

		//trace(CustomNoteHandler.customNoteAddon[0]);

		for(v in CustomNoteHandler.customNoteAddon)
			noteAddons.push(v.getCustomNote());

		tab_group_note = new FlxUI(null, UI_box);
		tab_group_note.name = 'Note';

		writingNotesText = new FlxUIText(20,100, 0, "");
		writingNotesText.setFormat("Arial",20,FlxColor.WHITE,FlxTextAlign.LEFT,FlxTextBorderStyle.OUTLINE,FlxColor.BLACK);

		stepperSusLength = new FlxUINumericStepper(10, 10, Conductor.stepCrochet / 2, 0, 0, Conductor.stepCrochet * _song.notes[curSection].lengthInSteps * 4);
		stepperSusLength.value = 0;
		stepperSusLength.name = 'note_susLength';

		var susLabel = new FlxText(stepperSusLength.x + 65,stepperSusLength.y,'SUS Note Length');

		check_extra_stuff = new FlxUICheckBox(10, 30 + stepperSusLength.y, null, null, "", 250);
		check_extra_stuff.checked = false;
		check_extra_stuff.callback = function()
		{
			subDivideDummy.visible = check_extra_stuff.checked;
			subLabel.visible = check_extra_stuff.checked;
			singleNoteSpeed.visible = check_extra_stuff.checked;
			noteSpeedLabel.visible = check_extra_stuff.checked;
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

		singleNoteSpeed = new FlxUINumericStepper(150, subDivideDummy.y + 15, 0.1, _song.speed, 0.1, 10, 1);
		singleNoteSpeed.value = _song.speed;
		singleNoteSpeed.name = 'note_speed';
		singleNoteSpeed.visible = false;

		noteSpeedLabel = new FlxText(subDivideDummy.x + 65,singleNoteSpeed.y,'Note Speed');
		noteSpeedLabel.visible = false;

		tab_group_note.add(writingNotesText);
		tab_group_note.add(stepperSusLength);
		tab_group_note.add(susLabel);
		tab_group_note.add(check_extra_stuff);
		tab_group_note.add(checkBoxLabel);
		tab_group_note.add(subDivideDummy);
		tab_group_note.add(subLabel);
		tab_group_note.add(singleNoteSpeed);
		tab_group_note.add(noteSpeedLabel);
		tab_group_note.add(noteTypeEffect);

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

		var girlfriendDropDown = new FlxUIDropDownMenu(10, 110, FlxUIDropDownMenu.makeStrIdLabelArray(Compile.getcharacterJSON(), true), function(character:String) {
			_song.girlfriend = Compile.getcharacterJSON()[Std.parseInt(character)];
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
		if (FlxG.sound.music != null)
		{
			FlxG.sound.music.stop();
			// vocals.stop();
		}

		FlxG.sound.playMusic(Paths.inst(daSong), 0.6);

		// WONT WORK FOR TUTORIAL OR TEST SONG!!! REDO LATER
		vocals = new FlxSound().loadEmbedded(Paths.voices(daSong));
		FlxG.sound.list.add(vocals);

		FlxG.sound.music.pause();
		vocals.pause();

		Conductor.songPosition = sectionStartTime();
		FlxG.sound.music.time = Conductor.songPosition;

		FlxG.sound.music.onComplete = function()
		{
			vocals.pause();
			FlxG.sound.music.pause();
			FlxG.sound.music.time = 0;
			vocals.time = 0;
			changeSection();
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
		/* 
			var loopCheck = new FlxUICheckBox(UI_box.x + 10, UI_box.y + 50, null, null, "Loops", 100, ['loop check']);
			loopCheck.checked = curNoteSelected.doesLoop;
			tooltips.add(loopCheck, {title: 'Section looping', body: "Whether or not it's a simon says style section", style: tooltipType});
			bullshitUI.add(loopCheck);

		 */
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
			else if (wname == 'song_speed')
			{
				if (nums.value <= 0)
					nums.value = 0;
				_song.speed = nums.value;
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

		// FlxG.log.add(id + " WEED " + sender + " WEED " + data + " WEED " + params);
	}

	var updatedSection:Bool = false;

	/* this function got owned LOL
		function lengthBpmBullshit():Float
		{
			if (_song.notes[curSection].changeBPM)
				return _song.notes[curSection].lengthInSteps * (_song.notes[curSection].bpm / _song.bpm);
			else
				return _song.notes[curSection].lengthInSteps;
	}*/
	function sectionStartTime():Float
	{
		var daBPM:Int = _song.bpm;
		var daPos:Float = 0;
		for (i in 0...curSection)
		{
			if (_song.notes[i].changeBPM)
			{
				daBPM = _song.notes[i].bpm;
			}
			daPos += 4 * (1000 * 60 / daBPM);
		}
		return daPos;
	}

	var writingNotes:Bool = false;
	var getNotePosition:Float = 0;

	override function update(elapsed:Float)
	{
		curStep = recalculateSteps();

		if(selectingShader != null)
			selectingShader.shaderValue.value[0] += elapsed;

		if(!check_extra_stuff.checked && subDivideDummy.visible) {
			subDivideDummy.visible = false;
			subLabel.visible = false;
			singleNoteSpeed.visible = false;
			noteSpeedLabel.visible = false;
			stepperSpeed.visible = true;
			speedLabel.visible = true;
		}else if(check_extra_stuff.checked && stepperSpeed.visible) {
			stepperSpeed.visible = false;
			speedLabel.visible = false;
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

		if (writingNotes)
			writingNotesText.text = "WRITING NOTES";
		else
			writingNotesText.text = "";

		Conductor.songPosition = FlxG.sound.music.time;
		_song.song = typingShit.text;

		var upP = controls.UP_P;
		var rightP = controls.RIGHT_P;
		var downP = controls.DOWN_P;
		var leftP = controls.LEFT_P;

		var controlArray:Array<Bool> = [leftP, downP, upP, rightP];

		if ((upP || rightP || downP || leftP) && writingNotes)
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

		strumLine.y = getYfromStrum((Conductor.songPosition - sectionStartTime()) % (Conductor.stepCrochet * _song.notes[curSection].lengthInSteps));
		camFollow.y = strumLine.y;

		if (playOSU_Sound) {
			curRenderedNotes.forEach(function(note:Note) {
				if (FlxG.sound.music.playing) {
					FlxG.overlap(strumLine, note, function(_, _) {
						if(!osuManiaSounds.contains(note) && !CustomNoteHandler.dontHitNotes.contains(note.noteAbstract)) {
							osuManiaSounds.push(note);
							FlxG.sound.play(Paths.sound('hitChart'), 2);
						}
					});
				}else if(osuManiaSounds[0] != null) {
					osuManiaSounds.splice(0, osuManiaSounds.length);
					osuManiaSounds = [];
				}
			});
		}

		getNotePosition = Conductor.songPosition;

		if (curBeat % 4 == 0 && curStep >= 16 * (curSection + 1))
		{
			trace(curStep);
			trace((_song.notes[curSection].lengthInSteps) * (curSection + 1));
			trace('DUMBSHIT');

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
				curRenderedNotes.forEach(function(note:Note)
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
					&& FlxG.mouse.y < gridBG.y + (GRID_SIZE * _song.notes[curSection].lengthInSteps))
				{
					FlxG.log.add('added note');
					addNote();
				}
			}
		}

		if (FlxG.mouse.x > gridBG.x
			&& FlxG.mouse.x < gridBG.x + gridBG.width
			&& FlxG.mouse.y > gridBG.y
			&& FlxG.mouse.y < gridBG.y + (GRID_SIZE * _song.notes[curSection].lengthInSteps))
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
			FlxG.switchState(new PlayState(muteInGame));
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
			+ "\nMade By Feeshy";
		super.update(elapsed);
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
		FlxG.sound.music.time = sectionStartTime();

		if (songBeginning)
		{
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

			curPhysicalEvents.clear();
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

				FlxG.sound.music.time = sectionStartTime();
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
					var copyE:Modifiers = {modSkill: skill, modGridY: (Std.int(gridY/GRID_SIZE) - (section * 16))*GRID_SIZE, modValue: value, modValueTwo: value2, modDisplayName: name};

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
			var strum = note[0] + Conductor.stepCrochet * (_song.notes[daSec].lengthInSteps * sectionNum);
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
			var strum = note[0] + Conductor.stepCrochet * (_song.notes[daSec].lengthInSteps * sectionNum);
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

		stepperLength.value = sec.lengthInSteps;
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
		if (curSelectedNote != null)
			stepperSusLength.value = curSelectedNote[2];
	}

	function updateGrid():Void
	{
		remove(gridBG);
		gridBG = FlxGridOverlay.create(GRID_SIZE, GRID_SIZE, GRID_SIZE * mainGrid, GRID_SIZE * _song.notes[curSection].lengthInSteps);
        add(gridBG);

		remove(gridBlackLine);
		gridBlackLine = new FlxSprite(gridBG.x + gridBG.width / 2).makeGraphic(2, Std.int(gridBG.height), FlxColor.BLACK);
		add(gridBlackLine);

		if(UI_Modifiers != null)
			UI_Modifiers.x = UI_box.x + UI_box.width;

		while (curRenderedNotes.members.length > 0)
		{
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
			

		for (i in sectionInfo)
		{
			var daStrumTime = i[0];
			var daNoteInfo = i[1];
			var daSus = i[2];
			var daNoteType = i[3];
			var daSpeed = i[4];

			var note:Note = new Note(daStrumTime, daNoteInfo % Std.int(mainGrid/2), null, false, daNoteType);
			note.sustainLength = daSus;
			note.setGraphicSize(GRID_SIZE, GRID_SIZE);
			note.updateHitbox();
			note.x = Math.floor(daNoteInfo * GRID_SIZE);
			note.y = Std.int(getYfromStrum((daStrumTime - sectionStartTime()) % (Conductor.stepCrochet * _song.notes[curSection].lengthInSteps)));

			note.refresh(_song.fifthKey);

			//trace(getYfromStrum((daStrumTime - sectionStartTime()) % (Conductor.stepCrochet * _song.notes[curSection].lengthInSteps)) + " " + curStep);

			if (curSelectedNote != null) {
				if (curSelectedNote[0] == note.strumTime && curSelectedNote[1] == daNoteInfo) {
					lastNote = note;
					lastNote.shader = selectingShader;
				}
			}	

			curRenderedNotes.add(note);

			if (daSus > 0)
			{
				var sustainVis:FlxSprite = new FlxSprite(note.x + (GRID_SIZE / 2),
					note.y + GRID_SIZE).makeGraphic(8, Math.floor(FlxMath.remapToRange(daSus, 0, Conductor.stepCrochet * _song.notes[curSection].lengthInSteps, 0, gridBG.height)));
				curRenderedSustains.add(sustainVis);
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

	private function addSection(lengthInSteps:Int = 16):Void
	{
		var sec:SwagSection = {
			lengthInSteps: lengthInSteps,
			bpm: _song.bpm,
			changeBPM: false,
			mustHitSection: true,
			sectionNotes: [],
			typeOfSection: 0,
			altAnim: false,
		};

		_song.notes.push(sec);
	}

	function selectNote(note:Note):Void
	{
		for (i in _song.notes[curSection].sectionNotes)
		{
			if (i[0] == note.strumTime && i[1] == Std.int(Math.floor(note.x / GRID_SIZE)))
			{
				curSelectedNote = i;
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
			if (i[0] == note.strumTime && i[1] % mainGrid == Std.int(Math.floor(note.x / GRID_SIZE)))
			{
				_song.notes[curSection].sectionNotes.remove(i);
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
		var noteStrum = getStrumTime(dummyArrow.y) + sectionStartTime();
		var noteData = Math.floor(FlxG.mouse.x / GRID_SIZE);
		var noteSus = 0;
		var noteSpeed = singleNoteSpeed.value;

		if (n != null) {
			n.noteAbstract = wtfIsNote;
			_song.notes[curSection].sectionNotes.push([n.strumTime, n.noteData + (n.mustPress ? mainGrid/2 : 0), n.sustainLength, n.noteAbstract, n.howSpeed]);
		}
		else {
			if(!check_extra_stuff.checked)
				noteSpeed = 0;

			_song.notes[curSection].sectionNotes.push([noteStrum, noteData, noteSus, wtfIsNote, noteSpeed]);
		}

		curSelectedNote = _song.notes[curSection].sectionNotes[_song.notes[curSection].sectionNotes.length - 1];

		updateGrid();
		updateNoteUI();

		autosaveSong();
	}

	function getStrumTime(yPos:Float):Float
	{
		return FlxMath.remapToRange(yPos, gridBG.y, gridBG.y + gridBG.height, 0, 16 * Conductor.stepCrochet);
	}

	function getYfromStrum(strumTime:Float):Float
	{
		return FlxMath.remapToRange(strumTime, 0, 16 * Conductor.stepCrochet, gridBG.y, gridBG.y + gridBG.height);
	}

	/*
		function calculateSectionLengths(?sec:SwagSection):Int
		{
			var daLength:Int = 0;

			for (i in _song.notes)
			{
				var swagLength = i.lengthInSteps;

				if (i.typeOfSection == Section.COPYCAT)
					swagLength * 2;

				daLength += swagLength;

				if (sec != null && sec == i)
				{
					trace('swag loop??');
					break;
				}
			}

			return daLength;
	}*/
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

		var data:String = Json.stringify(json);

		if ((data != null) && (data.length > 0))
		{
			_file = new FileReference();
			_file.addEventListener(Event.COMPLETE, onSaveComplete);
			_file.addEventListener(Event.CANCEL, onSaveCancel);
			_file.addEventListener(IOErrorEvent.IO_ERROR, onSaveError);
			_file.save(data.trim(), _song.song.toLowerCase() + ".json");
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

	function onSaveError(_):Void
	{
		_file.removeEventListener(Event.COMPLETE, onSaveComplete);
		_file.removeEventListener(Event.CANCEL, onSaveCancel);
		_file.removeEventListener(IOErrorEvent.IO_ERROR, onSaveError);
		_file = null;
		FlxG.log.error("Problem saving Level data");
	}
}