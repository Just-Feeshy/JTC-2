package stageeditor.handlers;

#if FEATURE_STAGE_EDITOR
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;

using StringTools;

/**
 * JTC2-friendly stand-in for Funkin's `funkin.ui.debug.stageeditor.handlers.AssetDataHandler`.
 *
 * Funkin's handler builds a `BitmapData` cache by walking its asset libraries
 * and matches per-pixel against object pixels to recover an `assetPath`. JTC2
 * doesn't have that pipeline; this handler instead lets the editor *list*
 * textures available under the chosen asset folder so the Object Graphic
 * toolbox (pass 6) can populate its dropdown.
 *
 * Object → data serialization lives on `StageEditorObject.toData()` already;
 * data → object lives on `StageEditorObject.fromData()`.
 */
class AssetDataHandler
{
    /**
     * List all `.png` assets under a given OpenFL library/folder prefix.
     * `folder` is a filter like "ui/" or "stages/" — empty returns everything.
     */
    public static function listTextures(folder:String = ""):Array<String>
    {
        var results:Array<String> = [];
        var needle:String = folder == null ? "" : folder.toLowerCase().trim();

        try
        {
            for (assetId in OpenFlAssets.list(AssetType.IMAGE))
            {
                if (assetId == null) continue;
                var lc = assetId.toLowerCase();
                if (!lc.endsWith(".png")) continue;
                if (needle != "" && lc.indexOf(needle) == -1) continue;
                if (!results.contains(assetId)) results.push(assetId);
            }
        }
        catch (e:Dynamic) {}

        results.sort(function(a:String, b:String):Int { return a < b ? -1 : (a > b ? 1 : 0); });
        return results;
    }

    /**
     * Convenience: list textures under a known JTC2 top-level folder.
     */
    public static function listTexturesInLibrary(library:String):Array<String>
    {
        if (library == null || library == "") return listTextures();
        return listTextures("/" + library + "/");
    }

    /**
     * Heuristic check whether an asset id refers to a sparrow atlas
     * (assumes a matching `.xml` exists next to the `.png`).
     */
    public static function isSparrowAtlas(pngAssetId:String):Bool
    {
        if (pngAssetId == null) return false;
        if (!pngAssetId.toLowerCase().endsWith(".png")) return false;
        var xmlAssetId:String = pngAssetId.substr(0, pngAssetId.length - 4) + ".xml";
        return OpenFlAssets.exists(xmlAssetId, AssetType.TEXT);
    }
}
#end
