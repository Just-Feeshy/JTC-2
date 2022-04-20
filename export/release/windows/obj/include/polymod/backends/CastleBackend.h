#ifndef INCLUDED_polymod_backends_CastleBackend
#define INCLUDED_polymod_backends_CastleBackend

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_polymod_backends_StubBackend
#include <polymod/backends/StubBackend.h>
#endif
HX_DECLARE_CLASS2(polymod,backends,CastleBackend)
HX_DECLARE_CLASS2(polymod,backends,IBackend)
HX_DECLARE_CLASS2(polymod,backends,StubBackend)

namespace polymod{
namespace backends{


class HXCPP_CLASS_ATTRIBUTES CastleBackend_obj : public  ::polymod::backends::StubBackend_obj
{
	public:
		typedef  ::polymod::backends::StubBackend_obj super;
		typedef CastleBackend_obj OBJ_;
		CastleBackend_obj();

	public:
		enum { _hx_ClassId = 0x672d9767 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="polymod.backends.CastleBackend")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"polymod.backends.CastleBackend"); }
		static ::hx::ObjectPtr< CastleBackend_obj > __new();
		static ::hx::ObjectPtr< CastleBackend_obj > __alloc(::hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CastleBackend_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CastleBackend",dc,17,2a,88); }

};

} // end namespace polymod
} // end namespace backends

#endif /* INCLUDED_polymod_backends_CastleBackend */ 
