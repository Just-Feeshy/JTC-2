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
#ifndef INCLUDED_io_newgrounds_components_EventComponent
#include <io/newgrounds/components/EventComponent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_dd66c03bdee0d224_8_new,"io.newgrounds.components.EventComponent","new",0x90d7fd73,"io.newgrounds.components.EventComponent.new","io/newgrounds/components/EventComponent.hx",8,0x13f63ddc)
HX_LOCAL_STACK_FRAME(_hx_pos_dd66c03bdee0d224_12_logEvent,"io.newgrounds.components.EventComponent","logEvent",0x19cb9303,"io.newgrounds.components.EventComponent.logEvent","io/newgrounds/components/EventComponent.hx",12,0x13f63ddc)
namespace io{
namespace newgrounds{
namespace components{

void EventComponent_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_dd66c03bdee0d224_8_new)
HXDLIN(   8)		super::__construct(core);
            	}

Dynamic EventComponent_obj::__CreateEmpty() { return new EventComponent_obj; }

void *EventComponent_obj::_hx_vtable = 0;

Dynamic EventComponent_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EventComponent_obj > _hx_result = new EventComponent_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool EventComponent_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x1718a611) {
		return inClassId==(int)0x00000001 || inClassId==(int)0x1718a611;
	} else {
		return inClassId==(int)0x2609990b;
	}
}

 ::io::newgrounds::Call EventComponent_obj::logEvent(::String eventName){
            	HX_GC_STACKFRAME(&_hx_pos_dd66c03bdee0d224_12_logEvent)
HXDLIN(  12)		return  ::io::newgrounds::Call_obj::__alloc( HX_CTX ,this->_core,HX_("Event.logEvent",ea,db,73,59),null(),null())->addComponentParameter(HX_("event_name",d0,27,3e,e5),eventName,null())->addComponentParameter(HX_("host",68,cf,12,45),this->_core->host,null());
            	}


HX_DEFINE_DYNAMIC_FUNC1(EventComponent_obj,logEvent,return )


::hx::ObjectPtr< EventComponent_obj > EventComponent_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< EventComponent_obj > __this = new EventComponent_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< EventComponent_obj > EventComponent_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	EventComponent_obj *__this = (EventComponent_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(EventComponent_obj), true, "io.newgrounds.components.EventComponent"));
	*(void **)__this = EventComponent_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

EventComponent_obj::EventComponent_obj()
{
}

::hx::Val EventComponent_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"logEvent") ) { return ::hx::Val( logEvent_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *EventComponent_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *EventComponent_obj_sStaticStorageInfo = 0;
#endif

static ::String EventComponent_obj_sMemberFields[] = {
	HX_("logEvent",f6,04,cb,60),
	::String(null()) };

::hx::Class EventComponent_obj::__mClass;

void EventComponent_obj::__register()
{
	EventComponent_obj _hx_dummy;
	EventComponent_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.EventComponent",01,c8,31,4e);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EventComponent_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EventComponent_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EventComponent_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EventComponent_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
