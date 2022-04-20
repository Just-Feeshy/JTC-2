#ifndef INCLUDED_polymod_ModMetadata
#define INCLUDED_polymod_ModMetadata

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS1(polymod,ModMetadata)
HX_DECLARE_CLASS2(polymod,util,SemanticVersion)

namespace polymod{


class HXCPP_CLASS_ATTRIBUTES ModMetadata_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ModMetadata_obj OBJ_;
		ModMetadata_obj();

	public:
		enum { _hx_ClassId = 0x29416a7b };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.ModMetadata")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.ModMetadata"); }
		static ::hx::ObjectPtr< ModMetadata_obj > __new();
		static ::hx::ObjectPtr< ModMetadata_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ModMetadata_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ModMetadata",31,e4,48,a3); }

		static  ::polymod::ModMetadata fromJsonStr(::String str);
		static ::Dynamic fromJsonStr_dyn();

		::String id;
		::String title;
		::String description;
		::String homepage;
		 ::polymod::util::SemanticVersion apiVersion;
		 ::polymod::util::SemanticVersion modVersion;
		::String license;
		::String licenseRef;
		 ::haxe::io::Bytes icon;
		 ::haxe::ds::StringMap metaData;
		::String _author;
		::String get_author();
		::Dynamic get_author_dyn();

		::String set_author(::String v);
		::Dynamic set_author_dyn();

		::Array< ::Dynamic> contributors;
		::String toJsonStr();
		::Dynamic toJsonStr_dyn();

};

} // end namespace polymod

#endif /* INCLUDED_polymod_ModMetadata */ 
