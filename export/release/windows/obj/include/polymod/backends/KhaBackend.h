#ifndef INCLUDED_polymod_backends_KhaBackend
#define INCLUDED_polymod_backends_KhaBackend

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_polymod_backends_StubBackend
#include <polymod/backends/StubBackend.h>
#endif
HX_DECLARE_CLASS2(polymod,backends,IBackend)
HX_DECLARE_CLASS2(polymod,backends,KhaBackend)
HX_DECLARE_CLASS2(polymod,backends,StubBackend)

namespace polymod{
namespace backends{


class HXCPP_CLASS_ATTRIBUTES KhaBackend_obj : public  ::polymod::backends::StubBackend_obj
{
	public:
		typedef  ::polymod::backends::StubBackend_obj super;
		typedef KhaBackend_obj OBJ_;
		KhaBackend_obj();

	public:
		enum { _hx_ClassId = 0x10401405 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.backends.KhaBackend")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.backends.KhaBackend"); }
		static ::hx::ObjectPtr< KhaBackend_obj > __new();
		static ::hx::ObjectPtr< KhaBackend_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~KhaBackend_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("KhaBackend",70,e8,d9,7c); }

};

} // end namespace polymod
} // end namespace backends

#endif /* INCLUDED_polymod_backends_KhaBackend */ 
