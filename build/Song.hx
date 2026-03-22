package;

import Section.SwagSection;
import haxe.Json;
import haxe.format.JsonParser;
import lime.utils.Assets;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import example_code.DefaultEvents.EventInfo;

using StringTools;

typedef SwagSong =
{
	var song:String;
	var notes:Array<SwagSection>;
	var modifiers:Array<EventInfo>;
	var bpm:Int;
	var needsVoices:Bool;
	var speed:Float;

	var player1:String;
	var player2:String;
	var girlfriend:String;

	var stage:String;
	var video:String;

	var validScore:Bool;
	var fifthKey:Bool;
	var modifyFPS:Bool;
	var colorMapping:Int;
	var fps:Int;

	//Player1
	var player1X:Float;
	var player1Y:Float;

	//Player2
	var player2X:Float;
	var player2Y:Float;
}

class Song
{
	public var song:String;
	public var notes:Array<SwagSection>;
	public var modifiers:Array<EventInfo>;	
	public var bpm:Int;
	public var needsVoices:Bool = true;
	public var speed:Float = 1;
	public var colorMapping:Int;
	public var modifyFPS:Bool;
	public var fps:Int;

	public var player1X:Float;
	public var player1Y:Float;

	public var player2X:Float;
	public var player2Y:Float;

	public var fifthKey:Bool;

	public function new(song, notes, bpm, fps)
	{
		this.song = song;
		this.notes = notes;
		this.bpm = bpm;
		this.fps = fps;
	}

	static function getChartFolder(?folder:String, ?jsonInput:String):String
	{
		var chartFolder:String = folder != null ? folder : jsonInput;
		return chartFolder != null ? chartFolder.toLowerCase().trim() : "";
	}

	static function getChartPath(chartName:String, folder:String):String
	{
		return Paths.getPath('data/' + folder + '/' + chartName.toLowerCase() + '.json', TEXT, null);
	}

	static function chartExists(chartName:String, folder:String):Bool
	{
		if (chartName == null || chartName.trim() == "" || folder == null || folder.trim() == "")
			return false;

		var chartPath:String = getChartPath(chartName, folder);
		return chartPath != null && chartPath != "" && OpenFlAssets.exists(chartPath, TEXT);
	}

	static function pushChartCandidate(candidates:Array<String>, chartName:String):Void
	{
		if (chartName == null)
			return;

		var resolvedName:String = chartName.toLowerCase().trim();

		if (resolvedName != "" && !candidates.contains(resolvedName))
			candidates.push(resolvedName);
	}

	static function resolveChartJsonInput(jsonInput:String, ?folder:String):String
	{
		var chartFolder:String = getChartFolder(folder, jsonInput);
		var requestedChart:String = jsonInput != null ? jsonInput.toLowerCase().trim() : chartFolder;
		var candidates:Array<String> = [];
		var hasExplicitDifficulty:Bool = requestedChart != chartFolder;

		pushChartCandidate(candidates, requestedChart);
		pushChartCandidate(candidates, chartFolder);

		if (!hasExplicitDifficulty || CoolUtil.difficultyArray.length == 1)
		{
			for (difficulty in CoolUtil.difficultyArray)
			{
				var difficultyName:String = difficulty.toLowerCase().trim();
				pushChartCandidate(candidates, difficultyName == "normal" ? chartFolder : chartFolder + "-" + difficultyName);
			}
		}

		for (candidate in candidates)
		{
			if (chartExists(candidate, chartFolder))
			{
				if (candidate != requestedChart)
					trace('Chart fallback: ' + requestedChart + ' -> ' + candidate);

				return candidate;
			}
		}

		throw 'Could not locate chart JSON for "' + chartFolder + '" (requested "' + requestedChart + '"). Tried: ' + candidates.join(", ");
	}

	public static function loadFromJson(jsonInput:String, ?folder:String, ?ifPlayState:Bool = true):SwagSong
	{
		var rawJson;
		var resolvedJsonInput:String = resolveChartJsonInput(jsonInput, folder);
		var chartFolder:String = getChartFolder(folder, jsonInput);
		var chartPath:String = getChartPath(resolvedJsonInput, chartFolder);
		var metadataRaw:String = loadCompanionMetadata(chartFolder, resolvedJsonInput);

		if(ifPlayState)
			rawJson = Assets.getText(chartPath).trim();
		else
			rawJson = Assets.getText(chartPath).trim();

		while (!rawJson.endsWith("}"))
		{
			rawJson = rawJson.substr(0, rawJson.length - 1);
			// LOL GOING THROUGH THE BULLSHIT TO CLEAN IDK WHATS STRANGE
		}

		return parseJSONshit(rawJson, chartFolder, resolvedJsonInput, metadataRaw);
	}

	public static function getRawJSON(jsonInput:String, ?folder:String):String {
		var resolvedJsonInput:String = resolveChartJsonInput(jsonInput, folder);
		var chartPath:String = getChartPath(resolvedJsonInput, getChartFolder(folder, jsonInput));
		return Assets.getText(chartPath).trim();
	}

	static function loadCompanionMetadata(chartFolder:String, chartName:String):Null<String>
	{
		if(chartFolder == null || chartFolder == "")
			return null;

		var metadataBases:Array<String> = [];
		var normalizedChartName:String = chartName != null ? chartName.toLowerCase().trim() : chartFolder;

		pushChartCandidate(metadataBases, chartFolder);
		pushChartCandidate(metadataBases, normalizedChartName);

		if(normalizedChartName.endsWith("-chart"))
			pushChartCandidate(metadataBases, normalizedChartName.substr(0, normalizedChartName.length - 6));

		for(base in metadataBases) {
			var metadataPath:String = Paths.getPath('data/' + chartFolder + '/' + base + '-metadata.json', TEXT, null);

			if(OpenFlAssets.exists(metadataPath, TEXT))
				return Assets.getText(metadataPath).trim();
		}

		return null;
	}

	public static function parseJSONshit(rawJson:String, ?chartFolder:String, ?chartName:String, ?metadataRaw:String):SwagSong
	{
		var parsed:Dynamic = Json.parse(rawJson);

		if(parsed == null)
			throw "Chart JSON was empty or invalid.";

		if(isWrappedLegacyChart(parsed))
			return finalizeSwagSong(cast Reflect.field(parsed, "song"), chartFolder);

		if(isTopLevelLegacyChart(parsed))
			return finalizeSwagSong(cast parsed, chartFolder);

		if(isVSliceChart(parsed))
			return parseVSliceChart(parsed, chartFolder, chartName, metadataRaw);

		throw "Unsupported chart format.";
	}

	static function isWrappedLegacyChart(parsed:Dynamic):Bool
	{
		var songData:Dynamic = Reflect.field(parsed, "song");
		return songData != null && Reflect.isObject(songData) && Std.isOfType(Reflect.field(songData, "notes"), Array);
	}

	static function isTopLevelLegacyChart(parsed:Dynamic):Bool
	{
		var notes:Dynamic = Reflect.field(parsed, "notes");
		return Std.isOfType(notes, Array) && !Reflect.isObject(Reflect.field(parsed, "song"));
	}

	static function isVSliceChart(parsed:Dynamic):Bool
	{
		var notes:Dynamic = Reflect.field(parsed, "notes");
		return notes != null && Reflect.isObject(notes) && !Std.isOfType(notes, Array) && Reflect.hasField(parsed, "events");
	}

	static function finalizeSwagSong(songData:SwagSong, ?chartFolder:String):SwagSong
	{
		ensureField(songData, "song", chartFolder != null && chartFolder != "" ? chartFolder : "unknown");
		ensureField(songData, "notes", []);
		ensureField(songData, "modifiers", []);
		ensureField(songData, "bpm", 100);
		ensureField(songData, "needsVoices", true);
		ensureField(songData, "speed", 1);
		ensureField(songData, "player1", "bf");
		ensureField(songData, "player2", "dad");
		ensureField(songData, "girlfriend", "gf");
		ensureField(songData, "stage", "stage");
		ensureField(songData, "video", null);
		ensureField(songData, "fifthKey", false);
		ensureField(songData, "modifyFPS", false);
		ensureField(songData, "colorMapping", 0);
		ensureField(songData, "fps", 100);
		ensureField(songData, "player1X", 0);
		ensureField(songData, "player1Y", 0);
		ensureField(songData, "player2X", 0);
		ensureField(songData, "player2Y", 0);
		songData.validScore = true;
		return songData;
	}

	static function ensureField(target:Dynamic, field:String, value:Dynamic):Void
	{
		if(target == null || field == null || field == "")
			return;

		if(!Reflect.hasField(target, field) || Reflect.field(target, field) == null)
			Reflect.setField(target, field, value);
	}

	static function parseVSliceChart(chartData:Dynamic, chartFolder:String, chartName:String, metadataRaw:String):SwagSong
	{
		var metadata:Dynamic = metadataRaw != null && metadataRaw.trim() != "" ? Json.parse(metadataRaw) : {};
		var availableNotes:Dynamic = Reflect.field(chartData, "notes");
		var events:Array<Dynamic> = cast readArray(chartData, "events");
		var selectedDifficulty:String = resolveVSliceDifficulty(availableNotes, chartFolder, chartName);
		var noteList:Array<Dynamic> = cast readDifficultyField(availableNotes, selectedDifficulty, []);
		var timeChanges:Array<VSliceTimeChange> = buildVSliceTimeChanges(metadata, chartData);
		var sections:Array<SwagSection> = buildSectionsFromVSlice(noteList, events, timeChanges);
		var scrollSpeed:Float = resolveVSliceScrollSpeed(chartData, selectedDifficulty);
		var songName:String = readString(metadata, "songName", chartFolder);
		var playData:Dynamic = readDynamic(metadata, "playData");
		var characters:Dynamic = readDynamic(playData, "characters");
		var stage:String = readString(playData, "stage", "stage");

		if(stage.toLowerCase().trim() == "mainstage")
			stage = "stage";

		var swagShit:SwagSong = {
			song: songName,
			notes: sections,
			modifiers: convertVSliceEvents(events, timeChanges),
			bpm: Std.int(Math.round(timeChanges[0].bpm)),
			needsVoices: true,
			speed: scrollSpeed,
			player1: readString(characters, "player", "bf"),
			player2: readString(characters, "opponent", "dad"),
			girlfriend: readString(characters, "girlfriend", "gf"),
			stage: stage,
			video: null,
			validScore: true,
			fifthKey: false,
			modifyFPS: false,
			colorMapping: 0,
			fps: 100,
			player1X: 0,
			player1Y: 0,
			player2X: 0,
			player2Y: 0
		};

		return finalizeSwagSong(swagShit, chartFolder);
	}

	static function resolveVSliceDifficulty(noteData:Dynamic, chartFolder:String, chartName:String):String
	{
		var requestedChart:String = chartName != null ? chartName.toLowerCase().trim() : chartFolder;
		var candidates:Array<String> = [];

		if(chartFolder != null && chartFolder != "" && requestedChart.startsWith(chartFolder + "-"))
			pushChartCandidate(candidates, requestedChart.substr(chartFolder.length + 1));

		for(difficulty in CoolUtil.difficultyArray)
			pushChartCandidate(candidates, difficulty.toLowerCase().trim());

		pushChartCandidate(candidates, "hard");
		pushChartCandidate(candidates, "normal");
		pushChartCandidate(candidates, "easy");

		for(candidate in candidates) {
			var resolved:Dynamic = readDifficultyField(noteData, candidate, null);

			if(resolved != null)
				return candidate;
		}

		var noteFields:Array<String> = Reflect.fields(noteData);
		return noteFields.length > 0 ? noteFields[0].toLowerCase().trim() : "normal";
	}

	static function resolveVSliceScrollSpeed(chartData:Dynamic, difficulty:String):Float
	{
		var scrollData:Dynamic = readDynamic(chartData, "scrollSpeed");

		if(scrollData == null)
			return 1;

		if(Std.isOfType(scrollData, Float) || Std.isOfType(scrollData, Int))
			return safeParseFloat(Std.string(scrollData), 1);

		return safeParseFloat(Std.string(readDifficultyField(scrollData, difficulty, 1)), 1);
	}

	static function buildVSliceTimeChanges(metadata:Dynamic, chartData:Dynamic):Array<VSliceTimeChange>
	{
		var results:Array<VSliceTimeChange> = [];
		var timeChanges:Array<Dynamic> = cast readArray(metadata, "timeChanges");
		var fallbackBpm:Float = safeParseFloat(Std.string(readDynamic(chartData, "bpm")), 100);

		for(change in timeChanges) {
			results.push({
				time: readFloat(change, "t", 0),
				bpm: readFloat(change, "bpm", fallbackBpm)
			});
		}

		if(results.length == 0)
			results.push({time: 0, bpm: fallbackBpm});

		results.sort(function(a:VSliceTimeChange, b:VSliceTimeChange):Int {
			return a.time < b.time ? -1 : (a.time > b.time ? 1 : 0);
		});

		if(results[0].time > 0)
			results.insert(0, {time: 0, bpm: results[0].bpm});

		return results;
	}

	static function buildSectionsFromVSlice(noteList:Array<Dynamic>, events:Array<Dynamic>, timeChanges:Array<VSliceTimeChange>):Array<SwagSection>
	{
		var maxStep:Float = 0;

		for(note in noteList) {
			var noteEndTime:Float = readFloat(note, "t", 0) + Math.max(0, readFloat(note, "l", 0));
			maxStep = Math.max(maxStep, timeToStep(noteEndTime, timeChanges));
		}

		for(event in events)
			maxStep = Math.max(maxStep, timeToStep(readFloat(event, "t", 0), timeChanges));

		var sectionCount:Int = Std.int(Math.max(1, Math.floor(maxStep / 16) + 1));
		var playerCounts:Array<Int> = [];
		var opponentCounts:Array<Int> = [];
		var focusOverrides:Array<Null<Bool>> = [];
		var sections:Array<SwagSection> = [];

		for(i in 0...sectionCount) {
			playerCounts.push(0);
			opponentCounts.push(0);
			focusOverrides.push(null);
		}

		for(note in noteList) {
			var sectionIndex:Int = getSectionIndexForTime(readFloat(note, "t", 0), timeChanges, sectionCount);
			var absoluteData:Int = readInt(note, "d", 0);

			if(absoluteData >= 4)
				opponentCounts[sectionIndex]++;
			else
				playerCounts[sectionIndex]++;
		}

		for(event in events) {
			var eventKind:String = readString(event, "e", "");

			if(eventKind.toLowerCase().trim() != "focuscamera")
				continue;

			var payload:Dynamic = readDynamic(event, "v");
			var target:Int = readInt(payload, "char", 0);
			var sectionIndex:Int = getSectionIndexForTime(readFloat(event, "t", 0), timeChanges, sectionCount);

			switch(target) {
				case 0:
					focusOverrides[sectionIndex] = true;
				case 1:
					focusOverrides[sectionIndex] = false;
			}
		}

		var currentMustHit:Bool = playerCounts[0] >= opponentCounts[0];
		var previousBpm:Float = -1;

		for(sectionIndex in 0...sectionCount) {
			if(focusOverrides[sectionIndex] != null)
				currentMustHit = focusOverrides[sectionIndex];
			else if(playerCounts[sectionIndex] != opponentCounts[sectionIndex])
				currentMustHit = playerCounts[sectionIndex] >= opponentCounts[sectionIndex];

			var sectionStartStep:Float = sectionIndex * 16;
			var bpmAtSection:Float = getBpmAtStep(sectionStartStep, timeChanges);

			sections.push({
				sectionNotes: [],
				lengthInSteps: 16,
				mustHitSection: currentMustHit,
				bpm: Std.int(Math.round(bpmAtSection)),
				changeBPM: sectionIndex > 0 && bpmAtSection != previousBpm,
				altAnim: false
			});

			previousBpm = bpmAtSection;
		}

		for(note in noteList) {
			var noteTime:Float = readFloat(note, "t", 0);
			var sectionIndex:Int = getSectionIndexForTime(noteTime, timeChanges, sectionCount);
			var absoluteData:Int = readInt(note, "d", 0);
			var convertedData:Int = convertVSliceNoteData(absoluteData, sections[sectionIndex].mustHitSection);
			var length:Float = Math.max(0, readFloat(note, "l", 0));
			var kind:Null<String> = readNullableString(note, "k");
			var noteEntry:Array<Dynamic> = [noteTime, convertedData, length, kind];
			sections[sectionIndex].sectionNotes.push(noteEntry);
		}

		for(section in sections) {
			section.sectionNotes.sort(function(a:Dynamic, b:Dynamic):Int {
				var aTime:Float = a[0];
				var bTime:Float = b[0];
				return aTime < bTime ? -1 : (aTime > bTime ? 1 : 0);
			});
		}

		return sections;
	}

	static function convertVSliceEvents(events:Array<Dynamic>, timeChanges:Array<VSliceTimeChange>):Array<EventInfo>
	{
		var converted:Array<EventInfo> = [];

		for(event in events) {
			var eventKind:String = readString(event, "e", "");

			if(eventKind == null || eventKind.trim() == "")
				continue;

			var payload:Dynamic = readDynamic(event, "v");
			var step:Int = Std.int(Math.round(timeToStep(readFloat(event, "t", 0), timeChanges)));

			converted.push({
				modSkill: "v-slice event",
				modGridY: step * 40,
				modValue: eventKind,
				modValueTwo: payload == null ? "" : Json.stringify(payload),
				modDisplayName: eventKind
			});
		}

		converted.sort(function(a:EventInfo, b:EventInfo):Int {
			return a.modGridY < b.modGridY ? -1 : (a.modGridY > b.modGridY ? 1 : 0);
		});

		return converted;
	}

	static function convertVSliceNoteData(absoluteData:Int, mustHitSection:Bool):Int
	{
		var laneCount:Int = 4;
		var normalizedData:Int = absoluteData;

		if(normalizedData < 0)
			normalizedData = 0;
		else if(normalizedData >= laneCount * 2)
			normalizedData = normalizedData % (laneCount * 2);

		if(mustHitSection)
			return normalizedData;

		return normalizedData >= laneCount ? normalizedData - laneCount : normalizedData + laneCount;
	}

	static function getSectionIndexForTime(time:Float, timeChanges:Array<VSliceTimeChange>, sectionCount:Int):Int
	{
		var step:Float = timeToStep(time, timeChanges);
		var index:Int = Std.int(Math.floor(step / 16));
		return Std.int(Math.max(0, Math.min(sectionCount - 1, index)));
	}

	static function getBpmAtStep(step:Float, timeChanges:Array<VSliceTimeChange>):Float
	{
		var currentBpm:Float = timeChanges[0].bpm;

		for(change in timeChanges) {
			var changeStep:Float = timeToStep(change.time, timeChanges);

			if(changeStep <= step)
				currentBpm = change.bpm;
			else
				break;
		}

		return currentBpm;
	}

	static function timeToStep(time:Float, timeChanges:Array<VSliceTimeChange>):Float
	{
		if(timeChanges.length == 0)
			return 0;

		var clampedTime:Float = Math.max(0, time);
		var totalSteps:Float = 0;
		var currentTime:Float = timeChanges[0].time;
		var currentBpm:Float = timeChanges[0].bpm;

		if(clampedTime < currentTime)
			return 0;

		for(i in 1...timeChanges.length) {
			var nextChange:VSliceTimeChange = timeChanges[i];

			if(clampedTime < nextChange.time)
				break;

			totalSteps += msToSteps(nextChange.time - currentTime, currentBpm);
			currentTime = nextChange.time;
			currentBpm = nextChange.bpm;
		}

		totalSteps += msToSteps(clampedTime - currentTime, currentBpm);
		return totalSteps;
	}

	static function msToSteps(durationMs:Float, bpm:Float):Float
	{
		if(bpm <= 0)
			return 0;

		return durationMs / (((60 / bpm) * 1000) / 4);
	}

	static function readArray(payload:Dynamic, field:String):Array<Dynamic>
	{
		var value:Dynamic = readDynamic(payload, field);
		return Std.isOfType(value, Array) ? cast value : [];
	}

	static function readDifficultyField(payload:Dynamic, difficulty:String, fallback:Dynamic):Dynamic
	{
		if(payload == null)
			return fallback;

		for(field in Reflect.fields(payload)) {
			if(field.toLowerCase().trim() == difficulty.toLowerCase().trim())
				return Reflect.field(payload, field);
		}

		return fallback;
	}

	static function readDynamic(payload:Dynamic, field:String):Dynamic
	{
		if(payload == null || field == null || field == "")
			return null;

		try {
			if(Reflect.hasField(payload, field))
				return Reflect.field(payload, field);
		}catch(e:Dynamic) {}

		return null;
	}

	static function readString(payload:Dynamic, field:String, fallback:String):String
	{
		var value:Dynamic = readDynamic(payload, field);
		return value == null ? fallback : Std.string(value);
	}

	static function readNullableString(payload:Dynamic, field:String):Null<String>
	{
		var value:Dynamic = readDynamic(payload, field);

		if(value == null)
			return null;

		var text:String = Std.string(value);
		return text.trim() == "" ? null : text;
	}

	static function readFloat(payload:Dynamic, field:String, fallback:Float):Float
	{
		var value:Dynamic = readDynamic(payload, field);
		return value == null ? fallback : safeParseFloat(Std.string(value), fallback);
	}

	static function readInt(payload:Dynamic, field:String, fallback:Int):Int
	{
		var value:Dynamic = readDynamic(payload, field);
		return value == null ? fallback : safeParseInt(Std.string(value), fallback);
	}

	static function safeParseFloat(value:String, fallback:Float):Float
	{
		var parsed:Float = Std.parseFloat(value);
		return Math.isNaN(parsed) ? fallback : parsed;
	}

	static function safeParseInt(value:String, fallback:Int):Int
	{
		var parsed:Null<Int> = Std.parseInt(value);
		return parsed == null ? fallback : parsed;
	}
}

private typedef VSliceTimeChange = {
	var time:Float;
	var bpm:Float;
}
