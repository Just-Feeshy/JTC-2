package feshixl.group;

import flixel.FlxBasic;
import flixel.util.FlxDestroyUtil.IFlxDestroyable;

import PlayState;

@:access(PlayState)
interface IFeshEvent {
    public function whenTriggered(eventName:String, eventValue:String, eventValue2:String, playState:PlayState):Void;
    public function whenGameIsRunning(activeEvents:Array<String>, playState:PlayState):Void;
    public function whenNoteIsPressed(note:Note, playState:PlayState):Void;
}

/**
* DONT RECOMMEND STORING THE `playstate` IN A VARIABLE!
**/
class FeshEventGroup implements IFeshEvent implements IFlxDestroyable {
    /**
	* `Array` of all the members in this group.
	*/
    public var members(default, null):Array<IFeshEvent>;

    public function new(?members:Array<IFeshEvent> = null) {
        if(members != null)
            this.members = members;
        else
            this.members = [];
    }
    
    /**
    * @param playState Basically get the entire main game.
    */
    public function whenTriggered(eventName:String, eventValue:String, eventValue2:String, playState:PlayState):Void {
        /**
        * `while` is the fastest and most efficient way I can think of making this.
        */

        if(members != null) {
            var i:Int = 0;
            var basic:IFeshEvent = null;

            while (i < members.length) {
                basic = members[i];

                if (basic != null)
                    basic.whenTriggered(eventName, eventValue, eventValue2, playState);

                i++;
            }
        }
    }

    /**
    * Basically control how the object is updated.
    * @param playState Basically get the entire main game.
    **/
    public function whenGameIsRunning(activeEvents:Array<String>, playState:PlayState):Void {
        /**
        * `while` is the fastest and most efficient way I can think of making this.
        */

        if(members != null) {
            var i:Int = 0;
            var basic:IFeshEvent = null;

            while (i < members.length) {
                basic = members[i];

                if (basic != null)
                    basic.whenGameIsRunning(activeEvents, playState);

                i++;
            }
        }
    }

    /**
    * @param note If a note from either the player or opponent side get's hit. 
    **/
    public function whenNoteIsPressed(note:Note, playState:PlayState):Void {
        /**
        * `while` is the fastest and most efficient way I can think of making this.
        */

        if(members != null) {
            var i:Int = 0;
            var basic:IFeshEvent = null;

            while (i < members.length) {
                basic = members[i];

                if (basic != null)
                    basic.whenNoteIsPressed(note, playState);

                i++;
            }
        }
    }

    /*
    * @param Object The object you want to add to the group.
	* @return The same `IFeshEvent` interface that was passed in.
	*/
    public function add(Object:IFeshEvent):IFeshEvent {
        if (Object == null)
            return null;

        // Don't bother adding an object twice.
		if (members.indexOf(Object) >= 0)
			return Object;

        members.push(Object);

        return Object;
    }

    /**
    * Removes an object from the group.
    *
    * @param   Object   The `IFeshEvent` you want to remove.
    * @param   Splice   Whether the object should be cut from the array entirely or not.
    * @return  The removed object.
    */
    public function remove(Object:IFeshEvent, ?Splice:Bool = true):Void {
        if (members == null)
			return;

        var index:Int = members.indexOf(Object);

        if (index < 0)
			return;

        if(Splice)
            members.splice(index, 1);
        else
            members[index] = null;
    }

    public function destroy():Void {
        if (members != null) {
            var i:Int = 0;
            var basic:Dynamic = null;

            while (i < members.length) {
                basic = members[i];

                if(basic is IFlxDestroyable) {
                    basic.destroy();
                }

                if (basic != null) {
                    basic = null;
                    members.remove(basic);
                }

                i++;
            }

            members = null;
        }
    }
}