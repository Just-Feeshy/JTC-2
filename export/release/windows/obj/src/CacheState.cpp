#include <hxcpp.h>

#ifndef INCLUDED_CacheState
#include <CacheState.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_JsonParser_2
#include <JsonParser_2.h>
#endif
#ifndef INCLUDED_LoadingState
#include <LoadingState.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
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
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
#ifndef INCLUDED_json2object_PositionUtils
#include <json2object/PositionUtils.h>
#endif
#ifndef INCLUDED_json2object_reader_BaseParser
#include <json2object/reader/BaseParser.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
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
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_sys_thread__Thread_HaxeThread
#include <sys/thread/_Thread/HaxeThread.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_0212c740f4ef8eb7_16_new,"CacheState","new",0xbe6d7501,"CacheState.new","CacheState.hx",16,0x917fe58f)
HX_LOCAL_STACK_FRAME(_hx_pos_0212c740f4ef8eb7_36_create,"CacheState","create",0xa4ff9cfb,"CacheState.create","CacheState.hx",36,0x917fe58f)
HX_LOCAL_STACK_FRAME(_hx_pos_0212c740f4ef8eb7_29_create,"CacheState","create",0xa4ff9cfb,"CacheState.create","CacheState.hx",29,0x917fe58f)
HX_LOCAL_STACK_FRAME(_hx_pos_0212c740f4ef8eb7_42_cacheStuff,"CacheState","cacheStuff",0x37af9ed1,"CacheState.cacheStuff","CacheState.hx",42,0x917fe58f)
HX_LOCAL_STACK_FRAME(_hx_pos_0212c740f4ef8eb7_51_loadAndSwitchState,"CacheState","loadAndSwitchState",0xcc50132b,"CacheState.loadAndSwitchState","CacheState.hx",51,0x917fe58f)

void CacheState_obj::__construct( ::flixel::FlxState target,bool stopMusic){
            	HX_STACKFRAME(&_hx_pos_0212c740f4ef8eb7_16_new)
HXLINE(  18)		this->stopMusic = false;
HXLINE(  23)		super::__construct();
HXLINE(  25)		this->target = target;
HXLINE(  26)		this->stopMusic = stopMusic;
            	}

Dynamic CacheState_obj::__CreateEmpty() { return new CacheState_obj; }

void *CacheState_obj::_hx_vtable = 0;

Dynamic CacheState_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CacheState_obj > _hx_result = new CacheState_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool CacheState_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2f064378) {
		if (inClassId<=(int)0x23a57bae) {
			if (inClassId<=(int)0x146909b3) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x146909b3;
			} else {
				return inClassId==(int)0x23a57bae;
			}
		} else {
			return inClassId==(int)0x29d19794 || inClassId==(int)0x2f064378;
		}
	} else {
		if (inClassId<=(int)0x7c795c9f) {
			if (inClassId<=(int)0x62817b24) {
				return inClassId==(int)0x3f706236 || inClassId==(int)0x62817b24;
			} else {
				return inClassId==(int)0x7c795c9f;
			}
		} else {
			return inClassId==(int)0x7ccf8994;
		}
	}
}

void CacheState_obj::create(){
            		HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::CacheState,_gthis) HXARGC(0)
            		void _hx_run(){
            			HX_GC_STACKFRAME(&_hx_pos_0212c740f4ef8eb7_36_create)
HXLINE(  36)			_gthis->cacheStuff();
            		}
            		HX_END_LOCAL_FUNC0((void))

            	HX_GC_STACKFRAME(&_hx_pos_0212c740f4ef8eb7_29_create)
HXDLIN(  29)		 ::CacheState _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  30)		this->menuBG =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  31)		 ::flixel::FlxSprite _hx_tmp = this->menuBG;
HXDLIN(  31)		_hx_tmp->loadGraphic(::Paths_obj::image(HX_("default_loading_screen",0d,f7,64,0a),null()),null(),null(),null(),null(),null());
HXLINE(  32)		{
HXLINE(  32)			 ::flixel::FlxSprite _this = this->menuBG;
HXDLIN(  32)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN(  32)			bool _hx_tmp1;
HXDLIN(  32)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE(  32)					_hx_tmp1 = true;
            				}
            				break;
            				default:{
HXLINE(  32)					_hx_tmp1 = false;
            				}
            			}
HXDLIN(  32)			if (_hx_tmp1) {
HXLINE(  32)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  32)				_this->set_x(((( (Float)(_hx_tmp) ) - _this->get_width()) / ( (Float)(2) )));
            			}
HXDLIN(  32)			bool _hx_tmp2;
HXDLIN(  32)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE(  32)					_hx_tmp2 = true;
            				}
            				break;
            				default:{
HXLINE(  32)					_hx_tmp2 = false;
            				}
            			}
HXDLIN(  32)			if (_hx_tmp2) {
HXLINE(  32)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN(  32)				_this->set_y(((( (Float)(_hx_tmp) ) - _this->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE(  33)		this->add(this->menuBG);
HXLINE(  35)		::sys::thread::_Thread::HaxeThread_obj::create( ::Dynamic(new _hx_Closure_0(_gthis)),false);
HXLINE(  39)		this->super::create();
            	}


void CacheState_obj::cacheStuff(){
            	HX_STACKFRAME(&_hx_pos_0212c740f4ef8eb7_42_cacheStuff)
HXLINE(  43)		if (!(( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("preload",c9,47,43,35),::hx::paccDynamic)) ))) {
HXLINE(  44)			{
HXLINE(  44)				 ::flixel::FlxState nextState = ::LoadingState_obj::getNextState(this->target,this->stopMusic);
HXDLIN(  44)				if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  44)					::flixel::FlxG_obj::game->_requestedState = nextState;
            				}
            			}
HXLINE(  45)			return;
            		}
HXLINE(  48)		{
HXLINE(  48)			 ::flixel::FlxState nextState = ::LoadingState_obj::getNextState(this->target,this->stopMusic);
HXDLIN(  48)			if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  48)				::flixel::FlxG_obj::game->_requestedState = nextState;
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(CacheState_obj,cacheStuff,(void))

void CacheState_obj::loadAndSwitchState( ::flixel::FlxState target, ::Dynamic __o_stopMusic){
            		 ::Dynamic stopMusic = __o_stopMusic;
            		if (::hx::IsNull(__o_stopMusic)) stopMusic = true;
            	HX_GC_STACKFRAME(&_hx_pos_0212c740f4ef8eb7_51_loadAndSwitchState)
HXLINE(  52)		 ::JsonParser_2 parser =  ::JsonParser_2_obj::__alloc( HX_CTX ,null(),null(),null());
HXLINE(  54)		if (::lime::utils::Assets_obj::exists(::Paths_obj::getPath(((HX_("data/",c5,0e,88,d4) + ( (::String)(::PlayState_obj::SONG->__Field(HX_("song",d5,23,58,4c),::hx::paccDynamic)) ).toLowerCase()) + HX_("/cache.json",c3,98,37,1b)),HX_("TEXT",ad,94,ba,37),HX_("",00,00,00,00)),null())) {
HXLINE(  55)			 ::flixel::FlxState nextState =  ::CacheState_obj::__alloc( HX_CTX , ::PlayState_obj::__alloc( HX_CTX ,null()),true);
HXDLIN(  55)			if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  55)				::flixel::FlxG_obj::game->_requestedState = nextState;
            			}
            		}
            		else {
HXLINE(  57)			 ::flixel::FlxState nextState = ::LoadingState_obj::getNextState(( ( ::flixel::FlxState)( ::PlayState_obj::__alloc( HX_CTX ,null())) ),false);
HXDLIN(  57)			if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  57)				::flixel::FlxG_obj::game->_requestedState = nextState;
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CacheState_obj,loadAndSwitchState,(void))


::hx::ObjectPtr< CacheState_obj > CacheState_obj::__new( ::flixel::FlxState target,bool stopMusic) {
	::hx::ObjectPtr< CacheState_obj > __this = new CacheState_obj();
	__this->__construct(target,stopMusic);
	return __this;
}

::hx::ObjectPtr< CacheState_obj > CacheState_obj::__alloc(::hx::Ctx *_hx_ctx, ::flixel::FlxState target,bool stopMusic) {
	CacheState_obj *__this = (CacheState_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CacheState_obj), true, "CacheState"));
	*(void **)__this = CacheState_obj::_hx_vtable;
	__this->__construct(target,stopMusic);
	return __this;
}

CacheState_obj::CacheState_obj()
{
}

void CacheState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CacheState);
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(stopMusic,"stopMusic");
	HX_MARK_MEMBER_NAME(menuBG,"menuBG");
	 ::HelperStates_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CacheState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(stopMusic,"stopMusic");
	HX_VISIT_MEMBER_NAME(menuBG,"menuBG");
	 ::HelperStates_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val CacheState_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return ::hx::Val( target ); }
		if (HX_FIELD_EQ(inName,"menuBG") ) { return ::hx::Val( menuBG ); }
		if (HX_FIELD_EQ(inName,"create") ) { return ::hx::Val( create_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"stopMusic") ) { return ::hx::Val( stopMusic ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cacheStuff") ) { return ::hx::Val( cacheStuff_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool CacheState_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"loadAndSwitchState") ) { outValue = loadAndSwitchState_dyn(); return true; }
	}
	return false;
}

::hx::Val CacheState_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast<  ::flixel::FlxState >(); return inValue; }
		if (HX_FIELD_EQ(inName,"menuBG") ) { menuBG=inValue.Cast<  ::flixel::FlxSprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"stopMusic") ) { stopMusic=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CacheState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("target",51,f3,ec,86));
	outFields->push(HX_("stopMusic",43,09,9d,20));
	outFields->push(HX_("menuBG",24,65,6d,05));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CacheState_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::flixel::FlxState */ ,(int)offsetof(CacheState_obj,target),HX_("target",51,f3,ec,86)},
	{::hx::fsBool,(int)offsetof(CacheState_obj,stopMusic),HX_("stopMusic",43,09,9d,20)},
	{::hx::fsObject /*  ::flixel::FlxSprite */ ,(int)offsetof(CacheState_obj,menuBG),HX_("menuBG",24,65,6d,05)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CacheState_obj_sStaticStorageInfo = 0;
#endif

static ::String CacheState_obj_sMemberFields[] = {
	HX_("target",51,f3,ec,86),
	HX_("stopMusic",43,09,9d,20),
	HX_("menuBG",24,65,6d,05),
	HX_("create",fc,66,0f,7c),
	HX_("cacheStuff",52,fd,d2,c6),
	::String(null()) };

::hx::Class CacheState_obj::__mClass;

static ::String CacheState_obj_sStaticFields[] = {
	HX_("loadAndSwitchState",ac,5a,a7,a6),
	::String(null())
};

void CacheState_obj::__register()
{
	CacheState_obj _hx_dummy;
	CacheState_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("CacheState",8f,e0,74,bd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &CacheState_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(CacheState_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CacheState_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CacheState_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CacheState_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CacheState_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

