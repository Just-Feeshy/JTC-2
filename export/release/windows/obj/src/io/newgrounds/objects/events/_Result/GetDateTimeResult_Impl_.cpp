#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects_events__Result_GetDateTimeResult_Impl_
#include <io/newgrounds/objects/events/_Result/GetDateTimeResult_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_5505b1367d794a0e_91_get_datetime,"io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_","get_datetime",0x59d0c397,"io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_.get_datetime","io/newgrounds/objects/events/Result.hx",91,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_5505b1367d794a0e_93_get_dateTime,"io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_","get_dateTime",0x44a9efb7,"io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_.get_dateTime","io/newgrounds/objects/events/Result.hx",93,0xd300c520)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{

void GetDateTimeResult_Impl__obj::__construct() { }

Dynamic GetDateTimeResult_Impl__obj::__CreateEmpty() { return new GetDateTimeResult_Impl__obj; }

void *GetDateTimeResult_Impl__obj::_hx_vtable = 0;

Dynamic GetDateTimeResult_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GetDateTimeResult_Impl__obj > _hx_result = new GetDateTimeResult_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool GetDateTimeResult_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x66b21d29;
}

::String GetDateTimeResult_Impl__obj::get_datetime( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_5505b1367d794a0e_91_get_datetime)
HXDLIN(  91)		return ( (::String)(this1->__Field(HX_("datetime",3b,d1,31,ef),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetDateTimeResult_Impl__obj,get_datetime,return )

::String GetDateTimeResult_Impl__obj::get_dateTime( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_5505b1367d794a0e_93_get_dateTime)
HXDLIN(  93)		return ( (::String)(this1->__Field(HX_("datetime",3b,d1,31,ef),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetDateTimeResult_Impl__obj,get_dateTime,return )


GetDateTimeResult_Impl__obj::GetDateTimeResult_Impl__obj()
{
}

bool GetDateTimeResult_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"get_datetime") ) { outValue = get_datetime_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_dateTime") ) { outValue = get_dateTime_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GetDateTimeResult_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *GetDateTimeResult_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class GetDateTimeResult_Impl__obj::__mClass;

static ::String GetDateTimeResult_Impl__obj_sStaticFields[] = {
	HX_("get_datetime",44,85,4b,a4),
	HX_("get_dateTime",64,b1,24,8f),
	::String(null())
};

void GetDateTimeResult_Impl__obj::__register()
{
	GetDateTimeResult_Impl__obj _hx_dummy;
	GetDateTimeResult_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_",fb,ed,91,22);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GetDateTimeResult_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GetDateTimeResult_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GetDateTimeResult_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GetDateTimeResult_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GetDateTimeResult_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result
