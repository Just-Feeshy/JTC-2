#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Character
#include <Character.h>
#endif
#ifndef INCLUDED_Compile
#include <Compile.h>
#endif
#ifndef INCLUDED_Conductor
#include <Conductor.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Note
#include <Note.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
#endif
#ifndef INCLUDED_example_code_DefaultEvents
#include <example_code/DefaultEvents.h>
#endif
#ifndef INCLUDED_feshixl_group_IFeshEvent
#include <feshixl/group/IFeshEvent.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_addons_transition_FlxTransitionableState
#include <flixel/addons/transition/FlxTransitionableState.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_FlxUIState
#include <flixel/addons/ui/FlxUIState.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IEventGetter
#include <flixel/addons/ui/interfaces/IEventGetter.h>
#endif
#ifndef INCLUDED_flixel_addons_ui_interfaces_IFlxUIState
#include <flixel/addons/ui/interfaces/IFlxUIState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_media_SoundChannel
#include <openfl/media/SoundChannel.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_93737c9261257c5d_25_new,"example_code.DefaultEvents","new",0x6e1711c0,"example_code.DefaultEvents.new","example_code/DefaultEvents.hx",25,0xaa7a37b1)
HX_LOCAL_STACK_FRAME(_hx_pos_93737c9261257c5d_33_whenTriggered,"example_code.DefaultEvents","whenTriggered",0x4441b6dd,"example_code.DefaultEvents.whenTriggered","example_code/DefaultEvents.hx",33,0xaa7a37b1)
HX_LOCAL_STACK_FRAME(_hx_pos_93737c9261257c5d_34_whenTriggered,"example_code.DefaultEvents","whenTriggered",0x4441b6dd,"example_code.DefaultEvents.whenTriggered","example_code/DefaultEvents.hx",34,0xaa7a37b1)
HX_LOCAL_STACK_FRAME(_hx_pos_93737c9261257c5d_72_whenTriggered,"example_code.DefaultEvents","whenTriggered",0x4441b6dd,"example_code.DefaultEvents.whenTriggered","example_code/DefaultEvents.hx",72,0xaa7a37b1)
HX_LOCAL_STACK_FRAME(_hx_pos_93737c9261257c5d_107_whenGameIsRunning,"example_code.DefaultEvents","whenGameIsRunning",0x66d12f29,"example_code.DefaultEvents.whenGameIsRunning","example_code/DefaultEvents.hx",107,0xaa7a37b1)
HX_LOCAL_STACK_FRAME(_hx_pos_93737c9261257c5d_122_whenNoteIsPressed,"example_code.DefaultEvents","whenNoteIsPressed",0xbc1eefcc,"example_code.DefaultEvents.whenNoteIsPressed","example_code/DefaultEvents.hx",122,0xaa7a37b1)
namespace example_code{

void DefaultEvents_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_93737c9261257c5d_25_new)
HXLINE(  26)		this->offsetBounce = 0;
            	}

Dynamic DefaultEvents_obj::__CreateEmpty() { return new DefaultEvents_obj; }

void *DefaultEvents_obj::_hx_vtable = 0;

Dynamic DefaultEvents_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< DefaultEvents_obj > _hx_result = new DefaultEvents_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool DefaultEvents_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x5a7ce6b8;
}

static ::feshixl::group::IFeshEvent_obj _hx_example_code_DefaultEvents__hx_feshixl_group_IFeshEvent= {
	( void (::hx::Object::*)(::String,::String,::String, ::PlayState))&::example_code::DefaultEvents_obj::whenTriggered,
	( void (::hx::Object::*)(::Array< ::String >, ::PlayState))&::example_code::DefaultEvents_obj::whenGameIsRunning,
	( void (::hx::Object::*)( ::Note, ::PlayState))&::example_code::DefaultEvents_obj::whenNoteIsPressed,
};

void *DefaultEvents_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0xf0fb0b33: return &_hx_example_code_DefaultEvents__hx_feshixl_group_IFeshEvent;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

void DefaultEvents_obj::whenTriggered(::String eventName,::String eventValue,::String eventValue2, ::PlayState playState){
            	HX_GC_STACKFRAME(&_hx_pos_93737c9261257c5d_33_whenTriggered)
HXDLIN(  33)		if ((eventName == HX_("flip chart",2b,fb,b7,53))) {
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(1)
            			void _hx_run( ::Note daNote){
            				HX_STACKFRAME(&_hx_pos_93737c9261257c5d_34_whenTriggered)
HXLINE(  35)				if (( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) )) {
HXLINE(  36)					daNote->noteData = ::Std_obj::_hx_int(::Math_obj::abs(( (Float)((daNote->noteData - 4)) )));
            				}
            				else {
HXLINE(  38)					daNote->noteData = ::Std_obj::_hx_int(::Math_obj::abs(( (Float)((daNote->noteData - 3)) )));
            				}
HXLINE(  40)				daNote->refresh(( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) ),null());
HXLINE(  41)				daNote->refresh(( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) ),true);
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  34)			playState->notes->forEachAlive( ::Dynamic(new _hx_Closure_0()),null());
HXLINE(  44)			{
HXLINE(  44)				int _g = 0;
HXDLIN(  44)				int _g1 = playState->unspawnNotes->length;
HXDLIN(  44)				while((_g < _g1)){
HXLINE(  44)					_g = (_g + 1);
HXDLIN(  44)					int i = (_g - 1);
HXLINE(  45)					 ::Note note = playState->unspawnNotes->__get(i).StaticCast<  ::Note >();
HXLINE(  47)					if (( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) )) {
HXLINE(  48)						note->noteData = ::Std_obj::_hx_int(::Math_obj::abs(( (Float)((note->noteData - 4)) )));
            					}
            					else {
HXLINE(  50)						note->noteData = ::Std_obj::_hx_int(::Math_obj::abs(( (Float)((note->noteData - 3)) )));
            					}
HXLINE(  52)					note->refresh(( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) ),null());
HXLINE(  53)					note->refresh(( (bool)(::PlayState_obj::SONG->__Field(HX_("fifthKey",e8,b7,40,b0),::hx::paccDynamic)) ),true);
            				}
            			}
            		}
            		else {
HXLINE(  55)			if ((eventName == HX_("blind effect",fc,45,6a,f6))) {
HXLINE(  56)				playState->camGame->set_alpha(( (Float)(0) ));
            			}
            			else {
HXLINE(  57)				if ((eventName == HX_("alt animation",4d,51,fe,e3))) {
HXLINE(  58)					bool _hx_tmp;
HXDLIN(  58)					if ((eventValue2.indexOf(HX_("bf",c4,55,00,00),null()) == -1)) {
HXLINE(  58)						_hx_tmp = (eventValue2.indexOf(HX_("boyfriend",6a,29,b8,e6),null()) != -1);
            					}
            					else {
HXLINE(  58)						_hx_tmp = true;
            					}
HXDLIN(  58)					if (_hx_tmp) {
HXLINE(  59)						playState->playerAltAnim = eventValue;
            					}
            					else {
HXLINE(  61)						playState->opponentAltAnim = eventValue;
            					}
            				}
            				else {
HXLINE(  62)					if ((eventName == HX_("jumpspeed",d9,33,09,7a))) {
HXLINE(  63)						 ::Dynamic _hx_tmp =  ::Dynamic(::hx::Anon_obj::Create(1)
            							->setFixed(0,HX_("AFFECTED_SCROLLSPEED",ef,68,8f,2c),::Std_obj::parseFloat(eventValue)));
HXDLIN(  63)						Float _hx_tmp1 = (::Conductor_obj::stepCrochet / ( (Float)(1000) ));
HXDLIN(  63)						::flixel::tweens::FlxTween_obj::tween(::hx::ClassOf< ::Note >(),_hx_tmp,(_hx_tmp1 * ::Std_obj::parseFloat(eventValue2)),null());
            					}
            					else {
HXLINE(  64)						if ((eventName == HX_("sicko shake",57,8f,3d,8d))) {
HXLINE(  65)							::Compile_obj::shakeCamTimer = ( (Float)(::Std_obj::parseInt(eventValue)) );
HXLINE(  66)							::Compile_obj::shakeCamTimerHUD = ( (Float)(::Std_obj::parseInt(eventValue2)) );
            						}
            						else {
HXLINE(  67)							if ((eventName == HX_("time freeze",0a,e2,d7,86))) {
            								HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_1, ::PlayState,playState,::String,eventValue) HXARGC(1)
            								void _hx_run( ::flixel::tweens::FlxTween tween){
            									HX_STACKFRAME(&_hx_pos_93737c9261257c5d_72_whenTriggered)
HXLINE(  72)									if (::hx::IsEq( ::Std_obj::parseInt(eventValue),1 )) {
HXLINE(  73)										playState->pauseMusic();
            									}
            								}
            								HX_END_LOCAL_FUNC1((void))

HXLINE(  68)								bool _hx_tmp;
HXDLIN(  68)								if (::hx::IsEq( ::Std_obj::parseInt(eventValue),0 )) {
HXLINE(  68)									_hx_tmp = ::hx::IsNull( ::flixel::FlxG_obj::sound->music->_channel );
            								}
            								else {
HXLINE(  68)									_hx_tmp = false;
            								}
HXDLIN(  68)								if (_hx_tmp) {
HXLINE(  69)									playState->resyncVocals();
            								}
HXLINE(  71)								 ::Dynamic _hx_tmp1 =  ::Dynamic(::hx::Anon_obj::Create(1)
            									->setFixed(0,HX_("timeFreeze",44,d2,ed,4c),::Std_obj::parseFloat(eventValue)));
HXDLIN(  71)								Float _hx_tmp2 = (::Conductor_obj::crochet / ( (Float)(500) ));
HXDLIN(  71)								Float _hx_tmp3 = (_hx_tmp2 * ::Std_obj::parseFloat(eventValue2));
HXDLIN(  71)								::flixel::tweens::FlxTween_obj::tween(::hx::ClassOf< ::Compile >(),_hx_tmp1,_hx_tmp3, ::Dynamic(::hx::Anon_obj::Create(1)
            									->setFixed(0,HX_("onComplete",f8,d4,7e,5d), ::Dynamic(new _hx_Closure_1(playState,eventValue)))));
            							}
            							else {
HXLINE(  75)								if ((eventName == HX_("strum bounce",7f,2b,8c,ea))) {
HXLINE(  76)									this->offsetBounce = ( (int)(::Std_obj::parseInt(eventValue2)) );
HXLINE(  77)									::Compile_obj::sizeTimer = ( (int)(::Std_obj::parseInt(eventValue)) );
HXLINE(  79)									if ((playState->flipWiggle >= 1)) {
HXLINE(  80)										playState->flipWiggle = -1;
            									}
            									else {
HXLINE(  82)										playState->flipWiggle = 1;
            									}
            								}
            								else {
HXLINE(  83)									if ((eventName == HX_("note rewind",69,ac,f5,23))) {
HXLINE(  84)										 ::Dynamic _hx_tmp =  ::Dynamic(::hx::Anon_obj::Create(1)
            											->setFixed(0,HX_("AFFECTED_STRUMTIME",2b,57,7e,43),::Std_obj::parseFloat(eventValue)));
HXDLIN(  84)										Float _hx_tmp1 = (::Conductor_obj::stepCrochet / ( (Float)(500) ));
HXDLIN(  84)										::flixel::tweens::FlxTween_obj::tween(::hx::ClassOf< ::Note >(),_hx_tmp,(_hx_tmp1 * ::Std_obj::parseFloat(eventValue2)),null());
            									}
            									else {
HXLINE(  85)										if ((eventName == HX_("character change",07,45,5e,de))) {
HXLINE(  86)											if ((eventValue2.indexOf(HX_("dad",47,36,4c,00),null()) != -1)) {
HXLINE(  87)												::Array< ::String > arrayer = ::Array_obj< ::String >::__new();
HXDLIN(  87)												{
HXLINE(  87)													int _g = 0;
HXDLIN(  87)													int _g1 = ::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->length;
HXDLIN(  87)													while((_g < _g1)){
HXLINE(  87)														_g = (_g + 1);
HXDLIN(  87)														int i = (_g - 1);
HXDLIN(  87)														arrayer->push(::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->__get(i).split(HX_(".",2e,00,00,00))->__get(0));
            													}
            												}
HXDLIN(  87)												if (arrayer->contains(eventValue.toLowerCase())) {
HXLINE(  88)													playState->remove(playState->dad,null()).StaticCast<  ::flixel::FlxBasic >();
HXLINE(  89)													playState->dad->destroy();
HXLINE(  90)													playState->dad =  ::Character_obj::__alloc( HX_CTX ,( (Float)(100) ),( (Float)(100) ),eventValue,null(),null());
HXLINE(  91)													playState->dad->refresh(eventValue,playState->camPos);
HXLINE(  92)													playState->add(playState->dad).StaticCast<  ::flixel::FlxBasic >();
            												}
            											}
            											else {
HXLINE(  94)												bool _hx_tmp;
HXDLIN(  94)												if ((eventValue2.indexOf(HX_("bf",c4,55,00,00),null()) == -1)) {
HXLINE(  94)													_hx_tmp = (eventValue2.indexOf(HX_("boyfriend",6a,29,b8,e6),null()) != -1);
            												}
            												else {
HXLINE(  94)													_hx_tmp = true;
            												}
HXDLIN(  94)												if (_hx_tmp) {
HXLINE(  95)													::Array< ::String > arrayer = ::Array_obj< ::String >::__new();
HXDLIN(  95)													{
HXLINE(  95)														int _g = 0;
HXDLIN(  95)														int _g1 = ::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->length;
HXDLIN(  95)														while((_g < _g1)){
HXLINE(  95)															_g = (_g + 1);
HXDLIN(  95)															int i = (_g - 1);
HXDLIN(  95)															arrayer->push(::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->__get(i).split(HX_(".",2e,00,00,00))->__get(0));
            														}
            													}
HXDLIN(  95)													if (arrayer->contains(eventValue.toLowerCase())) {
HXLINE(  96)														playState->remove(playState->dad,null()).StaticCast<  ::flixel::FlxBasic >();
HXLINE(  97)														playState->dad->destroy();
HXLINE(  98)														playState->dad =  ::Character_obj::__alloc( HX_CTX ,( (Float)(100) ),( (Float)(100) ),eventValue,null(),null());
HXLINE(  99)														playState->dad->refresh(eventValue,playState->camPos);
HXLINE( 100)														playState->add(playState->dad).StaticCast<  ::flixel::FlxBasic >();
            													}
            												}
            											}
            										}
            									}
            								}
            							}
            						}
            					}
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC4(DefaultEvents_obj,whenTriggered,(void))

void DefaultEvents_obj::whenGameIsRunning(::Array< ::String > activeEvents, ::PlayState playState){
            	HX_STACKFRAME(&_hx_pos_93737c9261257c5d_107_whenGameIsRunning)
HXDLIN( 107)		if (activeEvents->contains(HX_("strum bounce",7f,2b,8c,ea))) {
HXLINE( 108)			Float a = ( (Float)((this->offsetBounce * playState->flipWiggle)) );
HXDLIN( 108)			::Compile_obj::strumOffsetEvent[0] = (a + ((( (Float)(::Compile_obj::sizeTimer) ) / ( (Float)(10) )) * (( (Float)(0) ) - a)));
HXLINE( 110)			if ((::Compile_obj::sizeTimer <= 0)) {
HXLINE( 111)				int _g = 0;
HXDLIN( 111)				int _g1 = activeEvents->length;
HXDLIN( 111)				while((_g < _g1)){
HXLINE( 111)					_g = (_g + 1);
HXDLIN( 111)					int i = (_g - 1);
HXLINE( 112)					if ((activeEvents->__get(i) == HX_("strum bounce",7f,2b,8c,ea))) {
HXLINE( 113)						activeEvents->remove(HX_("strum bounce",7f,2b,8c,ea));
            					}
            				}
            			}
            		}
            		else {
HXLINE( 117)			this->offsetBounce = 0;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(DefaultEvents_obj,whenGameIsRunning,(void))

void DefaultEvents_obj::whenNoteIsPressed( ::Note note, ::PlayState playState){
            	HX_STACKFRAME(&_hx_pos_93737c9261257c5d_122_whenNoteIsPressed)
HXDLIN( 122)		return;
            	}


HX_DEFINE_DYNAMIC_FUNC2(DefaultEvents_obj,whenNoteIsPressed,(void))


::hx::ObjectPtr< DefaultEvents_obj > DefaultEvents_obj::__new() {
	::hx::ObjectPtr< DefaultEvents_obj > __this = new DefaultEvents_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< DefaultEvents_obj > DefaultEvents_obj::__alloc(::hx::Ctx *_hx_ctx) {
	DefaultEvents_obj *__this = (DefaultEvents_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(DefaultEvents_obj), false, "example_code.DefaultEvents"));
	*(void **)__this = DefaultEvents_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

DefaultEvents_obj::DefaultEvents_obj()
{
}

::hx::Val DefaultEvents_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"offsetBounce") ) { return ::hx::Val( offsetBounce ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"whenTriggered") ) { return ::hx::Val( whenTriggered_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"whenGameIsRunning") ) { return ::hx::Val( whenGameIsRunning_dyn() ); }
		if (HX_FIELD_EQ(inName,"whenNoteIsPressed") ) { return ::hx::Val( whenNoteIsPressed_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val DefaultEvents_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"offsetBounce") ) { offsetBounce=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DefaultEvents_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("offsetBounce",7b,01,10,3e));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo DefaultEvents_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(DefaultEvents_obj,offsetBounce),HX_("offsetBounce",7b,01,10,3e)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *DefaultEvents_obj_sStaticStorageInfo = 0;
#endif

static ::String DefaultEvents_obj_sMemberFields[] = {
	HX_("offsetBounce",7b,01,10,3e),
	HX_("whenTriggered",7d,fd,1a,18),
	HX_("whenGameIsRunning",c9,45,e2,c7),
	HX_("whenNoteIsPressed",6c,06,30,1d),
	::String(null()) };

::hx::Class DefaultEvents_obj::__mClass;

void DefaultEvents_obj::__register()
{
	DefaultEvents_obj _hx_dummy;
	DefaultEvents_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("example_code.DefaultEvents",ce,71,c3,cd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(DefaultEvents_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< DefaultEvents_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = DefaultEvents_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = DefaultEvents_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace example_code
