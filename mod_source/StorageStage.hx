package;

import template.StageBuilder;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.util.FlxDestroyUtil;

/*
* Custom made stage for JTC. hehe.
*/
class StorageStage extends StageBuilder {
    public var characterStorage:FlxTypedGroup<Character>;
    public var noteTagData:Map<String, String>;

    public var characterAnims:Array<String>;

    public function new(stage:String) {
        characterStorage = new FlxTypedGroup<Character>();
        add(characterStorage);

        noteTagData = new Map<String, String>();
        characterAnims = ["singLEFT", "singDOWN", "singUP", "singRIGHT"];

        super(stage);
    }

    public function singCharacter(character:Character, noteData:Int, isSustain:Bool):Void {
        if(!isSustain || (isSustain && character.dancing)) {
            character.playNoDanceAnim(characterAnims[noteData]);
        }

        character.holdTimer = 0;
    }

    override function whenNoteIsPressed(note:Note):Void {
        var i:UInt = 0;
        var character:Character = null;

        while(i < characterStorage.length) {
            character = characterStorage.members[i++];

            if(noteTagData.get(character.curCharacter) == note.tag) {
                singCharacter(character, note.noteData, note.isSustainNote);
            }
        }

        super.whenNoteIsPressed(note);
    }

    override function destroy() {
        characterStorage = FlxDestroyUtil.destroy(characterStorage);

        noteTagData.clear();
        noteTagData = null;

        super.destroy();
    }
}