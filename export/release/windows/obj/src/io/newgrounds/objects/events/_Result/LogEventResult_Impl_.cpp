#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects_events__Result_LogEventResult_Impl_
#include <io/newgrounds/objects/events/_Result/LogEventResult_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_508ed1c1fdd820da_78_get_event_name,"io.newgrounds.objects.events._Result.LogEventResult_Impl_","get_event_name",0xe46a4961,"io.newgrounds.objects.events._Result.LogEventResult_Impl_.get_event_name","io/newgrounds/objects/events/Result.hx",78,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_508ed1c1fdd820da_80_get_eventName,"io.newgrounds.objects.events._Result.LogEventResult_Impl_","get_eventName",0xeedc7714,"io.newgrounds.objects.events._Result.LogEventResult_Impl_.get_eventName","io/newgrounds/objects/events/Result.hx",80,0xd300c520)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{

void LogEventResult_Impl__obj::__construct() { }

Dynamic LogEventResult_Impl__obj::__CreateEmpty() { return new LogEventResult_Impl__obj; }

void *LogEventResult_Impl__obj::_hx_vtable = 0;

Dynamic LogEventResult_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< LogEventResult_Impl__obj > _hx_result = new LogEventResult_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool LogEventResult_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x31f17dd4;
}

::String LogEventResult_Impl__obj::get_event_name( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_508ed1c1fdd820da_78_get_event_name)
HXDLIN(  78)		return ( (::String)(this1->__Field(HX_("event_name",d0,27,3e,e5),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LogEventResult_Impl__obj,get_event_name,return )

::String LogEventResult_Impl__obj::get_eventName( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_508ed1c1fdd820da_80_get_eventName)
HXDLIN(  80)		return ( (::String)(this1->__Field(HX_("event_name",d0,27,3e,e5),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LogEventResult_Impl__obj,get_eventName,return )


LogEventResult_Impl__obj::LogEventResult_Impl__obj()
{
}

bool LogEventResult_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"get_eventName") ) { outValue = get_eventName_dyn(); return true; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_event_name") ) { outValue = get_event_name_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *LogEventResult_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *LogEventResult_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class LogEventResult_Impl__obj::__mClass;

static ::String LogEventResult_Impl__obj_sStaticFields[] = {
	HX_("get_event_name",19,b0,33,5b),
	HX_("get_eventName",5c,4f,70,b9),
	::String(null())
};

void LogEventResult_Impl__obj::__register()
{
	LogEventResult_Impl__obj _hx_dummy;
	LogEventResult_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Result.LogEventResult_Impl_",26,f6,ea,0b);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &LogEventResult_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(LogEventResult_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< LogEventResult_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = LogEventResult_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = LogEventResult_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result
