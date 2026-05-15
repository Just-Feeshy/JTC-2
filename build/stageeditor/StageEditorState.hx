package stageeditor;

#if FEATURE_STAGE_EDITOR
import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.addons.display.FlxGridOverlay;
import flixel.group.FlxGroup.FlxTypedGroup;
import flixel.text.FlxText;
import flixel.text.FlxText.FlxTextBorderStyle;
import flixel.util.FlxColor;
import haxe.ui.backend.flixel.UIState;
import haxe.ui.core.Screen;
import haxe.ui.containers.windows.WindowManager;
import haxe.ui.containers.dialogs.Dialogs;
import haxe.ui.containers.dialogs.Dialog.DialogButton;
import haxe.ui.containers.dialogs.MessageBox.MessageBoxType;
import haxe.ui.containers.menus.Menu;
import haxe.ui.containers.menus.MenuBar;
import haxe.ui.containers.menus.MenuItem;
import openfl.events.Event;
import openfl.events.IOErrorEvent;
import openfl.net.FileFilter;
import openfl.net.FileReference;
import stageeditor.handlers.StageEditorData;
import stageeditor.handlers.StageEditorData.StageEditorDataModel;
import stageeditor.components.AboutDialog;
import stageeditor.components.FindObjDialog;
import stageeditor.components.NewObjDialog;
import stageeditor.components.UserGuideDialog;
import stageeditor.components.WelcomeDialog;
import stageeditor.handlers.UndoRedoHandler;
import stageeditor.handlers.UndoRedoHandler.UndoAction;
import stageeditor.handlers.UndoRedoHandler.UndoActionType;
import stageeditor.toolboxes.StageEditorCharacterToolbox;
import stageeditor.toolboxes.StageEditorObjectAnimsToolbox;
import stageeditor.toolboxes.StageEditorObjectGraphicToolbox;
import stageeditor.toolboxes.StageEditorObjectPropertiesToolbox;
import stageeditor.toolboxes.StageEditorStageToolbox;

using stageeditor.handlers.UndoRedoHandler;
using stageeditor.handlers.StageDataHandler;

using StringTools;

/**
 * JTC2 port of Funkin's Stage Editor (Option 3 — visual 1:1 via Funkin's XML,
 * implementation rebuilt against JTC2's runtime).
 *
 * Pass 2 (this file): File menu wiring — New, Open, Save, Save As, Clear Assets,
 * Open Recent, Exit. Persistence via openfl.net.FileReference to a plain JSON file
 * (no .fnfs zip; that needs Funkin's asset bundling we don't have).
 */
@:build(haxe.ui.ComponentBuilder.build("assets/exclude/data/ui/stage-editor/main-view.xml"))
class StageEditorState extends UIState
{
    public static final LIGHT_MODE_COLORS:Array<FlxColor> = [0xFFE7E6E6, 0xFFF8F8F8];
    public static final DARK_MODE_COLORS:Array<FlxColor> = [0xFF181919, 0xFF202020];

    // Per-character visualization colors (BF / GF / DAD) — same order as Funkin.
    public static final CHARACTER_COLORS:Array<FlxColor> = [FlxColor.RED, FlxColor.PURPLE, FlxColor.CYAN];

    public static final MAX_Z_INDEX:Int = 10000;

    static inline var SAVE_KEY_RECENT:String = "stageEditorRecent";
    static inline var SAVE_KEY_THEME:String = "stageEditorTheme";
    static inline var MAX_RECENT:Int = 8;

    public static var instance:StageEditorState = null;

    var isDarkMode:Bool = true;

    // ── Cameras (mirrors Funkin) ──────────────────────────────────────────
    var camGame:FlxCamera;
    var camHUD:FlxCamera;
    public var camFollow:FlxObject;

    // ── Visualization sprites ─────────────────────────────────────────────
    var bg:FlxSprite;
    var floorLines:Array<FlxSprite> = [];
    var posCircles:Array<FlxSprite> = [];
    var camFields:FlxTypedGroup<FlxSprite>;
    var camMarker:FlxSprite;
    public var nameTxt:FlxText;

    // Currently-loaded stage data. Always non-null after create().
    var model:StageEditorDataModel;
    // Path/name of the file currently open. Empty string = unsaved/new.
    var currentFile:String = "";
    // Dirty bit. False = no unsaved edits since last save/load.
    var saved:Bool = true;

    var _file:FileReference;
    var _pendingFilename:String = "";

    // Object selection — `selectedSprite` is typed as FlxSprite so the toolbox
    // can read generic FlxSprite properties, but at runtime it's always one of
    // our `StageEditorObject` instances from `spriteArray`.
    public var selectedSprite:FlxSprite = null;
    var selectedZIndex:Int = 0;
    var selectedDanceEvery:Float = 0;

    /** All editor objects placed in the stage. */
    public var spriteArray:Array<StageEditorObject> = [];

    /** Object on the clipboard (set by Copy/Cut, read by Paste). */
    var copiedSpriteData:Dynamic = null;

    /** Undo/redo stacks (read+mutated by UndoRedoHandler extension methods). */
    public var undoArray:Array<UndoAction> = [];
    public var redoArray:Array<UndoAction> = [];

    // Mouse drag state.
    var dragging:Bool = false;
    var dragOffsetX:Float = 0;
    var dragOffsetY:Float = 0;

    // Toolboxes
    var stageToolbox:StageEditorStageToolbox;
    var objectPropertiesToolbox:StageEditorObjectPropertiesToolbox;
    var characterToolbox:StageEditorCharacterToolbox;
    var objectAnimsToolbox:StageEditorObjectAnimsToolbox;
    var objectGraphicToolbox:StageEditorObjectGraphicToolbox;

    public function new()
    {
        super();
    }

    override public function create():Void
    {
        // Restore theme preference from FlxG.save (defaults to dark — matches Funkin).
        isDarkMode = FlxG.save != null && Reflect.field(FlxG.save.data, SAVE_KEY_THEME) != "light";

        // Mirror Funkin's create() order exactly.
        // 1) Cameras: world + HUD.
        camGame = new FlxCamera();
        camHUD = new FlxCamera();
        camHUD.bgColor.alpha = 0;

        FlxG.cameras.reset(camGame);
        FlxG.cameras.add(camHUD, false);
        FlxG.cameras.setDefaultDrawTarget(camGame, true);

        persistentUpdate = false;

        // 2) Checkered background.
        bg = makeGridBackground();
        bg.scrollFactor.set();
        add(bg);

        // 3) UIState.create() — adds haxeui root to the FlxState display list.
        super.create();
        instance = this;

        // 4) Configure root to live in the HUD camera and span the screen.
        root.scrollFactor.set();
        root.cameras = [camHUD];
        root.width = FlxG.width;
        root.height = FlxG.height;
        if (menubar != null) menubar.height = 35;

        try
        {
            WindowManager.instance.container = root;
            Screen.instance.addComponent(root);
        }
        catch (_:Dynamic) {}

        // 5) Per-character visualization overlays (floor lines / position
        //    circles / camera bounds). Hidden by default; View menu toggles them.
        camFields = new FlxTypedGroup<FlxSprite>();
        camFields.visible = false;

        for (i in 0...CHARACTER_COLORS.length)
        {
            var floorLine:FlxSprite = new FlxSprite().makeGraphic(FlxG.width * 10, 15, CHARACTER_COLORS[i]);
            floorLine.screenCenter(X);

            var pointer:FlxSprite = new FlxSprite().makeGraphic(30, 30, CHARACTER_COLORS[i]);

            var field:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, CHARACTER_COLORS[i]);

            pointer.alpha = floorLine.alpha = field.alpha = 0.35;
            pointer.ID = floorLine.ID = field.ID = i;
            pointer.visible = floorLine.visible = false;

            add(floorLine);
            add(pointer);

            floorLines.push(floorLine);
            posCircles.push(pointer);

            camFields.add(field);
        }

        // 6) Camera-focus crosshair marker (Funkin uses GraphicCursorCross; we
        //    draw a simple plus shape in code at the same 80x80 footprint).
        camMarker = makeCrossMarker();
        updateMarkerPos();

        add(camFields);
        add(camMarker);

        // 7) Name-tag text label (rendered on the HUD camera so it ignores zoom).
        nameTxt = new FlxText(0, 0, 0, "", 24);
        nameTxt.setFormat(null, 24, FlxColor.WHITE, LEFT, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
        nameTxt.cameras = [camHUD];
        add(nameTxt);

        // 8) Camera follow object — world camera tracks this.
        camFollow = new FlxObject(0, 0, 2, 2);
        camFollow.screenCenter();
        add(camFollow);
        camGame.follow(camFollow);

        // 9) Model + menu/toolbox wiring (was the rest of pass 2/3).
        model = StageEditorData.makeEmpty();
        wireMenuBar();
        rebuildRecentMenu();
        buildToolboxes();
    }

    // ──────────────────────────────────────────────────────────────────────
    // Background grid + marker helpers
    // ──────────────────────────────────────────────────────────────────────

    function makeGridBackground():FlxSprite
    {
        var c = isDarkMode ? DARK_MODE_COLORS : LIGHT_MODE_COLORS;
        return FlxGridOverlay.create(10, 10, -1, -1, true, c[0], c[1]);
    }

    function makeCrossMarker():FlxSprite
    {
        // 80x80 + symbol: 4px-wide bars centered horizontally and vertically.
        var size:Int = 80;
        var s = new FlxSprite().makeGraphic(size, size, FlxColor.TRANSPARENT);
        var px = s.pixels;
        px.lock();
        var mid:Int = Std.int(size / 2);
        for (i in 0...size)
        {
            px.setPixel32(i, mid - 1, 0xFFFFFFFF);
            px.setPixel32(i, mid, 0xFFFFFFFF);
            px.setPixel32(i, mid + 1, 0xFFFFFFFF);
            px.setPixel32(mid - 1, i, 0xFFFFFFFF);
            px.setPixel32(mid, i, 0xFFFFFFFF);
            px.setPixel32(mid + 1, i, 0xFFFFFFFF);
        }
        px.unlock();
        s.dirty = true;
        return s;
    }

    /**
     * Center the camera-focus marker on the followed camFollow position.
     * Without real characters in the editor (pass 6), this just keeps the
     * crosshair at the camFollow point.
     */
    public function updateMarkerPos():Void
    {
        if (camMarker == null || camFollow == null) return;
        camMarker.x = camFollow.x - camMarker.width / 2;
        camMarker.y = camFollow.y - camMarker.height / 2;
    }

    function applyTheme():Void
    {
        if (bg == null) return;

        var index:Int = members.indexOf(bg);
        bg.kill();
        remove(bg);
        bg.destroy();

        bg = makeGridBackground();
        bg.scrollFactor.set();
        if (index >= 0) members.insert(index, bg);
        else add(bg);

        if (FlxG.save != null)
        {
            Reflect.setField(FlxG.save.data, SAVE_KEY_THEME, isDarkMode ? "dark" : "light");
            FlxG.save.flush();
        }
    }

    // ──────────────────────────────────────────────────────────────────────
    // Selection accessors used by toolboxes
    // ──────────────────────────────────────────────────────────────────────

    public function markDirty():Void
    {
        saved = false;
    }

    public function getSelectedZIndex():Int
    {
        return selectedZIndex;
    }

    public function setSelectedZIndex(z:Int):Void
    {
        selectedZIndex = z;
        // Future pass: re-sort the display list.
    }

    public function getSelectedDanceEvery():Float
    {
        return selectedDanceEvery;
    }

    public function setSelectedDanceEvery(beats:Float):Void
    {
        selectedDanceEvery = beats;
    }

    public function selectSprite(spr:FlxSprite):Void
    {
        // Restore previous selection's tint before swapping.
        var prevObj:StageEditorObject = asEditorObject(selectedSprite);
        if (prevObj != null) prevObj.setSelected(false);

        selectedSprite = spr;

        var nextObj:StageEditorObject = asEditorObject(selectedSprite);
        if (nextObj != null)
        {
            selectedZIndex = nextObj.zIndex;
            selectedDanceEvery = nextObj.danceEvery;
            nextObj.setSelected(true);
        }
        else
        {
            selectedZIndex = 0;
            selectedDanceEvery = 0;
        }

        refreshAllToolboxes();
    }

    function refreshAllToolboxes():Void
    {
        if (stageToolbox != null) stageToolbox.refresh();
        if (objectPropertiesToolbox != null) objectPropertiesToolbox.refresh();
        if (characterToolbox != null) characterToolbox.refresh();
        if (objectAnimsToolbox != null) objectAnimsToolbox.refresh();
        if (objectGraphicToolbox != null) objectGraphicToolbox.refresh();
    }

    // ──────────────────────────────────────────────────────────────────────
    // Toolboxes
    // ──────────────────────────────────────────────────────────────────────

    function buildToolboxes():Void
    {
        stageToolbox = new StageEditorStageToolbox(this);
        objectPropertiesToolbox = new StageEditorObjectPropertiesToolbox(this);
        characterToolbox = new StageEditorCharacterToolbox(this);
        objectAnimsToolbox = new StageEditorObjectAnimsToolbox(this);
        objectGraphicToolbox = new StageEditorObjectGraphicToolbox(this);

        // Bind the View → Windows menu checkboxes to toolbox visibility.
        if (menubarItemWindowStage != null) menubarItemWindowStage.onChange = function(_)
        {
            stageToolbox.toggle(menubarItemWindowStage.selected);
        };
        if (menubarItemWindowObjectProps != null) menubarItemWindowObjectProps.onChange = function(_)
        {
            objectPropertiesToolbox.toggle(menubarItemWindowObjectProps.selected);
        };
        if (menubarItemWindowCharacter != null) menubarItemWindowCharacter.onChange = function(_)
        {
            characterToolbox.toggle(menubarItemWindowCharacter.selected);
        };
        if (menubarItemWindowObjectAnims != null) menubarItemWindowObjectAnims.onChange = function(_)
        {
            objectAnimsToolbox.toggle(menubarItemWindowObjectAnims.selected);
        };
        if (menubarItemWindowObjectGraphic != null) menubarItemWindowObjectGraphic.onChange = function(_)
        {
            objectGraphicToolbox.toggle(menubarItemWindowObjectGraphic.selected);
        };
    }

    // ──────────────────────────────────────────────────────────────────────
    // Menu wiring
    // ──────────────────────────────────────────────────────────────────────

    function wireMenuBar():Void
    {
        // The @:build macro generated typed `menubarItem*` fields from main-view.xml.
        if (menubarItemNewStage != null) menubarItemNewStage.onClick = function(_) onMenuItemClick("new stage");
        if (menubarItemOpenStage != null) menubarItemOpenStage.onClick = function(_) onMenuItemClick("open stage");
        if (menubarItemSaveStage != null) menubarItemSaveStage.onClick = function(_) onMenuItemClick("save stage");
        if (menubarItemSaveStageAs != null) menubarItemSaveStageAs.onClick = function(_) onMenuItemClick("save stage as");
        if (menubarItemClearAssets != null) menubarItemClearAssets.onClick = function(_) onMenuItemClick("clear assets");
        if (menubarItemExit != null) menubarItemExit.onClick = function(_) onMenuItemClick("exit");

        // Edit menu — object operations.
        if (menubarItemNewObj != null) menubarItemNewObj.onClick = function(_) onMenuItemClick("new object");
        if (menubarItemDelete != null) menubarItemDelete.onClick = function(_) onMenuItemClick("delete object");
        if (menubarItemCopy != null) menubarItemCopy.onClick = function(_) onMenuItemClick("copy object");
        if (menubarItemCut != null) menubarItemCut.onClick = function(_) onMenuItemClick("cut object");
        if (menubarItemPaste != null) menubarItemPaste.onClick = function(_) onMenuItemClick("paste object");
        if (menubarItemSelectNone != null) menubarItemSelectNone.onClick = function(_) onMenuItemClick("select none");
        if (menubarItemUndo != null) menubarItemUndo.onClick = function(_) onMenuItemClick("undo");
        if (menubarItemRedo != null) menubarItemRedo.onClick = function(_) onMenuItemClick("redo");

        // Edit menu — Find Object.
        if (menubarItemFindObj != null) menubarItemFindObj.onClick = function(_) onMenuItemClick("find object");

        // Help menu.
        if (menubarItemAbout != null) menubarItemAbout.onClick = function(_) onMenuItemClick("about");
        if (menubarItemUserGuide != null) menubarItemUserGuide.onClick = function(_) onMenuItemClick("user guide");

        // View → Theme (light / dark).
        if (menubarItemThemeLight != null)
        {
            menubarItemThemeLight.selected = !isDarkMode;
            menubarItemThemeLight.onChange = function(_)
            {
                if (menubarItemThemeLight.selected) { isDarkMode = false; applyTheme(); }
            };
        }
        if (menubarItemThemeDark != null)
        {
            menubarItemThemeDark.selected = isDarkMode;
            menubarItemThemeDark.onChange = function(_)
            {
                if (menubarItemThemeDark.selected) { isDarkMode = true; applyTheme(); }
            };
        }

        // View → visibility toggles.
        if (menubarItemViewFloorLines != null) menubarItemViewFloorLines.onChange = function(_)
        {
            for (s in floorLines) if (s != null) s.visible = menubarItemViewFloorLines.selected;
        };
        if (menubarItemViewPosMarkers != null) menubarItemViewPosMarkers.onChange = function(_)
        {
            for (s in posCircles) if (s != null) s.visible = menubarItemViewPosMarkers.selected;
        };
        if (menubarItemViewCamBounds != null) menubarItemViewCamBounds.onChange = function(_)
        {
            if (camFields != null) camFields.visible = menubarItemViewCamBounds.selected;
        };
        if (menubarItemViewNameText != null) menubarItemViewNameText.onChange = function(_)
        {
            if (nameTxt != null) nameTxt.visible = menubarItemViewNameText.selected;
        };
    }

    public function onMenuItemClick(item:String):Void
    {
        switch (item.toLowerCase())
        {
            case "new stage":
                doNewStage();
            case "open stage":
                doOpenStage();
            case "save stage":
                doSaveStage();
            case "save stage as":
                doSaveStageAs();
            case "clear assets":
                doClearAssets();
            case "exit":
                doExit();
            case "new object":
                doNewObject();
            case "delete object":
                doDeleteObject();
            case "copy object":
                doCopyObject();
            case "cut object":
                doCopyObject();
                doDeleteObject();
            case "paste object":
                doPasteObject();
            case "select none":
                selectSprite(null);
            case "undo":
                this.performLastAction(false);
                refreshAllToolboxes();
            case "redo":
                this.performLastAction(true);
                refreshAllToolboxes();
            case "find object":
                showFindObject();
            case "about":
                showAbout();
            case "user guide":
                showUserGuide();
            default:
                // unhandled; future passes wire the rest
        }
    }

    // ──────────────────────────────────────────────────────────────────────
    // File operations
    // ──────────────────────────────────────────────────────────────────────

    function doNewStage():Void
    {
        confirmIfDirty("Starting a new stage will discard unsaved changes. Continue?", function()
        {
            model = StageEditorData.makeEmpty();
            currentFile = "";
            saved = true;
            updateAfterDataChange();
        });
    }

    function doOpenStage():Void
    {
        confirmIfDirty("Opening another stage will discard unsaved changes. Continue?", function()
        {
            destroyFileReference();
            _file = new FileReference();
            _file.addEventListener(Event.SELECT, onLoadSelect);
            _file.addEventListener(Event.COMPLETE, onLoadComplete);
            _file.addEventListener(IOErrorEvent.IO_ERROR, onIOError);

            _file.browse([new FileFilter("Stage JSON", "*." + StageEditorData.FILE_EXTENSION + ";*.json")]);
        });
    }

    function doSaveStage():Void
    {
        // Without Funkin's FileUtil.writeBytesToPath we can't silently overwrite a
        // path — FileReference always prompts. So "Save" falls through to "Save As"
        // unless we know the path is the same as last save (file dialog will pick
        // up the same name by default).
        if (currentFile == "")
        {
            doSaveStageAs();
            return;
        }

        doSaveAs(currentFile);
    }

    function doSaveStageAs():Void
    {
        var filename:String = (model.stageName == null || model.stageName == "") ? "untitled" : model.stageName;
        doSaveAs(filename + "." + StageEditorData.FILE_EXTENSION);
    }

    function doSaveAs(filename:String):Void
    {
        var data:String = StageEditorData.toJson(model);

        destroyFileReference();
        _pendingFilename = filename;
        _file = new FileReference();
        _file.addEventListener(Event.COMPLETE, onSaveComplete);
        _file.addEventListener(IOErrorEvent.IO_ERROR, onIOError);
        _file.save(data, filename);
    }

    function doClearAssets():Void
    {
        Dialogs.messageBox("This will destroy all objects in this stage.\n\nAre you sure? This cannot be undone.",
            "Clear Assets", MessageBoxType.TYPE_YESNO, true, function(btn:DialogButton)
            {
                if (btn != DialogButton.YES) return;

                clearAllObjects();
                model.objects = [];
                model.characters = [];
                saved = false;
                updateAfterDataChange();
            });
    }

    // ──────────────────────────────────────────────────────────────────────
    // Object operations
    // ──────────────────────────────────────────────────────────────────────

    function doNewObject():Void
    {
        // Prompt for a name via the same XML-driven dialog Funkin uses.
        var dlg = new NewObjDialog(this);
        dlg.showDialog();
    }

    function showFindObject():Void
    {
        var dlg = new FindObjDialog(this);
        dlg.showDialog();
    }

    function showAbout():Void
    {
        var dlg = new AboutDialog();
        dlg.showDialog();
    }

    function showUserGuide():Void
    {
        var dlg = new UserGuideDialog();
        dlg.showDialog();
    }

    // ──────────────────────────────────────────────────────────────────────
    // Public hooks for dialog components
    // ──────────────────────────────────────────────────────────────────────

    /**
     * Resets the in-memory stage to a fresh empty model without re-prompting
     * the dirty-bit check. Used by `WelcomeDialog` since it has already shown
     * its own prompt.
     */
    public function doNewStageFromDialog():Void
    {
        clearAllObjects();
        model = StageEditorData.makeEmpty();
        currentFile = "";
        saved = true;
        updateAfterDataChange();
    }

    /** Exposed wrapper around the private recent-files cache for WelcomeDialog. */
    public function loadRecentFilesPublic():Array<String>
    {
        return loadRecentFiles();
    }

    /** Open a file by path (desktop only). No-op on web. */
    public function openRecentByPath(path:String):Void
    {
        #if sys
        try
        {
            var raw:String = sys.io.File.getContent(path);
            this.applyJson(raw);
            currentFile = path;
            saved = true;
            updateAfterDataChange();
        }
        catch (e:Dynamic)
        {
            trace("StageEditor: failed to load '" + path + "': " + Std.string(e));
        }
        #end
    }

    function doDeleteObject():Void
    {
        if (selectedSprite == null) return;
        var obj:StageEditorObject = asEditorObject(selectedSprite);
        if (obj == null) return;

        this.createAndPushAction(OBJECT_DELETED, false);

        spriteArray.remove(obj);
        remove(obj, true);
        obj.kill();
        obj.destroy();

        selectSprite(null);
        markDirty();
    }

    function doCopyObject():Void
    {
        if (selectedSprite == null) return;
        var obj:StageEditorObject = asEditorObject(selectedSprite);
        if (obj == null) return;
        copiedSpriteData = obj.toData();
    }

    function doPasteObject():Void
    {
        if (copiedSpriteData == null) return;

        var obj:StageEditorObject = new StageEditorObject();
        obj.fromData(copiedSpriteData);
        obj.makeGraphic(64, 64, 0xFFFFFFFF);
        obj.name = uniqueName(obj.name);
        // Nudge so the copy is visible alongside the original.
        obj.x += 20;
        obj.y += 20;

        spriteArray.push(obj);
        add(obj);
        selectSprite(obj);
        markDirty();
    }

    function clearAllObjects():Void
    {
        for (obj in spriteArray.copy())
        {
            remove(obj, true);
            obj.kill();
            obj.destroy();
        }
        spriteArray = [];
        selectSprite(null);
    }

    function uniqueName(base:String):String
    {
        if (base == null || base == "") base = "object";

        var taken:Array<String> = [for (o in spriteArray) o.name];
        if (!taken.contains(base)) return base;

        var i:Int = 1;
        while (taken.contains(base + " (" + i + ")")) i++;
        return base + " (" + i + ")";
    }

    function asEditorObject(spr:FlxSprite):StageEditorObject
    {
        return Std.isOfType(spr, StageEditorObject) ? cast spr : null;
    }

    function doExit():Void
    {
        confirmIfDirty("You have unsaved changes. Leave the editor anyway?", function()
        {
            FlxG.switchState(new OptionsMenuState("editors"));
        });
    }

    function confirmIfDirty(prompt:String, onConfirm:Void->Void):Void
    {
        if (saved)
        {
            onConfirm();
            return;
        }

        Dialogs.messageBox(prompt, "Unsaved Changes", MessageBoxType.TYPE_YESNO, true, function(btn:DialogButton)
        {
            if (btn == DialogButton.YES) onConfirm();
        });
    }

    // ──────────────────────────────────────────────────────────────────────
    // FileReference callbacks
    // ──────────────────────────────────────────────────────────────────────

    function onLoadSelect(_):Void
    {
        try
        {
            _file.load();
        }
        catch (e:Dynamic)
        {
            trace("StageEditor: load select failed: " + Std.string(e));
        }
    }

    function onLoadComplete(_):Void
    {
        if (_file == null || _file.data == null)
        {
            trace("StageEditor: load complete but no data");
            destroyFileReference();
            return;
        }

        var raw:String = _file.data.toString();
        model = StageEditorData.fromJson(raw);
        currentFile = _file.name;
        saved = true;

        pushRecentFile(currentFile);
        rebuildRecentMenu();
        destroyFileReference();
        updateAfterDataChange();
    }

    function onSaveComplete(_):Void
    {
        currentFile = _pendingFilename;
        saved = true;

        pushRecentFile(currentFile);
        rebuildRecentMenu();
        destroyFileReference();
    }

    function onIOError(_):Void
    {
        trace("StageEditor: file IO error");
        destroyFileReference();
    }

    function destroyFileReference():Void
    {
        if (_file == null) return;
        try
        {
            _file.removeEventListener(Event.SELECT, onLoadSelect);
            _file.removeEventListener(Event.COMPLETE, onLoadComplete);
            _file.removeEventListener(Event.COMPLETE, onSaveComplete);
            _file.removeEventListener(IOErrorEvent.IO_ERROR, onIOError);
        }
        catch (_:Dynamic) {}
        _file = null;
    }

    // ──────────────────────────────────────────────────────────────────────
    // Recent files
    // ──────────────────────────────────────────────────────────────────────

    function loadRecentFiles():Array<String>
    {
        if (FlxG.save == null || FlxG.save.data == null) return [];
        var raw:Dynamic = Reflect.field(FlxG.save.data, SAVE_KEY_RECENT);
        if (raw == null || !Std.isOfType(raw, Array)) return [];
        return cast raw;
    }

    function pushRecentFile(name:String):Void
    {
        if (name == null || name.trim() == "") return;
        var recent:Array<String> = loadRecentFiles();
        recent.remove(name);
        recent.unshift(name);
        while (recent.length > MAX_RECENT) recent.pop();

        Reflect.setField(FlxG.save.data, SAVE_KEY_RECENT, recent);
        FlxG.save.flush();
    }

    function rebuildRecentMenu():Void
    {
        if (menubarItemOpenRecent == null) return;

        // Clear existing items.
        try
        {
            while (menubarItemOpenRecent.childComponents.length > 0)
                menubarItemOpenRecent.removeComponent(menubarItemOpenRecent.childComponents[0]);
        }
        catch (_:Dynamic) {}

        var recent:Array<String> = loadRecentFiles();
        if (recent.length == 0)
        {
            var placeholder:MenuItem = new MenuItem();
            placeholder.text = "(no recent files)";
            placeholder.disabled = true;
            menubarItemOpenRecent.addComponent(placeholder);
            return;
        }

        for (path in recent)
        {
            var item:MenuItem = new MenuItem();
            item.text = path;
            // FileReference can only browse — there's no way to open by path
            // (sandboxed), so for now Recent only documents history. Future:
            // resolve `path` via sys.io.File if `#if sys`.
            item.disabled = !canOpenByPath();
            #if sys
            var captured:String = path;
            item.onClick = function(_)
            {
                confirmIfDirty("Open recent file? Unsaved changes will be lost.", function()
                {
                    try
                    {
                        var raw:String = sys.io.File.getContent(captured);
                        model = StageEditorData.fromJson(raw);
                        currentFile = captured;
                        saved = true;
                        updateAfterDataChange();
                    }
                    catch (e:Dynamic)
                    {
                        trace("StageEditor: failed to load recent file '" + captured + "': " + Std.string(e));
                    }
                });
            };
            #end
            menubarItemOpenRecent.addComponent(item);
        }
    }

    inline function canOpenByPath():Bool
    {
        #if sys
        return true;
        #else
        return false;
        #end
    }

    // ──────────────────────────────────────────────────────────────────────
    // Update hook (toolboxes plug in here in later passes)
    // ──────────────────────────────────────────────────────────────────────

    function updateAfterDataChange():Void
    {
        refreshAllToolboxes();
    }

    // ──────────────────────────────────────────────────────────────────────
    // Update / destroy
    // ──────────────────────────────────────────────────────────────────────

    override public function update(elapsed:Float):Void
    {
        super.update(elapsed);

        handleKeyboardShortcuts();
        handleMouse();
    }

    // ──────────────────────────────────────────────────────────────────────
    // Mouse pick & drag
    // ──────────────────────────────────────────────────────────────────────

    var dragStartX:Float = 0;
    var dragStartY:Float = 0;

    function handleMouse():Void
    {
        if (mouseOverUI()) return;

        if (FlxG.mouse.justPressed)
        {
            var picked:StageEditorObject = pickObjectAtMouse();
            if (picked != null)
            {
                selectSprite(picked);
                dragging = true;
                dragOffsetX = FlxG.mouse.x - picked.x;
                dragOffsetY = FlxG.mouse.y - picked.y;
                dragStartX = picked.x;
                dragStartY = picked.y;
            }
            else
            {
                selectSprite(null);
            }
        }

        if (dragging && FlxG.mouse.pressed && selectedSprite != null)
        {
            selectedSprite.x = FlxG.mouse.x - dragOffsetX;
            selectedSprite.y = FlxG.mouse.y - dragOffsetY;
            if (objectPropertiesToolbox != null) objectPropertiesToolbox.refresh();
            markDirty();
        }

        if (dragging && FlxG.mouse.justReleased)
        {
            // Only push an undo record if the object actually moved.
            if (selectedSprite != null
                && (selectedSprite.x != dragStartX || selectedSprite.y != dragStartY))
            {
                // Temporarily restore the start position so createAndPushAction
                // captures the *previous* coords (undo target), then restore the
                // current position.
                var curX = selectedSprite.x;
                var curY = selectedSprite.y;
                selectedSprite.x = dragStartX;
                selectedSprite.y = dragStartY;
                this.createAndPushAction(OBJECT_MOVED, false);
                selectedSprite.x = curX;
                selectedSprite.y = curY;
            }
            dragging = false;
        }
    }

    function pickObjectAtMouse():StageEditorObject
    {
        // Iterate in reverse so the top-most (z-index-wise) is picked first.
        var i:Int = spriteArray.length - 1;
        while (i >= 0)
        {
            var obj:StageEditorObject = spriteArray[i];
            if (obj != null && obj.alive && obj.visible && pointInsideSprite(obj, FlxG.mouse.x, FlxG.mouse.y))
                return obj;
            i--;
        }
        return null;
    }

    inline function pointInsideSprite(spr:FlxSprite, px:Float, py:Float):Bool
    {
        return px >= spr.x && px <= spr.x + spr.width
            && py >= spr.y && py <= spr.y + spr.height;
    }

    function mouseOverUI():Bool
    {
        // Menubar is always interactive UI; skip canvas picks in the top strip.
        if (FlxG.mouse.screenY <= 35) return true;

        if (toolboxContainsScreenPoint(stageToolbox)) return true;
        if (toolboxContainsScreenPoint(objectPropertiesToolbox)) return true;
        if (toolboxContainsScreenPoint(characterToolbox)) return true;
        if (toolboxContainsScreenPoint(objectAnimsToolbox)) return true;
        if (toolboxContainsScreenPoint(objectGraphicToolbox)) return true;
        return false;
    }

    inline function toolboxContainsScreenPoint(tb:stageeditor.toolboxes.StageEditorDefaultToolbox):Bool
    {
        if (tb == null || !tb.dialogVisible) return false;
        var sx:Float = FlxG.mouse.screenX;
        var sy:Float = FlxG.mouse.screenY;
        return sx >= tb.screenLeft && sx <= tb.screenLeft + tb.width
            && sy >= tb.screenTop && sy <= tb.screenTop + tb.height;
    }

    function handleKeyboardShortcuts():Void
    {
        if (FlxG.keys.justPressed.ESCAPE)
        {
            onMenuItemClick("exit");
            return;
        }

        if (!pressingControl()) return;

        if (FlxG.keys.justPressed.N) onMenuItemClick("new stage");
        if (FlxG.keys.justPressed.O) onMenuItemClick("open stage");
        if (FlxG.keys.justPressed.S)
        {
            if (FlxG.keys.pressed.SHIFT) onMenuItemClick("save stage as");
            else onMenuItemClick("save stage");
        }
        if (FlxG.keys.justPressed.Q) onMenuItemClick("exit");
    }

    inline function pressingControl():Bool
    {
        // Flixel doesn't expose META; on Mac the cmd key reports as WINDOWS.
        return FlxG.keys.pressed.CONTROL #if mac || FlxG.keys.pressed.WINDOWS #end;
    }

    override public function destroy():Void
    {
        destroyFileReference();
        instance = null;
        super.destroy();
    }
}
#end
