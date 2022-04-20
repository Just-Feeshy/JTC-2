#ifndef INCLUDED_CrewState
#define INCLUDED_CrewState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
HX_DECLARE_CLASS0(CrewState)
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS3(flixel,addons,transition,FlxTransitionableState)
HX_DECLARE_CLASS3(flixel,addons,ui,FlxUIState)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IEventGetter)
HX_DECLARE_CLASS4(flixel,addons,ui,interfaces,IFlxUIState)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,util,IFlxDestroyable)



class HXCPP_CLASS_ATTRIBUTES CrewState_obj : public  ::MusicBeatState_obj
{
	public:
		typedef  ::MusicBeatState_obj super;
		typedef CrewState_obj OBJ_;
		CrewState_obj();

	public:
		enum { _hx_ClassId = 0x335844ac };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="CrewState")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"CrewState"); }
		static ::hx::ObjectPtr< CrewState_obj > __new();
		static ::hx::ObjectPtr< CrewState_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CrewState_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CrewState",50,fd,4d,c1); }

		 ::flixel::group::FlxTypedGroup officalDevTeam;
		int curSelected;
		Float globalOffset;
		void create();

		void update(Float elapsed);

		void changeDev(::hx::Null< int >  change);
		::Dynamic changeDev_dyn();

		void makeCoolPeople();
		::Dynamic makeCoolPeople_dyn();

};


#endif /* INCLUDED_CrewState */ 
