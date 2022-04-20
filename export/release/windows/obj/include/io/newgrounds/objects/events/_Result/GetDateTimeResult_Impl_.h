#ifndef INCLUDED_io_newgrounds_objects_events__Result_GetDateTimeResult_Impl_
#define INCLUDED_io_newgrounds_objects_events__Result_GetDateTimeResult_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(io,newgrounds,objects,events,_Result,GetDateTimeResult_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{


class HXCPP_CLASS_ATTRIBUTES GetDateTimeResult_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GetDateTimeResult_Impl__obj OBJ_;
		GetDateTimeResult_Impl__obj();

	public:
		enum { _hx_ClassId = 0x66b21d29 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_"); }

		inline static ::hx::ObjectPtr< GetDateTimeResult_Impl__obj > __new() {
			::hx::ObjectPtr< GetDateTimeResult_Impl__obj > __this = new GetDateTimeResult_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< GetDateTimeResult_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			GetDateTimeResult_Impl__obj *__this = (GetDateTimeResult_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GetDateTimeResult_Impl__obj), false, "io.newgrounds.objects.events._Result.GetDateTimeResult_Impl_"));
			*(void **)__this = GetDateTimeResult_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GetDateTimeResult_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GetDateTimeResult_Impl_",ce,72,f3,f4); }

		static ::String get_datetime( ::Dynamic this1);
		static ::Dynamic get_datetime_dyn();

		static ::String get_dateTime( ::Dynamic this1);
		static ::Dynamic get_dateTime_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result

#endif /* INCLUDED_io_newgrounds_objects_events__Result_GetDateTimeResult_Impl_ */ 
