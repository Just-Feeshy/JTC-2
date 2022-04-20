#include <hxcpp.h>

#ifndef INCLUDED_Test1
#include <Test1.h>
#endif
#ifndef INCLUDED_Test2
#include <Test2.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_86e19373cd85c608_13_new,"Test2","new",0xc06c5072,"Test2.new","Mod.hx",13,0xf531c55c)

void Test2_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_86e19373cd85c608_13_new)
HXDLIN(  13)		super::__construct();
            	}

Dynamic Test2_obj::__CreateEmpty() { return new Test2_obj; }

void *Test2_obj::_hx_vtable = 0;

Dynamic Test2_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Test2_obj > _hx_result = new Test2_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Test2_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x3d52c4bf) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x3d52c4bf;
	} else {
		return inClassId==(int)0x3d52c4c0;
	}
}


Test2_obj::Test2_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Test2_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Test2_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Test2_obj::__mClass;

void Test2_obj::__register()
{
	Test2_obj _hx_dummy;
	Test2_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Test2",80,ef,c2,a0);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Test2_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Test2_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Test2_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

