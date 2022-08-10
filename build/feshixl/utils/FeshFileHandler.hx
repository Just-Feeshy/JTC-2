package feshixl.utils;

#if !flash
import haxe.io.Path;
#end

import openfl.net.FileReference;

class FeshFileHandler extends FileReference {
    public var savedFileCallback:(fileName:String, path:String)->Void = null;

    @:noCompletion
    override function saveFileDialog_onSelect(path:String):Void {
        if(savedFileCallback != null) {
            savedFileCallback(Path.withoutDirectory(path), Path.directory(path));
            savedFileCallback = null;
        }

        super.saveFileDialog_onSelect(path);
    }

    @:noCompletion
    override function saveFileDialog_onSave(path:String):Void {
        if(savedFileCallback != null) {
            savedFileCallback(Path.withoutDirectory(path), Path.directory(path));
            savedFileCallback = null;
        }

        super.saveFileDialog_onSave(path);
    }
}