#ifndef INCLUDED_hxjsonast_JsonValue
#define INCLUDED_hxjsonast_JsonValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxjsonast,JObjectField)
HX_DECLARE_CLASS1(hxjsonast,Json)
HX_DECLARE_CLASS1(hxjsonast,JsonValue)
namespace hxjsonast{


class JsonValue_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef JsonValue_obj OBJ_;

	public:
		JsonValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("hxjsonast.JsonValue",a5,63,d3,fb); }
		::String __ToString() const { return HX_("JsonValue.",05,cc,5c,87) + _hx_tag; }

		static ::hxjsonast::JsonValue JArray(::Array< ::Dynamic> values);
		static ::Dynamic JArray_dyn();
		static ::hxjsonast::JsonValue JBool(bool b);
		static ::Dynamic JBool_dyn();
		static ::hxjsonast::JsonValue JNull;
		static inline ::hxjsonast::JsonValue JNull_dyn() { return JNull; }
		static ::hxjsonast::JsonValue JNumber(::String s);
		static ::Dynamic JNumber_dyn();
		static ::hxjsonast::JsonValue JObject(::Array< ::Dynamic> fields);
		static ::Dynamic JObject_dyn();
		static ::hxjsonast::JsonValue JString(::String s);
		static ::Dynamic JString_dyn();
};

} // end namespace hxjsonast

#endif /* INCLUDED_hxjsonast_JsonValue */ 
