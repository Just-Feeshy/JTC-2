#include <hxcpp.h>

#ifndef INCLUDED_NGio
#include <NGio.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimerManager
#include <flixel/util/FlxTimerManager.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxSignal
#include <flixel/util/IFlxSignal.h>
#endif
#ifndef INCLUDED_flixel_util__FlxSignal_FlxBaseSignal
#include <flixel/util/_FlxSignal/FlxBaseSignal.h>
#endif
#ifndef INCLUDED_flixel_util__FlxSignal_FlxSignal0
#include <flixel/util/_FlxSignal/FlxSignal0.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_io_newgrounds_Call
#include <io/newgrounds/Call.h>
#endif
#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
#endif
#ifndef INCLUDED_io_newgrounds_NG
#include <io/newgrounds/NG.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_AppComponent
#include <io/newgrounds/components/AppComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_ComponentList
#include <io/newgrounds/components/ComponentList.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_EventComponent
#include <io/newgrounds/components/EventComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Medal
#include <io/newgrounds/objects/Medal.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_Object
#include <io/newgrounds/objects/Object.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_ScoreBoard
#include <io/newgrounds/objects/ScoreBoard.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif
#ifndef INCLUDED_lime_app_Application
#include <lime/app/Application.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_lime_app_Module
#include <lime/app/Module.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_1f137c4d6a266f48_61_new,"NGio","new",0xf9819cd1,"NGio.new","NGio.hx",61,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_90_onNGLogin,"NGio","onNGLogin",0x33e3de62,"NGio.onNGLogin","NGio.hx",90,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_106_onNGMedalFetch,"NGio","onNGMedalFetch",0x8d5adb2a,"NGio.onNGMedalFetch","NGio.hx",106,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_142_onNGBoardsFetch,"NGio","onNGBoardsFetch",0x3d1e8fa6,"NGio.onNGBoardsFetch","NGio.hx",142,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_166_onNGScoresFetch,"NGio","onNGScoresFetch",0x7b2f4552,"NGio.onNGScoresFetch","NGio.hx",166,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_47_noLogin,"NGio","noLogin",0xae42b659,"NGio.noLogin","NGio.hx",47,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_44_noLogin,"NGio","noLogin",0xae42b659,"NGio.noLogin","NGio.hx",44,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_37_noLogin,"NGio","noLogin",0xae42b659,"NGio.noLogin","NGio.hx",37,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_149_postScore,"NGio","postScore",0x4096ba03,"NGio.postScore","NGio.hx",149,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_185_logEvent,"NGio","logEvent",0x006d7ee5,"NGio.logEvent","NGio.hx",185,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_192_unlockMedal,"NGio","unlockMedal",0xb0ad6a04,"NGio.unlockMedal","NGio.hx",192,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_24_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",24,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_25_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",25,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_27_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",27,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_29_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",29,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_30_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",30,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_32_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",32,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_33_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",33,0xcd75a7bf)
HX_LOCAL_STACK_FRAME(_hx_pos_1f137c4d6a266f48_34_boot,"NGio","boot",0x50009aa1,"NGio.boot","NGio.hx",34,0xcd75a7bf)

void NGio_obj::__construct(::String api,::String encKey,::String sessionId){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_61_new)
HXLINE(  62)		::haxe::Log_obj::trace(HX_("connecting to newgrounds",49,1b,2e,55),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),62,HX_("NGio",5f,e0,c4,33),HX_("new",60,d0,53,00)));
HXLINE(  64)		::io::newgrounds::NG_obj::createAndCheckSession(api,null(),sessionId,null());
HXLINE(  66)		::io::newgrounds::NG_obj::core->verbose = true;
HXLINE(  68)		::io::newgrounds::NG_obj::core->initEncryption(encKey,null(),null());
HXLINE(  70)		::haxe::Log_obj::trace(::io::newgrounds::NG_obj::core->attemptingLogin,::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),70,HX_("NGio",5f,e0,c4,33),HX_("new",60,d0,53,00)));
HXLINE(  72)		if (::io::newgrounds::NG_obj::core->attemptingLogin) {
HXLINE(  77)			::haxe::Log_obj::trace(HX_("attempting login",fe,74,81,50),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),77,HX_("NGio",5f,e0,c4,33),HX_("new",60,d0,53,00)));
HXLINE(  78)			::io::newgrounds::NG_obj::core->onLogin->add(this->onNGLogin_dyn(),null());
            		}
            		else {
HXLINE(  85)			::io::newgrounds::NG_obj::core->requestLogin(this->onNGLogin_dyn(),null(),null(),null());
            		}
            	}

Dynamic NGio_obj::__CreateEmpty() { return new NGio_obj; }

void *NGio_obj::_hx_vtable = 0;

Dynamic NGio_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< NGio_obj > _hx_result = new NGio_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool NGio_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0817d683;
}

void NGio_obj::onNGLogin(){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_90_onNGLogin)
HXLINE(  91)		 ::Dynamic _hx_tmp = ::haxe::Log_obj::trace;
HXDLIN(  91)		::String _hx_tmp1 = ( (::String)((HX_("logged in! user:",ed,2d,e5,40) + ::io::newgrounds::NG_obj::core->get_user()->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic))) );
HXDLIN(  91)		_hx_tmp(_hx_tmp1,::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),91,HX_("NGio",5f,e0,c4,33),HX_("onNGLogin",31,a7,5b,25)));
HXLINE(  92)		::NGio_obj::isLoggedIn = true;
HXLINE(  93)		::flixel::FlxG_obj::save->data->__SetField(HX_("sessionId",d1,58,4d,bb),::io::newgrounds::NG_obj::core->sessionId,::hx::paccDynamic);
HXLINE(  96)		::io::newgrounds::NG_obj::core->requestMedals(this->onNGMedalFetch_dyn(),null());
HXLINE(  99)		::io::newgrounds::NG_obj::core->requestScoreBoards(this->onNGBoardsFetch_dyn(),null());
HXLINE( 101)		::NGio_obj::ngDataLoaded->dispatch();
            	}


HX_DEFINE_DYNAMIC_FUNC0(NGio_obj,onNGLogin,(void))

void NGio_obj::onNGMedalFetch(){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_106_onNGMedalFetch)
            	}


HX_DEFINE_DYNAMIC_FUNC0(NGio_obj,onNGMedalFetch,(void))

void NGio_obj::onNGBoardsFetch(){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_142_onNGBoardsFetch)
HXDLIN( 142)		::haxe::Log_obj::trace(HX_("shoulda got score by NOW!",e0,b8,2d,75),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),142,HX_("NGio",5f,e0,c4,33),HX_("onNGBoardsFetch",b5,5d,77,86)));
            	}


HX_DEFINE_DYNAMIC_FUNC0(NGio_obj,onNGBoardsFetch,(void))

void NGio_obj::onNGScoresFetch(){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_166_onNGScoresFetch)
HXLINE( 167)		::NGio_obj::scoreboardsLoaded = true;
HXLINE( 169)		::NGio_obj::ngScoresLoaded->dispatch();
            	}


HX_DEFINE_DYNAMIC_FUNC0(NGio_obj,onNGScoresFetch,(void))

bool NGio_obj::isLoggedIn;

bool NGio_obj::scoreboardsLoaded;

::Array< ::Dynamic> NGio_obj::scoreboardArray;

 ::flixel::util::_FlxSignal::FlxSignal0 NGio_obj::ngDataLoaded;

 ::flixel::util::_FlxSignal::FlxSignal0 NGio_obj::ngScoresLoaded;

::String NGio_obj::GAME_VER;

::String NGio_obj::GAME_VER_NUMS;

bool NGio_obj::gotOnlineVer;

void NGio_obj::noLogin(::String api){
            		HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_1) HXARGC(1)
            		void _hx_run( ::flixel::util::FlxTimer tmr){
            			HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(1)
            			void _hx_run( ::Dynamic response){
            				HX_GC_STACKFRAME(&_hx_pos_1f137c4d6a266f48_47_noLogin)
HXLINE(  47)				if (::hx::IsNotNull( response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic) )) {
HXLINE(  49)					::NGio_obj::GAME_VER = ( (::String)( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("current_version",d2,3d,4a,b1),::hx::paccDynamic)) );
HXLINE(  50)					::NGio_obj::GAME_VER_NUMS = ::StringTools_obj::trim(::NGio_obj::GAME_VER.split(HX_(" ",20,00,00,00))->__get(0));
HXLINE(  51)					::haxe::Log_obj::trace((HX_("CURRENT NG VERSION: ",5e,21,96,d2) + ::NGio_obj::GAME_VER),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),51,HX_("NGio",5f,e0,c4,33),HX_("noLogin",68,5d,f7,4b)));
HXLINE(  52)					::haxe::Log_obj::trace((HX_("CURRENT NG VERSION: ",5e,21,96,d2) + ::NGio_obj::GAME_VER_NUMS),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),52,HX_("NGio",5f,e0,c4,33),HX_("noLogin",68,5d,f7,4b)));
HXLINE(  53)					::NGio_obj::gotOnlineVer = true;
            				}
            			}
            			HX_END_LOCAL_FUNC1((void))

            			HX_GC_STACKFRAME(&_hx_pos_1f137c4d6a266f48_44_noLogin)
HXLINE(  45)			 ::io::newgrounds::Call call = ::io::newgrounds::NG_obj::core->calls->app->getCurrentVersion(::NGio_obj::GAME_VER)->addDataHandler( ::Dynamic(new _hx_Closure_0()));
HXLINE(  56)			call->send();
            		}
            		HX_END_LOCAL_FUNC1((void))

            	HX_GC_STACKFRAME(&_hx_pos_1f137c4d6a266f48_37_noLogin)
HXLINE(  38)		::haxe::Log_obj::trace(HX_("INIT NOLOGIN",58,98,b9,6e),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),38,HX_("NGio",5f,e0,c4,33),HX_("noLogin",68,5d,f7,4b)));
HXLINE(  39)		::NGio_obj::GAME_VER = (HX_("v",76,00,00,00) + ::lime::app::Application_obj::current->meta->get(HX_("version",18,e7,f1,7c)));
HXLINE(  41)		::io::newgrounds::NG_obj::create(api,null(),null(),null());
HXLINE(  43)		 ::flixel::util::FlxTimer_obj::__alloc( HX_CTX ,null())->start(2, ::Dynamic(new _hx_Closure_1()),null());
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NGio_obj,noLogin,(void))

void NGio_obj::postScore(::hx::Null< int >  __o_score,::String song){
            		int score = __o_score.Default(0);
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_149_postScore)
HXDLIN( 149)		if (::NGio_obj::isLoggedIn) {
HXLINE( 151)			 ::Dynamic id = ::io::newgrounds::NG_obj::core->scoreBoards->keys();
HXDLIN( 151)			while(( (bool)(id->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 151)				int id1 = ( (int)(id->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 153)				 ::io::newgrounds::objects::ScoreBoard board = ( ( ::io::newgrounds::objects::ScoreBoard)(::io::newgrounds::NG_obj::core->scoreBoards->get(id1)) );
HXLINE( 155)				if (::hx::IsEq( song,board->_data->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic) )) {
HXLINE( 157)					board->postScore(score,HX_("Uhh meow?",f4,6d,8e,fc));
            				}
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(NGio_obj,postScore,(void))

void NGio_obj::logEvent(::String event){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_185_logEvent)
HXLINE( 186)		::io::newgrounds::NG_obj::core->calls->event->logEvent(event)->send();
HXLINE( 187)		::haxe::Log_obj::trace((HX_("should have logged: ",b3,75,8c,3a) + event),::hx::SourceInfo(HX_("build/NGio.hx",9e,54,d7,6e),187,HX_("NGio",5f,e0,c4,33),HX_("logEvent",f6,04,cb,60)));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NGio_obj,logEvent,(void))

void NGio_obj::unlockMedal(int id){
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_192_unlockMedal)
HXDLIN( 192)		if (::NGio_obj::isLoggedIn) {
HXLINE( 194)			 ::io::newgrounds::objects::Medal medal = ( ( ::io::newgrounds::objects::Medal)(::io::newgrounds::NG_obj::core->medals->get(id)) );
HXLINE( 195)			if (!(( (bool)(medal->_data->__Field(HX_("unlocked",23,34,0e,5c),::hx::paccDynamic)) ))) {
HXLINE( 196)				medal->sendUnlock();
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NGio_obj,unlockMedal,(void))


::hx::ObjectPtr< NGio_obj > NGio_obj::__new(::String api,::String encKey,::String sessionId) {
	::hx::ObjectPtr< NGio_obj > __this = new NGio_obj();
	__this->__construct(api,encKey,sessionId);
	return __this;
}

::hx::ObjectPtr< NGio_obj > NGio_obj::__alloc(::hx::Ctx *_hx_ctx,::String api,::String encKey,::String sessionId) {
	NGio_obj *__this = (NGio_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(NGio_obj), false, "NGio"));
	*(void **)__this = NGio_obj::_hx_vtable;
	__this->__construct(api,encKey,sessionId);
	return __this;
}

NGio_obj::NGio_obj()
{
}

::hx::Val NGio_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"onNGLogin") ) { return ::hx::Val( onNGLogin_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onNGMedalFetch") ) { return ::hx::Val( onNGMedalFetch_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onNGBoardsFetch") ) { return ::hx::Val( onNGBoardsFetch_dyn() ); }
		if (HX_FIELD_EQ(inName,"onNGScoresFetch") ) { return ::hx::Val( onNGScoresFetch_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool NGio_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"noLogin") ) { outValue = noLogin_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"GAME_VER") ) { outValue = ( GAME_VER ); return true; }
		if (HX_FIELD_EQ(inName,"logEvent") ) { outValue = logEvent_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"postScore") ) { outValue = postScore_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isLoggedIn") ) { outValue = ( isLoggedIn ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"unlockMedal") ) { outValue = unlockMedal_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ngDataLoaded") ) { outValue = ( ngDataLoaded ); return true; }
		if (HX_FIELD_EQ(inName,"gotOnlineVer") ) { outValue = ( gotOnlineVer ); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"GAME_VER_NUMS") ) { outValue = ( GAME_VER_NUMS ); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ngScoresLoaded") ) { outValue = ( ngScoresLoaded ); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"scoreboardArray") ) { outValue = ( scoreboardArray ); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"scoreboardsLoaded") ) { outValue = ( scoreboardsLoaded ); return true; }
	}
	return false;
}

bool NGio_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"GAME_VER") ) { GAME_VER=ioValue.Cast< ::String >(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isLoggedIn") ) { isLoggedIn=ioValue.Cast< bool >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ngDataLoaded") ) { ngDataLoaded=ioValue.Cast<  ::flixel::util::_FlxSignal::FlxSignal0 >(); return true; }
		if (HX_FIELD_EQ(inName,"gotOnlineVer") ) { gotOnlineVer=ioValue.Cast< bool >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"GAME_VER_NUMS") ) { GAME_VER_NUMS=ioValue.Cast< ::String >(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ngScoresLoaded") ) { ngScoresLoaded=ioValue.Cast<  ::flixel::util::_FlxSignal::FlxSignal0 >(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"scoreboardArray") ) { scoreboardArray=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"scoreboardsLoaded") ) { scoreboardsLoaded=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *NGio_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo NGio_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &NGio_obj::isLoggedIn,HX_("isLoggedIn",11,4d,dc,63)},
	{::hx::fsBool,(void *) &NGio_obj::scoreboardsLoaded,HX_("scoreboardsLoaded",44,75,af,14)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &NGio_obj::scoreboardArray,HX_("scoreboardArray",e5,0a,cd,8b)},
	{::hx::fsObject /*  ::flixel::util::_FlxSignal::FlxSignal0 */ ,(void *) &NGio_obj::ngDataLoaded,HX_("ngDataLoaded",68,53,80,54)},
	{::hx::fsObject /*  ::flixel::util::_FlxSignal::FlxSignal0 */ ,(void *) &NGio_obj::ngScoresLoaded,HX_("ngScoresLoaded",9f,2d,da,f9)},
	{::hx::fsString,(void *) &NGio_obj::GAME_VER,HX_("GAME_VER",36,60,1e,2f)},
	{::hx::fsString,(void *) &NGio_obj::GAME_VER_NUMS,HX_("GAME_VER_NUMS",56,9f,eb,04)},
	{::hx::fsBool,(void *) &NGio_obj::gotOnlineVer,HX_("gotOnlineVer",a4,50,ff,41)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String NGio_obj_sMemberFields[] = {
	HX_("onNGLogin",31,a7,5b,25),
	HX_("onNGMedalFetch",fb,c3,8d,10),
	HX_("onNGBoardsFetch",b5,5d,77,86),
	HX_("onNGScoresFetch",61,13,88,c4),
	::String(null()) };

static void NGio_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NGio_obj::isLoggedIn,"isLoggedIn");
	HX_MARK_MEMBER_NAME(NGio_obj::scoreboardsLoaded,"scoreboardsLoaded");
	HX_MARK_MEMBER_NAME(NGio_obj::scoreboardArray,"scoreboardArray");
	HX_MARK_MEMBER_NAME(NGio_obj::ngDataLoaded,"ngDataLoaded");
	HX_MARK_MEMBER_NAME(NGio_obj::ngScoresLoaded,"ngScoresLoaded");
	HX_MARK_MEMBER_NAME(NGio_obj::GAME_VER,"GAME_VER");
	HX_MARK_MEMBER_NAME(NGio_obj::GAME_VER_NUMS,"GAME_VER_NUMS");
	HX_MARK_MEMBER_NAME(NGio_obj::gotOnlineVer,"gotOnlineVer");
};

#ifdef HXCPP_VISIT_ALLOCS
static void NGio_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NGio_obj::isLoggedIn,"isLoggedIn");
	HX_VISIT_MEMBER_NAME(NGio_obj::scoreboardsLoaded,"scoreboardsLoaded");
	HX_VISIT_MEMBER_NAME(NGio_obj::scoreboardArray,"scoreboardArray");
	HX_VISIT_MEMBER_NAME(NGio_obj::ngDataLoaded,"ngDataLoaded");
	HX_VISIT_MEMBER_NAME(NGio_obj::ngScoresLoaded,"ngScoresLoaded");
	HX_VISIT_MEMBER_NAME(NGio_obj::GAME_VER,"GAME_VER");
	HX_VISIT_MEMBER_NAME(NGio_obj::GAME_VER_NUMS,"GAME_VER_NUMS");
	HX_VISIT_MEMBER_NAME(NGio_obj::gotOnlineVer,"gotOnlineVer");
};

#endif

::hx::Class NGio_obj::__mClass;

static ::String NGio_obj_sStaticFields[] = {
	HX_("isLoggedIn",11,4d,dc,63),
	HX_("scoreboardsLoaded",44,75,af,14),
	HX_("scoreboardArray",e5,0a,cd,8b),
	HX_("ngDataLoaded",68,53,80,54),
	HX_("ngScoresLoaded",9f,2d,da,f9),
	HX_("GAME_VER",36,60,1e,2f),
	HX_("GAME_VER_NUMS",56,9f,eb,04),
	HX_("gotOnlineVer",a4,50,ff,41),
	HX_("noLogin",68,5d,f7,4b),
	HX_("postScore",d2,82,0e,32),
	HX_("logEvent",f6,04,cb,60),
	HX_("unlockMedal",93,44,44,c6),
	::String(null())
};

void NGio_obj::__register()
{
	NGio_obj _hx_dummy;
	NGio_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("NGio",5f,e0,c4,33);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &NGio_obj::__GetStatic;
	__mClass->mSetStaticField = &NGio_obj::__SetStatic;
	__mClass->mMarkFunc = NGio_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(NGio_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(NGio_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< NGio_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = NGio_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = NGio_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = NGio_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void NGio_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_24_boot)
HXDLIN(  24)		isLoggedIn = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_25_boot)
HXDLIN(  25)		scoreboardsLoaded = false;
            	}
{
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_27_boot)
HXDLIN(  27)		scoreboardArray = ::Array_obj< ::Dynamic>::__new(0);
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_1f137c4d6a266f48_29_boot)
HXDLIN(  29)		ngDataLoaded =  ::flixel::util::_FlxSignal::FlxSignal0_obj::__alloc( HX_CTX );
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_1f137c4d6a266f48_30_boot)
HXDLIN(  30)		ngScoresLoaded =  ::flixel::util::_FlxSignal::FlxSignal0_obj::__alloc( HX_CTX );
            	}
{
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_32_boot)
HXDLIN(  32)		GAME_VER = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_33_boot)
HXDLIN(  33)		GAME_VER_NUMS = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_1f137c4d6a266f48_34_boot)
HXDLIN(  34)		gotOnlineVer = false;
            	}
}

