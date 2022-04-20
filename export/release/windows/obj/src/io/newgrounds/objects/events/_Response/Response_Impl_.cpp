#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_objects_events__Response_Response_Impl_
#include <io/newgrounds/objects/events/_Response/Response_Impl_.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_715965498b8b46af_25_get_success,"io.newgrounds.objects.events._Response.Response_Impl_","get_success",0x800edc3c,"io.newgrounds.objects.events._Response.Response_Impl_.get_success","io/newgrounds/objects/events/Response.hx",25,0xd9a6e3bc)
HX_LOCAL_STACK_FRAME(_hx_pos_715965498b8b46af_26_get_error,"io.newgrounds.objects.events._Response.Response_Impl_","get_error",0xdf55c201,"io.newgrounds.objects.events._Response.Response_Impl_.get_error","io/newgrounds/objects/events/Response.hx",26,0xd9a6e3bc)
HX_LOCAL_STACK_FRAME(_hx_pos_715965498b8b46af_27_get_debug,"io.newgrounds.objects.events._Response.Response_Impl_","get_debug",0x434b488c,"io.newgrounds.objects.events._Response.Response_Impl_.get_debug","io/newgrounds/objects/events/Response.hx",27,0xd9a6e3bc)
HX_LOCAL_STACK_FRAME(_hx_pos_715965498b8b46af_28_get_result,"io.newgrounds.objects.events._Response.Response_Impl_","get_result",0x42cfe484,"io.newgrounds.objects.events._Response.Response_Impl_.get_result","io/newgrounds/objects/events/Response.hx",28,0xd9a6e3bc)
HX_LOCAL_STACK_FRAME(_hx_pos_715965498b8b46af_29_get_appId,"io.newgrounds.objects.events._Response.Response_Impl_","get_appId",0x90675d15,"io.newgrounds.objects.events._Response.Response_Impl_.get_appId","io/newgrounds/objects/events/Response.hx",29,0xd9a6e3bc)
HX_LOCAL_STACK_FRAME(_hx_pos_715965498b8b46af_31__new,"io.newgrounds.objects.events._Response.Response_Impl_","_new",0xcda6c6bf,"io.newgrounds.objects.events._Response.Response_Impl_._new","io/newgrounds/objects/events/Response.hx",31,0xd9a6e3bc)
namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Response{

void Response_Impl__obj::__construct() { }

Dynamic Response_Impl__obj::__CreateEmpty() { return new Response_Impl__obj; }

void *Response_Impl__obj::_hx_vtable = 0;

Dynamic Response_Impl__obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Response_Impl__obj > _hx_result = new Response_Impl__obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Response_Impl__obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6dc65aaa;
}

bool Response_Impl__obj::get_success( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_715965498b8b46af_25_get_success)
HXDLIN(  25)		return ( (bool)(this1->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Response_Impl__obj,get_success,return )

 ::Dynamic Response_Impl__obj::get_error( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_715965498b8b46af_26_get_error)
HXDLIN(  26)		return this1->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Response_Impl__obj,get_error,return )

 ::Dynamic Response_Impl__obj::get_debug( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_715965498b8b46af_27_get_debug)
HXDLIN(  27)		return this1->__Field(HX_("debug",53,52,1f,d7),::hx::paccDynamic);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Response_Impl__obj,get_debug,return )

 ::Dynamic Response_Impl__obj::get_result( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_715965498b8b46af_28_get_result)
HXDLIN(  28)		return this1->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Response_Impl__obj,get_result,return )

::String Response_Impl__obj::get_appId( ::Dynamic this1){
            	HX_STACKFRAME(&_hx_pos_715965498b8b46af_29_get_appId)
HXDLIN(  29)		return ( (::String)(this1->__Field(HX_("app_id",f9,4f,cf,8f),::hx::paccDynamic)) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Response_Impl__obj,get_appId,return )

 ::Dynamic Response_Impl__obj::_new( ::io::newgrounds::NGLite core,::String reply){
            	HX_GC_STACKFRAME(&_hx_pos_715965498b8b46af_31__new)
HXDLIN(  31)		 ::Dynamic this1;
HXLINE(  33)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE(  33)			this1 =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,reply)->doParse();
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g = _hx_e;
HXLINE(  34)				{
HXLINE(  34)					null();
            				}
HXDLIN(  34)				 ::Dynamic e = ::haxe::Exception_obj::caught(_g)->unwrap();
HXLINE(  36)				this1 =  ::haxe::format::JsonParser_obj::__alloc( HX_CTX ,((((HX_("{\"success\":false,\"error\":{\"message\":\"Error parsing reply:'",4a,a8,ab,33) + reply) + HX_("' error:'",7c,c3,1f,33)) + ::Std_obj::string(e)) + HX_("'\",\"code\":0}}",fa,e6,a1,c6)))->doParse();
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
HXLINE(  39)		if (!(( (bool)(this1->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) ))) {
HXLINE(  40)			 ::Dynamic tmp = this1->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic);
HXDLIN(  40)			::String _hx_tmp;
HXDLIN(  40)			if (::hx::IsNull( tmp )) {
HXLINE(  40)				_hx_tmp = HX_("null",87,9e,0e,49);
            			}
            			else {
HXLINE(  40)				::String _hx_tmp1;
HXDLIN(  40)				if (::hx::IsNotNull( tmp->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic) )) {
HXLINE(  40)					_hx_tmp1 = ( (::String)(((HX_("#",23,00,00,00) + tmp->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic)) + HX_(" - ",73,6f,18,00))) );
            				}
            				else {
HXLINE(  40)					_hx_tmp1 = HX_("",00,00,00,00);
            				}
HXDLIN(  40)				_hx_tmp = ( (::String)((_hx_tmp1 + tmp->__Field(HX_("message",c7,35,11,9a),::hx::paccDynamic))) );
            			}
HXDLIN(  40)			core->logError((HX_("Call unseccessful: ",6b,6c,5c,b6) + _hx_tmp),::hx::SourceInfo(HX_("io/newgrounds/objects/events/Response.hx",bc,e3,a6,d9),40,HX_("io.newgrounds.objects.events._Response.Response_Impl_",d0,2b,e6,ae),HX_("_new",61,15,1f,3f)));
            		}
            		else {
HXLINE(  41)			if (!(( (bool)( ::Dynamic( ::Dynamic(this1->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) ))) {
HXLINE(  42)				 ::Dynamic tmp =  ::Dynamic( ::Dynamic(this1->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic);
HXDLIN(  42)				::String _hx_tmp;
HXDLIN(  42)				if (::hx::IsNull( tmp )) {
HXLINE(  42)					_hx_tmp = HX_("null",87,9e,0e,49);
            				}
            				else {
HXLINE(  42)					::String _hx_tmp1;
HXDLIN(  42)					if (::hx::IsNotNull( tmp->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic) )) {
HXLINE(  42)						_hx_tmp1 = ( (::String)(((HX_("#",23,00,00,00) + tmp->__Field(HX_("code",2d,b1,c4,41),::hx::paccDynamic)) + HX_(" - ",73,6f,18,00))) );
            					}
            					else {
HXLINE(  42)						_hx_tmp1 = HX_("",00,00,00,00);
            					}
HXDLIN(  42)					_hx_tmp = ( (::String)((_hx_tmp1 + tmp->__Field(HX_("message",c7,35,11,9a),::hx::paccDynamic))) );
            				}
HXDLIN(  42)				core->logError( ::Dynamic((((HX_("",00,00,00,00) +  ::Dynamic(this1->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("component",bd,f0,53,0f),::hx::paccDynamic)) + HX_(" fail: ",24,78,ad,1a)) + _hx_tmp)),::hx::SourceInfo(HX_("io/newgrounds/objects/events/Response.hx",bc,e3,a6,d9),42,HX_("io.newgrounds.objects.events._Response.Response_Impl_",d0,2b,e6,ae),HX_("_new",61,15,1f,3f)));
            			}
            		}
HXLINE(  31)		return this1;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Response_Impl__obj,_new,return )


Response_Impl__obj::Response_Impl__obj()
{
}

bool Response_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { outValue = _new_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_error") ) { outValue = get_error_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_debug") ) { outValue = get_debug_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"get_appId") ) { outValue = get_appId_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_result") ) { outValue = get_result_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_success") ) { outValue = get_success_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Response_Impl__obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Response_Impl__obj_sStaticStorageInfo = 0;
#endif

::hx::Class Response_Impl__obj::__mClass;

static ::String Response_Impl__obj_sStaticFields[] = {
	HX_("get_success",da,85,48,3e),
	HX_("get_error",1f,28,d3,b6),
	HX_("get_debug",aa,ae,c8,1a),
	HX_("get_result",a6,d8,0b,f9),
	HX_("get_appId",33,c3,e4,67),
	HX_("_new",61,15,1f,3f),
	::String(null())
};

void Response_Impl__obj::__register()
{
	Response_Impl__obj _hx_dummy;
	Response_Impl__obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.objects.events._Response.Response_Impl_",d0,2b,e6,ae);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Response_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Response_Impl__obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Response_Impl__obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Response_Impl__obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Response_Impl__obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Response
