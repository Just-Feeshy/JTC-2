#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects_events__Result_GetCurrentVersionResult_Impl_
#include <io/newgrounds/objects/events/_Result/GetCurrentVersionResult_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_f4605c69a0ee53a1_58_get_current_version,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_","get_current_version",0x87e211ba,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_.get_current_version","io/newgrounds/objects/events/Result.hx",58,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_f4605c69a0ee53a1_60_get_currentVersion,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_","get_currentVersion",0x5c6b7cf7,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_.get_currentVersion","io/newgrounds/objects/events/Result.hx",60,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_f4605c69a0ee53a1_64_get_client_deprecated,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_","get_client_deprecated",0x3b74fe0f,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_.get_client_deprecated","io/newgrounds/objects/events/Result.hx",64,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_f4605c69a0ee53a1_66_get_clientDeprecated,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_","get_clientDeprecated",0x4def50b6,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_.get_clientDeprecated","io/newgrounds/objects/events/Result.hx",66,0xd300c520)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{

void GetCurrentVersionResult_Impl__obj::__construct() { }

Dynamic GetCurrentVersionResult_Impl__obj::__CreateEmpty() { return new GetCurrentVersionResult_Impl__obj; }

void *GetCurrentVersionResult_Impl__obj::_hx_vtable = 0;

Dynamic GetCurrentVersionResult_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GetCurrentVersionResult_Impl__obj > _hx_result = new GetCurrentVersionResult_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool GetCurrentVersionResult_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x225522a5;
}

::String GetCurrentVersionResult_Impl__obj::get_current_version( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_f4605c69a0ee53a1_58_get_current_version)
HXDLIN(  58)		return ( (::String)(this1->__Field(HX_("current_version",d2,3d,4a,b1),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetCurrentVersionResult_Impl__obj,get_current_version,return )

::String GetCurrentVersionResult_Impl__obj::get_currentVersion( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_f4605c69a0ee53a1_60_get_currentVersion)
HXDLIN(  60)		return ( (::String)(this1->__Field(HX_("current_version",d2,3d,4a,b1),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetCurrentVersionResult_Impl__obj,get_currentVersion,return )

bool GetCurrentVersionResult_Impl__obj::get_client_deprecated( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_f4605c69a0ee53a1_64_get_client_deprecated)
HXDLIN(  64)		return ( (bool)(this1->__Field(HX_("client_deprecated",27,60,52,b0),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetCurrentVersionResult_Impl__obj,get_client_deprecated,return )

bool GetCurrentVersionResult_Impl__obj::get_clientDeprecated( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_f4605c69a0ee53a1_66_get_clientDeprecated)
HXDLIN(  66)		return ( (bool)(this1->__Field(HX_("client_deprecated",27,60,52,b0),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetCurrentVersionResult_Impl__obj,get_clientDeprecated,return )


GetCurrentVersionResult_Impl__obj::GetCurrentVersionResult_Impl__obj()
{
}

bool GetCurrentVersionResult_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"get_currentVersion") ) { outValue = get_currentVersion_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_current_version") ) { outValue = get_current_version_dyn(); return true; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_clientDeprecated") ) { outValue = get_clientDeprecated_dyn(); return true; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"get_client_deprecated") ) { outValue = get_client_deprecated_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GetCurrentVersionResult_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *GetCurrentVersionResult_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class GetCurrentVersionResult_Impl__obj::__mClass;

static ::String GetCurrentVersionResult_Impl__obj_sStaticFields[] = {
	HX_("get_current_version",e9,0c,55,3c),
	HX_("get_currentVersion",a8,3c,20,26),
	HX_("get_client_deprecated",fe,62,00,2f),
	HX_("get_clientDeprecated",a7,1e,18,7e),
	::String(null())
};

void GetCurrentVersionResult_Impl__obj::__register()
{
	GetCurrentVersionResult_Impl__obj _hx_dummy;
	GetCurrentVersionResult_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_",bf,f6,16,d3);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GetCurrentVersionResult_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GetCurrentVersionResult_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GetCurrentVersionResult_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GetCurrentVersionResult_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GetCurrentVersionResult_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result
