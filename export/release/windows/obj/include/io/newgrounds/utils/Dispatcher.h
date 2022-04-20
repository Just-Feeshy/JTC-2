#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#define INCLUDED_io_newgrounds_utils_Dispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_50ed06ee64fb384d_11_new)
HX_DECLARE_CLASS3(io,newgrounds,utils,Dispatcher)

namespace io{
namespace newgrounds{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES Dispatcher_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Dispatcher_obj OBJ_;
		Dispatcher_obj();

	public:
		enum { _hx_ClassId = 0x26e8d6a6 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.utils.Dispatcher")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.utils.Dispatcher"); }

		inline static ::hx::ObjectPtr< Dispatcher_obj > __new() {
			::hx::ObjectPtr< Dispatcher_obj > __this = new Dispatcher_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< Dispatcher_obj > __alloc(::hx::Ctx *_hx_ctx) {
			Dispatcher_obj *__this = (Dispatcher_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Dispatcher_obj), true, "io.newgrounds.utils.Dispatcher"));
			*(void **)__this = Dispatcher_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_50ed06ee64fb384d_11_new)
HXLINE(  13)		( ( ::io::newgrounds::utils::Dispatcher)(__this) )->_list = ::Array_obj< ::Dynamic>::__new();
HXLINE(  14)		( ( ::io::newgrounds::utils::Dispatcher)(__this) )->_once = ::Array_obj< ::Dynamic>::__new();
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Dispatcher_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Dispatcher",c7,cd,b1,50); }

		::Array< ::Dynamic> _list;
		::Array< ::Dynamic> _once;
		bool add( ::Dynamic handler,::hx::Null< bool >  once);
		::Dynamic add_dyn();

		bool addOnce( ::Dynamic handler);
		::Dynamic addOnce_dyn();

		bool remove( ::Dynamic handler);
		::Dynamic remove_dyn();

		void dispatch();
		::Dynamic dispatch_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace utils

#endif /* INCLUDED_io_newgrounds_utils_Dispatcher */ 
