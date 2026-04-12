package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxTimer;

class BaseGameOptionsSyncState extends MusicBeatState {
    private var returnCatalog:Null<String>;
    private var promptChoices:Array<String> = [];
    private var promptItems:Array<FlxText> = [];
    private var curSelected:Int = 0;
    private var hasSyncableOptions:Bool = false;
    private var awaitingTransition:Bool = false;

    private var titleText:FlxText;
    private var bodyText:FlxText;
    private var footerText:FlxText;
    private var statusText:FlxText;

    public function new(?returnCatalog:String = null) {
        this.returnCatalog = returnCatalog;
        super("void", "void");
    }

    override function create():Void {
        PlayerSettings.init();
        FlxG.mouse.visible = false;
        hasSyncableOptions = SaveData.hasBaseGameOptionsToImport();

        var bg:FlxSprite = new FlxSprite().makeGraphic(FlxG.width, FlxG.height, FlxColor.BLACK);
        add(bg);

        titleText = new FlxText(0, 90, FlxG.width, hasSyncableOptions
            ? "SYNC OPTIONS FROM BASE FNF?"
            : "NO BASE FNF OPTIONS FOUND", 40);
        titleText.setFormat(Paths.font("OpenSans-Bold.ttf"), 40, FlxColor.WHITE, CENTER);
        add(titleText);

        bodyText = new FlxText(120, 210, FlxG.width - 240, getBodyText(), 28);
        bodyText.setFormat(Paths.font("OpenSans-Regular.ttf"), 28, FlxColor.WHITE, CENTER);
        add(bodyText);

        statusText = new FlxText(120, 390, FlxG.width - 240, "", 24);
        statusText.setFormat(Paths.font("OpenSans-Bold.ttf"), 24, 0xFF9AD7FF, CENTER);
        add(statusText);

        promptChoices = hasSyncableOptions
            ? ["YES, IMPORT THEM", returnCatalog == null ? "NO, KEEP THIS MOD SEPARATE" : "BACK"]
            : ["BACK"];

        for(i in 0...promptChoices.length) {
            var optionText = new FlxText(0, 470 + (i * 55), FlxG.width, promptChoices[i], 30);
            optionText.setFormat(Paths.font("OpenSans-Bold.ttf"), 30, FlxColor.WHITE, CENTER);
            promptItems.push(optionText);
            add(optionText);
        }

        footerText = new FlxText(0, FlxG.height - 70, FlxG.width, getFooterText(), 20);
        footerText.setFormat(Paths.font("OpenSans-Regular.ttf"), 20, 0xFFBEBEBE, CENTER);
        add(footerText);

        updateSelection();
        super.create();
    }

    override function update(elapsed:Float):Void {
        if(awaitingTransition) {
            super.update(elapsed);
            return;
        }

        var previousPressed:Bool = controls.UP_P || controls.LEFT_P || FlxG.keys.justPressed.LEFT || FlxG.keys.justPressed.UP;
        var nextPressed:Bool = controls.DOWN_P || controls.RIGHT_P || FlxG.keys.justPressed.RIGHT || FlxG.keys.justPressed.DOWN;
        var acceptPressed:Bool = controls.ACCEPT || FlxG.keys.justPressed.ENTER || FlxG.keys.justPressed.SPACE;
        var backPressed:Bool = controls.BACK || FlxG.keys.justPressed.ESCAPE;

        if(hasSyncableOptions && FlxG.keys.justPressed.Y) {
            curSelected = 0;
            confirmSelection();
        } else if(hasSyncableOptions && FlxG.keys.justPressed.N) {
            curSelected = promptChoices.length - 1;
            confirmSelection();
        } else {
            if(promptChoices.length > 1) {
                if(previousPressed) {
                    curSelected = (curSelected - 1 + promptChoices.length) % promptChoices.length;
                    FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);
                    updateSelection();
                }

                if(nextPressed) {
                    curSelected = (curSelected + 1) % promptChoices.length;
                    FlxG.sound.play(Paths.sound("scrollMenu"), 0.4);
                    updateSelection();
                }
            }

            if(acceptPressed) {
                confirmSelection();
            } else if(backPressed) {
                curSelected = promptChoices.length - 1;
                confirmSelection();
            }
        }

        super.update(elapsed);
    }

    private function confirmSelection():Void {
        awaitingTransition = true;

        if(hasSyncableOptions && curSelected == 0) {
            var imported:Bool = SaveData.importBaseGameOptions();
            statusText.text = imported
                ? "Imported compatible options from base Friday Night Funkin'."
                : "No compatible options were imported.";
            FlxG.sound.play(Paths.sound("confirmMenu"), 0.7);
        } else {
            if(returnCatalog == null) {
                SaveData.markBaseGameSyncPromptSeen(false);
            }

            statusText.text = hasSyncableOptions
                ? "Keeping this mod's current options."
                : "Returning without importing anything.";
            FlxG.sound.play(Paths.sound("cancelMenu"), 0.7);
        }

        new FlxTimer().start(0.8, function(_:FlxTimer) {
            if(returnCatalog != null) {
                FlxG.switchState(new OptionsMenuState(returnCatalog));
            } else {
                FlxG.switchState(new TitleState());
            }
        });
    }

    private function updateSelection():Void {
        for(i in 0...promptItems.length) {
            var isSelected:Bool = i == curSelected;
            promptItems[i].color = isSelected ? 0xFF9AD7FF : FlxColor.WHITE;
            promptItems[i].alpha = isSelected ? 1 : 0.65;
        }
    }

    private function getBodyText():String {
        if(hasSyncableOptions) {
            return returnCatalog == null
                ? "A compatible Friday Night Funkin save was found. Import its gameplay and display options into this project's save before continuing?"
                : "Import compatible gameplay and display options from the base Friday Night Funkin save into this project's save?";
        }

        return "This project could not find compatible option data in the base Friday Night Funkin save slot.";
    }

    private function getFooterText():String {
        if(promptChoices.length > 1) {
            return "UP / DOWN OR LEFT / RIGHT TO CHOOSE   ENTER TO CONFIRM   ESC TO DECLINE";
        }

        return "ENTER OR ESC TO RETURN";
    }
}
