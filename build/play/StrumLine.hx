package play;

import Conductor;
import HoldCoverSprite;
import Strum;
import flixel.FlxCamera;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.group.FlxSpriteGroup.FlxTypedSpriteGroup;

class StrumLine {
	public var strums(default, null):FlxTypedSpriteGroup<Strum>;
	public var holdCovers(default, null):Array<HoldCoverSprite> = [];
	public var isPlayer(default, null):Bool;
	public var laneCount(default, null):Int;
	public var fifthKey(get, never):Bool;

	public var x(get, set):Float;
	public var y(get, set):Float;
	public var members(get, never):Array<Strum>;
	public var length(get, never):Int;

	public function new(isPlayer:Bool, laneCount:Int) {
		this.isPlayer = isPlayer;
		this.laneCount = laneCount;
		strums = new FlxTypedSpriteGroup<Strum>();
	}

	public function reset(laneCount:Int):Void {
		clearStrums();
		clearHoldCovers();
		this.laneCount = laneCount;
		strums.x = 0;
		strums.y = 0;
	}

	public function add(strum:Strum):Strum {
		return strums.add(strum);
	}

	public function clearStrums():Void {
		if(strums == null) {
			strums = new FlxTypedSpriteGroup<Strum>();
			return;
		}

		for(strum in strums.members.copy()) {
			if(strum != null) {
				strum.kill();
				strums.remove(strum, true);
				strum.destroy();
			}
		}
	}

	public function setupHoldCovers(group:FlxTypedGroup<HoldCoverSprite>, camera:FlxCamera):Void {
		clearHoldCovers(group);

		for(index in 0...laneCount) {
			var strum = getByIndex(index);
			var cover:HoldCoverSprite = null;

			if(strum != null) {
				cover = new HoldCoverSprite(strum.direction);
			}

			holdCovers.push(cover);

			if(cover != null) {
				cover.cameras = [camera];
				group.add(cover);
				updateHoldCoverPosition(index);
			}
		}
	}

	public function clearHoldCovers(?group:FlxTypedGroup<HoldCoverSprite>):Void {
		for(cover in holdCovers) {
			if(cover != null) {
				if(group != null) group.remove(cover, true);
				cover.destroy();
			}
		}

		holdCovers = [];
	}

	public function refreshHoldCover(lane:Int):Void {
		var cover = getHoldCover(lane);
		if(cover == null) return;

		cover.refreshHold();
		updateHoldCoverPosition(lane);
	}

	public function endHoldCover(lane:Int):Void {
		var cover = getHoldCover(lane);
		if(cover != null) cover.endHold();
	}

	public function killHoldCover(lane:Int):Void {
		var cover = getHoldCover(lane);
		if(cover != null) cover.hideInstant();
	}

	public function updateHoldCovers(?controlHoldArray:Array<Bool>):Void {
		for(lane in 0...holdCovers.length) {
			updateHoldCoverPosition(lane);
		}
	}

	public function updateHoldCoverPosition(lane:Int):Void {
		var cover = getHoldCover(lane);
		var strum = getByIndex(lane);

		if(cover == null || strum == null) return;

		if(!strum.visible) {
			cover.visible = false;
			return;
		}

		if(!cover.visible) return;

		cover.alpha = strum.alpha;
		cover.angle = strum.angle;
		cover.x = strum.x + (strum.width * 0.5) - (cover.width * 0.5) - 8;
		cover.y = strum.y - 96;
	}

	public function resetVisualState():Void {
		strums.forEachAlive(function(strum:Strum) {
			if(strum != null) strum.playAnim("static");
		});
	}

	public function playConfirm(strum:Strum):Void {
		if(strum == null) return;

		strum.playAnim("confirm", true);
		strum.holdTimer = Conductor.instance.stepLengthMs * 1.25 / 1000;
	}

	public function playLaneConfirm(lane:Int):Void {
		playConfirm(getByIndex(lane));
	}

	public function playConfirmHold(strum:Strum):Void {
		if(strum == null) return;

		if(strum.hasDedicatedConfirmHold()) {
			if(strum.getAnimName() == "confirm-hold") {
				return;
			}

			if(strum.getAnimName() == "confirm") {
				if(strum.animation.curAnim != null && strum.animation.curAnim.finished) {
					strum.playAnim("confirm-hold", true);
				}
			}else {
				strum.playAnim("confirm", true);
				strum.holdTimer = 0;
			}
		}else {
			playConfirm(strum);
		}
	}

	public function playLaneConfirmHold(lane:Int):Void {
		playConfirmHold(getByIndex(lane));
	}

	public function getByIndex(index:Int):Strum {
		if(strums == null || index < 0 || index >= strums.members.length) return null;
		return strums.members[index];
	}

	public function getHoldCover(index:Int):HoldCoverSprite {
		if(index < 0 || index >= holdCovers.length) return null;
		return holdCovers[index];
	}

	public function getDirectionName(lane:Int):String {
		if(fifthKey) {
			return switch(lane) {
				case 0: "left";
				case 1: "down";
				case 2: "space";
				case 3: "up";
				case 4: "right";
				default: "";
			}
		}

		return switch(lane) {
			case 0: "left";
			case 1: "down";
			case 2: "up";
			case 3: "right";
			default: "";
		}
	}

	function get_fifthKey():Bool {
		return laneCount == 5;
	}

	function get_x():Float {
		return strums.x;
	}

	function set_x(value:Float):Float {
		return strums.x = value;
	}

	function get_y():Float {
		return strums.y;
	}

	function set_y(value:Float):Float {
		return strums.y = value;
	}

	function get_members():Array<Strum> {
		return strums.members;
	}

	function get_length():Int {
		return strums.length;
	}
}
