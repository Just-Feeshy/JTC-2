#ifndef INCLUDED_json2object_JsonParser
#define INCLUDED_json2object_JsonParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(json2object,JsonParser)

namespace json2object{


class HXCPP_CLASS_ATTRIBUTES JsonParser_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef JsonParser_obj OBJ_;
		JsonParser_obj();

	public:
		enum { _hx_ClassId = 0x49aa452c };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="json2object.JsonParser")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"json2object.JsonParser"); }

		inline static ::hx::ObjectPtr< JsonParser_obj > __new() {
			::hx::ObjectPtr< JsonParser_obj > __this = new JsonParser_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< JsonParser_obj > __alloc(::hx::Ctx *_hx_ctx) {
			JsonParser_obj *__this = (JsonParser_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(JsonParser_obj), false, "json2object.JsonParser"));
			*(void **)__this = JsonParser_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~JsonParser_obj();

		HX_DO_RTTI_ALL;
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("JsonParser",47,65,2e,25); }

};

} // end namespace json2object

#endif /* INCLUDED_json2object_JsonParser */ 
