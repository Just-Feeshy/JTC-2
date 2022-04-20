#ifndef INCLUDED_polymod_backends__LimeBackend_IdAndLibrary
#define INCLUDED_polymod_backends__LimeBackend_IdAndLibrary

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(lime,utils,AssetLibrary)
HX_DECLARE_CLASS2(polymod,backends,LimeModLibrary)
HX_DECLARE_CLASS3(polymod,backends,_LimeBackend,IdAndLibrary)

namespace polymod{
namespace backends{
namespace _LimeBackend{


class HXCPP_CLASS_ATTRIBUTES IdAndLibrary_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef IdAndLibrary_obj OBJ_;
		IdAndLibrary_obj();

	public:
		enum { _hx_ClassId = 0x082cc890 };

		void __construct(::String id, ::haxe::ds::StringMap libs, ::polymod::backends::LimeModLibrary l);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.backends._LimeBackend.IdAndLibrary")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.backends._LimeBackend.IdAndLibrary"); }
		static ::hx::ObjectPtr< IdAndLibrary_obj > __new(::String id, ::haxe::ds::StringMap libs, ::polymod::backends::LimeModLibrary l);
		static ::hx::ObjectPtr< IdAndLibrary_obj > __alloc(::hx::Ctx *_hx_ctx,::String id, ::haxe::ds::StringMap libs, ::polymod::backends::LimeModLibrary l);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~IdAndLibrary_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("IdAndLibrary",bf,98,91,f1); }

		 ::polymod::backends::LimeModLibrary library;
		::String lib;
		::String modId;
		::String nakedId;
		::String fallbackId;
};

} // end namespace polymod
} // end namespace backends
} // end namespace _LimeBackend

#endif /* INCLUDED_polymod_backends__LimeBackend_IdAndLibrary */ 
