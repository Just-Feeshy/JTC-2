#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects__Error_Error_Impl_
#include <io/newgrounds/objects/_Error/Error_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_8cf48dd4c2c3d3b2_13_get_code,"io.newgrounds.objects._Error.Error_Impl_","get_code",0xd65a546d,"io.newgrounds.objects._Error.Error_Impl_.get_code","io/newgrounds/objects/Error.hx",13,0x7f549c0b)
HX_LOCAL_STACK_FRAME(_hx_pos_8cf48dd4c2c3d3b2_14_get_message,"io.newgrounds.objects._Error.Error_Impl_","get_message",0x38b11a87,"io.newgrounds.objects._Error.Error_Impl_.get_message","io/newgrounds/objects/Error.hx",14,0x7f549c0b)
HX_LOCAL_STACK_FRAME(_hx_pos_8cf48dd4c2c3d3b2_16__new,"io.newgrounds.objects._Error.Error_Impl_","_new",0x2c701598,"io.newgrounds.objects._Error.Error_Impl_._new","io/newgrounds/objects/Error.hx",16,0x7f549c0b)
HX_LOCAL_STACK_FRAME(_hx_pos_8cf48dd4c2c3d3b2_23_toString,"io.newgrounds.objects._Error.Error_Impl_","toString",0x4d49b863,"io.newgrounds.objects._Error.Error_Impl_.toString","io/newgrounds/objects/Error.hx",23,0x7f549c0b)
namespace io{
namespace newgrounds{
namespace objects{
namespace _Error{

void Error_Impl__obj::__construct() { }

Dynamic Error_Impl__obj::__CreateEmpty() { return new Error_Impl__obj; }

void *Error_Impl__obj::_hx_vtable = 0;

Dynamic Error_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Error_Impl__obj > _hx_result = new Error_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Error_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x795ac969;
}

 ::Dynamic Error_Impl__obj::get_code( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_8cf48dd4c2c3d3b2_13_get_code)
HXDLIN(  13)		return this1->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Error_Impl__obj,get_code,return )

::String Error_Impl__obj::get_message( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_8cf48dd4c2c3d3b2_14_get_message)
HXDLIN(  14)		return ( (::String)(this1->__Field(HX_("message",c7,35,11,9a),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Error_Impl__obj,get_message,return )

 ::Dynamic Error_Impl__obj::_new(::String message, ::Dynamic code){
            	HX_STACKFRAME(&_hx_pos_8cf48dd4c2c3d3b2_16__new)
HXDLIN(  16)		 ::Dynamic this1 =  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("message",c7,35,11,9a),message)
            			->setFixed(1,HX_("code",2d,b1,c4,41),code));
HXDLIN(  16)		return this1;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Error_Impl__obj,_new,return )

::String Error_Impl__obj::toString( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_8cf48dd4c2c3d3b2_23_toString)
HXDLIN(  23)		::String _hx_tmp;
HXDLIN(  23)		if (::hx::IsNotNull( this1->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic) )) {
HXDLIN(  23)			_hx_tmp = ( (::String)(((HX_("#",23,00,00,00) + this1->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic)) + HX_(" - ",73,6f,18,00))) );
            		}
            		else {
HXDLIN(  23)			_hx_tmp = HX_("",00,00,00,00);
            		}
HXDLIN(  23)		return ( (::String)((_hx_tmp + this1->__Field(HX_("message",c7,35,11,9a),::hx::paccDynamic))) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Error_Impl__obj,toString,return )


Error_Impl__obj::Error_Impl__obj()
{
}

bool Error_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { outValue = _new_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_code") ) { outValue = get_code_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"toString") ) { outValue = toString_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_message") ) { outValue = get_message_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Error_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Error_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Error_Impl__obj::__mClass;

static ::String Error_Impl__obj_sStaticFields[] = {
	HX_("get_code",b6,6c,7f,c1),
	HX_("get_message",de,95,0b,20),
	HX_("_new",61,15,1f,3f),
	HX_("toString",ac,d0,6e,38),
	::String(null())
};

void Error_Impl__obj::__register()
{
	Error_Impl__obj _hx_dummy;
	Error_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects._Error.Error_Impl_",97,4b,71,d9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Error_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Error_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Error_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Error_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Error_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace _Error
