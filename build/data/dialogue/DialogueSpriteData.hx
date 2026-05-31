package data.dialogue;

/**
 * Per-scene data for a single dialogue sprite slot (left/right portrait or speech bubble).
 *
 * Asset selection prefers `assetName` (stable across reorders); `assetID` is the legacy
 * positional index into the binding table and is kept as a fallback so old saves still
 * resolve.
 */
typedef DialogueSpriteData = {
    /**
     * Stable name used to look the asset up in the runtime binding table.
     * Preferred over `assetID` for new content.
     */
    @:optional
    var assetName:String;

    /**
     * Legacy positional index into the binding table.
     * `-1` means "no assetID set, use assetName".
     */
    @:optional
    @:default(-1)
    var assetID:Int;

    @:optional
    @:default([])
    var animations:Array<DialogueAnimationData>;

    @:optional
    @:default(1.0)
    var size:Float;

    @:optional
    @:default(0.0)
    var x:Float;

    @:optional
    @:default(0.0)
    var y:Float;
}
