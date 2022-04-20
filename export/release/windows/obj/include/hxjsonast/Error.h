#ifndef INCLUDED_hxjsonast_Error
#define INCLUDED_hxjsonast_Error

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(hxjsonast,Error)
HX_DECLARE_CLASS1(hxjsonast,Position)

namespace hxjsonast{


class HXCPP_CLASS_ATTRIBUTES Error_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Error_obj OBJ_;
		Error_obj();

	public:
		enum { _hx_ClassId = 0x7b10d16e };

		void __construct(::String message, ::hxjsonast::Position pos);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="hxjsonast.Error")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"hxjsonast.Error"); }
		static ::hx::ObjectPtr< Error_obj > __new(::String message, ::hxjsonast::Position pos);
		static ::hx::ObjectPtr< Error_obj > __alloc(::hx::Ctx *_hx_ctx,::String message, ::hxjsonast::Position pos);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Error_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Error",a8,3b,57,06); }

		::String message;
		 ::hxjsonast::Position pos;
};

} // end namespace hxjsonast

#endif /* INCLUDED_hxjsonast_Error */ 
