package data.dialogue;

/**
 * A catalog entry describing a sprite asset the conversation needs at runtime.
 * Editor saves the path; runtime mods may also bind by code without a catalog entry.
 */
typedef DialogueAssetEntry = {
    var name:String;

    @:optional
    var spritePath:String;

    @:optional
    var xmlPath:String;
}

/**
 * A catalog entry describing a sound asset the conversation needs at runtime.
 */
typedef DialogueSoundEntry = {
    var name:String;

    @:optional
    var path:String;
}

/**
 * Top-level conversation save format produced by DialogueCreatorState and consumed by
 * the in-game DialogueBuilder.
 *
 * Format `version` is required on new saves and used by `LegacyDialogueAdapter` to
 * decide whether incoming JSON needs to be migrated up from the v1 `DialogueInfo` shape.
 */
typedef ConversationData = {
    @:optional
    @:default("2.0.0")
    var version:String;

    var scenes:Array<DialogueSceneData>;

    @:optional
    @:default([])
    var assetCatalog:Array<DialogueAssetEntry>;

    @:optional
    @:default([])
    var soundCatalog:Array<DialogueSoundEntry>;
}
