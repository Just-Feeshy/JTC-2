#ifndef INCLUDED_io_newgrounds_components_GatewayComponent
#define INCLUDED_io_newgrounds_components_GatewayComponent

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
HX_DECLARE_CLASS3(io,newgrounds,components,GatewayComponent)

namespace io{
namespace newgrounds{
namespace components{


class HXCPP_CLASS_ATTRIBUTES GatewayComponent_obj : public  ::io::newgrounds::components::Component_obj
{
	public:
		typedef  ::io::newgrounds::components::Component_obj super;
		typedef GatewayComponent_obj OBJ_;
		GatewayComponent_obj();

	public:
		enum { _hx_ClassId = 0x017655e1 };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.components.GatewayComponent")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.components.GatewayComponent"); }
		static ::hx::ObjectPtr< GatewayComponent_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< GatewayComponent_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~GatewayComponent_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("GatewayComponent",39,4c,ca,65); }

		 ::io::newgrounds::Call getDatetime();
		::Dynamic getDatetime_dyn();

		 ::io::newgrounds::Call getVersion();
		::Dynamic getVersion_dyn();

		 ::io::newgrounds::Call ping();
		::Dynamic ping_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace components

#endif /* INCLUDED_io_newgrounds_components_GatewayComponent */ 
