package;

import flixel.FlxCamera;
import flixel.group.FlxGroup.FlxTypedGroup;

class CameraNoteRegularGroup<T:flixel.FlxBasic> extends FlxTypedGroup<T> {
    override public function draw():Void
    {
        @:privateAccess
        var oldDefaultCameras = FlxCamera._defaultCameras;
        var groupCameras = cameras;

        if(groupCameras != null) {
            @:privateAccess
            FlxCamera._defaultCameras = groupCameras;
        }

        var noteCamera:CameraNote = PlayState.camNOTE;

        if(noteCamera != null) {
            noteCamera.beginNotePass();
        }

        for (basic in members)
        {
            if (basic != null && basic.exists && basic.visible)
                basic.draw();
        }

        if(noteCamera != null) {
            noteCamera.flushNotePass();
        }

        @:privateAccess
        FlxCamera._defaultCameras = oldDefaultCameras;
    }
}
