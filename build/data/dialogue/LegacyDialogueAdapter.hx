package data.dialogue;

import data.dialogue.ConversationData.DialogueAssetEntry;
import data.dialogue.ConversationData.DialogueSoundEntry;

/**
 * Bridges the v1 `DialogueInfo` JSON shape (root keys: `info`, `totalSprites`,
 * `totalSounds`) to the v2 `ConversationData` shape (root keys: `version`, `scenes`,
 * `assetCatalog`, `soundCatalog`).
 *
 * The runtime and editor both call `up()` on parse; new files are returned
 * unchanged, legacy files are upgraded in memory. The v1 root carried inline
 * sprite/xml `Bytes` which the new format does not — those are dropped here, since
 * every shipped mod resolves assets via `bindAssetToID` / `bindAssetToName` rather
 * than via embedded bytes.
 */
class LegacyDialogueAdapter {
    public static function up(raw:Dynamic):ConversationData {
        if (raw == null) return null;

        if (Reflect.hasField(raw, "scenes")) {
            // Already v2 (or close enough — let json2object defaults fill gaps).
            return cast raw;
        }

        if (!Reflect.hasField(raw, "info")) {
            return cast raw;
        }

        return upgradeV1(raw);
    }

    static function upgradeV1(legacy:Dynamic):ConversationData {
        var legacyInfo:Array<Dynamic> = Reflect.field(legacy, "info");
        if (legacyInfo == null) legacyInfo = [];

        var scenes:Array<DialogueSceneData> = [];
        for (entry in legacyInfo) scenes.push(convertScene(entry));

        var assetCatalog:Array<DialogueAssetEntry> = [];
        var legacyTotalSprites:Array<Dynamic> = Reflect.field(legacy, "totalSprites");
        if (legacyTotalSprites != null) {
            for (entry in legacyTotalSprites) {
                var name:String = Reflect.field(entry, "name");
                if (name == null) continue;
                assetCatalog.push({
                    name: name,
                    spritePath: nullableString(Reflect.field(entry, "spritePath")),
                    xmlPath: nullableString(Reflect.field(entry, "xmlPath"))
                });
            }
        }

        // v1 stored sounds as base64/inline Bytes; we deliberately drop them. The
        // runtime DialogueBuilder will resolve sounds via bindSoundToID / catalog path.
        var soundCatalog:Array<DialogueSoundEntry> = [];

        return {
            version: "2.0.0",
            scenes: scenes,
            assetCatalog: assetCatalog,
            soundCatalog: soundCatalog
        };
    }

    static function convertScene(raw:Dynamic):DialogueSceneData {
        return {
            speed: numberOr(raw, "speed", 1.0),
            talkingAnimation: nullableString(Reflect.field(raw, "talkingAnimation")),
            text: cast (Reflect.field(raw, "text") ?? ["", ""]),
            font: stringOr(raw, "font", "PhantomMuff.ttf"),
            textColor: intOr(raw, "textColor", 0xFF000000),
            textSize: intOr(raw, "textSize", 32),
            soundIndex: intOr(raw, "soundIndex", 0),
            leftPortrait: convertSprite(Reflect.field(raw, "leftPortrait")),
            rightPortrait: convertSprite(Reflect.field(raw, "rightPortrait")),
            speechBubble: convertSprite(Reflect.field(raw, "speechBubble"))
        };
    }

    static function convertSprite(raw:Dynamic):DialogueSpriteData {
        if (raw == null) {
            return {assetID: -1, animations: [], size: 1.0, x: 0, y: 0};
        }

        var anims:Array<DialogueAnimationData> = [];
        var rawAnims:Array<Dynamic> = Reflect.field(raw, "animations");
        if (rawAnims != null) {
            for (a in rawAnims) {
                anims.push({
                    name: stringOr(a, "name", ""),
                    prefix: stringOr(a, "prefix", ""),
                    framerate: intOr(a, "framerate", 24),
                    looped: boolOr(a, "looped", false),
                    offset: cast (Reflect.field(a, "offset") ?? [])
                });
            }
        }

        return {
            assetID: intOr(raw, "assetID", -1),
            animations: anims,
            size: numberOr(raw, "size", 1.0),
            x: numberOr(raw, "x", 0),
            y: numberOr(raw, "y", 0)
        };
    }

    static inline function nullableString(v:Dynamic):String {
        return (v == null || (v is String && (v : String) == "")) ? null : Std.string(v);
    }

    static inline function stringOr(obj:Dynamic, field:String, fallback:String):String {
        var v = Reflect.field(obj, field);
        return (v == null) ? fallback : Std.string(v);
    }

    static inline function intOr(obj:Dynamic, field:String, fallback:Int):Int {
        var v = Reflect.field(obj, field);
        if (v == null) return fallback;
        if (v is Int) return (v : Int);
        if (v is Float) return Std.int(v);
        var parsed = Std.parseInt(Std.string(v));
        return parsed == null ? fallback : parsed;
    }

    static inline function numberOr(obj:Dynamic, field:String, fallback:Float):Float {
        var v = Reflect.field(obj, field);
        if (v == null) return fallback;
        if (v is Float || v is Int) return (v : Float);
        var parsed = Std.parseFloat(Std.string(v));
        return Math.isNaN(parsed) ? fallback : parsed;
    }

    static inline function boolOr(obj:Dynamic, field:String, fallback:Bool):Bool {
        var v = Reflect.field(obj, field);
        return v == null ? fallback : (v == true);
    }
}
