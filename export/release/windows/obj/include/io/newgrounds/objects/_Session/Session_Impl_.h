#ifndef INCLUDED_io_newgrounds_objects__Session_Session_Impl_
#define INCLUDED_io_newgrounds_objects__Session_Session_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(io,newgrounds,objects,_Session,Session_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace _Session{


class HXCPP_CLASS_ATTRIBUTES Session_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Session_Impl__obj OBJ_;
		Session_Impl__obj();

	public:
		enum { _hx_ClassId = 0x7406ecc5 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects._Session.Session_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects._Session.Session_Impl_"); }

		inline static ::hx::ObjectPtr< Session_Impl__obj > __new() {
			::hx::ObjectPtr< Session_Impl__obj > __this = new Session_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Session_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			Session_Impl__obj *__this = (Session_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Session_Impl__obj), false, "io.newgrounds.objects._Session.Session_Impl_"));
			*(void **)__this = Session_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Session_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Session_Impl_",56,c8,f2,4f); }

		static ::String get_passportUrl( ::Dynamic this1);
		static ::Dynamic get_passportUrl_dyn();

		static ::String get_passport_url( ::Dynamic this1);
		static ::Dynamic get_passport_url_dyn();

		static ::String get_status( ::Dynamic this1);
		static ::Dynamic get_status_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace _Session

#endif /* INCLUDED_io_newgrounds_objects__Session_Session_Impl_ */ 
