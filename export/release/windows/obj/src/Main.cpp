#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Preloader
#include <Preloader.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_MovieClip
#include <openfl/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_e47a9afac0942eb9_16_new,"Main","new",0x6616a5cb,"Main.new","Main.hx",16,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_53_init,"Main","init",0xea732345,"Main.init","Main.hx",53,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_63_setupGame,"Main","setupGame",0x7f7688ba,"Main.setupGame","Main.hx",63,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_35_main,"Main","main",0xed0e206e,"Main.main","Main.hx",35,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_27_boot,"Main","boot",0xe5d36c67,"Main.boot","Main.hx",27,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_28_boot,"Main","boot",0xe5d36c67,"Main.boot","Main.hx",28,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_30_boot,"Main","boot",0xe5d36c67,"Main.boot","Main.hx",30,0x087e5c05)

void Main_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_16_new)
HXLINE(  25)		this->startFullscreen = false;
HXLINE(  24)		this->skipSplash = true;
HXLINE(  23)		this->zoom = ((Float)-1);
HXLINE(  22)		this->initialState = ::hx::ClassOf< ::Preloader >();
HXLINE(  21)		this->gameHeight = 720;
HXLINE(  20)		this->gameWidth = 1280;
HXLINE(  40)		super::__construct();
HXLINE(  42)		if (::hx::IsNotNull( this->stage )) {
HXLINE(  44)			this->init(null());
            		}
            		else {
HXLINE(  48)			this->addEventListener(HX_("addedToStage",63,22,55,0c),this->init_dyn(),null(),null(),null());
            		}
            	}

Dynamic Main_obj::__CreateEmpty() { return new Main_obj; }

void *Main_obj::_hx_vtable = 0;

Dynamic Main_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Main_obj > _hx_result = new Main_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Main_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x0c89e854) {
		if (inClassId<=(int)0x07825a7d) {
			if (inClassId<=(int)0x0330636f) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x0330636f;
			} else {
				return inClassId==(int)0x07825a7d;
			}
		} else {
			return inClassId==(int)0x0c89e854;
		}
	} else {
		if (inClassId<=(int)0x4af7dd8e) {
			return inClassId==(int)0x1f4df417 || inClassId==(int)0x4af7dd8e;
		} else {
			return inClassId==(int)0x6b353933;
		}
	}
}

void Main_obj::init( ::openfl::events::Event E){
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_53_init)
HXLINE(  54)		if (this->hasEventListener(HX_("addedToStage",63,22,55,0c))) {
HXLINE(  56)			this->removeEventListener(HX_("addedToStage",63,22,55,0c),this->init_dyn(),null());
            		}
HXLINE(  59)		this->setupGame();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,init,(void))

void Main_obj::setupGame(){
            	HX_GC_STACKFRAME(&_hx_pos_e47a9afac0942eb9_63_setupGame)
HXLINE(  64)		int stageWidth = ::openfl::Lib_obj::get_current()->stage->stageWidth;
HXLINE(  65)		int stageHeight = ::openfl::Lib_obj::get_current()->stage->stageHeight;
HXLINE(  67)		if ((this->zoom == -1)) {
HXLINE(  69)			Float ratioX = (( (Float)(stageWidth) ) / ( (Float)(this->gameWidth) ));
HXLINE(  70)			Float ratioY = (( (Float)(stageHeight) ) / ( (Float)(this->gameHeight) ));
HXLINE(  71)			this->zoom = ::Math_obj::min(ratioX,ratioY);
HXLINE(  72)			this->gameWidth = ::Math_obj::ceil((( (Float)(stageWidth) ) / this->zoom));
HXLINE(  73)			this->gameHeight = ::Math_obj::ceil((( (Float)(stageHeight) ) / this->zoom));
            		}
HXLINE(  77)		this->initialState = ::hx::ClassOf< ::Preloader >();
HXLINE(  80)		this->feeshmora =  ::flixel::FlxGame_obj::__alloc( HX_CTX ,this->gameWidth,this->gameHeight,this->initialState,this->zoom,::Main_obj::framerate,::Main_obj::framerate,this->skipSplash,this->startFullscreen);
HXLINE(  82)		::flixel::FlxG_obj::save->bind(HX_("funkin",31,b2,4f,6f),HX_("ninjamuffin99",f7,4c,e5,00));
HXLINE(  84)		this->addChild(this->feeshmora);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,setupGame,(void))

bool Main_obj::feeshmoraModifiers;

int Main_obj::framerate;

int Main_obj::trueFramerate;

void Main_obj::main(){
            	HX_GC_STACKFRAME(&_hx_pos_e47a9afac0942eb9_35_main)
HXDLIN(  35)		 ::openfl::display::MovieClip _hx_tmp = ::openfl::Lib_obj::get_current();
HXDLIN(  35)		_hx_tmp->addChild( ::Main_obj::__alloc( HX_CTX ));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


::hx::ObjectPtr< Main_obj > Main_obj::__new() {
	::hx::ObjectPtr< Main_obj > __this = new Main_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Main_obj > Main_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Main_obj *__this = (Main_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Main_obj), true, "Main"));
	*(void **)__this = Main_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(feeshmora,"feeshmora");
	HX_MARK_MEMBER_NAME(gameWidth,"gameWidth");
	HX_MARK_MEMBER_NAME(gameHeight,"gameHeight");
	HX_MARK_MEMBER_NAME(initialState,"initialState");
	HX_MARK_MEMBER_NAME(zoom,"zoom");
	HX_MARK_MEMBER_NAME(skipSplash,"skipSplash");
	HX_MARK_MEMBER_NAME(startFullscreen,"startFullscreen");
	 ::openfl::display::Sprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(feeshmora,"feeshmora");
	HX_VISIT_MEMBER_NAME(gameWidth,"gameWidth");
	HX_VISIT_MEMBER_NAME(gameHeight,"gameHeight");
	HX_VISIT_MEMBER_NAME(initialState,"initialState");
	HX_VISIT_MEMBER_NAME(zoom,"zoom");
	HX_VISIT_MEMBER_NAME(skipSplash,"skipSplash");
	HX_VISIT_MEMBER_NAME(startFullscreen,"startFullscreen");
	 ::openfl::display::Sprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Main_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return ::hx::Val( zoom ); }
		if (HX_FIELD_EQ(inName,"init") ) { return ::hx::Val( init_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"feeshmora") ) { return ::hx::Val( feeshmora ); }
		if (HX_FIELD_EQ(inName,"gameWidth") ) { return ::hx::Val( gameWidth ); }
		if (HX_FIELD_EQ(inName,"setupGame") ) { return ::hx::Val( setupGame_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { return ::hx::Val( gameHeight ); }
		if (HX_FIELD_EQ(inName,"skipSplash") ) { return ::hx::Val( skipSplash ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"initialState") ) { return ::hx::Val( initialState ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"startFullscreen") ) { return ::hx::Val( startFullscreen ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Main_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"framerate") ) { outValue = ( framerate ); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"trueFramerate") ) { outValue = ( trueFramerate ); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"feeshmoraModifiers") ) { outValue = ( feeshmoraModifiers ); return true; }
	}
	return false;
}

::hx::Val Main_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { zoom=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"feeshmora") ) { feeshmora=inValue.Cast<  ::flixel::FlxGame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameWidth") ) { gameWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { gameHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skipSplash") ) { skipSplash=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"initialState") ) { initialState=inValue.Cast< ::hx::Class >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"startFullscreen") ) { startFullscreen=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Main_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"framerate") ) { framerate=ioValue.Cast< int >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"trueFramerate") ) { trueFramerate=ioValue.Cast< int >(); return true; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"feeshmoraModifiers") ) { feeshmoraModifiers=ioValue.Cast< bool >(); return true; }
	}
	return false;
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("feeshmora",6c,69,26,2a));
	outFields->push(HX_("gameWidth",b4,a4,7d,ff));
	outFields->push(HX_("gameHeight",79,f1,c1,44));
	outFields->push(HX_("initialState",ed,76,1b,48));
	outFields->push(HX_("zoom",13,a3,f8,50));
	outFields->push(HX_("skipSplash",46,75,9c,27));
	outFields->push(HX_("startFullscreen",3d,c1,ee,2d));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Main_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxGame */ ,(int)offsetof(Main_obj,feeshmora),HX_("feeshmora",6c,69,26,2a)},
	{::hx::fsInt,(int)offsetof(Main_obj,gameWidth),HX_("gameWidth",b4,a4,7d,ff)},
	{::hx::fsInt,(int)offsetof(Main_obj,gameHeight),HX_("gameHeight",79,f1,c1,44)},
	{::hx::fsObject /* ::hx::Class */ ,(int)offsetof(Main_obj,initialState),HX_("initialState",ed,76,1b,48)},
	{::hx::fsFloat,(int)offsetof(Main_obj,zoom),HX_("zoom",13,a3,f8,50)},
	{::hx::fsBool,(int)offsetof(Main_obj,skipSplash),HX_("skipSplash",46,75,9c,27)},
	{::hx::fsBool,(int)offsetof(Main_obj,startFullscreen),HX_("startFullscreen",3d,c1,ee,2d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo Main_obj_sStaticStorageInfo[] = {
	{::hx::fsBool,(void *) &Main_obj::feeshmoraModifiers,HX_("feeshmoraModifiers",30,fa,99,85)},
	{::hx::fsInt,(void *) &Main_obj::framerate,HX_("framerate",8d,e5,4b,4e)},
	{::hx::fsInt,(void *) &Main_obj::trueFramerate,HX_("trueFramerate",5f,c4,9e,95)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String Main_obj_sMemberFields[] = {
	HX_("feeshmora",6c,69,26,2a),
	HX_("gameWidth",b4,a4,7d,ff),
	HX_("gameHeight",79,f1,c1,44),
	HX_("initialState",ed,76,1b,48),
	HX_("zoom",13,a3,f8,50),
	HX_("skipSplash",46,75,9c,27),
	HX_("startFullscreen",3d,c1,ee,2d),
	HX_("init",10,3b,bb,45),
	HX_("setupGame",0f,51,ed,9e),
	::String(null()) };

static void Main_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::feeshmoraModifiers,"feeshmoraModifiers");
	HX_MARK_MEMBER_NAME(Main_obj::framerate,"framerate");
	HX_MARK_MEMBER_NAME(Main_obj::trueFramerate,"trueFramerate");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Main_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::feeshmoraModifiers,"feeshmoraModifiers");
	HX_VISIT_MEMBER_NAME(Main_obj::framerate,"framerate");
	HX_VISIT_MEMBER_NAME(Main_obj::trueFramerate,"trueFramerate");
};

#endif

::hx::Class Main_obj::__mClass;

static ::String Main_obj_sStaticFields[] = {
	HX_("feeshmoraModifiers",30,fa,99,85),
	HX_("framerate",8d,e5,4b,4e),
	HX_("trueFramerate",5f,c4,9e,95),
	HX_("main",39,38,56,48),
	::String(null())
};

void Main_obj::__register()
{
	Main_obj _hx_dummy;
	Main_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Main",59,64,2f,33);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Main_obj::__GetStatic;
	__mClass->mSetStaticField = &Main_obj::__SetStatic;
	__mClass->mMarkFunc = Main_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Main_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Main_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Main_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Main_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Main_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Main_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Main_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_27_boot)
HXDLIN(  27)		feeshmoraModifiers = true;
            	}
{
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_28_boot)
HXDLIN(  28)		framerate = 100;
            	}
{
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_30_boot)
HXDLIN(  30)		trueFramerate = ::Main_obj::framerate;
            	}
}

