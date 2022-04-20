#ifndef INCLUDED_example_code_DefaultEvents
#define INCLUDED_example_code_DefaultEvents

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_feshixl_group_IFeshEvent
#include <feshixl/group/IFeshEvent.h>
#endif
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS0(Note)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS1(example_code,DefaultEvents)
HX_DECLARE_CLASS2(feshixl,group,IFeshEvent)
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

namespace example_code{


class HXCPP_CLASS_ATTRIBUTES DefaultEvents_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef DefaultEvents_obj OBJ_;
		DefaultEvents_obj();

	public:
		enum { _hx_ClassId = 0x5a7ce6b8 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="example_code.DefaultEvents")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"example_code.DefaultEvents"); }
		static ::hx::ObjectPtr< DefaultEvents_obj > __new();
		static ::hx::ObjectPtr< DefaultEvents_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~DefaultEvents_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("DefaultEvents",9a,72,d3,d8); }

		int offsetBounce;
		void whenTriggered(::String eventName,::String eventValue,::String eventValue2, ::PlayState playState);
		::Dynamic whenTriggered_dyn();

		void whenGameIsRunning(::Array< ::String > activeEvents, ::PlayState playState);
		::Dynamic whenGameIsRunning_dyn();

		void whenNoteIsPressed( ::Note note, ::PlayState playState);
		::Dynamic whenNoteIsPressed_dyn();

};

} // end namespace example_code

#endif /* INCLUDED_example_code_DefaultEvents */ 
