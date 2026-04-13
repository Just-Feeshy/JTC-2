package;

import template.CustomNote;

/*
* Backend organizer for FNF custom notes made by YOU, the developer.
**/
class CustomNoteHandler {
    private static var funni:Bool = false;

    public static var yourNoteData:Map<String, Dynamic>;

    public static final dontHitNotes:Array<String> = [];
    public static final noNoteAbstractStrum:Array<String> = [];
    public static final ouchyNotes:Array<String> = [];
    public static final lowNotesTick:Array<String> = ['poison', 'regular', 'reverse', 'reverse poison'];

    @:allow(Note.getAddon)
    @:allow(Register.implementCustomNote)
    @:allow(ChartingState.addNoteUI)
    private static var customNoteAddon:Map<String, Class<ICustomNote>> = new Map<String, Class<ICustomNote>>();

    public static function getCustomNoteUnmuteVoiceAudio(noteType:String):Bool {
        if(noteType == null || !customNoteAddon.exists(noteType)) {
            return true;
        }

        var customNote:ICustomNote = cast Type.createInstance(customNoteAddon.get(noteType), []);
        return customNote == null ? true : customNote.canUnmuteVoiceAudio();
    }

    static public function spawn() {

        //custom static note data
        yourNoteData = [
            "trippy" => 0,
            "side note" => null
        ];
    }

    /*
    static public function configAddons() {
        if(!funni) {
            for (i in 0...customNoteAddon.length) {
                var v:NoteAddon = customNoteAddon[i];

                if(v.getCustomNote() != "" && v.getCustomNote() != null) {
                    if(v.playerShouldntHit() && !dontHitNotes.contains(v.getCustomNote()))
                        dontHitNotes.push(v.getCustomNote());
                    else if(v.noDefaultSplash() && !noNoteAbstractStrum.contains(v.getCustomNote()))
                        noNoteAbstractStrum.push(v.getCustomNote());
                    else if(v.giveHealth() < 0 && !ouchyNotes.contains(v.getCustomNote()))
                        ouchyNotes.push(v.getCustomNote());
                }
            }

            if(customNoteAddon[0] != null && customNoteAddon[0].getCustomNote() != "") {
                for(i in 0...customNoteAddon.length) {
                    var v:NoteAddon = customNoteAddon[i];

                    triggerWarning[v.getCustomNote()] = false;
                }
            }

            funni = true;
        }
    }
    */
}
