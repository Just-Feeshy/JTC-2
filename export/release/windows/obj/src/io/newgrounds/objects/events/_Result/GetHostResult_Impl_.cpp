#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects_events__Result_GetHostResult_Impl_
#include <io/newgrounds/objects/events/_Result/GetHostResult_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_2970e32056b4dc60_45_get_host_approved,"io.newgrounds.objects.events._Result.GetHostResult_Impl_","get_host_approved",0x2f1e24df,"io.newgrounds.objects.events._Result.GetHostResult_Impl_.get_host_approved","io/newgrounds/objects/events/Result.hx",45,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_2970e32056b4dc60_47_get_hostApproved,"io.newgrounds.objects.events._Result.GetHostResult_Impl_","get_hostApproved",0x5f2c9fae,"io.newgrounds.objects.events._Result.GetHostResult_Impl_.get_hostApproved","io/newgrounds/objects/events/Result.hx",47,0xd300c520)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{

void GetHostResult_Impl__obj::__construct() { }

Dynamic GetHostResult_Impl__obj::__CreateEmpty() { return new GetHostResult_Impl__obj; }

void *GetHostResult_Impl__obj::_hx_vtable = 0;

Dynamic GetHostResult_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GetHostResult_Impl__obj > _hx_result = new GetHostResult_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool GetHostResult_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x0fd64a1a;
}

bool GetHostResult_Impl__obj::get_host_approved( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_2970e32056b4dc60_45_get_host_approved)
HXDLIN(  45)		return ( (bool)(this1->__Field(HX_("host_approved",6e,49,52,b8),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetHostResult_Impl__obj,get_host_approved,return )

bool GetHostResult_Impl__obj::get_hostApproved( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_2970e32056b4dc60_47_get_hostApproved)
HXDLIN(  47)		return ( (bool)(this1->__Field(HX_("host_approved",6e,49,52,b8),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GetHostResult_Impl__obj,get_hostApproved,return )


GetHostResult_Impl__obj::GetHostResult_Impl__obj()
{
}

bool GetHostResult_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"get_hostApproved") ) { outValue = get_hostApproved_dyn(); return true; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_host_approved") ) { outValue = get_host_approved_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GetHostResult_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *GetHostResult_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class GetHostResult_Impl__obj::__mClass;

static ::String GetHostResult_Impl__obj_sStaticFields[] = {
	HX_("get_host_approved",c5,54,c2,be),
	HX_("get_hostApproved",88,6e,3d,fe),
	::String(null())
};

void GetHostResult_Impl__obj::__register()
{
	GetHostResult_Impl__obj _hx_dummy;
	GetHostResult_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Result.GetHostResult_Impl_",08,c2,65,53);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GetHostResult_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(GetHostResult_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< GetHostResult_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GetHostResult_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GetHostResult_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result
