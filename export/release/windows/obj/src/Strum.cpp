#include <hxcpp.h>

#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Strum
#include <Strum.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
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

HX_DEFINE_STACK_FRAME(_hx_pos_17cd27e139b23924_7_new,"Strum","new",0x7cd9b69b,"Strum.new","Strum.hx",7,0x9dd55535)
HX_LOCAL_STACK_FRAME(_hx_pos_17cd27e139b23924_28_setVisibility,"Strum","setVisibility",0x30ea0a0f,"Strum.setVisibility","Strum.hx",28,0x9dd55535)
HX_LOCAL_STACK_FRAME(_hx_pos_17cd27e139b23924_35_getInverseAxis,"Strum","getInverseAxis",0xbc9f9d20,"Strum.getInverseAxis","Strum.hx",35,0x9dd55535)
HX_LOCAL_STACK_FRAME(_hx_pos_17cd27e139b23924_42_getRegularAxis,"Strum","getRegularAxis",0x091d69cc,"Strum.getRegularAxis","Strum.hx",42,0x9dd55535)
HX_LOCAL_STACK_FRAME(_hx_pos_17cd27e139b23924_48_update,"Strum","update",0x19b2f6ae,"Strum.update","Strum.hx",48,0x9dd55535)

void Strum_obj::__construct(Float x,Float y){
            	HX_STACKFRAME(&_hx_pos_17cd27e139b23924_7_new)
HXLINE(  14)		this->onlyVisible = true;
HXLINE(  13)		this->prevVisible = true;
HXLINE(   8)		this->ifCustom = HX_("regular",5c,52,88,82);
HXLINE(  17)		super::__construct(x,y,null());
HXLINE(  19)		this->onlyFans = ( (Float)(1) );
HXLINE(  21)		if (::PlayState_obj::modifierCheckList(HX_("blind effect",fc,45,6a,f6))) {
HXLINE(  22)			this->set_visible(false);
            		}
            	}

Dynamic Strum_obj::__CreateEmpty() { return new Strum_obj; }

void *Strum_obj::_hx_vtable = 0;

Dynamic Strum_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Strum_obj > _hx_result = new Strum_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool Strum_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x2c01639b) {
		if (inClassId<=(int)0x0b8a3685) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x0b8a3685;
		} else {
			return inClassId==(int)0x2c01639b;
		}
	} else {
		return inClassId==(int)0x7ccf8994 || inClassId==(int)0x7dab0655;
	}
}

bool Strum_obj::setVisibility(bool visibility){
            	HX_STACKFRAME(&_hx_pos_17cd27e139b23924_28_setVisibility)
HXLINE(  29)		this->prevVisible = this->visible;
HXLINE(  30)		this->set_visible(visibility);
HXLINE(  31)		return this->visible;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Strum_obj,setVisibility,return )

Float Strum_obj::getInverseAxis( ::flixel::util::FlxAxes ax){
            	HX_STACKFRAME(&_hx_pos_17cd27e139b23924_35_getInverseAxis)
HXDLIN(  35)		if (::hx::IsPointerEq( ax,::flixel::util::FlxAxes_obj::Y_dyn() )) {
HXLINE(  36)			return this->x;
            		}
            		else {
HXLINE(  38)			return this->y;
            		}
HXLINE(  35)		return ((Float)0.);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Strum_obj,getInverseAxis,return )

Float Strum_obj::getRegularAxis( ::flixel::util::FlxAxes ax){
            	HX_STACKFRAME(&_hx_pos_17cd27e139b23924_42_getRegularAxis)
HXDLIN(  42)		if (::hx::IsPointerEq( ax,::flixel::util::FlxAxes_obj::Y_dyn() )) {
HXLINE(  43)			return this->y;
            		}
            		else {
HXLINE(  45)			return this->x;
            		}
HXLINE(  42)		return ((Float)0.);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Strum_obj,getRegularAxis,return )

void Strum_obj::update(Float elapsed){
            	HX_STACKFRAME(&_hx_pos_17cd27e139b23924_48_update)
HXLINE(  49)		Float _hx_tmp;
HXDLIN(  49)		if (( (bool)(::flixel::FlxG_obj::save->data->__Field(HX_("showAntialiasing",91,3f,42,e7),::hx::paccDynamic)) )) {
HXLINE(  49)			_hx_tmp = ( (Float)(1) );
            		}
            		else {
HXLINE(  49)			_hx_tmp = ((Float)1.5);
            		}
HXDLIN(  49)		this->super::update((elapsed / _hx_tmp));
HXLINE(  51)		bool _hx_tmp1;
HXDLIN(  51)		bool _hx_tmp2;
HXDLIN(  51)		if (this->animation->get_finished()) {
HXLINE(  51)			_hx_tmp2 = this->ifOpponent;
            		}
            		else {
HXLINE(  51)			_hx_tmp2 = false;
            		}
HXDLIN(  51)		if (_hx_tmp2) {
HXLINE(  51)			_hx_tmp1 = (this->animation->_curAnim->name == HX_("confirm",00,9d,39,10));
            		}
            		else {
HXLINE(  51)			_hx_tmp1 = false;
            		}
HXDLIN(  51)		if (_hx_tmp1) {
HXLINE(  52)			this->animation->play(HX_("static",ae,dc,fb,05),null(),null(),null());
HXLINE(  53)			this->centerOffsets(null());
            		}
HXLINE(  56)		bool _hx_tmp3;
HXDLIN(  56)		bool _hx_tmp4;
HXDLIN(  56)		if ((this->animation->_curAnim->name != HX_("static",ae,dc,fb,05))) {
HXLINE(  56)			_hx_tmp4 = (this->animation->_curAnim->name == HX_("pressed",a2,d2,e6,39));
            		}
            		else {
HXLINE(  56)			_hx_tmp4 = true;
            		}
HXDLIN(  56)		if (_hx_tmp4) {
HXLINE(  56)			_hx_tmp3 = ::PlayState_obj::modifierCheckList(HX_("blind effect",fc,45,6a,f6));
            		}
            		else {
HXLINE(  56)			_hx_tmp3 = false;
            		}
HXDLIN(  56)		if (_hx_tmp3) {
HXLINE(  57)			this->set_visible(false);
            		}
HXLINE(  59)		bool _hx_tmp5;
HXDLIN(  59)		bool _hx_tmp6;
HXDLIN(  59)		if ((this->animation->_curAnim->name == HX_("confirm",00,9d,39,10))) {
HXLINE(  59)			_hx_tmp6 = ::PlayState_obj::modifierCheckList(HX_("blind effect",fc,45,6a,f6));
            		}
            		else {
HXLINE(  59)			_hx_tmp6 = false;
            		}
HXDLIN(  59)		if (_hx_tmp6) {
HXLINE(  59)			_hx_tmp5 = (this->visible == false);
            		}
            		else {
HXLINE(  59)			_hx_tmp5 = false;
            		}
HXDLIN(  59)		if (_hx_tmp5) {
HXLINE(  60)			this->set_visible(true);
            		}
            	}



::hx::ObjectPtr< Strum_obj > Strum_obj::__new(Float x,Float y) {
	::hx::ObjectPtr< Strum_obj > __this = new Strum_obj();
	__this->__construct(x,y);
	return __this;
}

::hx::ObjectPtr< Strum_obj > Strum_obj::__alloc(::hx::Ctx *_hx_ctx,Float x,Float y) {
	Strum_obj *__this = (Strum_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Strum_obj), true, "Strum"));
	*(void **)__this = Strum_obj::_hx_vtable;
	__this->__construct(x,y);
	return __this;
}

Strum_obj::Strum_obj()
{
}

void Strum_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Strum);
	HX_MARK_MEMBER_NAME(ifCustom,"ifCustom");
	HX_MARK_MEMBER_NAME(ifOpponent,"ifOpponent");
	HX_MARK_MEMBER_NAME(onlyFans,"onlyFans");
	HX_MARK_MEMBER_NAME(xAxis,"xAxis");
	HX_MARK_MEMBER_NAME(prevVisible,"prevVisible");
	HX_MARK_MEMBER_NAME(onlyVisible,"onlyVisible");
	 ::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Strum_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ifCustom,"ifCustom");
	HX_VISIT_MEMBER_NAME(ifOpponent,"ifOpponent");
	HX_VISIT_MEMBER_NAME(onlyFans,"onlyFans");
	HX_VISIT_MEMBER_NAME(xAxis,"xAxis");
	HX_VISIT_MEMBER_NAME(prevVisible,"prevVisible");
	HX_VISIT_MEMBER_NAME(onlyVisible,"onlyVisible");
	 ::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Strum_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"xAxis") ) { return ::hx::Val( xAxis ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ifCustom") ) { return ::hx::Val( ifCustom ); }
		if (HX_FIELD_EQ(inName,"onlyFans") ) { return ::hx::Val( onlyFans ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ifOpponent") ) { return ::hx::Val( ifOpponent ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"prevVisible") ) { return ::hx::Val( prevVisible ); }
		if (HX_FIELD_EQ(inName,"onlyVisible") ) { return ::hx::Val( onlyVisible ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setVisibility") ) { return ::hx::Val( setVisibility_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getInverseAxis") ) { return ::hx::Val( getInverseAxis_dyn() ); }
		if (HX_FIELD_EQ(inName,"getRegularAxis") ) { return ::hx::Val( getRegularAxis_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Strum_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"xAxis") ) { xAxis=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ifCustom") ) { ifCustom=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onlyFans") ) { onlyFans=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ifOpponent") ) { ifOpponent=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"prevVisible") ) { prevVisible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onlyVisible") ) { onlyVisible=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Strum_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("ifCustom",6e,1b,65,7b));
	outFields->push(HX_("ifOpponent",9a,76,25,bd));
	outFields->push(HX_("onlyFans",cc,95,ae,b3));
	outFields->push(HX_("xAxis",39,e5,67,43));
	outFields->push(HX_("prevVisible",bf,f5,6c,09));
	outFields->push(HX_("onlyVisible",66,e0,95,f7));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Strum_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(Strum_obj,ifCustom),HX_("ifCustom",6e,1b,65,7b)},
	{::hx::fsBool,(int)offsetof(Strum_obj,ifOpponent),HX_("ifOpponent",9a,76,25,bd)},
	{::hx::fsFloat,(int)offsetof(Strum_obj,onlyFans),HX_("onlyFans",cc,95,ae,b3)},
	{::hx::fsBool,(int)offsetof(Strum_obj,xAxis),HX_("xAxis",39,e5,67,43)},
	{::hx::fsBool,(int)offsetof(Strum_obj,prevVisible),HX_("prevVisible",bf,f5,6c,09)},
	{::hx::fsBool,(int)offsetof(Strum_obj,onlyVisible),HX_("onlyVisible",66,e0,95,f7)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Strum_obj_sStaticStorageInfo = 0;
#endif

static ::String Strum_obj_sMemberFields[] = {
	HX_("ifCustom",6e,1b,65,7b),
	HX_("ifOpponent",9a,76,25,bd),
	HX_("onlyFans",cc,95,ae,b3),
	HX_("xAxis",39,e5,67,43),
	HX_("prevVisible",bf,f5,6c,09),
	HX_("onlyVisible",66,e0,95,f7),
	HX_("setVisibility",14,ec,85,74),
	HX_("getInverseAxis",7b,7f,69,a1),
	HX_("getRegularAxis",27,4c,e7,ed),
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class Strum_obj::__mClass;

void Strum_obj::__register()
{
	Strum_obj _hx_dummy;
	Strum_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Strum",29,cd,45,17);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Strum_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Strum_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Strum_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Strum_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

