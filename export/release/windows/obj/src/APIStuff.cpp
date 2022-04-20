#include <hxcpp.h>

#ifndef INCLUDED_APIStuff
#include <APIStuff.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_475af7b1632c1669_4_boot,"APIStuff","boot",0x2a33a106,"APIStuff.boot","APIStuff.hx",4,0x1fd9dae4)
HX_LOCAL_STACK_FRAME(_hx_pos_475af7b1632c1669_5_boot,"APIStuff","boot",0x2a33a106,"APIStuff.boot","APIStuff.hx",5,0x1fd9dae4)

void APIStuff_obj::__construct() { }

Dynamic APIStuff_obj::__CreateEmpty() { return new APIStuff_obj; }

void *APIStuff_obj::_hx_vtable = 0;

Dynamic APIStuff_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< APIStuff_obj > _hx_result = new APIStuff_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool APIStuff_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x276a66da;
}

::String APIStuff_obj::API;

::String APIStuff_obj::EncKey;


APIStuff_obj::APIStuff_obj()
{
}

bool APIStuff_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"API") ) { outValue = ( API ); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"EncKey") ) { outValue = ( EncKey ); return true; }
	}
	return false;
}

bool APIStuff_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"API") ) { API=ioValue.Cast< ::String >(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"EncKey") ) { EncKey=ioValue.Cast< ::String >(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *APIStuff_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo APIStuff_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &APIStuff_obj::API,HX_("API",7a,98,31,00)},
	{::hx::fsString,(void *) &APIStuff_obj::EncKey,HX_("EncKey",05,16,5d,2e)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static void APIStuff_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(APIStuff_obj::API,"API");
	HX_MARK_MEMBER_NAME(APIStuff_obj::EncKey,"EncKey");
};

#ifdef HXCPP_VISIT_ALLOCS
static void APIStuff_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(APIStuff_obj::API,"API");
	HX_VISIT_MEMBER_NAME(APIStuff_obj::EncKey,"EncKey");
};

#endif

::hx::Class APIStuff_obj::__mClass;

static ::String APIStuff_obj_sStaticFields[] = {
	HX_("API",7a,98,31,00),
	HX_("EncKey",05,16,5d,2e),
	::String(null())
};

void APIStuff_obj::__register()
{
	APIStuff_obj _hx_dummy;
	APIStuff_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("APIStuff",1a,74,d9,cb);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &APIStuff_obj::__GetStatic;
	__mClass->mSetStaticField = &APIStuff_obj::__SetStatic;
	__mClass->mMarkFunc = APIStuff_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(APIStuff_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< APIStuff_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = APIStuff_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = APIStuff_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = APIStuff_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void APIStuff_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_475af7b1632c1669_4_boot)
HXDLIN(   4)		API = HX_("",00,00,00,00);
            	}
{
            	HX_STACKFRAME(&_hx_pos_475af7b1632c1669_5_boot)
HXDLIN(   5)		EncKey = HX_("",00,00,00,00);
            	}
}

