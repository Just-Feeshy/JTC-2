#ifndef INCLUDED_io_newgrounds_components_LoaderComponent
#define INCLUDED_io_newgrounds_components_LoaderComponent

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
HX_DECLARE_CLASS3(io,newgrounds,components,LoaderComponent)

namespace io{
namespace newgrounds{
namespace components{


class HXCPP_CLASS_ATTRIBUTES LoaderComponent_obj : public  ::io::newgrounds::components::Component_obj
{
	public:
		typedef  ::io::newgrounds::components::Component_obj super;
		typedef LoaderComponent_obj OBJ_;
		LoaderComponent_obj();

	public:
		enum { _hx_ClassId = 0x0edada7e };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.components.LoaderComponent")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.components.LoaderComponent"); }
		static ::hx::ObjectPtr< LoaderComponent_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< LoaderComponent_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~LoaderComponent_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("LoaderComponent",0a,76,a1,ea); }

		 ::io::newgrounds::Call loadAuthorUrl(::hx::Null< bool >  redirect);
		::Dynamic loadAuthorUrl_dyn();

		 ::io::newgrounds::Call loadMoreGames(::hx::Null< bool >  redirect);
		::Dynamic loadMoreGames_dyn();

		 ::io::newgrounds::Call loadNewgrounds(::hx::Null< bool >  redirect);
		::Dynamic loadNewgrounds_dyn();

		 ::io::newgrounds::Call loadOfficialUrl(::hx::Null< bool >  redirect);
		::Dynamic loadOfficialUrl_dyn();

		 ::io::newgrounds::Call loadReferral(::hx::Null< bool >  redirect);
		::Dynamic loadReferral_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace components

#endif /* INCLUDED_io_newgrounds_components_LoaderComponent */ 
