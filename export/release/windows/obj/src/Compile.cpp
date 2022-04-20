#include <hxcpp.h>

#ifndef INCLUDED_CameraNote
#include <CameraNote.h>
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
#ifndef INCLUDED_Strum
#include <Strum.h>
#endif
#ifndef INCLUDED_betterShit_BetterCams
#include <betterShit/BetterCams.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_math_FlxRandom
#include <flixel/math/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_35_getNoteTime,"Compile","getNoteTime",0x4671e43a,"Compile.getNoteTime","Compile.hx",35,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_38_getcharacterJSON,"Compile","getcharacterJSON",0xc5bc0976,"Compile.getcharacterJSON","Compile.hx",38,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_47_compilePosition,"Compile","compilePosition",0xbc597421,"Compile.compilePosition","Compile.hx",47,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_55_spawn,"Compile","spawn",0xb6bec4e0,"Compile.spawn","Compile.hx",55,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_58_kill,"Compile","kill",0x65201499,"Compile.kill","Compile.hx",58,0xc3adcb4b)
static const Float _hx_array_data_50c04d53_6[] = {
	(Float)0,(Float)0,
};
static const Float _hx_array_data_50c04d53_7[] = {
	(Float)0,(Float)0,
};
static const Float _hx_array_data_50c04d53_8[] = {
	(Float)0,(Float)0,
};
static const Float _hx_array_data_50c04d53_9[] = {
	(Float)0,(Float)0,(Float)0,
};
static const Float _hx_array_data_50c04d53_10[] = {
	(Float)0,(Float)0,(Float)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_75_update,"Compile","update",0xfecf2fc4,"Compile.update","Compile.hx",75,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_92_update,"Compile","update",0xfecf2fc4,"Compile.update","Compile.hx",92,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_97_update,"Compile","update",0xfecf2fc4,"Compile.update","Compile.hx",97,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_109_eventHandler,"Compile","eventHandler",0xd646cecb,"Compile.eventHandler","Compile.hx",109,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_121_caculateShake,"Compile","caculateShake",0xa6914295,"Compile.caculateShake","Compile.hx",121,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_16_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",16,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_18_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",18,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_19_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",19,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_20_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",20,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_21_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",21,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_22_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",22,0xc3adcb4b)
static const Float _hx_array_data_50c04d53_22[] = {
	(Float)0,(Float)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_23_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",23,0xc3adcb4b)
static const Float _hx_array_data_50c04d53_24[] = {
	(Float)0,(Float)0,
};
static const Float _hx_array_data_50c04d53_25[] = {
	(Float)0,(Float)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_24_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",24,0xc3adcb4b)
static const Float _hx_array_data_50c04d53_27[] = {
	(Float)0,(Float)0,(Float)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_25_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",25,0xc3adcb4b)
static const Float _hx_array_data_50c04d53_29[] = {
	(Float)0,(Float)0,(Float)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_27_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",27,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_28_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",28,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_30_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",30,0xc3adcb4b)
HX_LOCAL_STACK_FRAME(_hx_pos_57a9bb3f23fab552_32_boot,"Compile","boot",0x5f31b92d,"Compile.boot","Compile.hx",32,0xc3adcb4b)

void Compile_obj::__construct() { }

Dynamic Compile_obj::__CreateEmpty() { return new Compile_obj; }

void *Compile_obj::_hx_vtable = 0;

Dynamic Compile_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Compile_obj > _hx_result = new Compile_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Compile_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x10dff293;
}

Float Compile_obj::strumOffset;

int Compile_obj::sizeTimer;

Float Compile_obj::shakeCamTimer;

Float Compile_obj::shakeCamTimerHUD;

Float Compile_obj::timeFreeze;

::Array< Float > Compile_obj::strumOffsetEvent;

::Array< ::Dynamic> Compile_obj::strumOffsetArray;

::Array< Float > Compile_obj::camAngle;

::Array< Float > Compile_obj::camPos;

::Array< ::String > Compile_obj::tempNoteAbstracts;

bool Compile_obj::preloadAddon;

::Array< ::Dynamic> Compile_obj::strumSize;

bool Compile_obj::jitStrumSize;

Float Compile_obj::getNoteTime(Float strumTime){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_35_getNoteTime)
HXDLIN(  35)		return (strumTime + (::Conductor_obj::stepCrochet * ::Note_obj::AFFECTED_STRUMTIME));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Compile_obj,getNoteTime,return )

::Array< ::String > Compile_obj::getcharacterJSON(){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_38_getcharacterJSON)
HXLINE(  39)		::Array< ::String > arrayer = ::Array_obj< ::String >::__new();
HXLINE(  41)		{
HXLINE(  41)			int _g = 0;
HXDLIN(  41)			int _g1 = ::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->length;
HXDLIN(  41)			while((_g < _g1)){
HXLINE(  41)				_g = (_g + 1);
HXDLIN(  41)				int i = (_g - 1);
HXLINE(  42)				arrayer->push(::sys::FileSystem_obj::readDirectory(HX_("config/characters",17,86,f6,a5))->__get(i).split(HX_(".",2e,00,00,00))->__get(0));
            			}
            		}
HXLINE(  44)		return arrayer;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Compile_obj,getcharacterJSON,return )

Float Compile_obj::compilePosition(Float strum){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_47_compilePosition)
HXLINE(  48)		Float noteY = ::Compile_obj::strumOffset;
HXLINE(  49)		noteY = (noteY + (strum - ::Compile_obj::strumOffset));
HXLINE(  51)		return noteY;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Compile_obj,compilePosition,return )

void Compile_obj::spawn(){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_55_spawn)
HXDLIN(  55)		::Compile_obj::kill();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Compile_obj,spawn,(void))

void Compile_obj::kill(){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_58_kill)
HXLINE(  59)		::Compile_obj::strumOffset = ( (Float)(0) );
HXLINE(  60)		::Compile_obj::sizeTimer = 0;
HXLINE(  61)		::Compile_obj::shakeCamTimer = ( (Float)(0) );
HXLINE(  62)		::Compile_obj::shakeCamTimerHUD = ( (Float)(0) );
HXLINE(  63)		::Compile_obj::timeFreeze = ( (Float)(0) );
HXLINE(  64)		::Compile_obj::strumOffsetEvent = ::Array_obj< Float >::fromData( _hx_array_data_50c04d53_6,2);
HXLINE(  65)		::Compile_obj::strumOffsetArray = ::Array_obj< ::Dynamic>::__new(2)->init(0,::Array_obj< Float >::fromData( _hx_array_data_50c04d53_7,2))->init(1,::Array_obj< Float >::fromData( _hx_array_data_50c04d53_8,2));
HXLINE(  66)		::Compile_obj::camPos = ::Array_obj< Float >::fromData( _hx_array_data_50c04d53_9,3);
HXLINE(  67)		::Compile_obj::camAngle = ::Array_obj< Float >::fromData( _hx_array_data_50c04d53_10,3);
HXLINE(  68)		::Compile_obj::tempNoteAbstracts = ::Array_obj< ::String >::__new(0);
HXLINE(  69)		::Compile_obj::preloadAddon = false;
HXLINE(  71)		::Compile_obj::jitStrumSize = false;
HXLINE(  72)		::Compile_obj::strumSize = ::Array_obj< ::Dynamic>::__new();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Compile_obj,kill,(void))

void Compile_obj::update(){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_75_update)
HXLINE(  76)		 ::betterShit::BetterCams mainCam = ( ( ::betterShit::BetterCams)(::flixel::FlxG_obj::camera) );
HXLINE(  77)		 ::betterShit::BetterCams camHUD = ::PlayState_obj::camHUD;
HXLINE(  78)		 ::betterShit::BetterCams noteCam = ( ( ::betterShit::BetterCams)(::PlayState_obj::camNOTE) );
HXLINE(  80)		Float _hx_tmp = ::Compile_obj::camAngle->__get(0);
HXDLIN(  80)		mainCam->set_engineAngle((_hx_tmp + ::Compile_obj::caculateShake(50,::Compile_obj::shakeCamTimer)));
HXLINE(  81)		Float _hx_tmp1 = ::Compile_obj::camAngle->__get(1);
HXDLIN(  81)		camHUD->set_engineAngle((_hx_tmp1 + ::Compile_obj::caculateShake(50,-(::Compile_obj::shakeCamTimerHUD))));
HXLINE(  82)		noteCam->set_engineAngle(::Compile_obj::camAngle->__get(2));
HXLINE(  84)		mainCam->set_engineX(::Compile_obj::camPos->__get(0));
HXLINE(  85)		camHUD->set_engineX(::Compile_obj::camPos->__get(1));
HXLINE(  87)		Float _hx_tmp2 = ::Compile_obj::camPos->__get(2);
HXDLIN(  87)		noteCam->set_engineX((_hx_tmp2 + ::Compile_obj::caculateShake(5,::Compile_obj::shakeCamTimer)));
HXLINE(  89)		::Compile_obj::eventHandler();
HXLINE(  91)		bool _hx_tmp3;
HXDLIN(  91)		if (!(::Compile_obj::jitStrumSize)) {
HXLINE(  91)			_hx_tmp3 = (::Compile_obj::sizeTimer > 0);
            		}
            		else {
HXLINE(  91)			_hx_tmp3 = true;
            		}
HXDLIN(  91)		if (_hx_tmp3) {
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(1)
            			void _hx_run( ::Strum spr){
            				HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_92_update)
HXLINE(  93)				spr->scale->set_x(::Compile_obj::strumSize->__get(spr->ID).StaticCast< ::Array< Float > >()->__get(0));
HXLINE(  94)				spr->scale->set_y((::Compile_obj::strumSize->__get(spr->ID).StaticCast< ::Array< Float > >()->__get(1) + (( (Float)(::Compile_obj::sizeTimer) ) / ( (Float)(100) ))));
            			}
            			HX_END_LOCAL_FUNC1((void))

            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_1) HXARGC(1)
            			void _hx_run( ::Strum spr){
            				HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_97_update)
HXLINE(  98)				spr->scale->set_x(::Compile_obj::strumSize->__get((spr->ID + 4)).StaticCast< ::Array< Float > >()->__get(0));
HXLINE(  99)				spr->scale->set_y((::Compile_obj::strumSize->__get((spr->ID + 4)).StaticCast< ::Array< Float > >()->__get(1) + (( (Float)(::Compile_obj::sizeTimer) ) / ( (Float)(100) ))));
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  92)			::PlayState_obj::opponentStrums->group->forEachAlive( ::Dynamic(new _hx_Closure_0()),false);
HXLINE(  97)			::PlayState_obj::playerStrums->group->forEachAlive( ::Dynamic(new _hx_Closure_1()),false);
            		}
HXLINE( 103)		::PlayState_obj::opponentStrums->set_x((::Compile_obj::strumOffsetArray->__get(0).StaticCast< ::Array< Float > >()->__get(0) + ::Compile_obj::strumOffsetEvent->__get(0)));
HXLINE( 104)		::PlayState_obj::playerStrums->set_x((::Compile_obj::strumOffsetArray->__get(0).StaticCast< ::Array< Float > >()->__get(1) + ::Compile_obj::strumOffsetEvent->__get(0)));
HXLINE( 105)		::PlayState_obj::opponentStrums->set_y((::Compile_obj::strumOffsetArray->__get(1).StaticCast< ::Array< Float > >()->__get(0) + ::Compile_obj::strumOffsetEvent->__get(1)));
HXLINE( 106)		::PlayState_obj::playerStrums->set_y((::Compile_obj::strumOffsetArray->__get(1).StaticCast< ::Array< Float > >()->__get(1) + ::Compile_obj::strumOffsetEvent->__get(1)));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Compile_obj,update,(void))

void Compile_obj::eventHandler(){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_109_eventHandler)
HXLINE( 110)		if ((::Compile_obj::shakeCamTimer > 0)) {
HXLINE( 111)			 ::Dynamic _hx_tmp = ::hx::ClassOf< ::Compile >();
HXDLIN( 111)			::Compile_obj::shakeCamTimer = (::Compile_obj::shakeCamTimer - ((Float)0.2));
            		}
HXLINE( 113)		if ((::Compile_obj::shakeCamTimerHUD > 0)) {
HXLINE( 114)			 ::Dynamic _hx_tmp = ::hx::ClassOf< ::Compile >();
HXDLIN( 114)			::Compile_obj::shakeCamTimerHUD = (::Compile_obj::shakeCamTimerHUD - ((Float)0.2));
            		}
HXLINE( 116)		if ((::Compile_obj::sizeTimer > 0)) {
HXLINE( 117)			 ::Dynamic _hx_tmp = ::hx::ClassOf< ::Compile >();
HXDLIN( 117)			::Compile_obj::sizeTimer = (::Compile_obj::sizeTimer - 1);
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Compile_obj,eventHandler,(void))

Float Compile_obj::caculateShake(int divider,Float shaker){
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_121_caculateShake)
HXDLIN( 121)		if ((::Compile_obj::shakeCamTimer > 0)) {
HXLINE( 122)			return (::flixel::FlxG_obj::random->_hx_float((-(::Compile_obj::shakeCamTimer) * ( (Float)(100) )),(::Compile_obj::shakeCamTimer * ( (Float)(100) )),null()) / ( (Float)(divider) ));
            		}
            		else {
HXLINE( 124)			return ( (Float)(0) );
            		}
HXLINE( 121)		return ((Float)0.);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Compile_obj,caculateShake,return )


Compile_obj::Compile_obj()
{
}

bool Compile_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { outValue = kill_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"spawn") ) { outValue = spawn_dyn(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"camPos") ) { outValue = ( camPos ); return true; }
		if (HX_FIELD_EQ(inName,"update") ) { outValue = update_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"camAngle") ) { outValue = ( camAngle ); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sizeTimer") ) { outValue = ( sizeTimer ); return true; }
		if (HX_FIELD_EQ(inName,"strumSize") ) { outValue = ( strumSize ); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"timeFreeze") ) { outValue = ( timeFreeze ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"strumOffset") ) { outValue = ( strumOffset ); return true; }
		if (HX_FIELD_EQ(inName,"getNoteTime") ) { outValue = getNoteTime_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"preloadAddon") ) { outValue = ( preloadAddon ); return true; }
		if (HX_FIELD_EQ(inName,"jitStrumSize") ) { outValue = ( jitStrumSize ); return true; }
		if (HX_FIELD_EQ(inName,"eventHandler") ) { outValue = eventHandler_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"shakeCamTimer") ) { outValue = ( shakeCamTimer ); return true; }
		if (HX_FIELD_EQ(inName,"caculateShake") ) { outValue = caculateShake_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"compilePosition") ) { outValue = compilePosition_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"shakeCamTimerHUD") ) { outValue = ( shakeCamTimerHUD ); return true; }
		if (HX_FIELD_EQ(inName,"strumOffsetEvent") ) { outValue = ( strumOffsetEvent ); return true; }
		if (HX_FIELD_EQ(inName,"strumOffsetArray") ) { outValue = ( strumOffsetArray ); return true; }
		if (HX_FIELD_EQ(inName,"getcharacterJSON") ) { outValue = getcharacterJSON_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"tempNoteAbstracts") ) { outValue = ( tempNoteAbstracts ); return true; }
	}
	return false;
}

bool Compile_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"camPos") ) { camPos=ioValue.Cast< ::Array< Float > >(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"camAngle") ) { camAngle=ioValue.Cast< ::Array< Float > >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sizeTimer") ) { sizeTimer=ioValue.Cast< int >(); return true; }
		if (HX_FIELD_EQ(inName,"strumSize") ) { strumSize=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"timeFreeze") ) { timeFreeze=ioValue.Cast< Float >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"strumOffset") ) { strumOffset=ioValue.Cast< Float >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"preloadAddon") ) { preloadAddon=ioValue.Cast< bool >(); return true; }
		if (HX_FIELD_EQ(inName,"jitStrumSize") ) { jitStrumSize=ioValue.Cast< bool >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"shakeCamTimer") ) { shakeCamTimer=ioValue.Cast< Float >(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"shakeCamTimerHUD") ) { shakeCamTimerHUD=ioValue.Cast< Float >(); return true; }
		if (HX_FIELD_EQ(inName,"strumOffsetEvent") ) { strumOffsetEvent=ioValue.Cast< ::Array< Float > >(); return true; }
		if (HX_FIELD_EQ(inName,"strumOffsetArray") ) { strumOffsetArray=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"tempNoteAbstracts") ) { tempNoteAbstracts=ioValue.Cast< ::Array< ::String > >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Compile_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo Compile_obj_sStaticStorageInfo[] = {
	{::hx::fsFloat,(void *) &Compile_obj::strumOffset,HX_("strumOffset",bc,05,af,62)},
	{::hx::fsInt,(void *) &Compile_obj::sizeTimer,HX_("sizeTimer",44,33,cc,0e)},
	{::hx::fsFloat,(void *) &Compile_obj::shakeCamTimer,HX_("shakeCamTimer",1c,76,01,6a)},
	{::hx::fsFloat,(void *) &Compile_obj::shakeCamTimerHUD,HX_("shakeCamTimerHUD",fb,2f,85,1e)},
	{::hx::fsFloat,(void *) &Compile_obj::timeFreeze,HX_("timeFreeze",44,d2,ed,4c)},
	{::hx::fsObject /* ::Array< Float > */ ,(void *) &Compile_obj::strumOffsetEvent,HX_("strumOffsetEvent",be,e8,c8,7f)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &Compile_obj::strumOffsetArray,HX_("strumOffsetArray",3d,8e,93,2f)},
	{::hx::fsObject /* ::Array< Float > */ ,(void *) &Compile_obj::camAngle,HX_("camAngle",44,29,1a,2b)},
	{::hx::fsObject /* ::Array< Float > */ ,(void *) &Compile_obj::camPos,HX_("camPos",c5,54,7c,b7)},
	{::hx::fsObject /* ::Array< ::String > */ ,(void *) &Compile_obj::tempNoteAbstracts,HX_("tempNoteAbstracts",4b,6f,80,f4)},
	{::hx::fsBool,(void *) &Compile_obj::preloadAddon,HX_("preloadAddon",f7,2c,a8,3b)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &Compile_obj::strumSize,HX_("strumSize",aa,02,78,f3)},
	{::hx::fsBool,(void *) &Compile_obj::jitStrumSize,HX_("jitStrumSize",15,95,86,cb)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void Compile_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Compile_obj::strumOffset,"strumOffset");
	HX_MARK_MEMBER_NAME(Compile_obj::sizeTimer,"sizeTimer");
	HX_MARK_MEMBER_NAME(Compile_obj::shakeCamTimer,"shakeCamTimer");
	HX_MARK_MEMBER_NAME(Compile_obj::shakeCamTimerHUD,"shakeCamTimerHUD");
	HX_MARK_MEMBER_NAME(Compile_obj::timeFreeze,"timeFreeze");
	HX_MARK_MEMBER_NAME(Compile_obj::strumOffsetEvent,"strumOffsetEvent");
	HX_MARK_MEMBER_NAME(Compile_obj::strumOffsetArray,"strumOffsetArray");
	HX_MARK_MEMBER_NAME(Compile_obj::camAngle,"camAngle");
	HX_MARK_MEMBER_NAME(Compile_obj::camPos,"camPos");
	HX_MARK_MEMBER_NAME(Compile_obj::tempNoteAbstracts,"tempNoteAbstracts");
	HX_MARK_MEMBER_NAME(Compile_obj::preloadAddon,"preloadAddon");
	HX_MARK_MEMBER_NAME(Compile_obj::strumSize,"strumSize");
	HX_MARK_MEMBER_NAME(Compile_obj::jitStrumSize,"jitStrumSize");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Compile_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Compile_obj::strumOffset,"strumOffset");
	HX_VISIT_MEMBER_NAME(Compile_obj::sizeTimer,"sizeTimer");
	HX_VISIT_MEMBER_NAME(Compile_obj::shakeCamTimer,"shakeCamTimer");
	HX_VISIT_MEMBER_NAME(Compile_obj::shakeCamTimerHUD,"shakeCamTimerHUD");
	HX_VISIT_MEMBER_NAME(Compile_obj::timeFreeze,"timeFreeze");
	HX_VISIT_MEMBER_NAME(Compile_obj::strumOffsetEvent,"strumOffsetEvent");
	HX_VISIT_MEMBER_NAME(Compile_obj::strumOffsetArray,"strumOffsetArray");
	HX_VISIT_MEMBER_NAME(Compile_obj::camAngle,"camAngle");
	HX_VISIT_MEMBER_NAME(Compile_obj::camPos,"camPos");
	HX_VISIT_MEMBER_NAME(Compile_obj::tempNoteAbstracts,"tempNoteAbstracts");
	HX_VISIT_MEMBER_NAME(Compile_obj::preloadAddon,"preloadAddon");
	HX_VISIT_MEMBER_NAME(Compile_obj::strumSize,"strumSize");
	HX_VISIT_MEMBER_NAME(Compile_obj::jitStrumSize,"jitStrumSize");
};

#endif

::hx::Class Compile_obj::__mClass;

static ::String Compile_obj_sStaticFields[] = {
	HX_("strumOffset",bc,05,af,62),
	HX_("sizeTimer",44,33,cc,0e),
	HX_("shakeCamTimer",1c,76,01,6a),
	HX_("shakeCamTimerHUD",fb,2f,85,1e),
	HX_("timeFreeze",44,d2,ed,4c),
	HX_("strumOffsetEvent",be,e8,c8,7f),
	HX_("strumOffsetArray",3d,8e,93,2f),
	HX_("camAngle",44,29,1a,2b),
	HX_("camPos",c5,54,7c,b7),
	HX_("tempNoteAbstracts",4b,6f,80,f4),
	HX_("preloadAddon",f7,2c,a8,3b),
	HX_("strumSize",aa,02,78,f3),
	HX_("jitStrumSize",15,95,86,cb),
	HX_("getNoteTime",d5,b3,23,82),
	HX_("getcharacterJSON",fb,c7,6c,61),
	HX_("compilePosition",3c,ad,ba,55),
	HX_("spawn",3b,9e,66,81),
	HX_("kill",9e,df,09,47),
	HX_("update",09,86,05,87),
	HX_("eventHandler",d0,a6,2a,d6),
	HX_("caculateShake",f0,6e,0a,8e),
	::String(null())
};

void Compile_obj::__register()
{
	Compile_obj _hx_dummy;
	Compile_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Compile",53,4d,c0,50);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Compile_obj::__GetStatic;
	__mClass->mSetStaticField = &Compile_obj::__SetStatic;
	__mClass->mMarkFunc = Compile_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Compile_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Compile_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Compile_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Compile_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Compile_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Compile_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_16_boot)
HXDLIN(  16)		strumOffset = ((Float)0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_18_boot)
HXDLIN(  18)		sizeTimer = 0;
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_19_boot)
HXDLIN(  19)		shakeCamTimer = ((Float)0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_20_boot)
HXDLIN(  20)		shakeCamTimerHUD = ((Float)0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_21_boot)
HXDLIN(  21)		timeFreeze = ((Float)0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_22_boot)
HXDLIN(  22)		strumOffsetEvent = ::Array_obj< Float >::fromData( _hx_array_data_50c04d53_22,2);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_23_boot)
HXDLIN(  23)		strumOffsetArray = ::Array_obj< ::Dynamic>::__new(2)->init(0,::Array_obj< Float >::fromData( _hx_array_data_50c04d53_24,2))->init(1,::Array_obj< Float >::fromData( _hx_array_data_50c04d53_25,2));
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_24_boot)
HXDLIN(  24)		camAngle = ::Array_obj< Float >::fromData( _hx_array_data_50c04d53_27,3);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_25_boot)
HXDLIN(  25)		camPos = ::Array_obj< Float >::fromData( _hx_array_data_50c04d53_29,3);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_27_boot)
HXDLIN(  27)		tempNoteAbstracts = ::Array_obj< ::String >::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_28_boot)
HXDLIN(  28)		preloadAddon = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_30_boot)
HXDLIN(  30)		strumSize = ::Array_obj< ::Dynamic>::__new();
            	}
{
            	HX_STACKFRAME(&_hx_pos_57a9bb3f23fab552_32_boot)
HXDLIN(  32)		jitStrumSize = false;
            	}
}

