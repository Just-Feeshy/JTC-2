#ifndef INCLUDED_SaveData
#define INCLUDED_SaveData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(SaveData)
HX_DECLARE_CLASS0(SaveType)



class HXCPP_CLASS_ATTRIBUTES SaveData_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef SaveData_obj OBJ_;
		SaveData_obj();

	public:
		enum { _hx_ClassId = 0x2b5f9ee7 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="SaveData")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"SaveData"); }

		inline static ::hx::ObjectPtr< SaveData_obj > __new() {
			::hx::ObjectPtr< SaveData_obj > __this = new SaveData_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< SaveData_obj > __alloc(::hx::Ctx *_hx_ctx) {
			SaveData_obj *__this = (SaveData_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(SaveData_obj), false, "SaveData"));
			*(void **)__this = SaveData_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~SaveData_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("SaveData",27,ac,ce,cf); }

		static void saveClient();
		static ::Dynamic saveClient_dyn();

		static  ::Dynamic getData( ::SaveType data);
		static ::Dynamic getData_dyn();

};


#endif /* INCLUDED_SaveData */ 
