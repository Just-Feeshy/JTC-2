#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_http_HttpBase
#include <haxe/http/HttpBase.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_AsyncHttp
#include <io/newgrounds/utils/AsyncHttp.h>
#endif
#ifndef INCLUDED_sys_Http
#include <sys/Http.h>
#endif
#ifndef INCLUDED_sys_thread_Deque
#include <sys/thread/Deque.h>
#endif
#ifndef INCLUDED_sys_thread__Thread_HaxeThread
#include <sys/thread/_Thread/HaxeThread.h>
#endif
#ifndef INCLUDED_sys_thread__Thread_Thread_Impl_
#include <sys/thread/_Thread/Thread_Impl_.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_484b684992387090_76_new,"io.newgrounds.utils.AsyncHttp","new",0xff573e7f,"io.newgrounds.utils.AsyncHttp.new","io/newgrounds/utils/AsyncHttp.hx",76,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_85_start,"io.newgrounds.utils.AsyncHttp","start",0xdd5de841,"io.newgrounds.utils.AsyncHttp.start","io/newgrounds/utils/AsyncHttp.hx",85,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_101_handleMessage,"io.newgrounds.utils.AsyncHttp","handleMessage",0xe04e09de,"io.newgrounds.utils.AsyncHttp.handleMessage","io/newgrounds/utils/AsyncHttp.hx",101,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_116_handleMessage,"io.newgrounds.utils.AsyncHttp","handleMessage",0xe04e09de,"io.newgrounds.utils.AsyncHttp.handleMessage","io/newgrounds/utils/AsyncHttp.hx",116,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_121_handleMessage,"io.newgrounds.utils.AsyncHttp","handleMessage",0xe04e09de,"io.newgrounds.utils.AsyncHttp.handleMessage","io/newgrounds/utils/AsyncHttp.hx",121,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_130_cleanUp,"io.newgrounds.utils.AsyncHttp","cleanUp",0xd50059e3,"io.newgrounds.utils.AsyncHttp.cleanUp","io/newgrounds/utils/AsyncHttp.hx",130,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_33_send,"io.newgrounds.utils.AsyncHttp","send",0x704d7a49,"io.newgrounds.utils.AsyncHttp.send","io/newgrounds/utils/AsyncHttp.hx",33,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_50_sendSync,"io.newgrounds.utils.AsyncHttp","sendSync",0x3d0bb944,"io.newgrounds.utils.AsyncHttp.sendSync","io/newgrounds/utils/AsyncHttp.hx",50,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_148_sendAsync,"io.newgrounds.utils.AsyncHttp","sendAsync",0xcc110c33,"io.newgrounds.utils.AsyncHttp.sendAsync","io/newgrounds/utils/AsyncHttp.hx",148,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_159_startTimer,"io.newgrounds.utils.AsyncHttp","startTimer",0xfdcebbc4,"io.newgrounds.utils.AsyncHttp.startTimer","io/newgrounds/utils/AsyncHttp.hx",159,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_168_stopTimer,"io.newgrounds.utils.AsyncHttp","stopTimer",0x05db47c2,"io.newgrounds.utils.AsyncHttp.stopTimer","io/newgrounds/utils/AsyncHttp.hx",168,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_174_update,"io.newgrounds.utils.AsyncHttp","update",0x55d8754a,"io.newgrounds.utils.AsyncHttp.update","io/newgrounds/utils/AsyncHttp.hx",174,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_183_sendThreaded,"io.newgrounds.utils.AsyncHttp","sendThreaded",0xde05c112,"io.newgrounds.utils.AsyncHttp.sendThreaded","io/newgrounds/utils/AsyncHttp.hx",183,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_191_sendThreaded,"io.newgrounds.utils.AsyncHttp","sendThreaded",0xde05c112,"io.newgrounds.utils.AsyncHttp.sendThreaded","io/newgrounds/utils/AsyncHttp.hx",191,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_192_sendThreaded,"io.newgrounds.utils.AsyncHttp","sendThreaded",0xde05c112,"io.newgrounds.utils.AsyncHttp.sendThreaded","io/newgrounds/utils/AsyncHttp.hx",192,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_193_sendThreaded,"io.newgrounds.utils.AsyncHttp","sendThreaded",0xde05c112,"io.newgrounds.utils.AsyncHttp.sendThreaded","io/newgrounds/utils/AsyncHttp.hx",193,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_25_boot,"io.newgrounds.utils.AsyncHttp","boot",0x65187133,"io.newgrounds.utils.AsyncHttp.boot","io/newgrounds/utils/AsyncHttp.hx",25,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_62_boot,"io.newgrounds.utils.AsyncHttp","boot",0x65187133,"io.newgrounds.utils.AsyncHttp.boot","io/newgrounds/utils/AsyncHttp.hx",62,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_63_boot,"io.newgrounds.utils.AsyncHttp","boot",0x65187133,"io.newgrounds.utils.AsyncHttp.boot","io/newgrounds/utils/AsyncHttp.hx",63,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_64_boot,"io.newgrounds.utils.AsyncHttp","boot",0x65187133,"io.newgrounds.utils.AsyncHttp.boot","io/newgrounds/utils/AsyncHttp.hx",64,0x570428f2)
HX_LOCAL_STACK_FRAME(_hx_pos_484b684992387090_67_boot,"io.newgrounds.utils.AsyncHttp","boot",0x65187133,"io.newgrounds.utils.AsyncHttp.boot","io/newgrounds/utils/AsyncHttp.hx",67,0x570428f2)
namespace io{
namespace newgrounds{
namespace utils{

void AsyncHttp_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_76_new)
HXLINE(  78)		this->_core = core;
HXLINE(  79)		this->_worker = ::sys::thread::_Thread::HaxeThread_obj::create(::io::newgrounds::utils::AsyncHttp_obj::sendThreaded_dyn(),false);
HXLINE(  80)		this->_key = ::io::newgrounds::utils::AsyncHttp_obj::_count++;
HXLINE(  81)		::io::newgrounds::utils::AsyncHttp_obj::_map->set(this->_key,::hx::ObjectPtr<OBJ_>(this));
HXLINE(  82)		{
HXLINE(  82)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN(  82)			if (_this->verbose) {
HXLINE(  82)				_this->log((HX_("async http created: ",5a,00,07,df) + this->_key),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),82,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("new",60,d0,53,00)));
            			}
            		}
            	}

Dynamic AsyncHttp_obj::__CreateEmpty() { return new AsyncHttp_obj; }

void *AsyncHttp_obj::_hx_vtable = 0;

Dynamic AsyncHttp_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< AsyncHttp_obj > _hx_result = new AsyncHttp_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool AsyncHttp_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4ff8ecc5;
}

void AsyncHttp_obj::start(::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_85_start)
HXLINE(  87)		{
HXLINE(  87)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN(  87)			if (_this->verbose) {
HXLINE(  87)				_this->log((HX_("async http started: ",f3,bb,3d,a6) + this->_key),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),87,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("start",62,74,0b,84)));
            			}
            		}
HXLINE(  89)		if ((::io::newgrounds::utils::AsyncHttp_obj::_livePool->length == 0)) {
HXLINE(  90)			::io::newgrounds::utils::AsyncHttp_obj::startTimer();
            		}
HXLINE(  92)		::io::newgrounds::utils::AsyncHttp_obj::_deadPool->remove(::hx::ObjectPtr<OBJ_>(this));
HXLINE(  93)		::io::newgrounds::utils::AsyncHttp_obj::_livePool->push(::hx::ObjectPtr<OBJ_>(this));
HXLINE(  95)		this->_onData = onData;
HXLINE(  96)		this->_onError = onError;
HXLINE(  97)		this->_onStatus = onStatus;
HXLINE(  98)		{
HXLINE(  98)			 ::sys::thread::_Thread::HaxeThread this1 = this->_worker;
HXDLIN(  98)			 ::Dynamic msg =  ::Dynamic(::hx::Anon_obj::Create(4)
            				->setFixed(0,HX_("key",9f,89,51,00),this->_key)
            				->setFixed(1,HX_("source",db,b0,31,32),::sys::thread::_Thread::HaxeThread_obj::current())
            				->setFixed(2,HX_("args",5d,8d,74,40),data)
            				->setFixed(3,HX_("core",5f,bd,c4,41),this->_core));
HXDLIN(  98)			this1->messages->add(msg);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC4(AsyncHttp_obj,start,(void))

void AsyncHttp_obj::handleMessage( ::Dynamic data){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_101_handleMessage)
HXLINE( 103)		{
HXLINE( 103)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 103)			if (_this->verbose) {
HXLINE( 103)				_this->log((HX_("handling message: ",32,3b,37,e9) + this->_key),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),103,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("handleMessage",ff,1e,86,b2)));
            			}
            		}
HXLINE( 105)		if (::hx::IsNotNull( data->__Field(HX_("status",32,e7,fb,05),::hx::paccDynamic) )) {
HXLINE( 107)			{
HXLINE( 107)				 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 107)				if (_this->verbose) {
HXLINE( 107)					_this->log( ::Dynamic((HX_("\t- status: ",f4,c1,3f,1d) + data->__Field(HX_("status",32,e7,fb,05),::hx::paccDynamic))),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),107,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("handleMessage",ff,1e,86,b2)));
            				}
            			}
HXLINE( 108)			this->_onStatus(( (int)(data->__Field(HX_("status",32,e7,fb,05),::hx::paccDynamic)) ));
HXLINE( 109)			return;
            		}
HXLINE( 112)		 ::Dynamic tempFunc;
HXLINE( 113)		if (::hx::IsNotNull( data->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic) )) {
            			HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_0,::String,a1, ::Dynamic,_g) HXARGC(0)
            			void _hx_run(){
            				HX_STACKFRAME(&_hx_pos_484b684992387090_116_handleMessage)
HXLINE( 116)				_g(a1);
            			}
            			HX_END_LOCAL_FUNC0((void))

HXLINE( 115)			{
HXLINE( 115)				 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 115)				if (_this->verbose) {
HXLINE( 115)					_this->log(HX_("\t- data",c6,4f,86,23),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),115,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("handleMessage",ff,1e,86,b2)));
            				}
            			}
HXLINE( 116)			 ::Dynamic _g = this->_onData;
HXDLIN( 116)			::String a1 = ( (::String)(data->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic)) );
HXDLIN( 116)			tempFunc =  ::Dynamic(new _hx_Closure_0(a1,_g));
            		}
            		else {
            			HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_1,::String,a1, ::Dynamic,_g) HXARGC(0)
            			void _hx_run(){
            				HX_STACKFRAME(&_hx_pos_484b684992387090_121_handleMessage)
HXLINE( 121)				_g(a1);
            			}
            			HX_END_LOCAL_FUNC0((void))

HXLINE( 120)			{
HXLINE( 120)				 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 120)				if (_this->verbose) {
HXLINE( 120)					_this->log(HX_("\t- error",ac,3a,a1,90),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),120,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("handleMessage",ff,1e,86,b2)));
            				}
            			}
HXLINE( 121)			 ::Dynamic _g = this->_onError;
HXDLIN( 121)			::String a1 = ( (::String)(data->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic)) );
HXDLIN( 121)			tempFunc =  ::Dynamic(new _hx_Closure_1(a1,_g));
            		}
HXLINE( 124)		{
HXLINE( 124)			this->_onData = null();
HXDLIN( 124)			this->_onError = null();
HXDLIN( 124)			::io::newgrounds::utils::AsyncHttp_obj::_deadPool->push(::hx::ObjectPtr<OBJ_>(this));
HXDLIN( 124)			::io::newgrounds::utils::AsyncHttp_obj::_livePool->remove(::hx::ObjectPtr<OBJ_>(this));
HXDLIN( 124)			if ((::io::newgrounds::utils::AsyncHttp_obj::_livePool->length == 0)) {
HXLINE( 124)				::io::newgrounds::utils::AsyncHttp_obj::stopTimer();
            			}
            		}
HXLINE( 127)		tempFunc();
            	}


HX_DEFINE_DYNAMIC_FUNC1(AsyncHttp_obj,handleMessage,(void))

void AsyncHttp_obj::cleanUp(){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_130_cleanUp)
HXLINE( 132)		this->_onData = null();
HXLINE( 133)		this->_onError = null();
HXLINE( 135)		::io::newgrounds::utils::AsyncHttp_obj::_deadPool->push(::hx::ObjectPtr<OBJ_>(this));
HXLINE( 136)		::io::newgrounds::utils::AsyncHttp_obj::_livePool->remove(::hx::ObjectPtr<OBJ_>(this));
HXLINE( 138)		if ((::io::newgrounds::utils::AsyncHttp_obj::_livePool->length == 0)) {
HXLINE( 139)			::io::newgrounds::utils::AsyncHttp_obj::stopTimer();
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(AsyncHttp_obj,cleanUp,(void))

::String AsyncHttp_obj::PATH;

void AsyncHttp_obj::send( ::io::newgrounds::NGLite core,::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_33_send)
HXLINE(  35)		if (core->verbose) {
HXLINE(  35)			core->log((HX_("sending: ",c0,09,59,eb) + data),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),35,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("send",48,8d,50,4c)));
            		}
HXLINE(  38)		::io::newgrounds::utils::AsyncHttp_obj::sendAsync(core,data,onData,onError,onStatus);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(AsyncHttp_obj,send,(void))

void AsyncHttp_obj::sendSync( ::io::newgrounds::NGLite core,::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus){
            	HX_GC_STACKFRAME(&_hx_pos_484b684992387090_50_sendSync)
HXLINE(  52)		 ::sys::Http http =  ::sys::Http_obj::__alloc( HX_CTX ,HX_("https://newgrounds.io/gateway_v3.php",f8,8a,a1,a2));
HXLINE(  53)		http->setParameter(HX_("input",0a,c4,1d,be),data);
HXLINE(  54)		http->onData = onData;
HXLINE(  55)		http->onError = onError;
HXLINE(  56)		http->onStatus = onStatus;
HXLINE(  58)		http->request(true);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(AsyncHttp_obj,sendSync,(void))

::Array< ::Dynamic> AsyncHttp_obj::_deadPool;

::Array< ::Dynamic> AsyncHttp_obj::_livePool;

 ::haxe::ds::IntMap AsyncHttp_obj::_map;

 ::haxe::Timer AsyncHttp_obj::_timer;

int AsyncHttp_obj::_count;

void AsyncHttp_obj::sendAsync( ::io::newgrounds::NGLite core,::String data, ::Dynamic onData, ::Dynamic onError, ::Dynamic onStatus){
            	HX_GC_STACKFRAME(&_hx_pos_484b684992387090_148_sendAsync)
HXLINE( 150)		 ::io::newgrounds::utils::AsyncHttp http;
HXLINE( 151)		if ((::io::newgrounds::utils::AsyncHttp_obj::_deadPool->length == 0)) {
HXLINE( 152)			http =  ::io::newgrounds::utils::AsyncHttp_obj::__alloc( HX_CTX ,core);
            		}
            		else {
HXLINE( 154)			http = ::io::newgrounds::utils::AsyncHttp_obj::_deadPool->__get(0).StaticCast<  ::io::newgrounds::utils::AsyncHttp >();
            		}
HXLINE( 156)		http->start(data,onData,onError,onStatus);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(AsyncHttp_obj,sendAsync,(void))

void AsyncHttp_obj::startTimer(){
            	HX_GC_STACKFRAME(&_hx_pos_484b684992387090_159_startTimer)
HXLINE( 161)		if (::hx::IsNotNull( ::io::newgrounds::utils::AsyncHttp_obj::_timer )) {
HXLINE( 162)			return;
            		}
HXLINE( 164)		::io::newgrounds::utils::AsyncHttp_obj::_timer =  ::haxe::Timer_obj::__alloc( HX_CTX ,((Float)16.666666666666668));
HXLINE( 165)		::io::newgrounds::utils::AsyncHttp_obj::_timer->run = ::io::newgrounds::utils::AsyncHttp_obj::update_dyn();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AsyncHttp_obj,startTimer,(void))

void AsyncHttp_obj::stopTimer(){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_168_stopTimer)
HXLINE( 170)		::io::newgrounds::utils::AsyncHttp_obj::_timer->stop();
HXLINE( 171)		::io::newgrounds::utils::AsyncHttp_obj::_timer = null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AsyncHttp_obj,stopTimer,(void))

void AsyncHttp_obj::update(){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_174_update)
HXLINE( 176)		 ::Dynamic message = ::sys::thread::_Thread::Thread_Impl__obj::readMessage(false);
HXLINE( 177)		if (::hx::IsNotNull( message )) {
HXLINE( 178)			( ( ::io::newgrounds::utils::AsyncHttp)(::io::newgrounds::utils::AsyncHttp_obj::_map->get( ::Dynamic(message->__Field(HX_("key",9f,89,51,00),::hx::paccDynamic)))) )->handleMessage(message);
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AsyncHttp_obj,update,(void))

void AsyncHttp_obj::sendThreaded(){
            	HX_STACKFRAME(&_hx_pos_484b684992387090_183_sendThreaded)
HXDLIN( 183)		while(true){
            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_0, ::Dynamic,data) HXARGC(1)
            			void _hx_run(::String reply){
            				HX_STACKFRAME(&_hx_pos_484b684992387090_191_sendThreaded)
HXLINE( 191)				( ( ::sys::thread::_Thread::HaxeThread)(data->__Field(HX_("source",db,b0,31,32),::hx::paccDynamic)) )->messages->add( ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("key",9f,89,51,00), ::Dynamic(data->__Field(HX_("key",9f,89,51,00),::hx::paccDynamic)))
            					->setFixed(1,HX_("data",2a,56,63,42),reply)));
            			}
            			HX_END_LOCAL_FUNC1((void))

            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_1, ::Dynamic,data) HXARGC(1)
            			void _hx_run(::String error){
            				HX_STACKFRAME(&_hx_pos_484b684992387090_192_sendThreaded)
HXLINE( 192)				( ( ::sys::thread::_Thread::HaxeThread)(data->__Field(HX_("source",db,b0,31,32),::hx::paccDynamic)) )->messages->add( ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("key",9f,89,51,00), ::Dynamic(data->__Field(HX_("key",9f,89,51,00),::hx::paccDynamic)))
            					->setFixed(1,HX_("error",c8,cb,29,73),error)));
            			}
            			HX_END_LOCAL_FUNC1((void))

            			HX_BEGIN_LOCAL_FUNC_S1(::hx::LocalFunc,_hx_Closure_2, ::Dynamic,data) HXARGC(1)
            			void _hx_run(int status){
            				HX_STACKFRAME(&_hx_pos_484b684992387090_193_sendThreaded)
HXLINE( 193)				( ( ::sys::thread::_Thread::HaxeThread)(data->__Field(HX_("source",db,b0,31,32),::hx::paccDynamic)) )->messages->add( ::Dynamic(::hx::Anon_obj::Create(2)
            					->setFixed(0,HX_("key",9f,89,51,00), ::Dynamic(data->__Field(HX_("key",9f,89,51,00),::hx::paccDynamic)))
            					->setFixed(1,HX_("status",32,e7,fb,05),status)));
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE( 185)			 ::Dynamic data = ::sys::thread::_Thread::Thread_Impl__obj::readMessage(true);
HXLINE( 186)			{
HXLINE( 186)				 ::io::newgrounds::NGLite _this = ( ( ::io::newgrounds::NGLite)(data->__Field(HX_("core",5f,bd,c4,41),::hx::paccDynamic)) );
HXDLIN( 186)				if (_this->verbose) {
HXLINE( 186)					_this->log( ::Dynamic((HX_("start message received: ",be,e4,24,d5) + data->__Field(HX_("key",9f,89,51,00),::hx::paccDynamic))),::hx::SourceInfo(HX_("io/newgrounds/utils/AsyncHttp.hx",f2,28,04,57),186,HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d),HX_("sendThreaded",11,6b,e2,0c)));
            				}
            			}
HXLINE( 188)			::io::newgrounds::utils::AsyncHttp_obj::sendSync(( ( ::io::newgrounds::NGLite)(data->__Field(HX_("core",5f,bd,c4,41),::hx::paccDynamic)) ),( (::String)(data->__Field(HX_("args",5d,8d,74,40),::hx::paccDynamic)) ), ::Dynamic(new _hx_Closure_0(data)), ::Dynamic(new _hx_Closure_1(data)), ::Dynamic(new _hx_Closure_2(data)));
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AsyncHttp_obj,sendThreaded,(void))


::hx::ObjectPtr< AsyncHttp_obj > AsyncHttp_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< AsyncHttp_obj > __this = new AsyncHttp_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< AsyncHttp_obj > AsyncHttp_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	AsyncHttp_obj *__this = (AsyncHttp_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(AsyncHttp_obj), true, "io.newgrounds.utils.AsyncHttp"));
	*(void **)__this = AsyncHttp_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

AsyncHttp_obj::AsyncHttp_obj()
{
}

void AsyncHttp_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AsyncHttp);
	HX_MARK_MEMBER_NAME(_core,"_core");
	HX_MARK_MEMBER_NAME(_key,"_key");
	HX_MARK_MEMBER_NAME(_onData,"_onData");
	HX_MARK_MEMBER_NAME(_onError,"_onError");
	HX_MARK_MEMBER_NAME(_onStatus,"_onStatus");
	HX_MARK_MEMBER_NAME(_worker,"_worker");
	HX_MARK_END_CLASS();
}

void AsyncHttp_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_core,"_core");
	HX_VISIT_MEMBER_NAME(_key,"_key");
	HX_VISIT_MEMBER_NAME(_onData,"_onData");
	HX_VISIT_MEMBER_NAME(_onError,"_onError");
	HX_VISIT_MEMBER_NAME(_onStatus,"_onStatus");
	HX_VISIT_MEMBER_NAME(_worker,"_worker");
}

::hx::Val AsyncHttp_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_key") ) { return ::hx::Val( _key ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { return ::hx::Val( _core ); }
		if (HX_FIELD_EQ(inName,"start") ) { return ::hx::Val( start_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_onData") ) { return ::hx::Val( _onData ); }
		if (HX_FIELD_EQ(inName,"_worker") ) { return ::hx::Val( _worker ); }
		if (HX_FIELD_EQ(inName,"cleanUp") ) { return ::hx::Val( cleanUp_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onError") ) { return ::hx::Val( _onError ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onStatus") ) { return ::hx::Val( _onStatus ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"handleMessage") ) { return ::hx::Val( handleMessage_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool AsyncHttp_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"send") ) { outValue = send_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"_map") ) { outValue = ( _map ); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_timer") ) { outValue = ( _timer ); return true; }
		if (HX_FIELD_EQ(inName,"_count") ) { outValue = ( _count ); return true; }
		if (HX_FIELD_EQ(inName,"update") ) { outValue = update_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sendSync") ) { outValue = sendSync_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_deadPool") ) { outValue = ( _deadPool ); return true; }
		if (HX_FIELD_EQ(inName,"_livePool") ) { outValue = ( _livePool ); return true; }
		if (HX_FIELD_EQ(inName,"sendAsync") ) { outValue = sendAsync_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"stopTimer") ) { outValue = stopTimer_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"startTimer") ) { outValue = startTimer_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sendThreaded") ) { outValue = sendThreaded_dyn(); return true; }
	}
	return false;
}

::hx::Val AsyncHttp_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_key") ) { _key=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { _core=inValue.Cast<  ::io::newgrounds::NGLite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_onData") ) { _onData=inValue.Cast<  ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_worker") ) { _worker=inValue.Cast<  ::sys::thread::_Thread::HaxeThread >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onError") ) { _onError=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onStatus") ) { _onStatus=inValue.Cast<  ::Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool AsyncHttp_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { _map=ioValue.Cast<  ::haxe::ds::IntMap >(); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_timer") ) { _timer=ioValue.Cast<  ::haxe::Timer >(); return true; }
		if (HX_FIELD_EQ(inName,"_count") ) { _count=ioValue.Cast< int >(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_deadPool") ) { _deadPool=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
		if (HX_FIELD_EQ(inName,"_livePool") ) { _livePool=ioValue.Cast< ::Array< ::Dynamic> >(); return true; }
	}
	return false;
}

void AsyncHttp_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_core",3e,d9,d5,f4));
	outFields->push(HX_("_key",a0,ce,1c,3f));
	outFields->push(HX_("_worker",1d,42,15,38));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo AsyncHttp_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::io::newgrounds::NGLite */ ,(int)offsetof(AsyncHttp_obj,_core),HX_("_core",3e,d9,d5,f4)},
	{::hx::fsInt,(int)offsetof(AsyncHttp_obj,_key),HX_("_key",a0,ce,1c,3f)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(AsyncHttp_obj,_onData),HX_("_onData",88,70,64,53)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(AsyncHttp_obj,_onError),HX_("_onError",aa,c3,1f,43)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(AsyncHttp_obj,_onStatus),HX_("_onStatus",10,d5,3e,2d)},
	{::hx::fsObject /*  ::sys::thread::_Thread::HaxeThread */ ,(int)offsetof(AsyncHttp_obj,_worker),HX_("_worker",1d,42,15,38)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo AsyncHttp_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &AsyncHttp_obj::PATH,HX_("PATH",a5,ad,12,35)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &AsyncHttp_obj::_deadPool,HX_("_deadPool",ff,14,28,99)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(void *) &AsyncHttp_obj::_livePool,HX_("_livePool",47,a9,f6,01)},
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(void *) &AsyncHttp_obj::_map,HX_("_map",9d,4f,1e,3f)},
	{::hx::fsObject /*  ::haxe::Timer */ ,(void *) &AsyncHttp_obj::_timer,HX_("_timer",06,07,1d,0c)},
	{::hx::fsInt,(void *) &AsyncHttp_obj::_count,HX_("_count",10,8c,4a,46)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String AsyncHttp_obj_sMemberFields[] = {
	HX_("_core",3e,d9,d5,f4),
	HX_("_key",a0,ce,1c,3f),
	HX_("_onData",88,70,64,53),
	HX_("_onError",aa,c3,1f,43),
	HX_("_onStatus",10,d5,3e,2d),
	HX_("_worker",1d,42,15,38),
	HX_("start",62,74,0b,84),
	HX_("handleMessage",ff,1e,86,b2),
	HX_("cleanUp",44,f0,41,ab),
	::String(null()) };

static void AsyncHttp_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AsyncHttp_obj::PATH,"PATH");
	HX_MARK_MEMBER_NAME(AsyncHttp_obj::_deadPool,"_deadPool");
	HX_MARK_MEMBER_NAME(AsyncHttp_obj::_livePool,"_livePool");
	HX_MARK_MEMBER_NAME(AsyncHttp_obj::_map,"_map");
	HX_MARK_MEMBER_NAME(AsyncHttp_obj::_timer,"_timer");
	HX_MARK_MEMBER_NAME(AsyncHttp_obj::_count,"_count");
};

#ifdef HXCPP_VISIT_ALLOCS
static void AsyncHttp_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AsyncHttp_obj::PATH,"PATH");
	HX_VISIT_MEMBER_NAME(AsyncHttp_obj::_deadPool,"_deadPool");
	HX_VISIT_MEMBER_NAME(AsyncHttp_obj::_livePool,"_livePool");
	HX_VISIT_MEMBER_NAME(AsyncHttp_obj::_map,"_map");
	HX_VISIT_MEMBER_NAME(AsyncHttp_obj::_timer,"_timer");
	HX_VISIT_MEMBER_NAME(AsyncHttp_obj::_count,"_count");
};

#endif

::hx::Class AsyncHttp_obj::__mClass;

static ::String AsyncHttp_obj_sStaticFields[] = {
	HX_("PATH",a5,ad,12,35),
	HX_("send",48,8d,50,4c),
	HX_("sendSync",c3,b7,2d,e0),
	HX_("_deadPool",ff,14,28,99),
	HX_("_livePool",47,a9,f6,01),
	HX_("_map",9d,4f,1e,3f),
	HX_("_timer",06,07,1d,0c),
	HX_("_count",10,8c,4a,46),
	HX_("sendAsync",d4,bc,ad,e6),
	HX_("startTimer",03,98,4c,2c),
	HX_("stopTimer",63,f8,77,20),
	HX_("update",09,86,05,87),
	HX_("sendThreaded",11,6b,e2,0c),
	::String(null())
};

void AsyncHttp_obj::__register()
{
	AsyncHttp_obj _hx_dummy;
	AsyncHttp_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.utils.AsyncHttp",0d,93,20,6d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &AsyncHttp_obj::__GetStatic;
	__mClass->mSetStaticField = &AsyncHttp_obj::__SetStatic;
	__mClass->mMarkFunc = AsyncHttp_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(AsyncHttp_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(AsyncHttp_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< AsyncHttp_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = AsyncHttp_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = AsyncHttp_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = AsyncHttp_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void AsyncHttp_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_484b684992387090_25_boot)
HXDLIN(  25)		PATH = HX_("https://newgrounds.io/gateway_v3.php",f8,8a,a1,a2);
            	}
{
            	HX_STACKFRAME(&_hx_pos_484b684992387090_62_boot)
HXDLIN(  62)		_deadPool = ::Array_obj< ::Dynamic>::__new(0);
            	}
{
            	HX_STACKFRAME(&_hx_pos_484b684992387090_63_boot)
HXDLIN(  63)		_livePool = ::Array_obj< ::Dynamic>::__new(0);
            	}
{
            	HX_GC_STACKFRAME(&_hx_pos_484b684992387090_64_boot)
HXDLIN(  64)		_map =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}
{
            	HX_STACKFRAME(&_hx_pos_484b684992387090_67_boot)
HXDLIN(  67)		_count = 0;
            	}
}

} // end namespace io
} // end namespace newgrounds
} // end namespace utils
