#include <hxcpp.h>

#ifndef INCLUDED_EventAddon
#include <EventAddon.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_fc522bbc640c041e_113_new,"EventAddon","new",0x0d171718,"EventAddon.new","AddonHandlerMain.hx",113,0xa00a22fb)
HX_LOCAL_STACK_FRAME(_hx_pos_fc522bbc640c041e_115_update,"EventAddon","update",0x54b14251,"EventAddon.update","AddonHandlerMain.hx",115,0xa00a22fb)

void EventAddon_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_fc522bbc640c041e_113_new)
            	}

Dynamic EventAddon_obj::__CreateEmpty() { return new EventAddon_obj; }

void *EventAddon_obj::_hx_vtable = 0;

Dynamic EventAddon_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< EventAddon_obj > _hx_result = new EventAddon_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool EventAddon_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x25751aae;
}

void EventAddon_obj::update(){
            	HX_STACKFRAME(&_hx_pos_fc522bbc640c041e_115_update)
            	}


HX_DEFINE_DYNAMIC_FUNC0(EventAddon_obj,update,(void))


EventAddon_obj::EventAddon_obj()
{
}

::hx::Val EventAddon_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return ::hx::Val( update_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *EventAddon_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *EventAddon_obj_sStaticStorageInfo = 0;
#endif

static ::String EventAddon_obj_sMemberFields[] = {
	HX_("update",09,86,05,87),
	::String(null()) };

::hx::Class EventAddon_obj::__mClass;

void EventAddon_obj::__register()
{
	EventAddon_obj _hx_dummy;
	EventAddon_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("EventAddon",26,eb,4f,8f);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(EventAddon_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< EventAddon_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = EventAddon_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = EventAddon_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

