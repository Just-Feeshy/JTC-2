#ifndef INCLUDED_io_newgrounds_components_ComponentList
#define INCLUDED_io_newgrounds_components_ComponentList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,components,AppComponent)
HX_DECLARE_CLASS3(io,newgrounds,components,Component)
HX_DECLARE_CLASS3(io,newgrounds,components,ComponentList)
HX_DECLARE_CLASS3(io,newgrounds,components,EventComponent)
HX_DECLARE_CLASS3(io,newgrounds,components,GatewayComponent)
HX_DECLARE_CLASS3(io,newgrounds,components,LoaderComponent)
HX_DECLARE_CLASS3(io,newgrounds,components,MedalComponent)
HX_DECLARE_CLASS3(io,newgrounds,components,ScoreBoardComponent)

namespace io{
namespace newgrounds{
namespace components{


class HXCPP_CLASS_ATTRIBUTES ComponentList_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ComponentList_obj OBJ_;
		ComponentList_obj();

	public:
		enum { _hx_ClassId = 0x63ab08f3 };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.components.ComponentList")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.components.ComponentList"); }
		static ::hx::ObjectPtr< ComponentList_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< ComponentList_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ComponentList_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ComponentList",9b,2b,44,2d); }

		 ::io::newgrounds::NGLite _core;
		 ::io::newgrounds::components::MedalComponent medal;
		 ::io::newgrounds::components::AppComponent app;
		 ::io::newgrounds::components::EventComponent event;
		 ::io::newgrounds::components::ScoreBoardComponent scoreBoard;
		 ::io::newgrounds::components::LoaderComponent loader;
		 ::io::newgrounds::components::GatewayComponent gateway;
};

} // end namespace io
} // end namespace newgrounds
} // end namespace components

#endif /* INCLUDED_io_newgrounds_components_ComponentList */ 
