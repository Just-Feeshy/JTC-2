#include <hxcpp.h>

#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif

::SaveType SaveType_obj::BLIND_MOD;

::SaveType SaveType_obj::CACHE_ASSETS;

::SaveType SaveType_obj::CAMERA_MOVEMENT_MOD;

::SaveType SaveType_obj::CUSTOM_HELL_MOD;

::SaveType SaveType_obj::CUSTOM_KEYBINDS;

::SaveType SaveType_obj::CUSTOM_MENU_BINDS;

::SaveType SaveType_obj::DOWNSCROLL;

::SaveType SaveType_obj::FADE_BATTLE_MOD;

::SaveType SaveType_obj::FAIR_BATTLE_MOD;

::SaveType SaveType_obj::FLIP_CHART_MOD;

::SaveType SaveType_obj::FPS_MULTIPLIER;

::SaveType SaveType_obj::GHOST_TAPPING;

::SaveType SaveType_obj::GRAPHICS;

::SaveType SaveType_obj::NONE;

::SaveType SaveType_obj::NO_BLUE_BALLS_MOD;

::SaveType SaveType_obj::PERFECT_MODE_MOD;

::SaveType SaveType_obj::PRESET_INPUTS;

::SaveType SaveType_obj::PRESET_KEYBINDS;

::SaveType SaveType_obj::SET_FPS_DEFAULT;

::SaveType SaveType_obj::SHOW_BOTTOM_BAR;

::SaveType SaveType_obj::SHOW_NOTE_SPLASH;

::SaveType SaveType_obj::X_WOBBLE_MOD;

bool SaveType_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("BLIND_MOD",58,5f,f1,ce)) { outValue = SaveType_obj::BLIND_MOD; return true; }
	if (inName==HX_("CACHE_ASSETS",40,9c,8b,6c)) { outValue = SaveType_obj::CACHE_ASSETS; return true; }
	if (inName==HX_("CAMERA_MOVEMENT_MOD",6c,ed,6d,4f)) { outValue = SaveType_obj::CAMERA_MOVEMENT_MOD; return true; }
	if (inName==HX_("CUSTOM_HELL_MOD",6e,da,51,64)) { outValue = SaveType_obj::CUSTOM_HELL_MOD; return true; }
	if (inName==HX_("CUSTOM_KEYBINDS",a5,1b,01,72)) { outValue = SaveType_obj::CUSTOM_KEYBINDS; return true; }
	if (inName==HX_("CUSTOM_MENU_BINDS",24,63,12,d1)) { outValue = SaveType_obj::CUSTOM_MENU_BINDS; return true; }
	if (inName==HX_("DOWNSCROLL",ef,b9,dd,41)) { outValue = SaveType_obj::DOWNSCROLL; return true; }
	if (inName==HX_("FADE_BATTLE_MOD",fe,ed,f5,25)) { outValue = SaveType_obj::FADE_BATTLE_MOD; return true; }
	if (inName==HX_("FAIR_BATTLE_MOD",96,f2,70,d9)) { outValue = SaveType_obj::FAIR_BATTLE_MOD; return true; }
	if (inName==HX_("FLIP_CHART_MOD",0f,54,88,91)) { outValue = SaveType_obj::FLIP_CHART_MOD; return true; }
	if (inName==HX_("FPS_MULTIPLIER",77,b7,48,1e)) { outValue = SaveType_obj::FPS_MULTIPLIER; return true; }
	if (inName==HX_("GHOST_TAPPING",e5,f5,54,4b)) { outValue = SaveType_obj::GHOST_TAPPING; return true; }
	if (inName==HX_("GRAPHICS",cb,88,ed,6b)) { outValue = SaveType_obj::GRAPHICS; return true; }
	if (inName==HX_("NONE",b8,da,ca,33)) { outValue = SaveType_obj::NONE; return true; }
	if (inName==HX_("NO_BLUE_BALLS_MOD",70,57,53,26)) { outValue = SaveType_obj::NO_BLUE_BALLS_MOD; return true; }
	if (inName==HX_("PERFECT_MODE_MOD",58,59,16,db)) { outValue = SaveType_obj::PERFECT_MODE_MOD; return true; }
	if (inName==HX_("PRESET_INPUTS",49,5d,16,4c)) { outValue = SaveType_obj::PRESET_INPUTS; return true; }
	if (inName==HX_("PRESET_KEYBINDS",37,0a,d3,e1)) { outValue = SaveType_obj::PRESET_KEYBINDS; return true; }
	if (inName==HX_("SET_FPS_DEFAULT",6e,fb,2a,1d)) { outValue = SaveType_obj::SET_FPS_DEFAULT; return true; }
	if (inName==HX_("SHOW_BOTTOM_BAR",61,7e,a7,ff)) { outValue = SaveType_obj::SHOW_BOTTOM_BAR; return true; }
	if (inName==HX_("SHOW_NOTE_SPLASH",d2,73,74,c6)) { outValue = SaveType_obj::SHOW_NOTE_SPLASH; return true; }
	if (inName==HX_("X_WOBBLE_MOD",3b,14,7b,b2)) { outValue = SaveType_obj::X_WOBBLE_MOD; return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(SaveType_obj)

int SaveType_obj::__FindIndex(::String inName)
{
	if (inName==HX_("BLIND_MOD",58,5f,f1,ce)) return 14;
	if (inName==HX_("CACHE_ASSETS",40,9c,8b,6c)) return 17;
	if (inName==HX_("CAMERA_MOVEMENT_MOD",6c,ed,6d,4f)) return 19;
	if (inName==HX_("CUSTOM_HELL_MOD",6e,da,51,64)) return 5;
	if (inName==HX_("CUSTOM_KEYBINDS",a5,1b,01,72)) return 18;
	if (inName==HX_("CUSTOM_MENU_BINDS",24,63,12,d1)) return 21;
	if (inName==HX_("DOWNSCROLL",ef,b9,dd,41)) return 1;
	if (inName==HX_("FADE_BATTLE_MOD",fe,ed,f5,25)) return 7;
	if (inName==HX_("FAIR_BATTLE_MOD",96,f2,70,d9)) return 6;
	if (inName==HX_("FLIP_CHART_MOD",0f,54,88,91)) return 4;
	if (inName==HX_("FPS_MULTIPLIER",77,b7,48,1e)) return 12;
	if (inName==HX_("GHOST_TAPPING",e5,f5,54,4b)) return 20;
	if (inName==HX_("GRAPHICS",cb,88,ed,6b)) return 10;
	if (inName==HX_("NONE",b8,da,ca,33)) return 0;
	if (inName==HX_("NO_BLUE_BALLS_MOD",70,57,53,26)) return 13;
	if (inName==HX_("PERFECT_MODE_MOD",58,59,16,db)) return 3;
	if (inName==HX_("PRESET_INPUTS",49,5d,16,4c)) return 16;
	if (inName==HX_("PRESET_KEYBINDS",37,0a,d3,e1)) return 2;
	if (inName==HX_("SET_FPS_DEFAULT",6e,fb,2a,1d)) return 11;
	if (inName==HX_("SHOW_BOTTOM_BAR",61,7e,a7,ff)) return 8;
	if (inName==HX_("SHOW_NOTE_SPLASH",d2,73,74,c6)) return 9;
	if (inName==HX_("X_WOBBLE_MOD",3b,14,7b,b2)) return 15;
	return super::__FindIndex(inName);
}

int SaveType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("BLIND_MOD",58,5f,f1,ce)) return 0;
	if (inName==HX_("CACHE_ASSETS",40,9c,8b,6c)) return 0;
	if (inName==HX_("CAMERA_MOVEMENT_MOD",6c,ed,6d,4f)) return 0;
	if (inName==HX_("CUSTOM_HELL_MOD",6e,da,51,64)) return 0;
	if (inName==HX_("CUSTOM_KEYBINDS",a5,1b,01,72)) return 0;
	if (inName==HX_("CUSTOM_MENU_BINDS",24,63,12,d1)) return 0;
	if (inName==HX_("DOWNSCROLL",ef,b9,dd,41)) return 0;
	if (inName==HX_("FADE_BATTLE_MOD",fe,ed,f5,25)) return 0;
	if (inName==HX_("FAIR_BATTLE_MOD",96,f2,70,d9)) return 0;
	if (inName==HX_("FLIP_CHART_MOD",0f,54,88,91)) return 0;
	if (inName==HX_("FPS_MULTIPLIER",77,b7,48,1e)) return 0;
	if (inName==HX_("GHOST_TAPPING",e5,f5,54,4b)) return 0;
	if (inName==HX_("GRAPHICS",cb,88,ed,6b)) return 0;
	if (inName==HX_("NONE",b8,da,ca,33)) return 0;
	if (inName==HX_("NO_BLUE_BALLS_MOD",70,57,53,26)) return 0;
	if (inName==HX_("PERFECT_MODE_MOD",58,59,16,db)) return 0;
	if (inName==HX_("PRESET_INPUTS",49,5d,16,4c)) return 0;
	if (inName==HX_("PRESET_KEYBINDS",37,0a,d3,e1)) return 0;
	if (inName==HX_("SET_FPS_DEFAULT",6e,fb,2a,1d)) return 0;
	if (inName==HX_("SHOW_BOTTOM_BAR",61,7e,a7,ff)) return 0;
	if (inName==HX_("SHOW_NOTE_SPLASH",d2,73,74,c6)) return 0;
	if (inName==HX_("X_WOBBLE_MOD",3b,14,7b,b2)) return 0;
	return super::__FindArgCount(inName);
}

::hx::Val SaveType_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("BLIND_MOD",58,5f,f1,ce)) return BLIND_MOD;
	if (inName==HX_("CACHE_ASSETS",40,9c,8b,6c)) return CACHE_ASSETS;
	if (inName==HX_("CAMERA_MOVEMENT_MOD",6c,ed,6d,4f)) return CAMERA_MOVEMENT_MOD;
	if (inName==HX_("CUSTOM_HELL_MOD",6e,da,51,64)) return CUSTOM_HELL_MOD;
	if (inName==HX_("CUSTOM_KEYBINDS",a5,1b,01,72)) return CUSTOM_KEYBINDS;
	if (inName==HX_("CUSTOM_MENU_BINDS",24,63,12,d1)) return CUSTOM_MENU_BINDS;
	if (inName==HX_("DOWNSCROLL",ef,b9,dd,41)) return DOWNSCROLL;
	if (inName==HX_("FADE_BATTLE_MOD",fe,ed,f5,25)) return FADE_BATTLE_MOD;
	if (inName==HX_("FAIR_BATTLE_MOD",96,f2,70,d9)) return FAIR_BATTLE_MOD;
	if (inName==HX_("FLIP_CHART_MOD",0f,54,88,91)) return FLIP_CHART_MOD;
	if (inName==HX_("FPS_MULTIPLIER",77,b7,48,1e)) return FPS_MULTIPLIER;
	if (inName==HX_("GHOST_TAPPING",e5,f5,54,4b)) return GHOST_TAPPING;
	if (inName==HX_("GRAPHICS",cb,88,ed,6b)) return GRAPHICS;
	if (inName==HX_("NONE",b8,da,ca,33)) return NONE;
	if (inName==HX_("NO_BLUE_BALLS_MOD",70,57,53,26)) return NO_BLUE_BALLS_MOD;
	if (inName==HX_("PERFECT_MODE_MOD",58,59,16,db)) return PERFECT_MODE_MOD;
	if (inName==HX_("PRESET_INPUTS",49,5d,16,4c)) return PRESET_INPUTS;
	if (inName==HX_("PRESET_KEYBINDS",37,0a,d3,e1)) return PRESET_KEYBINDS;
	if (inName==HX_("SET_FPS_DEFAULT",6e,fb,2a,1d)) return SET_FPS_DEFAULT;
	if (inName==HX_("SHOW_BOTTOM_BAR",61,7e,a7,ff)) return SHOW_BOTTOM_BAR;
	if (inName==HX_("SHOW_NOTE_SPLASH",d2,73,74,c6)) return SHOW_NOTE_SPLASH;
	if (inName==HX_("X_WOBBLE_MOD",3b,14,7b,b2)) return X_WOBBLE_MOD;
	return super::__Field(inName,inCallProp);
}

static ::String SaveType_obj_sStaticFields[] = {
	HX_("NONE",b8,da,ca,33),
	HX_("DOWNSCROLL",ef,b9,dd,41),
	HX_("PRESET_KEYBINDS",37,0a,d3,e1),
	HX_("PERFECT_MODE_MOD",58,59,16,db),
	HX_("FLIP_CHART_MOD",0f,54,88,91),
	HX_("CUSTOM_HELL_MOD",6e,da,51,64),
	HX_("FAIR_BATTLE_MOD",96,f2,70,d9),
	HX_("FADE_BATTLE_MOD",fe,ed,f5,25),
	HX_("SHOW_BOTTOM_BAR",61,7e,a7,ff),
	HX_("SHOW_NOTE_SPLASH",d2,73,74,c6),
	HX_("GRAPHICS",cb,88,ed,6b),
	HX_("SET_FPS_DEFAULT",6e,fb,2a,1d),
	HX_("FPS_MULTIPLIER",77,b7,48,1e),
	HX_("NO_BLUE_BALLS_MOD",70,57,53,26),
	HX_("BLIND_MOD",58,5f,f1,ce),
	HX_("X_WOBBLE_MOD",3b,14,7b,b2),
	HX_("PRESET_INPUTS",49,5d,16,4c),
	HX_("CACHE_ASSETS",40,9c,8b,6c),
	HX_("CUSTOM_KEYBINDS",a5,1b,01,72),
	HX_("CAMERA_MOVEMENT_MOD",6c,ed,6d,4f),
	HX_("GHOST_TAPPING",e5,f5,54,4b),
	HX_("CUSTOM_MENU_BINDS",24,63,12,d1),
	::String(null())
};

::hx::Class SaveType_obj::__mClass;

Dynamic __Create_SaveType_obj() { return new SaveType_obj; }

void SaveType_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("SaveType",b7,48,74,da), ::hx::TCanCast< SaveType_obj >,SaveType_obj_sStaticFields,0,
	&__Create_SaveType_obj, &__Create,
	&super::__SGetClass(), &CreateSaveType_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &SaveType_obj::__GetStatic;
}

void SaveType_obj::__boot()
{
BLIND_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("BLIND_MOD",58,5f,f1,ce),14);
CACHE_ASSETS = ::hx::CreateConstEnum< SaveType_obj >(HX_("CACHE_ASSETS",40,9c,8b,6c),17);
CAMERA_MOVEMENT_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("CAMERA_MOVEMENT_MOD",6c,ed,6d,4f),19);
CUSTOM_HELL_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("CUSTOM_HELL_MOD",6e,da,51,64),5);
CUSTOM_KEYBINDS = ::hx::CreateConstEnum< SaveType_obj >(HX_("CUSTOM_KEYBINDS",a5,1b,01,72),18);
CUSTOM_MENU_BINDS = ::hx::CreateConstEnum< SaveType_obj >(HX_("CUSTOM_MENU_BINDS",24,63,12,d1),21);
DOWNSCROLL = ::hx::CreateConstEnum< SaveType_obj >(HX_("DOWNSCROLL",ef,b9,dd,41),1);
FADE_BATTLE_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("FADE_BATTLE_MOD",fe,ed,f5,25),7);
FAIR_BATTLE_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("FAIR_BATTLE_MOD",96,f2,70,d9),6);
FLIP_CHART_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("FLIP_CHART_MOD",0f,54,88,91),4);
FPS_MULTIPLIER = ::hx::CreateConstEnum< SaveType_obj >(HX_("FPS_MULTIPLIER",77,b7,48,1e),12);
GHOST_TAPPING = ::hx::CreateConstEnum< SaveType_obj >(HX_("GHOST_TAPPING",e5,f5,54,4b),20);
GRAPHICS = ::hx::CreateConstEnum< SaveType_obj >(HX_("GRAPHICS",cb,88,ed,6b),10);
NONE = ::hx::CreateConstEnum< SaveType_obj >(HX_("NONE",b8,da,ca,33),0);
NO_BLUE_BALLS_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("NO_BLUE_BALLS_MOD",70,57,53,26),13);
PERFECT_MODE_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("PERFECT_MODE_MOD",58,59,16,db),3);
PRESET_INPUTS = ::hx::CreateConstEnum< SaveType_obj >(HX_("PRESET_INPUTS",49,5d,16,4c),16);
PRESET_KEYBINDS = ::hx::CreateConstEnum< SaveType_obj >(HX_("PRESET_KEYBINDS",37,0a,d3,e1),2);
SET_FPS_DEFAULT = ::hx::CreateConstEnum< SaveType_obj >(HX_("SET_FPS_DEFAULT",6e,fb,2a,1d),11);
SHOW_BOTTOM_BAR = ::hx::CreateConstEnum< SaveType_obj >(HX_("SHOW_BOTTOM_BAR",61,7e,a7,ff),8);
SHOW_NOTE_SPLASH = ::hx::CreateConstEnum< SaveType_obj >(HX_("SHOW_NOTE_SPLASH",d2,73,74,c6),9);
X_WOBBLE_MOD = ::hx::CreateConstEnum< SaveType_obj >(HX_("X_WOBBLE_MOD",3b,14,7b,b2),15);
}


