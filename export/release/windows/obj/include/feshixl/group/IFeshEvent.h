#ifndef INCLUDED_feshixl_group_IFeshEvent
#define INCLUDED_feshixl_group_IFeshEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(HelperStates)
HX_DECLARE_CLASS0(MusicBeatState)
HX_DECLARE_CLASS0(Note)
HX_DECLARE_CLASS0(PlayState)
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


class HXCPP_CLASS_ATTRIBUTES IFeshEvent_obj {
	public:
		typedef ::hx::Object super;
		HX_DO_INTERFACE_RTTI;

		void (::hx::Object :: *_hx_whenTriggered)(::String eventName,::String eventValue,::String eventValue2, ::PlayState playState); 
		static inline void whenTriggered( ::Dynamic _hx_,::String eventName,::String eventValue,::String eventValue2, ::PlayState playState) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::feshixl::group::IFeshEvent_obj *>(_hx_.mPtr->_hx_getInterface(0xf0fb0b33)))->_hx_whenTriggered)(eventName,eventValue,eventValue2,playState);
		}
		void (::hx::Object :: *_hx_whenGameIsRunning)(::Array< ::String > activeEvents, ::PlayState playState); 
		static inline void whenGameIsRunning( ::Dynamic _hx_,::Array< ::String > activeEvents, ::PlayState playState) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::feshixl::group::IFeshEvent_obj *>(_hx_.mPtr->_hx_getInterface(0xf0fb0b33)))->_hx_whenGameIsRunning)(activeEvents,playState);
		}
		void (::hx::Object :: *_hx_whenNoteIsPressed)( ::Note note, ::PlayState playState); 
		static inline void whenNoteIsPressed( ::Dynamic _hx_, ::Note note, ::PlayState playState) {
			(_hx_.mPtr->*( ::hx::interface_cast< ::feshixl::group::IFeshEvent_obj *>(_hx_.mPtr->_hx_getInterface(0xf0fb0b33)))->_hx_whenNoteIsPressed)(note,playState);
		}
};

} // end namespace feshixl
} // end namespace group

#endif /* INCLUDED_feshixl_group_IFeshEvent */ 
