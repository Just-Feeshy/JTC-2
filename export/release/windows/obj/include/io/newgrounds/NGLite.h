#ifndef INCLUDED_io_newgrounds_NGLite
#define INCLUDED_io_newgrounds_NGLite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(io,newgrounds,Call)
HX_DECLARE_CLASS2(io,newgrounds,ICallable)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,components,ComponentList)
HX_DECLARE_CLASS3(io,newgrounds,utils,Dispatcher)

namespace io{
namespace newgrounds{


class HXCPP_CLASS_ATTRIBUTES NGLite_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef NGLite_obj OBJ_;
		NGLite_obj();

	public:
		enum { _hx_ClassId = 0x7772213d };

		void __construct(::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.NGLite")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.NGLite"); }
		static ::hx::ObjectPtr< NGLite_obj > __new(::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail);
		static ::hx::ObjectPtr< NGLite_obj > __alloc(::hx::Ctx *_hx_ctx,::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		static void __alloc_dynamic_functions(::hx::Ctx *_hx_alloc,NGLite_obj *_hx_obj);
		//~NGLite_obj();

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
		::String __ToString() const { return HX_("NGLite",07,9e,d5,43); }

		static void __boot();
		static  ::io::newgrounds::NGLite core;
		static  ::io::newgrounds::utils::Dispatcher onCoreReady;
		static void create(::String appId,::String sessionId, ::Dynamic onSessionFail);
		static ::Dynamic create_dyn();

		static void createAndCheckSession(::String appId,::String backupSession, ::Dynamic onSessionFail);
		static ::Dynamic createAndCheckSession_dyn();

		static ::String getUrl();
		static ::Dynamic getUrl_dyn();

		static ::String getSessionId();
		static ::Dynamic getSessionId_dyn();

		void queueCall_io_newgrounds_Call_T( ::io::newgrounds::Call call);
		::Dynamic queueCall_io_newgrounds_Call_T_dyn();

		void markCallPending_io_newgrounds_Call_T( ::io::newgrounds::Call call);
		::Dynamic markCallPending_io_newgrounds_Call_T_dyn();

		bool verbose;
		bool debug;
		::String appId;
		::String host;
		::String sessionId;
		::String set_sessionId(::String value);
		::Dynamic set_sessionId_dyn();

		 ::io::newgrounds::components::ComponentList calls;
		 ::Dynamic encryptionHandler;
		Dynamic encryptionHandler_dyn() { return encryptionHandler;}
		virtual void checkInitialSession( ::Dynamic onFail, ::Dynamic response);
		::Dynamic checkInitialSession_dyn();

		void initialSessionFail( ::Dynamic onFail, ::Dynamic error);
		::Dynamic initialSessionFail_dyn();

		::Array< ::Dynamic> _queuedCalls;
		::Array< ::Dynamic> _pendingCalls;
		void onCallComplete(::Dynamic call);
		::Dynamic onCallComplete_dyn();

		void checkQueue();
		::Dynamic checkQueue_dyn();

		::Dynamic log;
		inline ::Dynamic &log_dyn() {return log; }

		void logVerbose( ::Dynamic any, ::Dynamic pos);
		::Dynamic logVerbose_dyn();

		::Dynamic logError;
		inline ::Dynamic &logError_dyn() {return logError; }

		bool _hx_assert(bool condition, ::Dynamic msg, ::Dynamic pos);
		::Dynamic _hx_assert_dyn();

		void initEncryption(::String key,::String cipher,::String format);
		::Dynamic initEncryption_dyn();

		::String encryptRc4(::String key,::String format,::String data);
		::Dynamic encryptRc4_dyn();

};

} // end namespace io
} // end namespace newgrounds

#endif /* INCLUDED_io_newgrounds_NGLite */ 
