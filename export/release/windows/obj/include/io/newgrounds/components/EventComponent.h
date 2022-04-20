#ifndef INCLUDED_io_newgrounds_components_EventComponent
#define INCLUDED_io_newgrounds_components_EventComponent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
HX_DECLARE_CLASS2(io,newgrounds,Call)
HX_DECLARE_CLASS2(io,newgrounds,ICallable)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,components,Component)
HX_DECLARE_CLASS3(io,newgrounds,components,EventComponent)

namespace io{
namespace newgrounds{
namespace components{


class HXCPP_CLASS_ATTRIBUTES EventComponent_obj : public  ::io::newgrounds::components::Component_obj
{
	public:
		typedef  ::io::newgrounds::components::Component_obj super;
		typedef EventComponent_obj OBJ_;
		EventComponent_obj();

	public:
		enum { _hx_ClassId = 0x2609990b };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.components.EventComponent")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.components.EventComponent"); }
		static ::hx::ObjectPtr< EventComponent_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< EventComponent_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~EventComponent_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("EventComponent",63,c9,6e,c2); }

		 ::io::newgrounds::Call logEvent(::String eventName);
		::Dynamic logEvent_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace components

#endif /* INCLUDED_io_newgrounds_components_EventComponent */ 
