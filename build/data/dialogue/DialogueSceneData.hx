package data.dialogue;

/**
 * A single scene (one "page") of dialogue inside a conversation.
 *
 * `text` is a two-slot array kept for legacy compatibility: index 0 is the narrator
 * slot ("left portrait" | "right portrait"), index 1 is the body text. New content
 * should prefer the explicit `narrator` field; the array is filled in for the runtime
 * by the loader.
 */
typedef DialogueSceneData = {
    @:optional
    @:default(1.0)
    var speed:Float;

    @:optional
    var talkingAnimation:String;

    var text:Array<String>;

    @:optional
    @:default("PhantomMuff.ttf")
    var font:String;

    @:optional
    @:default(-16777216)
    var textColor:Int;

    @:optional
    @:default(32)
    var textSize:Int;

    /**
     * Stable name lookup into the sound binding table.
     * Preferred over `soundIndex` for new content.
     */
    @:optional
    var soundName:String;

    @:optional
    @:default(0)
    var soundIndex:Int;

    var leftPortrait:DialogueSpriteData;
    var rightPortrait:DialogueSpriteData;
    var speechBubble:DialogueSpriteData;
}
