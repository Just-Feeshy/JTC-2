#ifndef INCLUDED_hxjsonast_Json
#define INCLUDED_hxjsonast_Json

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxjsonast,Json)
HX_DECLARE_CLASS1(hxjsonast,JsonValue)
HX_DECLARE_CLASS1(hxjsonast,Position)

namespace hxjsonast{


class HXCPP_CLASS_ATTRIBUTES Json_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Json_obj OBJ_;
		Json_obj();

	public:
		enum { _hx_ClassId = 0x1ae1950a };

		void __construct( ::hxjsonast::JsonValue value, ::hxjsonast::Position pos);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="hxjsonast.Json")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"hxjsonast.Json"); }
		static ::hx::ObjectPtr< Json_obj > __new( ::hxjsonast::JsonValue value, ::hxjsonast::Position pos);
		static ::hx::ObjectPtr< Json_obj > __alloc(::hx::Ctx *_hx_ctx, ::hxjsonast::JsonValue value, ::hxjsonast::Position pos);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Json_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Json",48,6e,41,31); }

		 ::hxjsonast::JsonValue value;
		 ::hxjsonast::Position pos;
};

} // end namespace hxjsonast

#endif /* INCLUDED_hxjsonast_Json */ 
