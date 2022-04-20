#ifndef INCLUDED_Mod
#define INCLUDED_Mod

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Mod)



class HXCPP_CLASS_ATTRIBUTES Mod_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Mod_obj OBJ_;
		Mod_obj();

	public:
		enum { _hx_ClassId = 0x7edf1336 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="Mod")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"Mod"); }

		inline static ::hx::ObjectPtr< Mod_obj > __new() {
			::hx::ObjectPtr< Mod_obj > __this = new Mod_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Mod_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Mod_obj *__this = (Mod_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Mod_obj), false, "Mod"));
			*(void **)__this = Mod_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Mod_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Mod",a2,ce,3a,00); }

		static void onInit();
		static ::Dynamic onInit_dyn();

};


#endif /* INCLUDED_Mod */ 
