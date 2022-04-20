#ifndef INCLUDED_io_newgrounds_components_AppComponent
#define INCLUDED_io_newgrounds_components_AppComponent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
HX_DECLARE_CLASS2(io,newgrounds,Call)
HX_DECLARE_CLASS2(io,newgrounds,ICallable)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,components,AppComponent)
HX_DECLARE_CLASS3(io,newgrounds,components,Component)

namespace io{
namespace newgrounds{
namespace components{


class HXCPP_CLASS_ATTRIBUTES AppComponent_obj : public  ::io::newgrounds::components::Component_obj
{
	public:
		typedef  ::io::newgrounds::components::Component_obj super;
		typedef AppComponent_obj OBJ_;
		AppComponent_obj();

	public:
		enum { _hx_ClassId = 0x22730f08 };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.components.AppComponent")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.components.AppComponent"); }
		static ::hx::ObjectPtr< AppComponent_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< AppComponent_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~AppComponent_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("AppComponent",fc,03,a5,e4); }

		 ::io::newgrounds::Call startSession(::hx::Null< bool >  force);
		::Dynamic startSession_dyn();

		 ::io::newgrounds::Call checkSession();
		::Dynamic checkSession_dyn();

		 ::io::newgrounds::Call endSession();
		::Dynamic endSession_dyn();

		 ::io::newgrounds::Call getCurrentVersion(::String version);
		::Dynamic getCurrentVersion_dyn();

		 ::io::newgrounds::Call getHostLicense();
		::Dynamic getHostLicense_dyn();

		 ::io::newgrounds::Call logView();
		::Dynamic logView_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace components

#endif /* INCLUDED_io_newgrounds_components_AppComponent */ 
