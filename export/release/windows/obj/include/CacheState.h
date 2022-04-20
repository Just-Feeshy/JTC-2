#ifndef INCLUDED_CacheState
#define INCLUDED_CacheState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
HX_DECLARE_CLASS0(CacheState)
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES CacheState_obj : public  ::MusicBeatState_obj
{
	public:
		typedef  ::MusicBeatState_obj super;
		typedef CacheState_obj OBJ_;
		CacheState_obj();

	public:
		enum { _hx_ClassId = 0x146909b3 };

		void __construct( ::flixel::FlxState target,bool stopMusic);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="CacheState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"CacheState"); }
		static ::hx::ObjectPtr< CacheState_obj > __new( ::flixel::FlxState target,bool stopMusic);
		static ::hx::ObjectPtr< CacheState_obj > __alloc(::hx::Ctx *_hx_ctx, ::flixel::FlxState target,bool stopMusic);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CacheState_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CacheState",8f,e0,74,bd); }

		static void loadAndSwitchState( ::flixel::FlxState target, ::Dynamic stopMusic);
		static ::Dynamic loadAndSwitchState_dyn();

		 ::flixel::FlxState target;
		bool stopMusic;
		 ::flixel::FlxSprite menuBG;
		void create();

		void cacheStuff();
		::Dynamic cacheStuff_dyn();

};


#endif /* INCLUDED_CacheState */ 
