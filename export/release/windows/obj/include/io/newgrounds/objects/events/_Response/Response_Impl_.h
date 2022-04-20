#ifndef INCLUDED_io_newgrounds_objects_events__Response_Response_Impl_
#define INCLUDED_io_newgrounds_objects_events__Response_Response_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS5(io,newgrounds,objects,events,_Response,Response_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Response{


class HXCPP_CLASS_ATTRIBUTES Response_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Response_Impl__obj OBJ_;
		Response_Impl__obj();

	public:
		enum { _hx_ClassId = 0x6dc65aaa };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects.events._Response.Response_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects.events._Response.Response_Impl_"); }

		inline static ::hx::ObjectPtr< Response_Impl__obj > __new() {
			::hx::ObjectPtr< Response_Impl__obj > __this = new Response_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Response_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			Response_Impl__obj *__this = (Response_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Response_Impl__obj), false, "io.newgrounds.objects.events._Response.Response_Impl_"));
			*(void **)__this = Response_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Response_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Response_Impl_",01,d6,f2,34); }

		static bool get_success( ::Dynamic this1);
		static ::Dynamic get_success_dyn();

		static  ::Dynamic get_error( ::Dynamic this1);
		static ::Dynamic get_error_dyn();

		static  ::Dynamic get_debug( ::Dynamic this1);
		static ::Dynamic get_debug_dyn();

		static  ::Dynamic get_result( ::Dynamic this1);
		static ::Dynamic get_result_dyn();

		static ::String get_appId( ::Dynamic this1);
		static ::Dynamic get_appId_dyn();

		static  ::Dynamic _new( ::io::newgrounds::NGLite core,::String reply);
		static ::Dynamic _new_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Response

#endif /* INCLUDED_io_newgrounds_objects_events__Response_Response_Impl_ */ 
