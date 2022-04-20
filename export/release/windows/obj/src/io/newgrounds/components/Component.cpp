#include <hxcpp.h>

#ifndef INCLUDED_io_newgrounds_NGLite
#include <io/newgrounds/NGLite.h>
#endif
#ifndef INCLUDED_io_newgrounds_components_Component
#include <io/newgrounds/components/Component.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b4f5373bfad10eb5_11_new,"io.newgrounds.components.Component","new",0x4367c331,"io.newgrounds.components.Component.new","io/newgrounds/components/Component.hx",11,0xf6d73140)
namespace io{
namespace newgrounds{
namespace components{

void Component_obj::__construct( ::io::newgrounds::NGLite core){
            	HX_STACKFRAME(&_hx_pos_b4f5373bfad10eb5_11_new)
HXDLIN(  11)		this->_core = core;
            	}

Dynamic Component_obj::__CreateEmpty() { return new Component_obj; }

void *Component_obj::_hx_vtable = 0;

Dynamic Component_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Component_obj > _hx_result = new Component_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Component_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1718a611;
}


::hx::ObjectPtr< Component_obj > Component_obj::__new( ::io::newgrounds::NGLite core) {
	::hx::ObjectPtr< Component_obj > __this = new Component_obj();
	__this->__construct(core);
	return __this;
}

::hx::ObjectPtr< Component_obj > Component_obj::__alloc(::hx::Ctx *_hx_ctx, ::io::newgrounds::NGLite core) {
	Component_obj *__this = (Component_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Component_obj), true, "io.newgrounds.components.Component"));
	*(void **)__this = Component_obj::_hx_vtable;
	__this->__construct(core);
	return __this;
}

Component_obj::Component_obj()
{
}

void Component_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Component);
	HX_MARK_MEMBER_NAME(_core,"_core");
	HX_MARK_END_CLASS();
}

void Component_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_core,"_core");
}

::hx::Val Component_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { return ::hx::Val( _core ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Component_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_core") ) { _core=inValue.Cast<  ::io::newgrounds::NGLite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Component_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("_core",3e,d9,d5,f4));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Component_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::io::newgrounds::NGLite */ ,(int)offsetof(Component_obj,_core),HX_("_core",3e,d9,d5,f4)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Component_obj_sStaticStorageInfo = 0;
#endif

static ::String Component_obj_sMemberFields[] = {
	HX_("_core",3e,d9,d5,f4),
	::String(null()) };

::hx::Class Component_obj::__mClass;

void Component_obj::__register()
{
	Component_obj _hx_dummy;
	Component_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("io.newgrounds.components.Component",bf,56,40,15);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Component_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Component_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Component_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Component_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace io
} // end namespace newgrounds
} // end namespace components
