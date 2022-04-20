#include <hxcpp.h>

#ifndef INCLUDED_Test1
#include <Test1.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_78575960ffe256e0_7_new,"Test1","new",0x2d05bbf1,"Test1.new","Mod.hx",7,0xf531c55c)

void Test1_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_78575960ffe256e0_7_new)
HXDLIN(   7)		return;
            	}

Dynamic Test1_obj::__CreateEmpty() { return new Test1_obj; }

void *Test1_obj::_hx_vtable = 0;

Dynamic Test1_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Test1_obj > _hx_result = new Test1_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Test1_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x3d52c4bf;
}


::hx::ObjectPtr< Test1_obj > Test1_obj::__new() {
	::hx::ObjectPtr< Test1_obj > __this = new Test1_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Test1_obj > Test1_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Test1_obj *__this = (Test1_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Test1_obj), false, "Test1"));
	*(void **)__this = Test1_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

Test1_obj::Test1_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Test1_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Test1_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Test1_obj::__mClass;

void Test1_obj::__register()
{
	Test1_obj _hx_dummy;
	Test1_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Test1",7f,ef,c2,a0);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Test1_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Test1_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Test1_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

