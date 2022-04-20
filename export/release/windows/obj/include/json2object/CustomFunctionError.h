#ifndef INCLUDED_json2object_CustomFunctionError
#define INCLUDED_json2object_CustomFunctionError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_da47e08bcf33f095_113_new)
HX_DECLARE_CLASS1(json2object,CustomFunctionError)

namespace json2object{


class HXCPP_CLASS_ATTRIBUTES CustomFunctionError_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef CustomFunctionError_obj OBJ_;
		CustomFunctionError_obj();

	public:
		enum { _hx_ClassId = 0x11805a7a };

		void __construct(::String message);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="json2object.CustomFunctionError")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"json2object.CustomFunctionError"); }

		inline static ::hx::ObjectPtr< CustomFunctionError_obj > __new(::String message) {
			::hx::ObjectPtr< CustomFunctionError_obj > __this = new CustomFunctionError_obj();
			__this->__construct(message);
			return __this;
		}

		inline static ::hx::ObjectPtr< CustomFunctionError_obj > __alloc(::hx::Ctx *_hx_ctx,::String message) {
			CustomFunctionError_obj *__this = (CustomFunctionError_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(CustomFunctionError_obj), true, "json2object.CustomFunctionError"));
			*(void **)__this = CustomFunctionError_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_da47e08bcf33f095_113_new)
HXDLIN( 113)		( ( ::json2object::CustomFunctionError)(__this) )->message = message;
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~CustomFunctionError_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("CustomFunctionError",ff,de,52,3c); }

		::String message;
};

} // end namespace json2object

#endif /* INCLUDED_json2object_CustomFunctionError */ 
