package play;

#if windows
import Discord.DiscordClient;
#end
import CacheState;
import CoolUtil;
import DefaultHandler;
import FreeplayState;
import Highscore;
import MainMenuState;
import Paths;
import PlayState;
import Song;
import StoryMenuState;
import VideoState;
import SaveData.SaveType;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;

@:access(PlayState)
class PlayFlow
{
	private var playState:PlayState;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function haveGamePaused():Void
	{
		playState.paused = !playState.paused;

		if (playState.paused) {
			playState.pauseMusic();
		}else {
			if (FlxG.sound.music != null && !playState.startingSong && !playState.inCutscene && !playState.talking) {
				playState.resyncVocals();
			}

			Countdown.resumeCountdown();
		}
	}

	public function pauseMenu():Void
	{
		playState.persistentUpdate = false;
		playState.persistentDraw = true;
		playState.paused = true;

		if (FlxG.random.bool(0.1)) {
			FlxG.switchState(new GitarooPause());
		} else {
			final screenPos = playState.currentPlayer.getScreenPosition();
			playState.openSubState(new PauseSubState(screenPos.x, screenPos.y));
		}

		#if windows
		DiscordClient.changePresence(
			playState.detailsPausedText,
			PlayState.SONG.song + " (" + playState.storyDifficultyText + ")\n Acc: " + playState.accTotal + "%",
			playState.iconRPC
		);
		#end
	}

	public function gameOverScreen():Void
	{
		playState.currentPlayer.stunned = true;
		playState.resetScriptedCameraState(false);

		if(playState.modifierCheckList('blind effect')) {
			FlxG.camera.alpha = 1;
		}

		playState.persistentUpdate = false;
		playState.persistentDraw = false;
		playState.paused = false;

		playState.pauseMusic();
		playState.clearGameplayCameraFilters();
		FlxG.camera.followLerp = 0;
		FlxG.camera.zoom = playState.defaultCamZoom;
		playState.playLua.set("inGameOver", true);
		playState.dispatchEvent(new PlayScriptEvent(PlayScriptEvent.GAME_OVER));
		playState.openSubState(new GameOverSubstate());

		#if windows
		DiscordClient.changePresence(
			"Game Over - " + playState.detailsText,
			PlayState.SONG.song + " (" + playState.storyDifficultyText + ")",
			playState.iconRPC
		);
		#end
	}

	public function whenSongFinished():Void
	{
		playState.canPause = false;
		FlxG.sound.music.volume = 0;
		playState.setAllVocalsVolume(0);
		playState.pauseVocals();

		if(SaveData.getData(SaveType.NOTE_OFFSET) > 0) {
			new FlxTimer().start(SaveData.getData(SaveType.NOTE_OFFSET) / 1000, function(_:FlxTimer) {
				endSong();
			});
		}else {
			endSong();
		}
	}

	public function endSong():Void
	{
		DefaultHandler.kill();

		if (PlayState.SONG.validScore && !playState.modifierCheckList('blue balls')) {
			#if !switch
			Highscore.saveScore(PlayState.SONG.song, playState.songScore, PlayState.storyDifficulty);
			#end
		}

		if (PlayState.isStoryMode) {
			PlayState.campaignScore += playState.songScore;
			PlayState.storyPlaylist.remove(PlayState.storyPlaylist[0]);

			if (PlayState.storyPlaylist.length <= 0) {
				if(playState.videoSwitchState == "" || playState.videoSwitchState == null || SaveData.getData(SaveType.SKIP_CUTSCENES)) {
					FlxG.sound.playMusic(Paths.music('Main Menu'));
					FlxG.switchState(new StoryMenuState());
				}else {
					FlxG.sound.music.stop();
					FlxG.switchState(new VideoState(new StoryMenuState(), playState.videoSwitchState));
				}

				if (PlayState.SONG.validScore && !playState.modifierCheckList('blue balls')) {
					#if !switch
					Highscore.saveWeekScore(
						Paths.modJSON.weeks.get("week_" + PlayState.storyWeek).week_name,
						PlayState.campaignScore,
						PlayState.storyDifficulty
					);
					#end
				}
			}
			else
			{
				var difficulty:String = CoolUtil.getDifficultyFileSuffix(PlayState.storyDifficulty);

				trace('LOADING NEXT SONG');
				trace(PlayState.storyPlaylist[0].toLowerCase() + difficulty);

				if (PlayState.SONG.song.toLowerCase() == 'eggnog') {
					var blackShit:FlxSprite = new FlxSprite(-FlxG.width * FlxG.camera.zoom,
						-FlxG.height * FlxG.camera.zoom).makeGraphic(FlxG.width * 3, FlxG.height * 3, FlxColor.BLACK);
					blackShit.scrollFactor.set();
					playState.add(blackShit);
					PlayState.camHUD.visible = false;
					PlayState.camNOTE.visible = false;

					FlxG.sound.play(Paths.sound('Lights_Shut_off'));
				}

				PlayState.prevCamFollow = playState.camFollow;
				PlayState.SONG = Song.loadFromJson(PlayState.storyPlaylist[0].toLowerCase() + difficulty, PlayState.storyPlaylist[0]);
				FlxG.sound.music.stop();

				if(playState.videoSwitchState == "" || playState.videoSwitchState == null || SaveData.getData(SaveType.SKIP_CUTSCENES)) {
					CacheState.loadAndSwitchState(new PlayState());
				}else {
					trace("WENT TO VIDEO");
					CacheState.loadAndSwitchState(new VideoState(new PlayState(), playState.videoSwitchState));
				}
			}
		}
		else
		{
			trace('WENT BACK TO FREEPLAY??');
			FlxG.switchState(new FreeplayState());
		}

		PlayState.hasWarning = true;
	}
}
