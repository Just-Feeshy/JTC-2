package play;

#if windows
import Discord.DiscordClient;
#end
import Conductor;
import Paths;
import PlayState;
import SaveData.SaveType;
import flixel.FlxG;
import flixel.system.FlxSound;

using StringTools;

@:access(PlayState)
class PlayAudio
{
	private var playState:PlayState;
	private var freezePausedAudio:Bool = false;
	private var currentPlaybackRate:Float = 1;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public inline function isTimeFreezeAudioPaused():Bool
	{
		return freezePausedAudio;
	}

	public function parseSongTrackSide(side:String):String
	{
		if (side == null)
			return PlayState.SONG_TRACK_SIDE_EXTRA;

		var normalizedSide = side.trim().toLowerCase();

		return switch (normalizedSide)
		{
			case PlayState.SONG_TRACK_SIDE_PLAYER, PlayState.SONG_TRACK_SIDE_OPPONENT, PlayState.SONG_TRACK_SIDE_SHARED:
				normalizedSide;
			default:
				PlayState.SONG_TRACK_SIDE_EXTRA;
		}
	}

	public function normalizeSongTrackFilters(filterString:String):Array<String>
	{
		var filters:Array<String> = [];

		if (filterString == null)
			return filters;

		for (entry in filterString.split(","))
		{
			var normalizedEntry = entry.trim().toLowerCase();

			if (normalizedEntry != "")
				filters.push(normalizedEntry);
		}

		return filters;
	}

	public function sanitizeSongTrackFilters(filters:Array<String>):Array<String>
	{
		var normalizedFilters:Array<String> = [];

		if (filters == null)
			return normalizedFilters;

		for (entry in filters)
		{
			if (entry == null)
				continue;

			var normalizedEntry = entry.trim().toLowerCase();

			if (normalizedEntry != "")
				normalizedFilters.push(normalizedEntry);
		}

		return normalizedFilters;
	}

	public function isSongTrackInSoundList(sound:FlxSound):Bool
	{
		return sound != null
			&& FlxG.sound.list != null
			&& FlxG.sound.list.members != null
			&& FlxG.sound.list.members.contains(sound);
	}

	public function applySongTrackVolume(track:SongTrackInfo):Void
	{
		if (track != null && track.sound != null)
			track.sound.volume = track.baseVolume * track.stateVolume;
	}

	private function setSoundPlaybackRate(sound:FlxSound, rate:Float):Void
	{
		if (sound == null)
			return;

		#if lime
		@:privateAccess
		if (sound._channel != null && sound._channel.__audioSource != null)
			sound._channel.__audioSource.pitch = rate;
		#end
	}

	public function songTrackMatchesTag(track:SongTrackInfo, noteTag:String):Bool
	{
		if (track == null || track.tagFilters == null || track.tagFilters.length == 0)
			return true;

		if (noteTag == null)
			return false;

		return track.tagFilters.contains(noteTag.trim().toLowerCase());
	}

	public function registerSongTrack(tag:String, fileName:String, sound:FlxSound, side:String, baseVolume:Float = 1,
		looped:Bool = false, ?tagFilters:Array<String>):SongTrackInfo
	{
		if (tag == null || tag.trim() == "" || sound == null)
			return null;

		var normalizedTag = tag.trim();

		if (playState.syncedSongTrackMap.exists(normalizedTag))
			destroySongTrack(normalizedTag);

		var track:SongTrackInfo = {
			tag: normalizedTag,
			fileName: fileName,
			sound: sound,
			side: parseSongTrackSide(side),
			baseVolume: baseVolume,
			stateVolume: 1,
			looped: looped,
			tagFilters: sanitizeSongTrackFilters(tagFilters)
		};

		playState.syncedSongTracks.push(track);
		playState.syncedSongTrackMap.set(track.tag, track);

		if (!isSongTrackInSoundList(sound))
			FlxG.sound.list.add(sound);

		applySongTrackVolume(track);
		return track;
	}

	public function destroySongTrack(tag:String):Void
	{
		if (tag == null || !playState.syncedSongTrackMap.exists(tag))
			return;

		var track = playState.syncedSongTrackMap.get(tag);
		playState.syncedSongTrackMap.remove(tag);
		playState.syncedSongTracks.remove(track);

		if (track.sound != null)
		{
			track.sound.stop();

			if (isSongTrackInSoundList(track.sound))
				FlxG.sound.list.remove(track.sound, true);

			track.sound.destroy();
		}

		if (playState.vocals == track.sound)
			playState.vocals = new FlxSound();

		if (playState.opponentVocals == track.sound)
			playState.opponentVocals = null;
	}

	public function destroyAllSongTracks():Void
	{
		for (track in playState.syncedSongTracks.copy())
			destroySongTrack(track.tag);

		playState.syncedSongTracks = [];
		playState.syncedSongTrackMap = new Map<String, SongTrackInfo>();
		playState.vocals = new FlxSound();
		playState.opponentVocals = null;
		freezePausedAudio = false;
	}

	public function playSongTrack(track:SongTrackInfo, ?startTime:Null<Float>):Void
	{
		if (track == null || track.sound == null)
			return;

		if (startTime != null)
			track.sound.time = startTime;

		track.sound.play(false, startTime != null ? startTime : track.sound.time);
		setSoundPlaybackRate(track.sound, playState.getTimeFreezePlaybackRate());
		applySongTrackVolume(track);
	}

	public function addSongTrack(tag:String, fileName:String, side:String = "extra", baseVolume:Float = 1,
		looped:Bool = false, ?tagFilters:Array<String>):Bool
	{
		if (tag == null || tag.trim() == "" || fileName == null || fileName.trim() == "")
			return false;

		if (!Paths.songSoundExists(PlayState.SONG.song, fileName))
			return false;

		var sound = new FlxSound().loadEmbedded(Paths.songSound(PlayState.SONG.song, fileName), looped);
		var track = registerSongTrack(tag, fileName, sound, side, baseVolume, looped, tagFilters);

		if (track == null)
			return false;

		if (FlxG.sound.music != null && FlxG.sound.music.playing && !playState.paused)
		{
			track.sound.time = FlxG.sound.music.time;
			playSongTrack(track, FlxG.sound.music.time);
		}

		return true;
	}

	public function hasSongTrackDesync(baseTime:Float):Bool
	{
		for (track in playState.syncedSongTracks)
		{
			if (track.sound != null && Math.abs(track.sound.time - baseTime) > PlayState.SONG_TRACK_DESYNC_TOLERANCE)
				return true;
		}

		return false;
	}

	public function loadSongVocals(song:String):Void
	{
		destroyAllSongTracks();
		playState.opponentVocals = null;

		if (PlayState.SONG.needsVoices)
		{
			var hasSplitVocals:Bool = Paths.songSoundExists(song, "1_Voices") && Paths.songSoundExists(song, "2_Voices");
			var hasSingleVocals:Bool = Paths.songSoundExists(song, "Voices");

			if (hasSplitVocals)
			{
				playState.vocals = new FlxSound().loadEmbedded(Paths.songSound(song, "1_Voices"));
				playState.opponentVocals = new FlxSound().loadEmbedded(Paths.songSound(song, "2_Voices"));
				registerSongTrack(PlayState.PLAYER_VOCALS_TRACK_TAG, "1_Voices", playState.vocals, PlayState.SONG_TRACK_SIDE_PLAYER);
				registerSongTrack(PlayState.OPPONENT_VOCALS_TRACK_TAG, "2_Voices", playState.opponentVocals, PlayState.SONG_TRACK_SIDE_OPPONENT);
			}
			else if (hasSingleVocals)
			{
				playState.vocals = new FlxSound().loadEmbedded(Paths.voices(song));
				registerSongTrack(PlayState.SHARED_VOCALS_TRACK_TAG, "Voices", playState.vocals, PlayState.SONG_TRACK_SIDE_SHARED);
			}
			else
			{
				trace("Warning: no vocals found for " + song + ", continuing without vocals.");
				playState.vocals = new FlxSound();
			}
		}
		else
		{
			playState.vocals = new FlxSound();
		}
	}

	public function pauseVocals():Void
	{
		for (track in playState.syncedSongTracks)
			track.sound.pause();
	}

	public function playVocals(?startTime:Null<Float>):Void
	{
		if (isSongAudioBlocked())
			return;

		for (track in playState.syncedSongTracks)
			playSongTrack(track, startTime);
	}

	public function stopVocals():Void
	{
		for (track in playState.syncedSongTracks)
			track.sound.stop();
	}

	public function setVocalsTime(time:Float):Void
	{
		for (track in playState.syncedSongTracks)
			track.sound.time = time;
	}

	public function setAllVocalsVolume(volume:Float):Void
	{
		for (track in playState.syncedSongTracks)
		{
			track.stateVolume = volume;
			applySongTrackVolume(track);
		}
	}

	public function setPlayerVocalsVolume(volume:Float, ?noteTag:String):Void
	{
		for (track in playState.syncedSongTracks)
		{
			if ((track.side == PlayState.SONG_TRACK_SIDE_PLAYER || track.side == PlayState.SONG_TRACK_SIDE_SHARED) && songTrackMatchesTag(track, noteTag))
			{
				track.stateVolume = volume;
				applySongTrackVolume(track);
			}
		}
	}

	public function setOpponentVocalsVolume(volume:Float, ?noteTag:String):Void
	{
		for (track in playState.syncedSongTracks)
		{
			if ((track.side == PlayState.SONG_TRACK_SIDE_OPPONENT || track.side == PlayState.SONG_TRACK_SIDE_SHARED) && songTrackMatchesTag(track, noteTag))
			{
				track.stateVolume = volume;
				applySongTrackVolume(track);
			}
		}
	}

	public function setSongPlaybackRate(rate:Float):Void
	{
		var boundedRate:Float = Math.min(1, Math.max(0.0001, rate));

		if(Math.abs(currentPlaybackRate - boundedRate) < 0.0005)
			return;

		currentPlaybackRate = boundedRate;

		if (FlxG.sound.music != null)
			setSoundPlaybackRate(FlxG.sound.music, boundedRate);

		for (track in playState.syncedSongTracks)
		{
			if (track.sound != null)
				setSoundPlaybackRate(track.sound, boundedRate);
		}
	}

	private function resumeAudioFromTimeFreeze():Void
	{
		var resumeTime:Float = Math.max(0, Conductor.instance.trackedSongPosition - Conductor.instance.combinedOffset);

		if(FlxG.sound.music == null)
		{
			startInstrumentTrack(resumeTime);
		}
		else if(FlxG.sound.music.length <= 0)
		{
			startInstrumentTrack(resumeTime);
		}
		else
		{
			FlxG.sound.music.time = resumeTime;
			FlxG.sound.music.play();
		}

		if(PlayState.muteInst && FlxG.sound.music != null)
			FlxG.sound.music.volume = 0;

		if(FlxG.sound.music != null) {
			setSongPosition(FlxG.sound.music.time);
			setVocalsTime(FlxG.sound.music.time);
			playVocals(FlxG.sound.music.time);
		}

		freezePausedAudio = false;
	}

	public function applyTimeFreezeValue(previousFreeze:Float, nextFreeze:Float):Void
	{
		if(nextFreeze >= 1)
		{
			if(!freezePausedAudio)
			{
				if (FlxG.sound.music != null)
					FlxG.sound.music.pause();

				pauseVocals();
				freezePausedAudio = true;
			}

			currentPlaybackRate = playState.getTimeFreezePlaybackRate(nextFreeze);
			return;
		}

		if(freezePausedAudio)
			resumeAudioFromTimeFreeze();

		setSongPlaybackRate(playState.getTimeFreezePlaybackRate(nextFreeze));
	}

	inline function isSongAudioBlocked():Bool
	{
		return playState.inCutscene || playState.talking;
	}

	public function startInstrumentTrack(?startTime:Null<Float>):Void
	{
		if (isSongAudioBlocked())
			return;

		if (FlxG.sound.music == null)
			FlxG.sound.music = new FlxSound();
		else
			FlxG.sound.music.stop();

		FlxG.sound.music.loadEmbedded(Paths.inst(PlayState.SONG.song), false);
		FlxG.sound.music.persist = true;
		FlxG.sound.music.group = FlxG.sound.defaultMusicGroup;
		FlxG.sound.music.volume = PlayState.muteInst ? 0 : 1;
		FlxG.sound.music.play(false, startTime == null ? 0 : startTime);
		setSoundPlaybackRate(FlxG.sound.music, playState.getTimeFreezePlaybackRate());
		currentPlaybackRate = playState.getTimeFreezePlaybackRate();
		freezePausedAudio = false;
		FlxG.sound.music.onComplete = playState.whenSongFinished.bind();
	}

	public function startSong():Void
	{
		if (isSongAudioBlocked())
		{
			pauseVocals();
			return;
		}

		playState.startingSong = false;
		playState.isInCountdown = false;
		playState.previousHeldInputSongTime = null;
		playState.previousFrameTime = FlxG.game.ticks;
		playState.lastReportedPlayheadPosition = 0;

		startInstrumentTrack(0);
		playVocals(FlxG.sound.music != null ? FlxG.sound.music.time : 0);
		setSongPosition(FlxG.sound.music != null ? FlxG.sound.music.time : 0);

		if(playState.paused) {
			FlxG.sound.music.pause();
			pauseVocals();
		}

		playState.songLength = FlxG.sound.music.length;

		#if windows
		DiscordClient.changePresence(
			playState.detailsText,
			PlayState.SONG.song + " (" + playState.storyDifficultyText + ")\n Acc: " + playState.accTotal + "%",
			playState.iconRPC,
			true,
			playState.songLength
		);
		#end
	}

	public function pauseMusic():Void
	{
		if (FlxG.sound.music != null) {
			FlxG.sound.music.pause();
			pauseVocals();
		}

		freezePausedAudio = false;
		Countdown.pauseCountdown();
	}

	public function resyncVocals(force:Bool = false):Void
	{
		if((playState.timeFreeze > 0 && !force) || isSongAudioBlocked())
		{
			pauseVocals();
			return;
		}

		pauseVocals();
		playState.previousHeldInputSongTime = null;

		var resumeTime:Float = Math.max(0, Conductor.instance.trackedSongPosition - Conductor.instance.combinedOffset);

		if(FlxG.sound.music == null)
		{
			startInstrumentTrack(resumeTime);
		}
		else if(FlxG.sound.music.length <= 0)
		{
			startInstrumentTrack(resumeTime);
		}
		else if(!FlxG.sound.music.playing)
		{
			FlxG.sound.music.time = resumeTime;
		}

		if(PlayState.muteInst)
			FlxG.sound.music.volume = 0;

		FlxG.sound.music.play();
		setSongPosition(FlxG.sound.music.time);
		setVocalsTime(FlxG.sound.music.time);
		playVocals(FlxG.sound.music.time);
		setSongPlaybackRate(playState.getTimeFreezePlaybackRate());
		freezePausedAudio = false;
	}

	public function setSongPosition(time:Float):Void
	{
		Conductor.instance.update(time, false);
		playState.syncMusicBeatState(Conductor.instance.trackedSongPosition);
		playState.lastTrackedSongPos = Conductor.instance.trackedSongPosition;
		playState.updateLuaVars();
		playState.updatePerSectionLuaVars();
	}
}
