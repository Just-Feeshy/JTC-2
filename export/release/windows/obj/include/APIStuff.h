#ifndef INCLUDED_APIStuff
#define INCLUDED_APIStuff

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(APIStuff)



class HXCPP_CLASS_ATTRIBUTES APIStuff_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef APIStuff_obj OBJ_;
		APIStuff_obj();

	public:
		enum { _hx_ClassId = 0x276a66da };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="APIStuff")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"APIStuff"); }

		inline static ::hx::ObjectPtr< APIStuff_obj > __new() {
			::hx::ObjectPtr< APIStuff_obj > __this = new APIStuff_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< APIStuff_obj > __alloc(::hx::Ctx *_hx_ctx) {
			APIStuff_obj *__this = (APIStuff_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(APIStuff_obj), false, "APIStuff"));
			*(void **)__this = APIStuff_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~APIStuff_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("APIStuff",1a,74,d9,cb); }

		static void __boot();
		static ::String API;
		static ::String EncKey;
};


#endif /* INCLUDED_APIStuff */ 
