#include <hxcpp.h>

#ifndef INCLUDED_json2object_Error
#include <json2object/Error.h>
#endif
namespace json2object{

::json2object::Error Error_obj::CustomFunctionException( ::Dynamic e, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("CustomFunctionException",06,8b,52,a3),6,2)->_hx_init(0,e)->_hx_init(1,pos);
}

::json2object::Error Error_obj::IncorrectEnumValue(::String value,::String expected, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("IncorrectEnumValue",eb,74,06,97),1,3)->_hx_init(0,value)->_hx_init(1,expected)->_hx_init(2,pos);
}

::json2object::Error Error_obj::IncorrectType(::String variable,::String expected, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("IncorrectType",5f,e8,13,c2),0,3)->_hx_init(0,variable)->_hx_init(1,expected)->_hx_init(2,pos);
}

::json2object::Error Error_obj::InvalidEnumConstructor(::String value,::String expected, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("InvalidEnumConstructor",62,76,0a,5f),2,3)->_hx_init(0,value)->_hx_init(1,expected)->_hx_init(2,pos);
}

::json2object::Error Error_obj::ParserError(::String message, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("ParserError",49,2e,e1,c5),5,2)->_hx_init(0,message)->_hx_init(1,pos);
}

::json2object::Error Error_obj::UninitializedVariable(::String variable, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("UninitializedVariable",97,bc,4f,a2),3,2)->_hx_init(0,variable)->_hx_init(1,pos);
}

::json2object::Error Error_obj::UnknownVariable(::String variable, ::Dynamic pos)
{
	return ::hx::CreateEnum< Error_obj >(HX_("UnknownVariable",c6,93,43,af),4,2)->_hx_init(0,variable)->_hx_init(1,pos);
}

bool Error_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("CustomFunctionException",06,8b,52,a3)) { outValue = Error_obj::CustomFunctionException_dyn(); return true; }
	if (inName==HX_("IncorrectEnumValue",eb,74,06,97)) { outValue = Error_obj::IncorrectEnumValue_dyn(); return true; }
	if (inName==HX_("IncorrectType",5f,e8,13,c2)) { outValue = Error_obj::IncorrectType_dyn(); return true; }
	if (inName==HX_("InvalidEnumConstructor",62,76,0a,5f)) { outValue = Error_obj::InvalidEnumConstructor_dyn(); return true; }
	if (inName==HX_("ParserError",49,2e,e1,c5)) { outValue = Error_obj::ParserError_dyn(); return true; }
	if (inName==HX_("UninitializedVariable",97,bc,4f,a2)) { outValue = Error_obj::UninitializedVariable_dyn(); return true; }
	if (inName==HX_("UnknownVariable",c6,93,43,af)) { outValue = Error_obj::UnknownVariable_dyn(); return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(Error_obj)

int Error_obj::__FindIndex(::String inName)
{
	if (inName==HX_("CustomFunctionException",06,8b,52,a3)) return 6;
	if (inName==HX_("IncorrectEnumValue",eb,74,06,97)) return 1;
	if (inName==HX_("IncorrectType",5f,e8,13,c2)) return 0;
	if (inName==HX_("InvalidEnumConstructor",62,76,0a,5f)) return 2;
	if (inName==HX_("ParserError",49,2e,e1,c5)) return 5;
	if (inName==HX_("UninitializedVariable",97,bc,4f,a2)) return 3;
	if (inName==HX_("UnknownVariable",c6,93,43,af)) return 4;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Error_obj,CustomFunctionException,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(Error_obj,IncorrectEnumValue,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(Error_obj,IncorrectType,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(Error_obj,InvalidEnumConstructor,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Error_obj,ParserError,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Error_obj,UninitializedVariable,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Error_obj,UnknownVariable,return)

int Error_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("CustomFunctionException",06,8b,52,a3)) return 2;
	if (inName==HX_("IncorrectEnumValue",eb,74,06,97)) return 3;
	if (inName==HX_("IncorrectType",5f,e8,13,c2)) return 3;
	if (inName==HX_("InvalidEnumConstructor",62,76,0a,5f)) return 3;
	if (inName==HX_("ParserError",49,2e,e1,c5)) return 2;
	if (inName==HX_("UninitializedVariable",97,bc,4f,a2)) return 2;
	if (inName==HX_("UnknownVariable",c6,93,43,af)) return 2;
	return super::__FindArgCount(inName);
}

::hx::Val Error_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("CustomFunctionException",06,8b,52,a3)) return CustomFunctionException_dyn();
	if (inName==HX_("IncorrectEnumValue",eb,74,06,97)) return IncorrectEnumValue_dyn();
	if (inName==HX_("IncorrectType",5f,e8,13,c2)) return IncorrectType_dyn();
	if (inName==HX_("InvalidEnumConstructor",62,76,0a,5f)) return InvalidEnumConstructor_dyn();
	if (inName==HX_("ParserError",49,2e,e1,c5)) return ParserError_dyn();
	if (inName==HX_("UninitializedVariable",97,bc,4f,a2)) return UninitializedVariable_dyn();
	if (inName==HX_("UnknownVariable",c6,93,43,af)) return UnknownVariable_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String Error_obj_sStaticFields[] = {
	HX_("IncorrectType",5f,e8,13,c2),
	HX_("IncorrectEnumValue",eb,74,06,97),
	HX_("InvalidEnumConstructor",62,76,0a,5f),
	HX_("UninitializedVariable",97,bc,4f,a2),
	HX_("UnknownVariable",c6,93,43,af),
	HX_("ParserError",49,2e,e1,c5),
	HX_("CustomFunctionException",06,8b,52,a3),
	::String(null())
};

::hx::Class Error_obj::__mClass;

Dynamic __Create_Error_obj() { return new Error_obj; }

void Error_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("json2object.Error",c3,74,fb,a2), ::hx::TCanCast< Error_obj >,Error_obj_sStaticFields,0,
	&__Create_Error_obj, &__Create,
	&super::__SGetClass(), &CreateError_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &Error_obj::__GetStatic;
}

void Error_obj::__boot()
{
}


} // end namespace json2object
