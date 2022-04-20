#ifndef INCLUDED_MainMenuState
#define INCLUDED_MainMenuState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MainMenuState)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS1(betterShit,BetterCams)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES MainMenuState_obj : public  ::MusicBeatState_obj
{
	public:
		typedef  ::MusicBeatState_obj super;
		typedef MainMenuState_obj OBJ_;
		MainMenuState_obj();

	public:
		enum { _hx_ClassId = 0x6915cded };

		void __construct( ::Dynamic fromFreeplay);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="MainMenuState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"MainMenuState"); }
		static ::hx::ObjectPtr< MainMenuState_obj > __new( ::Dynamic fromFreeplay);
		static ::hx::ObjectPtr< MainMenuState_obj > __alloc(::hx::Ctx *_hx_ctx, ::Dynamic fromFreeplay);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~MainMenuState_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("MainMenuState",59,88,5e,20); }

		 ::betterShit::BetterCams camX;
		 ::betterShit::BetterCams camMenu;
		 ::betterShit::BetterCams camNoBump;
		int curSelected;
		 ::flixel::group::FlxTypedGroup menuItems;
		 ::flixel::group::FlxTypedSpriteGroup displayChain;
		bool fromFreeplay;
		 ::flixel::FlxObject camFollow;
		 ::flixel::FlxObject secondCam;
		::Array< ::String > optionShit;
		void create();

		 ::Dynamic onCreate();

		bool selectedSomethin;
		void update(Float elapsed);

		void getLuaOptions();
		::Dynamic getLuaOptions_dyn();

		int getSelectVal(::hx::Null< int >  sel);
		::Dynamic getSelectVal_dyn();

		void changeItem(::hx::Null< int >  huh);
		::Dynamic changeItem_dyn();

};


#endif /* INCLUDED_MainMenuState */ 
