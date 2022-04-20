#ifndef INCLUDED_polymod_util__SemanticVersion_SemanticVersionScore_Impl_
#define INCLUDED_polymod_util__SemanticVersion_SemanticVersionScore_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(polymod,util,_SemanticVersion,SemanticVersionScore_Impl_)

namespace polymod{
namespace util{
namespace _SemanticVersion{


class HXCPP_CLASS_ATTRIBUTES SemanticVersionScore_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef SemanticVersionScore_Impl__obj OBJ_;
		SemanticVersionScore_Impl__obj();

	public:
		enum { _hx_ClassId = 0x4d5c95c3 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.util._SemanticVersion.SemanticVersionScore_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.util._SemanticVersion.SemanticVersionScore_Impl_"); }

		inline static ::hx::ObjectPtr< SemanticVersionScore_Impl__obj > __new() {
			::hx::ObjectPtr< SemanticVersionScore_Impl__obj > __this = new SemanticVersionScore_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< SemanticVersionScore_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			SemanticVersionScore_Impl__obj *__this = (SemanticVersionScore_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SemanticVersionScore_Impl__obj), false, "polymod.util._SemanticVersion.SemanticVersionScore_Impl_"));
			*(void **)__this = SemanticVersionScore_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SemanticVersionScore_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SemanticVersionScore_Impl_",00,04,09,a0); }

		static void __boot();
		static int NONE;
		static int MATCH_MAJOR;
		static int MATCH_MINOR;
		static int MATCH_PATCH;
		static int fromString(::String value);
		static ::Dynamic fromString_dyn();

};

} // end namespace polymod
} // end namespace util
} // end namespace _SemanticVersion

#endif /* INCLUDED_polymod_util__SemanticVersion_SemanticVersionScore_Impl_ */ 
