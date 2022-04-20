#ifndef INCLUDED_polymod_hscript__PolymodAbstractScriptClass_PolymodAbstractScriptClass_Impl_
#define INCLUDED_polymod_hscript__PolymodAbstractScriptClass_PolymodAbstractScriptClass_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(polymod,hscript,PolymodScriptClass)
HX_DECLARE_CLASS3(polymod,hscript,_PolymodAbstractScriptClass,PolymodAbstractScriptClass_Impl_)

namespace polymod{
namespace hscript{
namespace _PolymodAbstractScriptClass{


class HXCPP_CLASS_ATTRIBUTES PolymodAbstractScriptClass_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PolymodAbstractScriptClass_Impl__obj OBJ_;
		PolymodAbstractScriptClass_Impl__obj();

	public:
		enum { _hx_ClassId = 0x3a7177cc };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_"); }

		inline static ::hx::ObjectPtr< PolymodAbstractScriptClass_Impl__obj > __new() {
			::hx::ObjectPtr< PolymodAbstractScriptClass_Impl__obj > __this = new PolymodAbstractScriptClass_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< PolymodAbstractScriptClass_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			PolymodAbstractScriptClass_Impl__obj *__this = (PolymodAbstractScriptClass_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PolymodAbstractScriptClass_Impl__obj), false, "polymod.hscript._PolymodAbstractScriptClass.PolymodAbstractScriptClass_Impl_"));
			*(void **)__this = PolymodAbstractScriptClass_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PolymodAbstractScriptClass_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PolymodAbstractScriptClass_Impl_",95,80,7a,ca); }

		static  ::Dynamic resolveField( ::polymod::hscript::PolymodScriptClass this1,::String name);
		static ::Dynamic resolveField_dyn();

		static  ::Dynamic fieldRead( ::polymod::hscript::PolymodScriptClass this1,::String name);
		static ::Dynamic fieldRead_dyn();

		static  ::Dynamic fieldWrite( ::polymod::hscript::PolymodScriptClass this1,::String name, ::Dynamic value);
		static ::Dynamic fieldWrite_dyn();

};

} // end namespace polymod
} // end namespace hscript
} // end namespace _PolymodAbstractScriptClass

#endif /* INCLUDED_polymod_hscript__PolymodAbstractScriptClass_PolymodAbstractScriptClass_Impl_ */ 
