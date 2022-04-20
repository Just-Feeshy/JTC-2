#include <hxcpp.h>

#ifndef INCLUDED_hxjsonast_JObjectField
#include <hxjsonast/JObjectField.h>
#endif
#ifndef INCLUDED_hxjsonast_Json
#include <hxjsonast/Json.h>
#endif
#ifndef INCLUDED_hxjsonast_JsonValue
#include <hxjsonast/JsonValue.h>
#endif
namespace hxjsonast{

::hxjsonast::JsonValue JsonValue_obj::JArray(::Array< ::Dynamic> values)
{
	return ::hx::CreateEnum< JsonValue_obj >(HX_("JArray",ef,90,25,4f),3,1)->_hx_init(0,values);
}

::hxjsonast::JsonValue JsonValue_obj::JBool(bool b)
{
	return ::hx::CreateEnum< JsonValue_obj >(HX_("JBool",94,9d,9b,c7),4,1)->_hx_init(0,b);
}

::hxjsonast::JsonValue JsonValue_obj::JNull;

::hxjsonast::JsonValue JsonValue_obj::JNumber(::String s)
{
	return ::hx::CreateEnum< JsonValue_obj >(HX_("JNumber",b3,4e,43,db),1,1)->_hx_init(0,s);
}

::hxjsonast::JsonValue JsonValue_obj::JObject(::Array< ::Dynamic> fields)
{
	return ::hx::CreateEnum< JsonValue_obj >(HX_("JObject",a9,46,08,4f),2,1)->_hx_init(0,fields);
}

::hxjsonast::JsonValue JsonValue_obj::JString(::String s)
{
	return ::hx::CreateEnum< JsonValue_obj >(HX_("JString",bb,f0,f8,4a),0,1)->_hx_init(0,s);
}

bool JsonValue_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("JArray",ef,90,25,4f)) { outValue = JsonValue_obj::JArray_dyn(); return true; }
	if (inName==HX_("JBool",94,9d,9b,c7)) { outValue = JsonValue_obj::JBool_dyn(); return true; }
	if (inName==HX_("JNull",f1,b7,8e,cf)) { outValue = JsonValue_obj::JNull; return true; }
	if (inName==HX_("JNumber",b3,4e,43,db)) { outValue = JsonValue_obj::JNumber_dyn(); return true; }
	if (inName==HX_("JObject",a9,46,08,4f)) { outValue = JsonValue_obj::JObject_dyn(); return true; }
	if (inName==HX_("JString",bb,f0,f8,4a)) { outValue = JsonValue_obj::JString_dyn(); return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(JsonValue_obj)

int JsonValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_("JArray",ef,90,25,4f)) return 3;
	if (inName==HX_("JBool",94,9d,9b,c7)) return 4;
	if (inName==HX_("JNull",f1,b7,8e,cf)) return 5;
	if (inName==HX_("JNumber",b3,4e,43,db)) return 1;
	if (inName==HX_("JObject",a9,46,08,4f)) return 2;
	if (inName==HX_("JString",bb,f0,f8,4a)) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonValue_obj,JArray,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonValue_obj,JBool,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonValue_obj,JNumber,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonValue_obj,JObject,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(JsonValue_obj,JString,return)

int JsonValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("JArray",ef,90,25,4f)) return 1;
	if (inName==HX_("JBool",94,9d,9b,c7)) return 1;
	if (inName==HX_("JNull",f1,b7,8e,cf)) return 0;
	if (inName==HX_("JNumber",b3,4e,43,db)) return 1;
	if (inName==HX_("JObject",a9,46,08,4f)) return 1;
	if (inName==HX_("JString",bb,f0,f8,4a)) return 1;
	return super::__FindArgCount(inName);
}

::hx::Val JsonValue_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("JArray",ef,90,25,4f)) return JArray_dyn();
	if (inName==HX_("JBool",94,9d,9b,c7)) return JBool_dyn();
	if (inName==HX_("JNull",f1,b7,8e,cf)) return JNull;
	if (inName==HX_("JNumber",b3,4e,43,db)) return JNumber_dyn();
	if (inName==HX_("JObject",a9,46,08,4f)) return JObject_dyn();
	if (inName==HX_("JString",bb,f0,f8,4a)) return JString_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String JsonValue_obj_sStaticFields[] = {
	HX_("JString",bb,f0,f8,4a),
	HX_("JNumber",b3,4e,43,db),
	HX_("JObject",a9,46,08,4f),
	HX_("JArray",ef,90,25,4f),
	HX_("JBool",94,9d,9b,c7),
	HX_("JNull",f1,b7,8e,cf),
	::String(null())
};

::hx::Class JsonValue_obj::__mClass;

Dynamic __Create_JsonValue_obj() { return new JsonValue_obj; }

void JsonValue_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("hxjsonast.JsonValue",a5,63,d3,fb), ::hx::TCanCast< JsonValue_obj >,JsonValue_obj_sStaticFields,0,
	&__Create_JsonValue_obj, &__Create,
	&super::__SGetClass(), &CreateJsonValue_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &JsonValue_obj::__GetStatic;
}

void JsonValue_obj::__boot()
{
JNull = ::hx::CreateConstEnum< JsonValue_obj >(HX_("JNull",f1,b7,8e,cf),5);
}


} // end namespace hxjsonast
