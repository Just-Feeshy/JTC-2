#ifndef INCLUDED_polymod_util_DefineUtil
#define INCLUDED_polymod_util_DefineUtil

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,util,DefineUtil)

namespace polymod{
namespace util{


class HXCPP_CLASS_ATTRIBUTES DefineUtil_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef DefineUtil_obj OBJ_;
		DefineUtil_obj();

	public:
		enum { _hx_ClassId = 0x1945eb51 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.util.DefineUtil")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.util.DefineUtil"); }

		inline static ::hx::ObjectPtr< DefineUtil_obj > __new() {
			::hx::ObjectPtr< DefineUtil_obj > __this = new DefineUtil_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< DefineUtil_obj > __alloc(::hx::Ctx *_hx_ctx) {
			DefineUtil_obj *__this = (DefineUtil_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(DefineUtil_obj), false, "polymod.util.DefineUtil"));
			*(void **)__this = DefineUtil_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~DefineUtil_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("DefineUtil",fd,3d,af,80); }

};

} // end namespace polymod
} // end namespace util

#endif /* INCLUDED_polymod_util_DefineUtil */ 
