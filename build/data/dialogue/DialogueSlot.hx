package data.dialogue;

/**
 * Identifies one of the three sprite slots a dialogue scene addresses.
 * Replaces the loose `"speech bubble" | "left portrait" | "right portrait"` strings
 * that used to be scattered through DialogueCreatorState and DialogueBuilder.
 */
enum abstract DialogueSlot(String) from String to String {
    var SpeechBubble = "speech bubble";
    var LeftPortrait = "left portrait";
    var RightPortrait = "right portrait";

    public static final ALL:Array<DialogueSlot> = [SpeechBubble, LeftPortrait, RightPortrait];

    public inline function label():String return (this : String);
}
