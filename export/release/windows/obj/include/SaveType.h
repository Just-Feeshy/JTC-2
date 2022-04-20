#ifndef INCLUDED_SaveType
#define INCLUDED_SaveType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(SaveType)


class SaveType_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef SaveType_obj OBJ_;

	public:
		SaveType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("SaveType",b7,48,74,da); }
		::String __ToString() const { return HX_("SaveType.",97,57,4b,4b) + _hx_tag; }

		static ::SaveType BLIND_MOD;
		static inline ::SaveType BLIND_MOD_dyn() { return BLIND_MOD; }
		static ::SaveType CACHE_ASSETS;
		static inline ::SaveType CACHE_ASSETS_dyn() { return CACHE_ASSETS; }
		static ::SaveType CAMERA_MOVEMENT_MOD;
		static inline ::SaveType CAMERA_MOVEMENT_MOD_dyn() { return CAMERA_MOVEMENT_MOD; }
		static ::SaveType CUSTOM_HELL_MOD;
		static inline ::SaveType CUSTOM_HELL_MOD_dyn() { return CUSTOM_HELL_MOD; }
		static ::SaveType CUSTOM_KEYBINDS;
		static inline ::SaveType CUSTOM_KEYBINDS_dyn() { return CUSTOM_KEYBINDS; }
		static ::SaveType CUSTOM_MENU_BINDS;
		static inline ::SaveType CUSTOM_MENU_BINDS_dyn() { return CUSTOM_MENU_BINDS; }
		static ::SaveType DOWNSCROLL;
		static inline ::SaveType DOWNSCROLL_dyn() { return DOWNSCROLL; }
		static ::SaveType FADE_BATTLE_MOD;
		static inline ::SaveType FADE_BATTLE_MOD_dyn() { return FADE_BATTLE_MOD; }
		static ::SaveType FAIR_BATTLE_MOD;
		static inline ::SaveType FAIR_BATTLE_MOD_dyn() { return FAIR_BATTLE_MOD; }
		static ::SaveType FLIP_CHART_MOD;
		static inline ::SaveType FLIP_CHART_MOD_dyn() { return FLIP_CHART_MOD; }
		static ::SaveType FPS_MULTIPLIER;
		static inline ::SaveType FPS_MULTIPLIER_dyn() { return FPS_MULTIPLIER; }
		static ::SaveType GHOST_TAPPING;
		static inline ::SaveType GHOST_TAPPING_dyn() { return GHOST_TAPPING; }
		static ::SaveType GRAPHICS;
		static inline ::SaveType GRAPHICS_dyn() { return GRAPHICS; }
		static ::SaveType NONE;
		static inline ::SaveType NONE_dyn() { return NONE; }
		static ::SaveType NO_BLUE_BALLS_MOD;
		static inline ::SaveType NO_BLUE_BALLS_MOD_dyn() { return NO_BLUE_BALLS_MOD; }
		static ::SaveType PERFECT_MODE_MOD;
		static inline ::SaveType PERFECT_MODE_MOD_dyn() { return PERFECT_MODE_MOD; }
		static ::SaveType PRESET_INPUTS;
		static inline ::SaveType PRESET_INPUTS_dyn() { return PRESET_INPUTS; }
		static ::SaveType PRESET_KEYBINDS;
		static inline ::SaveType PRESET_KEYBINDS_dyn() { return PRESET_KEYBINDS; }
		static ::SaveType SET_FPS_DEFAULT;
		static inline ::SaveType SET_FPS_DEFAULT_dyn() { return SET_FPS_DEFAULT; }
		static ::SaveType SHOW_BOTTOM_BAR;
		static inline ::SaveType SHOW_BOTTOM_BAR_dyn() { return SHOW_BOTTOM_BAR; }
		static ::SaveType SHOW_NOTE_SPLASH;
		static inline ::SaveType SHOW_NOTE_SPLASH_dyn() { return SHOW_NOTE_SPLASH; }
		static ::SaveType X_WOBBLE_MOD;
		static inline ::SaveType X_WOBBLE_MOD_dyn() { return X_WOBBLE_MOD; }
};


#endif /* INCLUDED_SaveType */ 
