package;

import template.CustomNote;

/*
* Backend organizer for FNF custom notes made by YOU, the developer.
**/
class CustomNoteHandler {
    private static var funni:Bool = false;

    public static var triggerWarning:Map<String, Bool>;
    public static var yourNoteData:Map<String, Dynamic>;

    public static final dontHitNotes:Array<String> = ['poison', 'spiritual star', 'trippy', 'reverse poison', 'planet notes'];
    public static final noNoteAbstractStrum:Array<String> = ["reverse", "poison", "spiritual star", "trippy", "reverse poison", "ocean", "side note" , "planet notes"];
    public static final ouchyNotes:Array<String> = ['poison', 'trippy', 'reverse poison', 'planet notes'];
    public static final lowNotesTick:Array<String> = ['poison', 'regular', 'reverse', 'ocean', 'side note'];

    @:allow(Note.getAddon)
    @:allow(Register.implementCustomNote)
    private static var customNoteAddon:Map<String, Class<NoteAddon>> = new Map<String, Class<NoteAddon>>();

    static public function spawn() {
        triggerWarning = [
            "reverse" => false,
            "spiritual star" => false,
            "poison" => false,
            "reverse poison" => false,
            "side note" => false,
            "ocean" => false
        ];

        //Your custom static note data
        yourNoteData = [
            "trippy" => 0,
            "side note" => null
        ];
    }

    /**
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
    **/
}