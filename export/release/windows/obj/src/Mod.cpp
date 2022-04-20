#include <hxcpp.h>

#ifndef INCLUDED_HelperStates
#include <HelperStates.h>
#endif
#ifndef INCLUDED_MainMenuState
#include <MainMenuState.h>
#endif
#ifndef INCLUDED_Mod
#include <Mod.h>
#endif
#ifndef INCLUDED_ModLua
#include <ModLua.h>
#endif
#ifndef INCLUDED_MusicBeatState
#include <MusicBeatState.h>
#endif
#ifndef INCLUDED_Paths
#include <Paths.h>
#endif
#ifndef INCLUDED_Register
#include <Register.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_730d362dee2b253d_7_onInit,"Mod","onInit",0x05e7c41b,"Mod.onInit","Mod.hx",7,0xf531c55c)

void Mod_obj::__construct() { }

Dynamic Mod_obj::__CreateEmpty() { return new Mod_obj; }

void *Mod_obj::_hx_vtable = 0;

Dynamic Mod_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Mod_obj > _hx_result = new Mod_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Mod_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7edf1336;
}

void Mod_obj::onInit(){
            	HX_GC_STACKFRAME(&_hx_pos_730d362dee2b253d_7_onInit)
HXDLIN(   7)		::Register_obj::attachLuaToState(::hx::ClassOf< ::MainMenuState >(), ::ModLua_obj::__alloc( HX_CTX ,::Paths_obj::lua(HX_("jtc_menu",85,2a,5c,17))));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Mod_obj,onInit,(void))


Mod_obj::Mod_obj()
{
}

bool Mod_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onInit") ) { outValue = onInit_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Mod_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Mod_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Mod_obj::__mClass;

static ::String Mod_obj_sStaticFields[] = {
	HX_("onInit",cf,43,45,e8),
	::String(null())
};

void Mod_obj::__register()
{
	Mod_obj _hx_dummy;
	Mod_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Mod",a2,ce,3a,00);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Mod_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Mod_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Mod_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Mod_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Mod_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

