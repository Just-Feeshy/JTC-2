#ifndef INCLUDED_io_newgrounds_utils_TypedDispatcher
#define INCLUDED_io_newgrounds_utils_TypedDispatcher

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_930dd3809f5d6707_68_new)
HX_DECLARE_CLASS3(io,newgrounds,utils,TypedDispatcher)

namespace io{
namespace newgrounds{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES TypedDispatcher_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef TypedDispatcher_obj OBJ_;
		TypedDispatcher_obj();

	public:
		enum { _hx_ClassId = 0x49af1d52 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.utils.TypedDispatcher")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.utils.TypedDispatcher"); }

		inline static ::hx::ObjectPtr< TypedDispatcher_obj > __new() {
			::hx::ObjectPtr< TypedDispatcher_obj > __this = new TypedDispatcher_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< TypedDispatcher_obj > __alloc(::hx::Ctx *_hx_ctx) {
			TypedDispatcher_obj *__this = (TypedDispatcher_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TypedDispatcher_obj), true, "io.newgrounds.utils.TypedDispatcher"));
			*(void **)__this = TypedDispatcher_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_930dd3809f5d6707_68_new)
HXLINE(  70)		( ( ::io::newgrounds::utils::TypedDispatcher)(__this) )->_list = ::Array_obj< ::Dynamic>::__new();
HXLINE(  71)		( ( ::io::newgrounds::utils::TypedDispatcher)(__this) )->_once = ::Array_obj< ::Dynamic>::__new();
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~TypedDispatcher_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("TypedDispatcher",91,ae,cd,02); }

		::Array< ::Dynamic> _list;
		::Array< ::Dynamic> _once;
		bool add( ::Dynamic handler,::hx::Null< bool >  once);
		::Dynamic add_dyn();

		bool addOnce( ::Dynamic handler);
		::Dynamic addOnce_dyn();

		bool remove( ::Dynamic handler);
		::Dynamic remove_dyn();

		void dispatch( ::Dynamic arg);
		::Dynamic dispatch_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace utils

#endif /* INCLUDED_io_newgrounds_utils_TypedDispatcher */ 
