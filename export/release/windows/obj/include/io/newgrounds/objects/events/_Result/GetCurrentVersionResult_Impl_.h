#ifndef INCLUDED_io_newgrounds_objects_events__Result_GetCurrentVersionResult_Impl_
#define INCLUDED_io_newgrounds_objects_events__Result_GetCurrentVersionResult_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS5(io,newgrounds,objects,events,_Result,GetCurrentVersionResult_Impl_)

namespace io{
namespace newgrounds{
namespace objects{
namespace events{
namespace _Result{


class HXCPP_CLASS_ATTRIBUTES GetCurrentVersionResult_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef GetCurrentVersionResult_Impl__obj OBJ_;
		GetCurrentVersionResult_Impl__obj();

	public:
		enum { _hx_ClassId = 0x225522a5 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_"); }

		inline static ::hx::ObjectPtr< GetCurrentVersionResult_Impl__obj > __new() {
			::hx::ObjectPtr< GetCurrentVersionResult_Impl__obj > __this = new GetCurrentVersionResult_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< GetCurrentVersionResult_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			GetCurrentVersionResult_Impl__obj *__this = (GetCurrentVersionResult_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GetCurrentVersionResult_Impl__obj), false, "io.newgrounds.objects.events._Result.GetCurrentVersionResult_Impl_"));
			*(void **)__this = GetCurrentVersionResult_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GetCurrentVersionResult_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GetCurrentVersionResult_Impl_",d2,5b,a4,7b); }

		static ::String get_current_version( ::Dynamic this1);
		static ::Dynamic get_current_version_dyn();

		static ::String get_currentVersion( ::Dynamic this1);
		static ::Dynamic get_currentVersion_dyn();

		static bool get_client_deprecated( ::Dynamic this1);
		static ::Dynamic get_client_deprecated_dyn();

		static bool get_clientDeprecated( ::Dynamic this1);
		static ::Dynamic get_clientDeprecated_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects
} // end namespace events
} // end namespace _Result

#endif /* INCLUDED_io_newgrounds_objects_events__Result_GetCurrentVersionResult_Impl_ */ 
