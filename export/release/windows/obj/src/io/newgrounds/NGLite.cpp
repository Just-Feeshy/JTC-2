#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_crypto_Base64
#include <haxe/crypto/Base64.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Encoding
#include <haxe/io/Encoding.h>
#endif
#ifndef INCLUDED_io_newgrounds_Call
#include <io/newgrounds/Call.h>
#endif
#ifndef INCLUDED_io_newgrounds_ICallable
#include <io/newgrounds/ICallable.h>
#endif
#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_AppComponent
#include <io/newgrounds/components/AppComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_ComponentList
#include <io/newgrounds/components/ComponentList.h>
#endif
#ifndef INCLUDED_io_newgrounds_crypto_Rc4
#include <io/newgrounds/crypto/Rc4.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_6580f5bc70768aad_31_new,"io.newgrounds.NGLite","new",0x224ee173,"io.newgrounds.NGLite.new","io/newgrounds/NGLite.hx",31,0x2dcf2bbd)
HX_DEFINE_STACK_FRAME(_hx_pos_6580f5bc70768aad_78_new,"io.newgrounds.NGLite","new",0x224ee173,"io.newgrounds.NGLite.new","io/newgrounds/NGLite.hx",78,0x2dcf2bbd)
HX_DEFINE_STACK_FRAME(_hx_pos_6580f5bc70768aad_79_new,"io.newgrounds.NGLite","new",0x224ee173,"io.newgrounds.NGLite.new","io/newgrounds/NGLite.hx",79,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_191_queueCall_io_newgrounds_Call_T,"io.newgrounds.NGLite","queueCall_io_newgrounds_Call_T",0x12d91f6a,"io.newgrounds.NGLite.queueCall_io_newgrounds_Call_T","io/newgrounds/NGLite.hx",191,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_205_markCallPending_io_newgrounds_Call_T,"io.newgrounds.NGLite","markCallPending_io_newgrounds_Call_T",0xe926968d,"io.newgrounds.NGLite.markCallPending_io_newgrounds_Call_T","io/newgrounds/NGLite.hx",205,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_206_markCallPending_io_newgrounds_Call_T,"io.newgrounds.NGLite","markCallPending_io_newgrounds_Call_T",0xe926968d,"io.newgrounds.NGLite.markCallPending_io_newgrounds_Call_T","io/newgrounds/NGLite.hx",206,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_201_markCallPending_io_newgrounds_Call_T,"io.newgrounds.NGLite","markCallPending_io_newgrounds_Call_T",0xe926968d,"io.newgrounds.NGLite.markCallPending_io_newgrounds_Call_T","io/newgrounds/NGLite.hx",201,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_48_set_sessionId,"io.newgrounds.NGLite","set_sessionId",0xa1135587,"io.newgrounds.NGLite.set_sessionId","io/newgrounds/NGLite.hx",48,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_86_checkInitialSession,"io.newgrounds.NGLite","checkInitialSession",0x7b4fa92d,"io.newgrounds.NGLite.checkInitialSession","io/newgrounds/NGLite.hx",86,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_92_initialSessionFail,"io.newgrounds.NGLite","initialSessionFail",0x62298a7d,"io.newgrounds.NGLite.initialSessionFail","io/newgrounds/NGLite.hx",92,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_209_onCallComplete,"io.newgrounds.NGLite","onCallComplete",0x735bb503,"io.newgrounds.NGLite.onCallComplete","io/newgrounds/NGLite.hx",209,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_217_checkQueue,"io.newgrounds.NGLite","checkQueue",0xe99216f6,"io.newgrounds.NGLite.checkQueue","io/newgrounds/NGLite.hx",217,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_228___default_log,"io.newgrounds.NGLite","__default_log",0x4dd7ee79,"io.newgrounds.NGLite.__default_log","io/newgrounds/NGLite.hx",228,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_234_logVerbose,"io.newgrounds.NGLite","logVerbose",0x54258aab,"io.newgrounds.NGLite.logVerbose","io/newgrounds/NGLite.hx",234,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_241___default_logError,"io.newgrounds.NGLite","__default_logError",0x7e2f368f,"io.newgrounds.NGLite.__default_logError","io/newgrounds/NGLite.hx",241,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_245_assert,"io.newgrounds.NGLite","assert",0xa217e393,"io.newgrounds.NGLite.assert","io/newgrounds/NGLite.hx",245,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_263_initEncryption,"io.newgrounds.NGLite","initEncryption",0x05664180,"io.newgrounds.NGLite.initEncryption","io/newgrounds/NGLite.hx",263,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_266_initEncryption,"io.newgrounds.NGLite","initEncryption",0x05664180,"io.newgrounds.NGLite.initEncryption","io/newgrounds/NGLite.hx",266,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_271_encryptRc4,"io.newgrounds.NGLite","encryptRc4",0xcadfe54b,"io.newgrounds.NGLite.encryptRc4","io/newgrounds/NGLite.hx",271,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_104_create,"io.newgrounds.NGLite","create",0xd22403c9,"io.newgrounds.NGLite.create","io/newgrounds/NGLite.hx",104,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_119_createAndCheckSession,"io.newgrounds.NGLite","createAndCheckSession",0x2e672b1c,"io.newgrounds.NGLite.createAndCheckSession","io/newgrounds/NGLite.hx",119,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_137_getUrl,"io.newgrounds.NGLite","getUrl",0xf93d0146,"io.newgrounds.NGLite.getUrl","io/newgrounds/NGLite.hx",137,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_168_getSessionId,"io.newgrounds.NGLite","getSessionId",0x48c5a9e8,"io.newgrounds.NGLite.getSessionId","io/newgrounds/NGLite.hx",168,0x2dcf2bbd)
HX_LOCAL_STACK_FRAME(_hx_pos_6580f5bc70768aad_34_boot,"io.newgrounds.NGLite","boot",0xdacf63bf,"io.newgrounds.NGLite.boot","io/newgrounds/NGLite.hx",34,0x2dcf2bbd)
namespace io{
namespace newgrounds{

void NGLite_obj::__construct(::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail){
            		::String appId = __o_appId;
            		if (::hx::IsNull(__o_appId)) appId = HX_("test",52,c8,f9,4c);
            		bool debug = __o_debug.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_6580f5bc70768aad_31_new)
HXLINE( 187)		this->_pendingCalls = ::Array_obj< ::Dynamic>::__new();
HXLINE( 186)		this->_queuedCalls = ::Array_obj< ::Dynamic>::__new();
HXLINE(  69)		this->appId = appId;
HXLINE(  70)		this->set_sessionId(sessionId);
HXLINE(  71)		this->debug = debug;
HXLINE(  73)		this->calls =  ::io::newgrounds::components::ComponentList_obj::__alloc( HX_CTX ,::hx::ObjectPtr<OBJ_>(this));
HXLINE(  75)		if (::hx::IsNotNull( this->sessionId )) {
            			HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_0, ::Dynamic,onFail, ::Dynamic,_g) HXARGC(1)
            			void _hx_run( ::Dynamic response){
            				HX_GC_STACKFRAME(&_hx_pos_6580f5bc70768aad_78_new)
HXLINE(  78)				_g(onFail,response);
            			}
            			HX_END_LOCAL_FUNC1((void))

            			HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_1, ::Dynamic,onFail1, ::Dynamic,_g1) HXARGC(1)
            			void _hx_run( ::Dynamic error){
            				HX_GC_STACKFRAME(&_hx_pos_6580f5bc70768aad_79_new)
HXLINE(  79)				_g1(onFail1,error);
            			}
            			HX_END_LOCAL_FUNC1((void))

HXLINE(  78)			 ::Dynamic _g = this->checkInitialSession_dyn();
HXDLIN(  78)			 ::Dynamic onFail = onSessionFail;
HXDLIN(  78)			 ::Dynamic _hx_tmp =  ::Dynamic(new _hx_Closure_0(onFail,_g));
HXLINE(  79)			 ::Dynamic _g1 = this->initialSessionFail_dyn();
HXDLIN(  79)			 ::Dynamic onFail1 = onSessionFail;
HXDLIN(  79)			 ::Dynamic _hx_tmp1 =  ::Dynamic(new _hx_Closure_1(onFail1,_g1));
HXLINE(  77)			this->calls->app->checkSession()->addDataHandler(_hx_tmp)->addErrorHandler(_hx_tmp1)->send();
            		}
            	}

Dynamic NGLite_obj::__CreateEmpty() { return new NGLite_obj; }

void *NGLite_obj::_hx_vtable = 0;

Dynamic NGLite_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< NGLite_obj > _hx_result = new NGLite_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool NGLite_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7772213d;
}

void NGLite_obj::queueCall_io_newgrounds_Call_T( ::io::newgrounds::Call call){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_191_queueCall_io_newgrounds_Call_T)
HXLINE( 193)		if (this->verbose) {
HXLINE( 193)			this->log((HX_("queued - ",a0,ef,00,da) + call->component),::hx::SourceInfo(HX_("io/newgrounds/NGLite.hx",bd,2b,cf,2d),193,HX_("io.newgrounds.NGLite",01,ac,66,d9),HX_("queueCall",cf,6e,62,c4)));
            		}
HXLINE( 195)		this->_queuedCalls->push(call);
HXLINE( 196)		this->checkQueue();
            	}


HX_DEFINE_DYNAMIC_FUNC1(NGLite_obj,queueCall_io_newgrounds_Call_T,(void))

void NGLite_obj::markCallPending_io_newgrounds_Call_T( ::io::newgrounds::Call call){
            		HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_0, ::io::newgrounds::NGLite,_gthis, ::io::newgrounds::Call,call) HXARGC(1)
            		void _hx_run( ::Dynamic _){
            			HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_205_markCallPending_io_newgrounds_Call_T)
HXLINE( 205)			_gthis->onCallComplete(call);
            		}
            		HX_END_LOCAL_FUNC1((void))

            		HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_1, ::io::newgrounds::NGLite,_gthis, ::io::newgrounds::Call,call) HXARGC(1)
            		void _hx_run( ::Dynamic _){
            			HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_206_markCallPending_io_newgrounds_Call_T)
HXLINE( 206)			_gthis->onCallComplete(call);
            		}
            		HX_END_LOCAL_FUNC1((void))

            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_201_markCallPending_io_newgrounds_Call_T)
HXDLIN( 201)		 ::io::newgrounds::NGLite _gthis = ::hx::ObjectPtr<OBJ_>(this);
HXLINE( 203)		this->_pendingCalls->push(call);
HXLINE( 205)		call->addDataHandler( ::Dynamic(new _hx_Closure_0(_gthis,call)));
HXLINE( 206)		call->addErrorHandler( ::Dynamic(new _hx_Closure_1(_gthis,call)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(NGLite_obj,markCallPending_io_newgrounds_Call_T,(void))

::String NGLite_obj::set_sessionId(::String value){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_48_set_sessionId)
HXDLIN(  48)		::String _hx_tmp;
HXDLIN(  48)		if ((value == HX_("",00,00,00,00))) {
HXDLIN(  48)			_hx_tmp = null();
            		}
            		else {
HXDLIN(  48)			_hx_tmp = value;
            		}
HXDLIN(  48)		return (this->sessionId = _hx_tmp);
            	}


HX_DEFINE_DYNAMIC_FUNC1(NGLite_obj,set_sessionId,return )

void NGLite_obj::checkInitialSession( ::Dynamic onFail, ::Dynamic response){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_86_checkInitialSession)
HXDLIN(  86)		bool _hx_tmp;
HXDLIN(  86)		bool _hx_tmp1;
HXDLIN(  86)		if (( (bool)(response->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) )) {
HXDLIN(  86)			_hx_tmp1 = !(( (bool)( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) ));
            		}
            		else {
HXDLIN(  86)			_hx_tmp1 = true;
            		}
HXDLIN(  86)		if (!(_hx_tmp1)) {
HXDLIN(  86)			_hx_tmp = ( (bool)( ::Dynamic( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("session",56,17,98,93),::hx::paccDynamic))->__Field(HX_("expired",a5,5f,6a,25),::hx::paccDynamic)) );
            		}
            		else {
HXDLIN(  86)			_hx_tmp = true;
            		}
HXDLIN(  86)		if (_hx_tmp) {
HXLINE(  88)			 ::Dynamic _hx_tmp;
HXDLIN(  88)			if (( (bool)(response->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) )) {
HXLINE(  88)				_hx_tmp =  ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic);
            			}
            			else {
HXLINE(  88)				_hx_tmp = response->__Field(HX_("error",c8,cb,29,73),::hx::paccDynamic);
            			}
HXDLIN(  88)			this->initialSessionFail(onFail,_hx_tmp);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(NGLite_obj,checkInitialSession,(void))

void NGLite_obj::initialSessionFail( ::Dynamic onFail, ::Dynamic error){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_92_initialSessionFail)
HXLINE(  94)		this->set_sessionId(null());
HXLINE(  96)		if (::hx::IsNotNull( onFail )) {
HXLINE(  97)			onFail(error);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(NGLite_obj,initialSessionFail,(void))

void NGLite_obj::onCallComplete(::Dynamic call){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_209_onCallComplete)
HXLINE( 211)		this->_pendingCalls->remove(call);
HXLINE( 212)		this->checkQueue();
            	}


HX_DEFINE_DYNAMIC_FUNC1(NGLite_obj,onCallComplete,(void))

void NGLite_obj::checkQueue(){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_217_checkQueue)
HXDLIN( 217)		bool _hx_tmp;
HXDLIN( 217)		if ((this->_pendingCalls->length == 0)) {
HXDLIN( 217)			_hx_tmp = (this->_queuedCalls->length > 0);
            		}
            		else {
HXDLIN( 217)			_hx_tmp = false;
            		}
HXDLIN( 217)		if (_hx_tmp) {
HXLINE( 218)			::io::newgrounds::ICallable_obj::send(this->_queuedCalls->shift());
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC0(NGLite_obj,checkQueue,(void))

HX_BEGIN_DEFAULT_FUNC(__default_log,NGLite_obj)
void _hx_run( ::Dynamic any, ::Dynamic pos){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_228___default_log)
HXDLIN( 228)		 ::Dynamic _hx_tmp = ::haxe::Log_obj::trace;
HXDLIN( 228)		_hx_tmp((HX_("[Newgrounds API] :: ",bc,20,01,84) + ::Std_obj::string(any)),pos);
            	}
HX_END_LOCAL_FUNC2((void))
HX_END_DEFAULT_FUNC

void NGLite_obj::logVerbose( ::Dynamic any, ::Dynamic pos){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_234_logVerbose)
HXDLIN( 234)		if (this->verbose) {
HXLINE( 235)			this->log(any,pos);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(NGLite_obj,logVerbose,(void))

HX_BEGIN_DEFAULT_FUNC(__default_logError,NGLite_obj)
void _hx_run( ::Dynamic any, ::Dynamic pos){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_241___default_logError)
HXDLIN( 241)		 ::Dynamic _hx_tmp = ( ( ::io::newgrounds::NGLite)(__this) )->log;
HXDLIN( 241)		_hx_tmp((HX_("Error: ",4e,a8,5b,b7) + ::Std_obj::string(any)),pos);
            	}
HX_END_LOCAL_FUNC2((void))
HX_END_DEFAULT_FUNC

bool NGLite_obj::_hx_assert(bool condition, ::Dynamic msg, ::Dynamic pos){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_245_assert)
HXLINE( 246)		if (!(condition)) {
HXLINE( 247)			this->logError(msg,pos);
            		}
HXLINE( 249)		return condition;
            	}


HX_DEFINE_DYNAMIC_FUNC3(NGLite_obj,_hx_assert,return )

void NGLite_obj::initEncryption(::String key,::String __o_cipher,::String __o_format){
            		::String cipher = __o_cipher;
            		if (::hx::IsNull(__o_cipher)) cipher = HX_("rc4",63,d7,56,00);
            		::String format = __o_format;
            		if (::hx::IsNull(__o_format)) format = HX_("base64",8f,fd,27,55);
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_263_initEncryption)
HXDLIN( 263)		if ((cipher == HX_("none",b8,12,0a,49))) {
HXLINE( 264)			this->encryptionHandler = null();
            		}
            		else {
HXLINE( 265)			if ((cipher == HX_("rc4",63,d7,56,00))) {
            				HX_BEGIN_LOCAL_FUNC_S3(::hx::LocalFunc,_hx_Closure_0,::String,key1,::String,format1, ::Dynamic,_g) HXARGC(1)
            				::String _hx_run(::String data){
            					HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_266_initEncryption)
HXLINE( 266)					return ( (::String)(_g(key1,format1,data)) );
            				}
            				HX_END_LOCAL_FUNC1(return)

HXLINE( 266)				 ::Dynamic _g = this->encryptRc4_dyn();
HXDLIN( 266)				::String key1 = key;
HXDLIN( 266)				::String format1 = format;
HXDLIN( 266)				this->encryptionHandler =  ::Dynamic(new _hx_Closure_0(key1,format1,_g));
            			}
            			else {
HXLINE( 268)				HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("aes not yet implemented",2c,4d,d9,a3)));
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(NGLite_obj,initEncryption,(void))

::String NGLite_obj::encryptRc4(::String key,::String format,::String data){
            	HX_GC_STACKFRAME(&_hx_pos_6580f5bc70768aad_271_encryptRc4)
HXLINE( 273)		if ((format == HX_("hex",db,42,4f,00))) {
HXLINE( 274)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("hex format not yet implemented",79,74,67,ea)));
            		}
HXLINE( 276)		 ::haxe::io::Bytes keyBytes;
HXLINE( 277)		if ((format == HX_("base64",8f,fd,27,55))) {
HXLINE( 278)			keyBytes = ::haxe::crypto::Base64_obj::decode(key,null());
            		}
            		else {
HXLINE( 280)			keyBytes = null();
            		}
HXLINE( 282)		 ::io::newgrounds::crypto::Rc4 dataBytes =  ::io::newgrounds::crypto::Rc4_obj::__alloc( HX_CTX ,keyBytes);
HXDLIN( 282)		 ::haxe::io::Bytes dataBytes1 = dataBytes->crypt(::haxe::io::Bytes_obj::ofString(data,null()));
HXLINE( 284)		if ((format == HX_("base64",8f,fd,27,55))) {
HXLINE( 285)			return ::haxe::crypto::Base64_obj::encode(dataBytes1,null());
            		}
HXLINE( 287)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC3(NGLite_obj,encryptRc4,return )

 ::io::newgrounds::NGLite NGLite_obj::core;

 ::io::newgrounds::utils::Dispatcher NGLite_obj::onCoreReady;

void NGLite_obj::create(::String __o_appId,::String sessionId, ::Dynamic onSessionFail){
            		::String appId = __o_appId;
            		if (::hx::IsNull(__o_appId)) appId = HX_("test",52,c8,f9,4c);
            	HX_GC_STACKFRAME(&_hx_pos_6580f5bc70768aad_104_create)
HXLINE( 106)		::io::newgrounds::NGLite_obj::core =  ::io::newgrounds::NGLite_obj::__alloc( HX_CTX ,appId,sessionId,false,onSessionFail);
HXLINE( 108)		::io::newgrounds::NGLite_obj::onCoreReady->dispatch();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NGLite_obj,create,(void))

void NGLite_obj::createAndCheckSession(::String __o_appId,::String backupSession, ::Dynamic onSessionFail){
            		::String appId = __o_appId;
            		if (::hx::IsNull(__o_appId)) appId = HX_("test",52,c8,f9,4c);
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_119_createAndCheckSession)
HXLINE( 121)		::String session = ::io::newgrounds::NGLite_obj::getSessionId();
HXLINE( 122)		if (::hx::IsNull( session )) {
HXLINE( 123)			session = backupSession;
            		}
HXLINE( 125)		::io::newgrounds::NGLite_obj::create(appId,session,onSessionFail);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(NGLite_obj,createAndCheckSession,(void))

::String NGLite_obj::getUrl(){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_137_getUrl)
HXDLIN( 137)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(NGLite_obj,getUrl,return )

::String NGLite_obj::getSessionId(){
            	HX_STACKFRAME(&_hx_pos_6580f5bc70768aad_168_getSessionId)
HXDLIN( 168)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(NGLite_obj,getSessionId,return )


void NGLite_obj::__alloc_dynamic_functions(::hx::Ctx *_hx_ctx,NGLite_obj *_hx_obj) {
	if (!_hx_obj->logError.mPtr) _hx_obj->logError = new __default_logError(_hx_obj);
	if (!_hx_obj->log.mPtr) _hx_obj->log = new __default_log(_hx_obj);
}
::hx::ObjectPtr< NGLite_obj > NGLite_obj::__new(::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail) {
	::hx::ObjectPtr< NGLite_obj > __this = new NGLite_obj();
	__this->__construct(__o_appId,sessionId,__o_debug,onSessionFail);
	return __this;
}

::hx::ObjectPtr< NGLite_obj > NGLite_obj::__alloc(::hx::Ctx *_hx_ctx,::String __o_appId,::String sessionId,::hx::Null< bool >  __o_debug, ::Dynamic onSessionFail) {
	NGLite_obj *__this = (NGLite_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(NGLite_obj), true, "io.newgrounds.NGLite"));
	*(void **)__this = NGLite_obj::_hx_vtable;
	io::newgrounds::NGLite_obj::__alloc_dynamic_functions(_hx_ctx,__this);
	__this->__construct(__o_appId,sessionId,__o_debug,onSessionFail);
	return __this;
}

NGLite_obj::NGLite_obj()
{
	logError = new __default_logError(this);
	log = new __default_log(this);
}

void NGLite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NGLite);
	HX_MARK_MEMBER_NAME(verbose,"verbose");
	HX_MARK_MEMBER_NAME(debug,"debug");
	HX_MARK_MEMBER_NAME(appId,"appId");
	HX_MARK_MEMBER_NAME(host,"host");
	HX_MARK_MEMBER_NAME(sessionId,"sessionId");
	HX_MARK_MEMBER_NAME(calls,"calls");
	HX_MARK_MEMBER_NAME(encryptionHandler,"encryptionHandler");
	HX_MARK_MEMBER_NAME(_queuedCalls,"_queuedCalls");
	HX_MARK_MEMBER_NAME(_pendingCalls,"_pendingCalls");
	HX_MARK_MEMBER_NAME(log,"log");
	HX_MARK_MEMBER_NAME(logError,"logError");
	HX_MARK_END_CLASS();
}

void NGLite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(verbose,"verbose");
	HX_VISIT_MEMBER_NAME(debug,"debug");
	HX_VISIT_MEMBER_NAME(appId,"appId");
	HX_VISIT_MEMBER_NAME(host,"host");
	HX_VISIT_MEMBER_NAME(sessionId,"sessionId");
	HX_VISIT_MEMBER_NAME(calls,"calls");
	HX_VISIT_MEMBER_NAME(encryptionHandler,"encryptionHandler");
	HX_VISIT_MEMBER_NAME(_queuedCalls,"_queuedCalls");
	HX_VISIT_MEMBER_NAME(_pendingCalls,"_pendingCalls");
	HX_VISIT_MEMBER_NAME(log,"log");
	HX_VISIT_MEMBER_NAME(logError,"logError");
}

::hx::Val NGLite_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { return ::hx::Val( log ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { return ::hx::Val( host ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { return ::hx::Val( debug ); }
		if (HX_FIELD_EQ(inName,"appId") ) { return ::hx::Val( appId ); }
		if (HX_FIELD_EQ(inName,"calls") ) { return ::hx::Val( calls ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"assert") ) { return ::hx::Val( _hx_assert_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { return ::hx::Val( verbose ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"logError") ) { return ::hx::Val( logError ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sessionId") ) { return ::hx::Val( sessionId ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"checkQueue") ) { return ::hx::Val( checkQueue_dyn() ); }
		if (HX_FIELD_EQ(inName,"logVerbose") ) { return ::hx::Val( logVerbose_dyn() ); }
		if (HX_FIELD_EQ(inName,"encryptRc4") ) { return ::hx::Val( encryptRc4_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_queuedCalls") ) { return ::hx::Val( _queuedCalls ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_sessionId") ) { return ::hx::Val( set_sessionId_dyn() ); }
		if (HX_FIELD_EQ(inName,"_pendingCalls") ) { return ::hx::Val( _pendingCalls ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onCallComplete") ) { return ::hx::Val( onCallComplete_dyn() ); }
		if (HX_FIELD_EQ(inName,"initEncryption") ) { return ::hx::Val( initEncryption_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"encryptionHandler") ) { return ::hx::Val( encryptionHandler ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"initialSessionFail") ) { return ::hx::Val( initialSessionFail_dyn() ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"checkInitialSession") ) { return ::hx::Val( checkInitialSession_dyn() ); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"queueCall_io_newgrounds_Call_T") ) { return ::hx::Val( queueCall_io_newgrounds_Call_T_dyn() ); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"markCallPending_io_newgrounds_Call_T") ) { return ::hx::Val( markCallPending_io_newgrounds_Call_T_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool NGLite_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"core") ) { outValue = ( core ); return true; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { outValue = create_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"getUrl") ) { outValue = getUrl_dyn(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onCoreReady") ) { outValue = ( onCoreReady ); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getSessionId") ) { outValue = getSessionId_dyn(); return true; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createAndCheckSession") ) { outValue = createAndCheckSession_dyn(); return true; }
	}
	return false;
}

::hx::Val NGLite_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { log=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { host=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { debug=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"appId") ) { appId=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"calls") ) { calls=inValue.Cast<  ::io::newgrounds::components::ComponentList >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { verbose=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"logError") ) { logError=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sessionId") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_sessionId(inValue.Cast< ::String >()) );sessionId=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_queuedCalls") ) { _queuedCalls=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_pendingCalls") ) { _pendingCalls=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"encryptionHandler") ) { encryptionHandler=inValue.Cast<  ::Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool NGLite_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"core") ) { core=ioValue.Cast<  ::io::newgrounds::NGLite >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onCoreReady") ) { onCoreReady=ioValue.Cast<  ::io::newgrounds::utils::Dispatcher >(); return true; }
	}
	return false;
}

void NGLite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("verbose",82,d7,b9,71));
	outFields->push(HX_("debug",53,52,1f,d7));
	outFields->push(HX_("appId",dc,66,3b,24));
	outFields->push(HX_("host",68,cf,12,45));
	outFields->push(HX_("sessionId",d1,58,4d,bb));
	outFields->push(HX_("calls",15,72,1b,41));
	outFields->push(HX_("_queuedCalls",63,35,7d,bf));
	outFields->push(HX_("_pendingCalls",1d,41,30,db));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo NGLite_obj_sMemberStorageInfo[] = {
	{::hx::fsBool,(int)offsetof(NGLite_obj,verbose),HX_("verbose",82,d7,b9,71)},
	{::hx::fsBool,(int)offsetof(NGLite_obj,debug),HX_("debug",53,52,1f,d7)},
	{::hx::fsString,(int)offsetof(NGLite_obj,appId),HX_("appId",dc,66,3b,24)},
	{::hx::fsString,(int)offsetof(NGLite_obj,host),HX_("host",68,cf,12,45)},
	{::hx::fsString,(int)offsetof(NGLite_obj,sessionId),HX_("sessionId",d1,58,4d,bb)},
	{::hx::fsObject /*  ::io::newgrounds::components::ComponentList */ ,(int)offsetof(NGLite_obj,calls),HX_("calls",15,72,1b,41)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(NGLite_obj,encryptionHandler),HX_("encryptionHandler",87,e1,f0,ab)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(NGLite_obj,_queuedCalls),HX_("_queuedCalls",63,35,7d,bf)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(NGLite_obj,_pendingCalls),HX_("_pendingCalls",1d,41,30,db)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(NGLite_obj,log),HX_("log",84,54,52,00)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(NGLite_obj,logError),HX_("logError",a4,08,30,5e)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo NGLite_obj_sStaticStorageInfo[] = {
	{::hx::fsObject /*  ::io::newgrounds::NGLite */ ,(void *) &NGLite_obj::core,HX_("core",5f,bd,c4,41)},
	{::hx::fsObject /*  ::io::newgrounds::utils::Dispatcher */ ,(void *) &NGLite_obj::onCoreReady,HX_("onCoreReady",65,5d,00,e3)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String NGLite_obj_sMemberFields[] = {
	HX_("queueCall_io_newgrounds_Call_T",9d,43,06,7e),
	HX_("markCallPending_io_newgrounds_Call_T",00,63,8d,c1),
	HX_("verbose",82,d7,b9,71),
	HX_("debug",53,52,1f,d7),
	HX_("appId",dc,66,3b,24),
	HX_("host",68,cf,12,45),
	HX_("sessionId",d1,58,4d,bb),
	HX_("set_sessionId",b4,0e,b7,c1),
	HX_("calls",15,72,1b,41),
	HX_("encryptionHandler",87,e1,f0,ab),
	HX_("checkInitialSession",1a,02,4a,8a),
	HX_("initialSessionFail",30,6e,76,16),
	HX_("_queuedCalls",63,35,7d,bf),
	HX_("_pendingCalls",1d,41,30,db),
	HX_("onCallComplete",36,03,fa,e1),
	HX_("checkQueue",a9,8f,da,6d),
	HX_("log",84,54,52,00),
	HX_("logVerbose",5e,03,6e,d8),
	HX_("logError",a4,08,30,5e),
	HX_("assert",c6,46,03,4c),
	HX_("initEncryption",b3,8f,04,74),
	HX_("encryptRc4",fe,5d,28,4f),
	::String(null()) };

static void NGLite_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NGLite_obj::core,"core");
	HX_MARK_MEMBER_NAME(NGLite_obj::onCoreReady,"onCoreReady");
};

#ifdef HXCPP_VISIT_ALLOCS
static void NGLite_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NGLite_obj::core,"core");
	HX_VISIT_MEMBER_NAME(NGLite_obj::onCoreReady,"onCoreReady");
};

#endif

::hx::Class NGLite_obj::__mClass;

static ::String NGLite_obj_sStaticFields[] = {
	HX_("core",5f,bd,c4,41),
	HX_("onCoreReady",65,5d,00,e3),
	HX_("create",fc,66,0f,7c),
	HX_("createAndCheckSession",49,59,5b,b3),
	HX_("getUrl",79,64,28,a3),
	HX_("getSessionId",5b,f5,a3,ca),
	::String(null())
};

void NGLite_obj::__register()
{
	NGLite_obj _hx_dummy;
	NGLite_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.NGLite",01,ac,66,d9);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &NGLite_obj::__GetStatic;
	__mClass->mSetStaticField = &NGLite_obj::__SetStatic;
	__mClass->mMarkFunc = NGLite_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(NGLite_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(NGLite_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< NGLite_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = NGLite_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = NGLite_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = NGLite_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void NGLite_obj::__boot()
{
{
            	HX_GC_STACKFRAME(&_hx_pos_6580f5bc70768aad_34_boot)
HXDLIN(  34)		onCoreReady =  ::io::newgrounds::utils::Dispatcher_obj::__alloc( HX_CTX );
            	}
}

} // end namespace io
} // end namespace newgrounds
