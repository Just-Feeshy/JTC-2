#include <hxcpp.h>

#ifndef INCLUDED_json2object_CustomFunctionError
#include <json2object/CustomFunctionError.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_da47e08bcf33f095_113_new,"json2object.CustomFunctionError","new",0xbb8b074c,"json2object.CustomFunctionError.new","json2object/Error.hx",113,0x2c9e52dc)
namespace json2object{

void CustomFunctionError_obj::__construct(::String message){
            	HX_STACKFRAME(&_hx_pos_da47e08bcf33f095_113_new)
HXDLIN( 113)		this->message = message;
            	}

Dynamic CustomFunctionError_obj::__CreateEmpty() { return new CustomFunctionError_obj; }

void *CustomFunctionError_obj::_hx_vtable = 0;

Dynamic CustomFunctionError_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< CustomFunctionError_obj > _hx_result = new CustomFunctionError_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool CustomFunctionError_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x11805a7a;
}


CustomFunctionError_obj::CustomFunctionError_obj()
{
}

void CustomFunctionError_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CustomFunctionError);
	HX_MARK_MEMBER_NAME(message,"message");
	HX_MARK_END_CLASS();
}

void CustomFunctionError_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(message,"message");
}

::hx::Val CustomFunctionError_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"message") ) { return ::hx::Val( message ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val CustomFunctionError_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"message") ) { message=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CustomFunctionError_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("message",c7,35,11,9a));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo CustomFunctionError_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(CustomFunctionError_obj,message),HX_("message",c7,35,11,9a)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *CustomFunctionError_obj_sStaticStorageInfo = 0;
#endif

static ::String CustomFunctionError_obj_sMemberFields[] = {
	HX_("message",c7,35,11,9a),
	::String(null()) };

::hx::Class CustomFunctionError_obj::__mClass;

void CustomFunctionError_obj::__register()
{
	CustomFunctionError_obj _hx_dummy;
	CustomFunctionError_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("json2object.CustomFunctionError",5a,b1,12,ed);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(CustomFunctionError_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< CustomFunctionError_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = CustomFunctionError_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = CustomFunctionError_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace json2object
