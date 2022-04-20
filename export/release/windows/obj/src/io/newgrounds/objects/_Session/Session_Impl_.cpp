#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_objects__Session_Session_Impl_
#include <io/newgrounds/objects/_Session/Session_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_7c7953594efc7d54_23_get_passportUrl,"io.newgrounds.objects._Session.Session_Impl_","get_passportUrl",0xd698fd99,"io.newgrounds.objects._Session.Session_Impl_.get_passportUrl","io/newgrounds/objects/Session.hx",23,0xf7a96c7d)
HX_LOCAL_STACK_FRAME(_hx_pos_7c7953594efc7d54_25_get_passport_url,"io.newgrounds.objects._Session.Session_Impl_","get_passport_url",0xf5e356e6,"io.newgrounds.objects._Session.Session_Impl_.get_passport_url","io/newgrounds/objects/Session.hx",25,0xf7a96c7d)
HX_LOCAL_STACK_FRAME(_hx_pos_7c7953594efc7d54_30_get_status,"io.newgrounds.objects._Session.Session_Impl_","get_status",0x4def84d6,"io.newgrounds.objects._Session.Session_Impl_.get_status","io/newgrounds/objects/Session.hx",30,0xf7a96c7d)
namespace io{
namespace newgrounds{
namespace objects{
namespace _Session{

void Session_Impl__obj::__construct() { }

Dynamic Session_Impl__obj::__CreateEmpty() { return new Session_Impl__obj; }

void *Session_Impl__obj::_hx_vtable = 0;

Dynamic Session_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Session_Impl__obj > _hx_result = new Session_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Session_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7406ecc5;
}

::String Session_Impl__obj::get_passportUrl( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_7c7953594efc7d54_23_get_passportUrl)
HXDLIN(  23)		return ( (::String)(this1->__Field(HX_("passport_url",42,e6,1b,68),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Session_Impl__obj,get_passportUrl,return )

::String Session_Impl__obj::get_passport_url( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_7c7953594efc7d54_25_get_passport_url)
HXDLIN(  25)		return ( (::String)(this1->__Field(HX_("passport_url",42,e6,1b,68),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Session_Impl__obj,get_passport_url,return )

::String Session_Impl__obj::get_status( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_7c7953594efc7d54_30_get_status)
HXLINE(  32)		bool _hx_tmp;
HXDLIN(  32)		bool _hx_tmp1;
HXDLIN(  32)		if (!(( (bool)(this1->__Field(HX_("expired",a5,5f,6a,25),::hx::paccDynamic)) ))) {
HXLINE(  32)			_hx_tmp1 = ::hx::IsNull( this1->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic) );
            		}
            		else {
HXLINE(  32)			_hx_tmp1 = true;
            		}
HXDLIN(  32)		if (!(_hx_tmp1)) {
HXLINE(  32)			_hx_tmp = ::hx::IsEq( this1->__Field(HX_("id",db,5b,00,00),::hx::paccDynamic),HX_("",00,00,00,00) );
            		}
            		else {
HXLINE(  32)			_hx_tmp = true;
            		}
HXDLIN(  32)		if (_hx_tmp) {
HXLINE(  33)			return HX_("session-expired",6e,cc,68,ac);
            		}
HXLINE(  35)		bool _hx_tmp2;
HXDLIN(  35)		bool _hx_tmp3;
HXDLIN(  35)		if (::hx::IsNotNull( this1->__Field(HX_("user",4b,92,ad,4d),::hx::paccDynamic) )) {
HXLINE(  35)			_hx_tmp3 = ::hx::IsNotNull(  ::Dynamic(this1->__Field(HX_("user",4b,92,ad,4d),::hx::paccDynamic))->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic) );
            		}
            		else {
HXLINE(  35)			_hx_tmp3 = false;
            		}
HXDLIN(  35)		if (_hx_tmp3) {
HXLINE(  35)			_hx_tmp2 = ::hx::IsNotEq(  ::Dynamic(this1->__Field(HX_("user",4b,92,ad,4d),::hx::paccDynamic))->__Field(HX_("name",4b,72,ff,48),::hx::paccDynamic),HX_("",00,00,00,00) );
            		}
            		else {
HXLINE(  35)			_hx_tmp2 = false;
            		}
HXDLIN(  35)		if (_hx_tmp2) {
HXLINE(  36)			return HX_("user-loaded",07,45,85,a0);
            		}
HXLINE(  38)		return HX_("request-login",ab,da,18,fe);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Session_Impl__obj,get_status,return )


Session_Impl__obj::Session_Impl__obj()
{
}

bool Session_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"get_status") ) { outValue = get_status_dyn(); return true; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_passportUrl") ) { outValue = get_passportUrl_dyn(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_passport_url") ) { outValue = get_passport_url_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Session_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Session_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Session_Impl__obj::__mClass;

static ::String Session_Impl__obj_sStaticFields[] = {
	HX_("get_passportUrl",54,45,20,f6),
	HX_("get_passport_url",cb,d2,ba,6c),
	HX_("get_status",fb,56,83,f6),
	::String(null())
};

void Session_Impl__obj::__register()
{
	Session_Impl__obj _hx_dummy;
	Session_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects._Session.Session_Impl_",b3,7e,f9,41);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Session_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Session_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Session_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Session_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Session_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace _Session
