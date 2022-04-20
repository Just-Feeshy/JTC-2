#include <hxcpp.h>

#ifndef INCLUDED_polymod_hscript_Param
#include <polymod/hscript/Param.h>
#endif
namespace polymod{
namespace hscript{

::polymod::hscript::Param Param_obj::Unused;

bool Param_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("Unused",36,0d,17,a0)) { outValue = Param_obj::Unused; return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(Param_obj)

int Param_obj::__FindIndex(::String inName)
{
	if (inName==HX_("Unused",36,0d,17,a0)) return 0;
	return super::__FindIndex(inName);
}

int Param_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("Unused",36,0d,17,a0)) return 0;
	return super::__FindArgCount(inName);
}

::hx::Val Param_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("Unused",36,0d,17,a0)) return Unused;
	return super::__Field(inName,inCallProp);
}

static ::String Param_obj_sStaticFields[] = {
	HX_("Unused",36,0d,17,a0),
	::String(null())
};

::hx::Class Param_obj::__mClass;

Dynamic __Create_Param_obj() { return new Param_obj; }

void Param_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("polymod.hscript.Param",ba,bb,9d,ae), ::hx::TCanCast< Param_obj >,Param_obj_sStaticFields,0,
	&__Create_Param_obj, &__Create,
	&super::__SGetClass(), &CreateParam_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &Param_obj::__GetStatic;
}

void Param_obj::__boot()
{
Unused = ::hx::CreateConstEnum< Param_obj >(HX_("Unused",36,0d,17,a0),0);
}


} // end namespace polymod
} // end namespace hscript
