#ifndef INCLUDED_json2object_Error
#define INCLUDED_json2object_Error

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(json2object,Error)
namespace json2object{


class Error_obj : public ::hx::EnumBase_obj
{
	typedef ::hx::EnumBase_obj super;
		typedef Error_obj OBJ_;

	public:
		Error_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		static bool __GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::String GetEnumName( ) const { return HX_("json2object.Error",c3,74,fb,a2); }
		::String __ToString() const { return HX_("Error.",86,f7,fc,85) + _hx_tag; }

		static ::json2object::Error CustomFunctionException( ::Dynamic e, ::Dynamic pos);
		static ::Dynamic CustomFunctionException_dyn();
		static ::json2object::Error IncorrectEnumValue(::String value,::String expected, ::Dynamic pos);
		static ::Dynamic IncorrectEnumValue_dyn();
		static ::json2object::Error IncorrectType(::String variable,::String expected, ::Dynamic pos);
		static ::Dynamic IncorrectType_dyn();
		static ::json2object::Error InvalidEnumConstructor(::String value,::String expected, ::Dynamic pos);
		static ::Dynamic InvalidEnumConstructor_dyn();
		static ::json2object::Error ParserError(::String message, ::Dynamic pos);
		static ::Dynamic ParserError_dyn();
		static ::json2object::Error UninitializedVariable(::String variable, ::Dynamic pos);
		static ::Dynamic UninitializedVariable_dyn();
		static ::json2object::Error UnknownVariable(::String variable, ::Dynamic pos);
		static ::Dynamic UnknownVariable_dyn();
};

} // end namespace json2object

#endif /* INCLUDED_json2object_Error */ 
