#ifndef INCLUDED_HelperStates
#define INCLUDED_HelperStates

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_addons_ui_FlxUIState
#include <flixel/addons/ui/FlxUIState.h>
#endif
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(ModLua)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)



class HXCPP_CLASS_ATTRIBUTES HelperStates_obj : public  ::flixel::addons::ui::FlxUIState_obj
{
	public:
		typedef  ::flixel::addons::ui::FlxUIState_obj super;
		typedef HelperStates_obj OBJ_;
		HelperStates_obj();

	public:
		enum { _hx_ClassId = 0x29d19794 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="HelperStates")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"HelperStates"); }

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~HelperStates_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("HelperStates",70,dd,a5,0e); }

		static void __boot();
		static  ::haxe::ds::StringMap scriptsInStates;
		static  ::ModLua getLua(::hx::Class state);
		static ::Dynamic getLua_dyn();

		static bool luaExist(::hx::Class state);
		static ::Dynamic luaExist_dyn();

		 ::haxe::ds::StringMap modifiableSprites;
		virtual void create();

		virtual  ::Dynamic onCreate();
		::Dynamic onCreate_dyn();

		void callLua(::String name,::cpp::VirtualArray args);
		::Dynamic callLua_dyn();

		void resetScript();
		::Dynamic resetScript_dyn();

		void clearStuff();
		::Dynamic clearStuff_dyn();

		virtual void destroy();

};


#endif /* INCLUDED_HelperStates */ 
