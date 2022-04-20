#ifndef INCLUDED_io_newgrounds_Call
#define INCLUDED_io_newgrounds_Call

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
#endif
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(io,newgrounds,Call)
HX_DECLARE_CLASS2(io,newgrounds,ICallable)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,utils,Dispatcher)
HX_DECLARE_CLASS3(io,newgrounds,utils,TypedDispatcher)

namespace io{
namespace newgrounds{


class HXCPP_CLASS_ATTRIBUTES Call_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Call_obj OBJ_;
		Call_obj();

	public:
		enum { _hx_ClassId = 0x23330310 };

		void __construct( ::io::newgrounds::NGLite core,::String component,::hx::Null< bool >  __o_requireSession,::hx::Null< bool >  __o_isSecure);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.Call")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.Call"); }
		static ::hx::ObjectPtr< Call_obj > __new( ::io::newgrounds::NGLite core,::String component,::hx::Null< bool >  __o_requireSession,::hx::Null< bool >  __o_isSecure);
		static ::hx::ObjectPtr< Call_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core,::String component,::hx::Null< bool >  __o_requireSession,::hx::Null< bool >  __o_isSecure);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Call_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		void *_hx_getInterface(int inHash);
		::String __ToString() const { return HX_("Call",be,44,93,2c); }

		::String component;
		 ::io::newgrounds::NGLite _core;
		 ::haxe::ds::StringMap _properties;
		 ::haxe::ds::StringMap _parameters;
		bool _requireSession;
		bool _isSecure;
		 ::io::newgrounds::utils::TypedDispatcher _dataHandlers;
		 ::io::newgrounds::utils::Dispatcher _successHandlers;
		 ::io::newgrounds::utils::TypedDispatcher _httpErrorHandlers;
		 ::io::newgrounds::utils::TypedDispatcher _statusHandlers;
		 ::io::newgrounds::Call addProperty(::String name, ::Dynamic value);
		::Dynamic addProperty_dyn();

		 ::io::newgrounds::Call addComponentParameter(::String name, ::Dynamic value, ::Dynamic defaultValue);
		::Dynamic addComponentParameter_dyn();

		 ::io::newgrounds::Call addDataHandler( ::Dynamic handler);
		::Dynamic addDataHandler_dyn();

		 ::io::newgrounds::Call addSuccessHandler( ::Dynamic handler);
		::Dynamic addSuccessHandler_dyn();

		 ::io::newgrounds::Call addErrorHandler( ::Dynamic handler);
		::Dynamic addErrorHandler_dyn();

		 ::io::newgrounds::Call addStatusHandler( ::Dynamic handler);
		::Dynamic addStatusHandler_dyn();

		void send();
		::Dynamic send_dyn();

		void queue();
		::Dynamic queue_dyn();

		void onData(::String reply);
		::Dynamic onData_dyn();

		void onHttpError(::String message);
		::Dynamic onHttpError_dyn();

		void onStatus(int status);
		::Dynamic onStatus_dyn();

		void destroy();
		::Dynamic destroy_dyn();

};

} // end namespace io
} // end namespace newgrounds

#endif /* INCLUDED_io_newgrounds_Call */ 
