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
    public var characterSinging:Map<String, Bool>;

    public function new(stage:String) {
        super(stage);

        characterStorage = new FlxTypedGroup<Character>();

        noteTagData = new Map<String, String>();
        characterSinging = new Map<String, Bool>();
        characterAnims = ["singLEFT", "singDOWN", "singUP", "singRIGHT"];
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
                characterSinging.set(character.curCharacter, true);
            }else {
                characterSinging.set(character.curCharacter, false);
            }
        }

        super.whenNoteIsPressed(note);
    }

    override function update(elapsed:Float):Void {
        var i:UInt = 0;
        var character:Character = null;

        while(i < characterStorage.length) {
            character = characterStorage.members[i++];

            if(!characterSinging.get(character.curCharacter) && character.animation.finished) {
                character.dance();
            }
        }

        super.update(elapsed);
    }

    override function destroy() {
        super.destroy();

        characterStorage = FlxDestroyUtil.destroy(characterStorage);

        if(noteTagData != null) {
            noteTagData.clear();
        }

        noteTagData = null;
    }
}