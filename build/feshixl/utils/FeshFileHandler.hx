package feshixl.utils;

#if !flash
import haxe.io.Path;
#end

import openfl.net.FileReference;

class FeshFileHandler extends FileReference {
    var fileSavedName:String = "";

    @:noCompletion
    override function saveFileDialog_onSelect(path:String):Void {
        #if desktop
		fileSavedName = Path.withoutDirectory(path);
        #end

        super.saveFileDialog_onSelect(path);
    }
}