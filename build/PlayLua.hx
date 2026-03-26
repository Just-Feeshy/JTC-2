package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;
import openfl.Lib;

import SaveData.SaveType;

using StringTools;

@:access(PlayState)
class PlayLua
{
	private var playState:PlayState;
	private var ownedLua:ModLua;
	private var luaDetachedForStateSwitch:Bool = false;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function hasScript():Bool
	{
		#if (USING_LUA && cpp)
		return !luaDetachedForStateSwitch && getLua() != null;
		#else
		return false;
		#end
	}

	public function getLua():ModLua
	{
		#if (USING_LUA && cpp)
		if(ownedLua != null)
			return ownedLua;
		#end

		return playState != null ? playState.getModLua() : null;
	}

	public function getSprite(name:String):FlxSprite
	{
		if(name == null || name.trim() == "")
			return null;

		var lua:ModLua = getLua();
		return lua != null ? lua.getSprite(name) : null;
	}

	public function call(name:String, args:Array<Dynamic>):Dynamic
	{
		return hasScript() ? playState.callLua(name, args) : null;
	}

	public function set(variable:String, data:Dynamic):Void
	{
		if(hasScript())
			playState.setLua(variable, data);
	}

	public function addToNoteAngle(daAngle:Float, note:Note):Float
	{
		var xLua:Null<Float> = cast call("addToNoteAngle", [daAngle, note.caculatePos, note.strumTime, note.noteData, note.tag, note.noteAbstract, note.isSustainNote]);
		var finalLuaVar:Float = daAngle;

		if(xLua != null)
			finalLuaVar = xLua + daAngle;

		return finalLuaVar;
	}

	public function loadScript():Void
	{
		#if (USING_LUA && cpp)
		Register.detachLuaFromState(PlayState);

		var songScript:String = "song/" + CoolUtil.readableSongDirectory(PlayState.SONG.song.toLowerCase());
		var stageScript:String = "stage/" + PlayState.curStage.toLowerCase();
		var scriptPath:String = null;

		if(Paths.assetExists(Paths.getPath('scripts/${songScript}.lua', TEXT, null), TEXT)) {
			scriptPath = songScript;
		}else if(Paths.assetExists(Paths.getPath('scripts/${stageScript}.lua', TEXT, null), TEXT)) {
			scriptPath = stageScript;
		}

		ownedLua = null;
		luaDetachedForStateSwitch = false;

		if(scriptPath != null) {
			Register.attachLuaToState(PlayState, Paths.lua(scriptPath));
			ownedLua = playState.getModLua();

			if(ownedLua != null)
				ownedLua.execute();
		}
		#end
	}

	public function generateStaticBindings():Void
	{
		#if (USING_LUA && cpp)
		if(!hasScript())
			return;

		playState.modifiableSprites.set("iconP1", playState.iconP1);
		playState.modifiableSprites.set("iconP2", playState.iconP2);
		playState.modifiableSprites.set("healthBarBG", playState.healthBarBG);
		playState.modifiableSprites.set("healthBar", playState.healthBar);

		playState.modifiableCharacters.set("boyfriend", playState.boyfriend);
		playState.modifiableCharacters.set("gf", playState.gf);
		playState.modifiableCharacters.set("dad", playState.dad);

		playState.modifiableCameras.set("camHUD", playState.ownedCamHUD);
		playState.modifiableCameras.set("camGAME", FlxG.camera);
		playState.modifiableCameras.set("camNOTE", playState.ownedCamNOTE);
		playState.modifiableCameras.set("camNoteSustain", playState.ownedCamNoteSustain);

		set("songName", PlayState.SONG.song);
		set("isStoryMode", PlayState.isStoryMode);
		set("startedCountdown", false);
		set("difficulty", PlayState.storyDifficulty);
		set("difficultyName", CoolUtil.getDifficultyName(PlayState.storyDifficulty));
		set("week", Paths.modJSON.weeks.get("week_" + PlayState.storyWeek).week_name.toUpperCase());
		set("weekRaw", PlayState.storyWeek);
		set("hasCutscene", PlayState.SONG.video != null ? true : false);
		set("inGameOver", false);

		set("defaultBoyfriendX", playState.boyfriend.x);
		set("defaultBoyfriendY", playState.boyfriend.y);
		set("defaultOpponentX", playState.dad.x);
		set("defaultOpponentY", playState.dad.y);

		if(playState.gf != null) {
			set("defaultGirlfriendX", playState.gf.x);
			set("defaultGirlfriendY", playState.gf.y);
		}else {
			set("defaultGirlfriendX", 0);
			set("defaultGirlfriendY", 0);
		}

		playState.addCallback("checkKeyStatus", function(key:Int, status:Int) {
			return FlxG.keys.checkStatus(key, status);
		});

		playState.addCallback("freezeOrUnfreezeGame", function() {
			playState.haveGamePaused();
		});

		playState.addCallback("setEndVideo", function(path:String) {
			playState.videoSwitchState = Paths.video(path);
		});

		playState.addCallback("setGameplayCameraFocus", function(x:Float, y:Float, snap:Bool = true) {
			playState.setScriptedCameraFocus(x, y, snap);
		});

		playState.addCallback("clearGameplayCameraFocus", function(snap:Bool = true) {
			playState.clearScriptedCameraFocus(snap);
		});

		playState.addCallback("setGameplayCameraZoom", function(zoom:Float, direct:Bool = true, snap:Bool = true) {
			playState.setScriptedCameraZoom(zoom, direct, snap);
		});

		playState.addCallback("clearGameplayCameraZoom", function(snap:Bool = true) {
			playState.clearScriptedCameraZoom(snap);
		});

		playState.addCallback("focusGameplayCameraOnSprite", function(name:String, zoom:Float = 1, anchorX:Float = 0.5, anchorY:Float = 0.5,
			offsetX:Float = 0, offsetY:Float = 0, direct:Bool = true, snap:Bool = true) {
			return playState.focusGameplayCameraOnSprite(name, zoom, anchorX, anchorY, offsetX, offsetY, direct, snap);
		});

		playState.addCallback("callEvent", function(skill:String, value:String, value2:String) {
			playState.events.whenTriggered(skill, value, value2, playState);
			playState.event_Extra(skill, value, value2);
		});

		playState.addCallback("addSongTrack", function(tag:String, fileName:String, side:String = "extra", volume:Float = 1,
			looped:Bool = false, tagFilterList:String = "") {
			return playState.addSongTrack(tag, fileName, side, volume, looped, playState.normalizeSongTrackFilters(tagFilterList));
		});

		playState.addCallback("removeSongTrack", function(tag:String) {
			playState.destroySongTrack(tag);
		});

		playState.addCallback("hasSongTrack", function(tag:String) {
			return playState.syncedSongTrackMap.exists(tag);
		});

		playState.addCallback("setSongTrackBaseVolume", function(tag:String, volume:Float) {
			var track = playState.syncedSongTrackMap.get(tag);

			if(track == null)
				return false;

			track.baseVolume = volume;
			playState.applySongTrackVolume(track);
			return true;
		});

		playState.addCallback("instaKillPlayer", function() {
			playState.gameOverScreen();
		});

		playState.addCallback("createCharacterSprite", function(name:String, characterName:String, x:Float, y:Float, isPlayer:Bool = false) {
			if(playState.modifiableCharacters.exists(name))
				return;

			var characterSprite:Character = new Character(x, y, characterName, isPlayer);
			characterSprite.refresh(characterName, playState.camPos);
			characterSprite.active = true;

			playState.modifiableCharacters.set(name, characterSprite);
		});

		playState.addCallback("createCharacterSpriteNFA", function(name:String, characterName:String, x:Float, y:Float, isPlayer:Bool = false) {
			if(playState.modifiableCharacters.exists(name))
				return;

			var characterSprite:Character = new Character(x, y, characterName, isPlayer, null, false);
			characterSprite.refresh(characterName, playState.camPos);
			characterSprite.active = true;

			playState.modifiableCharacters.set(name, characterSprite);
		});

		playState.addCallback("characterDance", function(name:String) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null)
				return false;

			character.dance();
			return true;
		});

		playState.addCallback("setCharacterHoldTimer", function(name:String, value:Float) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character != null)
				character.holdTimer = value;
		});

		playState.addCallback("getCharacterIsPlayer", function(name:String) {
			var character:Character = playState.modifiableCharacters.get(name);
			return character != null ? character.isPlayer : false;
		});

		playState.addCallback("getCharacterDancing", function(name:String) {
			var character:Character = playState.modifiableCharacters.get(name);
			return character != null ? character.dancing : false;
		});

		playState.addCallback("getCharacterStunned", function(name:String) {
			var character:Character = playState.modifiableCharacters.get(name);
			return character != null ? character.stunned : false;
		});

		playState.addCallback("getCharacterHoldTimer", function(name:String) {
			var character:Character = playState.modifiableCharacters.get(name);
			return character != null ? character.holdTimer : 0;
		});

		playState.addCallback("getSpriteIndexFromStage", function(name:String) {
			var spr:FlxSprite = getSprite(name);
			return spr != null ? playState.stage.members.indexOf(spr) : -1;
		});

		playState.addCallback("insertSpriteToStage", function(position:Int, name:String) {
			var spr:FlxSprite = getSprite(name);

			if(spr != null)
				playState.stage.insert(position, spr);
		});

		playState.addCallback("addSpriteToStage", function(name:String) {
			var spr:FlxSprite = getSprite(name);

			if(spr != null)
				playState.stage.add(spr);
		});

		playState.addCallback("removeSpriteFromStage", function(name:String) {
			var spr:FlxSprite = getSprite(name);

			if(spr != null)
				playState.stage.remove(spr);
		});

		playState.addCallback("setHealthBarColors", function(opponentHex:String, playerHex:String) {
			var opponentColor:FlxColor = !opponentHex.startsWith("0x") ? Std.parseInt('0xff' + opponentHex) : Std.parseInt(opponentHex);
			var playerColor:FlxColor = !playerHex.startsWith("0x") ? Std.parseInt('0x' + playerHex) : Std.parseInt(playerHex);
			playState.healthBar.createFilledBar(opponentColor, playerColor);
		});

		playState.addCallback("doTweenHealthBarColor", function(name:String, side:String, hex:String, duration:Float, ease:String) {
			var barColor:FlxColor = !hex.startsWith("0x") ? Std.parseInt('0xff' + hex) : Std.parseInt(hex);
			var lua:ModLua = getLua();

			if(lua == null)
				return;

			if(side == "left" || side == "opponent") {
				lua.luaTweens.set(name, FlxTween.color(playState.healthBar.emptyBar, duration, playState.healthBar.emptyColor, barColor, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
						lua.luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}

			if(side == "right" || side == "player") {
				lua.luaTweens.set(name, FlxTween.color(playState.healthBar.filledBar, duration, playState.healthBar.filledColor, barColor, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
						lua.luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
			}
		});

		playState.addCallback("setHealthBarColor", function(hex:String, side:String) {
			var hexColor:FlxColor = !hex.startsWith("0x") ? Std.parseInt('0xff' + hex) : Std.parseInt(hex);

			if(side == "left" || side == "opponent")
				playState.healthBar.emptyColor = hexColor;

			if(side == "right" || side == "player")
				playState.healthBar.filledColor = hexColor;
		});

		playState.addCallback("disableInputs", function(disable:Bool) {
			playState.disableInputs = disable;
		});
		#end
	}

	public function generateNoteBindings():Void
	{
		#if (USING_LUA && cpp)
		if(!hasScript())
			return;

		for(i in 0...PlayState.playerStrums.members.length) {
			set('defaultPlayerStrumX' + i, PlayState.playerStrums.members[i].x);
			set('defaultPlayerStrumY' + i, PlayState.playerStrums.members[i].y);
			set('defaultPlayerStrumWidth' + i, PlayState.playerStrums.members[i].scale.x);
			set('defaultPlayerStrumHeight' + i, PlayState.playerStrums.members[i].scale.y);
		}

		for(i in 0...PlayState.opponentStrums.members.length) {
			set('defaultOpponentStrumX' + i, PlayState.opponentStrums.members[i].x);
			set('defaultOpponentStrumY' + i, PlayState.opponentStrums.members[i].y);
			set('defaultOpponentStrumWidth' + i, PlayState.opponentStrums.members[i].scale.x);
			set('defaultOpponentStrumHeight' + i, PlayState.opponentStrums.members[i].scale.y);
		}

		playState.addCallback("setNoteStrumPos", function(id:Int, x:Float, y:Float) {
			var strumOBJ:Strum = playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length];
			strumOBJ.x = x;
			strumOBJ.y = y;
		});

		playState.addCallback("setNoteStrumAngleX", function(id:Int, angle:Float) {
			playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].xAngle = angle;
		});

		playState.addCallback("setNoteStrumAngleY", function(id:Int, angle:Float) {
			playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].yAngle = angle;
		});

		playState.addCallback("setNoteStrumAngleZ", function(id:Int, angle:Float) {
			playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].angle = angle;
		});

		playState.addCallback("setNoteStrumAngle", function(id:Int, angle:Float) {
			playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].angle = angle;
		});

		playState.addCallback("setNoteDirection", function(id:Int, angle:Float) {
			playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].directionAngle = angle;
		});

		playState.addCallback("setNoteAlpha", function(id:Int, alpha:Float) {
			playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].alpha = alpha;
		});

		playState.addCallback("setNoteScale", function(id:Int, x:Float, y:Float, shouldUpdateHitbox:Bool = true) {
			var strumOBJ:Strum = playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length];
			strumOBJ.scale.set(x, y);

			if(shouldUpdateHitbox)
				strumOBJ.updateHitbox();
		});

		playState.addCallback("getNoteStrumAngleX", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].xAngle;
		});

		playState.addCallback("getNoteStrumAngleY", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].yAngle;
		});

		playState.addCallback("getNoteStrumAngleZ", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].angle;
		});

		playState.addCallback("getNoteStrumAngle", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].angle;
		});

		playState.addCallback("getNoteDirection", function(id:Int, angle:Float) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].directionAngle;
		});

		playState.addCallback("getNoteScaleX", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].scale.x;
		});

		playState.addCallback("getNoteScaleY", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].scale.y;
		});

		playState.addCallback("getNotePosX", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].x;
		});

		playState.addCallback("getNotePosY", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].y;
		});

		playState.addCallback("getNoteAlpha", function(id:Int) {
			return playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length].alpha;
		});

		playState.addCallback("getNoteScreenCenter", function(id:Int, ?axis:String) {
			var strumOBJ:Strum = playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length];

			switch(axis.toLowerCase()) {
				case "x": return strumOBJ.getScreenCenter(X);
				case "y": return strumOBJ.getScreenCenter(Y);
			}

			return 0;
		});

		registerNoteTweenCallback("noteTweenX", function(strumOBJ:Strum, value:Dynamic) return {x: value});
		registerNoteTweenCallback("noteTweenY", function(strumOBJ:Strum, value:Dynamic) return {y: value});
		registerNoteTweenCallback("noteTweenAngle", function(strumOBJ:Strum, value:Dynamic) return {angle: value});
		registerNoteTweenCallback("noteTweenAngleX", function(strumOBJ:Strum, value:Dynamic) return {xAngle: value});
		registerNoteTweenCallback("noteTweenAngleY", function(strumOBJ:Strum, value:Dynamic) return {yAngle: value});
		registerNoteTweenCallback("noteTweenAngleZ", function(strumOBJ:Strum, value:Dynamic) return {angle: value});
		registerNoteTweenCallback("noteTweenDirection", function(strumOBJ:Strum, value:Dynamic) return {directionAngle: value});
		registerNoteTweenCallback("noteTweenAlpha", function(strumOBJ:Strum, value:Dynamic) return {alpha: value});

		playState.addCallback("noteTweenScale", function(name:String, id:Int, value1:Float, value2:Float, duration:Float, ease:String) {
			var strumOBJ:Strum = playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length];
			var lua:ModLua = getLua();

			if(strumOBJ == null || lua == null)
				return;

			lua.luaTweens.set(name, FlxTween.tween(strumOBJ.scale, {x: value1, y: value2}, duration, {ease: Register.getFlxEaseByString(ease),
				onComplete: function(twn:FlxTween) {
					lua.luaTweens.remove(name);
					call('onTweenCompleted', [name]);
				}
			}));
		});
		#end
	}

	private function registerNoteTweenCallback(name:String, buildProps:Dynamic):Void
	{
		playState.addCallback(name, function(tweenName:String, id:Int, value:Dynamic, duration:Float, ease:String) {
			var strumOBJ:Strum = playState.strumLineNotes.members[Std.int(Math.abs(id)) % playState.strumLineNotes.length];
			var lua:ModLua = getLua();

			if(strumOBJ == null || lua == null)
				return;

			lua.luaTweens.set(tweenName, FlxTween.tween(strumOBJ, buildProps(strumOBJ, value), duration, {ease: Register.getFlxEaseByString(ease),
				onComplete: function(twn:FlxTween) {
					lua.luaTweens.remove(tweenName);
					call('onTweenCompleted', [tweenName]);
				}
			}));
		});
	}

	public function updateDynamicVars():Void
	{
		if(!hasScript())
			return;

		set('cameraX', playState.camFollow.x);
		set('cameraY', playState.camFollow.y);

		set("score", playState.songScore);
		set("misses", playState.misses);
		set("hits", playState.hits);

		set("boyfriendName", playState.boyfriend.curCharacter);
		set("dadName", playState.dad.curCharacter);
		set("gfName", playState.gf != null ? playState.gf.curCharacter : "");

		set('downscroll', SaveData.getData(DOWNSCROLL));
		set('framerate', Lib.current.stage.frameRate);
		set('ghostTapping', GhostTapping.ghostTap);
		set("songLength", FlxG.sound.music.length);
		set("trackPos", Conductor.trackPosition);

		set("iconP1_ID_Regular", playState.iconP1.iconAnimInfo[0]);
		set("iconP2_ID_Regular", playState.iconP2.iconAnimInfo[0]);
		set("iconP1_ID_Dead", playState.iconP1.iconAnimInfo[1]);
		set("iconP2_ID_Dead", playState.iconP2.iconAnimInfo[1]);
		set("iconP1_ID_Winning", playState.iconP1.iconAnimInfo[2]);
		set("iconP2_ID_Winning", playState.iconP2.iconAnimInfo[2]);
	}

	public function updatePerSectionVars():Void
	{
		if(!hasScript())
			return;

		set("bpm", PlayState.SONG.bpm);
		set("scrollspeed", PlayState.SONG.speed);
		set("mustHitSection", PlayState.SONG.notes[Std.int(playState.curStep / 16)].mustHitSection);
		set("altAnim", PlayState.SONG.notes[Math.floor(playState.curStep / 16)].altAnim);
	}

	public function prepareForStateSwitch():Void
	{
		var stateLua:ModLua = ownedLua;

		if(!luaDetachedForStateSwitch && stateLua != null) {
			if(HelperStates.luaExist(PlayState) && HelperStates.getLua(PlayState) == stateLua) {
				Register.detachLuaFromState(PlayState);
			}else {
				stateLua.close();
			}

			luaDetachedForStateSwitch = true;
		}
	}

	public function destroy():Void
	{
		var stateLua:ModLua = ownedLua;

		if(!luaDetachedForStateSwitch && stateLua != null) {
			if(HelperStates.luaExist(PlayState) && HelperStates.getLua(PlayState) == stateLua) {
				Register.detachLuaFromState(PlayState);
			}else {
				stateLua.close();
			}
		}

		ownedLua = null;
		playState = null;
		luaDetachedForStateSwitch = true;
	}
}
