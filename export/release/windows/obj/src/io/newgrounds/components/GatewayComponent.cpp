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
#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_GatewayComponent
#include <io/newgrounds/components/GatewayComponent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_7f43647141866289_8_new,"io.newgrounds.components.GatewayComponent","new",0x36c7c6c9,"io.newgrounds.components.GatewayComponent.new","io/newgrounds/components/GatewayComponent.hx",8,0x21aecf06)
HX_LOCAL_STACK_FRAME(_hx_pos_7f43647141866289_12_getDatetime,"io.newgrounds.components.GatewayComponent","getDatetime",0xf6839b5a,"io.newgrounds.components.GatewayComponent.getDatetime","io/newgrounds/components/GatewayComponent.hx",12,0x21aecf06)
HX_LOCAL_STACK_FRAME(_hx_pos_7f43647141866289_17_getVersion,"io.newgrounds.components.GatewayComponent","getVersion",0x899b05d9,"io.newgrounds.components.GatewayComponent.getVersion","io/newgrounds/components/GatewayComponent.hx",17,0x21aecf06)
HX_LOCAL_STACK_FRAME(_hx_pos_7f43647141866289_22_ping,"io.newgrounds.components.GatewayComponent","ping",0xb95b97e9,"io.newgrounds.components.GatewayComponent.ping","io/newgrounds/components/GatewayComponent.hx",22,0x21aecf06)
namespace io{
namespace newgrounds{
namespace components{

void GatewayComponent_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_7f43647141866289_8_new)
HXDLIN(   8)		super::__construct(core);
            	}

Dynamic GatewayComponent_obj::__CreateEmpty() { return new GatewayComponent_obj; }

void *GatewayComponent_obj::_hx_vtable = 0;

Dynamic GatewayComponent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< GatewayComponent_obj > _hx_result = new GatewayComponent_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool GatewayComponent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x017655e1) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x017655e1;
	} else {
		return inClassId==(int)0x1718a611;
	}
}

 ::io::newgrounds::Call GatewayComponent_obj::getDatetime(){
            	HX_GC_STACKFRAME(&_hx_pos_7f43647141866289_12_getDatetime)
HXDLIN(  12)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Gateway.getDatetime",67,f4,23,2d),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(GatewayComponent_obj,getDatetime,return )

 ::io::newgrounds::Call GatewayComponent_obj::getVersion(){
            	HX_GC_STACKFRAME(&_hx_pos_7f43647141866289_17_getVersion)
HXDLIN(  17)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Gateway.getVersion",6c,4d,79,b5),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(GatewayComponent_obj,getVersion,return )

 ::io::newgrounds::Call GatewayComponent_obj::ping(){
            	HX_GC_STACKFRAME(&_hx_pos_7f43647141866289_22_ping)
HXDLIN(  22)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Gateway.ping",3c,1f,65,eb),null(),null());
            	}


HX_DEFINE_DYNAMIC_FUNC0(GatewayComponent_obj,ping,return )


::hx::ObjectPtr< GatewayComponent_obj > GatewayComponent_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< GatewayComponent_obj > __this = new GatewayComponent_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< GatewayComponent_obj > GatewayComponent_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	GatewayComponent_obj *__this = (GatewayComponent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(GatewayComponent_obj), true, "io.newgrounds.components.GatewayComponent"));
	*(void **)__this = GatewayComponent_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

GatewayComponent_obj::GatewayComponent_obj()
{
}

::hx::Val GatewayComponent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ping") ) { return ::hx::Val( ping_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getVersion") ) { return ::hx::Val( getVersion_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getDatetime") ) { return ::hx::Val( getDatetime_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *GatewayComponent_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *GatewayComponent_obj_sStaticStorageInfo = 0;
#endif

static ::String GatewayComponent_obj_sMemberFields[] = {
	HX_("getDatetime",f1,93,25,15),
	HX_("getVersion",22,6d,53,cc),
	HX_("ping",72,f2,57,4a),
	::String(null()) };

::hx::Class GatewayComponent_obj::__mClass;

void GatewayComponent_obj::__register()
{
	GatewayComponent_obj _hx_dummy;
	GatewayComponent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.GatewayComponent",57,ae,40,a7);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(GatewayComponent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< GatewayComponent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GatewayComponent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GatewayComponent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
