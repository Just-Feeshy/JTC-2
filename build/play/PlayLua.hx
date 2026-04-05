package play;

import Section.SwagSection;
import CoolUtil;
import HealthIcon;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.tweens.FlxTween;
import flixel.util.FlxColor;
import openfl.Lib;
import play.DeathCharacter;

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

	public inline function hasScript():Bool
	{
		#if (USING_LUA && cpp)
		return !luaDetachedForStateSwitch && ownedLua != null;
		#else
		return false;
		#end
	}

	public inline function getOwnedLua():ModLua
	{
		return ownedLua;
	}

	public inline function releaseSongCacheImages(song:String):Void {
		#if (USING_LUA && cpp)
		if(!hasScript()) {
			Cache.releaseSongCacheImages(song);
		}
		#else
		Cache.releaseSongCacheImages(song);
		#end
	}

	public function getLua():ModLua
	{
		return ownedLua;
	}

	public function getSprite(name:String):FlxSprite
	{
		if(name == null || name.trim() == "")
			return null;

		var lua:ModLua = getLua();
		return lua != null ? lua.getSprite(name) : null;
	}

	public function resumeLuaSpriteAnimations():Void
	{
		#if (USING_LUA && cpp)
		var lua:ModLua = getLua();

		if(lua != null) {
			lua.resumeLuaSpriteAnimations();
		}
		#end
	}

	public function pauseLuaSpriteAnimations():Void
	{
		#if (USING_LUA && cpp)
		var lua:ModLua = getLua();

		if(lua != null) {
			lua.pauseLuaSpriteAnimations();
		}
		#end
	}

	public function pauseLuaTweens():Void
	{
		#if (USING_LUA && cpp)
		var lua:ModLua = getLua();

		if(lua != null) {
			lua.pauseLuaTweens();
		}
		#end
	}

	public function resumeLuaTweens():Void
	{
		#if (USING_LUA && cpp)
		var lua:ModLua = getLua();

		if(lua != null) {
			lua.resumeLuaTweens();
		}
		#end
	}

	public function call(name:String, args:Array<Dynamic>):Dynamic
	{
		var lua:ModLua = getLua();
		return lua != null && !luaDetachedForStateSwitch ? lua.call(name, args) : null;
	}

	public function set(variable:String, data:Dynamic):Void
	{
		var lua:ModLua = getLua();
		if(lua != null && !luaDetachedForStateSwitch)
			lua.set(variable, data);
	}

	public function resetElapsed():Void
	{
		set("curElapsed", 0);
	}

	public function syncResumeState():Void
	{
		updateDynamicVars();
		updatePerSectionVars();
	}

	public function syncDefaultCharacterPositions():Void
	{
		if(playState == null)
			return;

		if(playState.boyfriend != null) {
			set("defaultBoyfriendX", playState.boyfriend.x);
			set("defaultBoyfriendY", playState.boyfriend.y);
		}

		if(playState.dad != null) {
			set("defaultOpponentX", playState.dad.x);
			set("defaultOpponentY", playState.dad.y);
		}

		if(playState.gf != null) {
			set("defaultGirlfriendX", playState.gf.x);
			set("defaultGirlfriendY", playState.gf.y);
		} else {
			set("defaultGirlfriendX", 0);
			set("defaultGirlfriendY", 0);
		}
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
		var scriptPath:String = resolveScriptKey();

		if(ownedLua != null) {
			ownedLua.close();
		}

		ownedLua = null;
		luaDetachedForStateSwitch = false;

		if(scriptPath != null) {
			attachScript(scriptPath);
		}
		#end
	}

	public function reloadScriptForSongRestart():Void
	{
		#if (USING_LUA && cpp)
		var scriptPath:String = resolveScriptKey();

		if(scriptPath == null) {
			return;
		}

		if(ownedLua != null) {
			ownedLua.close();
		}

		ownedLua = new ModLua(Paths.lua(scriptPath));
		ownedLua.stateOwnsCreatedObjects = true;
		luaDetachedForStateSwitch = false;

		if(ownedLua != null) {
			ownedLua.execute();
			generateStaticBindings();
			generateNoteBindings();
			updateDynamicVars();
			updatePerSectionVars();
			set("curElapsed", 0);
			set("curTicks", FlxG.game.ticks);
			call("onCreate", []);
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
		set("isInCountdown", false);
		set("startTimestamp", playState.startTimestamp);
		set("countdownStep", Countdown.stepToString(Countdown.countdownStep));
		set("countdownStepInt", Countdown.stepToInt(Countdown.countdownStep));
		set("difficulty", PlayState.storyDifficulty);
		set("difficultyName", CoolUtil.getDifficultyName(PlayState.storyDifficulty));
		set("week", Paths.modJSON.weeks.get("week_" + PlayState.storyWeek).week_name.toUpperCase());
		set("weekRaw", PlayState.storyWeek);
		set("hasCutscene", PlayState.SONG.video != null ? true : false);
		set("inGameOver", false);

		syncDefaultCharacterPositions();

		playState.addCallback("checkKeyStatus", function(key:Int, status:Int) {
			return FlxG.keys.checkStatus(key, status);
		});

		playState.addCallback("freezeOrUnfreezeGame", function() {
			playState.haveGamePaused();
		});

		playState.addCallback("performCountdown", function() {
			return Countdown.performCountdown();
		});

		playState.addCallback("pauseCountdown", function() {
			Countdown.pauseCountdown();
		});

		playState.addCallback("resumeCountdown", function() {
			Countdown.resumeCountdown();
		});

		playState.addCallback("stopCountdown", function() {
			Countdown.stopCountdown();
		});

		playState.addCallback("skipCountdown", function() {
			Countdown.skipCountdown();
		});

		playState.addCallback("resetCountdown", function() {
			Countdown.resetCountdown();
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

			playState.addCallback("setGameplayCameraFocusLerp", function(lerp:Float) {
				playState.setScriptedCameraFocusLerp(lerp);
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

		playState.addCallback("destroySongTrack", function(tag:String) {
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

		playState.addCallback("setGameOverAnimationSuffix", function(suffix:String = "") {
			GameOverSubstate.animationSuffix = suffix != null ? suffix : "";
		});

		playState.addCallback("setGameOverCharacter", function(character:String = "", animation:String = "") {
			GameOverSubstate.characterName = character != null ? character.trim() : "";
			GameOverSubstate.deathAnimationName = animation != null ? animation.trim() : "";
		});

		playState.addCallback("setGameOverDeathAnimation", function(animation:String = "") {
			GameOverSubstate.deathAnimationName = animation != null ? animation.trim() : "";
		});

		playState.addCallback("setGameOverMusicSuffix", function(suffix:String = "") {
			GameOverSubstate.musicSuffix = suffix != null ? suffix : "";
		});

		playState.addCallback("setGameOverBlueBallSuffix", function(suffix:String = "") {
			GameOverSubstate.blueBallSuffix = suffix != null ? suffix : "";
		});

		playState.addCallback("setGameOverSuffixes", function(animation:String = "", music:String = "", blueBall:String = "") {
			GameOverSubstate.animationSuffix = animation != null ? animation : "";
			GameOverSubstate.musicSuffix = music != null ? music : "";
			GameOverSubstate.blueBallSuffix = blueBall != null ? blueBall : "";
		});

		playState.addCallback("resetGameOverConfig", function() {
			GameOverSubstate.reset();
		});

		playState.addCallback("createCharacterSprite", function(name:String, characterName:String, x:Float, y:Float, isPlayer:Bool = false) {
			if(playState.modifiableCharacters.exists(name))
				return;

			var characterSprite:Character = new Character(x, y, characterName, isPlayer);
			characterSprite.refresh(characterName, playState.camPos);
			characterSprite.active = true;

			playState.modifiableCharacters.set(name, characterSprite);
		});

		playState.addCallback("makeCharacter", function(name:String, characterName:String, x:Float, y:Float, isPlayer:Bool = false) {
			if(playState.modifiableCharacters.exists(name))
				return false;

			var characterSprite:Character = new Character(x, y, characterName, isPlayer);
			characterSprite.refresh(characterName, playState.camPos);
			characterSprite.active = true;

			playState.modifiableCharacters.set(name, characterSprite);
			return true;
		});

		playState.addCallback("createCharacterSpriteNFA", function(name:String, characterName:String, x:Float, y:Float, isPlayer:Bool = false) {
			if(playState.modifiableCharacters.exists(name))
				return;

			var characterSprite:Character = new Character(x, y, characterName, isPlayer, null, false);
			characterSprite.refresh(characterName, playState.camPos);
			characterSprite.active = true;

			playState.modifiableCharacters.set(name, characterSprite);
		});

		playState.addCallback("setCharacterAnimOffset", function(name:String, animation:String, x:Float, y:Float) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null || animation == null) {
				return false;
			}

			character.addOffset(animation, x, y);
			return true;
		});

		playState.addCallback("addCharacterOffset", function(name:String, animation:String, x:Float, y:Float) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null || animation == null) {
				return false;
			}

			character.addOffset(animation, x, y);
			return true;
		});

		playState.addCallback("warmCharacterAnimations", function(name:String, animations:Array<Dynamic>) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null || animations == null) {
				return false;
			}

			var animationNames:Array<String> = [];

			for(animation in animations) {
				if(animation != null) {
					animationNames.push(Std.string(animation));
				}
			}

			character.warmAnimations(animationNames);
			return true;
		});

		playState.addCallback("primeCharacterAnimations", function(name:String, animations:Array<Dynamic>) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null || animations == null) {
				return false;
			}

			var animationNames:Array<String> = [];

			for(animation in animations) {
				if(animation != null) {
					animationNames.push(Std.string(animation));
				}
			}

			var originalAnim:String = character.getCurrentAnimation();
			var originalFrame:Int = character.animation != null && character.animation.curAnim != null ? character.animation.curAnim.curFrame : 0;
			var originalVisible:Bool = character.visible;
			var originalActive:Bool = character.active;
			var originalExists:Bool = character.exists;
			var originalAlpha:Float = character.alpha;

			character.exists = true;
			character.visible = true;
			character.active = true;

			if(character.alpha <= 0) {
				character.alpha = 0.00001;
			}

			for(animationName in animationNames) {
				if(animationName == null || !character.hasAnimation(animationName)) {
					continue;
				}

				character.playAnimation(animationName, true);
				character.drawFrame(true);
			}

			if(originalAnim != null && originalAnim != "" && character.hasAnimation(originalAnim)) {
				character.playAnimation(originalAnim, true, false, originalFrame);
			} else if(character.hasAnimation("idle")) {
				character.playAnimation("idle", true);
			}

			character.drawFrame(true);
			character.visible = originalVisible;
			character.active = originalActive;
			character.exists = originalExists;
			character.alpha = originalAlpha;
			return true;
		});

		playState.addCallback("warmLoadedCharacterAnimations", function(name:String, type:String = "boyfriend", animations:Array<Dynamic>) {
			if(name == null || animations == null) {
				return false;
			}

			var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(name);

			if(resolvedCharacter == null) {
				return false;
			}

			var character:Character = null;

			switch(type.toLowerCase().trim()) {
				case "dad", "opponent":
					character = playState.dadMap != null ? playState.dadMap.get(resolvedCharacter) : null;
				case "gf", "girlfriend":
					character = playState.gfMap != null ? playState.gfMap.get(resolvedCharacter) : null;
				default:
					character = playState.boyfriendMap != null ? playState.boyfriendMap.get(resolvedCharacter) : null;
			}

			if(character == null) {
				return false;
			}

			var animationNames:Array<String> = [];

			for(animation in animations) {
				if(animation != null) {
					animationNames.push(Std.string(animation));
				}
			}

			character.warmAnimations(animationNames);
			return true;
		});

		playState.addCallback("primeLoadedCharacterAnimations", function(name:String, type:String = "boyfriend", animations:Array<Dynamic>) {
			if(name == null || animations == null) {
				return false;
			}

			var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(name);

			if(resolvedCharacter == null) {
				return false;
			}

			var character:Character = null;

			switch(type.toLowerCase().trim()) {
				case "dad", "opponent":
					character = playState.dadMap != null ? playState.dadMap.get(resolvedCharacter) : null;
				case "gf", "girlfriend":
					character = playState.gfMap != null ? playState.gfMap.get(resolvedCharacter) : null;
				default:
					character = playState.boyfriendMap != null ? playState.boyfriendMap.get(resolvedCharacter) : null;
			}

			if(character == null) {
				return false;
			}

			var animationNames:Array<String> = [];

			for(animation in animations) {
				if(animation != null) {
					animationNames.push(Std.string(animation));
				}
			}

			var originalAnim:String = character.getCurrentAnimation();
			var originalFrame:Int = character.animation != null && character.animation.curAnim != null ? character.animation.curAnim.curFrame : 0;
			var originalVisible:Bool = character.visible;
			var originalActive:Bool = character.active;
			var originalExists:Bool = character.exists;
			var originalAlpha:Float = character.alpha;

			character.exists = true;
			character.visible = true;
			character.active = true;

			if(character.alpha <= 0) {
				character.alpha = 0.00001;
			}

			for(animationName in animationNames) {
				if(animationName == null || !character.hasAnimation(animationName)) {
					continue;
				}

				character.playAnimation(animationName, true);
				character.drawFrame(true);
			}

			if(originalAnim != null && originalAnim != "" && character.hasAnimation(originalAnim)) {
				character.playAnimation(originalAnim, true, false, originalFrame);
			} else if(character.hasAnimation("idle")) {
				character.playAnimation("idle", true);
			}

			character.drawFrame(true);
			character.visible = originalVisible;
			character.active = originalActive;
			character.exists = originalExists;
			character.alpha = originalAlpha;
			return true;
		});

		playState.addCallback("addCharacterToList", function(name:String, type:String = "boyfriend") {
			var charType:Int = 0;

			switch(type.toLowerCase().trim()) {
				case "dad", "opponent":
					charType = 1;
				case "gf", "girlfriend":
					charType = 2;
				default:
					charType = 0;
			}

			var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(name);

			if(resolvedCharacter == null) {
				return false;
			}

			playState.addCharacterToList(resolvedCharacter, charType);
			return true;
		});

		playState.addCallback("removeLoadedCharacter", function(name:String, type:String = "boyfriend") {
			var charType:Int = 0;

			switch(type.toLowerCase().trim()) {
				case "dad", "opponent":
					charType = 1;
				case "gf", "girlfriend":
					charType = 2;
				default:
					charType = 0;
			}

			var resolvedCharacter:String = DefaultHandler.resolveCharacterJSON(name);

			if(resolvedCharacter == null) {
				return false;
			}

			return playState.removeLoadedCharacter(resolvedCharacter, charType);
		});

		playState.addCallback("addCharacter", function(name:String, insertBefore:String = null) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null) {
				return false;
			}

			if(playState.stage.members.indexOf(character) >= 0) {
				return true;
			}

			var insertIndex:Int = -1;

			if(insertBefore != null) {
				switch(insertBefore.toLowerCase().trim()) {
					case "boyfriend", "bf", "player":
						insertIndex = playState.stage.members.indexOf(playState.boyfriend);
					case "dad", "opponent":
						insertIndex = playState.stage.members.indexOf(playState.dad);
					case "gf", "girlfriend":
						insertIndex = playState.gf != null ? playState.stage.members.indexOf(playState.gf) : -1;
					default:
						var targetSprite:FlxSprite = getSprite(insertBefore);
						insertIndex = targetSprite != null ? playState.stage.members.indexOf(targetSprite) : -1;
				}
			}

			if(insertIndex >= 0) {
				playState.stage.insert(insertIndex, character);
			} else {
				playState.stage.add(character);
			}

			return true;
		});

		playState.addCallback("characterDance", function(name:String) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character == null)
				return false;

			character.dance();
			return true;
		});

		playState.addCallback("playCharacterAnim", function(name:String, animation:String, forced:Bool = false, reverse:Bool = false, startFrame:Int = 0) {
			var sprite = getSprite(name);

			if(!Std.isOfType(sprite, Character) || animation == null) {
				return false;
			}

			var character:Character = cast sprite;

			if(character == null || !character.hasAnimation(animation)) {
				return false;
			}

			character.playAnimation(animation, forced, reverse, startFrame);
			return true;
		});

		playState.addCallback("setCharacterAnimationAlias", function(name:String, sourceAnimation:String, targetAnimation:String) {
			var sprite = getSprite(name);

			if(!Std.isOfType(sprite, Character)) {
				return false;
			}

			var character:Character = cast sprite;

			if(character == null) {
				return false;
			}

			character.setAnimationAlias(sourceAnimation, targetAnimation);
			return true;
		});

		playState.addCallback("setCharacterAnimationSetSuffix", function(name:String, suffix:String) {
			var sprite = getSprite(name);

			if(!Std.isOfType(sprite, Character)) {
				return false;
			}

			var character:Character = cast sprite;

			if(character == null) {
				return false;
			}

			character.setAnimationSetSuffix(suffix);
			return true;
		});

		playState.addCallback("clearCharacterAnimationAlias", function(name:String, sourceAnimation:String) {
			var sprite = getSprite(name);

			if(!Std.isOfType(sprite, Character)) {
				return false;
			}

			var character:Character = cast sprite;

			if(character == null) {
				return false;
			}

			character.clearAnimationAlias(sourceAnimation);
			return true;
		});

		playState.addCallback("setCharacterHoldTimer", function(name:String, value:Float) {
			var character:Character = playState.modifiableCharacters.get(name);

			if(character != null)
				character.holdTimer = value;
		});

		playState.addCallback("setOpponentAltAnim", function(suffix:String = "") {
			playState.opponentAltAnim = suffix != null ? suffix : "";
		});

		playState.addCallback("setCharacterIdleSuffix", function(name:String, suffix:String = "") {
			var character:Character = null;

			switch(name != null ? name.toLowerCase().trim() : "") {
				case "dad", "opponent":
					character = playState.dad;
				case "boyfriend", "bf", "player":
					character = playState.boyfriend;
				case "gf", "girlfriend":
					character = playState.gf;
				default:
					character = playState.modifiableCharacters.get(name);
			}

			if(character == null)
				return false;

			character.idleSuffix = suffix != null ? suffix : "";
			return true;
		});

		playState.addCallback("setCharacterShouldPlayDance", function(name:String, enabled:Bool = true) {
			var character:Character = null;

			switch(name != null ? name.toLowerCase().trim() : "") {
				case "dad", "opponent":
					character = playState.dad;
				case "boyfriend", "bf", "player":
					character = playState.boyfriend;
				case "gf", "girlfriend":
					character = playState.gf;
				default:
					character = playState.modifiableCharacters.get(name);
			}

			if(character == null)
				return false;

			character.shouldPlayDance = enabled;
			return true;
		});

		playState.addCallback("setCharacterSpecialAnim", function(name:String, enabled:Bool = true) {
			var character:Character = null;

			switch(name != null ? name.toLowerCase().trim() : "") {
				case "dad", "opponent":
					character = playState.dad;
				case "boyfriend", "bf", "player":
					character = playState.boyfriend;
				case "gf", "girlfriend":
					character = playState.gf;
				default:
					character = playState.modifiableCharacters.get(name);
			}

			if(character == null)
				return false;

			character.specialAnim = enabled;
			return true;
		});

		playState.addCallback("setCharacterCustomAnimation", function(name:String, enabled:Bool = true) {
			var character:Character = null;

			switch(name != null ? name.toLowerCase().trim() : "") {
				case "dad", "opponent":
					character = playState.dad;
				case "boyfriend", "bf", "player":
					character = playState.boyfriend;
				case "gf", "girlfriend":
					character = playState.gf;
				default:
					character = playState.modifiableCharacters.get(name);
			}

			if(character == null)
				return false;

			character.customAnimation = enabled;
			return true;
		});

		playState.addCallback("playOpponentIdle", function() {
			playState.playOpponentIdle();
			return true;
		});

		playState.addCallback("getHealthNormalized", function() {
			var normalizedHealth:Float = playState.health / 2;
			if(normalizedHealth < 0) {
				normalizedHealth = 0;
			}else if(normalizedHealth > 1) {
				normalizedHealth = 1;
			}

			return normalizedHealth;
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

			if(spr != null && playState.stage.members.indexOf(spr) < 0)
				playState.stage.insert(position, spr);
		});

		playState.addCallback("addSpriteToStage", function(name:String) {
			var spr:FlxSprite = getSprite(name);

			if(spr != null && playState.stage.members.indexOf(spr) < 0)
				playState.stage.add(spr);
		});

		playState.addCallback("removeSpriteFromStage", function(name:String) {
			var spr:FlxSprite = getSprite(name);

			if(spr != null)
				playState.stage.remove(spr);
		});

		playState.addCallback("setHealthBarColors", function(opponentHex:String, playerHex:String) {
			var opponentColor:FlxColor = parseLuaColor(opponentHex);
			var playerColor:FlxColor = parseLuaColor(playerHex);
			playState.healthBar.createFilledBar(opponentColor, playerColor);
		});

		playState.addCallback("setHealthIconAnimation", function(side:String, character:String, regular:Int, dead:Int, winning:Int, ?isPlayer:Null<Bool>) {
			var icon:HealthIcon = null;
			var usePlayerIcon:Bool = true;
			var normalizedSide:String = side != null ? side.toLowerCase().trim() : "";

			switch(normalizedSide) {
				case "left", "opponent", "dad", "p2":
					icon = playState.iconP2;
					usePlayerIcon = false;
				default:
					icon = playState.iconP1;
					usePlayerIcon = true;
			}

			if(icon == null || character == null || character.trim() == "") {
				return false;
			}

			if(isPlayer != null) {
				usePlayerIcon = isPlayer;
			}

			icon.character = character;
			icon.createAnim(character, [cast regular, cast dead, cast winning], usePlayerIcon);
			icon.setGraphicSize(150, 150);
			icon.updateHitbox();
			icon.y = playState.healthBar.y - (icon.height / 2);

			if(icon == playState.iconP1) {
				playState.playerIconColor = CoolUtil.calculateAverageColor(icon.updateFramePixels());
			} else {
				playState.opponentIconColor = CoolUtil.calculateAverageColor(icon.updateFramePixels());
			}

			updateDynamicVars();
			return true;
		});

		playState.addCallback("doTweenHealthBarColor", function(name:String, side:String, hex:String, duration:Float, ease:String) {
			var barColor:FlxColor = parseLuaColor(hex);
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
			var hexColor:FlxColor = parseLuaColor(hex);

			if(side == "left" || side == "opponent")
				playState.healthBar.emptyColor = hexColor;

			if(side == "right" || side == "player")
				playState.healthBar.filledColor = hexColor;
		});

		playState.addCallback("disableInputs", function(disable:Bool) {
			playState.disableInputs = disable;
		});

		playState.addCallback("setHudIconsStatic", function(staticIcons:Bool) {
			playState.hudIconsStatic = staticIcons;
		});

		// Death Character Lua Bindings
		playState.addCallback("createDeathCharacter", function() {
			if(playState.customDeathCharacter == null) {
				playState.customDeathCharacter = new DeathCharacter();
			}
			return true;
		});

		playState.addCallback("loadDeathCharacterGraphic", function(imagePath:String, ?xmlPath:String) {
			if(playState.customDeathCharacter == null) {
				playState.customDeathCharacter = new DeathCharacter();
			}
			playState.customDeathCharacter.loadDeathGraphic(imagePath, xmlPath);
			return true;
		});

		playState.addCallback("loadDeathCharacterSimpleGraphic", function(imagePath:String) {
			if(playState.customDeathCharacter == null) {
				playState.customDeathCharacter = new DeathCharacter();
			}
			playState.customDeathCharacter.loadSimpleGraphic(imagePath);
			return true;
		});

		playState.addCallback("addDeathCharacterAnimation", function(name:String, prefix:String, frameRate:Int = 24, looped:Bool = false) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.addDeathAnimation(name, prefix, frameRate, looped);
			return true;
		});

		playState.addCallback("setDeathCharacterAnimationOffset", function(name:String, x:Float, y:Float) {
			if(playState.customDeathCharacter == null || name == null) return false;
			playState.customDeathCharacter.addDeathOffset(name, x, y);
			return true;
		});

		playState.addCallback("setDeathCharacterAnimations", function(firstDeath:String, deathLoop:String, deathConfirm:String) {
			if(playState.customDeathCharacter == null) return false;
			if(firstDeath != null) playState.customDeathCharacter.firstDeathAnim = firstDeath;
			if(deathLoop != null) playState.customDeathCharacter.deathLoopAnim = deathLoop;
			if(deathConfirm != null) playState.customDeathCharacter.deathConfirmAnim = deathConfirm;
			return true;
		});

		playState.addCallback("setDeathCharacterPosition", function(x:Float, y:Float) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.setDeathPosition(x, y);
			return true;
		});

		playState.addCallback("setDeathCharacterCameraOffset", function(offsetX:Float, offsetY:Float) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.cameraOffsetX = offsetX;
			playState.customDeathCharacter.cameraOffsetY = offsetY;
			return true;
		});

		playState.addCallback("setDeathCharacterCameraZoom", function(zoom:Float) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.cameraZoom = zoom;
			return true;
		});

		playState.addCallback("setDeathCharacterScale", function(scaleX:Float, scaleY:Float) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.scale.set(scaleX, scaleY);
			playState.customDeathCharacter.updateHitbox();
			return true;
		});

		playState.addCallback("setDeathCharacterFlipX", function(flip:Bool) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.flipX = flip;
			return true;
		});

		playState.addCallback("setDeathCharacterAntialiasing", function(enabled:Bool) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.antialiasing = enabled;
			return true;
		});

		playState.addCallback("setDeathSounds", function(deathSound:String, deathMusic:String, deathMusicLoop:String, deathConfirmMusic:String) {
			if(playState.customDeathCharacter == null) return false;
			if(deathSound != null) playState.customDeathCharacter.deathSoundPath = deathSound;
			if(deathMusic != null) playState.customDeathCharacter.deathMusicPath = deathMusic;
			if(deathMusicLoop != null) playState.customDeathCharacter.deathMusicLoopPath = deathMusicLoop;
			if(deathConfirmMusic != null) playState.customDeathCharacter.deathConfirmMusicPath = deathConfirmMusic;
			return true;
		});

		playState.addCallback("setDeathCharacterOffset", function(offsetX:Float, offsetY:Float) {
			if(playState.customDeathCharacter == null) return false;
			playState.customDeathCharacter.offset.set(offsetX, offsetY);
			return true;
		});

		playState.addCallback("hasCustomDeathCharacter", function() {
			return playState.customDeathCharacter != null;
		});

		playState.addCallback("clearCustomDeathCharacter", function() {
			if(playState.customDeathCharacter != null) {
				playState.customDeathCharacter.destroy();
				playState.customDeathCharacter = null;
			}
			return true;
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
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.x = x;
					strumOBJ.y = y;
				});
			});

			playState.addCallback("setNoteStrumAngleX", function(id:Int, angle:Float) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.xAngle = angle;
				});
			});

			playState.addCallback("setNoteStrumAngleY", function(id:Int, angle:Float) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.yAngle = angle;
				});
			});

			playState.addCallback("setNoteStrumAngleZ", function(id:Int, angle:Float) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.angle = angle;
				});
			});

			playState.addCallback("setNoteStrumAngle", function(id:Int, angle:Float) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.angle = angle;
				});
			});

			playState.addCallback("setNoteDirection", function(id:Int, angle:Float) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.directionAngle = angle;
				});
			});

			playState.addCallback("setNoteAlpha", function(id:Int, alpha:Float) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.alpha = alpha;
				});
			});

			playState.addCallback("setNoteScale", function(id:Int, x:Float, y:Float, shouldUpdateHitbox:Bool = true) {
				return withStrumById(id, function(strumOBJ:Strum) {
					strumOBJ.scale.set(x, y);

					if(shouldUpdateHitbox)
						strumOBJ.updateHitbox();
				});
			});

		playState.addCallback("getNoteStrumAngleX", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.xAngle : 0;
		});

		playState.addCallback("getNoteStrumAngleY", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.yAngle : 0;
		});

		playState.addCallback("getNoteStrumAngleZ", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.angle : 0;
		});

		playState.addCallback("getNoteStrumAngle", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.angle : 0;
		});

		playState.addCallback("getNoteDirection", function(id:Int, angle:Float) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.directionAngle : 0;
		});

		playState.addCallback("getNoteScaleX", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.scale.x : 0;
		});

		playState.addCallback("getNoteScaleY", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.scale.y : 0;
		});

		playState.addCallback("getNotePosX", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.x : 0;
		});

		playState.addCallback("getNotePosY", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.y : 0;
		});

		playState.addCallback("getNoteAlpha", function(id:Int) {
			var strumOBJ:Strum = getStrumById(id);
			return strumOBJ != null ? strumOBJ.alpha : 0;
		});

			playState.addCallback("getNoteScreenCenter", function(id:Int, ?axis:String):Float {
				var strumOBJ:Strum = getStrumById(id);

				if(strumOBJ == null)
					return 0.0;

				switch((axis == null ? "" : axis).toLowerCase()) {
					case "x": return strumOBJ.getScreenCenter(X);
					case "y": return strumOBJ.getScreenCenter(Y);
				}

			return 0.0;
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
				var strumOBJ:Strum = getStrumById(id);
				var lua:ModLua = getLua();

				if(strumOBJ == null || lua == null)
					return false;

				lua.luaTweens.set(name, FlxTween.tween(strumOBJ.scale, {x: value1, y: value2}, duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
						lua.luaTweens.remove(name);
						call('onTweenCompleted', [name]);
					}
				}));
				return true;
			});
		#end
	}

		private function registerNoteTweenCallback(name:String, buildProps:Dynamic):Void
		{
			playState.addCallback(name, function(tweenName:String, id:Int, value:Dynamic, duration:Float, ease:String) {
				var strumOBJ:Strum = getStrumById(id);
				var lua:ModLua = getLua();

				if(strumOBJ == null || lua == null)
					return false;

				lua.luaTweens.set(tweenName, FlxTween.tween(strumOBJ, buildProps(strumOBJ, value), duration, {ease: Register.getFlxEaseByString(ease),
					onComplete: function(twn:FlxTween) {
						lua.luaTweens.remove(tweenName);
						call('onTweenCompleted', [tweenName]);
					}
				}));
				return true;
			});
		}

		private inline function withStrumById(id:Int, apply:Strum->Void):Bool
		{
			var strumOBJ:Strum = getStrumById(id);

			if(strumOBJ == null) {
				return false;
			}

			apply(strumOBJ);
			return true;
		}

	private function getStrumById(id:Int):Strum
	{
		if(playState == null || playState.strumLineNotes == null || playState.strumLineNotes.members == null) {
			return null;
		}

		var strumCount:Int = playState.strumLineNotes.length;

		if(strumCount <= 0) {
			return null;
		}

		return playState.strumLineNotes.members[Std.int(Math.abs(id)) % strumCount];
	}

	public function updateDynamicVars():Void
	{
		if(!hasScript())
			return;

        getLua().updateManagedSprites(FlxG.elapsed);

		var curStepFloat:Float = Conductor.instance.currentStepTime;
		var curBeatFloat:Float = Conductor.instance.currentBeatTime;
		var curStepValue:Int = Conductor.instance.currentStep;
		var curBeatValue:Int = Conductor.instance.currentBeat;

		set('cameraX', playState.camFollow.x);
		set('cameraY', playState.camFollow.y);
		set("health", playState.health);

		var normalizedHealth:Float = playState.health / 2;
		if(normalizedHealth < 0) {
			normalizedHealth = 0;
		}else if(normalizedHealth > 1) {
			normalizedHealth = 1;
		}
		set("healthNormalized", normalizedHealth);

		set("score", playState.songScore);
		set("misses", playState.misses);
		set("hits", playState.hits);
		set("curStep", curStepValue);
		set("curBeat", curBeatValue);
		set("curSection", playState.curSection);
		set("curStepFloat", curStepFloat);
		set("curBeatFloat", curBeatFloat);
		set("substateOpenName", playState.subState != null ? Type.getClassName(Type.getClass(playState.subState)) : "");
		set("isInCountdown", playState.isInCountdown);
		set("startTimestamp", playState.startTimestamp);
		set("countdownStep", Countdown.stepToString(Countdown.countdownStep));
		set("countdownStepInt", Countdown.stepToInt(Countdown.countdownStep));

		set("boyfriendName", playState.boyfriend.curCharacter);
		set("dadName", playState.dad.curCharacter);
		set("gfName", playState.gf != null ? playState.gf.curCharacter : "");

		set('downscroll', SaveData.getData(DOWNSCROLL));
		set('framerate', Lib.current.stage.frameRate);
		set('ghostTapping', GhostTapping.ghostTap);
		set("songLength", FlxG.sound.music.length);
		set("trackPos", Conductor.instance.trackedSongPosition);

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

		var sectionIndex:Int = Std.int(Math.floor(Conductor.instance.currentStepTime) / 16);
		var curSection:SwagSection = null;

		if(PlayState.SONG != null && PlayState.SONG.notes != null && sectionIndex >= 0 && sectionIndex < PlayState.SONG.notes.length) {
			curSection = PlayState.SONG.notes[sectionIndex];
		}

		set("bpm", Conductor.instance.activeBpm);
		set("scrollspeed", PlayState.SONG.speed);
		set("mustHitSection", curSection != null ? curSection.mustHitSection : false);
		set("altAnim", curSection != null ? curSection.altAnim : false);
	}

	private function getStepFloatFromTime(songTime:Float):Float
	{
		return Conductor.instance.getTimeInSteps(songTime);
	}

	public function prepareForStateSwitch():Void
	{
		var stateLua:ModLua = ownedLua;

		if(!luaDetachedForStateSwitch && stateLua != null) {
			stateLua.close();
			luaDetachedForStateSwitch = true;
		}
	}

	public function destroy():Void
	{
		var stateLua:ModLua = ownedLua;

		if(!luaDetachedForStateSwitch && stateLua != null) {
			stateLua.close();
		}

		ownedLua = null;
		playState = null;
		luaDetachedForStateSwitch = true;
	}

	private function resolveScriptKey():String
	{
		var songScript:String = "song/" + CoolUtil.readableSongDirectory(PlayState.SONG.song.toLowerCase());
		var stageScript:String = "stage/" + PlayState.curStage.toLowerCase();

		if(Paths.assetExists(Paths.getPath('scripts/${songScript}.lua', TEXT, null), TEXT)) {
			return songScript;
		}

		if(Paths.assetExists(Paths.getPath('scripts/${stageScript}.lua', TEXT, null), TEXT)) {
			return stageScript;
		}

		return null;
	}

	private function attachScript(scriptPath:String):Void
	{
		ownedLua = new ModLua(Paths.lua(scriptPath));
		ownedLua.stateOwnsCreatedObjects = true;

		if(ownedLua != null) {
			ownedLua.execute();
		}
	}

	// Parse color string safely to handle unsigned 32-bit values on Windows/CPP
	private static function parseLuaColor(colorStr:String):Int {
		if (colorStr == null) return 0;

		var hex:String = colorStr.trim();

		// Remove 0x prefix if present
		if (hex.toLowerCase().startsWith("0x")) {
			hex = hex.substr(2);
		}

		// Pad with alpha if only RGB provided (6 chars or less)
		if (hex.length <= 6) {
			hex = "ff" + StringTools.lpad(hex, "0", 6);
		}

		// Parse in two 16-bit parts to avoid Int32 overflow on Windows/CPP
		var highStr:String = "0x" + hex.substr(0, 4);
		var lowStr:String = "0x" + hex.substr(4, 4);
		var high:Null<Int> = Std.parseInt(highStr);
		var low:Null<Int> = Std.parseInt(lowStr);

		return ((high != null ? high : 0) << 16) | (low != null ? low : 0);
	}
}
