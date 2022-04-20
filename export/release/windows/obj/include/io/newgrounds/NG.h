#ifndef INCLUDED_io_newgrounds_NG
#define INCLUDED_io_newgrounds_NG

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(io,newgrounds,NG)
HX_DECLARE_CLASS2(io,newgrounds,NGLite)
HX_DECLARE_CLASS3(io,newgrounds,utils,Dispatcher)

namespace io{
namespace newgrounds{


class HXCPP_CLASS_ATTRIBUTES NG_obj : public  ::io::newgrounds::NGLite_obj
{
	public:
		typedef  ::io::newgrounds::NGLite_obj super;
		typedef NG_obj OBJ_;
		NG_obj();

	public:
		enum { _hx_ClassId = 0x62957ed3 };

		void __construct(::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="io.newgrounds.NG")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"io.newgrounds.NG"); }
		static ::hx::ObjectPtr< NG_obj > __new(::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail);
		static ::hx::ObjectPtr< NG_obj > __alloc(::hx::Ctx *_hx_ctx,::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~NG_obj();

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
		::String __ToString() const { return HX_("NG",39,44,00,00); }

		static void __boot();
		static  ::io::newgrounds::NG core;
		static  ::io::newgrounds::utils::Dispatcher onCoreReady;
		static void create(::String appId,::String sessionId,::hx::Null< bool >  debug, ::Dynamic onSessionFail);
		static ::Dynamic create_dyn();

		static void createAndCheckSession(::String appId,::hx::Null< bool >  debug,::String backupSession, ::Dynamic onSessionFail);
		static ::Dynamic createAndCheckSession_dyn();

		static  ::EReg urlParser;
		static ::String getHost();
		static ::Dynamic getHost_dyn();

		 ::Dynamic get_user();
		::Dynamic get_user_dyn();

		::String get_passportUrl();
		::Dynamic get_passportUrl_dyn();

		 ::haxe::ds::IntMap medals;
		 ::haxe::ds::IntMap scoreBoards;
		 ::io::newgrounds::utils::Dispatcher onLogin;
		 ::io::newgrounds::utils::Dispatcher onLogOut;
		 ::io::newgrounds::utils::Dispatcher onMedalsLoaded;
		 ::io::newgrounds::utils::Dispatcher onScoreBoardsLoaded;
		bool loggedIn;
		bool attemptingLogin;
		bool _loginCancelled;
		 ::Dynamic _passportCallback;
		Dynamic _passportCallback_dyn() { return _passportCallback;}
		 ::Dynamic _session;
		void checkInitialSession( ::Dynamic failHandler, ::Dynamic response);

		void requestLogin( ::Dynamic onSuccess, ::Dynamic onPending, ::Dynamic onFail, ::Dynamic onCancel);
		::Dynamic requestLogin_dyn();

		void onSessionReceive( ::Dynamic response, ::Dynamic onSuccess, ::Dynamic onPending, ::Dynamic onFail, ::Dynamic onCancel);
		::Dynamic onSessionReceive_dyn();

		void openPassportUrl();
		::Dynamic openPassportUrl_dyn();

		void openPassportHelper(::String url);
		::Dynamic openPassportHelper_dyn();

		void onPassportUrlOpen();
		::Dynamic onPassportUrlOpen_dyn();

		void dispatchPassportCallback();
		::Dynamic dispatchPassportCallback_dyn();

		void checkSession( ::Dynamic response, ::Dynamic onSuccess, ::Dynamic onCancel);
		::Dynamic checkSession_dyn();

		void cancelLoginRequest();
		::Dynamic cancelLoginRequest_dyn();

		void endLoginAndCall( ::Dynamic callback);
		::Dynamic endLoginAndCall_dyn();

		void logOut( ::Dynamic onComplete);
		::Dynamic logOut_dyn();

		void onLogOutSuccessful();
		::Dynamic onLogOutSuccessful_dyn();

		void requestMedals( ::Dynamic onSuccess, ::Dynamic onFail);
		::Dynamic requestMedals_dyn();

		void onMedalsReceived( ::Dynamic response);
		::Dynamic onMedalsReceived_dyn();

		void requestScoreBoards( ::Dynamic onSuccess, ::Dynamic onFail);
		::Dynamic requestScoreBoards_dyn();

		void onBoardsReceived( ::Dynamic response);
		::Dynamic onBoardsReceived_dyn();

		void timer(Float delay, ::Dynamic callback);
		::Dynamic timer_dyn();

};

} // end namespace io
} // end namespace newgrounds

#endif /* INCLUDED_io_newgrounds_NG */ 
