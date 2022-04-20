#include <hxcpp.h>

#ifndef INCLUDED_template_EventAddon
#include <template/EventAddon.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b1a65a135ae92e24_107_new,"template.EventAddon","new",0xd41434cc,"template.EventAddon.new","template/CustomNote.hx",107,0xc1584e66)
HX_LOCAL_STACK_FRAME(_hx_pos_b1a65a135ae92e24_109_update,"template.EventAddon","update",0xebfead1d,"template.EventAddon.update","template/CustomNote.hx",109,0xc1584e66)
namespace _hx_template{

void EventAddon_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_b1a65a135ae92e24_107_new)
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
	return inClassId==(int)0x00000001 || inClassId==(int)0x1bc577e0;
}

void EventAddon_obj::update(){
            	HX_STACKFRAME(&_hx_pos_b1a65a135ae92e24_109_update)
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
	__mClass->mName = HX_("template.EventAddon",da,1e,17,53);
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

} // end namespace template
