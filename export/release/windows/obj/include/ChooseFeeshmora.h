#ifndef INCLUDED_ChooseFeeshmora
#define INCLUDED_ChooseFeeshmora

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(ChooseFeeshmora)
HX_DECLARE_CLASS0(JsonParser_28)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(json2object,reader,BaseParser)



class HXCPP_CLASS_ATTRIBUTES ChooseFeeshmora_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ChooseFeeshmora_obj OBJ_;
		ChooseFeeshmora_obj();

	public:
		enum { _hx_ClassId = 0x2e2748b5 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="ChooseFeeshmora")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"ChooseFeeshmora"); }

		inline static ::hx::ObjectPtr< ChooseFeeshmora_obj > __new() {
			::hx::ObjectPtr< ChooseFeeshmora_obj > __this = new ChooseFeeshmora_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< ChooseFeeshmora_obj > __alloc(::hx::Ctx *_hx_ctx) {
			ChooseFeeshmora_obj *__this = (ChooseFeeshmora_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ChooseFeeshmora_obj), false, "ChooseFeeshmora"));
			*(void **)__this = ChooseFeeshmora_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ChooseFeeshmora_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ChooseFeeshmora",75,63,00,62); }

		static void __boot();
		static  ::JsonParser_28 parser;
		static ::Array< ::String > avaiableColors;
		static  ::haxe::ds::StringMap chooseSkin;
		static void changeMapArray(::String switcher,int daGet);
		static ::Dynamic changeMapArray_dyn();

		static int getMapSize(::String switcher);
		static ::Dynamic getMapSize_dyn();

};


#endif /* INCLUDED_ChooseFeeshmora */ 
