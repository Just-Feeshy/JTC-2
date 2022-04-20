#include <hxcpp.h>

#ifndef INCLUDED_CustomKeys
#include <CustomKeys.h>
#endif
#ifndef INCLUDED_MusicBeatSubstate
#include <MusicBeatSubstate.h>
#endif
#ifndef INCLUDED_OptionsSubState
#include <OptionsSubState.h>
#endif
#ifndef INCLUDED_SaveType
#include <SaveType.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_FlxSubState
#include <flixel/FlxSubState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_util_IFlxDestroyable
#include <flixel/util/IFlxDestroyable.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_5813655399be5ed0_18_new,"OptionsSubState","new",0xc4a08641,"OptionsSubState.new","OptionsSubState.hx",18,0xe308bc4f)
HX_LOCAL_STACK_FRAME(_hx_pos_5813655399be5ed0_22_newSubState,"OptionsSubState","newSubState",0x23beb7d2,"OptionsSubState.newSubState","OptionsSubState.hx",22,0xe308bc4f)

void OptionsSubState_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_5813655399be5ed0_18_new)
HXDLIN(  18)		super::__construct();
            	}

Dynamic OptionsSubState_obj::__CreateEmpty() { return new OptionsSubState_obj; }

void *OptionsSubState_obj::_hx_vtable = 0;

Dynamic OptionsSubState_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< OptionsSubState_obj > _hx_result = new OptionsSubState_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool OptionsSubState_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x62817b24) {
		if (inClassId<=(int)0x5661ffbf) {
			if (inClassId<=(int)0x27392463) {
				return inClassId==(int)0x00000001 || inClassId==(int)0x27392463;
			} else {
				return inClassId==(int)0x5661ffbf;
			}
		} else {
			return inClassId==(int)0x62817b24;
		}
	} else {
		if (inClassId<=(int)0x7ccf8994) {
			return inClassId==(int)0x7c795c9f || inClassId==(int)0x7ccf8994;
		} else {
			return inClassId==(int)0x7fce3ab0;
		}
	}
}

 ::OptionsSubState OptionsSubState_obj::newSubState( ::SaveType type){
            	HX_GC_STACKFRAME(&_hx_pos_5813655399be5ed0_22_newSubState)
HXDLIN(  22)		if ((type->_hx_getIndex() == 18)) {
HXLINE(  24)			return  ::CustomKeys_obj::__alloc( HX_CTX );
            		}
            		else {
HXLINE(  26)			return  ::OptionsSubState_obj::__alloc( HX_CTX );
            		}
HXLINE(  22)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(OptionsSubState_obj,newSubState,return )


::hx::ObjectPtr< OptionsSubState_obj > OptionsSubState_obj::__new() {
	::hx::ObjectPtr< OptionsSubState_obj > __this = new OptionsSubState_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< OptionsSubState_obj > OptionsSubState_obj::__alloc(::hx::Ctx *_hx_ctx) {
	OptionsSubState_obj *__this = (OptionsSubState_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(OptionsSubState_obj), true, "OptionsSubState"));
	*(void **)__this = OptionsSubState_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

OptionsSubState_obj::OptionsSubState_obj()
{
}

bool OptionsSubState_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"newSubState") ) { outValue = newSubState_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *OptionsSubState_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *OptionsSubState_obj_sStaticStorageInfo = 0;
#endif

::hx::Class OptionsSubState_obj::__mClass;

static ::String OptionsSubState_obj_sStaticFields[] = {
	HX_("newSubState",f1,b8,07,1e),
	::String(null())
};

void OptionsSubState_obj::__register()
{
	OptionsSubState_obj _hx_dummy;
	OptionsSubState_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("OptionsSubState",cf,51,f6,cd);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &OptionsSubState_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(OptionsSubState_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< OptionsSubState_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = OptionsSubState_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = OptionsSubState_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

