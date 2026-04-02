package play;

import Section.SwagSection;
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
		return !luaDetachedForStateSwitch && getLua() != null;
		#else
		return false;
		#end
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
		var scriptPath:String = resolveScriptKey();

		Register.detachLuaFromState(PlayState);

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

		Register.attachLuaToState(PlayState, Paths.lua(scriptPath));
		ownedLua = playState.getModLua();
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
		Register.attachLuaToState(PlayState, Paths.lua(scriptPath));
		ownedLua = playState.getModLua();

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
