#ifndef INCLUDED_io_newgrounds_objects_events__Result_GetHostResult_Impl_
#define INCLUDED_io_newgrounds_objects_events__Result_GetHostResult_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(io,newgrounds,objects,events,_Result,GetHostResult_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{


class HXCPP_CLASS_ATTRIBUTES GetHostResult_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GetHostResult_Impl__obj OBJ_;
		GetHostResult_Impl__obj();

	public:
		enum { _hx_ClassId = 0x0fd64a1a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects.events._Result.GetHostResult_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects.events._Result.GetHostResult_Impl_"); }

		inline static ::hx::ObjectPtr< GetHostResult_Impl__obj > __new() {
			::hx::ObjectPtr< GetHostResult_Impl__obj > __this = new GetHostResult_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< GetHostResult_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			GetHostResult_Impl__obj *__this = (GetHostResult_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GetHostResult_Impl__obj), false, "io.newgrounds.objects.events._Result.GetHostResult_Impl_"));
			*(void **)__this = GetHostResult_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GetHostResult_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GetHostResult_Impl_",5b,a1,a9,a2); }

		static bool get_host_approved( ::Dynamic this1);
		static ::Dynamic get_host_approved_dyn();

		static bool get_hostApproved( ::Dynamic this1);
		static ::Dynamic get_hostApproved_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result

#endif /* INCLUDED_io_newgrounds_objects_events__Result_GetHostResult_Impl_ */ 
