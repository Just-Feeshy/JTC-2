#ifndef INCLUDED_io_newgrounds_objects_Object
#define INCLUDED_io_newgrounds_objects_Object

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,objects,Object)
HX_DECLARE_CLASS3(io,newgrounds,utils,Dispatcher)

namespace io{
namespace newgrounds{
namespace objects{


class HXCPP_CLASS_ATTRIBUTES Object_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Object_obj OBJ_;
		Object_obj();

	public:
		enum { _hx_ClassId = 0x596f3161 };

		void __construct( ::io::newgrounds::NGLite core, ::Dynamic data);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.objects.Object")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.objects.Object"); }
		static ::hx::ObjectPtr< Object_obj > __new( ::io::newgrounds::NGLite core, ::Dynamic data);
		static ::hx::ObjectPtr< Object_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core, ::Dynamic data);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Object_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Object",df,f2,d3,49); }

		 ::io::newgrounds::NGLite _core;
		 ::Dynamic _data;
		 ::io::newgrounds::utils::Dispatcher onUpdate;
		virtual void parse( ::Dynamic data);
		::Dynamic parse_dyn();

		void destroy();
		::Dynamic destroy_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace objects

#endif /* INCLUDED_io_newgrounds_objects_Object */ 
