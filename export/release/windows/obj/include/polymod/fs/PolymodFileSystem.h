#ifndef INCLUDED_polymod_fs_PolymodFileSystem
#define INCLUDED_polymod_fs_PolymodFileSystem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,fs,IFileSystem)
HX_DECLARE_CLASS2(polymod,fs,PolymodFileSystem)
HX_DECLARE_CLASS2(polymod,fs,SysFileSystem)

namespace polymod{
namespace fs{


class HXCPP_CLASS_ATTRIBUTES PolymodFileSystem_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PolymodFileSystem_obj OBJ_;
		PolymodFileSystem_obj();

	public:
		enum { _hx_ClassId = 0x4abdba0a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.fs.PolymodFileSystem")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.fs.PolymodFileSystem"); }

		inline static ::hx::ObjectPtr< PolymodFileSystem_obj > __new() {
			::hx::ObjectPtr< PolymodFileSystem_obj > __this = new PolymodFileSystem_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< PolymodFileSystem_obj > __alloc(::hx::Ctx *_hx_ctx) {
			PolymodFileSystem_obj *__this = (PolymodFileSystem_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodFileSystem_obj), false, "polymod.fs.PolymodFileSystem"));
			*(void **)__this = PolymodFileSystem_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PolymodFileSystem_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PolymodFileSystem",01,02,17,7e); }

		static ::Dynamic makeFileSystem( ::Dynamic cls, ::Dynamic params);
		static ::Dynamic makeFileSystem_dyn();

		static  ::polymod::fs::SysFileSystem _detectFileSystem( ::Dynamic params);
		static ::Dynamic _detectFileSystem_dyn();

};

} // end namespace polymod
} // end namespace fs

#endif /* INCLUDED_polymod_fs_PolymodFileSystem */ 
