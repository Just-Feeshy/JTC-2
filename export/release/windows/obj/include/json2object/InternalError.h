#ifndef INCLUDED_json2object_InternalError
#define INCLUDED_json2object_InternalError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(json2object,InternalError)
namespace json2object{


class InternalError_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef InternalError_obj OBJ_;

	public:
		InternalError_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("json2object.InternalError",46,13,7c,c0); }
		::String __ToString() const { return HX_("InternalError.",a3,7e,ad,20) + _hx_tag; }

		static ::json2object::InternalError AbstractNoJsonRepresentation(::String name);
		static ::Dynamic AbstractNoJsonRepresentation_dyn();
		static ::json2object::InternalError CannotGenerateSchema(::String name);
		static ::Dynamic CannotGenerateSchema_dyn();
		static ::json2object::InternalError HandleExpr;
		static inline ::json2object::InternalError HandleExpr_dyn() { return HandleExpr; }
		static ::json2object::InternalError ParsingThrow;
		static inline ::json2object::InternalError ParsingThrow_dyn() { return ParsingThrow; }
		static ::json2object::InternalError UnsupportedAbstractEnumType(::String name);
		static ::Dynamic UnsupportedAbstractEnumType_dyn();
		static ::json2object::InternalError UnsupportedEnumAbstractValue(::String name);
		static ::Dynamic UnsupportedEnumAbstractValue_dyn();
		static ::json2object::InternalError UnsupportedMapKeyType(::String name);
		static ::Dynamic UnsupportedMapKeyType_dyn();
		static ::json2object::InternalError UnsupportedSchemaObjectType(::String name);
		static ::Dynamic UnsupportedSchemaObjectType_dyn();
		static ::json2object::InternalError UnsupportedSchemaType(::String type);
		static ::Dynamic UnsupportedSchemaType_dyn();
};

} // end namespace json2object

#endif /* INCLUDED_json2object_InternalError */ 
