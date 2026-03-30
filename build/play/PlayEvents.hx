package play;

import Conductor;
import PlayState;
import VSliceEvent;

using StringTools;

@:access(PlayState)
class PlayEvents
{
	private var playState:PlayState;

	public function new(playState:PlayState)
	{
		this.playState = playState;
	}

	public function generateStaticLua():Void
	{
		if(playState.playLua != null)
			playState.playLua.generateStaticBindings();
	}

	public function makeNoteLua():Void
	{
		if(playState.playLua != null)
			playState.playLua.generateNoteBindings();
	}

	public function updateLuaVars():Void
	{
		if(playState.playLua != null)
			playState.playLua.updateDynamicVars();
	}

	public function updatePerSectionLuaVars():Void
	{
		if(playState.playLua != null)
			playState.playLua.updatePerSectionVars();
	}

	public function eventLoad():Void
	{
		if(playState.eventInfo.length == 0)
			return;

		var liveSongTime:Float = Conductor.instance.trackedSongPosition;
		var liveStep:Int = playState.getStepFromTime(liveSongTime);
		var liveGridY:Int = liveStep * 40;

		while(playState.eventInfo.length > 0) {
			var nextEvent:Dynamic = playState.eventInfo[0];
			var eventTime:Null<Float> = Reflect.field(nextEvent, "modTime");

			if(eventTime != null) {
				if(liveSongTime < eventTime)
					return;
			} else {
				var gridY:Int = Reflect.field(nextEvent, "modGridY");

				if(liveGridY < gridY)
					return;
			}

			eventLoadDefaultHandler();
		}
	}

	public function eventLoadDefaultHandler():Void
	{
		var value:String = Reflect.field(playState.eventInfo[0], "modValue");
		var value2:String = Reflect.field(playState.eventInfo[0], "modValueTwo");
		var skill:String = Reflect.field(playState.eventInfo[0], "modSkill");

		playState.eventInfo.shift();

		if(skill == null) {
			skill = "";
		}

		skill = skill.toLowerCase().trim();

		if(!playState.eventStorage.contains(skill))
			playState.eventStorage.push(skill);

		var useRawValues:Bool = VSliceEvent.usesRawValues(skill);

		if(value != null) {
			value = useRawValues ? value.trim() : value.toLowerCase().trim();
		}

		if(value2 != null) {
			value2 = useRawValues ? value2.trim() : value2.toLowerCase().trim();
		}

		playState.events.whenTriggered(skill, value, value2, playState);
		playState.event_Extra(skill, value, value2);
	}
}
