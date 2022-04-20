#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_Controls
#include <Controls.h>
#endif
#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MainMenuState
#include <MainMenuState.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_PlayerSettings
#include <PlayerSettings.h>
#endif
#ifndef INCLUDED_WarningSubGroup
#include <WarningSubGroup.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxAction
#include <flixel/input/actions/FlxAction.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionDigital
#include <flixel/input/actions/FlxActionDigital.h>
#endif
#ifndef INCLUDED_flixel_input_actions_FlxActionSet
#include <flixel/input/actions/FlxActionSet.h>
#endif
#ifndef INCLUDED_flixel_math_FlxPoint
#include <flixel/math/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextBorderStyle
#include <flixel/text/FlxTextBorderStyle.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAxes
#include <flixel/util/FlxAxes.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxPooled
#include <flixel/util/IFlxPooled.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_37bdfba41cd05886_12_new,"WarningSubGroup","new",0xa0861e6d,"WarningSubGroup.new","WarningSubGroup.hx",12,0xb1824da3)
HX_LOCAL_STACK_FRAME(_hx_pos_37bdfba41cd05886_24_get_controls,"WarningSubGroup","get_controls",0x2ab242d2,"WarningSubGroup.get_controls","WarningSubGroup.hx",24,0xb1824da3)
HX_LOCAL_STACK_FRAME(_hx_pos_37bdfba41cd05886_47_update,"WarningSubGroup","update",0x294fbe1c,"WarningSubGroup.update","WarningSubGroup.hx",47,0xb1824da3)
HX_LOCAL_STACK_FRAME(_hx_pos_37bdfba41cd05886_52_update,"WarningSubGroup","update",0x294fbe1c,"WarningSubGroup.update","WarningSubGroup.hx",52,0xb1824da3)
HX_LOCAL_STACK_FRAME(_hx_pos_37bdfba41cd05886_66_getWarning,"WarningSubGroup","getWarning",0x49909df9,"WarningSubGroup.getWarning","WarningSubGroup.hx",66,0xb1824da3)

void WarningSubGroup_obj::__construct(::Array< ::String > warn){
            	HX_GC_STACKFRAME(&_hx_pos_37bdfba41cd05886_12_new)
HXLINE(  15)		this->sway = ((Float)-1);
HXLINE(  13)		this->acceptedTermsOfService = false;
HXLINE(  27)		super::__construct(0,0,null());
HXLINE(  29)		 ::flixel::FlxSprite bg =  ::flixel::FlxSprite_obj::__alloc( HX_CTX ,null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,::flixel::FlxG_obj::height,-16777216,null(),null());
HXLINE(  30)		bg->scrollFactor->set(null(),null());
HXLINE(  31)		this->add(bg);
HXLINE(  33)		int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  33)		this->warningTxt =  ::flixel::text::FlxText_obj::__alloc( HX_CTX ,0,0,_hx_tmp,(HX_("WARNING!\n\n",65,f2,a2,2e) + this->getWarning(warn)),32,null());
HXLINE(  38)		this->warningTxt->setFormat(HX_("VCR OSD Mono",be,44,e4,b8),32,-1,HX_("center",d5,25,db,05),null(),null(),null());
HXLINE(  39)		{
HXLINE(  39)			 ::flixel::text::FlxText _this = this->warningTxt;
HXDLIN(  39)			 ::flixel::util::FlxAxes axes = ::flixel::util::FlxAxes_obj::XY_dyn();
HXDLIN(  39)			bool _hx_tmp1;
HXDLIN(  39)			switch((int)(axes->_hx_getIndex())){
            				case (int)0: case (int)2: {
HXLINE(  39)					_hx_tmp1 = true;
            				}
            				break;
            				default:{
HXLINE(  39)					_hx_tmp1 = false;
            				}
            			}
HXDLIN(  39)			if (_hx_tmp1) {
HXLINE(  39)				int _hx_tmp = ::flixel::FlxG_obj::width;
HXDLIN(  39)				_this->set_x(((( (Float)(_hx_tmp) ) - _this->get_width()) / ( (Float)(2) )));
            			}
HXDLIN(  39)			bool _hx_tmp2;
HXDLIN(  39)			switch((int)(axes->_hx_getIndex())){
            				case (int)1: case (int)2: {
HXLINE(  39)					_hx_tmp2 = true;
            				}
            				break;
            				default:{
HXLINE(  39)					_hx_tmp2 = false;
            				}
            			}
HXDLIN(  39)			if (_hx_tmp2) {
HXLINE(  39)				int _hx_tmp = ::flixel::FlxG_obj::height;
HXDLIN(  39)				_this->set_y(((( (Float)(_hx_tmp) ) - _this->get_height()) / ( (Float)(2) )));
            			}
            		}
HXLINE(  40)		this->add(this->warningTxt);
HXLINE(  42)		this->txtY = this->warningTxt->y;
HXLINE(  44)		this->set_cameras(::Array_obj< ::Dynamic>::__new(1)->init(0,::PlayState_obj::camHUD));
            	}

Dynamic WarningSubGroup_obj::__CreateEmpty() { return new WarningSubGroup_obj; }

void *WarningSubGroup_obj::_hx_vtable = 0;

Dynamic WarningSubGroup_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< WarningSubGroup_obj > _hx_result = new WarningSubGroup_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool WarningSubGroup_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2c01639b) {
		if (inClassId<=(int)0x288ce903) {
			if (inClassId<=(int)0x2282e773) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x2282e773;
			} else {
				return inClassId==(int)0x288ce903;
			}
		} else {
			return inClassId==(int)0x2c01639b;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

 ::Controls WarningSubGroup_obj::get_controls(){
            	HX_STACKFRAME(&_hx_pos_37bdfba41cd05886_24_get_controls)
HXDLIN(  24)		return ::PlayerSettings_obj::player1->controls;
            	}


HX_DEFINE_DYNAMIC_FUNC0(WarningSubGroup_obj,get_controls,return )

void WarningSubGroup_obj::update(Float elapsed){
            	HX_GC_STACKFRAME(&_hx_pos_37bdfba41cd05886_47_update)
HXDLIN(  47)		 ::WarningSubGroup _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE(  48)		bool _hx_tmp;
HXDLIN(  48)		if (::PlayerSettings_obj::player1->controls->_accept->check()) {
HXLINE(  48)			_hx_tmp = !(this->pressedSwitch);
            		}
            		else {
HXLINE(  48)			_hx_tmp = false;
            		}
HXDLIN(  48)		if (_hx_tmp) {
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::WarningSubGroup,_gthis) HXARGC(1)
            			void _hx_run( ::flixel::tweens::FlxTween twn){
            				HX_STACKFRAME(&_hx_pos_37bdfba41cd05886_52_update)
HXLINE(  52)				_gthis->acceptedTermsOfService = true;
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  49)			this->pressedSwitch = true;
HXLINE(  51)			::flixel::tweens::FlxTween_obj::tween(::hx::ObjectPtr<OBJ_>(this), ::Dynamic(::hx::Anon_obj::Create(1)
            				->setFixed(0,HX_("alpha",5e,a7,96,21),0)),1, ::Dynamic(::hx::Anon_obj::Create(2)
            				->setFixed(0,HX_("ease",ee,8b,0c,43),::flixel::tweens::FlxEase_obj::quadOut_dyn())
            				->setFixed(1,HX_("onComplete",f8,d4,7e,5d), ::Dynamic(new _hx_Closure_0(_gthis)))));
            		}
HXLINE(  56)		if (::PlayerSettings_obj::player1->controls->_back->check()) {
HXLINE(  57)			 ::flixel::FlxState nextState =  ::MainMenuState_obj::__alloc( HX_CTX ,true);
HXDLIN(  57)			if (::flixel::FlxG_obj::game->_state->switchTo(nextState)) {
HXLINE(  57)				::flixel::FlxG_obj::game->_requestedState = nextState;
            			}
            		}
HXLINE(  59)		this->super::update((elapsed / ((Float)1.25)));
HXLINE(  61)		 ::WarningSubGroup _hx_tmp1 = ::hx::ObjectPtr<OBJ_>(this);
HXDLIN(  61)		_hx_tmp1->sway = (_hx_tmp1->sway + ((Float)0.004));
HXLINE(  63)		this->warningTxt->set_y((this->txtY + (::Math_obj::sin((this->sway * ::Math_obj::PI)) * ( (Float)(15) ))));
            	}


::String WarningSubGroup_obj::getWarning(::Array< ::String > wrns){
            	HX_STACKFRAME(&_hx_pos_37bdfba41cd05886_66_getWarning)
HXLINE(  67)		::haxe::Log_obj::trace(wrns,::hx::SourceInfo(HX_("build/WarningSubGroup.hx",24,9f,28,1d),67,HX_("WarningSubGroup",fb,63,49,f8),HX_("getWarning",66,60,2d,59)));
HXLINE(  69)		{
HXLINE(  69)			int _g = 0;
HXDLIN(  69)			while((_g < wrns->length)){
HXLINE(  69)				::String v = wrns->__get(_g);
HXDLIN(  69)				_g = (_g + 1);
HXLINE(  70)				bool _hx_tmp;
HXDLIN(  70)				if (::hx::IsNotNull( v )) {
HXLINE(  70)					_hx_tmp = (v != HX_("",00,00,00,00));
            				}
            				else {
HXLINE(  70)					_hx_tmp = false;
            				}
HXDLIN(  70)				if (_hx_tmp) {
HXLINE(  71)					return v;
            				}
            			}
            		}
HXLINE(  73)		return HX_("",00,00,00,00);
            	}


HX_DEFINE_DYNAMIC_FUNC1(WarningSubGroup_obj,getWarning,return )


::hx::ObjectPtr< WarningSubGroup_obj > WarningSubGroup_obj::__new(::Array< ::String > warn) {
	::hx::ObjectPtr< WarningSubGroup_obj > __this = new WarningSubGroup_obj();
	__this->__construct(warn);
	return __this;
}

::hx::ObjectPtr< WarningSubGroup_obj > WarningSubGroup_obj::__alloc(::hx::Ctx *_hx_ctx,::Array< ::String > warn) {
	WarningSubGroup_obj *__this = (WarningSubGroup_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(WarningSubGroup_obj), true, "WarningSubGroup"));
	*(void **)__this = WarningSubGroup_obj::_hx_vtable;
	__this->__construct(warn);
	return __this;
}

WarningSubGroup_obj::WarningSubGroup_obj()
{
}

void WarningSubGroup_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WarningSubGroup);
	HX_MARK_MEMBER_NAME(acceptedTermsOfService,"acceptedTermsOfService");
	HX_MARK_MEMBER_NAME(sway,"sway");
	HX_MARK_MEMBER_NAME(txtY,"txtY");
	HX_MARK_MEMBER_NAME(pressedSwitch,"pressedSwitch");
	HX_MARK_MEMBER_NAME(warningTxt,"warningTxt");
	 ::flixel::group::FlxTypedSpriteGroup_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void WarningSubGroup_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(acceptedTermsOfService,"acceptedTermsOfService");
	HX_VISIT_MEMBER_NAME(sway,"sway");
	HX_VISIT_MEMBER_NAME(txtY,"txtY");
	HX_VISIT_MEMBER_NAME(pressedSwitch,"pressedSwitch");
	HX_VISIT_MEMBER_NAME(warningTxt,"warningTxt");
	 ::flixel::group::FlxTypedSpriteGroup_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val WarningSubGroup_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"sway") ) { return ::hx::Val( sway ); }
		if (HX_FIELD_EQ(inName,"txtY") ) { return ::hx::Val( txtY ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"controls") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_controls() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"warningTxt") ) { return ::hx::Val( warningTxt ); }
		if (HX_FIELD_EQ(inName,"getWarning") ) { return ::hx::Val( getWarning_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_controls") ) { return ::hx::Val( get_controls_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pressedSwitch") ) { return ::hx::Val( pressedSwitch ); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"acceptedTermsOfService") ) { return ::hx::Val( acceptedTermsOfService ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val WarningSubGroup_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"sway") ) { sway=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"txtY") ) { txtY=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"warningTxt") ) { warningTxt=inValue.Cast<  ::flixel::text::FlxText >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pressedSwitch") ) { pressedSwitch=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"acceptedTermsOfService") ) { acceptedTermsOfService=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WarningSubGroup_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("acceptedTermsOfService",1e,1b,d4,77));
	outFields->push(HX_("sway",9c,2a,5e,4c));
	outFields->push(HX_("txtY",e9,33,08,4d));
	outFields->push(HX_("pressedSwitch",36,36,73,90));
	outFields->push(HX_("warningTxt",74,2d,a8,3c));
	outFields->push(HX_("controls",76,86,bc,37));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo WarningSubGroup_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(WarningSubGroup_obj,acceptedTermsOfService),HX_("acceptedTermsOfService",1e,1b,d4,77)},
	{::hx::fsFloat,(int)offsetof(WarningSubGroup_obj,sway),HX_("sway",9c,2a,5e,4c)},
	{::hx::fsFloat,(int)offsetof(WarningSubGroup_obj,txtY),HX_("txtY",e9,33,08,4d)},
	{::hx::fsBool,(int)offsetof(WarningSubGroup_obj,pressedSwitch),HX_("pressedSwitch",36,36,73,90)},
	{::hx::fsObject /*  ::flixel::text::FlxText */ ,(int)offsetof(WarningSubGroup_obj,warningTxt),HX_("warningTxt",74,2d,a8,3c)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *WarningSubGroup_obj_sStaticStorageInfo = 0;
#endif

static ::String WarningSubGroup_obj_sMemberFields[] = {
	HX_("acceptedTermsOfService",1e,1b,d4,77),
	HX_("sway",9c,2a,5e,4c),
	HX_("txtY",e9,33,08,4d),
	HX_("pressedSwitch",36,36,73,90),
	HX_("warningTxt",74,2d,a8,3c),
	HX_("get_controls",7f,3a,d6,ec),
	HX_("update",09,86,05,87),
	HX_("getWarning",66,60,2d,59),
	::String(null()) };

::hx::Class WarningSubGroup_obj::__mClass;

void WarningSubGroup_obj::__register()
{
	WarningSubGroup_obj _hx_dummy;
	WarningSubGroup_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("WarningSubGroup",fb,63,49,f8);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(WarningSubGroup_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< WarningSubGroup_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = WarningSubGroup_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = WarningSubGroup_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

