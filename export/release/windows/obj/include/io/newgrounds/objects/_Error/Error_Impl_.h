#ifndef INCLUDED_io_newgrounds_objects__Error_Error_Impl_
#define INCLUDED_io_newgrounds_objects__Error_Error_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(io,newgrounds,objects,_Error,Error_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace _Error{


class HXCPP_CLASS_ATTRIBUTES Error_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Error_Impl__obj OBJ_;
		Error_Impl__obj();

	public:
		enum { _hx_ClassId = 0x795ac969 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects._Error.Error_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects._Error.Error_Impl_"); }

		inline static ::hx::ObjectPtr< Error_Impl__obj > __new() {
			::hx::ObjectPtr< Error_Impl__obj > __this = new Error_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Error_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			Error_Impl__obj *__this = (Error_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Error_Impl__obj), false, "io.newgrounds.objects._Error.Error_Impl_"));
			*(void **)__this = Error_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Error_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Error_Impl_",48,a6,94,ea); }

		static  ::Dynamic get_code( ::Dynamic this1);
		static ::Dynamic get_code_dyn();

		static ::String get_message( ::Dynamic this1);
		static ::Dynamic get_message_dyn();

		static  ::Dynamic _new(::String message, ::Dynamic code);
		static ::Dynamic _new_dyn();

		static ::String toString( ::Dynamic this1);
		static ::Dynamic toString_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace _Error

#endif /* INCLUDED_io_newgrounds_objects__Error_Error_Impl_ */ 
