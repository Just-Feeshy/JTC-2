package;

interface ModInitialize {
    //TODO: Make this interface very useful
}

typedef ConfigDef = {
	var main:String;

	var mod:Mod_Info;
    var background_images:Array<String>;
    var cache_configuration:Array<String>;
    var song_util:SongUtils;
	var main_menu:Main_Menu;
    var title_menu:Title_Menu;
    var loading_display:LoadingDisplay;

    var custom_notes:Array<String>;
    var weeks:Map<String, WeekInfo>;
}

typedef Mod_Info = {
    var name:String;
    var version:String;

    var stages:Array<String>;
    var events:Array<ConfigEvent>;
    var discord_rpc:DiscordRPC;
}

typedef ConfigCharacters = {
    var file:String;
    var animations:Map<String, AnimationInfo>;
    var position:Map<String, Int>;
    var icon:Array<Int>;
    var playAnim:String;
    var isPlayer:Bool;
    var pixel:Bool;

    var iconFile:String;
    var clippingAdjustment:Map<String, Array<Int>>;
}

typedef SongUtils = {
    var difficulties:Array<String>;
}

typedef ConfigEvent = {
    var name:String;
    var description:String;
}

typedef Main_Menu = {
    var background_image:String;
    var has_background_image:Bool;
    var bpm:Int;
}

typedef Title_Menu = {
    var credit_engine_creator:Bool;

    var music:TitleMusic;

    var mod_creators:Array<String>;
    var waky:Array<Waky>;

    var random_waky:Array<Array<String>>;
}

typedef TitleMusic = {
    var song:String;
    var bpm:Int;
};

typedef Waky = {
    var texts:Array<String>;
    var addon:Bool;
}

typedef WeekInfo = {
    var week_name:String;
    var week_background:String;
    var week_unlocked:Bool;

    var week_data:Array<String>;
}

typedef AnimationInfo = {
    var name:String;
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

typedef LoadingDisplay = {
    var show_loading_bar:Bool;
    var loading_bar_colors:Array<String>;
    var loading_bar_alpha:Float;
}