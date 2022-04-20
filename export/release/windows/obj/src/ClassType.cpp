#include <hxcpp.h>

#ifndef INCLUDED_ClassType
#include <ClassType.h>
#endif

::ClassType ClassType_obj::EVENT;

::ClassType ClassType_obj::NOTE;

::ClassType ClassType_obj::STAGE;

bool ClassType_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("EVENT",fa,ff,b2,f3)) { outValue = ClassType_obj::EVENT; return true; }
	if (inName==HX_("NOTE",f2,df,ca,33)) { outValue = ClassType_obj::NOTE; return true; }
	if (inName==HX_("STAGE",9e,a2,f9,01)) { outValue = ClassType_obj::STAGE; return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(ClassType_obj)

int ClassType_obj::__FindIndex(::String inName)
{
	if (inName==HX_("EVENT",fa,ff,b2,f3)) return 1;
	if (inName==HX_("NOTE",f2,df,ca,33)) return 0;
	if (inName==HX_("STAGE",9e,a2,f9,01)) return 2;
	return super::__FindIndex(inName);
}

int ClassType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("EVENT",fa,ff,b2,f3)) return 0;
	if (inName==HX_("NOTE",f2,df,ca,33)) return 0;
	if (inName==HX_("STAGE",9e,a2,f9,01)) return 0;
	return super::__FindArgCount(inName);
}

::hx::Val ClassType_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("EVENT",fa,ff,b2,f3)) return EVENT;
	if (inName==HX_("NOTE",f2,df,ca,33)) return NOTE;
	if (inName==HX_("STAGE",9e,a2,f9,01)) return STAGE;
	return super::__Field(inName,inCallProp);
}

static ::String ClassType_obj_sStaticFields[] = {
	HX_("NOTE",f2,df,ca,33),
	HX_("EVENT",fa,ff,b2,f3),
	HX_("STAGE",9e,a2,f9,01),
	::String(null())
};

::hx::Class ClassType_obj::__mClass;

Dynamic __Create_ClassType_obj() { return new ClassType_obj; }

void ClassType_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("ClassType",f2,f2,19,82), ::hx::TCanCast< ClassType_obj >,ClassType_obj_sStaticFields,0,
	&__Create_ClassType_obj, &__Create,
	&super::__SGetClass(), &CreateClassType_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &ClassType_obj::__GetStatic;
}

void ClassType_obj::__boot()
{
EVENT = ::hx::CreateConstEnum< ClassType_obj >(HX_("EVENT",fa,ff,b2,f3),1);
NOTE = ::hx::CreateConstEnum< ClassType_obj >(HX_("NOTE",f2,df,ca,33),0);
STAGE = ::hx::CreateConstEnum< ClassType_obj >(HX_("STAGE",9e,a2,f9,01),2);
}


