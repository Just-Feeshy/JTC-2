#include <hxcpp.h>

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

HX_DEFINE_STACK_FRAME(_hx_pos_0d22f47cc764a29c_9_new,"io.newgrounds.components.AppComponent","new",0x480eb50c,"io.newgrounds.components.AppComponent.new","io/newgrounds/components/AppComponent.hx",9,0x11e9cea3)
HX_LOCAL_STACK_FRAME(_hx_pos_0d22f47cc764a29c_13_startSession,"io.newgrounds.components.AppComponent","startSession",0x7b1520e8,"io.newgrounds.components.AppComponent.startSession","io/newgrounds/components/AppComponent.hx",13,0x11e9cea3)
HX_LOCAL_STACK_FRAME(_hx_pos_0d22f47cc764a29c_19_checkSession,"io.newgrounds.components.AppComponent","checkSession",0xf6eff542,"io.newgrounds.components.AppComponent.checkSession","io/newgrounds/components/AppComponent.hx",19,0x11e9cea3)
HX_LOCAL_STACK_FRAME(_hx_pos_0d22f47cc764a29c_24_endSession,"io.newgrounds.components.AppComponent","endSession",0x18c8858f,"io.newgrounds.components.AppComponent.endSession","io/newgrounds/components/AppComponent.hx",24,0x11e9cea3)
HX_LOCAL_STACK_FRAME(_hx_pos_0d22f47cc764a29c_29_getCurrentVersion,"io.newgrounds.components.AppComponent","getCurrentVersion",0xc98b44c1,"io.newgrounds.components.AppComponent.getCurrentVersion","io/newgrounds/components/AppComponent.hx",29,0x11e9cea3)
HX_LOCAL_STACK_FRAME(_hx_pos_0d22f47cc764a29c_35_getHostLicense,"io.newgrounds.components.AppComponent","getHostLicense",0xeff0fed7,"io.newgrounds.components.AppComponent.getHostLicense","io/newgrounds/components/AppComponent.hx",35,0x11e9cea3)
HX_LOCAL_STACK_FRAME(_hx_pos_0d22f47cc764a29c_41_logView,"io.newgrounds.components.AppComponent","logView",0x8601efb5,"io.newgrounds.components.AppComponent.logView","io/newgrounds/components/AppComponent.hx",41,0x11e9cea3)
namespace io{
namespace newgrounds{
namespace components{

void AppComponent_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_0d22f47cc764a29c_9_new)
HXDLIN(   9)		super::__construct(core);
            	}

Dynamic AppComponent_obj::__CreateEmpty() { return new AppComponent_obj; }

void *AppComponent_obj::_hx_vtable = 0;

Dynamic AppComponent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< AppComponent_obj > _hx_result = new AppComponent_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool AppComponent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1718a611) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x1718a611;
	} else {
		return inClassId==(int)0x22730f08;
	}
}

 ::io::newgrounds::Call AppComponent_obj::startSession(::hx::Null< bool >  __o_force){
            		bool force = __o_force.Default(false);
            	HX_GC_STACKFRAME(&_hx_pos_0d22f47cc764a29c_13_startSession)
HXDLIN(  13)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("App.startSession",21,57,ff,7a),null(),null())->addComponentParameter(HX_("force",eb,b1,94,04),force,false);
            	}


HX_DEFINE_DYNAMIC_FUNC1(AppComponent_obj,startSession,return )

 ::io::newgrounds::Call AppComponent_obj::checkSession(){
            	HX_GC_STACKFRAME(&_hx_pos_0d22f47cc764a29c_19_checkSession)
HXDLIN(  19)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("App.checkSession",7b,2b,da,f6),true,null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(AppComponent_obj,checkSession,return )

 ::io::newgrounds::Call AppComponent_obj::endSession(){
            	HX_GC_STACKFRAME(&_hx_pos_0d22f47cc764a29c_24_endSession)
HXDLIN(  24)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("App.endSession",88,8b,aa,17),true,null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(AppComponent_obj,endSession,return )

 ::io::newgrounds::Call AppComponent_obj::getCurrentVersion(::String version){
            	HX_GC_STACKFRAME(&_hx_pos_0d22f47cc764a29c_29_getCurrentVersion)
HXDLIN(  29)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("App.getCurrentVersion",e8,df,34,e9),null(),null())->addComponentParameter(HX_("version",18,e7,f1,7c),version,null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(AppComponent_obj,getCurrentVersion,return )

 ::io::newgrounds::Call AppComponent_obj::getHostLicense(){
            	HX_GC_STACKFRAME(&_hx_pos_0d22f47cc764a29c_35_getHostLicense)
HXDLIN(  35)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("App.getHostLicense",50,f5,7f,67),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(AppComponent_obj,getHostLicense,return )

 ::io::newgrounds::Call AppComponent_obj::logView(){
            	HX_GC_STACKFRAME(&_hx_pos_0d22f47cc764a29c_41_logView)
HXDLIN(  41)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("App.logView",1c,64,d5,dd),null(),null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(AppComponent_obj,logView,return )


::hx::ObjectPtr< AppComponent_obj > AppComponent_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< AppComponent_obj > __this = new AppComponent_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< AppComponent_obj > AppComponent_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	AppComponent_obj *__this = (AppComponent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(AppComponent_obj), true, "io.newgrounds.components.AppComponent"));
	*(void **)__this = AppComponent_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

AppComponent_obj::AppComponent_obj()
{
}

::hx::Val AppComponent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"logView") ) { return ::hx::Val( logView_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"endSession") ) { return ::hx::Val( endSession_dyn() ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startSession") ) { return ::hx::Val( startSession_dyn() ); }
		if (HX_FIELD_EQ(inName,"checkSession") ) { return ::hx::Val( checkSession_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getHostLicense") ) { return ::hx::Val( getHostLicense_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getCurrentVersion") ) { return ::hx::Val( getCurrentVersion_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *AppComponent_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *AppComponent_obj_sStaticStorageInfo = 0;
#endif

static ::String AppComponent_obj_sMemberFields[] = {
	HX_("startSession",14,fb,43,05),
	HX_("checkSession",6e,cf,1e,81),
	HX_("endSession",bb,3c,ba,39),
	HX_("getCurrentVersion",15,0b,fa,fc),
	HX_("getHostLicense",03,bc,2b,87),
	HX_("logView",09,45,19,74),
	::String(null()) };

::hx::Class AppComponent_obj::__mClass;

void AppComponent_obj::__register()
{
	AppComponent_obj _hx_dummy;
	AppComponent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.AppComponent",1a,7f,3c,ff);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(AppComponent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< AppComponent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = AppComponent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = AppComponent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
