#include <hxcpp.h>

#ifndef INCLUDED_json2object_InternalError
#include <json2object/InternalError.h>
#endif
namespace json2object{

::json2object::InternalError InternalError_obj::AbstractNoJsonRepresentation(::String name)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("AbstractNoJsonRepresentation",18,f9,ca,56),0,1)->_hx_init(0,name);
}

::json2object::InternalError InternalError_obj::CannotGenerateSchema(::String name)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("CannotGenerateSchema",b9,37,b7,b3),1,1)->_hx_init(0,name);
}

::json2object::InternalError InternalError_obj::HandleExpr;

::json2object::InternalError InternalError_obj::ParsingThrow;

::json2object::InternalError InternalError_obj::UnsupportedAbstractEnumType(::String name)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("UnsupportedAbstractEnumType",12,c8,4e,05),4,1)->_hx_init(0,name);
}

::json2object::InternalError InternalError_obj::UnsupportedEnumAbstractValue(::String name)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("UnsupportedEnumAbstractValue",19,77,83,f2),5,1)->_hx_init(0,name);
}

::json2object::InternalError InternalError_obj::UnsupportedMapKeyType(::String name)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("UnsupportedMapKeyType",b2,a1,80,04),6,1)->_hx_init(0,name);
}

::json2object::InternalError InternalError_obj::UnsupportedSchemaObjectType(::String name)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("UnsupportedSchemaObjectType",4f,5b,d6,a7),7,1)->_hx_init(0,name);
}

::json2object::InternalError InternalError_obj::UnsupportedSchemaType(::String type)
{
	return ::hx::CreateEnum< InternalError_obj >(HX_("UnsupportedSchemaType",70,b8,f9,fc),8,1)->_hx_init(0,type);
}

bool InternalError_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("AbstractNoJsonRepresentation",18,f9,ca,56)) { outValue = InternalError_obj::AbstractNoJsonRepresentation_dyn(); return true; }
	if (inName==HX_("CannotGenerateSchema",b9,37,b7,b3)) { outValue = InternalError_obj::CannotGenerateSchema_dyn(); return true; }
	if (inName==HX_("HandleExpr",1d,a5,74,58)) { outValue = InternalError_obj::HandleExpr; return true; }
	if (inName==HX_("ParsingThrow",f6,3e,1e,e9)) { outValue = InternalError_obj::ParsingThrow; return true; }
	if (inName==HX_("UnsupportedAbstractEnumType",12,c8,4e,05)) { outValue = InternalError_obj::UnsupportedAbstractEnumType_dyn(); return true; }
	if (inName==HX_("UnsupportedEnumAbstractValue",19,77,83,f2)) { outValue = InternalError_obj::UnsupportedEnumAbstractValue_dyn(); return true; }
	if (inName==HX_("UnsupportedMapKeyType",b2,a1,80,04)) { outValue = InternalError_obj::UnsupportedMapKeyType_dyn(); return true; }
	if (inName==HX_("UnsupportedSchemaObjectType",4f,5b,d6,a7)) { outValue = InternalError_obj::UnsupportedSchemaObjectType_dyn(); return true; }
	if (inName==HX_("UnsupportedSchemaType",70,b8,f9,fc)) { outValue = InternalError_obj::UnsupportedSchemaType_dyn(); return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(InternalError_obj)

int InternalError_obj::__FindIndex(::String inName)
{
	if (inName==HX_("AbstractNoJsonRepresentation",18,f9,ca,56)) return 0;
	if (inName==HX_("CannotGenerateSchema",b9,37,b7,b3)) return 1;
	if (inName==HX_("HandleExpr",1d,a5,74,58)) return 2;
	if (inName==HX_("ParsingThrow",f6,3e,1e,e9)) return 3;
	if (inName==HX_("UnsupportedAbstractEnumType",12,c8,4e,05)) return 4;
	if (inName==HX_("UnsupportedEnumAbstractValue",19,77,83,f2)) return 5;
	if (inName==HX_("UnsupportedMapKeyType",b2,a1,80,04)) return 6;
	if (inName==HX_("UnsupportedSchemaObjectType",4f,5b,d6,a7)) return 7;
	if (inName==HX_("UnsupportedSchemaType",70,b8,f9,fc)) return 8;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,AbstractNoJsonRepresentation,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,CannotGenerateSchema,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,UnsupportedAbstractEnumType,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,UnsupportedEnumAbstractValue,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,UnsupportedMapKeyType,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,UnsupportedSchemaObjectType,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(InternalError_obj,UnsupportedSchemaType,return)

int InternalError_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("AbstractNoJsonRepresentation",18,f9,ca,56)) return 1;
	if (inName==HX_("CannotGenerateSchema",b9,37,b7,b3)) return 1;
	if (inName==HX_("HandleExpr",1d,a5,74,58)) return 0;
	if (inName==HX_("ParsingThrow",f6,3e,1e,e9)) return 0;
	if (inName==HX_("UnsupportedAbstractEnumType",12,c8,4e,05)) return 1;
	if (inName==HX_("UnsupportedEnumAbstractValue",19,77,83,f2)) return 1;
	if (inName==HX_("UnsupportedMapKeyType",b2,a1,80,04)) return 1;
	if (inName==HX_("UnsupportedSchemaObjectType",4f,5b,d6,a7)) return 1;
	if (inName==HX_("UnsupportedSchemaType",70,b8,f9,fc)) return 1;
	return super::__FindArgCount(inName);
}

::hx::Val InternalError_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("AbstractNoJsonRepresentation",18,f9,ca,56)) return AbstractNoJsonRepresentation_dyn();
	if (inName==HX_("CannotGenerateSchema",b9,37,b7,b3)) return CannotGenerateSchema_dyn();
	if (inName==HX_("HandleExpr",1d,a5,74,58)) return HandleExpr;
	if (inName==HX_("ParsingThrow",f6,3e,1e,e9)) return ParsingThrow;
	if (inName==HX_("UnsupportedAbstractEnumType",12,c8,4e,05)) return UnsupportedAbstractEnumType_dyn();
	if (inName==HX_("UnsupportedEnumAbstractValue",19,77,83,f2)) return UnsupportedEnumAbstractValue_dyn();
	if (inName==HX_("UnsupportedMapKeyType",b2,a1,80,04)) return UnsupportedMapKeyType_dyn();
	if (inName==HX_("UnsupportedSchemaObjectType",4f,5b,d6,a7)) return UnsupportedSchemaObjectType_dyn();
	if (inName==HX_("UnsupportedSchemaType",70,b8,f9,fc)) return UnsupportedSchemaType_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String InternalError_obj_sStaticFields[] = {
	HX_("AbstractNoJsonRepresentation",18,f9,ca,56),
	HX_("CannotGenerateSchema",b9,37,b7,b3),
	HX_("HandleExpr",1d,a5,74,58),
	HX_("ParsingThrow",f6,3e,1e,e9),
	HX_("UnsupportedAbstractEnumType",12,c8,4e,05),
	HX_("UnsupportedEnumAbstractValue",19,77,83,f2),
	HX_("UnsupportedMapKeyType",b2,a1,80,04),
	HX_("UnsupportedSchemaObjectType",4f,5b,d6,a7),
	HX_("UnsupportedSchemaType",70,b8,f9,fc),
	::String(null())
};

::hx::Class InternalError_obj::__mClass;

Dynamic __Create_InternalError_obj() { return new InternalError_obj; }

void InternalError_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("json2object.InternalError",46,13,7c,c0), ::hx::TCanCast< InternalError_obj >,InternalError_obj_sStaticFields,0,
	&__Create_InternalError_obj, &__Create,
	&super::__SGetClass(), &CreateInternalError_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &InternalError_obj::__GetStatic;
}

void InternalError_obj::__boot()
{
HandleExpr = ::hx::CreateConstEnum< InternalError_obj >(HX_("HandleExpr",1d,a5,74,58),2);
ParsingThrow = ::hx::CreateConstEnum< InternalError_obj >(HX_("ParsingThrow",f6,3e,1e,e9),3);
}


} // end namespace json2object
