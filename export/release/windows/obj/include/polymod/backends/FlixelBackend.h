#ifndef INCLUDED_polymod_backends_FlixelBackend
#define INCLUDED_polymod_backends_FlixelBackend

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_polymod_backends_OpenFLBackend
#include <polymod/backends/OpenFLBackend.h>
#endif
HX_DECLARE_CLASS2(polymod,backends,FlixelBackend)
HX_DECLARE_CLASS2(polymod,backends,IBackend)
HX_DECLARE_CLASS2(polymod,backends,LimeBackend)
HX_DECLARE_CLASS2(polymod,backends,OpenFLBackend)

namespace polymod{
namespace backends{


class HXCPP_CLASS_ATTRIBUTES FlixelBackend_obj : public  ::polymod::backends::OpenFLBackend_obj
{
	public:
		typedef  ::polymod::backends::OpenFLBackend_obj super;
		typedef FlixelBackend_obj OBJ_;
		FlixelBackend_obj();

	public:
		enum { _hx_ClassId = 0x0065a5e7 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.backends.FlixelBackend")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.backends.FlixelBackend"); }
		static ::hx::ObjectPtr< FlixelBackend_obj > __new();
		static ::hx::ObjectPtr< FlixelBackend_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~FlixelBackend_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("FlixelBackend",f8,34,e6,f0); }

		void clearCache();

		void destroy();

};

} // end namespace polymod
} // end namespace backends

#endif /* INCLUDED_polymod_backends_FlixelBackend */ 
