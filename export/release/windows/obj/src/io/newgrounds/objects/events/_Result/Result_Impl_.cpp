#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects_events__Result_Result_Impl_
#include <io/newgrounds/objects/events/_Result/Result_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_18d2ca7c5b2138eb_16_get_component,"io.newgrounds.objects.events._Result.Result_Impl_","get_component",0x7c8cfcb6,"io.newgrounds.objects.events._Result.Result_Impl_.get_component","io/newgrounds/objects/events/Result.hx",16,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_18d2ca7c5b2138eb_17_get_echo,"io.newgrounds.objects.events._Result.Result_Impl_","get_echo",0x93827d8c,"io.newgrounds.objects.events._Result.Result_Impl_.get_echo","io/newgrounds/objects/events/Result.hx",17,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_18d2ca7c5b2138eb_18_get_data,"io.newgrounds.objects.events._Result.Result_Impl_","get_data",0x92d7ccd1,"io.newgrounds.objects.events._Result.Result_Impl_.get_data","io/newgrounds/objects/events/Result.hx",18,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_18d2ca7c5b2138eb_19_get_success,"io.newgrounds.objects.events._Result.Result_Impl_","get_success",0x95ea117c,"io.newgrounds.objects.events._Result.Result_Impl_.get_success","io/newgrounds/objects/events/Result.hx",19,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_18d2ca7c5b2138eb_20_get_debug,"io.newgrounds.objects.events._Result.Result_Impl_","get_debug",0xec92adcc,"io.newgrounds.objects.events._Result.Result_Impl_.get_debug","io/newgrounds/objects/events/Result.hx",20,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_18d2ca7c5b2138eb_21_get_error,"io.newgrounds.objects.events._Result.Result_Impl_","get_error",0x889d2741,"io.newgrounds.objects.events._Result.Result_Impl_.get_error","io/newgrounds/objects/events/Result.hx",21,0xd300c520)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{

void Result_Impl__obj::__construct() { }

Dynamic Result_Impl__obj::__CreateEmpty() { return new Result_Impl__obj; }

void *Result_Impl__obj::_hx_vtable = 0;

Dynamic Result_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Result_Impl__obj > _hx_result = new Result_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Result_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x16a5c722;
}

::String Result_Impl__obj::get_component( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_18d2ca7c5b2138eb_16_get_component)
HXDLIN(  16)		return ( (::String)(this1->__Field(HX_("component",bd,f0,53,0f),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Result_Impl__obj,get_component,return )

::String Result_Impl__obj::get_echo( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_18d2ca7c5b2138eb_17_get_echo)
HXDLIN(  17)		return ( (::String)(this1->__Field(HX_("echo",e5,06,0e,43),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Result_Impl__obj,get_echo,return )

 ::Dynamic Result_Impl__obj::get_data( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_18d2ca7c5b2138eb_18_get_data)
HXDLIN(  18)		return  ::Dynamic(this1->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Result_Impl__obj,get_data,return )

bool Result_Impl__obj::get_success( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_18d2ca7c5b2138eb_19_get_success)
HXDLIN(  19)		return ( (bool)( ::Dynamic(this1->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Result_Impl__obj,get_success,return )

bool Result_Impl__obj::get_debug( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_18d2ca7c5b2138eb_20_get_debug)
HXDLIN(  20)		return ( (bool)( ::Dynamic(this1->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("debug",53,52,1f,d7),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Result_Impl__obj,get_debug,return )

 ::Dynamic Result_Impl__obj::get_error( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_18d2ca7c5b2138eb_21_get_error)
HXDLIN(  21)		return  ::Dynamic(this1->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Result_Impl__obj,get_error,return )


Result_Impl__obj::Result_Impl__obj()
{
}

bool Result_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"get_echo") ) { outValue = get_echo_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_data") ) { outValue = get_data_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_debug") ) { outValue = get_debug_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_error") ) { outValue = get_error_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_success") ) { outValue = get_success_dyn(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_component") ) { outValue = get_component_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Result_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Result_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Result_Impl__obj::__mClass;

static ::String Result_Impl__obj_sStaticFields[] = {
	HX_("get_component",94,c4,b7,d0),
	HX_("get_echo",6e,c2,c8,c2),
	HX_("get_data",b3,11,1e,c2),
	HX_("get_success",da,85,48,3e),
	HX_("get_debug",aa,ae,c8,1a),
	HX_("get_error",1f,28,d3,b6),
	::String(null())
};

void Result_Impl__obj::__register()
{
	Result_Impl__obj _hx_dummy;
	Result_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Result.Result_Impl_",10,81,f6,92);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Result_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Result_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Result_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Result_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Result_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result
