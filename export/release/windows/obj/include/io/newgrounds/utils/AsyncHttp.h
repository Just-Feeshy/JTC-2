#ifndef INCLUDED_io_newgrounds_utils_AsyncHttp
#define INCLUDED_io_newgrounds_utils_AsyncHttp

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS1(haxe,Timer)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,utils,AsyncHttp)
HX_DECLARE_CLASS3(sys,thread,_Thread,HaxeThread)

namespace io{
namespace newgrounds{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES AsyncHttp_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef AsyncHttp_obj OBJ_;
		AsyncHttp_obj();

	public:
		enum { _hx_ClassId = 0x4ff8ecc5 };

		void __construct( ::io::newgrounds::NGLite core);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.utils.AsyncHttp")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.utils.AsyncHttp"); }
		static ::hx::ObjectPtr< AsyncHttp_obj > __new( ::io::newgrounds::NGLite core);
		static ::hx::ObjectPtr< AsyncHttp_obj > __alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~AsyncHttp_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("AsyncHttp",c4,f4,76,14); }

		static void __boot();
		static ::String PATH;
		static void send( ::io::newgrounds::NGLite core,::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus);
		static ::Dynamic send_dyn();

		static void sendSync( ::io::newgrounds::NGLite core,::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus);
		static ::Dynamic sendSync_dyn();

		static ::Array< ::Dynamic> _deadPool;
		static ::Array< ::Dynamic> _livePool;
		static  ::haxe::ds::IntMap _map;
		static  ::haxe::Timer _timer;
		static int _count;
		static void sendAsync( ::io::newgrounds::NGLite core,::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus);
		static ::Dynamic sendAsync_dyn();

		static void startTimer();
		static ::Dynamic startTimer_dyn();

		static void stopTimer();
		static ::Dynamic stopTimer_dyn();

		static void update();
		static ::Dynamic update_dyn();

		static void sendThreaded();
		static ::Dynamic sendThreaded_dyn();

		 ::io::newgrounds::NGLite _core;
		int _key;
		 ::Dynamic _onData;
		Dynamic _onData_dyn() { return _onData;}
		 ::Dynamic _onError;
		Dynamic _onError_dyn() { return _onError;}
		 ::Dynamic _onStatus;
		Dynamic _onStatus_dyn() { return _onStatus;}
		 ::sys::thread::_Thread::HaxeThread _worker;
		void start(::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus);
		::Dynamic start_dyn();

		void handleMessage( ::Dynamic data);
		::Dynamic handleMessage_dyn();

		void cleanUp();
		::Dynamic cleanUp_dyn();

};

} // end namespace io
} // end namespace newgrounds
} // end namespace utils

#endif /* INCLUDED_io_newgrounds_utils_AsyncHttp */ 
