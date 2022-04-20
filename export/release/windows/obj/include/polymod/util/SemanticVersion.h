#ifndef INCLUDED_polymod_util_SemanticVersion
#define INCLUDED_polymod_util_SemanticVersion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,util,SemanticVersion)

namespace polymod{
namespace util{


class HXCPP_CLASS_ATTRIBUTES SemanticVersion_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef SemanticVersion_obj OBJ_;
		SemanticVersion_obj();

	public:
		enum { _hx_ClassId = 0x3992c45a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.util.SemanticVersion")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.util.SemanticVersion"); }
		static ::hx::ObjectPtr< SemanticVersion_obj > __new();
		static ::hx::ObjectPtr< SemanticVersion_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SemanticVersion_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SemanticVersion",92,52,8e,27); }

		static  ::polymod::util::SemanticVersion fromString(::String str);
		static ::Dynamic fromString_dyn();

		::String original;
		::String effective;
		int major;
		int minor;
		int patch;
		::Array< ::String > preRelease;
		int checkCompatibility( ::polymod::util::SemanticVersion newer);
		::Dynamic checkCompatibility_dyn();

		int compare( ::polymod::util::SemanticVersion other);
		::Dynamic compare_dyn();

		bool isEqualTo( ::polymod::util::SemanticVersion other);
		::Dynamic isEqualTo_dyn();

		bool isNewerThan( ::polymod::util::SemanticVersion other);
		::Dynamic isNewerThan_dyn();

		virtual ::String toString();
		::Dynamic toString_dyn();

};

} // end namespace polymod
} // end namespace util

#endif /* INCLUDED_polymod_util_SemanticVersion */ 
