#include <hxcpp.h>

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
#ifndef INCLUDED_io_newgrounds_components_EventComponent
#include <io/newgrounds/components/EventComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_GatewayComponent
#include <io/newgrounds/components/GatewayComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_LoaderComponent
#include <io/newgrounds/components/LoaderComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_MedalComponent
#include <io/newgrounds/components/MedalComponent.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_ScoreBoardComponent
#include <io/newgrounds/components/ScoreBoardComponent.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_f54da57cc2a963a3_14_new,"io.newgrounds.components.ComponentList","new",0xbe2cae2f,"io.newgrounds.components.ComponentList.new","io/newgrounds/components/ComponentList.hx",14,0xdc173482)
namespace io{
namespace newgrounds{
namespace components{

void ComponentList_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_GC_STACKFRAME(&_hx_pos_f54da57cc2a963a3_14_new)
HXLINE(  16)		this->_core = core;
HXLINE(  18)		this->medal =  ::io::newgrounds::components::MedalComponent_obj::__alloc( HX_CTX ,this->_core);
HXLINE(  19)		this->app =  ::io::newgrounds::components::AppComponent_obj::__alloc( HX_CTX ,this->_core);
HXLINE(  20)		this->event =  ::io::newgrounds::components::EventComponent_obj::__alloc( HX_CTX ,this->_core);
HXLINE(  21)		this->scoreBoard =  ::io::newgrounds::components::ScoreBoardComponent_obj::__alloc( HX_CTX ,this->_core);
HXLINE(  22)		this->loader =  ::io::newgrounds::components::LoaderComponent_obj::__alloc( HX_CTX ,this->_core);
HXLINE(  23)		this->gateway =  ::io::newgrounds::components::GatewayComponent_obj::__alloc( HX_CTX ,this->_core);
            	}

Dynamic ComponentList_obj::__CreateEmpty() { return new ComponentList_obj; }

void *ComponentList_obj::_hx_vtable = 0;

Dynamic ComponentList_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ComponentList_obj > _hx_result = new ComponentList_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool ComponentList_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x63ab08f3;
}


::hx::ObjectPtr< ComponentList_obj > ComponentList_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< ComponentList_obj > __this = new ComponentList_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< ComponentList_obj > ComponentList_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	ComponentList_obj *__this = (ComponentList_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ComponentList_obj), true, "io.newgrounds.components.ComponentList"));
	*(void **)__this = ComponentList_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

ComponentList_obj::ComponentList_obj()
{
}

void ComponentList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ComponentList);
	HX_MARK_MEMBER_NAME(_core,"_core");
	HX_MARK_MEMBER_NAME(medal,"medal");
	HX_MARK_MEMBER_NAME(app,"app");
	HX_MARK_MEMBER_NAME(event,"event");
	HX_MARK_MEMBER_NAME(scoreBoard,"scoreBoard");
	HX_MARK_MEMBER_NAME(loader,"loader");
	HX_MARK_MEMBER_NAME(gateway,"gateway");
	HX_MARK_END_CLASS();
}

void ComponentList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_core,"_core");
	HX_VISIT_MEMBER_NAME(medal,"medal");
	HX_VISIT_MEMBER_NAME(app,"app");
	HX_VISIT_MEMBER_NAME(event,"event");
	HX_VISIT_MEMBER_NAME(scoreBoard,"scoreBoard");
	HX_VISIT_MEMBER_NAME(loader,"loader");
	HX_VISIT_MEMBER_NAME(gateway,"gateway");
}

::hx::Val ComponentList_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"app") ) { return ::hx::Val( app ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { return ::hx::Val( _core ); }
		if (HX_FIELD_EQ(inName,"medal") ) { return ::hx::Val( medal ); }
		if (HX_FIELD_EQ(inName,"event") ) { return ::hx::Val( event ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loader") ) { return ::hx::Val( loader ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gateway") ) { return ::hx::Val( gateway ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scoreBoard") ) { return ::hx::Val( scoreBoard ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ComponentList_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"app") ) { app=inValue.Cast<  ::io::newgrounds::components::AppComponent >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { _core=inValue.Cast<  ::io::newgrounds::NGLite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"medal") ) { medal=inValue.Cast<  ::io::newgrounds::components::MedalComponent >(); return inValue; }
		if (HX_FIELD_EQ(inName,"event") ) { event=inValue.Cast<  ::io::newgrounds::components::EventComponent >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loader") ) { loader=inValue.Cast<  ::io::newgrounds::components::LoaderComponent >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gateway") ) { gateway=inValue.Cast<  ::io::newgrounds::components::GatewayComponent >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scoreBoard") ) { scoreBoard=inValue.Cast<  ::io::newgrounds::components::ScoreBoardComponent >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ComponentList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_core",3e,d9,d5,f4));
	outFields->push(HX_("medal",f7,fd,bb,05));
	outFields->push(HX_("app",a1,fc,49,00));
	outFields->push(HX_("event",1a,c8,c4,75));
	outFields->push(HX_("scoreBoard",f4,39,64,f2));
	outFields->push(HX_("loader",13,48,6f,58));
	outFields->push(HX_("gateway",04,40,59,91));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ComponentList_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::io::newgrounds::NGLite */ ,(int)offsetof(ComponentList_obj,_core),HX_("_core",3e,d9,d5,f4)},
	{::hx::fsObject /*  ::io::newgrounds::components::MedalComponent */ ,(int)offsetof(ComponentList_obj,medal),HX_("medal",f7,fd,bb,05)},
	{::hx::fsObject /*  ::io::newgrounds::components::AppComponent */ ,(int)offsetof(ComponentList_obj,app),HX_("app",a1,fc,49,00)},
	{::hx::fsObject /*  ::io::newgrounds::components::EventComponent */ ,(int)offsetof(ComponentList_obj,event),HX_("event",1a,c8,c4,75)},
	{::hx::fsObject /*  ::io::newgrounds::components::ScoreBoardComponent */ ,(int)offsetof(ComponentList_obj,scoreBoard),HX_("scoreBoard",f4,39,64,f2)},
	{::hx::fsObject /*  ::io::newgrounds::components::LoaderComponent */ ,(int)offsetof(ComponentList_obj,loader),HX_("loader",13,48,6f,58)},
	{::hx::fsObject /*  ::io::newgrounds::components::GatewayComponent */ ,(int)offsetof(ComponentList_obj,gateway),HX_("gateway",04,40,59,91)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ComponentList_obj_sStaticStorageInfo = 0;
#endif

static ::String ComponentList_obj_sMemberFields[] = {
	HX_("_core",3e,d9,d5,f4),
	HX_("medal",f7,fd,bb,05),
	HX_("app",a1,fc,49,00),
	HX_("event",1a,c8,c4,75),
	HX_("scoreBoard",f4,39,64,f2),
	HX_("loader",13,48,6f,58),
	HX_("gateway",04,40,59,91),
	::String(null()) };

::hx::Class ComponentList_obj::__mClass;

void ComponentList_obj::__register()
{
	ComponentList_obj _hx_dummy;
	ComponentList_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.ComponentList",bd,6a,38,57);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ComponentList_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ComponentList_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ComponentList_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ComponentList_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
