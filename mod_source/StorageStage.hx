package;

import flixel.group.FlxGroup.FlxTypedGroup;

class StorageStage extends StageBuilder {
    public var characterStorage:FlxTypedGroup<Character>;
    public var noteTagData:Map<String, String>;

    public function new(stage:String) {
        characterStorage = FlxTypedGroup<Character>();
        add(characterStorage);

        noteTagData = new Map<String, String>();

        super(stage);
    }

    public function singCharacter(character:Character):Void {
        
    }

    override function update(elapsed:Float):Void {
        

        super.update(elapsed);
    }

    override function destroy() {
        characterStorage = FlxDestroyUtil.destroy(characterStorage);

        noteTagData.clear();
        noteTagData = null;

        super.destroy();
    }
}