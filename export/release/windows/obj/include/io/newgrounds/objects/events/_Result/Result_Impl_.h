#ifndef INCLUDED_io_newgrounds_objects_events__Result_Result_Impl_
#define INCLUDED_io_newgrounds_objects_events__Result_Result_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(io,newgrounds,objects,events,_Result,Result_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{


class HXCPP_CLASS_ATTRIBUTES Result_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Result_Impl__obj OBJ_;
		Result_Impl__obj();

	public:
		enum { _hx_ClassId = 0x16a5c722 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects.events._Result.Result_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects.events._Result.Result_Impl_"); }

		inline static ::hx::ObjectPtr< Result_Impl__obj > __new() {
			::hx::ObjectPtr< Result_Impl__obj > __this = new Result_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Result_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			Result_Impl__obj *__this = (Result_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Result_Impl__obj), false, "io.newgrounds.objects.events._Result.Result_Impl_"));
			*(void **)__this = Result_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Result_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Result_Impl_",5d,75,65,f6); }

		static ::String get_component( ::Dynamic this1);
		static ::Dynamic get_component_dyn();

		static ::String get_echo( ::Dynamic this1);
		static ::Dynamic get_echo_dyn();

		static  ::Dynamic get_data( ::Dynamic this1);
		static ::Dynamic get_data_dyn();

		static bool get_success( ::Dynamic this1);
		static ::Dynamic get_success_dyn();

		static bool get_debug( ::Dynamic this1);
		static ::Dynamic get_debug_dyn();

		static  ::Dynamic get_error( ::Dynamic this1);
		static ::Dynamic get_error_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result

#endif /* INCLUDED_io_newgrounds_objects_events__Result_Result_Impl_ */ 
