#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects__Score_Score_Impl_
#include <io/newgrounds/objects/_Score/Score_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_4c5bacf33a16b422_23_get_formatted_value,"io.newgrounds.objects._Score.Score_Impl_","get_formatted_value",0xb71b3702,"io.newgrounds.objects._Score.Score_Impl_.get_formatted_value","io/newgrounds/objects/Score.hx",23,0xaedec6c1)
HX_LOCAL_STACK_FRAME(_hx_pos_4c5bacf33a16b422_26_get_formattedValue,"io.newgrounds.objects._Score.Score_Impl_","get_formattedValue",0x6ad2f901,"io.newgrounds.objects._Score.Score_Impl_.get_formattedValue","io/newgrounds/objects/Score.hx",26,0xaedec6c1)
namespace io{
namespace newgrounds{
namespace objects{
namespace _Score{

void Score_Impl__obj::__construct() { }

Dynamic Score_Impl__obj::__CreateEmpty() { return new Score_Impl__obj; }

void *Score_Impl__obj::_hx_vtable = 0;

Dynamic Score_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Score_Impl__obj > _hx_result = new Score_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Score_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x5c1f387d;
}

::String Score_Impl__obj::get_formatted_value( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_4c5bacf33a16b422_23_get_formatted_value)
HXDLIN(  23)		return ( (::String)(this1->__Field(HX_("formatted_value",ae,16,f4,5b),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Score_Impl__obj,get_formatted_value,return )

::String Score_Impl__obj::get_formattedValue( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_4c5bacf33a16b422_26_get_formattedValue)
HXDLIN(  26)		return ( (::String)(this1->__Field(HX_("formatted_value",ae,16,f4,5b),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Score_Impl__obj,get_formattedValue,return )


Score_Impl__obj::Score_Impl__obj()
{
}

bool Score_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"get_formattedValue") ) { outValue = get_formattedValue_dyn(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_formatted_value") ) { outValue = get_formatted_value_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Score_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Score_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Score_Impl__obj::__mClass;

static ::String Score_Impl__obj_sStaticFields[] = {
	HX_("get_formatted_value",c5,e5,fe,e6),
	HX_("get_formattedValue",9e,93,16,16),
	::String(null())
};

void Score_Impl__obj::__register()
{
	Score_Impl__obj _hx_dummy;
	Score_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects._Score.Score_Impl_",2b,05,3c,33);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Score_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Score_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Score_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Score_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Score_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace _Score
