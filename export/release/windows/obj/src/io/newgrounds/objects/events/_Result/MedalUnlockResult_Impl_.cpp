#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects_events__Result_MedalUnlockResult_Impl_
#include <io/newgrounds/objects/events/_Result/MedalUnlockResult_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_93848e41f576495d_119_get_medal_score,"io.newgrounds.objects.events._Result.MedalUnlockResult_Impl_","get_medal_score",0x46c6bdf8,"io.newgrounds.objects.events._Result.MedalUnlockResult_Impl_.get_medal_score","io/newgrounds/objects/events/Result.hx",119,0xd300c520)
HX_LOCAL_STACK_FRAME(_hx_pos_93848e41f576495d_121_get_medalScore,"io.newgrounds.objects.events._Result.MedalUnlockResult_Impl_","get_medalScore",0x29ab136d,"io.newgrounds.objects.events._Result.MedalUnlockResult_Impl_.get_medalScore","io/newgrounds/objects/events/Result.hx",121,0xd300c520)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{

void MedalUnlockResult_Impl__obj::__construct() { }

Dynamic MedalUnlockResult_Impl__obj::__CreateEmpty() { return new MedalUnlockResult_Impl__obj; }

void *MedalUnlockResult_Impl__obj::_hx_vtable = 0;

Dynamic MedalUnlockResult_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< MedalUnlockResult_Impl__obj > _hx_result = new MedalUnlockResult_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool MedalUnlockResult_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6457e24f;
}

::String MedalUnlockResult_Impl__obj::get_medal_score( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_93848e41f576495d_119_get_medal_score)
HXDLIN( 119)		return ( (::String)(this1->__Field(HX_("medal_score",ca,0b,4e,ce),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MedalUnlockResult_Impl__obj,get_medal_score,return )

::String MedalUnlockResult_Impl__obj::get_medalScore( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_93848e41f576495d_121_get_medalScore)
HXDLIN( 121)		return ( (::String)(this1->__Field(HX_("medal_score",ca,0b,4e,ce),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(MedalUnlockResult_Impl__obj,get_medalScore,return )


MedalUnlockResult_Impl__obj::MedalUnlockResult_Impl__obj()
{
}

bool MedalUnlockResult_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"get_medalScore") ) { outValue = get_medalScore_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_medal_score") ) { outValue = get_medal_score_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *MedalUnlockResult_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *MedalUnlockResult_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class MedalUnlockResult_Impl__obj::__mClass;

static ::String MedalUnlockResult_Impl__obj_sStaticFields[] = {
	HX_("get_medal_score",61,c3,2f,8f),
	HX_("get_medalScore",24,6e,d1,e2),
	::String(null())
};

void MedalUnlockResult_Impl__obj::__register()
{
	MedalUnlockResult_Impl__obj _hx_dummy;
	MedalUnlockResult_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Result.MedalUnlockResult_Impl_",05,7d,a2,6c);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &MedalUnlockResult_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(MedalUnlockResult_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< MedalUnlockResult_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = MedalUnlockResult_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = MedalUnlockResult_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result
