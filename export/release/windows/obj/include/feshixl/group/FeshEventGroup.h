#ifndef INCLUDED_feshixl_group_FeshEventGroup
#define INCLUDED_feshixl_group_FeshEventGroup

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_feshixl_group_IFeshEvent
#include <feshixl/group/IFeshEvent.h>
#endif
HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS0(Note)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS2(feshixl,group,FeshEventGroup)
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

namespace feshixl{
namespace group{


class HXCPP_CLASS_ATTRIBUTES FeshEventGroup_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef FeshEventGroup_obj OBJ_;
		FeshEventGroup_obj();

	public:
		enum { _hx_ClassId = 0x53bb30f7 };

		void __construct(::Array< ::Dynamic> members);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="feshixl.group.FeshEventGroup")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"feshixl.group.FeshEventGroup"); }
		static ::hx::ObjectPtr< FeshEventGroup_obj > __new(::Array< ::Dynamic> members);
		static ::hx::ObjectPtr< FeshEventGroup_obj > __alloc(::hx::Ctx *_hx_ctx,::Array< ::Dynamic> members);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FeshEventGroup_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("FeshEventGroup",99,e1,b0,b0); }

		::Array< ::Dynamic> members;
		void whenTriggered(::String eventName,::String eventValue,::String eventValue2, ::PlayState playState);
		::Dynamic whenTriggered_dyn();

		void whenGameIsRunning(::Array< ::String > activeEvents, ::PlayState playState);
		::Dynamic whenGameIsRunning_dyn();

		void whenNoteIsPressed( ::Note note, ::PlayState playState);
		::Dynamic whenNoteIsPressed_dyn();

		::Dynamic add(::Dynamic Object);
		::Dynamic add_dyn();

		void remove(::Dynamic Object, ::Dynamic Splice);
		::Dynamic remove_dyn();

		void destroy();
		::Dynamic destroy_dyn();

};

} // end namespace feshixl
} // end namespace group

#endif /* INCLUDED_feshixl_group_FeshEventGroup */ 
