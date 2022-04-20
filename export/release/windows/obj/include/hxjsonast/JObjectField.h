#ifndef INCLUDED_hxjsonast_JObjectField
#define INCLUDED_hxjsonast_JObjectField

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxjsonast,JObjectField)
HX_DECLARE_CLASS1(hxjsonast,Json)
HX_DECLARE_CLASS1(hxjsonast,Position)

namespace hxjsonast{


class HXCPP_CLASS_ATTRIBUTES JObjectField_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef JObjectField_obj OBJ_;
		JObjectField_obj();

	public:
		enum { _hx_ClassId = 0x1d9ae6f7 };

		void __construct(::String name, ::hxjsonast::Position namePos, ::hxjsonast::Json value);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="hxjsonast.JObjectField")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"hxjsonast.JObjectField"); }
		static ::hx::ObjectPtr< JObjectField_obj > __new(::String name, ::hxjsonast::Position namePos, ::hxjsonast::Json value);
		static ::hx::ObjectPtr< JObjectField_obj > __alloc(::hx::Ctx *_hx_ctx,::String name, ::hxjsonast::Position namePos, ::hxjsonast::Json value);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~JObjectField_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("JObjectField",51,f9,4a,55); }

		::String name;
		 ::hxjsonast::Position namePos;
		 ::hxjsonast::Json value;
};

} // end namespace hxjsonast

#endif /* INCLUDED_hxjsonast_JObjectField */ 
