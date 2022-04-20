#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
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
#ifndef INCLUDED_io_newgrounds_objects_events__Response_Response_Impl_
#include <io/newgrounds/objects/events/_Response/Response_Impl_.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_AsyncHttp
#include <io/newgrounds/utils/AsyncHttp.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_Dispatcher
#include <io/newgrounds/utils/Dispatcher.h>
#endif
#ifndef INCLUDED_io_newgrounds_utils_TypedDispatcher
#include <io/newgrounds/utils/TypedDispatcher.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f1ddbe0d84463704_40_new,"io.newgrounds.Call","new",0x1ccf1d2a,"io.newgrounds.Call.new","io/newgrounds/Call.hx",40,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_49_addProperty,"io.newgrounds.Call","addProperty",0x8ab8a660,"io.newgrounds.Call.addProperty","io/newgrounds/Call.hx",49,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_60_addComponentParameter,"io.newgrounds.Call","addComponentParameter",0xd39c1ef7,"io.newgrounds.Call.addComponentParameter","io/newgrounds/Call.hx",60,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_74_addDataHandler,"io.newgrounds.Call","addDataHandler",0xe294b595,"io.newgrounds.Call.addDataHandler","io/newgrounds/Call.hx",74,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_84_addSuccessHandler,"io.newgrounds.Call","addSuccessHandler",0x660b3892,"io.newgrounds.Call.addSuccessHandler","io/newgrounds/Call.hx",84,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_94_addErrorHandler,"io.newgrounds.Call","addErrorHandler",0x1575546d,"io.newgrounds.Call.addErrorHandler","io/newgrounds/Call.hx",94,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_104_addStatusHandler,"io.newgrounds.Call","addStatusHandler",0xc6b7f4cd,"io.newgrounds.Call.addStatusHandler","io/newgrounds/Call.hx",104,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_117_send,"io.newgrounds.Call","send",0x1bb8713e,"io.newgrounds.Call.send","io/newgrounds/Call.hx",117,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_175_queue,"io.newgrounds.Call","queue",0x096a20db,"io.newgrounds.Call.queue","io/newgrounds/Call.hx",175,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_178_onData,"io.newgrounds.Call","onData",0x490eac5f,"io.newgrounds.Call.onData","io/newgrounds/Call.hx",178,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_196_onHttpError,"io.newgrounds.Call","onHttpError",0x125edccb,"io.newgrounds.Call.onHttpError","io/newgrounds/Call.hx",196,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_207_onStatus,"io.newgrounds.Call","onStatus",0x8ed0f4a7,"io.newgrounds.Call.onStatus","io/newgrounds/Call.hx",207,0xa923bbe6)
HX_LOCAL_STACK_FRAME(_hx_pos_f1ddbe0d84463704_215_destroy,"io.newgrounds.Call","destroy",0x5d88a6c4,"io.newgrounds.Call.destroy","io/newgrounds/Call.hx",215,0xa923bbe6)
namespace io{
namespace newgrounds{

void Call_obj::__construct( ::io::newgrounds::NGLite core,::String component,::hx::Null< bool >  __o_requireSession,::hx::Null< bool >  __o_isSecure){
            		bool requireSession = __o_requireSession.Default(false);
            		bool isSecure = __o_isSecure.Default(false);
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_40_new)
HXLINE(  42)		this->_core = core;
HXLINE(  43)		this->component = component;
HXLINE(  44)		this->_requireSession = requireSession;
HXLINE(  45)		bool _hx_tmp;
HXDLIN(  45)		if (isSecure) {
HXLINE(  45)			_hx_tmp = ::hx::IsNotNull( core->encryptionHandler );
            		}
            		else {
HXLINE(  45)			_hx_tmp = false;
            		}
HXDLIN(  45)		this->_isSecure = _hx_tmp;
            	}

Dynamic Call_obj::__CreateEmpty() { return new Call_obj; }

void *Call_obj::_hx_vtable = 0;

Dynamic Call_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Call_obj > _hx_result = new Call_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Call_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x23330310;
}

static ::io::newgrounds::ICallable_obj _hx_io_newgrounds_Call__hx_io_newgrounds_ICallable= {
	( void (::hx::Object::*)())&::io::newgrounds::Call_obj::send,
	( void (::hx::Object::*)())&::io::newgrounds::Call_obj::queue,
	( void (::hx::Object::*)())&::io::newgrounds::Call_obj::destroy,
};

void *Call_obj::_hx_getInterface(int inHash) {
	switch(inHash) {
		case (int)0xda87fdcf: return &_hx_io_newgrounds_Call__hx_io_newgrounds_ICallable;
	}
	#ifdef HXCPP_SCRIPTABLE
	return super::_hx_getInterface(inHash);
	#else
	return 0;
	#endif
}

 ::io::newgrounds::Call Call_obj::addProperty(::String name, ::Dynamic value){
            	HX_GC_STACKFRAME(&_hx_pos_f1ddbe0d84463704_49_addProperty)
HXLINE(  51)		if (::hx::IsNull( this->_properties )) {
HXLINE(  52)			this->_properties =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            		}
HXLINE(  54)		this->_properties->set(name,value);
HXLINE(  56)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Call_obj,addProperty,return )

 ::io::newgrounds::Call Call_obj::addComponentParameter(::String name, ::Dynamic value, ::Dynamic defaultValue){
            	HX_GC_STACKFRAME(&_hx_pos_f1ddbe0d84463704_60_addComponentParameter)
HXLINE(  62)		if (::hx::IsEq( value,defaultValue )) {
HXLINE(  63)			return ::hx::ObjectPtr<OBJ_>(this);
            		}
HXLINE(  65)		if (::hx::IsNull( this->_parameters )) {
HXLINE(  66)			this->_parameters =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
            		}
HXLINE(  68)		this->_parameters->set(name,value);
HXLINE(  70)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC3(Call_obj,addComponentParameter,return )

 ::io::newgrounds::Call Call_obj::addDataHandler( ::Dynamic handler){
            	HX_GC_STACKFRAME(&_hx_pos_f1ddbe0d84463704_74_addDataHandler)
HXLINE(  76)		if (::hx::IsNull( this->_dataHandlers )) {
HXLINE(  77)			this->_dataHandlers =  ::io::newgrounds::utils::TypedDispatcher_obj::__alloc( HX_CTX );
            		}
HXLINE(  79)		this->_dataHandlers->add(handler,null());
HXLINE(  80)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,addDataHandler,return )

 ::io::newgrounds::Call Call_obj::addSuccessHandler( ::Dynamic handler){
            	HX_GC_STACKFRAME(&_hx_pos_f1ddbe0d84463704_84_addSuccessHandler)
HXLINE(  86)		if (::hx::IsNull( this->_successHandlers )) {
HXLINE(  87)			this->_successHandlers =  ::io::newgrounds::utils::Dispatcher_obj::__alloc( HX_CTX );
            		}
HXLINE(  89)		this->_successHandlers->add(handler,null());
HXLINE(  90)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,addSuccessHandler,return )

 ::io::newgrounds::Call Call_obj::addErrorHandler( ::Dynamic handler){
            	HX_GC_STACKFRAME(&_hx_pos_f1ddbe0d84463704_94_addErrorHandler)
HXLINE(  96)		if (::hx::IsNull( this->_httpErrorHandlers )) {
HXLINE(  97)			this->_httpErrorHandlers =  ::io::newgrounds::utils::TypedDispatcher_obj::__alloc( HX_CTX );
            		}
HXLINE(  99)		this->_httpErrorHandlers->add(handler,null());
HXLINE( 100)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,addErrorHandler,return )

 ::io::newgrounds::Call Call_obj::addStatusHandler( ::Dynamic handler){
            	HX_GC_STACKFRAME(&_hx_pos_f1ddbe0d84463704_104_addStatusHandler)
HXLINE( 106)		if (::hx::IsNull( this->_statusHandlers )) {
HXLINE( 107)			this->_statusHandlers =  ::io::newgrounds::utils::TypedDispatcher_obj::__alloc( HX_CTX );
            		}
HXLINE( 109)		this->_statusHandlers->add(handler,null());
HXLINE( 110)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,addStatusHandler,return )

void Call_obj::send(){
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_117_send)
HXLINE( 119)		 ::Dynamic data =  ::Dynamic(::hx::Anon_obj::Create(0));
HXLINE( 120)		data->__SetField(HX_("app_id",f9,4f,cf,8f),this->_core->appId,::hx::paccDynamic);
HXLINE( 121)		data->__SetField(HX_("call",9e,18,ba,41), ::Dynamic(::hx::Anon_obj::Create(0)),::hx::paccDynamic);
HXLINE( 122)		 ::Dynamic(data->__Field(HX_("call",9e,18,ba,41),::hx::paccDynamic))->__SetField(HX_("component",bd,f0,53,0f),this->component,::hx::paccDynamic);
HXLINE( 124)		if (this->_core->debug) {
HXLINE( 125)			this->addProperty(HX_("debug",53,52,1f,d7),true);
            		}
HXLINE( 127)		bool _hx_tmp;
HXDLIN( 127)		if (::hx::IsNotNull( this->_properties )) {
HXLINE( 127)			_hx_tmp = !(this->_properties->exists(HX_("session_id",64,14,71,28)));
            		}
            		else {
HXLINE( 127)			_hx_tmp = true;
            		}
HXDLIN( 127)		if (_hx_tmp) {
HXLINE( 130)			if (::hx::IsNotNull( this->_core->sessionId )) {
HXLINE( 133)				this->addProperty(HX_("session_id",64,14,71,28),this->_core->sessionId);
            			}
            			else {
HXLINE( 135)				if (this->_requireSession) {
HXLINE( 137)					 ::Dynamic code = null();
HXDLIN( 137)					 ::Dynamic this1 =  ::Dynamic(::hx::Anon_obj::Create(2)
            						->setFixed(0,HX_("message",c7,35,11,9a),((HX_("cannot send \"",c7,4a,46,e2) + this->component) + HX_("\" call without a sessionId",b6,01,39,6a)))
            						->setFixed(1,HX_("code",2d,b1,c4,41),code));
HXDLIN( 137)					this->_core->logError(this1,::hx::SourceInfo(HX_("io/newgrounds/Call.hx",e6,bb,23,a9),137,HX_("io.newgrounds.Call",38,00,23,72),HX_("send",48,8d,50,4c)));
HXLINE( 138)					return;
            				}
            			}
            		}
HXLINE( 142)		if (::hx::IsNotNull( this->_properties )) {
HXLINE( 144)			 ::Dynamic field = this->_properties->keys();
HXDLIN( 144)			while(( (bool)(field->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 144)				::String field1 = ( (::String)(field->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 145)				::Reflect_obj::setField(data,field1,this->_properties->get(field1));
            			}
            		}
HXLINE( 148)		if (::hx::IsNotNull( this->_parameters )) {
HXLINE( 150)			 ::Dynamic(data->__Field(HX_("call",9e,18,ba,41),::hx::paccDynamic))->__SetField(HX_("parameters",aa,be,7e,51), ::Dynamic(::hx::Anon_obj::Create(0)),::hx::paccDynamic);
HXLINE( 152)			{
HXLINE( 152)				 ::Dynamic field = this->_parameters->keys();
HXDLIN( 152)				while(( (bool)(field->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 152)					::String field1 = ( (::String)(field->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE( 153)					 ::Dynamic data1 =  ::Dynamic( ::Dynamic(data->__Field(HX_("call",9e,18,ba,41),::hx::paccDynamic))->__Field(HX_("parameters",aa,be,7e,51),::hx::paccDynamic));
HXDLIN( 153)					::Reflect_obj::setField(data1,field1,this->_parameters->get(field1));
            				}
            			}
            		}
HXLINE( 156)		{
HXLINE( 156)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 156)			 ::Dynamic replacer = null();
HXDLIN( 156)			::String space = null();
HXDLIN( 156)			 ::Dynamic any = (HX_("Post  - ",d3,33,57,c2) + ::haxe::format::JsonPrinter_obj::print(data,replacer,space));
HXDLIN( 156)			if (_this->verbose) {
HXLINE( 156)				_this->log(any,::hx::SourceInfo(HX_("io/newgrounds/Call.hx",e6,bb,23,a9),156,HX_("io.newgrounds.Call",38,00,23,72),HX_("send",48,8d,50,4c)));
            			}
            		}
HXLINE( 158)		if (this->_isSecure) {
HXLINE( 160)			 ::Dynamic secureData = this->_core->encryptionHandler;
HXDLIN( 160)			 ::Dynamic replacer = null();
HXDLIN( 160)			::String space = null();
HXDLIN( 160)			::String secureData1 = ( (::String)(secureData(::haxe::format::JsonPrinter_obj::print( ::Dynamic(data->__Field(HX_("call",9e,18,ba,41),::hx::paccDynamic)),replacer,space))) );
HXLINE( 161)			data->__SetField(HX_("call",9e,18,ba,41), ::Dynamic(::hx::Anon_obj::Create(0)),::hx::paccDynamic);
HXLINE( 162)			 ::Dynamic(data->__Field(HX_("call",9e,18,ba,41),::hx::paccDynamic))->__SetField(HX_("secure",77,60,4c,64),secureData1,::hx::paccDynamic);
HXLINE( 164)			{
HXLINE( 164)				 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 164)				if (_this->verbose) {
HXLINE( 164)					_this->log((HX_("    secure - ",5c,3b,8a,2b) + secureData1),::hx::SourceInfo(HX_("io/newgrounds/Call.hx",e6,bb,23,a9),164,HX_("io.newgrounds.Call",38,00,23,72),HX_("send",48,8d,50,4c)));
            				}
            			}
            		}
HXLINE( 167)		this->_core->markCallPending_io_newgrounds_Call_T(::hx::ObjectPtr<OBJ_>(this));
HXLINE( 169)		 ::io::newgrounds::NGLite _hx_tmp1 = this->_core;
HXDLIN( 169)		 ::Dynamic replacer1 = null();
HXDLIN( 169)		::String space1 = null();
HXDLIN( 169)		::io::newgrounds::utils::AsyncHttp_obj::send(_hx_tmp1,::haxe::format::JsonPrinter_obj::print(data,replacer1,space1),this->onData_dyn(),this->onHttpError_dyn(),this->onStatus_dyn());
            	}


HX_DEFINE_DYNAMIC_FUNC0(Call_obj,send,(void))

void Call_obj::queue(){
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_175_queue)
HXDLIN( 175)		this->_core->queueCall_io_newgrounds_Call_T(::hx::ObjectPtr<OBJ_>(this));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Call_obj,queue,(void))

void Call_obj::onData(::String reply){
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_178_onData)
HXLINE( 180)		{
HXLINE( 180)			 ::io::newgrounds::NGLite _this = this->_core;
HXDLIN( 180)			if (_this->verbose) {
HXLINE( 180)				_this->log((HX_("Reply - ",a9,b8,72,01) + reply),::hx::SourceInfo(HX_("io/newgrounds/Call.hx",e6,bb,23,a9),180,HX_("io.newgrounds.Call",38,00,23,72),HX_("onData",e9,5e,ed,e4)));
            			}
            		}
HXLINE( 182)		bool _hx_tmp;
HXDLIN( 182)		if (::hx::IsNull( this->_dataHandlers )) {
HXLINE( 182)			_hx_tmp = ::hx::IsNull( this->_successHandlers );
            		}
            		else {
HXLINE( 182)			_hx_tmp = false;
            		}
HXDLIN( 182)		if (_hx_tmp) {
HXLINE( 183)			return;
            		}
HXLINE( 185)		 ::Dynamic response = ::io::newgrounds::objects::events::_Response::Response_Impl__obj::_new(this->_core,reply);
HXLINE( 187)		if (::hx::IsNotNull( this->_dataHandlers )) {
HXLINE( 188)			this->_dataHandlers->dispatch(response);
            		}
HXLINE( 190)		bool _hx_tmp1;
HXDLIN( 190)		bool _hx_tmp2;
HXDLIN( 190)		if (( (bool)(response->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) )) {
HXLINE( 190)			_hx_tmp2 = ( (bool)( ::Dynamic( ::Dynamic(response->__Field(HX_("result",dd,68,84,08),::hx::paccDynamic))->__Field(HX_("data",2a,56,63,42),::hx::paccDynamic))->__Field(HX_("success",c3,25,4e,b8),::hx::paccDynamic)) );
            		}
            		else {
HXLINE( 190)			_hx_tmp2 = false;
            		}
HXDLIN( 190)		if (_hx_tmp2) {
HXLINE( 190)			_hx_tmp1 = ::hx::IsNotNull( this->_successHandlers );
            		}
            		else {
HXLINE( 190)			_hx_tmp1 = false;
            		}
HXDLIN( 190)		if (_hx_tmp1) {
HXLINE( 191)			this->_successHandlers->dispatch();
            		}
HXLINE( 193)		this->destroy();
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,onData,(void))

void Call_obj::onHttpError(::String message){
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_196_onHttpError)
HXLINE( 198)		this->_core->logError(message,::hx::SourceInfo(HX_("io/newgrounds/Call.hx",e6,bb,23,a9),198,HX_("io.newgrounds.Call",38,00,23,72),HX_("onHttpError",01,b6,3a,65)));
HXLINE( 200)		if (::hx::IsNull( this->_httpErrorHandlers )) {
HXLINE( 201)			return;
            		}
HXLINE( 203)		 ::Dynamic code = null();
HXDLIN( 203)		 ::Dynamic this1 =  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("message",c7,35,11,9a),message)
            			->setFixed(1,HX_("code",2d,b1,c4,41),code));
HXDLIN( 203)		 ::Dynamic error = this1;
HXLINE( 204)		this->_httpErrorHandlers->dispatch(error);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,onHttpError,(void))

void Call_obj::onStatus(int status){
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_207_onStatus)
HXLINE( 209)		if (::hx::IsNull( this->_statusHandlers )) {
HXLINE( 210)			return;
            		}
HXLINE( 212)		this->_statusHandlers->dispatch(status);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Call_obj,onStatus,(void))

void Call_obj::destroy(){
            	HX_STACKFRAME(&_hx_pos_f1ddbe0d84463704_215_destroy)
HXLINE( 217)		this->_core = null();
HXLINE( 219)		this->_properties = null();
HXLINE( 220)		this->_parameters = null();
HXLINE( 222)		this->_dataHandlers = null();
HXLINE( 223)		this->_successHandlers = null();
HXLINE( 224)		this->_httpErrorHandlers = null();
HXLINE( 225)		this->_statusHandlers = null();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Call_obj,destroy,(void))


::hx::ObjectPtr< Call_obj > Call_obj::__new( ::io::newgrounds::NGLite core,::String component,::hx::Null< bool >  __o_requireSession,::hx::Null< bool >  __o_isSecure) {
	::hx::ObjectPtr< Call_obj > __this = new Call_obj();
	__this->__construct(core,component,__o_requireSession,__o_isSecure);
	return __this;
}

::hx::ObjectPtr< Call_obj > Call_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core,::String component,::hx::Null< bool >  __o_requireSession,::hx::Null< bool >  __o_isSecure) {
	Call_obj *__this = (Call_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Call_obj), true, "io.newgrounds.Call"));
	*(void **)__this = Call_obj::_hx_vtable;
	__this->__construct(core,component,__o_requireSession,__o_isSecure);
	return __this;
}

Call_obj::Call_obj()
{
}

void Call_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Call);
	HX_MARK_MEMBER_NAME(component,"component");
	HX_MARK_MEMBER_NAME(_core,"_core");
	HX_MARK_MEMBER_NAME(_properties,"_properties");
	HX_MARK_MEMBER_NAME(_parameters,"_parameters");
	HX_MARK_MEMBER_NAME(_requireSession,"_requireSession");
	HX_MARK_MEMBER_NAME(_isSecure,"_isSecure");
	HX_MARK_MEMBER_NAME(_dataHandlers,"_dataHandlers");
	HX_MARK_MEMBER_NAME(_successHandlers,"_successHandlers");
	HX_MARK_MEMBER_NAME(_httpErrorHandlers,"_httpErrorHandlers");
	HX_MARK_MEMBER_NAME(_statusHandlers,"_statusHandlers");
	HX_MARK_END_CLASS();
}

void Call_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(component,"component");
	HX_VISIT_MEMBER_NAME(_core,"_core");
	HX_VISIT_MEMBER_NAME(_properties,"_properties");
	HX_VISIT_MEMBER_NAME(_parameters,"_parameters");
	HX_VISIT_MEMBER_NAME(_requireSession,"_requireSession");
	HX_VISIT_MEMBER_NAME(_isSecure,"_isSecure");
	HX_VISIT_MEMBER_NAME(_dataHandlers,"_dataHandlers");
	HX_VISIT_MEMBER_NAME(_successHandlers,"_successHandlers");
	HX_VISIT_MEMBER_NAME(_httpErrorHandlers,"_httpErrorHandlers");
	HX_VISIT_MEMBER_NAME(_statusHandlers,"_statusHandlers");
}

::hx::Val Call_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"send") ) { return ::hx::Val( send_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { return ::hx::Val( _core ); }
		if (HX_FIELD_EQ(inName,"queue") ) { return ::hx::Val( queue_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onData") ) { return ::hx::Val( onData_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return ::hx::Val( destroy_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onStatus") ) { return ::hx::Val( onStatus_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"component") ) { return ::hx::Val( component ); }
		if (HX_FIELD_EQ(inName,"_isSecure") ) { return ::hx::Val( _isSecure ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_properties") ) { return ::hx::Val( _properties ); }
		if (HX_FIELD_EQ(inName,"_parameters") ) { return ::hx::Val( _parameters ); }
		if (HX_FIELD_EQ(inName,"addProperty") ) { return ::hx::Val( addProperty_dyn() ); }
		if (HX_FIELD_EQ(inName,"onHttpError") ) { return ::hx::Val( onHttpError_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_dataHandlers") ) { return ::hx::Val( _dataHandlers ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"addDataHandler") ) { return ::hx::Val( addDataHandler_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_requireSession") ) { return ::hx::Val( _requireSession ); }
		if (HX_FIELD_EQ(inName,"_statusHandlers") ) { return ::hx::Val( _statusHandlers ); }
		if (HX_FIELD_EQ(inName,"addErrorHandler") ) { return ::hx::Val( addErrorHandler_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_successHandlers") ) { return ::hx::Val( _successHandlers ); }
		if (HX_FIELD_EQ(inName,"addStatusHandler") ) { return ::hx::Val( addStatusHandler_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"addSuccessHandler") ) { return ::hx::Val( addSuccessHandler_dyn() ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_httpErrorHandlers") ) { return ::hx::Val( _httpErrorHandlers ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"addComponentParameter") ) { return ::hx::Val( addComponentParameter_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Call_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { _core=inValue.Cast<  ::io::newgrounds::NGLite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"component") ) { component=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_isSecure") ) { _isSecure=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_properties") ) { _properties=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_parameters") ) { _parameters=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_dataHandlers") ) { _dataHandlers=inValue.Cast<  ::io::newgrounds::utils::TypedDispatcher >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_requireSession") ) { _requireSession=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_statusHandlers") ) { _statusHandlers=inValue.Cast<  ::io::newgrounds::utils::TypedDispatcher >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_successHandlers") ) { _successHandlers=inValue.Cast<  ::io::newgrounds::utils::Dispatcher >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_httpErrorHandlers") ) { _httpErrorHandlers=inValue.Cast<  ::io::newgrounds::utils::TypedDispatcher >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Call_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("component",bd,f0,53,0f));
	outFields->push(HX_("_core",3e,d9,d5,f4));
	outFields->push(HX_("_properties",12,c9,98,33));
	outFields->push(HX_("_parameters",c9,8b,08,24));
	outFields->push(HX_("_requireSession",10,87,83,2a));
	outFields->push(HX_("_isSecure",60,f3,4b,04));
	outFields->push(HX_("_dataHandlers",92,00,89,23));
	outFields->push(HX_("_successHandlers",cd,40,13,e2));
	outFields->push(HX_("_httpErrorHandlers",6a,75,9b,6b));
	outFields->push(HX_("_statusHandlers",5a,8f,17,fa));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Call_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(Call_obj,component),HX_("component",bd,f0,53,0f)},
	{::hx::fsObject /*  ::io::newgrounds::NGLite */ ,(int)offsetof(Call_obj,_core),HX_("_core",3e,d9,d5,f4)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Call_obj,_properties),HX_("_properties",12,c9,98,33)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Call_obj,_parameters),HX_("_parameters",c9,8b,08,24)},
	{::hx::fsBool,(int)offsetof(Call_obj,_requireSession),HX_("_requireSession",10,87,83,2a)},
	{::hx::fsBool,(int)offsetof(Call_obj,_isSecure),HX_("_isSecure",60,f3,4b,04)},
	{::hx::fsObject /*  ::io::newgrounds::utils::TypedDispatcher */ ,(int)offsetof(Call_obj,_dataHandlers),HX_("_dataHandlers",92,00,89,23)},
	{::hx::fsObject /*  ::io::newgrounds::utils::Dispatcher */ ,(int)offsetof(Call_obj,_successHandlers),HX_("_successHandlers",cd,40,13,e2)},
	{::hx::fsObject /*  ::io::newgrounds::utils::TypedDispatcher */ ,(int)offsetof(Call_obj,_httpErrorHandlers),HX_("_httpErrorHandlers",6a,75,9b,6b)},
	{::hx::fsObject /*  ::io::newgrounds::utils::TypedDispatcher */ ,(int)offsetof(Call_obj,_statusHandlers),HX_("_statusHandlers",5a,8f,17,fa)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Call_obj_sStaticStorageInfo = 0;
#endif

static ::String Call_obj_sMemberFields[] = {
	HX_("component",bd,f0,53,0f),
	HX_("_core",3e,d9,d5,f4),
	HX_("_properties",12,c9,98,33),
	HX_("_parameters",c9,8b,08,24),
	HX_("_requireSession",10,87,83,2a),
	HX_("_isSecure",60,f3,4b,04),
	HX_("_dataHandlers",92,00,89,23),
	HX_("_successHandlers",cd,40,13,e2),
	HX_("_httpErrorHandlers",6a,75,9b,6b),
	HX_("_statusHandlers",5a,8f,17,fa),
	HX_("addProperty",96,7f,94,dd),
	HX_("addComponentParameter",ad,d7,0b,1e),
	HX_("addDataHandler",1f,02,98,1d),
	HX_("addSuccessHandler",48,de,56,46),
	HX_("addErrorHandler",a3,00,55,7d),
	HX_("addStatusHandler",d7,f7,8e,42),
	HX_("send",48,8d,50,4c),
	HX_("queue",91,8d,ea,5d),
	HX_("onData",e9,5e,ed,e4),
	HX_("onHttpError",01,b6,3a,65),
	HX_("onStatus",b1,dd,a8,e5),
	HX_("destroy",fa,2c,86,24),
	::String(null()) };

::hx::Class Call_obj::__mClass;

void Call_obj::__register()
{
	Call_obj _hx_dummy;
	Call_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.Call",38,00,23,72);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Call_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Call_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Call_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Call_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
