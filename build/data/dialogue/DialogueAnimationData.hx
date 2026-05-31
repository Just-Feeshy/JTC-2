package data.dialogue;

/**
 * One animation registered against a dialogue sprite (portrait or speech bubble).
 * `name` is the runtime handle, `prefix` is the Sparrow atlas frame prefix.
 */
typedef DialogueAnimationData = {
    var name:String;
    var prefix:String;

    @:optional
    @:default(24)
    var framerate:Int;

    @:optional
    @:default(false)
    var looped:Bool;

    @:optional
    @:default([])
    var offset:Array<Int>;
}
