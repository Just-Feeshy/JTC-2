package;

interface ModInitialize {
    //TODO: Make this interface very useful
}

typedef ConfigDef = {
	var main:String;

	var mod:Mod_Info;
	var main_menu:Main_Menu;
    var title_menu:Title_Menu;

    var custom_notes:Array<String>;
    
    var weeks:Map<String, WeekInfo>;
};

typedef ConfigCharacters = {
    var file:String;
    var animations:Map<String, AnimationInfo>;
    var position:Map<String, Int>;
    var icon:Array<Int>;
    var playAnim:String;
    var isPlayer:Bool;
    var pixel:Bool;
}

typedef Mod_Info = {
    var name:String;
    var version:String;

    var stages:Array<String>;
    var discord_rpc:DiscordRPC;
}

typedef Main_Menu = {
    var background_image:String;
    var bpm:Int;
}

typedef Title_Menu = {
    var credit_engine_creator:Bool;

    var mod_creators:Array<String>;
    var waky:Array<String>;

    var random_waky:Array<Array<String>>;
}

typedef WeekInfo = {
    var week_name:String;
    var week_background:String;
    var week_unlocked:Bool;

    var week_data:Array<String>;
}

typedef AnimationInfo = {
    var prefix:String;
    var framerate:Int;
    var looped:Bool;
    var offset:Array<Int>;
}

typedef DiscordRPC = {
    var ClientID:String;
    var largeImageKey:String;
    var largeImageText:String;
    var smallImageKey:String;
    var smallImageText:String;
}