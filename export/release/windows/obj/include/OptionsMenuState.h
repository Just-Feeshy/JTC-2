#ifndef INCLUDED_OptionsMenuState
#define INCLUDED_OptionsMenuState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
HX_DECLARE_CLASS0(Alphabet)
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS0(Options)
HX_DECLARE_CLASS0(OptionsMenuState)
HX_DECLARE_CLASS1(betterShit,BetterCams)
HX_DECLARE_CLASS2(feshixl,filters,GuassianBlur)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS1(flixel,FlxSubState)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS3(flixel,graphics,tile,FlxGraphicsShader)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS2(openfl,display,GraphicsShader)
HX_DECLARE_CLASS2(openfl,display,Shader)



class HXCPP_CLASS_ATTRIBUTES OptionsMenuState_obj : public  ::MusicBeatState_obj
{
	public:
		typedef  ::MusicBeatState_obj super;
		typedef OptionsMenuState_obj OBJ_;
		OptionsMenuState_obj();

	public:
		enum { _hx_ClassId = 0x520ebf94 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="OptionsMenuState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"OptionsMenuState"); }
		static ::hx::ObjectPtr< OptionsMenuState_obj > __new();
		static ::hx::ObjectPtr< OptionsMenuState_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~OptionsMenuState_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("OptionsMenuState",d4,0c,2d,7c); }

		int imNotSure;
		 ::betterShit::BetterCams camBackground;
		 ::betterShit::BetterCams camNoBlur;
		 ::betterShit::BetterCams camSubState;
		 ::feshixl::filters::GuassianBlur blurEffect;
		::Array< ::Dynamic> optionList;
		 ::flixel::group::FlxTypedSpriteGroup curOptionSection;
		 ::flixel::group::FlxTypedGroup optionSetting;
		int curCatalog;
		int curSelected;
		bool shouldPress;
		bool isChangingOption;
		bool changeBlur;
		::String settingTxt;
		void create();

		void setControls( ::Options option,int id);
		::Dynamic setControls_dyn();

		void changeSelection(::hx::Null< int >  change);
		::Dynamic changeSelection_dyn();

		void setting( ::Options option,::String display,int id);
		::Dynamic setting_dyn();

		void setCat(int catagory);
		::Dynamic setCat_dyn();

		void openSubStateBlur( ::flixel::FlxSubState SubState);
		::Dynamic openSubStateBlur_dyn();

		void closeSubState();

		void update(Float elapsed);

};


#endif /* INCLUDED_OptionsMenuState */ 
