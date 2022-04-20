#include <hxcpp.h>

#ifndef INCLUDED_json2object_JsonParser
#include <json2object/JsonParser.h>
#endif

namespace json2object{

void JsonParser_obj::__construct() { }

Dynamic JsonParser_obj::__CreateEmpty() { return new JsonParser_obj; }

void *JsonParser_obj::_hx_vtable = 0;

Dynamic JsonParser_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< JsonParser_obj > _hx_result = new JsonParser_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool JsonParser_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x49aa452c;
}


JsonParser_obj::JsonParser_obj()
{
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *JsonParser_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *JsonParser_obj_sStaticStorageInfo = 0;
#endif

::hx::Class JsonParser_obj::__mClass;

void JsonParser_obj::__register()
{
	JsonParser_obj _hx_dummy;
	JsonParser_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("json2object.JsonParser",4c,4a,3e,59);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< JsonParser_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = JsonParser_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = JsonParser_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace json2object
