#include <hxcpp.h>

#ifndef INCLUDED_polymod_util_DefineUtil
#include <polymod/util/DefineUtil.h>
#endif

namespace polymod{
namespace util{

void DefineUtil_obj::__construct() { }

Dynamic DefineUtil_obj::__CreateEmpty() { return new DefineUtil_obj; }

void *DefineUtil_obj::_hx_vtable = 0;

Dynamic DefineUtil_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< DefineUtil_obj > _hx_result = new DefineUtil_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool DefineUtil_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1945eb51;
}


DefineUtil_obj::DefineUtil_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *DefineUtil_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *DefineUtil_obj_sStaticStorageInfo = 0;
#endif

::hx::Class DefineUtil_obj::__mClass;

void DefineUtil_obj::__register()
{
	DefineUtil_obj _hx_dummy;
	DefineUtil_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("polymod.util.DefineUtil",71,c6,bc,6e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< DefineUtil_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = DefineUtil_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = DefineUtil_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace polymod
} // end namespace util
