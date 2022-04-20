#include <hxcpp.h>

#ifndef INCLUDED_ShaderType
#include <ShaderType.h>
#endif

::ShaderType ShaderType_obj::GAUSSIAN_BLUR;

::ShaderType ShaderType_obj::GLIM_SELECTION;

::ShaderType ShaderType_obj::MINING_SIM_LOADING;

bool ShaderType_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("GAUSSIAN_BLUR",ab,26,58,7d)) { outValue = ShaderType_obj::GAUSSIAN_BLUR; return true; }
	if (inName==HX_("GLIM_SELECTION",76,ca,c9,1a)) { outValue = ShaderType_obj::GLIM_SELECTION; return true; }
	if (inName==HX_("MINING_SIM_LOADING",65,3a,b3,ed)) { outValue = ShaderType_obj::MINING_SIM_LOADING; return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(ShaderType_obj)

int ShaderType_obj::__FindIndex(::String inName)
{
	if (inName==HX_("GAUSSIAN_BLUR",ab,26,58,7d)) return 2;
	if (inName==HX_("GLIM_SELECTION",76,ca,c9,1a)) return 1;
	if (inName==HX_("MINING_SIM_LOADING",65,3a,b3,ed)) return 0;
	return super::__FindIndex(inName);
}

int ShaderType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("GAUSSIAN_BLUR",ab,26,58,7d)) return 0;
	if (inName==HX_("GLIM_SELECTION",76,ca,c9,1a)) return 0;
	if (inName==HX_("MINING_SIM_LOADING",65,3a,b3,ed)) return 0;
	return super::__FindArgCount(inName);
}

::hx::Val ShaderType_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("GAUSSIAN_BLUR",ab,26,58,7d)) return GAUSSIAN_BLUR;
	if (inName==HX_("GLIM_SELECTION",76,ca,c9,1a)) return GLIM_SELECTION;
	if (inName==HX_("MINING_SIM_LOADING",65,3a,b3,ed)) return MINING_SIM_LOADING;
	return super::__Field(inName,inCallProp);
}

static ::String ShaderType_obj_sStaticFields[] = {
	HX_("MINING_SIM_LOADING",65,3a,b3,ed),
	HX_("GLIM_SELECTION",76,ca,c9,1a),
	HX_("GAUSSIAN_BLUR",ab,26,58,7d),
	::String(null())
};

::hx::Class ShaderType_obj::__mClass;

Dynamic __Create_ShaderType_obj() { return new ShaderType_obj; }

void ShaderType_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("ShaderType",9f,d8,52,32), ::hx::TCanCast< ShaderType_obj >,ShaderType_obj_sStaticFields,0,
	&__Create_ShaderType_obj, &__Create,
	&super::__SGetClass(), &CreateShaderType_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &ShaderType_obj::__GetStatic;
}

void ShaderType_obj::__boot()
{
GAUSSIAN_BLUR = ::hx::CreateConstEnum< ShaderType_obj >(HX_("GAUSSIAN_BLUR",ab,26,58,7d),2);
GLIM_SELECTION = ::hx::CreateConstEnum< ShaderType_obj >(HX_("GLIM_SELECTION",76,ca,c9,1a),1);
MINING_SIM_LOADING = ::hx::CreateConstEnum< ShaderType_obj >(HX_("MINING_SIM_LOADING",65,3a,b3,ed),0);
}


